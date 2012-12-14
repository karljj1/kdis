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

#include "./EntityIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityIdentifier::EntityIdentifier( void ) :
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

EntityIdentifier::~EntityIdentifier( void )
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
