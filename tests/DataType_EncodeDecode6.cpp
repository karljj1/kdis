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
#include <KDIS/DataTypes/EnvironmentRecord.hpp>
#include <KDIS/DataTypes/EnvironmentType.hpp>
#include <KDIS/DataTypes/FlareState.hpp>
#include <KDIS/DataTypes/FundamentalOperationalData.hpp>
#include <KDIS/DataTypes/FundamentalOperationalData_MarkXInterrogator.hpp>
#include <KDIS/DataTypes/FundamentalOperationalData_MarkXTransponder.hpp>
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
#include <KDIS/DataTypes/Mine.hpp>
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
#include <KDIS/DataTypes/SeparationPart.hpp>
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
#include <bitset>
#include <iostream>
#include <stdexcept>
#include <vector>

TEST(DataType_EncodeDecode6, AcousticEmitterSystem) {
  KDIS::DATA_TYPE::AcousticEmitterSystem dtIn;
  EXPECT_EQ(0, dtIn.GetName());
  EXPECT_EQ(0, dtIn.GetFunction());
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AcousticEmitterSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, AggregateIdentifier) {
  KDIS::DATA_TYPE::AggregateIdentifier dtIn;
  EXPECT_TRUE(!(dtIn < dtIn));
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AggregateIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, AggregateMarking) {
  KDIS::DATA_TYPE::AggregateMarking dtIn;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ASCII,
            dtIn.GetAggregateMarkingCharacterSet());
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AggregateMarking dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
  EXPECT_NO_THROW(dtIn.SetAggregateMarkingString("on your mark,"));
  const KDIS::KString amstr{"get set, go!"};
  KDIS::DATA_TYPE::AggregateMarking am2{KDIS::DATA_TYPE::ENUMS::ASCII, amstr};
  EXPECT_EQ(amstr, am2.GetAggregateMarkingString());
  KDIS::KDataStream stream2;
  EXPECT_THROW(am2.Decode(stream2), KDIS::KException);  // too short
  EXPECT_NO_THROW(am2.Encode(stream2));
  EXPECT_NO_THROW(am2.Decode(stream2));
  EXPECT_TRUE(dtIn == dtIn);
  EXPECT_TRUE(dtIn != am2);
}

TEST(DataType_EncodeDecode6, AggregateType) {
  KDIS::DATA_TYPE::AggregateType dtIn;
  EXPECT_EQ(0, dtIn.GetEntityKind());
  EXPECT_EQ(0, dtIn.GetDomain());
  EXPECT_EQ(0, dtIn.GetCountry());
  EXPECT_NO_THROW(dtIn.GetAsString());
  EXPECT_TRUE(!(dtIn < dtIn));
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
  constexpr KDIS::DATA_TYPE::ENUMS::Breach2bit b2b{
      KDIS::DATA_TYPE::ENUMS::Cleared2bit};
  EXPECT_NO_THROW(dtIn.SetBreach(b2b));
  EXPECT_EQ(b2b, dtIn.GetBreach());
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
  EXPECT_EQ(0, dtIn.GetType());
  EXPECT_EQ(0, dtIn.GetClass());
  EXPECT_NO_THROW(dtIn.GetAsString());
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
  EXPECT_EQ(0, dtIn.GetLineStateCommand());
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EntityDestinationRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

class EnvironmentRecordTest : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::EnvironmentRecord er;
  KDIS::KDataStream stream;
  class UniformGeometryRecord : public KDIS::DATA_TYPE::EnvironmentRecord {
   public:
    UniformGeometryRecord() {
      m_ui32EnvRecTyp = KDIS::DATA_TYPE::ENUMS::UniformGeometryRecordType;
    }
  };
  class UnknownEnvironmentRecord : public KDIS::DATA_TYPE::EnvironmentRecord {
   public:
    UnknownEnvironmentRecord() { m_ui32EnvRecTyp = 0xF1F1F1F1; }
  };
};

TEST_F(EnvironmentRecordTest, GetLength) { EXPECT_EQ(0, er.GetLength()); }

TEST_F(EnvironmentRecordTest, GetEnvironmentRecordType) {
  EXPECT_EQ(0, er.GetEnvironmentRecordType());
}

TEST_F(EnvironmentRecordTest, SetGetIndex) {
  EXPECT_NO_THROW(er.SetIndex(28));
  EXPECT_EQ(28, er.GetIndex());
}

TEST_F(EnvironmentRecordTest, GetAsString) {
  EXPECT_NO_THROW(er.GetAsString());
}

TEST_F(EnvironmentRecordTest, DecodeTooShort) {
  EXPECT_THROW(er.Decode(stream), KDIS::KException);
}

TEST_F(EnvironmentRecordTest, EncodeDecodeRoundTrip) {
  EXPECT_NO_THROW(er.Encode(stream));
  EXPECT_NO_THROW(er.Decode(stream));
}

TEST_F(EnvironmentRecordTest, FactoryDecodeEnvRecTypeNotSet) {
  EXPECT_THROW(er.FactoryDecodeEnvironmentRecord(stream), KDIS::KException);
}

TEST_F(EnvironmentRecordTest, FactoryDecodeNotImplementedFromStream) {
  auto ugr = UniformGeometryRecord();
  stream = ugr.Encode();
  EXPECT_THROW(er.FactoryDecodeEnvironmentRecord(stream), KDIS::KException);
}

TEST_F(EnvironmentRecordTest, FactoryDecodeUnknownFromStream) {
  auto uer = UnknownEnvironmentRecord();
  stream = uer.Encode();
  EXPECT_THROW(er.FactoryDecodeEnvironmentRecord(stream), KDIS::KException);
}

TEST_F(EnvironmentRecordTest, ConstructFromStream) {
  stream = er.Encode();
  KDIS::DATA_TYPE::EnvironmentRecord er2(stream);
  EXPECT_EQ(er, er2);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, EnvironmentType) {
  KDIS::DATA_TYPE::EnvironmentType dtIn;
  EXPECT_EQ(0, dtIn.GetDomain());
  EXPECT_EQ(0, dtIn.GetSubCategory());
  EXPECT_NO_THROW(dtIn.GetAsString());
  EXPECT_TRUE(!(dtIn < dtIn));
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

TEST(DataType_EncodeDecode6, FundamentalOperationalData_MarkXInterrogator) {
  KDIS::DATA_TYPE::FundamentalOperationalData_MarkXInterrogator dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::AlternateParameter4 ap4{
      KDIS::DATA_TYPE::ENUMS::Valid};
  EXPECT_NO_THROW(dtIn.SetAlternateParameter4(ap4));
  EXPECT_EQ(ap4, dtIn.GetAlternateParameter4());
  constexpr KDIS::DATA_TYPE::ENUMS::TCAS tcas{KDIS::DATA_TYPE::ENUMS::TCAS_I};
  EXPECT_NO_THROW(dtIn.SetTCASVersion(tcas));
  EXPECT_EQ(tcas, dtIn.GetTCASVersion());
}

TEST(DataType_EncodeDecode6, FundamentalOperationalData_MarkXTransponder) {
  KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::AlternateParameter4 ap4{
      KDIS::DATA_TYPE::ENUMS::OtherAlternateParameter4};
  EXPECT_NO_THROW(dtIn.SetAlternateParameter4(ap4));
  EXPECT_EQ(ap4, dtIn.GetAlternateParameter4());
  // FundamentalOperationalData_MarkXTransponder has no Encode/Decode feature
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
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_BasicFixedWingAircraft dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicGroundCombatSoldier) {
  KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicGroundCombatVehicle) {
  KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicRotorWingAircraft) {
  KDIS::DATA_TYPE::GED_BasicRotorWingAircraft dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_BasicRotorWingAircraft dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedFixedWingAircraft) {
  KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedGroundCombatSoldier) {
  KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier dtIn;
  EXPECT_EQ(0, dtIn.GetRestStatus());
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedGroundCombatVehicle) {
  KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedRotaryWingAircraft) {
  KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_GroundLogisticsVehicle) {
  KDIS::DATA_TYPE::GED_GroundLogisticsVehicle dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GED_GroundLogisticsVehicle dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridAxisIrregular) {
  KDIS::DATA_TYPE::GridAxisIrregular dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GridAxisIrregular dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

class GridAxisRegularTest : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::GridAxisRegular gar;
  KDIS::KDataStream stream;
};

TEST_F(GridAxisRegularTest, GetAsString) { EXPECT_NO_THROW(gar.GetAsString()); }

TEST_F(GridAxisRegularTest, EncodeStreamConstructor) {
  stream = gar.Encode();
  KDIS::DATA_TYPE::GridAxisRegular gar2(stream);
  EXPECT_EQ(gar, gar2);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST_F(GridAxisRegularTest, GetLength) {
  EXPECT_EQ(KDIS::DATA_TYPE::GridAxisRegular::GridAxisRegularBytes,
            gar.GetLength());
}

class GridDataType0Test : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::GridDataType0 gdt0;
  KDIS::KDataStream stream;
};

TEST_F(GridDataType0Test, AlternateConstructors) {
  EXPECT_THROW(KDIS::DATA_TYPE::GridDataType0(5, 2, stream), std::length_error);
  std::vector<KDIS::KUINT8> vec = {4, 44, 244};
  EXPECT_NO_THROW(
      gdt0 = KDIS::DATA_TYPE::GridDataType0(7, vec.data(), vec.size()));
  EXPECT_EQ(vec.size(), gdt0.GetNumberOfBytes());
}

TEST_F(GridDataType0Test, GetDataRepresentation) {
  EXPECT_NO_THROW(gdt0.GetDataRepresentation());
}

TEST_F(GridDataType0Test, AddDataValue) {
  EXPECT_NO_THROW(gdt0.AddDataValue(42));
}

TEST_F(GridDataType0Test, GetAsString) { EXPECT_NO_THROW(gdt0.GetAsString()); }

TEST_F(GridDataType0Test, EncodeStreamConstructor) {
  stream = gdt0.Encode();
  KDIS::DATA_TYPE::GridDataType0 gdt0two(stream);
  EXPECT_EQ(gdt0, gdt0two);
  EXPECT_EQ(0, stream.GetBufferSize());
}

class GridDataType1Test : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::GridDataType1 gdt1;
  KDIS::KDataStream stream;
};

TEST_F(GridDataType1Test, AlternateConstructors) {
  EXPECT_THROW(KDIS::DATA_TYPE::GridDataType1(33, 2, stream),
               std::length_error);
  EXPECT_NO_THROW(
      KDIS::DATA_TYPE::GridDataType1(0, 0, 0, std::vector<KDIS::KUINT16>()));
}

TEST_F(GridDataType1Test, SetGetFieldScale) {
  EXPECT_NO_THROW(gdt1.SetFieldScale(33.3));
  EXPECT_FLOAT_EQ(33.3, gdt1.GetFieldScale());
}

TEST_F(GridDataType1Test, EncodeStreamConstructor) {
  stream = gdt1.Encode();
  KDIS::DATA_TYPE::GridDataType1 gdt1two(stream);
  EXPECT_EQ(gdt1, gdt1two);
  EXPECT_EQ(0, stream.GetBufferSize());
}

class GridDataType2Test : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::GridDataType2 gdt2;
  KDIS::KDataStream stream;
};

TEST_F(GridDataType2Test, AlternateConstructors) {
  const std::vector<KDIS::KFLOAT32> vec = {1.2, 3.4, 5.6};
  EXPECT_NO_THROW(auto obj = KDIS::DATA_TYPE::GridDataType2(6, vec));
}

TEST_F(GridDataType2Test, EncodeStreamConstructor) {
  stream = gdt2.Encode();
  KDIS::DATA_TYPE::GridDataType2 gdt2two(stream);
  EXPECT_EQ(gdt2, gdt2two);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GroupAssignmentRecord) {
  KDIS::DATA_TYPE::GroupAssignmentRecord dtIn;
  for (KDIS::KUINT8 ii = 0; ii < 32; ++ii) {
    EXPECT_NO_THROW(dtIn.SetGroupBitField(ii, false));
  }
  EXPECT_EQ(false, dtIn.IsGroupBitSet(0));
  EXPECT_EQ(false, dtIn.IsGroupBitSet(9));
  EXPECT_EQ(false, dtIn.IsGroupBitSet(31));
  EXPECT_THROW(dtIn.IsGroupBitSet(32), KDIS::KException);
  EXPECT_THROW(dtIn.SetGroupBitField(32, true), KDIS::KException);
  for (KDIS::KUINT8 ii = 0; ii < 32; ++ii) {
    EXPECT_NO_THROW(dtIn.SetGroupBitField(ii, true));
  }
  EXPECT_TRUE(dtIn.IsGroupBitSet(0));
  EXPECT_TRUE(dtIn.IsGroupBitSet(19));
  EXPECT_TRUE(dtIn.IsGroupBitSet(31));
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GroupAssignmentRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GroupDestinationRecord) {
  KDIS::DATA_TYPE::GroupDestinationRecord dtIn;
  for (KDIS::KUINT8 ii = 0; ii < 32; ++ii) {
    EXPECT_NO_THROW(dtIn.SetGroupBitField(ii, false));
  }
  EXPECT_EQ(false, dtIn.IsGroupBitSet(0));
  EXPECT_EQ(false, dtIn.IsGroupBitSet(13));
  EXPECT_EQ(false, dtIn.IsGroupBitSet(31));
  EXPECT_THROW(dtIn.IsGroupBitSet(32), KDIS::KException);
  EXPECT_THROW(dtIn.SetGroupBitField(32, true), KDIS::KException);
  for (KDIS::KUINT8 ii = 0; ii < 32; ++ii) {
    EXPECT_NO_THROW(dtIn.SetGroupBitField(ii, true));
  }
  EXPECT_TRUE(dtIn.IsGroupBitSet(0));
  EXPECT_TRUE(dtIn.IsGroupBitSet(22));
  EXPECT_TRUE(dtIn.IsGroupBitSet(31));
  EXPECT_EQ(0, dtIn.GetLineStateCommand());
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::GroupDestinationRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, IFF_ATC_NAVAIDS_FundamentalParameterData) {
  KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData dtIn;
  EXPECT_EQ(0, dtIn.GetApplicableModes());
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
  KDIS::DATA_TYPE::EntityDestinationRecord edr;
  KDIS::DATA_TYPE::GroupDestinationRecord gdr;
  KDIS::DATA_TYPE::GroupAssignmentRecord gar;
  KDIS::DATA_TYPE::IntercomCommunicationParameters dtInEdr(&edr);
  KDIS::DATA_TYPE::IntercomCommunicationParameters dtInGdr(&gdr);
  KDIS::DATA_TYPE::IntercomCommunicationParameters dtInGar(&gar);
  EXPECT_TRUE(dtInEdr == dtInEdr);
  EXPECT_TRUE(dtInGdr == dtInGdr);
  EXPECT_TRUE(dtInGar == dtInGar);
  KDIS::DATA_TYPE::IntercomCommunicationParameters dtIn;
  EXPECT_EQ(0, dtIn.GetRecordType());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IntercomCommunicationParameters dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LayerHeader) {
  KDIS::DATA_TYPE::LayerHeader dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LayerHeader dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LE_DeadReckoningParameter) {
  KDIS::DATA_TYPE::LE_DeadReckoningParameter dtIn;
  EXPECT_EQ(0, dtIn.GetDeadReckoningAlgorithm());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::LE_DeadReckoningParameter dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LE_EntityIdentifier) {
  KDIS::DATA_TYPE::LE_EntityIdentifier dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  EXPECT_TRUE(!(dtIn < dtIn));
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

class LinearObjectAppearanceTest : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::LinearObjectAppearance loa;
  KDIS::KDataStream stream;
};

TEST_F(LinearObjectAppearanceTest, SetGetBreach) {
  constexpr KDIS::DATA_TYPE::ENUMS::Breach2bit b2b{
      KDIS::DATA_TYPE::ENUMS::Breached2bit};
  EXPECT_NO_THROW(loa.SetBreach(b2b));
  EXPECT_EQ(b2b, loa.GetBreach());
}

TEST_F(LinearObjectAppearanceTest, SetGetBreachLocation) {
  constexpr std::bitset<8> bs8{0xFB};
  EXPECT_NO_THROW(loa.SetBreachLocation(bs8));
  EXPECT_EQ(bs8, loa.GetBreachLocationAsBitset());
}

TEST_F(LinearObjectAppearanceTest, SetGetOpacity) {
  EXPECT_THROW(loa.SetOpacity(101), KDIS::KException);
  EXPECT_NO_THROW(loa.SetOpacity(87));
  EXPECT_EQ(87, loa.GetOpacity());
}

TEST_F(LinearObjectAppearanceTest, SetGetAttached) {
  EXPECT_NO_THROW(loa.SetAttached(false));
  EXPECT_EQ(false, loa.IsAttached());
}

TEST_F(LinearObjectAppearanceTest, SetGetChemical) {
  constexpr KDIS::DATA_TYPE::ENUMS::Chemical ch{
      KDIS::DATA_TYPE::ENUMS::Hydrochloric};
  EXPECT_NO_THROW(loa.SetChemical(ch));
  EXPECT_EQ(ch, loa.GetChemical());
}

TEST_F(LinearObjectAppearanceTest, SetGetVisibleSide) {
  constexpr KDIS::DATA_TYPE::ENUMS::VisibleSide vs{
      KDIS::DATA_TYPE::ENUMS::LeftSideVisible};
  EXPECT_NO_THROW(loa.SetVisibleSide(vs));
  EXPECT_EQ(vs, loa.GetVisibleSide());
}

TEST_F(LinearObjectAppearanceTest, EncodeStreamConstructor) {
  stream = loa.Encode();
  KDIS::DATA_TYPE::LinearObjectAppearance loa2(stream);
  EXPECT_EQ(loa, loa2);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LinearSegmentParameter) {
  KDIS::DATA_TYPE::LinearSegmentParameter dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
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

class MineTest : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::Mine mn;
  KDIS::KDataStream stream;
  const KDIS::DATA_TYPE::Vector vec;
};

TEST_F(MineTest, AlternateConstructors) {
  EXPECT_NO_THROW(KDIS::DATA_TYPE::Mine(vec, 7));
}

TEST_F(MineTest, AddScalarDetectionCoefficientValue) {
  EXPECT_NO_THROW(mn.AddScalarDetectionCoefficientValue(17));
}

TEST_F(MineTest, AddTripDetonationWire) {
  const std::vector<KDIS::DATA_TYPE::Vector> vtx = {
      KDIS::DATA_TYPE::Vector(1, 2, 3)};
  EXPECT_NO_THROW(mn.AddTripDetonationWire(vtx));
}

TEST_F(MineTest, AddVertexToTripDetonationWire) {
  // Index too big
  EXPECT_THROW(mn.AddVertexToTripDetonationWire(7, vec), KDIS::KException);
}

TEST_F(MineTest, SetTripDetonationWireVertices) {
  const std::vector<KDIS::DATA_TYPE::Vector> vtx = {
      KDIS::DATA_TYPE::Vector(1, 2, 3)};
  constexpr KDIS::KUINT16 idx{0};
  EXPECT_EQ(idx, mn.AddTripDetonationWire(vtx));
  const std::vector<KDIS::DATA_TYPE::Vector> vtx2 = {vec};
  EXPECT_NO_THROW(mn.SetTripDetonationWireVertices(idx, vtx2));
}

TEST_F(MineTest, RemoveTripDetonationWire) {
  const std::vector<KDIS::DATA_TYPE::Vector> vtx = {
      KDIS::DATA_TYPE::Vector(1, 2, 3)};
  EXPECT_NO_THROW(mn.AddTripDetonationWire(vtx));
  EXPECT_NO_THROW(mn.RemoveTripDetonationWire(0));
}

TEST_F(MineTest, GetWireVertices) {
  const std::vector<KDIS::DATA_TYPE::Vector> vtx = {
      KDIS::DATA_TYPE::Vector(1, 2, 3)};
  EXPECT_NO_THROW(mn.AddTripDetonationWire(vtx));
  EXPECT_EQ(vtx, mn.GetWireVertices(0));
}

TEST_F(MineTest, ClearWireVertices) {
  const std::vector<KDIS::DATA_TYPE::Vector> vtx = {
      KDIS::DATA_TYPE::Vector(1, 2, 3)};
  EXPECT_NO_THROW(mn.AddTripDetonationWire(vtx));
  EXPECT_NO_THROW(mn.ClearWireVertices(0));
}

TEST_F(MineTest, GetAsString) { EXPECT_NO_THROW(mn.GetAsString()); }

TEST_F(MineTest, EncodeDecode) {
  // Encode/Decode are not supported by Mine
  EXPECT_THROW(mn.Decode(stream), std::logic_error);
  EXPECT_THROW(mn.Encode(), std::logic_error);
  EXPECT_THROW(mn.Encode(stream), std::logic_error);
}

TEST(DataType_EncodeDecode6, MinefieldAppearance) {
  KDIS::DATA_TYPE::MinefieldAppearance dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::MinefieldType mt{
      KDIS::DATA_TYPE::ENUMS::MixedAntiPersonnelAntiTank};
  EXPECT_NO_THROW(dtIn.SetMinefieldType(mt));
  EXPECT_EQ(mt, dtIn.GetMinefieldType());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::MinefieldAppearance dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

class MinefieldDataFilterTest : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::MinefieldDataFilter mdf;
  KDIS::KDataStream stream;
};

TEST_F(MinefieldDataFilterTest, SetIsGroundBurialDepthOffset) {
  EXPECT_NO_THROW(mdf.SetGroundBurialDepthOffset(true));
  EXPECT_TRUE(mdf.IsGroundBurialDepthOffset());
}

TEST_F(MinefieldDataFilterTest, SetIsWaterBurialDepthOffset) {
  EXPECT_NO_THROW(mdf.SetWaterBurialDepthOffset(true));
  EXPECT_TRUE(mdf.IsWaterBurialDepthOffset());
}

TEST_F(MinefieldDataFilterTest, SetIsSnowBurialDepthOffset) {
  EXPECT_NO_THROW(mdf.SetSnowBurialDepthOffset(true));
  EXPECT_TRUE(mdf.IsSnowBurialDepthOffset());
}

TEST_F(MinefieldDataFilterTest, SetIsMineOrientation) {
  EXPECT_NO_THROW(mdf.SetMineOrientation(true));
  EXPECT_TRUE(mdf.IsMineOrientation());
}

TEST_F(MinefieldDataFilterTest, SetIsThermalContrast) {
  EXPECT_NO_THROW(mdf.SetThermalContrast(true));
  EXPECT_TRUE(mdf.IsThermalContrast());
}

TEST_F(MinefieldDataFilterTest, SetIsReflectance) {
  EXPECT_NO_THROW(mdf.SetReflectance(true));
  EXPECT_TRUE(mdf.IsReflectance());
}

TEST_F(MinefieldDataFilterTest, SetIsMineEmplacementAge) {
  EXPECT_NO_THROW(mdf.SetMineEmplacementAge(true));
  EXPECT_TRUE(mdf.IsMineEmplacementAge());
}

TEST_F(MinefieldDataFilterTest, SetIsFusing) {
  EXPECT_NO_THROW(mdf.SetFusing(true));
  EXPECT_TRUE(mdf.IsFusing());
}

TEST_F(MinefieldDataFilterTest, SetIsScalarDetectionCoefficient) {
  EXPECT_NO_THROW(mdf.SetScalarDetectionCoefficient(true));
  EXPECT_TRUE(mdf.IsScalarDetectionCoefficient());
}

TEST_F(MinefieldDataFilterTest, SetIsPaintScheme) {
  EXPECT_NO_THROW(mdf.SetPaintScheme(true));
  EXPECT_TRUE(mdf.IsPaintScheme());
}

TEST(DataType_EncodeDecode6, MinefieldDataFilter) {
  KDIS::DATA_TYPE::MinefieldDataFilter dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::MinefieldDataFilter dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

class MineFusingTest : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::MineFusing mfg;
  KDIS::KDataStream stream;
  static constexpr KDIS::DATA_TYPE::ENUMS::MineFuse mf{
      KDIS::DATA_TYPE::ENUMS::NoMineFuse};
  static constexpr KDIS::DATA_TYPE::ENUMS::MineFuse mf2{
      KDIS::DATA_TYPE::ENUMS::OtherMineFuse};
};

// Definitions to satisfy odr-use (One Definition Rule-use, e.g. taking its
//    address). These out-of-class definitions are required in C++11, but not in
//    C++17.
constexpr KDIS::DATA_TYPE::ENUMS::MineFuse MineFusingTest::mf;
constexpr KDIS::DATA_TYPE::ENUMS::MineFuse MineFusingTest::mf2;

TEST_F(MineFusingTest, AlternateConstructors) {
  EXPECT_NO_THROW(auto obj = KDIS::DATA_TYPE::MineFusing(mf, mf2, true));
}

TEST_F(MineFusingTest, SetGetPrimaryFuse) {
  EXPECT_NO_THROW(mfg.SetPrimaryFuse(mf));
  EXPECT_EQ(mf, mfg.GetPrimaryFuse());
}

TEST_F(MineFusingTest, SetGetSecondaryFuse) {
  EXPECT_NO_THROW(mfg.SetSecondaryFuse(mf2));
  EXPECT_EQ(mf2, mfg.GetSecondaryFuse());
}

TEST_F(MineFusingTest, EncodeStreamConstructor) {
  stream = mfg.Encode();
  KDIS::DATA_TYPE::MineFusing mfg2(stream);
  EXPECT_EQ(mfg, mfg2);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, MinePaintScheme) {
  KDIS::DATA_TYPE::MinePaintScheme dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::MineAlgae ma{
      KDIS::DATA_TYPE::ENUMS::AlgaeNone};
  EXPECT_NO_THROW(dtIn.SetAlgae(ma));
  EXPECT_EQ(ma, dtIn.GetAlgae());
  constexpr KDIS::DATA_TYPE::ENUMS::PaintScheme ps{
      KDIS::DATA_TYPE::ENUMS::OtherPaintScheme};
  EXPECT_NO_THROW(dtIn.SetPaintScheme(ps));
  EXPECT_EQ(ps, dtIn.GetPaintScheme());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::MinePaintScheme dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, NamedLocationIdentifier) {
  KDIS::DATA_TYPE::NamedLocationIdentifier dtIn;
  EXPECT_EQ(0, dtIn.GetStationName());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::NamedLocationIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

class ObjectAppearanceTest : public ::testing::Test {
 protected:
  static constexpr KDIS::DATA_TYPE::ENUMS::ObjectDamage od{
      KDIS::DATA_TYPE::ENUMS::NoObjectDamage};
  KDIS::DATA_TYPE::ObjectAppearance oa;
};

// Definition to satisfy odr-use (One Definition Rule-use, e.g. taking its
//    address). This out-of-class definition is required in C++11, but not in
//    C++17.
constexpr KDIS::DATA_TYPE::ENUMS::ObjectDamage ObjectAppearanceTest::od;

TEST_F(ObjectAppearanceTest, ConstructorPerCentTooHigh) {
  EXPECT_THROW(
      KDIS::DATA_TYPE::ObjectAppearance(101, od, false, false, false, false),
      KDIS::KException);
}

TEST_F(ObjectAppearanceTest, ConstructorNominal) {
  EXPECT_NO_THROW(
      KDIS::DATA_TYPE::ObjectAppearance(0, od, false, false, false, false));
}

TEST_F(ObjectAppearanceTest, SetGetPercentageComplete) {
  EXPECT_THROW(oa.SetPercentageComplete(101), KDIS::KException);
  EXPECT_NO_THROW(oa.SetPercentageComplete(47));
  EXPECT_EQ(47, oa.GetPercentageComplete());
}

TEST_F(ObjectAppearanceTest, SetGetDamage) {
  EXPECT_NO_THROW(oa.SetDamage(od));
  EXPECT_EQ(od, oa.GetDamage());
}

TEST_F(ObjectAppearanceTest, Encode) {
  KDIS::KDataStream stream = oa.Encode();
  KDIS::DATA_TYPE::ObjectAppearance oaOut(stream);
  EXPECT_EQ(oa, oaOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ObjectType) {
  KDIS::DATA_TYPE::ObjectType dtIn;
  EXPECT_EQ(0, dtIn.GetDomain());
  EXPECT_TRUE(!(dtIn < dtIn));
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

class PointObjectAppearanceTest : public ::testing::Test {
 protected:
  KDIS::DATA_TYPE::PointObjectAppearance poa;
};

TEST_F(PointObjectAppearanceTest, SetGetBreach) {
  constexpr KDIS::DATA_TYPE::ENUMS::Breach2bit b2b{
      KDIS::DATA_TYPE::ENUMS::NoBreaching2bit};
  EXPECT_NO_THROW(poa.SetBreach(b2b));
  EXPECT_EQ(b2b, poa.GetBreach());
}

TEST_F(PointObjectAppearanceTest, SetGetOpacity) {
  EXPECT_NO_THROW(poa.SetOpacity(7));
  EXPECT_EQ(7, poa.GetOpacity());
  EXPECT_THROW(poa.SetOpacity(101), KDIS::KException);
}

TEST_F(PointObjectAppearanceTest, SetGetChemical) {
  constexpr KDIS::DATA_TYPE::ENUMS::Chemical ch{
      KDIS::DATA_TYPE::ENUMS::OtherChemical};
  EXPECT_NO_THROW(poa.SetChemical(ch));
  EXPECT_EQ(ch, poa.GetChemical());
}

TEST_F(PointObjectAppearanceTest, ConstructFromStream) {
  KDIS::KDataStream stream = poa.Encode();
  KDIS::DATA_TYPE::PointObjectAppearance poa2(stream);
  EXPECT_EQ(poa, poa2);
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
  EXPECT_EQ(0, dtIn.GetRecordID());
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
  EXPECT_EQ(0, dtIn.GetNature());
  EXPECT_EQ(0, dtIn.GetPosition());
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
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SecondaryOperationalData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SeparationPart) {
  KDIS::DATA_TYPE::SeparationPart dtIn;
  EXPECT_EQ(0, dtIn.GetReasonForSeparation());
  EXPECT_EQ(0, dtIn.GetPreEntityIndicator());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SeparationPart dtOut(stream);
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
  EXPECT_EQ(0, dtIn.GetSystemType());
  EXPECT_EQ(0, dtIn.GetSystemName());
  EXPECT_EQ(0, dtIn.GetSystemMode());
  EXPECT_NO_THROW(dtIn.SetSystemType(
      KDIS::DATA_TYPE::ENUMS::Mark_X_XII_ATCRBS_ModeS_Transponder));
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SystemIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, UnderwaterAcousticEmitterBeam) {
  KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, UnderwaterAcousticEmitterSystem) {
  KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, UnderwaterAcousticFundamentalParameterData) {
  KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData dtIn;
  EXPECT_EQ(0, dtIn.GetActiveEmissionParameterIndex());
  EXPECT_EQ(0, dtIn.GetScanPattern());
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
