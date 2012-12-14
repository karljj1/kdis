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

#include "./Header7.h"

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Header7::Header7( void )
{
	m_PDUStatusUnion.m_ui8PDUStatus = 0;
}

//////////////////////////////////////////////////////////////////////////

Header7::Header7( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Header7::Header7( ProtocolVersion PV, KUINT8 ExerciseID, PDUType PT, ProtocolFamily PF, const TimeStamp & TS, KUINT16 PDULength ) :
    Header6( PV, ExerciseID, PT, PF, TS, PDULength )
{
	m_PDUStatusUnion.m_ui8PDUStatus = 0;
}

//////////////////////////////////////////////////////////////////////////

Header7::~Header7( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatus( KUINT8 S )
{
    m_PDUStatusUnion.m_ui8PDUStatus = S;
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

void Header7::Decode( KDataStream & stream ) throw( KException )
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


