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

#include "./Start_Resume_R_PDU.h"

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

Start_Resume_R_PDU::Start_Resume_R_PDU()
{
    m_ui8PDUType = Start_Resume_R_PDU_Type;
    m_ui16PDULength = START_RESUME_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_R_PDU::Start_Resume_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_R_PDU::Start_Resume_R_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Start_Resume_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_R_PDU::Start_Resume_R_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity, const ClockTime & RealWorldTime,
                                        const ClockTime & SimTime, KUINT32 ReqID, RequiredReliabilityService RRS ) :
    Start_Resume_PDU( ReceivingEntity, SupplyingEntity, RealWorldTime, SimTime, ReqID ),
    Reliability_Header( RRS )
{
    m_ui8PDUType = Start_Resume_R_PDU_Type;
    m_ui16PDULength = START_RESUME_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_R_PDU::Start_Resume_R_PDU( const Simulation_Management_Header & SimMgrHeader, const ClockTime & RealWorldTime,
                                        const ClockTime & SimTime, KUINT32 ReqID, RequiredReliabilityService RRS  ) :
    Start_Resume_PDU( SimMgrHeader, RealWorldTime, SimTime, ReqID ),
    Reliability_Header( RRS )
{
    m_ui8PDUType = Start_Resume_R_PDU_Type;
    m_ui16PDULength = START_RESUME_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_R_PDU::~Start_Resume_R_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

KString Start_Resume_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Start/Resume-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "Real World Time:\n"
       << IndentString( m_RealWorldTime.GetAsString(), 1 )
       << "Simulation Time:\n"
       << IndentString( m_SimTime.GetAsString(), 1 )
       << Reliability_Header::GetAsString()
       << "Request ID: " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Start_Resume_R_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < START_RESUME_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_RealWorldTime
           >> KDIS_STREAM m_SimTime;

    Reliability_Header::Decode( stream );

    stream >> m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Start_Resume_R_PDU::Encode() const
{
    KDataStream stream;

    Start_Resume_R_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Start_Resume_R_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );

    stream << KDIS_STREAM m_RealWorldTime
           << KDIS_STREAM m_SimTime;

    Reliability_Header::Encode( stream );

    stream << m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Start_Resume_R_PDU::operator == ( const Start_Resume_R_PDU & Value ) const
{
    if( Start_Resume_PDU::operator   !=( Value ) ) return false;
    if( Reliability_Header::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Start_Resume_R_PDU::operator != ( const Start_Resume_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
