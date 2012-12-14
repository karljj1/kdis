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

#include "./Acknowledge_PDU.h"

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

Acknowledge_PDU::Acknowledge_PDU( void )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::Acknowledge_PDU( KDataStream & stream ) throw( KException )
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

Acknowledge_PDU::Acknowledge_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                                  AcknowledgeFlag AF, AcknowledgeResponseFlag ARF, KUINT32 RequestID ) :
    Simulation_Management_Header( OriginatingEntityID, ReceivingEntityID ),
    m_ui16AcknowledgeFlag( AF ),
    m_ui16ResponseFlag( ARF ),
    m_ui32RequestID( RequestID )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::Acknowledge_PDU( const Simulation_Management_Header & SimMgrHeader, AcknowledgeFlag AF,
                                  AcknowledgeResponseFlag ARF, KUINT32 RequestID ) :
    Simulation_Management_Header( SimMgrHeader ),
    m_ui16AcknowledgeFlag( AF ),
    m_ui16ResponseFlag( ARF ),
    m_ui32RequestID( RequestID )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::Acknowledge_PDU( const Create_Entity_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Simulation_Management_Header( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID() ),
    m_ui16AcknowledgeFlag( CreateEntityPDU ),
    m_ui16ResponseFlag( ARF ),
    m_ui32RequestID( pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::Acknowledge_PDU( const Remove_Entity_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Simulation_Management_Header( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID() ),
    m_ui16AcknowledgeFlag( RemoveEntityPDU ),
    m_ui16ResponseFlag( ARF ),
    m_ui32RequestID( pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::Acknowledge_PDU( const Start_Resume_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Simulation_Management_Header( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID() ),
    m_ui16AcknowledgeFlag( Start_ResumePDU ),
    m_ui16ResponseFlag( ARF ),
    m_ui32RequestID( pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::Acknowledge_PDU( const Stop_Freeze_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Simulation_Management_Header( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID() ),
    m_ui16AcknowledgeFlag( Stop_FreezePDU ),
    m_ui16ResponseFlag( ARF ),
    m_ui32RequestID( pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::~Acknowledge_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Acknowledge_PDU::SetAcknowledgeFlag( AcknowledgeFlag AF )
{
    m_ui16AcknowledgeFlag = AF;
}

//////////////////////////////////////////////////////////////////////////

AcknowledgeFlag Acknowledge_PDU::GetAcknowledgeFlag() const
{
    return ( AcknowledgeFlag )m_ui16AcknowledgeFlag;
}

//////////////////////////////////////////////////////////////////////////

void Acknowledge_PDU::SetAcknowledgeResponseFlag( AcknowledgeResponseFlag ARF )
{
    m_ui16ResponseFlag = ARF;
}

//////////////////////////////////////////////////////////////////////////

AcknowledgeResponseFlag Acknowledge_PDU::GetAcknowledgeResponseFlag() const
{
    return ( AcknowledgeResponseFlag )m_ui16ResponseFlag;
}

//////////////////////////////////////////////////////////////////////////

void Acknowledge_PDU::SetRequestID( KUINT32 ID )
{
    m_ui32RequestID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Acknowledge_PDU::GetRequestID() const
{
    return m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KString Acknowledge_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Acknowledge PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "\tAcknowledge Flag:  "   << GetEnumAsStringAcknowledgeFlag( m_ui16AcknowledgeFlag )
       << "\n\tResponse Flag:     " << GetEnumAsStringAcknowledgeResponseFlag( m_ui16ResponseFlag )
       << "\n\tRequest ID:        " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Acknowledge_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ACKNOWLEDGE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream );
    stream >> m_ui16AcknowledgeFlag
           >> m_ui16ResponseFlag
           >> m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Acknowledge_PDU::Encode() const
{
    KDataStream stream;

    Acknowledge_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Acknowledge_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );
    stream << m_ui16AcknowledgeFlag
           << m_ui16ResponseFlag
           << m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Acknowledge_PDU::operator == ( const Acknowledge_PDU & Value ) const
{
    if( Simulation_Management_Header::operator   !=( Value ) )                    return false;
    if( m_ui16AcknowledgeFlag                    != Value.m_ui16AcknowledgeFlag ) return false;
    if( m_ui16ResponseFlag                       != Value.m_ui16ResponseFlag )    return false;
    if( m_ui32RequestID                          != Value.m_ui32RequestID )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Acknowledge_PDU::operator != ( const Acknowledge_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



