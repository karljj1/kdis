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

#include "./EnumRadio.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for TransmitState

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TransmitStateDescriptor[] =
{
    { 0 , "Off" },
    { 1 , "OnButNotTransmitting" },
    { 2 , "OnAndTransmitting" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTransmitState()
{
	return sizeof( TransmitStateDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTransmitState( KUINT32 Index )
{
	return &TransmitStateDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTransmitState( KINT32 Value )
{
    return GetEnumAsString( TransmitStateDescriptor, sizeof( TransmitStateDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTransmitState( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TransmitStateDescriptor, sizeof( TransmitStateDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTransmitState()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTransmitState( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTransmitState( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTransmitState( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for RadioInputSource

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor RadioInputSourceDescriptor[] =
{
    { 0 , "OtherRadioInputSource" },
    { 1 , "Pilot" },
    { 2 , "Copilot" },
    { 3 , "FirstOfficer" },
    { 4 , "Driver" },
    { 5 , "Loader" },
    { 6 , "Gunner" },
    { 7 , "Commander" },
    { 8 , "DigitalDataDevice" },
    { 9 , "Intercom" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRadioInputSource()
{
	return sizeof( RadioInputSourceDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRadioInputSource( KUINT32 Index )
{
	return &RadioInputSourceDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRadioInputSource( KINT32 Value )
{
    return GetEnumAsString( RadioInputSourceDescriptor, sizeof( RadioInputSourceDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRadioInputSource( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( RadioInputSourceDescriptor, sizeof( RadioInputSourceDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRadioInputSource()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRadioInputSource( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRadioInputSource( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRadioInputSource( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AntennaPatternType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AntennaPatternTypeDescriptor[] =
{
    { 0 , "Omni_Directional" },
    { 1 , "Beam" },
    { 2 , "SphericalHarmonic" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAntennaPatternType()
{
	return sizeof( AntennaPatternTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAntennaPatternType( KUINT32 Index )
{
	return &AntennaPatternTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAntennaPatternType( KINT32 Value )
{
    return GetEnumAsString( AntennaPatternTypeDescriptor, sizeof( AntennaPatternTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAntennaPatternType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AntennaPatternTypeDescriptor, sizeof( AntennaPatternTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAntennaPatternType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAntennaPatternType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAntennaPatternType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAntennaPatternType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for RadioMajorModulation

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor RadioMajorModulationDescriptor[] =
{
    { 0 , "OtherRadioMajorModulation" },
    { 1 , "Amplitude" },
    { 2 , "AmplitudeAndAngle" },
    { 3 , "Angle" },
    { 4 , "Combination" },
    { 5 , "Pulse" },
    { 6 , "Unmodulated" },
    { 7 , "CarrierPhaseShiftModulation_CPSM" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRadioMajorModulation()
{
	return sizeof( RadioMajorModulationDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRadioMajorModulation( KUINT32 Index )
{
	return &RadioMajorModulationDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRadioMajorModulation( KINT32 Value )
{
    return GetEnumAsString( RadioMajorModulationDescriptor, sizeof( RadioMajorModulationDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRadioMajorModulation( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( RadioMajorModulationDescriptor, sizeof( RadioMajorModulationDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRadioMajorModulation()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRadioMajorModulation( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRadioMajorModulation( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRadioMajorModulation( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DetailAmplitude

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetailAmplitudeDescriptor[] =
{
    { 0, "OtherDetailAmplitude" },
    { 1, "AFSK_AudioFrequencyShiftKeying" },
    { 2, "AM_AmplitudeModulation" },
    { 3, "CW_ContinuousWaveModulation" },
    { 4, "DSB_DoubleSideband" },
    { 5, "ISB_IndependentSideband" },
    { 6, "LSB_SingleBandSuppressedCarrier_LowerSidebandMode" },
    { 7, "SSB_Full_SingleSidebandFullCarrier" },
    { 8, "SSB_Reduc_SingleBandReducedCarrier" },
    { 9, "USB_SingleBandSuppressedCarrier_UpperSidebandMode" },
    { 10, "VSB_VestigialSideband" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailAmplitude()
{
	return sizeof( DetailAmplitudeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailAmplitude( KUINT32 Index )
{
	return &DetailAmplitudeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailAmplitude( KINT32 Value )
{
    return GetEnumAsString( DetailAmplitudeDescriptor, sizeof( DetailAmplitudeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailAmplitude( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetailAmplitudeDescriptor, sizeof( DetailAmplitudeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailAmplitude()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailAmplitude( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailAmplitude( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailAmplitude( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DetailAmplitudeAndAngle

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetailAmplitudeAndAngleDescriptor[] =
{
    { 0 , "OtherDetailAmplitudeAndAngleDetail" },
    { 1 , "AmplitudeAndAngleDetail" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailAmplitudeAndAngle()
{
	return sizeof( DetailAmplitudeAndAngleDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailAmplitudeAndAngle( KUINT32 Index )
{
	return &DetailAmplitudeAndAngleDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailAmplitudeAndAngle( KINT32 Value )
{
    return GetEnumAsString( DetailAmplitudeAndAngleDescriptor, sizeof( DetailAmplitudeAndAngleDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailAmplitudeAndAngle( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetailAmplitudeAndAngleDescriptor, sizeof( DetailAmplitudeAndAngleDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailAmplitudeAndAngle()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailAmplitudeAndAngle( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailAmplitudeAndAngle( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailAmplitudeAndAngle( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DetailAngle

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetailAngleDescriptor[] =
{
    { 0 , "OtherDetailAngle" },
    { 1 , "FM_FrequencyModulation" },
    { 2 , "FSK_FrequencyShiftKeying" },
    { 3 , "PM_PhaseModulation" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailAngle()
{
	return sizeof( DetailAngleDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailAngle( KUINT32 Index )
{
	return &DetailAngleDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailAngle( KINT32 Value )
{
    return GetEnumAsString( DetailAngleDescriptor, sizeof( DetailAngleDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailAngle( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetailAngleDescriptor, sizeof( DetailAngleDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailAngle()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailAngle( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailAngle( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailAngle( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DetailCombination

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetailCombinationDescriptor[] =
{
    { 0 , "OtherDetailCombination" },
    { 1 , "AmplitudeAnglePulse" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailCombination()
{
	return sizeof( DetailCombinationDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailCombination( KUINT32 Index )
{
	return &DetailCombinationDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailCombination( KINT32 Value )
{
    return GetEnumAsString( DetailCombinationDescriptor, sizeof( DetailCombinationDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailCombination( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetailCombinationDescriptor, sizeof( DetailCombinationDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailCombination()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailCombination( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailCombination( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailCombination( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DetailPulse

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetailPulseDescriptor[] =
{
    { 0 , "OtherPulseDetail" },
    { 1 , "PulseDetail" },
    { 2 , "X_Band_TACAN_PulseDetail" },
    { 3 , "Y_Band_TACAN_PulseDetail" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailPulse()
{
	return sizeof( DetailPulseDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailPulse( KUINT32 Index )
{
	return &DetailPulseDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailPulse( KINT32 Value )
{
    return GetEnumAsString( DetailPulseDescriptor, sizeof( DetailPulseDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailPulse( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetailPulseDescriptor, sizeof( DetailPulseDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailPulse()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailPulse( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailPulse( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailPulse( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DetailUnmodulated

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetailUnmodulatedDescriptor[] =
{
    { 0 , "OtherDetailUnmodulted" },
    { 1 , "ContinuousWaveEmissionOfAnUnmodulatedCarrier" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailUnmodulated()
{
	return sizeof( DetailUnmodulatedDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailUnmodulated( KUINT32 Index )
{
	return &DetailUnmodulatedDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailUnmodulated( KINT32 Value )
{
    return GetEnumAsString( DetailUnmodulatedDescriptor, sizeof( DetailUnmodulatedDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailUnmodulated( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetailUnmodulatedDescriptor, sizeof( DetailUnmodulatedDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailUnmodulated()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailUnmodulated( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailUnmodulated( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailUnmodulated( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DetailCarrierPhaseShift

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetailCarrierPhaseShiftDescriptor[] =
{
    { 0 , "OtherDetailCarrierPhaseShift" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailCarrierPhaseShift()
{
	return sizeof( DetailCarrierPhaseShiftDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailCarrierPhaseShift( KUINT32 Index )
{
	return &DetailCarrierPhaseShiftDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailCarrierPhaseShift( KINT32 Value )
{
    return GetEnumAsString( DetailCarrierPhaseShiftDescriptor, sizeof( DetailCarrierPhaseShiftDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailCarrierPhaseShift( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetailCarrierPhaseShiftDescriptor, sizeof( DetailCarrierPhaseShiftDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetailCarrierPhaseShift()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetailCarrierPhaseShift( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetailCarrierPhaseShift( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetailCarrierPhaseShift( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ModulationSystem

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ModulationSystemDescriptor[] =
{
    { 0 , "OtherModulationSystem" },
    { 1 , "GenericModulationSystem" },
    { 2 , "HQ" },
    { 3 , "HQII" },
    { 4 , "HQIIA" },
    { 5 , "SINCGARS" },
    { 6 , "CCTT_SINCGARS" },
    { 7 , "EPLRS_EnhancedPositionLocationReportingSystem" },
    { 8 , "JTIDS_MIDS" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeModulationSystem()
{
	return sizeof( ModulationSystemDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorModulationSystem( KUINT32 Index )
{
	return &ModulationSystemDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringModulationSystem( KINT32 Value )
{
    return GetEnumAsString( ModulationSystemDescriptor, sizeof( ModulationSystemDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringModulationSystem( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ModulationSystemDescriptor, sizeof( ModulationSystemDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeModulationSystem()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorModulationSystem( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringModulationSystem( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringModulationSystem( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for CryptoSystemType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor CryptoSystemTypeDescriptor[] =
{
    { 0 , "OtherCryptoSystem" },
    { 1 , "KY_28" },
    { 2 , "VINSON_KY_57_KY_58_SINCGARS_ICOM" },
    { 3 , "NarrowSpectrumSecureVoice_NSVE" },
    { 4 , "WideSpectrumSecureVoice_WSVE" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeCryptoSystemType()
{
	return sizeof( CryptoSystemTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorCryptoSystemType( KUINT32 Index )
{
	return &CryptoSystemTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCryptoSystemType( KINT32 Value )
{
    return GetEnumAsString( CryptoSystemTypeDescriptor, sizeof( CryptoSystemTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCryptoSystemType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( CryptoSystemTypeDescriptor, sizeof( CryptoSystemTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeCryptoSystemType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorCryptoSystemType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCryptoSystemType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCryptoSystemType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EncryptionMode

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EncryptionModeDescriptor[] =
{
    { 0 , "BaseBand" },
    { 1 , "Diphase" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEncryptionMode()
{
	return sizeof( EncryptionModeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEncryptionMode( KUINT32 Index )
{
	return &EncryptionModeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEncryptionMode( KINT32 Value )
{
    return GetEnumAsString( EncryptionModeDescriptor, sizeof( EncryptionModeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEncryptionMode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EncryptionModeDescriptor, sizeof( EncryptionModeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEncryptionMode()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEncryptionMode( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEncryptionMode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEncryptionMode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EncodingClass

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EncodingClassDescriptor[] =
{
    { 0 , "EncodedAudio" },
    { 1 , "RawBinaryData" },
    { 2 , "ApplicationSpecificData" },
    { 3 , "DatabaseIndex" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEncodingClass()
{
	return sizeof( EncodingClassDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEncodingClass( KUINT32 Index )
{
	return &EncodingClassDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEncodingClass( KINT32 Value )
{
    return GetEnumAsString( EncodingClassDescriptor, sizeof( EncodingClassDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEncodingClass( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EncodingClassDescriptor, sizeof( EncodingClassDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEncodingClass()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEncodingClass( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEncodingClass( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEncodingClass( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EncodingType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EncodingTypeDescriptor[] =
{
    { 1 , "_8_bit_mu_law" },
    { 2 , "CVSD_per_MIL_STD_188_113" },
    { 3 , "ADPCM_per_CCITT_G_721" },
    { 4 , "_16_bit_linear_PCM" },
    { 5 , "_8_bit_linear_PCM" },
    { 6 , "VQ_VectorQuantization" },
	{ 8 , "GSM_FullRate" },
    { 9 , "GSM_HalfRate" },
    { 10 , "SpeexNarrowBand" },
    { 100 , "_16_bit_linear_PCM2sComplementLittleEndian" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEncodingType()
{
	return sizeof( EncodingTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEncodingType( KUINT32 Index )
{
	return &EncodingTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEncodingType( KINT32 Value )
{
    return GetEnumAsString( EncodingTypeDescriptor, sizeof( EncodingTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEncodingType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EncodingTypeDescriptor, sizeof( EncodingTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEncodingType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEncodingType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEncodingType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEncodingType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for TDLType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TDLTypeDescriptor[] =
{
    { 0 , "OtherTDLType" },
    { 1 , "PADIL" },
    { 2 , "NATOLink_1" },
    { 3 , "ATDL_1" },
    { 4 , "Link11B_TADILB_" },
    { 5 , "SituationalAwarenessDataLink_SADL_" },
    { 6 , "Link16LegacyFormat_JTIDS_TADIL_J_" },
    { 7 , "Link16LegacyFormat_JTIDS_FDL_TADIL_J_" },
    { 8 , "Link11A_TADILA_" },
    { 9 , "IJMS" },
    { 10 , "Link4A_TADILC_" },
    { 11 , "Link4C" },
    { 12 , "TIBS" },
    { 13 , "ATL" },
    { 14 , "ConstantSource" },
    { 15 , "AbbreviatedCommandandControl" },
    { 16 , "MILSTAR" },
    { 17 , "ATHS" },
    { 18 , "OTHGOLD" },
    { 19 , "TACELINT" },
    { 20 , "WeaponsDataLink_AWW_13_" },
    { 21 , "AbbreviatedCommandandControl1" },
    { 22 , "EnhancedPositionLocationReportingSystem_EPLRS_" },
    { 23 , "PositionLocationReportingSystem_PLRS_" },
    { 24 , "SINCGARS_TDLType" },
    { 25 , "HaveQuickI" },
    { 26 , "HaveQuickII" },
    { 27 , "HaveQuickIIA_Saturn_" },
    { 28 , "Intra_FlightDataLink1" },
    { 29 , "Intra_FlightDataLink2" },
    { 30 , "ImprovedDataModem_IDM_" },
    { 31 , "AirForceApplicationProgramDevelopment_AFAPD_" },
    { 32 , "CooperativeEngagementCapability_CEC_" },
    { 33 , "ForwardAreaAirDefense_FAAD_DataLink_FDL_" },
    { 34 , "GroundBasedDataLink_GBDL_" },
    { 35 , "IntraVehicularInfoSystem_IVIS_" },
    { 36 , "MarineTacticalSystem_MTS_" },
    { 37 , "TacticalFireDirectionSystem_TACFIRE_" },
    { 38 , "IntegratedBroadcastService_IBS_" },
    { 39 , "AirborneInformationTransfer_ABIT_" },
    { 40 , "AdvancedTacticalAirborneReconnaissanceSystem_ATARS_DataLink" },
    { 41 , "BattleGroupPassiveHorizonExtensionSystem_BGPHES_DataLink" },
    { 42 , "CommonHighBandwidthDataLink_CHBDL_" },
    { 43 , "GuardrailInteroperableDataLink_IDL_" },
    { 44 , "GuardrailCommonSensorSystemOne_CSS1_DataLink" },
    { 45 , "GuardrailCommonSensorSystemTwo_CSS2_DataLink" },
    { 46 , "GuardrailCSS2Multi_RoleDataLink_MRDL_" },
    { 47 , "GuardrailCSS2DirectAirtoSatelliteRelay_DASR_DataLink" },
    { 48 , "LineofSight_LOS_DataLinkImplementation_LOStether_" },
    { 49 , "LightweightCDL_LWCDL_" },
    { 50 , "L_52M_SR_71_" },
    { 51 , "RivetReach_RivetOwlDataLink" },
    { 52 , "SeniorSpan" },
    { 53 , "SeniorSpur" },
    { 54 , "SeniorStretch_" },
    { 55 , "SeniorYearInteroperableDataLink_IDL_" },
    { 56 , "SpaceCDL" },
    { 57 , "TR_1modeMISTAirborneDataLink" },
    { 58 , "Ku_bandSATCOMDataLinkImplementation_UAV_" },
    { 59 , "MissionEquipmentControlDatalink_MECDL_" },
    { 60 , "RadarDataTransmittingSetDataLink" },
    { 61 , "SurveillanceandControlDataLink_SCDL_" },
    { 62 , "TacticalUAVVideo" },
    { 63 , "UHFSATCOMDataLinkImplementation_UAV_" },
    { 64 , "TacticalCommonDataLink_TCDL_" },
    { 65 , "LowLevelAirPictureInterface_LLAPI_" },
    { 66 , "WeaponsDataLink_AGM_130_" },
    { 99 , "GC3" },
    { 100 , "Link16StandardizedFormat_JTIDS_MIDS_TADILJ_" },
    { 101 , "Link16EnhancedDataRate_EDRJTIDS_MIDS_TADIL_J_" },
    { 102 , "JTIDS_MIDSNetDataLoad_TIMS_TOMS_" },
    { 103 , "Link22" },
    { 104 , "AFIWCIADSCommunicationsLinks" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTDLType()
{
	return sizeof( TDLTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTDLType( KUINT32 Index )
{
	return &TDLTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTDLType( KINT32 Value )
{
    return GetEnumAsString( TDLTypeDescriptor, sizeof( TDLTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTDLType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TDLTypeDescriptor, sizeof( TDLTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTDLType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTDLType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTDLType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTDLType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ControlType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ControlTypeDescriptor[] =
{
    { 0 , "ControlTypeReserved" },
    { 1 , "ControlTypeStatus" },
    { 2 , "Request_Acknowledge_Required" },
    { 3 , "Request_No_Acknowledge" },
    { 4 , "Ack_Request_Granted" },
    { 5 , "Nack_Request_Denied" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeControlType()
{
	return sizeof( ControlTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorControlType( KUINT32 Index )
{
	return &ControlTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringControlType( KINT32 Value )
{
    return GetEnumAsString( ControlTypeDescriptor, sizeof( ControlTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringControlType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ControlTypeDescriptor, sizeof( ControlTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeControlType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorControlType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringControlType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringControlType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ChannelType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ChannelTypeDescriptor[] =
{
    { 0 , "ChannelTypeReserved" },
    { 1 , "Connection_FDX" },
    { 2 , "Connection_HDX_Destination_Receive_Only" },
    { 3 , "Connection_HDX_Destination_Transmit_Only" },
    { 4 , "Connection_HDX" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeChannelType()
{
	return sizeof( ChannelTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorChannelType( KUINT32 Index )
{
	return &ChannelTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringChannelType( KINT32 Value )
{
    return GetEnumAsString( ChannelTypeDescriptor, sizeof( ChannelTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringChannelType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ChannelTypeDescriptor, sizeof( ChannelTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeChannelType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorChannelType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringChannelType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringChannelType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ChannelClass

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ChannelClassDescriptor[] =
{
    { 0 , "Simulated_Comm_Channel" },
    { 1 , "Simulation_Support_Comm_Channel" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeChannelClass()
{
	return sizeof( ChannelClassDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorChannelClass( KUINT32 Index )
{
	return &ChannelClassDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringChannelClass( KINT32 Value )
{
    return GetEnumAsString( ChannelClassDescriptor, sizeof( ChannelClassDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringChannelClass( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ChannelClassDescriptor, sizeof( ChannelClassDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeChannelClass()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorChannelClass( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringChannelClass( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringChannelClass( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for TransmitLineState

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TransmitLineStateDescriptor[] =
{
    { 0 , "TransmitLineStateNotApplicable" },
    { 1 , "NotTransmitting" },
    { 2 , "Transmitting" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTransmitLineState()
{
	return sizeof( TransmitLineStateDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTransmitLineState( KUINT32 Index )
{
	return &TransmitLineStateDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTransmitLineState( KINT32 Value )
{
    return GetEnumAsString( TransmitLineStateDescriptor, sizeof( TransmitLineStateDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTransmitLineState( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TransmitLineStateDescriptor, sizeof( TransmitLineStateDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTransmitLineState()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTransmitLineState( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTransmitLineState( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTransmitLineState( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for LineStateCommand

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor LineStateCommandDescriptor[] =
{
    { 0 , "NoLineStateCommand" },
    { 1 , "SetLineState_Transmitting" },
    { 2 , "SetLineState_NotTransmitting" },
    { 3 , "ReturnToLocalLineStateControl" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeLineStateCommand()
{
	return sizeof( LineStateCommandDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorLineStateCommand( KUINT32 Index )
{
	return &LineStateCommandDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringLineStateCommand( KINT32 Value )
{
    return GetEnumAsString( LineStateCommandDescriptor, sizeof( LineStateCommandDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringLineStateCommand( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( LineStateCommandDescriptor, sizeof( LineStateCommandDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeLineStateCommand()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorLineStateCommand( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringLineStateCommand( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringLineStateCommand( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AdditionalIntrCommParamType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AdditionalIntrCommParamTypeDescriptor[] =
{
    { 1 , "EntityDestinationRecord_Type" },
    { 2 , "GroupDestinationRecord_Type" },
    { 3 , "GroupAssignmentRecord_Type" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAdditionalIntrCommParamType()
{
	return sizeof( AdditionalIntrCommParamTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAdditionalIntrCommParamType( KUINT32 Index )
{
	return &AdditionalIntrCommParamTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAdditionalIntrCommParamType( KINT32 Value )
{
    return GetEnumAsString( AdditionalIntrCommParamTypeDescriptor, sizeof( AdditionalIntrCommParamTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAdditionalIntrCommParamType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AdditionalIntrCommParamTypeDescriptor, sizeof( AdditionalIntrCommParamTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAdditionalIntrCommParamType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAdditionalIntrCommParamType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAdditionalIntrCommParamType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAdditionalIntrCommParamType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

#if DIS_VERSION > 6
//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AttachedIndicator

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AttachedIndicatorDescriptor[] =
{
    { 0 , "NoStatementAttachedIndicator" },
    { 1 , "UnattachedAttachedIndicator" },
    { 2 , "AttachedAttachedIndicator" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAttachedIndicator()
{
	return sizeof( AttachedIndicatorDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAttachedIndicator( KUINT32 Index )
{
	return &AttachedIndicatorDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAttachedIndicator( KINT32 Value )
{
    return GetEnumAsString( AttachedIndicatorDescriptor, sizeof( AttachedIndicatorDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAttachedIndicator( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AttachedIndicatorDescriptor, sizeof( AttachedIndicatorDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAttachedIndicator()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAttachedIndicator( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAttachedIndicator( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAttachedIndicator( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif // DIS 7

#endif


