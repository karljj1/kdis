/*********************************************************************
Copyright 2013 KDIS
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

#include "./Mode5MessageFormats.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Mode5MessageFormats::Mode5MessageFormats() :
	m_msgFormats( 0 )
{	
}

//////////////////////////////////////////////////////////////////////////

Mode5MessageFormats::Mode5MessageFormats( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Mode5MessageFormats::~Mode5MessageFormats()
{
}

//////////////////////////////////////////////////////////////////////////

void Mode5MessageFormats::SetMessageFormatPresent( KUINT8 MF, KBOOL P ) throw( KException )
{
	if( MF > 31 )throw KException( __FUNCTION__, OUT_OF_BOUNDS );
	m_msgFormats.set( MF, P );
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5MessageFormats::IsMessageFormatPresent( KUINT8 MF ) const throw( KException )
{
	if( MF > 31 )throw KException( __FUNCTION__, OUT_OF_BOUNDS );
	return m_msgFormats.test( MF );
}

//////////////////////////////////////////////////////////////////////////

void Mode5MessageFormats::SetMessageFormatPresentFlags( KINT32 All ) 
{
	m_msgFormats = bitset<32>( All );
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Mode5MessageFormats::GetMessageFormatPresentFlags() const
{
	return m_msgFormats.to_ulong();
}

//////////////////////////////////////////////////////////////////////////

KString Mode5MessageFormats::GetAsString() const
{
    KStringStream ss;	
	ss << "Mode 5 Message Formats: " << m_msgFormats.to_string() << "\n";       
    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Mode5MessageFormats::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_5_MESSAGE_FORMATS_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	KINT32 tmp = 0;
    stream >> tmp;
	m_msgFormats = bitset<32>( tmp );
}

//////////////////////////////////////////////////////////////////////////

KDataStream Mode5MessageFormats::Encode() const
{
    KDataStream stream;

    Mode5MessageFormats::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Mode5MessageFormats::Encode( KDataStream & stream ) const
{
	stream << m_msgFormats.to_ulong();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5MessageFormats::operator == ( const Mode5MessageFormats & Value ) const
{
	if( m_msgFormats != Value.m_msgFormats ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5MessageFormats::operator != ( const Mode5MessageFormats & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
