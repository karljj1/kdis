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

Radio_Communications_Header::Radio_Communications_Header() :
	m_ui16RadioID( 0 )
{
    m_ui8ProtocolFamily = Radio_Communications;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Radio_Communications_Header::Radio_Communications_Header( const Header & H ) :
	Header( H ),
	m_ui16RadioID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Radio_Communications_Header::Radio_Communications_Header( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Radio_Communications_Header::Radio_Communications_Header( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
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

Radio_Communications_Header::~Radio_Communications_Header()
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

void Radio_Communications_Header::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < RADIO_COMMUNICATIONS_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

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

