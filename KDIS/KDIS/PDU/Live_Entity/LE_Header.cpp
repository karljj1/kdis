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

#include "./LE_Header.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

LE_Header::LE_Header()
{
    m_ui8ProtocolFamily = LiveEntity;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

LE_Header::LE_Header( const Header & H ) :
	Header( H )
{
}

//////////////////////////////////////////////////////////////////////////

LE_Header::LE_Header( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

LE_Header::LE_Header( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

LE_Header::~LE_Header()
{
}

//////////////////////////////////////////////////////////////////////////

void LE_Header::SetSubprotocol( KUINT8 S )
{
    m_ui8Padding1 = S; // Using the first pading octet from the header.
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LE_Header::GetSubprotocol() const
{
    return m_ui8Padding1; // Using the first pading octet from the header.
}

//////////////////////////////////////////////////////////////////////////

void LE_Header::SetLiveEntityID( const LE_EntityIdentifier & ID )
{
    m_EntID = ID;
}

//////////////////////////////////////////////////////////////////////////

const LE_EntityIdentifier & LE_Header::GetLiveEntityID() const
{
    return m_EntID;
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier & LE_Header::GetLiveEntityID()
{
    return m_EntID;
}

//////////////////////////////////////////////////////////////////////////

KString LE_Header::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "Subprotocol:		   " << m_ui8Padding1
       << "Live Entity ID:     " << m_EntID.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LE_Header::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < LE_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_EntID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LE_Header::Encode() const
{
    KDataStream stream;

    LE_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LE_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_EntID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Header::operator == ( const LE_Header & Value ) const
{
    if( Header::operator != ( Value ) )     return false;
    if( m_EntID          != Value.m_EntID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Header::operator != ( const LE_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


