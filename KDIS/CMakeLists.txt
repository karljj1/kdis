CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(KDIS)

#Import all files, Headers and cpp files seperate.

#Options-------------------------------------------------

OPTION(BUILD_EXAMPLES_TO_LINK_TO_LIB "Build the examples so they link against a Lib version of KDIS instead of including the whole source for each example" ON)
SET(EXAMPLES_USE_STATIC_OR_SHARED_LIB STATIC CACHE STRING "If BUILD_EXAMPLES_TO_LINK_TO_LIB is ON then do you want to build against a STATIC library or a SHARED library(dll)")
SET(DIS_VERSION 7 CACHE STRING "The version of DIS to use. IEEE 1278.1-1995(5), IEEE 1278.1A-1998(6) or IEEE 1278.1x-2012(7). This parameter will decide what files should be included in the example projects.")
OPTION(KDIS_USE_ENUM_DESCRIPTORS "Use enumeration descriptors. These allow enum values to be turned into their text labels. This increase the memory footprint of your application so do not enable if you do not plan to use." ON)
OPTION(BUILD_EXAMPLES "Create example projects" ON)
OPTION(USE_SOLUTION_FOLDERS "Organise all projects into folders in your solution. At the moment this feature seems to be Visual Studio Professional(Not Express) only." ON)
OPTION(BUILD_TESTS "Build the KDIS unit tests. Uses the google test framework.")

IF(NOT DIS_VERSION MATCHES 5 AND NOT DIS_VERSION GREATER 5 AND NOT DIS_VERSION GREATER 6)
MESSAGE(FATAL_ERROR "Invalid DIS version, only 5, 6 and 7 are supported")
ENDIF(NOT DIS_VERSION MATCHES 5 AND NOT DIS_VERSION GREATER 5 AND NOT DIS_VERSION GREATER 6)

IF(NOT EXAMPLES_USE_STATIC_OR_SHARED_LIB MATCHES SHARED AND NOT EXAMPLES_USE_STATIC_OR_SHARED_LIB MATCHES STATIC)
MESSAGE(FATAL_ERROR "Invalid EXAMPLES_USE_STATIC_OR_SHARED_LIB parameter, only STATIC or SHARED is allowed")
ENDIF(NOT EXAMPLES_USE_STATIC_OR_SHARED_LIB MATCHES SHARED AND NOT EXAMPLES_USE_STATIC_OR_SHARED_LIB MATCHES STATIC)

IF(USE_SOLUTION_FOLDERS)
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
ELSE(USE_SOLUTION_FOLDERS)
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS OFF)
ENDIF(USE_SOLUTION_FOLDERS)

########################################################
#                       Base                           #
########################################################

SET(BASE_DIRNAME KDIS)
SET(BASE_DIR ${KDIS_SOURCE_DIR}/KDIS)

# *.H

SET(KDIS_SRC_BASE_H
    ${BASE_DIR}/KDataStream.h
    ${BASE_DIR}/KDefines.h
    ${BASE_DIR}/KEncodersDecoders.h
    ${BASE_DIR}/KSymbolicNames.h
)

# *.cpp

SET(KDIS_SRC_BASE_CPP ${BASE_DIR}/KDataStream.cpp)

########################################################
#                       DataTypes                      #
########################################################

SET(DATATYPES_DIRNAME DataTypes)
SET(DATATYPES_DIR ${BASE_DIR}/DataTypes)

# *.h

# DIS 5
SET(KDIS_SRC_DATATYPES_H
    ${DATATYPES_DIR}/AirPlatformAppearance.h
    ${DATATYPES_DIR}/AntennaLocation.h
    ${DATATYPES_DIR}/ArticulatedPart.h
    ${DATATYPES_DIR}/AttachedPart.h
    ${DATATYPES_DIR}/ClockTime.h
    ${DATATYPES_DIR}/CryptoSystem.h
    ${DATATYPES_DIR}/CulturalFeatureAppearance.h
    ${DATATYPES_DIR}/DataTypeBase.h
    ${DATATYPES_DIR}/DeadReckoningParameter.h
    ${DATATYPES_DIR}/Descriptor.h
    ${DATATYPES_DIR}/EmissionSystem.h
    ${DATATYPES_DIR}/EmitterBeam.h
    ${DATATYPES_DIR}/EmitterSystem.h
    ${DATATYPES_DIR}/EncodingScheme.h
    ${DATATYPES_DIR}/EntityAppearance.h
    ${DATATYPES_DIR}/EntityCapabilities.h
    ${DATATYPES_DIR}/EntityIdentifier.h
    ${DATATYPES_DIR}/EntityMarking.h
    ${DATATYPES_DIR}/EntityType.h
    ${DATATYPES_DIR}/EnvironmentalsAppearance.h
    ${DATATYPES_DIR}/EulerAngles.h
    ${DATATYPES_DIR}/FactoryDecoder.h
    ${DATATYPES_DIR}/FixedDatum.h
    ${DATATYPES_DIR}/FundamentalParameterData.h
    ${DATATYPES_DIR}/GuidedMunitionsAppearance.h
    ${DATATYPES_DIR}/LandPlatformAppearance.h
    ${DATATYPES_DIR}/LifeFormAppearance.h
    ${DATATYPES_DIR}/ModulationType.h
    ${DATATYPES_DIR}/MunitionDescriptor.h
    ${DATATYPES_DIR}/RadioEntityType.h
    ${DATATYPES_DIR}/SensorEmitterAppearance.h
    ${DATATYPES_DIR}/SimulationIdentifier.h
    ${DATATYPES_DIR}/SpacePlatformAppearance.h
    ${DATATYPES_DIR}/SubSurfacePlatformAppearance.h
    ${DATATYPES_DIR}/Supplies.h
    ${DATATYPES_DIR}/SurfacePlatformAppearance.h
    ${DATATYPES_DIR}/TimeStamp.h
    ${DATATYPES_DIR}/TrackJamTargetIdentifier.h
    ${DATATYPES_DIR}/VariableDatum.h
    ${DATATYPES_DIR}/VariableParameter.h
    ${DATATYPES_DIR}/Vector.h
    ${DATATYPES_DIR}/WorldCoordinates.h
)

#DIS 6
IF(DIS_VERSION GREATER 5)

    LIST(APPEND KDIS_SRC_DATATYPES_H
    ${DATATYPES_DIR}/AcousticEmitterSystem.h
    ${DATATYPES_DIR}/AggregateIdentifier.h
    ${DATATYPES_DIR}/AggregateMarking.h
    ${DATATYPES_DIR}/AggregateType.h
    ${DATATYPES_DIR}/APA.h
    ${DATATYPES_DIR}/ArealObjectAppearance.h
    ${DATATYPES_DIR}/BeamData.h
    ${DATATYPES_DIR}/BoundingSphereRecord.h
    ${DATATYPES_DIR}/COMBICState.h
    ${DATATYPES_DIR}/CommunicationsChannelType.h
    ${DATATYPES_DIR}/ConeRecord1.h
    ${DATATYPES_DIR}/ConeRecord2.h
    ${DATATYPES_DIR}/EllipsoidRecord1.h
    ${DATATYPES_DIR}/EllipsoidRecord2.h
    ${DATATYPES_DIR}/EntityDestinationRecord.h
    ${DATATYPES_DIR}/EnvironmentRecord.h
    ${DATATYPES_DIR}/EnvironmentType.h
    ${DATATYPES_DIR}/FlareState.h
    ${DATATYPES_DIR}/FundamentalOperationalData.h
    ${DATATYPES_DIR}/FundamentalOperationalData_MarkXInterrogator.h
    ${DATATYPES_DIR}/FundamentalOperationalData_MarkXTransponder.h
    ${DATATYPES_DIR}/FundamentalOperationalData_RRB.h
    ${DATATYPES_DIR}/FundamentalOperationalData_Soviet.h
    ${DATATYPES_DIR}/GaussianPlumeRecord.h
    ${DATATYPES_DIR}/GaussianPuffRecord.h
    ${DATATYPES_DIR}/GED.h
    ${DATATYPES_DIR}/GED_BasicFixedWingAircraft.h
    ${DATATYPES_DIR}/GED_BasicGroundCombatSoldier.h
    ${DATATYPES_DIR}/GED_BasicGroundCombatVehicle.h
    ${DATATYPES_DIR}/GED_BasicRotorWingAircraft.h
    ${DATATYPES_DIR}/GED_EnhancedFixedWingAircraft.h
    ${DATATYPES_DIR}/GED_EnhancedGroundCombatSoldier.h
    ${DATATYPES_DIR}/GED_EnhancedGroundCombatVehicle.h
    ${DATATYPES_DIR}/GED_EnhancedRotaryWingAircraft.h
    ${DATATYPES_DIR}/GED_GroundLogisticsVehicle.h
    ${DATATYPES_DIR}/GridAxisIrregular.h
    ${DATATYPES_DIR}/GridAxisRegular.h
    ${DATATYPES_DIR}/GridData.h
    ${DATATYPES_DIR}/GridDataType0.h
    ${DATATYPES_DIR}/GridDataType1.h
    ${DATATYPES_DIR}/GridDataType2.h
    ${DATATYPES_DIR}/GroupAssignmentRecord.h
    ${DATATYPES_DIR}/GroupDestinationRecord.h
    ${DATATYPES_DIR}/IFF_ATC_NAVAIDS_FundamentalParameterData.h
    ${DATATYPES_DIR}/IFF_Layer2.h
    ${DATATYPES_DIR}/IntercomCommunicationParameters.h
    ${DATATYPES_DIR}/KFIXED.h
    ${DATATYPES_DIR}/LayerHeader.h
    ${DATATYPES_DIR}/LE_DeadReckoningParameter.h
    ${DATATYPES_DIR}/LE_EntityIdentifier.h
    ${DATATYPES_DIR}/LE_EulerAngles.h
    ${DATATYPES_DIR}/LE_Vector.h
    ${DATATYPES_DIR}/LinearObjectAppearance.h
    ${DATATYPES_DIR}/LinearSegmentParameter.h
    ${DATATYPES_DIR}/LineRecord1.h
    ${DATATYPES_DIR}/LineRecord2.h
    ${DATATYPES_DIR}/Mine.h
    ${DATATYPES_DIR}/MinefieldAppearance.h
    ${DATATYPES_DIR}/MinefieldDataFilter.h
    ${DATATYPES_DIR}/MineFusing.h
    ${DATATYPES_DIR}/MinePaintScheme.h
    ${DATATYPES_DIR}/NamedLocationIdentifier.h
    ${DATATYPES_DIR}/ObjectAppearance.h
    ${DATATYPES_DIR}/ObjectType.h
    ${DATATYPES_DIR}/OrientationError.h
    ${DATATYPES_DIR}/PerimeterPointCoordinate.h
    ${DATATYPES_DIR}/PointObjectAppearance.h
    ${DATATYPES_DIR}/PointRecord1.h
    ${DATATYPES_DIR}/PointRecord2.h
    ${DATATYPES_DIR}/PositionError.h
    ${DATATYPES_DIR}/PropulsionSystem.h
    ${DATATYPES_DIR}/RecordSet.h
    ${DATATYPES_DIR}/RectangularVolumeRecord1.h
    ${DATATYPES_DIR}/RectangularVolumeRecord2.h
    ${DATATYPES_DIR}/RectangularVolumeRecord3.h
    ${DATATYPES_DIR}/RelationshipRecord.h
    ${DATATYPES_DIR}/RelativeWorldCoordinates.h
    ${DATATYPES_DIR}/SecondaryOperationalData.h
    ${DATATYPES_DIR}/Shaft.h
    ${DATATYPES_DIR}/SilentAggregateSystem.h
    ${DATATYPES_DIR}/SilentEntitySystem.h
    ${DATATYPES_DIR}/SphereRecord1.h
    ${DATATYPES_DIR}/SphereRecord2.h
    ${DATATYPES_DIR}/SystemIdentifier.h
    ${DATATYPES_DIR}/UnderwaterAcousticEmitterBeam.h
    ${DATATYPES_DIR}/UnderwaterAcousticEmitterSystem.h
    ${DATATYPES_DIR}/UnderwaterAcousticFundamentalParameterData.h
    ${DATATYPES_DIR}/VectoringNozzleSystem.h
    )

ENDIF(DIS_VERSION GREATER 5)

#DIS 7
IF(DIS_VERSION GREATER 6)

LIST(APPEND KDIS_SRC_DATATYPES_H
    ${DATATYPES_DIR}/AttributeRecordSet.h
    ${DATATYPES_DIR}/CommunicationsNodeID.h
    ${DATATYPES_DIR}/DEAreaAimpoint.h
    ${DATATYPES_DIR}/EnhancedMode1Code.h
    ${DATATYPES_DIR}/ExplosionDescriptor.h
    ${DATATYPES_DIR}/IFF_Layer3.h
    ${DATATYPES_DIR}/IFF_Layer3Interrogator.h
    ${DATATYPES_DIR}/IFF_Layer3Transponder.h
    ${DATATYPES_DIR}/IOCommunicationsNode.h
    ${DATATYPES_DIR}/IOEffect.h
    ${DATATYPES_DIR}/Mode5InterrogatorBasicData.h
    ${DATATYPES_DIR}/Mode5InterrogatorStatus.h
    ${DATATYPES_DIR}/Mode5TransponderBasicData.h
    ${DATATYPES_DIR}/Mode5TransponderStatus.h
    ${DATATYPES_DIR}/Mode5TransponderSupplementalData.h
    ${DATATYPES_DIR}/ModeXCodeRecord.h
    ${DATATYPES_DIR}/StandardVariable.h
)

ENDIF(DIS_VERSION GREATER 6)

# *.cpp

#DIS 5
SET(KDIS_SRC_DATATYPES_CPP
    ${DATATYPES_DIR}/AirPlatformAppearance.cpp
    ${DATATYPES_DIR}/AntennaLocation.cpp
    ${DATATYPES_DIR}/ArticulatedPart.cpp
    ${DATATYPES_DIR}/AttachedPart.cpp
    ${DATATYPES_DIR}/ClockTime.cpp
    ${DATATYPES_DIR}/CryptoSystem.cpp
    ${DATATYPES_DIR}/CulturalFeatureAppearance.cpp
    ${DATATYPES_DIR}/DataTypeBase.cpp
    ${DATATYPES_DIR}/DeadReckoningParameter.cpp
    ${DATATYPES_DIR}/Descriptor.cpp
    ${DATATYPES_DIR}/EmissionSystem.cpp
    ${DATATYPES_DIR}/EmitterBeam.cpp
    ${DATATYPES_DIR}/EmitterSystem.cpp
    ${DATATYPES_DIR}/EncodingScheme.cpp
    ${DATATYPES_DIR}/EntityAppearance.cpp
    ${DATATYPES_DIR}/EntityCapabilities.cpp
    ${DATATYPES_DIR}/EntityIdentifier.cpp
    ${DATATYPES_DIR}/EntityMarking.cpp
    ${DATATYPES_DIR}/EntityType.cpp
    ${DATATYPES_DIR}/EnvironmentalsAppearance.cpp
    ${DATATYPES_DIR}/EulerAngles.cpp
    ${DATATYPES_DIR}/FixedDatum.cpp
    ${DATATYPES_DIR}/FundamentalParameterData.cpp
    ${DATATYPES_DIR}/GuidedMunitionsAppearance.cpp
    ${DATATYPES_DIR}/LandPlatformAppearance.cpp
    ${DATATYPES_DIR}/LifeFormAppearance.cpp
    ${DATATYPES_DIR}/ModulationType.cpp
    ${DATATYPES_DIR}/MunitionDescriptor.cpp
    ${DATATYPES_DIR}/RadioEntityType.cpp
    ${DATATYPES_DIR}/SensorEmitterAppearance.cpp
    ${DATATYPES_DIR}/SimulationIdentifier.cpp
    ${DATATYPES_DIR}/SpacePlatformAppearance.cpp
    ${DATATYPES_DIR}/SubSurfacePlatformAppearance.cpp
    ${DATATYPES_DIR}/Supplies.cpp
    ${DATATYPES_DIR}/SurfacePlatformAppearance.cpp
    ${DATATYPES_DIR}/TimeStamp.cpp
    ${DATATYPES_DIR}/TrackJamTargetIdentifier.cpp
    ${DATATYPES_DIR}/VariableDatum.cpp
    ${DATATYPES_DIR}/VariableParameter.cpp
    ${DATATYPES_DIR}/Vector.cpp
    ${DATATYPES_DIR}/WorldCoordinates.cpp
)


#DIS 6
IF(DIS_VERSION GREATER 5)
LIST(APPEND KDIS_SRC_DATATYPES_CPP
    ${DATATYPES_DIR}/AcousticEmitterSystem.cpp
    ${DATATYPES_DIR}/AggregateIdentifier.cpp
    ${DATATYPES_DIR}/AggregateMarking.cpp
    ${DATATYPES_DIR}/AggregateType.cpp
    ${DATATYPES_DIR}/APA.cpp
    ${DATATYPES_DIR}/ArealObjectAppearance.cpp
    ${DATATYPES_DIR}/BeamData.cpp
    ${DATATYPES_DIR}/BoundingSphereRecord.cpp
    ${DATATYPES_DIR}/COMBICState.cpp
    ${DATATYPES_DIR}/CommunicationsChannelType.cpp
    ${DATATYPES_DIR}/ConeRecord1.cpp
    ${DATATYPES_DIR}/ConeRecord2.cpp
    ${DATATYPES_DIR}/EllipsoidRecord1.cpp
    ${DATATYPES_DIR}/EllipsoidRecord2.cpp
    ${DATATYPES_DIR}/EntityDestinationRecord.cpp
    ${DATATYPES_DIR}/EnvironmentRecord.cpp
    ${DATATYPES_DIR}/EnvironmentType.cpp
    ${DATATYPES_DIR}/FlareState.cpp
    ${DATATYPES_DIR}/FundamentalOperationalData.cpp
    ${DATATYPES_DIR}/FundamentalOperationalData_MarkXInterrogator.cpp
    ${DATATYPES_DIR}/FundamentalOperationalData_MarkXTransponder.cpp
    ${DATATYPES_DIR}/FundamentalOperationalData_RRB.cpp
    ${DATATYPES_DIR}/FundamentalOperationalData_Soviet.cpp
    ${DATATYPES_DIR}/GaussianPlumeRecord.cpp
    ${DATATYPES_DIR}/GaussianPuffRecord.cpp
    ${DATATYPES_DIR}/GED_BasicFixedWingAircraft.cpp
    ${DATATYPES_DIR}/GED_BasicGroundCombatSoldier.cpp
    ${DATATYPES_DIR}/GED_BasicGroundCombatVehicle.cpp
    ${DATATYPES_DIR}/GED_BasicRotorWingAircraft.cpp
    ${DATATYPES_DIR}/GED_EnhancedFixedWingAircraft.cpp
    ${DATATYPES_DIR}/GED_EnhancedGroundCombatSoldier.cpp
    ${DATATYPES_DIR}/GED_EnhancedGroundCombatVehicle.cpp
    ${DATATYPES_DIR}/GED_EnhancedRotaryWingAircraft.cpp
    ${DATATYPES_DIR}/GED_GroundLogisticsVehicle.cpp
    ${DATATYPES_DIR}/GridAxisIrregular.cpp
    ${DATATYPES_DIR}/GridAxisRegular.cpp
    ${DATATYPES_DIR}/GridData.cpp
    ${DATATYPES_DIR}/GridDataType0.cpp
    ${DATATYPES_DIR}/GridDataType1.cpp
    ${DATATYPES_DIR}/GridDataType2.cpp
    ${DATATYPES_DIR}/GroupAssignmentRecord.cpp
    ${DATATYPES_DIR}/GroupDestinationRecord.cpp
    ${DATATYPES_DIR}/IFF_ATC_NAVAIDS_FundamentalParameterData.cpp
    ${DATATYPES_DIR}/IFF_Layer2.cpp
    ${DATATYPES_DIR}/IntercomCommunicationParameters.cpp
    ${DATATYPES_DIR}/KFIXED.cpp
    ${DATATYPES_DIR}/LayerHeader.cpp
    ${DATATYPES_DIR}/LE_DeadReckoningParameter.cpp
    ${DATATYPES_DIR}/LE_EntityIdentifier.cpp
    ${DATATYPES_DIR}/LE_EulerAngles.cpp
    ${DATATYPES_DIR}/LE_Vector.cpp
    ${DATATYPES_DIR}/LinearObjectAppearance.cpp
    ${DATATYPES_DIR}/LinearSegmentParameter.cpp
    ${DATATYPES_DIR}/LineRecord1.cpp
    ${DATATYPES_DIR}/LineRecord2.cpp
    ${DATATYPES_DIR}/Mine.cpp
    ${DATATYPES_DIR}/MinefieldAppearance.cpp
    ${DATATYPES_DIR}/MinefieldDataFilter.cpp
    ${DATATYPES_DIR}/MineFusing.cpp
    ${DATATYPES_DIR}/MinePaintScheme.cpp
    ${DATATYPES_DIR}/NamedLocationIdentifier.cpp
    ${DATATYPES_DIR}/ObjectAppearance.cpp
    ${DATATYPES_DIR}/ObjectType.cpp
    ${DATATYPES_DIR}/OrientationError.cpp
    ${DATATYPES_DIR}/PerimeterPointCoordinate.cpp
    ${DATATYPES_DIR}/PointObjectAppearance.cpp
    ${DATATYPES_DIR}/PointRecord1.cpp
    ${DATATYPES_DIR}/PointRecord2.cpp
    ${DATATYPES_DIR}/PositionError.cpp
    ${DATATYPES_DIR}/PropulsionSystem.cpp
    ${DATATYPES_DIR}/RecordSet.cpp
    ${DATATYPES_DIR}/RectangularVolumeRecord1.cpp
    ${DATATYPES_DIR}/RectangularVolumeRecord2.cpp
    ${DATATYPES_DIR}/RectangularVolumeRecord3.cpp
    ${DATATYPES_DIR}/RelationshipRecord.cpp
    ${DATATYPES_DIR}/RelativeWorldCoordinates.cpp
    ${DATATYPES_DIR}/SecondaryOperationalData.cpp
    ${DATATYPES_DIR}/Shaft.cpp
    ${DATATYPES_DIR}/SilentAggregateSystem.cpp
    ${DATATYPES_DIR}/SilentEntitySystem.cpp
    ${DATATYPES_DIR}/SphereRecord1.cpp
    ${DATATYPES_DIR}/SphereRecord2.cpp
    ${DATATYPES_DIR}/SystemIdentifier.cpp
    ${DATATYPES_DIR}/UnderwaterAcousticEmitterBeam.cpp
    ${DATATYPES_DIR}/UnderwaterAcousticEmitterSystem.cpp
    ${DATATYPES_DIR}/UnderwaterAcousticFundamentalParameterData.cpp
    ${DATATYPES_DIR}/VectoringNozzleSystem.cpp
   )

ENDIF(DIS_VERSION GREATER 5)

#DIS 7
IF(DIS_VERSION GREATER 6)

LIST(APPEND KDIS_SRC_DATATYPES_CPP
    ${DATATYPES_DIR}/AttributeRecordSet.cpp
    ${DATATYPES_DIR}/CommunicationsNodeID.cpp
    ${DATATYPES_DIR}/DEAreaAimpoint.cpp
    ${DATATYPES_DIR}/EnhancedMode1Code.cpp
    ${DATATYPES_DIR}/ExplosionDescriptor.cpp
    ${DATATYPES_DIR}/IFF_Layer3.cpp
    ${DATATYPES_DIR}/IFF_Layer3Interrogator.cpp
    ${DATATYPES_DIR}/IFF_Layer3Transponder.cpp
    ${DATATYPES_DIR}/IOCommunicationsNode.cpp
    ${DATATYPES_DIR}/IOEffect.cpp
    ${DATATYPES_DIR}/Mode5InterrogatorBasicData.cpp
    ${DATATYPES_DIR}/Mode5InterrogatorStatus.cpp
    ${DATATYPES_DIR}/Mode5TransponderBasicData.cpp
    ${DATATYPES_DIR}/Mode5TransponderStatus.cpp
    ${DATATYPES_DIR}/Mode5TransponderSupplementalData.cpp
    ${DATATYPES_DIR}/ModeXCodeRecord.cpp
    ${DATATYPES_DIR}/StandardVariable.cpp
)

ENDIF(DIS_VERSION GREATER 6)


########################################################
#                         Enums                        #
########################################################

# *.h

#DIS 5-6
SET(ENUMS_DIRNAME /DataTypes/Enums)
SET(ENUMS_DIR ${BASE_DIR}/DataTypes/Enums)

SET(KDIS_SRC_ENUMS_H
    ${ENUMS_DIR}/EnumBurstDescriptor.h
    ${ENUMS_DIR}/EnumDescriptor.h
    ${ENUMS_DIR}/EnumDesignator.h
    ${ENUMS_DIR}/EnumDetonationResult.h
    ${ENUMS_DIR}/EnumEmitter.h
    ${ENUMS_DIR}/EnumEntityInfoInteraction.h
    ${ENUMS_DIR}/EnumEntityManagement.h
    ${ENUMS_DIR}/EnumHeader.h
    ${ENUMS_DIR}/EnumIFF.h
    ${ENUMS_DIR}/EnumMinefield.h
    ${ENUMS_DIR}/EnumRadio.h
    ${ENUMS_DIR}/EnumSimulationManagement.h
    ${ENUMS_DIR}/EnumSupply.h
    ${ENUMS_DIR}/EnumSyntheticEnvironment.h
    ${ENUMS_DIR}/EnumSystemIdentifier.h
    ${ENUMS_DIR}/KDISEnums.h
)

#DIS 7
IF(DIS_VERSION GREATER 6)

LIST(APPEND KDIS_SRC_ENUMS_H
    ${ENUMS_DIR}/EnumInformationOperations.h
)

ENDIF(DIS_VERSION GREATER 6)

#DIS 5-6
SET(KDIS_SRC_ENUMS_CPP
    ${ENUMS_DIR}/EnumBurstDescriptor.cpp
    ${ENUMS_DIR}/EnumDescriptor.cpp
    ${ENUMS_DIR}/EnumDesignator.cpp
    ${ENUMS_DIR}/EnumDetonationResult.cpp
    ${ENUMS_DIR}/EnumEmitter.cpp
    ${ENUMS_DIR}/EnumEntityInfoInteraction.cpp
    ${ENUMS_DIR}/EnumEntityManagement.cpp
    ${ENUMS_DIR}/EnumHeader.cpp
    ${ENUMS_DIR}/EnumIFF.cpp
    ${ENUMS_DIR}/EnumMinefield.cpp
    ${ENUMS_DIR}/EnumRadio.cpp
    ${ENUMS_DIR}/EnumSimulationManagement.cpp
    ${ENUMS_DIR}/EnumSupply.cpp
    ${ENUMS_DIR}/EnumSyntheticEnvironment.cpp
    ${ENUMS_DIR}/EnumSystemIdentifier.cpp
)

#DIS 7
IF(DIS_VERSION GREATER 6)

LIST(APPEND KDIS_SRC_ENUMS_CPP
    ${ENUMS_DIR}/EnumInformationOperations.cpp
)

ENDIF(DIS_VERSION GREATER 6)

########################################################
#                         PDU                          #
########################################################

# *.h

#Base----------------------------------------------------#

SET(PDU_BASE_DIRNAME PDU)
SET(PDU_BASE_DIR ${BASE_DIR}/PDU)

SET(KDIS_SRC_PDU_BASE_H ${PDU_BASE_DIR}/Header.h
                        ${PDU_BASE_DIR}/Header6.h
                        ${PDU_BASE_DIR}/Bundle.h
)

SET(KDIS_SRC_PDU_BASE_CPP ${PDU_BASE_DIR}/Header6.cpp
                          ${PDU_BASE_DIR}/Bundle.cpp
)

# DIS 7
IF(DIS_VERSION GREATER 6)

    LIST(APPEND KDIS_SRC_PDU_BASE_H ${PDU_BASE_DIR}/Header7.h)

    LIST(APPEND KDIS_SRC_PDU_BASE_CPP ${PDU_BASE_DIR}/Header7.cpp)

ENDIF(DIS_VERSION GREATER 6)

#Distributed_Emission_Regeneration------------------------#

SET(PDU_DER_DIRNAME PDU/Distributed_Emission_Regeneration)
SET(PDU_DER_DIR ${BASE_DIR}/PDU/Distributed_Emission_Regeneration)

#DIS 5
SET(KDIS_SRC_PDU_DER_H
    ${PDU_DER_DIR}/Designator_PDU.h
    ${PDU_DER_DIR}/Electromagnetic_Emission_PDU.h
)

#DIS 6
IF(DIS_VERSION GREATER 5)

    LIST(APPEND KDIS_SRC_PDU_DER_H
        ${PDU_DER_DIR}/IFF_PDU.h
        ${PDU_DER_DIR}/SEES_PDU.h
        ${PDU_DER_DIR}/Underwater_Acoustic_PDU.h
    )

ENDIF(DIS_VERSION GREATER 5)

#DIS 5
SET(KDIS_SRC_PDU_DER_CPP
    ${PDU_DER_DIR}/Designator_PDU.cpp
    ${PDU_DER_DIR}/Electromagnetic_Emission_PDU.cpp
)

# DIS 6
IF(DIS_VERSION GREATER 5)

    LIST(APPEND KDIS_SRC_PDU_DER_CPP
        ${PDU_DER_DIR}/IFF_PDU.cpp
        ${PDU_DER_DIR}/SEES_PDU.cpp
        ${PDU_DER_DIR}/Underwater_Acoustic_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 5)

#Entity_Info_Interaction---------------------------------#

SET(PDU_EII_DIRNAME PDU/Entity_Info_Interaction)
SET(PDU_EII_DIR ${BASE_DIR}/PDU/Entity_Info_Interaction)

#DIS 5
SET(KDIS_SRC_PDU_EII_H
    ${PDU_EII_DIR}/Collision_PDU.h
    ${PDU_EII_DIR}/Entity_State_PDU.h
)

#DIS 6
IF(DIS_VERSION GREATER 5)

    LIST(APPEND KDIS_SRC_PDU_EII_H
        ${PDU_EII_DIR}/Collision_Elastic_PDU.h
        ${PDU_EII_DIR}/Entity_State_Update_PDU.h
    )

ENDIF(DIS_VERSION GREATER 5)

#DIS 7
IF(DIS_VERSION GREATER 6)

    LIST(APPEND KDIS_SRC_PDU_EII_H
        ${PDU_EII_DIR}/Attribute_PDU.h
    )

ENDIF(DIS_VERSION GREATER 6)

# DIS 5
SET(KDIS_SRC_PDU_EII_CPP
    ${PDU_EII_DIR}/Collision_PDU.cpp
    ${PDU_EII_DIR}/Entity_State_PDU.cpp
)

#DIS 6
IF(DIS_VERSION GREATER 5)

    LIST(APPEND KDIS_SRC_PDU_EII_CPP
        ${PDU_EII_DIR}/Collision_Elastic_PDU.cpp
        ${PDU_EII_DIR}/Entity_State_Update_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 5)

#DIS 7
IF(DIS_VERSION GREATER 6)

    LIST(APPEND KDIS_SRC_PDU_EII_CPP
        ${PDU_EII_DIR}/Attribute_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 6)

#Entity_Management---------------------------------------#

SET(PDU_EM_DIRNAME PDU/Entity_Management)
#DIS 6 - All
SET(PDU_EM_DIR ${BASE_DIR}/PDU/Entity_Management)

IF(DIS_VERSION GREATER 5)

    SET(KDIS_SRC_PDU_EM_H
    ${PDU_EM_DIR}/Aggregate_State_PDU.h
    ${PDU_EM_DIR}/IsGroupOf_PDU.h
    ${PDU_EM_DIR}/IsPartOf_PDU.h
    ${PDU_EM_DIR}/Transfer_Control_Request_PDU.h
    )

    SET(KDIS_SRC_PDU_EM_CPP
    ${PDU_EM_DIR}/Aggregate_State_PDU.cpp
    ${PDU_EM_DIR}/IsGroupOf_PDU.cpp
    ${PDU_EM_DIR}/IsPartOf_PDU.cpp
    ${PDU_EM_DIR}/Transfer_Control_Request_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 5)

#LE------------------------------------------------------#

SET(PDU_LE_DIRNAME PDU/Live_Entity)
#DIS 6 - All
SET(PDU_LE_DIR ${BASE_DIR}/PDU/Live_Entity)

IF(DIS_VERSION GREATER 5)

    SET(KDIS_SRC_PDU_LE_H
    ${PDU_LE_DIR}/Appearance_PDU.h
    ${PDU_LE_DIR}/Articulated_Parts_PDU.h
    ${PDU_LE_DIR}/LE_Detonation_PDU.h
    ${PDU_LE_DIR}/LE_Fire_PDU.h
    ${PDU_LE_DIR}/LE_Header.h
    ${PDU_LE_DIR}/TSPI_PDU.h
    )

    SET(KDIS_SRC_PDU_LE_CPP
    ${PDU_LE_DIR}/Appearance_PDU.cpp
    ${PDU_LE_DIR}/Articulated_Parts_PDU.cpp
    ${PDU_LE_DIR}/LE_Detonation_PDU.cpp
    ${PDU_LE_DIR}/LE_Fire_PDU.cpp
    ${PDU_LE_DIR}/LE_Header.cpp
    ${PDU_LE_DIR}/TSPI_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 5)

#Logistics-----------------------------------------------#

SET(PDU_L_DIRNAME PDU/Logistics)
SET(PDU_L_DIR ${BASE_DIR}/PDU/Logistics)

#DIS 5
SET(KDIS_SRC_PDU_L_H
    ${PDU_L_DIR}/Logistics_Header.h
    ${PDU_L_DIR}/Repair_Complete_PDU.h
    ${PDU_L_DIR}/Repair_Response_PDU.h
    ${PDU_L_DIR}/Resupply_Cancel_PDU.h
    ${PDU_L_DIR}/Resupply_Offer_PDU.h
    ${PDU_L_DIR}/Resupply_Received_PDU.h
    ${PDU_L_DIR}/Service_Request_PDU.h
)

#DIS 5
SET(KDIS_SRC_PDU_L_CPP
    ${PDU_L_DIR}/Logistics_Header.cpp
    ${PDU_L_DIR}/Repair_Complete_PDU.cpp
    ${PDU_L_DIR}/Repair_Response_PDU.cpp
    ${PDU_L_DIR}/Resupply_Cancel_PDU.cpp
    ${PDU_L_DIR}/Resupply_Offer_PDU.cpp
    ${PDU_L_DIR}/Resupply_Received_PDU.cpp
    ${PDU_L_DIR}/Service_Request_PDU.cpp
)

#Minefield-----------------------------------------------#

SET(PDU_M_DIRNAME PDU/Minefield)
#DIS 6 - All
SET(PDU_M_DIR ${BASE_DIR}/PDU/Minefield)

IF(DIS_VERSION GREATER 5)

    SET(KDIS_SRC_PDU_M_H
        ${PDU_M_DIR}/Minefield_Data_PDU.h
        ${PDU_M_DIR}/Minefield_Header.h
        ${PDU_M_DIR}/Minefield_Query_PDU.h
        ${PDU_M_DIR}/Minefield_Response_NACK_PDU.h
        ${PDU_M_DIR}/Minefield_State_PDU.h
    )

    SET(KDIS_SRC_PDU_M_CPP
        ${PDU_M_DIR}/Minefield_Data_PDU.cpp
        ${PDU_M_DIR}/Minefield_Header.cpp
        ${PDU_M_DIR}/Minefield_Query_PDU.cpp
        ${PDU_M_DIR}/Minefield_Response_NACK_PDU.cpp
        ${PDU_M_DIR}/Minefield_State_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 5)

#Radio_Communications------------------------------------#

SET(PDU_R_DIRNAME PDU/Radio_Communications)
SET(PDU_R_DIR ${BASE_DIR}/PDU/Radio_Communications)

#DIS 5
SET(KDIS_SRC_PDU_R_H
    ${PDU_R_DIR}/Radio_Communications_Header.h
    ${PDU_R_DIR}/Receiver_PDU.h
    ${PDU_R_DIR}/Signal_PDU.h
    ${PDU_R_DIR}/Transmitter_PDU.h
)

#DIS 6

IF(DIS_VERSION GREATER 5)

    LIST(APPEND KDIS_SRC_PDU_R_H
        ${PDU_R_DIR}/Intercom_Control_PDU.h
        ${PDU_R_DIR}/Intercom_Signal_PDU.h
    )

ENDIF(DIS_VERSION GREATER 5)

#DIS 5
SET(KDIS_SRC_PDU_R_CPP
    ${PDU_R_DIR}/Radio_Communications_Header.cpp
    ${PDU_R_DIR}/Receiver_PDU.cpp
    ${PDU_R_DIR}/Signal_PDU.cpp
    ${PDU_R_DIR}/Transmitter_PDU.cpp
)

#DIS 6

IF(DIS_VERSION GREATER 5)

    LIST(APPEND KDIS_SRC_PDU_R_CPP
        ${PDU_R_DIR}/Intercom_Control_PDU.cpp
        ${PDU_R_DIR}/Intercom_Signal_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 5)

#Simulation_Management-----------------------------------#

SET(PDU_SM_DIRNAME PDU/Simulation_Management)
SET(PDU_SM_DIR ${BASE_DIR}/PDU/Simulation_Management)

#DIS 5
SET(KDIS_SRC_PDU_SM_H
    ${PDU_SM_DIR}/Acknowledge_PDU.h
    ${PDU_SM_DIR}/Action_Request_PDU.h
    ${PDU_SM_DIR}/Action_Response_PDU.h
    ${PDU_SM_DIR}/Comment_PDU.h
    ${PDU_SM_DIR}/Create_Entity_PDU.h
    ${PDU_SM_DIR}/Data_PDU.h
    ${PDU_SM_DIR}/Data_Query_PDU.h
    ${PDU_SM_DIR}/Event_Report_PDU.h
    ${PDU_SM_DIR}/Remove_Entity_PDU.h
    ${PDU_SM_DIR}/Set_Data_PDU.h
    ${PDU_SM_DIR}/Simulation_Management_Header.h
    ${PDU_SM_DIR}/Start_Resume_PDU.h
    ${PDU_SM_DIR}/Stop_Freeze_PDU.h
)

#DIS 5
SET(KDIS_SRC_PDU_SM_CPP
    ${PDU_SM_DIR}/Acknowledge_PDU.cpp
    ${PDU_SM_DIR}/Action_Request_PDU.cpp
    ${PDU_SM_DIR}/Action_Response_PDU.cpp
    ${PDU_SM_DIR}/Comment_PDU.cpp
    ${PDU_SM_DIR}/Create_Entity_PDU.cpp
    ${PDU_SM_DIR}/Data_PDU.cpp
    ${PDU_SM_DIR}/Data_Query_PDU.cpp
    ${PDU_SM_DIR}/Event_Report_PDU.cpp
    ${PDU_SM_DIR}/Remove_Entity_PDU.cpp
    ${PDU_SM_DIR}/Set_Data_PDU.cpp
    ${PDU_SM_DIR}/Simulation_Management_Header.cpp
    ${PDU_SM_DIR}/Start_Resume_PDU.cpp
    ${PDU_SM_DIR}/Stop_Freeze_PDU.cpp
)

#Simulation_Management_With_Reliability------------------#

SET(PDU_SMWR_DIRNAME PDU/Simulation_Management_With_Reliability)
#DIS 6 - ALL
SET(PDU_SMWR_DIR ${BASE_DIR}/PDU/Simulation_Management_With_Reliability)

IF(DIS_VERSION GREATER 5)

    SET(KDIS_SRC_PDU_SMWR_H
        ${PDU_SMWR_DIR}/Acknowledge_R_PDU.h
        ${PDU_SMWR_DIR}/Action_Request_R_PDU.h
        ${PDU_SMWR_DIR}/Action_Response_R_PDU.h
        ${PDU_SMWR_DIR}/Comment_R_PDU.h
        ${PDU_SMWR_DIR}/Create_Entity_R_PDU.h
        ${PDU_SMWR_DIR}/Data_Query_R_PDU.h
        ${PDU_SMWR_DIR}/Data_R_PDU.h
        ${PDU_SMWR_DIR}/Event_Report_R_PDU.h
        ${PDU_SMWR_DIR}/Record_Query_R_PDU.h
        ${PDU_SMWR_DIR}/Record_R_PDU.h
        ${PDU_SMWR_DIR}/Reliability_Header.h
        ${PDU_SMWR_DIR}/Remove_Entity_R_PDU.h
        ${PDU_SMWR_DIR}/Set_Data_R_PDU.h
        ${PDU_SMWR_DIR}/Set_Record_R_PDU.h
        ${PDU_SMWR_DIR}/Start_Resume_R_PDU.h
        ${PDU_SMWR_DIR}/Stop_Freeze_R_PDU.h
    )

    SET(KDIS_SRC_PDU_SMWR_CPP
       ${PDU_SMWR_DIR}/Acknowledge_R_PDU.cpp
       ${PDU_SMWR_DIR}/Action_Request_R_PDU.cpp
       ${PDU_SMWR_DIR}/Action_Response_R_PDU.cpp
       ${PDU_SMWR_DIR}/Comment_R_PDU.cpp
       ${PDU_SMWR_DIR}/Create_Entity_R_PDU.cpp
       ${PDU_SMWR_DIR}/Data_Query_R_PDU.cpp
       ${PDU_SMWR_DIR}/Data_R_PDU.cpp
       ${PDU_SMWR_DIR}/Event_Report_R_PDU.cpp
       ${PDU_SMWR_DIR}/Record_Query_R_PDU.cpp
       ${PDU_SMWR_DIR}/Record_R_PDU.cpp
       ${PDU_SMWR_DIR}/Reliability_Header.cpp
       ${PDU_SMWR_DIR}/Remove_Entity_R_PDU.cpp
       ${PDU_SMWR_DIR}/Set_Data_R_PDU.cpp
       ${PDU_SMWR_DIR}/Set_Record_R_PDU.cpp
       ${PDU_SMWR_DIR}/Start_Resume_R_PDU.cpp
       ${PDU_SMWR_DIR}/Stop_Freeze_R_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 5)

#Synthetic_Environment------------------------------------#

SET(PDU_SE_DIRNAME PDU/Synthetic_Environment)
#DIS 6 - ALL
SET(PDU_SE_DIR ${BASE_DIR}/PDU/Synthetic_Environment)

IF(DIS_VERSION GREATER 5)

    SET(KDIS_SRC_PDU_SE_H
     ${PDU_SE_DIR}/Areal_Object_State_PDU.h
     ${PDU_SE_DIR}/Environmental_Process_PDU.h
     ${PDU_SE_DIR}/Gridded_Data_PDU.h
     ${PDU_SE_DIR}/Linear_Object_State_PDU.h
     ${PDU_SE_DIR}/Object_State_Header.h
     ${PDU_SE_DIR}/Point_Object_State_PDU.h
    )

    SET(KDIS_SRC_PDU_SE_CPP
     ${PDU_SE_DIR}/Areal_Object_State_PDU.cpp
     ${PDU_SE_DIR}/Environmental_Process_PDU.cpp
     ${PDU_SE_DIR}/Gridded_Data_PDU.cpp
     ${PDU_SE_DIR}/Linear_Object_State_PDU.cpp
     ${PDU_SE_DIR}/Object_State_Header.cpp
     ${PDU_SE_DIR}/Point_Object_State_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 5)

#Warfare-------------------------------------------------#

SET(PDU_W_DIRNAME PDU/Warfare)
SET(PDU_W_DIR ${BASE_DIR}/PDU/Warfare)

#DIS 5
SET(KDIS_SRC_PDU_W_H
    ${PDU_W_DIR}/Detonation_PDU.h
    ${PDU_W_DIR}/Fire_PDU.h
    ${PDU_W_DIR}/Warfare_Header.h
)

#DIS 7
IF(DIS_VERSION GREATER 6)

    LIST(APPEND KDIS_SRC_PDU_W_H
        ${PDU_W_DIR}/Directed_Energy_Fire_PDU.h
        ${PDU_W_DIR}/Entity_Damage_Status_PDU.h
    )

ENDIF(DIS_VERSION GREATER 6)

#DIS 5
SET(KDIS_SRC_PDU_W_CPP
    ${PDU_W_DIR}/Detonation_PDU.cpp
    ${PDU_W_DIR}/Fire_PDU.cpp
    ${PDU_W_DIR}/Warfare_Header.cpp
)

#DIS 7
IF(DIS_VERSION GREATER 6)

    LIST(APPEND KDIS_SRC_PDU_W_CPP
        ${PDU_W_DIR}/Directed_Energy_Fire_PDU.cpp
        ${PDU_W_DIR}/Entity_Damage_Status_PDU.cpp
    )

ENDIF(DIS_VERSION GREATER 6)

#Information_Operations----------------------------------#

SET(PDU_IO_DIRNAME PDU/Information_Operations)
SET(PDU_IO_DIR ${BASE_DIR}/PDU/Information_Operations)

IF(DIS_VERSION GREATER 6)

#DIS 7
SET(KDIS_SRC_PDU_IO_H
    ${PDU_IO_DIR}/IO_Header.h
    ${PDU_IO_DIR}/IO_Action_PDU.h
    ${PDU_IO_DIR}/IO_Report_PDU.h
)

#DIS 7
SET(KDIS_SRC_PDU_IO_CPP
    ${PDU_IO_DIR}/IO_Header.cpp
    ${PDU_IO_DIR}/IO_Action_PDU.cpp
    ${PDU_IO_DIR}/IO_Report_PDU.cpp
)

ENDIF(DIS_VERSION GREATER 6)

########################################################
#                         Extras                       #
########################################################

SET(EX_DIRNAME Extras)
SET(EX_DIR ${BASE_DIR}/Extras)

SET(KDIS_SRC_EX_H
    ${EX_DIR}/DeadReckoningCalculator.h
    ${EX_DIR}/DIS_Logger_Playback.h
    ${EX_DIR}/DIS_Logger_Record.h
    ${EX_DIR}/KConversions.h
    ${EX_DIR}/KRef_Ptr.h
    ${EX_DIR}/KUtils.h
    ${EX_DIR}/Math.h
    ${EX_DIR}/PDU_Factory.h
    ${EX_DIR}/PDU_Factory_Filters.h
)

SET(KDIS_SRC_EX_CPP
    ${EX_DIR}/DeadReckoningCalculator.cpp
    ${EX_DIR}/DIS_Logger_Playback.cpp
    ${EX_DIR}/DIS_Logger_Record.cpp
    ${EX_DIR}/PDU_Factory.cpp
)

########################################################
#                         Network                      #
########################################################

SET(NET_DIRNAME Network)
SET(NET_DIR ${BASE_DIR}/Network)

SET(KDIS_SRC_NET_H
    ${NET_DIR}/Connection.h
    ${NET_DIR}/ConnectionAddressFilter.h
    ${NET_DIR}/ConnectionSubscriber.h
)

SET(KDIS_SRC_NET_CPP
    ${NET_DIR}/Connection.cpp
    ${NET_DIR}/ConnectionAddressFilter.cpp
)

ADD_SUBDIRECTORY(Examples)

IF(BUILD_TESTS)
    ADD_SUBDIRECTORY(Tests)
ENDIF(BUILD_TESTS)

INSTALL(TARGETS ${KDIS_DLL} LIBRARY DESTINATION lib)

INSTALL(FILES ${KDIS_SRC_BASE_H}       DESTINATION  include/${BASE_DIRNAME})
INSTALL(FILES ${KDIS_SRC_DATATYPES_H}  DESTINATION  include/${BASE_DIRNAME}/${DATATYPES_DIRNAME})
INSTALL(FILES ${KDIS_SRC_ENUMS_H}      DESTINATION  include/${BASE_DIRNAME}/${ENUMS_DIRNAME})
INSTALL(FILES ${KDIS_SRC_EX_H}         DESTINATION  include/${BASE_DIRNAME}/${EX_DIRNAME})
INSTALL(FILES ${KDIS_SRC_NET_H}        DESTINATION  include/${BASE_DIRNAME}/${NET_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_BASE_H}   DESTINATION  include/${BASE_DIRNAME}/${PDU_BASE_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_DER_H}    DESTINATION  include/${BASE_DIRNAME}/${PDU_DER_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_EII_H}    DESTINATION  include/${BASE_DIRNAME}/${PDU_EII_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_EM_H}     DESTINATION  include/${BASE_DIRNAME}/${PDU_EM_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_IO_H}     DESTINATION  include/${BASE_DIRNAME}/${PDU_IO_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_L_H}      DESTINATION  include/${BASE_DIRNAME}/${PDU_L_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_LE_H}     DESTINATION  include/${BASE_DIRNAME}/${PDU_LE_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_M_H}      DESTINATION  include/${BASE_DIRNAME}/${PDU_M_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_R_H}      DESTINATION  include/${BASE_DIRNAME}/${PDU_R_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_SE_H}     DESTINATION  include/${BASE_DIRNAME}/${PDU_SE_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_SM_H}     DESTINATION  include/${BASE_DIRNAME}/${PDU_SM_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_SMWR_H}   DESTINATION  include/${BASE_DIRNAME}/${PDU_SMWR_DIRNAME})
INSTALL(FILES ${KDIS_SRC_PDU_W_H}      DESTINATION  include/${BASE_DIRNAME}/${PDU_W_DIRNAME})

