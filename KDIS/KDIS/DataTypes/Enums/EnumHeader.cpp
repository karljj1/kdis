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

#include "./EnumHeader.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for ProtocolVersion

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ProtocolVersionDescriptor[] =
{
    { 0 , "Other_PV" },
    { 1 , "DIS_PDU_Version_1" },
    { 2 , "IEEE_1278_1993" },
    { 3 , "DIS_PDU_Version_2_Third_Draft" },
    { 4 , "DIS_PDU_Version_2_Fourth_Draft" },
    { 5 , "IEEE_1278_1_1995" },
    { 6 , "IEEE_1278_1A_1998" },
    { 7 , "IEEE_1278_1_2012" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeProtocolVersion()
{
	return sizeof( ProtocolVersionDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorProtocolVersion( KUINT32 Index )
{
	return &ProtocolVersionDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringProtocolVersion( KINT32 Value )
{
    return GetEnumAsString( ProtocolVersionDescriptor, sizeof( ProtocolVersionDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringProtocolVersion( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ProtocolVersionDescriptor, sizeof( ProtocolVersionDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeProtocolVersion()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorProtocolVersion( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringProtocolVersion( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringProtocolVersion( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for PDUType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor PDUTypeDescriptor[] =
{
    { 0 , "Other_PDU_Type" },
    { 1 , "Entity_State_PDU_Type" },
    { 2 , "Fire_PDU_Type" },
    { 3 , "Detonation_PDU_Type" },
    { 4 , "Collision_PDU_Type" },
    { 5 , "Service_Request_PDU_Type" },
    { 6 , "Resupply_Offer_PDU_Type" },
    { 7 , "Resupply_Received_PDU_Type" },
    { 8 , "Resupply_Cancel_PDU_Type" },
    { 9 , "Repair_Complete_PDU_Type" },
    { 10 , "Repair_Response_PDU_Type" },
    { 11 , "Create_Entity_PDU_Type" },
    { 12 , "Remove_Entity_PDU_Type" },
    { 13 , "Start_Resume_PDU_Type" },
    { 14 , "Stop_Freeze_PDU_Type" },
    { 15 , "Acknowledge_PDU_Type" },
    { 16 , "Action_Request_PDU_Type" },
    { 17 , "Action_Response_PDU_Type" },
    { 18 , "Data_Query_PDU_Type" },
    { 19 , "Set_Data_PDU_Type" },
    { 20 , "Data_PDU_Type" },
    { 21 , "Event_Report_PDU_Type" },
    { 22 , "Message_PDU_Type" },
    { 23 , "Electromagnetic_Emission_PDU_Type" },
    { 24 , "Designator_PDU_Type" },
    { 25 , "Transmitter_PDU_Type" },
    { 26 , "Signal_PDU_Type" },
    { 27 , "Receiver_PDU_Type" },
    { 28 , "IFF_ATC_NAVAIDS_PDU_Type" },
    { 29 , "UnderwaterAcoustic_PDU_Type" },
    { 30 , "SupplementalEmission_EntityState_PDU_Type" },
    { 31 , "IntercomSignal_PDU_Type" },
    { 32 , "IntercomControl_PDU_Type" },
    { 33 , "AggregateState_PDU_Type" },
    { 34 , "IsGroupOf_PDU_Type" },
    { 35 , "TransferControl_PDU_Type" },
    { 36 , "IsPartOf_PDU_Type" },
    { 37 , "MinefieldState_PDU_Type" },
    { 38 , "MinefieldQuery_PDU_Type" },
    { 39 , "MinefieldData_PDU_Type" },
    { 40 , "MinefieldResponseNAK_PDU_Type" },
    { 41 , "EnvironmentalProcess_PDU_Type" },
    { 42 , "GriddedData_PDU_Type" },
    { 43 , "PointObjectState_PDU_Type" },
    { 44 , "LinearObjectState_PDU_Type" },
    { 45 , "ArealObjectState_PDU_Type" },
    { 46 , "TSPI_PDU_Type" },
    { 47 , "Appearance_PDU_Type" },
    { 48 , "ArticulatedParts_PDU_Type" },
    { 49 , "LEFire_PDU_Type" },
    { 50 , "LEDetonation_PDU_Type" },
    { 51 , "CreateEntity_R_PDU_Type" },
    { 52 , "RemoveEntity_R_PDU_Type" },
    { 53 , "Start_Resume_R_PDU_Type" },
    { 54 , "Stop_Freeze_R_PDU_Type" },
    { 55 , "Acknowledge_R_PDU_Type" },
    { 56 , "ActionRequest_R_PDU_Type" },
    { 57 , "ActionResponse_R_PDU_Type" },
    { 58 , "DataQuery_R_PDU_Type" },
    { 59 , "SetData_R_PDU_Type" },
    { 60 , "Data_R_PDU_Type" },
    { 61 , "EventReport_R_PDU_Type" },
    { 62 , "Comment_R_PDU_Type" },
    { 63 , "Record_R_PDU_Type" },
    { 64 , "SetRecord_R_PDU_Type" },
    { 65 , "RecordQuery_R_PDU_Type" },
    { 66 , "Collision_Elastic_PDU_Type" },
    { 67 , "EntityStateUpdate_PDU_Type" },
    { 68 , "DirectedEnergyFire_PDU_Type" },
    { 69 , "EntityDamageStatus_PDU_Type" },
    { 70 , "IO_Action_PDU_Type" },
    { 71 , "IO_Report_PDU_Type" },
    { 72 , "Attribute_PDU_Type" },
    { 129 , "Announce_Object_PDU_Type" },
    { 130 , "Delete_Object_PDU_Type" },
    { 132 , "Describe_Event_PDU_Type" },
    { 133 , "Describe_Object_PDU_Type" },
    { 134 , "Request_Event_PDU_Type" },
    { 135 , "Request_Object_PDU_Type" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePDUType()
{
	return sizeof( PDUTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPDUType( KUINT32 Index )
{
	return &PDUTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPDUType( KINT32 Value )
{
    return GetEnumAsString( PDUTypeDescriptor, sizeof( PDUTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPDUType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( PDUTypeDescriptor, sizeof( PDUTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePDUType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPDUType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPDUType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPDUType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ProtocolFamily

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ProtocolFamilyDescriptor[] =
{
    { 0 , "Other_PFF" },
    { 1 , "Entity_Information_Interaction" },
    { 2 , "Warfare" },
    { 3 , "Logistics" },
    { 4 , "Radio_Communications" },
    { 5 , "Simulation_Management" },
    { 6 , "Distributed_Emission_Regeneration" },
    { 7 , "EntityManagement" },
    { 8 , "Minefield" },
    { 9 , "SyntheticEnvironment" },
    { 10 , "SimulationManagementwithReliability" },
    { 11 , "LiveEntity" },
    { 12 , "Non_RealTime" },
    { 13 , "Information_Operations" },
    { 129 , "Experimental_CGF" },
    { 130 , "Experimental_Entity_Infomation_Field_Instrumentation" },
    { 131 , "Experimental_Warfare_Field_Instrumentation" },
    { 132 , "Experimental_Environment_Object_Infomation_Interaction" },
    { 133 , "Experimental_Entity_Management" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeProtocolFamily()
{
	return sizeof( ProtocolFamilyDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorProtocolFamily( KUINT32 Index )
{
	return &ProtocolFamilyDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringProtocolFamily( KINT32 Value )
{
    return GetEnumAsString( ProtocolFamilyDescriptor, sizeof( ProtocolFamilyDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringProtocolFamily( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ProtocolFamilyDescriptor, sizeof( ProtocolFamilyDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeProtocolFamily()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorProtocolFamily( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringProtocolFamily( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringProtocolFamily( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for TimeStampType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TimeStampTypeDescriptor[] =
{
    { 0 , "RelativeTime" },
    { 1, "AbsoluteTime" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTimeStampType()
{
	return sizeof( TimeStampTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTimeStampType( KUINT32 Index )
{
	return &TimeStampTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTimeStampType( KINT32 Value )
{
    return GetEnumAsString( TimeStampTypeDescriptor, sizeof( TimeStampTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTimeStampType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TimeStampTypeDescriptor, sizeof( TimeStampTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTimeStampType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTimeStampType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTimeStampType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTimeStampType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for LVCIndicator

#if DIS_VERSION > 6
#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor LVCIndicatorDescriptor[] =
{
    { 0 , "No Statement LVC" },
    { 1 , "Live LVC" },
    { 2 , "Virtual LVC" },
    { 3 , "Constructive LVC" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeLVCIndicator()
{
	return sizeof( LVCIndicatorDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorLVCIndicator( KUINT32 Index )
{
	return &LVCIndicatorDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringLVCIndicator( KINT32 Value )
{
    return GetEnumAsString( LVCIndicatorDescriptor, sizeof( LVCIndicatorDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringLVCIndicator( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( LVCIndicatorDescriptor, sizeof( LVCIndicatorDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeLVCIndicator()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorLVCIndicator( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringLVCIndicator( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringLVCIndicator( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
#endif
