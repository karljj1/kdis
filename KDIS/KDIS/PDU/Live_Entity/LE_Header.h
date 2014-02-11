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
    class:      LE_Header
    DIS:        (6) 1278.1a - 1998
    created:    29/06/2010
    author:     Karl Jones

    purpose:    Header for all PDU's from the Live Entity (LE) Family.

    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/LE_EntityIdentifier.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT LE_Header : public Header
{
protected:

    KDIS::DATA_TYPE::LE_EntityIdentifier m_EntID;

public:

    static const KUINT16 LE_HEADER_SIZE = 16;

    LE_Header();

	LE_Header( const Header & H );

    LE_Header( KDataStream & stream ) throw( KException );

	LE_Header( const Header & H, KDataStream & stream ) throw( KException );

    virtual ~LE_Header();

    //************************************
    // FullName:    KDIS::PDU::LE_Header::SetLiveEntityID
    //              KDIS::PDU::LE_Header::GetLiveEntityID
    // Description: Identifies the entity issuing the PDU.
    // Parameter:   const LE_EntityIdentifier & ID
    //************************************
    void SetLiveEntityID( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );
    const KDIS::DATA_TYPE::LE_EntityIdentifier & GetLiveEntityID() const;
    KDIS::DATA_TYPE::LE_EntityIdentifier & GetLiveEntityID();

    //************************************
    // FullName:    KDIS::PDU::LE_Header::SetSubprotocol
    //              KDIS::PDU::LE_Header::GetSubprotocol
    // Description: This field shall specify the sub protocol to be used to decode the PDU.
    //              The value of zero is reserved for PDUs complying to the published standard.
    // Parameter:   KUINT8 S
    //************************************
    void SetSubprotocol( KUINT8 S );
    KUINT8 GetSubprotocol() const;

    //************************************
    // FullName:    KDIS::PDU::LE_Header::GetAsString
    // Description: Returns a string representation of the PDU
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::LE_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::LE_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_Header & Value ) const;
    KBOOL operator != ( const LE_Header & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
