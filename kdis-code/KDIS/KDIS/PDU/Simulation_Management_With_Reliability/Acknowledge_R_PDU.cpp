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

#include "./Acknowledge_R_PDU.h"

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

Acknowledge_R_PDU::Acknowledge_R_PDU( void )
{
    m_ui8PDUType = Acknowledge_R_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( KDataStream & stream ) throw( KException )
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

Acknowledge_R_PDU::Acknowledge_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                                      AcknowledgeFlag AF, AcknowledgeResponseFlag ARF, KUINT32 RequestID ) :
    Acknowledge_PDU( OriginatingEntityID, ReceivingEntityID, AF, ARF, RequestID )
{
    m_ui8PDUType = Acknowledge_R_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Simulation_Management_Header & SimMgrHeader, AcknowledgeFlag AF,
                                      AcknowledgeResponseFlag ARF, KUINT32 RequestID ) :
    Acknowledge_PDU( SimMgrHeader, AF, ARF, RequestID )
{
    m_ui8PDUType = Acknowledge_R_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Create_Entity_R_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), CreateEntityPDU, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Remove_Entity_R_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), RemoveEntityPDU, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Start_Resume_R_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), Start_ResumePDU, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Stop_Freeze_R_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), Stop_FreezePDU, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Transfer_Control_Request_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), TransferControlRequest, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::~Acknowledge_R_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KString Acknowledge_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Acknowledge-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "\tAcknowledge Flag:   "   << GetEnumAsStringAcknowledgeFlag( m_ui16AcknowledgeFlag )
       << "\n\tResponse Flag:      " << GetEnumAsStringAcknowledgeResponseFlag( m_ui16ResponseFlag )
       << "\n\tRequest ID:         " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Acknowledge_R_PDU::operator == ( const Acknowledge_R_PDU & Value ) const
{
    if( Acknowledge_PDU::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Acknowledge_R_PDU::operator != ( const Acknowledge_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
