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
    class:      Resupply_Received_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Resupply Received PDU
    Size:       224 bits / 28 octets + ( 96 bits / 12 octets * ( number of supplies ) )
*********************************************************************/

#pragma once

#include "./Logistics_Header.h"
#include "./../../DataTypes/Supplies.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::Supplies;
using std::vector;

class KDIS_EXPORT Resupply_Received_PDU : public Logistics_Header
{
protected:

    KUINT8 m_ui8NumSupplyTypes;

    KUINT16 m_ui16Padding1;

    KUINT8 m_ui8Padding2;

    vector<Supplies> m_vSupplies;

public:

    static const KUINT16 RESUPPLY_RECEIVED_PDU_SIZE = 28; // Does not include supply size

    Resupply_Received_PDU( void );

    Resupply_Received_PDU( KDataStream & stream ) throw( KException );

    Resupply_Received_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity );

    virtual ~Resupply_Received_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::SetNumberOfSupplyTypes
    //              KDIS::PDU::Resupply_Received_PDU::GetNumberOfSupplyTypes
    // Description: How many supplies are being provided.
    //              This value is calculated automatically by
    //              the number of supplies, only change
    //              if you know what you are doing
    // Parameter:   KUINT8  UI, void
    //************************************
    void SetNumberOfSupplyTypes( KUINT8  UI );
    KUINT8 GetNumberOfSupplyTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::AddSupply
    //              KDIS::PDU::Resupply_Received_PDU::SetSupplies
    //              KDIS::PDU::Resupply_Received_PDU::GetSupplies
    // Description: Add a supply, updates Number Of Supply Types and
    //              PDU size fields automatically.
    // Parameter:   const Supplies & S, void
    //************************************
    void AddSupply( const Supplies & S );
    void SetSupplies( const vector<Supplies> & S );
    vector<Supplies> GetSupplies() const;

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Resupply_Received_PDU & Value ) const;
    KBOOL operator != ( const Resupply_Received_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
