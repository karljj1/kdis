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

Set_Record_R_PDU::Set_Record_R_PDU() :
    m_ui32RqId( 0 ),
    m_ui32NumRecSets( 0 ),
	m_ui8Padding1( 0 ),
	m_ui16Padding( 0 ),
	m_ui32Padding( 0 )
{
    m_ui8PDUType = SetRecord_R_PDU_Type;
    m_ui16PDULength = SET_RECORD_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Set_Record_R_PDU::Set_Record_R_PDU( const Header & H ) :
	Simulation_Management_Header( H ),
	m_ui32RqId( 0 ),
    m_ui32NumRecSets( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Set_Record_R_PDU::Set_Record_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Set_Record_R_PDU::Set_Record_R_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Simulation_Management_Header( H )
{
    Decode( stream, true );
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

Set_Record_R_PDU::~Set_Record_R_PDU()
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

void Set_Record_R_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < SET_RECORD_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vRecs.clear();

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> m_ui32RqId
           >> m_ui8ReqRelSrv
           >> m_ui8Padding1
           >> m_ui16Padding
           >> m_ui32Padding
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
           << m_ui8Padding1
           << m_ui16Padding
           << m_ui32Padding
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


