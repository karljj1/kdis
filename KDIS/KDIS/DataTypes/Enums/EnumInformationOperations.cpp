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
    { 5 , "OperationsSecurity_OPSEC" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringWarfareType( KINT32 Value )
{
    return GetEnumAsString( WarfareTypeDescriptor, sizeof( WarfareTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringWarfareType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( WarfareTypeDescriptor, sizeof( WarfareTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringWarfareType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionType( KINT32 Value )
{
    return GetEnumAsString( ActionTypeDescriptor, sizeof( ActionTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActionType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ActionTypeDescriptor, sizeof( ActionTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionPhase( KINT32 Value )
{
    return GetEnumAsString( ActionPhaseDescriptor, sizeof( ActionPhaseDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringActionPhase( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ActionPhaseDescriptor, sizeof( ActionPhaseDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringActionPhase( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStandardVariableType( KINT32 Value )
{
    return GetEnumAsString( StandardVariableTypeDescriptor, sizeof( StandardVariableTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringStandardVariableType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( StandardVariableTypeDescriptor, sizeof( StandardVariableTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStandardVariableType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOCommunicationsNodeType( KINT32 Value )
{
    return GetEnumAsString( IOCommunicationsNodeTypeDescriptor, sizeof( IOCommunicationsNodeTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOCommunicationsNodeType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOCommunicationsNodeTypeDescriptor, sizeof( IOCommunicationsNodeTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOCommunicationsNodeType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOStatus( KINT32 Value )
{
    return GetEnumAsString( IOStatusDescriptor, sizeof( IOStatusDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOStatus( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOStatusDescriptor, sizeof( IOStatusDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOStatus( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOLinkType( KINT32 Value )
{
    return GetEnumAsString( IOLinkTypeDescriptor, sizeof( IOLinkTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOLinkType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOLinkTypeDescriptor, sizeof( IOLinkTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOLinkType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOEffectType( KINT32 Value )
{
    return GetEnumAsString( IOEffectTypeDescriptor, sizeof( IOEffectTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOEffectType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOEffectTypeDescriptor, sizeof( IOEffectTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOEffectType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOEffectType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for IOEffectType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor IOReportTypeDescriptor[] =
{
    { 1 , "InitialReport" },
    { 2 , "UpdateReport" },
    { 3 , "FinalReport" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOReportType( KINT32 Value )
{
    return GetEnumAsString( IOReportTypeDescriptor, sizeof( IOReportTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOReportType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( IOReportTypeDescriptor, sizeof( IOReportTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringIOReportType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringIOReportType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
