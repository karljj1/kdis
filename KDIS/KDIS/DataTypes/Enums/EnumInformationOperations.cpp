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

#include "./EnumInformationOperations.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for WarfareType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor WarfareTypeDescriptor[] =
{
    { 0 , "NoWarfareTypeStatement" },
    { 1 , "ElectronicWarfare_CW" },
    { 2 , "ComputerNetworkOperations_CNO" },
    { 3 , "PsychologicalOperations_PSYOPS" },
    { 4 , "MilitaryDeception_MILDEC" },
    { 5 , "OperationsSecurity_OPSEC" },
	{ 6 , "PhysicalAttack" }	
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeWarfareType()
{
	return sizeof( WarfareTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorWarfareType( KUINT32 Index )
{
	return &WarfareTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringWarfareType( KINT32 Value )
{
    return GetEnumAsString( WarfareTypeDescriptor, sizeof( WarfareTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringWarfareType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( WarfareTypeDescriptor, sizeof( WarfareTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeWarfareType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorWarfareType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringWarfareType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ActionType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ActionTypeDescriptor[] =
{
    { 0 , "NoActionTypeStatement" },
    { 1 , "IOAttackProfileData_Parametrics" },
    { 2 , "IOAttackComputerEffects" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActionType()
{
	return sizeof( ActionTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActionType( KUINT32 Index )
{
	return &ActionTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionType( KINT32 Value )
{
    return GetEnumAsString( ActionTypeDescriptor, sizeof( ActionTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActionType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ActionTypeDescriptor, sizeof( ActionTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActionType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActionType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ActionPhase

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ActionPhaseDescriptor[] =
{
    { 0 , "NoActionPhaseStatement" },
    { 1 , "StartAttackProfile" },
    { 2 , "EndAttackProfile" },
    { 3 , "ContinueAttackProfileWithChanges" },
    { 4 , "StartAttackEffects" },
    { 5 , "EndAttackEffects" },
    { 6 , "ContinueAttackEffectsWithChanges" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActionPhase()
{
	return sizeof( ActionPhaseDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActionPhase( KUINT32 Index )
{
	return &ActionPhaseDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionPhase( KINT32 Value )
{
    return GetEnumAsString( ActionPhaseDescriptor, sizeof( ActionPhaseDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActionPhase( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ActionPhaseDescriptor, sizeof( ActionPhaseDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeActionPhase()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorActionPhase( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionPhase( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for StandardVariableType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor StandardVariableTypeDescriptor[] =
{
    { 4000 , "DEPrecisionAimpointRecord" },
    { 4001 , "DEAreaAimpointRecord" },
    { 5500 , "IOEffectRecord" },
    { 5501 , "IOCommunicationsNodeRecord" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeStandardVariableType()
{
	return sizeof( StandardVariableTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorStandardVariableType( KUINT32 Index )
{
	return &StandardVariableTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStandardVariableType( KINT32 Value )
{
    return GetEnumAsString( StandardVariableTypeDescriptor, sizeof( StandardVariableTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringStandardVariableType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( StandardVariableTypeDescriptor, sizeof( StandardVariableTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeStandardVariableType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorStandardVariableType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStandardVariableType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringStandardVariableType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for IOCommunicationsNodeType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor IOCommunicationsNodeTypeDescriptor[] =
{
    { 0 , "NoStatementCommunicationsNodeType" },
    { 1 , "SenderNodeID" },
    { 2 , "ReceiverNodeID" },
    { 3 , "SenderReceiverNodeID" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOCommunicationsNodeType()
{
	return sizeof( IOCommunicationsNodeTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOCommunicationsNodeType( KUINT32 Index )
{
	return &IOCommunicationsNodeTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOCommunicationsNodeType( KINT32 Value )
{
    return GetEnumAsString( IOCommunicationsNodeTypeDescriptor, sizeof( IOCommunicationsNodeTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOCommunicationsNodeType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOCommunicationsNodeTypeDescriptor, sizeof( IOCommunicationsNodeTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOCommunicationsNodeType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOCommunicationsNodeType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOCommunicationsNodeType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOCommunicationsNodeType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for IOStatus

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor IOStatusDescriptor[] =
{
    { 0 , "NoStatementIOStatus" },
    { 1 , "EffectOnSender" },
    { 2 , "EffectOnReceiver" },
    { 3 , "EffectOnSenderAndReceiver" },
    { 4 , "EffectOnMessage" },
    { 5 , "EffectOnSenderAndMessage" },
    { 6 , "EffectOnReceiverAndMessage" },
    { 7 , "EffectOnSenderReceiverAndMessage" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOStatus()
{
	return sizeof( IOStatusDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOStatus( KUINT32 Index )
{
	return &IOStatusDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOStatus( KINT32 Value )
{
    return GetEnumAsString( IOStatusDescriptor, sizeof( IOStatusDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOStatus( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOStatusDescriptor, sizeof( IOStatusDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOStatus()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOStatus( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOStatus( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOStatus( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for IOLinkType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor IOLinkTypeDescriptor[] =
{
    { 0 , "NoStatementIOLinkType" },
    { 1 , "LogicalLink" },
    { 2 , "PhysicalNode" },
    { 3 , "PhysicalLink" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOLinkType()
{
	return sizeof( IOLinkTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOLinkType( KUINT32 Index )
{
	return &IOLinkTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOLinkType( KINT32 Value )
{
    return GetEnumAsString( IOLinkTypeDescriptor, sizeof( IOLinkTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOLinkType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOLinkTypeDescriptor, sizeof( IOLinkTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOLinkType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOLinkType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOLinkType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOLinkType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for IOEffectType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor IOEffectTypeDescriptor[] =
{
    { 0 , "NoStatementIOEffectType" },
    { 1 , "Denial" },
    { 2 , "Degraded" },
    { 3 , "Disrupt" },
    { 4 , "OtherIOEffectType" },
    { 5 , "TerminateEffect" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOEffectType()
{
	return sizeof( IOEffectTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOEffectType( KUINT32 Index )
{
	return &IOEffectTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOEffectType( KINT32 Value )
{
    return GetEnumAsString( IOEffectTypeDescriptor, sizeof( IOEffectTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOEffectType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOEffectTypeDescriptor, sizeof( IOEffectTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOEffectType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOEffectType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOEffectType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOEffectType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for IOReportType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor IOReportTypeDescriptor[] =
{
    { 1 , "InitialReport" },
    { 2 , "UpdateReport" },
    { 3 , "FinalReport" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOReportType()
{
	return sizeof( IOEffectTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOReportType( KUINT32 Index )
{
	return &IOEffectTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOReportType( KINT32 Value )
{
    return GetEnumAsString( IOReportTypeDescriptor, sizeof( IOReportTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOReportType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOReportTypeDescriptor, sizeof( IOReportTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeIOReportType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorIOReportType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOReportType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOReportType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
