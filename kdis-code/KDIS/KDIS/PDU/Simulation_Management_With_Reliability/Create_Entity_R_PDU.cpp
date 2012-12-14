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

#include "./Create_Entity_R_PDU.h"

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

Create_Entity_R_PDU::Create_Entity_R_PDU( void )
{
    m_ui8PDUType = CreateEntity_R_PDU_Type;
    m_ui16PDULength = CREATE_ENTITY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}
//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::Create_Entity_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::Create_Entity_R_PDU( const EntityIdentifier & OrigintatingID, const EntityIdentifier & ReceivingID,
        KUINT32 RequestID, RequiredReliabilityService RRS ) :
    Create_Entity_PDU( OrigintatingID, ReceivingID, RequestID ),
    Reliability_Header( RRS )
{
    m_ui8PDUType = CreateEntity_R_PDU_Type;
    m_ui16PDULength = CREATE_ENTITY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::Create_Entity_R_PDU( const Simulation_Management_Header & SimMgrHeader, KUINT32 RequestID,
        RequiredReliabilityService RRS ) :
    Create_Entity_PDU( SimMgrHeader, RequestID ),
    Reliability_Header( RRS )
{
    m_ui8PDUType = CreateEntity_R_PDU_Type;
    m_ui16PDULength = CREATE_ENTITY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::~Create_Entity_R_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KString Create_Entity_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Create Entity-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << Reliability_Header::GetAsString()
       << "Request ID: " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Create_Entity_R_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < CREATE_ENTITY_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream );

    Reliability_Header::Decode( stream );

    stream >> m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Create_Entity_R_PDU::Encode() const
{
    KDataStream stream;

    Create_Entity_R_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Create_Entity_R_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );

    Reliability_Header::Encode( stream );

    stream << m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Create_Entity_R_PDU::operator == ( const Create_Entity_R_PDU & Value ) const
{
    if( Create_Entity_PDU::operator  !=( Value ) ) return false;
    if( Reliability_Header::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Create_Entity_R_PDU::operator != ( const Create_Entity_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

