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

#include "./EnumMinefield.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for MinefieldType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor MinefieldTypeDescriptor[] =
{
    { 0 , "Mixed Anti Personnel and Anti Tank" },
    { 1 , "Pure Anti Personnel" },
    { 2 , "Pure Anti Tank" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMinefieldType()
{
	return sizeof( MinefieldTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMinefieldType( KUINT32 Index )
{
	return &MinefieldTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMinefieldType( KINT32 Value )
{
    return GetEnumAsString( MinefieldTypeDescriptor, sizeof( MinefieldTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMinefieldType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( MinefieldTypeDescriptor, sizeof( MinefieldTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMinefieldType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMinefieldType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMinefieldType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMinefieldType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for MinefieldProtocolMode

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor MinefieldProtocolModeDescriptor[] =
{
    { 0 , "Heartbeat" },
    { 1 , "QPR" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMinefieldProtocolMode()
{
	return sizeof( MinefieldProtocolModeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMinefieldProtocolMode( KUINT32 Index )
{
	return &MinefieldProtocolModeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMinefieldProtocolMode( KINT32 Value )
{
    return GetEnumAsString( MinefieldProtocolModeDescriptor, sizeof( MinefieldProtocolModeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMinefieldProtocolMode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( MinefieldProtocolModeDescriptor, sizeof( MinefieldProtocolModeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMinefieldProtocolMode()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMinefieldProtocolMode( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMinefieldProtocolMode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMinefieldProtocolMode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for SensorType
// Note: The values have been put into order for the binary search algorithm to work correctly.

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor SensorTypeDescriptor[] =
{
    { 0 , "SensorTypeOther" },
    { 1 , "Optical_UnaidedEyeActivelySearching" },
    { 2 , "FLIR_Generic3_5" },
    { 3 , "RADAR_Generic" },
    { 4 , "Magnetic_Generic" },
    { 5 , "Laser_Generic" },
    { 6 , "SONAR_Generic" },
    { 7 , "Physical_GenericProbe" },
    { 8 , "Multispectral_Generic" },
    { 17 , "Optical_UnaidedEyeNotActivelySearching" },
    { 18 , "FLIR_Generic8_12" },
    { 19 , "RADAR_GenericGPR" },
    { 20 , "Magnetic_AN_PSS_11" },
    { 21 , "Laser_ASTAMIDS" },
    { 23 , "Physical_ProbeMetalContent" },
    { 33 , "Optical_Binoculars" },
    { 34 , "FLIR_ASTAMIDS_I" },
    { 35 , "RADAR_GSTAMIDSI" },
    { 36 , "Magnetic_AN_PSS_12" },
    { 39 , "Physical_ProbeNoMetalContent" },
    { 49 , "Optical_ImageIntensifier" },
    { 50 , "FLIR_ASTAMIDS_II" },
    { 51 , "RADAR_GSTAMIDSII" },
    { 52 , "Magnetic_GSTAMIDS" },
    { 65 , "Optical_HMMWVOccupantActivelySearching" },
    { 66 , "FLIR_GSTAMIDS3_5" },
    { 67 , "RADAR_HSTAMIDSI" },
    { 81 , "Optical_HMMWVOccupantNotActivelySearching" },
    { 82 , "FLIR_GSTAMIDS8_1" },
    { 83 , "RADAR_HSTAMIDSII" },
    { 97 , "Optical_TruckOccupantActivelySearching" },
    { 98 , "FLIR_HSTAMIDS3_5" },
    { 113 , "Optical_TruckOccupantNotActivelySearching" },
    { 114 , "FLIR_HSTAMIDS8_1" },
    { 129 , "Optical_TrackedVehicleOccupantClosedHatchActivelySearching" },
    { 130 , "FLIR_COBRA3_5" },
    { 145 , "Optical_TrackedVehicleOccupantClosedHatchNotActivelySearching" },
    { 146 , "FLIR_COBRA8_12" },
    { 161 , "Optical_TrackedVehicleOccupantOpenHatchActivelySearching" },
    { 177 , "Optical_TrackedVehicleOccupantOpenHatchNotActivelySearching" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeSensorType()
{
	return sizeof( SensorTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorSensorType( KUINT32 Index )
{
	return &SensorTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSensorType( KINT32 Value )
{
    return GetEnumAsString( SensorTypeDescriptor, sizeof( SensorTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSensorType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( SensorTypeDescriptor, sizeof( SensorTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeSensorType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorSensorType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringSensorType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringSensorType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for MineFuse

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor MineFuseDescriptor[] =
{
    { 0 , "NoMineFuse" },
    { 1 , "OtherMineFuse" },
    { 2 , "PressureFuse" },
    { 3 , "MagneticFuse" },
    { 4 , "TiltRodFuse" },
    { 5 , "CommandFuse" },
    { 6 , "TripWireFuse" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMineFuse()
{
	return sizeof( MineFuseDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMineFuse( KUINT32 Index )
{
	return &MineFuseDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMineFuse( KINT32 Value )
{
    return GetEnumAsString( MineFuseDescriptor, sizeof( MineFuseDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMineFuse( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( MineFuseDescriptor, sizeof( MineFuseDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMineFuse()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMineFuse( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMineFuse( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMineFuse( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for MineAlgae

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor MineAlgaeDescriptor[] =
{
    { 0 , "AlgaeNone" },
    { 1 , "AlgaeLight" },
    { 2 , "AlgaeModerate" },
    { 3 , "AlgaeHeavy" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMineAlgae()
{
	return sizeof( MineAlgaeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMineAlgae( KUINT32 Index )
{
	return &MineAlgaeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMineAlgae( KINT32 Value )
{
    return GetEnumAsString( MineAlgaeDescriptor, sizeof( MineAlgaeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMineAlgae( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( MineAlgaeDescriptor, sizeof( MineAlgaeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMineAlgae()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMineAlgae( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMineAlgae( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMineAlgae( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for PaintScheme

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor PaintSchemeDescriptor[] =
{
    { 0 , "OtherPaintScheme" },
    { 1 , "StandardPaintScheme" },
    { 2 , "CamouflageDesert" },
    { 3 , "CamouflageJungle" },
    { 4 , "CamouflageSnow" },
    { 5 , "CamouflageGravel" },
    { 6 , "CamouflagePavement" },
    { 7 , "CamouflageSand" },
    { 8 , "NaturalWood" },
    { 9 , "ClearPaintScheme" },
    { 10 , "Red" },
    { 11 , "Blue" },
    { 12 , "Green" },
    { 13 , "Olive" },
    { 14 , "White" },
    { 15 , "Tan" },
    { 16 , "Black" },
    { 17 , "Yellow" },
    { 18 , "Brown" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePaintScheme()
{
	return sizeof( PaintSchemeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPaintScheme( KUINT32 Index )
{
	return &PaintSchemeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPaintScheme( KINT32 Value )
{
    return GetEnumAsString( PaintSchemeDescriptor, sizeof( PaintSchemeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPaintScheme( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( PaintSchemeDescriptor, sizeof( PaintSchemeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePaintScheme()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPaintScheme( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPaintScheme( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPaintScheme( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
