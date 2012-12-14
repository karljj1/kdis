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

Start_Resume_R_PDU::Start_Resume_R_PDU( void )
{
    m_ui8PDUType = Start_Resume_R_PDU_Type;
    m_ui16PDULength = START_RESUME_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Start_Resume_R_PDU::Start_Resume_R_PDU( KDataStream & stream ) throw( KException )
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

Start_Resume_R_PDU::~Start_Resume_R_PDU( void )
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

void Start_Resume_R_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < START_RESUME_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream );

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
