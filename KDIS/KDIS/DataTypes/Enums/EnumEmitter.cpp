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

#include "./EnumEmitter.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for EmitterName

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EmitterNameDescriptor[] =
{
    { 10 , "RL138" },
	{ 45 , "DECCAMIL" },
	{ 80 , "GR400" },
	{ 90 , "GR600" },
	{ 135 , "LV200TA" },
	{ 180 , "LV200TV" },
    { 225 , "A310Z" },
    { 270 , "A325A" },
    { 315 , "A346Z" },
    { 360 , "A353B" },
    { 405 , "A372A" },
    { 450 , "A372B" },
    { 495 , "A372C" },
    { 540 , "A377A" },
    { 585 , "A377B" },
    { 630 , "A380Z" },
    { 675 , "A381Z" },
    { 720 , "A398Z" },
    { 765 , "A403Z" },
    { 809 , "GR400" },
    { 810 , "A409A" },
    { 855 , "A418A" },
    { 900 , "A419Z" },
    { 909 , "GR600" },
    { 945 , "A429Z" },
    { 990 , "A432Z" },
    { 1035 , "A434Z" },
    { 1080 , "A401A" },
    { 1095 , "AA_12Seeker" },
    { 1100 , "Agave" },
    { 1125 , "AGRION15" },
    { 1170 , "AIMK23" },
    { 1215 , "AIDAII" },
    { 1260 , "AlbatrosMK2" },
	{ 1280 , "L13_3_55G6_BoxSpring" },
	{ 1282 , "L13_3_55G6_BoxSpringB" },
    { 1305 , "ANASPS502" },
    { 1350 , "ANRITSUElectricAR_30A" },
    { 1359 , "LV200TA" },
    { 1395 , "AntilopeV" },
    { 1400 , "AN_ALE_50" },
    { 1440 , "AN_ALQ99" },
    { 1485 , "AN_ALQ_100" },
    { 1530 , "AN_ALQ_101" },
    { 1575 , "AN_ALQ_119" },
    { 1585 , "AN_ALQ_122" },
    { 1620 , "AN_ALQ_126A" },
    { 1626 , "AN_ALQ_131" },
    { 1628 , "AN_ALQ_135C_D" },
    { 1630 , "AN_ALQ_144A_V_3" },
    { 1632 , "AN_ALQ_153" },
    { 1634 , "AN_ALQ_155" },
    { 1636 , "AN_ALQ_161_A" },
    { 1638 , "AN_ALQ_162" },
    { 1640 , "AN_ALQ_165" },
    { 1642 , "AN_ALQ_167" },
    { 1644 , "AN_ALQ_172_V_2" },
    { 1646 , "AN_ALQ_176" },
    { 1648 , "AN_ALQ_184" },
    { 1650 , "AN_ALQ_188" },
    { 1652 , "AN_ALR_56" },
    { 1654 , "AN_ALR_69" },
    { 1656 , "AN_ALT_16A" },
    { 1658 , "AN_ALT_28" },
    { 1660 , "AN_ALT_32A" },
    { 1665 , "AN_APD10" },
    { 1710 , "AN_APG53" },
    { 1755 , "AN_APG59" },
    { 1800 , "AN_APG_63AB" },
    { 1805 , "AN_APG_63C" },
    { 1809 , "LV200TV" },
    { 1845 , "AN_APG65" },
    { 1870 , "AN_APG_66" },
    { 1890 , "AN_APG68" },
    { 1935 , "AN_APG70" },
    { 1945 , "AN_APG_73" },
    { 1960 , "AN_APG_77" },
    { 1970 , "AN_APG_78" },
    { 1980 , "AN_APG_502" },
    { 2025 , "AN_APN_1" },
    { 2070 , "AN_APN_22" },
    { 2115 , "AN_APN59" },
    { 2160 , "AN_APN_69" },
    { 2205 , "AN_APN_81" },
    { 2250 , "AN_APN_117" },
    { 2295 , "AN_APN_118" },
    { 2340 , "AN_APN_130" },
    { 2385 , "AN_APN_131" },
    { 2430 , "AN_APN_133" },
    { 2475 , "AN_APN_134" },
    { 2520 , "AN_APN_147" },
    { 2565 , "AN_APN_150" },
    { 2610 , "AN_APN_153" },
    { 2655 , "AN_APN154" },
    { 2700 , "AN_APN_155" },
    { 2745 , "AN_APN_159" },
    { 2790 , "AN_APN_182" },
    { 2835 , "AN_APN_187" },
    { 2880 , "AN_APN_190" },
    { 2925 , "AN_APN194" },
    { 2970 , "AN_APN_195" },
    { 3015 , "AN_APN_198" },
    { 3060 , "AN_APN_200" },
    { 3105 , "AN_APN202" },
    { 3150 , "AN_APN_217" },
    { 3152 , "AN_APN_218" },
    { 3160 , "AN_APN_238" },
    { 3162 , "AN_APN_239" },
    { 3164 , "AN_APN_241" },
    { 3166 , "AN_APN_242" },
    { 3195 , "AN_APN_506" },
    { 3240 , "AN_APQ_72" },
    { 3285 , "AN_APQ_99" },
    { 3330 , "AN_APQ100" },
    { 3375 , "AN_APQ_102" },
    { 3420 , "AN_APQ_109" },
    { 3465 , "AN_APQ113" },
    { 3510 , "AN_APQ120" },
    { 3555 , "AN_APQ126" },
    { 3600 , "AN_APQ_128" },
    { 3645 , "AN_APQ_129" },
    { 3690 , "AN_APQ148" },
    { 3735 , "AN_APQ_153" },
    { 3780 , "AN_APQ159" },
    { 3785 , "AN_APQ_164" },
    { 3788 , "AN_APQ_166" },
    { 3795 , "AN_APQ_181" },
    { 3820 , "AN_APS_31" },
    { 3825 , "AN_APS_42" },
    { 3870 , "AN_APS80" },
    { 3915 , "AN_APS_88" },
    { 3960 , "AN_APS115" },
    { 4005 , "AN_APS116" },
    { 4050 , "AN_APS_120" },
    { 4095 , "AN_APS121" },
    { 4140 , "AN_APS124" },
    { 4185 , "AN_APS125" },
    { 4230 , "AN_APS_128" },
    { 4275 , "AN_APS130" },
    { 4320 , "AN_APS133" },
    { 4365 , "AN_APS_134" },
    { 4410 , "AN_APS137" },
    { 4455 , "AN_APS_138" },
    { 4465 , "AN_APS_143_V_1" },
    { 4500 , "AN_APW22" },
    { 4545 , "AN_APW23" },
    { 4590 , "AN_APX_6" },
    { 4635 , "AN_APX7" },
    { 4680 , "AN_APX39" },
    { 4725 , "AN_APX_72" },
    { 4770 , "AN_APX76" },
    { 4815 , "AN_APX78" },
    { 4860 , "AN_APX101" },
    { 4870 , "AN_APX_113AIFF" },
    { 4900 , "AN_APY_1" },
    { 4905 , "AN_APY2" },
    { 4950 , "AN_APY3" },
    { 4995 , "AN_ARN21" },
    { 5040 , "AN_ARN52" },
    { 5085 , "AN_ARN84" },
    { 5130 , "AN_ARN118" },
    { 5175 , "AN_ARW73" },
    { 5220 , "AN_ASB1" },
    { 5265 , "AN_ASG21" },
    { 5280 , "AN_ASQ_108" },
    { 5310 , "AN_AWG9" },
    { 5355 , "AN_BPS_9" },
    { 5400 , "AN_BPS15" },
    { 5405 , "AN_BPS_16" },
    { 5420 , "AN_CRM_30" },
    { 5430 , "AN_DPW_23" },
    { 5445 , "AN_DSQ26PhoenixMH" },
    { 5490 , "AN_DSQ28HarpoonMH" },
    { 5495 , "AN_FPN_40" },
    { 5500 , "AN_FPN_62" },
    { 5505 , "AN_FPS_16" },
    { 5507 , "AN_FPS_18" },
    { 5510 , "AN_FPS_117" },
    { 5515 , "AN_FPS_20R" },
    { 5520 , "AN_FPS_77" },
    { 5525 , "AN_FPS_103" },
    { 5527 , "AN_GPN_12" },
    { 5530 , "AN_GPX_6" },
    { 5535 , "AN_GPX8" },
    { 5537 , "AN_GRN_12" },
    { 5540 , "AN_MPQ_10" },
    { 5545 , "AN_MPQ_46_HPI_ILL" },
    { 5550 , "AN_MPQ_48_55CWAR" },
    { 5551 , "AN_MPQ_49" },
    { 5555 , "AN_MPQ_50_PAR_TA" },
    { 5560 , "AN_MPQ_51_ROR_TT" },
    { 5570 , "AN_MPQ_53" },
    { 5575 , "AN_MPQ_64" },
    { 5580 , "AN_SPG_34" },
    { 5625 , "AN_SPG50" },
    { 5670 , "AN_SPG51" },
    { 5715 , "AN_SPG_51CWITI" },
    { 5760 , "AN_SPG_51FC" },
    { 5805 , "AN_SPG52" },
    { 5850 , "AN_SPG_53" },
    { 5895 , "AN_SPG55B" },
    { 5940 , "AN_SPG60" },
    { 5985 , "AN_SPG62" },
    { 6030 , "AN_SPN35" },
    { 6075 , "AN_SPN43" },
    { 6120 , "AN_SPQ_2" },
    { 6165 , "AN_SPQ9" },
    { 6210 , "AN_SPS_4" },
    { 6255 , "AN_SPS_5" },
    { 6300 , "AN_SPS_5C" },
    { 6345 , "AN_SPS_6" },
    { 6390 , "AN_SPS10" },
    { 6435 , "AN_SPS21" },
    { 6480 , "AN_SPS_28" },
    { 6525 , "AN_SPS_37" },
    { 6570 , "AN_SPS_39A" },
    { 6615 , "AN_SPS40" },
    { 6660 , "AN_SPS_41" },
    { 6705 , "AN_SPS48" },
    { 6750 , "AN_SPS_48C" },
    { 6795 , "AN_SPS49" },
    { 6840 , "AN_SPS52" },
    { 6885 , "AN_SPS53" },
    { 6930 , "AN_SPS55" },
    { 6975 , "AN_SPS_55SS" },
    { 7020 , "AN_SPS_58" },
    { 7065 , "AN_SPS59" },
    { 7110 , "AN_SPS64" },
    { 7155 , "AN_SPS65" },
    { 7200 , "AN_SPS67" },
    { 7245 , "AN_SPY1" },
    { 7250 , "AN_SPY_1A" },
    { 7270 , "AN_TPN_17" },
    { 7275 , "AN_TPN_24" },
    { 7280 , "AN_TPQ_18" },
    { 7295 , "AN_TPQ_36" },
    { 7300 , "AN_TPQ_37" },
    { 7301 , "AN_TPQ_38_V8_" },
    { 7303 , "AN_TPQ_47" },
    { 7305 , "AN_TPS_43" },
    { 7310 , "AN_TPS_43E" },
    { 7315 , "AN_TPS_59" },
    { 7320 , "AN_TPS_63" },
    { 7322 , "AN_TPS_70_V_1" },
    { 7325 , "AN_TPS_75" },
    { 7330 , "AN_TPX_46_V_7" },
    { 7335 , "AN_ULQ_6A" },
    { 7380 , "AN_UPN25" },
    { 7425 , "AN_UPS1" },
    { 7426 , "AN_UPS_2" },
    { 7470 , "AN_UPX1" },
    { 7515 , "AN_UPX5" },
    { 7560 , "AN_UPX11" },
    { 7605 , "AN_UPX12" },
    { 7650 , "AN_UPX17" },
    { 7695 , "AN_UPX23" },
    { 7740 , "AN_VPS2" },
    { 7785 , "ApelcoAD77" },
    { 7830 , "APG71" },
    { 7875 , "APN148" },
    { 7920 , "APN227" },
    { 7965 , "_deleted_" },
    { 8010 , "_deleted_1" },
    { 8055 , "_deleted_2" },
    { 8100 , "APS504V3" },
    { 8105 , "AR3D" },
    { 8115 , "AR320" },
    { 8120 , "AR327" },
    { 8145 , "ARM31" },
    { 8190 , "ARI5954" },
    { 8235 , "ARI5955" },
    { 8280 , "ARI5979" },
    { 8325 , "ARINC564BNDX_KINGRDR1E" },
    { 8370 , "ARINC700BNDX_KINGRDR1E" },
    { 8375 , "ARK_1" },
    { 8380 , "ARSR_3" },
    { 8390 , "ARSR_18" },
    { 8415 , "AS2Kipper" },
    { 8460 , "AS2KipperMH" },
    { 8505 , "AS4Kitchen" },
    { 8550 , "AS4KitchenMH" },
    { 8595 , "AS5KeltMH" },
    { 8640 , "AS6KingfishMH" },
    { 8685 , "AS7Kerry" },
    { 8730 , "AS7KerryMG" },
    { 8735 , "AS15KENTaltimeter" },
    { 8760 , "AspideAAM_SAMILL" },
    { 8775 , "ASRO" },
    { 8780 , "ASR_5" },
    { 8785 , "ASR_8" },
    { 8790 , "ASR_9" },
    { 8820 , "AT2SwatterMG" },
    { 8840 , "ATCR_33" },
    { 8845 , "ATCR33K_M" },
    { 8865 , "AtlasElektronkTRSN" },
    { 8870 , "ATLAS_9740VTS" },
    { 8910 , "AVG65" },
    { 8955 , "AVH7" },
    { 9000 , "AVQ20" },
    { 9045 , "AVQ30X" },
    { 9075 , "AVQ_50_RCA_" },
    { 9090 , "AVQ70" },
    { 9135 , "AWS5" },
    { 9180 , "AWS6" },
    { 9200 , "B597Z" },
    { 9205 , "B636Z" },
    { 9225 , "BackNetAB" },
    { 9270 , "BackTrap" },
    { 9310 , "BALTYK" },
    { 9315 , "BallEnd" },
    { 9360 , "BallGun" },
    { 9405 , "BandStand" },
    { 9450 , "P_35_37_A_P_50_B_BarLock" },
    { 9495 , "BassTilt" },
    { 9540 , "Beacon" },
    { 9585 , "BeanSticks" },
    { 9630 , "BeeHind" },
    { 9640 , "BellCrownA" },
    { 9642 , "BellCrownB" },
    { 9645 , "BIGBACK" },
    { 9660 , "BigBird" },
    { 9675 , "BigBulge" },
    { 9720 , "BigBulgeA" },
    { 9765 , "BigBulgeB" },
    { 9780 , "SNAR_10BigFred" },
    { 9810 , "BigMesh" },
    { 9855 , "BigNet" },
    { 98859 , "S15MTBillBoard" },
    { 9900 , "BillFold" },
    { 9905 , "BlowpipeMG" },
    { 9930 , "BlueFoxSeaHarrierFRSMk1_5" },
    { 9935 , "BlueVixenSeaHarrierF_AMk2" },
    { 9945 , "BlueSilk" },
    { 9990 , "BlueParrot" },
    { 10035 , "BlueOrchid" },
    { 10080 , "BoatSail" },
    { 10125 , "BoforsElectronic9LV331" },
    { 10170 , "BoforsEricssonSeaGiraffe50HC" },
    { 10215 , "BowlMesh" },
    { 10260 , "BoxBrick" },
    { 10305 , "BoxTail" },
    { 10350 , "BPS11A" },
    { 10395 , "BPS14" },
    { 10440 , "BPS15A" },
    { 10485 , "BR_15TokyoKEIKI" },
    { 10510 , "BRIDGEMASTE" },
    { 10530 , "BreadBin" },
    { 10575 , "BT271" },
    { 10620 , "BX732" },
    { 10665 , "BuzzStand" },
    { 10710 , "C5AMultiModeRadar" },
    { 10755 , "Caiman" },
    { 10800 , "CakeStand" },
    { 10845 , "CalypsoC61" },
    { 10890 , "CalypsoIi" },
    { 10895 , "CardionCoastal" },
    { 10935 , "CastorIi" },
    { 10940 , "Castor2JTT_CrotaleNG_" },
    { 10980 , "CatHouse" },
    { 10985 , "CDR_431" },
    { 11000 , "ChairBackTT" },
    { 11010 , "ChairBackILL" },
    { 11025 , "CheeseBrick" },
    { 11070 , "ClamPipe" },
    { 11115 , "Clamshell" },
    { 11160 , "CollinsWXR_700X" },
    { 11205 , "CollinsDN101" },
    { 11250 , "ContravesSeaHunterMK4" },
    { 11260 , "CornCan" },
    { 11270 , "CR_105RMCA" },
    { 11295 , "CrossBird" },
    { 11340 , "CrossDome" },
    { 11385 , "CrossLegs" },
    { 11430 , "CrossOut" },
    { 11475 , "CrossSlot" },
    { 11520 , "CrossSword" },
    { 11565 , "CrossUp" },
    { 11610 , "CrossSwordFC" },
    { 11655 , "CrotaleAcquisitionTATHD_5000" },
    { 11660 , "CrotaleNGTAGriffon" },
    { 11665 , "CrotaleTT" },
    { 11700 , "CrotaleMGMissileSystem" },
    { 11745 , "CSSC3CCAS1M1M2MH" },
    { 11790 , "CSSC2BHY1AMH" },
    { 11835 , "CWS2" },
    { 11880 , "CylinderHead" },
    { 11925 , "CyranoII" },
    { 11970 , "CyranoIV" },
    { 11975 , "CyranoIV_M" },
    { 12010 , "DA_01_00" },
    { 12015 , "DA0500" },
    { 12060 , "Dawn" },
    { 12105 , "DeadDuck" },
    { 12110 , "DECCA_20V90_9" },
    { 12111 , "DECCA_20V90S" },
    { 12150 , "DECCA45" },
    { 12195 , "DECCA50" },
    { 12240 , "DECCA110" },
    { 12285 , "DECCA170" },
    { 12330 , "DECCA202" },
    { 12375 , "DECCAD202" },
    { 12420 , "DECCA303" },
    { 12430 , "DECCA535" },
    { 12465 , "DECCA626" },
    { 12510 , "DECCA629" },
    { 12555 , "DECCA914" },
    { 12600 , "DECCA916" },
    { 12610 , "DECCA926" },
    { 12645 , "DECCA1226Commercial" },
    { 12690 , "DECCA1626" },
    { 12735 , "DECCA2459" },
    { 12780 , "DECCAAWS1" },
    { 12782 , "DECCAAWS2" },
    { 12785 , "DECCAAWS4" },
    { 12787 , "DECCAAWS_4_2_" },
    { 12800 , "DECCAMAR" },
    { 12805 , "DECCARM326" },
    { 12825 , "DECCARM416" },
    { 12870 , "DECCARM914" },
    { 12915 , "DECCARM1690" },
    { 12960 , "DECCASuper101MK3" },
    { 13005 , "DISS1" },
    { 13050 , "RapierTTDN181DN181" },
    { 13055 , "Rapier2000TTBLINDFIREFSCTT" },
    { 13095 , "DogEar" },
    { 13140 , "DogHouse" },
    { 13185 , "Don2" },
    { 13230 , "DonA_B_2_Kay" },
    { 13275 , "Donets" },
    { 13320 , "DownBeat" },
    { 13365 , "DRAA2A" },
    { 13410 , "DRAA2B" },
    { 13455 , "DRAC39" },
    { 13500 , "DRBC30B" },
    { 13545 , "DRBC31A" },
    { 13590 , "DRBC32A" },
    { 13635 , "DRBC32D" },
    { 13680 , "DRBC33A" },
    { 13725 , "DRBI10" },
    { 13770 , "DRBI23" },
    { 13815 , "DRBJ11B" },
    { 13860 , "DRBN30" },
    { 13905 , "DRBN32" },
    { 13950 , "DRBR51" },
    { 13995 , "DRBV20B" },
    { 14040 , "DRBV22" },
    { 14085 , "DRBV26C" },
    { 14130 , "DRBV30" },
    { 14175 , "DRBV50" },
    { 14220 , "DRBV51" },
    { 14265 , "DRBV51A" },
    { 14310 , "DRBV51B" },
    { 14355 , "DRBV51C" },
    { 14400 , "DropKick" },
    { 14445 , "DRUA31" },
    { 14490 , "DrumTilt" },
    { 14535 , "DrumTiltA" },
    { 14545 , "DrumTiltB" },
    { 14580 , "Dumbo" },
    { 14600 , "ECR_90" },
    { 14625 , "EggCupA_B" },
    { 14670 , "EKCO190" },
    { 14715 , "ELM2001B" },
    { 14760 , "ELM2207" },
    { 14770 , "EL_M2216_V_" },
    { 14805 , "ELTAEL_M2221GMSTGR" },
    { 14810 , "ELTASIS" },
    { 14850 , "EMD2900" },
    { 14895 , "EndTray" },
    { 14940 , "Exocet1" },
    { 14985 , "Exocet1MH" },
    { 15030 , "Exocet2" },
    { 15075 , "EyeBowl" },
    { 15120 , "EyeShield" },
    { 15140 , "F332Z" },
    { 15160 , "FALCON" },
    { 15165 , "FanSongA" },
    { 15200 , "FanSongB_FTA" },
    { 15210 , "FanSongB_FTT" },
    { 15220 , "FanSongC_ETA" },
    { 15230 , "FanSongC_ETT" },
    { 15240 , "FanSongC_EMG" },
    { 15255 , "FanSongB_FFMG" },
    { 15300 , "FanTail" },
    { 15310 , "FCR_1401" },
    { 15345 , "FinCurve" },
    { 15390 , "FireCan" },
    { 15435 , "FireDish" },
    { 15470 , "FireDomeTA" },
    { 15475 , "FireDomeTT" },
    { 15480 , "FireDomeTI" },
    { 15525 , "FireIron" },
    { 15570 , "FireWheel" },
    { 15615 , "FishBowl" },
    { 15660 , "FlapLid" },
    { 15705 , "FlapTruck" },
    { 15750 , "FlapWheel" },
    { 15795 , "FlashDance" },
    { 15840 , "P_15FlatFaceABCD" },
    { 15885 , "FlatScreen" },
    { 15930 , "FlatSpin" },
    { 15975 , "FlatTwin" },
    { 16020 , "Fledermaus" },
    { 16030 , "FLYCATCHER" },
    { 16065 , "FlyScreen" },
    { 16110 , "FlyScreenAB" },
    { 16155 , "FlyTrapB" },
    { 16200 , "FogLampMG" },
    { 16245 , "FogLampTT" },
    { 16290 , "FoilTwo" },
    { 16335 , "FoxHunter" },
    { 16380 , "FOXFIREFoxFireAL" },
    { 16390 , "FOXFIREILL" },
    { 16400 , "FR_151A" },
    { 16410 , "FR_1505DA" },
    { 16420 , "FR_2000" },
    { 16421 , "FR_2855W" },
    { 16425 , "FrontDome" },
    { 16470 , "FrontDoor" },
    { 16515 , "FrontPiece" },
    { 16560 , "Furuno" },
    { 16605 , "Furuno701" },
    { 16650 , "Furuno7112" },
    { 16695 , "Furuno2400" },
    { 16740 , "GA0100" },
    { 16785 , "Gage" },
    { 16830 , "Garpin" },
    { 16875 , "GEMBX132" },
    { 16880 , "MPDR_12GepardTA" },
    { 16884 , "GepardTT" },
    { 16888 , "GERAN_F" },
    { 16900 , "GIRAFFE" },
    { 16915 , "GinSlingTA" },
    { 16920 , "GinSlingGinSlingTT" },
    { 16925 , "GinSlingMG" },
    { 16945 , "GPN_22" },
    { 16950 , "GRN_9" },
    { 16965 , "GreenStain" },
    { 17010 , "GridBow" },
    { 170259 , "S32GRILLPANTT" },
    { 17055 , "Guardsman" },
    { 17070 , "RPK_2GUNDISH_ZSU_23_4_" },
    { 17100 , "HairNet" },
    { 17145 , "HalfPlateA" },
    { 17190 , "HalfPlateB" },
    { 17220 , "HARD" },
    { 17235 , "HawkScreech" },
    { 17280 , "HeadLightA" },
    { 17325 , "HeadLights" },
    { 17370 , "HeadLightsC" },
    { 17415 , "HeadLightsMGA" },
    { 17460 , "HeadLightsMGB" },
    { 17505 , "HeadLightsTT" },
    { 17550 , "HeadNet" },
    { 17595 , "HenEgg" },
    { 17640 , "HenHouse" },
    { 17685 , "HenNest" },
    { 17730 , "HenRoost" },
    { 17775 , "HighBrick" },
    { 17820 , "HighFix" },
    { 17865 , "HighLarkTI" },
    { 17910 , "HighLark1" },
    { 17955 , "HighLark2" },
    { 18000 , "HighLark4" },
    { 18045 , "HighLune" },
    { 18090 , "HighPoleAB" },
    { 18135 , "HighScoop" },
    { 181509 , "S19MTHIGHSCREEN" },
    { 18180 , "HighSieve" },
    { 18200 , "HN_503" },
    { 18225 , "HomeTalk" },
    { 18270 , "HornSpoon" },
    { 18280 , "HOTBRICK" },
    { 18315 , "HotFlash" },
    { 18320 , "IRL144MHotShotTA" },
    { 18325 , "IRL144MHotShotTT" },
    { 18330 , "IRL144MHotShotMG" },
    { 18360 , "IFFMKXIIAIMSUPX29" },
    { 18405 , "IFFMKXV" },
    { 18410 , "JavelinMG" },
    { 18450 , "JayBird" },
    { 18460 , "JRC_NMD_401" },
    { 18495 , "Jupiter" },
    { 18540 , "JupiterII" },
    { 18550 , "JY_8" },
    { 18555 , "JY_9" },
    { 18560 , "JY_14" },
    { 18585 , "K376Z" },
    { 18630 , "KelvinHughes2A" },
    { 18675 , "KelvinHughes14_9" },
    { 18720 , "KelvinHughestype1006" },
    { 18765 , "KelvinHughestype1007" },
    { 18785 , "KH_902M" },
    { 18810 , "KiteScreech" },
    { 18855 , "KiteScreechA" },
    { 18900 , "KiteScreechB" },
    { 18945 , "Kivach" },
    { 18990 , "KnifeRest" },
    { 19035 , "P_10KnifeRestB" },
    { 19037 , "KNIFERESTC" },
    { 19050 , "KR_75" },
    { 19080 , "KSASRN" },
    { 19125 , "KSATSR" },
    { 19170 , "LandFall" },
    { 19215 , "LandRollMG" },
    { 19260 , "LandRollTA" },
    { 19305 , "LandRollTT" },
    { 19310 , "LC_150" },
    { 19350 , "Leningraf" },
    { 19395 , "LightBulb" },
    { 19400 , "LMTNRAI_6A" },
    { 19440 , "LN55" },
    { 19485 , "Ln66" },
    { 19530 , "LongBow" },
    { 19575 , "LongBrick" },
    { 19620 , "LongBull" },
    { 19665 , "LongEye" },
    { 19710 , "LongHead" },
    { 19755 , "LongTalk" },
    { 19800 , "LongTrack" },
    { 19845 , "LongTrough" },
    { 19890 , "LookTwo" },
    { 19935 , "LORAN" },
    { 19950 , "LowBlowTA" },
    { 19955 , "LowBlowTT" },
    { 19960 , "LowBlowMG" },
    { 19980 , "LowSieve" },
    { 20025 , "LowTrough" },
    { 20040 , "TRS_2050LP_23" },
    { 20070 , "LW08" },
    { 20090 , "M_1983FCR" },
    { 20115 , "M22_40" },
    { 20160 , "M44" },
    { 20205 , "M401Z" },
    { 20250 , "M585Z" },
    { 20295 , "M588Z" },
    { 20340 , "MA1IFFPortion" },
    { 20360 , "MARELD" },
    { 20385 , "MAType909" },
    { 20430 , "Marconi1810" },
    { 20475 , "MarconiCanadaHC75" },
    { 20495 , "MarconiS713" },
    { 20520 , "MarconiS1802" },
    { 20530 , "MarconiS247" },
    { 20565 , "MarconiS810" },
    { 20585 , "MarconiSA10" },
    { 20610 , "Marconitype967" },
    { 20655 , "Marconitype968" },
    { 20700 , "Marconitype992" },
    { 20745 , "Marconi_signaaltype1022" },
    { 20790 , "Marconi_signaaltype910" },
    { 20835 , "Marconi_signaaltype911" },
    { 20880 , "Marconi_signaaltype992R" },
    { 20925 , "MeshBrick" },
    { 20950 , "MirageILL" },
    { 20970 , "MK15CIWS" },
    { 21015 , "MK_23" },
    { 21060 , "MK23TAS" },
    { 21105 , "MK25" },
    { 21150 , "MK_35M2" },
    { 21195 , "MK92" },
    { 21240 , "MK_92CAS" },
    { 21285 , "MK_92STIR" },
    { 21330 , "MK95" },
    { 21340 , "MLA_1" },
    { 21375 , "MMAPS705" },
    { 21420 , "MMSPG74" },
    { 21465 , "MMSPG75" },
    { 21490 , "MMSPN703" },
    { 21510 , "MMSPS702" },
    { 21555 , "MMSPS768" },
    { 21600 , "MMSPS774" },
    { 21645 , "Moon4" },
    { 21650 , "MMRS" },
    { 21690 , "MPDR18X" },
    { 21710 , "MT_305X" },
    { 21735 , "MuffCob" },
    { 21780 , "Mushroom" },
    { 21825 , "Mushroom1" },
    { 21870 , "Mushroom2" },
    { 21880 , "N920Z" },
    { 21890 , "NanjingB" },
    { 21895 , "NanjingC" },
    { 21915 , "Nayada" },
    { 21960 , "Neptun" },
    { 21980 , "NIKETT" },
    { 22005 , "NRBA50" },
    { 22050 , "NRBA51" },
    { 22095 , "NRBF20A" },
    { 22140 , "NysaB" },
    { 22185 , "O524A" },
    { 22230 , "O580B" },
    { 22275 , "O625Z" },
    { 22320 , "O626Z" },
    { 22345 , "OddGroup" },
    { 22365 , "OddLot" },
    { 22410 , "OddPair" },
    { 22455 , "Oka" },
    { 22500 , "OKEAN" },
    { 22545 , "OKINXE12C" },
    { 22590 , "OMEGA" },
    { 22635 , "OmeraORB32" },
    { 22680 , "OneEye" },
    { 22690 , "OP_28" },
    { 22725 , "OPS_16B" },
    { 22730 , "OPS_18" },
    { 22740 , "OPS_28" },
    { 22770 , "OR_2" },
    { 22810 , "ORB_31S" },
    { 22815 , "ORB32" },
    { 22860 , "OrionRtn10X" },
    { 22905 , "OtomatMKIITeseo" },
    { 22950 , "OwlScreech" },
    { 22955 , "P360Z" },
    { 22960 , "PA_1660" },
    { 22995 , "PalmFrond" },
    { 23040 , "PalmFrondAB" },
    { 23085 , "PatHandTT" },
    { 23095 , "PatHandMG" },
    { 23130 , "PattyCake" },
    { 23175 , "PawnCake" },
    { 23220 , "PBR4Rubin" },
    { 23265 , "PeaSticks" },
    { 23310 , "PeelCone" },
    { 23355 , "PeelGroup" },
    { 23400 , "PeelGroupA" },
    { 23445 , "PeelGroupB" },
    { 23490 , "PeelPair" },
    { 23535 , "Philips9LV200" },
    { 23580 , "Philips9LV331" },
    { 23625 , "PhilipsLV223" },
    { 23670 , "PhilipsSeaGiraffe50HC" },
    { 23690 , "PinJib" },
    { 23710 , "PlankShad" },
    { 23715 , "PlankShave" },
    { 23760 , "PlankShaveA" },
    { 23805 , "PlankShaveB" },
    { 23850 , "PlateSteer" },
    { 23895 , "PlesseyAWS1" },
    { 23940 , "PlesseyAWS4" },
    { 23985 , "PlesseyAWS6" },
    { 23990 , "PlesseyRJ" },
    { 24030 , "Plesseytype996" },
    { 24075 , "PlinthNet" },
    { 24095 , "Pluto" },
    { 24100 , "POHJANPALO" },
    { 24120 , "POLLUX" },
    { 24165 , "PopGroup" },
    { 24210 , "PopGroupMG" },
    { 24255 , "PopGroupTA" },
    { 24300 , "PopGroupTT" },
    { 24345 , "PorkTrough" },
    { 24390 , "PostBow" },
    { 24435 , "PostLamp" },
    { 24480 , "PotDrum" },
    { 24525 , "PotHead" },
    { 24570 , "PRIMUS40WXD" },
    { 24615 , "PRIMUS300SL" },
    { 24620 , "Primus3000" },
    { 24650 , "PS_05A" },
    { 24660 , "PS46A" },
    { 24705 , "PS70R" },
    { 24710 , "PS_890" },
    { 24750 , "PuffBall" },
    { 24770 , "R_76" },
    { 24780 , "RAC_30" },
    { 24795 , "Racal1229" },
    { 24840 , "RacalAC2690BT" },
    { 24885 , "RacalDecca1216" },
    { 24930 , "RacalDecca360" },
    { 24975 , "RacalDeccaAC1290" },
    { 25020 , "RacalDeccaTM1229" },
    { 25065 , "RacalDeccaTM1626" },
    { 25110 , "RacalDRBN34A" },
    { 25155 , "Radar24" },
    { 25200 , "RAN7S" },
    { 25205 , "RAN10S" },
    { 25245 , "RAN11LX" },
    { 25260 , "RapierTA" },
    { 25265 , "Rapier2000TADagger" },
    { 25270 , "RapierMG" },
    { 25280 , "RAT_31S" },
    { 25285 , "RATAC_LCT_" },
    { 25290 , "Raytheon1220" },
    { 25300 , "Raytheon1302" },
    { 25335 , "Raytheon1500" },
    { 25380 , "Raytheon1645" },
    { 25425 , "Raytheon1650" },
    { 25470 , "Raytheon1900" },
    { 25515 , "Raytheon2502" },
    { 25560 , "RaytheonTM1650_6X" },
    { 25605 , "RaytheonTM1660_12S" },
    { 25630 , "RAY_1220XR" },
    { 25635 , "RAY_1401" },
    { 25650 , "Ray2900" },
    { 25695 , "Raypath" },
    { 25735 , "RBE2" },
    { 25740 , "RDM" },
    { 25760 , "RDY" },
    { 25785 , "RDN72" },
    { 25830 , "RDR1A" },
    { 25835 , "RDR1E" },
    { 25840 , "RDR4A" },
    { 25875 , "RDR1200" },
    { 25885 , "RDR1400" },
    { 25890 , "RDR1400C" },
    { 25895 , "RDR1500" },
    { 25920 , "RiceLamp" },
    { 25965 , "RicePad" },
    { 26010 , "RiceScreen" },
    { 26055 , "ROLANDBN" },
    { 26100 , "ROLANDMG" },
    { 26145 , "ROLANDTA" },
    { 26190 , "ROLANDTT" },
    { 26235 , "RoundBall" },
    { 26280 , "RoundHouse" },
    { 26325 , "RoundHouseB" },
    { 26330 , "RT_02_50" },
    { 26350 , "RTN_1A" },
    { 26370 , "RV2" },
    { 26415 , "RV3" },
    { 26460 , "RV5" },
    { 26505 , "RV10" },
    { 26550 , "RV17" },
    { 26595 , "RV18" },
    { 26610 , "RV_377" },
    { 26640 , "RVUM" },
    { 26660 , "RXN2_60" },
    { 26670 , "S_1810CD" },
    { 26685 , "SA2Guideline" },
    { 26730 , "SA3Goa" },
    { 26775 , "SA8GeckoDT" },
    { 26795 , "SA_12TELARILL" },
    { 26820 , "SAN7GadflyTI" },
    { 26865 , "SAN11Cads1UN" },
    { 26910 , "SaltPotAB" },
    { 26955 , "SATURNEII" },
    { 27000 , "ScanCan" },
    { 27045 , "ScanFix" },
    { 27090 , "ScanOdd" },
    { 27135 , "ScanThree" },
    { 27140 , "SCANTER_CSR_" },
    { 27141 , "SCORADS" },
    { 27150 , "SCOREBOARD" },
    { 27180 , "ScoupPlate" },
    { 27190 , "SCR_584" },
    { 27225 , "SeaArcher2" },
    { 27270 , "SeaHunter4MG" },
    { 27315 , "SeaHunter4TA" },
    { 27360 , "SeaHunter4TT" },
    { 27405 , "SeaGull" },
    { 27450 , "SeaNet" },
    { 27495 , "SeaSpray" },
    { 27540 , "SeaTiger" },
    { 27570 , "Searchwater" },
    { 27585 , "SeleniaOrion7" },
    { 27630 , "Seleniatype912" },
    { 27675 , "SelenniaRAN12L_X" },
    { 27720 , "SelenniaRTN10X" },
    { 27765 , "SeliniaARP1645" },
    { 27810 , "SGR10200" },
    { 27855 , "SGR103_02" },
    { 27870 , "SGR_104" },
    { 27900 , "SheetBend" },
    { 27945 , "SheetCurve" },
    { 27990 , "ShipGlobe" },
    { 28035 , "ShipWheel" },
    { 28080 , "SGR114" },
    { 28125 , "ShoreWalkA" },
    { 28170 , "ShortHorn" },
    { 28215 , "ShotDome" },
    { 28260 , "SideGlobeJN" },
    { 28280 , "PRV_11SideNet" },
    { 28305 , "SideWalkA" },
    { 28350 , "SignaalDA02" },
    { 28395 , "SignaalDA05" },
    { 28440 , "SignaalDA08" },
    { 28485 , "SignaalLW08" },
    { 28530 , "SignaalLWOR" },
    { 28575 , "SignaalM45" },
    { 28620 , "SignaalMW08" },
    { 28665 , "SignaalSMART" },
    { 28710 , "SignaalSTING" },
    { 28755 , "SignaalSTIR" },
    { 28800 , "SignaalWM20_2" },
    { 28845 , "SignaalWM25" },
    { 28890 , "SignaalWM27" },
    { 28935 , "SignaalWM28" },
    { 28980 , "SignaalZW01" },
    { 29025 , "SignaalZW06" },
    { 29070 , "SkiPole" },
    { 29115 , "SkinHead" },
    { 29160 , "SkipSpin" },
    { 29185 , "SKYGUARDTAUAR_1021" },
    { 29190 , "SKYGUARDTTUAR_1021" },
    { 29205 , "SkyWatch" },
    { 29215 , "SKYSHADOW" },
    { 29220 , "SKYSHIELDTA" },
    { 29250 , "SL" },
    { 29270 , "SL_ALQ_234" },
    { 29295 , "SlapShotE" },
    { 29340 , "SlimNet" },
    { 29385 , "SlotBackA" },
    { 29400 , "SlotBackILL" },
    { 29430 , "SlotBackB" },
    { 29440 , "SlotRest" },
    { 29475 , "SMA3RM" },
    { 29520 , "SMA3RM20" },
    { 29565 , "SMA3RM20A_SMG" },
    { 29610 , "SMABPS704" },
    { 29655 , "SMASPIN749_V_2" },
    { 29700 , "SMASPN703" },
    { 29745 , "SMASPN751" },
    { 29790 , "SMASPOS748" },
    { 29835 , "SMASPQ2" },
    { 29880 , "SMASPQ2D" },
    { 29925 , "SMASPQ701" },
    { 29970 , "SMASPS702UPX" },
    { 30015 , "SMAST2OTOMATIIMH" },
    { 30060 , "SMA718Beacon" },
    { 30080 , "SNAPSHOT" },
    { 30105 , "SnoopDrift" },
    { 30150 , "SnoopHead" },
    { 30195 , "SnoopPair" },
    { 30240 , "SnoopPlate" },
    { 30285 , "SnoopSlab" },
    { 30330 , "SnoopTray" },
    { 30375 , "SnoopTray1" },
    { 30420 , "SnoopTray2" },
    { 30465 , "SnoopWatch" },
    { 304709 , "S18M1SnowDrift" },
    { 30510 , "SO_1" },
    { 30520 , "SO_12" },
    { 30555 , "SOACommunist" },
    { 30580 , "SO_69" },
    { 30600 , "SockEye" },
    { 30645 , "SOM64" },
    { 30670 , "SPADATT" },
    { 30690 , "Sparrow_AIM_RIM_7_ILL" },
    { 30700 , "SperryM_3" },
    { 30735 , "SPG53F" },
    { 30780 , "SPG70_RTN10X_" },
    { 30825 , "SPG74_RTN20X_" },
    { 30870 , "SPG75_RTN30X_" },
    { 30915 , "SPG76_RTN30X_" },
    { 30960 , "SpinScanA" },
    { 31005 , "SpinScanB" },
    { 31050 , "SpinTrough" },
    { 31095 , "SplashDrop" },
    { 31140 , "SPN35A" },
    { 31185 , "SPN41" },
    { 31230 , "SPN42" },
    { 31275 , "SPN43A" },
    { 31320 , "SPN43B" },
    { 31365 , "SPN44" },
    { 31410 , "SPN46" },
    { 31455 , "SPN703" },
    { 31500 , "SPN728_V_1" },
    { 31545 , "SPN748" },
    { 31590 , "SPN750" },
    { 31635 , "SpongeCake" },
    { 31680 , "P_12SpoonRest" },
    { 31725 , "SPQ712_RAN12L_X_" },
    { 31770 , "SPS6C" },
    { 31815 , "SPS10F" },
    { 31860 , "SPS12" },
    { 31905 , "_deleted_SPS58" },
    { 31950 , "_deleted_SPS64" },
    { 31995 , "SPS768_RANEL_" },
    { 32040 , "SPS774_RAN10S_" },
    { 32085 , "SPY790" },
    { 32130 , "SquareHead" },
    { 32175 , "SquarePair" },
    { 32220 , "SquareSlot" },
    { 32265 , "SquareTie" },
    { 32310 , "SquashDome" },
    { 32330 , "P_15MSquatEye" },
    { 32355 , "SquintEye" },
    { 32400 , "SRN6" },
    { 32445 , "SRN15" },
    { 32490 , "SRN745" },
    { 32535 , "SRO1" },
    { 32580 , "SRO2" },
    { 32625 , "SSC2BSamletMG" },
    { 32670 , "SSN2ABCSSC" },
    { 32715 , "SSN2ABCSSC2A3A2MH" },
    { 32760 , "SSN2CSeeker" },
    { 32805 , "SSN2CDStyx" },
    { 32850 , "SSN2CDStyxCDMH" },
    { 32895 , "SSN3SSCSSC18BN" },
    { 32940 , "SSN3BSepalAL" },
    { 32985 , "SSN3BSepalMH" },
    { 33030 , "SSN9Siren" },
    { 33075 , "SSN9SirenAL" },
    { 33120 , "SSN9SirenMH" },
    { 33165 , "SSN12SandboxAL" },
    { 33210 , "SSN12SandboxMH" },
    { 33255 , "SSN19Shipwreck" },
    { 33300 , "SSN19ShipwreckAL" },
    { 33345 , "SSN19ShipwreckMH" },
    { 33390 , "SSN21AL" },
    { 33435 , "SSN22Sunburn" },
    { 33480 , "SSN22SunburnMH" },
    { 33525 , "StoneCake" },
    { 33570 , "STR41" },
    { 33590 , "StraightFlushTA" },
    { 33595 , "StraightFlushTT" },
    { 33600 , "StraightFlushILL" },
    { 33615 , "StrikeOut" },
    { 33660 , "StrutCurve" },
    { 33705 , "StrutPair" },
    { 33750 , "StrutPair1" },
    { 33795 , "StrutPair2" },
    { 33840 , "SunVisor" },
    { 33860 , "Superfledermaus" },
    { 33885 , "SwiftRod1" },
    { 33930 , "SwiftRod2" },
    { 33975 , "T1166" },
    { 34020 , "T1171" },
    { 34040 , "T1202" },
    { 34065 , "T6004" },
    { 34110 , "T6031" },
    { 34155 , "T8067" },
    { 34200 , "T8068" },
    { 34245 , "T8124" },
    { 34290 , "T8408" },
    { 34335 , "T8911" },
    { 34380 , "T8937" },
    { 34425 , "T8944" },
    { 34470 , "T8987" },
    { 34515 , "P_14TallKing" },
    { 34560 , "TallMike" },
    { 34605 , "TallPath" },
    { 34625 , "TeamWork" },
    { 34640 , "THAADGBR" },
    { 34650 , "THD225" },
    { 34670 , "THD1940Picador" },
    { 34695 , "THD5500" },
    { 34740 , "ThinPath" },
    { 34785 , "PRV_9ThinSkin" },
    { 34795 , "ThompsonCSFTA_10" },
    { 34830 , "ThompsonCSFTHD1040Neptune" },
    { 34875 , "ThompsonCSFCalypso" },
    { 34920 , "ThompsonCSFCASTOR" },
    { 34965 , "ThompsonCSFCastorII" },
    { 35010 , "ThompsonCSFDRBC32A" },
    { 35055 , "ThompsonCSFDRBJ11D_E" },
    { 35100 , "ThompsonCSFDRBV15A" },
    { 35145 , "ThompsonCSFDRBV15C" },
    { 35190 , "ThompsonCSFDRBV22D" },
    { 35235 , "ThompsonCSFDRBV23B" },
    { 35280 , "ThompsonCSFDRUA33" },
    { 35325 , "ThompsonCSFMarsDRBV21A" },
    { 35370 , "ThompsonCSFSeaTiger" },
    { 35415 , "ThompsonCSFTriton" },
    { 35460 , "ThompsonCSFVegawithDRBC32E" },
    { 35480 , "TRS_2105TIGER_G" },
    { 35490 , "TRS_2100TIGER_S" },
    { 35505 , "TieRods" },
    { 3555036 , "D6TinShield" },
    { 35570 , "TinTrap" },
    { 35580 , "TIRSPONDER" },
    { 35595 , "ToadStool1" },
    { 35640 , "ToadStool2" },
    { 35685 , "ToadStool3" },
    { 35730 , "ToadStool4" },
    { 35775 , "ToadStool5" },
    { 35800 , "TombStone" },
    { 35820 , "TopBow" },
    { 35865 , "TopDome" },
    { 35910 , "TopKnot" },
    { 35955 , "TopMesh" },
    { 36000 , "TopPair" },
    { 36045 , "TopPlate" },
    { 36090 , "TopSail" },
    { 36135 , "TopSteer" },
    { 36180 , "TopTrough" },
    { 36220 , "ScrumHalfTA" },
    { 36225 , "TorScrumHalfTTTor" },
    { 36230 , "ScrumHalfMG" },
    { 36270 , "TrackDish" },
    { 36315 , "TORSOM" },
    { 36360 , "TrapDoor" },
    { 36380 , "TRISPONDE" },
    { 36405 , "TRS3033" },
    { 36420 , "TRS3405" },
    { 36425 , "TRS3410" },
    { 36430 , "TRS3415" },
    { 36450 , "TRS_N" },
    { 36495 , "TSE5000" },
    { 36540 , "TSR333" },
    { 36585 , "TubeArm" },
    { 36630 , "TwinEyes" },
    { 36675 , "TwinPill" },
    { 36720 , "TwinScan" },
    { 36765 , "TwinScanRo" },
    { 36810 , "TwoSpot" },
    { 36855 , "TYPE262" },
    { 36900 , "TYPE275" },
    { 36945 , "TYPE293" },
    { 36990 , "TYPE343SUNVISORB" },
    { 37035 , "TYPE347B" },
    { 37050 , "Type_404A_CH_" },
    { 37080 , "Type756" },
    { 37125 , "TYPE903" },
    { 37170 , "TYPE909TI" },
    { 37215 , "TYPE909TT" },
    { 37260 , "TYPE910" },
    { 37265 , "TYPE_931_CH_" },
    { 37305 , "TYPE965" },
    { 37350 , "TYPE967" },
    { 37395 , "TYPE968" },
    { 37440 , "TYPE974" },
    { 37485 , "TYPE975" },
    { 37530 , "TYPE978" },
    { 37575 , "TYPE992" },
    { 37620 , "TYPE993" },
    { 37665 , "TYPE994" },
    { 37710 , "TYPE1006_1_" },
    { 37755 , "TYPE1006_2_" },
    { 37800 , "TYPE1022" },
    { 37845 , "UKMK10" },
    { 37850 , "UPS_220C" },
    { 37890 , "UPX110" },
    { 37935 , "UPX27" },
    { 37980 , "URN20" },
    { 38025 , "URN25" },
    { 38045 , "VOLEXIII_IV" },
    { 38070 , "W8818" },
    { 38115 , "W8838" },
    { 38120 , "W8852" },
    { 38160 , "WAS_74S" },
    { 38205 , "WaspHead" },
    { 38210 , "WATCHDOG" },
    { 38250 , "WatchGuard" },
    { 38260 , "Watchman" },
    { 38295 , "WesternElectricMK10" },
    { 38340 , "WestinghouseElectricSPG50" },
    { 38385 , "WestinghouseElectricW120" },
    { 38430 , "WestinghouseSPS29C" },
    { 38475 , "WestinghouseSPS37" },
    { 38520 , "WetEye" },
    { 38565 , "WetEyeMod" },
    { 38570 , "WGU_41_B" },
    { 38572 , "WGU_44_B" },
    { 38610 , "Whiff" },
    { 38655 , "WhiffBrick" },
    { 38700 , "WhiffFire" },
    { 38715 , "WHITEHOUSE" },
    { 38745 , "WildCard" },
    { 38790 , "WitchEight" },
    { 38835 , "WitchFive" },
    { 38880 , "WM2XSeries" },
    { 38925 , "WM2XSeriesCAS" },
    { 38950 , "WSR_74C" },
    { 38955 , "WSR_74S" },
    { 38970 , "WoodGage" },
    { 39015 , "YardRake" },
    { 39060 , "YewLoop" },
    { 39105 , "Yo_Yo" },
    { 451226 , "DECCAMIL" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEmitterName()
{
	return sizeof( EmitterNameDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEmitterName( KUINT32 Index )
{
	return &EmitterNameDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEmitterName( KINT32 Value )
{
    return GetEnumAsString( EmitterNameDescriptor, sizeof( EmitterNameDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEmitterName( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EmitterNameDescriptor, sizeof( EmitterNameDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEmitterName()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEmitterName( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEmitterName( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEmitterName( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EmitterFunction

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EmitterFunctionDescriptor[] =
{
    { 0 , "OtherFunctionFunction" },
    { 1 , "Multi_functionFunction" },
    { 2 , "EarlyWarning_SurveillanceFunction" },
    { 3 , "HeightFindingFunction" },
    { 4 , "FireControlFunction" },
    { 5 , "Acquisition_DetectionFunction" },
    { 6 , "TrackingFunction" },
    { 7 , "Guidance_IlluminationFunction" },
    { 8 , "Firingpoint_launchpointlocationFunction" },
    { 9 , "RangingFunction" },
    { 10 , "RadarAltimeterFunction" },
    { 11 , "ImagingFunction" },
    { 12 , "MotionDetectionFunction" },
    { 13 , "NavigationFunction" },
    { 14 , "Weather_MeterologicalFunction" },
    { 15 , "InstrumentationFunction" },
    { 16 , "Identification_Classification_includingIFF_Function" },
    { 17 , "AAA_Anti_AircraftArtillery_FireControlFunction" },
    { 18 , "AirSearch_BombFunction" },
    { 19 , "AirInterceptFunction" },
    { 20 , "AltimeterFunction" },
    { 21 , "AirMappingFunction" },
    { 22 , "AirTrafficControlFunction" },
    { 23 , "BeaconFunction" },
    { 24 , "BattlefieldSurveillanceFunction" },
    { 25 , "GroundControlApproachFunction" },
    { 26 , "GroundControlInterceptFunction" },
    { 27 , "CoastalSurveillanceFunction" },
    { 28 , "Decoy_MimicFunction" },
    { 29 , "DataTransmissionFunction" },
    { 30 , "EarthSurveillanceFunction" },
    { 31 , "GunLayBeaconFunction" },
    { 32 , "GroundMappingFunction" },
    { 33 , "HarborSurveillanceFunction" },
    { 35 , "ILS_InstrumentLandingSystem_Function" },
    { 36 , "IonosphericSoundFunction" },
    { 37 , "InterrogatorFunction" },
    { 38 , "BarrageJammingFunction" },
    { 39 , "ClickJammingFunction" },
    { 41 , "FrequencySweptJammingFunction" },
    { 42 , "JammingFunction" },
    { 44 , "PulsedJammingFunction" },
    { 45 , "RepeaterJammingFunction" },
    { 46 , "SpotNoiseJammingFunction" },
    { 47 , "MissileAcquisitionFunction" },
    { 48 , "MissileDownlinkFunction" },
    { 50 , "SpaceFunction" },
    { 51 , "SurfaceSearchFunction" },
    { 52 , "ShellTrackingFunction" },
    { 56 , "TelevisionFunction" },
    { 57 , "UnknownFunction" },
    { 58 , "VideoRemotingFunction" },
    { 59 , "ExperimentalorTrainingFunction" },
    { 60 , "MissileGuidanceFunction" },
    { 61 , "MissileHomingFunction" },
    { 62 , "MissileTrackingFunction" },
    { 64 , "Jamming_noiseFunction" },
    { 65 , "Jamming_deceptionFunction" },
    { 71 , "Navigation_DistanceMeasuringEquipmentFunction" },
    { 72 , "TerrainFollowingFunction" },
    { 73 , "WeatherAvoidanceFunction" },
    { 74 , "ProximityFuseFunction" },
    { 76 , "RadiosondeFunction" },
    { 77 , "SonobuoyFunction" },
    { 96 , "Weapon_non_lethalFunction" },
    { 97 , "Weapon_lethalFunction" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEmitterFunction()
{
	return sizeof( EmitterFunctionDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEmitterFunction( KUINT32 Index )
{
	return &EmitterFunctionDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEmitterFunction( KINT32 Value )
{
    return GetEnumAsString( EmitterFunctionDescriptor, sizeof( EmitterFunctionDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEmitterFunction( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EmitterFunctionDescriptor, sizeof( EmitterFunctionDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEmitterFunction()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEmitterFunction( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEmitterFunction( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEmitterFunction( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for StateUpdateIndicator

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor StateUpdateIndicatorDescriptor[] =
{
    { 0 , "StateUpdate" },
    { 1 , "ChangedDataUpdate" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeStateUpdateIndicator()
{
	return sizeof( StateUpdateIndicatorDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorStateUpdateIndicator( KUINT32 Index )
{
	return &StateUpdateIndicatorDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStateUpdateIndicator( KINT32 Value )
{
    return GetEnumAsString( StateUpdateIndicatorDescriptor, sizeof( StateUpdateIndicatorDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringStateUpdateIndicator( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( StateUpdateIndicatorDescriptor, sizeof( StateUpdateIndicatorDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeStateUpdateIndicator()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorStateUpdateIndicator( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStateUpdateIndicator( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringStateUpdateIndicator( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for HighDensityTrackJam

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor HighDensityTrackJamDescriptor[] =
{
    { 0 , "NotSelected" },
    { 1 , "Selected" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeHighDensityTrackJam()
{
	return sizeof( HighDensityTrackJamDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorHighDensityTrackJam( KUINT32 Index )
{
	return &HighDensityTrackJamDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringHighDensityTrackJam( KINT32 Value )
{
    return GetEnumAsString( HighDensityTrackJamDescriptor, sizeof( HighDensityTrackJamDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringHighDensityTrackJam( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( HighDensityTrackJamDescriptor, sizeof( HighDensityTrackJamDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeHighDensityTrackJam()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorHighDensityTrackJam( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringHighDensityTrackJam( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringHighDensityTrackJam( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for PassiveParameterIndex

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor PassiveParameterIndexDescriptor[] =
{
    { 0 , "OtherPPI" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePassiveParameterIndex()
{
	return sizeof( PassiveParameterIndexDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPassiveParameterIndex( KUINT32 Index )
{
	return &PassiveParameterIndexDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPassiveParameterIndex( KINT32 Value )
{
    return GetEnumAsString( PassiveParameterIndexDescriptor, sizeof( PassiveParameterIndexDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPassiveParameterIndex( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( PassiveParameterIndexDescriptor, sizeof( PassiveParameterIndexDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePassiveParameterIndex()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPassiveParameterIndex( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPassiveParameterIndex( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPassiveParameterIndex( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AdditionalPassiveParameterIndex

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AdditionalPassiveParameterIndexDescriptor[] =
{
    { 0 , "OtherAPPI" },
    { 1 , "GrahamsMKVCoffeeMaker" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAdditionalPassiveParameterIndex()
{
	return sizeof( AdditionalPassiveParameterIndexDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAdditionalPassiveParameterIndex( KUINT32 Index )
{
	return &AdditionalPassiveParameterIndexDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAdditionalPassiveParameterIndex( KINT32 Value )
{
    return GetEnumAsString( AdditionalPassiveParameterIndexDescriptor, sizeof( AdditionalPassiveParameterIndexDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAdditionalPassiveParameterIndex( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AdditionalPassiveParameterIndexDescriptor, sizeof( AdditionalPassiveParameterIndexDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAdditionalPassiveParameterIndex()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAdditionalPassiveParameterIndex( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAdditionalPassiveParameterIndex( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAdditionalPassiveParameterIndex( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for PropulsionPlantConfiguration

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor PropulsionPlantConfigurationDescriptor[] =
{
    { 0 , "OtherPPC_HMMS_Off" },
    { 1 , "Diesel_Electric_HMMS_Off" },
    { 2 , "Diesel_HMMS_Off" },
    { 3 , "Battery_HMMS_Off" },
    { 4 , "Turbine_Reduction_HMMS_Off" },
    { 6 , "Steam_HMMS_Off" },
    { 7 , "Gas_Turbine_HMMS_Off" },
    { 128 , "OtherPPC_HMMS_On" },
    { 129 , "Diesel_Electric_HMMS_On" },
    { 130 , "Diesel_HMMS_On" },
    { 131 , "Battery_HMMS_On" },
    { 132 , "Turbine_Reduction_HMMS_On" },
    { 134 , "Steam_HMMS_On" },
    { 135 , "Gas_Turbine_HMMS_On" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePropulsionPlantConfiguration()
{
	return sizeof( PropulsionPlantConfigurationDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPropulsionPlantConfiguration( KUINT32 Index )
{
	return &PropulsionPlantConfigurationDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPropulsionPlantConfiguration( KINT32 Value )
{
    return GetEnumAsString( PropulsionPlantConfigurationDescriptor, sizeof( PropulsionPlantConfigurationDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPropulsionPlantConfiguration( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( PropulsionPlantConfigurationDescriptor, sizeof( PropulsionPlantConfigurationDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePropulsionPlantConfiguration()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPropulsionPlantConfiguration( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPropulsionPlantConfiguration( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPropulsionPlantConfiguration( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AcousticSystemName

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AcousticSystemNameDescriptor[] =
{
    { 0 , "OtherAcousticSystemName" },
    { 1 , "AN_BQQ_5" },
    { 2 , "AN_SSQ_62" },
    { 3 , "AN_SQS_23" },
    { 4 , "AN_SQS_26" },
    { 5 , "AN_SQS_53" },
    { 6 , "ALFS" },
    { 7 , "LFA" },
    { 8 , "AN_AQS_901" },
    { 9 , "AN_AQS_902" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAcousticSystemName()
{
	return sizeof( AcousticSystemNameDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAcousticSystemName( KUINT32 Index )
{
	return &AcousticSystemNameDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAcousticSystemName( KINT32 Value )
{
    return GetEnumAsString( AcousticSystemNameDescriptor, sizeof( AcousticSystemNameDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAcousticSystemName( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AcousticSystemNameDescriptor, sizeof( AcousticSystemNameDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAcousticSystemName()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAcousticSystemName( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAcousticSystemName( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAcousticSystemName( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AcousticSystemFunction

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AcousticSystemFunctionDescriptor[] =
{
    { 0 , "OtherAcousticSystemFunction" },
    { 1 , "PlatformSearch_Detect_Track" },
    { 2 , "Navigation" },
    { 3 , "MineHunting" },
    { 4 , "WeaponSearch_Detect_Track_Detect" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAcousticSystemFunction()
{
	return sizeof( AcousticSystemFunctionDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAcousticSystemFunction( KUINT32 Index )
{
	return &AcousticSystemFunctionDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAcousticSystemFunction( KINT32 Value )
{
    return GetEnumAsString( AcousticSystemFunctionDescriptor, sizeof( AcousticSystemFunctionDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAcousticSystemFunction( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AcousticSystemFunctionDescriptor, sizeof( AcousticSystemFunctionDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAcousticSystemFunction()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAcousticSystemFunction( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAcousticSystemFunction( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAcousticSystemFunction( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ActiveEmissionParameterIndex

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ActiveEmissionParameterIndexDescriptor[] =
{
    { 0 , "OtherActiveEmissionParameterIndex" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActiveEmissionParameterIndex()
{
	return sizeof( ActiveEmissionParameterIndexDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActiveEmissionParameterIndex( KUINT32 Index )
{
	return &ActiveEmissionParameterIndexDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActiveEmissionParameterIndex( KINT32 Value )
{
    return GetEnumAsString( ActiveEmissionParameterIndexDescriptor, sizeof( ActiveEmissionParameterIndexDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActiveEmissionParameterIndex( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ActiveEmissionParameterIndexDescriptor, sizeof( ActiveEmissionParameterIndexDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActiveEmissionParameterIndex()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActiveEmissionParameterIndex( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActiveEmissionParameterIndex( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActiveEmissionParameterIndex( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ScanPattern

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ScanPatternDescriptor[] =
{
    { 0 , "ScanPatternNotUsed" },
    { 1 , "Conical" },
    { 2 , "Helical" },
    { 3 , "Raster" },
    { 4 , "SectorSearch" },
    { 5 , "ContinuousSearch" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeScanPattern()
{
	return sizeof( ScanPatternDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorScanPattern( KUINT32 Index )
{
	return &ScanPatternDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringScanPattern( KINT32 Value )
{
    return GetEnumAsString( ScanPatternDescriptor, sizeof( ScanPatternDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringScanPattern( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ScanPatternDescriptor, sizeof( ScanPatternDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeScanPattern()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorScanPattern( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringScanPattern( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringScanPattern( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for PowerSettingAircraft

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor PowerSettingAircraftDescriptor[] =
{
    { -100 , "AircraftEngineOff" },
    { 0 , "AircraftIdlePower" },
    { 50 , "AircraftMilPower" },
    { 51 , "AircraftMinAB" },
    { 100 , "AircraftMaxAB" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePowerSettingAircraft()
{
	return sizeof( PowerSettingAircraftDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPowerSettingAircraft( KUINT32 Index )
{
	return &PowerSettingAircraftDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPowerSettingAircraft( KINT32 Value )
{
    return GetEnumAsString( PowerSettingAircraftDescriptor, sizeof( PowerSettingAircraftDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPowerSettingAircraft( const KString & Value, KINT32 & ValueOut)
{
	return GetEnumFromString( PowerSettingAircraftDescriptor, sizeof( PowerSettingAircraftDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePowerSettingAircraft()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPowerSettingAircraft( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPowerSettingAircraft( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPowerSettingAircraft( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for PowerSettingHelicopter

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor PowerSettingHelicopterDescriptor[] =
{
    { -100 , "HelicopterEngineOff" },
    { 0 , "HelicopterIdlePower" },
    { 100 , "HelicopterMaxPower" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePowerSettingHelicopter()
{
	return sizeof( PowerSettingHelicopterDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPowerSettingHelicopter( KUINT32 Index )
{
	return &PowerSettingHelicopterDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPowerSettingHelicopter( KINT32 Value )
{
    return GetEnumAsString( PowerSettingHelicopterDescriptor, sizeof( PowerSettingHelicopterDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPowerSettingHelicopter( const KString & Value, KINT32 & ValueOut )
{
    return GetEnumFromString( PowerSettingHelicopterDescriptor, sizeof( PowerSettingHelicopterDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePowerSettingHelicopter()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPowerSettingHelicopter( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPowerSettingHelicopter( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPowerSettingHelicopter( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for PowerSettingTank

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor PowerSettingTankDescriptor[] =
{
    { -100 , "TankEngineOff" },
    { 0 , "TankIdlePower" },
    { 100 , "TankMaxPower" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePowerSettingTank()
{
	return sizeof( PowerSettingTankDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPowerSettingTank( KUINT32 Index )
{
	return &PowerSettingTankDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPowerSettingTank( KINT32 Value )
{
    return GetEnumAsString( PowerSettingTankDescriptor, sizeof( PowerSettingTankDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPowerSettingTank( const KString & Value, KINT32 & ValueOut )
{
    return GetEnumFromString( PowerSettingTankDescriptor, sizeof( PowerSettingTankDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePowerSettingTank()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPowerSettingTank( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPowerSettingTank( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPowerSettingTank( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

