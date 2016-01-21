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

#include "./CommunicationsChannelType.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

CommunicationsChannelType::CommunicationsChannelType() :
    m_ui8Type( 0 ),
    m_ui8Class( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsChannelType::CommunicationsChannelType( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

CommunicationsChannelType::CommunicationsChannelType( ChannelType CT, ChannelClass CC ) :
    m_ui8Type( CT ),
    m_ui8Class( CC )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsChannelType::~CommunicationsChannelType()
{
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsChannelType::SetType( ChannelType CT )
{
    m_ui8Type = CT;
}

//////////////////////////////////////////////////////////////////////////

ChannelType CommunicationsChannelType::GetType() const
{
    return ( ChannelType )m_ui8Type;
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsChannelType::SetClass( ChannelClass CC )
{
    m_ui8Class = CC;
}

//////////////////////////////////////////////////////////////////////////

ChannelClass CommunicationsChannelType::GetClass() const
{
    return ( ChannelClass )m_ui8Class;
}

//////////////////////////////////////////////////////////////////////////

KString CommunicationsChannelType::GetAsString() const
{
    KStringStream ss;

    ss << "Communications Channel Type:"
       << "\n\tType  : " << ( KUINT16 )m_ui8Type
       << "\n\tClass : " << ( KUINT16 )m_ui8Class
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsChannelType::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < COMM_CHANNEL_TYPE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8CommChannelType;
}

//////////////////////////////////////////////////////////////////////////

KDataStream CommunicationsChannelType::Encode() const
{
    KDataStream stream;

    CommunicationsChannelType::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsChannelType::Encode( KDataStream & stream ) const
{
    stream << m_ui8CommChannelType;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CommunicationsChannelType::operator == ( const CommunicationsChannelType & Value ) const
{
    if( m_ui8CommChannelType != Value.m_ui8CommChannelType ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CommunicationsChannelType::operator != ( const CommunicationsChannelType & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


