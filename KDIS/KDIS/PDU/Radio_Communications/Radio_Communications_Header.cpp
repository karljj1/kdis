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

#include "./Radio_Communications_Header.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Radio_Communications_Header::Radio_Communications_Header( void ) :
	m_ui16RadioID( 0 )
{
    m_ui8ProtocolFamily = Radio_Communications;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Radio_Communications_Header::Radio_Communications_Header( KDataStream & stream ) throw( KException )
{
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
}

//////////////////////////////////////////////////////////////////////////

Radio_Communications_Header::Radio_Communications_Header( const EntityIdentifier & ID, KUINT16 RadioID ) :
    m_EntityID( ID ),
    m_ui16RadioID( RadioID )
{
    m_ui8ProtocolFamily = Radio_Communications;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Radio_Communications_Header::~Radio_Communications_Header( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Radio_Communications_Header::SetEntityID( const EntityIdentifier & ID )
{
    m_EntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Radio_Communications_Header::GetEntityID() const
{
    return m_EntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Radio_Communications_Header::GetEntityID()
{
    return m_EntityID;
}

//////////////////////////////////////////////////////////////////////////

void Radio_Communications_Header::SetRadioID( KUINT16 ID )
{
    m_ui16RadioID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Radio_Communications_Header::GetRadioID() const
{
    return m_ui16RadioID;
}


//////////////////////////////////////////////////////////////////////////

KString Radio_Communications_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Entity ID:\n"
       << IndentString( m_EntityID.GetAsString(), 1 )
       << "Radio ID:        " << m_ui16RadioID << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Radio_Communications_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RADIO_COMMUNICATIONS_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

    stream >> KDIS_STREAM m_EntityID
           >> m_ui16RadioID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Radio_Communications_Header::Encode() const
{
    KDataStream stream;

    Radio_Communications_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Radio_Communications_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_EntityID
           << m_ui16RadioID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Radio_Communications_Header::operator == ( const Radio_Communications_Header & Value ) const
{
    if( Header::operator    !=( Value ) )            return false;
    if( m_EntityID          != Value.m_EntityID )    return false;
    if( m_ui16RadioID       != Value.m_ui16RadioID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Radio_Communications_Header::operator != ( const Radio_Communications_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

