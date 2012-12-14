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

KString GetEnumAsStringRepairResult( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRepairResult( const KString & Value, KINT32 & ValueOut );

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
