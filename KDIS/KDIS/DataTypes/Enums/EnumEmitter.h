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
    EnumEmitter
    created:    17/09/2008
    author:     Karl Jones

    purpose:    Enums for emitter params
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Emitter Name                                                         */
/* Emitter Name                                                         */
/* Used In:                                                             */
/*  Emitter System                                                      */
/************************************************************************/

enum EmitterName
{
    RL138                                                             = 10,
    DECCAMIL                                                          = 45,
    GR400                                                             = 80,
    GR600                                                             = 90,
    LV200TA                                                           = 135,
    LV200TV                                                           = 180,
    A310Z                                                             = 225,
    A325A                                                             = 270,
    A346Z                                                             = 315,
    A353B                                                             = 360,
    A372A                                                             = 405,
    A372B                                                             = 450,
    A372C                                                             = 495,
    A377A                                                             = 540,
    A377B                                                             = 585,
    A380Z                                                             = 630,
    A381Z                                                             = 675,
    A398Z                                                             = 720,
    A403Z                                                             = 765,
    A409A                                                             = 810,
    A418A                                                             = 855,
    A419Z                                                             = 900,
    A429Z                                                             = 945,
    A432Z                                                             = 990,
    A434Z                                                             = 1035,
    A401A                                                             = 1080,
    AA_12Seeker                                                       = 1095,
    Agave                                                             = 1100,
    AGRION15                                                          = 1125,
    AIMK23                                                            = 1170,
    AIDAII                                                            = 1215,
    AlbatrosMK2                                                       = 1260,
	L13_3_55G6_BoxSpring                                              = 1280,
	L13_3_55G6_BoxSpringB                                             = 1282,
    ANASPS502                                                         = 1305,
    ANRITSUElectricAR_30A                                             = 1350,
    AntilopeV                                                         = 1395,
    AN_ALE_50                                                         = 1400,
    AN_ALQ99                                                          = 1440,
    AN_ALQ_100                                                        = 1485,
    AN_ALQ_101                                                        = 1530,
    AN_ALQ_119                                                        = 1575,
    AN_ALQ_122                                                        = 1585,
    AN_ALQ_126A                                                       = 1620,
    AN_ALQ_131                                                        = 1626,
    AN_ALQ_135C_D                                                     = 1628,
    AN_ALQ_144A_V_3                                                   = 1630,
    AN_ALQ_153                                                        = 1632,
    AN_ALQ_155                                                        = 1634,
    AN_ALQ_161_A                                                      = 1636,
    AN_ALQ_162                                                        = 1638,
    AN_ALQ_165                                                        = 1640,
    AN_ALQ_167                                                        = 1642,
    AN_ALQ_172_V_2                                                    = 1644,
    AN_ALQ_176                                                        = 1646,
    AN_ALQ_184                                                        = 1648,
    AN_ALQ_188                                                        = 1650,
    AN_ALR_56                                                         = 1652,
    AN_ALR_69                                                         = 1654,
    AN_ALT_16A                                                        = 1656,
    AN_ALT_28                                                         = 1658,
    AN_ALT_32A                                                        = 1660,
    AN_APD10                                                          = 1665,
    AN_APG53                                                          = 1710,
    AN_APG59                                                          = 1755,
    AN_APG_63AB                                                       = 1800,
    AN_APG_63C                                                        = 1805,
    AN_APG65                                                          = 1845,
    AN_APG_66                                                         = 1870,
    AN_APG68                                                          = 1890,
    AN_APG70                                                          = 1935,
    AN_APG_73                                                         = 1945,
    AN_APG_77                                                         = 1960,
    AN_APG_78                                                         = 1970,
    AN_APG_502                                                        = 1980,
    AN_APN_1                                                          = 2025,
    AN_APN_22                                                         = 2070,
    AN_APN59                                                          = 2115,
    AN_APN_69                                                         = 2160,
    AN_APN_81                                                         = 2205,
    AN_APN_117                                                        = 2250,
    AN_APN_118                                                        = 2295,
    AN_APN_130                                                        = 2340,
    AN_APN_131                                                        = 2385,
    AN_APN_133                                                        = 2430,
    AN_APN_134                                                        = 2475,
    AN_APN_147                                                        = 2520,
    AN_APN_150                                                        = 2565,
    AN_APN_153                                                        = 2610,
    AN_APN154                                                         = 2655,
    AN_APN_155                                                        = 2700,
    AN_APN_159                                                        = 2745,
    AN_APN_182                                                        = 2790,
    AN_APN_187                                                        = 2835,
    AN_APN_190                                                        = 2880,
    AN_APN194                                                         = 2925,
    AN_APN_195                                                        = 2970,
    AN_APN_198                                                        = 3015,
    AN_APN_200                                                        = 3060,
    AN_APN202                                                         = 3105,
    AN_APN_217                                                        = 3150,
    AN_APN_218                                                        = 3152,
    AN_APN_238                                                        = 3160,
    AN_APN_239                                                        = 3162,
    AN_APN_241                                                        = 3164,
    AN_APN_242                                                        = 3166,
    AN_APN_506                                                        = 3195,
    AN_APQ_72                                                         = 3240,
    AN_APQ_99                                                         = 3285,
    AN_APQ100                                                         = 3330,
    AN_APQ_102                                                        = 3375,
    AN_APQ_109                                                        = 3420,
    AN_APQ113                                                         = 3465,
    AN_APQ120                                                         = 3510,
    AN_APQ126                                                         = 3555,
    AN_APQ_128                                                        = 3600,
    AN_APQ_129                                                        = 3645,
    AN_APQ148                                                         = 3690,
    AN_APQ_153                                                        = 3735,
    AN_APQ159                                                         = 3780,
    AN_APQ_164                                                        = 3785,
    AN_APQ_166                                                        = 3788,
    AN_APQ_181                                                        = 3795,
    AN_APS_31                                                         = 3820,
    AN_APS_42                                                         = 3825,
    AN_APS80                                                          = 3870,
    AN_APS_88                                                         = 3915,
    AN_APS115                                                         = 3960,
    AN_APS116                                                         = 4005,
    AN_APS_120                                                        = 4050,
    AN_APS121                                                         = 4095,
    AN_APS124                                                         = 4140,
    AN_APS125                                                         = 4185,
    AN_APS_128                                                        = 4230,
    AN_APS130                                                         = 4275,
    AN_APS133                                                         = 4320,
    AN_APS_134                                                        = 4365,
    AN_APS137                                                         = 4410,
    AN_APS_138                                                        = 4455,
    AN_APS_143_V_1                                                    = 4465,
    AN_APW22                                                          = 4500,
    AN_APW23                                                          = 4545,
    AN_APX_6                                                          = 4590,
    AN_APX7                                                           = 4635,
    AN_APX39                                                          = 4680,
    AN_APX_72                                                         = 4725,
    AN_APX76                                                          = 4770,
    AN_APX78                                                          = 4815,
    AN_APX101                                                         = 4860,
    AN_APX_113AIFF                                                    = 4870,
    AN_APY_1                                                          = 4900,
    AN_APY2                                                           = 4905,
    AN_APY3                                                           = 4950,
    AN_ARN21                                                          = 4995,
    AN_ARN52                                                          = 5040,
    AN_ARN84                                                          = 5085,
    AN_ARN118                                                         = 5130,
    AN_ARW73                                                          = 5175,
    AN_ASB1                                                           = 5220,
    AN_ASG21                                                          = 5265,
    AN_ASQ_108                                                        = 5280,
    AN_AWG9                                                           = 5310,
    AN_BPS_9                                                          = 5355,
    AN_BPS15                                                          = 5400,
    AN_BPS_16                                                         = 5405,
    AN_CRM_30                                                         = 5420,
    AN_DPW_23                                                         = 5430,
    AN_DSQ26PhoenixMH                                                 = 5445,
    AN_DSQ28HarpoonMH                                                 = 5490,
    AN_FPN_40                                                         = 5495,
    AN_FPN_62                                                         = 5500,
    AN_FPS_16                                                         = 5505,
    AN_FPS_18                                                         = 5507,
    AN_FPS_117                                                        = 5510,
    AN_FPS_20R                                                        = 5515,
    AN_FPS_77                                                         = 5520,
    AN_FPS_103                                                        = 5525,
    AN_GPN_12                                                         = 5527,
    AN_GPX_6                                                          = 5530,
    AN_GPX8                                                           = 5535,
    AN_GRN_12                                                         = 5537,
    AN_MPQ_10                                                         = 5540,
    AN_MPQ_46_HPI_ILL                                                 = 5545,
    AN_MPQ_48_55CWAR                                                  = 5550,
    AN_MPQ_49                                                         = 5551,
    AN_MPQ_50_PAR_TA                                                  = 5555,
    AN_MPQ_51_ROR_TT                                                  = 5560,
    AN_MPQ_53                                                         = 5570,
    AN_MPQ_64                                                         = 5575,
    AN_SPG_34                                                         = 5580,
    AN_SPG50                                                          = 5625,
    AN_SPG51                                                          = 5670,
    AN_SPG_51CWITI                                                    = 5715,
    AN_SPG_51FC                                                       = 5760,
    AN_SPG52                                                          = 5805,
    AN_SPG_53                                                         = 5850,
    AN_SPG55B                                                         = 5895,
    AN_SPG60                                                          = 5940,
    AN_SPG62                                                          = 5985,
    AN_SPN35                                                          = 6030,
    AN_SPN43                                                          = 6075,
    AN_SPQ_2                                                          = 6120,
    AN_SPQ9                                                           = 6165,
    AN_SPS_4                                                          = 6210,
    AN_SPS_5                                                          = 6255,
    AN_SPS_5C                                                         = 6300,
    AN_SPS_6                                                          = 6345,
    AN_SPS10                                                          = 6390,
    AN_SPS21                                                          = 6435,
    AN_SPS_28                                                         = 6480,
    AN_SPS_37                                                         = 6525,
    AN_SPS_39A                                                        = 6570,
    AN_SPS40                                                          = 6615,
    AN_SPS_41                                                         = 6660,
    AN_SPS48                                                          = 6705,
    AN_SPS_48C                                                        = 6750,
    AN_SPS49                                                          = 6795,
    AN_SPS52                                                          = 6840,
    AN_SPS53                                                          = 6885,
    AN_SPS55                                                          = 6930,
    AN_SPS_55SS                                                       = 6975,
    AN_SPS_58                                                         = 7020,
    AN_SPS59                                                          = 7065,
    AN_SPS64                                                          = 7110,
    AN_SPS65                                                          = 7155,
    AN_SPS67                                                          = 7200,
    AN_SPY1                                                           = 7245,
    AN_SPY_1A                                                         = 7250,
    AN_TPN_17                                                         = 7270,
    AN_TPN_24                                                         = 7275,
    AN_TPQ_18                                                         = 7280,
    AN_TPQ_36                                                         = 7295,
    AN_TPQ_37                                                         = 7300,
    AN_TPQ_38_V8_                                                     = 7301,
    AN_TPQ_47                                                         = 7303,
    AN_TPS_43                                                         = 7305,
    AN_TPS_43E                                                        = 7310,
    AN_TPS_59                                                         = 7315,
    AN_TPS_63                                                         = 7320,
    AN_TPS_70_V_1                                                     = 7322,
    AN_TPS_75                                                         = 7325,
    AN_TPX_46_V_7                                                     = 7330,
    AN_ULQ_6A                                                         = 7335,
    AN_UPN25                                                          = 7380,
    AN_UPS1                                                           = 7425,
    AN_UPS_2                                                          = 7426,
    AN_UPX1                                                           = 7470,
    AN_UPX5                                                           = 7515,
    AN_UPX11                                                          = 7560,
    AN_UPX12                                                          = 7605,
    AN_UPX17                                                          = 7650,
    AN_UPX23                                                          = 7695,
    AN_VPS2                                                           = 7740,
    ApelcoAD77                                                        = 7785,
    APG71                                                             = 7830,
    APN148                                                            = 7875,
    APN227                                                            = 7920,
    _deleted_                                                         = 7965,
    _deleted_1                                                        = 8010,
    _deleted_2                                                        = 8055,
    APS504V3                                                          = 8100,
    AR3D                                                              = 8105,
    AR320                                                             = 8115,
    AR327                                                             = 8120,
    ARM31                                                             = 8145,
    ARI5954                                                           = 8190,
    ARI5955                                                           = 8235,
    ARI5979                                                           = 8280,
    ARINC564BNDX_KINGRDR1E                                            = 8325,
    ARINC700BNDX_KINGRDR1E                                            = 8370,
    ARK_1                                                             = 8375,
    ARSR_3                                                            = 8380,
    ARSR_18                                                           = 8390,
    AS2Kipper                                                         = 8415,
    AS2KipperMH                                                       = 8460,
    AS4Kitchen                                                        = 8505,
    AS4KitchenMH                                                      = 8550,
    AS5KeltMH                                                         = 8595,
    AS6KingfishMH                                                     = 8640,
    AS7Kerry                                                          = 8685,
    AS7KerryMG                                                        = 8730,
    AS15KENTaltimeter                                                 = 8735,
    AspideAAM_SAMILL                                                  = 8760,
    ASRO                                                              = 8775,
    ASR_5                                                             = 8780,
    ASR_8                                                             = 8785,
    ASR_9                                                             = 8790,
    AT2SwatterMG                                                      = 8820,
    ATCR_33                                                           = 8840,
    ATCR33K_M                                                         = 8845,
    AtlasElektronkTRSN                                                = 8865,
    ATLAS_9740VTS                                                     = 8870,
    AVG65                                                             = 8910,
    AVH7                                                              = 8955,
    AVQ20                                                             = 9000,
    AVQ30X                                                            = 9045,
    AVQ_50_RCA_                                                       = 9075,
    AVQ70                                                             = 9090,
    AWS5                                                              = 9135,
    AWS6                                                              = 9180,
    B597Z                                                             = 9200,
    B636Z                                                             = 9205,
    BackNetAB                                                         = 9225,
    BackTrap                                                          = 9270,
    BALTYK                                                            = 9310,
    BallEnd                                                           = 9315,
    BallGun                                                           = 9360,
    BandStand                                                         = 9405,
    P_35_37_A_P_50_B_BarLock                                          = 9450,
    BassTilt                                                          = 9495,
    Beacon                                                            = 9540,
    BeanSticks                                                        = 9585,
    BeeHind                                                           = 9630,
    BellCrownA                                                        = 9640,
    BellCrownB                                                        = 9642,
    BIGBACK                                                           = 9645,
    BigBird                                                           = 9660,
    BigBulge                                                          = 9675,
    BigBulgeA                                                         = 9720,
    BigBulgeB                                                         = 9765,
    SNAR_10BigFred                                                    = 9780,
    BigMesh                                                           = 9810,
    BigNet                                                            = 9855,
    S15MTBillBoard                                                    = 98859,
    BillFold                                                          = 9900,
    BlowpipeMG                                                        = 9905,
    BlueFoxSeaHarrierFRSMk1_5                                         = 9930,
    BlueVixenSeaHarrierF_AMk2                                         = 9935,
    BlueSilk                                                          = 9945,
    BlueParrot                                                        = 9990,
    BlueOrchid                                                        = 10035,
    BoatSail                                                          = 10080,
    BoforsElectronic9LV331                                            = 10125,
    BoforsEricssonSeaGiraffe50HC                                      = 10170,
    BowlMesh                                                          = 10215,
    BoxBrick                                                          = 10260,
    BoxTail                                                           = 10305,
    BPS11A                                                            = 10350,
    BPS14                                                             = 10395,
    BPS15A                                                            = 10440,
    BR_15TokyoKEIKI                                                   = 10485,
    BRIDGEMASTE                                                       = 10510,
    BreadBin                                                          = 10530,
    BT271                                                             = 10575,
    BX732                                                             = 10620,
    BuzzStand                                                         = 10665,
    C5AMultiModeRadar                                                 = 10710,
    Caiman                                                            = 10755,
    CakeStand                                                         = 10800,
    CalypsoC61                                                        = 10845,
    CalypsoIi                                                         = 10890,
    CardionCoastal                                                    = 10895,
    CastorIi                                                          = 10935,
    Castor2JTT_CrotaleNG_                                             = 10940,
    CatHouse                                                          = 10980,
    CDR_431                                                           = 10985,
    ChairBackTT                                                       = 11000,
    ChairBackILL                                                      = 11010,
    CheeseBrick                                                       = 11025,
    ClamPipe                                                          = 11070,
    Clamshell                                                         = 11115,
    CollinsWXR_700X                                                   = 11160,
    CollinsDN101                                                      = 11205,
    ContravesSeaHunterMK4                                             = 11250,
    CornCan                                                           = 11260,
    CR_105RMCA                                                        = 11270,
    CrossBird                                                         = 11295,
    CrossDome                                                         = 11340,
    CrossLegs                                                         = 11385,
    CrossOut                                                          = 11430,
    CrossSlot                                                         = 11475,
    CrossSword                                                        = 11520,
    CrossUp                                                           = 11565,
    CrossSwordFC                                                      = 11610,
    CrotaleAcquisitionTATHD_5000                                      = 11655,
    CrotaleNGTAGriffon                                                = 11660,
    CrotaleTT                                                         = 11665,
    CrotaleMGMissileSystem                                            = 11700,
    CSSC3CCAS1M1M2MH                                                  = 11745,
    CSSC2BHY1AMH                                                      = 11790,
    CWS2                                                              = 11835,
    CylinderHead                                                      = 11880,
    CyranoII                                                          = 11925,
    CyranoIV                                                          = 11970,
    CyranoIV_M                                                        = 11975,
    DA_01_00                                                          = 12010,
    DA0500                                                            = 12015,
    Dawn                                                              = 12060,
    DeadDuck                                                          = 12105,
    DECCA_20V90_9                                                     = 12110,
    DECCA_20V90S                                                      = 12111,
    DECCA45                                                           = 12150,
    DECCA50                                                           = 12195,
    DECCA110                                                          = 12240,
    DECCA170                                                          = 12285,
    DECCA202                                                          = 12330,
    DECCAD202                                                         = 12375,
    DECCA303                                                          = 12420,
    DECCA535                                                          = 12430,
    DECCA626                                                          = 12465,
    DECCA629                                                          = 12510,
    DECCA914                                                          = 12555,
    DECCA916                                                          = 12600,
    DECCA926                                                          = 12610,
    DECCA1226Commercial                                               = 12645,
    DECCA1626                                                         = 12690,
    DECCA2459                                                         = 12735,
    DECCAAWS1                                                         = 12780,
    DECCAAWS2                                                         = 12782,
    DECCAAWS4                                                         = 12785,
    DECCAAWS_4_2_                                                     = 12787,
    DECCAMAR                                                          = 12800,
    DECCARM326                                                        = 12805,
    DECCARM416                                                        = 12825,
    DECCARM914                                                        = 12870,
    DECCARM1690                                                       = 12915,
    DECCASuper101MK3                                                  = 12960,
    DISS1                                                             = 13005,
    RapierTTDN181DN181                                                = 13050,
    Rapier2000TTBLINDFIREFSCTT                                        = 13055,
    DogEar                                                            = 13095,
    DogHouse                                                          = 13140,
    Don2                                                              = 13185,
    DonA_B_2_Kay                                                      = 13230,
    Donets                                                            = 13275,
    DownBeat                                                          = 13320,
    DRAA2A                                                            = 13365,
    DRAA2B                                                            = 13410,
    DRAC39                                                            = 13455,
    DRBC30B                                                           = 13500,
    DRBC31A                                                           = 13545,
    DRBC32A                                                           = 13590,
    DRBC32D                                                           = 13635,
    DRBC33A                                                           = 13680,
    DRBI10                                                            = 13725,
    DRBI23                                                            = 13770,
    DRBJ11B                                                           = 13815,
    DRBN30                                                            = 13860,
    DRBN32                                                            = 13905,
    DRBR51                                                            = 13950,
    DRBV20B                                                           = 13995,
    DRBV22                                                            = 14040,
    DRBV26C                                                           = 14085,
    DRBV30                                                            = 14130,
    DRBV50                                                            = 14175,
    DRBV51                                                            = 14220,
    DRBV51A                                                           = 14265,
    DRBV51B                                                           = 14310,
    DRBV51C                                                           = 14355,
    DropKick                                                          = 14400,
    DRUA31                                                            = 14445,
    DrumTilt                                                          = 14490,
    DrumTiltA                                                         = 14535,
    DrumTiltB                                                         = 14545,
    Dumbo                                                             = 14580,
    ECR_90                                                            = 14600,
    EggCupA_B                                                         = 14625,
    EKCO190                                                           = 14670,
    ELM2001B                                                          = 14715,
    ELM2207                                                           = 14760,
    EL_M2216_V_                                                       = 14770,
    ELTAEL_M2221GMSTGR                                                = 14805,
    ELTASIS                                                           = 14810,
    EMD2900                                                           = 14850,
    EndTray                                                           = 14895,
    Exocet1                                                           = 14940,
    Exocet1MH                                                         = 14985,
    Exocet2                                                           = 15030,
    EyeBowl                                                           = 15075,
    EyeShield                                                         = 15120,
    F332Z                                                             = 15140,
    FALCON                                                            = 15160,
    FanSongA                                                          = 15165,
    FanSongB_FTA                                                      = 15200,
    FanSongB_FTT                                                      = 15210,
    FanSongC_ETA                                                      = 15220,
    FanSongC_ETT                                                      = 15230,
    FanSongC_EMG                                                      = 15240,
    FanSongB_FFMG                                                     = 15255,
    FanTail                                                           = 15300,
    FCR_1401                                                          = 15310,
    FinCurve                                                          = 15345,
    FireCan                                                           = 15390,
    FireDish                                                          = 15435,
    FireDomeTA                                                        = 15470,
    FireDomeTT                                                        = 15475,
    FireDomeTI                                                        = 15480,
    FireIron                                                          = 15525,
    FireWheel                                                         = 15570,
    FishBowl                                                          = 15615,
    FlapLid                                                           = 15660,
    FlapTruck                                                         = 15705,
    FlapWheel                                                         = 15750,
    FlashDance                                                        = 15795,
    P_15FlatFaceABCD                                                  = 15840,
    FlatScreen                                                        = 15885,
    FlatSpin                                                          = 15930,
    FlatTwin                                                          = 15975,
    Fledermaus                                                        = 16020,
    FLYCATCHER                                                        = 16030,
    FlyScreen                                                         = 16065,
    FlyScreenAB                                                       = 16110,
    FlyTrapB                                                          = 16155,
    FogLampMG                                                         = 16200,
    FogLampTT                                                         = 16245,
    FoilTwo                                                           = 16290,
    FoxHunter                                                         = 16335,
    FOXFIREFoxFireAL                                                  = 16380,
    FOXFIREILL                                                        = 16390,
    FR_151A                                                           = 16400,
    FR_1505DA                                                         = 16410,
    FR_2000                                                           = 16420,
    FR_2855W                                                          = 16421,
    FrontDome                                                         = 16425,
    FrontDoor                                                         = 16470,
    FrontPiece                                                        = 16515,
    Furuno                                                            = 16560,
    Furuno701                                                         = 16605,
    Furuno7112                                                        = 16650,
    Furuno2400                                                        = 16695,
    GA0100                                                            = 16740,
    Gage                                                              = 16785,
    Garpin                                                            = 16830,
    GEMBX132                                                          = 16875,
    MPDR_12GepardTA                                                   = 16880,
    GepardTT                                                          = 16884,
    GERAN_F                                                           = 16888,
    GIRAFFE                                                           = 16900,
    GinSlingTA                                                        = 16915,
    GinSlingGinSlingTT                                                = 16920,
    GinSlingMG                                                        = 16925,
    GPN_22                                                            = 16945,
    GRN_9                                                             = 16950,
    GreenStain                                                        = 16965,
    GridBow                                                           = 17010,
    S32GRILLPANTT                                                     = 170259,
    Guardsman                                                         = 17055,
    RPK_2GUNDISH_ZSU_23_4_                                            = 17070,
    HairNet                                                           = 17100,
    HalfPlateA                                                        = 17145,
    HalfPlateB                                                        = 17190,
    HARD                                                              = 17220,
    HawkScreech                                                       = 17235,
    HeadLightA                                                        = 17280,
    HeadLights                                                        = 17325,
    HeadLightsC                                                       = 17370,
    HeadLightsMGA                                                     = 17415,
    HeadLightsMGB                                                     = 17460,
    HeadLightsTT                                                      = 17505,
    HeadNet                                                           = 17550,
    HenEgg                                                            = 17595,
    HenHouse                                                          = 17640,
    HenNest                                                           = 17685,
    HenRoost                                                          = 17730,
    HighBrick                                                         = 17775,
    HighFix                                                           = 17820,
    HighLarkTI                                                        = 17865,
    HighLark1                                                         = 17910,
    HighLark2                                                         = 17955,
    HighLark4                                                         = 18000,
    HighLune                                                          = 18045,
    HighPoleAB                                                        = 18090,
    HighScoop                                                         = 18135,
    S19MTHIGHSCREEN                                                   = 181509,
    HighSieve                                                         = 18180,
    HN_503                                                            = 18200,
    HomeTalk                                                          = 18225,
    HornSpoon                                                         = 18270,
    HOTBRICK                                                          = 18280,
    HotFlash                                                          = 18315,
    IRL144MHotShotTA                                                  = 18320,
    IRL144MHotShotTT                                                  = 18325,
    IRL144MHotShotMG                                                  = 18330,
    IFFMKXIIAIMSUPX29                                                 = 18360,
    IFFMKXV                                                           = 18405,
    JavelinMG                                                         = 18410,
    JayBird                                                           = 18450,
    JRC_NMD_401                                                       = 18460,
    Jupiter                                                           = 18495,
    JupiterII                                                         = 18540,
    JY_8                                                              = 18550,
    JY_9                                                              = 18555,
    JY_14                                                             = 18560,
    K376Z                                                             = 18585,
    KelvinHughes2A                                                    = 18630,
    KelvinHughes14_9                                                  = 18675,
    KelvinHughestype1006                                              = 18720,
    KelvinHughestype1007                                              = 18765,
    KH_902M                                                           = 18785,
    KiteScreech                                                       = 18810,
    KiteScreechA                                                      = 18855,
    KiteScreechB                                                      = 18900,
    Kivach                                                            = 18945,
    KnifeRest                                                         = 18990,
    P_10KnifeRestB                                                    = 19035,
    KNIFERESTC                                                        = 19037,
    KR_75                                                             = 19050,
    KSASRN                                                            = 19080,
    KSATSR                                                            = 19125,
    LandFall                                                          = 19170,
    LandRollMG                                                        = 19215,
    LandRollTA                                                        = 19260,
    LandRollTT                                                        = 19305,
    LC_150                                                            = 19310,
    Leningraf                                                         = 19350,
    LightBulb                                                         = 19395,
    LMTNRAI_6A                                                        = 19400,
    LN55                                                              = 19440,
    Ln66                                                              = 19485,
    LongBow                                                           = 19530,
    LongBrick                                                         = 19575,
    LongBull                                                          = 19620,
    LongEye                                                           = 19665,
    LongHead                                                          = 19710,
    LongTalk                                                          = 19755,
    LongTrack                                                         = 19800,
    LongTrough                                                        = 19845,
    LookTwo                                                           = 19890,
    LORAN                                                             = 19935,
    LowBlowTA                                                         = 19950,
    LowBlowTT                                                         = 19955,
    LowBlowMG                                                         = 19960,
    LowSieve                                                          = 19980,
    LowTrough                                                         = 20025,
    TRS_2050LP_23                                                     = 20040,
    LW08                                                              = 20070,
    M_1983FCR                                                         = 20090,
    M22_40                                                            = 20115,
    M44                                                               = 20160,
    M401Z                                                             = 20205,
    M585Z                                                             = 20250,
    M588Z                                                             = 20295,
    MA1IFFPortion                                                     = 20340,
    MARELD                                                            = 20360,
    MAType909                                                         = 20385,
    Marconi1810                                                       = 20430,
    MarconiCanadaHC75                                                 = 20475,
    MarconiS713                                                       = 20495,
    MarconiS1802                                                      = 20520,
    MarconiS247                                                       = 20530,
    MarconiS810                                                       = 20565,
    MarconiSA10                                                       = 20585,
    Marconitype967                                                    = 20610,
    Marconitype968                                                    = 20655,
    Marconitype992                                                    = 20700,
    Marconi_signaaltype1022                                           = 20745,
    Marconi_signaaltype910                                            = 20790,
    Marconi_signaaltype911                                            = 20835,
    Marconi_signaaltype992R                                           = 20880,
    MeshBrick                                                         = 20925,
    MirageILL                                                         = 20950,
    MK15CIWS                                                          = 20970,
    MK_23                                                             = 21015,
    MK23TAS                                                           = 21060,
    MK25                                                              = 21105,
    MK_35M2                                                           = 21150,
    MK92                                                              = 21195,
    MK_92CAS                                                          = 21240,
    MK_92STIR                                                         = 21285,
    MK95                                                              = 21330,
    MLA_1                                                             = 21340,
    MMAPS705                                                          = 21375,
    MMSPG74                                                           = 21420,
    MMSPG75                                                           = 21465,
    MMSPN703                                                          = 21490,
    MMSPS702                                                          = 21510,
    MMSPS768                                                          = 21555,
    MMSPS774                                                          = 21600,
    Moon4                                                             = 21645,
    MMRS                                                              = 21650,
    MPDR18X                                                           = 21690,
    MT_305X                                                           = 21710,
    MuffCob                                                           = 21735,
    Mushroom                                                          = 21780,
    Mushroom1                                                         = 21825,
    Mushroom2                                                         = 21870,
    N920Z                                                             = 21880,
    NanjingB                                                          = 21890,
    NanjingC                                                          = 21895,
    Nayada                                                            = 21915,
    Neptun                                                            = 21960,
    NIKETT                                                            = 21980,
    NRBA50                                                            = 22005,
    NRBA51                                                            = 22050,
    NRBF20A                                                           = 22095,
    NysaB                                                             = 22140,
    O524A                                                             = 22185,
    O580B                                                             = 22230,
    O625Z                                                             = 22275,
    O626Z                                                             = 22320,
    OddGroup                                                          = 22345,
    OddLot                                                            = 22365,
    OddPair                                                           = 22410,
    Oka                                                               = 22455,
    OKEAN                                                             = 22500,
    OKINXE12C                                                         = 22545,
    OMEGA                                                             = 22590,
    OmeraORB32                                                        = 22635,
    OneEye                                                            = 22680,
    OP_28                                                             = 22690,
    OPS_16B                                                           = 22725,
    OPS_18                                                            = 22730,
    OPS_28                                                            = 22740,
    OR_2                                                              = 22770,
    ORB_31S                                                           = 22810,
    ORB32                                                             = 22815,
    OrionRtn10X                                                       = 22860,
    OtomatMKIITeseo                                                   = 22905,
    OwlScreech                                                        = 22950,
    P360Z                                                             = 22955,
    PA_1660                                                           = 22960,
    PalmFrond                                                         = 22995,
    PalmFrondAB                                                       = 23040,
    PatHandTT                                                         = 23085,
    PatHandMG                                                         = 23095,
    PattyCake                                                         = 23130,
    PawnCake                                                          = 23175,
    PBR4Rubin                                                         = 23220,
    PeaSticks                                                         = 23265,
    PeelCone                                                          = 23310,
    PeelGroup                                                         = 23355,
    PeelGroupA                                                        = 23400,
    PeelGroupB                                                        = 23445,
    PeelPair                                                          = 23490,
    Philips9LV200                                                     = 23535,
    Philips9LV331                                                     = 23580,
    PhilipsLV223                                                      = 23625,
    PhilipsSeaGiraffe50HC                                             = 23670,
    PinJib                                                            = 23690,
    PlankShad                                                         = 23710,
    PlankShave                                                        = 23715,
    PlankShaveA                                                       = 23760,
    PlankShaveB                                                       = 23805,
    PlateSteer                                                        = 23850,
    PlesseyAWS1                                                       = 23895,
    PlesseyAWS4                                                       = 23940,
    PlesseyAWS6                                                       = 23985,
    PlesseyRJ                                                         = 23990,
    Plesseytype996                                                    = 24030,
    PlinthNet                                                         = 24075,
    Pluto                                                             = 24095,
    POHJANPALO                                                        = 24100,
    POLLUX                                                            = 24120,
    PopGroup                                                          = 24165,
    PopGroupMG                                                        = 24210,
    PopGroupTA                                                        = 24255,
    PopGroupTT                                                        = 24300,
    PorkTrough                                                        = 24345,
    PostBow                                                           = 24390,
    PostLamp                                                          = 24435,
    PotDrum                                                           = 24480,
    PotHead                                                           = 24525,
    PRIMUS40WXD                                                       = 24570,
    PRIMUS300SL                                                       = 24615,
    Primus3000                                                        = 24620,
    PS_05A                                                            = 24650,
    PS46A                                                             = 24660,
    PS70R                                                             = 24705,
    PS_890                                                            = 24710,
    PuffBall                                                          = 24750,
    R_76                                                              = 24770,
    RAC_30                                                            = 24780,
    Racal1229                                                         = 24795,
    RacalAC2690BT                                                     = 24840,
    RacalDecca1216                                                    = 24885,
    RacalDecca360                                                     = 24930,
    RacalDeccaAC1290                                                  = 24975,
    RacalDeccaTM1229                                                  = 25020,
    RacalDeccaTM1626                                                  = 25065,
    RacalDRBN34A                                                      = 25110,
    Radar24                                                           = 25155,
    RAN7S                                                             = 25200,
    RAN10S                                                            = 25205,
    RAN11LX                                                           = 25245,
    RapierTA                                                          = 25260,
    Rapier2000TADagger                                                = 25265,
    RapierMG                                                          = 25270,
    RAT_31S                                                           = 25280,
    RATAC_LCT_                                                        = 25285,
    Raytheon1220                                                      = 25290,
    Raytheon1302                                                      = 25300,
    Raytheon1500                                                      = 25335,
    Raytheon1645                                                      = 25380,
    Raytheon1650                                                      = 25425,
    Raytheon1900                                                      = 25470,
    Raytheon2502                                                      = 25515,
    RaytheonTM1650_6X                                                 = 25560,
    RaytheonTM1660_12S                                                = 25605,
    RAY_1220XR                                                        = 25630,
    RAY_1401                                                          = 25635,
    Ray2900                                                           = 25650,
    Raypath                                                           = 25695,
    RBE2                                                              = 25735,
    RDM                                                               = 25740,
    RDY                                                               = 25760,
    RDN72                                                             = 25785,
    RDR1A                                                             = 25830,
    RDR1E                                                             = 25835,
    RDR4A                                                             = 25840,
    RDR1200                                                           = 25875,
    RDR1400                                                           = 25885,
    RDR1400C                                                          = 25890,
    RDR1500                                                           = 25895,
    RiceLamp                                                          = 25920,
    RicePad                                                           = 25965,
    RiceScreen                                                        = 26010,
    ROLANDBN                                                          = 26055,
    ROLANDMG                                                          = 26100,
    ROLANDTA                                                          = 26145,
    ROLANDTT                                                          = 26190,
    RoundBall                                                         = 26235,
    RoundHouse                                                        = 26280,
    RoundHouseB                                                       = 26325,
    RT_02_50                                                          = 26330,
    RTN_1A                                                            = 26350,
    RV2                                                               = 26370,
    RV3                                                               = 26415,
    RV5                                                               = 26460,
    RV10                                                              = 26505,
    RV17                                                              = 26550,
    RV18                                                              = 26595,
    RV_377                                                            = 26610,
    RVUM                                                              = 26640,
    RXN2_60                                                           = 26660,
    S_1810CD                                                          = 26670,
    SA2Guideline                                                      = 26685,
    SA3Goa                                                            = 26730,
    SA8GeckoDT                                                        = 26775,
    SA_12TELARILL                                                     = 26795,
    SAN7GadflyTI                                                      = 26820,
    SAN11Cads1UN                                                      = 26865,
    SaltPotAB                                                         = 26910,
    SATURNEII                                                         = 26955,
    ScanCan                                                           = 27000,
    ScanFix                                                           = 27045,
    ScanOdd                                                           = 27090,
    ScanThree                                                         = 27135,
    SCANTER_CSR_                                                      = 27140,
    SCORADS                                                           = 27141,
    SCOREBOARD                                                        = 27150,
    ScoupPlate                                                        = 27180,
    SCR_584                                                           = 27190,
    SeaArcher2                                                        = 27225,
    SeaHunter4MG                                                      = 27270,
    SeaHunter4TA                                                      = 27315,
    SeaHunter4TT                                                      = 27360,
    SeaGull                                                           = 27405,
    SeaNet                                                            = 27450,
    SeaSpray                                                          = 27495,
    SeaTiger                                                          = 27540,
    Searchwater                                                       = 27570,
    SeleniaOrion7                                                     = 27585,
    Seleniatype912                                                    = 27630,
    SelenniaRAN12L_X                                                  = 27675,
    SelenniaRTN10X                                                    = 27720,
    SeliniaARP1645                                                    = 27765,
    SGR10200                                                          = 27810,
    SGR103_02                                                         = 27855,
    SGR_104                                                           = 27870,
    SheetBend                                                         = 27900,
    SheetCurve                                                        = 27945,
    ShipGlobe                                                         = 27990,
    ShipWheel                                                         = 28035,
    SGR114                                                            = 28080,
    ShoreWalkA                                                        = 28125,
    ShortHorn                                                         = 28170,
    ShotDome                                                          = 28215,
    SideGlobeJN                                                       = 28260,
    PRV_11SideNet                                                     = 28280,
    SideWalkA                                                         = 28305,
    SignaalDA02                                                       = 28350,
    SignaalDA05                                                       = 28395,
    SignaalDA08                                                       = 28440,
    SignaalLW08                                                       = 28485,
    SignaalLWOR                                                       = 28530,
    SignaalM45                                                        = 28575,
    SignaalMW08                                                       = 28620,
    SignaalSMART                                                      = 28665,
    SignaalSTING                                                      = 28710,
    SignaalSTIR                                                       = 28755,
    SignaalWM20_2                                                     = 28800,
    SignaalWM25                                                       = 28845,
    SignaalWM27                                                       = 28890,
    SignaalWM28                                                       = 28935,
    SignaalZW01                                                       = 28980,
    SignaalZW06                                                       = 29025,
    SkiPole                                                           = 29070,
    SkinHead                                                          = 29115,
    SkipSpin                                                          = 29160,
    SKYGUARDTAUAR_1021                                                = 29185,
    SKYGUARDTTUAR_1021                                                = 29190,
    SkyWatch                                                          = 29205,
    SKYSHADOW                                                         = 29215,
    SKYSHIELDTA                                                       = 29220,
    SL                                                                = 29250,
    SL_ALQ_234                                                        = 29270,
    SlapShotE                                                         = 29295,
    SlimNet                                                           = 29340,
    SlotBackA                                                         = 29385,
    SlotBackILL                                                       = 29400,
    SlotBackB                                                         = 29430,
    SlotRest                                                          = 29440,
    SMA3RM                                                            = 29475,
    SMA3RM20                                                          = 29520,
    SMA3RM20A_SMG                                                     = 29565,
    SMABPS704                                                         = 29610,
    SMASPIN749_V_2                                                    = 29655,
    SMASPN703                                                         = 29700,
    SMASPN751                                                         = 29745,
    SMASPOS748                                                        = 29790,
    SMASPQ2                                                           = 29835,
    SMASPQ2D                                                          = 29880,
    SMASPQ701                                                         = 29925,
    SMASPS702UPX                                                      = 29970,
    SMAST2OTOMATIIMH                                                  = 30015,
    SMA718Beacon                                                      = 30060,
    SNAPSHOT                                                          = 30080,
    SnoopDrift                                                        = 30105,
    SnoopHead                                                         = 30150,
    SnoopPair                                                         = 30195,
    SnoopPlate                                                        = 30240,
    SnoopSlab                                                         = 30285,
    SnoopTray                                                         = 30330,
    SnoopTray1                                                        = 30375,
    SnoopTray2                                                        = 30420,
    SnoopWatch                                                        = 30465,
    S18M1SnowDrift                                                    = 304709,
    SO_1                                                              = 30510,
    SO_12                                                             = 30520,
    SOACommunist                                                      = 30555,
    SO_69                                                             = 30580,
    SockEye                                                           = 30600,
    SOM64                                                             = 30645,
    SPADATT                                                           = 30670,
    Sparrow_AIM_RIM_7_ILL                                             = 30690,
    SperryM_3                                                         = 30700,
    SPG53F                                                            = 30735,
    SPG70_RTN10X_                                                     = 30780,
    SPG74_RTN20X_                                                     = 30825,
    SPG75_RTN30X_                                                     = 30870,
    SPG76_RTN30X_                                                     = 30915,
    SpinScanA                                                         = 30960,
    SpinScanB                                                         = 31005,
    SpinTrough                                                        = 31050,
    SplashDrop                                                        = 31095,
    SPN35A                                                            = 31140,
    SPN41                                                             = 31185,
    SPN42                                                             = 31230,
    SPN43A                                                            = 31275,
    SPN43B                                                            = 31320,
    SPN44                                                             = 31365,
    SPN46                                                             = 31410,
    SPN703                                                            = 31455,
    SPN728_V_1                                                        = 31500,
    SPN748                                                            = 31545,
    SPN750                                                            = 31590,
    SpongeCake                                                        = 31635,
    P_12SpoonRest                                                     = 31680,
    SPQ712_RAN12L_X_                                                  = 31725,
    SPS6C                                                             = 31770,
    SPS10F                                                            = 31815,
    SPS12                                                             = 31860,
    _deleted_SPS58                                                    = 31905,
    _deleted_SPS64                                                    = 31950,
    SPS768_RANEL_                                                     = 31995,
    SPS774_RAN10S_                                                    = 32040,
    SPY790                                                            = 32085,
    SquareHead                                                        = 32130,
    SquarePair                                                        = 32175,
    SquareSlot                                                        = 32220,
    SquareTie                                                         = 32265,
    SquashDome                                                        = 32310,
    P_15MSquatEye                                                     = 32330,
    SquintEye                                                         = 32355,
    SRN6                                                              = 32400,
    SRN15                                                             = 32445,
    SRN745                                                            = 32490,
    SRO1                                                              = 32535,
    SRO2                                                              = 32580,
    SSC2BSamletMG                                                     = 32625,
    SSN2ABCSSC                                                        = 32670,
    SSN2ABCSSC2A3A2MH                                                 = 32715,
    SSN2CSeeker                                                       = 32760,
    SSN2CDStyx                                                        = 32805,
    SSN2CDStyxCDMH                                                    = 32850,
    SSN3SSCSSC18BN                                                    = 32895,
    SSN3BSepalAL                                                      = 32940,
    SSN3BSepalMH                                                      = 32985,
    SSN9Siren                                                         = 33030,
    SSN9SirenAL                                                       = 33075,
    SSN9SirenMH                                                       = 33120,
    SSN12SandboxAL                                                    = 33165,
    SSN12SandboxMH                                                    = 33210,
    SSN19Shipwreck                                                    = 33255,
    SSN19ShipwreckAL                                                  = 33300,
    SSN19ShipwreckMH                                                  = 33345,
    SSN21AL                                                           = 33390,
    SSN22Sunburn                                                      = 33435,
    SSN22SunburnMH                                                    = 33480,
    StoneCake                                                         = 33525,
    STR41                                                             = 33570,
    StraightFlushTA                                                   = 33590,
    StraightFlushTT                                                   = 33595,
    StraightFlushILL                                                  = 33600,
    StrikeOut                                                         = 33615,
    StrutCurve                                                        = 33660,
    StrutPair                                                         = 33705,
    StrutPair1                                                        = 33750,
    StrutPair2                                                        = 33795,
    SunVisor                                                          = 33840,
    Superfledermaus                                                   = 33860,
    SwiftRod1                                                         = 33885,
    SwiftRod2                                                         = 33930,
    T1166                                                             = 33975,
    T1171                                                             = 34020,
    T1202                                                             = 34040,
    T6004                                                             = 34065,
    T6031                                                             = 34110,
    T8067                                                             = 34155,
    T8068                                                             = 34200,
    T8124                                                             = 34245,
    T8408                                                             = 34290,
    T8911                                                             = 34335,
    T8937                                                             = 34380,
    T8944                                                             = 34425,
    T8987                                                             = 34470,
    P_14TallKing                                                      = 34515,
    TallMike                                                          = 34560,
    TallPath                                                          = 34605,
    TeamWork                                                          = 34625,
    THAADGBR                                                          = 34640,
    THD225                                                            = 34650,
    THD1940Picador                                                    = 34670,
    THD5500                                                           = 34695,
    ThinPath                                                          = 34740,
    PRV_9ThinSkin                                                     = 34785,
    ThompsonCSFTA_10                                                  = 34795,
    ThompsonCSFTHD1040Neptune                                         = 34830,
    ThompsonCSFCalypso                                                = 34875,
    ThompsonCSFCASTOR                                                 = 34920,
    ThompsonCSFCastorII                                               = 34965,
    ThompsonCSFDRBC32A                                                = 35010,
    ThompsonCSFDRBJ11D_E                                              = 35055,
    ThompsonCSFDRBV15A                                                = 35100,
    ThompsonCSFDRBV15C                                                = 35145,
    ThompsonCSFDRBV22D                                                = 35190,
    ThompsonCSFDRBV23B                                                = 35235,
    ThompsonCSFDRUA33                                                 = 35280,
    ThompsonCSFMarsDRBV21A                                            = 35325,
    ThompsonCSFSeaTiger                                               = 35370,
    ThompsonCSFTriton                                                 = 35415,
    ThompsonCSFVegawithDRBC32E                                        = 35460,
    TRS_2105TIGER_G                                                   = 35480,
    TRS_2100TIGER_S                                                   = 35490,
    TieRods                                                           = 35505,
    D6TinShield                                                       = 3555036,
    TinTrap                                                           = 35570,
    TIRSPONDER                                                        = 35580,
    ToadStool1                                                        = 35595,
    ToadStool2                                                        = 35640,
    ToadStool3                                                        = 35685,
    ToadStool4                                                        = 35730,
    ToadStool5                                                        = 35775,
    TombStone                                                         = 35800,
    TopBow                                                            = 35820,
    TopDome                                                           = 35865,
    TopKnot                                                           = 35910,
    TopMesh                                                           = 35955,
    TopPair                                                           = 36000,
    TopPlate                                                          = 36045,
    TopSail                                                           = 36090,
    TopSteer                                                          = 36135,
    TopTrough                                                         = 36180,
    ScrumHalfTA                                                       = 36220,
    TorScrumHalfTTTor                                                 = 36225,
    ScrumHalfMG                                                       = 36230,
    TrackDish                                                         = 36270,
    TORSOM                                                            = 36315,
    TrapDoor                                                          = 36360,
    TRISPONDE                                                         = 36380,
    TRS3033                                                           = 36405,
    TRS3405                                                           = 36420,
    TRS3410                                                           = 36425,
    TRS3415                                                           = 36430,
    TRS_N                                                             = 36450,
    TSE5000                                                           = 36495,
    TSR333                                                            = 36540,
    TubeArm                                                           = 36585,
    TwinEyes                                                          = 36630,
    TwinPill                                                          = 36675,
    TwinScan                                                          = 36720,
    TwinScanRo                                                        = 36765,
    TwoSpot                                                           = 36810,
    TYPE262                                                           = 36855,
    TYPE275                                                           = 36900,
    TYPE293                                                           = 36945,
    TYPE343SUNVISORB                                                  = 36990,
    TYPE347B                                                          = 37035,
    Type_404A_CH_                                                     = 37050,
    Type756                                                           = 37080,
    TYPE903                                                           = 37125,
    TYPE909TI                                                         = 37170,
    TYPE909TT                                                         = 37215,
    TYPE910                                                           = 37260,
    TYPE_931_CH_                                                      = 37265,
    TYPE965                                                           = 37305,
    TYPE967                                                           = 37350,
    TYPE968                                                           = 37395,
    TYPE974                                                           = 37440,
    TYPE975                                                           = 37485,
    TYPE978                                                           = 37530,
    TYPE992                                                           = 37575,
    TYPE993                                                           = 37620,
    TYPE994                                                           = 37665,
    TYPE1006_1_                                                       = 37710,
    TYPE1006_2_                                                       = 37755,
    TYPE1022                                                          = 37800,
    UKMK10                                                            = 37845,
    UPS_220C                                                          = 37850,
    UPX110                                                            = 37890,
    UPX27                                                             = 37935,
    URN20                                                             = 37980,
    URN25                                                             = 38025,
    VOLEXIII_IV                                                       = 38045,
    W8818                                                             = 38070,
    W8838                                                             = 38115,
    W8852                                                             = 38120,
    WAS_74S                                                           = 38160,
    WaspHead                                                          = 38205,
    WATCHDOG                                                          = 38210,
    WatchGuard                                                        = 38250,
    Watchman                                                          = 38260,
    WesternElectricMK10                                               = 38295,
    WestinghouseElectricSPG50                                         = 38340,
    WestinghouseElectricW120                                          = 38385,
    WestinghouseSPS29C                                                = 38430,
    WestinghouseSPS37                                                 = 38475,
    WetEye                                                            = 38520,
    WetEyeMod                                                         = 38565,
    WGU_41_B                                                          = 38570,
    WGU_44_B                                                          = 38572,
    Whiff                                                             = 38610,
    WhiffBrick                                                        = 38655,
    WhiffFire                                                         = 38700,
    WHITEHOUSE                                                        = 38715,
    WildCard                                                          = 38745,
    WitchEight                                                        = 38790,
    WitchFive                                                         = 38835,
    WM2XSeries                                                        = 38880,
    WM2XSeriesCAS                                                     = 38925,
    WSR_74C                                                           = 38950,
    WSR_74S                                                           = 38955,
    WoodGage                                                          = 38970,
    YardRake                                                          = 39015,
    YewLoop                                                           = 39060,
    Yo_Yo                                                             = 39105
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeEmitterName();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorEmitterName( KUINT32 Index );

KString GetEnumAsStringEmitterName( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEmitterName( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Emitter Function                                                     */
/* Function of a particular beam                                        */
/* Used In:                                                             */
/*  Emitter Beam                                                        */
/************************************************************************/

enum EmitterFunction
{
    OtherFunctionFunction                                             = 0,
    Multi_functionFunction                                            = 1,
    EarlyWarning_SurveillanceFunction                                 = 2,
    HeightFindingFunction                                             = 3,
    FireControlFunction                                               = 4,
    Acquisition_DetectionFunction                                     = 5,
    TrackingFunction                                                  = 6,
    Guidance_IlluminationFunction                                     = 7,
    Firingpoint_launchpointlocationFunction                           = 8,
    RangingFunction                                                   = 9,
    RadarAltimeterFunction                                            = 10,
    ImagingFunction                                                   = 11,
    MotionDetectionFunction                                           = 12,
    NavigationFunction                                                = 13,
    Weather_MeterologicalFunction                                     = 14,
    InstrumentationFunction                                           = 15,
    Identification_Classification_includingIFF_Function               = 16,
    AAA_Anti_AircraftArtillery_FireControlFunction                    = 17,
    AirSearch_BombFunction                                            = 18,
    AirInterceptFunction                                              = 19,
    AltimeterFunction                                                 = 20,
    AirMappingFunction                                                = 21,
    AirTrafficControlFunction                                         = 22,
    BeaconFunction                                                    = 23,
    BattlefieldSurveillanceFunction                                   = 24,
    GroundControlApproachFunction                                     = 25,
    GroundControlInterceptFunction                                    = 26,
    CoastalSurveillanceFunction                                       = 27,
    Decoy_MimicFunction                                               = 28,
    DataTransmissionFunction                                          = 29,
    EarthSurveillanceFunction                                         = 30,
    GunLayBeaconFunction                                              = 31,
    GroundMappingFunction                                             = 32,
    HarborSurveillanceFunction                                        = 33,
    ILS_InstrumentLandingSystem_Function                              = 35,
    IonosphericSoundFunction                                          = 36,
    InterrogatorFunction                                              = 37,
    BarrageJammingFunction                                            = 38,
    ClickJammingFunction                                              = 39,
    FrequencySweptJammingFunction                                     = 41,
    JammingFunction                                                   = 42,
    PulsedJammingFunction                                             = 44,
    RepeaterJammingFunction                                           = 45,
    SpotNoiseJammingFunction                                          = 46,
    MissileAcquisitionFunction                                        = 47,
    MissileDownlinkFunction                                           = 48,
    SpaceFunction                                                     = 50,
    SurfaceSearchFunction                                             = 51,
    ShellTrackingFunction                                             = 52,
    TelevisionFunction                                                = 56,
    UnknownFunction                                                   = 57,
    VideoRemotingFunction                                             = 58,
    ExperimentalorTrainingFunction                                    = 59,
    MissileGuidanceFunction                                           = 60,
    MissileHomingFunction                                             = 61,
    MissileTrackingFunction                                           = 62,
    Jamming_noiseFunction                                             = 64,
    Jamming_deceptionFunction                                         = 65,
    Navigation_DistanceMeasuringEquipmentFunction                     = 71,
    TerrainFollowingFunction                                          = 72,
    WeatherAvoidanceFunction                                          = 73,
    ProximityFuseFunction                                             = 74,
    RadiosondeFunction                                                = 76,
    SonobuoyFunction                                                  = 77,
    Weapon_non_lethalFunction                                         = 96,
    Weapon_lethalFunction                                             = 97
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeEmitterFunction();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorEmitterFunction( KUINT32 Index );

KString GetEnumAsStringEmitterFunction( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEmitterFunction( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* State Update Indicator                                               */
/* Contains Event types                                                 */
/* Used In:                                                             */
/*  Electromagnetic Emission PDU                                        */
/************************************************************************/

enum StateUpdateIndicator
{
    StateUpdate                                                       = 0,
    ChangedDataUpdate                                                 = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeStateUpdateIndicator();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorStateUpdateIndicator( KUINT32 Index );

KString GetEnumAsStringStateUpdateIndicator( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringStateUpdateIndicator( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* High Density Track/Jam                                               */
/* Indicates if the receiving simulation application can assume that all*/
/* targets, in the scan pattern which the sending emitter can track or  */
/* jam are being tracked/jammed/ When selected the system issuing the   */
/* PDU shall not include any entities in the track/jam field.           */
/* Used In:                                                             */
/*  Electromagnetic Emission PDU                                        */
/************************************************************************/

enum HighDensityTrackJam
{
    NotSelected                                                       = 0,
    Selected                                                          = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeHighDensityTrackJam();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorHighDensityTrackJam( KUINT32 Index );

KString GetEnumAsStringHighDensityTrackJam( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringHighDensityTrackJam( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Passive Parameter Index                                              */
/* Indicates which database record ( or file ) shall                    */
/* used in the definition of passive signature (unintentional)          */
/* emissions of the entity.                                             */
/* Used In:                                                             */
/*  Underwater_Acoustic_PDU                                             */
/************************************************************************/

enum PassiveParameterIndex
{
    OtherPPI                                                          = 0
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizePassiveParameterIndex();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorPassiveParameterIndex( KUINT32 Index );

KString GetEnumAsStringPassiveParameterIndex( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringPassiveParameterIndex( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Additional Passive Parameter Index                                   */
/* Indicates which database record ( or file ) shall be used to describe*/
/* an additional acoustic source such as transient effects, pre-launch  */
/* data( i.e torpedo tube floodings ), additional sources, and the      */
/* states available for each source type. This index shall be used to   */
/* identify data from databases such as the Special Event Database      */
/* ( SEDB )and an Additional Narrowband Database ( ANDB ).              */
/* Used In:                                                             */
/*  Underwater_Acoustic_PDU                                             */
/************************************************************************/

enum AdditionalPassiveParameterIndex
{
    OtherAPPI                                                         = 0,
    GrahamsMKVCoffeeMaker                                             = 1
    // >32768   Reserved for classified enumerations
    // Point of Contact =
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeAdditionalPassiveParameterIndex();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorAdditionalPassiveParameterIndex( KUINT32 Index );

KString GetEnumAsStringAdditionalPassiveParameterIndex( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAdditionalPassiveParameterIndex( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Propulsion Plant Configuration                                       */
/* Used to determine the passive signature characteristics of an entity */
/* Bit 7 is used to indicate hull mounted marker status                 */
/* HMMS = Hull Mounted Marker Status                                    */
/* Used In:                                                             */
/*  Underwater_Acoustic_PDU                                             */
/************************************************************************/

enum PropulsionPlantConfiguration
{
    OtherPPC_HMMS_Off                                                 = 0,
    OtherPPC_HMMS_On                                                  = 128,
    Diesel_Electric_HMMS_Off                                          = 1,
    Diesel_Electric_HMMS_On                                           = 129,
    Diesel_HMMS_Off                                                   = 2,
    Diesel_HMMS_On                                                    = 130,
    Battery_HMMS_Off                                                  = 3,
    Battery_HMMS_On                                                   = 131,
    Turbine_Reduction_HMMS_Off                                        = 4,
    Turbine_Reduction_HMMS_On                                         = 132,
    Steam_HMMS_Off                                                    = 6,
    Steam_HMMS_On                                                     = 134,
    Gas_Turbine_HMMS_Off                                              = 7,
    Gas_Turbine_HMMS_On                                               = 135
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizePropulsionPlantConfiguration();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorPropulsionPlantConfiguration( KUINT32 Index );

KString GetEnumAsStringPropulsionPlantConfiguration( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringPropulsionPlantConfiguration( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* AcousticSystemName                                                   */
/* Specifies the system for a UA emitter                                */
/* Used In:                                                             */
/*  Underwater_Acoustic_PDU - Acoustic Emitter System                   */
/************************************************************************/

enum AcousticSystemName
{
    OtherAcousticSystemName                                           = 0,
    AN_BQQ_5                                                          = 1,
    AN_SSQ_62                                                         = 2,
    AN_SQS_23                                                         = 3,
    AN_SQS_26                                                         = 4,
    AN_SQS_53                                                         = 5,
    ALFS                                                              = 6,
    LFA                                                               = 7,
    AN_AQS_901                                                        = 8,
    AN_AQS_902                                                        = 9
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeAcousticSystemName();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorAcousticSystemName( KUINT32 Index );

KString GetEnumAsStringAcousticSystemName( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAcousticSystemName( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* AcousticSystemFunction                                               */
/* Describes the function of the acoustic system                        */
/* Used In:                                                             */
/*  Underwater_Acoustic_PDU - Acoustic Emitter System                   */
/************************************************************************/

enum AcousticSystemFunction
{
    OtherAcousticSystemFunction                                       = 0,
    PlatformSearch_Detect_Track                                       = 1,
    Navigation                                                        = 2,
    MineHunting                                                       = 3,
    WeaponSearch_Detect_Track_Detect                                  = 4
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeAcousticSystemFunction();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorAcousticSystemFunction( KUINT32 Index );

KString GetEnumAsStringAcousticSystemFunction( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAcousticSystemFunction( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Active Emission Parameter Index                                      */
/* Describes the function of the acoustic system                        */
/* Used In:                                                             */
/*  Underwater_Acoustic_PDU - UA Fundamental Parameter Data             */
/************************************************************************/

enum ActiveEmissionParameterIndex
{
    OtherActiveEmissionParameterIndex                                 = 0
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeActiveEmissionParameterIndex();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorActiveEmissionParameterIndex( KUINT32 Index );

KString GetEnumAsStringActiveEmissionParameterIndex( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringActiveEmissionParameterIndex( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Scan Pattern                                                         */
/* Desscribes the UA scan pattern                                       */
/* Used In:                                                             */
/*  Underwater_Acoustic_PDU - UA Fundamental Parameter Data             */
/************************************************************************/

enum ScanPattern
{
    ScanPatternNotUsed                                                = 0,
    Conical                                                           = 1,
    Helical                                                           = 2,
    Raster                                                            = 3,
    SectorSearch                                                      = 4,
    ContinuousSearch                                                  = 5
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeScanPattern();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorScanPattern( KUINT32 Index );

KString GetEnumAsStringScanPattern( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringScanPattern( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Power Setting                                                        */
/* Represents the power settings after any response lags have been      */
/* incorprated                                                          */
/* Used In:                                                             */
/*  SEES_PDU - Propulsion System                                        */
/************************************************************************/

enum PowerSettingAircraft
{
    AircraftEngineOff                                                 = -100,
    AircraftIdlePower                                                 = 0,
    AircraftMilPower                                                  = 50,
    AircraftMinAB                                                     = 51,
    AircraftMaxAB                                                     = 100
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizePowerSettingAircraft();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorPowerSettingAircraft( KUINT32 Index );

KString GetEnumAsStringPowerSettingAircraft( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringPowerSettingAircraft( const KString & Value, KINT32 & ValueOut ); 

enum PowerSettingHelicopter
{
    HelicopterEngineOff                                               = -100,
    HelicopterIdlePower                                               = 0,
    HelicopterMaxPower                                                = 100
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizePowerSettingHelicopter();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorPowerSettingHelicopter( KUINT32 Index );

KString GetEnumAsStringPowerSettingHelicopter( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringPowerSettingHelicopter( const KString & Value, KINT32 & ValueOut ); 

enum PowerSettingTank
{
    TankEngineOff                                                     = -100,
    TankIdlePower                                                     = 0,
    TankMaxPower                                                      = 100
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizePowerSettingTank();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorPowerSettingTank( KUINT32 Index );

KString GetEnumAsStringPowerSettingTank( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringPowerSettingTank( const KString & Value, KINT32 & ValueOut ); 

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
