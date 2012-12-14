/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

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

Logistics_Header::Logistics_Header( void )
{
    m_ui8ProtocolFamily = Logistics;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Logistics_Header::Logistics_Header( const EntityIdentifier & ReceivingEntityID, const EntityIdentifier & SupplyingEntityID ) :
    m_ReceivingEntity( ReceivingEntityID ),
    m_SupplyingEntity( SupplyingEntityID )
{
    m_ui8ProtocolFamily = Logistics;
}

//////////////////////////////////////////////////////////////////////////

Logistics_Header::~Logistics_Header( void )
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

void Logistics_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LOGISTICS_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

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
