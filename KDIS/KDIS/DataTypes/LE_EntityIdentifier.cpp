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

#include "./LE_EntityIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier::LE_EntityIdentifier() :
    m_ui8SiteID( 0 ),
    m_ui8ApplicationID( 0 ),
    m_ui16EntityID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier::LE_EntityIdentifier( KUINT8 SiteID, KUINT8 ApplicatonID, KUINT16 EntityID ) :
    m_ui8SiteID( SiteID ),
    m_ui8ApplicationID( ApplicatonID ),
    m_ui16EntityID( EntityID )
{
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier::LE_EntityIdentifier( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier::~LE_EntityIdentifier()
{
}

//////////////////////////////////////////////////////////////////////////

void LE_EntityIdentifier::SetSiteID( KUINT8 ID )
{
    m_ui8SiteID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LE_EntityIdentifier::GetSiteID() const
{
    return m_ui8SiteID;
}

//////////////////////////////////////////////////////////////////////////

void LE_EntityIdentifier::SetApplicationID( KUINT8 ID )
{
    m_ui8ApplicationID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LE_EntityIdentifier::GetApplicationID() const
{
    return m_ui8ApplicationID;
}

//////////////////////////////////////////////////////////////////////////

void LE_EntityIdentifier::SetEntityID( KUINT16 ID )
{
    m_ui16EntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 LE_EntityIdentifier::GetEntityID() const
{
    return m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

KString LE_EntityIdentifier::GetAsString() const
{
    KStringStream ss;

    ss << "Site:        " << ( KUINT16 )m_ui8SiteID           << "\n"
       << "Application: " << ( KUINT16 )m_ui8ApplicationID    << "\n"
       << "Object:      " << m_ui16EntityID                   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LE_EntityIdentifier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LE_ENTITY_IDENTIFER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8SiteID
           >> m_ui8ApplicationID
           >> m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LE_EntityIdentifier::Encode() const
{
    KDataStream stream;

    LE_EntityIdentifier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LE_EntityIdentifier::Encode( KDataStream & stream ) const
{
    stream << m_ui8SiteID
           << m_ui8ApplicationID
           << m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_EntityIdentifier::operator == ( const LE_EntityIdentifier & Value ) const
{
    if( m_ui8SiteID        != Value.m_ui8SiteID )        return false;
    if( m_ui8ApplicationID != Value.m_ui8ApplicationID ) return false;
    if( m_ui16EntityID     != Value.m_ui16EntityID )     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_EntityIdentifier::operator != ( const LE_EntityIdentifier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_EntityIdentifier::operator <  ( const LE_EntityIdentifier & Value ) const
{
    // We will bit shift all 3 fields into a single KUINT32, this will generate a new unique value which we can then use for comparison.
    // bits 0-7  = SiteID
    // bits 8-15 = ApplicationID
    // bits 16-31 = EntityID
    KUINT32 ui32ThisCmpVal = 0, ui32OtherCmpVal = 0;

    ui32ThisCmpVal = m_ui8SiteID | ( KUINT32 )m_ui8ApplicationID << 8 | ( KUINT32 )m_ui16EntityID << 16;
    ui32OtherCmpVal = Value.m_ui8SiteID | ( KUINT32 )Value.m_ui8ApplicationID << 8 | ( KUINT32 )Value.m_ui16EntityID << 16;

    return ui32ThisCmpVal < ui32OtherCmpVal;
}

//////////////////////////////////////////////////////////////////////////
