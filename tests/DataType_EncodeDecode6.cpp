#include <gtest/gtest.h>

#include <KDIS/DataTypes/APA.hpp>
#include <KDIS/DataTypes/AcousticEmitterSystem.hpp>
#include <KDIS/DataTypes/AggregateIdentifier.hpp>
#include <KDIS/DataTypes/AggregateMarking.hpp>
#include <KDIS/DataTypes/AggregateType.hpp>
#include <KDIS/DataTypes/ArealObjectAppearance.hpp>
#include <KDIS/DataTypes/BeamData.hpp>
#include <KDIS/DataTypes/BoundingSphereRecord.hpp>
#include <KDIS/DataTypes/COMBICState.hpp>
#include <KDIS/DataTypes/CommunicationsChannelType.hpp>
#include <KDIS/DataTypes/ConeRecord1.hpp>
#include <KDIS/DataTypes/ConeRecord2.hpp>
#include <KDIS/DataTypes/EllipsoidRecord1.hpp>
#include <KDIS/DataTypes/EllipsoidRecord2.hpp>
#include <KDIS/DataTypes/EntityDestinationRecord.hpp>
#include <KDIS/DataTypes/EnvironmentType.hpp>
#include <KDIS/DataTypes/FlareState.hpp>
#include <KDIS/DataTypes/FundamentalOperationalData.hpp>
#include <KDIS/DataTypes/GED_BasicFixedWingAircraft.hpp>
#include <KDIS/DataTypes/GED_BasicGroundCombatSoldier.hpp>
#include <KDIS/DataTypes/GED_BasicGroundCombatVehicle.hpp>
#include <KDIS/DataTypes/GED_BasicRotorWingAircraft.hpp>
#include <KDIS/DataTypes/GED_EnhancedFixedWingAircraft.hpp>
#include <KDIS/DataTypes/GED_EnhancedGroundCombatSoldier.hpp>
#include <KDIS/DataTypes/GED_EnhancedGroundCombatVehicle.hpp>
#include <KDIS/DataTypes/GED_EnhancedRotaryWingAircraft.hpp>
#include <KDIS/DataTypes/GED_GroundLogisticsVehicle.hpp>
#include <KDIS/DataTypes/GaussianPlumeRecord.hpp>
#include <KDIS/DataTypes/GaussianPuffRecord.hpp>
#include <KDIS/DataTypes/GridAxisIrregular.hpp>
#include <KDIS/DataTypes/GridAxisRegular.hpp>
#include <KDIS/DataTypes/GridDataType0.hpp>
#include <KDIS/DataTypes/GridDataType1.hpp>
#include <KDIS/DataTypes/GridDataType2.hpp>
#include <KDIS/DataTypes/GroupAssignmentRecord.hpp>
#include <KDIS/DataTypes/GroupDestinationRecord.hpp>
#include <KDIS/DataTypes/IFF_ATC_NAVAIDS_FundamentalParameterData.hpp>
#include <KDIS/DataTypes/IFF_Layer2.hpp>
#include <KDIS/DataTypes/IntercomCommunicationParameters.hpp>
#include <KDIS/DataTypes/LE_DeadReckoningParameter.hpp>
#include <KDIS/DataTypes/LE_EntityIdentifier.hpp>
#include <KDIS/DataTypes/LE_EulerAngles.hpp>
#include <KDIS/DataTypes/LayerHeader.hpp>
#include <KDIS/DataTypes/LineRecord1.hpp>
#include <KDIS/DataTypes/LineRecord2.hpp>
#include <KDIS/DataTypes/LinearObjectAppearance.hpp>
#include <KDIS/DataTypes/LinearSegmentParameter.hpp>
#include <KDIS/DataTypes/MineFusing.hpp>
#include <KDIS/DataTypes/MinePaintScheme.hpp>
#include <KDIS/DataTypes/MinefieldAppearance.hpp>
#include <KDIS/DataTypes/MinefieldDataFilter.hpp>
#include <KDIS/DataTypes/NamedLocationIdentifier.hpp>
#include <KDIS/DataTypes/ObjectAppearance.hpp>
#include <KDIS/DataTypes/ObjectType.hpp>
#include <KDIS/DataTypes/OrientationError.hpp>
#include <KDIS/DataTypes/PerimeterPointCoordinate.hpp>
#include <KDIS/DataTypes/PointObjectAppearance.hpp>
#include <KDIS/DataTypes/PointRecord1.hpp>
#include <KDIS/DataTypes/PointRecord2.hpp>
#include <KDIS/DataTypes/PositionError.hpp>
#include <KDIS/DataTypes/PropulsionSystem.hpp>
#include <KDIS/DataTypes/RecordSet.hpp>
#include <KDIS/DataTypes/RectangularVolumeRecord1.hpp>
#include <KDIS/DataTypes/RectangularVolumeRecord2.hpp>
#include <KDIS/DataTypes/RectangularVolumeRecord3.hpp>
#include <KDIS/DataTypes/RelationshipRecord.hpp>
#include <KDIS/DataTypes/RelativeWorldCoordinates.hpp>
#include <KDIS/DataTypes/SecondaryOperationalData.hpp>
#include <KDIS/DataTypes/Shaft.hpp>
#include <KDIS/DataTypes/SilentAggregateSystem.hpp>
#include <KDIS/DataTypes/SilentEntitySystem.hpp>
#include <KDIS/DataTypes/SphereRecord1.hpp>
#include <KDIS/DataTypes/SphereRecord2.hpp>
#include <KDIS/DataTypes/SystemIdentifier.hpp>
#include <KDIS/DataTypes/UnderwaterAcousticEmitterBeam.hpp>
#include <KDIS/DataTypes/UnderwaterAcousticEmitterSystem.hpp>
#include <KDIS/DataTypes/UnderwaterAcousticFundamentalParameterData.hpp>
#include <KDIS/DataTypes/VectoringNozzleSystem.hpp>
#include <KDIS/KDefines.hpp>
#include <iostream>

TEST(DataType_EncodeDecode6, AcousticEmitterSystem) {
  KDIS::DATA_TYPE::AcousticEmitterSystem dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AcousticEmitterSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, AggregateIdentifier) {
  KDIS::DATA_TYPE::AggregateIdentifier dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AggregateIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, AggregateMarking) {
  KDIS::DATA_TYPE::AggregateMarking dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AggregateMarking dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, AggregateType) {
  KDIS::DATA_TYPE::AggregateType dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AggregateType dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, APA) {
  KDIS::DATA_TYPE::APA dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::APA dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ArealObjectAppearance) {
  KDIS::DATA_TYPE::ArealObjectAppearance dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ArealObjectAppearance dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, BeamData) {
  KDIS::DATA_TYPE::BeamData dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::BeamData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, BoundingSphereRecord) {
  KDIS::DATA_TYPE::BoundingSphereRecord dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::BoundingSphereRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, COMBICState) {
  KDIS::DATA_TYPE::COMBICState dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::COMBICState dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, CommunicationsChannelType) {
  KDIS::DATA_TYPE::CommunicationsChannelType dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::CommunicationsChannelType dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ConeRecord1) {
  KDIS::DATA_TYPE::ConeRecord1 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ConeRecord1 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ConeRecord2) {
  KDIS::DATA_TYPE::ConeRecord2 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ConeRecord2 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, EllipsoidRecord1) {
  KDIS::DATA_TYPE::EllipsoidRecord1 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EllipsoidRecord1 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, EllipsoidRecord2) {
  KDIS::DATA_TYPE::EllipsoidRecord2 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EllipsoidRecord2 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, EntityDestinationRecord) {
  KDIS::DATA_TYPE::EntityDestinationRecord dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EntityDestinationRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, EnvironmentType) {
  KDIS::DATA_TYPE::EnvironmentType dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EnvironmentType dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, FlareState) {
  KDIS::DATA_TYPE::FlareState dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::FlareState dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, FundamentalOperationalData) {
  KDIS::DATA_TYPE::FundamentalOperationalData dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::FundamentalOperationalData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GaussianPlumeRecord) {
  KDIS::DATA_TYPE::GaussianPlumeRecord dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GaussianPlumeRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GaussianPuffRecord) {
  KDIS::DATA_TYPE::GaussianPuffRecord dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GaussianPuffRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicFixedWingAircraft) {
  KDIS::DATA_TYPE::GED_BasicFixedWingAircraft dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_BasicFixedWingAircraft dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicGroundCombatSoldier) {
  KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicGroundCombatVehicle) {
  KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicRotorWingAircraft) {
  KDIS::DATA_TYPE::GED_BasicRotorWingAircraft dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_BasicRotorWingAircraft dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedFixedWingAircraft) {
  KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedGroundCombatSoldier) {
  KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedGroundCombatVehicle) {
  KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedRotaryWingAircraft) {
  KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_GroundLogisticsVehicle) {
  KDIS::DATA_TYPE::GED_GroundLogisticsVehicle dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_GroundLogisticsVehicle dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridAxisIrregular) {
  KDIS::DATA_TYPE::GridAxisIrregular dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GridAxisIrregular dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridAxisRegular) {
  KDIS::DATA_TYPE::GridAxisRegular dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GridAxisRegular dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridDataType0) {
  KDIS::DATA_TYPE::GridDataType0 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GridDataType0 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridDataType1) {
  KDIS::DATA_TYPE::GridDataType1 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GridDataType1 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridDataType2) {
  KDIS::DATA_TYPE::GridDataType2 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GridDataType2 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GroupAssignmentRecord) {
  KDIS::DATA_TYPE::GroupAssignmentRecord dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GroupAssignmentRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GroupDestinationRecord) {
  KDIS::DATA_TYPE::GroupDestinationRecord dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GroupDestinationRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, IFF_ATC_NAVAIDS_FundamentalParameterData) {
  KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, IFF_Layer2) {
  KDIS::DATA_TYPE::IFF_Layer2 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IFF_Layer2 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, IntercomCommunicationParameters) {
  KDIS::DATA_TYPE::IntercomCommunicationParameters dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IntercomCommunicationParameters dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LayerHeader) {
  KDIS::DATA_TYPE::LayerHeader dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LayerHeader dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LE_DeadReckoningParameter) {
  KDIS::DATA_TYPE::LE_DeadReckoningParameter dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LE_DeadReckoningParameter dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LE_EntityIdentifier) {
  KDIS::DATA_TYPE::LE_EntityIdentifier dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LE_EntityIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LE_EulerAngles) {
  KDIS::DATA_TYPE::LE_EulerAngles dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LE_EulerAngles dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LinearObjectAppearance) {
  KDIS::DATA_TYPE::LinearObjectAppearance dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LinearObjectAppearance dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LinearSegmentParameter) {
  KDIS::DATA_TYPE::LinearSegmentParameter dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LinearSegmentParameter dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LineRecord1) {
  KDIS::DATA_TYPE::LineRecord1 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LineRecord1 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LineRecord2) {
  KDIS::DATA_TYPE::LineRecord2 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LineRecord2 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, MinefieldAppearance) {
  KDIS::DATA_TYPE::MinefieldAppearance dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::MinefieldAppearance dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, MinefieldDataFilter) {
  KDIS::DATA_TYPE::MinefieldDataFilter dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::MinefieldDataFilter dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, MineFusing) {
  KDIS::DATA_TYPE::MineFusing dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::MineFusing dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, MinePaintScheme) {
  KDIS::DATA_TYPE::MinePaintScheme dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::MinePaintScheme dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, NamedLocationIdentifier) {
  KDIS::DATA_TYPE::NamedLocationIdentifier dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::NamedLocationIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ObjectAppearance) {
  KDIS::DATA_TYPE::ObjectAppearance dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ObjectAppearance dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ObjectType) {
  KDIS::DATA_TYPE::ObjectType dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ObjectType dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, OrientationError) {
  KDIS::DATA_TYPE::OrientationError dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::OrientationError dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PerimeterPointCoordinate) {
  KDIS::DATA_TYPE::PerimeterPointCoordinate dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::PerimeterPointCoordinate dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PointObjectAppearance) {
  KDIS::DATA_TYPE::PointObjectAppearance dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::PointObjectAppearance dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PointRecord1) {
  KDIS::DATA_TYPE::PointRecord1 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::PointRecord1 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PointRecord2) {
  KDIS::DATA_TYPE::PointRecord2 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::PointRecord2 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PositionError) {
  KDIS::DATA_TYPE::PositionError dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::PositionError dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PropulsionSystem) {
  KDIS::DATA_TYPE::PropulsionSystem dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::PropulsionSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RecordSet) {
  KDIS::DATA_TYPE::RecordSet dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::RecordSet dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RectangularVolumeRecord1) {
  KDIS::DATA_TYPE::RectangularVolumeRecord1 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::RectangularVolumeRecord1 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RectangularVolumeRecord2) {
  KDIS::DATA_TYPE::RectangularVolumeRecord2 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::RectangularVolumeRecord2 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RectangularVolumeRecord3) {
  KDIS::DATA_TYPE::RectangularVolumeRecord3 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::RectangularVolumeRecord3 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RelationshipRecord) {
  KDIS::DATA_TYPE::RelationshipRecord dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::RelationshipRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RelativeWorldCoordinates) {
  KDIS::DATA_TYPE::RelativeWorldCoordinates dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::RelativeWorldCoordinates dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SecondaryOperationalData) {
  KDIS::DATA_TYPE::SecondaryOperationalData dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SecondaryOperationalData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, Shaft) {
  KDIS::DATA_TYPE::Shaft dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Shaft dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SilentAggregateSystem) {
  KDIS::DATA_TYPE::SilentAggregateSystem dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SilentAggregateSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SilentEntitySystem) {
  KDIS::DATA_TYPE::SilentEntitySystem dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SilentEntitySystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SphereRecord1) {
  KDIS::DATA_TYPE::SphereRecord1 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SphereRecord1 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SphereRecord2) {
  KDIS::DATA_TYPE::SphereRecord2 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SphereRecord2 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SystemIdentifier) {
  KDIS::DATA_TYPE::SystemIdentifier dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SystemIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, UnderwaterAcousticEmitterBeam) {
  KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, UnderwaterAcousticEmitterSystem) {
  KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, UnderwaterAcousticFundamentalParameterData) {
  KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, VectoringNozzleSystem) {
  KDIS::DATA_TYPE::VectoringNozzleSystem dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::VectoringNozzleSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}
