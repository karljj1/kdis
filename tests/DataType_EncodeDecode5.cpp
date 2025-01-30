#include <gtest/gtest.h>

#include <KDIS/DataTypes/AntennaLocation.hpp>
#include <KDIS/DataTypes/ArticulatedPart.hpp>
#include <KDIS/DataTypes/AttachedPart.hpp>
#include <KDIS/DataTypes/ClockTime.hpp>
#include <KDIS/DataTypes/CryptoSystem.hpp>
#include <KDIS/DataTypes/DeadReckoningParameter.hpp>
#include <KDIS/DataTypes/Descriptor.hpp>
#include <KDIS/DataTypes/EmissionSystem.hpp>
#include <KDIS/DataTypes/EmitterBeam.hpp>
#include <KDIS/DataTypes/EmitterSystem.hpp>
#include <KDIS/DataTypes/EncodingScheme.hpp>
#include <KDIS/DataTypes/EntityAppearance.hpp>
#include <KDIS/DataTypes/EntityCapabilities.hpp>
#include <KDIS/DataTypes/EntityIdentifier.hpp>
#include <KDIS/DataTypes/EntityMarking.hpp>
#include <KDIS/DataTypes/EntityType.hpp>
#include <KDIS/DataTypes/EulerAngles.hpp>
#include <KDIS/DataTypes/FixedDatum.hpp>
#include <KDIS/DataTypes/FundamentalParameterData.hpp>
#include <KDIS/DataTypes/LifeFormAppearance.hpp>
#include <KDIS/DataTypes/ModulationType.hpp>
#include <KDIS/DataTypes/MunitionDescriptor.hpp>
#include <KDIS/DataTypes/RadioEntityType.hpp>
#include <KDIS/DataTypes/SimulationIdentifier.hpp>
#include <KDIS/DataTypes/Supplies.hpp>
#include <KDIS/DataTypes/TimeStamp.hpp>
#include <KDIS/DataTypes/TrackJamTargetIdentifier.hpp>
#include <KDIS/DataTypes/VariableDatum.hpp>
#include <KDIS/DataTypes/VariableParameter.hpp>
#include <KDIS/DataTypes/Vector.hpp>
#include <KDIS/DataTypes/WorldCoordinates.hpp>
#include <iostream>

TEST(DataType_EncodeDecode5, AntennaLocation) {
  KDIS::DATA_TYPE::AntennaLocation dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AntennaLocation dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, ArticulatedPart) {
  KDIS::DATA_TYPE::ArticulatedPart dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ArticulatedPart dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, AttachedPart) {
  KDIS::DATA_TYPE::AttachedPart dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AttachedPart dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, ClockTime) {
  KDIS::DATA_TYPE::ClockTime dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ClockTime dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, CryptoSystem) {
  KDIS::DATA_TYPE::CryptoSystem dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::CryptoSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, DeadReckoningParameter) {
  KDIS::DATA_TYPE::DeadReckoningParameter dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::DeadReckoningParameter dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EmissionSystem) {
  KDIS::DATA_TYPE::EmissionSystem dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EmissionSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EmitterBeam) {
  KDIS::DATA_TYPE::EmitterBeam dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EmitterBeam dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EmitterSystem) {
  KDIS::DATA_TYPE::EmitterSystem dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EmitterSystem dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EncodingScheme) {
  KDIS::DATA_TYPE::EncodingScheme dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EncodingScheme dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityAppearance) {
  KDIS::DATA_TYPE::EntityAppearance dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EntityAppearance dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityCapabilities) {
  KDIS::DATA_TYPE::EntityCapabilities dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EntityCapabilities dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityIdentifier) {
  KDIS::DATA_TYPE::EntityIdentifier dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EntityIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityMarking) {
  KDIS::DATA_TYPE::EntityMarking dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EntityMarking dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityType) {
  KDIS::DATA_TYPE::EntityType dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EntityType dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EulerAngles) {
  KDIS::DATA_TYPE::EulerAngles dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EulerAngles dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, FixedDatum) {
  KDIS::DATA_TYPE::FixedDatum dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::FixedDatum dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, FundamentalParameterData) {
  KDIS::DATA_TYPE::FundamentalParameterData dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::FundamentalParameterData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, LifeFormAppearance) {
  KDIS::DATA_TYPE::LifeFormAppearance dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::EntityCompliance ec{
      KDIS::DATA_TYPE::ENUMS::Detained};
  EXPECT_NO_THROW(dtIn.SetEntityCompliance(ec));
  EXPECT_EQ(ec, dtIn.GetEntityCompliance());
  // LifeFormAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, ModulationType) {
  KDIS::DATA_TYPE::ModulationType dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ModulationType dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, MunitionDescriptor) {
  KDIS::DATA_TYPE::MunitionDescriptor dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::MunitionDescriptor dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, RadioEntityType) {
  KDIS::DATA_TYPE::RadioEntityType dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::RadioEntityType dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, SimulationIdentifier) {
  KDIS::DATA_TYPE::SimulationIdentifier dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SimulationIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, Supplies) {
  KDIS::DATA_TYPE::Supplies dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Supplies dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, TimeStamp) {
  KDIS::DATA_TYPE::TimeStamp dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::TimeStamp dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, TrackJamTargetIdentifier) {
  KDIS::DATA_TYPE::TrackJamTargetIdentifier dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::TrackJamTargetIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, VariableDatum) {
  KDIS::DATA_TYPE::VariableDatum dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::VariableDatum dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, VariableParameter) {
  KDIS::DATA_TYPE::VariableParameter dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::VariableParameter dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, Vector) {
  KDIS::DATA_TYPE::Vector dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Vector dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, WorldCoordinates) {
  KDIS::DATA_TYPE::WorldCoordinates dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::WorldCoordinates dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}
