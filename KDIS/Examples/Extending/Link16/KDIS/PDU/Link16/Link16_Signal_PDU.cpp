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

#include "./Link16_Signal_PDU.h"

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

Link16_Signal_PDU::Link16_Signal_PDU() :
	m_ui16NPG( 0 ),
	m_ui8NetNumber( 0 ),
	m_ui8TSEC( 0 ),
	m_ui8MSEC( 0 ),
	m_ui8MsgType( 0 ),
	m_ui16Padding1( 0 ),
	m_ui32PTTInteger( 0 ),
	m_ui32PTTFraction( 0 )
{
	m_TimeSlotIDUnion.m_ui16TimeSlotID = 0;
	m_ui16PDULength = LINK16_SIGNAL_PDU_SIZE;
	m_EncodingScheme.SetEncodingClass( RawBinaryData );
	m_EncodingScheme.SetTDLType( Link16StandardizedFormat_JTIDS_MIDS_TADILJ_ );
}

//////////////////////////////////////////////////////////////////////////

Link16_Signal_PDU::Link16_Signal_PDU( KDataStream & stream ) throw( KException )
{
	Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Link16_Signal_PDU::Link16_Signal_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Signal_PDU( H )
{
	Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Link16_Signal_PDU::Link16_Signal_PDU( const EntityIdentifier & ID, KUINT16 RadioID, const EncodingScheme & ES,
									  KUINT32 SampleRate, KUINT16 Samples, const KOCTET * Data, KUINT16 DataLength,
									  KUINT16 NPG, KUINT8 NN, KUINT8 TSEC, KUINT8 MSEC, Link16MessageType MT,
									  KUINT32 TSN, KUINT32 Epoch, KUINT32 TTInteger, KUINT32 TTFraction ) :
	Signal_PDU( ID, RadioID, ES, SampleRate, Samples, Data, DataLength ),
	m_ui16NPG( NPG ),
	m_ui8NetNumber( NN ),
	m_ui8TSEC( TSEC ),
	m_ui8MSEC( MSEC ),
	m_ui8MsgType( MT ),
	m_ui16Padding1( 0 ),
	m_ui32PTTInteger( TTInteger ),
	m_ui32PTTFraction( TTFraction )
{
	m_TimeSlotIDUnion.m_ui32TimeSlotNumber = TSN;
	m_TimeSlotIDUnion.m_ui32Padding1 = 0;
	m_TimeSlotIDUnion.m_ui32Epoch = Epoch;
	m_ui16PDULength = LINK16_SIGNAL_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Link16_Signal_PDU::~Link16_Signal_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetNetworkParticipationGroup( KUINT16 NPG )
{
	if( NPG > 511 )m_ui16NPG = 511;
	else m_ui16NPG = NPG;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Link16_Signal_PDU::GetNetworkParticipationGroup() const
{
	return m_ui16NPG;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetNetNumber( KUINT8 NN )
{
	if( NN > 127 )m_ui8NetNumber = 127;
	else m_ui8NetNumber = NN;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Link16_Signal_PDU::GetNetNumber() const
{
	return m_ui8NetNumber;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetTransmissionSecurity( KUINT8 TSEC )
{
	if( TSEC > 127 )m_ui8TSEC = 255;
	else m_ui8TSEC = TSEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Link16_Signal_PDU::GetTransmissionSecurity() const
{
	return m_ui8TSEC;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetMessageSecurity( KUINT8 MSEC )
{
	if( MSEC > 127 )m_ui8MSEC = 255;
	else m_ui8MSEC = MSEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Link16_Signal_PDU::GetMessageSecurity() const
{
	return m_ui8MSEC;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetMessageType( Link16MessageType MT )
{
	m_ui8MsgType = MT;
}

//////////////////////////////////////////////////////////////////////////

Link16MessageType Link16_Signal_PDU::GetMessageType() const
{
	return ( Link16MessageType )m_ui8MsgType;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetTimeSlotNumber( KUINT32 TSN )
{
	m_TimeSlotIDUnion.m_ui32TimeSlotNumber = TSN;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Link16_Signal_PDU::GetTimeSlotNumber() const
{
	return m_TimeSlotIDUnion.m_ui32TimeSlotNumber;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetEpoch( KUINT32 E )
{
	m_TimeSlotIDUnion.m_ui32Epoch = E;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Link16_Signal_PDU::GetEpoch() const
{
	return m_TimeSlotIDUnion.m_ui32Epoch;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetPerceivedTransmitTimeInteger( KUINT32 PTTI )
{
	m_ui32PTTInteger = PTTI;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Link16_Signal_PDU::GetPerceivedTransmitTimeInteger() const
{
	return m_ui32PTTInteger;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetPerceivedTransmitTimeFraction( KUINT32 PTTF )
{
	m_ui32PTTFraction = PTTF;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Link16_Signal_PDU::GetPerceivedTransmitTimeFraction() const
{
	return m_ui32PTTFraction;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::SetPerceivedTransmitTime( KUINT32 Integer, KUINT32 Fraction )
{
	m_ui32PTTInteger = Integer;
	m_ui32PTTFraction = Fraction;
}

//////////////////////////////////////////////////////////////////////////

KString Link16_Signal_PDU::GetAsString() const
{
	KStringStream ss;

	ss << Header::GetAsString()
	<< "-Link16 Signal PDU-\n"
	<< Radio_Communications_Header::GetAsString()
	<< m_EncodingScheme.GetAsString()
	<< "Sample Rate:				 " << m_ui32SampleRate			                       << "\n"
	<< "Data Length:				 " << m_ui16DataLength			                       << "\n"
	<< "Samples:					 " << m_ui16Samples				                       << "\n"
	<< "Network Participation Group: " << m_ui16NPG					                       << "\n"
	<< "Network Number:				 " << ( KUINT16 )m_ui8NetNumber                        << "\n"
	<< "Transmission Security:		 " << ( KUINT16 )m_ui8TSEC		                       << "\n"
	<< "Message Security:			 " << ( KUINT16 )m_ui8MSEC		                       << "\n"
	<< "Message Type:				 " << GetEnumAsStringLink16MessageType( m_ui8MsgType ) << "\n"
	<< "Time Slot ID:				 " << m_TimeSlotIDUnion.m_ui16TimeSlotID	           << "\n"
	<< "Perceived Transmit Time:	 " << m_ui32PTTInteger << " : " << m_ui32PTTFraction   << "\n";

	// Data is not printed as we dont know what the data is.
	
	return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
	if( stream.GetBufferSize() < LINK16_SIGNAL_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	Radio_Communications_Header::Decode( stream, ignoreHeader );

	stream >> KDIS_STREAM m_EncodingScheme
		   >> m_ui32SampleRate
		   >> m_ui16DataLength
		   >> m_ui16Samples
		   >> m_ui16NPG
		   >> m_ui8NetNumber
		   >> m_ui8TSEC
		   >> m_ui8MSEC
		   >> m_ui8MsgType
		   >> m_ui16Padding1
		   >> m_TimeSlotIDUnion.m_ui16TimeSlotID
		   >> m_ui32PTTInteger
		   >> m_ui32PTTFraction;

	for( KUINT16 i = 0; i < ( m_ui16DataLength / 8 ); ++i )
	{
		KOCTET o;
		stream >> o;
		m_vData.push_back( o );
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream Link16_Signal_PDU::Encode() const
{
	KDataStream stream;

	Radio_Communications_Header::Encode( stream );

	return stream;
}

//////////////////////////////////////////////////////////////////////////

void Link16_Signal_PDU::Encode( KDataStream & stream ) const
{
	Radio_Communications_Header::Encode( stream ); 

	stream << KDIS_STREAM m_EncodingScheme
		   << m_ui32SampleRate
		   << m_ui16DataLength
		   << m_ui16Samples
		   << m_ui16NPG
		   << m_ui8NetNumber
		   << m_ui8TSEC
		   << m_ui8MSEC
		   << m_ui8MsgType
		   << m_ui16Padding1
		   << m_TimeSlotIDUnion.m_ui16TimeSlotID
		   << m_ui32PTTInteger
		   << m_ui32PTTFraction;

	vector<KOCTET>::const_iterator citr = m_vData.begin();

	for( ; citr != m_vData.end(); ++citr )
	{
		stream << *citr;
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL Link16_Signal_PDU::operator == ( const Link16_Signal_PDU & Value ) const
{
    if( Signal_PDU::operator               != ( Value ) )                                return false;
    if( m_ui16NPG                          != Value.m_ui16NPG )                          return false;
    if( m_ui8NetNumber                     != Value.m_ui8NetNumber )                     return false;
    if( m_ui8TSEC                          != Value.m_ui8TSEC )                          return false;
    if( m_ui8MSEC                          != Value.m_ui8MSEC )                          return false;
    if( m_ui8MsgType                       != Value.m_ui8MsgType )                       return false;
	if( m_TimeSlotIDUnion.m_ui16TimeSlotID != Value.m_TimeSlotIDUnion.m_ui16TimeSlotID ) return false;
	if( m_ui32PTTInteger                   != Value.m_ui32PTTInteger )                   return false;
	if( m_ui32PTTFraction                  != Value.m_ui32PTTFraction )                  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Link16_Signal_PDU::operator != ( const Link16_Signal_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
