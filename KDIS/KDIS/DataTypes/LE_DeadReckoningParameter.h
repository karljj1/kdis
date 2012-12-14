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
    class:      LE_DeadReckoningParameter
    created:    2008/09/18
    author:     Karl Jones

    purpose:    Parameters for dead reckoning the position and orientation
                of the entity. For Live Entities the acceleration and velocity
                vectors are using KFIXED data types.
    size:       56 bits / 7 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./LE_Vector.h"
#include "./LE_EulerAngles.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm;

class KDIS_EXPORT LE_DeadReckoningParameter : public DataTypeBase
{
protected:

    KUINT8 m_ui8DeadRecknoningAlgorithm;

    LE_Vector8_3 m_LinearAcceleration;

    LE_Vector8_3 m_AngularVelocity;

public:

    static const KUINT16 LE_DEAD_RECKONING_PARAMETER_SIZE = 7;

    LE_DeadReckoningParameter( void );

    LE_DeadReckoningParameter( KDataStream & stream ) throw( KException );

    LE_DeadReckoningParameter( DeadReckoningAlgorithm DRA, const LE_Vector8_3 & LinearAcceleration,
                               const LE_Vector8_3 & AngularVelocity );

    virtual ~LE_DeadReckoningParameter( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::SetDeadReckoningAlgorithm
    //              KDIS::DATA_TYPE::LE_DeadReckoningParameter::GetDeadReckoningAlgorithm
    // Description: Dead Reckoning Algorithm
    // Parameter:   DeadReckoningAlgorithm DRA, void
    //************************************
    void SetDeadReckoningAlgorithm( DeadReckoningAlgorithm DRA );
    DeadReckoningAlgorithm GetDeadReckoningAlgorithm() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::SetLinearAcceleration
    //              KDIS::DATA_TYPE::LE_DeadReckoningParameter::GetLinearAcceleration
    // Description: Linear acceleration in decimeters per second.
    // Parameter:   const LE_Vector8_3 & LA, void
    //************************************
    void SetLinearAcceleration( const LE_Vector8_3 & LA );
    const LE_Vector8_3 & GetLinearAcceleration() const;
    LE_Vector8_3 & GetLinearAcceleration();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::SetAngularVelocity
    //              KDIS::DATA_TYPE::LE_DeadReckoningParameter::GetAngularVelocity
    // Description: Angular velocity in radians per second.
    // Parameter:   const EulerAngles & AV
    //************************************
    void SetAngularVelocity( const LE_Vector8_3 & AV );
    const LE_Vector8_3 & GetAngularVelocity() const;
    LE_Vector8_3 & GetAngularVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_DeadReckoningParameter & Value ) const;
    KBOOL operator != ( const LE_DeadReckoningParameter & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
