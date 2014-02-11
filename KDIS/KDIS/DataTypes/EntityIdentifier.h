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
    class:      EntityIdentifier
    created:    18/09/2008
    author:     Karl Jones

    purpose:    Entity Identifier Field found in PDU's. 
				Also known as:
					Object Identifier. - where entity id is object id.
					Event Identifier. - where entity id is event id.
    size:       48 bits / 6 octets
*********************************************************************/

#pragma once

#include "./SimulationIdentifier.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EntityIdentifier : public SimulationIdentifier
{
protected:

    KUINT16 m_ui16EntityID;

public:

    static const KUINT16 ENTITY_IDENTIFER_SIZE = 6;

    EntityIdentifier();

    EntityIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID, KUINT16 EntityID );

    EntityIdentifier( const SimulationIdentifier & SimID, KUINT16 EntityID );

    EntityIdentifier( KDataStream & stream ) throw( KException );

    virtual ~EntityIdentifier();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityIdentifier::SetEntityID
    //              KDIS::DATA_TYPE::EntityIdentifier::GetEntityID
    // Description: Entity ID, also known as 'Object ID', 'Process Numbers', 'Event ID' or 'Reference Number'.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetEntityID( KUINT16 ID );
    KUINT16 GetEntityID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EntityIdentifier & Value ) const;
    KBOOL operator != ( const EntityIdentifier & Value ) const;
    KBOOL operator <  ( const EntityIdentifier & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

