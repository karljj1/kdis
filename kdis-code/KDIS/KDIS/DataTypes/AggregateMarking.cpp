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

#include "./AggregateMarking.h"
#include <string.h>

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

AggregateMarking::AggregateMarking( void )
{
    memset( m_sAggregateMarkingString, 0x00, 32 );
}

//////////////////////////////////////////////////////////////////////////

AggregateMarking::AggregateMarking( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

AggregateMarking::AggregateMarking( EntityMarkingCharacterSet MarkingCharSet, const KCHAR8 * MarkingText, KUINT16 TextSize ) throw( KException )
{
    memset( m_sAggregateMarkingString, 0x00, 32 );
    SetAggregateMarkingCharacterSet( MarkingCharSet );
    SetAggregateMarkingString( MarkingText, TextSize );
}

//////////////////////////////////////////////////////////////////////////

AggregateMarking::~AggregateMarking( void )
{
}

//////////////////////////////////////////////////////////////////////////

void AggregateMarking::SetAggregateMarkingCharacterSet( const EntityMarkingCharacterSet EMCS )
{
    m_ui8AggregateMarkingCharacterSet = EMCS;
}

//////////////////////////////////////////////////////////////////////////

EntityMarkingCharacterSet AggregateMarking::GetAggregateMarkingCharacterSet() const
{
    return ( EntityMarkingCharacterSet )m_ui8AggregateMarkingCharacterSet;
}

//////////////////////////////////////////////////////////////////////////

void AggregateMarking::SetAggregateMarkingString( const KINT8 * M, KUINT16 StringSize )
{
    if( StringSize > 31 ) throw KException( __FUNCTION__, STRING_PDU_SIZE_TOO_BIG );

    strncpy( m_sAggregateMarkingString, M, StringSize );

    m_sAggregateMarkingString[StringSize] = '\0';
}

//////////////////////////////////////////////////////////////////////////

KString AggregateMarking::GetAggregateMarkingString() const
{
    return m_sAggregateMarkingString;
}

//////////////////////////////////////////////////////////////////////////

KString AggregateMarking::GetAsString() const
{
    KStringStream ss;

    ss << "Aggregate Marking:"
       << "\n\tMaring Char Set:      " << ( KUINT16 )m_ui8AggregateMarkingCharacterSet
       << "\n\tMarking String:       " << GetAggregateMarkingString()
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void AggregateMarking::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < AGGREGATE_MARKING_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8AggregateMarkingCharacterSet;

    for( KUINT16 i = 0; i < 31; ++i )
    {
        stream >> m_sAggregateMarkingString[i];
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream AggregateMarking::Encode() const
{
    KDataStream stream;

    AggregateMarking::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void AggregateMarking::Encode( KDataStream & stream ) const
{
    stream << m_ui8AggregateMarkingCharacterSet;

    for( KUINT16 i = 0; i < 31; ++i )
    {
        stream << m_sAggregateMarkingString[i];
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL AggregateMarking::operator == ( const AggregateMarking & Value ) const
{
    if( m_ui8AggregateMarkingCharacterSet != Value.m_ui8AggregateMarkingCharacterSet )return false;
    if( memcmp( m_sAggregateMarkingString, Value.m_sAggregateMarkingString, 32 ) != 0 )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AggregateMarking::operator != ( const AggregateMarking & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

