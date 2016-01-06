#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/DataTypes/AcousticEmitterSystem.h"
#include "KDIS/DataTypes/AggregateIdentifier.h"
#include "KDIS/DataTypes/AggregateMarking.h"
#include "KDIS/DataTypes/AggregateType.h"
#include "KDIS/DataTypes/AntennaLocation.h"
#include "KDIS/DataTypes/APA.h"
#include "KDIS/DataTypes/ArealObjectAppearance.h"
#include "KDIS/DataTypes/ArticulatedPart.h"
#include "KDIS/DataTypes/AttachedPart.h"
#include "KDIS/DataTypes/AttributeRecordSet.h"
#include "KDIS/DataTypes/BeamData.h"
#include "KDIS/DataTypes/BoundingSphereRecord.h"
#include "KDIS/DataTypes/ClockTime.h"
#include "KDIS/DataTypes/COMBICState.h"
#include "KDIS/DataTypes/CommunicationsChannelType.h"
#include "KDIS/DataTypes/CommunicationsNodeID.h"
#include "KDIS/DataTypes/ConeRecord1.h"
#include "KDIS/DataTypes/ConeRecord2.h"
#include "KDIS/DataTypes/CryptoSystem.h"
#include "KDIS/DataTypes/DeadReckoningParameter.h"
#include "KDIS/DataTypes/DEAreaAimpoint.h"
#include "KDIS/DataTypes/Descriptor.h"
#include "KDIS/DataTypes/EllipsoidRecord1.h"
#include "KDIS/DataTypes/EllipsoidRecord2.h"
#include "KDIS/DataTypes/EmissionSystem.h"
#include "KDIS/DataTypes/EmitterBeam.h"
#include "KDIS/DataTypes/EmitterSystem.h"
#include "KDIS/DataTypes/EncodingScheme.h"
#include "KDIS/DataTypes/EnhancedMode1Code.h"
#include "KDIS/DataTypes/EntityAppearance.h"
#include "KDIS/DataTypes/EntityCapabilities.h"
#include "KDIS/DataTypes/EntityDestinationRecord.h"
#include "KDIS/DataTypes/EntityIdentifier.h"
#include "KDIS/DataTypes/EntityMarking.h"
#include "KDIS/DataTypes/EntityType.h"
#include "KDIS/DataTypes/EnvironmentType.h"
#include "KDIS/DataTypes/EulerAngles.h"
#include "KDIS/DataTypes/ExplosionDescriptor.h"
#include "KDIS/DataTypes/FixedDatum.h"
#include "KDIS/DataTypes/FlareState.h"
#include "KDIS/DataTypes/FundamentalOperationalData.h"
#include "KDIS/DataTypes/FundamentalParameterData.h"
#include "KDIS/DataTypes/GaussianPlumeRecord.h"
#include "KDIS/DataTypes/GaussianPuffRecord.h"
#include "KDIS/DataTypes/GED_BasicFixedWingAircraft.h"
#include "KDIS/DataTypes/GED_BasicGroundCombatSoldier.h"
#include "KDIS/DataTypes/GED_BasicGroundCombatVehicle.h"
#include "KDIS/DataTypes/GED_BasicRotorWingAircraft.h"
#include "KDIS/DataTypes/GED_EnhancedFixedWingAircraft.h"
#include "KDIS/DataTypes/GED_EnhancedGroundCombatSoldier.h"
#include "KDIS/DataTypes/GED_EnhancedGroundCombatVehicle.h"
#include "KDIS/DataTypes/GED_EnhancedRotaryWingAircraft.h"
#include "KDIS/DataTypes/GED_GroundLogisticsVehicle.h"
#include "KDIS/DataTypes/GridAxisIrregular.h"
#include "KDIS/DataTypes/GridAxisRegular.h"
#include "KDIS/DataTypes/GridDataType0.h"
#include "KDIS/DataTypes/GridDataType1.h"
#include "KDIS/DataTypes/GridDataType2.h"
#include "KDIS/DataTypes/GroupAssignmentRecord.h"
#include "KDIS/DataTypes/GroupDestinationRecord.h"
#include "KDIS/DataTypes/IFF_ATC_NAVAIDS_FundamentalParameterData.h"
#include "KDIS/DataTypes/IFF_Layer2.h"
#include "KDIS/DataTypes/IFF_Layer3.h"
#include "KDIS/DataTypes/IFF_Layer3Interrogator.h"
#include "KDIS/DataTypes/IFF_Layer3Transponder.h"
#include "KDIS/DataTypes/IntercomCommunicationParameters.h"
#include "KDIS/DataTypes/IOCommunicationsNode.h"
#include "KDIS/DataTypes/IOEffect.h"
#include "KDIS/DataTypes/LayerHeader.h"
#include "KDIS/DataTypes/LE_DeadReckoningParameter.h"
#include "KDIS/DataTypes/LE_EntityIdentifier.h"
#include "KDIS/DataTypes/LE_EulerAngles.h"
#include "KDIS/DataTypes/LinearObjectAppearance.h"
#include "KDIS/DataTypes/LinearSegmentParameter.h"
#include "KDIS/DataTypes/LineRecord1.h"
#include "KDIS/DataTypes/LineRecord2.h"
#include "KDIS/DataTypes/MinefieldAppearance.h"
#include "KDIS/DataTypes/MinefieldDataFilter.h"
#include "KDIS/DataTypes/MineFusing.h"
#include "KDIS/DataTypes/MinePaintScheme.h"
#include "KDIS/DataTypes/Mode5InterrogatorBasicData.h"
#include "KDIS/DataTypes/Mode5InterrogatorStatus.h"
#include "KDIS/DataTypes/Mode5TransponderBasicData.h"
#include "KDIS/DataTypes/Mode5TransponderStatus.h"
#include "KDIS/DataTypes/Mode5TransponderSupplementalData.h"
#include "KDIS/DataTypes/ModeXCodeRecord.h"
#include "KDIS/DataTypes/ModulationType.h"
#include "KDIS/DataTypes/MunitionDescriptor.h"
#include "KDIS/DataTypes/NamedLocationIdentifier.h"
#include "KDIS/DataTypes/ObjectAppearance.h"
#include "KDIS/DataTypes/ObjectType.h"
#include "KDIS/DataTypes/OrientationError.h"
#include "KDIS/DataTypes/PerimeterPointCoordinate.h"
#include "KDIS/DataTypes/PointObjectAppearance.h"
#include "KDIS/DataTypes/PointRecord1.h"
#include "KDIS/DataTypes/PointRecord2.h"
#include "KDIS/DataTypes/PositionError.h"
#include "KDIS/DataTypes/PropulsionSystem.h"
#include "KDIS/DataTypes/RadioEntityType.h"
#include "KDIS/DataTypes/RecordSet.h"
#include "KDIS/DataTypes/RectangularVolumeRecord1.h"
#include "KDIS/DataTypes/RectangularVolumeRecord2.h"
#include "KDIS/DataTypes/RectangularVolumeRecord3.h"
#include "KDIS/DataTypes/RelationshipRecord.h"
#include "KDIS/DataTypes/RelativeWorldCoordinates.h"
#include "KDIS/DataTypes/SecondaryOperationalData.h"
#include "KDIS/DataTypes/Shaft.h"
#include "KDIS/DataTypes/SilentAggregateSystem.h"
#include "KDIS/DataTypes/SilentEntitySystem.h"
#include "KDIS/DataTypes/SimulationIdentifier.h"
#include "KDIS/DataTypes/SphereRecord1.h"
#include "KDIS/DataTypes/SphereRecord2.h"
#include "KDIS/DataTypes/StandardVariable.h"
#include "KDIS/DataTypes/Supplies.h"
#include "KDIS/DataTypes/SystemIdentifier.h"
#include "KDIS/DataTypes/TimeStamp.h"
#include "KDIS/DataTypes/TrackJamTargetIdentifier.h"
#include "KDIS/DataTypes/UnderwaterAcousticEmitterBeam.h"
#include "KDIS/DataTypes/UnderwaterAcousticEmitterSystem.h"
#include "KDIS/DataTypes/UnderwaterAcousticFundamentalParameterData.h"
#include "KDIS/DataTypes/VariableDatum.h"
#include "KDIS/DataTypes/VariableParameter.h"
#include "KDIS/DataTypes/Vector.h"
#include "KDIS/DataTypes/VectoringNozzleSystem.h"
#include "KDIS/DataTypes/WorldCoordinates.h"

using namespace KDIS;
using namespace DATA_TYPE;

TEST(DataType_EncodeDecode, AcousticEmitterSystem)
{
	AcousticEmitterSystem dtIn;
	KDataStream stream = dtIn.Encode();
	AcousticEmitterSystem dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, AggregateIdentifier)
{
	AggregateIdentifier dtIn;
	KDataStream stream = dtIn.Encode();
	AggregateIdentifier dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, AggregateMarking)
{
	AggregateMarking dtIn;
	KDataStream stream = dtIn.Encode();
	AggregateMarking dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, AggregateType)
{
	AggregateType dtIn;
	KDataStream stream = dtIn.Encode();
	AggregateType dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, AntennaLocation)
{
	AntennaLocation dtIn;
	KDataStream stream = dtIn.Encode();
	AntennaLocation dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, APA)
{
	APA dtIn;
	KDataStream stream = dtIn.Encode();
	APA dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ArealObjectAppearance)
{
	ArealObjectAppearance dtIn;
	KDataStream stream = dtIn.Encode();
	ArealObjectAppearance dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ArticulatedPart)
{
	ArticulatedPart dtIn;
	KDataStream stream = dtIn.Encode();
	ArticulatedPart dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, AttachedPart)
{
	AttachedPart dtIn;
	KDataStream stream = dtIn.Encode();
	AttachedPart dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, AttributeRecordSet)
{
	AttributeRecordSet dtIn;
	KDataStream stream = dtIn.Encode();
	AttributeRecordSet dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, BeamData)
{
	BeamData dtIn;
	KDataStream stream = dtIn.Encode();
	BeamData dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, BoundingSphereRecord)
{
	BoundingSphereRecord dtIn;
	KDataStream stream = dtIn.Encode();
	BoundingSphereRecord dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ClockTime)
{
	ClockTime dtIn;
	KDataStream stream = dtIn.Encode();
	ClockTime dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, COMBICState)
{
	COMBICState dtIn;
	KDataStream stream = dtIn.Encode();
	COMBICState dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, CommunicationsChannelType)
{
	CommunicationsChannelType dtIn;
	KDataStream stream = dtIn.Encode();
	CommunicationsChannelType dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, CommunicationsNodeID)
{
	CommunicationsNodeID dtIn;
	KDataStream stream = dtIn.Encode();
	CommunicationsNodeID dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ConeRecord1)
{
	ConeRecord1 dtIn;
	KDataStream stream = dtIn.Encode();
	ConeRecord1 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ConeRecord2)
{
	ConeRecord2 dtIn;
	KDataStream stream = dtIn.Encode();
	ConeRecord2 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, CryptoSystem)
{
	CryptoSystem dtIn;
	KDataStream stream = dtIn.Encode();
	CryptoSystem dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, DeadReckoningParameter)
{
	DeadReckoningParameter dtIn;
	KDataStream stream = dtIn.Encode();
	DeadReckoningParameter dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, DEAreaAimpoint)
{
	DEAreaAimpoint dtIn;
	KDataStream stream = dtIn.Encode();
	DEAreaAimpoint dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, Descriptor)
{
	Descriptor dtIn;
	KDataStream stream = dtIn.Encode();
	Descriptor dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EllipsoidRecord1)
{
	EllipsoidRecord1 dtIn;
	KDataStream stream = dtIn.Encode();
	EllipsoidRecord1 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EllipsoidRecord2)
{
	EllipsoidRecord2 dtIn;
	KDataStream stream = dtIn.Encode();
	EllipsoidRecord2 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EmissionSystem)
{
	EmissionSystem dtIn;
	KDataStream stream = dtIn.Encode();
	EmissionSystem dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EmitterBeam)
{
	EmitterBeam dtIn;
	KDataStream stream = dtIn.Encode();
	EmitterBeam dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EmitterSystem)
{
	EmitterSystem dtIn;
	KDataStream stream = dtIn.Encode();
	EmitterSystem dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EncodingScheme)
{
	EncodingScheme dtIn;
	KDataStream stream = dtIn.Encode();
	EncodingScheme dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EnhancedMode1Code)
{
	EnhancedMode1Code dtIn;
	KDataStream stream = dtIn.Encode();
	EnhancedMode1Code dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EntityAppearance)
{
	EntityAppearance dtIn;
	KDataStream stream = dtIn.Encode();
	EntityAppearance dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EntityCapabilities)
{
	EntityCapabilities dtIn;
	KDataStream stream = dtIn.Encode();
	EntityCapabilities dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EntityDestinationRecord)
{
	EntityDestinationRecord dtIn;
	KDataStream stream = dtIn.Encode();
	EntityDestinationRecord dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EntityIdentifier)
{
	EntityIdentifier dtIn;
	KDataStream stream = dtIn.Encode();
	EntityIdentifier dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EntityMarking)
{
	EntityMarking dtIn;
	KDataStream stream = dtIn.Encode();
	EntityMarking dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EntityType)
{
	EntityType dtIn;
	KDataStream stream = dtIn.Encode();
	EntityType dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EnvironmentType)
{
	EnvironmentType dtIn;
	KDataStream stream = dtIn.Encode();
	EnvironmentType dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, EulerAngles)
{
	EulerAngles dtIn;
	KDataStream stream = dtIn.Encode();
	EulerAngles dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ExplosionDescriptor)
{
	ExplosionDescriptor dtIn;
	KDataStream stream = dtIn.Encode();
	ExplosionDescriptor dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, FixedDatum)
{
	FixedDatum dtIn;
	KDataStream stream = dtIn.Encode();
	FixedDatum dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, FlareState)
{
	FlareState dtIn;
	KDataStream stream = dtIn.Encode();
	FlareState dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, FundamentalOperationalData)
{
	FundamentalOperationalData dtIn;
	KDataStream stream = dtIn.Encode();
	FundamentalOperationalData dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, FundamentalParameterData)
{
	FundamentalParameterData dtIn;
	KDataStream stream = dtIn.Encode();
	FundamentalParameterData dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GaussianPlumeRecord)
{
	GaussianPlumeRecord dtIn;
	KDataStream stream = dtIn.Encode();
	GaussianPlumeRecord dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GaussianPuffRecord)
{
	GaussianPuffRecord dtIn;
	KDataStream stream = dtIn.Encode();
	GaussianPuffRecord dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GED_BasicFixedWingAircraft)
{
	GED_BasicFixedWingAircraft dtIn;
	KDataStream stream = dtIn.Encode();
	GED_BasicFixedWingAircraft dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GED_BasicGroundCombatSoldier)
{
	GED_BasicGroundCombatSoldier dtIn;
	KDataStream stream = dtIn.Encode();
	GED_BasicGroundCombatSoldier dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GED_BasicGroundCombatVehicle)
{
	GED_BasicGroundCombatVehicle dtIn;
	KDataStream stream = dtIn.Encode();
	GED_BasicGroundCombatVehicle dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GED_BasicRotorWingAircraft)
{
	GED_BasicRotorWingAircraft dtIn;
	KDataStream stream = dtIn.Encode();
	GED_BasicRotorWingAircraft dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GED_EnhancedFixedWingAircraft)
{
	GED_EnhancedFixedWingAircraft dtIn;
	KDataStream stream = dtIn.Encode();
	GED_EnhancedFixedWingAircraft dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GED_EnhancedGroundCombatSoldier)
{
	GED_EnhancedGroundCombatSoldier dtIn;
	KDataStream stream = dtIn.Encode();
	GED_EnhancedGroundCombatSoldier dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GED_EnhancedGroundCombatVehicle)
{
	GED_EnhancedGroundCombatVehicle dtIn;
	KDataStream stream = dtIn.Encode();
	GED_EnhancedGroundCombatVehicle dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GED_EnhancedRotaryWingAircraft)
{
	GED_EnhancedRotaryWingAircraft dtIn;
	KDataStream stream = dtIn.Encode();
	GED_EnhancedRotaryWingAircraft dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GED_GroundLogisticsVehicle)
{
	GED_GroundLogisticsVehicle dtIn;
	KDataStream stream = dtIn.Encode();
	GED_GroundLogisticsVehicle dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GridAxisIrregular)
{
	GridAxisIrregular dtIn;
	KDataStream stream = dtIn.Encode();
	GridAxisIrregular dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GridAxisRegular)
{
	GridAxisRegular dtIn;
	KDataStream stream = dtIn.Encode();
	GridAxisRegular dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GridDataType0)
{
	GridDataType0 dtIn;
	KDataStream stream = dtIn.Encode();
	GridDataType0 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GridDataType1)
{
	GridDataType1 dtIn;
	KDataStream stream = dtIn.Encode();
	GridDataType1 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GridDataType2)
{
	GridDataType2 dtIn;
	KDataStream stream = dtIn.Encode();
	GridDataType2 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GroupAssignmentRecord)
{
	GroupAssignmentRecord dtIn;
	KDataStream stream = dtIn.Encode();
	GroupAssignmentRecord dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, GroupDestinationRecord)
{
	GroupDestinationRecord dtIn;
	KDataStream stream = dtIn.Encode();
	GroupDestinationRecord dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, IFF_ATC_NAVAIDS_FundamentalParameterData)
{
	IFF_ATC_NAVAIDS_FundamentalParameterData dtIn;
	KDataStream stream = dtIn.Encode();
	IFF_ATC_NAVAIDS_FundamentalParameterData dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, IFF_Layer2)
{
	IFF_Layer2 dtIn;
	KDataStream stream = dtIn.Encode();
	IFF_Layer2 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, IFF_Layer3)
{
	IFF_Layer3 dtIn;
	KDataStream stream = dtIn.Encode();
	IFF_Layer3 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, IFF_Layer3Interrogator)
{
	IFF_Layer3Interrogator dtIn;
	KDataStream stream = dtIn.Encode();
	IFF_Layer3Interrogator dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, IFF_Layer3Transponder)
{
	IFF_Layer3Transponder dtIn;
	KDataStream stream = dtIn.Encode();
	IFF_Layer3Transponder dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, IntercomCommunicationParameters)
{
	IntercomCommunicationParameters dtIn;
	KDataStream stream = dtIn.Encode();
	IntercomCommunicationParameters dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, IOCommunicationsNode)
{
	IOCommunicationsNode dtIn;
	KDataStream stream = dtIn.Encode();
	IOCommunicationsNode dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, IOEffect)
{
	IOEffect dtIn;
	KDataStream stream = dtIn.Encode();
	IOEffect dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, LayerHeader)
{
	LayerHeader dtIn;
	KDataStream stream = dtIn.Encode();
	LayerHeader dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, LE_DeadReckoningParameter)
{
	LE_DeadReckoningParameter dtIn;
	KDataStream stream = dtIn.Encode();
	LE_DeadReckoningParameter dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, LE_EntityIdentifier)
{
	LE_EntityIdentifier dtIn;
	KDataStream stream = dtIn.Encode();
	LE_EntityIdentifier dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, LE_EulerAngles)
{
	LE_EulerAngles dtIn;
	KDataStream stream = dtIn.Encode();
	LE_EulerAngles dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, LinearObjectAppearance)
{
	LinearObjectAppearance dtIn;
	KDataStream stream = dtIn.Encode();
	LinearObjectAppearance dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, LinearSegmentParameter)
{
	LinearSegmentParameter dtIn;
	KDataStream stream = dtIn.Encode();
	LinearSegmentParameter dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, LineRecord1)
{
	LineRecord1 dtIn;
	KDataStream stream = dtIn.Encode();
	LineRecord1 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, LineRecord2)
{
	LineRecord2 dtIn;
	KDataStream stream = dtIn.Encode();
	LineRecord2 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, MinefieldAppearance)
{
	MinefieldAppearance dtIn;
	KDataStream stream = dtIn.Encode();
	MinefieldAppearance dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, MinefieldDataFilter)
{
	MinefieldDataFilter dtIn;
	KDataStream stream = dtIn.Encode();
	MinefieldDataFilter dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, MineFusing)
{
	MineFusing dtIn;
	KDataStream stream = dtIn.Encode();
	MineFusing dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, MinePaintScheme)
{
	MinePaintScheme dtIn;
	KDataStream stream = dtIn.Encode();
	MinePaintScheme dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, Mode5InterrogatorBasicData)
{
	Mode5InterrogatorBasicData dtIn;
	KDataStream stream = dtIn.Encode();
	Mode5InterrogatorBasicData dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, Mode5InterrogatorStatus)
{
	Mode5InterrogatorStatus dtIn;
	KDataStream stream = dtIn.Encode();
	Mode5InterrogatorStatus dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, Mode5TransponderBasicData)
{
	Mode5TransponderBasicData dtIn;
	KDataStream stream = dtIn.Encode();
	Mode5TransponderBasicData dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, Mode5TransponderStatus)
{
	Mode5TransponderStatus dtIn;
	KDataStream stream = dtIn.Encode();
	Mode5TransponderStatus dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, Mode5TransponderSupplementalData)
{
	Mode5TransponderSupplementalData dtIn;
	KDataStream stream = dtIn.Encode();
	Mode5TransponderSupplementalData dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ModeXCodeRecord)
{
	ModeXCodeRecord dtIn;
	KDataStream stream = dtIn.Encode();
	ModeXCodeRecord dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ModulationType)
{
	ModulationType dtIn;
	KDataStream stream = dtIn.Encode();
	ModulationType dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, MunitionDescriptor)
{
	MunitionDescriptor dtIn;
	KDataStream stream = dtIn.Encode();
	MunitionDescriptor dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, NamedLocationIdentifier)
{
	NamedLocationIdentifier dtIn;
	KDataStream stream = dtIn.Encode();
	NamedLocationIdentifier dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ObjectAppearance)
{
	ObjectAppearance dtIn;
	KDataStream stream = dtIn.Encode();
	ObjectAppearance dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, ObjectType)
{
	ObjectType dtIn;
	KDataStream stream = dtIn.Encode();
	ObjectType dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, OrientationError)
{
	OrientationError dtIn;
	KDataStream stream = dtIn.Encode();
	OrientationError dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, PerimeterPointCoordinate)
{
	PerimeterPointCoordinate dtIn;
	KDataStream stream = dtIn.Encode();
	PerimeterPointCoordinate dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, PointObjectAppearance)
{
	PointObjectAppearance dtIn;
	KDataStream stream = dtIn.Encode();
	PointObjectAppearance dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, PointRecord1)
{
	PointRecord1 dtIn;
	KDataStream stream = dtIn.Encode();
	PointRecord1 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, PointRecord2)
{
	PointRecord2 dtIn;
	KDataStream stream = dtIn.Encode();
	PointRecord2 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, PositionError)
{
	PositionError dtIn;
	KDataStream stream = dtIn.Encode();
	PositionError dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, PropulsionSystem)
{
	PropulsionSystem dtIn;
	KDataStream stream = dtIn.Encode();
	PropulsionSystem dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, RadioEntityType)
{
	RadioEntityType dtIn;
	KDataStream stream = dtIn.Encode();
	RadioEntityType dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, RecordSet)
{
	RecordSet dtIn;
	KDataStream stream = dtIn.Encode();
	RecordSet dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, RectangularVolumeRecord1)
{
	RectangularVolumeRecord1 dtIn;
	KDataStream stream = dtIn.Encode();
	RectangularVolumeRecord1 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, RectangularVolumeRecord2)
{
	RectangularVolumeRecord2 dtIn;
	KDataStream stream = dtIn.Encode();
	RectangularVolumeRecord2 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, RectangularVolumeRecord3)
{
	RectangularVolumeRecord3 dtIn;
	KDataStream stream = dtIn.Encode();
	RectangularVolumeRecord3 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, RelationshipRecord)
{
	RelationshipRecord dtIn;
	KDataStream stream = dtIn.Encode();
	RelationshipRecord dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, RelativeWorldCoordinates)
{
	RelativeWorldCoordinates dtIn;
	KDataStream stream = dtIn.Encode();
	RelativeWorldCoordinates dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, SecondaryOperationalData)
{
	SecondaryOperationalData dtIn;
	KDataStream stream = dtIn.Encode();
	SecondaryOperationalData dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, Shaft)
{
	Shaft dtIn;
	KDataStream stream = dtIn.Encode();
	Shaft dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, SilentAggregateSystem)
{
	SilentAggregateSystem dtIn;
	KDataStream stream = dtIn.Encode();
	SilentAggregateSystem dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, SilentEntitySystem)
{
	SilentEntitySystem dtIn;
	KDataStream stream = dtIn.Encode();
	SilentEntitySystem dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, SimulationIdentifier)
{
	SimulationIdentifier dtIn;
	KDataStream stream = dtIn.Encode();
	SimulationIdentifier dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, SphereRecord1)
{
	SphereRecord1 dtIn;
	KDataStream stream = dtIn.Encode();
	SphereRecord1 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, SphereRecord2)
{
	SphereRecord2 dtIn;
	KDataStream stream = dtIn.Encode();
	SphereRecord2 dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, StandardVariable)
{
	StandardVariable dtIn;
	KDataStream stream = dtIn.Encode();
	StandardVariable dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, Supplies)
{
	Supplies dtIn;
	KDataStream stream = dtIn.Encode();
	Supplies dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, SystemIdentifier)
{
	SystemIdentifier dtIn;
	KDataStream stream = dtIn.Encode();
	SystemIdentifier dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, TimeStamp)
{
	TimeStamp dtIn;
	KDataStream stream = dtIn.Encode();
	TimeStamp dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, TrackJamTargetIdentifier)
{
	TrackJamTargetIdentifier dtIn;
	KDataStream stream = dtIn.Encode();
	TrackJamTargetIdentifier dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, UnderwaterAcousticEmitterBeam)
{
	UnderwaterAcousticEmitterBeam dtIn;
	KDataStream stream = dtIn.Encode();
	UnderwaterAcousticEmitterBeam dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, UnderwaterAcousticEmitterSystem)
{
	UnderwaterAcousticEmitterSystem dtIn;
	KDataStream stream = dtIn.Encode();
	UnderwaterAcousticEmitterSystem dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, UnderwaterAcousticFundamentalParameterData)
{
	UnderwaterAcousticFundamentalParameterData dtIn;
	KDataStream stream = dtIn.Encode();
	UnderwaterAcousticFundamentalParameterData dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, VariableDatum)
{
	VariableDatum dtIn;
	KDataStream stream = dtIn.Encode();
	VariableDatum dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, VariableParameter)
{
	VariableParameter dtIn;
	KDataStream stream = dtIn.Encode();
	VariableParameter dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, Vector)
{
	Vector dtIn;
	KDataStream stream = dtIn.Encode();
	Vector dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, VectoringNozzleSystem)
{
	VectoringNozzleSystem dtIn;
	KDataStream stream = dtIn.Encode();
	VectoringNozzleSystem dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode, WorldCoordinates)
{
	WorldCoordinates dtIn;
	KDataStream stream = dtIn.Encode();
	WorldCoordinates dtOut(stream);
	EXPECT_EQ(dtIn, dtOut);
	EXPECT_EQ(0, stream.GetBufferSize());
}
