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

#include "./Stop_Freeze_PDU.h"

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

Stop_Freeze_PDU::Stop_Freeze_PDU()
{
    m_ui8PDUType = Stop_Freeze_PDU_Type;
    m_ui16PDULength = STOP_FREEZE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_PDU::Stop_Freeze_PDU( const Header & H ) :
	Simulation_Management_Header( H )
{
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_PDU::Stop_Freeze_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_PDU::Stop_Freeze_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Simulation_Management_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_PDU::Stop_Freeze_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity,
                                  const ClockTime & RealWorldTime, StopFreezeReason SFR, FrozenBehavior FB, KUINT32 ReqID ) :
    Simulation_Management_Header( ReceivingEntity, SupplyingEntity ),
    m_RealWorldTime( RealWorldTime ),
    m_ui8Reason( SFR ),
    m_ui8FrozenBehaviour( FB ),
    m_ui16Padding( 0 ),
    m_ui32RequestID( ReqID )
{
    m_ui8PDUType = Stop_Freeze_PDU_Type;
    m_ui16PDULength = STOP_FREEZE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_PDU::Stop_Freeze_PDU( const Simulation_Management_Header & SimMgrHeader, const ClockTime & RealWorldTime,
                                  StopFreezeReason SFR, FrozenBehavior FB, KUINT32 ReqID ) :
    Simulation_Management_Header( SimMgrHeader ),
    m_RealWorldTime( RealWorldTime ),
    m_ui8Reason( SFR ),
    m_ui8FrozenBehaviour( FB ),
    m_ui16Padding( 0 ),
    m_ui32RequestID( ReqID )
{
    m_ui8PDUType = Stop_Freeze_PDU_Type;
    m_ui16PDULength = STOP_FREEZE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_PDU::~Stop_Freeze_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void  Stop_Freeze_PDU::SetRealWorldTime( const ClockTime & T )
{
    m_RealWorldTime = T;
}

//////////////////////////////////////////////////////////////////////////

const ClockTime & Stop_Freeze_PDU::GetRealWorldTime() const
{
    return m_RealWorldTime;
}

//////////////////////////////////////////////////////////////////////////

ClockTime & Stop_Freeze_PDU::GetRealWorldTime()
{
    return m_RealWorldTime;
}

//////////////////////////////////////////////////////////////////////////

void Stop_Freeze_PDU::SetReason( StopFreezeReason SFR )
{
    m_ui8Reason = SFR;
}

//////////////////////////////////////////////////////////////////////////

StopFreezeReason Stop_Freeze_PDU::GetReason() const
{
    return ( StopFreezeReason )m_ui8Reason;
}

//////////////////////////////////////////////////////////////////////////

void Stop_Freeze_PDU::SetFrozenBehavior( FrozenBehavior FB )
{
    m_ui8FrozenBehaviour = FB;
}

//////////////////////////////////////////////////////////////////////////

FrozenBehavior Stop_Freeze_PDU::GetFrozenBehavior() const
{
    return ( FrozenBehavior )m_ui8FrozenBehaviour;
}

//////////////////////////////////////////////////////////////////////////

void Stop_Freeze_PDU::SetRequestID( KUINT32 ID )
{
    m_ui32RequestID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Stop_Freeze_PDU::GetRequestID() const
{
    return m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KString Stop_Freeze_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Stop/Freeze PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "Real World Time:\n"
       << IndentString( m_RealWorldTime.GetAsString(), 1 )
       << "\tReason:           "   << GetEnumAsStringStopFreezeReason( m_ui8Reason )
       << "\n\tFrozen Behavior:  " << GetEnumAsStringFrozenBehavior( m_ui8FrozenBehaviour )
       << "\n\tRequest ID:       " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Stop_Freeze_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < STOP_FREEZE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_RealWorldTime
           >> m_ui8Reason
           >> m_ui8FrozenBehaviour
           >> m_ui16Padding
           >> m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Stop_Freeze_PDU::Encode() const
{
    KDataStream stream;

    Stop_Freeze_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Stop_Freeze_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );
    stream << KDIS_STREAM m_RealWorldTime
           << m_ui8Reason
           << m_ui8FrozenBehaviour
           << m_ui16Padding
           << m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Stop_Freeze_PDU::operator == ( const Stop_Freeze_PDU & Value ) const
{
    if( Simulation_Management_Header::operator  !=( Value ) )                   return false;
    if( m_RealWorldTime                         != Value.m_RealWorldTime )      return false;
    if( m_ui8Reason                             != Value.m_ui8Reason )          return false;
    if( m_ui8FrozenBehaviour                    != Value.m_ui8FrozenBehaviour ) return false;
    if( m_ui32RequestID                         != Value.m_ui32RequestID )      return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Stop_Freeze_PDU::operator != ( const Stop_Freeze_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

