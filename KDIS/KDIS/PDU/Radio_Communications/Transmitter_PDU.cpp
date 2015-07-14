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

#include "./Transmitter_PDU.h"

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

Transmitter_PDU::Transmitter_PDU() :
    m_ui16Padding1( 0 ),
    m_ui16AntennaPatternLength( 0 ),
    m_ui8LengthOfModulationParam( 0 ),
    m_ui16Padding2( 0 ),
    m_ui8Padding3( 0 )
{
    m_ui8PDUType = Transmitter_PDU_Type;
    m_ui16PDULength = TRANSMITTER_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Transmitter_PDU::Transmitter_PDU( const Header & H ) :
	Radio_Communications_Header( H ),    
	m_ui16Padding1( 0 ),
    m_ui16AntennaPatternLength( 0 ),
    m_ui8LengthOfModulationParam( 0 ),
    m_ui16Padding2( 0 ),
    m_ui8Padding3( 0 )	
{
}

//////////////////////////////////////////////////////////////////////////

Transmitter_PDU::Transmitter_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Transmitter_PDU::Transmitter_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Radio_Communications_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Transmitter_PDU::Transmitter_PDU( const RadioEntityType & Type, TransmitState TS, RadioInputSource IS,
                                  const AntennaLocation & AL, AntennaPatternType APT, KUINT64 Freq,
                                  KFLOAT32 FreqBW, KFLOAT32 Power, const ModulationType & MT,
                                  const CryptoSystem & CS, const KOCTET * ModulationParams,
                                  KUINT8 ModulationParamsLength, const KOCTET * AntennaPattern,
                                  KUINT16 AntennaPatternLength ) :
    m_RadioEntityType( Type ),
    m_ui8TransmitterState( TS ),
    m_ui8InputSource( IS ),
    m_ui16Padding1( 0 ),
    m_AntennaLocation( AL ),
    m_ui16AntennaPatternType( APT ),
    m_ui16AntennaPatternLength( 0 ),
    m_ui64Freq( Freq ),
    m_f32TransmitFreqBW( FreqBW ),
    m_f32Power( Power ),
    m_ModulationType( MT ),
    m_CryptoSystem( CS ),
    m_ui8LengthOfModulationParam( 0 ),
    m_ui16Padding2( 0 ),
    m_ui8Padding3( 0 )
{
    m_ui8PDUType = Transmitter_PDU_Type;
    m_ui16PDULength = TRANSMITTER_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Transmitter_PDU::~Transmitter_PDU()
{
    m_vModulationParams.clear();
    m_vAntennaPattern.clear();
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetRadioEntityType( const RadioEntityType & Type )
{
    m_RadioEntityType = Type;
}

//////////////////////////////////////////////////////////////////////////

const RadioEntityType & Transmitter_PDU::GetRadioEntityType() const
{
    return m_RadioEntityType;
}

//////////////////////////////////////////////////////////////////////////

RadioEntityType & Transmitter_PDU::GetRadioEntityType()
{
    return m_RadioEntityType;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetTransmitState( TransmitState TS )
{
    m_ui8TransmitterState = TS;
}

//////////////////////////////////////////////////////////////////////////

TransmitState Transmitter_PDU::GetTransmitState() const
{
    return ( TransmitState )m_ui8TransmitterState;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetInputSource( RadioInputSource IS )
{
    m_ui8InputSource = IS;
}

//////////////////////////////////////////////////////////////////////////

RadioInputSource Transmitter_PDU::GetInputSource() const
{
    return ( RadioInputSource )m_ui8InputSource;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetAntennaLocation( const AntennaLocation & AL )
{
    m_AntennaLocation = AL;
}

//////////////////////////////////////////////////////////////////////////

const AntennaLocation & Transmitter_PDU::GetAntennaLocation() const
{
    return m_AntennaLocation;
}

//////////////////////////////////////////////////////////////////////////

AntennaLocation & Transmitter_PDU::GetAntennaLocation()
{
    return m_AntennaLocation;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetAntennaPatternType( AntennaPatternType APT )
{
    m_ui16AntennaPatternType = APT;
}

//////////////////////////////////////////////////////////////////////////

AntennaPatternType Transmitter_PDU::GetAntennaPatternType() const
{
    return ( AntennaPatternType )m_ui16AntennaPatternType;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Transmitter_PDU::GetAntennaPatternLength() const
{
    return m_ui16AntennaPatternLength;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetFrequency( KUINT64 F )
{
    m_ui64Freq = F;
}

//////////////////////////////////////////////////////////////////////////

KUINT64 Transmitter_PDU::GetFrequency() const
{
    return m_ui64Freq;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetTransmitFrequencyBandWidth( KFLOAT32 TFBW )
{
    m_f32TransmitFreqBW = TFBW;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Transmitter_PDU::GetTransmitFrequencyBandWidth() const
{
    return m_f32TransmitFreqBW;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetPower( KFLOAT32 P )
{
    m_f32Power = P;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Transmitter_PDU::GetPower() const
{
    return m_f32Power;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetModulationType( const ModulationType & MT )
{
    m_ModulationType = MT;
}

//////////////////////////////////////////////////////////////////////////

const ModulationType & Transmitter_PDU::GetModulationType() const
{
    return m_ModulationType;
}

//////////////////////////////////////////////////////////////////////////

ModulationType & Transmitter_PDU::GetModulationType()
{
    return m_ModulationType;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetCryptoSystem( const CryptoSystem & CS )
{
    m_CryptoSystem = CS;
}

//////////////////////////////////////////////////////////////////////////

const CryptoSystem & Transmitter_PDU::GetCryptoSystem() const
{
    return m_CryptoSystem;
}

//////////////////////////////////////////////////////////////////////////

CryptoSystem & Transmitter_PDU::GetCryptoSystem()
{
    return m_CryptoSystem;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Transmitter_PDU::GetLengthOfModulationParameters() const
{
    return m_ui8LengthOfModulationParam;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetModulationParameters( const KOCTET * MP, KUINT8 Length )
{
    // If we already have data clear it first.
    m_ui16PDULength -= m_vModulationParams.size();
    m_vModulationParams.clear();

    // Copy data into the vector
    for( KUINT8 i = 0; i < Length; ++i, ++MP )
    {
        m_vModulationParams.push_back( *MP );
    }

    // Check if we need to add any padding, the length should be a
    // multiple of 8.
    KUINT8 ui8PaddingNeeded = ( Length % 8 == 0 ? 0 : ( 8 - Length % 8 ) );
	
    // Add the padding, if needed.
    for( KUINT8 i = 0; i < ui8PaddingNeeded; ++ i )
    {
        m_vModulationParams.push_back( 0 );
    }

    // Update length
    m_ui8LengthOfModulationParam = m_vModulationParams.size();
    m_ui16PDULength += m_ui8LengthOfModulationParam;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::GetModulationParameters( KOCTET * MP, KUINT8 Length ) const throw( KException )
{
    if( Length < m_ui8LengthOfModulationParam )throw KException( __FUNCTION__, BUFFER_TOO_SMALL );

    vector<KOCTET>::const_iterator citr = m_vModulationParams.begin();
    vector<KOCTET>::const_iterator citrEnd = m_vModulationParams.end();
    for( ; citr != citrEnd; ++citr, ++MP )
    {
        *MP = *citr;
    }
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::SetAntennaPattern( const KOCTET * AP, KUINT16 Length )
{
    // If we already have data clear it first.
    m_ui16PDULength -= m_vAntennaPattern.size();
    m_vAntennaPattern.clear();

    // Copy data into the vector
    for( KUINT16 i = 0; i < Length; ++i, ++AP )
    {
        m_vAntennaPattern.push_back( *AP );
    }

    // Check if we need to add any padding, the length should be a
    // multiple of 8.
    KUINT8 ui8PaddingNeeded = Length % 8;

    // Add the padding, if needed.
    for( KUINT8 i = 0; i < ui8PaddingNeeded; ++ i )
    {
        m_vAntennaPattern.push_back( 0 );
    }

    // Update length
    m_ui16AntennaPatternLength = m_vAntennaPattern.size();
    m_ui16PDULength += m_ui16AntennaPatternLength;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::GetAntennaPattern( KOCTET * AP, KUINT16 Length ) const throw( KException )
{
    if( Length < m_ui16AntennaPatternLength )throw KException( __FUNCTION__, BUFFER_TOO_SMALL );

    vector<KOCTET>::const_iterator citr = m_vAntennaPattern.begin();
    vector<KOCTET>::const_iterator citrEnd = m_vAntennaPattern.end();
    for( ; citr != citrEnd; ++citr, ++AP )
    {
        *AP = *citr;
    }
}

//////////////////////////////////////////////////////////////////////////

KString Transmitter_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Transmitter PDU-\n"
       << Radio_Communications_Header::GetAsString()
       << "Radio Entity Type:          " << m_RadioEntityType.GetAsString()
       << "Transmit State:             " << GetEnumAsStringTransmitState ( m_ui8TransmitterState )<< "\n"
       << "Input Source:               " << GetEnumAsStringRadioInputSource( m_ui8InputSource )   << "\n"
       << m_AntennaLocation.GetAsString()
       << "Antenna Pattern Type:       " << GetEnumAsStringAntennaPatternType( m_ui16AntennaPatternType ) << "\n"
       << "Antenna Pattern Length:     " << m_ui16AntennaPatternLength << "\n"
       << "Frequency(hertz):           " << m_ui64Freq                 << "\n"
       << "Transmit Frequency BW:      " << m_f32TransmitFreqBW        << "\n"
       << "Power(decibel-milliwatts):  " << m_f32Power                 << "\n"
       << m_ModulationType.GetAsString()
       << m_CryptoSystem.GetAsString()
       << "Length Of Modulation Param: " << ( KUINT16 )m_ui8LengthOfModulationParam << "\n"
       << "Variable Params.......NOT IMPLEMENTED\n";

    // TODO: Interpretation of the variable params is not provided at the moment. Karl

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < TRANSMITTER_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

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
           >> m_ui8Padding3;

    for( KUINT8 i = 0; i < m_ui8LengthOfModulationParam; ++i )
    {
        KOCTET o;
        stream >> o;
        m_vModulationParams.push_back( o );
    }

    for( KUINT16 i = 0; i < m_ui16AntennaPatternLength; ++i )
    {
        KOCTET o;
        stream >> o;
        m_vAntennaPattern.push_back( o );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Transmitter_PDU::Encode() const
{
    KDataStream stream;

    Transmitter_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Transmitter_PDU::Encode( KDataStream & stream ) const
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
           << m_ui8Padding3;

    vector<KOCTET>::const_iterator citrModulation = m_vModulationParams.begin();

    for( ; citrModulation != m_vModulationParams.end(); ++citrModulation )
    {
        stream << *citrModulation;
    }

    vector<KOCTET>::const_iterator citrAntenna = m_vAntennaPattern.begin();

    for( ; citrAntenna != m_vAntennaPattern.end(); ++citrAntenna )
    {
        stream << *citrAntenna;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Transmitter_PDU::operator == ( const Transmitter_PDU & Value ) const
{
    if( Radio_Communications_Header::operator   !=( Value ) )                           return false;
    if( m_RadioEntityType                       != Value.m_RadioEntityType )            return false;
    if( m_ui8TransmitterState                   != Value.m_ui8TransmitterState )        return false;
    if( m_ui8InputSource                        != Value.m_ui8InputSource )             return false;
    if( m_AntennaLocation                       != Value.m_AntennaLocation )            return false;
    if( m_ui16AntennaPatternType                != Value.m_ui16AntennaPatternType )     return false;
    if( m_ui16AntennaPatternLength              != Value.m_ui16AntennaPatternLength )   return false;
    if( m_ui64Freq                              != Value.m_ui64Freq )                   return false;
    if( m_f32TransmitFreqBW                     != Value.m_f32TransmitFreqBW )          return false;
    if( m_f32Power                              != Value.m_f32Power )                   return false;
    if( m_ModulationType                        != Value.m_ModulationType )             return false;
    if( m_CryptoSystem                          != Value.m_CryptoSystem )               return false;
    if( m_ui8LengthOfModulationParam            != Value.m_ui8LengthOfModulationParam ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Transmitter_PDU::operator != ( const Transmitter_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
