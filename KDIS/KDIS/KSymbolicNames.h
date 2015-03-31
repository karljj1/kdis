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
    KSymbolicNames
    created:    20/9/2008
	updated:    14/12/2012
    author:     Karl Jones

    purpose:    DIS Symbolic names used to represent DIS numeric values
*********************************************************************/

#define AGG_RESPONSE                                10                                  // s
#define ALL_AGGREGATES                              0xffff
#define ALL_APPLIC                                  0xffff
#define ALL_BEAMS                                   0xffff
#define ALL_EMITTERS                                0xffff
#define ALL_ENTITIES                                0xffff
#define ALL_OBJECTS                                 0xffff
#define ALL_SITES                                   0xffff
#define COLLISION_ELASTIC_TIMEOUT                   5                                   // s
#define COLLISION_THRSH                             0.1f                                // m/s
#define DE_ENERGY_THRSH                             0.01f 
#define DE_PRECISION_AIMING_THRSH                   0.5f                                // m
#define DRA_ORIENT_THRSH_DFLT                       3                                   // degs
#define DRA_POS_THRSH_DFLT                          1                                   // m
#define D_SPOT_NO_ENTITY                            NO_SITE , NO_APPLIC , NO_ENTITY
#define EE_AD_PULRAT_THRSH                          0.017f                              // rads/s
#define EE_AD_PULACC_THRSH                          0.017f                              // rads/s^2
#define EE_AZ_THRSH                                 1                                   // degs
#define EE_EL_THRSH                                 1                                   // degs
#define EE_ERP_THRSH                                1                                   // dB
#define EE_FREQ_THRSH                               1                                   // Hz
#define EE_FRNG_THRSH                               1                                   // Hz
#define EE_FT_VEL_THRSH                             1                                   // m/s
#define EE_FT_ACC_THRSH                             1                                   // m/s^2
#define EE_FT_MWD_THRSH                             10000                               //  m
#define EE_FT_KT_THRSH                              10                                  // s
#define EE_FT_ESP_THRSH                             10                                  // m
#define EE_HIGH_DENSITY_THRSH                       10                                  // entities/beam
#define EE_PRF_THRSH                                1                                   // Hz
#define EE_PW_THRSH                                 1                                   // µs
#define ENTITY_ID_UNKNOWN                           NO_SITE , NO_APPLIC , NO_ENTITY
#define EP_DIMENSION_THRSH                          1                                   // m
#define EP_NO_SEQUENCE                              0xffff                           
#define EP_POS_THRSH                                1                                   // m
#define EP_STATE_THRSH                              10                                  // ±%
#define GD_GEOMETRY_CHANGE                          10                                  // ±%
#define GD_STATE_CHANGE                             10                                  // ±%
#define HBT_ESPDU_KIND_CULTURAL_FEATURE             1                                   // min Tolerance: ±10%
#define HBT_ESPDU_KIND_ENVIRONMENTAL                1                                   // min Tolerance: ±10%
#define HBT_ESPDU_KIND_EXPENDABLE                   5                                   // s Tolerance: ±10%
#define HBT_ESPDU_KIND_LIFE_FORM                    1                                   // min Tolerance: ±10%
#define HBT_ESPDU_KIND_MUNITION                     5                                   // s Tolerance: ±10%
#define HBT_ESPDU_KIND_RADIO                        5                                   // s Tolerance: ±10%
#define HBT_ESPDU_KIND_SENSOR_EMITTER               5                                   // s Tolerance: ±10%
#define HBT_ESPDU_KIND_SUPPLY                       5                                   // s Tolerance: ±10%
#define HBT_ESPDU_PLATFORM_AIR                      5                                   // s Tolerance: ±10%
#define HBT_ESPDU_PLATFORM_LAND                     55                                  // s Tolerance: ±10%
#define HBT_ESPDU_PLATFORM_SPACE                    5                                   // s Tolerance: ±10%
#define HBT_ESPDU_PLATFORM_SUBSURFACE               55                                  // s Tolerance: ±10%
#define HBT_ESPDU_PLATFORM_SURFACE                  55                                  // s Tolerance: ±10%
#define HBT_PDU_AGGREGATE_STATE                     30                                  // s Tolerance: ±10%
#define HBT_PDU_APPEARANCE                          60                                  // s Tolerance: ±10%
#define HBT_PDU_DE_FIRE                             0.5f                                // s Tolerance: ±10%
#define HBT_PDU_DESIGNATOR                          5                                   // s Tolerance: ±10%
#define HBT_PDU_EE                                  10                                  // s Tolerance: ±10% 
#define HBT_PDU_ENTITY_DAMAGE                       10                                  // s Tolerance: ±10% 
#define HBT_PDU_ENVIRONMENTAL_PROCESS               15                                  // s Tolerance: ±10% 
#define HBT_PDU_GRIDDED_DATA                        15                                  // min Tolerance: ±10% 
#define HBT_PDU_IFF                                 10                                  // s Tolerance: ±10% 
#define HBT_PDU_ISGROUPOF                           1                                   // min Tolerance: ±10% 
#define HBT_PDU_MINEFIELD_DATA                      5                                   // s Tolerance: ±10%
#define HBT_PDU_MINEFIELD_STATE                     5                                   // s Tolerance: ±10%
#define HBT_PDU_RECEIVER                            1                                   // min Tolerance: ±10% 
#define HBT_PDU_SEES                                3                                   // min Tolerance: ±10% 
#define HBT_PDU_TRANSMITTER                         2                                   // s Tolerance: ±10% 
#define HBT_PDU_TSPI                                30                                  // s Tolerance: ±10% 
#define HBT_PDU_UA                                  3                                   // min Tolerance: ±10% 
#define HBT_STATIONARY                              1                                   // min Tolerance: ±10% 
#define HBT_TIMEOUT_MPLIER                          2.4f                                // NOTE - The entity timeout parameter is based on taking the specific entity heartbeat parameter and multiplying it by the HBT_TIMEOUT_MPLIER. 
#define HQ_TOD_DIFF_THRSH                           20                                  // ms
#define IFF_CHG_LATENCY                             2                                   // s
#define IFF_AZ_THRSH                                3                                   // deg
#define IFF_EL_THRSH                                3                                   // deg
#define IFF_PDU_FINAL                               10                                  // s
#define IFF_PDU_RESUME                              10                                  // s
#define MAX_PDU_SIZE_BITS                           65536
#define MAX_PDU_SIZE_OCTETS                         8192
#define MINEFIELD_CHANGE                            2.5f                                // s
#define MINEFIELD_RESPONSE_TIMER                    1                                   // s Tolerance: ±10% 
#define MULTIPLES_PRESENT                           0
#define NO_AGG                                      0
#define NO_APPLIC                                   0
#define NO_BEAM                                     0
#define NO_CATEGORY                                 0
#define NO_EMITTER                                  0
#define NO_ENTITY                                   0
#define NO_ENTITY_IMPACTED                          NO_SITE , NO_APPLIC , NO_ENTITY
#define NO_FIRE_MISSION                             0
#define NO_KIND                                     0
#define NO_LOCATION                                 NO_SITE , NO_APPLIC , NO_ENTITY
#define NO_OBJECT                                   0
#define NO_PATTERN                                  0
#define NO_REF_NUMBER                               0
#define NO_SITE                                     0
#define NO_SPECIFIC                                 0
#define NO_SPECIFIC_ENTITY                          NO_SITE , NO_APPLIC , NO_ENTITY
#define NO_SUBCAT                                   0
#define NO_VALUE                                    0
#define NON_SYNC_THRSH                              1                                   // min 
#define REPAR_REC_T1_DFLT                           5                                   // s
#define REPAR_SUP_T1_DFLT                           12                                  // s
#define REPAR_SUP_T2_DFLT                           12                                  // s
#define RESUP_REC_T1_DFLT                           5                                   // s
#define RESUP_REC_T2_DFLT                           55                                  // s
#define RESUP_SUP_T1_DFLT                           1                                   // min
#define RQST_ASSIGN_ID                              0xfffe
#define SEES_NDA_THRSH                              2                                   // ±° in the axis of deflection
#define SEES_PS_THRSH                               10                                  // ±% of the maximum value of the Power 
#define SEES_RPM_THRSH                              5                                   // ±% of the maximum speed in RPM
#define SMALLEST_MTU_OCTETS                         1400                                // Octets for Internet Protocol Version 4 networks
#define SM_REL_RETRY_CNT                            3
#define SM_REL_RETRY_DELAY                          2                                   // s
#define TARGET_ID_UNKNOWN                           NO_SITE , NO_APPLIC , NO_ENTITY
#define TIMESTAMP_AHEAD                             5                                   // s
#define TIMESTAMP_BEHIND                            5                                   // s
#define TI_TIMER1                                   2                                   // s
#define TI_TIMER2                                   12                                  // s
#define TO_AUTO_RESPONSE_TIMER                      5                                   // s
#define TO_MAN_RESPONSE_TIMER                       120                                 // s
#define TR_TIMER1                                   5                                   // s
#define TR_TIMER2                                   60                                  // s
#define TRANS_ORIENT_THRSH_DFLT                     180                                 // deg
#define TRANS_POS_THRSH_DFLT                        500                                 // m
#define UA_ORIENT_THRSH                             2                                   // deg
#define UA_POS_THRSH                                10                                  // m
#define UA_SRPM_ROC_THRSH                           10                                  // ±% of maximum rate of change
#define UA_SRPM_THRSH                               5                                   // ±% of maximum shaft rate in RPM
#define UNTIL_FURTHER_NOTICE                        65535
#define MUNITION_NOT_TRACKED                        NO_SITE , NO_APPLIC , NO_ENTITY
#define TARGET_IN_TJ_FIELD_DFLT                     10

// Deprecated Symbolic Values
#define HRT_BEAT_MOVE_TIMER                         2
#define HRT_BEAT_MPLIER                             2.4f
#define HRT_BEAT_TIMER                              5
