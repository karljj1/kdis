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

#include "./EntityIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityIdentifier::EntityIdentifier() :
    m_ui16EntityID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier::EntityIdentifier( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier::EntityIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID, KUINT16 EntityID ) :
    SimulationIdentifier( SiteID, ApplicatonID ),
    m_ui16EntityID( EntityID )
{
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier::EntityIdentifier( const SimulationIdentifier & SimID, KUINT16 EntityID ) :
    SimulationIdentifier( SimID ),
    m_ui16EntityID( EntityID )
{
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier::~EntityIdentifier()
{
}

//////////////////////////////////////////////////////////////////////////

void EntityIdentifier::SetEntityID( KUINT16 ID )
{
    m_ui16EntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 EntityIdentifier::GetEntityID() const
{
    return m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

KString EntityIdentifier::GetAsString() const
{
    KStringStream ss;

    ss << SimulationIdentifier::GetAsString()
       << "Object:      " << m_ui16EntityID << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EntityIdentifier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < EntityIdentifier::ENTITY_IDENTIFER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    SimulationIdentifier::Decode( stream );
    stream >> m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EntityIdentifier::Encode() const
{
    KDataStream stream;

    EntityIdentifier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EntityIdentifier::Encode( KDataStream & stream ) const
{
    SimulationIdentifier::Encode( stream );
    stream << m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityIdentifier::operator == ( const EntityIdentifier & Value ) const
{
    if( SimulationIdentifier::operator !=( Value ) )             return false;
    if( m_ui16EntityID                 != Value.m_ui16EntityID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityIdentifier::operator != ( const EntityIdentifier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityIdentifier::operator <  ( const EntityIdentifier & Value ) const
{
    // We will bit shift all 3 fields into a single KUINT64, this will generate a new unique value which we can then use for comparison.
    // bits 0-15  = SiteID
    // bits 16-31 = ApplicationID
    // bits 32-47 = EntityID
    // bits 48-63 = 0
    KUINT64 ui64ThisCmpVal = 0, ui64OtherCmpVal = 0;

    ui64ThisCmpVal = m_ui16SiteID | ( KUINT64 )m_ui16ApplicationID << 16 | ( KUINT64 )m_ui16EntityID << 32;
    ui64OtherCmpVal = Value.m_ui16SiteID | ( KUINT64 )Value.m_ui16ApplicationID << 16 | ( KUINT64 )Value.m_ui16EntityID << 32;

    return ui64ThisCmpVal < ui64OtherCmpVal;
}

//////////////////////////////////////////////////////////////////////////
