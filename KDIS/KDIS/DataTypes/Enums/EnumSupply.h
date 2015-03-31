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
    EnumSupply
    created:    17/10/2008
    author:     Karl Jones

    purpose:    Enums for supply/repairs
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Resupply Enums                                                       */
/* Used In:                                                             */
/*  Service Request                                                     */
/************************************************************************/

enum ServiceTypeRequested
{
    OtherRequest                                                      = 0,
    Resupply                                                          = 1,
    Repair                                                            = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeServiceTypeRequested();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorServiceTypeRequested( KUINT32 Index );

KString GetEnumAsStringServiceTypeRequested( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringServiceTypeRequested( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Repair Type Performed                                                */
/* Used In:                                                             */
/*  Repair Complete                                                     */
/************************************************************************/

enum RepairTypePerformed
{
    // General
    NoRepairsPerformed                                                = 0,
    AllRequestedRepairsPerformed                                      = 1,
    // Drive Train
    Motor_Engine                                                      = 10,
    Starter                                                           = 20,
    Alternator                                                        = 30,
    Generator                                                         = 40,
    Battery                                                           = 50,
    Engine_CoolantLeak                                                = 60,
    FuelFilter                                                        = 70,
    Transmission_OilLeak                                              = 80,
    Engine_OilLeak                                                    = 90,
    Pumps                                                             = 100,
    Filters                                                           = 110,
    Transmission                                                      = 120,
    Brakes                                                            = 130,
    SuspensionSystem                                                  = 140,
    OilFilter                                                         = 150,
    // Hull/Airframe/B
    Hull                                                              = 1000,
    AirFrame                                                          = 1010,
    TruckBody                                                         = 1020,
    TankBody                                                          = 1030,
    TrailerBody                                                       = 1040,
    Turret                                                            = 1050,
    // Interfaces with environment
    Propeller                                                         = 1500,
    Filters1                                                          = 1520,
    Wheels                                                            = 1540,
    Tire                                                              = 1550,
    Track                                                             = 1560,
    // Weapons
    GunElevationDrive                                                 = 2000,
    GunStabilizationSystem                                            = 2010,
    GunnersPrimarySight_GPS                                           = 2020,
    CommandersExtensionToTheGPS                                       = 2030,
    LoadingMechanism                                                  = 2040,
    GunnersAuxiliarySight                                             = 2050,
    GunnersControlPanel                                               = 2060,
    GunnersControlAssemblyHandle                                      = 2070,
    CommandersControlHandles_Assembly                                 = 2090,
    CommandersWeaponStation                                           = 2100,
    CommandersIndependentThermalViewer_CITV                           = 2110,
    GeneralWeapons                                                    = 2120,
    // Fuel systems
    FuelTransferPump                                                  = 4000,
    FuelLines                                                         = 4010,
    Gauges                                                            = 4020,
    GeneralFuelSystem                                                 = 4030,
    // Electronics
    ElectronicWarfareSystems                                          = 4500,
    DdetectionSystems                                                 = 4600,
    RadioFrequency                                                    = 4610,
    Microwave                                                         = 4620,
    Infrared                                                          = 4630,
    Laser                                                             = 4640,
    RangeFinders                                                      = 4700,
    Range_OnlyRadar                                                   = 4710,
    LaserRangeFinder                                                  = 4720,
    ElectronicSystems                                                 = 4800,
    RadioFrequency1                                                   = 4810,
    Microwave1                                                        = 4820,
    Infrared1                                                         = 4830,
    Laser1                                                            = 4840,
    Radios                                                            = 5000,
    CommunicationSystems                                              = 5010,
    Intercoms                                                         = 5100,
    Encoders                                                          = 5200,
    Encryptiondevices                                                 = 5250,
    Decoders                                                          = 5300,
    DecryptionDevices                                                 = 5350,
    Computers                                                         = 5500,
    NavigationAndControlSystems                                       = 6000,
    FireControlSystems                                                = 6500,
    // Life support systems
    AirSupply                                                         = 8000,
    Filters2                                                          = 8010,
    WaterSupply                                                       = 8020,
    RefrigerationSystem                                               = 8030,
    Chemical_Biological_RadiologicalProtection                        = 8040,
    WaterWashDownSystems                                              = 8050,
    DecontaminationSystems                                            = 8060,
    // Hydraulic systems and actuators
    WaterSupply1                                                      = 9000,
    CoolingSystem                                                     = 9010,
    Winches                                                           = 9020,
    Catapults                                                         = 9030,
    Cranes                                                            = 9040,
    Launchers                                                         = 9050,
    // Auxiliary craft
    Lifeboats                                                         = 10000,
    LandingCraft                                                      = 10010,
    EjectionSeats                                                     = 10020
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeRepairTypePerformed();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorRepairTypePerformed( KUINT32 Index );

KString GetEnumAsStringRepairTypePerformed( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRepairTypePerformed( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Repair Result                                                        */
/* Used In:                                                             */
/*  Repair Response                                                     */
/************************************************************************/

enum RepairResult
{
    OtherRepairResult                                                 = 0,
    RepairEnded                                                       = 1,
    InvalidRepair                                                     = 2,
    RepairInterrupted                                                 = 3,
    ServiceCanceledByTheSupplier                                      = 4
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeRepairResult();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorRepairResult( KUINT32 Index );

KString GetEnumAsStringRepairResult( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRepairResult( const KString & Value, KINT32 & ValueOut );

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
