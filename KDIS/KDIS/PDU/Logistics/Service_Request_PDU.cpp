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

Service_Request_PDU::Service_Request_PDU()
{
    m_ui8PDUType = Service_Request_PDU_Type;
    m_ui16PDULength = SERVICE_REQUEST_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Service_Request_PDU::Service_Request_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Service_Request_PDU::Service_Request_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Resupply_Received_PDU( H )
{
    Decode( stream, true );
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

Service_Request_PDU::~Service_Request_PDU()
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

void Service_Request_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < SERVICE_REQUEST_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Logistics_Header::Decode( stream, ignoreHeader );	

    stream >> m_ui8ServiceTypeRequested
           >> m_ui8NumSupplyTypes
           >> m_ui16Padding1;

    // Now recheck the size of the packet as we now know the number of supply types.
    if( stream.GetBufferSize() < m_ui8NumSupplyTypes * Supplies::SUPPLIES_SIZE )throw KException( __FUNCTION__, RESUPPLY_RECEIVED_PDU_SIZE );

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

