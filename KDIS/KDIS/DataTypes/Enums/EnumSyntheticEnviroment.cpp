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

#include "./EnumSyntheticEnviroment.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for EnvironmentRecordType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EnvironmentRecordTypeDescriptor[] =
{
    { 0x00000100 , "COMBICStateType" },
    { 0x00000103 , "FlareStateType" },
    { 0x00010000 , "BoundingSphereRecordRecordType" },
    { 0x00050000 , "UniformGeometryRecordType" },
    { 0x000A0000 , "PoKINT32Record1Type" },
    { 0x000C0000 , "LineRecord1Type" },
    { 0x000D0000 , "SphereRecord1Type" },
    { 0x00100000 , "EllipsoidRecord1Type" },
    { 0x00300000 , "ConeRecord1Type" },
    { 0x00500000 , "RectangularVolumeRecord1Type" },
    { 0x05000000 , "RectangularVolumeRecord3Type" },
    { 0x0A000000 , "PoKINT32Record2Type" },
    { 0x0C000000 , "LineRecord2Type" },
    { 0x0D000000 , "SphereRecord2Type" },
    { 0x10000000 , "EllipsoidRecord2Type" },
    { 0x30000000 , "ConeRecord2Type" },
    { 0x50000000 , "RectangularVolumeRecord2Type" },
    { 0x60000000 , "GaussianPlumeRecordType" },
    { 0x70000000 , "GaussianPuffRecordType" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEnvironmentRecordType( KINT32 Value )
{
    return GetEnumAsString( EnvironmentRecordTypeDescriptor, sizeof( EnvironmentRecordTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEnvironmentRecordType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EnvironmentRecordTypeDescriptor, sizeof( EnvironmentRecordTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEnvironmentRecordType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEnvironmentRecordType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for EnvironmentSubcategory

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor EnvironmentSubcategoryDescriptor[] =
{
    { 0 , "OtherEnvironmentSubcategory" },
    { 20 , "VerySmallSize" },
    { 40 , "SmallSize" },
    { 60 , "MediumSize" },
    { 80 , "LargeSize" },
    { 100 , "VeryLargeSize" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEnvironmentSubcategory( KINT32 Value )
{
    return GetEnumAsString( EnvironmentSubcategoryDescriptor, sizeof( EnvironmentSubcategoryDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEnvironmentSubcategory( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EnvironmentSubcategoryDescriptor, sizeof( EnvironmentSubcategoryDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEnvironmentSubcategory( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEnvironmentSubcategory( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for CoordinateSystem

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor CoordinateSystemDescriptor[] =
{
    { 0 , "RightHandedCartesian" },
    { 1 , "LeftHandedCartesian" },
    { 2 , "LatLonHeight" },
    { 3 , "LatLonDepth" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCoordinateSystem( KINT32 Value )
{
    return GetEnumAsString( CoordinateSystemDescriptor, sizeof( CoordinateSystemDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCoordinateSystem( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( CoordinateSystemDescriptor, sizeof( CoordinateSystemDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCoordinateSystem( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCoordinateSystem( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for CoordinateSystem

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ConstantGridDescriptor[] =
{
    { 0 , "Constant" },
    { 1 , "Updated" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringConstantGrid( KINT32 Value )
{
    return GetEnumAsString( ConstantGridDescriptor, sizeof( ConstantGridDescriptor ) / sizeof( EnumDescriptor ), Value );
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringConstantGrid( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ConstantGridDescriptor, sizeof( ConstantGridDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringConstantGrid( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringConstantGrid( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for CoordinateSystem

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor GridDataRepresentationDescriptor[] =
{
    { 0 , "Type0(8 bit)" },
    { 1 , "Type1(16 bit)" },
    { 2 , "Type2(32 bit)" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringGridDataRepresentation( KINT32 Value )
{
    return GetEnumAsString( GridDataRepresentationDescriptor, sizeof( GridDataRepresentationDescriptor ) / sizeof( EnumDescriptor ), Value );
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringGridDataRepresentation( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( GridDataRepresentationDescriptor, sizeof( GridDataRepresentationDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringGridDataRepresentation( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringGridDataRepresentation( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ObjectDamage

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ObjectDamageDescriptor[] =
{
    { 0 , "NoObjectDamage" },
    { 1 , "ObjectDamaged" },
    { 2 , "ObjectDestroyed" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringObjectDamage( KINT32 Value )
{
    return GetEnumAsString( ObjectDamageDescriptor, sizeof( ObjectDamageDescriptor ) / sizeof( EnumDescriptor ), Value );
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringObjectDamage( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ObjectDamageDescriptor, sizeof( ObjectDamageDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringObjectDamage( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringObjectDamage( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for Breach2bit

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor Breach2bitDescriptor[] =
{
    { 0 , "NoBreaching2bit" },
    { 1 , "Breached2bit" },
    { 2 , "Cleared2bit" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringBreach2bit( KINT32 Value )
{
    return GetEnumAsString( Breach2bitDescriptor, sizeof( Breach2bitDescriptor ) / sizeof( EnumDescriptor ), Value );
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringBreach2bit( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( Breach2bitDescriptor, sizeof( Breach2bitDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringBreach2bit( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringBreach2bit( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for Breach2bit

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ChemicalDescriptor[] =
{
    { 0 , "OtherChemical" },
    { 1 , "Hydrochloric" },
    { 2 , "WhitePhosphorous" },
    { 3 , "RedPhosphorous" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringChemical( KINT32 Value )
{
    return GetEnumAsString( ChemicalDescriptor, sizeof( ChemicalDescriptor ) / sizeof( EnumDescriptor ), Value );
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringChemical( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ChemicalDescriptor, sizeof( ChemicalDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringChemical( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringChemical( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for VisibleSide

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor VisibleSideDescriptor[] =
{
    { 0 , "LeftSideVisible" },
    { 1 , "RightSideVisible" },
    { 2 , "BothSidesVisible" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringVisibleSide( KINT32 Value )
{
    return GetEnumAsString( VisibleSideDescriptor, sizeof( VisibleSideDescriptor ) / sizeof( EnumDescriptor ), Value );
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringVisibleSide( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( VisibleSideDescriptor, sizeof( VisibleSideDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringVisibleSide( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringVisibleSide( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
