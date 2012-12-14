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

Stop_Freeze_R_PDU::Stop_Freeze_R_PDU( void )
{
    m_ui8PDUType = Stop_Freeze_R_PDU_Type;
    m_ui16PDULength = STOP_FREEZE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Stop_Freeze_R_PDU::Stop_Freeze_R_PDU( KDataStream & stream ) throw( KException )
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

Stop_Freeze_R_PDU::~Stop_Freeze_R_PDU( void )
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

void Stop_Freeze_R_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < STOP_FREEZE_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream );

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

