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

#include "./Service_Request_PDU.h"

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

Service_Request_PDU::Service_Request_PDU( void )
{
    m_ui8PDUType = Service_Request_PDU_Type;
    m_ui16PDULength = SERVICE_REQUEST_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Service_Request_PDU::Service_Request_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Service_Request_PDU::Service_Request_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity, ServiceTypeRequested STR ) :
    Resupply_Received_PDU( ReceivingEntity, SupplyingEntity ),
    m_ui8ServiceTypeRequested( STR )
{
    m_ui8PDUType = Service_Request_PDU_Type;
    m_ui16PDULength = SERVICE_REQUEST_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Service_Request_PDU::~Service_Request_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Service_Request_PDU::SetServiceTypeRequested( ServiceTypeRequested STR )
{
    m_ui8ServiceTypeRequested = STR;
}

//////////////////////////////////////////////////////////////////////////

ServiceTypeRequested Service_Request_PDU::GetServiceTypeRequested() const
{
    return ( ServiceTypeRequested )m_ui8ServiceTypeRequested;
}

//////////////////////////////////////////////////////////////////////////

KString Service_Request_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Service Request-\n"
       << IndentString( Logistics_Header::GetAsString(), 1 )
       << "\tService Type:           " << GetEnumAsStringServiceTypeRequested( m_ui8ServiceTypeRequested )
       << "\tNumber Of Supply Types: " << ( KUINT16 )m_ui8NumSupplyTypes;

    // Now add supplies
    vector<Supplies>::const_iterator citr = m_vSupplies.begin();
    vector<Supplies>::const_iterator citrEnd = m_vSupplies.end();

    // Add supplies to the stream
    for( ; citr != citrEnd; ++citr )
    {
        ss << IndentString( citr->GetAsString(), 1 )
           << "\tQuantity :	" << citr->GetQuantity();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Service_Request_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SERVICE_REQUEST_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Logistics_Header::Decode( stream );

    stream >> m_ui8ServiceTypeRequested
           >> m_ui8NumSupplyTypes
           >> m_ui16Padding1;

    // Now recheck the size of the packet as we now know the number of supply types.
    if( stream.GetBufferSize() < SERVICE_REQUEST_PDU_SIZE + ( m_ui8NumSupplyTypes * Supplies::SUPPLIES_SIZE ) )throw KException( __FUNCTION__, RESUPPLY_RECEIVED_PDU_SIZE );

    for( KUINT16 i = 0; i < m_ui8NumSupplyTypes; ++i )
    {
        Supplies sup;
        stream >> KDIS_STREAM sup;
        m_vSupplies.push_back( sup );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Service_Request_PDU::Encode() const
{
    KDataStream stream;

    Service_Request_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Service_Request_PDU::Encode( KDataStream & stream ) const
{
    Logistics_Header::Encode( stream );
    stream << m_ui8ServiceTypeRequested
           << m_ui8NumSupplyTypes
           << m_ui16Padding1;

    vector<Supplies>::const_iterator citr = m_vSupplies.begin();
    vector<Supplies>::const_iterator citrEnd = m_vSupplies.end();

    // Add supplies to the stream
    for( ; citr != citrEnd; ++citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Service_Request_PDU::operator == ( const Service_Request_PDU & Value ) const
{
    if( Logistics_Header::operator  !=( Value ) )                        return false;
    if( m_ui8ServiceTypeRequested   != Value.m_ui8ServiceTypeRequested ) return false;
    if( m_ui8NumSupplyTypes         != Value.m_ui8NumSupplyTypes )       return false;
    if( m_vSupplies                 != Value.m_vSupplies )               return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Service_Request_PDU::operator != ( const Service_Request_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

