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

#include "./EnumLink16.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for TimeSlotAllocationMode

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TimeSlotAllocationModeDescriptor[] =
{
    { 0 , "TSA0" },
    { 1 , "TSA1" },
    { 2 , "TSA2" },
    { 3 , "TSA3" },
	{ 4 , "TSA4" }
};

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringTimeSlotAllocationMode( KINT32 Value )
{
    return GetEnumAsString( TimeSlotAllocationModeDescriptor, sizeof( TimeSlotAllocationModeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringTimeSlotAllocationMode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TimeSlotAllocationModeDescriptor, sizeof( TimeSlotAllocationModeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringTimeSlotAllocationMode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringTimeSlotAllocationMode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for TransmittingTerminalPrimaryMode

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TransmittingTerminalPrimaryModeDescriptor[] =
{
    { 1 , "NTR" },
    { 2 , "JTIDS_Unit_Participant" }    
};

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringTransmittingTerminalPrimaryMode( KINT32 Value )
{
    return GetEnumAsString( TransmittingTerminalPrimaryModeDescriptor, sizeof( TransmittingTerminalPrimaryModeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringTransmittingTerminalPrimaryMode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TransmittingTerminalPrimaryModeDescriptor, sizeof( TransmittingTerminalPrimaryModeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringTransmittingTerminalPrimaryMode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringTransmittingTerminalPrimaryMode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for TransmittingTerminalSecondaryMode

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TransmittingTerminalSecondaryModeDescriptor[] =
{
    { 0 , "NoTransmittingTerminalSecondaryMode" },
    { 1 , "NetPositionReference" },   
	{ 2 , "PrimaryNavigationController" },
    { 3 , "SecondaryNavigationController" }
};

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringTransmittingTerminalSecondaryMode( KINT32 Value )
{
    return GetEnumAsString( TransmittingTerminalSecondaryModeDescriptor, sizeof( TransmittingTerminalSecondaryModeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringTransmittingTerminalSecondaryMode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TransmittingTerminalSecondaryModeDescriptor, sizeof( TransmittingTerminalSecondaryModeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringTransmittingTerminalSecondaryMode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringTransmittingTerminalSecondaryMode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for SynchronizationState

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor SynchronizationStateDescriptor[] =
{
    { 0 , "CoarseSynchronization" },
    { 1 , "FineSynchronization" }
};

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringSynchronizationState( KINT32 Value )
{
    return GetEnumAsString( SynchronizationStateDescriptor, sizeof( SynchronizationStateDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringSynchronizationState( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( SynchronizationStateDescriptor, sizeof( SynchronizationStateDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringSynchronizationState( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringSynchronizationState( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for SynchronizationState

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor Link16MessageTypeDescriptor[] =
{
    { 0 , "JTIDS_Header_Messages" },
    { 1 , "RTT_A_B" },
	{ 2 , "RTT_Reply" },
    { 3 , "JTIDS_Voice_CVSD" },
	{ 4 , "JTIDS_Voice_LPC10" },
    { 5 , "JTIDS_Voice_LPC12" },
	{ 6 , "JTIDS_LET" },
    { 7 , "VMF" }
};

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringLink16MessageType( KINT32 Value )
{
    return GetEnumAsString( Link16MessageTypeDescriptor, sizeof( Link16MessageTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringLink16MessageType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( Link16MessageTypeDescriptor, sizeof( Link16MessageTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumAsStringLink16MessageType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::LINK16::GetEnumFromStringLink16MessageType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif



