/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    EnumEntityInfoInteraction
    created:    17/09/2008
    author:     Karl Jones

    purpose:    Enums used for Entity Info Interaction PDUs
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Collision Type                                                       */
/* Contains collision type information                                  */
/* Used In:                                                             */
/*  Collision PDU                                                       */
/************************************************************************/

enum CollisionType
{
    ElasticCollision                                                  = 0,
    InelasticCollision                                                = 1,
    OtherCollision                                                    = 2
};

KString GetEnumAsStringCollisionType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringCollisionType( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Entity Type Fields                                                   */
/* Entity Type                                                          */
/* Used In:                                                             */
/*  Entity Type Data type                                               */
/************************************************************************/

enum EntityKind
{
    OtherKind                                                         = 0,
    Platform                                                          = 1,
    Munition                                                          = 2,
    Lifeform                                                          = 3,
    Environmental                                                     = 4,
    Culturalfeature                                                   = 5,
    Supply                                                            = 6,
    Radio                                                             = 7,
    Expendable                                                        = 8,
    SensorEmitter                                                     = 9
};

KString GetEnumAsStringEntityKind( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityKind( const KString & Value, KINT32 & ValueOut ); 

enum EntityDomain
{
    OtherDomain                                                       = 0,
    Land                                                              = 1,
    Air                                                               = 2,
    Surface                                                           = 3,
    Subsurface                                                        = 4,
    Space                                                             = 5
};

KString GetEnumAsStringEntityDomain( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityDomain( const KString & Value, KINT32 & ValueOut ); 

enum Country
{
    OtherCountry                                                      = 0,
    Afghanistan                                                       = 1,
    Argentina                                                         = 10,
    Indonesia                                                         = 100,
    Iran                                                              = 101,
    Iraq                                                              = 102,
    Ireland                                                           = 104,
    Israel                                                            = 105,
    Italy                                                             = 106,
    IvoryCoast                                                        = 107,
    Jamaica                                                           = 108,
    JanMayen_Norway                                                   = 109,
    Aruba                                                             = 11,
    Japan                                                             = 110,
    JarvisIsland_USA                                                  = 111,
    Jersey_UK                                                         = 112,
    JohnstonAtoll_USA                                                 = 113,
    Jordan                                                            = 114,
    JuanDeNovaIsland                                                  = 115,
    Kenya                                                             = 116,
    KingmanReef_USA                                                   = 117,
    Kiribati                                                          = 118,
    NorthKorea                                                        = 119,
    AshmoreAndCartierIslands_Australia                                = 12,
    SouthKorea                                                        = 120,
    Kuwait                                                            = 121,
    Laos                                                              = 122,
    Lebanon                                                           = 123,
    Lesotho                                                           = 124,
    Liberia                                                           = 125,
    Libya                                                             = 126,
    Liechtenstein                                                     = 127,
    Luxembourg                                                        = 128,
    Madagascar                                                        = 129,
    Australia                                                         = 13,
    Macau_Portugal                                                    = 130,
    Malawi                                                            = 131,
    Malaysia                                                          = 132,
    Maldives                                                          = 133,
    Mali                                                              = 134,
    Malta                                                             = 135,
    IsleOfMan_UK                                                      = 136,
    MarshallIslands                                                   = 137,
    Martinique_France                                                 = 138,
    Mauritania                                                        = 139,
    Austria                                                           = 14,
    Mauritius                                                         = 140,
    Mayotte_France                                                    = 141,
    Mexico                                                            = 142,
    Micronesia                                                        = 143,
    Monaco                                                            = 144,
    Mongolia                                                          = 145,
    Montserrat_UK                                                     = 146,
    Morocco                                                           = 147,
    Mozambique                                                        = 148,
    Namibia                                                           = 149,
    Bahamas                                                           = 15,
    Nauru                                                             = 150,
    NavassaIsland_USA                                                 = 151,
    Nepal                                                             = 152,
    Netherlands                                                       = 153,
    NetherlandsAntilles                                               = 154,
    NewCaledonia_France                                               = 155,
    NewZealand                                                        = 156,
    Nicaragua                                                         = 157,
    Niger                                                             = 158,
    Nigeria                                                           = 159,
    Bahrain                                                           = 16,
    Niue_NewZealand                                                   = 160,
    NorfolkIsland_Australia                                           = 161,
    NorthernMarianaIslands_USA                                        = 162,
    Norway                                                            = 163,
    Oman                                                              = 164,
    Pakistan                                                          = 165,
    PalmyraAtoll_USA                                                  = 166,
    Panama                                                            = 168,
    PapuaNewGuinea                                                    = 169,
    BakerIsland_USA                                                   = 17,
    ParacelIslands                                                    = 170,
    Paraguay                                                          = 171,
    Peru                                                              = 172,
    Philippines                                                       = 173,
    PitcairnIslands_UK                                                = 174,
    Poland                                                            = 175,
    Portugal                                                          = 176,
    PuertoRico_USA                                                    = 177,
    Qatar                                                             = 178,
    Reunion_France                                                    = 179,
    Bangladesh                                                        = 18,
    Romania                                                           = 180,
    Rwanda                                                            = 181,
    StKittsAndNevis                                                   = 182,
    StHelena_UK                                                       = 183,
    StLucia                                                           = 184,
    StPierreAndMiquelon_France                                        = 185,
    StVincentAndTheGrenadines                                         = 186,
    SanMarino                                                         = 187,
    SaoTomeAndPrincipe                                                = 188,
    SaudiArabia                                                       = 189,
    Barbados                                                          = 19,
    Senegal                                                           = 190,
    Seychelles                                                        = 191,
    SierraLeone                                                       = 192,
    Singapore                                                         = 193,
    SolomonIslands                                                    = 194,
    Somalia                                                           = 195,
    SouthGeorgiaAndTheSouthSandwichIslands_UK                         = 196,
    SouthAfrica                                                       = 197,
    Spain                                                             = 198,
    SpratlyIslands                                                    = 199,
    Albania                                                           = 2,
    BassasDaIndia_France                                              = 20,
    SriLanka                                                          = 200,
    Sudan                                                             = 201,
    Suriname                                                          = 202,
    Svalbard_Norway                                                   = 203,
    Swaziland                                                         = 204,
    Sweden                                                            = 205,
    Switzerland                                                       = 206,
    Syria                                                             = 207,
    Taiwan                                                            = 208,
    Tanzania                                                          = 209,
    Belgium                                                           = 21,
    Thailand                                                          = 210,
    Togo                                                              = 211,
    Tokelau_NewZealand                                                = 212,
    Tonga                                                             = 213,
    TrinidadAndTobago                                                 = 214,
    TromelinIsland_France                                             = 215,
    PacificIslands                                                    = 216,
    Tunisia                                                           = 217,
    Turkey                                                            = 218,
    TurksAndCaicosIslands_UK                                          = 219,
    Belize                                                            = 22,
    Tuvalu                                                            = 220,
    Uganda                                                            = 221,
    CommonwealthOfIndependentStates                                   = 222,
    UnitedArabEmirates                                                = 223,
    UnitedKingdom                                                     = 224,
    UnitedStates                                                      = 225,
    Uruguay                                                           = 226,
    Vanuatu                                                           = 227,
    VaticanCity                                                       = 228,
    Venezuela                                                         = 229,
    Benin                                                             = 23,
    Vietnam                                                           = 230,
    VirginIslands_USA                                                 = 231,
    WakeIsland_USA                                                    = 232,
    WallisAndFutuna_France                                            = 233,
    WesternSahara                                                     = 234,
    WestBank_Israel                                                   = 235,
    WesternSamoa                                                      = 236,
    Yemen                                                             = 237,
    Bermuda_UK                                                        = 24,
    Zaire                                                             = 241,
    Zambia                                                            = 242,
    Zimbabwe                                                          = 243,
    Armenia                                                           = 244,
    Azerbaijan                                                        = 245,
    Belarus                                                           = 246,
    BosniaAndHercegovina                                              = 247,
    ClippertonIsland_France                                           = 248,
    Croatia                                                           = 249,
    Bhutan                                                            = 25,
    Estonia                                                           = 250,
    Georgia                                                           = 251,
    Kazakhstan                                                        = 252,
    Kyrgyzstan                                                        = 253,
    Latvia                                                            = 254,
    Lithuania                                                         = 255,
    Macedonia                                                         = 256,
    MidwayIslands_USA                                                 = 257,
    Moldova                                                           = 258,
    Montenegro                                                        = 259,
    Bolivia                                                           = 26,
    Russia                                                            = 260,
    SerbiaAndMontenegro                                               = 261,
    Slovenia                                                          = 262,
    Tajikistan                                                        = 263,
    Turkmenistan                                                      = 264,
    Ukraine                                                           = 265,
    Uzbekistan                                                        = 266,
    Botswana                                                          = 27,
    BouvetIsland_Norway                                               = 28,
    Brazil                                                            = 29,
    Algeria                                                           = 3,
    BritishIndianOceanTerritory_UK                                    = 30,
    BritishVirginIslands_UK                                           = 31,
    Brunei                                                            = 32,
    Bulgaria                                                          = 33,
    Burkina                                                           = 34,
    Burma                                                             = 35,
    Burundi                                                           = 36,
    Cambodia                                                          = 37,
    Cameroon                                                          = 38,
    Canada                                                            = 39,
    AmericanSamoa_USA                                                 = 4,
    CapeVerde                                                         = 40,
    CaymanIslands_UK                                                  = 41,
    CentralAfricanRepublic                                            = 42,
    Chad                                                              = 43,
    Chile                                                             = 44,
    China                                                             = 45,
    ChristmasIsland_Australia                                         = 46,
    CocosIslands_Australia                                            = 47,
    Colombia                                                          = 48,
    Comoros                                                           = 49,
    Andorra                                                           = 5,
    Congo                                                             = 50,
    CookIslands_NewZealand                                            = 51,
    CoralSeaIslands_Australia                                         = 52,
    CostaRica                                                         = 53,
    Cuba                                                              = 54,
    Cyprus                                                            = 55,
    Czechoslovakia                                                    = 56,
    Denmark                                                           = 57,
    Djibouti                                                          = 58,
    Dominica                                                          = 59,
    Angola                                                            = 6,
    DominicanRepublic                                                 = 60,
    Ecuador                                                           = 61,
    Egypt                                                             = 62,
    ElSalvador                                                        = 63,
    EquatorialGuinea                                                  = 64,
    Ethiopia                                                          = 65,
    EuropaIsland_France                                               = 66,
    FalklandIslands_UK                                                = 67,
    FaroeIslands_Denmark                                              = 68,
    Fiji                                                              = 69,
    Anguilla                                                          = 7,
    Finland                                                           = 70,
    France                                                            = 71,
    FrenchGuiana_France                                               = 72,
    FrenchPolynesia_France                                            = 73,
    FrenchSouthernAndAntarcticIslands_France                          = 74,
    Gabon                                                             = 75,
    Gambia                                                            = 76,
    GazaStrip_Israel                                                  = 77,
    Germany                                                           = 78,
    Ghana                                                             = 79,
    Antarctica                                                        = 8,
    Gibraltar_UK                                                      = 80,
    GloriosoIslands_France                                            = 81,
    Greece                                                            = 82,
    Greenland_Denmark                                                 = 83,
    Grenada                                                           = 84,
    Guadaloupe_France                                                 = 85,
    Guam_USA                                                          = 86,
    Guatemala                                                         = 87,
    Guernsey_UK                                                       = 88,
    Guinea                                                            = 89,
    AntiguaAndBarbuda                                                 = 9,
    GuineaBissau                                                      = 90,
    Guyana                                                            = 91,
    Haiti                                                             = 92,
    HeardIslandAndMcDonaldIslands_Australia                           = 93,
    Honduras                                                          = 94,
    HongKong_UK                                                       = 95, // This was correct when DIS standard was published. Honk Kong is no longer part of the UK.
    HowlandIsland_USA                                                 = 96,
    Hungary                                                           = 97,
    Iceland                                                           = 98,
    India                                                             = 99
};

KString GetEnumAsStringCountry( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringCountry( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Articulation Params                                                  */
/* Contains articulation parameters                                     */
/* Used In:                                                             */
/*  Articulation Parameters                                             */
/************************************************************************/

enum ArticulationType
{
    ArticulatedPart                                                   = 0,
    AttachedPart                                                      = 1
};

KString GetEnumAsStringArticulationType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringArticulationType( const KString & Value, KINT32 & ValueOut ); 

enum ArticulatedPartsLowBits
{
    Position                                                          = 1,
    ZRate                                                             = 10,
    Azimuth                                                           = 11,
    AzimuthRate                                                       = 12,
    Elevation                                                         = 13,
    ElevationRate                                                     = 14,
    Rotation                                                          = 15,
    RotationRate                                                      = 16,
    PositionRate                                                      = 2,
    Extension                                                         = 3,
    ExtensionRate                                                     = 4,
    XValue                                                            = 5,
    XRate                                                             = 6,
    YValue                                                            = 7,
    YRate                                                             = 8,
    ZValue                                                            = 9
};

KString GetEnumAsStringArticulatedPartsLowBits( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringArticulatedPartsLowBits( const KString & Value, KINT32 & ValueOut ); 

enum ArticulatedPartsHighBits
{
    Rudder                                                            = 1024,
    LeftFlap                                                          = 1056,
    RightFlap                                                         = 1088,
    LeftAileron                                                       = 1120,
    RightAileron                                                      = 1152,
    HelicopterMainRotor                                               = 1184,
    HelicopterTailRotor                                               = 1216,
    OtherAircraftControlSurfaces                                      = 1248,
    Periscope                                                         = 2048,
    GenericAntenna                                                    = 2080,
    Snorkel                                                           = 2112,
    OtherExtendableParts                                              = 2144,
    LandingGear                                                       = 3072,
    TailHook                                                          = 3104,
    SpeedBrake                                                        = 3136,
    LeftWeaponBayDoor                                                 = 3168,
    RightWeaponBayDoors                                               = 3200,
    TankOrAPCHatch                                                    = 3232,
    Wingsweep                                                         = 3264,
    BridgeLauncher                                                    = 3296,
    BridgeSection1                                                    = 3328,
    BridgeSection2                                                    = 3360,
    BridgeSection3                                                    = 3392,
    PrimaryBlade1                                                     = 3424,
    PrimaryBlade2                                                     = 3456,
    PrimaryBoom                                                       = 3488,
    PrimaryLauncherArm                                                = 3520,
    OtherFixedPositionParts                                           = 3552,
    PrimaryTurretNumber1                                              = 4096,
    PrimaryTurretNumber2                                              = 4128,
    PrimaryTurretNumber3                                              = 4160,
    PrimaryTurretNumber4                                              = 4192,
    PrimaryTurretNumber5                                              = 4224,
    PrimaryTurretNumber6                                              = 4256,
    PrimaryTurretNumber7                                              = 4288,
    PrimaryTurretNumber8                                              = 4320,
    PrimaryTurretNumber9                                              = 4352,
    PrimaryTurretNumber10                                             = 4384,
    PrimaryGunNumber1                                                 = 4416,
    PrimaryGunNumber2                                                 = 4448,
    PrimaryGunNumber3                                                 = 4480,
    PrimaryGunNumber4                                                 = 4512,
    PrimaryGunNumber5                                                 = 4544,
    PrimaryGunNumber6                                                 = 4576,
    PrimaryGunNumber7                                                 = 4608,
    PrimaryGunNumber8                                                 = 4640,
    PrimaryGunNumber9                                                 = 4672,
    PrimaryGunNumber10                                                = 4704,
    PrimaryLauncher1                                                  = 4736,
    PrimaryLauncher2                                                  = 4768,
    PrimaryLauncher3                                                  = 4800,
    PrimaryLauncher4                                                  = 4832,
    PrimaryLauncher5                                                  = 4864,
    PrimaryLauncher6                                                  = 4896,
    PrimaryLauncher7                                                  = 4928,
    PrimaryLauncher8                                                  = 4960,
    PrimaryLauncher9                                                  = 4992,
    PrimaryLauncher10                                                 = 5024,
    PrimaryDefenseSystems1                                            = 5056,
    PrimaryDefenseSystems2                                            = 5088,
    PrimaryDefenseSystems3                                            = 5120,
    PrimaryDefenseSystems4                                            = 5152,
    PrimaryDefenseSystems5                                            = 5184,
    PrimaryDefenseSystems6                                            = 5216,
    PrimaryDefenseSystems7                                            = 5248,
    PrimaryDefenseSystems8                                            = 5280,
    PrimaryDefenseSystems9                                            = 5312,
    PrimaryDefenseSystems10                                           = 5344,
    PrimaryRadar1                                                     = 5376,
    PrimaryRadar2                                                     = 5408,
    PrimaryRadar3                                                     = 5440,
    PrimaryRadar4                                                     = 5472,
    PrimaryRadar5                                                     = 5504,
    PrimaryRadar6                                                     = 5536,
    PrimaryRadar7                                                     = 5568,
    PrimaryRadar8                                                     = 5600,
    PrimaryRadar9                                                     = 5632,
    PrimaryRadar10                                                    = 5664,
    SecondaryTurretNumber1                                            = 5696,
    SecondaryTurretNumber2                                            = 5728,
    SecondaryTurretNumber3                                            = 5760,
    SecondaryTurretNumber4                                            = 5792,
    SecondaryTurretNumber5                                            = 5824,
    SecondaryTurretNumber6                                            = 5856,
    SecondaryTurretNumber7                                            = 5888,
    SecondaryTurretNumber8                                            = 5920,
    SecondaryTurretNumber9                                            = 5952,
    SecondaryTurretNumber10                                           = 5984,
    SecondaryGunNumber1                                               = 6016,
    SecondaryGunNumber2                                               = 6048,
    SecondaryGunNumber3                                               = 6080,
    SecondaryGunNumber4                                               = 6112,
    SecondaryGunNumber5                                               = 6144,
    SecondaryGunNumber6                                               = 6176,
    SecondaryGunNumber7                                               = 6208,
    SecondaryGunNumber8                                               = 6240,
    SecondaryGunNumber9                                               = 6272,
    SecondaryGunNumber10                                              = 6304,
    SecondaryLauncher1                                                = 6336,
    SecondaryLauncher2                                                = 6368,
    SecondaryLauncher3                                                = 6400,
    SecondaryLauncher4                                                = 6432,
    SecondaryLauncher5                                                = 6464,
    SecondaryLauncher6                                                = 6496,
    SecondaryLauncher7                                                = 6528,
    SecondaryLauncher8                                                = 6560,
    SecondaryLauncher9                                                = 6592,
    SecondaryLauncher10                                               = 6624,
    SecondaryDefenseSystems1                                          = 6656,
    SecondaryDefenseSystems2                                          = 6688,
    SecondaryDefenseSystems3                                          = 6720,
    SecondaryDefenseSystems4                                          = 6752,
    SecondaryDefenseSystems5                                          = 6784,
    SecondaryDefenseSystems6                                          = 6816,
    SecondaryDefenseSystems7                                          = 6848,
    SecondaryDefenseSystems8                                          = 6880,
    SecondaryDefenseSystems9                                          = 6912,
    SecondaryDefenseSystems10                                         = 6944,
    SecondaryRadar1                                                   = 6976,
    SecondaryRadar2                                                   = 7008,
    SecondaryRadar3                                                   = 7040,
    SecondaryRadar4                                                   = 7072,
    SecondaryRadar5                                                   = 7104,
    SecondaryRadar6                                                   = 7136,
    SecondaryRadar7                                                   = 7168,
    SecondaryRadar8                                                   = 7200,
    SecondaryRadar9                                                   = 7232,
    SecondaryRadar10                                                  = 7264
};

KString GetEnumAsStringArticulatedPartsHighBits( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringArticulatedPartsHighBits( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* General Appearance Fields                                            */
/* Contains general appearance enums                                    */
/* Used In:                                                             */
/*  LandPlatformAppearance                                              */
/*  AirPlatformAppearance                                               */
/*  SurfacePlatformAppearance                                           */
/*  SubSurfacePlatformAppearance                                        */
/*  SpacePlatformAppearance                                             */
/*  GuidedMunitionsAppearance                                           */
/*  LifeFormAppearance                                                  */
/*  EnvironmentalsAppearance                                            */
/************************************************************************/

enum EntityPaintScheme
{
    UniformColor                                                      = 0,
    Camouflage                                                        = 1
};

KString GetEnumAsStringEntityPaintScheme( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityPaintScheme( const KString & Value, KINT32 & ValueOut ); 

enum EntityDamage
{
    NoDamage                                                          = 0,
    SlightDamage                                                      = 1,
    ModerateDamage                                                    = 2,
    Destroyed                                                         = 3
};

KString GetEnumAsStringEntityDamage( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityDamage( const KString & Value, KINT32 & ValueOut ); 

enum EntitySmoke
{
    NotSmoking                                                        = 0,
    SmokePlume                                                        = 1,
    EngineSmoke                                                       = 2,
    EngineSmokeAndSmokePlume                                          = 3
};

KString GetEnumAsStringEntitySmoke( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntitySmoke( const KString & Value, KINT32 & ValueOut ); 

enum EntityTrailingEffect
{
    NoTrail                                                           = 0,
    Small                                                             = 1,
    Medium                                                            = 2,
    Large                                                             = 3
};

KString GetEnumAsStringEntityTrailingEffect( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityTrailingEffect( const KString & Value, KINT32 & ValueOut ); 

enum EntityHatchState
{
    EntityHatchStateNotApplicable                                     = 0,
    PrimaryHatchIsClosed                                              = 1,
    PrimaryHatchIsPopped                                              = 2,
    PrimaryHatchIsPoppedPersonVisibleUnderHatch                       = 3,
    PrimaryHatchIsOpen                                                = 4,
    PrimaryHatchIsOpenPersonVisible                                   = 5
};

KString GetEnumAsStringEntityHatchState( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityHatchState( const KString & Value, KINT32 & ValueOut ); 

enum EntityLights
{
    NoLights                                                          = 0,
    RunningLightsOn                                                   = 1,
    NavigationLightsOn                                                = 2,
    FromationLightsOn                                                 = 3
};

KString GetEnumAsStringEntityLights( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityLights( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Specific Appearance Fields                                           */
/* Contains specific appearance enums                                   */
/* Used In:                                                             */
/*  LandPlatformAppearance                                              */
/*  AirPlatformAppearance                                               */
/*  SurfacePlatformAppearance                                           */
/*  SubSurfacePlatformAppearance                                        */
/*  SpacePlatformAppearance                                             */
/*  GuidedMunitionsAppearance                                           */
/*  LifeFormAppearance                                                  */
/*  EnvironmentalsAppearance                                            */
/************************************************************************/

enum EntityCamouflage
{
    DesertCamouflage                                                  = 0,
    WinterCamouflage                                                  = 1,
    ForestCamouflage                                                  = 2
};

KString GetEnumAsStringEntityCamouflage( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityCamouflage( const KString & Value, KINT32 & ValueOut ); 

enum EntityLifeformAppearance
{
    UprightStandingStill                                              = 1,
    UprightWalking                                                    = 2,
    UprightRunning                                                    = 3,
    Kneeling                                                          = 4,
    Prone                                                             = 5,
    Crawling                                                          = 6,
    Swimming                                                          = 7,
    Parachuting                                                       = 8,
    Jumping                                                           = 9,
    Sitting                                                           = 10,
    Squatting                                                         = 11,
    Crouching                                                         = 12,
    Wading                                                            = 13,
    SurrenderAppearance                                               = 14,
    DetainedAppearance                                                = 15
};

KString GetEnumAsStringEntityLifeformAppearance( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityLifeformAppearance( const KString & Value, KINT32 & ValueOut ); 

enum EntityLifeformWeapon
{
    NoPrimaryWeaponPresent                                            = 0,
    PrimaryWeaponIsStowed                                             = 1,
    PrimaryWeaponIsDeployed                                           = 2,
    PrimaryWeaponIsInTheFiringPosition                                = 3
};

KString GetEnumAsStringEntityLifeformWeapon( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityLifeformWeapon( const KString & Value, KINT32 & ValueOut ); 

enum EntityDensity
{
    Clear                                                             = 0,
    Hazy                                                              = 1,
    Dense                                                             = 2,
    VeryDense                                                         = 3,
    Opaque                                                            = 4
};

KString GetEnumAsStringEntityDensity( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityDensity( const KString & Value, KINT32 & ValueOut ); 

enum EntityCompliance
{
    Detained                                                          = 1,
    Surrender                                                         = 2,
    UsingFists                                                        = 3,
    VerbalAbuseLevel1                                                 = 4,
    VerbalAbuseLevel2                                                 = 5,
    VerbalAbuseLevel3                                                 = 6,
    PassiveResistanceLevel1                                           = 7,
	PassiveResistanceLevel2                                           = 8,
	PassiveResistanceLevel3                                           = 9,
	UsingNonLethalWeapon1                                             = 10,
	UsingNonLethalWeapon2                                             = 11,
	UsingNonLethalWeapon3                                             = 12,
	UsingNonLethalWeapon4                                             = 13,
	UsingNonLethalWeapon5                                             = 14,
	UsingNonLethalWeapon6                                             = 15
};

KString GetEnumAsStringEntityCompliance( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityCompliance( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Dead Reckoning Parameters                                            */
/* Dead Reckoning Algorithms consist of 3 elements.                     */
/*                                                                      */
/*  DRM_X_Y_Z                                                           */
/*  X - Specifies rotation as either fixed(F) or rotating(R).           */
/*  Y - Specifies dead reckoning rates to be held constant as either    */
/*      rate of position (P) or rate of velocity (V).                   */
/*  Z - Specifies the coordinate system as either world coordinates (W) */
/*      or body axis coordinates(B).                                    */
/*                                                                      */
/* F_P_W    -   Constant velocity (or low acceleration)linear motion    */
/* R_P_W    -   Similar to F_P_W but where orientation is required      */
/*              (e.g. visual simulation).                               */
/* R_V_W    -   Similar to F_V_W but where orientation is required      */
/*              (e.g. visual simulation).                               */
/* F_V_W    -   High speed or manoeuvring  at any speed (e.g. TBM,      */
/*              ICBM, SAM, SSM, and ASM weapons.                        */
/* F_P_B    -   Similar to R_P_W but when body-centred calculation is   */
/*              preferred.                                              */
/* R_P_B    -   Similar to R_V_W but when body-centred calculation is   */
/*              preferred.                                              */
/* R_V_B    -   Similar to F_V_W but when body-centred calculation is   */
/*              preferred.                                              */
/* F_V_B    -   Similar to F_P_B but when body-centred calculation is   */
/*              preferred.                                              */
/*                                                                      */
/* Used In:                                                             */
/*  Dead Reckoning Parameters Data type                                 */
/*  Designator PDU                                                      */
/************************************************************************/

enum DeadReckoningAlgorithm
{
    Other_DRA                                                         = 0,
    Static                                                            = 1,
    DRM_F_P_W                                                         = 2,
    DRM_R_P_W                                                         = 3,
    DRM_R_V_W                                                         = 4,
    DRM_F_V_W                                                         = 5,
    DRM_F_P_B                                                         = 6,
    DRM_R_P_B                                                         = 7,
    DRM_R_V_B                                                         = 8,
    DRM_F_V_B                                                         = 9
};

KString GetEnumAsStringDeadReckoningAlgorithm( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDeadReckoningAlgorithm( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Entity Marking Fields                                                */
/* Contains character set field                                         */
/* Used In:                                                             */
/*  Entity Marking                                                      */
/************************************************************************/

enum EntityMarkingCharacterSet
{
    ASCII                                                             = 1,
    ArmyMarking                                                       = 2,
    DigitChevron                                                      = 3
};

KString GetEnumAsStringEntityMarkingCharacterSet( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEntityMarkingCharacterSet( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Entity State enums                                                   */
/* Used In:                                                             */
/*  Entity State                                                        */
/*  Minefield State                                                     */
/************************************************************************/

enum ForceID
{
    OtherForceID                                                       = 0,
    Friendly                                                           = 1,
    Opposing                                                           = 2,
    Neutral                                                            = 3,
    Friendly2                                                          = 4,
    Opposing2                                                          = 5,
    Neutral2                                                           = 6,
    Friendly3                                                          = 7,
    Opposing3                                                          = 8,
    Neutral3                                                           = 9,
    Friendly4                                                          = 10,
    Opposing4                                                          = 11,
    Neutral4                                                           = 12,
    Friendly5                                                          = 13,
    Opposing5                                                          = 14,
    Neutral5                                                           = 15,
    Friendly6                                                          = 16,
    Opposing6                                                          = 17,
    Neutral6                                                           = 18,
    Friendly7                                                          = 19,
    Opposing7                                                          = 20,
    Neutral7                                                           = 21,
    Friendly8                                                          = 22,
    Opposing8                                                          = 23,
    Neutral8                                                           = 24,
    Friendly9                                                          = 25,
    Opposing9                                                          = 26,
    Neutral9                                                           = 27,
    Friendly10                                                         = 28,
    Opposing10                                                         = 29,
    Neutral10                                                          = 30
};

KString GetEnumAsStringForceID( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringForceID( const KString & Value, KINT32 & ValueOut ); 

#if DIS_VERSION > 6

/************************************************************************/
/* Action Code                                                          */
/* Action code applicable to all attribute records in a Attribute_PDU.  */
/* Used In:                                                             */
/*  Attribute_PDU                                                       */
/************************************************************************/

enum ActionCode
{
    PDUExtendingAnotherPDU                                            = 1,
	PDUPartialStateUpdate                                             = 2
};

KString GetEnumAsStringActionCode( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringActionCode( const KString & Value, KINT32 & ValueOut ); 

#endif // DIS 7


}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
