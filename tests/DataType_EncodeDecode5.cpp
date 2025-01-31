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
#include <KDIS/DataTypes/GuidedMunitionsAppearance.hpp>
#include <KDIS/DataTypes/LandPlatformAppearance.hpp>
#include <KDIS/DataTypes/LifeFormAppearance.hpp>
#include <KDIS/DataTypes/ModulationType.hpp>
#include <KDIS/DataTypes/MunitionDescriptor.hpp>
#include <KDIS/DataTypes/NonHumanLifeFormAppearance.hpp>
#include <KDIS/DataTypes/RadioAppearance.hpp>
#include <KDIS/DataTypes/RadioEntityType.hpp>
#include <KDIS/DataTypes/SensorEmitterAppearance.hpp>
#include <KDIS/DataTypes/SimulationIdentifier.hpp>
#include <KDIS/DataTypes/SpacePlatformAppearance.hpp>
#include <KDIS/DataTypes/SubSurfacePlatformAppearance.hpp>
#include <KDIS/DataTypes/Supplies.hpp>
#include <KDIS/DataTypes/SupplyAppearance.hpp>
#include <KDIS/DataTypes/SurfacePlatformAppearance.hpp>
#include <KDIS/DataTypes/TimeStamp.hpp>
#include <KDIS/DataTypes/TrackJamTargetIdentifier.hpp>
#include <KDIS/DataTypes/VariableDatum.hpp>
#include <KDIS/DataTypes/VariableParameter.hpp>
#include <KDIS/DataTypes/Vector.hpp>
#include <KDIS/DataTypes/WorldCoordinates.hpp>
#include <iostream>
#include <vector>

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

TEST(DataType_EncodeDecode5, GuidedMunitionsAppearance) {
  KDIS::DATA_TYPE::GuidedMunitionsAppearance dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::EntityDamage ed{
      KDIS::DATA_TYPE::ENUMS::SlightDamage};
  EXPECT_NO_THROW(dtIn.SetEntityDamage(ed));
  EXPECT_EQ(ed, dtIn.GetEntityDamage());
  constexpr KDIS::DATA_TYPE::ENUMS::EntitySmoke es{
      KDIS::DATA_TYPE::ENUMS::NotSmoking};
  EXPECT_NO_THROW(dtIn.SetEntitySmoke(es));
  EXPECT_EQ(es, dtIn.GetEntitySmoke());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect ete{
      KDIS::DATA_TYPE::ENUMS::Small};
  EXPECT_NO_THROW(dtIn.SetEntityTrailingEffect(ete));
  EXPECT_EQ(ete, dtIn.GetEntityTrailingEffect());
  EXPECT_TRUE(dtIn == dtIn);
  // GuidedMunitionsAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, LandPlatformAppearance) {
  KDIS::DATA_TYPE::LandPlatformAppearance dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::EntityPaintScheme eps{
      KDIS::DATA_TYPE::ENUMS::UniformColor};
  EXPECT_NO_THROW(dtIn.SetEntityPaintScheme(eps));
  EXPECT_EQ(eps, dtIn.GetEntityPaintScheme());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityDamage ed{
      KDIS::DATA_TYPE::ENUMS::Destroyed};
  EXPECT_NO_THROW(dtIn.SetEntityDamage(ed));
  EXPECT_EQ(ed, dtIn.GetEntityDamage());
  constexpr KDIS::DATA_TYPE::ENUMS::EntitySmoke es{
      KDIS::DATA_TYPE::ENUMS::EngineSmoke};
  EXPECT_NO_THROW(dtIn.SetEntitySmoke(es));
  EXPECT_EQ(es, dtIn.GetEntitySmoke());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect ete{
      KDIS::DATA_TYPE::ENUMS::NoTrail};
  EXPECT_NO_THROW(dtIn.SetEntityTrailingEffect(ete));
  EXPECT_EQ(ete, dtIn.GetEntityTrailingEffect());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityHatchState ehs{
      KDIS::DATA_TYPE::ENUMS::EntityHatchStateNotApplicable};
  EXPECT_NO_THROW(dtIn.SetEntityHatchState(ehs));
  EXPECT_EQ(ehs, dtIn.GetEntityHatchState());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityCamouflage ecam{
      KDIS::DATA_TYPE::ENUMS::ForestCamouflage};
  EXPECT_NO_THROW(dtIn.SetEntityCamouflage(ecam));
  EXPECT_EQ(ecam, dtIn.GetEntityCamouflage());
  EXPECT_TRUE(dtIn == dtIn);
  // LandPlatformAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, LifeFormAppearance) {
  KDIS::DATA_TYPE::LifeFormAppearance dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::EntityPaintScheme eps{
      KDIS::DATA_TYPE::ENUMS::Camouflage};
  EXPECT_NO_THROW(dtIn.SetEntityPaintScheme(eps));
  EXPECT_EQ(eps, dtIn.GetEntityPaintScheme());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityDamage ed{
      KDIS::DATA_TYPE::ENUMS::ModerateDamage};
  EXPECT_NO_THROW(dtIn.SetEntityDamage(ed));
  EXPECT_EQ(ed, dtIn.GetEntityDamage());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityCompliance ec{
      KDIS::DATA_TYPE::ENUMS::Detained};
  EXPECT_NO_THROW(dtIn.SetEntityCompliance(ec));
  EXPECT_EQ(ec, dtIn.GetEntityCompliance());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityLifeformAppearance ela{
      KDIS::DATA_TYPE::ENUMS::UprightStandingStill};
  EXPECT_NO_THROW(dtIn.SetEntityLifeformState(ela));
  EXPECT_EQ(ela, dtIn.GetEntityLifeformState());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon elw{
      KDIS::DATA_TYPE::ENUMS::NoPrimaryWeaponPresent};
  EXPECT_NO_THROW(dtIn.SetEntityLifeformWeapon1(elw));
  EXPECT_EQ(elw, dtIn.GetEntityLifeformWeapon1());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon elw2{
      KDIS::DATA_TYPE::ENUMS::PrimaryWeaponIsStowed};
  EXPECT_NO_THROW(dtIn.SetEntityLifeformWeapon2(elw2));
  EXPECT_EQ(elw2, dtIn.GetEntityLifeformWeapon2());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityCamouflage ecam{
      KDIS::DATA_TYPE::ENUMS::WinterCamouflage};
  EXPECT_NO_THROW(dtIn.SetEntityCamouflage(ecam));
  EXPECT_EQ(ecam, dtIn.GetEntityCamouflage());
  EXPECT_TRUE(dtIn == dtIn);
  // LifeFormAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, ModulationType) {
  KDIS::DATA_TYPE::ModulationType dtIn;
  EXPECT_EQ(0, dtIn.GetMajorModulation());
  EXPECT_EQ(0, dtIn.GetSystem());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ModulationType dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, MunitionDescriptor) {
  KDIS::DATA_TYPE::MunitionDescriptor dtIn;
  EXPECT_EQ(0, dtIn.GetWarhead());
  EXPECT_EQ(0, dtIn.GetFuse());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::MunitionDescriptor dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, NonHumanLifeFormAppearance) {
  KDIS::DATA_TYPE::NonHumanLifeFormAppearance dtIn;
  EXPECT_TRUE(dtIn == dtIn);
  // NonHumanLifeFormAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, RadioAppearance) {
  KDIS::DATA_TYPE::RadioAppearance dtIn;
  EXPECT_TRUE(dtIn == dtIn);
  // RadioAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, RadioEntityType) {
  KDIS::DATA_TYPE::RadioEntityType dtIn;
  EXPECT_EQ(0, dtIn.GetEntityKind());
  EXPECT_EQ(0, dtIn.GetDomain());
  EXPECT_EQ(0, dtIn.GetCountry());
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::RadioEntityType dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, SensorEmitterAppearance) {
  KDIS::DATA_TYPE::SensorEmitterAppearance dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::EntityPaintScheme eps{
      KDIS::DATA_TYPE::ENUMS::UniformColor};
  EXPECT_NO_THROW(dtIn.SetEntityPaintScheme(eps));
  EXPECT_EQ(eps, dtIn.GetEntityPaintScheme());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityDamage ed{
      KDIS::DATA_TYPE::ENUMS::NoDamage};
  EXPECT_NO_THROW(dtIn.SetEntityDamage(ed));
  EXPECT_EQ(ed, dtIn.GetEntityDamage());
  constexpr KDIS::DATA_TYPE::ENUMS::EntitySmoke es{
      KDIS::DATA_TYPE::ENUMS::EngineSmoke};
  EXPECT_NO_THROW(dtIn.SetEntitySmoke(es));
  EXPECT_EQ(es, dtIn.GetEntitySmoke());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect ete{
      KDIS::DATA_TYPE::ENUMS::Large};
  EXPECT_NO_THROW(dtIn.SetEntityTrailingEffect(ete));
  EXPECT_EQ(ete, dtIn.GetEntityTrailingEffect());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityCamouflage ec{
      KDIS::DATA_TYPE::ENUMS::DesertCamouflage};
  EXPECT_NO_THROW(dtIn.SetEntityCamouflage(ec));
  EXPECT_EQ(ec, dtIn.GetEntityCamouflage());
  EXPECT_TRUE(dtIn == dtIn);
  // SensorEmitterAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, SimulationIdentifier) {
  KDIS::DATA_TYPE::SimulationIdentifier dtIn;
  EXPECT_TRUE(!(dtIn < dtIn));
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::SimulationIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, SpacePlatformAppearance) {
  KDIS::DATA_TYPE::SpacePlatformAppearance dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::EntityPaintScheme eps{
      KDIS::DATA_TYPE::ENUMS::Camouflage};
  EXPECT_NO_THROW(dtIn.SetEntityPaintScheme(eps));
  EXPECT_EQ(eps, dtIn.GetEntityPaintScheme());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityDamage ed{
      KDIS::DATA_TYPE::ENUMS::ModerateDamage};
  EXPECT_NO_THROW(dtIn.SetEntityDamage(ed));
  EXPECT_EQ(ed, dtIn.GetEntityDamage());
  constexpr KDIS::DATA_TYPE::ENUMS::EntitySmoke es{
      KDIS::DATA_TYPE::ENUMS::EngineSmokeAndSmokePlume};
  EXPECT_NO_THROW(dtIn.SetEntitySmoke(es));
  EXPECT_EQ(es, dtIn.GetEntitySmoke());
  EXPECT_TRUE(dtIn == dtIn);
  // SpacePlatformAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, SubSurfacePlatformAppearance) {
  KDIS::DATA_TYPE::SubSurfacePlatformAppearance dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::EntityPaintScheme eps{
      KDIS::DATA_TYPE::ENUMS::UniformColor};
  EXPECT_NO_THROW(dtIn.SetEntityPaintScheme(eps));
  EXPECT_EQ(eps, dtIn.GetEntityPaintScheme());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityDamage ed{
      KDIS::DATA_TYPE::ENUMS::Destroyed};
  EXPECT_NO_THROW(dtIn.SetEntityDamage(ed));
  EXPECT_EQ(ed, dtIn.GetEntityDamage());
  constexpr KDIS::DATA_TYPE::ENUMS::EntitySmoke es{
      KDIS::DATA_TYPE::ENUMS::NotSmoking};
  EXPECT_NO_THROW(dtIn.SetEntitySmoke(es));
  EXPECT_EQ(es, dtIn.GetEntitySmoke());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityHatchState ehs{
      KDIS::DATA_TYPE::ENUMS::PrimaryHatchIsPoppedPersonVisibleUnderHatch};
  EXPECT_NO_THROW(dtIn.SetEntityHatchState(ehs));
  EXPECT_EQ(ehs, dtIn.GetEntityHatchState());
  EXPECT_TRUE(dtIn == dtIn);
  // SubSurfacePlatformAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, Supplies) {
  KDIS::DATA_TYPE::Supplies dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Supplies dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, SupplyAppearance) {
  KDIS::DATA_TYPE::SupplyAppearance dtIn;
  EXPECT_TRUE(dtIn == dtIn);
  // SupplyAppearance has no Encode/Decode feature
}

TEST(DataType_EncodeDecode5, SurfacePlatformAppearance) {
  KDIS::DATA_TYPE::SurfacePlatformAppearance dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::EntityPaintScheme eps{
      KDIS::DATA_TYPE::ENUMS::Camouflage};
  EXPECT_NO_THROW(dtIn.SetEntityPaintScheme(eps));
  EXPECT_EQ(eps, dtIn.GetEntityPaintScheme());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityDamage ed{
      KDIS::DATA_TYPE::ENUMS::SlightDamage};
  EXPECT_NO_THROW(dtIn.SetEntityDamage(ed));
  EXPECT_EQ(ed, dtIn.GetEntityDamage());
  constexpr KDIS::DATA_TYPE::ENUMS::EntitySmoke es{
      KDIS::DATA_TYPE::ENUMS::SmokePlume};
  EXPECT_NO_THROW(dtIn.SetEntitySmoke(es));
  EXPECT_EQ(es, dtIn.GetEntitySmoke());
  constexpr KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect ete{
      KDIS::DATA_TYPE::ENUMS::Medium};
  EXPECT_NO_THROW(dtIn.SetEntityTrailingEffect(ete));
  EXPECT_EQ(ete, dtIn.GetEntityTrailingEffect());
  EXPECT_TRUE(dtIn == dtIn);
  // SurfacePlatformAppearance has no Encode/Decode feature
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
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::TrackJamTargetIdentifier dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, VariableDatum) {
  KDIS::DATA_TYPE::VariableDatum dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::DatumID did{
      KDIS::DATA_TYPE::ENUMS::UnitNumberID};
  EXPECT_NO_THROW(dtIn.SetDatumID(did));
  EXPECT_EQ(did, dtIn.GetDatumID());
  EXPECT_EQ(0, dtIn.GetDatumLength());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::VariableDatum dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, VariableParameter) {
  KDIS::DATA_TYPE::VariableParameter dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::VariableParameterType vpt{
      KDIS::DATA_TYPE::ENUMS::AttachedPartType};
  EXPECT_NO_THROW(dtIn.SetVariableParameterType(vpt));
  EXPECT_EQ(vpt, dtIn.GetVariableParameterType());
  std::vector<KDIS::KUINT8> vec2big(16);
  std::vector<KDIS::KUINT8> vecgood(15, 42);
  EXPECT_THROW(dtIn.SetData(vec2big.data(), vec2big.size()), KDIS::KException);
  EXPECT_THROW(dtIn.SetData(nullptr, 15), KDIS::KException);
  EXPECT_NO_THROW(dtIn.SetData(vecgood.data(), vecgood.size()));
  KDIS::KUINT8* arrout = dtIn.GetData();
  for (int i = 0; i < vecgood.size(); ++i) {
    EXPECT_EQ(vecgood[i], arrout[i]) << "Arrays differ at index " << i;
  }
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
