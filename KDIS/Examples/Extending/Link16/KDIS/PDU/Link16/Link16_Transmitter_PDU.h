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

/********************************************************************
	class:      Link16_Transmitter_PDU
	created:	23/10/2008	
	author:		Karl Jones
	
	purpose:	Transmitter PDU used in Link 16 simulations.
				Joint Tactical Information Distribution System(JTIDS)

				Radio Entity Type:  category should be set to 21 for link 16 terminal.

				Input Source:	    Set automatically to 8 for Digital Data Device.

				Frequency:		    This field shall specify the JTIDS center frequency 
			  						of 1131000000 for communications mode 1. 
									For communications mode 2 or 4, a frequency of
									969000000 shall be used.

				Freq BW:	        Band Width, value of 240000000, unless operating in
									communications mode 2 or 4, and then a value of 3000000 
									shall be used.

				Modulation Type:    A. The Spread Spectrum field shall be set to 1 for
									frequency hopping only for JTIDS communications mode 1. 
									For modes 2 or 4, the Spread Spectrum field shall be set
									to 0.
									B. The Major modulation field shall be set to 7 for
									Carrier Phase Shift Modulation.
									C. The Detail modulation field shall contain a 0.
									D. The System field shall be set to 8 for JTIDS/MIDS.

			   Crypto System:       Set automatically to 0 for link 16.

			   Length Of mod params:Set automatically to 8 for link 16.

			   SetModulationParameters:	Ignore this as we know the modulation params data format
			   GetModulationParameters: Ignore this as we know the modulation params data format

   size:	   896 bits / 112 octets - min size without antenna params
*********************************************************************/

#pragma once

#include "./../../DataTypes/Enums/EnumLink16.h"
#include "KDIS/PDU/Radio_Communications/Transmitter_PDU.h"
#include "./../../KDefinesLink16.h"

namespace KDIS {
namespace PDU {
namespace LINK16 {

class KDIS_EXPORT_LINK16 Link16_Transmitter_PDU : public Transmitter_PDU
{
protected:
	
	KUINT8 m_ui8TSAM;

	KUINT8 m_ui8TTPM;

	KUINT8 m_ui8TTSM;

	KUINT8 m_ui8SyncState;

	KUINT32 m_ui32NetworkSyncID;

public:

	static const KUINT16 LINK16_TRANSMITTER_PDU_SIZE = 112; // Min Size

	Link16_Transmitter_PDU();

	Link16_Transmitter_PDU( KDataStream & stream ) throw( KException );

	Link16_Transmitter_PDU( const Header & H, KDataStream & stream ) throw( KException );

	Link16_Transmitter_PDU( const KDIS::DATA_TYPE::RadioEntityType & Type, KDIS::DATA_TYPE::ENUMS::TransmitState TS, KDIS::DATA_TYPE::ENUMS::RadioInputSource IS,
						    const KDIS::DATA_TYPE::AntennaLocation & AL, KDIS::DATA_TYPE::ENUMS::AntennaPatternType APT, KUINT64 Freq,
							KFLOAT32 FreqBW, KFLOAT32 Power, const KDIS::DATA_TYPE::ModulationType & MT,
							const KDIS::DATA_TYPE::CryptoSystem & CS, const KOCTET * ModulationParams,
							KUINT8 ModulationParamsLength, const KOCTET * AntennaPattern,
							KUINT8 AntennaPatternLength, KDIS::DATA_TYPE::ENUMS::LINK16::TimeSlotAllocationMode TSA, 
							KDIS::DATA_TYPE::ENUMS::LINK16::TransmittingTerminalPrimaryMode TTPM, KDIS::DATA_TYPE::ENUMS::LINK16::TransmittingTerminalSecondaryMode TTSM,
							KUINT32 NetSyncID );
	
	virtual ~Link16_Transmitter_PDU();

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Transmitter_PDU::SetTimeSlotAllocationMode
	//				KDIS::PDU::Link16::Link16_Transmitter_PDU::GetTimeSlotAllocationMode
	// Description: TSA Level.
	// Parameter:   TimeSlotAllocationMode TSA
	//************************************
	void SetTimeSlotAllocationMode( KDIS::DATA_TYPE::ENUMS::LINK16::TimeSlotAllocationMode TSA );
	KDIS::DATA_TYPE::ENUMS::LINK16::TimeSlotAllocationMode GetTimeSlotAllocationMode() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Transmitter_PDU::SetTransmittingTerminalPrimaryMode
	//				KDIS::PDU::Link16::Link16_Transmitter_PDU::GetTransmittingTerminalPrimaryMode
	// Description: Primary mode of operation of the transmitting terminal.
	// Parameter:   TransmittingTerminalPrimaryMode TTPM
	//************************************
	void SetTransmittingTerminalPrimaryMode( KDIS::DATA_TYPE::ENUMS::LINK16::TransmittingTerminalPrimaryMode TTPM );
	KDIS::DATA_TYPE::ENUMS::LINK16::TransmittingTerminalPrimaryMode GetTransmittingTerminalPrimaryMode() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Transmitter_PDU::SetTransmittingTerminalSecondaryMode
	//				KDIS::PDU::Link16::Link16_Transmitter_PDU::GetTransmittingTerminalSecondaryMode
	// Description: Secondary mode of operation of the transmitting terminal.
	// Parameter:   TransmittingTerminalSecondaryMode TTSM
	//************************************
	void SetTransmittingTerminalSecondaryMode( KDIS::DATA_TYPE::ENUMS::LINK16::TransmittingTerminalSecondaryMode TTSM );
	KDIS::DATA_TYPE::ENUMS::LINK16::TransmittingTerminalSecondaryMode GetTransmittingTerminalSecondaryMode() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Transmitter_PDU::GetSynchronizationState
	// Description: Synchronization state. For TSA level 0-3 this shall be
	//              set to 3 for fine synchronization. For TSA level 4, 
	//              it shall be initially set to 2 for coarse synchronization.
	//              This value is automatically set by the SetTimeSlotAllocationMode function.
	//************************************
	KDIS::DATA_TYPE::ENUMS::LINK16::SynchronizationState GetSynchronizationState() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Transmitter_PDU::SetNetworkSyncID
	//				KDIS::PDU::Link16::Link16_Transmitter_PDU::GetNetworkSyncID
	// Description: Set automatically when the TSA level is set.
	//				For TSA levels 0-2, it shall be set to zero. 
	//				For TSA levels 3-4 it shall be a random number
	//				generated using the DIS Timestamp as a seed.
	// Parameter:   TransmittingTerminalSecondaryMode TTSM
	//************************************
	void SetNetworkSyncID( KUINT32 ID );
	KUINT32 GetNetworkSyncID() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Transmitter_PDU::GetAsString
	// Description: Returns a string representation	of the PDU.
	//************************************
	virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Link16::Link16_Transmitter_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Transmitter_PDU::Encode
	// Description: Convert To Network Data. 
	// Parameter:   KDataStream & stream
	//************************************
	virtual KDataStream Encode() const;
	virtual void Encode( KDataStream & stream ) const;

	KBOOL operator == ( const Link16_Transmitter_PDU & Value ) const;
    KBOOL operator != ( const Link16_Transmitter_PDU & Value ) const;
};

} // END namespace LINK16
} // END namespace PDU
} // END namespace KDIS

