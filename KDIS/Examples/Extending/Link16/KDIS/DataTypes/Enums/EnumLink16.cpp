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



