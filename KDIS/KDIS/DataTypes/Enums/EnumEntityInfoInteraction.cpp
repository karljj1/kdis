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

#include "./EnumEntityInfoInteraction.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for CollisionType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor CollisionTypeDescriptor[] =
{
    { 0 , "InelasticCollision" },
    { 1 , "ElasticCollision" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeCollisionType()
{
	return sizeof( CollisionTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorCollisionType( KUINT32 Index )
{
	return &CollisionTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCollisionType( KINT32 Value )
{
    return GetEnumAsString( CollisionTypeDescriptor, sizeof( CollisionTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCollisionType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( CollisionTypeDescriptor, sizeof( CollisionTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeCollisionType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorCollisionType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCollisionType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCollisionType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityKind

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityKindDescriptor[] =
{
    { 0 , "OtherKind" },
    { 1 , "Platform" },
    { 2 , "Munition" },
    { 3 , "Lifeform" },
    { 4 , "Environmental" },
    { 5 , "Culturalfeature" },
    { 6 , "Supply" },
    { 7 , "Radio" },
    { 8 , "Expendable" },
    { 9 , "SensorEmitter" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityKind()
{
	return sizeof( EntityKindDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityKind( KUINT32 Index )
{
	return &EntityKindDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityKind( KINT32 Value )
{
    return GetEnumAsString( EntityKindDescriptor, sizeof( EntityKindDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityKind( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityKindDescriptor, sizeof( EntityKindDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityKind()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityKind( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityKind( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityKind( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityDomain

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityDomainDescriptor[] =
{
    { 0 , "OtherDomain" },
    { 1 , "Land" },
    { 2 , "Air" },
    { 3 , "Surface" },
    { 4 , "Subsurface" },
    { 5 , "Space" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityDomain()
{
	return sizeof( EntityDomainDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityDomain( KUINT32 Index )
{
	return &EntityDomainDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityDomain( KINT32 Value )
{
    return GetEnumAsString( EntityDomainDescriptor, sizeof( EntityDomainDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityDomain( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityDomainDescriptor, sizeof( EntityDomainDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityDomain()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityDomain( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityDomain( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityDomain( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for Country
// Note the order has changed for the search algorithm to work correctly.

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor CountryDescriptor[] =
{
    { 0 , "OtherCountry" },
    { 1 , "Afghanistan" },
    { 2 , "Albania" },
    { 3 , "Algeria" },
    { 4 , "AmericanSamoa_USA" },
    { 5 , "Andorra" },
    { 6 , "Angola" },
    { 7 , "Anguilla" },
    { 8 , "Antarctica" },
    { 9 , "AntiguaAndBarbuda" },
    { 10 , "Argentina" },
    { 11 , "Aruba" },
    { 12 , "AshmoreAndCartierIslands_Australia" },
    { 13 , "Australia" },
    { 14 , "Austria" },
    { 15 , "Bahamas" },
    { 16 , "Bahrain" },
    { 17 , "BakerIsland_USA" },
    { 18 , "Bangladesh" },
    { 19 , "Barbados" },
    { 20 , "BassasDaIndia_France" },
    { 21 , "Belgium" },
    { 22 , "Belize" },
    { 23 , "Benin" },
    { 24 , "Bermuda_UK" },
    { 25 , "Bhutan" },
    { 26 , "Bolivia" },
    { 27 , "Botswana" },
    { 28 , "BouvetIsland_Norway" },
    { 29 , "Brazil" },
    { 30 , "BritishIndianOceanTerritory_UK" },
    { 31 , "BritishVirginIslands_UK" },
    { 32 , "Brunei" },
    { 33 , "Bulgaria" },
    { 34 , "Burkina" },
    { 35 , "Burma" },
    { 36 , "Burundi" },
    { 37 , "Cambodia" },
    { 38 , "Cameroon" },
    { 39 , "Canada" },
    { 40 , "CapeVerde" },
    { 41 , "CaymanIslands_UK" },
    { 42 , "CentralAfricanRepublic" },
    { 43 , "Chad" },
    { 44 , "Chile" },
    { 45 , "China" },
    { 46 , "ChristmasIsland_Australia" },
    { 47 , "CocosIslands_Australia" },
    { 48 , "Colombia" },
    { 49 , "Comoros" },
    { 50 , "Congo" },
    { 51 , "CookIslands_NewZealand" },
    { 52 , "CoralSeaIslands_Australia" },
    { 53 , "CostaRica" },
    { 54 , "Cuba" },
    { 55 , "Cyprus" },
    { 56 , "Czechoslovakia" },
    { 57 , "Denmark" },
    { 58 , "Djibouti" },
    { 59 , "Dominica" },
    { 60 , "DominicanRepublic" },
    { 61 , "Ecuador" },
    { 62 , "Egypt" },
    { 63 , "ElSalvador" },
    { 64 , "EquatorialGuinea" },
    { 65 , "Ethiopia" },
    { 66 , "EuropaIsland_France" },
    { 67 , "FalklandIslands_UK" },
    { 68 , "FaroeIslands_Denmark" },
    { 69 , "Fiji" },
    { 70 , "Finland" },
    { 71 , "France" },
    { 72 , "FrenchGuiana_France" },
    { 73 , "FrenchPolynesia_France" },
    { 74 , "FrenchSouthernAndAntarcticIslands_France" },
    { 75 , "Gabon" },
    { 76 , "Gambia" },
    { 77 , "GazaStrip_Israel" },
    { 78 , "Germany" },
    { 79 , "Ghana" },
    { 80 , "Gibraltar_UK" },
    { 81 , "GloriosoIslands_France" },
    { 82 , "Greece" },
    { 83 , "Greenland_Denmark" },
    { 84 , "Grenada" },
    { 85 , "Guadaloupe_France" },
    { 86 , "Guam_USA" },
    { 87 , "Guatemala" },
    { 88 , "Guernsey_UK" },
    { 89 , "Guinea" },
    { 90 , "GuineaBissau" },
    { 91 , "Guyana" },
    { 92 , "Haiti" },
    { 93 , "HeardIslandAndMcDonaldIslands_Australia" },
    { 94 , "Honduras" },
    { 95 , "HongKong_UK" },
    { 96 , "HowlandIsland_USA" },
    { 97 , "Hungary" },
    { 98 , "Iceland" },
    { 99 , "India" },
    { 100 , "Indonesia" },
    { 101 , "Iran" },
    { 102 , "Iraq" },
    { 104 , "Ireland" },
    { 105 , "Israel" },
    { 106 , "Italy" },
    { 107 , "IvoryCoast" },
    { 108 , "Jamaica" },
    { 109 , "JanMayen_Norway" },
    { 110 , "Japan" },
    { 111 , "JarvisIsland_USA" },
    { 112 , "Jersey_UK" },
    { 113 , "JohnstonAtoll_USA" },
    { 114 , "Jordan" },
    { 115 , "JuanDeNovaIsland" },
    { 116 , "Kenya" },
    { 117 , "KingmanReef_USA" },
    { 118 , "Kiribati" },
    { 119 , "NorthKorea" },
    { 120 , "SouthKorea" },
    { 121 , "Kuwait" },
    { 122 , "Laos" },
    { 123 , "Lebanon" },
    { 124 , "Lesotho" },
    { 125 , "Liberia" },
    { 126 , "Libya" },
    { 127 , "Liechtenstein" },
    { 128 , "Luxembourg" },
    { 129 , "Madagascar" },
    { 130 , "Macau_Portugal" },
    { 131 , "Malawi" },
    { 132 , "Malaysia" },
    { 133 , "Maldives" },
    { 134 , "Mali" },
    { 135 , "Malta" },
    { 136 , "IsleOfMan_UK" },
    { 137 , "MarshallIslands" },
    { 138 , "Martinique_France" },
    { 139 , "Mauritania" },
    { 140 , "Mauritius" },
    { 141 , "Mayotte_France" },
    { 142 , "Mexico" },
    { 143 , "Micronesia" },
    { 144 , "Monaco" },
    { 145 , "Mongolia" },
    { 146 , "Montserrat_UK" },
    { 147 , "Morocco" },
    { 148 , "Mozambique" },
    { 149 , "Namibia" },
    { 150 , "Nauru" },
    { 151 , "NavassaIsland_USA" },
    { 152 , "Nepal" },
    { 153 , "Netherlands" },
    { 154 , "NetherlandsAntilles" },
    { 155 , "NewCaledonia_France" },
    { 156 , "NewZealand" },
    { 157 , "Nicaragua" },
    { 158 , "Niger" },
    { 159 , "Nigeria" },
    { 160 , "Niue_NewZealand" },
    { 161 , "NorfolkIsland_Australia" },
    { 162 , "NorthernMarianaIslands_USA" },
    { 163 , "Norway" },
    { 164 , "Oman" },
    { 165 , "Pakistan" },
    { 166 , "PalmyraAtoll_USA" },
    { 168 , "Panama" },
    { 169 , "PapuaNewGuinea" },
    { 170 , "ParacelIslands" },
    { 171 , "Paraguay" },
    { 172 , "Peru" },
    { 173 , "Philippines" },
    { 174 , "PitcairnIslands_UK" },
    { 175 , "Poland" },
    { 176 , "Portugal" },
    { 177 , "PuertoRico_USA" },
    { 178 , "Qatar" },
    { 179 , "Reunion_France" },
    { 180 , "Romania" },
    { 181 , "Rwanda" },
    { 182 , "StKittsAndNevis" },
    { 183 , "StHelena_UK" },
    { 184 , "StLucia" },
    { 185 , "StPierreAndMiquelon_France" },
    { 186 , "StVincentAndTheGrenadines" },
    { 187 , "SanMarino" },
    { 188 , "SaoTomeAndPrincipe" },
    { 189 , "SaudiArabia" },
    { 190 , "Senegal" },
    { 191 , "Seychelles" },
    { 192 , "SierraLeone" },
    { 193 , "Singapore" },
    { 194 , "SolomonIslands" },
    { 195 , "Somalia" },
    { 196 , "SouthGeorgiaAndTheSouthSandwichIslands_UK" },
    { 197 , "SouthAfrica" },
    { 198 , "Spain" },
    { 199 , "SpratlyIslands" },
    { 200 , "SriLanka" },
    { 201 , "Sudan" },
    { 202 , "Suriname" },
    { 203 , "Svalbard_Norway" },
    { 204 , "Swaziland" },
    { 205 , "Sweden" },
    { 206 , "Switzerland" },
    { 207 , "Syria" },
    { 208 , "Taiwan" },
    { 209 , "Tanzania" },
    { 210 , "Thailand" },
    { 211 , "Togo" },
    { 212 , "Tokelau_NewZealand" },
    { 213 , "Tonga" },
    { 214 , "TrinidadAndTobago" },
    { 215 , "TromelinIsland_France" },
    { 216 , "PacificIslands" },
    { 217 , "Tunisia" },
    { 218 , "Turkey" },
    { 219 , "TurksAndCaicosIslands_UK" },
    { 220 , "Tuvalu" },
    { 221 , "Uganda" },
    { 222 , "CommonwealthOfIndependentStates" },
    { 223 , "UnitedArabEmirates" },
    { 224 , "UnitedKingdom" },
    { 225 , "UnitedStates" },
    { 226 , "Uruguay" },
    { 227 , "Vanuatu" },
    { 228 , "VaticanCity" },
    { 229 , "Venezuela" },
    { 230 , "Vietnam" },
    { 231 , "VirginIslands_USA" },
    { 232 , "WakeIsland_USA" },
    { 233 , "WallisAndFutuna_France" },
    { 234 , "WesternSahara" },
    { 235 , "WestBank_Israel" },
    { 236 , "WesternSamoa" },
    { 237 , "Yemen" },
    { 241 , "Zaire" },
    { 242 , "Zambia" },
    { 243 , "Zimbabwe" },
    { 244 , "Armenia" },
    { 245 , "Azerbaijan" },
    { 246 , "Belarus" },
    { 247 , "BosniaAndHercegovina" },
    { 248 , "ClippertonIsland_France" },
    { 249 , "Croatia" },
    { 250 , "Estonia" },
    { 251 , "Georgia" },
    { 252 , "Kazakhstan" },
    { 253 , "Kyrgyzstan" },
    { 254 , "Latvia" },
    { 255 , "Lithuania" },
    { 256 , "Macedonia" },
    { 257 , "MidwayIslands_USA" },
    { 258 , "Moldova" },
    { 259 , "Montenegro" },
    { 260 , "Russia" },
    { 261 , "SerbiaAndMontenegro" },
    { 262 , "Slovenia" },
    { 263 , "Tajikistan" },
    { 264 , "Turkmenistan" },
    { 265 , "Ukraine" },
    { 266 , "Uzbekistan" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeCountry()
{
	return sizeof( CountryDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorCountry( KUINT32 Index )
{
	return &CountryDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCountry( KINT32 Value )
{
    return GetEnumAsString( CountryDescriptor, sizeof( CountryDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCountry( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( CountryDescriptor, sizeof( CountryDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeCountry()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorCountry( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCountry( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCountry( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for VariableParameterType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor VariableParameterTypeDescriptor[] =
{
    { 0 , "ArticulatedPartType" },
    { 1 , "AttachedPartType" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeVariableParameterType()
{
	return sizeof( VariableParameterTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorVariableParameterType( KUINT32 Index )
{
	return &VariableParameterTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringVariableParameterType( KINT32 Value )
{
    return GetEnumAsString( VariableParameterTypeDescriptor, sizeof( VariableParameterTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringVariableParameterType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( VariableParameterTypeDescriptor, sizeof( VariableParameterTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeVariableParameterType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorVariableParameterType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringVariableParameterType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringVariableParameterType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ArticulatedPartsMetric

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ArticulatedPartsMetricDescriptor[] =
{
    { 1 , "Position" },
    { 2 , "PositionRate" },
    { 3 , "Extension" },
    { 4 , "ExtensionRate" },
    { 5 , "XValue" },
    { 6 , "XRate" },
    { 7 , "YValue" },
    { 8 , "YRate" },
    { 9 , "ZValue" },
    { 10 , "ZRate" },
    { 11 , "Azimuth" },
    { 12 , "AzimuthRate" },
    { 13 , "Elevation" },
    { 14 , "ElevationRate" },
    { 15 , "Rotation" },
    { 16 , "RotationRate" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeArticulatedPartsMetric()
{
	return sizeof( ArticulatedPartsMetricDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorArticulatedPartsMetric( KUINT32 Index )
{
	return &ArticulatedPartsMetricDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringArticulatedPartsMetric( KINT32 Value )
{
    return GetEnumAsString( ArticulatedPartsMetricDescriptor, sizeof( ArticulatedPartsMetricDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringArticulatedPartsMetric( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ArticulatedPartsMetricDescriptor, sizeof( ArticulatedPartsMetricDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeArticulatedPartsMetric()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorArticulatedPartsMetric( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringArticulatedPartsMetric( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringArticulatedPartsMetric( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ArticulatedPartsClass

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ArticulatedPartsClassDescriptor[] =
{
    { 1024 , "Rudder" },
    { 1056 , "LeftFlap" },
    { 1088 , "RightFlap" },
    { 1120 , "LeftAileron" },
    { 1152 , "RightAileron" },
    { 1184 , "HelicopterMainRotor" },
    { 1216 , "HelicopterTailRotor" },
    { 1248 , "OtherAircraftControlSurfaces" },
    { 2048 , "Periscope" },
    { 2080 , "GenericAntenna" },
    { 2112 , "Snorkel" },
    { 2144 , "OtherExtendableParts" },
    { 3072 , "LandingGear" },
    { 3104 , "TailHook" },
    { 3136 , "SpeedBrake" },
    { 3168 , "LeftWeaponBayDoor" },
    { 3200 , "RightWeaponBayDoors" },
    { 3232 , "TankOrAPCHatch" },
    { 3264 , "Wingsweep" },
    { 3296 , "BridgeLauncher" },
    { 3328 , "BridgeSection1" },
    { 3360 , "BridgeSection2" },
    { 3392 , "BridgeSection3" },
    { 3424 , "PrimaryBlade1" },
    { 3456 , "PrimaryBlade2" },
    { 3488 , "PrimaryBoom" },
    { 3520 , "PrimaryLauncherArm" },
    { 3552 , "OtherFixedPositionParts" },
    { 4096 , "PrimaryTurretNumber1" },
    { 4128 , "PrimaryTurretNumber2" },
    { 4160 , "PrimaryTurretNumber3" },
    { 4192 , "PrimaryTurretNumber4" },
    { 4224 , "PrimaryTurretNumber5" },
    { 4256 , "PrimaryTurretNumber6" },
    { 4288 , "PrimaryTurretNumber7" },
    { 4320 , "PrimaryTurretNumber8" },
    { 4352 , "PrimaryTurretNumber9" },
    { 4384 , "PrimaryTurretNumber10" },
    { 4416 , "PrimaryGunNumber1" },
    { 4448 , "PrimaryGunNumber2" },
    { 4480 , "PrimaryGunNumber3" },
    { 4512 , "PrimaryGunNumber4" },
    { 4544 , "PrimaryGunNumber5" },
    { 4576 , "PrimaryGunNumber6" },
    { 4608 , "PrimaryGunNumber7" },
    { 4640 , "PrimaryGunNumber8" },
    { 4672 , "PrimaryGunNumber9" },
    { 4704 , "PrimaryGunNumber10" },
    { 4736 , "PrimaryLauncher1" },
    { 4768 , "PrimaryLauncher2" },
    { 4800 , "PrimaryLauncher3" },
    { 4832 , "PrimaryLauncher4" },
    { 4864 , "PrimaryLauncher5" },
    { 4896 , "PrimaryLauncher6" },
    { 4928 , "PrimaryLauncher7" },
    { 4960 , "PrimaryLauncher8" },
    { 4992 , "PrimaryLauncher9" },
    { 5024 , "PrimaryLauncher10" },
    { 5056 , "PrimaryDefenseSystems1" },
    { 5088 , "PrimaryDefenseSystems2" },
    { 5120 , "PrimaryDefenseSystems3" },
    { 5152 , "PrimaryDefenseSystems4" },
    { 5184 , "PrimaryDefenseSystems5" },
    { 5216 , "PrimaryDefenseSystems6" },
    { 5248 , "PrimaryDefenseSystems7" },
    { 5280 , "PrimaryDefenseSystems8" },
    { 5312 , "PrimaryDefenseSystems9" },
    { 5344 , "PrimaryDefenseSystems10" },
    { 5376 , "PrimaryRadar1" },
    { 5408 , "PrimaryRadar2" },
    { 5440 , "PrimaryRadar3" },
    { 5472 , "PrimaryRadar4" },
    { 5504 , "PrimaryRadar5" },
    { 5536 , "PrimaryRadar6" },
    { 5568 , "PrimaryRadar7" },
    { 5600 , "PrimaryRadar8" },
    { 5632 , "PrimaryRadar9" },
    { 5664 , "PrimaryRadar10" },
    { 5696 , "SecondaryTurretNumber1" },
    { 5728 , "SecondaryTurretNumber2" },
    { 5760 , "SecondaryTurretNumber3" },
    { 5792 , "SecondaryTurretNumber4" },
    { 5824 , "SecondaryTurretNumber5" },
    { 5856 , "SecondaryTurretNumber6" },
    { 5888 , "SecondaryTurretNumber7" },
    { 5920 , "SecondaryTurretNumber8" },
    { 5952 , "SecondaryTurretNumber9" },
    { 5984 , "SecondaryTurretNumber10" },
    { 6016 , "SecondaryGunNumber1" },
    { 6048 , "SecondaryGunNumber2" },
    { 6080 , "SecondaryGunNumber3" },
    { 6112 , "SecondaryGunNumber4" },
    { 6144 , "SecondaryGunNumber5" },
    { 6176 , "SecondaryGunNumber6" },
    { 6208 , "SecondaryGunNumber7" },
    { 6240 , "SecondaryGunNumber8" },
    { 6272 , "SecondaryGunNumber9" },
    { 6304 , "SecondaryGunNumber10" },
    { 6336 , "SecondaryLauncher1" },
    { 6368 , "SecondaryLauncher2" },
    { 6400 , "SecondaryLauncher3" },
    { 6432 , "SecondaryLauncher4" },
    { 6464 , "SecondaryLauncher5" },
    { 6496 , "SecondaryLauncher6" },
    { 6528 , "SecondaryLauncher7" },
    { 6560 , "SecondaryLauncher8" },
    { 6592 , "SecondaryLauncher9" },
    { 6624 , "SecondaryLauncher10" },
    { 6656 , "SecondaryDefenseSystems1" },
    { 6688 , "SecondaryDefenseSystems2" },
    { 6720 , "SecondaryDefenseSystems3" },
    { 6752 , "SecondaryDefenseSystems4" },
    { 6784 , "SecondaryDefenseSystems5" },
    { 6816 , "SecondaryDefenseSystems6" },
    { 6848 , "SecondaryDefenseSystems7" },
    { 6880 , "SecondaryDefenseSystems8" },
    { 6912 , "SecondaryDefenseSystems9" },
    { 6944 , "SecondaryDefenseSystems10" },
    { 6976 , "SecondaryRadar1" },
    { 7008 , "SecondaryRadar2" },
    { 7040 , "SecondaryRadar3" },
    { 7072 , "SecondaryRadar4" },
    { 7104 , "SecondaryRadar5" },
    { 7136 , "SecondaryRadar6" },
    { 7168 , "SecondaryRadar7" },
    { 7200 , "SecondaryRadar8" },
    { 7232 , "SecondaryRadar9" },
    { 7264 , "SecondaryRadar10" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeArticulatedPartsClass()
{
	return sizeof( ArticulatedPartsClassDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorArticulatedPartsClass( KUINT32 Index )
{
	return &ArticulatedPartsClassDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringArticulatedPartsClass( KINT32 Value )
{
    return GetEnumAsString( ArticulatedPartsClassDescriptor, sizeof( ArticulatedPartsClassDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringArticulatedPartsClass( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ArticulatedPartsClassDescriptor, sizeof( ArticulatedPartsClassDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeArticulatedPartsClass()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorArticulatedPartsClass( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringArticulatedPartsClass( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringArticulatedPartsClass( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AttachedPartParameterType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AttachedPartParameterTypeDescriptor[] =
{
    { 1   , "ModelSpecificStations" },
    { 512 , "FuselageStations" },
	{ 640 , "LeftWingStations" },
	{ 768 , "RightWingStations" },
	{ 896 , "M16A42Rifle" },
	{ 897 , "M249SAW" },
	{ 898 , "M60MachineGun" },
	{ 899 , "M203GrenadeLauncher" },
	{ 900 , "M136AT4" },
	{ 901 , "M47Dragon" },
	{ 902 , "AAWSMJavelin" },
	{ 903 , "M18A1ClaymoreMine" },
	{ 904 , "MK19GrenadeLauncher" },
	{ 905 , "M2MachineGun" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAttachedPartParameterType()
{
	return sizeof( AttachedPartParameterTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAttachedPartParameterType( KUINT32 Index )
{
	return &AttachedPartParameterTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAttachedPartParameterType( KINT32 Value )
{
    return GetEnumAsString( AttachedPartParameterTypeDescriptor, sizeof( AttachedPartParameterTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAttachedPartParameterType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AttachedPartParameterTypeDescriptor, sizeof( AttachedPartParameterTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAttachedPartParameterType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAttachedPartParameterType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAttachedPartParameterType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAttachedPartParameterType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityPaintScheme

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityPaintSchemeDescriptor[] =
{
    { 0 , "UniformColor" },
    { 1 , "Camouflage" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityPaintScheme()
{
	return sizeof( EntityPaintSchemeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityPaintScheme( KUINT32 Index )
{
	return &EntityPaintSchemeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityPaintScheme( KINT32 Value )
{
    return GetEnumAsString( EntityPaintSchemeDescriptor, sizeof( EntityPaintSchemeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityPaintScheme( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityPaintSchemeDescriptor, sizeof( EntityPaintSchemeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityPaintScheme()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityPaintScheme( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityPaintScheme( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityPaintScheme( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityDamage

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityDamageDescriptor[] =
{
    { 0 , "NoDamage" },
    { 1 , "SlightDamage" },
    { 2 , "ModerateDamage" },
    { 3 , "Destroyed" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityDamage()
{
	return sizeof( EntityDamageDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityDamage( KUINT32 Index )
{
	return &EntityDamageDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityDamage( KINT32 Value )
{
    return GetEnumAsString( EntityDamageDescriptor, sizeof( EntityDamageDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityDamage( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityDamageDescriptor, sizeof( EntityDamageDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityDamage()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityDamage( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityDamage( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityDamage( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntitySmoke

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntitySmokeDescriptor[] =
{
    { 0 , "NotSmoking" },
    { 1 , "SmokePlume" },
    { 2 , "EngineSmoke" },
    { 3 , "EngineSmokeAndSmokePlume" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntitySmoke()
{
	return sizeof( EntitySmokeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntitySmoke( KUINT32 Index )
{
	return &EntitySmokeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntitySmoke( KINT32 Value )
{
    return GetEnumAsString( EntitySmokeDescriptor, sizeof( EntitySmokeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntitySmoke( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntitySmokeDescriptor, sizeof( EntitySmokeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntitySmoke()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntitySmoke( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntitySmoke( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntitySmoke( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityTrailingEffect

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityTrailingEffectDescriptor[] =
{
    { 0 , "NoTrail" },
    { 1 , "Small" },
    { 2 , "Medium" },
    { 3 , "Large" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityTrailingEffect()
{
	return sizeof( EntityTrailingEffectDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityTrailingEffect( KUINT32 Index )
{
	return &EntityTrailingEffectDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityTrailingEffect( KINT32 Value )
{
    return GetEnumAsString( EntityTrailingEffectDescriptor, sizeof( EntityTrailingEffectDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityTrailingEffect( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityTrailingEffectDescriptor, sizeof( EntityTrailingEffectDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityTrailingEffect()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityTrailingEffect( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityTrailingEffect( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityTrailingEffect( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityHatchState

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityHatchStateDescriptor[] =
{
    { 0 , "EntityHatchStateNotApplicable" },
    { 1 , "PrimaryHatchIsClosed" },
    { 2 , "PrimaryHatchIsPopped" },
    { 3 , "PrimaryHatchIsPoppedPersonVisibleUnderHatch" },
    { 4 , "PrimaryHatchIsOpen" },
    { 5 , "PrimaryHatchIsOpenPersonVisible" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityHatchState()
{
	return sizeof( EntityHatchStateDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityHatchState( KUINT32 Index )
{
	return &EntityHatchStateDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityHatchState( KINT32 Value )
{
    return GetEnumAsString( EntityHatchStateDescriptor, sizeof( EntityHatchStateDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityHatchState( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityHatchStateDescriptor, sizeof( EntityHatchStateDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityHatchState()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityHatchState( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityHatchState( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityHatchState( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityLights

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityLightsDescriptor[] =
{
    { 0 , "NoLights" },
    { 1 , "RunningLightsOn" },
    { 2 , "NavigationLightsOn" },
    { 3 , "FromationLightsOn" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityLights()
{
	return sizeof( EntityLightsDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityLights( KUINT32 Index )
{
	return &EntityLightsDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityLights( KINT32 Value )
{
    return GetEnumAsString( EntityLightsDescriptor, sizeof( EntityLightsDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityLights( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityLightsDescriptor, sizeof( EntityLightsDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityLights()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityLights( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityLights( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityLights( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityCamouflage

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityCamouflageDescriptor[] =
{
    { 0 , "DesertCamouflage" },
    { 1 , "WinterCamouflage" },
    { 2 , "ForestCamouflage" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityCamouflage()
{
	return sizeof( EntityCamouflageDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityCamouflage( KUINT32 Index )
{
	return &EntityCamouflageDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityCamouflage( KINT32 Value )
{
    return GetEnumAsString( EntityCamouflageDescriptor, sizeof( EntityCamouflageDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityCamouflage( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityCamouflageDescriptor, sizeof( EntityCamouflageDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityCamouflage()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityCamouflage( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityCamouflage( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityCamouflage( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityLifeformAppearance

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityLifeformAppearanceDescriptor[] =
{
    { 1 , "UprightStandingStill" },
    { 2 , "UprightWalking" },
    { 3 , "UprightRunning" },
    { 4 , "Kneeling" },
    { 5 , "Prone" },
    { 6 , "Crawling" },
    { 7 , "Swimming" },
    { 8 , "Parachuting" },
    { 9 , "Jumping" },
	{ 10 , "Sitting" },
	{ 11 , "Squatting" },
	{ 12 , "Crouching" },
	{ 13 , "Wading" },
	{ 14 , "SurrenderAppearance" },
	{ 15 , "DetainedAppearance" }	
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityLifeformAppearance()
{
	return sizeof( EntityLifeformAppearanceDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityLifeformAppearance( KUINT32 Index )
{
	return &EntityLifeformAppearanceDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityLifeformAppearance( KINT32 Value )
{
    return GetEnumAsString( EntityLifeformAppearanceDescriptor, sizeof( EntityLifeformAppearanceDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityLifeformAppearance( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityLifeformAppearanceDescriptor, sizeof( EntityLifeformAppearanceDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityLifeformAppearance()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityLifeformAppearance( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityLifeformAppearance( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityLifeformAppearance( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityLifeformWeapon

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityLifeformWeaponDescriptor[] =
{
    { 0 , "NoPrimaryWeaponPresent" },
    { 1 , "PrimaryWeaponIsStowed" },
    { 2 , "PrimaryWeaponIsDeployed" },
    { 3 , "PrimaryWeaponIsInTheFiringPosition" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityLifeformWeapon()
{
	return sizeof( EntityLifeformWeaponDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityLifeformWeapon( KUINT32 Index )
{
	return &EntityLifeformWeaponDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityLifeformWeapon( KINT32 Value )
{
    return GetEnumAsString( EntityLifeformWeaponDescriptor, sizeof( EntityLifeformWeaponDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityLifeformWeapon( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityLifeformWeaponDescriptor, sizeof( EntityLifeformWeaponDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityLifeformWeapon()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityLifeformWeapon( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityLifeformWeapon( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityLifeformWeapon( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityDensity

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityDensityDescriptor[] =
{
    { 0 , "Clear" },
    { 1 , "Hazy" },
    { 2 , "Dense" },
    { 3 , "VeryDense" },
    { 4 , "Opaque" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityDensity()
{
	return sizeof( EntityDensityDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityDensity( KUINT32 Index )
{
	return &EntityDensityDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityDensity( KINT32 Value )
{
    return GetEnumAsString( EntityDensityDescriptor, sizeof( EntityDensityDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityDensity( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityDensityDescriptor, sizeof( EntityDensityDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityDensity()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityDensity( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityDensity( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityDensity( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityCompliance

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityComplianceDescriptor[] =
{
    { 1 , "Detained" },
    { 2 , "Surrender" },
    { 3 , "UsingFists" },
    { 4 , "VerbalAbuseLevel1" },
	{ 5 , "VerbalAbuseLevel2" },
	{ 6 , "VerbalAbuseLevel3" },
	{ 7 , "PassiveResistanceLevel1" },
	{ 8 , "PassiveResistanceLevel2" },
	{ 9 , "PassiveResistanceLevel3" },
	{ 10 , "UsingNonLethalWeapon1" },
	{ 11 , "UsingNonLethalWeapon2" },
	{ 12 , "UsingNonLethalWeapon3" },
	{ 13 , "UsingNonLethalWeapon4" },
	{ 14 , "UsingNonLethalWeapon5" },
	{ 15 , "UsingNonLethalWeapon6" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityCompliance()
{
	return sizeof( EntityComplianceDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityCompliance( KUINT32 Index )
{
	return &EntityComplianceDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityCompliance( KINT32 Value )
{
    return GetEnumAsString( EntityComplianceDescriptor, sizeof( EntityComplianceDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityCompliance( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityComplianceDescriptor, sizeof( EntityComplianceDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityCompliance()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityCompliance( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityCompliance( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityCompliance( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DeadReckoningAlgorithm

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DeadReckoningAlgorithmDescriptor[] =
{
    { 0 , "Other_DRA" },
    { 1 , "Static" },
    { 2 , "DRM_F_P_W" },
    { 3 , "DRM_R_P_W" },
    { 4 , "DRM_R_V_W" },
    { 5 , "DRM_F_V_W" },
    { 6 , "DRM_F_P_B" },
    { 7 , "DRM_R_P_B" },
    { 8 , "DRM_R_V_B" },
    { 9 , "DRM_F_V_B" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDeadReckoningAlgorithm()
{
	return sizeof( DeadReckoningAlgorithmDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDeadReckoningAlgorithm( KUINT32 Index )
{
	return &DeadReckoningAlgorithmDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDeadReckoningAlgorithm( KINT32 Value )
{
    return GetEnumAsString( DeadReckoningAlgorithmDescriptor, sizeof( DeadReckoningAlgorithmDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDeadReckoningAlgorithm( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DeadReckoningAlgorithmDescriptor, sizeof( DeadReckoningAlgorithmDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDeadReckoningAlgorithm()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDeadReckoningAlgorithm( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDeadReckoningAlgorithm( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDeadReckoningAlgorithm( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EntityMarkingCharacterSet

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EntityMarkingCharacterSetDescriptor[] =
{
    { 1 , "ASCII" },
    { 2 , "ArmyMarking" },
    { 3 , "DigitChevron" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityMarkingCharacterSet()
{
	return sizeof( EntityMarkingCharacterSetDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityMarkingCharacterSet( KUINT32 Index )
{
	return &EntityMarkingCharacterSetDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityMarkingCharacterSet( KINT32 Value )
{
    return GetEnumAsString( EntityMarkingCharacterSetDescriptor, sizeof( EntityMarkingCharacterSetDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityMarkingCharacterSet( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EntityMarkingCharacterSetDescriptor, sizeof( EntityMarkingCharacterSetDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEntityMarkingCharacterSet()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEntityMarkingCharacterSet( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEntityMarkingCharacterSet( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEntityMarkingCharacterSet( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ForceID

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ForceIDDescriptor[] =
{
    { 0 , "OtherForceID" },
    { 1 , "Friendly" },
    { 2 , "Opposing" },
    { 3 , "Neutral" },
    { 4 , "Friendly2" },
    { 5 , "Opposing2" },
    { 6 , "Neutral2" },
    { 7 , "Friendly3" },
    { 8 , "Opposing3" },
    { 9 , "Neutral3" },
    { 10 , "Friendly4" },
    { 11 , "Opposing4" },
    { 12 , "Neutral4" },
    { 13 , "Friendly5" },
    { 14 , "Opposing5" },
    { 15 , "Neutral5" },
    { 16 , "Friendly6" },
    { 17 , "Opposing6" },
    { 18 , "Neutral6" },
    { 19 , "Friendly7" },
    { 20 , "Opposing7" },
    { 21 , "Neutral7" },
    { 22 , "Friendly8" },
    { 23 , "Opposing8" },
    { 24 , "Neutral8" },
    { 25 , "Friendly9" },
    { 26 , "Opposing9" },
    { 27 , "Neutral9" },
    { 28 , "Friendly10" },
    { 29 , "Opposing10" },
    { 30 , "Neutral10" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeForceID()
{
	return sizeof( ForceIDDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorForceID( KUINT32 Index )
{
	return &ForceIDDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringForceID( KINT32 Value )
{
    return GetEnumAsString( ForceIDDescriptor, sizeof( ForceIDDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringForceID( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ForceIDDescriptor, sizeof( ForceIDDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeForceID()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorForceID( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringForceID( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringForceID( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ActionCode

#if DIS_VERSION > 6
#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ActionCodeDescriptor[] =
{
    { 1 , "PDUExtendingAnotherPDU" },
    { 2 , "PDUPartialStateUpdate" },
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActionCode()
{
	return sizeof( ActionCodeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActionCode( KUINT32 Index )
{
	return &ActionCodeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionCode( KINT32 Value )
{
    return GetEnumAsString( ActionCodeDescriptor, sizeof( ActionCodeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActionCode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ActionCodeDescriptor, sizeof( ActionCodeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActionCode()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActionCode( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionCode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActionCode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
#endif // DIS 7
