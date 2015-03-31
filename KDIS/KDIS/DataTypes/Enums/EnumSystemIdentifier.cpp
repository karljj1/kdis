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

#include "./EnumSystemIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for SystemType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor SystemTypeDescriptor[] =
{
    { 0 , "OtherSystemType" },
    { 1 , "Mark_X_XII_ATCRBS_ModeS_Transponder" },
    { 2 , "Mark_X_XII_ATCRBS_ModeS_Interrogator" },
    { 3 , "Soviet_Transponder" },
    { 4 , "Soviet_Interrogator" },
    { 5 , "RRB_Transponder" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeSystemType()
{
	return sizeof( SystemTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorSystemType( KUINT32 Index )
{
	return &SystemTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemType( KINT32 Value )
{
    return GetEnumAsString( SystemTypeDescriptor, sizeof( SystemTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( SystemTypeDescriptor, sizeof( SystemTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeSystemType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorSystemType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for SystemName

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor SystemNameDescriptor[] =
{
    { 0 , "OtherSystemName" },
    { 1 , "Mark_X" },
    { 2 , "Mark_XII" },
    { 3 , "ATCRBS" },
    { 4 , "Soviet" },
    { 5 , "Mode_S" },
    { 6 , "Mark_X_XII_ATCRBS" },
    { 7 , "Mark_X_XII_ATCRBS_Mode_S" },
    { 8 , "ARI_5954" },
    { 9 , "ARI_5983" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeSystemName()
{
	return sizeof( SystemNameDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorSystemName( KUINT32 Index )
{
	return &SystemNameDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemName( KINT32 Value )
{
    return GetEnumAsString( SystemNameDescriptor, sizeof( SystemNameDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemName( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( SystemNameDescriptor, sizeof( SystemNameDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeSystemName()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorSystemName( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemName( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemName( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for SystemMode

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor SystemModeDescriptor[] =
{
    { 0 , "OtherSystemMode" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeSystemMode()
{
	return sizeof( SystemModeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorSystemMode( KUINT32 Index )
{
	return &SystemModeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemMode( KINT32 Value )
{
    return GetEnumAsString( SystemModeDescriptor, sizeof( SystemModeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemMode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( SystemModeDescriptor, sizeof( SystemModeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeSystemMode()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorSystemMode( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemMode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemMode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
