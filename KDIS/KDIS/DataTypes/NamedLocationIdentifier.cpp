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

#include "./NamedLocationIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier::NamedLocationIdentifier() :
    m_ui16StnName( 0 ),
    m_ui16StnNum( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier::NamedLocationIdentifier( StationName SN,  KUINT16 StationNumber ) :
    m_ui16StnName( SN ),
    m_ui16StnNum( StationNumber )
{
}

//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier::NamedLocationIdentifier( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier::~NamedLocationIdentifier()
{
}

//////////////////////////////////////////////////////////////////////////

void NamedLocationIdentifier::SetStationName( StationName SN )
{
    m_ui16StnName = SN;
}

//////////////////////////////////////////////////////////////////////////

StationName NamedLocationIdentifier::GetStationName() const
{
    return ( StationName )m_ui16StnName;
}

//////////////////////////////////////////////////////////////////////////

void NamedLocationIdentifier::SetStationNumber( KUINT16 SN )
{
    m_ui16StnNum = SN;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 NamedLocationIdentifier::GetStationNumber() const
{
    return m_ui16StnNum;
}

//////////////////////////////////////////////////////////////////////////

KString NamedLocationIdentifier::GetAsString() const
{
    KStringStream ss;

    ss << "Named Location Identifier:"
       << "\n\tName:   " << GetEnumAsStringStationName( m_ui16StnName )
       << "\n\tNumber: " << m_ui16StnNum
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void NamedLocationIdentifier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < NAMED_LOCATION_ID_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16StnName
           >> m_ui16StnNum;
}

//////////////////////////////////////////////////////////////////////////

KDataStream NamedLocationIdentifier::Encode() const
{
    KDataStream stream;

    NamedLocationIdentifier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void NamedLocationIdentifier::Encode( KDataStream & stream ) const
{
    stream << m_ui16StnName
           << m_ui16StnNum;
}

//////////////////////////////////////////////////////////////////////////

KBOOL NamedLocationIdentifier::operator == ( const NamedLocationIdentifier & Value ) const
{
    if( m_ui16StnName != Value.m_ui16StnName ) return false;
    if( m_ui16StnNum  != Value.m_ui16StnNum )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL NamedLocationIdentifier::operator != ( const NamedLocationIdentifier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


