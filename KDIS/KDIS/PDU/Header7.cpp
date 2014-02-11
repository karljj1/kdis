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

#include "./Header7.h"

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Header7::Header7()
{
	m_PDUStatusUnion.m_ui8PDUStatus = 0;
}

//////////////////////////////////////////////////////////////////////////

Header7::Header7( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Header7::Header7( ProtocolVersion PV, KUINT8 ExerciseID, PDUType PT, ProtocolFamily PF, const TimeStamp & TS, KUINT16 PDULength ) :
    Header6( PV, ExerciseID, PT, PF, TS, PDULength )
{
	m_PDUStatusUnion.m_ui8PDUStatus = 0;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

Header7::~Header7()
{
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatus( KUINT8 S )
{
    m_PDUStatusUnion.m_ui8PDUStatus = S;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Header7::GetPDUStatus() const
{
    return m_PDUStatusUnion.m_ui8PDUStatus;
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusCEI( KBOOL CEI )
{
	m_PDUStatusUnion.m_ui8PDUStatusCEI = CEI;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::GetPDUStatusCEI() const
{
	return m_PDUStatusUnion.m_ui8PDUStatusCEI;
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusTEI( KBOOL TEI )
{
    m_PDUStatusUnion.m_ui8PDUStatusTEI = TEI;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::GetPDUStatusTEI() const
{
    return m_PDUStatusUnion.m_ui8PDUStatusTEI;
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusLVC( LVCIndicator LVC )
{
	m_PDUStatusUnion.m_ui8PDUStatusLVC = LVC;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

LVCIndicator Header7::GetPDUStatusLVC() const
{
	return ( LVCIndicator )m_PDUStatusUnion.m_ui8PDUStatusLVC;
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusFTI( KBOOL FTI )
{
	m_PDUStatusUnion.m_ui8PDUStatusFTI = FTI;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::GetPDUStatusFTI() const
{
	return m_PDUStatusUnion.m_ui8PDUStatusFTI;
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusDTI( DetonationType DTI )
{
	m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI = DTI;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

DetonationType Header7::GetPDUStatusDTI() const
{
	return ( DetonationType )m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI;
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusRAI( AttachedIndicator RAI )
{
	m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI = RAI;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

AttachedIndicator Header7::GetPDUStatusRAI() const
{
	return ( AttachedIndicator )m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI;
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusIAI( AttachedIndicator IAI )
{
	m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI = IAI;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

AttachedIndicator Header7::GetPDUStatusIAI() const
{
	return ( AttachedIndicator )m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI;
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusSM( KBOOL SM )
{
	m_PDUStatusUnion.m_ui8PDUStatusSM = SM;
	m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::GetPDUStatusSM() const
{
	return m_PDUStatusUnion.m_ui8PDUStatusSM;
}

//////////////////////////////////////////////////////////////////////////

KString Header7::GetAsString() const
{
    KStringStream ss;

	ss << Header6::GetAsString();

	// Append the status flags this PDU should have
	if( m_ui8PDUType < Attribute_PDU_Type )
	{
		//
		// CEI - Applies to every PDU except attribute
		//
		ss << "PDU Status:\n"
		   << "\tCoupled Extension Indicator: " << ( KUINT16 )m_PDUStatusUnion.m_ui8PDUStatusCEI << "\n"; 
	
		//
		// TEI - Applies to various PDU
		//
		if( m_ui8PDUType == Entity_State_PDU_Type               ||
			m_ui8PDUType == Electromagnetic_Emission_PDU_Type   ||
			m_ui8PDUType == Designator_PDU_Type                 ||
			m_ui8PDUType == Transmitter_PDU_Type                ||
			m_ui8PDUType == Signal_PDU_Type                     ||
			m_ui8PDUType == Receiver_PDU_Type                   ||
			m_ui8PDUType == IFF_ATC_NAVAIDS_PDU_Type            ||
			m_ui8PDUType == IntercomSignal_PDU_Type             ||
			m_ui8PDUType == IntercomControl_PDU_Type            ||
			m_ui8PDUType == EnvironmentalProcess_PDU_Type       ||
			m_ui8PDUType == EntityStateUpdate_PDU_Type )
		{
			ss << "\tTransferred Entity Indicator: " << ( KUINT16 )m_PDUStatusUnion.m_ui8PDUStatusTEI << "\n";
		}

		//
		// LVC - Applies to various PDU
		//
		if( m_ui8PDUType == Entity_State_PDU_Type               ||
			m_ui8PDUType == Fire_PDU_Type                       ||
			m_ui8PDUType == Designator_PDU_Type                 ||
			m_ui8PDUType == Electromagnetic_Emission_PDU_Type   ||
			m_ui8PDUType == Designator_PDU_Type                 ||
			m_ui8PDUType == Transmitter_PDU_Type                ||
			m_ui8PDUType == Signal_PDU_Type                     ||
			m_ui8PDUType == Receiver_PDU_Type                   ||
			m_ui8PDUType == IFF_ATC_NAVAIDS_PDU_Type            ||
			m_ui8PDUType == IntercomSignal_PDU_Type             ||
			m_ui8PDUType == IntercomControl_PDU_Type            ||
			m_ui8PDUType == EnvironmentalProcess_PDU_Type       ||
			m_ui8PDUType == EntityStateUpdate_PDU_Type          ||
			m_ui8PDUType == DirectedEnergyFire_PDU_Type         ||
			m_ui8PDUType == EntityDamageStatus_PDU_Type         ||
			m_ui8PDUType == IO_Action_PDU_Type                  ||
			m_ui8PDUType == IO_Report_PDU_Type ) 
		{
			ss << "\tLVC Indicator: " << GetEnumAsStringLVCIndicator( m_PDUStatusUnion.m_ui8PDUStatusLVC ) << "\n";
		}

		//
		// FTI - Fire PDU only or DTI - Detonation PDU only
		//
		if( m_ui8PDUType != Fire_PDU_Type )
		{
			ss << "\tFire Type Indicator: " << ( KUINT16 )m_PDUStatusUnion.m_ui8PDUStatusFTI << "\n"; 
		}
		else if( m_ui8PDUType != Detonation_PDU_Type )
		{
			ss << "\tDetonation Type Indicator: " << ( KUINT16 )m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI << "\n"; 
		}

		// 
		// RAI - Transmitter(25), Signal(26), Receiver(27) or IAI  - IntercomSignal(31), IntercomControl(32)
		//
		if( m_ui8PDUType == Transmitter_PDU_Type  ||
			m_ui8PDUType == Signal_PDU_Type       ||
			m_ui8PDUType == Receiver_PDU_Type )
		{
			ss << "\tRadio Attached Indicator: " << GetEnumAsStringAttachedIndicator( m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI ) << "\n"; 
		}
		else if( m_ui8PDUType == IntercomSignal_PDU_Type  ||
				 m_ui8PDUType == IntercomControl_PDU_Type )
		{
			ss << "\tIntercom Attached Indicator: " << GetEnumAsStringAttachedIndicator( m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI ) << "\n"; 
		}

		//
		// SM - IFF ATC NAVAIDS(28) only
		//
		if( m_ui8PDUType == IFF_ATC_NAVAIDS_PDU_Type )
		{
			ss << "\tSimulation Mode: " << ( KUINT16 )m_PDUStatusUnion.m_ui8PDUStatusSM << "\n";
		}
	}

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Header7::Decode( KDataStream & stream, bool ignoreHeader /*= false*/ ) throw( KException )
{
	if( !ignoreHeader )
	{
		if( stream.GetBufferSize() < HEADER6_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

		stream >> m_ui8ProtocolVersion
			   >> m_ui8ExerciseID
			   >> m_ui8PDUType
			   >> m_ui8ProtocolFamily
			   >> KDIS_STREAM m_TimeStamp
			   >> m_ui16PDULength
			   >> ( ( m_ui8ProtocolFamily == LiveEntity ) ? m_ui8Padding1 : m_PDUStatusUnion.m_ui8PDUStatus ) // LE family use the padding for the sub protocol field.
			   >> m_ui8Padding2;
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream Header7::Encode() const
{
    KDataStream stream;

    Header6::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Header7::Encode( KDataStream & stream ) const
{
    stream << m_ui8ProtocolVersion
           << m_ui8ExerciseID
           << m_ui8PDUType
           << m_ui8ProtocolFamily
           << KDIS_STREAM m_TimeStamp
           << m_ui16PDULength
		   << ( ( m_ui8ProtocolFamily == LiveEntity ) ? m_ui8Padding1 : m_PDUStatusUnion.m_ui8PDUStatus )  // LE family use the padding for the sub protocol field.
           << m_ui8Padding2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::operator == ( const Header7 & Value ) const
{
    if( Header6::operator !=( Value ) ) return false;
	if( m_PDUStatusUnion.m_ui8PDUStatus != Value.m_PDUStatusUnion.m_ui8PDUStatus ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::operator != ( const Header7 & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


