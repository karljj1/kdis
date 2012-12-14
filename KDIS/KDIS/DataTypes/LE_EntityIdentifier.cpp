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

#include "./LE_EntityIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier::LE_EntityIdentifier( void ) :
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

LE_EntityIdentifier::~LE_EntityIdentifier( void )
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
    return true;
}

//////////////////////////////////////////////////////////////////////////
