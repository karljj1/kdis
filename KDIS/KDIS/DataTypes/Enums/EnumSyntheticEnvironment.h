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

/********************************************************************
    EnumSyntheticEnvironment
    created:    27/06/2009
    author:     Karl Jones

    purpose:    Enums used in Synthetic Environment PDUs
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Environment Record Type                                              */
/* Specifies the record type                                            */
/* Used In:                                                             */
/*  Environmental_Process_PDU                                           */
/************************************************************************/

enum EnvironmentRecordType
{
    // Geometry Record
    PointRecord1Type                                                  = 0x000A0000,
    PointRecord2Type                                                  = 0x0A000000,
    LineRecord1Type                                                   = 0x000C0000,
    LineRecord2Type                                                   = 0x0C000000,
    BoundingSphereRecordType                                          = 0x00010000,
    SphereRecord1Type                                                 = 0x000D0000,
    SphereRecord2Type                                                 = 0x0D000000,
    EllipsoidRecord1Type                                              = 0x00100000,
    EllipsoidRecord2Type                                              = 0x10000000,
    ConeRecord1Type                                                   = 0x00300000,
    ConeRecord2Type                                                   = 0x30000000,
    UniformGeometryRecordType                                         = 0x00050000, // TODO: Not implemented, 12.3.4.16 of SISO-REF-010-2006 has a poor description. It is difficult to understand what should be in it. Karl 27/08/2009
    RectangularVolumeRecord1Type                                      = 0x00500000,
    RectangularVolumeRecord2Type                                      = 0x50000000,
    GaussianPlumeRecordType                                           = 0x60000000,
    GaussianPuffRecordType                                            = 0x70000000,
    RectangularVolumeRecord3Type                                      = 0x05000000,
    // State Record
    COMBICStateType                                                   = 0x00000100,
    FlareStateType                                                    = 0x00000103
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeEnvironmentRecordType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorEnvironmentRecordType( KUINT32 Index );

KString GetEnumAsStringEnvironmentRecordType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEnvironmentRecordType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Environment Subcategory                                              */
/* Indicates the entity's size.                                         */
/* Used In:                                                             */
/*  EnvironmentType                                                     */
/************************************************************************/

enum EnvironmentSubcategory
{
    OtherEnvironmentSubcategory                                       = 0,
    VerySmallSize                                                     = 20,
    SmallSize                                                         = 40,
    MediumSize                                                        = 60,
    LargeSize                                                         = 80,
    VeryLargeSize                                                     = 100
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeEnvironmentSubcategory();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorEnvironmentSubcategory( KUINT32 Index );

KString GetEnumAsStringEnvironmentSubcategory( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEnvironmentSubcategory( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Coordinate System                                                    */
/* Specifies the coordinate system of the grid for the environmental    */
/* data contained in the Gridded Data PDU.                              */
/* Used In:                                                             */
/*  Gridded Data PDU                                                    */
/************************************************************************/

enum CoordinateSystem
{
    RightHandedCartesian                                              = 0, // Right handed Cartesian (local topographic projection: east, north, up)
    LeftHandedCartesian                                               = 1, // Left handed Cartesian (local topographic projection: east, north, down)
    LatLonHeight                                                      = 2, // Latitude, Longitude, Height
    LatLonDepth                                                       = 3  // Latitude, Longitude, Depth
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeCoordinateSystem();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorCoordinateSystem( KUINT32 Index );

KString GetEnumAsStringCoordinateSystem( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringCoordinateSystem( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Constant Grid                                                        */
/* Specifies whether the domain grid axes are identical to those of the */
/* previous domain update grid for the environmental data sample        */
/* contained in the PDU                                                 */
/* Used In:                                                             */
/*  Gridded Data PDU                                                    */
/************************************************************************/

enum ConstantGrid
{
    Constant                                                          = 0,
    Updated                                                           = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeConstantGrid();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorConstantGrid( KUINT32 Index );

KString GetEnumAsStringConstantGrid( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringConstantGrid( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Grid Data Representation                                             */
/* Specifies the value that describes the data representation method    */
/* for the environmental state variable data contained within the Data  */
/* Values fields of this record.                                        */
/* Used In:                                                             */
/*  Grid Data                                                           */
/************************************************************************/

enum GridDataRepresentation
{
    Type0                                                             = 0, // 8 bit representation.
    Type1                                                             = 1, // 16 bit representation.
    Type2                                                             = 2  // 32 bit representation.
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeGridDataRepresentation();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorGridDataRepresentation( KUINT32 Index );

KString GetEnumAsStringGridDataRepresentation( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringGridDataRepresentation( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Object Damage                                                        */
/* Describes the damaged appearance of the object.                      */
/* Used In:                                                             */
/*  Object Appearance                                                   */
/************************************************************************/

enum ObjectDamage
{
    NoObjectDamage                                                    = 0,
    ObjectDamaged                                                     = 1,
    ObjectDestroyed                                                   = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeObjectDamage();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorObjectDamage( KUINT32 Index );

KString GetEnumAsStringObjectDamage( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringObjectDamage( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Breach 2 bit                                                         */
/* Describes the breach status for Log crib, Abatis, Vehicle defilade,  */
/* and Infantry fighting position.                                      */
/* Used In:                                                             */
/*  Point Object Appearance                                             */
/*  Linear Object Appearance                                            */
/*  Areal Object Appearance                                             */
/************************************************************************/

enum Breach2bit
{
    NoBreaching2bit                                                   = 0,
    Breached2bit                                                      = 1,
    Cleared2bit                                                       = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeBreach2bit();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorBreach2bit( KUINT32 Index );

KString GetEnumAsStringBreach2bit( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringBreach2bit( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Chemical                                                             */
/* Describes the chemical content of smoke                              */
/* Used In:                                                             */
/*  Point Object Appearance                                             */
/*  Linear Object Appearance                                            */
/*  Areal Object Appearance                                             */
/************************************************************************/

enum Chemical
{
    OtherChemical                                                     = 0,
    Hydrochloric                                                      = 1,
    WhitePhosphorous                                                  = 2,
    RedPhosphorous                                                    = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeChemical();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorChemical( KUINT32 Index );

KString GetEnumAsStringChemical( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringChemical( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Visible Side                                                         */
/* Describes the side of the lane marker which is visible.              */
/* Used In:                                                             */
/*  Linear Object Appearance                                            */
/************************************************************************/

enum VisibleSide
{
    LeftSideVisible                                                   = 0,
    RightSideVisible                                                  = 1,
    BothSidesVisible                                                  = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeVisibleSide();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorVisibleSide( KUINT32 Index );

KString GetEnumAsStringVisibleSide( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringVisibleSide( const KString & Value, KINT32 & ValueOut );

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
