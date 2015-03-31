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

#include "./EnumSupply.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for ServiceTypeRequested

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ServiceTypeRequestedDescriptor[] =
{
    { 0 , "OtherRequest" },
    { 1 , "Resupply" },
    { 2 , "Repair" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeServiceTypeRequested()
{
	return sizeof( ServiceTypeRequestedDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorServiceTypeRequested( KUINT32 Index )
{
	return &ServiceTypeRequestedDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringServiceTypeRequested( KINT32 Value )
{
    return GetEnumAsString( ServiceTypeRequestedDescriptor, sizeof( ServiceTypeRequestedDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringServiceTypeRequested( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ServiceTypeRequestedDescriptor, sizeof( ServiceTypeRequestedDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeServiceTypeRequested()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorServiceTypeRequested( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringServiceTypeRequested( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringServiceTypeRequested( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for RepairTypePerformed

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor RepairTypePerformedDescriptor[] =
{
    { 0 , "NoRepairsPerformed" },
    { 1 , "AllRequestedRepairsPerformed" },
    { 10 , "Motor_Engine" },
    { 20 , "Starter" },
    { 30 , "Alternator" },
    { 40 , "Generator" },
    { 50 , "Battery" },
    { 60 , "Engine_CoolantLeak" },
    { 70 , "FuelFilter" },
    { 80 , "Transmission_OilLeak" },
    { 90 , "Engine_OilLeak" },
    { 100 , "Pumps" },
    { 110 , "Filters" },
    { 120 , "Transmission" },
    { 130 , "Brakes" },
    { 140 , "SuspensionSystem" },
    { 150 , "OilFilter" },
    { 1000 , "Hull" },
    { 1010 , "AirFrame" },
    { 1020 , "TruckBody" },
    { 1030 , "TankBody" },
    { 1040 , "TrailerBody" },
    { 1050 , "Turret" },
    { 1500 , "Propeller" },
    { 1520 , "Filters1" },
    { 1540 , "Wheels" },
    { 1550 , "Tire" },
    { 1560 , "Track" },
    { 2000 , "GunElevationDrive" },
    { 2010 , "GunStabilizationSystem" },
    { 2020 , "GunnersPrimarySight_GPS" },
    { 2030 , "CommandersExtensionToTheGPS" },
    { 2040 , "LoadingMechanism" },
    { 2050 , "GunnersAuxiliarySight" },
    { 2060 , "GunnersControlPanel" },
    { 2070 , "GunnersControlAssemblyHandle" },
    { 2090 , "CommandersControlHandles_Assembly" },
    { 2100 , "CommandersWeaponStation" },
    { 2110 , "CommandersIndependentThermalViewer_CITV" },
    { 2120 , "GeneralWeapons" },
    { 4000 , "FuelTransferPump" },
    { 4010 , "FuelLines" },
    { 4020 , "Gauges" },
    { 4030 , "GeneralFuelSystem" },
    { 4500 , "ElectronicWarfareSystems" },
    { 4600 , "DdetectionSystems" },
    { 4610 , "RadioFrequency" },
    { 4620 , "Microwave" },
    { 4630 , "Infrared" },
    { 4640 , "Laser" },
    { 4700 , "RangeFinders" },
    { 4710 , "Range_OnlyRadar" },
    { 4720 , "LaserRangeFinder" },
    { 4800 , "ElectronicSystems" },
    { 4810 , "RadioFrequency1" },
    { 4820 , "Microwave1" },
    { 4830 , "Infrared1" },
    { 4840 , "Laser1" },
    { 5000 , "Radios" },
    { 5010 , "CommunicationSystems" },
    { 5100 , "Intercoms" },
    { 5200 , "Encoders" },
    { 5250 , "Encryptiondevices" },
    { 5300 , "Decoders" },
    { 5350 , "DecryptionDevices" },
    { 5500 , "Computers" },
    { 6000 , "NavigationAndControlSystems" },
    { 6500 , "FireControlSystems" },
    { 8000 , "AirSupply" },
    { 8010 , "Filters2" },
    { 8020 , "WaterSupply" },
    { 8030 , "RefrigerationSystem" },
    { 8040 , "Chemical_Biological_RadiologicalProtection" },
    { 8050 , "WaterWashDownSystems" },
    { 8060 , "DecontaminationSystems" },
    { 9000 , "WaterSupply1" },
    { 9010 , "CoolingSystem" },
    { 9020 , "Winches" },
    { 9030 , "Catapults" },
    { 9040 , "Cranes" },
    { 9050 , "Launchers" },
    { 10000 , "Lifeboats" },
    { 10010 , "LandingCraft" },
    { 10020 , "EjectionSeats" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRepairTypePerformed()
{
	return sizeof( RepairTypePerformedDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRepairTypePerformed( KUINT32 Index )
{
	return &RepairTypePerformedDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRepairTypePerformed( KINT32 Value )
{
    return GetEnumAsString( RepairTypePerformedDescriptor, sizeof( RepairTypePerformedDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRepairTypePerformed( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( RepairTypePerformedDescriptor, sizeof( RepairTypePerformedDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRepairTypePerformed()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRepairTypePerformed( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRepairTypePerformed( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRepairTypePerformed( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for RepairResult

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor RepairResultDescriptor[] =
{
    { 0 , "OtherRepairResult" },
    { 1 , "RepairEnded" },
    { 2 , "InvalidRepair" },
    { 3 , "RepairInterrupted" },
    { 4 , "ServiceCanceledByTheSupplier" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRepairResult()
{
	return sizeof( RepairResultDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRepairResult( KUINT32 Index )
{
	return &RepairResultDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRepairResult( KINT32 Value )
{
    return GetEnumAsString( RepairResultDescriptor, sizeof( RepairResultDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRepairResult( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( RepairResultDescriptor, sizeof( RepairResultDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRepairResult()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRepairResult( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRepairResult( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRepairResult( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
