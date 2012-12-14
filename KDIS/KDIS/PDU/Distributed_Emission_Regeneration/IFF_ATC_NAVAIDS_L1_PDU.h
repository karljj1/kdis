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
    class:      IFF_ATC_NAVAIDS_L1_PDU
    DIS:        (6) 1278.1A - 1998
    created:    2008/12/05
    author:     Karl Jones

    purpose:    All IFF/ATC/NAVAIDS shall have a layer 1 as their first
                layer.

                Additional layers shall contain the following types
                of data:

                Layer 2 - Infomation about radiating characteristics of the system
                          described(for signal originators) and operational parameters
                          not changeableby the system operator(for both originators and
                          responders).

                Layer 6 - Information sufficient for emission regeneration (for originators)
                          or sufficient for description of signal emission rate by type
                          (for responders).

                Layer 7 - Information sufficient for correlation of response sets to originating events (for responders).

                Note: Not all layers have been defined.

    Size:       480 bits / 60 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/SystemIdentifier.h"
#include "./../../DataTypes/FundamentalOperationalData.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::Vector;
using KDIS::DATA_TYPE::SystemIdentifier;
using KDIS::DATA_TYPE::FundamentalOperationalData;

class KDIS_EXPORT IFF_ATC_NAVAIDS_L1_PDU : public Header
{
protected:

    EntityIdentifier m_EmittingEntityID;

    EntityIdentifier m_EventID;

    Vector m_Location;

    SystemIdentifier m_SystemID;

    KUINT16 m_ui16Padding;

    FundamentalOperationalData m_FOD;

public:

    static const KUINT16 IFF_ATC_NAVAIDS_L1_PDU_SIZE = 60;

    IFF_ATC_NAVAIDS_L1_PDU( void );

    IFF_ATC_NAVAIDS_L1_PDU( KDataStream & stream ) throw( KException );

    IFF_ATC_NAVAIDS_L1_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID, const Vector & Location,
                            const SystemIdentifier & ID, const FundamentalOperationalData & FOD );

    virtual ~IFF_ATC_NAVAIDS_L1_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::SetEmittingEntityID
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::GetEmittingEntityID
    // Description: Emitting Entity ID
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEmittingEntityID ( const EntityIdentifier & ID );
    const EntityIdentifier & GetEmittingEntityID() const;
    EntityIdentifier & GetEmittingEntityID();

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::SetEventID
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::GetEventID
    // Description: Event ID. For associated events.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEventID( const EntityIdentifier & ID );
    const EntityIdentifier & GetEventID() const;
    EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::SetLocation
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::GetLocation
    // Description: Location of the emitting system relative to
    //              the emitting entity's coordinate system.
    //              Represented as a Entity Coordinate Vector
    // Parameter:   const Vector & L, void
    //************************************
    void SetLocation( const Vector & L );
    const Vector & GetLocation() const;
    Vector & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::SetSystemIdentifier
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::GetSystemIdentifier
    // Description: Identifies the emitting system.
    // Parameter:   const SystemIdentifier & ID, void
    //************************************
    void SetSystemIdentifier( const SystemIdentifier & ID );
    const SystemIdentifier & GetSystemIdentifier() const;
    SystemIdentifier & GetSystemIdentifier();

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::SetFundamentalOperationalData
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::GetFundamentalOperationalData
    // Description: Identifies certain basic operational data for an emitting system.
    // Parameter:   const FundamentalOperationalData & FOD, void
    //************************************
    void SetFundamentalOperationalData( const FundamentalOperationalData & FOD );
    const FundamentalOperationalData & GetFundamentalOperationalData() const;
    FundamentalOperationalData & GetFundamentalOperationalData();

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L1_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IFF_ATC_NAVAIDS_L1_PDU & Value ) const;
    KBOOL operator != ( const IFF_ATC_NAVAIDS_L1_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
