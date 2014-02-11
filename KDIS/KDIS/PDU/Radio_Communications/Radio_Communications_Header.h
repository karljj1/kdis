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

class KDIS_EXPORT Radio_Communications_Header : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_EntityID;

    KUINT16 m_ui16RadioID;

public:

    static const KUINT16 RADIO_COMMUNICATIONS_HEADER_SIZE = 20;

    Radio_Communications_Header();

	Radio_Communications_Header( const Header & H );

    Radio_Communications_Header( KDataStream & stream ) throw( KException );

	Radio_Communications_Header( const Header & H, KDataStream & stream ) throw( KException );

    Radio_Communications_Header( const KDIS::DATA_TYPE::EntityIdentifier & ID, KUINT16 RadioID );

    virtual ~Radio_Communications_Header();

    //************************************
    // FullName:    KDIS::PDU::Radio_Communications_Header::SetEntityID
    //              KDIS::PDU::Radio_Communications_Header::GetEntityID
    // Description: For attached radios, this field should identify the Entity Identifier record 
	//              or Object Identifier record to which the radio is attached. 
	//              For unattached radios, this field should contain the Unattached Identifier record.
	//              Also known as Radio Reference ID in DIS 7.
	//              Note: The combination of the Radio Reference ID and the Radio Number field uniquely identifies a
	//              particular radio within a simulation exercise. This combination is referred to as the Radio Identifier.
	//              The Radio Identifier is used to associate Transmitter, Signal, and Receiver PDUs with the same radio.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetEntityID ( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetEntityID();

    //************************************
    // FullName:    KDIS::PDU::Radio_Communications_Header::SetRadioID
    //              KDIS::PDU::Radio_Communications_Header::GetRadioID
    // Description: Identifies a radio/communications device belonging to the entity.
    //              IDs should be assigned sequentially to entities, starting with 1.
	//              Also known as Radio Number in DIS 7.
	//              Note: The combination of the Radio Reference ID and the Radio Number field uniquely identifies a
	//              particular radio within a simulation exercise. This combination is referred to as the Radio Identifier.
	//              The Radio Identifier is used to associate Transmitter, Signal, and Receiver PDUs with the same radio.
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
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
