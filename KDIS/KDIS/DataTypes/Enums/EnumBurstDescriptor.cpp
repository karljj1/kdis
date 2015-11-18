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

#include "./EnumBurstDescriptor.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for WarheadType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor WarheadTypeDescriptor[] =
{
    { 0 , "OtherWarhead" },
    { 10 , "Cargo_VariableSubmunitions_Warhead" },
    { 20 , "Fuel_AirExplosiveWarhead" },
    { 30 , "GlassBeadsWarhead" },
    { 31 , "_1umWarhead" },
    { 32 , "_5umWarhead" },
    { 33 , "_10umWarhead" },
    { 1000 , "HighExplosive_HE_Warhead" },
    { 1100 , "HE_PlasticWarhead" },
    { 1200 , "HE_IncendiaryWarhead" },
    { 1300 , "HE_FragmentationWarhead" },
    { 1400 , "HE_AntitankWarhead" },
    { 1500 , "HE_BombletsWarhead" },
    { 1600 , "HE_ShapedChargeWarhead" },
    { 1610 , "HE_ContinuousRodWarhead" },
    { 1615 , "HE_TungstenBallWarhead" },
    { 1620 , "HE_BlastFragmentationWarhead" },
    { 1625 , "HE_SteerableDartswithHEWarhead" },
    { 1630 , "HE_DartsWarhead" },
    { 1635 , "HE_FlechettesWarhead" },
    { 1640 , "HE_DirectedFragmentationWarhead" },
    { 1645 , "HE_Semi_ArmorPiercing_SAP_Warhead" },
    { 1650 , "HE_ShapedChargeFragmentationWarhead" },
    { 1655 , "HE_Semi_ArmorPiercing_FragmentationWarhead" },
    { 1660 , "HE_HallowChargeWarhead" },
    { 1665 , "HE_DoubleHallowChargeWarhead" },
    { 1670 , "HE_GeneralPurposeWarhead" },
    { 1675 , "HE_BlastPenetratorWarhead" },
    { 1680 , "HE_RodPenetratorWarhead" },
    { 1685 , "HE_AntipersonnelWarhead" },
    { 2000 , "SmokeWarhead" },
    { 3000 , "IlluminationWarhead" },
    { 4000 , "PracticeWarhead" },
    { 5000 , "KineticWarhead" },
    { 6000 , "MinesWarhead" },
    { 7000 , "NuclearWarhead" },
    { 7010 , "Nuclear_IMTWarhead" },
    { 8000 , "Chemical_GeneralWarhead" },
    { 8100 , "Chemical_BlisterAgentWarhead" },
    { 8110 , "HD_Mustard_Warhead" },
    { 8115 , "ThickenedHD_Mustard_Warhead" },
    { 8120 , "DustyHD_Mustard_Warhead" },
    { 8200 , "Chemical_BloodAgentWarhead" },
    { 8210 , "AC_HCN_Warhead" },
    { 8215 , "CK_CNCI_Warhead" },
    { 8220 , "CG_Phosgene_Warhead" },
    { 8300 , "Chemical_NerveAgentWarhead" },
    { 8310 , "VXWarhead" },
    { 8315 , "ThickenedVXWarhead" },
    { 8320 , "DustyVXWarhead" },
    { 8325 , "GA_Tabun_Warhead" },
    { 8330 , "ThickenedGA_Tabun_Warhead" },
    { 8335 , "DustyGA_Tabun_Warhead" },
    { 8340 , "GB_Sarin_Warhead" },
    { 8345 , "ThickenedGB_Sarin_Warhead" },
    { 8350 , "DustyGB_Sarin_Warhead" },
    { 8355 , "GD_Soman_Warhead" },
    { 8360 , "ThickenedGD_Soman_Warhead" },
    { 8365 , "DustyGD_Soman_Warhead" },
    { 8370 , "GFWarhead" },
    { 8375 , "ThickenedGFWarhead" },
    { 8380 , "DustyGFWarhead" },
    { 9000 , "BiologicalWarhead" },
    { 9100 , "Biological_VirusWarhead" },
    { 9200 , "Biological_BacteriaWarhead" },
    { 9300 , "Biological_RickettsiaWarhead" },
    { 9400 , "Biological_GeneticallyModifiedMicro_organismsWarhead" },
    { 9500 , "Biological_ToxinWarhead" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeWarheadType()
{
	return sizeof( WarheadTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorWarheadType( KUINT32 Index )
{
	return &WarheadTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringWarheadType( KINT32 Value )
{
    return GetEnumAsString( WarheadTypeDescriptor, sizeof( WarheadTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringWarheadType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( WarheadTypeDescriptor, sizeof( WarheadTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeWarheadType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorWarheadType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringWarheadType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringWarheadType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for FuseType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor FuseTypeDescriptor[] =
{
    { 0 , "OtherFuse" },
    { 10 , "IntelligentInfluence" },
    { 20 , "Sensor" },
    { 30 , "Self_destruct" },
    { 40 , "UltraQuick" },
    { 50 , "Body" },
    { 60 , "DeepIntrusion" },
    { 100 , "Multifunction" },
    { 200 , "PointDetonation_PD" },
    { 300 , "BaseDetonation_BD" },
    { 1000 , "Contact" },
    { 1100 , "Contact_Instant_Impact" },
    { 1200 , "Contact_Delayed" },
    { 1201 , "_10msdelay" },
    { 1202 , "_20msdelay" },
    { 1205 , "_50msdelay" },
    { 1206 , "_60msdelay" },
    { 1210 , "_100msdelay" },
    { 1212 , "_125msdelay" },
    { 1225 , "_250msdelay" },
    { 1300 , "Contact_Electronic_ObliqueContact" },
    { 1400 , "Contact_Graze" },
    { 1500 , "Contact_Crush" },
    { 1600 , "Contact_Hydro" },
    { 1700 , "Contact_Mechanical" },
    { 1800 , "Contact_Chemical" },
    { 1900 , "Contact_Piezoelectric" },
    { 1910 , "Contact_PointInitiating" },
    { 1920 , "Contact_PointInitiating_BaseDetonating" },
    { 1930 , "Contact_BaseDetonating" },
    { 1940 , "Contact_BallisticCapandBase" },
    { 1950 , "Contact_Base" },
    { 1960 , "Contact_Nose" },
    { 1970 , "Contact_FittedinStandoffProbe" },
    { 1980 , "Contact_Non_aligned" },
    { 2000 , "Timed" },
    { 2100 , "Timed_Programmable" },
    { 2200 , "Timed_Burnout" },
    { 2300 , "Timed_Pyrotechnic" },
    { 2400 , "Timed_Electronic" },
    { 2500 , "Timed_BaseDelay" },
    { 2600 , "Timed_ReinforcedNoseImpactDelay" },
    { 2700 , "Timed_ShortDelayImpact" },
    { 2701 , "_10msdelay1" },
    { 2702 , "_20msdelay1" },
    { 2705 , "_50msdelay1" },
    { 2706 , "_60msdelay1" },
    { 2710 , "_100msdelay1" },
    { 2712 , "_125msdelay1" },
    { 2725 , "_250msdelay1" },
    { 2800 , "Timed_NoseMountedVariableDelay" },
    { 2900 , "Timed_LongDelaySide" },
    { 2910 , "Timed_SelectableDelay" },
    { 2920 , "Timed_Impact" },
    { 2930 , "Timed_Sequence" },
    { 3000 , "Proximity" },
    { 3100 , "Proximity_ActiveLaser" },
    { 3200 , "Proximity_Magnetic_Magpolarity" },
    { 3300 , "Proximity_ActiveRadar_DopplerRadar" },
    { 3400 , "Proximity_RadioFrequency_RF" },
    { 3500 , "Proximity_Programmable" },
    { 3600 , "Proximity_Programmable_Prefragmented" },
    { 3700 , "Proximity_Infrared" },
    { 4000 , "Command" },
    { 4100 , "Command_Electronic_RemotelySet" },
    { 5000 , "Altitude" },
    { 5100 , "Altitude_RadioAltimeter" },
    { 5200 , "Altitude_AirBurst" },
    { 6000 , "Depth" },
    { 7000 , "Acoustic" },
    { 8000 , "Pressure" },
    { 8010 , "Pressure_Delay" },
    { 8100 , "Inert" },
    { 8110 , "Dummy" },
    { 8120 , "Practice" },
    { 8130 , "PlugRepresenting" },
    { 8150 , "Training" },
    { 9000 , "Pyrotechnic" },
    { 9010 , "Pyrotechnic_Delay" },
    { 9100 , "Electro_optical" },
    { 9110 , "Electromechanical" },
    { 9120 , "Electromechanical_Nose" },
    { 9200 , "Strikerless" },
    { 9210 , "Strikerless_NoseImpact" },
    { 9220 , "Strikerless_Compression_Ignition" },
    { 9300 , "Compression_Ignition" },
    { 9310 , "Compression_Ignition_Strikerless_NoseImpact" },
    { 9400 , "Percussion" },
    { 9410 , "Percussion_Instantaneous" },
    { 9500 , "Electronic" },
    { 9510 , "Electronic_InternallyMounted" },
    { 9520 , "Electronic_RangeSetting" },
    { 9530 , "Electronic_Programmed" },
    { 9600 , "Mechanical" },
    { 9610 , "Mechanical_Nose" },
    { 9620 , "Mechanical_Tail" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeFuseType()
{
	return sizeof( FuseTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorFuseType( KUINT32 Index )
{
	return &FuseTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringFuseType( KINT32 Value )
{
    return GetEnumAsString( FuseTypeDescriptor, sizeof( FuseTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringFuseType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( FuseTypeDescriptor, sizeof( FuseTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeFuseType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorFuseType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringFuseType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringFuseType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

#if DIS_VERSION > 6
//////////////////////////////////////////////////////////////////////////

// Implementation of string values for FireType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor FireTypeDescriptor[] =
{
    { 0 , "Munition" },
    { 1 , "Expendable" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeFireType()
{
	return sizeof( FireTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorFireType( KUINT32 Index )
{
	return &FireTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringFireType( KINT32 Value )
{
    return GetEnumAsString( FireTypeDescriptor, sizeof( FireTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringFireType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( FireTypeDescriptor, sizeof( FireTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeFireType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorFireType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringFireType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringFireType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DetonationType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetonationTypeDescriptor[] =
{
    { 0 , "Munition" },
    { 1 , "Expendable" },
	{ 2 , "Non-Munition Explosion" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetonationType()
{
	return sizeof( DetonationTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetonationType( KUINT32 Index )
{
	return &DetonationTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetonationType( KINT32 Value )
{
    return GetEnumAsString( DetonationTypeDescriptor, sizeof( DetonationTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetonationType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetonationTypeDescriptor, sizeof( DetonationTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetonationType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetonationType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetonationType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetonationType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ExplosiveMaterial

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ExplosiveMaterialDescriptor[] =
{
    { 0 , "GeneralExplosiveMaterial" },
    { 1 , "LiquidAviationMissileFuels" },
	{ 2 , "LiquidOtherFuels" },
	{ 3 , "LiquidExplosiveMaterial" },
	{ 4 , "Solid" },
	{ 5 , "Gaseous" },
	{ 6 , "DustMaterial" },
	{ 10 , "AVGAS_AviationGas" },
	{ 11 , "JetFuelUnspecified" },
	{ 12 , "JP4_F40JETB" },
	{ 13 , "JP5_F44JETA" },
	{ 14 , "JP7" },
	{ 15 , "JP8F_34JETA1" },
	{ 16 , "JP10MissileFuel" },
	{ 17 , "JPTS" },
	{ 18 , "JetA" },
	{ 19 , "JetA1" },
	{ 20 , "JetB" },
	{ 21 , "JetBiofuel" },
	{ 151 , "GasolinePetrol_UnspecifiedOctane" },
	{ 153 , "Ethanol" },
	{ 154 , "E85Ethanol" },	
	{ 155 , "FuelOil" },
	{ 156 , "Kerosene" },
	{ 157 , "CrudeOil_Unspecified" },
	{ 158 , "LightCrudeOil" },
	{ 159 , "LiquidPetroleumGas" },
	{ 160 , "RP1RocketFuel" },
	{ 161 , "LH2RocketFuel" },
	{ 162 , "LOXRocketFuel" },
	{ 164 , "Alcohol" },
	{ 166 , "HydrogenLiquid" },
	{ 301 , "Nitroglycerin" },
	{ 302 , "ANFO" },
	{ 451 , "Dynamite" },
	{ 452 , "TNT" },
	{ 453 , "RDX" },
	{ 454 , "PETN" },
	{ 455 , "HMX" },
	{ 456 , "C4" },
	{ 457 , "CompositionC4" },
	{ 601 , "NaturalGas" },
	{ 602 , "Butane" },
	{ 603 , "Propane" },
	{ 604 , "Helium" },
	{ 605 , "HydrogenGaseous" },
	{ 801 , "DustUnspecifiedType" },
	{ 802 , "GrainDust" },
	{ 803 , "FlourDust" },
	{ 804 , "SugarDust" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeExplosiveMaterial()
{
	return sizeof( ExplosiveMaterialDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorExplosiveMaterial( KUINT32 Index )
{
	return &ExplosiveMaterialDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringExplosiveMaterial( KINT32 Value )
{
    return GetEnumAsString( ExplosiveMaterialDescriptor, sizeof( ExplosiveMaterialDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringExplosiveMaterial( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ExplosiveMaterialDescriptor, sizeof( ExplosiveMaterialDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeExplosiveMaterial()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorExplosiveMaterial( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringExplosiveMaterial( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringExplosiveMaterial( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
#endif
