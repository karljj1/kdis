# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## Unreleased

### Added

### Deprecated

### Removed

### Fixed

## 2.10.0 - 2023-10-12

### Added

-   `ApplyFilterBeforeDecodingPDUBody` to `PDU_Factory_Filter`. It can be used to reject PDU's before the body has been decoded enhancing performance or for rejecting custom or non-standard PDU's
-   `RadioAppearance` struct
-   `SupplyAppearance` struct
-   `VariableParameter` type `SeparationPart`
-   `BeamStateEnum` to the `EnumEmitter` file based on the `UID 318` contents of `SISO-REF-010-2016-v22` document
-   Additional enums (`SISO 10-2015`) for `ModulationType`, `BeamAntennaPatternReferenceSystem`, `ModulationSystem`, `TDLType`, `SystemType`, `SystemMode`, and `SystemName`
-   `DIS 7` support added for `SystemIdentifier`,`BeamAntennaPattern`, and `ExpendableDescriptor`
-   `SendOnly` option to `Connection` class. `Connection` will not bind if this is `true`
-   Support for `unique_ptr` when `C++11` is supported
-   Implementation of getter and setter running lights to `SubSurfacePlatformAppearance`
-   More unit tests
-   Guard in case `_USE_MATH_DEFINES` is already defined in `KUtils.h`
-   `CMAKE_INSTALL_PREFIX` to define alternative install location (defaults to `/usr/include/KDIS`)
-   Non-Human Life Form Appearance
-   `Simulation_Management_Header` explicit constructor and copy constructor
-   Missing enums `16` and `17` for `EventTypeEnum` ([#89](https://sourceforge.net/p/kdis/bugs/89))
-   Additional Time Shared enums ([#103](https://sourceforge.net/p/kdis/bugs/103))
-   Incorrect conversion from bits to bytes in `Signal_PDU`

### Changed

-   `EmitterBeam` class to use `DIS_VERSION` definition when defining or declaring member variables and method. For `DIS 7`, introduced the `BeamStatus` and `JammingTechnique` classes to replicate the v7 PDU structure
-   `PDU_Factory_Filter` virtual destructor to prevent undefined behavior
-   `LifeFormAppearance` struct with additional fields
-   `AirPlatformAppearance` struct with additional fields
-   `GuidedMunitionAppearance` struct with additional fields
-   Improved `GetAsString` function for `NonHumanLifeFormAppearance`
-   `CulturalFeatureAppearance` incorrectly supports Engine Smoke bit. Modified the struct to eliminate bit-6 tracking
-   `Connection` functions to be `virtual` allowing further derivation

### Deprecated

### Removed

### Fixed

-   `EllipsoidRecord2::Decode` should not have included `EllipsoidRecord1::Decode`
-   Inaccuracy in `GeocentricToGeodetic` calculations
-   Unit test compilation issues on Linux
-   Corrected some old tutorial links
-   Ordering of orientation and `dt` sigma fields in `EllipsoidRecord2`
-   Whitespace and comment cleaning
-   Incorrect PDU length calculation when calling `Comment_PDU::SetVariableDatum`
-   `Action_Response_PDU` constructor not populating all fields and incorrect length calculation
-   Incorrect erasing loop in `Connection::RemoveSubscriber` where duplicates were not always removed ([#49](https://sourceforge.net/p/kdis/bugs/49))
-   Rounding error in `GeocentricToGeodetic`
-   Incorrect PDU length comment ([#50](https://sourceforge.net/p/kdis/bugs/50))
-   `AttributeRecordSet::GetRecordLength` not including all fields in size calculation ([#51](https://sourceforge.net/p/kdis/bugs/51))
-   Divide by `0` in `DeadReckoningCalculator::computeRotationAxis` when axis were `0`
-   Bug in `Connection::GetNextPDU` when a PDU was not decoded. Now the stream is cleared and flow continues
-   Bug in `OrientationError::SetElevationError` ndue to no value was assigned
-   `Minefield_Data_PDU::Encode` not correctly increment the detonation wires
-   Memory leak in `PDU_Factory` when applyFilters rejected the PDU
-   Memory leak in `Entity_State_PDU::operator=` when assigning a new `DeadReckoningCalculator`
-   Conversion Near Poles and Casting in `KCOnversion.h` (thanks Kyle)
-   Logic error in detecting polar regions for the coordinate conversion code
-   Bug in `Intercom_Control_PDU::Decode`
-   Type mismatch between `EntityAppearance` types (class to structs)
-   Memory leak in `Entity_State_PDU` when calling `SetDeadReckoningCalculator`
-   `CryptoSystem` byte ordering
-   `MarkXTransponder` negative altitude detection
-   Potential stream overrun in `DetonationPDU`
-   `Layer2` and `Layer3` incorrectly double decoding the header due to constructors not ignoring the header even when one is provided
-   Enum functions not being exported to `dll` ([#94](https://sourceforge.net/p/kdis/bugs/94))
-   Incorrect enums for Beam Function ([#103](https://sourceforge.net/p/kdis/bugs/103))

### Security

## 2.9.0 - 2016-01-21

### Added

-   Unit tests via [`googletest`](https://github.com/google/googletest) framework
-   Bool operator for convenience to `KRef_Ptr`
-   `Connection::SetBlockingTimeOut` allowing for setting a timeout for blocking mode
-   Copy constructor and assignment operator to `Entity_State_PDU`
-   Getter and setter functions to `EntityKind` that support integers as well as enums for kind, domain and country simplifying the overall usage
-   `GetEnumSize` and `GetEnumDescriptor` exposing the internal `EnumDescriptor` arrays used for `GetEnumAsString` and `GetEnumFromString` allowing to iterate through an enumeration using these two functions
-   Implicit conversion support to `KRef_Ptr`
-   Implementation of `LifeFormAppearance::SetEntityLifeformState`
-   `PDU_FactoryLink16` to `Link 16` example
-   Padding to `SilentAggregateSystem`
-   Padding to `Mode5TransponderBasicData`

### Changed

-   Format in `RelativeWorldCoordinates::GetAsString()`
-   Improved `Connection` socket error messages
-   Improved debugging information in header when a PDU has a buffer that is too small
-   `Link 16` example is built as a dynamic library
-   `Link16` example code to support partial decoding

### Fixed

-   Incorrect size was assigned to `LE_VECTOR_SIZE`
-   `KRef_Ptr` compilation bug when using weak references
-   `AggregateMarking::Decode` not setting the last char to `\0` in `m_sAggregateMarkingString` casuing comparison issues
-   Bug decode and encode functions in `Entity_State_Update_PDU` that not handled padding correctly
-   Bug in `Appearance_PDU` decode function when no flags were used
-   Bug in `AttachedPart` not encoding and decoding the part type
-   Bug in `FixedDatum:GetDatumValue` was using `strncpy` to return data which causes issues when the data was not a `string`
-   Bug in `IFF_PDU::Decode`
-   Bug in `Intercom Control` PDU and `IntercomCommunicationParameters` where some values were not initialized causing unexpected behaviours during encoding and deconding
-   Bug in `Underwater_Acoustic_PDU::Decode` was encoding by mistake
-   Bug in `SphereRecord2::Encode()` was calling the wrong encoding function internally
-   Bug in `GED_BasicFixedWingAircraft` and `GED_BasicFixedWingAircraft` that used `8 bit` int instead of `16 bit` for speed
-   `CMake` for `KDIS_LIB` that was causing building a shared library instead of static
-   `CMake` for `MinGW` when building `lib` and `dll` version of `KDIS`
-   Comparison operator `==` in `Set_Data_R_PDU`
-   Comparison operator `==` in `KFIXED`
-   Decoding bug in `Intercom_Control_PDU`
-   Deconding bug when handling padding in `Aggregate_State_PDU`
-   Encoding bug in `Receiver_PDU`
-   Encoding and deconding bug in `Entity_Damage_Status_PDU` was not including padding
-   Exception handling bug in `Connection` and `IsGroupOf_PDU`
-   Incorrect PDU minimum size for `GridDataType` `0` and `1`
-   Incorrect PDU size in `Underwater_Acoustic_PDU`
-   Incorrect PDU size in `IFF_ATC_NAVAIDS_FundamentalParameterData`
-   Missing padding in `IO_Report_PDU`
-   `null` reference crash when encoding `IntercomCommunicationParameters` with no record
-   Protocol version not being set in `Intercom_Control_PDU`
-   `SilentEntitySystem` not initializing `m_ui16NumOfAppearanceRecords` to `0` casuing enconding and deconding failure
-   Size calculation in `SetFixedDatum` and `SetVariableDatum`
-   `TSPI_PDU::m_ui8SSDLen` not being initialised to `0` in some constructors
-   Uninitialized variables in `SetData_R_PDU`
-   `VariableDatum::GetPDULength` returning the incorrect value
-   Several fixes for `LE_FIRE_PDU` and `LE_Detonation_PDU` from public submission (thanks Gï¿½ran)

## 2.8.0 - 2014-06-27

### Added

-   `IFF_PDU` PDU which replaces `IFF_ATC_NAVAIDS_L1_PDU` PDU
-   `IFF_Layer3Transponder` and `IFF_Layer3Interrogator` classes
-   `VariableParamaters` class. This replaces all `ArticulationParamaters` classes as the base class
-   `AttachedPart` class
-   `CryptoSystem::SetKeyID` and `CryptoSystem::GetKeyID`
-   Implementations of `LinearVelocity`, `EntityLocation`, `EntityOrientation`, `EntityAppearance` in `Entity_State_Update_PDU`
-   Implementation of `SetPDUStatusFireType` and `GetPDUStatusFireType` in `Fire_PDU`
-   Getter and setter for `ResponseCode`, `ResponsePowerReduction`, and `ResponseRadarEnhancement` in `FundamentalOperationalData_RRB`
-   Getter and setter for `NumBurst` in `PointObjectAppearance`
-   Getter and setter for `AttackerEntityID` to `AttackerEntityID`
-   `WorldCoordinates::Set` to set all values in one call
-   `Vector::Set` to set all values in one call
-   `Vector::Lerp`
-   `WorldCoordinates::Lerp`
-   `SystemDesignator` and `SystemSpecificData` to `IFF_ATC_NAVAIDS_L1_PDU`
-   `SetTCASVersion` to `FundamentalOperationalData_MarkXTransponder` and `FundamentalOperationalData_MarkXInterrogator`
-   Missing enums to `StationName`
-   Missing enums to `WarfareType`
-   Missing enums to `EncodingType`
-   `Automatic Dependent Surveillance` broadcast to `EntityCapabilities`
-   `make install` target for Linux (thanks Bud Davis)

### Changed

-   Renamed `ArticulationParamaters` to `ArticulatedPart`
-   `BurstDescriptor` in `LE Fire` and `LE Detonation` PDU with `MunitionDescriptor`. This class is the same except for the `SetMunition` and `GetMunition` functions which are now named `SetType` and `GetType`
-   Renamed `ArticulationParameters` to `ArticulatedPart`
-   Renamed `TypeVariantHighBits` to `TypeVariantClass` in `ArticulatedPart`
-   Renamed `TypeVariantLowBits` to `TypeVariantMetric` in `ArticulatedPart`
-   `FactoryDecoder` uses `KRef_Ptr` class
-   Renamed `EnumFundamentalOperationalData.h` to `EnumIFF.h` and `EnumFundamentalOperationalData.cpp` to `EnumIFF.cpp`
-   Renamed enum `WarheadType::GlassBladsWarhead` to `WarheadType::GlassBeadsWarhead`
-   Renamed enum `EncodingType::_16_bit_linear_PCM` to `EncodingType::_16_bit_linear_PCM2sComplementBigEndian`
-   From defintion `COMM_CHANNEL_TYPE` to `static KUINT16 COMM_CHANNEL_TYPE_SIZE`
-   Cleaned namespaces
-   Cleaned `GetAsString` for many classes
-   Performance improvements in decoding. Parameter `ignoreHeader` added to `Decode` function on PDU's, this will help performance by not decoding the Header twice each time a PDU is received. `PDU_Factory` uses this technique
-   Improved comments
-   _Copyright 2013 KDIS_ to _Copyright 2013 Karl Jones_
-   `UNLICENSE` statement to examples excepts `Link16`

### Removed

-   `BurstDescriptor`. Fire PDU and Detonation PDU now use the Descriptor class. Fire PDU has Munition and Expendable descriptor. Detonation has Munition, Expendable or Explosion descriptor. This is in line with the `DIS 7` standard. To support `< DIS 7` then use the Munition Descriptor class
-   `IFF_ATC_NAVAIDS_L2_PDU` PDU. Now a data type class called `IFF_Layer2` which is a property of `IFF_PDU`
-   Removed `OtherCollision` from enum `CollisionType`
-   Macro `KDIS_VERSION`

### Fixed

-   No operation bug in `CryptoSystem::SetCryptoSystemType`
-   No operation bug in `Aggregate_State_PDU::SetAggregateState`
-   Incorrect size values for `DATA_R_PDU`, `SET_RECORD_R_PDU_SIZE`, and `STOP_FREEZE_R_PDU_SIZE`
-   Bug in `Set_Record_R_PDU::Decode` and `Set_Record_R_PDU::Encode` due to not enough padding
-   Error checking bug in `Resupply_Received_PDU::Decode` and `Service_Request_PDU::Decode`
-   Bug in `Transmitter_PDU::Transmitter_PDU` where `AntennaPatternLength` was using the wrong data type
-   Bug in `Data_Query_PDU::SetVariableDatum` where the length had a wrong value
-   Bug in `MinePaintScheme` due to not using the correct variable for `SetPaintScheme` and `GetPaintScheme`
-   `ArticulatedPart` parameter type variant field had incorrect high and low bits
-   `ArticulatedPart` Parameter type value field should have been `KFLOAT32` and not `KUINT64`
-   Bug in `TimeStamp::SetTimeStampType`
-   Bug in `EmitterBeam::SetEmitterBeamFunction` due to missing implementation
-   Bug in `EmitterBeam::ClearTrackedJammedTargets` due to invalid length value
-   Bug with `EmissionSystem` data length being set to bytes and not words
-   Enum `CollisionType` had inelastic and elastic values mixed up
-   Bug compiling `Link 16` example when using the `dll` version of `KDIS`
-   `Data_PDU::RequestID` was not set to `0` by default causing junk values
-   Bug in `Directed_Energy_Fire_PDU` encode and decode functions were not including padding
-   Bug in `FactoryDecoder` when calling the clear function. If a single object was used to handle more than 1 enum it would attempt to delete it multiple times(one per enum)
-   Bug with `GuidedMunitionsAppearance` when using the `dll` version of `KDIS`
-   Bug in `GetNextPDU` function when an error occurs, the next call was using corrupted data
-   Incorrect function name in `EllipsoidRecord2`. Function `GetSigma` should have been `GetDOverDt`
-   Invalid symbolic names
-   Compilation bug when using _Visual Studio 2010 Express_ due to `WIN32` was not defined
-   Comment _you have to cmake . cmake . before building_ (thanks Bud Davis)
-   Missing license header in some files

## 2.7.0 - 2013-01-31

### Changed

-   License from `LGPL` to `FreeBSD`
-   Renamed `COLLISION_THRSH_DFLT` to `COLLISION_THRSH` and `EE_EL_THRSH_DFLT` to `EE_EL_THRSH` in `KSynmbolicNames.h`
-   Default `DIS` version is `DIS 7` when using `CMake`
-   From `ProtocolVersion IEEE_1278_1_200x` to `IEEE_1278_1_2012` in `EnumHeader.h`

## 2.6.0 - 2012-12-18

### Added

-   `KDIS::PDU::Bundle` class to support sending PDU Bundles
-   `Example_Bundle` to show how to send PDU Bundles
-   Support to `Connection` class to handle PDU Bundles via `GetNextPDU` function.
-   Operators `==` and `!=` to `KDataStream`
-   `Send(const KDataStream& stream)` function in `Connection` class
-   Comment in `SetProtocolVersion` function to clear some common questions about how `KDIS` sets the `ProtocolVersion`

### Changed

-   `Example_PDUFactory` to support PDU Bundles
-   `CopyFromBuffer` parameter `SerialData` is `const`

### Fixed

-   Bug in `CulturalFeatureAppearance::SetEntityExteriorLights` where an invalid value was being assigned
-   Bug in `Transmitter_PDU::Encode` function

## 2.5.0 - 2012-08-08

### Added

-   `Cultural` and `Sensor/Emitter` appearances

### Changed

-   Extended the appearance type classes so they now contain all the appearance data instead of just the specific in `EntityAppearance`. The general appearance data was not always used in the same way
-   `Data_Query_PDU` and `Data_Query_R_PDU` time interval field to use the `TimeStamp` class instead of a `KUINT32`

### Removed

-   Removed General and Specific Appearance classes from `EntityAppearance`

### Fixed

-   Bug in `EnumDetonationResult`

-   Bug in `TimeStamp::CalculateTimeStamp` where the `Linux` version was not using `nano secs`

## 2.4.0 - 2011-12-14

### Added

-   `Link16_Signal_PDU` PDU
-   `Link16_Transmitter_PDU` PDU
-   `GetEnumFromString<Enum Name>` function allowing to convert an enum string to value and value to enum
-   Added missing enums in `EmitterName`

### Changed

-   Examples are now sorted in sub directories by their category
-   `CMake` files to generate solution directories to better organize projects. Mainly a _Visual Studio Pro_ (not _Visual Studio Express_) feature. Controlled by the `CMake` flag `USE_SOLUTION_FOLDERS`
-   Renamed enum descriptors in `EnumInformationOperations.cpp` to align with naming convention used in other enum files

### Fixed

-   Bug in `Data_Query_PDU` and `Data_Query_R_PDU` where variable and fixed Datum's were being used instead of just ID's
-   Improvements to `DeadReckoningCalculator::GenerateSmoothingPoints`
-   Bug in `CMake` for `DIS 7` when using `KDIS` as a `DLL` since it was including `EnumInformationOperations.cpp`
-   Bug in Collision PDU where the variable `m_f32Mass` was not being encoded/decoded
-   Bug in several `GetEnumAsString<Enum Name>` functions where the size of their descriptors was using the incorrect value
-   Some classes were not setting variables to `0` by default
-   Bug in `EncodingScheme` due to incorrect size
-   Invalid enums in `EmitterName`

## 2.3.0 - 2011-07-27

### Added

-   `Directed_Energy_Fire_PDU` PDU
-   `Entity_Damage_Status_PDU` PDU
-   `EntityMarking` support for `string` instead of `char[]`
-   `Vector::GetMagnitude`, `Vector::GetDistance`, and `WorldCoordinates::GetDistance` functions
-   Missing PDUs in `PDU_Factory`

### Changed

-   Function `send` in `Connection` returns the number of bytes sent instead of `void`

### Removed

-   `LGPL` licence header from examples. All examples are unlicenced

### Fixed

-   `APA` class `public` union should have been `private`
-   Memory leak in `Connection` class where the `PDU_Factory` was not being deleted

## 2.2.0 - 2011-05-30

### Added

-   `Attribute_PDU` PDU
-   `FactoryDecoder` class to add custom decoders. Current data types that now support this feature are `VariableDatum`, `FixedDatum`, `EnvironmentRecord`, and `StandardVariable`
-   Further enumerations for `DatumID` field, taken from `SISO-REF-010-2010 RC3`
-   `Header6` and `Header7`, based on the `DIS_VERSION`, alias of `Header`
-   `Header7` features all PDU Status fields and codes from `DIS 7` standard
-   `ConnectionAddressFilter` class, in `NETWORK` namespace, allowing for filtering by IP address
-   `ConnectionAddressFilter` example
-   `FactoryDecode` function to `EnvironmentRecord`. All derived classes can now be decoded using this function
-   `ClearVariableDatumList` to `Aggregate_State_PDU`
-   `CMake` option `BUILD_EXAMPLES`
-   [`astyle`](https://sourceforge.net/projects/astyle) to fix code format

### Changed

-   In order to support custom data types some PDU now store internal objects as pointers. Some PDU interfaces have been changed to reflect this. StandardVariable Factory Decode functions have also been changed
-   Performance improvements (_~20%_) to `KDataStream` encode and decode functions
-   Renamed _LE_ directory to _Live_Entity_ for better naming style with other PDU family directories
-   `Environment_Process_PDU` decode function to use the new `FactoryDecode` function from `EnvironmentRecord`
-   From `#if DIS_VERSION >= 7` to `#if DIS_VERSION > 6` for compiling with `MinGW`

### Removed

-   `PDUStatusTEILVC`

### Fixed

-   Bug in `Transmitter_PDU::GetAsString` where the length of Modulation Param was not being output correctly
-   Bug in `PDU_Factory` decode function that prevented PDU bundling
-   Compilation error in `Connection.cpp`, for some versions of Linux, due to `Connection::SendPDU(Header *H)` did not match the header signature
-   When using none blocking sockets in `Connection::GetNextPDU` the `OnDataReceived` event was called even when no data is received
-   Corrected `DetonationType` enum values
-   Compilation warning with some compilers due to files not ending with a newline

## 2.1.1 - 2010-12-23

### Added

-   `SendPDU` function to `Connection` class

### Changed

-   Example `Env Proc PDU` to show the usage of `SendPDU` function
-   `ConnectionSubscriber` to allow for making changes on pdu transmit

## 2.1.0 - 2010-12-22

### Added

-   `IO_Action_PDU` PDU
-   Namespace called `NETWORK` where is available the new `Connection` class, a cross platform `DIS` centric socket
-   Example `Example_PduFactory2` to show the usagew of the new `Connection` class
-   `Decode` function to `PDU_Factory`. It is now simple to add support for custom PDU classes by overriding the function in custom factory classes
-   Missing `GetEnumAsString` calls for various enums
-   `KDataStream::GetBufferPtr` function to improve performance over using `CopyIntoBuffer` function
-   Missing function `GetEnumAsStringDetailAmplitude`

### Changed

-   Improved clarity and appearance of various `GetAsString` functions
-   Examples to use the new `KDataStream::GetBufferPtr` function
-   `KException` to inherit from `std::exception` allowing for catching `KDIS` exceptions with standard exceptions
-   Examples to use `KException` as a standard excpetion
-   Renamed all example projects to start with `Example_` except for the `dll` and `lib` examples

### Removed

-   `KSockets`
-   Redundant code from `KDataStream::CopyFromBuffer`
-   Unused variables in `VaiableDatum.cpp`

### Fixed

-   Bug in `EntityType::ReadFromTokenisedString` where the string being passed was unexpectedly changed by the `strtok` function
-   Bug in `Point_Object_State_PDU` where the final padding field had not been included
-   Bug in `GetEnumAsStringEmitterName` where some values were not sorted correctly
-   Bug when using `bitset` in `MS Visual Studio 2010`

## 2.0.1 - 2010-09-01

### Added

-   `SetSupplies` function to `Resupply_Received_PDU`

### Changed

-   Code refactor. Removed unnecessary `using namespace` statements and replaced with `using` statements to allow for _Intelisense_ to correctly display the contents of a namespace
-   Moved `EMITTER_BEAM_SIZE`, `EMITTER_SYSTEM_SIZE`, `OBJECT_TYPE_SIZE`, `POINT_OBJECT_APPEARANCE_SIZE`, and `SUPPLIES_SIZE` to class scope
-   `ENTITY_DESTINATION_RECORD`, `GROUP_DESTINATION_RECORD`, `GROUP_ASSIGNMENT_RECORD` from a macro to `static const KUINT16`
-   Rename `ENTITY_DESTINATION_RECORD`, `GROUP_DESTINATION_RECORD`, and `GROUP_ASSIGNMENT_RECORD` to `[NAME]_SIZE`
-   Moved `GEDItem`, `GEDList`, `GridAxisDescriptor`, `GridDataPtr`, `EnvironmentRecordPtr`, and `EnvironmentRecordLst` from `PDU` namespace to `DATA_TYPE`

### Fixed

-   Minor typos

## 2.0.0 - 2010-08-31

### Added

-   All `DIS 6` (_IEEE 1278.1a_) PDUs
-   `TSPI_PDU` PDU
-   `Appearance_PDU` PDU
-   `Articulated_Parts_PDU` PDU
-   `LE_Fire_PDU` PDU
-   `LE_Detonation_PDU` PDU
-   Missing PDUs in `PDU_Factory`

### Changed

-   `GetAsString` functions to improve formatting

### Fixed

-   Bug in point, linear and areal appearance classes. The endian was not being swapped when encoding/decoding
-   Bug in `Entity_State_Update_PDU` decode function
-   Bug in `DecimalToDMS` when passing negative values

## 1.16.0 - 2010-06-28

### Added

-   `Minefield_Query_PDU` PDU
-   `Minefield_Data_PDU` PDU
-   `Minefield_Response_NACK_PDU` PDU
-   Missing PDUs in `PDU_Factory`
-   Clear functions to some of the variable fields

### Changed

-   Postfix `d` for debug `lib` and `dll` example binaries. The postfix value can be changed via `CMake` variable `CMAKE_DEBUG_POSTFIX`
-   Entity state pdu throw exception if `InitDeadReckoning` is not called before `ApplyDeadReckoning`
-   All `GetAsString<Enum Name>` functions of `EnumMinefield` to use the optimized `GetAsString` function instead of the old linear search algorithm

### Fixed

-   Bug in `VariableDatum` decode where the datum value vector was not being cleared on each decode
-   `Minefield_Header` protocol family and version were not being set
-   Bug in `CreateTokenisedString` where the extra value was not being added to the string
-   Functions `GetEnumAsString<Enum Name>` for all minefield enums were not correctly defined
-   Invalid values (over 135) for `PDUType` enum. This affected linear, object and point state PDU from the `Synthetic_Environment` family
-   Bug in `LinearObjectAppearance` and `ArealObjectAppearance` encode and decode functions where 1 extra octet was being encoded/decoded
-   Typo from `SIMULATION_IDENTIFER_SIZE` to `SIMULATION_IDENTIFIER_SIZE`
-   Bug in `SpecificAppearance::GetAsString` was using `Kind` value instead of `Domain` (thanks David)
-   Bug in minefield state pdu where the PDU type was incorrect
-   Bug in `RecordSet::SetRecordValues` where the length was incorrect

## 1.15.1 - 2010-05-17

### Fixed

-   PDU length in `Minefield_State_PDU`
-   Bug in `MinefieldAppearance` where the struct and union were in wrong order

## 1.15.0 - 2010-05-11

### Added

-   `Areal_Object_State_PDU` PDU
-   `Minefield_State_PDU` PDU
-   Change kind value of `EnvironmentType`
-   Filters to `PDU_Factory`. It is now possible to filter what PDU get through
-   Missing PDUs in `PDU_Factory`
-   `PDU_Factory` filter examples
-   `ReadFromTokenisedString` and `CreateTokenisedString` to `EntityType`. This allows for a tokenized string (such as `csv`) to be parsed into the entity type
-   Improved timestamps automatic calculation to include milliseconds for Windows and Linux
-   Additional operator overloads to `Vector`, `EulerAngles`, and `WorldCoordinates`

### Changed

-   All PDU size macros have been moved into the relevant classes namespace with `public` attribute and type changed to `static const KUINT32`
-   Renamed `GENERAL_APPEARANCE__SIZE` to `GENERAL_APPEARANCE_SIZE`
-   All entity specific appearance classes to invert/negate the _Entity State Active_ value. In this case the `DIS` standard actually states that `0` indicates the state `true` and `1` the state `false`
-   Dead reckoning is no longer done through static functions. Each entity must have a dead reckoning calculator class to perform the dead reckoning correctly

### Removed

-   `GED_BasicFixedWingAircraftt`

### Fixed

-   PDU length in `Linear_Object_State_PDU::SetLinearSegmentParameters`
-   Bug in all `EnvironmentRecords` where the length value should not include the length of the `EnvironmentRecord` header
-   `CMake` bug that caused example `Environmental_Process_PDU` to only be included in `DIS 7`; should have been `DI 6` and `DIS 7`
-   Mismatch between entity location and world location in `Detonation_PDU` constructor
-   Typo `m_EntiyCapabilities` in `Entity_State_PDU`
-   Public accessibility on Param Type Variant union in `ArticulationParameters`

## 1.14.0 - 2010-03-17

### Added

-   `Linear_Object_State_PDU` PDU

### Changed

-   PDU factory example avoid closing on PDU exceptions. It now prints the error and continues

### Fixed

-   Bug in `AggregateMarking` encode and decode functions 1 octet offset causing problems with Aggregate State PDU's
-   Bug in `EncodingScheme` when compiling to Linux. This change was reported in `1.13.0` but not included

## 1.13.0 - 2010-02-26

### Added

-   `Point_Object_State_PDU` PDU
-   `EulerToHeadingPitchRoll` conversion to `KConversions.h`
-   `SetTimeStampAutoCalculate`, `IsTimeStampAutoCalculate`, and `CalculateTimeStamp` to `TimeStamp`. Attempts to automatically calculate the timestamp when the encode function is called

### Changed

-   Renamed variables of `HeadingPitchRollToEuler` from `EulX`, `EulY`, and `EulZ` to `Psi`, `Theta`, and `Phi`
-   `Entity_State_PDU` and `Environmental_Process_PDU` examples to use the new automatic timestamp calculation

### Fixed

-   Bug in `HeadingPitchRollToEuler` conversion
-   Typo from `Entity_Infomation_Interaction` to `Entity_Information_Interaction`
-   Bug in `EncodingScheme` when compiling to Linux

## 1.12.1 - 2009-12-16

### Added

-   `Gridded_Data_PDU` new constructor

### Changed

-   `EntityIdentifier` and `AggregateIdentifier` derive from `SimulationIdentifier`
-   `VariableDatum` to pass `const KString` references (thanks Anthony)
-   `SimulationIdentifier` function `GetAsString` write _Object_ instead of _Entity_

### Fixed

-   Bug in `Gridded_Data_PDU` where `GRIDDED_DATA_PDU_SIZE` was incorrectly set to `32` instead of `64`
-   Bug where all protected PDU status member variables belonging to the `Header` class to become `public`. Caused by using anonymous unions
-   Compilation error _Compiler Error C2635_ when casting from `Header` to a derived class. Caused by `virtual` inheritance

## 1.12.0 - 2009-11-23

### Added

-   `Gridded_Data_PDU` PDU
-   Missing PDUs in `PDU_Factory`

### Changed

-   All `GetEnumAsString` functions use a single optimized search function
-   Renamed `Send` example to `Entity_State_PDU`

### Fixed

-   Bugs in some `GetEnumAsString` functions
-   Bug in `Intercom_Control_PDU::GetAsString` and `Intercom_Control_PDU::Encode` iterators
-   Incorrect `null` termination text in `EntityMarking` (thanks Anthony)

## 1.11.1 - 2009-09-21

### Added

-   Macro to `PDUStatusTEILVC` to only include if `DIS 7`

### Removed

-   Obsolete files (`BoundSphere.h` and `BoundSphere.cpp`) in `DataTypes` directory

### Fixed

-   `CMake` not includes `Environmental_Process_PDU` when `DIS 5` is defined
-   Bug in `Radio_Communications_Header` where `DIS 7` macros are not defined in the correct place
-   Bug in `LineRecord2` and `PointRecord2` where the comparison operator would cause an infinite loop

## 1.11.0 - 2009-09-16

### Added

-   `Environmental_Process_PDU` PDU
-   `Environmental_Process_PDU` example
-   `DecimalToDMS` and `DMSTODecimal` to `KConversions.h`
-   Initial support for `DIS` version `7`. `DIS` version can be specified via `CMake` or pre-processor definitions
-   `PDUStatus` in `Header` (`DIS 7`). `PDUStatus` includes getters and setters for `PDUStatusTransferredEntityIndicator` and `PDUStatusLVCIndicator` to `Entity_State_PDU`, `Electromagnetic_Emission_PDU`, `Designator_PDU`, `Radio_Communications_Header`, `IFF_ATC_NAVAIDS_PDU`, `Electromagnetic_Emission_PDU`, and `Entity_State_Update_PDU`. Getter and setters for `PDUStatusFireType` to `Fire_PDU`. Getter and setter for `PDUStatusDetonationType` to `Detonation_PDU`. Getter and setter for `PDUStatusAttachedIndicator` to `Transmitter_PDU`, `Signal_PDU`, `Receiver_PDU`, `Intercom_System_PDU`, and `Intercom_Control_PDU`
-   `SetWritePosition` and `GetWritePosition` functions to `KDataStream` allowing data "peaking"
-   Missing PDUs in `PDU_Factory`
-   `KException` new constructor allowing for more details to be added

### Changed

-   `Send` example uses a while loop to continuously send the PDU. Some applications do not always pick up the first PDU

### Fixed

-   Some of the `Vector` operators would return the referenced objects and not the new copy of the object. This effected operators `*`, `+` and `-` (thanks Michael)
-   Typo in `VariableDatum::GetAsString()` function. "Fixed Datum:" should have been "Variable Datum:"
-   Timer in `Logger` playback is not started until the log is fully loaded

## 1.10.0 - 2009-08-08

### Added

-   `Dead Reckoning` implementation in class `DeadReckoningCalculator`. This class calculates dead reckoning transformations for all dead reckoning algorithms. This feature is currently in `BETA` until all algorithms are verified to work correctly
-   `<` operator to `EntityType`, `AggregateType`, `AggregateIdentifier`, and `ClockTime`
-   `*`, `+`, `+=`, `-`, `-=`, and `[]` operators to `EulerAngles`, `WorldCoordinates`, and `Vector`
-   `ApplyDeadReckoning` function to `Entity_State_PDU`

### Changed

-   Namespaces are no longer global when included in a KDIS header. This prevents KDIS from conflicting with other class/struct/enums that have the same name

## 1.9.2 - 2009-07-30

### Added

-   Missing destructor implementation to `Action_Response_R_PDU`
-   `virtual` to all destructors to it is called even when a base pointer is deleted
-   `==` and `!=` operators to all data types and PDUs
-   `<` operator to `EntityIdentifier`, and `TimeStamp`
-   More comments

### Fixed

-   Incorrect namespace references in function comments

## 1.9.1 - 2009-07-26

### Added

-   Additional comments to several PDUs to help further explain each field
-   `GetEnumAsString<Enum Name>(KINT32 Value)` function to all enumerations. These functions return the string value for an enumeration (`99` -> `"Value"`). It can be enabled/disabled by declaring the macro `KDIS_USE_ENUM_DESCRIPTORS` in the pre-processor definitions or in `KDefines.h` file. This feature makes the library significantly larger: disable if not used. When disabled the `GetEnumAsString<Enum Name>` functions return the enumerated value as a string (`99` -> `"99"`).
-   Website based on `MediaWiki` available at <https://sourceforge.net/p/kdis/wiki/Main_Page>

### Changed

-   Moved remaining enumerations from `KDISEnums.h` to `EnumEntityInfoInteraction.h`
-   Replaced all uses of `strnset` with `memset`
-   Default constructor initialize all data types to zero (if not already)
-   `Send` example shows how to correctly use the timestamp

### Removed

-   Self-explanatory comments to several PDUs
-   `vc2008.zip` file

### Fixed

-   Bug in `FixedDatum` where `KDIS_EXPORT` is defined inside the template functions causing problem if compiling as a DLL shared library

## 1.9.0 - 2009-07-06

### Added

-   `IsGroupOf_PDU` PDU
-   `IsPartOf_PDU` PDU
-   `MAX_PDU_SIZE` of `8192` from `1278.1-200X` standard
-   `KRef_Ptr` class. This is an implementation of referenced pointer, designed to prevent memory leaks where memory needs to be dynamically allocated
-   `HeadingPitchRollToEuler` to `KConversions.h`

### Changed

-   Country Type in `EntityType` constructor from `KUINT8` to `KUINT16`

### Removed

-   `using namespace std` directives from header files to prevent `std` attributes being exposed in the global namespace causing potential clashes

### Fixed

-   Some catch blocks catch all exception types rather than just `KException`

## 1.8.2 - 2009-05-26

### Changed

-   `Linux` support (thanks Anthony)
-   Reference from `UINT16` to `KUINT16`
-   From `sizeof DataType` to `sizeof(DataType)`
-   `#include` use forward slash (`/`) instead of back slash (`\`)
-   `#include` match the case of the file name
-   `#include` added `./` to all relative paths

### Removed

-   Additonal `IntercomCommunicationsParameter` includes from `CMake` file
-   Reference to `winsock2.h` in `KEncoderDecoders`

### Fixed

-   `DIS_Logger_Record.cpp` throw qualifier missing on `writeToFile` function
-   Bug in `SystemIdentifier` where the union and struct were in the wrong order

## 1.8.1 - 2009-05-25

### Fixed

-   Bug in `SwapBytes` that caused the endian to not be correctly swapped

## 1.8.0 - 2009-05-13

### Added

-   `Record_R_PDU` PDU
-   `Record_Query_R_PDU` PDU
-   `Set_Record_R_PDU` PDU

### Removed

-   `RecordSpecification` data type. Record Sets are now placed directly into a PDU. When a change is made to a `RecordSpecification` parameter it was not always possible to update the PDU size. Removing `RecordSpecification` fixes this problem. This only effects `Transfer_Control_PDU`

### Fixed

-   Bug in `FixedDatum` that caused template functions to give linker errors due implementation in source file instead of header file

## 1.7.0 - 2009-05-11

### Added

-   `Data_Query_R_PDU` PDU
-   `Set_Data_R_PDU` PDU
-   `Data_R_PDU` PDU
-   `Event_Report_R_PDU` PDU
-   `Set_Data_PDU` new constructor
-   `Data_Query_PDU` new constructor
-   `Set_Data_PDU` new constructor
-   `Event_Report_PDU` new constructor
-   `PDU_Factory` support for all PDUs
-   Comments to existing PDU's to further explain their usage

### Changed

-   `Data_PDU` constructor from `(KUINT32 RequestID)` to `(const EntityIdentifier, OriginatingEntityID)`, and `(const EntityIdentifier, ReceivingEntityID, KUINT32 RequestID)`
-   `Action_Request_PDU` changed constructor from `(KUINT32 RequestID, KUINT32 ActionID)` to `(const EntityIdentifier, OriginatingEntityID)`, `(const EntityIdentifier, ReceivingEntityID)`, and `(KUINT32 RequestID, KUINT32 ActionID)`

### Fixed

-   Duplicate includes in `CMake` file
-   Missing `Intercom_Control_PDU` entry

## 1.6.0 - 2009-03-30

### Added

-   `Transfer_Control_Request_PDU` PDU
-   `Create_Entity_R_PDU` PDU
-   `Remove_Entity_R_PDU` PDU
-   `Start_Resume_R_PDU` PDU
-   `Stop_Freeze_R_PDU` PDU
-   `Acknowledge_R_PDU` PDU
-   `Action_Request_R_PDU` PDU
-   `Action_Response_R_PDU` PDU
-   `Comment_R_PDU` PDU
-   `IFF_ATC_NAVAIDS_L2_PDU` PDU missing fundamental parts
-   Added additional enumeration values taken from `SISO-REF-010 Changes`
-   `Start_Resume_PDU` new constructors
-   `Stop_Freeze_R_PDU` new constructors
-   `Electromagnetic_Emission_PDU` two new constructors
-   `IFF_ATC_NAVAIDS_L1_PDU ` new constructor

### Changed

-   Moved all enumerations that belong to Entity Info/Interaction into `EnumEntityInfoInteraction.h`
-   Moved all enumerations that belong to Simulation Management Info/Interaction into `EnumSimulationManagement.h`
-   `DatumID` enumerations are now appended with `Record` instead of `Datum`
-   All PDU automatically set the Protocol Version

### Removed

-   `KDIS_NEWORK_ENDIAN` from `KDefines.h`
-   Removed line in `Example_Send` that sets the Protocol Family as this is now done automatically in the constructor

### Fixed

-   Bug in `GetData` function of `Signal_PDU`
-   Bug in `Decode` function of `Create_Entity_PDU`
-   Bug in `CMakeLists.txt` where file `Entity_State_Update_PDU.h` was not being included
-   Bug in `Simulation_Management_Header` constructor where protocol family is not set
-   Bug in `SEES` constructor where protocol family is not set

## 1.5.4 - 2009-03-12

### Fixed

-   Bug in `GetData` function of `Signal_PDU`

## 1.5.3 - 2009-03-11

### Added

-   Interface in `VariableDatum` for setting an arbitrary binary stream

### Fixed

-   `VariableDatum` encoding and decoding
-   `VariableDatum` bits/bytes mix up
-   Typos in comments
-   Because of needless `Microsoft Word` garbage, the changelog has been rewritten

## 1.5.2 - 2009-03-04

### Fixed

-   `Comment_PDU` constructor where the PDU type and length were not initialized
-   `DESIGNATOR_PDU_SIZE` was incorrect, should be `88`, due to a typo in the `IEEE` standard
-   `EncodingScheme` bits were incorrect on Big Endian machines

## 1.5.1 - 2009-03-02

### Added

-   Support for `DIS` version `5` in `PDU_Factory `

### Fixed

-   `FuseType` enumeration has previously incorrect values
-   `CMake` bugs when building with `DIS` version `5`

## 1.5.0 - 2009-02-20

### Added

-   `Intercom_Control_PDU` PDU
-   `Aggregate_State_PDU` PDU
-   `KDIS_LIB` (static library) and `KDIS_DLL` (shared library) examples
-   [`CMake`](https://cmake.org) which is a cross-platform, open-source build system. The `CMake` file has certain options that allow to specify the version of `DIS` to use (`5` or `6`) and if to link against a `static` or `shared` library. Any future examples will require the use of `CMake`

### Changed

-   `KDataStream` only accepts `KUINT16` rather than `KUINT32`, which could have resulted in various buffer overrun problems
-   `KDIS_EXPORT` macro now searches the project for preproccesor deflagrate. Use either `EXPORT_KDIS` or `IMPORT_KDIS`. _E.g: `/D "EXPORT_KDIS"`_

## 1.4.0 - 2009-02-05

### Added

-   `Intercom_Signal_PDU` PDU
-   `DIS_Logger_Record` and `DIS_Logger_Playback`, which logs PDUs to a text file so that they can be replayed, have been added to `Extras`
-   `DIS_Logger_Record` and `DIS_Logger_Playback` examples. Included captured data is generated by `MAK VR-Forces 3.10`
-   `GetAsString` and `ReadFromString` functions to `KDataStream`. `GetAsString` converts the data stream into a hex string, whereas `ReadFromString` converts the string into a `KDataStream`. These two functions allow DIS data to be logged to a file and viewed at a later time

## 1.3.1 - 2009-01-30

### Removed

-   References to the incomplete `Intercom_Signal_PDU` from `PDU_Factory`, which should not have been accessible

## 1.3.0 - 2009-01-24

### Fixed

-   Bugs in `Signal_PDU` where `SetData` did not set the `DataSize` and `GetData` was returning the padding that was added to the data
-   Bug in `Entity_State_PDU` where `EntityAppearance` was being encoded incorrectly
-   Typo in `SurfacePlatformAppearance::GetAsString` from _Space Platform Appearance_ instead of _Surface Platform Appearance_

## 1.2.0 - 2008-12-21

### Added

-   `Collision_Elastic_PDU` PDU
-   `Entity_State_Update_PDU` PDU
-   `FF_ATC_NAVAIDS_PDU` PDU
-   Class `PDU_Factory` that converts a data stream into the correct PDU and returns an `auto_ptr` to the new PDU
-   Example to show how to use `PDU_Factory`
-   Namespace `UTILS`
-   `KConversions.h`, which includes `RadToDeg`, `DegToRad`, `MetersToFeet`, `FeetToMeters`, and `GeodeticToGeocentric`, has been added to `UTILS`
-   `DIS` version a PDU belongs to in the header comments

### Changed

-   All `GetFunctions` that previously returned an object now return a reference/const reference
-   All examples have been integrated into a single directory
-   All examples now use an updated version of `KSOCKETS`. However, it is still recommended to use your own socket library
-   Renamed `Electronmagnetic_Emission_PDU` to `Electromagnetic_Emission_PDU`
-   Licence from `GPL` to `LGPL`
-   Changelog in HTML format
-   `IsMachineBigEndian` use static variables providing a very small performance boost

### Removed

-   `#ifdef _win32` for primitive data types in `KDefines.h` that was prevented any other OS from working

### Fixed

-   Bug in `Comment_PDU` where the PDU length was incorrect while reading variable datum lengths since the returned variable datum lengths value was in bits

## 1.1.1 - 2008-10-28

### Added

-   `vc9` send example

## 1.1.0 - 2008-10-27

### Added

-   `AntennaLocation` new constructor
-   `BurstDescriptor` new constructor
-   `DeadReckoningParameter`new constructor
-   `EmissionSystem` new constructor
-   `EmitterBeam` new constructor
-   `EncodingScheme` 2 new constructors
-   `GeneralAppearance` new constructor
-   `TimeStamp` new constructor
-   `Entity_State_PDU` new constructor
-   `Collision_PDU` new constructor
-   `Repair_Complete_PDU` new constructor
-   `Repair_Response_PDU` new constructor
-   `Radio_Communications_Header` new constructor
-   `Receiver_PDU` new constructor
-   `Signal_PDU` new constructor
-   `Transmitter_PDU` new constructor
-   `Acknowledge_PDU` new constructors to auto generate a response depending on the PDU

### Changed

-   `BurstDescriptor` function `SetMunition` pass by reference
-   `DeadReckoningParameter` function `setDeadReckoningAlgorithm` pass by value
-   Renamed `m_ui16Fire` to `m_ui16Fuse`

### Removed

-   `EmitterBeam` removed typing error in `Set6BeamParamIndex` and `Get6BeamParamIndex`

### Fixed

-   Bug in `vc9` example that checked for `Data_PDU` instead of `Entity_State_PDU`

## 1.0.1 - 2008-10-24

### Changed

-   `Signal_PDU` data length is number of bits instead of octets
