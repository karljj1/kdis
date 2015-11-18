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

#include "./EnumSimulationManagement.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for RequiredReliabilityService

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor RequiredReliabilityServiceDescriptor[] =
{
    { 0 , "Acknowledged" },
    { 1 , "Unacknowledged" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRequiredReliabilityService()
{
	return sizeof( RequiredReliabilityServiceDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRequiredReliabilityService( KUINT32 Index )
{
	return &RequiredReliabilityServiceDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRequiredReliabilityService( KINT32 Value )
{
    return GetEnumAsString( RequiredReliabilityServiceDescriptor, sizeof( RequiredReliabilityServiceDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRequiredReliabilityService( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( RequiredReliabilityServiceDescriptor, sizeof( RequiredReliabilityServiceDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRequiredReliabilityService()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRequiredReliabilityService( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRequiredReliabilityService( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRequiredReliabilityService( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for StopFreezeReason

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor StopFreezeReasonDescriptor[] =
{
    { 0 , "OtherStopFreezeReason" },
    { 1 , "Recess" },
    { 2 , "Termination" },
    { 3 , "SystemFailure" },
    { 4 , "SecurityViolation" },
    { 5 , "EntityReconstitution" },
    { 6 , "StopForReset" },
    { 7 , "StopForRestart" },
    { 8 , "AbortTrainingReturnToTacticalOperations" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeStopFreezeReason()
{
	return sizeof( StopFreezeReasonDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorStopFreezeReason( KUINT32 Index )
{
	return &StopFreezeReasonDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStopFreezeReason( KINT32 Value )
{
    return GetEnumAsString( StopFreezeReasonDescriptor, sizeof( StopFreezeReasonDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringStopFreezeReason( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( StopFreezeReasonDescriptor, sizeof( StopFreezeReasonDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeStopFreezeReason()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorStopFreezeReason( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStopFreezeReason( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringStopFreezeReason( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for FrozenBehavior

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor FrozenBehaviorDescriptor[] =
{
    { 0 , "SimClock" },
    { 1 , "TransmitPDU" },
    { 2 , "ReceivePDU" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeFrozenBehavior()
{
	return sizeof( FrozenBehaviorDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorFrozenBehavior( KUINT32 Index )
{
	return &FrozenBehaviorDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringFrozenBehavior( KINT32 Value )
{
    return GetEnumAsString( FrozenBehaviorDescriptor, sizeof( FrozenBehaviorDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringFrozenBehavior( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( FrozenBehaviorDescriptor, sizeof( FrozenBehaviorDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeFrozenBehavior()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorFrozenBehavior( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringFrozenBehavior( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringFrozenBehavior( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AcknowledgeFlag

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AcknowledgeFlagDescriptor[] =
{
    { 1 , "CreateEntityPDU" },
    { 2 , "RemoveEntityPDU" },
    { 3 , "Start_ResumePDU" },
    { 4 , "Stop_FreezePDU" },
    { 5 , "TransferControlRequest" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAcknowledgeFlag()
{
	return sizeof( AcknowledgeFlagDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAcknowledgeFlag( KUINT32 Index )
{
	return &AcknowledgeFlagDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAcknowledgeFlag( KINT32 Value )
{
    return GetEnumAsString( AcknowledgeFlagDescriptor, sizeof( AcknowledgeFlagDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAcknowledgeFlag( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AcknowledgeFlagDescriptor, sizeof( AcknowledgeFlagDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAcknowledgeFlag()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAcknowledgeFlag( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAcknowledgeFlag( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAcknowledgeFlag( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AcknowledgeResponseFlag

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AcknowledgeResponseFlagDescriptor[] =
{
    { 0 , "OtherAcknowledgeResponseFlag" },
    { 1 , "AbleToComply" },
    { 2 , "UnableToComply" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAcknowledgeResponseFlag()
{
	return sizeof( AcknowledgeResponseFlagDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAcknowledgeResponseFlag( KUINT32 Index )
{
	return &AcknowledgeResponseFlagDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAcknowledgeResponseFlag( KINT32 Value )
{
    return GetEnumAsString( AcknowledgeResponseFlagDescriptor, sizeof( AcknowledgeResponseFlagDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAcknowledgeResponseFlag( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AcknowledgeResponseFlagDescriptor, sizeof( AcknowledgeResponseFlagDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAcknowledgeResponseFlag()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAcknowledgeResponseFlag( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAcknowledgeResponseFlag( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAcknowledgeResponseFlag( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ActionID

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ActionIDDescriptor[] =
{
    { 0 , "OtherActionID" },
    { 1 , "LocalStorageOfTheRequestedInformation" },
    { 2 , "InformSMofEvent_RanOutOfAmmunition" },
    { 3 , "InformSMofEvent_KilledInaAction" },
    { 4 , "InformSMofEvent_Damage" },
    { 5 , "InformSMofEvent_MobilityDisabled" },
    { 6 , "InformSMofEvent_FireDisabled" },
    { 7 , "InformSMofEvent_RanOutOfFuel" },
    { 8 , "RecallCheckPointData" },
    { 9 , "RecallInitialParameters" },
    { 10 , "InitiateTether_Lead" },
    { 11 , "InitiateTether_Follow" },
    { 12 , "Unthether" },
    { 13 , "InitiateServiceStationResupply" },
    { 14 , "InitiatetailGateResupply" },
    { 15 , "InitiaTehitchLead" },
    { 16 , "InitiaTehitchFollow" },
    { 17 , "Unhitch" },
    { 18 , "Mount" },
    { 19 , "Dismount" },
    { 20 , "StartDRC_DailyReadinessCheck" },
    { 21 , "StopDRC" },
    { 22 , "DataQuery" },
    { 23 , "StatusRequest" },
    { 24 , "SendObjectStateData" },
    { 25 , "Reconstitute" },
    { 26 , "LockSiteConfiguration" },
    { 27 , "UnlockSiteConfiguration" },
    { 28 , "UpdateSiteConfiguration" },
    { 29 , "QuerySiteConfiguration" },
    { 30 , "TetheringInformation" },
    { 31 , "MountIntent" },
    { 33 , "AcceptSubscription" },
    { 34 , "UnSubscribe" },
    { 35 , "TeleportEntity" },
    { 36 , "Changeaggregatestate" },
    { 37 , "RequestStartPDU" },
    { 38 , "WakeUpGetReadyForInitialization" },
    { 39 , "InitializeInternalparameters" },
    { 40 , "SendPlanData" },
    { 41 , "SynchronizeInternalClocks" },
    { 42 , "Run" },
    { 43 , "SaveInternalParameters" },
    { 44 , "SimulatemalFunction" },
    { 45 , "JoinExercise" },
    { 46 , "ResignExercise" },
    { 47 , "TimeAdvance" },
    { 100 , "TACCSFLOSRequest_Type1" },
    { 101 , "TACCSFLOSRequest_Type2" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActionID()
{
	return sizeof( ActionIDDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActionID( KUINT32 Index )
{
	return &ActionIDDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionID( KINT32 Value )
{
    return GetEnumAsString( ActionIDDescriptor, sizeof( ActionIDDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActionID( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ActionIDDescriptor, sizeof( ActionIDDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActionID()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActionID( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionID( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActionID( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for RequestStatus

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor RequestStatusDescriptor[] =
{
    { 0 , "OtherRequestStatus" },
    { 1 , "Pending" },
    { 2 , "Executing" },
    { 3 , "PartiallyComplete" },
    { 4 , "Complete" },
    { 5 , "RequestRejected" },
    { 6 , "ReTransmitRequestNow" },
    { 7 , "ReTransmitRequestLater" },
    { 8 , "InvalidTimeParameters" },
    { 9 , "SimulationTimeExceeded" },
    { 10 , "RequestDone" },
    { 100 , "TACCSFLOSReply_Type1" },
    { 101 , "TACCSFLOSReply_Type2" },
    { 201 , "JoinExerciseRequestRejected" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRequestStatus()
{
	return sizeof( RequestStatusDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRequestStatus( KUINT32 Index )
{
	return &RequestStatusDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRequestStatus( KINT32 Value )
{
    return GetEnumAsString( RequestStatusDescriptor, sizeof( RequestStatusDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRequestStatus( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( RequestStatusDescriptor, sizeof( RequestStatusDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRequestStatus()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRequestStatus( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRequestStatus( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRequestStatus( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EventType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EventTypeDescriptor[] =
{
    { 0 , "OtherEvent" },
    { 2 , "RanOutOfAmmunition" },
    { 3 , "KilledInAction" },
    { 4 , "Damage" },
    { 5 , "MobilityDisabled" },
    { 6 , "FireDisabled" },
    { 7 , "RanOutOfFuel" },
    { 8 , "EntityInitialization" },
    { 9 , "RequestForIndirectFireOrCASMission" },
    { 10 , "IndirectFireOrCASFire" },
    { 11 , "MinefieldEntry" },
    { 12 , "MinefieldDetonation" },
    { 13 , "VehicleMasterPowerOn" },
    { 14 , "VehicleMasterPowerOff" },
    { 15 , "AggregateStateChangeRequested" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEventType()
{
	return sizeof( EventTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEventType( KUINT32 Index )
{
	return &EventTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEventType( KINT32 Value )
{
    return GetEnumAsString( EventTypeDescriptor, sizeof( EventTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEventType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EventTypeDescriptor, sizeof( EventTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEventType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEventType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEventType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEventType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

