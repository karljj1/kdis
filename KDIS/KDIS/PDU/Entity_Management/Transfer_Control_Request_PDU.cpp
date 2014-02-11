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

#include "./Transfer_Control_Request_PDU.h"

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

Transfer_Control_Request_PDU::Transfer_Control_Request_PDU() :
    m_ui32ReqID( 0 ),
    m_ui8ReqRelSrv( 0 ),
    m_ui8TrnTyp( 0 ),
    m_ui32NumRecSets( 0 )
{
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = TransferControl_PDU_Type;
    m_ui16PDULength = TRANSFER_CONTROL_REQUEST_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Transfer_Control_Request_PDU::Transfer_Control_Request_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Transfer_Control_Request_PDU::Transfer_Control_Request_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Simulation_Management_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Transfer_Control_Request_PDU::Transfer_Control_Request_PDU( KUINT32 ReqID, RequiredReliabilityService RRS, TransferType TT,
        const EntityIdentifier & TrnsEntID ) :
    m_ui32ReqID( ReqID ),
    m_ui8ReqRelSrv( RRS ),
    m_ui8TrnTyp( TT ),
    m_TrnsEntID( TrnsEntID ),
    m_ui32NumRecSets( 0 )
{
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = TransferControl_PDU_Type;
    m_ui16PDULength = TRANSFER_CONTROL_REQUEST_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Transfer_Control_Request_PDU::~Transfer_Control_Request_PDU()
{
    m_vRecs.clear();
}

//////////////////////////////////////////////////////////////////////////

void Transfer_Control_Request_PDU::SetRequestID( KUINT32 ID )
{
    m_ui32ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Transfer_Control_Request_PDU::GetRequestID() const
{
    return m_ui32ReqID;
}

//////////////////////////////////////////////////////////////////////////

void Transfer_Control_Request_PDU::SetRequiredReliabilityService( RequiredReliabilityService RRS )
{
    m_ui8ReqRelSrv = RRS;
}

//////////////////////////////////////////////////////////////////////////

RequiredReliabilityService Transfer_Control_Request_PDU::GetRequiredReliabilityService() const
{
    return ( RequiredReliabilityService )m_ui8ReqRelSrv;
}

//////////////////////////////////////////////////////////////////////////

void Transfer_Control_Request_PDU::SetTransferType( TransferType TT )
{
    m_ui8TrnTyp = TT;
}

//////////////////////////////////////////////////////////////////////////

TransferType Transfer_Control_Request_PDU::GetTransferType() const
{
    return ( TransferType )m_ui8TrnTyp;
}

//////////////////////////////////////////////////////////////////////////

void Transfer_Control_Request_PDU::SetTransferEntityID( const EntityIdentifier & ID )
{
    m_TrnsEntID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Transfer_Control_Request_PDU::GetTransferEntityID() const
{
    return m_TrnsEntID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Transfer_Control_Request_PDU::GetTransferEntityID()
{
    return m_TrnsEntID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Transfer_Control_Request_PDU::GetNumberOfRecords() const
{
    return m_ui32NumRecSets;
}

//////////////////////////////////////////////////////////////////////////

void Transfer_Control_Request_PDU::AddRecordSet( const RecordSet & RS )
{
    m_vRecs.push_back( RS );
    ++m_ui32NumRecSets;
    m_ui16PDULength += RS.GetRecordLength();
}

//////////////////////////////////////////////////////////////////////////

void Transfer_Control_Request_PDU::SetRecordSets( const vector<RecordSet> & RS )
{
    m_vRecs.clear();
    m_vRecs = RS;
    m_ui32NumRecSets = m_vRecs.size();

    // Calculate the PDU size
    m_ui16PDULength = TRANSFER_CONTROL_REQUEST_PDU_SIZE;

    vector<RecordSet>::const_iterator citr = m_vRecs.begin();
    vector<RecordSet>::const_iterator citrEnd = m_vRecs.end();

    for( ; citr != citrEnd; ++citr )
    {
        m_ui16PDULength += citr->GetRecordLength();
    }
}

//////////////////////////////////////////////////////////////////////////

const vector<RecordSet> & Transfer_Control_Request_PDU::GetRecordSets() const
{
    return m_vRecs;
}

//////////////////////////////////////////////////////////////////////////

KString Transfer_Control_Request_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Transfer Control Request PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "Request ID:                   " << m_ui32ReqID << "\n"
       << "Required Reliability Service: " << GetEnumAsStringRequiredReliabilityService( m_ui8ReqRelSrv ) << "\n"
       << "Transfer Type:                " << GetEnumAsStringTransferType( m_ui8TrnTyp ) << "\n"
       << m_TrnsEntID.GetAsString()
       << "Number Of record Sets:        " << m_ui32NumRecSets << "\n";

    vector<RecordSet>::const_iterator citr = m_vRecs.begin();
    vector<RecordSet>::const_iterator citrEnd = m_vRecs.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << IndentString( citr->GetAsString(), 1 );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Transfer_Control_Request_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < TRANSFER_CONTROL_REQUEST_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vRecs.clear();

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> m_ui32ReqID
           >> m_ui8ReqRelSrv
           >> m_ui8TrnTyp
           >> KDIS_STREAM m_TrnsEntID
           >> m_ui32NumRecSets;

    for( KUINT32 i = 0; i < m_ui32NumRecSets; ++i )
    {
        m_vRecs.push_back( RecordSet( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Transfer_Control_Request_PDU::Encode() const
{
    KDataStream stream;

    Transfer_Control_Request_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Transfer_Control_Request_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );

    stream << m_ui32ReqID
           << m_ui8ReqRelSrv
           << m_ui8TrnTyp
           << KDIS_STREAM m_TrnsEntID
           << m_ui32NumRecSets;

    vector<RecordSet>::const_iterator citr = m_vRecs.begin();
    vector<RecordSet>::const_iterator citrEnd = m_vRecs.end();

    for( ; citr != citrEnd; ++citr )
    {
        stream << citr->Encode();
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Transfer_Control_Request_PDU::operator == ( const Transfer_Control_Request_PDU & Value ) const
{
    if( Simulation_Management_Header::operator  !=( Value ) )               return false;
    if( m_ui32ReqID                             != Value.m_ui32ReqID )      return false;
    if( m_ui8ReqRelSrv                          != Value.m_ui8ReqRelSrv )   return false;
    if( m_ui8TrnTyp                             != Value.m_ui8TrnTyp )      return false;
    if( m_TrnsEntID                             != Value.m_TrnsEntID )      return false;
    if( m_ui32NumRecSets                        != Value.m_ui32NumRecSets ) return false;
    if( m_vRecs                                 != Value.m_vRecs )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Transfer_Control_Request_PDU::operator != ( const Transfer_Control_Request_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

