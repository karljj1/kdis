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
    Minefield
    created:    06/05/2010
    author:     Karl Jones

    purpose:    Enums used for minefields.
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Minefield Type                                                       */
/* Indicates the type of minefield.                                     */
/* Used In:                                                             */
/*  Minefield Appearance                                                */
/************************************************************************/

enum MinefieldType
{
    MixedAntiPersonnelAntiTank                                        = 0,
    PureAntiPersonnel                                                 = 1,
    PureAntiTank                                                      = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeMinefieldType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorMinefieldType( KUINT32 Index );

KString GetEnumAsStringMinefieldType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringMinefieldType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Minefield Protocol Mode                                              */
/* Specifies which protocol mode is being used to communicate the       */
/* minefield data.                                                      */
/* Used In:                                                             */
/*  Minefield_State_PDU                                                 */
/************************************************************************/

enum MinefieldProtocolMode
{
    Heartbeat                                                         = 0,
    QPR                                                               = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeMinefieldProtocolMode();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorMinefieldProtocolMode( KUINT32 Index );

KString GetEnumAsStringMinefieldProtocolMode( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringMinefieldProtocolMode( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Sensor Type                                                          */
/* Bits 0-3 identify the category of the sensor type and bits 4-15      */
/* identify the subcategory within the specified category.              */
/* I have simplified this so the first word of the enum is the category */
/* and the remaining is the sub category.                               */
/* Used In:                                                             */
/*  Minefield_Query_PDU                                                 */
/*  Minefield_Data_PDU                                                  */
/************************************************************************/

enum SensorType
{
    // Category 0 - Other
    SensorTypeOther                                                   = 0,
    // Category 1 - Optical
    Optical_UnaidedEyeActivelySearching                               = 1,
    Optical_UnaidedEyeNotActivelySearching                            = 17,
    Optical_Binoculars                                                = 33,
    Optical_ImageIntensifier                                          = 49,
    Optical_HMMWVOccupantActivelySearching                            = 65,
    Optical_HMMWVOccupantNotActivelySearching                         = 81,
    Optical_TruckOccupantActivelySearching                            = 97,
    Optical_TruckOccupantNotActivelySearching                         = 113,
    Optical_TrackedVehicleOccupantClosedHatchActivelySearching        = 129,
    Optical_TrackedVehicleOccupantClosedHatchNotActivelySearching     = 145,
    Optical_TrackedVehicleOccupantOpenHatchActivelySearching          = 161,
    Optical_TrackedVehicleOccupantOpenHatchNotActivelySearching       = 177,
    // Category 2 - FLIR
    FLIR_Generic3_5                                                   = 2,
    FLIR_Generic8_12                                                  = 18,
    FLIR_ASTAMIDS_I                                                   = 34,
    FLIR_ASTAMIDS_II                                                  = 50,
    FLIR_GSTAMIDS3_5                                                  = 66,
    FLIR_GSTAMIDS8_1                                                  = 82,
    FLIR_HSTAMIDS3_5                                                  = 98,
    FLIR_HSTAMIDS8_1                                                  = 114,
    FLIR_COBRA3_5                                                     = 130,
    FLIR_COBRA8_12                                                    = 146,
    // Category 3 - RADAR
    RADAR_Generic                                                     = 3,
    RADAR_GenericGPR                                                  = 19,
    RADAR_GSTAMIDSI                                                   = 35,
    RADAR_GSTAMIDSII                                                  = 51,
    RADAR_HSTAMIDSI                                                   = 67,
    RADAR_HSTAMIDSII                                                  = 83,
    // Category 4 - Magnetic
    Magnetic_Generic                                                  = 4,
    Magnetic_AN_PSS_11                                                = 20,
    Magnetic_AN_PSS_12                                                = 36,
    Magnetic_GSTAMIDS                                                 = 52,
    // Category 5 - Laser
    Laser_Generic                                                     = 5,
    Laser_ASTAMIDS                                                    = 21,
    // Category 6 - SONAR
    SONAR_Generic                                                     = 6,
    // Category 7 - Physical
    Physical_GenericProbe                                             = 7,
    Physical_ProbeMetalContent                                        = 23,
    Physical_ProbeNoMetalContent                                      = 39,
    // Category 8 - Multispectral
    Multispectral_Generic                                             = 8
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeSensorType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorSensorType( KUINT32 Index );

KString GetEnumAsStringSensorType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringSensorType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* MineFuse                                                             */
/* Identifies the type of the fuse on a mine(primary and secondary).    */
/* Used In:                                                             */
/*  MineFusing                                                          */
/************************************************************************/

enum MineFuse
{
    NoMineFuse                                                        = 0,
    OtherMineFuse                                                     = 1,
    PressureFuse                                                      = 2,
    MagneticFuse                                                      = 3,
    TiltRodFuse                                                       = 4,
    CommandFuse                                                       = 5,
    TripWireFuse                                                      = 6
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeMineFuse();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorMineFuse( KUINT32 Index );

KString GetEnumAsStringMineFuse( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringMineFuse( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* MineAlgae                                                            */
/* The algae build-up on a mine.                                        */
/* Used In:                                                             */
/*  MinePaintScheme                                                     */
/************************************************************************/

enum MineAlgae
{
    AlgaeNone                                                         = 0,
    AlgaeLight                                                        = 1,
    AlgaeModerate                                                     = 2,
    AlgaeHeavy                                                        = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeMineAlgae();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorMineAlgae( KUINT32 Index );

KString GetEnumAsStringMineAlgae( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringMineAlgae( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* PaintScheme                                                          */
/* The paint scheme of a mine                                           */
/* Used In:                                                             */
/*  MinePaintScheme                                                     */
/************************************************************************/

enum PaintScheme
{
    OtherPaintScheme                                                  = 0,
    StandardPaintScheme                                               = 1,
    CamouflageDesert                                                  = 2,
    CamouflageJungle                                                  = 3,
    CamouflageSnow                                                    = 4,
    CamouflageGravel                                                  = 5,
    CamouflagePavement                                                = 6,
    CamouflageSand                                                    = 7,
    NaturalWood                                                       = 8,
    ClearPaintScheme                                                  = 9,
    Red                                                               = 10,
    Blue                                                              = 11,
    Green                                                             = 12,
    Olive                                                             = 13,
    White                                                             = 14,
    Tan                                                               = 15,
    Black                                                             = 16,
    Yellow                                                            = 17,
    Brown                                                             = 18
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizePaintScheme();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorPaintScheme( KUINT32 Index );

KString GetEnumAsStringPaintScheme( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringPaintScheme( const KString & Value, KINT32 & ValueOut );

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
