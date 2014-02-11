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

#include "./IO_Header.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IO_Header::IO_Header()
{
    m_ui8ProtocolFamily = Information_Operations;
    m_ui8ProtocolVersion = IEEE_1278_1_2012;
}

//////////////////////////////////////////////////////////////////////////

IO_Header::IO_Header( const Header & H ) :
	Header( H )
{
}

//////////////////////////////////////////////////////////////////////////

IO_Header::IO_Header( const EntityIdentifier & OrigID ) :
    m_OriginatingEntityID( OrigID )
{
    m_ui8ProtocolFamily = Information_Operations;
    m_ui8ProtocolVersion = IEEE_1278_1_2012;
}

//////////////////////////////////////////////////////////////////////////

IO_Header::IO_Header( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IO_Header::IO_Header( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

IO_Header::~IO_Header()
{
}

//////////////////////////////////////////////////////////////////////////

void IO_Header::SetOriginatingEntityID( const EntityIdentifier & ID )
{
    m_OriginatingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IO_Header::GetOriginatingEntityID() const
{
    return m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IO_Header::GetOriginatingEntityID()
{
    return m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KString IO_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Originating Entity ID:\n"
       << IndentString( m_OriginatingEntityID.GetAsString(), 1 );

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IO_Header::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < IO_HEADER_SIZE  )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream IO_Header::Encode() const
{
    KDataStream stream;

    IO_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IO_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IO_Header::operator == ( const IO_Header & Value ) const
{
    if( Header::operator        !=( Value ) )                    return false;
    if( m_OriginatingEntityID   != Value.m_OriginatingEntityID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IO_Header::operator != ( const IO_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

