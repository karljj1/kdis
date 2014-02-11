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

Acknowledge_PDU::Acknowledge_PDU()
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::Acknowledge_PDU( const Header & H ) :
	Simulation_Management_Header( H )
{
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::Acknowledge_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_PDU::Acknowledge_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Simulation_Management_Header( H )
{
    Decode( stream, true );
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

Acknowledge_PDU::~Acknowledge_PDU()
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

void Acknowledge_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < ACKNOWLEDGE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	
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



