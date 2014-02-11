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

#include "./EntityMarking.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityMarking::EntityMarking() :
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

EntityMarking::~EntityMarking()
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



