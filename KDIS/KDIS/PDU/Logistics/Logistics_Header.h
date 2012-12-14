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
    class:      Logistics_Header
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/17
    author:     Karl Jones

    purpose:    Header for all Logistics PDU's
    Size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Logistics_Header : public Header
{
protected:

    EntityIdentifier m_ReceivingEntity;

    EntityIdentifier m_SupplyingEntity;

public:

    static const KUINT16 LOGISTICS_HEADER_SIZE = 24;

    Logistics_Header( void );

    Logistics_Header( const EntityIdentifier & ReceivingEntityID, const EntityIdentifier & SupplyingEntityID );

    virtual ~Logistics_Header( void );

    //************************************
    // FullName:    KDIS::PDU::Logistics_Header::SetReceivingEntity
    //              KDIS::PDU::Logistics_Header::GetReceivingEntity
    // Description: Entity Receiving the supplies/repairs
    // Parameter:   const EntityIdentifier & EI
    //************************************
    void SetReceivingEntity( const EntityIdentifier & EI );
    const EntityIdentifier & GetReceivingEntity() const;
    EntityIdentifier & GetReceivingEntity();

    //************************************
    // FullName:    KDIS::PDU::Logistics_Header::SetSupplyingEntity
    //              KDIS::PDU::Logistics_Header::GetSupplyingEntity
    // Description: Entity providing the supplies/repairs
    // Parameter:   const EntityIdentifier & EI, void
    //************************************
    void SetSupplyingEntity( const EntityIdentifier & EI );
    const EntityIdentifier & GetSupplyingEntity() const;
    EntityIdentifier & GetSupplyingEntity();

    //************************************
    // FullName:    KDIS::PDU::Logistics_Header::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Logistics_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Logistics_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Logistics_Header & Value ) const;
    KBOOL operator != ( const Logistics_Header & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
