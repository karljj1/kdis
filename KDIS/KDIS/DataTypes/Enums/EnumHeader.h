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
    EnumHeader
    created:    17/09/2008
    author:     Karl Jones

    purpose:    Enums used in PDU header
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Protocol Version.                                                    */
/* Version of DIS being used                                            */
/* Used In:                                                             */
/*  PDU Header                                                          */
/************************************************************************/

enum ProtocolVersion
{
    Other_PV                                                          = 0,
    DIS_PDU_Version_1                                                 = 1,
    IEEE_1278_1993                                                    = 2,
    DIS_PDU_Version_2_Third_Draft                                     = 3,
    DIS_PDU_Version_2_Fourth_Draft                                    = 4,
    IEEE_1278_1_1995                                                  = 5,
    IEEE_1278_1A_1998                                                 = 6,
    IEEE_1278_1_2012                                                  = 7  
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeProtocolVersion();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorProtocolVersion( KUINT32 Index );

KString GetEnumAsStringProtocolVersion( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringProtocolVersion( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* PDU Type                                                             */
/* Indicates the type of PDU                                            */
/* X Indicates that the PDU has been implemented in KDIS                */
/* Used In:                                                             */
/*  PDU Header                                                          */
/* // X - indicates the PDU has been implemented                        */
/************************************************************************/

enum PDUType
{
    Other_PDU_Type                                                    = 0,
    Entity_State_PDU_Type                                             = 1,  // X
    Fire_PDU_Type                                                     = 2,  // X
    Detonation_PDU_Type                                               = 3,  // X
    Collision_PDU_Type                                                = 4,  // X
    Service_Request_PDU_Type                                          = 5,  // X
    Resupply_Offer_PDU_Type                                           = 6,  // X
    Resupply_Received_PDU_Type                                        = 7,  // X
    Resupply_Cancel_PDU_Type                                          = 8,  // X
    Repair_Complete_PDU_Type                                          = 9,  // X
    Repair_Response_PDU_Type                                          = 10, // X
    Create_Entity_PDU_Type                                            = 11, // X
    Remove_Entity_PDU_Type                                            = 12, // X
    Start_Resume_PDU_Type                                             = 13, // X
    Stop_Freeze_PDU_Type                                              = 14, // X
    Acknowledge_PDU_Type                                              = 15, // X
    Action_Request_PDU_Type                                           = 16, // X
    Action_Response_PDU_Type                                          = 17, // X
    Data_Query_PDU_Type                                               = 18, // X
    Set_Data_PDU_Type                                                 = 19, // X
    Data_PDU_Type                                                     = 20, // X
    Event_Report_PDU_Type                                             = 21, // X
    Message_PDU_Type                                                  = 22, // X AKA Comment PDU
    Electromagnetic_Emission_PDU_Type                                 = 23, // X
    Designator_PDU_Type                                               = 24, // X
    Transmitter_PDU_Type                                              = 25, // X
    Signal_PDU_Type                                                   = 26, // X
    Receiver_PDU_Type                                                 = 27, // X
    IFF_ATC_NAVAIDS_PDU_Type                                          = 28, // X
    UnderwaterAcoustic_PDU_Type                                       = 29, // X
    SupplementalEmission_EntityState_PDU_Type                         = 30, // X
    IntercomSignal_PDU_Type                                           = 31, // X
    IntercomControl_PDU_Type                                          = 32, // X
    AggregateState_PDU_Type                                           = 33, // X
    IsGroupOf_PDU_Type                                                = 34, // X
    TransferControl_PDU_Type                                          = 35, // X AKA Transfer Ownership PDU
    IsPartOf_PDU_Type                                                 = 36, // X
    MinefieldState_PDU_Type                                           = 37, // X
    MinefieldQuery_PDU_Type                                           = 38, // X
    MinefieldData_PDU_Type                                            = 39, // X
    MinefieldResponseNAK_PDU_Type                                     = 40, // X
    EnvironmentalProcess_PDU_Type                                     = 41, // X
    GriddedData_PDU_Type                                              = 42, // X
    PointObjectState_PDU_Type                                         = 43, // X
    LinearObjectState_PDU_Type                                        = 44, // X
    ArealObjectState_PDU_Type                                         = 45, // X
    TSPI_PDU_Type                                                     = 46, // X
    Appearance_PDU_Type                                               = 47, // X
    ArticulatedParts_PDU_Type                                         = 48, // X
    LEFire_PDU_Type                                                   = 49, // X
    LEDetonation_PDU_Type                                             = 50, // X
    CreateEntity_R_PDU_Type                                           = 51, // X
    RemoveEntity_R_PDU_Type                                           = 52, // X
    Start_Resume_R_PDU_Type                                           = 53, // X
    Stop_Freeze_R_PDU_Type                                            = 54, // X
    Acknowledge_R_PDU_Type                                            = 55, // X
    ActionRequest_R_PDU_Type                                          = 56, // X
    ActionResponse_R_PDU_Type                                         = 57, // X
    DataQuery_R_PDU_Type                                              = 58, // X
    SetData_R_PDU_Type                                                = 59, // X
    Data_R_PDU_Type                                                   = 60, // X
    EventReport_R_PDU_Type                                            = 61, // X
    Comment_R_PDU_Type                                                = 62, // X
    Record_R_PDU_Type                                                 = 63, // X
    SetRecord_R_PDU_Type                                              = 64, // X
    RecordQuery_R_PDU_Type                                            = 65, // X
    Collision_Elastic_PDU_Type                                        = 66, // X
    EntityStateUpdate_PDU_Type                                        = 67, // X
    DirectedEnergyFire_PDU_Type                                       = 68, // X Taken from 'IEEE 1278.1-200X Draft' SISO-REF-010 PCR Changes
    EntityDamageStatus_PDU_Type                                       = 69, // X Taken from 'IEEE 1278.1-200X Draft' SISO-REF-010 PCR Changes
    IO_Action_PDU_Type                                                = 70, // X Taken from 'IEEE 1278.1-200X Draft' SISO-REF-010 PCR Changes
    IO_Report_PDU_Type                                                = 71, // X Taken from 'IEEE 1278.1-200X Draft' SISO-REF-010 PCR Changes
    Attribute_PDU_Type                                                = 72, // X Taken from 'IEEE 1278.1-200X Draft' SISO-REF-010 PCR Changes
    Announce_Object_PDU_Type                                          = 129,
    Delete_Object_PDU_Type                                            = 130,
    Describe_Event_PDU_Type                                           = 132,
    Describe_Object_PDU_Type                                          = 133,
    Request_Event_PDU_Type                                            = 134,
    Request_Object_PDU_Type                                           = 135
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizePDUType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorPDUType( KUINT32 Index );

KString GetEnumAsStringPDUType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringPDUType( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Protocol Family                                                      */
/* Indicates the family of protocols to which the PDU belongs           */
/* Used In:                                                             */
/*  PDU Header                                                          */
/************************************************************************/

enum ProtocolFamily
{
    Other_PFF                                                         = 0,
    Entity_Information_Interaction                                    = 1,
    Warfare                                                           = 2,
    Logistics                                                         = 3,
    Radio_Communications                                              = 4,
    Simulation_Management                                             = 5,
    Distributed_Emission_Regeneration                                 = 6,
    EntityManagement                                                  = 7,
    Minefield                                                         = 8,
    SyntheticEnvironment                                              = 9,
    SimulationManagementwithReliability                               = 10,
    LiveEntity                                                        = 11,
    Non_RealTime                                                      = 12,
    Information_Operations                                            = 13, //   Taken from 'IEEE 1278.1-200X Draft' SISO-REF-010 PCR Changes
    Experimental_CGF                                                  = 129,
    Experimental_Entity_Infomation_Field_Instrumentation              = 130,
    Experimental_Warfare_Field_Instrumentation                        = 131,
    Experimental_Environment_Object_Infomation_Interaction             = 132,
    Experimental_Entity_Management                                    = 133
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeProtocolFamily();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorProtocolFamily( KUINT32 Index );

KString GetEnumAsStringProtocolFamily( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringProtocolFamily( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Time Stamp Type                                                      */
/* Indicates if the Time stamp is absolute or relative                  */
/* Absolute - Used when all simulation clocks are synchronized to UTC   */
/* Relative - Used when clocks are not synchronized, Each sim           */
/*            shall keep time begging with an arbitrary starting point  */
/*            The timestamp represents units of time passed since the   */
/*            beginning of the current hour.                            */
/* Used In:                                                             */
/*  PDU Header                                                          */
/************************************************************************/

enum TimeStampType
{
    RelativeTime                                                      = 0,
    AbsoluteTime                                                      = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeTimeStampType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorTimeStampType( KUINT32 Index );

KString GetEnumAsStringTimeStampType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTimeStampType( const KString & Value, KINT32 & ValueOut ); 

#if DIS_VERSION > 6

/************************************************************************/
/* LVC Indicator                                                        */
/* Indicates whether the data contained in this PDU is related to a     */
/* live, virtual or constructive entity. If the LVC designation is not  */
/* able to be determined, this field shall be set to No Statement (0).  */
/* Used In:                                                             */
/*  PDU Header 7                                                        */
/************************************************************************/

enum LVCIndicator
{
    NoStatementLVC                                                    = 0,
    LiveLVC                                                           = 1,
    VirtualLVC                                                        = 2,
    ConstructiveLVC                                                   = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeLVCIndicator();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorLVCIndicator( KUINT32 Index );

KString GetEnumAsStringLVCIndicator( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringLVCIndicator( const KString & Value, KINT32 & ValueOut ); 

#endif // DIS 7

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS

