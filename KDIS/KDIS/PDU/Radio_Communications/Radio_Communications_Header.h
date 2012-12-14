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
    class:      Radio_Communications_Header
    DIS:        (5) 1278.1 - 1995
    created:    21/10/2008
    author:     Karl Jones

    purpose:    Radio Communications Header. 
    Size:       160 bits / 20 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Radio_Communications_Header : public Header
{
protected:

    EntityIdentifier m_EntityID;

    KUINT16 m_ui16RadioID;

public:

    static const KUINT16 RADIO_COMMUNICATIONS_HEADER_SIZE = 20;

    Radio_Communications_Header( void );

    Radio_Communications_Header( KDataStream & stream ) throw( KException );

    Radio_Communications_Header( const EntityIdentifier & ID, KUINT16 RadioID );

    virtual ~Radio_Communications_Header( void );

    //************************************
    // FullName:    KDIS::PDU::Radio_Communications_Header::SetEntityID
    //              KDIS::PDU::Radio_Communications_Header::GetEntityID
    // Description: Entity that is the source of the radio transmission
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetEntityID ( const EntityIdentifier & ID );
    const EntityIdentifier & GetEntityID() const;
    EntityIdentifier & GetEntityID();

    //************************************
    // FullName:    KDIS::PDU::Radio_Communications_Header::SetRadioID
    //              KDIS::PDU::Radio_Communications_Header::GetRadioID
    // Description: Identifies a radio/communications device belonging to the entity.
    //              IDs should be assigned sequentially to entities, starting with 1.
    // Parameter:   KUINT16 ID
    //************************************
    void SetRadioID( KUINT16 ID );
    KUINT16 GetRadioID() const;

    //************************************
    // FullName:    KDIS::PDU::Radio_Communications_Header::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Radio_Communications_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Radio_Communications_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Radio_Communications_Header & Value ) const;
    KBOOL operator != ( const Radio_Communications_Header & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
