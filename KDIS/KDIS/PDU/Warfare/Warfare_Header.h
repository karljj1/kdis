/*********************************************************************
Copyright 2013 KDIS
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
    class:      Fire_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/10/13
    author:     Karl Jones

    purpose:    Warfare PDU family header
    Size:       288 bits / 36 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Warfare_Header : public Header
{
protected:

    EntityIdentifier m_FiringEntityID;

    EntityIdentifier m_TargetEntityID;

    EntityIdentifier m_MunitionID;

    EntityIdentifier m_EventID;

public:

    static const KUINT16 WARFARE_HEADER_SIZE = 36;

    Warfare_Header( void );

    Warfare_Header( const EntityIdentifier & FiringEntID, const EntityIdentifier & TargetEntID,
                    const EntityIdentifier & MunitionID, const EntityIdentifier & EventID );

    virtual ~Warfare_Header( void );

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::SetFiringEntityID
    //              KDIS::PDU::Warfare_Header::GetFiringEntityID
    // Description: Firing Entity.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetFiringEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetFiringEntityID() const;
    EntityIdentifier & GetFiringEntityID();

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::SetTargetEntityID
    //              KDIS::PDU::Warfare_Header::GetTargetEntityID
    // Description: Target Entity. If target is unknown the ID
    //              shall contain the symbolic value: TARGET_ID_UNKNOWN.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetTargetEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetTargetEntityID() const;
    EntityIdentifier & GetTargetEntityID();

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::SetMunitionID
    //              KDIS::PDU::Warfare_Header::GetMunitionID
    // Description: Munition ID. If the munition is not tracked
    //              the ID shall contain the symbolic value: MUNITION_NOT_TRACKED.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetMunitionID( const EntityIdentifier & ID );
    const EntityIdentifier & GetMunitionID() const;
    EntityIdentifier & GetMunitionID();

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::SetEventID
    //              KDIS::PDU::Warfare_Header::GetEventID
    // Description: Event ID. Used to associate related firing/detonation
    //              events. If a detonation event if not proceeded
    //              by a firing event then the value shall be 0 (e.g land mines)
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEventID( const EntityIdentifier & ID );
    const EntityIdentifier & GetEventID() const;
    EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Warfare_Header & Value ) const;
    KBOOL operator != ( const Warfare_Header & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
