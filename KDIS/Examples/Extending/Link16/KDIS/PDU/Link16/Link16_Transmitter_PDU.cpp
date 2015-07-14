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

#include "./Link16_Transmitter_PDU.h"
#include "KDIS/DataTypes/CryptoSystem.h"
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace LINK16;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace ENUMS::LINK16;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Link16_Transmitter_PDU::Link16_Transmitter_PDU() :
	m_ui8TSAM( 0 ),
	m_ui8TTPM( 0 ),
	m_ui8TTSM( 0 ),
	m_ui8SyncState( 0 ),
	m_ui32NetworkSyncID( 0 )
{
	m_ui16PDULength = LINK16_TRANSMITTER_PDU_SIZE;
	m_CryptoSystem = CryptoSystem( OtherCryptoSystem, BaseBand, 0 );
	m_ui8InputSource = DigitalDataDevice;
	m_ui8LengthOfModulationParam = 8;	
}

//////////////////////////////////////////////////////////////////////////

Link16_Transmitter_PDU::Link16_Transmitter_PDU( KDataStream & stream ) throw( KException )
{
	Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Link16_Transmitter_PDU::Link16_Transmitter_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Transmitter_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Link16_Transmitter_PDU::Link16_Transmitter_PDU( const RadioEntityType & Type, TransmitState TS, RadioInputSource IS,
												const AntennaLocation & AL, AntennaPatternType APT, KUINT64 Freq,
												KFLOAT32 FreqBW, KFLOAT32 Power, const ModulationType & MT,
												const CryptoSystem & CS, const KOCTET * ModulationParams,
												KUINT8 ModulationParamsLength, const KOCTET * AntennaPattern,
												KUINT8 AntennaPatternLength, TimeSlotAllocationMode TSA, 
												TransmittingTerminalPrimaryMode TTPM, TransmittingTerminalSecondaryMode TTSM,
												KUINT32 NetSyncID ) :
	Transmitter_PDU( Type, TS, IS, AL, APT, Freq, FreqBW, Power, MT, CS, ModulationParams, ModulationParamsLength, AntennaPattern, AntennaPatternLength ),
	m_ui8TTPM( TTPM ),
	m_ui8TTSM( TTSM ),
	m_ui32NetworkSyncID( TTSM )
{
	SetTimeSlotAllocationMode( TSA );
	m_ui16PDULength = LINK16_TRANSMITTER_PDU_SIZE;
	m_CryptoSystem = CryptoSystem( OtherCryptoSystem, BaseBand, 0 );
	m_ui8InputSource = DigitalDataDevice;
	m_ui8LengthOfModulationParam = 8;		
}

//////////////////////////////////////////////////////////////////////////

Link16_Transmitter_PDU::~Link16_Transmitter_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Link16_Transmitter_PDU::SetTimeSlotAllocationMode( TimeSlotAllocationMode TSA )
{
	m_ui8TSAM = TSA;

	// Sync State
	if( TSA == TSA4 )m_ui8SyncState = FineSynchronization;
	else m_ui8SyncState = CoarseSynchronization;

	// Network Sync ID
	if( TSA < TSA3 )m_ui32NetworkSyncID = 0;
	else
	{
		// Random number using DIS time stamp as a seed
		srand( GetTimeStamp().GetTime() );
		m_ui32NetworkSyncID = rand();
	}
}

//////////////////////////////////////////////////////////////////////////

TimeSlotAllocationMode Link16_Transmitter_PDU::GetTimeSlotAllocationMode() const
{
	return ( TimeSlotAllocationMode )m_ui8TSAM;
}

////////////////////////////////////////////////////////////////////////////

void Link16_Transmitter_PDU::SetTransmittingTerminalPrimaryMode( TransmittingTerminalPrimaryMode TTPM )
{
	m_ui8TTPM = TTPM;
}

//////////////////////////////////////////////////////////////////////////

TransmittingTerminalPrimaryMode Link16_Transmitter_PDU::GetTransmittingTerminalPrimaryMode() const
{
	return ( TransmittingTerminalPrimaryMode )m_ui8TTPM;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Transmitter_PDU::SetTransmittingTerminalSecondaryMode( TransmittingTerminalSecondaryMode TTSM )
{	
	m_ui8TTSM = TTSM;
}

//////////////////////////////////////////////////////////////////////////

TransmittingTerminalSecondaryMode Link16_Transmitter_PDU::GetTransmittingTerminalSecondaryMode() const
{
	return ( TransmittingTerminalSecondaryMode )m_ui8TTSM;
}

//////////////////////////////////////////////////////////////////////////

SynchronizationState Link16_Transmitter_PDU::GetSynchronizationState() const
{
	return ( SynchronizationState )m_ui8SyncState;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Transmitter_PDU::SetNetworkSyncID( KUINT32 ID )
{
	m_ui32NetworkSyncID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Link16_Transmitter_PDU::GetNetworkSyncID() const
{
	return m_ui32NetworkSyncID;
}

//////////////////////////////////////////////////////////////////////////

KString Link16_Transmitter_PDU::GetAsString() const
{
	KStringStream ss;

	ss << Header::GetAsString()
	<< "-Link16 Transmitter PDU-\n"
	<< Radio_Communications_Header::GetAsString()
	<< "Radio Entity Type:          "           << m_RadioEntityType.GetAsString()
	<< "Transmite State:            "           << ( KUINT16 )m_ui8TransmitterState	                             << "\n"
	<< "Input Source:		        "           << ( KUINT16 )m_ui8InputSource		                             << "\n"
	<< m_AntennaLocation.GetAsString()
	<< "Antenna Pattern Type:       "           << m_ui16AntennaPatternType			                             << "\n"
	<< "Antenna Pattern Length:     "           << m_ui16AntennaPatternLength			                         << "\n"
	<< "Frequency(hertz):		    "           << m_ui64Freq							                         << "\n"
	<< "Transmit Frequency BW:      "           << m_f32TransmitFreqBW				                             << "\n"
	<< "Power(decibel-milliwatts):  "           << m_f32Power							                         << "\n"
	<< m_ModulationType.GetAsString()
	<< m_CryptoSystem.GetAsString()
	<< "Length Of Modulation Param: "           << m_ui8LengthOfModulationParam		                             << "\n"
	<< "Link 16 Params:\n\t"
	<< "Time Slot Allocation Mode:			  " << GetEnumAsStringTimeSlotAllocationMode( m_ui8TSAM	)	         << "\n\t"
	<< "Transmitting Terminal Primary Mode:   " << GetEnumAsStringTransmittingTerminalPrimaryMode( m_ui8TTPM )	 << "\n\t"
	<< "Transmitting Terminal Secondary Mode: " << GetEnumAsStringTransmittingTerminalSecondaryMode( m_ui8TTSM ) << "\n\t"
	<< "Synchronization State:				  " << GetEnumAsStringSynchronizationState( m_ui8SyncState )         << "\n\t"
	<< "Network Synchronization ID:			  " << m_ui32NetworkSyncID		                                     << "\n";

	return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Link16_Transmitter_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
	if( stream.GetBufferSize() < LINK16_TRANSMITTER_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	m_vAntennaPattern.clear();

	Radio_Communications_Header::Decode( stream, ignoreHeader );

	stream >> KDIS_STREAM m_RadioEntityType
		   >> m_ui8TransmitterState
		   >> m_ui8InputSource
		   >> m_ui16Padding1
		   >> KDIS_STREAM m_AntennaLocation
		   >> m_ui16AntennaPatternType
		   >> m_ui16AntennaPatternLength
		   >> m_ui64Freq
		   >> m_f32TransmitFreqBW
		   >> m_f32Power
		   >> KDIS_STREAM m_ModulationType
		   >> KDIS_STREAM m_CryptoSystem
	       >> m_ui8LengthOfModulationParam
		   >> m_ui16Padding2
		   >> m_ui8Padding3
		   >> m_ui8TSAM
		   >> m_ui8TTPM
		   >> m_ui8TTSM
		   >> m_ui8SyncState
		   >> m_ui32NetworkSyncID;

	for( KUINT16 i = 0; i < m_ui16AntennaPatternLength; ++i )
	{
		KOCTET o;
		stream >> o;
		m_vAntennaPattern.push_back( o );
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream Link16_Transmitter_PDU::Encode() const
{
	KDataStream stream;

	Radio_Communications_Header::Encode( stream );

	return stream;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Transmitter_PDU::Encode( KDataStream & stream ) const
{
	Radio_Communications_Header::Encode( stream );

	stream << KDIS_STREAM m_RadioEntityType
		   << m_ui8TransmitterState
		   << m_ui8InputSource
		   << m_ui16Padding1
		   << KDIS_STREAM m_AntennaLocation
		   << m_ui16AntennaPatternType
		   << m_ui16AntennaPatternLength
		   << m_ui64Freq
		   << m_f32TransmitFreqBW
		   << m_f32Power
		   << KDIS_STREAM m_ModulationType
		   << KDIS_STREAM m_CryptoSystem
	       << m_ui8LengthOfModulationParam
		   << m_ui16Padding2
		   << m_ui8Padding3
		   << m_ui8TSAM
		   << m_ui8TTPM
		   << m_ui8TTSM
		   << m_ui8SyncState
		   << m_ui32NetworkSyncID;

	vector<KOCTET>::const_iterator citrAntenna = m_vAntennaPattern.begin();
	vector<KOCTET>::const_iterator citrAntennaEnd = m_vAntennaPattern.end();
	for( ; citrAntenna != citrAntennaEnd; ++citrAntenna )
	{
		stream << *citrAntenna;
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL Link16_Transmitter_PDU::operator == ( const Link16_Transmitter_PDU & Value ) const
{
    if( Transmitter_PDU::operator != ( Value ) )                 return false;
    if( m_ui8TSAM                 != Value.m_ui8TSAM )           return false;
    if( m_ui8TTPM                 != Value.m_ui8TTPM )           return false;
    if( m_ui8TTSM                 != Value.m_ui8TTSM )           return false;
    if( m_ui8SyncState            != Value.m_ui8SyncState )      return false;
	if( m_ui32NetworkSyncID       != Value.m_ui32NetworkSyncID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Link16_Transmitter_PDU::operator != ( const Link16_Transmitter_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
