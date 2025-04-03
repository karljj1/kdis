cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

#
# Project
#
project(
  KDIS
  VERSION 3.0.0
  LANGUAGES CXX
  HOMEPAGE_URL https://github.com/karljj1/kdis
  DESCRIPTION "Open source implementation of DIS (Distributed Interactive Simulation) IEEE 1278.1"
)

#
# Settings
#
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT DEFINED CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
# Define PROJECT_IS_TOP_LEVEL if not available
if(CMAKE_VERSION VERSION_LESS "3.21")
  string(COMPARE EQUAL "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}" PROJECT_IS_TOP_LEVEL)
endif()

#
# Options
#
include(CMakeDependentOption)
# cmake-lint: disable=C0301
set(DIS_VERSION
    7
    CACHE
      STRING
      "DIS version. Possible values are '5' (IEEE 1278.1-1995), '6' (IEEE 1278.1A-1998), or '7' (IEEE 1278.1x-2012)"
)
# cmake-lint: disable=C0301
option(
  KDIS_USE_ENUM_DESCRIPTORS
  "Enumeration descriptors. Allow enum values to be turned into their text labels. This increase the memory footprint of the library"
  ON
)
option(KDIS_BUILD_INSTALL "Build install" ${PROJECT_IS_TOP_LEVEL})
option(KDIS_BUILD_DOCS "Build documentation" ${PROJECT_IS_TOP_LEVEL})
option(KDIS_BUILD_EXAMPLES "Build examples" ${PROJECT_IS_TOP_LEVEL})
option(KDIS_BUILD_TESTS "Build tests" ${PROJECT_IS_TOP_LEVEL})
cmake_dependent_option(
  KDIS_BUILD_TESTS_COVERAGE "Build tests coverage" ${PROJECT_IS_TOP_LEVEL} "KDIS_BUILD_TESTS" OFF
)
option(BUILD_SHARED_LIBS "Build shared library" ON)

#
# Checks
#
if(NOT DIS_VERSION EQUAL 5
   AND NOT DIS_VERSION EQUAL 6
   AND NOT DIS_VERSION EQUAL 7
)
  message(FATAL_ERROR "Invalid DIS version '${DIS_VERSION}'")
endif()
if(KDIS_BUILD_TESTS_COVERAGE)
  # Compiler (GNU, Clang and Flang)
  get_property(LANGUAGES GLOBAL PROPERTY ENABLED_LANGUAGES)
  foreach(lang ${LANGUAGES})
    # FIXME See https://github.com/bilke/cmake-modules/issues/84
    if(NOT "${CMAKE_${lang}_COMPILER_ID}" MATCHES "GNU")
      message(
        WARNING
          "Tests coverage disabled because compiler '${CMAKE_${lang}_COMPILER_ID}' does not support it"
      )
      set(KDIS_BUILD_TESTS_COVERAGE
          OFF
          CACHE BOOL "Build tests coverage" FORCE
      )
      break()
    endif()
  endforeach()
endif()

#
# Includes
#
include(GenerateExportHeader)
if(KDIS_BUILD_INSTALL)
  include(GNUInstallDirs)
  include(CMakePackageConfigHelpers)
endif()
if(KDIS_BUILD_TESTS)
  include(CPM)
  if(KDIS_BUILD_TESTS_COVERAGE)
    enable_language(C)
    include(CodeCoverage)
  endif()
endif()

#
# Dependencies
#
if(KDIS_BUILD_DOCS)
  # Doxygen
  find_package(Doxygen REQUIRED)
endif()
if(KDIS_BUILD_TESTS)
  # GoogleTest
  CPMAddPackage(
    NAME GoogleTest
    GITHUB_REPOSITORY google/googletest
    GIT_TAG v1.12.0
    EXCLUDE_FROM_ALL ON
    SYSTEM ON
    OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt ON"
  )
endif()

#
# Headers & Sources
#
set(KDIS_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})
set(KDIS_HEADERS_DIR_BINARY ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME})
set(KDIS_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(KDIS_HEADERS ${KDIS_HEADERS_DIR}/KDataStream.hpp ${KDIS_HEADERS_DIR}/KDefines.hpp
                 ${KDIS_HEADERS_DIR}/KEncodersDecoders.hpp ${KDIS_HEADERS_DIR}/KSymbolicNames.hpp
)
set(KDIS_SOURCES ${KDIS_SOURCES_DIR}/KDataStream.cpp)

# Utils
set(KDIS_UTILS_HEADERS_DIR ${KDIS_HEADERS_DIR}/utils)
set(KDIS_UTILS_SOURCES_DIR ${KDIS_SOURCES_DIR}/utils)

list(APPEND KDIS_HEADERS ${KDIS_UTILS_HEADERS_DIR}/BoundedLengthString.hpp
                         ${KDIS_UTILS_HEADERS_DIR}/Endian.hpp
                         ${KDIS_UTILS_HEADERS_DIR}/format.hpp
                         ${KDIS_UTILS_HEADERS_DIR}/NumberConversions.hpp)
list(APPEND KDIS_SOURCES ${KDIS_UTILS_SOURCES_DIR}/Endian.cpp
                         ${KDIS_UTILS_SOURCES_DIR}/NumberConversions.cpp)

# DataTypes
set(KDIS_DATATYPES_HEADERS_DIR ${KDIS_HEADERS_DIR}/DataTypes)
set(KDIS_DATATYPES_SOURCES_DIR ${KDIS_SOURCES_DIR}/DataTypes)

# DataTypes DIS 5
list(
  APPEND
  KDIS_HEADERS
  ${KDIS_DATATYPES_HEADERS_DIR}/AirPlatformAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/AntennaLocation.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/ArticulatedPart.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/AttachedPart.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/ClockTime.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/CryptoSystem.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/CulturalFeatureAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/DataTypeBase.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/DeadReckoningParameter.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/Descriptor.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EmissionSystem.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EmitterBeam.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EmitterSystem.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EncodingScheme.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EntityAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EntityCapabilities.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EntityIdentifier.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EntityMarking.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EntityType.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EnvironmentalsAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/EulerAngles.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/FactoryDecoder.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/FixedDatum.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/FundamentalParameterData.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/GuidedMunitionsAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/LandPlatformAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/LifeFormAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/ModulationType.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/MunitionDescriptor.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/NonHumanLifeFormAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/RadioAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/RadioEntityType.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/SensorEmitterAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/SimulationIdentifier.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/SpacePlatformAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/SubSurfacePlatformAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/Supplies.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/SurfacePlatformAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/TimeStamp.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/TrackJamTargetIdentifier.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/VariableDatum.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/VariableParameter.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/Vector.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/WorldCoordinates.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/SupplyAppearance.hpp
  ${KDIS_DATATYPES_HEADERS_DIR}/ExpendableAppearance.hpp
)
list(
  APPEND
  KDIS_SOURCES
  ${KDIS_DATATYPES_SOURCES_DIR}/AirPlatformAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/AntennaLocation.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/ArticulatedPart.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/AttachedPart.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/ClockTime.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/CryptoSystem.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/CulturalFeatureAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/DataTypeBase.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/DeadReckoningParameter.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/Descriptor.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EmissionSystem.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EmitterBeam.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EmitterSystem.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EncodingScheme.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EntityAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EntityCapabilities.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EntityIdentifier.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EntityMarking.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EntityType.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EnvironmentalsAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/EulerAngles.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/FixedDatum.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/FundamentalParameterData.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/GuidedMunitionsAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/LandPlatformAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/LifeFormAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/ModulationType.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/MunitionDescriptor.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/NonHumanLifeFormAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/RadioAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/RadioEntityType.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/SensorEmitterAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/SimulationIdentifier.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/SpacePlatformAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/SubSurfacePlatformAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/Supplies.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/SurfacePlatformAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/TimeStamp.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/TrackJamTargetIdentifier.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/VariableDatum.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/VariableParameter.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/Vector.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/WorldCoordinates.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/SupplyAppearance.cpp
  ${KDIS_DATATYPES_SOURCES_DIR}/ExpendableAppearance.cpp
)

# DataTypes DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(
    APPEND
    KDIS_HEADERS
    ${KDIS_DATATYPES_HEADERS_DIR}/AcousticEmitterSystem.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/AggregateIdentifier.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/AggregateMarking.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/AggregateType.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/APA.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/ArealObjectAppearance.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/BeamData.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/BoundingSphereRecord.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/COMBICState.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/CommunicationsChannelType.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/ConeRecord1.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/ConeRecord2.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/EllipsoidRecord1.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/EllipsoidRecord2.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/EntityDestinationRecord.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/EnvironmentRecord.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/EnvironmentType.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/FlareState.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/FundamentalOperationalData.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/FundamentalOperationalData_MarkXInterrogator.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/FundamentalOperationalData_MarkXTransponder.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/FundamentalOperationalData_RRB.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/FundamentalOperationalData_Soviet.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GaussianPlumeRecord.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GaussianPuffRecord.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED_BasicFixedWingAircraft.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED_BasicGroundCombatSoldier.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED_BasicGroundCombatVehicle.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED_BasicRotorWingAircraft.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED_EnhancedFixedWingAircraft.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED_EnhancedGroundCombatSoldier.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED_EnhancedGroundCombatVehicle.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED_EnhancedRotaryWingAircraft.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GED_GroundLogisticsVehicle.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GridAxisIrregular.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GridAxisRegular.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GridData.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GridDataType0.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GridDataType1.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GridDataType2.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GroupAssignmentRecord.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/GroupDestinationRecord.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/IFF_ATC_NAVAIDS_FundamentalParameterData.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/IFF_Layer2.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/IntercomCommunicationParameters.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/KFIXED.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/LayerHeader.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/LE_DeadReckoningParameter.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/LE_EntityIdentifier.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/LE_EulerAngles.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/LE_Vector.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/LinearObjectAppearance.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/LinearSegmentParameter.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/LineRecord1.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/LineRecord2.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/Mine.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/MinefieldAppearance.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/MinefieldDataFilter.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/MineFusing.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/MinePaintScheme.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/NamedLocationIdentifier.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/ObjectAppearance.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/ObjectType.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/OrientationError.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/PerimeterPointCoordinate.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/PointObjectAppearance.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/PointRecord1.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/PointRecord2.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/PositionError.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/PropulsionSystem.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/RecordSet.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/RectangularVolumeRecord1.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/RectangularVolumeRecord2.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/RectangularVolumeRecord3.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/RelationshipRecord.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/RelativeWorldCoordinates.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/SecondaryOperationalData.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/Shaft.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/SilentAggregateSystem.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/SilentEntitySystem.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/SphereRecord1.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/SphereRecord2.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/SystemIdentifier.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/UnderwaterAcousticEmitterBeam.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/UnderwaterAcousticEmitterSystem.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/UnderwaterAcousticFundamentalParameterData.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/VectoringNozzleSystem.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/SeparationPart.hpp
  )
  list(
    APPEND
    KDIS_SOURCES
    ${KDIS_DATATYPES_SOURCES_DIR}/AcousticEmitterSystem.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/AggregateIdentifier.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/AggregateMarking.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/AggregateType.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/APA.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/ArealObjectAppearance.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/BeamData.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/BoundingSphereRecord.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/COMBICState.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/CommunicationsChannelType.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/ConeRecord1.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/ConeRecord2.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/EllipsoidRecord1.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/EllipsoidRecord2.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/EntityDestinationRecord.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/EnvironmentRecord.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/EnvironmentType.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/FlareState.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/FundamentalOperationalData.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/FundamentalOperationalData_MarkXInterrogator.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/FundamentalOperationalData_MarkXTransponder.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/FundamentalOperationalData_RRB.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/FundamentalOperationalData_Soviet.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GaussianPlumeRecord.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GaussianPuffRecord.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GED_BasicFixedWingAircraft.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GED_BasicGroundCombatSoldier.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GED_BasicGroundCombatVehicle.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GED_BasicRotorWingAircraft.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GED_EnhancedFixedWingAircraft.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GED_EnhancedGroundCombatSoldier.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GED_EnhancedGroundCombatVehicle.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GED_EnhancedRotaryWingAircraft.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GED_GroundLogisticsVehicle.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GridAxisIrregular.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GridAxisRegular.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GridData.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GridDataType0.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GridDataType1.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GridDataType2.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GroupAssignmentRecord.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/GroupDestinationRecord.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/IFF_ATC_NAVAIDS_FundamentalParameterData.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/IFF_Layer2.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/IntercomCommunicationParameters.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/KFIXED.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/LayerHeader.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/LE_DeadReckoningParameter.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/LE_EntityIdentifier.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/LE_EulerAngles.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/LE_Vector.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/LinearObjectAppearance.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/LinearSegmentParameter.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/LineRecord1.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/LineRecord2.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/Mine.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/MinefieldAppearance.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/MinefieldDataFilter.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/MineFusing.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/MinePaintScheme.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/NamedLocationIdentifier.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/ObjectAppearance.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/ObjectType.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/OrientationError.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/PerimeterPointCoordinate.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/PointObjectAppearance.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/PointRecord1.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/PointRecord2.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/PositionError.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/PropulsionSystem.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/RecordSet.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/RectangularVolumeRecord1.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/RectangularVolumeRecord2.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/RectangularVolumeRecord3.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/RelationshipRecord.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/RelativeWorldCoordinates.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/SecondaryOperationalData.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/Shaft.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/SilentAggregateSystem.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/SilentEntitySystem.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/SphereRecord1.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/SphereRecord2.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/SystemIdentifier.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/UnderwaterAcousticEmitterBeam.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/UnderwaterAcousticEmitterSystem.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/UnderwaterAcousticFundamentalParameterData.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/VectoringNozzleSystem.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/SeparationPart.cpp
  )
endif()

# DataTypes DIS 7
if(DIS_VERSION GREATER_EQUAL 7)
  list(
    APPEND
    KDIS_HEADERS
    ${KDIS_DATATYPES_HEADERS_DIR}/AttributeRecordSet.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/BeamStatus.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/CommunicationsNodeID.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/DEAreaAimpoint.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/EnhancedMode1Code.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/ExplosionDescriptor.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/ExpendableDescriptor.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/IFF_Layer3.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/IFF_Layer3Interrogator.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/IFF_Layer3Transponder.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/IOCommunicationsNode.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/IOEffect.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/JammingTechnique.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/Mode5InterrogatorBasicData.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/Mode5InterrogatorStatus.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/Mode5TransponderBasicData.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/Mode5TransponderStatus.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/Mode5TransponderSupplementalData.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/ModeXCodeRecord.hpp
    ${KDIS_DATATYPES_HEADERS_DIR}/StandardVariable.hpp
  )
  list(
    APPEND
    KDIS_SOURCES
    ${KDIS_DATATYPES_SOURCES_DIR}/AttributeRecordSet.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/BeamStatus.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/CommunicationsNodeID.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/DEAreaAimpoint.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/EnhancedMode1Code.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/ExplosionDescriptor.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/ExpendableDescriptor.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/IFF_Layer3.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/IFF_Layer3Interrogator.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/IFF_Layer3Transponder.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/IOCommunicationsNode.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/IOEffect.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/JammingTechnique.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/Mode5InterrogatorBasicData.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/Mode5InterrogatorStatus.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/Mode5TransponderBasicData.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/Mode5TransponderStatus.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/Mode5TransponderSupplementalData.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/ModeXCodeRecord.cpp
    ${KDIS_DATATYPES_SOURCES_DIR}/StandardVariable.cpp
  )
endif()

# Enums
set(KDIS_ENUMS_HEADERS_DIR ${KDIS_HEADERS_DIR}/DataTypes/Enums)
set(KDIS_ENUMS_SOURCES_DIR ${KDIS_SOURCES_DIR}/DataTypes/Enums)

# Enums DIS 5
list(
  APPEND
  KDIS_HEADERS
  ${KDIS_ENUMS_HEADERS_DIR}/EnumBurstDescriptor.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumDescriptor.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumDesignator.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumDetonationResult.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumEmitter.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumEntityInfoInteraction.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumEntityManagement.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumHeader.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumIFF.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumMinefield.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumRadio.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumSimulationManagement.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumSupply.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumSyntheticEnvironment.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/EnumSystemIdentifier.hpp
  ${KDIS_ENUMS_HEADERS_DIR}/KDISEnums.hpp
)
list(
  APPEND
  KDIS_SOURCES
  ${KDIS_ENUMS_SOURCES_DIR}/EnumBurstDescriptor.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumDescriptor.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumDesignator.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumDetonationResult.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumEmitter.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumEntityInfoInteraction.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumEntityManagement.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumHeader.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumIFF.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumMinefield.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumRadio.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumSimulationManagement.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumSupply.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumSyntheticEnvironment.cpp
  ${KDIS_ENUMS_SOURCES_DIR}/EnumSystemIdentifier.cpp
)

# Enums DIS 7
if(DIS_VERSION GREATER_EQUAL 7)
  list(APPEND KDIS_HEADERS ${KDIS_ENUMS_HEADERS_DIR}/EnumInformationOperations.hpp)
  list(APPEND KDIS_SOURCES ${KDIS_ENUMS_SOURCES_DIR}/EnumInformationOperations.cpp)
endif()

# PDU base
set(KDIS_PDU_BASE_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU)
set(KDIS_PDU_BASE_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU)

list(APPEND KDIS_HEADERS ${KDIS_PDU_BASE_HEADERS_DIR}/Cloneable.hpp)

# PDU base DIS 5
list(APPEND KDIS_HEADERS ${KDIS_PDU_BASE_HEADERS_DIR}/Header.hpp
     ${KDIS_PDU_BASE_HEADERS_DIR}/Header6.hpp ${KDIS_PDU_BASE_HEADERS_DIR}/Bundle.hpp
)
list(APPEND KDIS_SOURCES ${KDIS_PDU_BASE_SOURCES_DIR}/Header6.cpp
     ${KDIS_PDU_BASE_SOURCES_DIR}/Bundle.cpp
)

# PDU base DIS 7
if(DIS_VERSION GREATER_EQUAL 7)
  list(APPEND KDIS_HEADERS ${KDIS_PDU_BASE_HEADERS_DIR}/Header7.hpp)
  list(APPEND KDIS_SOURCES ${KDIS_PDU_BASE_SOURCES_DIR}/Header7.cpp)
endif()

# PDU Distributed Emission Regeneration
set(KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_HEADERS_DIR
    ${KDIS_HEADERS_DIR}/PDU/Distributed_Emission_Regeneration
)
set(KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_SOURCES_DIR
    ${KDIS_SOURCES_DIR}/PDU/Distributed_Emission_Regeneration
)

# PDU Distributed Emission Regeneration DIS 5
list(APPEND KDIS_HEADERS
     ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_HEADERS_DIR}/Designator_PDU.hpp
     ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_HEADERS_DIR}/Electromagnetic_Emission_PDU.hpp
)
list(APPEND KDIS_SOURCES
     ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_SOURCES_DIR}/Designator_PDU.cpp
     ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_SOURCES_DIR}/Electromagnetic_Emission_PDU.cpp
)

# PDU Distributed Emission Regeneration DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(APPEND KDIS_HEADERS ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_HEADERS_DIR}/IFF_PDU.hpp
       ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_HEADERS_DIR}/SEES_PDU.hpp
       ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_HEADERS_DIR}/Underwater_Acoustic_PDU.hpp
  )
  list(APPEND KDIS_SOURCES ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_SOURCES_DIR}/IFF_PDU.cpp
       ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_SOURCES_DIR}/SEES_PDU.cpp
       ${KDIS_PDU_DISTRIBUTED_EMISSION_REGENERATION_SOURCES_DIR}/Underwater_Acoustic_PDU.cpp
  )
endif()

# PDU Entity Info Interaction
set(KDIS_PDU_ENTITY_INFO_INTERACTION_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Entity_Info_Interaction)
set(KDIS_PDU_ENTITY_INFO_INTERACTION_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Entity_Info_Interaction)

# PDU Entity Info Interaction DIS 5
list(APPEND KDIS_HEADERS ${KDIS_PDU_ENTITY_INFO_INTERACTION_HEADERS_DIR}/Collision_PDU.hpp
     ${KDIS_PDU_ENTITY_INFO_INTERACTION_HEADERS_DIR}/Entity_State_PDU.hpp
)
list(APPEND KDIS_SOURCES ${KDIS_PDU_ENTITY_INFO_INTERACTION_SOURCES_DIR}/Collision_PDU.cpp
     ${KDIS_PDU_ENTITY_INFO_INTERACTION_SOURCES_DIR}/Entity_State_PDU.cpp
)

# PDU Entity Info Interaction DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(APPEND KDIS_HEADERS
       ${KDIS_PDU_ENTITY_INFO_INTERACTION_HEADERS_DIR}/Collision_Elastic_PDU.hpp
       ${KDIS_PDU_ENTITY_INFO_INTERACTION_HEADERS_DIR}/Entity_State_Update_PDU.hpp
  )
  list(APPEND KDIS_SOURCES
       ${KDIS_PDU_ENTITY_INFO_INTERACTION_SOURCES_DIR}/Collision_Elastic_PDU.cpp
       ${KDIS_PDU_ENTITY_INFO_INTERACTION_SOURCES_DIR}/Entity_State_Update_PDU.cpp
  )
endif()

# PDU Entity Info Interaction DIS 7
if(DIS_VERSION GREATER_EQUAL 7)
  list(APPEND KDIS_HEADERS ${KDIS_PDU_ENTITY_INFO_INTERACTION_HEADERS_DIR}/Attribute_PDU.hpp)
  list(APPEND KDIS_SOURCES ${KDIS_PDU_ENTITY_INFO_INTERACTION_SOURCES_DIR}/Attribute_PDU.cpp)
endif()

# PDU Entity Management
set(KDIS_PDU_ENTITY_MANAGEMENT_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Entity_Management)
set(KDIS_PDU_ENTITY_MANAGEMENT_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Entity_Management)

# PDU Entity Management DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(
    APPEND
    KDIS_HEADERS
    ${KDIS_PDU_ENTITY_MANAGEMENT_HEADERS_DIR}/Aggregate_State_PDU.hpp
    ${KDIS_PDU_ENTITY_MANAGEMENT_HEADERS_DIR}/IsGroupOf_PDU.hpp
    ${KDIS_PDU_ENTITY_MANAGEMENT_HEADERS_DIR}/IsPartOf_PDU.hpp
    ${KDIS_PDU_ENTITY_MANAGEMENT_HEADERS_DIR}/Transfer_Control_Request_PDU.hpp
  )
  list(
    APPEND
    KDIS_SOURCES
    ${KDIS_PDU_ENTITY_MANAGEMENT_SOURCES_DIR}/Aggregate_State_PDU.cpp
    ${KDIS_PDU_ENTITY_MANAGEMENT_SOURCES_DIR}/IsGroupOf_PDU.cpp
    ${KDIS_PDU_ENTITY_MANAGEMENT_SOURCES_DIR}/IsPartOf_PDU.cpp
    ${KDIS_PDU_ENTITY_MANAGEMENT_SOURCES_DIR}/Transfer_Control_Request_PDU.cpp
  )
endif()

# PDU Live Entity
set(KDIS_PDU_LIVE_ENTITY_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Live_Entity)
set(KDIS_PDU_LIVE_ENTITY_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Live_Entity)

# PDU Live Entity DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(
    APPEND
    KDIS_HEADERS
    ${KDIS_PDU_LIVE_ENTITY_HEADERS_DIR}/Appearance_PDU.hpp
    ${KDIS_PDU_LIVE_ENTITY_HEADERS_DIR}/Articulated_Parts_PDU.hpp
    ${KDIS_PDU_LIVE_ENTITY_HEADERS_DIR}/LE_Detonation_PDU.hpp
    ${KDIS_PDU_LIVE_ENTITY_HEADERS_DIR}/LE_Fire_PDU.hpp
    ${KDIS_PDU_LIVE_ENTITY_HEADERS_DIR}/LE_Header.hpp
    ${KDIS_PDU_LIVE_ENTITY_HEADERS_DIR}/TSPI_PDU.hpp
  )
  list(
    APPEND
    KDIS_SOURCES
    ${KDIS_PDU_LIVE_ENTITY_SOURCES_DIR}/Appearance_PDU.cpp
    ${KDIS_PDU_LIVE_ENTITY_SOURCES_DIR}/Articulated_Parts_PDU.cpp
    ${KDIS_PDU_LIVE_ENTITY_SOURCES_DIR}/LE_Detonation_PDU.cpp
    ${KDIS_PDU_LIVE_ENTITY_SOURCES_DIR}/LE_Fire_PDU.cpp
    ${KDIS_PDU_LIVE_ENTITY_SOURCES_DIR}/LE_Header.cpp
    ${KDIS_PDU_LIVE_ENTITY_SOURCES_DIR}/TSPI_PDU.cpp
  )
endif()

# PDU Logistics
set(KDIS_PDU_LOGISTICS_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Logistics)
set(KDIS_PDU_LOGISTICS_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Logistics)

# PDU Logistics DIS 5
list(
  APPEND
  KDIS_HEADERS
  ${KDIS_PDU_LOGISTICS_HEADERS_DIR}/Logistics_Header.hpp
  ${KDIS_PDU_LOGISTICS_HEADERS_DIR}/Repair_Complete_PDU.hpp
  ${KDIS_PDU_LOGISTICS_HEADERS_DIR}/Repair_Response_PDU.hpp
  ${KDIS_PDU_LOGISTICS_HEADERS_DIR}/Resupply_Cancel_PDU.hpp
  ${KDIS_PDU_LOGISTICS_HEADERS_DIR}/Resupply_Offer_PDU.hpp
  ${KDIS_PDU_LOGISTICS_HEADERS_DIR}/Resupply_Received_PDU.hpp
  ${KDIS_PDU_LOGISTICS_HEADERS_DIR}/Service_Request_PDU.hpp
)
list(
  APPEND
  KDIS_SOURCES
  ${KDIS_PDU_LOGISTICS_SOURCES_DIR}/Logistics_Header.cpp
  ${KDIS_PDU_LOGISTICS_SOURCES_DIR}/Repair_Complete_PDU.cpp
  ${KDIS_PDU_LOGISTICS_SOURCES_DIR}/Repair_Response_PDU.cpp
  ${KDIS_PDU_LOGISTICS_SOURCES_DIR}/Resupply_Cancel_PDU.cpp
  ${KDIS_PDU_LOGISTICS_SOURCES_DIR}/Resupply_Offer_PDU.cpp
  ${KDIS_PDU_LOGISTICS_SOURCES_DIR}/Resupply_Received_PDU.cpp
  ${KDIS_PDU_LOGISTICS_SOURCES_DIR}/Service_Request_PDU.cpp
)

# PDU Minefield
set(KDIS_PDU_MINEFIELD_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Minefield)
set(KDIS_PDU_MINEFIELD_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Minefield)

# PDU Minefield DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(
    APPEND
    KDIS_HEADERS
    ${KDIS_PDU_MINEFIELD_HEADERS_DIR}/Minefield_Data_PDU.hpp
    ${KDIS_PDU_MINEFIELD_HEADERS_DIR}/Minefield_Header.hpp
    ${KDIS_PDU_MINEFIELD_HEADERS_DIR}/Minefield_Query_PDU.hpp
    ${KDIS_PDU_MINEFIELD_HEADERS_DIR}/Minefield_Response_NACK_PDU.hpp
    ${KDIS_PDU_MINEFIELD_HEADERS_DIR}/Minefield_State_PDU.hpp
  )
  list(
    APPEND
    KDIS_SOURCES
    ${KDIS_PDU_MINEFIELD_SOURCES_DIR}/Minefield_Data_PDU.cpp
    ${KDIS_PDU_MINEFIELD_SOURCES_DIR}/Minefield_Header.cpp
    ${KDIS_PDU_MINEFIELD_SOURCES_DIR}/Minefield_Query_PDU.cpp
    ${KDIS_PDU_MINEFIELD_SOURCES_DIR}/Minefield_Response_NACK_PDU.cpp
    ${KDIS_PDU_MINEFIELD_SOURCES_DIR}/Minefield_State_PDU.cpp
  )
endif()

# PDU Radio Communications
set(KDIS_PDU_RADIO_COMMUNICATIONS_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Radio_Communications)
set(KDIS_PDU_RADIO_COMMUNICATIONS_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Radio_Communications)

# PDU Radio Communications DIS 5
list(
  APPEND
  KDIS_HEADERS
  ${KDIS_PDU_RADIO_COMMUNICATIONS_HEADERS_DIR}/Radio_Communications_Header.hpp
  ${KDIS_PDU_RADIO_COMMUNICATIONS_HEADERS_DIR}/Receiver_PDU.hpp
  ${KDIS_PDU_RADIO_COMMUNICATIONS_HEADERS_DIR}/Signal_PDU.hpp
  ${KDIS_PDU_RADIO_COMMUNICATIONS_HEADERS_DIR}/Transmitter_PDU.hpp
)
list(
  APPEND
  KDIS_SOURCES
  ${KDIS_PDU_RADIO_COMMUNICATIONS_SOURCES_DIR}/Radio_Communications_Header.cpp
  ${KDIS_PDU_RADIO_COMMUNICATIONS_SOURCES_DIR}/Receiver_PDU.cpp
  ${KDIS_PDU_RADIO_COMMUNICATIONS_SOURCES_DIR}/Signal_PDU.cpp
  ${KDIS_PDU_RADIO_COMMUNICATIONS_SOURCES_DIR}/Transmitter_PDU.cpp
)

# PDU Radio Communications DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(APPEND KDIS_HEADERS ${KDIS_PDU_RADIO_COMMUNICATIONS_HEADERS_DIR}/Intercom_Control_PDU.hpp
       ${KDIS_PDU_RADIO_COMMUNICATIONS_HEADERS_DIR}/Intercom_Signal_PDU.hpp
  )
  list(APPEND KDIS_SOURCES ${KDIS_PDU_RADIO_COMMUNICATIONS_SOURCES_DIR}/Intercom_Control_PDU.cpp
       ${KDIS_PDU_RADIO_COMMUNICATIONS_SOURCES_DIR}/Intercom_Signal_PDU.cpp
  )
endif()

# PDU Simulation Management
set(KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Simulation_Management)
set(KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Simulation_Management)

# PDU Simulation Management DIS 5
list(
  APPEND
  KDIS_HEADERS
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Acknowledge_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Action_Request_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Action_Response_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Comment_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Create_Entity_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Data_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Data_Query_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Event_Report_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Remove_Entity_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Set_Data_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Simulation_Management_Header.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Start_Resume_PDU.hpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_HEADERS_DIR}/Stop_Freeze_PDU.hpp
)
list(
  APPEND
  KDIS_SOURCES
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Acknowledge_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Action_Request_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Action_Response_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Comment_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Create_Entity_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Data_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Data_Query_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Event_Report_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Remove_Entity_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Set_Data_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Simulation_Management_Header.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Start_Resume_PDU.cpp
  ${KDIS_PDU_SIMULATION_MANAGEMENT_SOURCES_DIR}/Stop_Freeze_PDU.cpp
)

# PDU Simulation Management With Reliability
set(KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR
    ${KDIS_HEADERS_DIR}/PDU/Simulation_Management_With_Reliability
)
set(KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR
    ${KDIS_SOURCES_DIR}/PDU/Simulation_Management_With_Reliability
)

# PDU Simulation Management With Reliability DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(
    APPEND
    KDIS_HEADERS
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Acknowledge_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Action_Request_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Action_Response_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Comment_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Create_Entity_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Data_Query_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Data_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Event_Report_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Record_Query_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Record_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Reliability_Header.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Remove_Entity_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Set_Data_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Set_Record_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Start_Resume_R_PDU.hpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_HEADERS_DIR}/Stop_Freeze_R_PDU.hpp
  )
  list(
    APPEND
    KDIS_SOURCES
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Acknowledge_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Action_Request_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Action_Response_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Comment_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Create_Entity_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Data_Query_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Data_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Event_Report_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Record_Query_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Record_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Reliability_Header.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Remove_Entity_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Set_Data_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Set_Record_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Start_Resume_R_PDU.cpp
    ${KDIS_PDU_SIMULATION_MANAGEMENT_WITH_RELIABILITY_SOURCES_DIR}/Stop_Freeze_R_PDU.cpp
  )
endif()

# PDU Synthetic Environment
set(KDIS_PDU_SYNTHETIC_ENVIRONMENT_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Synthetic_Environment)
set(KDIS_PDU_SYNTHETIC_ENVIRONMENT_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Synthetic_Environment)

# PDU Synthetic Environment DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(
    APPEND
    KDIS_HEADERS
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_HEADERS_DIR}/Areal_Object_State_PDU.hpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_HEADERS_DIR}/Environmental_Process_PDU.hpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_HEADERS_DIR}/Gridded_Data_PDU.hpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_HEADERS_DIR}/Linear_Object_State_PDU.hpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_HEADERS_DIR}/Object_State_Header.hpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_HEADERS_DIR}/Point_Object_State_PDU.hpp
  )
  list(
    APPEND
    KDIS_SOURCES
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_SOURCES_DIR}/Areal_Object_State_PDU.cpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_SOURCES_DIR}/Environmental_Process_PDU.cpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_SOURCES_DIR}/Gridded_Data_PDU.cpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_SOURCES_DIR}/Linear_Object_State_PDU.cpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_SOURCES_DIR}/Object_State_Header.cpp
    ${KDIS_PDU_SYNTHETIC_ENVIRONMENT_SOURCES_DIR}/Point_Object_State_PDU.cpp
  )
endif()

# PDU Warfare
set(KDIS_PDU_WARFARE_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Warfare)
set(KDIS_PDU_WARFARE_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Warfare)

# PDU Warfare DIS 5
list(APPEND KDIS_HEADERS ${KDIS_PDU_WARFARE_HEADERS_DIR}/Detonation_PDU.hpp
     ${KDIS_PDU_WARFARE_HEADERS_DIR}/Fire_PDU.hpp
     ${KDIS_PDU_WARFARE_HEADERS_DIR}/Warfare_Header.hpp
)
list(APPEND KDIS_SOURCES ${KDIS_PDU_WARFARE_SOURCES_DIR}/Detonation_PDU.cpp
     ${KDIS_PDU_WARFARE_SOURCES_DIR}/Fire_PDU.cpp
     ${KDIS_PDU_WARFARE_SOURCES_DIR}/Warfare_Header.cpp
)

# PDU Warfare DIS 7
if(DIS_VERSION GREATER_EQUAL 7)
  list(APPEND KDIS_HEADERS ${KDIS_PDU_WARFARE_HEADERS_DIR}/Directed_Energy_Fire_PDU.hpp
       ${KDIS_PDU_WARFARE_HEADERS_DIR}/Entity_Damage_Status_PDU.hpp
  )
  list(APPEND KDIS_SOURCES ${KDIS_PDU_WARFARE_SOURCES_DIR}/Directed_Energy_Fire_PDU.cpp
       ${KDIS_PDU_WARFARE_SOURCES_DIR}/Entity_Damage_Status_PDU.cpp
  )
endif()

# PDU Information Operations
set(KDIS_PDU_INFORMATION_OPERATIONS_HEADERS_DIR ${KDIS_HEADERS_DIR}/PDU/Information_Operations)
set(KDIS_PDU_INFORMATION_OPERATIONS_SOURCES_DIR ${KDIS_SOURCES_DIR}/PDU/Information_Operations)

# PDU Information Operations DIS 7
if(DIS_VERSION GREATER_EQUAL 7)
  list(APPEND KDIS_HEADERS ${KDIS_PDU_INFORMATION_OPERATIONS_HEADERS_DIR}/IO_Header.hpp
       ${KDIS_PDU_INFORMATION_OPERATIONS_HEADERS_DIR}/IO_Action_PDU.hpp
       ${KDIS_PDU_INFORMATION_OPERATIONS_HEADERS_DIR}/IO_Report_PDU.hpp
  )
  list(APPEND KDIS_SOURCES ${KDIS_PDU_INFORMATION_OPERATIONS_SOURCES_DIR}/IO_Header.cpp
       ${KDIS_PDU_INFORMATION_OPERATIONS_SOURCES_DIR}/IO_Action_PDU.cpp
       ${KDIS_PDU_INFORMATION_OPERATIONS_SOURCES_DIR}/IO_Report_PDU.cpp
  )
endif()

# Extras
set(KDIS_EXTRAS_HEADERS_DIR ${KDIS_HEADERS_DIR}/Extras)
set(KDIS_EXTRAS_SOURCES_DIR ${KDIS_SOURCES_DIR}/Extras)

list(
  APPEND
  KDIS_HEADERS
  ${KDIS_EXTRAS_HEADERS_DIR}/DeadReckoningCalculator.hpp
  ${KDIS_EXTRAS_HEADERS_DIR}/DIS_Logger_Playback.hpp
  ${KDIS_EXTRAS_HEADERS_DIR}/DIS_Logger_Record.hpp
  ${KDIS_EXTRAS_HEADERS_DIR}/KConversions.hpp
  ${KDIS_EXTRAS_HEADERS_DIR}/KRef_Ptr.hpp
  ${KDIS_EXTRAS_HEADERS_DIR}/KUtils.hpp
  ${KDIS_EXTRAS_HEADERS_DIR}/Math.hpp
  ${KDIS_EXTRAS_HEADERS_DIR}/PDU_Factory.hpp
  ${KDIS_EXTRAS_HEADERS_DIR}/PDU_Factory_Filters.hpp
)
list(APPEND KDIS_SOURCES ${KDIS_EXTRAS_SOURCES_DIR}/DeadReckoningCalculator.cpp
     ${KDIS_EXTRAS_SOURCES_DIR}/DIS_Logger_Playback.cpp
     ${KDIS_EXTRAS_SOURCES_DIR}/DIS_Logger_Record.cpp ${KDIS_EXTRAS_SOURCES_DIR}/PDU_Factory.cpp
)

# Network
set(KDIS_NETWORK_HEADERS_DIR ${KDIS_HEADERS_DIR}/Network)
set(KDIS_NETWORK_SOURCES_DIR ${KDIS_SOURCES_DIR}/Network)

list(APPEND KDIS_HEADERS ${KDIS_NETWORK_HEADERS_DIR}/Connection.hpp
     ${KDIS_NETWORK_HEADERS_DIR}/ConnectionAddressFilter.hpp
     ${KDIS_NETWORK_HEADERS_DIR}/ConnectionSubscriber.hpp
)
list(APPEND KDIS_SOURCES ${KDIS_NETWORK_SOURCES_DIR}/Connection.cpp
     ${KDIS_NETWORK_SOURCES_DIR}/ConnectionAddressFilter.cpp
)

#
# Configuration file
#
set(KDIS_HEADER_CONFIG_FILE ${KDIS_HEADERS_DIR_BINARY}/KConfig.hpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/KConfig.hpp.in ${KDIS_HEADER_CONFIG_FILE} @ONLY)
list(APPEND KDIS_HEADERS ${KDIS_HEADER_CONFIG_FILE})

#
# Library
#
add_library(${PROJECT_NAME} ${KDIS_HEADERS} ${KDIS_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
# Export header
set(KDIS_HEADER_EXPORT_FILE ${KDIS_HEADERS_DIR_BINARY}/KExport.hpp)
generate_export_header(
  ${PROJECT_NAME} EXPORT_FILE_NAME ${KDIS_HEADER_EXPORT_FILE} INCLUDE_GUARD_NAME
  ${PROJECT_NAME}_KEXPORT_HPP_
)
list(APPEND KDIS_HEADERS ${KDIS_HEADER_EXPORT_FILE})
# Include directories
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
# Compile definitions
target_compile_definitions(
  ${PROJECT_NAME} PRIVATE DIS_VERSION=${DIS_VERSION}
                          $<$<BOOL:${KDIS_USE_ENUM_DESCRIPTORS}>:KDIS_USE_ENUM_DESCRIPTORS>
)
# Properties
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
# TODO Compile options target_compile_options( ${PROJECT_NAME} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4
# /WX> $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror> )

#
# Install
#
if(KDIS_BUILD_INSTALL)
  # Headers
  foreach(file ${KDIS_HEADERS})
    get_filename_component(file ${file} ABSOLUTE)
    get_filename_component(dir ${file} DIRECTORY)
    if(dir STREQUAL ${KDIS_HEADERS_DIR_BINARY})
      set(headers_dir ${KDIS_HEADERS_DIR_BINARY})
    else()
      set(headers_dir ${KDIS_HEADERS_DIR})
    endif()
    string(REPLACE ${headers_dir} "" dir ${dir})
    set(dir "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${dir}")
    if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.31")
      # Policy CMP0177
      cmake_path(SET dir NORMALIZE "${dir}")
    endif()
    install(FILES ${file} DESTINATION ${dir})
  endforeach()
  # Configuration
  configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
  )
  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )
  # Package
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
                ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
  )
  install(
    EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
  )
  install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

  #
  # CPack
  #
  set(CPACK_GENERATOR DEB RPM TXZ TGZ)
  set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
  set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
  set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_DESCRIPTION})
  set(CPACK_PACKAGE_FILE_NAME
      "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}.${CMAKE_SYSTEM_PROCESSOR}"
  )
  set(CPACK_PACKAGE_RPM_DIR "${CMAKE_CURRENT_BINARY_DIR}/_CPack_Packages/Linux/RPM")
  set(CPACK_DEBIAN_PACKAGE_MAINTAINER
      "Karl Jones <Karljj1@yahoo.com>, Carlo Corradini <carlo.corradini98@gmail.com>"
  )
  include(CPack)
endif()

#
# Examples
#
if(KDIS_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

#
# Documentation
#
if(KDIS_BUILD_DOCS)
  set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
  set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")

  configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

  add_custom_target(
    ${PROJECT_NAME}_docs
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
  )
endif()

#
# Tests
#
if(KDIS_BUILD_TESTS)
  add_subdirectory(tests)
endif()
