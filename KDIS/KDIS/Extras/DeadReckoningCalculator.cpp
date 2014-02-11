/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include "./DeadReckoningCalculator.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <limits>

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

#define MAGIC_EPSILON 0.00001
const float PI_TIMES_TWO = 2.0f * M_PI;

//////////////////////////////////////////////////////////////////////////

template <typename T>
inline KBOOL equivalent( const T lhs, const T rhs, T epsilon = std::numeric_limits<T>::epsilon() )
{
    T delta = rhs - lhs;
    return ( delta < 0 ) ? delta > -epsilon : delta < epsilon;
}

/////////////////////////////////////////////////////////////////////////

inline const KFLOAT32 checkAngleHR( const KFLOAT32 a)
{
    if (a < -M_PI) return (a + PI_TIMES_TWO);
    else if (a > M_PI) return (a - PI_TIMES_TWO);
    return a;
}

//////////////////////////////////////////////////////////////////////////

inline const KFLOAT32 checkAngleP( const KFLOAT32 a )
{
    if (a < -M_PI_2)  return (-M_PI-a);
    else if (a > M_PI_2) return (M_PI-a);
    return a;
}

/////////////////////////////////////////////////////////////////////////

template <typename T>
inline const T clampVal( const T val, T CutOff )
{
    if( CutOff < 0 )CutOff = -CutOff;

    if( val > CutOff )return CutOff;
    else if( val < -CutOff )return -CutOff;

    return val;
}

//////////////////////////////////////////////////////////////////////////

void matrixToHPR_new( const TMATRIX& rotation, EulerAngles & hpr )
{
    static const float PRECISION = MAGIC_EPSILON;
    KFLOAT64 sin_pitch = clampVal( -rotation.Data[0][2], 1.0f ); // -mat(0,2)
    KFLOAT64 pitch = asin( sin_pitch );
    hpr.SetThetaInRadians( pitch );

    KFLOAT64 cp = cos( pitch );
    if (equivalent<double>(cp, 0, PRECISION))
    {
        KFLOAT64 cr = clampVal(rotation.Data[1][1],1.0f);
        KFLOAT64 sr = clampVal(-rotation.Data[2][1],1.0f);
        hpr.SetPsiInRadians( 0.0f );
        hpr.SetPhiInRadians( atan2( sr,cr ) );
    } else {
        KFLOAT64 sr = clampVal(rotation.Data[1][2],1.0f);
        KFLOAT64 cr = clampVal(rotation.Data[2][2],1.0f);
        float sgnr = (sr < 0) ? -1.0f : 1.0f;

        KFLOAT64 sh = clampVal(rotation.Data[0][1],1.0f);
        KFLOAT64 ch = clampVal(rotation.Data[0][0],1.0f);
        float sgnh = (sh < 0) ? -1.0f : 1.0f;

        //hpr.SetPsiInRadians( acos ( ch / cp )*sgnh );
        //hpr.SetPhiInRadians( acos( cr / cp)*sgnr);
        hpr.SetPsiInRadians( atan2 (sh,ch ) );
        hpr.SetPhiInRadians( atan2 (sr,cr ) );
    }
}

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::positionReset( const WorldCoordinates & Position )
{
    m_initPosition = Position;
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::orientationReset( const EulerAngles & Orientation )
{
    m_initOrientation = Orientation;

    const KFLOAT32 f32Psi = Orientation.GetPsiInRadians();
    const KFLOAT32 f32Theta = Orientation.GetThetaInRadians();
    const KFLOAT32 f32Phi = Orientation.GetPhiInRadians();

    const KFLOAT64 f32CosPsi = cos( f32Psi );
    const KFLOAT64 f32CosTheta = cos( f32Theta );
    const KFLOAT64 f32CosPhi = cos( f32Phi );
    const KFLOAT64 f32SinPsi = sin( f32Psi );
    const KFLOAT64 f32SinTheta = sin( f32Theta );
    const KFLOAT64 f32SinPhi = sin( f32Phi );

    // Create the orientation matrix

    // RI - could use osg mathematics for Euler to rotation matrix computation
    const KFLOAT64 sinTheta_cosPsi = f32SinTheta * f32CosPsi;
    const KFLOAT64 sinTheta_sinPsi = f32SinTheta * f32SinPsi;

    m_initOrientationMatrix.Data[0][0] = f32CosTheta * f32CosPsi;
    m_initOrientationMatrix.Data[0][1] = f32CosTheta * f32SinPsi;
    m_initOrientationMatrix.Data[0][2] = -f32SinTheta;

    m_initOrientationMatrix.Data[1][0] = ( f32SinPhi * sinTheta_cosPsi ) - ( f32CosPhi * f32SinPsi );
    m_initOrientationMatrix.Data[1][1] = ( f32SinPhi * sinTheta_sinPsi ) + ( f32CosPhi * f32CosPsi );
    m_initOrientationMatrix.Data[1][2] = f32SinPhi * f32CosTheta;

    m_initOrientationMatrix.Data[2][0] = ( f32CosPhi * sinTheta_cosPsi ) + ( f32SinPhi * f32SinPsi );
    m_initOrientationMatrix.Data[2][1] = ( f32CosPhi * sinTheta_sinPsi ) - ( f32SinPhi * f32CosPsi );
    m_initOrientationMatrix.Data[2][2] = f32CosPhi * f32CosTheta;

    m_initOrientationMatrixTranspose = m_initOrientationMatrix;
    m_initOrientationMatrixTranspose.inPlanceTranspose();

    computeRotationAxis(m_initOrientationMatrix);
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::angularVelocityReset( const Vector & AngularVelocity )
{
    m_initAngularVelocity = AngularVelocity;

    m_initEulerAngularVelocity = toEulerAngularVelocity(AngularVelocity, m_initOrientation);

    // Create the ww matrix
    m_wwMatrix.Data[0][0] = m_initAngularVelocity[0] * m_initAngularVelocity[0];
    m_wwMatrix.Data[0][1] = m_initAngularVelocity[0] * m_initAngularVelocity[1];
    m_wwMatrix.Data[0][2] = m_initAngularVelocity[0] * m_initAngularVelocity[2];

    m_wwMatrix.Data[1][0] = m_initAngularVelocity[1] * m_initAngularVelocity[0];
    m_wwMatrix.Data[1][1] = m_initAngularVelocity[1] * m_initAngularVelocity[1];
    m_wwMatrix.Data[1][2] = m_initAngularVelocity[1] * m_initAngularVelocity[2];

    m_wwMatrix.Data[2][0] = m_initAngularVelocity[2] * m_initAngularVelocity[0];
    m_wwMatrix.Data[2][1] = m_initAngularVelocity[2] * m_initAngularVelocity[1];
    m_wwMatrix.Data[2][2] = m_initAngularVelocity[2] * m_initAngularVelocity[2];

    m_SkewOmegaMatrix.Data[0][0] = 0;
    m_SkewOmegaMatrix.Data[0][1] = - m_initAngularVelocity[2];
    m_SkewOmegaMatrix.Data[0][2] = m_initAngularVelocity[1];

    m_SkewOmegaMatrix.Data[1][0] = m_initAngularVelocity[2];
    m_SkewOmegaMatrix.Data[1][1] = 0;
    m_SkewOmegaMatrix.Data[1][2] = - m_initAngularVelocity[0];

    m_SkewOmegaMatrix.Data[2][0] = - m_initAngularVelocity[1];
    m_SkewOmegaMatrix.Data[2][1] = m_initAngularVelocity[0];
    m_SkewOmegaMatrix.Data[2][2] = 0;

    m_f64Magnitude = sqrt( m_initAngularVelocity[0] * m_initAngularVelocity[0] +
                           m_initAngularVelocity[1] * m_initAngularVelocity[1] +
                           m_initAngularVelocity[2] * m_initAngularVelocity[2] );
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::velocityReset( const Vector & LinearVelocity )
{
    m_initLinearVelocity = LinearVelocity;
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::accelerationReset( const Vector & LinearAcceleration )
{
    m_initLinearAcceleration = LinearAcceleration;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles DeadReckoningCalculator::toEulerAngularVelocity( const Vector & angVel, const EulerAngles & Orientation )
{
    KFLOAT32 dpsi, dtheta, dphi;

    const KFLOAT32 phi = Orientation.GetPhiInRadians();
    const KFLOAT32 theta = Orientation.GetThetaInRadians();
    const KFLOAT32 psi = Orientation.GetPsiInRadians();

    KFLOAT32 cos_phi = cos( phi );
    KFLOAT32 sin_phi = sin( phi );

    dtheta = angVel[1] * cos_phi - angVel[2] * sin_phi;
    dpsi  = ( angVel[1] * sin_phi + angVel[2] * cos_phi ) / cos( theta ); //could be unstable when cos(theta) is close to 0
    dphi = angVel[0] + dpsi * sin( theta );

    return EulerAngles( ( const KFLOAT32 )dpsi, ( const KFLOAT32 )dtheta, ( const KFLOAT32 )dphi );
}


void DeadReckoningCalculator::calcOrientation_simplified( EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset )
{
    /* Orientation */
    // A simpler way from the IEEE method:
    /*
        m_curOrientation += ( toEulerAngularVelocity( m_initAngularVelocity, m_curOrientation ) * DeltaTime );
    */
    OrientationOut = m_initOrientation + m_initEulerAngularVelocity * totalTimeSinceReset;
    // make sure the Pitch is between -90 and +90 degrees
    // also handle the discontinuity when Pitch is very close to +-90
    if( equivalent<KFLOAT32>( OrientationOut[1], M_PI_2, MAGIC_EPSILON * 100 ) ) {
        OrientationOut[0] = M_PI - OrientationOut[0]; //reflecting the heading angle, to avoid discontinuity
        if (OrientationOut[1] < 0)
            OrientationOut[1] =  (-M_PI_2-OrientationOut[1]);
        else if (OrientationOut[1] > 0)
            OrientationOut[1] = (M_PI_2-OrientationOut[1]);
    }

    // Make sure the value is within -180 and +180 degrees for Heading and Roll.
    OrientationOut[0] = checkAngleHR( OrientationOut[0]);
    OrientationOut[2] = checkAngleHR( OrientationOut[2]);
}

/////////////////////////////////////////////////////////////////////////


void DeadReckoningCalculator::computeRotationAxis( const TMATRIX& curOrientationMatrix )
{
    if (!m_bQuaxAxisSet)
    {
        KFLOAT32 x,y,z;
        x = curOrientationMatrix.Data[1][2] - curOrientationMatrix.Data[2][1];
        y = curOrientationMatrix.Data[2][0] - curOrientationMatrix.Data[0][2];
        z = curOrientationMatrix.Data[0][1] - curOrientationMatrix.Data[1][0];

        // normalise
        KFLOAT32 len = sqrt(x * x + y * y + z * z);

        x /= len;
        y /= len;
        z /= len;

        m_quatAxis.SetX(x);
        m_quatAxis.SetY(y);
        m_quatAxis.SetZ(z);

        m_bQuaxAxisSet = true;
    }
}

void DeadReckoningCalculator::calcOrientation( EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset  )
{
    // compute the DR matrix
    TMATRIX DR;
    if (m_bQuaxAxisSet)
        computeDRMatrix_asQuat( DR, totalTimeSinceReset );
    else
        computeDRMatrix( DR, totalTimeSinceReset );

    TMATRIX curOrientationMatrix = DR * m_initOrientationMatrix;
    //TMATRIX curOrientationMatrix = m_initOrientationMatrix;

    matrixToHPR_new( curOrientationMatrix, OrientationOut );
    //matrixToHPR( curOrientationMatrix, m_curOrientation );
    OrientationOut[0] = checkAngleHR( OrientationOut[0]);
    OrientationOut[1] = checkAngleP(OrientationOut[1]);
    OrientationOut[2] = checkAngleHR( OrientationOut[2]);

    computeRotationAxis(curOrientationMatrix);
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::computeDRMatrix( TMATRIX& res, const KFLOAT32 totalTimeSinceReset )
{
    TMATRIX I;
    const KFLOAT64 f64DeltaMag = totalTimeSinceReset * m_f64Magnitude;
    if( f64DeltaMag > MAGIC_EPSILON )
    {
        const KFLOAT32 f64CosMagDelta = cos( f64DeltaMag );
        const KFLOAT64 fwwScalar = ( 1 - f64CosMagDelta ) / ( m_f64Magnitude * m_f64Magnitude );
        res = m_wwMatrix;
        res *= fwwScalar;
        I *= f64CosMagDelta;
        const KFLOAT64 f64SkewScalar = sin( f64DeltaMag ) / m_f64Magnitude;
        res += I;
        res -= ( m_SkewOmegaMatrix * f64SkewScalar );
    }
    else
    {
        res = I; // Identity matrix
    }
}

void DeadReckoningCalculator::computeDRMatrix_asQuat( TMATRIX& res, const KFLOAT32 totalTimeSinceReset )
{
    // to be implemented
    // assume that m_quatAxis is set
    KFLOAT32 qx, qy, qz;
    KFLOAT32 q0;
    const KFLOAT64 beta = totalTimeSinceReset * m_f64Magnitude;

    KFLOAT32 sin_beta_2 = sin(beta/2.0f);
    qx = sin_beta_2 * m_quatAxis.GetX();
    qy = sin_beta_2 * m_quatAxis.GetY();
    qz = sin_beta_2 * m_quatAxis.GetZ();
    q0 = cos(beta/2.0f);

    res.Data[0][0] = q0*q0 + qx*qx - 0.5f;
    res.Data[0][1] = qx*qy - q0*qz;
    res.Data[0][2] = qx*qz + q0*qy;

    res.Data[1][0] = qx*qy + q0*qz;
    res.Data[1][1] = q0*q0 + qy*qy - 0.5f;
    res.Data[1][2] = qy*qz - q0*qx;

    res.Data[2][0] = qx*qz - q0*qy;
    res.Data[2][1] = qy*qz + q0*qx;
    res.Data[2][2] = q0*q0 + qz*qz - 0.5f;
}

//////////////////////////////////////////////////////////////////////////
// Dead Reckoning Algorithm Implementations
//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::calcDeadReckoningFPW( WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset)
{
    /* Position */
    PositionOut = ( m_initPosition + ( m_initLinearVelocity * totalTimeSinceReset ) );
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::calcDeadReckoningRPW( WorldCoordinates & PositionOut, EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset )
{
    /* Position */
    PositionOut = ( m_initPosition + ( m_initLinearVelocity * totalTimeSinceReset ) );
    //calcOrientation(OrientationOut);
    calcOrientation_simplified( OrientationOut, totalTimeSinceReset );
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::calcDeadReckoningRVW(  WorldCoordinates & PositionOut, EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset )
{
    /* Position */
    PositionOut = ( m_initPosition + ( m_initLinearVelocity * totalTimeSinceReset ) +
                    ( m_initLinearAcceleration * ( 0.5 * totalTimeSinceReset * totalTimeSinceReset ) ) );
    //calcOrientation(OrientationOut);
    calcOrientation_simplified( OrientationOut, totalTimeSinceReset );
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::calcDeadReckoningFVW( WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset )
{
    /* Position */
    PositionOut = ( m_initPosition + ( m_initLinearVelocity * totalTimeSinceReset ) +
                    ( m_initLinearAcceleration * ( 0.5 * totalTimeSinceReset * totalTimeSinceReset ) ) );
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::calcDeadReckoningFPB( WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset )
{
    // See page 124 of IEEE 1278.1 - 1995 for more details on this and other dead reckoning equations.

    // Calculate Magnitude, scalars etc
    const KFLOAT64 f64DeltaMag = totalTimeSinceReset * m_f64Magnitude;
    if( f64DeltaMag > MAGIC_EPSILON )
    {
        KFLOAT32 m_f32MagPow2 = m_f64Magnitude * m_f64Magnitude;
        KFLOAT32 m_f32MagPow3 = m_f32MagPow2 * m_f64Magnitude;

        const KFLOAT64 f64Scalar = ( ( f64DeltaMag ) - sin( f64DeltaMag ) ) / m_f32MagPow3;
        const KFLOAT64 f64IScalar = sin( f64DeltaMag ) / m_f64Magnitude;
        const KFLOAT64 f64SkewScale = ( 1 - cos( f64DeltaMag ) ) / m_f32MagPow2 ;
        TMATRIX R1( m_wwMatrix ), IMatrix;
        R1 *= f64Scalar;
        IMatrix *= f64IScalar;
        R1 += IMatrix;
        R1 += ( m_SkewOmegaMatrix * f64SkewScale ); // RI - should be + instead of - IEEE 1278.1-1995.pdf page 128

        PositionOut = ( m_initPosition + ( m_initOrientationMatrixTranspose * ( R1 * m_initLinearVelocity ) ) );
    }
    else
    {
        PositionOut = ( m_initPosition + ( m_initOrientationMatrixTranspose * m_initLinearVelocity * totalTimeSinceReset ) );
    }
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::calcDeadReckoningRPB(  WorldCoordinates & PositionOut, EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset)
{
    /* Position */
    // Position is calculated the same as FPB
    calcDeadReckoningFPB( PositionOut, totalTimeSinceReset );
    //calcOrientation(OrientationOut);
    calcOrientation_simplified( OrientationOut, totalTimeSinceReset );
}


//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::calcDeadReckoningRVB( WorldCoordinates & PositionOut, EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset )
{
    /* Position */
    calcDeadReckoningFVB( PositionOut, totalTimeSinceReset );
    //calcOrientation(OrientationOut);
    calcOrientation_simplified( OrientationOut, totalTimeSinceReset );
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::calcDeadReckoningFVB( WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset )
{
    // the first part of the equation
    calcDeadReckoningFPB( PositionOut, totalTimeSinceReset);

    // now adding to the position R0t_w->b * R2 * Ab
    // Calculate Magnitude, scalars etc
    const KFLOAT64 f64DeltaMag = totalTimeSinceReset * m_f64Magnitude;

    if( f64DeltaMag > MAGIC_EPSILON )
    {

        KFLOAT32 m_f32MagPow2 = m_f64Magnitude * m_f64Magnitude;
        KFLOAT32 m_f32MagPow3 = m_f32MagPow2 * m_f64Magnitude;
        KFLOAT32 m_f32MagPow4 = m_f32MagPow3 * m_f64Magnitude;
        KFLOAT32 m_f32DeltaPow2 = f64DeltaMag * f64DeltaMag;

        KFLOAT64 f64R2Scale = (0.5 * m_f32DeltaPow2 - cos( f64DeltaMag )- f64DeltaMag * sin( f64DeltaMag ) + 1)/m_f32MagPow4;

        KFLOAT64 f64R2IScalar = ( cos( f64DeltaMag ) + f64DeltaMag * sin( f64DeltaMag ) - 1.0 ) / m_f32MagPow2;

        KFLOAT64 f64R2SkewScale = ( sin( f64DeltaMag ) - f64DeltaMag * cos( f64DeltaMag ) ) / m_f32MagPow3;

        // Create the ww matrix
        TMATRIX R2Matrix( m_wwMatrix ), IR2Matrix;
        R2Matrix *= f64R2Scale;
        IR2Matrix *= f64R2IScalar;
        R2Matrix += ( IR2Matrix + ( m_SkewOmegaMatrix * f64R2SkewScale ) );

        PositionOut = PositionOut + ( m_initOrientationMatrixTranspose * ( R2Matrix * m_Ab ) );
    } else
        PositionOut = PositionOut + ( m_initOrientationMatrixTranspose * m_Ab ) * totalTimeSinceReset;
}

/////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::RunAlgorithm( const KFLOAT32 totalTimeSinceReset, WorldCoordinates& PositionOut, EulerAngles& OrientationOut )
{
    switch( m_DRA )
    {
    case DRM_F_P_W:
        calcDeadReckoningFPW( PositionOut, totalTimeSinceReset );
        break;

    case DRM_R_P_W:
        if( m_f64Magnitude < MAGIC_EPSILON )
            calcDeadReckoningFPW( PositionOut, totalTimeSinceReset );
        else
            calcDeadReckoningRPW( PositionOut, OrientationOut, totalTimeSinceReset );
        break;

    case DRM_R_V_W:
        if( m_f64Magnitude < MAGIC_EPSILON )
            calcDeadReckoningFVW( PositionOut, totalTimeSinceReset );
        else
            calcDeadReckoningRVW( PositionOut, OrientationOut, totalTimeSinceReset );
        break;

    case DRM_F_V_W:
        calcDeadReckoningFVW( PositionOut, totalTimeSinceReset );
        break;

    case DRM_F_P_B:
        calcDeadReckoningFPB( PositionOut, totalTimeSinceReset );
        break;

    case DRM_R_P_B:
        calcDeadReckoningRPB( PositionOut, OrientationOut, totalTimeSinceReset );
        break;

    case DRM_R_V_B:
        calcDeadReckoningRVB( PositionOut, OrientationOut, totalTimeSinceReset );
        break;

    case DRM_F_V_B:
        calcDeadReckoningFVB( PositionOut, totalTimeSinceReset );
        break;
    }
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

DeadReckoningCalculator::DeadReckoningCalculator() :
    m_f64Magnitude( 0 ),
    m_DRA( Other_DRA )
{
}

//////////////////////////////////////////////////////////////////////////

DeadReckoningCalculator::~DeadReckoningCalculator()
{
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::Reset( const Vector & LinearVelocity, const Vector & LinearAcceleration, const Vector & AngularVelocity,
                                     const WorldCoordinates & Position, const EulerAngles & Orientation, const Vector & QuatAxis, DeadReckoningAlgorithm DRA )
{
    m_DRA = DRA;

    positionReset( Position );
    if ((QuatAxis.GetX() + QuatAxis.GetY() + QuatAxis.GetZ()) > 0.0f) // must set m_bQuaxAxisSet before orientationReset
        quatAxisReset(QuatAxis);
    else
        m_bQuaxAxisSet = false;
    orientationReset( Orientation );
    angularVelocityReset( AngularVelocity );
    velocityReset( LinearVelocity );
    accelerationReset( LinearAcceleration );

    m_Ab = ( m_initLinearAcceleration + ( m_SkewOmegaMatrix * m_initLinearVelocity ) );
}

//////////////////////////////////////////////////////////////////////////

vector<WorldCoordinates> DeadReckoningCalculator::GenerateSmoothingPoints( const WorldCoordinates & StartPosition, const WorldCoordinates & EndPosition,
                                                                           KUINT32 NumberOfPoints )
{
    vector<WorldCoordinates> Points;
    Points.reserve( NumberOfPoints );

    GenerateSmoothingPoints( StartPosition, EndPosition, NumberOfPoints, Points );

    return Points;
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::GenerateSmoothingPoints( const WorldCoordinates & StartPosition, const WorldCoordinates & EndPosition,
                                                       KUINT32 NumberOfPoints, vector<WorldCoordinates> & v)
{
    v.reserve( NumberOfPoints );
    WorldCoordinates delta_loc = EndPosition - StartPosition;

    for( KINT32 i = 1; i <= NumberOfPoints; ++i )
    {
        v.push_back( StartPosition + ( delta_loc *  ( KFLOAT32( i ) / KFLOAT32( NumberOfPoints ) ) ) );
    }
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningCalculator::quatAxisReset( const Vector & QuatAxis )
{
    m_quatAxis = QuatAxis;
    m_bQuaxAxisSet = true;
}

//////////////////////////////////////////////////////////////////////////
