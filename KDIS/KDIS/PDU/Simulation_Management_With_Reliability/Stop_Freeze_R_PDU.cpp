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

#include "./Stop_Freeze_R_PDU.h"

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

Stop_Freeze_R_PDU::Stop_Freeze_R_PDU()
{
    m_ui8PDUType = Stop_Freeze_R_PDU_Type;
    m_ui16PDULength = STOP_FREEZE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_R_PDU::Stop_Freeze_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_R_PDU::Stop_Freeze_R_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Stop_Freeze_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_R_PDU::Stop_Freeze_R_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity, const ClockTime & RealWorldTime,
                                      StopFreezeReason SFR, FrozenBehavior FB, KUINT32 ReqID, RequiredReliabilityService RRS ) :
    Stop_Freeze_PDU( ReceivingEntity, SupplyingEntity, RealWorldTime, SFR, FB, ReqID ),
    Reliability_Header( RRS )
{
    m_ui8PDUType = Stop_Freeze_R_PDU_Type;
    m_ui16PDULength = STOP_FREEZE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_R_PDU::Stop_Freeze_R_PDU( const Simulation_Management_Header & SimMgrHeader, const ClockTime & RealWorldTime,
                                      StopFreezeReason SFR, FrozenBehavior FB, KUINT32 ReqID, RequiredReliabilityService RRS ) :
    Stop_Freeze_PDU( SimMgrHeader, RealWorldTime, SFR, FB, ReqID ),
    Reliability_Header( RRS )
{
    m_ui8PDUType = Stop_Freeze_R_PDU_Type;
    m_ui16PDULength = STOP_FREEZE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_R_PDU::~Stop_Freeze_R_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

KString Stop_Freeze_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Stop/Freeze-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "Real World Time:\n"
       << IndentString( m_RealWorldTime.GetAsString(), 1 )
       << "\tReason:           " << GetEnumAsStringStopFreezeReason( m_ui8Reason )
       << "\n\tFrozen Behavior:  " << GetEnumAsStringFrozenBehavior( m_ui8FrozenBehaviour )
       << "\n" << Reliability_Header::GetAsString()
       << "\n\tRequest ID:       " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Stop_Freeze_R_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < STOP_FREEZE_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_RealWorldTime
           >> m_ui8Reason
           >> m_ui8FrozenBehaviour
           >> m_ui8ReqRelSrv
           >> m_ui8Padding2
           >> m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Stop_Freeze_R_PDU::Encode() const
{
    KDataStream stream;

    Stop_Freeze_R_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Stop_Freeze_R_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );

    stream << KDIS_STREAM m_RealWorldTime
           << m_ui8Reason
           << m_ui8FrozenBehaviour
           << m_ui8ReqRelSrv
           << m_ui8Padding2
           << m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Stop_Freeze_R_PDU::operator == ( const Stop_Freeze_R_PDU & Value ) const
{
    if( Stop_Freeze_PDU::operator    !=( Value ) ) return false;
    if( Reliability_Header::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Stop_Freeze_R_PDU::operator != ( const Stop_Freeze_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

