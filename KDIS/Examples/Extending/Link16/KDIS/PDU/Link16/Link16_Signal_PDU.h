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
	class:      Link16_Signal_PDU
	created:	22/10/2008/
	author:		Karl Jones
	
	purpose:	Used for transmitting Link 16 data messages
				Note: The link 16 messages are not implemented, you will need
				to pass them as data in a octet buffer form.

	EncodingScheme: Set automatically. TDL = Link16StandardizedFormat_JTIDS_MIDS_TADILJ
	
	Sample Rate:    Set to 0 automatically.

	Samples:		Set to 0 automatically.
	
	SetData:	Returns the link 16 message in octets
	GetData:	Set the link 16 message in octets

	size:		416 bits / 52 - min size
*********************************************************************/

#pragma once

#include "KDIS/PDU/Radio_Communications/Signal_PDU.h"
#include "./../../DataTypes/Enums/EnumLink16.h"
#include "./../../KDefinesLink16.h"

namespace KDIS {
namespace PDU {
namespace LINK16 {

class KDIS_EXPORT_LINK16 Link16_Signal_PDU : public Signal_PDU
{
protected:

	KUINT16 m_ui16NPG;

	KUINT8 m_ui8NetNumber;

	KUINT8 m_ui8TSEC;

	KUINT8 m_ui8MSEC;

	KUINT8 m_ui8MsgType;

	KUINT16 m_ui16Padding1;

	union
	{
		struct
		{
			KUINT32 m_ui32TimeSlotNumber	: 17;

			KUINT32 m_ui32Padding1			: 7;

			KUINT32 m_ui32Epoch				: 8;
		};
		KUINT32 m_ui16TimeSlotID;
	}m_TimeSlotIDUnion;

	KUINT32 m_ui32PTTInteger;

	KUINT32 m_ui32PTTFraction;

public:
	    
	static const KUINT16 LINK16_SIGNAL_PDU_SIZE = 52;

	Link16_Signal_PDU();	

	Link16_Signal_PDU( KDataStream & stream ) throw( KException );

	Link16_Signal_PDU( const Header & H, KDataStream & stream ) throw( KException );

	Link16_Signal_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ID, KUINT16 RadioID, const KDIS::DATA_TYPE::EncodingScheme & ES,
                       KUINT32 SampleRate, KUINT16 Samples, const KOCTET * Data, KUINT16 DataLength,
					   KUINT16 NPG, KUINT8 NN, KUINT8 TSEC, KUINT8 MSEC, KDIS::DATA_TYPE::ENUMS::LINK16::Link16MessageType MT,
					   KUINT32 TSN, KUINT32 Epoch, KUINT32 TTInteger, KUINT32 TTFraction );
	
	virtual ~Link16_Signal_PDU();

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::SetNetworkParticipationGroup
	//				KDIS::PDU::Link16::Link16_Signal_PDU::GetNetworkParticipationGroup
	// Description: Network Participation Group 
	//				Valid values are 0-511. If outside of this range it will be set to 511
	//				Used to segregate information within a JTIDS/MIDS network.
	//				Creates virtual networks of participants.
	// Parameter:   KUINT16 NPG
	//************************************
	void SetNetworkParticipationGroup( KUINT16 NPG );
	KUINT16 GetNetworkParticipationGroup() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::SetNetworkParticipationGroup
	//				KDIS::PDU::Link16::Link16_Signal_PDU::GetNetworkParticipationGroup
	// Description: Network Number. Used to create virtual sub-circuits 
	//				within NPG for stacked nets or between NPGs for multi-net.
	//				Valid values are 0-127. If outside of this range it will be set to 127
	// Parameter:   KUINT16 NPG
	//************************************
	void SetNetNumber( KUINT8 NN );
	KUINT8 GetNetNumber() const;

	//************************************	
	// FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::SetTransmissionSecurity
	//				KDIS::PDU::Link16::Link16_Signal_PDU::GetTransmissionSecurity
	// Description: Identification of the crypto variable used for
	//				JTIDS transmission encryption.
	//				Valid values are 0-127. If outside of this range it 
	//				will be set to 255 to indicate no statement/wildcard.
	// Parameter:   KUINT8 TSEC
	//************************************
	void SetTransmissionSecurity( KUINT8 TSEC );
	KUINT8 GetTransmissionSecurity() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::SetMessageSecurity
	//				KDIS::PDU::Link16::Link16_Signal_PDU::GetMessageSecurity
	// Description: Identification of the crypto variable used for
	//				JTIDS message encryption.
	//				Valid values are 0-127. If outside of this range it 
	//				will be set to 255 to indicate no statement/wildcard.
	// Parameter:   KUINT8 MSEC
	//************************************
	void SetMessageSecurity( KUINT8 MSEC );
	KUINT8 GetMessageSecurity() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::SetMessageType
	//				KDIS::PDU::Link16::Link16_Signal_PDU::GetMessageType
	// Description: Link 16 message type. 
	// Parameter:   Link16MessageType MT
	//************************************
	void SetMessageType( KDIS::DATA_TYPE::ENUMS::LINK16::Link16MessageType MT );
	KDIS::DATA_TYPE::ENUMS::LINK16::Link16MessageType GetMessageType() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::Link16_Signal_PDU::SetTimeSlotNumber
	//				KDIS::DATA_TYPE::Link16_Signal_PDU::GetTimeSlotNumber
	// Description: 0 value represents time slot A-1,
	//				time slot 98303 represents C-32767. 
	//				When the epoch is 112, the last valid time slot
	//				is 45151 (end of the day).
	//				Valid range 0-98303.
	// Parameter:   KUINT32 TSN
	//************************************
	void SetTimeSlotNumber( KUINT32 TSN );
	KUINT32 GetTimeSlotNumber() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::SetEpoch
	//			    KDIS::PDU::Link16::Link16_Signal_PDU::GetEpoch
	// Description: An epoch is 12.8 minutes long, 112.5
	//				Epochs in a 24 hour day. 
	//				Valid range 0-112.
	// Parameter:   KUINT32 E
	//************************************
	void SetEpoch( KUINT32 E );
	KUINT32 GetEpoch() const;

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::SetPerceivedTransmitTime
	//				KDIS::PDU::Link16::Link16_Signal_PDU::GetPerceivedTransmitTime
	// Description: NTP timestamp format-- NTP timestamps
	//				are represented as a 64-bit unsigned
	//				fixed-point number, in seconds relative to
	//				0 hours on 1 January 1900 UTC. 
	//				The integer part is in the first 32 bits 
	//				and the fraction part in the last 32 bits. The precision of
	//				All Fs (4294967295) in both fields shall indicate
	//				a no statement/wildcard.
	// Parameter:   KUINT32
	//************************************
	void SetPerceivedTransmitTimeInteger( KUINT32 PTTI );
	KUINT32 GetPerceivedTransmitTimeInteger() const;
	void SetPerceivedTransmitTimeFraction( KUINT32 PTTF );
	KUINT32 GetPerceivedTransmitTimeFraction() const;
	void SetPerceivedTransmitTime( KUINT32 Integer, KUINT32 Fraction );

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::GetAsString
	// Description: Returns a string representation of the PDU.
	//************************************
	virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

	//************************************
	// FullName:    KDIS::PDU::Link16::Link16_Signal_PDU::Encode
	// Description: Convert To Network Data. 
	// Parameter:   KDataStream & stream
	//************************************
	virtual KDataStream Encode() const;
	virtual void Encode( KDataStream & stream ) const;

	KBOOL operator == ( const Link16_Signal_PDU & Value ) const;
    KBOOL operator != ( const Link16_Signal_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
} // END namespace LINK16
