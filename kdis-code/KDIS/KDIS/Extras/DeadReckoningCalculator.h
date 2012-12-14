/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    class:      DeadReckoningCalculator
    created:    06/08/2009
    author:     Karl Jones, Robert Ioiart

    purpose:    Class for calculating dead reckoning of an entity.

                Dead Reckoning Algorithms consist of 3 elements.

                XYZ

                X - Specifies rotation as either fixed(F) or rotating(R).

                Y - Specifies dead reckoning rates to be held constant as either rate of position (P)
                    or rate of velocity (V).

                Z - Specifies the coordinate system as either world coordinates (W) or body axis coordinates(B).

                Note: These  algorithms are still in a BETA state, they need testing and validating.
                If you find a problem please let me know and if you find a solution I would be even happier to hear from you :)

                Status:

                1 Static - N/A
                2 FPW    - Position Works
                3 RPW    - Position Works, orientation is a simplified version.(If you know how to do it the correct way please let me know)
                4 RVW    - Position Works, orientation is a simplified version.(If you know how to do it the correct way please let me know)
                5 FVW    - Position Works
                6 FPB    - Position Works
                7 RPB    - Position Works, orientation is a simplified version.(If you know how to do it the correct way please let me know)
                8 RVB    - Position Works, orientation is a simplified version.(If you know how to do it the correct way please let me know)
                9 FVB    - Position Works
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./../DataTypes/EulerAngles.h"
#include "./../DataTypes/WorldCoordinates.h"
#include "./../DataTypes/Vector.h"
#include <vector>

namespace KDIS {
namespace UTILS {

using KDIS::DATA_TYPE::EulerAngles;
using KDIS::DATA_TYPE::WorldCoordinates;
using KDIS::DATA_TYPE::Vector;
using KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm;
using std::vector;

////////////////////////////////////////////////////////
// A simple matrix class for simplifying the dead reckoning equations.
////////////////////////////////////////////////////////

template<class Type, KUINT8 cols, KUINT8 rows>
class Matrix
{
public:

    Type Data[cols][rows];

    Matrix( void )
    {
        for( KUINT16 i = 0; i < cols; ++i )
        {
            for( KUINT16 j = 0; j < rows; ++j )
            {
                if( i == j )Data[i][j] = 1;
                else Data[i][j] = 0;
            }
        }
    };

    Matrix operator + ( const Matrix & Value )
    {
        Matrix m = *this;
        for( KUINT16 i = 0; i < cols; ++i )
        {
            for( KUINT16 j = 0; j < rows; ++j )
            {
                m.Data[i][j] += Value.Data[i][j];
            }
        }

        return m;
    };

    Matrix & operator += ( const Matrix & Value )
    {
        for( KUINT16 i = 0; i < cols; ++i )
        {
            for( KUINT16 j = 0; j < rows; ++j )
            {
                Data[i][j] += Value.Data[i][j];
            }
        }

        return *this;
    };

    Matrix operator - ( const Matrix & Value )
    {
        Matrix m = *this;
        for( KUINT16 i = 0; i < cols; ++i )
        {
            for( KUINT16 j = 0; j < rows; ++j )
            {
                m.Data[i][j] -= Value.Data[i][j];
            }
        }

        return m;
    };

    Matrix & operator -= ( const Matrix & Value )
    {
        for( KUINT16 i = 0; i < cols; ++i )
        {
            for( KUINT16 j = 0; j < rows; ++j )
            {
                Data[i][j] -= Value.Data[i][j];
            }
        }

        return *this;
    };

    Matrix operator * ( const Matrix & Value )
    {
        Matrix m = *this;
        Type tmp = 0,
             tmp2 = 0,
             sum = 0;

        for( KUINT16 i = 0; i < rows; ++i )
        {
            for( KUINT16 j = 0; j < cols; ++j )
            {
                for( KUINT16 k = 0; k < cols; ++k )
                {
                    tmp += m.Data[i][k] * Value.Data[k][j];
                }

                m.Data[i][j] = tmp;
                tmp = 0;
            }
        }

        return m;
    };

    template<class T>
    Matrix operator * ( const T Value )
    {
        Matrix m = *this;
        for( KUINT16 i = 0; i < cols; ++i )
        {
            for( KUINT16 j = 0; j < rows; ++j )
            {
                m.Data[i][j] *= Value;
            }
        }

        return m;
    };

    template<class T>
    Matrix & operator *= ( const T Value )
    {
        for( KUINT16 i = 0; i < cols; ++i )
        {
            for( KUINT16 j = 0; j < rows; ++j )
            {
                Data[i][j] *= Value;
            }
        }

        return *this;
    };

    Vector operator * ( const Vector& Value )
    {
        Vector res;
        for( KUINT16 i = 0; i < rows; ++i )
        {
            for( KUINT16 j = 0; j < cols; ++j )
            {
                res[i] += Data[i][j] * Value[j];
            }
        }

        return res;
    };

    void inPlanceTranspose()
    {
        if( cols != rows )return;

        for( KUINT16 i = 0; i < rows; ++i )
        {
            for( KUINT16 j = 0; j < i; ++j )
            {
                Type aux = Data[i][j];
                Data[i][j] = Data[j][i];
                Data[j][i] = aux;
            }
        }
    }
};

//////////////////////////////////////////////////////////////////////////
typedef Matrix<KFLOAT32, 3, 3> TMATRIX;

class KDIS_EXPORT DeadReckoningCalculator
{
protected:

    WorldCoordinates m_initPosition;
    Vector m_initLinearVelocity;

    Vector m_initLinearAcceleration;
    Vector m_Ab;
    KBOOL m_bQuaxAxisSet;
    Vector m_quatAxis;

    // Some algorithms are implemented as an integral form for rotation, thus using the time since t0
    KFLOAT32 m_f64Magnitude;

    // Orientation cache
    EulerAngles m_initOrientation, m_initEulerAngularVelocity;
    TMATRIX m_initOrientationMatrix, m_initOrientationMatrixTranspose;

    // Angular velocity cache
    Vector m_initAngularVelocity;
    TMATRIX m_wwMatrix;
    TMATRIX m_SkewOmegaMatrix;

    DeadReckoningAlgorithm m_DRA; // The selected dead reckoning algorithm

    void positionReset( const WorldCoordinates & Position );
    void orientationReset( const EulerAngles & Orientation );
    void angularVelocityReset( const Vector & AngularVelocity );
    void velocityReset( const Vector & LinearVelocity );
    void accelerationReset( const Vector & LinearAcceleration );
    void quatAxisReset(const Vector & QuatAxis);

    EulerAngles toEulerAngularVelocity( const Vector & angVel, const EulerAngles & Orientation );

    void calcOrientation_simplified( EulerAngles & OrientationOut, const KFLOAT32 DeltaTime );
    void calcOrientation( EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset  );

    void computeRotationAxis( const TMATRIX& curOrientationMatrix );
    void computeDRMatrix( TMATRIX & res, const KFLOAT32 totalTimeSinceReset  );
    void computeDRMatrix_asQuat( TMATRIX & res, const KFLOAT32 totalTimeSinceReset  );

    /************************************************************************/
    /* Dead Reckoning Algorithm Implementations                             */
    /************************************************************************/

    // FPW //
    void calcDeadReckoningFPW( WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset);

    // RPW //
    void calcDeadReckoningRPW( WorldCoordinates & PositionOut, EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset );

    // RVW //
    void calcDeadReckoningRVW( WorldCoordinates & PositionOut, EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset );

    // FVW //
    void calcDeadReckoningFVW( WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset );

    // FPB //
    void calcDeadReckoningFPB( WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset);

    // RPB //
    void calcDeadReckoningRPB( WorldCoordinates & PositionOut, EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset );

    // RVB //
    void calcDeadReckoningRVB( WorldCoordinates & PositionOut, EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset );

    // FVB //
    void calcDeadReckoningFVB( WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset );

public:

    DeadReckoningCalculator( void );

    ~DeadReckoningCalculator( void );

    //************************************
    // FullName:    KDIS::UTILS::DeadReckoningCalculator::Reset
    // Author:      Robert Ioiart - 04/05/2010
    // Description: Resets this object. For a local entity should be called before sending out
    //              an entity state PDU so the local entity can dead-reckon itself.
    //              For a remote entity should be called when an ES PDU is received.
    // Parameter:   const Vector & LinearVelocity
    // Parameter:   const Vector & LinearAcceleration
    // Parameter:   const Vector & AngularVelocity - Angular velocity around the DIS body axes.
    // Parameter:   const WorldCoordinates & Position
    // Parameter:   const EulerAngles & Orientation
    // Parameter:   DeadReckoningAlgorithm DRA
    //************************************
    void Reset( const Vector & LinearVelocity, const Vector & LinearAcceleration, const Vector & AngularVelocity,
                const WorldCoordinates & Position, const EulerAngles & Orientation, const Vector & QuatAxis, DeadReckoningAlgorithm DRA );

    //************************************
    // FullName:    KDIS::UTILS::DeadReckoningCalculator::RunAlgorithm
    // Author:      Robert Ioiart - 04/05/2010
    // Description: Steps algorithm for a time step, computing the dead-reckoned position and orientation
    //              based on the values provided at the last Reset.
    // Parameter:   const KFLOAT64 TotalTimeSinceReset
    // Parameter:   WorldCoordinates & PositionOut
    // Parameter:   EulerAngles & OrientationOut
    //************************************
    void RunAlgorithm( const KFLOAT32 TotalTimeSinceReset, WorldCoordinates & PositionOut, EulerAngles & OrientationOut );

	//************************************
    // FullName:    KDIS::DeadReckoningCalculator::GenerateSmoothingPoints
    // Description: When a new update of position is received from another entity, a correction
    //              in position is usually required so that the entity may be depicted in simulation
    //              as accurately as possible.
    //              The preferred method is to gradually correct the position of the entity over a period of time.
    //              This is called smoothing, this function will generate the smoothing points for you.
    // Parameter:   const WorldCoordinates & StartPosition,
    // Parameter:   const WorldCoordinates & EndPosition,
    // Parameter:   KUINT32 NumberOfPoints
    //************************************
    vector<WorldCoordinates> GenerateSmoothingPoints( const WorldCoordinates & StartPosition, const WorldCoordinates & EndPosition, KUINT32 NumberOfPoints );

    //************************************
    // FullName:    KDIS::DeadReckoningCalculator::GenerateSmoothingPoints
    // Description: When a new update of position is received from another entity, a correction
    //              in position is usually required so that the entity may be depicted in simulation
    //              as accurately as possible.
    //              The preferred method is to gradually correct the position of the entity over a period of time.
    //              This is called smoothing, this function will generate the smoothing points for you.
    //
    // Note:        This is the preferred version for generating smoothing points, because it does not
    //              incur the cost of a copy of the vector.
    //
    // Parameter:   const WorldCoordinates & StartPosition,
    // Parameter:   const WorldCoordinates & EndPosition,
    // Parameter:   KUINT32 NumberOfPoints
    // Parameter:   vector<WorldCoordinates> & v
    //************************************
    void GenerateSmoothingPoints( const WorldCoordinates & StartPosition, const WorldCoordinates & EndPosition, KUINT32 NumberOfPoints, vector<WorldCoordinates> & v );
};

}; // END namespace UTILS
}; // END namespace KDIS

