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

Stop_Freeze_PDU::Stop_Freeze_PDU( void )
{
    m_ui8PDUType = Stop_Freeze_PDU_Type;
    m_ui16PDULength = STOP_FREEZE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_PDU::Stop_Freeze_PDU( KDataStream & stream ) throw( KException )
{
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
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

Stop_Freeze_PDU::~Stop_Freeze_PDU( void )
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

void Stop_Freeze_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < STOP_FREEZE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream );

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

