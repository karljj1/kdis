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

#include "./Record_Query_R_PDU.h"

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

Record_Query_R_PDU::Record_Query_R_PDU() :
    m_ui32RqId( 0 ),
    m_ui16EvntTyp( 0 ),
    m_ui32Time( 0 ),
    m_ui32NumRecs( 0 )
{
    m_ui8PDUType = RecordQuery_R_PDU_Type;
    m_ui16PDULength = RECORD_QUERY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Record_Query_R_PDU::Record_Query_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Record_Query_R_PDU::Record_Query_R_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Simulation_Management_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Record_Query_R_PDU::Record_Query_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID, KUINT32 RequestID,
                                        RequiredReliabilityService RRS, EventType ET, KUINT32 Time ) :
    Simulation_Management_Header( OriginatingEntityID, ReceivingEntityID ),
    Reliability_Header( RRS ),
    m_ui32RqId( RequestID ),
    m_ui16EvntTyp( ET ),
    m_ui32Time( Time ),
    m_ui32NumRecs( 0 )
{
    m_ui8PDUType = RecordQuery_R_PDU_Type;
    m_ui16PDULength = RECORD_QUERY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Record_Query_R_PDU::~Record_Query_R_PDU()
{
    m_vui32RecID.clear();
}

//////////////////////////////////////////////////////////////////////////

void Record_Query_R_PDU::SetRequestID( KUINT32 ID )
{
    m_ui32RqId = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Record_Query_R_PDU::GetRequestID() const
{
    return m_ui32RqId;
}

//////////////////////////////////////////////////////////////////////////

void Record_Query_R_PDU::SetEventType( EventType ET )
{
    m_ui16EvntTyp = ET;
}

//////////////////////////////////////////////////////////////////////////

EventType Record_Query_R_PDU::GetEventType() const
{
    return ( EventType )m_ui16EvntTyp;
}

//////////////////////////////////////////////////////////////////////////

void Record_Query_R_PDU::SetTime( KUINT32 T )
{
    m_ui32Time = T;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Record_Query_R_PDU::GetTime() const
{
    return m_ui32Time;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Record_Query_R_PDU::GetNumberRecords() const
{
    return m_ui32NumRecs;
}

//////////////////////////////////////////////////////////////////////////

void Record_Query_R_PDU::AddRecordID( const KUINT32 ID )
{
    m_vui32RecID.push_back( ID );
    ++m_ui32NumRecs;
    m_ui16PDULength += 4;
}

//////////////////////////////////////////////////////////////////////////

void Record_Query_R_PDU::SetRecordIDs( const vector<KUINT32> & ID )
{
    m_vui32RecID.clear();
    m_vui32RecID = ID;
    m_ui32NumRecs = m_vui32RecID.size();
    m_ui16PDULength = RECORD_QUERY_R_PDU_SIZE + ( m_ui32NumRecs * 4 );
}

//////////////////////////////////////////////////////////////////////////

const vector<KUINT32> & Record_Query_R_PDU::GetRecordIDs() const
{
    return m_vui32RecID;
}

//////////////////////////////////////////////////////////////////////////

KString Record_Query_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Record Query-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "\tRequest ID:                "   << m_ui32RqId
       << Reliability_Header::GetAsString()
       << "\tEvent Type:                "   << GetEnumAsStringEventType( m_ui16EvntTyp ) << "\n"
       << "\tTime:                      "   << m_ui32Time     << "\n"
       << "\tNumber Of Record IDs:      "   << m_ui32NumRecs  << "\n";

    vector<KUINT32>::const_iterator citr = m_vui32RecID.begin();
    vector<KUINT32>::const_iterator citrEnd = m_vui32RecID.end();

    for( ; citr != citrEnd; ++citr )
    {
        ss << "\t" << *citr << "\n";
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Record_Query_R_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < RECORD_QUERY_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vui32RecID.clear();

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> m_ui32RqId
           >> m_ui8ReqRelSrv
           >> m_ui8Padding
           >> m_ui16EvntTyp
           >> m_ui32Time
           >> m_ui32NumRecs;

    for( KUINT32 i = 0; i < m_ui32NumRecs; ++i )
    {
        KUINT32 j;
        stream >> j;
        m_vui32RecID.push_back( j );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Record_Query_R_PDU::Encode() const
{
    KDataStream stream;

    Record_Query_R_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Record_Query_R_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );

    stream << m_ui32RqId
           << m_ui8ReqRelSrv
           << m_ui8Padding
           << m_ui16EvntTyp
           << m_ui32Time
           << m_ui32NumRecs;

    vector<KUINT32>::const_iterator citr = m_vui32RecID.begin();
    vector<KUINT32>::const_iterator citrEnd = m_vui32RecID.end();

    for( ; citr != citrEnd; ++citr )
    {
        stream << *citr;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Record_Query_R_PDU::operator == ( const Record_Query_R_PDU & Value ) const
{
    if( Simulation_Management_Header::operator !=( Value ) )             return false;
    if( Reliability_Header::operator           !=( Value ) )             return false;
    if( m_ui32RqId                             != Value.m_ui32RqId )     return false;
    if( m_ui8ReqRelSrv                         != Value.m_ui8ReqRelSrv ) return false;
    if( m_ui16EvntTyp                          != Value.m_ui16EvntTyp )  return false;
    if( m_ui32Time                             != Value.m_ui32Time )     return false;
    if( m_ui32NumRecs                          != Value.m_ui32NumRecs )  return false;
    if( m_vui32RecID                           != Value.m_vui32RecID )   return false;

    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Record_Query_R_PDU::operator != ( const Record_Query_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////






