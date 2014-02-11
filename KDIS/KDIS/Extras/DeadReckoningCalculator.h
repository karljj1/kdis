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

////////////////////////////////////////////////////////
// A simple matrix class for simplifying the dead reckoning equations.
////////////////////////////////////////////////////////

template<class Type, KUINT8 cols, KUINT8 rows>
class Matrix
{
public:

    Type Data[cols][rows];

    Matrix()
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

    KDIS::DATA_TYPE::Vector operator * ( const KDIS::DATA_TYPE::Vector& Value )
    {
        KDIS::DATA_TYPE::Vector res;
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

    KDIS::DATA_TYPE::WorldCoordinates m_initPosition;
    KDIS::DATA_TYPE::Vector m_initLinearVelocity;

    KDIS::DATA_TYPE::Vector m_initLinearAcceleration;
    KDIS::DATA_TYPE::Vector m_Ab;
    KBOOL m_bQuaxAxisSet;
    KDIS::DATA_TYPE::Vector m_quatAxis;

    // Some algorithms are implemented as an integral form for rotation, thus using the time since t0
    KFLOAT32 m_f64Magnitude;

    // Orientation cache
    KDIS::DATA_TYPE::EulerAngles m_initOrientation, m_initEulerAngularVelocity;
    TMATRIX m_initOrientationMatrix, m_initOrientationMatrixTranspose;

    // Angular velocity cache
    KDIS::DATA_TYPE::Vector m_initAngularVelocity;
    TMATRIX m_wwMatrix;
    TMATRIX m_SkewOmegaMatrix;

	KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm m_DRA; // The selected dead reckoning algorithm

    void positionReset( const KDIS::DATA_TYPE::WorldCoordinates & Position );
    void orientationReset( const KDIS::DATA_TYPE::EulerAngles & Orientation );
    void angularVelocityReset( const KDIS::DATA_TYPE::Vector & AngularVelocity );
    void velocityReset( const KDIS::DATA_TYPE::Vector & LinearVelocity );
    void accelerationReset( const KDIS::DATA_TYPE::Vector & LinearAcceleration );
    void quatAxisReset(const KDIS::DATA_TYPE::Vector & QuatAxis);

    KDIS::DATA_TYPE::EulerAngles toEulerAngularVelocity( const KDIS::DATA_TYPE::Vector & angVel, const KDIS::DATA_TYPE::EulerAngles & Orientation );

    void calcOrientation_simplified( KDIS::DATA_TYPE::EulerAngles & OrientationOut, const KFLOAT32 DeltaTime );
    void calcOrientation( KDIS::DATA_TYPE::EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset  );

    void computeRotationAxis( const TMATRIX& curOrientationMatrix );
    void computeDRMatrix( TMATRIX & res, const KFLOAT32 totalTimeSinceReset  );
    void computeDRMatrix_asQuat( TMATRIX & res, const KFLOAT32 totalTimeSinceReset  );

    /************************************************************************/
    /* Dead Reckoning Algorithm Implementations                             */
    /************************************************************************/

    // FPW //
    void calcDeadReckoningFPW( KDIS::DATA_TYPE::WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset);

    // RPW //
    void calcDeadReckoningRPW( KDIS::DATA_TYPE::WorldCoordinates & PositionOut, KDIS::DATA_TYPE::EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset );

    // RVW //
    void calcDeadReckoningRVW( KDIS::DATA_TYPE::WorldCoordinates & PositionOut,KDIS::DATA_TYPE::EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset );

    // FVW //
    void calcDeadReckoningFVW( KDIS::DATA_TYPE::WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset );

    // FPB //
    void calcDeadReckoningFPB( KDIS::DATA_TYPE::WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset);

    // RPB //
    void calcDeadReckoningRPB( KDIS::DATA_TYPE::WorldCoordinates & PositionOut, KDIS::DATA_TYPE::EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset );

    // RVB //
    void calcDeadReckoningRVB( KDIS::DATA_TYPE::WorldCoordinates & PositionOut, KDIS::DATA_TYPE::EulerAngles & OrientationOut, const KFLOAT32 totalTimeSinceReset );

    // FVB //
    void calcDeadReckoningFVB( KDIS::DATA_TYPE::WorldCoordinates & PositionOut, const KFLOAT32 totalTimeSinceReset );

public:

    DeadReckoningCalculator();

    ~DeadReckoningCalculator();

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
    void Reset( const KDIS::DATA_TYPE::Vector & LinearVelocity, const KDIS::DATA_TYPE::Vector & LinearAcceleration, const KDIS::DATA_TYPE::Vector & AngularVelocity,
		        const KDIS::DATA_TYPE::WorldCoordinates & Position, const KDIS::DATA_TYPE::EulerAngles & Orientation, const KDIS::DATA_TYPE::Vector & QuatAxis, KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm DRA );

    //************************************
    // FullName:    KDIS::UTILS::DeadReckoningCalculator::RunAlgorithm
    // Author:      Robert Ioiart - 04/05/2010
    // Description: Steps algorithm for a time step, computing the dead-reckoned position and orientation
    //              based on the values provided at the last Reset.
    // Parameter:   const KFLOAT64 TotalTimeSinceReset
    // Parameter:   WorldCoordinates & PositionOut
    // Parameter:   EulerAngles & OrientationOut
    //************************************
    void RunAlgorithm( const KFLOAT32 TotalTimeSinceReset, KDIS::DATA_TYPE::WorldCoordinates & PositionOut, KDIS::DATA_TYPE::EulerAngles & OrientationOut );

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
	std::vector<KDIS::DATA_TYPE::WorldCoordinates> GenerateSmoothingPoints( const KDIS::DATA_TYPE::WorldCoordinates & StartPosition, const KDIS::DATA_TYPE::WorldCoordinates & EndPosition, KUINT32 NumberOfPoints );

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
	void GenerateSmoothingPoints( const KDIS::DATA_TYPE::WorldCoordinates & StartPosition, const KDIS::DATA_TYPE::WorldCoordinates & EndPosition, KUINT32 NumberOfPoints, std::vector<KDIS::DATA_TYPE::WorldCoordinates> & v );
};

} // END namespace UTILS
} // END namespace KDIS

