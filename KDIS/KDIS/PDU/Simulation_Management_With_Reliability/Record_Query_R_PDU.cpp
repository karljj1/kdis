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

Record_Query_R_PDU::Record_Query_R_PDU( void ) :
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
    Decode( stream );
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

Record_Query_R_PDU::~Record_Query_R_PDU( void )
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

void Record_Query_R_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RECORD_QUERY_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vui32RecID.clear();

    Simulation_Management_Header::Decode( stream );

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






