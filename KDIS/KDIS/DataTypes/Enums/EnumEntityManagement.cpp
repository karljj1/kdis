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

#include "./EnumEntityManagement.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for AggregateState

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AggregateStateDescriptor[] =
{
    { 0 , "OtherAggregateState" },
    { 1 , "Aggregated" },
    { 2 , "Disaggregated" },
    { 3 , "FullyDisaggregated" },
    { 4 , "PseudoDisaggregated" },
    { 5 , "PartiallyDisaggregated" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAggregateState()
{
	return sizeof( AggregateStateDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAggregateState( KUINT32 Index )
{
	return &AggregateStateDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAggregateState( KINT32 Value )
{
    return GetEnumAsString( AggregateStateDescriptor, sizeof( AggregateStateDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAggregateState( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AggregateStateDescriptor, sizeof( AggregateStateDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAggregateState()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAggregateState( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAggregateState( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAggregateState( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AggregateKind

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AggregateKindDescriptor[] =
{
    { 0 , "OtherAggregateKind" },
    { 1 , "MilitaryHierachy" },
    { 2 , "CommonType" },
    { 3 , "CommonMission" },
    { 4 , "SimilarCapabilities" },
    { 5 , "CommonLocation" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAggregateKind()
{
	return sizeof( AggregateKindDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAggregateKind( KUINT32 Index )
{
	return &AggregateKindDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAggregateKind( KINT32 Value )
{
    return GetEnumAsString( AggregateKindDescriptor, sizeof( AggregateKindDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAggregateKind( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AggregateKindDescriptor, sizeof( AggregateKindDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAggregateKind()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAggregateKind( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAggregateKind( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAggregateKind( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for Formation

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor FormationDescriptor[] =
{
    { 0 , "OtherFormation" },
    { 1 , "Assembly" },
    { 2 , "Vee" },
    { 3 , "Wedge" },
    { 4 , "Line" },
    { 5 , "Column" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeFormation()
{
	return sizeof( FormationDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorFormation( KUINT32 Index )
{
	return &FormationDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringFormation( KINT32 Value )
{
    return GetEnumAsString( FormationDescriptor, sizeof( FormationDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringFormation( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( FormationDescriptor, sizeof( FormationDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeFormation()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorFormation( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringFormation( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringFormation( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for GroupedEntityCategory

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor GroupedEntityCategoryDescriptor[] =
{
    { 0 , "UndefinedGEC" },
    { 1 , "BasicGroundCombatVehicleGEC" },
    { 2 , "EnhancedGroundCombatVehicleGEC" },
    { 3 , "BasicGroundCombatSoldierGEC" },
    { 4 , "EnhancedGroundCombatSoldierGEC" },
    { 5 , "BasicRotorWingAircraftGEC" },
    { 6 , "EnhancedRotorWingAircraftGEC" },
    { 7 , "BasicFixedWingAircraftGEC" },
    { 8 , "EnhancedFixedWingAircraftGEC" },
    { 9 , "GroundLogisticsVehicleGEC" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeGroupedEntityCategory()
{
	return sizeof( GroupedEntityCategoryDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorGroupedEntityCategory( KUINT32 Index )
{
	return &GroupedEntityCategoryDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringGroupedEntityCategory( KINT32 Value )
{
    return GetEnumAsString( GroupedEntityCategoryDescriptor, sizeof( GroupedEntityCategoryDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringGroupedEntityCategory( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( GroupedEntityCategoryDescriptor, sizeof( GroupedEntityCategoryDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeGroupedEntityCategory()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorGroupedEntityCategory( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringGroupedEntityCategory( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringGroupedEntityCategory( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for TransferType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TransferTypeDescriptor[] =
{
    { 0 , "OtherTransferType" },
    { 1 , "ControllingApplicationRequestsTransferOfAnEntity" },
    { 2 , "ApplicationDesiringControlRequestsTransferOfAnEntity" },
    { 3 , "MutualExchange_SwapOfAnEntity" },
    { 4 , "ControllingApplicationRequestsTransferOfAnEnvironmentalProcess" },
    { 5 , "ApplicationDesiringControlsRequestsTransferOfAnEnvironmentalProcess" },
    { 6 , "MutualExchange_SwapOfAnEnvironmental" },
    { 7 , "CancelTransfer" },
    { 8 , "ManualPullTransfer_Entity" },
    { 9 , "ManualPullTransfer_EnvironmentalProcess" },
    { 10 , "RemoveEntity" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTransferType()
{
	return sizeof( TransferTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTransferType( KUINT32 Index )
{
	return &TransferTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTransferType( KINT32 Value )
{
    return GetEnumAsString( TransferTypeDescriptor, sizeof( TransferTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTransferType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TransferTypeDescriptor, sizeof( TransferTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTransferType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTransferType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTransferType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTransferType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ID_Enum

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ID_EnumDescriptor[] =
{
    { 10000 , "IdentificationID" },
    { 11000 , "EntityTypeID" },
    { 11100 , "ConcatenatedID" },
    { 11110 , "Kind_U8_ID" },
    { 11120 , "Domain_U8_ID" },
    { 11130 , "Country_U16_ID" },
    { 11140 , "Category_U8_ID" },
    { 11150 , "Subcategory_U8_ID" },
    { 11160 , "Specific_U8_ID" },
    { 11170 , "Extra_U8_ID" },
    { 11200 , "ForceID_U8_ID" },
    { 11300 , "DescriptionID" },
    { 12000 , "AlternativeEntityTypeID" },
    { 12110 , "Kind_U8_1ID" },
    { 12120 , "Domain_U8_1ID" },
    { 12130 , "Country_U16_1ID" },
    { 12140 , "Category_U8_1ID" },
    { 12150 , "Subcategory_U8_1ID" },
    { 12160 , "Specific_U8_1ID" },
    { 12170 , "Extra_U8_1ID" },
    { 12300 , "Description1ID" },
    { 13000 , "EntityMarkingID" },
    { 13100 , "EntityMarkingString_string80_ID" },
    { 13200 , "CrewID_string80_ID" },
    { 14000 , "TaskOrganizationID" },
    { 14200 , "RegimentName_string_ID" },
    { 14300 , "BattalionName_string_ID" },
    { 14400 , "CompanyName_string_ID" },
    { 14500 , "PlatoonNameID" },
    { 14520 , "SquadNameID" },
    { 14540 , "TeamNameID" },
    { 14600 , "BumperNameID" },
    { 14700 , "VehicleNameID" },
    { 14800 , "UnitNumberID" },
    { 15000 , "DISIdentityID" },
    { 15100 , "DISSiteIDID" },
    { 15200 , "DISHostIDID" },
    { 15300 , "DISEntityIDID" },
    { 15800 , "OwnershipStatusID" },
    { 20000 , "LoadsID" },
    { 21000 , "CrewMembersID" },
    { 21100 , "CrewMemberIDID" },
    { 21200 , "HealthID" },
    { 21300 , "JobAssignment_string_ID" },
    { 23000 , "FuelID" },
    { 23100 , "Quantity_liters_ID" },
    { 23105 , "Quantity_gallons_ID" },
    { 24000 , "AmmunitionID" },
    { 24001 , "_120_mmHEAT_quantity_Rounds_ID" },
    { 24002 , "_120_mmSABOT_quantity_Rounds_ID" },
    { 24003 , "_12_7_mmM8_quantity_Rounds_ID" },
    { 24004 , "_12_7_mmM20_quantity_Rounds_ID" },
    { 24005 , "_7_62_mmM62_quantity_Rounds_ID" },
    { 24006 , "M250UKL8A1_quantity_Grenades_ID" },
    { 24007 , "M250UKL8A3_quantity_Grenades_ID" },
    { 24008 , "_7_62_mmM80_quantity_Rounds_ID" },
    { 24009 , "_12_7_mm_quantity_Rounds_ID" },
    { 24010 , "_7_62_mm_quantity_Rounds_ID" },
    { 24060 , "Mines_quantity_Mines_ID" },
    { 24100 , "TypeID" },
    { 24110 , "KindID" },
    { 24120 , "DomainID" },
    { 24130 , "CountryID" },
    { 24140 , "CategoryID" },
    { 24150 , "SubcategoryID" },
    { 24160 , "ExtraID" },
    { 24300 , "Description2ID" },
    { 25000 , "CargoID" },
    { 26000 , "VehicleMass_U32Kilograms_ID" },
    { 27000 , "SupplyQuantityID" },
    { 28000 , "ArmamentID" },
    { 30000 , "StatusID" },
    { 31000 , "PositionID" },
    { 31100 , "MilGrid10ID" },
    { 31200 , "GeocentricCoordinatesID" },
    { 31210 , "X_U32meters_ID" },
    { 31220 , "Y_U32meters_ID" },
    { 31230 , "Z_U32meters_ID" },
    { 31300 , "LatitudeID" },
    { 31400 , "LongitudeID" },
    { 31500 , "LineofSightID" },
    { 31510 , "XID" },
    { 31520 , "YID" },
    { 31530 , "ZID" },
    { 32000 , "OrientationID" },
    { 32100 , "HullHeadingAngle_degrees_ID" },
    { 32200 , "HullPitchAngleID" },
    { 32300 , "RollAngleID" },
    { 32500 , "X_U32degrees_ID" },
    { 32600 , "Y_U32degrees_ID" },
    { 32700 , "Z_U32degrees_ID" },
    { 33000 , "AppearanceID" },
    { 33100 , "AmbientLightingID" },
    { 33101 , "LightsID" },
    { 33200 , "PaintSchemeID" },
    { 33300 , "SmokeID" },
    { 33400 , "TrailingEffectsID" },
    { 33500 , "FlamingID" },
    { 33600 , "MarkingID" },
    { 33710 , "MinePlowsAttachedID" },
    { 33720 , "MineRollersAttachedID" },
    { 33730 , "TankTurretAzimuth_degreesRel2Ion_ID" },
    { 34000 , "FailuresandMalfunctionsID" },
    { 34100 , "Age_miles_ID" },
    { 34110 , "KilometersID" },
    { 35000 , "DamageID" },
    { 35050 , "CauseID" },
    { 35100 , "MobilityKillID" },
    { 35200 , "Fire_PowerKillID" },
    { 35300 , "PersonnelCasualtiesID" },
    { 36000 , "VelocityID" },
    { 36100 , "X_velocity_meters_second_ID" },
    { 36200 , "Y_velocity_meters_second_ID" },
    { 36300 , "Z_velocity_meters_second_ID" },
    { 37000 , "AccelerationID" },
    { 37100 , "X_accelerationID" },
    { 37200 , "Y_accelerationID" },
    { 37300 , "Z_accelerationID" },
    { 38100 , "EngineStatusID" },
    { 40000 , "ExerciseID" },
    { 40010 , "ExerciseStateID" },
    { 40020 , "AFATDSFileNameID" },
    { 41000 , "TerrainDatabaseID" },
    { 42000 , "MissionsID" },
    { 42100 , "MissionIDID" },
    { 42200 , "MissionTypeID" },
    { 42300 , "MissionRequestTimeStampID" },
    { 43000 , "ExerciseDescription_string_ID" },
    { 43100 , "Name_string_ID" },
    { 43200 , "Entities_Integer_ID" },
    { 43300 , "VersionID" },
    { 43410 , "GuiseMode_UI32_ID" },
    { 43420 , "SimulationApplicationActiveStatus_UI16_0Backup1Primary_ID" },
    { 43430 , "SimulationApplicationRoleID_VariableID_64ID" },
    { 43440 , "SimulationApplicationState_VariableID_64ID" },
    { 44000 , "VisualOutputModeID" },
    { 44100 , "SimulationManagerRole_VariableID_ID" },
    { 44110 , "SimulationManagerSiteID_UI16_ID" },
    { 44120 , "SimulationManagerApplic_ID_UI16_ID" },
    { 44130 , "SimulationManagerEntityID_UnisgnedI16_ID" },
    { 44140 , "SimulationManagerActiveStatus_UI160Backup_1Primary_ID" },
    { 44200 , "AfterActiveReviewRole_VariableID_ID" },
    { 44210 , "AfterActiveReviewSiteID_UI16_ID" },
    { 44220 , "AfterActiveApplic_ID_UI16_ID" },
    { 44230 , "AfterActiveReviewEntityID_UI16_ID" },
    { 44240 , "AfterActiveReviewActiveStatus_UI160Backup_1PrimaryID" },
    { 44300 , "ExerciseLoggerRole_VariableID_ID" },
    { 44310 , "ExerciseLoggerSiteID_UI16_ID" },
    { 44320 , "ExerciseLoggerApplic_ID_UI16_ID" },
    { 44330 , "ExerciseEntityID_UI16_ID" },
    { 44340 , "ExerciseLoggerActiveStatus_UI160Backup_1Primary_ID" },
    { 44400 , "SyntheticEnvironmentManagerRole_VariableID_ID" },
    { 44410 , "SyntheticEnvironmentManagerSiteID_UI16_ID" },
    { 44420 , "SyntheticEnvironmentManagerApplic_ID_UI16_ID" },
    { 44430 , "SyntheticEnvironmentManagerEntityID_UI16_ID" },
    { 44440 , "SyntheticEnvironmentManagerActiveStatus_UI160Backup_1Primary_ID" },
    { 44500 , "SIMNET_DISTranslatorRole_VariableID_ID" },
    { 44510 , "SIMNET_DISTranslatorSiteID_UI16_ID" },
    { 44520 , "SIMNET_DISTranslatorApplic_ID_UI16_ID" },
    { 44530 , "SIMNET_DISTranslatorEntityID_UI16_ID" },
    { 44540 , "SIMNET_DISTranslatorActiveStatus_UI160Backup_1Primary_ID" },
    { 50000 , "EnvironmentID" },
    { 51000 , "WeatherID" },
    { 51100 , "ThermalConditionID" },
    { 52000 , "TimeID" },
    { 52100 , "TimeofDay_DiscreteID" },
    { 52200 , "TimeofDay_ContinuousID" },
    { 52300 , "TimeModeID" },
    { 52305 , "TimeSceneID" },
    { 52310 , "CurrentHourID" },
    { 52320 , "CurrentMinuteID" },
    { 52330 , "CurrentSecondID" },
    { 52340 , "AzimuthID" },
    { 52350 , "MaximumElevationID" },
    { 52360 , "TimeZoneID" },
    { 52400 , "TimeSunriseEnabledID" },
    { 52410 , "SunriseHourID" },
    { 52420 , "SunriseMinuteID" },
    { 52430 , "SunriseSecondID" },
    { 52440 , "SunriseAzimuthID" },
    { 52500 , "TimeSunsetEnabledID" },
    { 52510 , "SunsetHourID" },
    { 52511 , "SunsetHour1ID" },
    { 52520 , "SunsetMinuteID" },
    { 52530 , "SunsetSecondID" },
    { 52600 , "DateID" },
    { 52610 , "MonthID" },
    { 52620 , "DayID" },
    { 52630 , "YearID" },
    { 53000 , "CloudsID" },
    { 53050 , "CloudLayerEnableID" },
    { 53060 , "CloudLayerSelectionID" },
    { 53100 , "VisibilityID" },
    { 53200 , "BaseAltitude_meters_ID" },
    { 53250 , "BaseAltitude_feet_ID" },
    { 53300 , "Ceiling_meters_ID" },
    { 53350 , "Ceiling_feet_ID" },
    { 53400 , "CharactericticsID" },
    { 53410 , "ConcentrationLength_Float32__milligrams_meter_ID" },
    { 53420 , "Transmittance_Float32_ID" },
    { 53430 , "Radiance_Float32__microwatts_centimeter_steradian_ID" },
    { 54000 , "PrecipitationID" },
    { 54100 , "Rain_KBOOLean_ID" },
    { 55000 , "Fog_KBOOLean_ID" },
    { 55100 , "Visibility_meters_ID" },
    { 55105 , "Visibility_miles_ID" },
    { 55200 , "DensityID" },
    { 55300 , "BaseID" },
    { 55401 , "ViewLayerfromaboveID" },
    { 55410 , "TransitionRangeID" },
    { 55420 , "Bottom_meters_ID" },
    { 55425 , "Bottom_feet_ID" },
    { 55430 , "Ceiling_meters_1ID" },
    { 55435 , "Ceiling_feet_1ID" },
    { 56000 , "HeavenlyBodiesID" },
    { 56100 , "SunID" },
    { 56110 , "Position1ID" },
    { 56120 , "PositionAzimuthID" },
    { 56130 , "PositionElevationID" },
    { 56140 , "PositionIntensityID" },
    { 56200 , "MoonID" },
    { 56210 , "Position2ID" },
    { 56220 , "PositionAzimuth1ID" },
    { 56230 , "PositionElevation1ID" },
    { 56240 , "PositionIntensity1ID" },
    { 56310 , "HorizonID" },
    { 56320 , "HorizonAzimuthID" },
    { 56330 , "HorizonElevationID" },
    { 56340 , "HorizonHeadingID" },
    { 56350 , "HorizonIntensityID" },
    { 57000 , "MeteorologicalID" },
    { 57100 , "TemperatureID" },
    { 57200 , "HumidityID" },
    { 57300 , "Visibility1ID" },
    { 57400 , "WindsID" },
    { 57410 , "SpeedID" },
    { 57500 , "RainsoakID" },
    { 58000 , "Haze_KBOOLean_ID" },
    { 58100 , "Visibility_meters_1ID" },
    { 58105 , "Visibility_feet_ID" },
    { 58200 , "Density1ID" },
    { 58430 , "Ceiling_meters_2ID" },
    { 58435 , "Ceiling_feet_2ID" },
    { 59000 , "ContaminantsandObsurantsID" },
    { 59100 , "Contaminant_ObscurantType_UI32_ID" },
    { 59110 , "Persistence_Enumeration8_ID" },
    { 59115 , "ChemicalDosage_Float32__milligrams_meter_minute_ID" },
    { 59120 , "ChemicalAirConcentration_Float32__milligrams_meter_ID" },
    { 59125 , "ChemicalGroundDeposition_Float32__milligrams_meter_ID" },
    { 59130 , "ChemicalMaximumGroundDeposition_Float32__milligrams_meter_ID" },
    { 59135 , "ChemicalDosageThreshold_Float32__milligram_meter_minute_ID" },
    { 59140 , "BiologicalDosage_Float32__particles_literofair_minute_ID" },
    { 59145 , "BiologicalAirConcentration_Float32__particles_literofair_ID" },
    { 59150 , "BiologicalDosageThreshold_Float32__particles_literofair_minute_ID" },
    { 59155 , "BiologicalBinnedParticleCount_EnumID" },
    { 59160 , "RadiologicalDosage_FloatingPoInt32_ID" },
    { 60000 , "CommunicationsID" },
    { 61100 , "ChannelTypeID" },
    { 61101 , "ChannelType1ID" },
    { 61200 , "ChannelIdentificationID" },
    { 61300 , "AlphaIdentificationID" },
    { 61400 , "RadioIdentificationID" },
    { 61500 , "LandLineIdentificationID" },
    { 61600 , "IntercomIdentificationID" },
    { 61700 , "GroupNetworkChannelNumberID" },
    { 62100 , "RadioCommunicationsStatusID" },
    { 62200 , "StationaryRadioTransmittersDefaultTime_unsigned_Recod" },
    { 62300 , "MovingRadioTransmittersDefaultTime_unsigned_ID" },
    { 62400 , "StationaryRadioSignalsDefaultTimeID" },
    { 62500 , "MovingRadioSignalsDefaultTimeID" },
    { 63101 , "RadioInitializationTransecSecurityKey_record_ID" },
    { 63102 , "RadioInitializationInternalNoiseLevel_record_ID" },
    { 63103 , "RadioInitializationSquelchThreshold_record_ID" },
    { 63104 , "RadioInitializationAntennaLocation_record_ID" },
    { 63105 , "RadioInitializationAntennaPatternType_record_ID" },
    { 63106 , "RadioInitializationAntennaPatternLength_record_ID" },
    { 63107 , "RadioInitializationBeamDefinition_record_ID" },
    { 63108 , "RadioInitializationTransmitHeartbeatTime_record_ID" },
    { 63109 , "RadioInitializationTransmitThresholdDistance_record_ID" },
    { 63110 , "RadioChannelInitializationLockoutID_record_ID" },
    { 63111 , "RadioChannelInitializationHopsetID_record_ID" },
    { 63112 , "RadioChannelInitializationPresetFrequency_record_ID" },
    { 63113 , "RadioChannelInitializationFrequencySyncTime_record_ID" },
    { 63114 , "RadioChannelInitializationComsecKey_record_ID" },
    { 63115 , "RadioChannelInitializationAlpha_record_ID" },
    { 70000 , "AlgorithmParametersID" },
    { 71000 , "DeadReckoningAlgorithm_DRA_ID" },
    { 71100 , "DRALocationThreshold_unsigned32_ID" },
    { 71200 , "DRAOrientationThresholdID" },
    { 71300 , "DRATimeThresholdID" },
    { 72000 , "SimulationManagementParametersID" },
    { 72100 , "CheckpointIntervalID" },
    { 72600 , "TransmitterTimeThresholdID" },
    { 72700 , "ReceiverTimeThresholdID" },
    { 73000 , "InteroperabilityModeID" },
    { 74000 , "SIMNETDataCollection_record_ID" },
    { 75000 , "EventIDID" },
    { 75100 , "SourceSiteIDID" },
    { 75200 , "SourceHostIDID" },
    { 90000 , "ArticulatedPartsID" },
    { 90050 , "PartIDID" },
    { 90070 , "Index_See4_7_2_ID" },
    { 90100 , "Position3ID" },
    { 90200 , "PositionRateID" },
    { 90300 , "ExtensionID" },
    { 90400 , "ExtensionRateID" },
    { 90500 , "X1ID" },
    { 90600 , "X_rateID" },
    { 90700 , "Y1ID" },
    { 90800 , "Y_rateID" },
    { 90900 , "Z1ID" },
    { 91000 , "Z_rateID" },
    { 91100 , "Azimuth1ID" },
    { 91200 , "AzimuthRateID" },
    { 91300 , "ElevationID" },
    { 91400 , "ElevationRateID" },
    { 91500 , "RotationID" },
    { 91600 , "RotationRateID" },
    { 100001 , "DRAAngularX_VelocityID" },
    { 100002 , "DRAAngularY_VelocityID" },
    { 100003 , "DRAAngularZ_VelocityID" },
    { 100004 , "Appearance_TrailingEffectsID" },
    { 100005 , "Appearance_HatchID" },
    { 100008 , "Appearance_CharacterSetID" },
    { 100010 , "Capability_AmmunitionSupplierID" },
    { 100011 , "Capability_MiscellaneousSupplierID" },
    { 100012 , "Capability_RepairProviderID" },
    { 100014 , "ArticulationParameterID" },
    { 100047 , "ArticulationParameterTypeID" },
    { 100048 , "ArticulationParameterValueID" },
    { 100058 , "TimeofDay__SceneID" },
    { 100100 , "SonarSystemStatusID" },
    { 100160 , "UpperLatitudeID" },
    { 100161 , "LatitudeSouth_LocationOfWeatherCellID" },
    { 100162 , "WesternLongitudeID" },
    { 100163 , "LongitudeWest_LocationOfWeatherCellID" },
    { 100164 , "AccomplishedAcceptID" },
    { 100165 , "CDROMNumber_DiskIDForTerrainID" },
    { 100166 , "DTEDDiskID" },
    { 100167 , "AltitudeID" },
    { 100169 , "TacticalSystemStatusID" },
    { 100170 , "JTIDSStatusID" },
    { 100171 , "TADIL_JStatusID" },
    { 100172 , "DSDDStatusID" },
    { 100200 , "WeaponSystemStatusID" },
    { 100300 , "Entity_Track_UpdateDataID" },
    { 100400 , "Local_ForceTrainingID" },
    { 100500 , "Entity_TrackIdentityDataID" },
    { 100600 , "EngagementDataID" },
    { 100700 , "Entity_TrackEquipmentDataID" },
    { 100800 , "Emission_EWDataID" },
    { 100900 , "AppearanceDataID" },
    { 101000 , "Command_OrderDataID" },
    { 101100 , "EnvironmentalDataID" },
    { 101200 , "SignificantEventDataID" },
    { 101300 , "OperatorActionDataID" },
    { 101400 , "TimeSynchronizationID" },
    { 101500 , "TomahawkDataID" },
    { 500001 , "MunitionID" },
    { 500002 , "EngineFuelID" },
    { 500003 , "StorageFuelID" },
    { 500004 , "ExpendableExpendableID" },
    { 500005 , "TotalRecordSetsID" },
    { 500006 , "LaunchedMunition" },
    { 500007 , "AssociationAssociationID" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeID_Enum()
{
	return sizeof( ID_EnumDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorID_Enum( KUINT32 Index )
{
	return &ID_EnumDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringID_Enum( KINT32 Value )
{
    return GetEnumAsString( ID_EnumDescriptor, sizeof( ID_EnumDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringID_Enum( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ID_EnumDescriptor, sizeof( ID_EnumDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeID_Enum()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorID_Enum( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringID_Enum( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringID_Enum( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

// As
KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDatumID( KINT32 Value )
{
    return GetEnumAsStringID_Enum( Value );
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRecordID( KINT32 Value )
{
    return GetEnumAsStringID_Enum( Value );
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAttributeID( KINT32 Value )
{
    return GetEnumAsStringID_Enum( Value );
}

// From
KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDatumID( const KString & Value, KINT32 & ValueOut  )
{
	return GetEnumFromStringID_Enum( Value, ValueOut );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRecordID( const KString & Value, KINT32 & ValueOut  )
{
    return GetEnumFromStringID_Enum( Value, ValueOut );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAttributeID( const KString & Value, KINT32 & ValueOut  )
{
    return GetEnumFromStringID_Enum( Value, ValueOut );
}

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for RestStatus

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor RestStatusDescriptor[] =
{
    { 0 , "NotRested" },
    { 1 , "Avg_1_HrADayInLast3Days" },
    { 2 , "Avg_2_HrADayInLast3Days" },
    { 3 , "Avg_3_HrADayInLast3Days" },
    { 4 , "Avg_4_HrADayInLast3Days" },
    { 5 , "Avg_5_HrADayInLast3Days" },
    { 6 , "Avg_6_HrADayInLast3Days" },
    { 7 , "Avg_7_HrADayInLast3Days" },
    { 8 , "FullyRested" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRestStatus()
{
	return sizeof( RestStatusDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRestStatus( KUINT32 Index )
{
	return &RestStatusDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRestStatus( KINT32 Value )
{
    return GetEnumAsString( RestStatusDescriptor, sizeof( RestStatusDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRestStatus( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( RestStatusDescriptor, sizeof( RestStatusDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRestStatus()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRestStatus( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRestStatus( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRestStatus( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for RelationshipNature

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor RelationshipNatureDescriptor[] =
{
    { 0 , "OtherNature" },
    { 1 , "HostFireableMunition" },
    { 2 , "MunitionCarriedAsCargo" },
    { 3 , "FuelCarriedAsCargo" },
    { 4 , "GunmountAttachedToHost" },
    { 5 , "ComputerGeneratedForcesCarriedAsCargo" },
    { 6 , "VehicleCarriedAsCargo" },
    { 7 , "EmitterMountedOnHost" },
    { 8 , "MobileCommandAndControlEntityCarriedAboardHost" },
    { 9 , "EntityStationedAt" },
    { 10 , "TeamMemberInFormationWith" } 
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRelationshipNature()
{
	return sizeof( RelationshipNatureDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRelationshipNature( KUINT32 Index )
{
	return &RelationshipNatureDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRelationshipNature( KINT32 Value )
{
    return GetEnumAsString( RelationshipNatureDescriptor, sizeof( RelationshipNatureDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRelationshipNature( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( RelationshipNatureDescriptor, sizeof( RelationshipNatureDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRelationshipNature()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRelationshipNature( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRelationshipNature( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRelationshipNature( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for RelationshipPosition

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor RelationshipPositionDescriptor[] =
{
    { 0 , "OtherPosition" },
    { 1 , "OnTopOf" },
    { 2 , "InsideOf" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRelationshipPosition()
{
	return sizeof( RelationshipPositionDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRelationshipPosition( KUINT32 Index )
{
	return &RelationshipPositionDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRelationshipPosition( KINT32 Value )
{
    return GetEnumAsString( RelationshipPositionDescriptor, sizeof( RelationshipPositionDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRelationshipPosition( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( RelationshipPositionDescriptor, sizeof( RelationshipPositionDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeRelationshipPosition()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorRelationshipPosition( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringRelationshipPosition( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringRelationshipPosition( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for StationName

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor StationNameDescriptor[] =
{
    { 0 , "OtherStationName" },
    { 1 , "AircraftWingstation" },
    { 2 , "ShipsForwardGunmount_Starboard" },
    { 3 , "ShipsForwardGunmount_Port" },
    { 4 , "ShipsForwardGunmount_Centerline" },
    { 5 , "ShipsAftGunmount_Starboard" },
    { 6 , "ShipsAftGunmount_Port" },
    { 7 , "ShipsAftGunmount_Centerline" },
    { 8 , "ForwardTorpedoTube" },
    { 9 , "AftTorpedoTube" },
    { 10 , "BombBay" },
    { 11 , "CargoBay" },
	{ 12 , "TruckBed" },
	{ 13 , "TrailerBed" },
	{ 14 , "WellDeck" },
	{ 15 , "OnStationRangeAndBearing" },
	{ 16 , "OnStationXYZ" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeStationName()
{
	return sizeof( StationNameDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorStationName( KUINT32 Index )
{
	return &StationNameDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStationName( KINT32 Value )
{
    return GetEnumAsString( StationNameDescriptor, sizeof( StationNameDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringStationName( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( StationNameDescriptor, sizeof( StationNameDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeStationName()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorStationName( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringStationName( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringStationName( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif




