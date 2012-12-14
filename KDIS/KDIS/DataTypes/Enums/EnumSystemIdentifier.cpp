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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemType( KINT32 Value )
{
    return GetEnumAsString( SystemTypeDescriptor, sizeof( SystemTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( SystemTypeDescriptor, sizeof( SystemTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemName( KINT32 Value )
{
    return GetEnumAsString( SystemNameDescriptor, sizeof( SystemNameDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemName( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( SystemNameDescriptor, sizeof( SystemNameDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemName( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

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

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemMode( KINT32 Value )
{
    return GetEnumAsString( SystemModeDescriptor, sizeof( SystemModeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemMode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( SystemModeDescriptor, sizeof( SystemModeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSystemMode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSystemMode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
