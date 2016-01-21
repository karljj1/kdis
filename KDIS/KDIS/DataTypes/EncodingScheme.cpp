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

#include "./EncodingScheme.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EncodingScheme::EncodingScheme()
{
    m_EncodingSchemeUnion.m_ui16EncodingScheme = 0;
}

//////////////////////////////////////////////////////////////////////////

EncodingScheme::EncodingScheme( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EncodingScheme::EncodingScheme( EncodingClass EC, KUINT16 EncodingType, TDLType T ) :
    m_ui16TDLType( T )
{
    m_EncodingSchemeUnion.m_ui16Type = EncodingType;
    m_EncodingSchemeUnion.m_ui16Class = EC;
}

//////////////////////////////////////////////////////////////////////////

EncodingScheme::EncodingScheme( EncodingType Audio, TDLType T ) :
    m_ui16TDLType( T )
{
    m_EncodingSchemeUnion.m_ui16Type = Audio;
    m_EncodingSchemeUnion.m_ui16Class = EncodedAudio;
}

//////////////////////////////////////////////////////////////////////////

EncodingScheme::~EncodingScheme()
{
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::SetEncodingClass( EncodingClass EC )
{
    m_EncodingSchemeUnion.m_ui16Class = EC;
}

//////////////////////////////////////////////////////////////////////////

EncodingClass EncodingScheme::GetEncodingClass() const
{
    return ( EncodingClass )m_EncodingSchemeUnion.m_ui16Class;
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::SetEncodingTypeAudio( EncodingType T )
{
    m_EncodingSchemeUnion.m_ui16Class = EncodedAudio;
    m_EncodingSchemeUnion.m_ui16Type = T;
}

//////////////////////////////////////////////////////////////////////////

EncodingType EncodingScheme::GetEncodingTypeAudio() const
{
    return ( EncodingType )m_EncodingSchemeUnion.m_ui16Type;
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::SetEncodingType( KUINT16 T )
{
    m_EncodingSchemeUnion.m_ui16Type = T;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 EncodingScheme::GetEncodingType() const
{
    return m_EncodingSchemeUnion.m_ui16Type;
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::SetTDLType( TDLType T )
{
    m_ui16TDLType = T;
}

//////////////////////////////////////////////////////////////////////////

TDLType EncodingScheme::GetTDLType() const
{
    return ( TDLType )m_ui16TDLType;
}

//////////////////////////////////////////////////////////////////////////

KString EncodingScheme::GetAsString() const
{
    KStringStream ss;

    ss << "Encoding Scheme:"
       << "\n\tClass:    " << GetEnumAsStringEncodingClass( m_EncodingSchemeUnion.m_ui16Class )
       << "\n\tType:     " << m_EncodingSchemeUnion.m_ui16Type
       << "\n\tTDL:      " << GetEnumAsStringTDLType( m_ui16TDLType )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ENCODING_SCHEME_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_EncodingSchemeUnion.m_ui16EncodingScheme
           >> m_ui16TDLType;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EncodingScheme::Encode() const
{
    KDataStream stream;

    EncodingScheme::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::Encode( KDataStream & stream ) const
{
    stream << m_EncodingSchemeUnion.m_ui16EncodingScheme
           << m_ui16TDLType;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EncodingScheme::operator == ( const EncodingScheme & Value ) const
{
    if( m_EncodingSchemeUnion.m_ui16EncodingScheme != Value.m_EncodingSchemeUnion.m_ui16EncodingScheme ) return false;
    if( m_ui16TDLType != Value.m_ui16TDLType ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EncodingScheme::operator != ( const EncodingScheme & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

