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

#include "./AggregateMarking.h"
#include <string.h>

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

AggregateMarking::AggregateMarking() :
    m_ui8AggregateMarkingCharacterSet( ASCII )
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

AggregateMarking::~AggregateMarking()
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
    m_sAggregateMarkingString[31] = 0;
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
    if( memcmp( m_sAggregateMarkingString, Value.m_sAggregateMarkingString, 31 ) != 0 )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AggregateMarking::operator != ( const AggregateMarking & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

