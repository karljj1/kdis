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

// TODO: You are here


#define HRT_BEAT_MOVE_TIMER                         2
#define HRT_BEAT_MPLIER                             2.4f
#define HRT_BEAT_TIMER                              5
#define MUNITION_NOT_TRACKED                        NO_SITE , NO_APPLIC , NO_ENTITY
#define NO_APPLIC                                   0
#define NO_ENTITY                                   0
#define NO_ENTITY_IMPACTED                          NO_SITE , NO_APPLIC , NO_ENTITY
#define NO_FIRE_MISSION                             0
#define NO_LOCATION                                 NO_SITE , NO_APPLIC , NO_ENTITY
#define NO_SITE                                     0
#define NO_SPECIFIC_ENTITY                          NO_SITE , NO_APPLIC , NO_ENTITY
#define REPAR_REC_T1_DFLT                           5
#define REPAR_SUP_T1_DFLT                           12
#define REPAR_SUP_T2_DFLT                           12
#define RESUP_REC_T1_DFLT                           5
#define RESUP_REC_T2_DFLT                           55
#define RESUP_SUP_T1_DFLT                           1
#define RQST_ASSIGN_ID                              0xffff
#define TARGET_ID_UNKNOWN                           NO_SITE , NO_APPLIC , NO_ENTITY
#define TARGET_IN_TJ_FIELD_DFLT                     10
#define TRANS_ORIENT_THRSH_DFLT                     180
#define TRANS_POS_THRSH_DFLT                        500
#define EP_NO_SEQUENCE                              0xffff

// DIS 7
#define UNTIL_FURTHER_NOTICE                        65535

