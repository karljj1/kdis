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
    EnumEntityManagement
    created:    07/02/2009
    author:     Karl Jones

    purpose:    Enums used in Entity Mangement PDUs
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Aggregate State                                                      */
/* Used In:                                                             */
/*  Aggregate_State_PDU                                                 */
/************************************************************************/

enum AggregateState
{
    OtherAggregateState                                               = 0,
    Aggregated                                                        = 1,
    Disaggregated                                                     = 2,
    FullyDisaggregated                                                = 3,
    PseudoDisaggregated                                               = 4,
    PartiallyDisaggregated                                            = 5
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeAggregateState();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorAggregateState( KUINT32 Index );

KString GetEnumAsStringAggregateState( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAggregateState( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Aggregate Kind                                                       */
/* Aggregate kind used in AggregateType                                 */
/* Used In:                                                             */
/*  AggregateType                                                       */
/************************************************************************/

enum AggregateKind
{
    OtherAggregateKind                                                = 0,
    MilitaryHierachy                                                  = 1,
    CommonType                                                        = 2,
    CommonMission                                                     = 3,
    SimilarCapabilities                                               = 4,
    CommonLocation                                                    = 5
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeAggregateKind();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorAggregateKind( KUINT32 Index );

KString GetEnumAsStringAggregateKind( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAggregateKind( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Formation                                                            */
/* Aggregate formation                                                  */
/* Used In:                                                             */
/*  Aggregate_State_PDU                                                 */
/************************************************************************/

enum Formation
{
    OtherFormation                                                    = 0,
    Assembly                                                          = 1,
    Vee                                                               = 2,
    Wedge                                                             = 3,
    Line                                                              = 4,
    Column                                                            = 5
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeFormation();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorFormation( KUINT32 Index );

KString GetEnumAsStringFormation( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringFormation( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Grouped Entity Category                                              */
/* Describes the type of entities constituting a group.                 */
/* Used In:                                                             */
/*  IsGroupOf_PDU                                                       */
/************************************************************************/

enum GroupedEntityCategory
{
    UndefinedGEC                                                         = 0,
    BasicGroundCombatVehicleGEC                                          = 1,
    EnhancedGroundCombatVehicleGEC                                       = 2,
    BasicGroundCombatSoldierGEC                                          = 3,
    EnhancedGroundCombatSoldierGEC                                       = 4,
    BasicRotorWingAircraftGEC                                            = 5,
    EnhancedRotorWingAircraftGEC                                         = 6,
    BasicFixedWingAircraftGEC                                            = 7,
    EnhancedFixedWingAircraftGEC                                         = 8,
    GroundLogisticsVehicleGEC                                            = 9
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeGroupedEntityCategory();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorGroupedEntityCategory( KUINT32 Index );

KString GetEnumAsStringGroupedEntityCategory( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringGroupedEntityCategory( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Transfer Type                                                        */
/* Transfer Type field of the Transfer Control PDU.                     */
/* Used In:                                                             */
/*  Transfer Control PDU                                                */
/************************************************************************/

enum TransferType
{
    OtherTransferType                                                    = 0,

    // AKA Push Transfer - Entity.
    // A simulation initiates a request to transfer an entity it owns to another simulation.
    ControllingApplicationRequestsTransferOfAnEntity                     = 1,

    // AKA Automatic Pull Transfer - Entity.
    // A  simulation automatically initiates a request to assume ownership of an entity presently
    // owned by another simulation.
    ApplicationDesiringControlRequestsTransferOfAnEntity                 = 2,

    MutualExchange_SwapOfAnEntity                                        = 3,

    // AKA Push Transfer - Environmental Process.
    // A simulation initiates a request to transfer an environmental process it owns to another simulation.
    ControllingApplicationRequestsTransferOfAnEnvironmentalProcess       = 4,

    // AKA Automatic Pull Transfer - Environmental Process .
    // A simulation automatically initiates a request to assume ownership of an environmental process
    // presently owned by another simulation.
    ApplicationDesiringControlsRequestsTransferOfAnEnvironmentalProcess  = 5,

    MutualExchange_SwapOfAnEnvironmental                                 = 6,

    // Cancel Transfer.  The present transfer is cancelled.
    CancelTransfer                                                       = 7,

    // **Note the following are taken from 'IEEE 1278.1-200X Draft'**

    // A simulation manually initiates a request to assume ownership of an entity presently owned
    // by another simulation
    ManualPullTransfer_Entity                                            = 8,

    //A simulation manually initiates a request to assume ownership of an environmental process
    // presently owned by another simulation.
    ManualPullTransfer_EnvironmentalProcess                              = 9,

    //If the entity specified in the Transferred Entity field exists as a local entity at the
    // simulation, it is to be automatically removed.
    RemoveEntity                                                         = 10
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeTransferType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorTransferType( KUINT32 Index );

KString GetEnumAsStringTransferType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTransferType( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* ID_Enum / Datum ID / Record ID                                       */
/* Used In:                                                             */
/*  Fixed Datum                                                         */
/*  Variable Datum                                                      */
/*  Record Set                                                          */
/************************************************************************/

enum ID_Enum
{
    IdentificationID                                                  = 10000,
    DRAAngularX_VelocityID                                            = 100001,
    DRAAngularY_VelocityID                                            = 100002,
    DRAAngularZ_VelocityID                                            = 100003,
    Appearance_TrailingEffectsID                                      = 100004,
    Appearance_HatchID                                                = 100005,
    Appearance_CharacterSetID                                         = 100008,
    Capability_AmmunitionSupplierID                                   = 100010,
    Capability_MiscellaneousSupplierID                                = 100011,
    Capability_RepairProviderID                                       = 100012,
    ArticulationParameterID                                           = 100014,
    ArticulationParameterTypeID                                       = 100047,
    ArticulationParameterValueID                                      = 100048,
    TimeofDay__SceneID                                                = 100058,
    SonarSystemStatusID                                               = 100100,
    UpperLatitudeID                                                   = 100160,
    LatitudeSouth_LocationOfWeatherCellID                             = 100161,
    WesternLongitudeID                                                = 100162,
    LongitudeWest_LocationOfWeatherCellID                             = 100163,
    AccomplishedAcceptID                                              = 100164,
    CDROMNumber_DiskIDForTerrainID                                    = 100165,
    DTEDDiskID                                                        = 100166,
    AltitudeID                                                        = 100167,
    TacticalSystemStatusID                                            = 100169,
    JTIDSStatusID                                                     = 100170,
    TADIL_JStatusID                                                   = 100171,
    DSDDStatusID                                                      = 100172,
    WeaponSystemStatusID                                              = 100200,
    Entity_Track_UpdateDataID                                         = 100300,
    Local_ForceTrainingID                                             = 100400,
    Entity_TrackIdentityDataID                                        = 100500,
    EngagementDataID                                                  = 100600,
    Entity_TrackEquipmentDataID                                       = 100700,
    Emission_EWDataID                                                 = 100800,
    AppearanceDataID                                                  = 100900,
    Command_OrderDataID                                               = 101000,
    EnvironmentalDataID                                               = 101100,
    SignificantEventDataID                                            = 101200,
    OperatorActionDataID                                              = 101300,
    TimeSynchronizationID                                             = 101400,
    TomahawkDataID                                                    = 101500,
    EntityTypeID                                                      = 11000,
    ConcatenatedID                                                    = 11100,
    Kind_U8_ID                                                        = 11110,
    Domain_U8_ID                                                      = 11120,
    Country_U16_ID                                                    = 11130,
    Category_U8_ID                                                    = 11140,
    Subcategory_U8_ID                                                 = 11150,
    Specific_U8_ID                                                    = 11160,
    Extra_U8_ID                                                       = 11170,
    ForceID_U8_ID                                                     = 11200,
    DescriptionID                                                     = 11300,
    AlternativeEntityTypeID                                           = 12000,
    Kind_U8_1ID                                                       = 12110,
    Domain_U8_1ID                                                     = 12120,
    Country_U16_1ID                                                   = 12130,
    Category_U8_1ID                                                   = 12140,
    Subcategory_U8_1ID                                                = 12150,
    Specific_U8_1ID                                                   = 12160,
    Extra_U8_1ID                                                      = 12170,
    Description1ID                                                    = 12300,
    EntityMarkingID                                                   = 13000,
    EntityMarkingString_string80_ID                                   = 13100,
    CrewID_string80_ID                                                = 13200,
    TaskOrganizationID                                                = 14000,
    RegimentName_string_ID                                            = 14200,
    BattalionName_string_ID                                           = 14300,
    CompanyName_string_ID                                             = 14400,
    PlatoonNameID                                                     = 14500,
    SquadNameID                                                       = 14520,
    TeamNameID                                                        = 14540,
    BumperNameID                                                      = 14600,
    VehicleNameID                                                     = 14700,
    UnitNumberID                                                      = 14800,
    DISIdentityID                                                     = 15000,
    DISSiteIDID                                                       = 15100,
    DISHostIDID                                                       = 15200,
    DISEntityIDID                                                     = 15300,
    OwnershipStatusID                                                 = 15800, // Ownership Status record - 64 bits
    LoadsID                                                           = 20000,
    CrewMembersID                                                     = 21000,
    CrewMemberIDID                                                    = 21100,
    HealthID                                                          = 21200,
    JobAssignment_string_ID                                           = 21300,
    FuelID                                                            = 23000,
    Quantity_liters_ID                                                = 23100,
    Quantity_gallons_ID                                               = 23105,
    AmmunitionID                                                      = 24000,
    _120_mmHEAT_quantity_Rounds_ID                                    = 24001,
    _120_mmSABOT_quantity_Rounds_ID                                   = 24002,
    _12_7_mmM8_quantity_Rounds_ID                                     = 24003,
    _12_7_mmM20_quantity_Rounds_ID                                    = 24004,
    _7_62_mmM62_quantity_Rounds_ID                                    = 24005,
    M250UKL8A1_quantity_Grenades_ID                                   = 24006,
    M250UKL8A3_quantity_Grenades_ID                                   = 24007,
    _7_62_mmM80_quantity_Rounds_ID                                    = 24008,
    _12_7_mm_quantity_Rounds_ID                                       = 24009,
    _7_62_mm_quantity_Rounds_ID                                       = 24010,
    Mines_quantity_Mines_ID                                           = 24060,
    TypeID                                                            = 24100,
    KindID                                                            = 24110,
    DomainID                                                          = 24120,
    CountryID                                                         = 24130,
    CategoryID                                                        = 24140,
    SubcategoryID                                                     = 24150,
    ExtraID                                                           = 24160,
    Description2ID                                                    = 24300,
    CargoID                                                           = 25000,
    VehicleMass_U32Kilograms_ID                                       = 26000,
    SupplyQuantityID                                                  = 27000,
    ArmamentID                                                        = 28000,
    StatusID                                                          = 30000,
    PositionID                                                        = 31000,
    MilGrid10ID                                                       = 31100,
    GeocentricCoordinatesID                                           = 31200,
    X_U32meters_ID                                                    = 31210,
    Y_U32meters_ID                                                    = 31220,
    Z_U32meters_ID                                                    = 31230,
    LatitudeID                                                        = 31300,
    LongitudeID                                                       = 31400,
    LineofSightID                                                     = 31500,
    XID                                                               = 31510,
    YID                                                               = 31520,
    ZID                                                               = 31530,
    OrientationID                                                     = 32000,
    HullHeadingAngle_degrees_ID                                       = 32100,
    HullPitchAngleID                                                  = 32200,
    RollAngleID                                                       = 32300,
    X_U32degrees_ID                                                   = 32500,
    Y_U32degrees_ID                                                   = 32600,
    Z_U32degrees_ID                                                   = 32700,
    AppearanceID                                                      = 33000,
    AmbientLightingID                                                 = 33100,
    LightsID                                                          = 33101,
    PaintSchemeID                                                     = 33200,
    SmokeID                                                           = 33300,
    TrailingEffectsID                                                 = 33400,
    FlamingID                                                         = 33500,
    MarkingID                                                         = 33600,
    MinePlowsAttachedID                                               = 33710,
    MineRollersAttachedID                                             = 33720,
    TankTurretAzimuth_degreesRel2Ion_ID                               = 33730,
    FailuresandMalfunctionsID                                         = 34000,
    Age_miles_ID                                                      = 34100,
    KilometersID                                                      = 34110,
    DamageID                                                          = 35000,
    CauseID                                                           = 35050,
    MobilityKillID                                                    = 35100,
    Fire_PowerKillID                                                  = 35200,
    PersonnelCasualtiesID                                             = 35300,
    VelocityID                                                        = 36000,
    X_velocity_meters_second_ID                                       = 36100,
    Y_velocity_meters_second_ID                                       = 36200,
    Z_velocity_meters_second_ID                                       = 36300,
    AccelerationID                                                    = 37000,
    X_accelerationID                                                  = 37100,
    Y_accelerationID                                                  = 37200,
    Z_accelerationID                                                  = 37300,
    EngineStatusID                                                    = 38100,
    ExerciseID                                                        = 40000,
    ExerciseStateID                                                   = 40010,
    AFATDSFileNameID                                                  = 40020,
    TerrainDatabaseID                                                 = 41000,
    MissionsID                                                        = 42000,
    MissionIDID                                                       = 42100,
    MissionTypeID                                                     = 42200,
    MissionRequestTimeStampID                                         = 42300,
    ExerciseDescription_string_ID                                     = 43000,
    Name_string_ID                                                    = 43100,
    Entities_integer_ID                                               = 43200,
    VersionID                                                         = 43300,
    GuiseMode_UI32_ID                                                 = 43410,
    SimulationApplicationActiveStatus_UI16_0Backup1Primary_ID         = 43420,
    SimulationApplicationRoleID_VariableID_64ID                       = 43430,
    SimulationApplicationState_VariableID_64ID                        = 43440,
    VisualOutputModeID                                                = 44000,
    SimulationManagerRole_VariableID_ID                               = 44100,
    SimulationManagerSiteID_UI16_ID                                   = 44110,
    SimulationManagerApplic_ID_UI16_ID                                = 44120,
    SimulationManagerEntityID_UnisgnedI16_ID                          = 44130,
    SimulationManagerActiveStatus_UI160Backup_1Primary_ID             = 44140,
    AfterActiveReviewRole_VariableID_ID                               = 44200,
    AfterActiveReviewSiteID_UI16_ID                                   = 44210,
    AfterActiveApplic_ID_UI16_ID                                      = 44220,
    AfterActiveReviewEntityID_UI16_ID                                 = 44230,
    AfterActiveReviewActiveStatus_UI160Backup_1PrimaryID              = 44240,
    ExerciseLoggerRole_VariableID_ID                                  = 44300,
    ExerciseLoggerSiteID_UI16_ID                                      = 44310,
    ExerciseLoggerApplic_ID_UI16_ID                                   = 44320,
    ExerciseEntityID_UI16_ID                                          = 44330,
    ExerciseLoggerActiveStatus_UI160Backup_1Primary_ID                = 44340,
    SyntheticEnvironmentManagerRole_VariableID_ID                     = 44400,
    SyntheticEnvironmentManagerSiteID_UI16_ID                         = 44410,
    SyntheticEnvironmentManagerApplic_ID_UI16_ID                      = 44420,
    SyntheticEnvironmentManagerEntityID_UI16_ID                       = 44430,
    SyntheticEnvironmentManagerActiveStatus_UI160Backup_1Primary_ID   = 44440,
    SIMNET_DISTranslatorRole_VariableID_ID                            = 44500,
    SIMNET_DISTranslatorSiteID_UI16_ID                                = 44510,
    SIMNET_DISTranslatorApplic_ID_UI16_ID                             = 44520,
    SIMNET_DISTranslatorEntityID_UI16_ID                              = 44530,
    SIMNET_DISTranslatorActiveStatus_UI160Backup_1Primary_ID          = 44540,
    EnvironmentID                                                     = 50000,
    WeatherID                                                         = 51000,
    ThermalConditionID                                                = 51100,
    TimeID                                                            = 52000,
    TimeofDay_DiscreteID                                              = 52100,
    TimeofDay_ContinuousID                                            = 52200,
    TimeModeID                                                        = 52300,
    TimeSceneID                                                       = 52305,
    CurrentHourID                                                     = 52310,
    CurrentMinuteID                                                   = 52320,
    CurrentSecondID                                                   = 52330,
    AzimuthID                                                         = 52340,
    MaximumElevationID                                                = 52350,
    TimeZoneID                                                        = 52360,
    TimeSunriseEnabledID                                              = 52400,
    SunriseHourID                                                     = 52410,
    SunriseMinuteID                                                   = 52420,
    SunriseSecondID                                                   = 52430,
    SunriseAzimuthID                                                  = 52440,
    TimeSunsetEnabledID                                               = 52500,
    SunsetHourID                                                      = 52510,
    SunsetHour1ID                                                     = 52511,
    SunsetMinuteID                                                    = 52520,
    SunsetSecondID                                                    = 52530,
    DateID                                                            = 52600,
    MonthID                                                           = 52610,
    DayID                                                             = 52620,
    YearID                                                            = 52630,
    CloudsID                                                          = 53000,
    CloudLayerEnableID                                                = 53050,
    CloudLayerSelectionID                                             = 53060,
    VisibilityID                                                      = 53100,
    BaseAltitude_meters_ID                                            = 53200,
    BaseAltitude_feet_ID                                              = 53250,
    Ceiling_meters_ID                                                 = 53300,
    Ceiling_feet_ID                                                   = 53350,
    CharactericticsID                                                 = 53400,
    ConcentrationLength_Float32__milligrams_meter_ID                  = 53410,
    Transmittance_Float32_ID                                          = 53420,
    Radiance_Float32__microwatts_centimeter_steradian_ID              = 53430,
    PrecipitationID                                                   = 54000,
    Rain_KBOOLean_ID                                                  = 54100,
    Fog_KBOOLean_ID                                                   = 55000,
    Visibility_meters_ID                                              = 55100,
    Visibility_miles_ID                                               = 55105,
    DensityID                                                         = 55200,
    BaseID                                                            = 55300,
    ViewLayerfromaboveID                                              = 55401,
    TransitionRangeID                                                 = 55410,
    Bottom_meters_ID                                                  = 55420,
    Bottom_feet_ID                                                    = 55425,
    Ceiling_meters_1ID                                                = 55430,
    Ceiling_feet_1ID                                                  = 55435,
    HeavenlyBodiesID                                                  = 56000,
    SunID                                                             = 56100,
    Position1ID                                                       = 56110,
    PositionAzimuthID                                                 = 56120,
    PositionElevationID                                               = 56130,
    PositionIntensityID                                               = 56140,
    MoonID                                                            = 56200,
    Position2ID                                                       = 56210,
    PositionAzimuth1ID                                                = 56220,
    PositionElevation1ID                                              = 56230,
    PositionIntensity1ID                                              = 56240,
    HorizonID                                                         = 56310,
    HorizonAzimuthID                                                  = 56320,
    HorizonElevationID                                                = 56330,
    HorizonHeadingID                                                  = 56340,
    HorizonIntensityID                                                = 56350,
    MeteorologicalID                                                  = 57000,
    TemperatureID                                                     = 57100,
    HumidityID                                                        = 57200,
    Visibility1ID                                                     = 57300,
    WindsID                                                           = 57400,
    SpeedID                                                           = 57410,
    RainsoakID                                                        = 57500,
    Haze_KBOOLean_ID                                                  = 58000,
    Visibility_meters_1ID                                             = 58100,
    Visibility_feet_ID                                                = 58105,
    Density1ID                                                        = 58200,
    Ceiling_meters_2ID                                                = 58430,
    Ceiling_feet_2ID                                                  = 58435,
    ContaminantsandObsurantsID                                        = 59000,
    Contaminant_ObscurantType_UI32_ID                                 = 59100,
    Persistence_Enumeration8_ID                                       = 59110,
    ChemicalDosage_Float32__milligrams_meter_minute_ID                = 59115,
    ChemicalAirConcentration_Float32__milligrams_meter_ID             = 59120,
    ChemicalGroundDeposition_Float32__milligrams_meter_ID             = 59125,
    ChemicalMaximumGroundDeposition_Float32__milligrams_meter_ID      = 59130,
    ChemicalDosageThreshold_Float32__milligram_meter_minute_ID        = 59135,
    BiologicalDosage_Float32__particles_literofair_minute_ID          = 59140,
    BiologicalAirConcentration_Float32__particles_literofair_ID       = 59145,
    BiologicalDosageThreshold_Float32__particles_literofair_minute_ID = 59150,
    BiologicalBinnedParticleCount_EnumID                              = 59155,
    RadiologicalDosage_FloatingPoint32_ID                             = 59160,
    CommunicationsID                                                  = 60000,
    ChannelTypeID                                                     = 61100,
    ChannelType1ID                                                    = 61101,
    ChannelIdentificationID                                           = 61200,
    AlphaIdentificationID                                             = 61300,
    RadioIdentificationID                                             = 61400,
    LandLineIdentificationID                                          = 61500,
    IntercomIdentificationID                                          = 61600,
    GroupNetworkChannelNumberID                                       = 61700,
    RadioCommunicationsStatusID                                       = 62100,
    StationaryRadioTransmittersDefaultTime_unsigned_Recod             = 62200,
    MovingRadioTransmittersDefaultTime_unsigned_ID                    = 62300,
    StationaryRadioSignalsDefaultTimeID                               = 62400,
    MovingRadioSignalsDefaultTimeID                                   = 62500,
    RadioInitializationTransecSecurityKey_record_ID                   = 63101,
    RadioInitializationInternalNoiseLevel_record_ID                   = 63102,
    RadioInitializationSquelchThreshold_record_ID                     = 63103,
    RadioInitializationAntennaLocation_record_ID                      = 63104,
    RadioInitializationAntennaPatternType_record_ID                   = 63105,
    RadioInitializationAntennaPatternLength_record_ID                 = 63106,
    RadioInitializationBeamDefinition_record_ID                       = 63107,
    RadioInitializationTransmitHeartbeatTime_record_ID                = 63108,
    RadioInitializationTransmitThresholdDistance_record_ID            = 63109,
    RadioChannelInitializationLockoutID_record_ID                     = 63110,
    RadioChannelInitializationHopsetID_record_ID                      = 63111,
    RadioChannelInitializationPresetFrequency_record_ID               = 63112,
    RadioChannelInitializationFrequencySyncTime_record_ID             = 63113,
    RadioChannelInitializationComsecKey_record_ID                     = 63114,
    RadioChannelInitializationAlpha_record_ID                         = 63115,
    AlgorithmParametersID                                             = 70000,
    DeadReckoningAlgorithm_DRA_ID                                     = 71000,
    DRALocationThreshold_unsigned32_ID                                = 71100,
    DRAOrientationThresholdID                                         = 71200,
    DRATimeThresholdID                                                = 71300,
    SimulationManagementParametersID                                  = 72000,
    CheckpointIntervalID                                              = 72100,
    TransmitterTimeThresholdID                                        = 72600,
    ReceiverTimeThresholdID                                           = 72700,
    InteroperabilityModeID                                            = 73000,
    SIMNETDataCollection_record_ID                                    = 74000,
    EventIDID                                                         = 75000,
    SourceSiteIDID                                                    = 75100,
    SourceHostIDID                                                    = 75200,
    ArticulatedPartsID                                                = 90000,
    PartIDID                                                          = 90050,
    Index_See4_7_2_ID                                                 = 90070,
    Position3ID                                                       = 90100,
    PositionRateID                                                    = 90200,
    ExtensionID                                                       = 90300,
    ExtensionRateID                                                   = 90400,
    X1ID                                                              = 90500,
    X_rateID                                                          = 90600,
    Y1ID                                                              = 90700,
    Y_rateID                                                          = 90800,
    Z1ID                                                              = 90900,
    Z_rateID                                                          = 91000,
    Azimuth1ID                                                        = 91100,
    AzimuthRateID                                                     = 91200,
    ElevationID                                                       = 91300,
    ElevationRateID                                                   = 91400,
    RotationID                                                        = 91500,
    RotationRateID                                                    = 91600,
    MunitionID                                                        = 500001, // 128 bits
    EngineFuelID                                                      = 500002, // 64 bits
    StorageFuelID                                                     = 500003, // 64 bits
    ExpendableExpendableID                                            = 500004, // 128 bits
    TotalRecordSetsID                                                 = 500005, // 32 bits
    LaunchedMunition                                                  = 500006, // 384 bits
    AssociationAssociationID                                          = 500007  // 256 bits
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeID_Enum();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorID_Enum( KUINT32 Index );

typedef ID_Enum DatumID;
typedef ID_Enum RecordID;
typedef ID_Enum AttributeID;

KString GetEnumAsStringID_Enum( KINT32 Value );
KString GetEnumAsStringDatumID( KINT32 Value );
KString GetEnumAsStringRecordID( KINT32 Value );
KString GetEnumAsStringAttributeID( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringID_Enum( const KString & Value, KINT32 & ValueOut ); 
KBOOL GetEnumFromStringDatumID( const KString & Value, KINT32 & ValueOut ); 
KBOOL GetEnumFromStringRecordID( const KString & Value, KINT32 & ValueOut ); 
KBOOL GetEnumFromStringAttributeID( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Rest Status                                                          */
/* Rest Status field in the Grouped Entity Description.                 */
/* Used In:                                                             */
/*  GED_EnhancedGroundCombatSoldier                                     */
/************************************************************************/

enum RestStatus
{
    NotRested                                                         = 0, // Has not slept in the last 3 days.
    Avg_1_HrADayInLast3Days                                           = 1, // Has slept an average of 1 hour per day in the last three days.
    Avg_2_HrADayInLast3Days                                           = 2, // Has slept an average of 2 hours per day in the last three days.
    Avg_3_HrADayInLast3Days                                           = 3, // Has slept an average of 3 hours per day in the last three days.
    Avg_4_HrADayInLast3Days                                           = 4, // Has slept an average of 4 hours per day in the last three days.
    Avg_5_HrADayInLast3Days                                           = 5, // Has slept an average of 5 hours per day in the last three days.
    Avg_6_HrADayInLast3Days                                           = 6, // Has slept an average of 6 hours per day in the last three days.
    Avg_7_HrADayInLast3Days                                           = 7, // Has slept an average of 7 hours per day in the last three days.
    FullyRested                                                       = 8  // Fully rested (Has slept an average of 8 hours per day in the last three days)
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeRestStatus();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorRestStatus( KUINT32 Index );

KString GetEnumAsStringRestStatus( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRestStatus( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* RelationshipNature                                                   */
/* Nature or purpose for joining of the part entity to the host         */
/* entity within a IsPartOf PDU.                                        */
/* Used In:                                                             */
/*  IsPartOf_PDU                                                        */
/************************************************************************/

enum RelationshipNature
{
    OtherNature                                                       = 0,
    HostFireableMunition                                              = 1,
    MunitionCarriedAsCargo                                            = 2,
    FuelCarriedAsCargo                                                = 3,
    GunmountAttachedToHost                                            = 4,
    ComputerGeneratedForcesCarriedAsCargo                             = 5,
    VehicleCarriedAsCargo                                             = 6,
    EmitterMountedOnHost                                              = 7,
    MobileCommandAndControlEntityCarriedAboardHost                    = 8,
    EntityStationedAt                                                 = 9, // See Position enumerations with respect to host.
    TeamMemberInFormationWith                                         = 10
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeRelationshipNature();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorRelationshipNature( KUINT32 Index );

KString GetEnumAsStringRelationshipNature( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRelationshipNature( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* RelationshipPosition                                                 */
/* Specifies the position of the part entity with respect to the host   */
/* entity within a IsPartOf PDU.                                        */
/* Used In:                                                             */
/*  IsPartOf_PDU                                                        */
/************************************************************************/

enum RelationshipPosition
{
    OtherPosition                                                     = 0,
    OnTopOf                                                           = 1,
    InsideOf                                                          = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeRelationshipPosition();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorRelationshipPosition( KUINT32 Index );

KString GetEnumAsStringRelationshipPosition( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRelationshipPosition( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* StationName                                                          */
/* Specifies the station name within the host at which the part entity  */
/* is located. If the part entity is On Station, this field shall       */
/* specify the representation of the part�s location data fields.       */
/* Used In:                                                             */
/*  IsPartOf_PDU                                                        */
/************************************************************************/

enum StationName
{
    OtherStationName                                                  = 0,
    AircraftWingstation                                               = 1,
    ShipsForwardGunmount_Starboard                                    = 2,
    ShipsForwardGunmount_Port                                         = 3,
    ShipsForwardGunmount_Centerline                                   = 4,
    ShipsAftGunmount_Starboard                                        = 5,
    ShipsAftGunmount_Port                                             = 6,
    ShipsAftGunmount_Centerline                                       = 7,
    ForwardTorpedoTube                                                = 8,
    AftTorpedoTube                                                    = 9,
    BombBay                                                           = 10,
    CargoBay                                                          = 11,
    TruckBed                                                          = 12,
    TrailerBed                                                        = 13,
    WellDeck                                                          = 14,
    OnStationRangeAndBearing                                          = 15,
    OnStationXYZ                                                      = 16
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeStationName();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorStationName( KUINT32 Index );

KString GetEnumAsStringStationName( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringStationName( const KString & Value, KINT32 & ValueOut ); 

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
