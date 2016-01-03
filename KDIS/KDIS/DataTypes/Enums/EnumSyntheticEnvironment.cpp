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

#include "./EnumSyntheticEnvironment.h"

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
    { 0x000A0000 , "PointRecord1Type" },
    { 0x000C0000 , "LineRecord1Type" },
    { 0x000D0000 , "SphereRecord1Type" },
    { 0x00100000 , "EllipsoidRecord1Type" },
    { 0x00300000 , "ConeRecord1Type" },
    { 0x00500000 , "RectangularVolumeRecord1Type" },
    { 0x05000000 , "RectangularVolumeRecord3Type" },
    { 0x0A000000 , "PointRecord2Type" },
    { 0x0C000000 , "LineRecord2Type" },
    { 0x0D000000 , "SphereRecord2Type" },
    { 0x10000000 , "EllipsoidRecord2Type" },
    { 0x30000000 , "ConeRecord2Type" },
    { 0x50000000 , "RectangularVolumeRecord2Type" },
    { 0x60000000 , "GaussianPlumeRecordType" },
    { 0x70000000 , "GaussianPuffRecordType" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEnvironmentRecordType()
{
	return sizeof( EnvironmentRecordTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEnvironmentRecordType( KUINT32 Index )
{
	return &EnvironmentRecordTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEnvironmentRecordType( KINT32 Value )
{
    return GetEnumAsString( EnvironmentRecordTypeDescriptor, sizeof( EnvironmentRecordTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEnvironmentRecordType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EnvironmentRecordTypeDescriptor, sizeof( EnvironmentRecordTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEnvironmentRecordType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEnvironmentRecordType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEnvironmentRecordType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

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

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEnvironmentSubcategory()
{
	return sizeof( EnvironmentSubcategoryDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEnvironmentSubcategory( KUINT32 Index )
{
	return &EnvironmentSubcategoryDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEnvironmentSubcategory( KINT32 Value )
{
    return GetEnumAsString( EnvironmentSubcategoryDescriptor, sizeof( EnvironmentSubcategoryDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringEnvironmentSubcategory( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( EnvironmentSubcategoryDescriptor, sizeof( EnvironmentSubcategoryDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeEnvironmentSubcategory()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorEnvironmentSubcategory( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringEnvironmentSubcategory( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

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

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeCoordinateSystem()
{
	return sizeof( CoordinateSystemDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorCoordinateSystem( KUINT32 Index )
{
	return &CoordinateSystemDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCoordinateSystem( KINT32 Value )
{
    return GetEnumAsString( CoordinateSystemDescriptor, sizeof( CoordinateSystemDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCoordinateSystem( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( CoordinateSystemDescriptor, sizeof( CoordinateSystemDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeCoordinateSystem()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorCoordinateSystem( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringCoordinateSystem( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringCoordinateSystem( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ConstantGrid

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ConstantGridDescriptor[] =
{
    { 0 , "Constant" },
    { 1 , "Updated" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeConstantGrid()
{
	return sizeof( CoordinateSystemDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorConstantGrid( KUINT32 Index )
{
	return &CoordinateSystemDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringConstantGrid( KINT32 Value )
{
    return GetEnumAsString( ConstantGridDescriptor, sizeof( ConstantGridDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringConstantGrid( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ConstantGridDescriptor, sizeof( ConstantGridDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeConstantGrid()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorConstantGrid( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringConstantGrid( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringConstantGrid( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for GridDataRepresentation

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor GridDataRepresentationDescriptor[] =
{
    { 0 , "Type0(8 bit)" },
    { 1 , "Type1(16 bit)" },
    { 2 , "Type2(32 bit)" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeGridDataRepresentation()
{
	return sizeof( CoordinateSystemDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorGridDataRepresentation( KUINT32 Index )
{
	return &CoordinateSystemDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringGridDataRepresentation( KINT32 Value )
{
    return GetEnumAsString( GridDataRepresentationDescriptor, sizeof( GridDataRepresentationDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringGridDataRepresentation( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( GridDataRepresentationDescriptor, sizeof( GridDataRepresentationDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeGridDataRepresentation()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorGridDataRepresentation( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringGridDataRepresentation( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

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

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeObjectDamage()
{
	return sizeof( ObjectDamageDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorObjectDamage( KUINT32 Index )
{
	return &ObjectDamageDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringObjectDamage( KINT32 Value )
{
    return GetEnumAsString( ObjectDamageDescriptor, sizeof( ObjectDamageDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringObjectDamage( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ObjectDamageDescriptor, sizeof( ObjectDamageDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeObjectDamage()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorObjectDamage( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringObjectDamage( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

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

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeBreach2bit()
{
	return sizeof( Breach2bitDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorBreach2bit( KUINT32 Index )
{
	return &Breach2bitDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringBreach2bit( KINT32 Value )
{
    return GetEnumAsString( Breach2bitDescriptor, sizeof( Breach2bitDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringBreach2bit( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( Breach2bitDescriptor, sizeof( Breach2bitDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeBreach2bit()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorBreach2bit( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringBreach2bit( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringBreach2bit( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for Chemical

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ChemicalDescriptor[] =
{
    { 0 , "OtherChemical" },
    { 1 , "Hydrochloric" },
    { 2 , "WhitePhosphorous" },
    { 3 , "RedPhosphorous" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeChemical()
{
	return sizeof( Breach2bitDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorChemical( KUINT32 Index )
{
	return &Breach2bitDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringChemical( KINT32 Value )
{
    return GetEnumAsString( ChemicalDescriptor, sizeof( ChemicalDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringChemical( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ChemicalDescriptor, sizeof( ChemicalDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeChemical()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorChemical( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringChemical( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

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

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeVisibleSide()
{
	return sizeof( VisibleSideDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorVisibleSide( KUINT32 Index )
{
	return &VisibleSideDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringVisibleSide( KINT32 Value )
{
    return GetEnumAsString( VisibleSideDescriptor, sizeof( VisibleSideDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringVisibleSide( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( VisibleSideDescriptor, sizeof( VisibleSideDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeVisibleSide()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorVisibleSide( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringVisibleSide( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringVisibleSide( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
