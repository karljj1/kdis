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
    Burst Descriptor Params
    created:    17/09/2009
    author:     Karl Jones

    purpose:    Enums used for Descriptor params.
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Warhead Type                                                         */
/* Warhead Type Enums                                                   */
/* Used In:                                                             */
/*  Burst Descriptor                                                    */
/************************************************************************/

enum WarheadType
{
    OtherWarhead                                                      = 0,
    Cargo_VariableSubmunitions_Warhead                                = 10,
    Fuel_AirExplosiveWarhead                                          = 20,
    GlassBeadsWarhead                                                 = 30,
    _1umWarhead                                                       = 31,
    _5umWarhead                                                       = 32,
    _10umWarhead                                                      = 33,
    HighExplosive_HE_Warhead                                          = 1000,
    HE_PlasticWarhead                                                 = 1100,
    HE_IncendiaryWarhead                                              = 1200,
    HE_FragmentationWarhead                                           = 1300,
    HE_AntitankWarhead                                                = 1400,
    HE_BombletsWarhead                                                = 1500,
    HE_ShapedChargeWarhead                                            = 1600,
    HE_ContinuousRodWarhead                                           = 1610,
    HE_TungstenBallWarhead                                            = 1615,
    HE_BlastFragmentationWarhead                                      = 1620,
    HE_SteerableDartswithHEWarhead                                    = 1625,
    HE_DartsWarhead                                                   = 1630,
    HE_FlechettesWarhead                                              = 1635,
    HE_DirectedFragmentationWarhead                                   = 1640,
    HE_Semi_ArmorPiercing_SAP_Warhead                                 = 1645,
    HE_ShapedChargeFragmentationWarhead                               = 1650,
    HE_Semi_ArmorPiercing_FragmentationWarhead                        = 1655,
    HE_HallowChargeWarhead                                            = 1660,
    HE_DoubleHallowChargeWarhead                                      = 1665,
    HE_GeneralPurposeWarhead                                          = 1670,
    HE_BlastPenetratorWarhead                                         = 1675,
    HE_RodPenetratorWarhead                                           = 1680,
    HE_AntipersonnelWarhead                                           = 1685,
    SmokeWarhead                                                      = 2000,
    IlluminationWarhead                                               = 3000,
    PracticeWarhead                                                   = 4000,
    KineticWarhead                                                    = 5000,
    MinesWarhead                                                      = 6000,
    NuclearWarhead                                                    = 7000,
    Nuclear_IMTWarhead                                                = 7010,
    Chemical_GeneralWarhead                                           = 8000,
    Chemical_BlisterAgentWarhead                                      = 8100,
    HD_Mustard_Warhead                                                = 8110,
    ThickenedHD_Mustard_Warhead                                       = 8115,
    DustyHD_Mustard_Warhead                                           = 8120,
    Chemical_BloodAgentWarhead                                        = 8200,
    AC_HCN_Warhead                                                    = 8210,
    CK_CNCI_Warhead                                                   = 8215,
    CG_Phosgene_Warhead                                               = 8220,
    Chemical_NerveAgentWarhead                                        = 8300,
    VXWarhead                                                         = 8310,
    ThickenedVXWarhead                                                = 8315,
    DustyVXWarhead                                                    = 8320,
    GA_Tabun_Warhead                                                  = 8325,
    ThickenedGA_Tabun_Warhead                                         = 8330,
    DustyGA_Tabun_Warhead                                             = 8335,
    GB_Sarin_Warhead                                                  = 8340,
    ThickenedGB_Sarin_Warhead                                         = 8345,
    DustyGB_Sarin_Warhead                                             = 8350,
    GD_Soman_Warhead                                                  = 8355,
    ThickenedGD_Soman_Warhead                                         = 8360,
    DustyGD_Soman_Warhead                                             = 8365,
    GFWarhead                                                         = 8370,
    ThickenedGFWarhead                                                = 8375,
    DustyGFWarhead                                                    = 8380,
    BiologicalWarhead                                                 = 9000,
    Biological_VirusWarhead                                           = 9100,
    Biological_BacteriaWarhead                                        = 9200,
    Biological_RickettsiaWarhead                                      = 9300,
    Biological_GeneticallyModifiedMicro_organismsWarhead              = 9400,
    Biological_ToxinWarhead                                           = 9500
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeWarheadType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorWarheadType( KUINT32 Index );

KString GetEnumAsStringWarheadType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringWarheadType( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Fuse Type                                                            */
/* Fuse Type Enums                                                      */
/* Used In:                                                             */
/*  Burst Descriptor                                                    */
/************************************************************************/

enum FuseType
{
    OtherFuse                                                         = 0,
    IntelligentInfluence                                              = 10,
    Sensor                                                            = 20,
    Self_destruct                                                     = 30,
    UltraQuick                                                        = 40,
    Body                                                              = 50,

    DeepIntrusion                                                     = 60,
    Multifunction                                                     = 100,

    PointDetonation_PD                                                = 200,
    BaseDetonation_BD                                                 = 300,

    Contact                                                           = 1000,
    Contact_Instant_Impact                                            = 1100,
    Contact_Delayed                                                   = 1200,
    _10msdelay                                                        = 1201,
    _20msdelay                                                        = 1202,
    _50msdelay                                                        = 1205,
    _60msdelay                                                        = 1206,
    _100msdelay                                                       = 1210,
    _125msdelay                                                       = 1212,
    _250msdelay                                                       = 1225,
    Contact_Electronic_ObliqueContact                                 = 1300,
    Contact_Graze                                                     = 1400,
    Contact_Crush                                                     = 1500,
    Contact_Hydrostatic                                               = 1600,
    Contact_Mechanical                                                = 1700,
    Contact_Chemical                                                  = 1800,
    Contact_Piezoelectric                                             = 1900,
    Contact_PointInitiating                                           = 1910,
    Contact_PointInitiating_BaseDetonating                            = 1920,
    Contact_BaseDetonating                                            = 1930,
    Contact_BallisticCapandBase                                       = 1940,
    Contact_Base                                                      = 1950,
    Contact_Nose                                                      = 1960,
    Contact_FittedinStandoffProbe                                     = 1970,
    Contact_Non_aligned                                               = 1980,

    Timed                                                             = 2000,
    Timed_Programmable                                                = 2100,
    Timed_Burnout                                                     = 2200,
    Timed_Pyrotechnic                                                 = 2300,
    Timed_Electronic                                                  = 2400,
    Timed_BaseDelay                                                   = 2500,
    Timed_ReinforcedNoseImpactDelay                                   = 2600,
    Timed_ShortDelayImpact                                            = 2700,
    _10msdelay1                                                       = 2701,
    _20msdelay1                                                       = 2702,
    _50msdelay1                                                       = 2705,
    _60msdelay1                                                       = 2706,
    _100msdelay1                                                      = 2710,
    _125msdelay1                                                      = 2712,
    _250msdelay1                                                      = 2725,
    Timed_NoseMountedVariableDelay                                    = 2800,
    Timed_LongDelaySide                                               = 2900,
    Timed_SelectableDelay                                             = 2910,
    Timed_Impact                                                      = 2920,
    Timed_Sequence                                                    = 2930,

    Proximity                                                         = 3000,
    Proximity_ActiveLaser                                             = 3100,
    Proximity_Magnetic_Magpolarity                                    = 3200,
    Proximity_ActiveRadar_DopplerRadar                                = 3300,
    Proximity_RadioFrequency_RF                                       = 3400,
    Proximity_Programmable                                            = 3500,
    Proximity_Programmable_Prefragmented                              = 3600,
    Proximity_Infrared                                                = 3700,

    Command                                                           = 4000,
    Command_Electronic_RemotelySet                                    = 4100,

    Altitude                                                          = 5000,
    Altitude_RadioAltimeter                                           = 5100,
    Altitude_AirBurst                                                 = 5200,

    Depth                                                             = 6000,

    Acoustic                                                          = 7000,

    Pressure                                                          = 8000,
    Pressure_Delay                                                    = 8010,
    Inert                                                             = 8100,
    Dummy                                                             = 8110,
    Practice                                                          = 8120,
    PlugRepresenting                                                  = 8130,
    Training                                                          = 8150,

    Pyrotechnic                                                       = 9000,
    Pyrotechnic_Delay                                                 = 9010,
    Electro_optical                                                   = 9100,
    Electromechanical                                                 = 9110,
    Electromechanical_Nose                                            = 9120,
    Strikerless                                                       = 9200,
    Strikerless_NoseImpact                                            = 9210,
    Strikerless_Compression_Ignition                                  = 9220,
    Compression_Ignition                                              = 9300,
    Compression_Ignition_Strikerless_NoseImpact                       = 9310,
    Percussion                                                        = 9400,
    Percussion_Instantaneous                                          = 9410,
    Electronic                                                        = 9500,
    Electronic_InternallyMounted                                      = 9510,
    Electronic_RangeSetting                                           = 9520,
    Electronic_Programmed                                             = 9530,
    Mechanical                                                        = 9600,
    Mechanical_Nose                                                   = 9610,
    Mechanical_Tail                                                   = 9620
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeFuseType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorFuseType( KUINT32 Index );

KString GetEnumAsStringFuseType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringFuseType( const KString & Value, KINT32 & ValueOut ); 

#if DIS_VERSION > 6
/************************************************************************/
/* Fire Type                                                            */
/* Indicates whether the type of object fired was a munition or an      */
/* expendable.                                                          */
/* Used In:                                                             */
/*  Fire PDU                                                            */
/************************************************************************/

enum FireType
{
    MunitionFTI                                                       = 0,
    ExpendableFTI                                                     = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeFireType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorFireType( KUINT32 Index );

KString GetEnumAsStringFireType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringFireType( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Detonation Type                                                      */
/* Indicates whether the type of object that detonated, exploded or     */
/* burst was a munition, expendable, or non-munition explosion.         */
/* Used In:                                                             */
/*  Detonation PDU                                                      */
/************************************************************************/

enum DetonationType
{
    MunitionDTI                                                       = 0,
    ExpendableDTI                                                     = 1,
	NonMunitionExplosionDTI                                           = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeDetonationType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorDetonationType( KUINT32 Index );

KString GetEnumAsStringDetonationType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetonationType( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Explosive Material                                                   */
/* Indicates the material that exploded.                                */
/* These values were taken from CR02668.                                */
/* Used In:                                                             */
/*  Explosive Descriptor                                                */
/************************************************************************/

enum ExplosiveMaterial 
{
    GeneralExplosiveMaterial                                          = 0,                
    LiquidAviationMissileFuels                                        = 1,
    LiquidOtherFuels                                                  = 2,
    LiquidExplosiveMaterial                                           = 3,
    Solid                                                             = 4,
    Gaseous                                                           = 5,
    DustMaterial                                                      = 6,
    AVGAS_AviationGas                                                 = 10,
    JetFuelUnspecified                                                = 11, 
    JP4_F40JETB                                                       = 12,
    JP5_F44JETA                                                       = 13,
    JP7                                                               = 14,
    JP8F_34JETA1                                                      = 15,
    JP10MissileFuel                                                   = 16,
    JPTS                                                              = 17,
    JetA                                                              = 18,
    JetA1                                                             = 19,
    JetB                                                              = 20,
    JetBiofuel                                                        = 21,
    GasolinePetrol_UnspecifiedOctane                                  = 151,
	Ethanol                                                           = 153,
	E85Ethanol                                                        = 154,    	        
    FuelOil                                                           = 155,
    Kerosene                                                          = 156,
    CrudeOil_Unspecified                                              = 157,
    LightCrudeOil                                                     = 158,
    LiquidPetroleumGas                                                = 159,
    RP1RocketFuel                                                     = 160,
    LH2RocketFuel                                                     = 161,
    LOXRocketFuel                                                     = 162,    
    Alcohol                                                           = 164,
	HydrogenLiquid                                                    = 166,
    Nitroglycerin                                                     = 301,
    ANFO                                                              = 302,
    Dynamite                                                          = 451,
    TNT                                                               = 452,
    RDX                                                               = 453,
    PETN                                                              = 454,
    HMX                                                               = 455,
    C4                                                                = 456,
    CompositionC4                                                     = 457,
    NaturalGas                                                        = 601,
    Butane                                                            = 602,
    Propane                                                           = 603,
    Helium                                                            = 604,
    HydrogenGaseous                                                   = 605,
    DustUnspecifiedType                                               = 801, 
    GrainDust                                                         = 802,
    FlourDust                                                         = 803,
    SugarDust                                                         = 804
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeExplosiveMaterial ();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorExplosiveMaterial ( KUINT32 Index );

KString GetEnumAsStringExplosiveMaterial( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringExplosiveMaterial( const KString & Value, KINT32 & ValueOut ); 

#endif

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
