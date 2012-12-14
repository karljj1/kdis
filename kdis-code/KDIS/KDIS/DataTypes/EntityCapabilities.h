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
    class:      EntityCapabilities
    created:    2008/09/24
    author:     Karl Jones

    purpose:    Collection of bits to describe the capabilities of the entity
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EntityCapabilities :  public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT32   m_AmmunitionSupply : 1;
            KUINT32   m_FuelSupply       : 1;
            KUINT32   m_RecoveryService  : 1;
            KUINT32   m_RepairService    : 1;
            KUINT32   m_Unused           : 28;
        };
        KUINT32 m_ui16Data;
    };

public:

    static const KUINT16 ENTITY_CAPABILITIES_SIZE = 4;

    EntityCapabilities( void );

    EntityCapabilities( KDataStream & stream ) throw( KException );

    EntityCapabilities( KBOOL AmunitionSupply, KBOOL FuelSupply, KBOOL RecoveryService, KBOOL RepairService );

    virtual ~EntityCapabilities( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetHasAmmunitionSupply
    //              KDIS::DATA_TYPE::EntityCapabilities::HasAmmunitionSupply
    // Description: Does the entity have a ammunition supply
    // Parameter:   KBOOL HAS, void
    //************************************
    void SetHasAmmunitionSupply( KBOOL HAS );
    KBOOL HasAmmunitionSupply() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetHasFuelSupply
    //              KDIS::DATA_TYPE::EntityCapabilities::HasFuelSupply
    // Description: Does the entity have a fuel supply
    // Parameter:   KBOOL HAS, void
    //************************************
    void SetHasFuelSupply( KBOOL HAS );
    KBOOL HasFuelSupply() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetHasRecoveryService
    //              KDIS::DATA_TYPE::EntityCapabilities::HasRecoveryService
    // Description: Does the entity have a recovery service, such as towing
    // Parameter:   KBOOL HAS, void
    //************************************
    void SetHasRecoveryService( KBOOL HAS );
    KBOOL HasRecoveryService() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetHasRepairService
    //              KDIS::DATA_TYPE::EntityCapabilities::HasRepairService
    // Description: Does the entity have a repair service
    // Parameter:   KBOOL HAS, void
    //************************************
    void SetHasRepairService( KBOOL HAS );
    KBOOL HasRepairService() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetAllFields
    //              KDIS::DATA_TYPE::EntityCapabilities::GetAllFields
    // Description: 4 octet length field with all the bits set
    // Parameter:   KUINT32 All, void
    //************************************
    void SetAllFields( KUINT32 All );
    KUINT32 GetAllFields() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EntityCapabilities & Value ) const;
    KBOOL operator != ( const EntityCapabilities & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

