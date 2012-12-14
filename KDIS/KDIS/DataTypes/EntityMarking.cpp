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

#include "./EntityMarking.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityMarking::EntityMarking( void ) :
    m_ui8EntityMarkingCharacterSet( 0 )
{
    memset( m_sEntityMarkingString, 0x00, sizeof( m_sEntityMarkingString ) );
}

//////////////////////////////////////////////////////////////////////////

EntityMarking::EntityMarking( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EntityMarking::EntityMarking( EntityMarkingCharacterSet MarkingCharSet, const KCHAR8 * MarkingText, KUINT16 TextSize ) throw( KException ) :
    m_ui8EntityMarkingCharacterSet( MarkingCharSet )
{
    if( TextSize > 11 )throw KException( __FUNCTION__, STRING_PDU_SIZE_TOO_BIG );

    memset( m_sEntityMarkingString, 0x00, sizeof( m_sEntityMarkingString ) );
    SetEntityMarkingString( MarkingText, TextSize );
}

//////////////////////////////////////////////////////////////////////////

EntityMarking::EntityMarking( const EntityMarkingCharacterSet MarkingCharSet, const KString & MarkingText ) throw( KException ) :
	m_ui8EntityMarkingCharacterSet( MarkingCharSet )
{
	if( MarkingText.size() > 11 ) throw KException( __FUNCTION__, STRING_PDU_SIZE_TOO_BIG );

	memset( m_sEntityMarkingString, 0x00, sizeof( m_sEntityMarkingString ) );
	SetEntityMarkingString( MarkingText );    
}

//////////////////////////////////////////////////////////////////////////

EntityMarking::~EntityMarking( void )
{
}

//////////////////////////////////////////////////////////////////////////

void EntityMarking::SetEntityMarkingCharacterSet( EntityMarkingCharacterSet EMCS )
{
    m_ui8EntityMarkingCharacterSet = EMCS;
}

//////////////////////////////////////////////////////////////////////////

EntityMarkingCharacterSet EntityMarking::GetEntityMarkingCharacterSet() const
{
    return ( EntityMarkingCharacterSet )m_ui8EntityMarkingCharacterSet;
}

//////////////////////////////////////////////////////////////////////////

void EntityMarking::SetEntityMarkingString( const KINT8 * EMS, KUINT16 StringSize ) throw( KException )
{
    if( StringSize > 11 ) throw KException( __FUNCTION__, STRING_PDU_SIZE_TOO_BIG );

    memcpy( m_sEntityMarkingString, EMS, StringSize );
    m_sEntityMarkingString[StringSize] = 0x0; // Null terminate the string.
}

//////////////////////////////////////////////////////////////////////////

void EntityMarking::SetEntityMarkingString( const KString & EMS ) throw( KException )
{
	if( EMS.size() > 11 ) throw KException( __FUNCTION__, STRING_PDU_SIZE_TOO_BIG );

	memcpy( m_sEntityMarkingString, EMS.c_str(), EMS.size() );
	m_sEntityMarkingString[EMS.size()] = 0x0; // Null terminate the string.
}

//////////////////////////////////////////////////////////////////////////

KString EntityMarking::GetEntityMarkingString() const
{
    return m_sEntityMarkingString;
}

//////////////////////////////////////////////////////////////////////////

KString EntityMarking::GetAsString() const
{
    KStringStream ss;

    ss << "Entity Marking:"
       << "\n\tMaring Char Set:      " << GetEnumAsStringEntityMarkingCharacterSet( m_ui8EntityMarkingCharacterSet )
       << "\n\tMarking String:       " << GetEntityMarkingString()
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EntityMarking::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ENTITY_MARKING_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8EntityMarkingCharacterSet;

    for( KUINT16 i = 0; i < 11; ++i )
    {
        stream >> m_sEntityMarkingString[i];
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream EntityMarking::Encode() const
{
    KDataStream stream;

    EntityMarking::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EntityMarking::Encode( KDataStream & stream ) const
{
    stream << m_ui8EntityMarkingCharacterSet;

    for( KUINT16 i = 0; i < 11; ++i )
    {
        stream << m_sEntityMarkingString[i];
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityMarking::operator == ( const EntityMarking & Value ) const
{
    if( m_ui8EntityMarkingCharacterSet != Value.m_ui8EntityMarkingCharacterSet )  return false;
    if( memcmp( m_sEntityMarkingString, Value.m_sEntityMarkingString, 11 ) != 0 ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityMarking::operator != ( const EntityMarking & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



