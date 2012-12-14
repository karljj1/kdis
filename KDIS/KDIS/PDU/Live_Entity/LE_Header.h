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

using KDIS::DATA_TYPE::LE_EntityIdentifier;

class KDIS_EXPORT LE_Header : public Header
{
protected:

    LE_EntityIdentifier m_EntID;

public:

    static const KUINT16 LE_HEADER_SIZE = 16;

    LE_Header( void );

    LE_Header( KDataStream & stream ) throw( KException );

    virtual ~LE_Header( void );

    //************************************
    // FullName:    KDIS::PDU::LE_Header::SetLiveEntityID
    //              KDIS::PDU::LE_Header::GetLiveEntityID
    // Description: Identifies the entity issuing the PDU.
    // Parameter:   const LE_EntityIdentifier & ID
    //************************************
    void SetLiveEntityID( const LE_EntityIdentifier & ID );
    const LE_EntityIdentifier & GetLiveEntityID() const;
    LE_EntityIdentifier & GetLiveEntityID();

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
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
