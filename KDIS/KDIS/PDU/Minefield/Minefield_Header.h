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
    class:      Minefield_Header
    DIS:        (6) 1278.1a - 1998
    created:    13/04/2010
    author:     Karl Jones

    purpose:    Contains common attributes for all minefield PDU.

    size:       144 bits / 18 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Minefield_Header : public Header
{
protected:

    EntityIdentifier m_MinefieldID;

public:

    static const KUINT16 MINEFIELD_HEADER_SIZE = 18;

    Minefield_Header( void );

    Minefield_Header( KDataStream & stream ) throw( KException );

    virtual ~Minefield_Header( void );

    //************************************
    // FullName:    KDIS::PDU::Minefield_Header::SetMinefieldID
    //              KDIS::PDU::Minefield_Header::GetMinefieldID
    // Description: The Minefield Identifier (Minefield ID) does not represent an entity but
    //              rather an aggregation of mine entities for the purpose of conserving bandwidth.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetMinefieldID( const EntityIdentifier & ID );
    const EntityIdentifier & GetMinefieldID() const;
    EntityIdentifier & GetMinefieldID();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Header::GetAsString
    // Description: Returns a string representation of the PDU
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Minefield_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Minefield_Header & Value ) const;
    KBOOL operator != ( const Minefield_Header & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
