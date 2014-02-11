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
    class:      IO_Header
    DIS:        (7) 1278.1-2012
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

class KDIS_EXPORT IO_Header : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_OriginatingEntityID;

public:

    static const KUINT16 IO_HEADER_SIZE = 18;

    IO_Header();

	IO_Header( const Header & H );

	IO_Header( KDataStream & stream ) throw( KException );

	IO_Header( const Header & H, KDataStream & stream ) throw( KException );

    IO_Header( const KDIS::DATA_TYPE::EntityIdentifier & OrigID );

    virtual ~IO_Header();

    //************************************
    // FullName:    KDIS::PDU::IO_Header::SetOriginatingEntityID
    //              KDIS::PDU::IO_Header::GetOriginatingEntityID
    // Description: Originating Entity ID, the simulation that is issuing the PDU.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetOriginatingEntityID ( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetOriginatingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetOriginatingEntityID();

    //************************************
    // FullName:    KDIS::PDU::IO_Header::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
