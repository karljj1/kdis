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

#include "./Reliability_Header.h"

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

Reliability_Header::Reliability_Header() :
    m_ui8ReqRelSrv( 0 ),
    m_ui16Padding1( 0 ),
    m_ui8Padding( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Reliability_Header::Reliability_Header( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Reliability_Header::Reliability_Header( RequiredReliabilityService RRS ) :
    m_ui8ReqRelSrv( RRS ),
    m_ui16Padding1( 0 ),
    m_ui8Padding( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Reliability_Header::~Reliability_Header()
{
}

//////////////////////////////////////////////////////////////////////////

void Reliability_Header::SetRequiredReliabilityService( RequiredReliabilityService RRS )
{
    m_ui8ReqRelSrv = RRS;
}

//////////////////////////////////////////////////////////////////////////

RequiredReliabilityService Reliability_Header::GetRequiredReliabilityService() const
{
    return ( RequiredReliabilityService )m_ui8ReqRelSrv;
}

//////////////////////////////////////////////////////////////////////////

KString Reliability_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Required Reliability Service: " << GetEnumAsStringRequiredReliabilityService( m_ui8ReqRelSrv )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Reliability_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RELIABILITY_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8ReqRelSrv
           >> m_ui16Padding1
           >> m_ui8Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Reliability_Header::Encode() const
{
    KDataStream stream;

    Reliability_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Reliability_Header::Encode( KDataStream & stream ) const
{
    stream << m_ui8ReqRelSrv
           << m_ui16Padding1
           << m_ui8Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Reliability_Header::operator == ( const Reliability_Header & Value ) const
{
    if( m_ui8ReqRelSrv != Value.m_ui8ReqRelSrv ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Reliability_Header::operator != ( const Reliability_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
