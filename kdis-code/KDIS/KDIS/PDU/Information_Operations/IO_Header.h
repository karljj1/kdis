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
    class:      IO_Header
    DIS:        (7) 1278.1-200x
    created:    12/11/2010
    author:     Karl Jones

    purpose:    Contains common fields found in information operations PDU.
                Information operations (IO) are the integrated employment of electronic warfare (EW),
                computer network operations (CNO), psychological operations (PSYOP),
                military deception (MILDEC), and operations security (OPSEC), along with
                specific supporting capabilities, to influence, disrupt, corrupt, or otherwise
                affect enemy information and decision making while protecting friendly information
                operations.

    Size:       144 bits / 18 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/StandardVariable.h"
#include "./../../Extras/KRef_Ptr.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::StandardVariable;

class KDIS_EXPORT IO_Header : public Header
{
protected:

    EntityIdentifier m_OriginatingEntityID;

public:

    static const KUINT16 IO_HEADER_SIZE = 18;

    IO_Header( void );

    IO_Header( const EntityIdentifier & OrigID );

    IO_Header( KDataStream & stream ) throw( KException );

    virtual ~IO_Header( void );

    //************************************
    // FullName:    KDIS::PDU::IO_Header::SetOriginatingEntityID
    //              KDIS::PDU::IO_Header::GetOriginatingEntityID
    // Description: Originating Entity ID, the simulation that is issuing the PDU.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetOriginatingEntityID ( const EntityIdentifier & ID );
    const EntityIdentifier & GetOriginatingEntityID() const;
    EntityIdentifier & GetOriginatingEntityID();

    //************************************
    // FullName:    KDIS::PDU::IO_Header::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::IO_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IO_Header & Value ) const;
    KBOOL operator != ( const IO_Header & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
