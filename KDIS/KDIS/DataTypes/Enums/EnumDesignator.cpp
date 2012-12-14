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

#include "./EnumDesignator.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for DesignatorCodeName

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DesignatorCodeNameDescriptor[] =
{
    { 0 , "OtherDesignatorCodeName" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDesignatorCodeName( KINT32 Value )
{
    return GetEnumAsString( DesignatorCodeNameDescriptor, sizeof( DesignatorCodeNameDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDesignatorCodeName( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DesignatorCodeNameDescriptor, sizeof( DesignatorCodeNameDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDesignatorCodeName( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDesignatorCodeName( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DesignatorCode

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DesignatorCodeDescriptor[] =
{
    { 0 , "OtherDesignatorCode" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDesignatorCode( KINT32 Value )
{
    return GetEnumAsString( DesignatorCodeDescriptor, sizeof( DesignatorCodeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDesignatorCode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DesignatorCodeDescriptor, sizeof( DesignatorCodeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDesignatorCode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDesignatorCode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif



//////////////////////////////////////////////////////////////////////////
// DIS 7

#if DIS_VERSION > 6

// Implementation of string values for BeamSpotShape

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor BeamSpotShapeDescriptor[] =
{
    { 0 , "OtherBeamSpotShape" },
	{ 1 , "Gaussian" },
	{ 2 , "TopHat" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringBeamSpotShape( KINT32 Value )
{
    return GetEnumAsString( BeamSpotShapeDescriptor, sizeof( BeamSpotShapeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringBeamSpotShape( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( BeamSpotShapeDescriptor, sizeof( BeamSpotShapeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringBeamSpotShape( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringBeamSpotShape( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

#endif

