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
    class:      DeadReckoningParameter
    created:    2008/09/18
    author:     Karl Jones

    purpose:    Parameters for dead reckoning the position and orientation
                of the entity.
    size:       320 bits / 40 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm;

class KDIS_EXPORT DeadReckoningParameter : public DataTypeBase
{
protected:

    KUINT8 m_ui8DeadRecknoningAlgorithm;

    KOCTET m_OtherParams[15]; // Undefined

    Vector m_LinearAcceleration;

    Vector m_AngularVelocity;

public:

    static const KUINT16 DEAD_RECKONING_PARAMETER_SIZE = 40;

    DeadReckoningParameter( void );

    DeadReckoningParameter( KDataStream & stream ) throw( KException );

    DeadReckoningParameter( DeadReckoningAlgorithm DRA, const Vector & LinearAcceleration,
                            const Vector & AngularVelocity );

    virtual ~DeadReckoningParameter( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::SetDeadReckoningAlgorithm
    //              KDIS::DATA_TYPE::DeadReckoningParameter::GetDeadReckoningAlgorithm
    // Description: Dead Reckoning Algorithm
    // Parameter:   DeadReckoningAlgorithm DRA, void
    //************************************
    void SetDeadReckoningAlgorithm( DeadReckoningAlgorithm DRA );
    DeadReckoningAlgorithm GetDeadReckoningAlgorithm() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::SetLinearAcceleration
    //              KDIS::DATA_TYPE::DeadReckoningParameter::GetLinearAcceleration
    // Description: Linear Acceleration in m/s.
    // Parameter:   const Vector & LA, void
    //************************************
    void SetLinearAcceleration( const Vector & LA );
    const Vector & GetLinearAcceleration() const;
    Vector & GetLinearAcceleration();

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::SetAngularVelocity
    //              KDIS::DATA_TYPE::DeadReckoningParameter::GetAngularVelocity
    // Description: Angular Velocity
    // Parameter:   const EulerAngles & AV
    //************************************
    void SetAngularVelocity( const Vector & AV );
    const Vector & GetAngularVelocity() const;
    Vector & GetAngularVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::SetQuatAxis
    //              KDIS::DATA_TYPE::DeadReckoningParameter::GetQuatAxis
    // Description: Updated DIS - Geometric Interpretation of Orientation Dead Reckoning / Quaternion axis
    // Parameter:   const EulerAngles & AV
    //************************************
    void SetQuatAxis( const Vector & QA );
    const Vector GetQuatAxis() const;
    Vector GetQuatAxis();


    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const DeadReckoningParameter & Value ) const;
    KBOOL operator != ( const DeadReckoningParameter & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
