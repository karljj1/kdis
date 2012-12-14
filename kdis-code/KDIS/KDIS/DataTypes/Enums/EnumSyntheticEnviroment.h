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

/********************************************************************
    EnumSyntheticEnviroment
    created:    27/06/2009
    author:     Karl Jones

    purpose:    Enums used in Synthetic Enviroment PDUs
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
    UniformGeometryRecordType                                         = 0x00050000, // Not implemented, 12.3.4.16 of SISO-REF-010-2006 has a poor description. It is difficult to understand what should be in it. Karl 27/08/2009
    RectangularVolumeRecord1Type                                      = 0x00500000,
    RectangularVolumeRecord2Type                                      = 0x50000000,
    GaussianPlumeRecordType                                           = 0x60000000,
    GaussianPuffRecordType                                            = 0x70000000,
    RectangularVolumeRecord3Type                                      = 0x05000000,
    // State Record
    COMBICStateType                                                   = 0x00000100,
    FlareStateType                                                    = 0x00000103
};

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

KString GetEnumAsStringVisibleSide( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringVisibleSide( const KString & Value, KINT32 & ValueOut );

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
