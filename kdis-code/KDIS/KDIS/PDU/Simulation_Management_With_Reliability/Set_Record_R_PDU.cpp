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

#include "./Set_Record_R_PDU.h"

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

Set_Record_R_PDU::Set_Record_R_PDU( void ) :
    m_ui32RqId( 0 ),
    m_ui32NumRecSets( 0 )
{
    m_ui8PDUType = SetRecord_R_PDU_Type;
    m_ui16PDULength = SET_RECORD_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Set_Record_R_PDU::Set_Record_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Set_Record_R_PDU::Set_Record_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                                    KUINT32 RequestID, RequiredReliabilityService RRS ) :
    Simulation_Management_Header( OriginatingEntityID, ReceivingEntityID ),
    m_ui32RqId( RequestID ),
    Reliability_Header( RRS ),
    m_ui32NumRecSets( 0 )
{
    m_ui8PDUType = SetRecord_R_PDU_Type;
    m_ui16PDULength = SET_RECORD_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Set_Record_R_PDU::~Set_Record_R_PDU( void )
{
    m_vRecs.clear();
}

//////////////////////////////////////////////////////////////////////////

void Set_Record_R_PDU::SetRequestID( KUINT32 ID )
{
    m_ui32RqId = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Set_Record_R_PDU::GetRequestID() const
{
    return m_ui32RqId;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Set_Record_R_PDU::GetNumberOfRecords() const
{
    return m_ui32NumRecSets;
}

//////////////////////////////////////////////////////////////////////////

void Set_Record_R_PDU::AddRecordSet( const RecordSet & RS )
{
    m_vRecs.push_back( RS );
    ++m_ui32NumRecSets;
    m_ui16PDULength += RS.GetRecordLength();
}

//////////////////////////////////////////////////////////////////////////

void Set_Record_R_PDU::SetRecordSets( const vector<RecordSet> & RS )
{
    // Reset the PDU size.
    vector<RecordSet>::const_iterator citr = m_vRecs.begin();
    vector<RecordSet>::const_iterator citrEnd = m_vRecs.end();

    for( ; citr != citrEnd; ++citr )
    {
        m_ui16PDULength -= citr->GetRecordLength();
    }

    m_vRecs.clear();
    m_vRecs = RS;
    m_ui32NumRecSets = m_vRecs.size();

    // Calculate the new PDU size
    for( citr = m_vRecs.begin(); citr != m_vRecs.end(); ++citr )
    {
        m_ui16PDULength += citr->GetRecordLength();
    }
}

//////////////////////////////////////////////////////////////////////////

const vector<RecordSet> & Set_Record_R_PDU::GetRecordSets() const
{
    return m_vRecs;
}


//////////////////////////////////////////////////////////////////////////

KString Set_Record_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Record-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "\tRequest ID:                "   << m_ui32RqId
       << Reliability_Header::GetAsString()
       << "\tNumber Of record Sets:     " << m_ui32NumRecSets  << "\n";

    vector<RecordSet>::const_iterator citr = m_vRecs.begin();
    vector<RecordSet>::const_iterator citrEnd = m_vRecs.end();

    for( ; citr != citrEnd; ++citr )
    {
        ss << IndentString( citr->GetAsString(), 1 );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Set_Record_R_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SET_RECORD_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vRecs.clear();

    Simulation_Management_Header::Decode( stream );

    stream >> m_ui32RqId
           >> m_ui8ReqRelSrv
           >> m_ui8Padding2
           >> m_ui32NumRecSets;

    for( KUINT32 i = 0; i < m_ui32NumRecSets; ++i )
    {
        m_vRecs.push_back( RecordSet( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Set_Record_R_PDU::Encode() const
{
    KDataStream stream;

    Set_Record_R_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Set_Record_R_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );

    stream << m_ui32RqId
           << m_ui8ReqRelSrv
           << m_ui8Padding2
           << m_ui32NumRecSets;

    vector<RecordSet>::const_iterator citr = m_vRecs.begin();
    vector<RecordSet>::const_iterator citrEnd = m_vRecs.end();

    for( ; citr != citrEnd; ++citr )
    {
        stream << citr->Encode();
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Set_Record_R_PDU::operator == ( const Set_Record_R_PDU & Value ) const
{
    if( Simulation_Management_Header::operator !=( Value ) ) return false;
    if( Reliability_Header::operator           !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Set_Record_R_PDU::operator != ( const Set_Record_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


