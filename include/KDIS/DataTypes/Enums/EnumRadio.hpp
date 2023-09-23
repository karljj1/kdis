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
    EnumRadio
    created:    21/08/2008
    author:     Karl Jones

    purpose:    Enums for radio parameters
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Transmit State                                                       */
/* Radio Tranmit State                                                  */
/* Used In:                                                             */
/*  Tranmitter PDU                                                      */
/************************************************************************/

enum TransmitState
{
    Off                                                               = 0,
    OnButNotTransmitting                                              = 1,
    OnAndTransmitting                                                 = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeTransmitState();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorTransmitState( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringTransmitState( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringTransmitState( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Radio Input Source                                                   */
/* Radio in put source, represents the part of the entity that is       */
/* transmitting.                                                        */
/* Used In:                                                             */
/*  Tranmitter PDU                                                      */
/************************************************************************/

enum RadioInputSource
{
    OtherRadioInputSource                                             = 0,
    Pilot                                                             = 1,
    Copilot                                                           = 2,
    FirstOfficer                                                      = 3,
    Driver                                                            = 4,
    Loader                                                            = 5,
    Gunner                                                            = 6,
    Commander                                                         = 7,
    DigitalDataDevice                                                 = 8,
    Intercom                                                          = 9,
    #if DIS_VERSION > 6
    AudioJammer                                                       =10,
    DataJammer                                                        =11,
    GPSJammer                                                         =12,
    GPSMeaconer                                                       =13,
    #endif
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeRadioInputSource();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorRadioInputSource( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringRadioInputSource( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringRadioInputSource( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Antenna Pattern Type                                                 */
/* Type of representation used for radiation pattern from antenna       */
/* transmitting.                                                        */
/* Used In:                                                             */
/*  Tranmitter PDU                                                      */
/************************************************************************/

enum AntennaPatternType
{
    Omni_Directional                                                  = 0,
    Beam                                                              = 1,
    SphericalHarmonic                                                 = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeAntennaPatternType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorAntennaPatternType( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringAntennaPatternType( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringAntennaPatternType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Radio Major Modulation                                               */
/* Major Modulation Field                                               */
/* Used In:                                                             */
/*  Modulation Type                                                     */
/************************************************************************/

enum RadioMajorModulation
{
    NoStatementRadioMajorModulation                                   = 0,
    Amplitude                                                         = 1,
    AmplitudeAndAngle                                                 = 2,
    Angle                                                             = 3,
    Combination                                                       = 4,
    Pulse                                                             = 5,
    Unmodulated                                                       = 6,
    CarrierPhaseShiftModulation_CPSM                                  = 7
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeRadioMajorModulation();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorRadioMajorModulation( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringRadioMajorModulation( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringRadioMajorModulation( const KString & Value, KINT32 & ValueOut );


/************************************************************************/
/* Modulation Detail                                                    */
/* Various Enums dependent on Radio Major Modulation                    */
/* Used In:                                                             */
/*  Modulation Type                                                     */
/************************************************************************/

enum DetailAmplitude
{
    OtherDetailAmplitude                                              = 0,
    AFSK_AudioFrequencyShiftKeying                                    = 1,
    AM_AmplitudeModulation                                            = 2,
    CW_ContinuousWaveModulation                                       = 3,
    DSB_DoubleSideband                                                = 4,
    ISB_IndependentSideband                                           = 5,
    LSB_SingleBandSuppressedCarrier_LowerSidebandMode                 = 6,
    SSB_Full_SingleSidebandFullCarrier                                = 7,
    SSB_Reduc_SingleBandReducedCarrier                                = 8,
    USB_SingleBandSuppressedCarrier_UpperSidebandMode                 = 9,
    VSB_VestigialSideband                                             = 10
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeDetailAmplitude();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorDetailAmplitude( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringDetailAmplitude( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringDetailAmplitude( const KString & Value, KINT32 & ValueOut );

enum DetailAmplitudeAndAngle
{
    OtherDetailAmplitudeAndAngleDetail                                = 0,
    AmplitudeAndAngleDetail                                           = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeDetailAmplitudeAndAngle();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorDetailAmplitudeAndAngle( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringDetailAmplitudeAndAngle( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringDetailAmplitudeAndAngle( const KString & Value, KINT32 & ValueOut );

enum DetailAngle
{
    OtherDetailAngle                                                  = 0,
    FM_FrequencyModulation                                            = 1,
    FSK_FrequencyShiftKeying                                          = 2,
    PM_PhaseModulation                                                = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeDetailAngle();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorDetailAngle( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringDetailAngle( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringDetailAngle( const KString & Value, KINT32 & ValueOut );

enum DetailCombination
{
    OtherDetailCombination                                            = 0,
    AmplitudeAnglePulse                                               = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeDetailCombination();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorDetailCombination( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringDetailCombination( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringDetailCombination( const KString & Value, KINT32 & ValueOut );

enum DetailPulse
{
    OtherPulseDetail                                                  = 0,
    PulseDetail                                                       = 1,
    X_Band_TACAN_PulseDetail                                          = 2,
    Y_Band_TACAN_PulseDetail                                          = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeDetailPulse();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorDetailPulse( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringDetailPulse( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringDetailPulse( const KString & Value, KINT32 & ValueOut );

enum DetailUnmodulated
{
    OtherDetailUnmodulted                                             = 0,
    ContinuousWaveEmissionOfAnUnmodulatedCarrier                      = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeDetailUnmodulated();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorDetailUnmodulated( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringDetailUnmodulated( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringDetailUnmodulated( const KString & Value, KINT32 & ValueOut );

enum DetailCarrierPhaseShift
{
    OtherDetailCarrierPhaseShift                                      = 0
};

enum DetailNoStatement
{
    DetailNoStatementNoStatement                                      = 0
};
// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeDetailCarrierPhaseShift();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorDetailCarrierPhaseShift( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringDetailCarrierPhaseShift( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringDetailCarrierPhaseShift( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Modulation System                                                    */
/* Specifies the interpretation of the modulation parameter field(s)    */
/* Used In:                                                             */
/*  Modulation Type                                                     */
/************************************************************************/

enum ModulationSystem
{
    OtherModulationSystem                                             = 0,
    GenericModulationSystem                                           = 1,
    HQ                                                                = 2,
    HQII                                                              = 3,
    HQIIA                                                             = 4,
    SINCGARS                                                          = 5,
    CCTT_SINCGARS                                                     = 6,
    EPLRS_EnhancedPositionLocationReportingSystem                     = 7,
    JTIDS_MIDS                                                        = 8,
    #if DIS_VERSION > 6
    LINK11                                                            = 9,
    LINK11b                                                           = 10,
    LBAND_SATCOM                                                      = 11,
    ENHANCED_SINCGARS_73                                              = 12,
    NAVIGATION_AID                                                     = 13,
    #endif
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeModulationSystem();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorModulationSystem( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringModulationSystem( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringModulationSystem( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Crypto System Type                                                   */
/* Identifies the crypto equipment used in a tranmission                */
/* Used In:                                                             */
/*  Transmitter PDU                                                     */
/************************************************************************/

enum CryptoSystemType
{
    OtherCryptoSystem                                                 = 0,
    KY_28                                                             = 1,
    VINSON_KY_57_KY_58_SINCGARS_ICOM                                  = 2,
    NarrowSpectrumSecureVoice_NSVE                                    = 3,
    WideSpectrumSecureVoice_WSVE                                      = 4,
    #if DIS_VERSION > 6
    SINCGARS_ICOM                                                     = 5,
    KY_75                                                             = 6,
    KY_100                                                            = 7,
    KY_57                                                             = 8,
    KYV_5                                                             = 9,
    Link11_KG_40A_P_NTDS                                              = 10,
    Link11B_KG_40A_S                                                  = 11,
    Link11_KG_40AR                                                    = 12,
    #endif
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeCryptoSystemType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorCryptoSystemType( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringCryptoSystemType( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringCryptoSystemType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Encryption Mode                                                      */
/* Identifies the mode of encryption                                    */
/* Used In:                                                             */
/*  CryptoSystem                                                        */
/************************************************************************/

enum EncryptionMode
{
    BaseBand                                                          = 0,
    Diphase                                                           = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeEncryptionMode();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorEncryptionMode( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringEncryptionMode( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringEncryptionMode( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Encoding Class                                                       */
/* Encoding class for a signal PDU                                      */
/* Used In:                                                             */
/*  EncodingScheme                                                      */
/************************************************************************/

enum EncodingClass
{
    EncodedAudio                                                      = 0,
    RawBinaryData                                                     = 1,
    ApplicationSpecificData                                           = 2,
    DatabaseIndex                                                     = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeEncodingClass();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorEncodingClass( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringEncodingClass( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringEncodingClass( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Encoding Type                                                        */
/* Encoding type when EncodingClass is audio                            */
/* Used In:                                                             */
/*  EncodingScheme                                                      */
/************************************************************************/

enum EncodingType
{
    _8_bit_mu_law                                                     = 1,
    CVSD_per_MIL_STD_188_113                                          = 2,
    ADPCM_per_CCITT_G_721                                             = 3,
    _16_bit_linear_PCM2sComplementBigEndian                           = 4,
    _8_bit_linear_PCM                                                 = 5,
    VQ_VectorQuantization                                             = 6,
    GSM_FullRate                                                      = 8,
    GSM_HalfRate                                                      = 9,
    SpeexNarrowBand                                                   = 10,
    _16_bit_linear_PCM2sComplementLittleEndian                        = 100

};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeEncodingType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorEncodingType( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringEncodingType( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringEncodingType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* TDL Type                                                             */
/* Tactical Data Link Type                                              */
/* Used In:                                                             */
/*  EncodingScheme                                                      */
/************************************************************************/

enum TDLType
{
    OtherTDLType                                                      = 0,
    PADIL                                                             = 1,
    NATOLink_1                                                        = 2,
    ATDL_1                                                            = 3,
    Link11B_TADILB_                                                   = 4,
    SituationalAwarenessDataLink_SADL_                                = 5,
    Link16LegacyFormat_JTIDS_TADIL_J_                                 = 6,
    Link16LegacyFormat_JTIDS_FDL_TADIL_J_                             = 7,
    Link11A_TADILA_                                                   = 8,
    IJMS                                                              = 9,
    Link4A_TADILC_                                                    = 10,
    Link4C                                                            = 11,
    TIBS                                                              = 12,
    ATL                                                               = 13,
    ConstantSource                                                    = 14,
    AbbreviatedCommandandControl                                      = 15,
    MILSTAR                                                           = 16,
    ATHS                                                              = 17,
    OTHGOLD                                                           = 18,
    TACELINT                                                          = 19,
    WeaponsDataLink_AWW_13_                                           = 20,
    AbbreviatedCommandandControl1                                     = 21,
    EnhancedPositionLocationReportingSystem_EPLRS_                    = 22,
    PositionLocationReportingSystem_PLRS_                             = 23,
    SINCGARS_TDLType                                                  = 24,
    HaveQuickI                                                        = 25,
    HaveQuickII                                                       = 26,
    HaveQuickIIA_Saturn_                                              = 27,
    Intra_FlightDataLink1                                             = 28,
    Intra_FlightDataLink2                                             = 29,
    ImprovedDataModem_IDM_                                            = 30,
    AirForceApplicationProgramDevelopment_AFAPD_                      = 31,
    CooperativeEngagementCapability_CEC_                              = 32,
    ForwardAreaAirDefense_FAAD_DataLink_FDL_                          = 33,
    GroundBasedDataLink_GBDL_                                         = 34,
    IntraVehicularInfoSystem_IVIS_                                    = 35,
    MarineTacticalSystem_MTS_                                         = 36,
    TacticalFireDirectionSystem_TACFIRE_                              = 37,
    IntegratedBroadcastService_IBS_                                   = 38,
    AirborneInformationTransfer_ABIT_                                 = 39,
    AdvancedTacticalAirborneReconnaissanceSystem_ATARS_DataLink       = 40,
    BattleGroupPassiveHorizonExtensionSystem_BGPHES_DataLink          = 41,
    CommonHighBandwidthDataLink_CHBDL_                                = 42,
    GuardrailInteroperableDataLink_IDL_                               = 43,
    GuardrailCommonSensorSystemOne_CSS1_DataLink                      = 44,
    GuardrailCommonSensorSystemTwo_CSS2_DataLink                      = 45,
    GuardrailCSS2Multi_RoleDataLink_MRDL_                             = 46,
    GuardrailCSS2DirectAirtoSatelliteRelay_DASR_DataLink              = 47,
    LineofSight_LOS_DataLinkImplementation_LOStether_                 = 48,
    LightweightCDL_LWCDL_                                             = 49,
    L_52M_SR_71_                                                      = 50,
    RivetReach_RivetOwlDataLink                                       = 51,
    SeniorSpan                                                        = 52,
    SeniorSpur                                                        = 53,
    SeniorStretch_                                                    = 54,
    SeniorYearInteroperableDataLink_IDL_                              = 55,
    SpaceCDL                                                          = 56,
    TR_1modeMISTAirborneDataLink                                      = 57,
    Ku_bandSATCOMDataLinkImplementation_UAV_                          = 58,
    MissionEquipmentControlDatalink_MECDL_                            = 59,
    RadarDataTransmittingSetDataLink                                  = 60,
    SurveillanceandControlDataLink_SCDL_                              = 61,
    TacticalUAVVideo                                                  = 62,
    UHFSATCOMDataLinkImplementation_UAV_                              = 63,
    TacticalCommonDataLink_TCDL_                                      = 64,
    LowLevelAirPictureInterface_LLAPI_                                = 65,
    WeaponsDataLink_AGM_130_                                          = 66,
    #if DIS_VERSION > 6
    Automatic_Identification_System_AIS                               = 67,
    Weapons_Data_Link_AIM_120                                         = 68,
    Weapons_Data_Link_AIM_9                                           = 69,
    #endif
    GC3                                                               = 99,
    Link16StandardizedFormat_JTIDS_MIDS_TADILJ_                       = 100,
    Link16EnhancedDataRate_EDRJTIDS_MIDS_TADIL_J_                     = 101,
    JTIDS_MIDSNetDataLoad_TIMS_TOMS_                                  = 102,
    Link22                                                            = 103,
    AFIWCIADSCommunicationsLinks                                      = 104,
    #if DIS_VERSION > 6
    F22_IntraFlight_Data_Link_IFDL = 105,
    LBand_SATCOM = 106,
    TSAF_Communications_Link = 107,
    Enhanced_SINCGARS_7_3 = 108,
    F35_Multifunction_Advanced_Data_Link_MADL = 109,
    Cursor_on_Target = 110,
    All_Purpose_Structured_Eurocontrol_Surveillance_Information_Exchange_ASTERIX = 111,
    #endif
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeTDLType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorTDLType( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringTDLType( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringTDLType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Control Type                                                         */
/* Type of control requested                                            */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum ControlType
{
    ControlTypeReserved                                               = 0,
    ControlTypeStatus                                                 = 1,
    Request_Acknowledge_Required                                      = 2,
    Request_No_Acknowledge                                            = 3,
    Ack_Request_Granted                                               = 4,
    Nack_Request_Denied                                               = 5
    // 6-255 Reserved
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeControlType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorControlType( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringControlType( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringControlType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Communications Channel Type                                          */
/* Communications Channel Type enumerations                             */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum ChannelType
{
    ChannelTypeReserved                                               = 0,
    Connection_FDX                                                    = 1,
    Connection_HDX_Destination_Receive_Only                           = 2,
    Connection_HDX_Destination_Transmit_Only                          = 3,
    Connection_HDX                                                    = 4
    // 5-255 Reserved
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeChannelType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorChannelType( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringChannelType( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringChannelType( const KString & Value, KINT32 & ValueOut );

enum ChannelClass
{
    Simulated_Comm_Channel                                            = 0,
    Simulation_Support_Comm_Channel                                   = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeChannelClass();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorChannelClass( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringChannelClass( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringChannelClass( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Transmit Line State                                                  */
/* Identifies the current transmit state of the line at the intercon    */
/* source.                                                              */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum TransmitLineState
{
    TransmitLineStateNotApplicable                                    = 0,
    NotTransmitting                                                   = 1,
    Transmitting                                                      = 2
    // 3-255 Reserved
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeTransmitLineState();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorTransmitLineState( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringTransmitLineState( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringTransmitLineState( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Line State Command                                                   */
/* specifies the detailed type requested when the control type is       */
/* request or acknowledge                                               */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum LineStateCommand
{
    NoLineStateCommand                                                = 0,
    SetLineState_Transmitting                                         = 1,
    SetLineState_NotTransmitting                                      = 2,
    ReturnToLocalLineStateControl                                     = 3
    // 4-255        Reserved
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeLineStateCommand();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorLineStateCommand( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringLineStateCommand( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringLineStateCommand( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* AdditionalIntrCommParamType                                          */
/* specifies the type of additonal intercom parameter data included.    */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum AdditionalIntrCommParamType
{
    EntityDestinationRecord_Type                                      = 1,
    GroupDestinationRecord_Type                                       = 2,
    GroupAssignmentRecord_Type                                        = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeAdditionalIntrCommParamType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorAdditionalIntrCommParamType( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringAdditionalIntrCommParamType( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringAdditionalIntrCommParamType( const KString & Value, KINT32 & ValueOut );

#if DIS_VERSION > 6
/************************************************************************/
/* AttachedIndicator                                                    */
/* Used to indicate whether the object is attached to an entity or      */
/* object.                                                              */
/* Used In:                                                             */
/*  PDU Header 7                                                        */
/************************************************************************/

enum AttachedIndicator
{
    NoStatementAttachedIndicator                                      = 0,
    UnattachedAttachedIndicator                                       = 1,
    AttachedAttachedIndicator                                         = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KDIS_EXPORT KUINT32 GetEnumSizeAttachedIndicator();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor * GetEnumDescriptorAttachedIndicator( KUINT32 Index );

KDIS_EXPORT KString GetEnumAsStringAttachedIndicator( KINT32 Value );

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringAttachedIndicator( const KString & Value, KINT32 & ValueOut );

#endif

enum BeamAntennaPatternReferenceSystem
{
    ReferenceSystemWorldCoordinates                                   = 1,
    ReferenceSystemEntityCoordinates                                  = 2
};

KUINT32 GetEnumSizeBeamAntennaPatternReferenceSystem();

const EnumDescriptor * GetEnumDescriptorBeamAntennaPatternReferenceSystem( KUINT32 Index);

KString GetEnumAsStringBeamAntennaPatternReferenceSystem(KINT32 Value);

KBOOL GetEnumFromStringBeamAntennaPatternReferenceSystem( const KString& Value, KINT32 & ValueOut );


} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
