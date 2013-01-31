/*********************************************************************
Copyright 2013 KDIS
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
    class:      Transmitter_PDU
    DIS:        (5) 1278.1 - 1995
    created:    21/10/2008
    author:     Karl Jones

    purpose:    Used to communicate the state of a particular radio 
				transmitter or simple intercom.

    size:       832 bits / 104 octets - min size
*********************************************************************/

#pragma once

#include "./Radio_Communications_Header.h"
#include "./../../DataTypes/RadioEntityType.h"
#include "./../../DataTypes/AntennaLocation.h"
#include "./../../DataTypes/ModulationType.h"
#include "./../../DataTypes/CryptoSystem.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::RadioEntityType;
using KDIS::DATA_TYPE::AntennaLocation;
using KDIS::DATA_TYPE::ModulationType;
using KDIS::DATA_TYPE::CryptoSystem;
using KDIS::DATA_TYPE::ENUMS::TransmitState;
using KDIS::DATA_TYPE::ENUMS::RadioInputSource;
using KDIS::DATA_TYPE::ENUMS::AntennaPatternType;
using std::vector;

class KDIS_EXPORT Transmitter_PDU : public Radio_Communications_Header
{
protected:

    RadioEntityType m_RadioEntityType;

    KUINT8 m_ui8TransmitterState;

    KUINT8 m_ui8InputSource;

    KUINT16 m_ui16Padding1;

    AntennaLocation m_AntennaLocation;

    KUINT16 m_ui16AntennaPatternType;

    KUINT16 m_ui16AntennaPatternLength;

    KUINT64 m_ui64Freq;

    KFLOAT32 m_f32TransmitFreqBW;

    KFLOAT32 m_f32Power;

    ModulationType m_ModulationType;

    CryptoSystem m_CryptoSystem;

    KUINT8 m_ui8LengthOfModulationParam;

    KUINT16 m_ui16Padding2;

    KUINT8 m_ui8Padding3;

    vector<KOCTET> m_vModulationParams;

    vector<KOCTET> m_vAntennaPattern;

public:

    static const KUINT16 TRANSMITTER_PDU_SIZE = 104; // Min Size

    Transmitter_PDU( void );

    Transmitter_PDU( KDataStream & stream ) throw( KException );

    Transmitter_PDU( const RadioEntityType & Type, TransmitState TS, RadioInputSource IS,
                     const AntennaLocation & AL, AntennaPatternType APT, KUINT64 Freq,
                     KFLOAT32 FreqBW, KFLOAT32 Power, const ModulationType & MT,
                     const CryptoSystem & CS, const KOCTET * ModulationParams,
                     KUINT8 ModulationParamsLength, const KOCTET * AntennaPattern,
                     KUINT8 AntennaPatternLength );

    virtual ~Transmitter_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetRadioEntityType
    //              KDIS::PDU::Transmitter_PDU::GetRadioEntityType
    // Description: Radio Entity Type
    // Parameter:   const RadioEntityType & Type, void
    //************************************
    void SetRadioEntityType( const RadioEntityType & Type );
    const RadioEntityType & GetRadioEntityType() const;
    RadioEntityType & GetRadioEntityType();

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetTransmitState
    //              KDIS::PDU::Transmitter_PDU::GetTransmitState
    // Description: Radio Transmit State, on or off.
    // Parameter:   TransmitState TS, void
    //************************************
    void SetTransmitState( TransmitState TS );
    TransmitState GetTransmitState() const;

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetInputSource
    //              KDIS::PDU::Transmitter_PDU::GetInputSource
    // Description: Source of the radio in relation to the entity.
    // Parameter:   RadioInputSource IS, void
    //************************************
    void SetInputSource( RadioInputSource IS );
    RadioInputSource GetInputSource() const;

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetAntennaLocation
    //              KDIS::PDU::Transmitter_PDU::GetAntennaLocation
    // Description: Location of the Antenna in world coordinates
    //              and entity coordinates.
    // Parameter:   const AntennaLocation AL, void
    //************************************
    void SetAntennaLocation( const AntennaLocation & AL );
    const AntennaLocation & GetAntennaLocation() const;
    AntennaLocation & GetAntennaLocation();

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetAntennaPatternType
    //              KDIS::PDU::Transmitter_PDU::GetAntennaPatternType
    // Description: Type of representation used for radiation pattern
    //              from antenna.
    // Parameter:   AntennaPatternType APT, void
    //************************************
    void SetAntennaPatternType( AntennaPatternType APT );
    AntennaPatternType GetAntennaPatternType() const;

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::GetAntennaPatternLength
    // Description: Length of Antenna pattern parameters in
    //              octets. Antenna Parameters must end on a 64 bit
    //              boundary, so this value will be a multiple of 8.
    //************************************
    KUINT16 GetAntennaPatternLength() const;

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetFrequency
    //              KDIS::PDU::Transmitter_PDU::GetFrequency
    // Description: Center frequency of radio transmission in hertz.
    // Parameter:   KUINT64 F, void
    //************************************
    void SetFrequency( KUINT64 F );
    KUINT64 GetFrequency() const;

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetTransmitFrequencyBandWidth
    //              KDIS::PDU::Transmitter_PDU::GetTransmitFrequencyBandWidth
    // Description: Band Width
    // Parameter:   KFLOAT32 TFBW, void
    //************************************
    void SetTransmitFrequencyBandWidth( KFLOAT32 TFBW );
    KFLOAT32 GetTransmitFrequencyBandWidth() const;

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetPower
    //              KDIS::PDU::Transmitter_PDU::GetPower
    // Description: Power in decibel-milliwatts
    // Parameter:   KFLOAT32 P, void
    //************************************
    void SetPower( KFLOAT32 P );
    KFLOAT32 GetPower() const;

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetModulationType
    //              KDIS::PDU::Transmitter_PDU::GetModulationType
    // Description: Modulation Type
    // Parameter:   const ModulationType & MT, void
    //************************************
    void SetModulationType( const ModulationType & MT );
    const ModulationType & GetModulationType() const;
    ModulationType & GetModulationType();

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetCryptoSystem
    //              KDIS::PDU::Transmitter_PDU::GetCryptoSystem
    // Description: Identifies the crypto equipment and key
    //              used in a transmission .
    // Parameter:   const CryptoSystem & CS, void
    //************************************
    void SetCryptoSystem( const CryptoSystem & CS );
    const CryptoSystem & GetCryptoSystem() const;
    CryptoSystem & GetCryptoSystem();

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::GetLengthOfModulationParameters
    // Description: Returns length in octets of the modulation parameters
    //              field. modulation parameters must end on a
    //              64 bit parameter so this value will be a
    //              multiple of 8.
    //************************************
    KUINT8 GetLengthOfModulationParameters() const;

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetModulationParameters
    //              KDIS::PDU::Transmitter_PDU::GetModulationParameters
    // Description: Modulation parameter are interpreted in various ways so
    //              a buffer is taken/returned. set function will add
    //              padding if the size is not a multiple of 8.
    //              copy data over.
    // Parameter:   KOCTET * MP - buffer for writing/reading
    // Parameter:   KUINT8 Length - size of buffer.
    //************************************
    void SetModulationParameters( const KOCTET * MP, KUINT8 Length );
    void GetModulationParameters( KOCTET * MP, KUINT8 Length ) const throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::SetAntennaPattern
    //              KDIS::PDU::Transmitter_PDU::GetAntennaPattern
    // Description: For omni-direction this field is 0, for the other 2
    //              types the size varies. set function will add
    //              padding if the size is not a multiple of 8.
    //              copy data over.
    // Parameter:   KOCTET * MP - buffer for writing/reading
    // Parameter:   KUINT8 Length - size of buffer.
    //************************************
    void SetAntennaPattern( const KOCTET * AP, KUINT8 Length );
    void GetAntennaPattern( KOCTET * AP, KUINT8 Length ) const throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Transmitter_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Transmitter_PDU & Value ) const;
    KBOOL operator != ( const Transmitter_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS

