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

#include "./Start_Resume_PDU.h"

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

Start_Resume_PDU::Start_Resume_PDU() :
    m_ui32RequestID( 0 )
{
    m_ui8PDUType = Start_Resume_PDU_Type;
    m_ui16PDULength = START_RESUME_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_PDU::Start_Resume_PDU( const Header & H ) :
    Simulation_Management_Header( H ),
    m_ui32RequestID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_PDU::Start_Resume_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_PDU::Start_Resume_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
    Simulation_Management_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_PDU::Start_Resume_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity,
                                    const ClockTime & RealWorldTime, const ClockTime & SimTime, KUINT32 ReqID ) :
    Simulation_Management_Header( ReceivingEntity, SupplyingEntity ),
    m_RealWorldTime( RealWorldTime ),
    m_SimTime( SimTime ),
    m_ui32RequestID( ReqID )
{
    m_ui8PDUType = Start_Resume_PDU_Type;
    m_ui16PDULength = START_RESUME_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_PDU::Start_Resume_PDU( const Simulation_Management_Header & SimMgrHeader, const ClockTime & RealWorldTime,
                                    const ClockTime & SimTime, KUINT32 ReqID  ) :
    Simulation_Management_Header( SimMgrHeader ),
    m_RealWorldTime( RealWorldTime ),
    m_SimTime( SimTime ),
    m_ui32RequestID( ReqID )
{
    m_ui8PDUType = Start_Resume_PDU_Type;
    m_ui16PDULength = START_RESUME_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_PDU::~Start_Resume_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void  Start_Resume_PDU::SetRealWorldTime( const ClockTime & T )
{
    m_RealWorldTime = T;
}

//////////////////////////////////////////////////////////////////////////

const ClockTime & Start_Resume_PDU::GetRealWorldTime() const
{
    return m_RealWorldTime;
}

//////////////////////////////////////////////////////////////////////////

ClockTime & Start_Resume_PDU::GetRealWorldTime()
{
    return m_RealWorldTime;
}

//////////////////////////////////////////////////////////////////////////

void Start_Resume_PDU::SetSimulationTime( const ClockTime & T )
{
    m_SimTime = T;
}

//////////////////////////////////////////////////////////////////////////

const ClockTime & Start_Resume_PDU::GetSimulationTime() const
{
    return m_SimTime;
}

//////////////////////////////////////////////////////////////////////////

ClockTime & Start_Resume_PDU::GetSimulationTime()
{
    return m_SimTime;
}

//////////////////////////////////////////////////////////////////////////

void Start_Resume_PDU::SetRequestID( KUINT32 ID )
{
    m_ui32RequestID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Start_Resume_PDU::GetRequestID() const
{
    return m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KString Start_Resume_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Start/Resume PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "Real World Time:\n"
       << IndentString( m_RealWorldTime.GetAsString(), 1 )
       << "Simulation Time:\n"
       << IndentString( m_SimTime.GetAsString(), 1 )
       << "Request ID: " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Start_Resume_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < START_RESUME_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_RealWorldTime
           >> KDIS_STREAM m_SimTime
           >> m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Start_Resume_PDU::Encode() const
{
    KDataStream stream;

    Start_Resume_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Start_Resume_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );
    stream << KDIS_STREAM m_RealWorldTime
           << KDIS_STREAM m_SimTime
           << m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Start_Resume_PDU::operator == ( const Start_Resume_PDU & Value ) const
{
    if( Simulation_Management_Header::operator  !=( Value ) )              return false;
    if( m_RealWorldTime                         != Value.m_RealWorldTime ) return false;
    if( m_SimTime                               != Value.m_SimTime )       return false;
    if( m_ui32RequestID                         != Value.m_ui32RequestID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Start_Resume_PDU::operator != ( const Start_Resume_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


