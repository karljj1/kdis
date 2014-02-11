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
    class:      Simulation_Management_Header
    DIS:        (5) 1278.1 - 1995
    created:    17/09/2008
    author:     Karl Jones

    purpose:    Contains common fields found in Simulation management PDU.
    Size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Simulation_Management_Header : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_OriginatingEntityID;

    KDIS::DATA_TYPE::EntityIdentifier m_ReceivingEntityID;

public:

    static const KUINT16 SIMULATION_MANAGEMENT_HEADER_SIZE = 24;

    Simulation_Management_Header();

    Simulation_Management_Header( KDataStream & stream ) throw( KException );

	Simulation_Management_Header( const Header & H );

	Simulation_Management_Header( const Header & H, KDataStream & stream ) throw( KException );

    Simulation_Management_Header( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID );

    virtual ~Simulation_Management_Header();

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::SetOriginatingEntityID
    //              KDIS::PDU::Simulation_Management_Header::GetOriginatingEntityID
    // Description: Originating Entity ID
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetOriginatingEntityID ( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetOriginatingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetOriginatingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::SetReceivingEntityID
    //              KDIS::PDU::Simulation_Management_Header::GetReceivingEntityID
    // Description: Receiving Entity ID:
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetReceivingEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetReceivingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetReceivingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Simulation_Management_Header & Value ) const;
    KBOOL operator != ( const Simulation_Management_Header & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
