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

Record_R_PDU::Record_R_PDU( void ) :
    m_ui16EvntTyp( 0 ),
    m_ui32SrlNm( 0 )
{
    m_ui8PDUType = Record_R_PDU_Type;
    m_ui16PDULength = RECORD_R_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Record_R_PDU::Record_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
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

Record_R_PDU::~Record_R_PDU( void )
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

void Record_R_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RECORD_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream );

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

