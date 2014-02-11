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

#include "./Record_R_PDU.h"

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

Record_R_PDU::Record_R_PDU() :
    m_ui16EvntTyp( 0 ),
    m_ui32SrlNm( 0 )
{
    m_ui8PDUType = Record_R_PDU_Type;
    m_ui16PDULength = RECORD_R_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Record_R_PDU::Record_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Record_R_PDU::Record_R_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Set_Record_R_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Record_R_PDU::Record_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID, KUINT32 RequestID,
                            RequiredReliabilityService RRS, EventType ET, KUINT32 ResponseSerialNumber ) :
    Set_Record_R_PDU( OriginatingEntityID, ReceivingEntityID, RequestID, RRS ),
    m_ui16EvntTyp( ET ),
    m_ui32SrlNm( ResponseSerialNumber )
{
    m_ui8PDUType = Record_R_PDU_Type;
    m_ui16PDULength = RECORD_R_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Record_R_PDU::~Record_R_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Record_R_PDU::SetEventType( EventType ET )
{
    m_ui16EvntTyp = ET;
}

//////////////////////////////////////////////////////////////////////////

EventType Record_R_PDU::GetEventType() const
{
    return ( EventType )m_ui16EvntTyp;
}

//////////////////////////////////////////////////////////////////////////

void Record_R_PDU::SetResponseSerialNumber( KUINT32 RSN )
{
    m_ui32SrlNm = RSN;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Record_R_PDU::GetResponseSerialNumber() const
{
    return m_ui32SrlNm;
}

//////////////////////////////////////////////////////////////////////////

KString Record_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Record-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "\tRequest ID:                "   << m_ui32RqId
       << Reliability_Header::GetAsString()
       << "\tEvent Type:                "   << GetEnumAsStringEventType( m_ui16EvntTyp ) << "\n"
       << "\tSerial Number:             "   << m_ui32SrlNm    << "\n"
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

void Record_R_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < RECORD_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> m_ui32RqId
           >> m_ui8ReqRelSrv
           >> m_ui8Padding2
           >> m_ui16EvntTyp
           >> m_ui32SrlNm
           >> m_ui32NumRecSets;

    for( KUINT32 i = 0; i < m_ui32NumRecSets; ++i )
    {
        m_vRecs.push_back( RecordSet( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Record_R_PDU::Encode() const
{
    KDataStream stream;

    Record_R_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Record_R_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );

    stream << m_ui32RqId
           << m_ui8ReqRelSrv
           << m_ui8Padding2
           << m_ui16EvntTyp
           << m_ui32SrlNm
           << m_ui32NumRecSets;

    vector<RecordSet>::const_iterator citr = m_vRecs.begin();
    vector<RecordSet>::const_iterator citrEnd = m_vRecs.end();

    for( ; citr != citrEnd; ++citr )
    {
        stream << citr->Encode();
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Record_R_PDU::operator == ( const Record_R_PDU & Value ) const
{
    if( Set_Record_R_PDU::operator !=( Value ) )             return false;
    if( m_ui16EvntTyp              != Value.m_ui16EvntTyp )  return false;
    if( m_ui32SrlNm                != Value.m_ui32SrlNm )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Record_R_PDU::operator != ( const Record_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

