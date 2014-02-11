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

#include "./Logistics_Header.h"

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Logistics_Header::Logistics_Header()
{
    m_ui8ProtocolFamily = Logistics;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Logistics_Header::Logistics_Header( const Header & H ) :
	Header( H )
{
}

//////////////////////////////////////////////////////////////////////////

Logistics_Header::Logistics_Header( const EntityIdentifier & ReceivingEntityID, const EntityIdentifier & SupplyingEntityID ) :
    m_ReceivingEntity( ReceivingEntityID ),
    m_SupplyingEntity( SupplyingEntityID )
{
    m_ui8ProtocolFamily = Logistics;
}

//////////////////////////////////////////////////////////////////////////

Logistics_Header::~Logistics_Header()
{
}

//////////////////////////////////////////////////////////////////////////

void Logistics_Header::SetReceivingEntity( const EntityIdentifier & EI )
{
    m_ReceivingEntity = EI;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Logistics_Header::GetReceivingEntity() const
{
    return m_ReceivingEntity;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Logistics_Header::GetReceivingEntity()
{
    return m_ReceivingEntity;
}

//////////////////////////////////////////////////////////////////////////

void Logistics_Header::SetSupplyingEntity( const EntityIdentifier & EI )
{
    m_SupplyingEntity = EI;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Logistics_Header::GetSupplyingEntity() const
{
    return m_SupplyingEntity;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Logistics_Header::GetSupplyingEntity()
{
    return m_SupplyingEntity;
}

//////////////////////////////////////////////////////////////////////////

KString Logistics_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Receiving Entity ID:	"
       << IndentString( m_ReceivingEntity.GetAsString(), 1 )
       << "\tSupplying Entity ID:	"
       << IndentString( m_SupplyingEntity.GetAsString(), 1 ) ;

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Logistics_Header::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < LOGISTICS_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_ReceivingEntity
           >> KDIS_STREAM m_SupplyingEntity;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Logistics_Header::Encode() const
{
    KDataStream stream;

    Logistics_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Logistics_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );
    stream << KDIS_STREAM m_ReceivingEntity
           << KDIS_STREAM m_SupplyingEntity;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Logistics_Header::operator == ( const Logistics_Header & Value ) const
{
    if( Header::operator  !=( Value ) )                 return false;
    if( m_ReceivingEntity != Value.m_ReceivingEntity )  return false;
    if( m_SupplyingEntity != Value.m_SupplyingEntity )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Logistics_Header::operator != ( const Logistics_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
