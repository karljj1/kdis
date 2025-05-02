#include <gtest/gtest.h>

#include <KDIS/DataTypes/GridDataType2.hpp>
#include <KDIS/DataTypes/VariableDatum.hpp>
#include <KDIS/KDefines.hpp>
#include <KDIS/PDU/Distributed_Emission_Regeneration/IFF_PDU.hpp>
#include <KDIS/PDU/Distributed_Emission_Regeneration/SEES_PDU.hpp>
#include <KDIS/PDU/Distributed_Emission_Regeneration/Underwater_Acoustic_PDU.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Collision_Elastic_PDU.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Entity_State_Update_PDU.hpp>
#include <KDIS/PDU/Entity_Management/Aggregate_State_PDU.hpp>
#include <KDIS/PDU/Entity_Management/IsGroupOf_PDU.hpp>
#include <KDIS/PDU/Entity_Management/IsPartOf_PDU.hpp>
#include <KDIS/PDU/Entity_Management/Transfer_Control_Request_PDU.hpp>
#include <KDIS/PDU/Header6.hpp>
#include <KDIS/PDU/Live_Entity/Appearance_PDU.hpp>
#include <KDIS/PDU/Live_Entity/Articulated_Parts_PDU.hpp>
#include <KDIS/PDU/Live_Entity/LE_Detonation_PDU.hpp>
#include <KDIS/PDU/Live_Entity/LE_Fire_PDU.hpp>
#include <KDIS/PDU/Live_Entity/TSPI_PDU.hpp>
#include <KDIS/PDU/Minefield/Minefield_Data_PDU.hpp>
#include <KDIS/PDU/Minefield/Minefield_Query_PDU.hpp>
#include <KDIS/PDU/Minefield/Minefield_Response_NACK_PDU.hpp>
#include <KDIS/PDU/Minefield/Minefield_State_PDU.hpp>
#include <KDIS/PDU/Radio_Communications/Intercom_Control_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Acknowledge_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Action_Request_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Action_Response_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Comment_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Create_Entity_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Data_Query_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Data_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Event_Report_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Record_Query_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Record_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Remove_Entity_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Set_Data_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Set_Record_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Start_Resume_R_PDU.hpp>
#include <KDIS/PDU/Simulation_Management_With_Reliability/Stop_Freeze_R_PDU.hpp>
#include <KDIS/PDU/Synthetic_Environment/Areal_Object_State_PDU.hpp>
#include <KDIS/PDU/Synthetic_Environment/Environmental_Process_PDU.hpp>
#include <KDIS/PDU/Synthetic_Environment/Gridded_Data_PDU.hpp>
#include <KDIS/PDU/Synthetic_Environment/Linear_Object_State_PDU.hpp>
#include <KDIS/PDU/Synthetic_Environment/Point_Object_State_PDU.hpp>
#include <iostream>

//
// Distributed Emission Regeneration
//
class IFF_PDU_Test : public ::testing::Test {
 protected:
  KDIS::PDU::IFF_PDU pdu;
  KDIS::KDataStream stream;
};

TEST_F(IFF_PDU_Test, GetProtocolFamily) {
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Distributed_Emission_Regeneration,
      pdu.GetProtocolFamily());
}

TEST_F(IFF_PDU_Test, AlternateConstructors) {
  KDIS::PDU::Header hdr;
  EXPECT_NO_THROW(KDIS::PDU::IFF_PDU(hdr));
}

TEST_F(IFF_PDU_Test, SetGetEmittingEntityID) {
  const KDIS::DATA_TYPE::EntityIdentifier eid;
  EXPECT_NO_THROW(pdu.SetEmittingEntityID(eid));
  EXPECT_EQ(eid, pdu.GetEmittingEntityID());
}

TEST_F(IFF_PDU_Test, AddLayer) {
  KDIS::DATA_TYPE::LyrHdrPtr lhp = new KDIS::DATA_TYPE::LayerHeader;
  EXPECT_NO_THROW(pdu.AddLayer(lhp));
}

TEST_F(IFF_PDU_Test, SetGetLayers) {
  KDIS::DATA_TYPE::LyrHdrPtr lhp = new KDIS::DATA_TYPE::LayerHeader;
  const std::vector<KDIS::DATA_TYPE::LyrHdrPtr> vec = {lhp};
  EXPECT_NO_THROW(pdu.SetLayers(vec));
  EXPECT_EQ(vec, pdu.GetLayers());
}

TEST_F(IFF_PDU_Test, ClearLayers) { EXPECT_NO_THROW(pdu.ClearLayers()); }

TEST_F(IFF_PDU_Test, GetAsString) { EXPECT_NO_THROW(pdu.GetAsString()); }

TEST_F(IFF_PDU_Test, EncodeDecode) {
  EXPECT_NO_THROW(pdu.Encode(stream));
  EXPECT_THROW(pdu.Decode(stream),
               KDIS::KException);  // stream too small to decode
}

TEST_F(IFF_PDU_Test, DecodeUnsupported) {
  KDIS::DATA_TYPE::LyrHdrPtr lhp = new KDIS::DATA_TYPE::LayerHeader;
  lhp->SetLayerNumber(5);  // layer number unsupported by IFF_PDU
  EXPECT_NO_THROW(pdu.AddLayer(lhp));
  EXPECT_NO_THROW(pdu.Encode(stream));
  EXPECT_THROW(pdu.Decode(stream),
               KDIS::KException);  // b/c unsupported layer #
}

TEST(PDU_ProtocolFamily6, SEES_PDU) {
  KDIS::PDU::SEES_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Distributed_Emission_Regeneration,
      pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Underwater_Acoustic_PDU) {
  KDIS::PDU::Underwater_Acoustic_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Distributed_Emission_Regeneration,
      pdu.GetProtocolFamily());
  EXPECT_EQ(0, pdu.GetStateUpdateIndicator());
  EXPECT_EQ(0, pdu.GetPassiveParameterIndex());
  EXPECT_EQ(0, pdu.GetPropulsionPlantConfiguration());
  EXPECT_NO_THROW(pdu.GetAsString());
}

//
// Entity Info Interaction
//
TEST(PDU_ProtocolFamily6, Collision_Elastic_PDU) {
  KDIS::PDU::Collision_Elastic_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Entity_Information_Interaction,
      pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Entity_State_Update_PDU) {
  KDIS::PDU::Entity_State_Update_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Entity_Information_Interaction,
      pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.GetAsString());
}

//
// Entity Management
//
class Aggregate_State_PDU_Test : public ::testing::Test {
 protected:
  KDIS::PDU::Aggregate_State_PDU pdu;
};

TEST_F(Aggregate_State_PDU_Test, AlternateConstructors) {
  const KDIS::DATA_TYPE::AggregateIdentifier ai;
  KDIS::DATA_TYPE::ENUMS::ForceID fid{KDIS::DATA_TYPE::ENUMS::Opposing};
  KDIS::DATA_TYPE::ENUMS::AggregateState as{
      KDIS::DATA_TYPE::ENUMS::Disaggregated};
  const KDIS::DATA_TYPE::AggregateType at;
  KDIS::DATA_TYPE::ENUMS::Formation form{KDIS::DATA_TYPE::ENUMS::Vee};
  const KDIS::DATA_TYPE::AggregateMarking am;
  const KDIS::DATA_TYPE::Vector dim;
  const KDIS::DATA_TYPE::EulerAngles eas;
  const KDIS::DATA_TYPE::WorldCoordinates wcs;
  const KDIS::DATA_TYPE::Vector vel;
  EXPECT_NO_THROW(KDIS::PDU::Aggregate_State_PDU(ai, fid, as, at, form, am, dim,
                                                 eas, wcs, vel));
}

TEST_F(Aggregate_State_PDU_Test, GetProtocolFamily) {
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::EntityManagement,
            pdu.GetProtocolFamily());
}

TEST_F(Aggregate_State_PDU_Test, GetProtocolVersion) {
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::IEEE_1278_1A_1998,
            pdu.GetProtocolVersion());
}

TEST_F(Aggregate_State_PDU_Test, GetPDUType) {
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::AggregateState_PDU_Type, pdu.GetPDUType());
}

TEST_F(Aggregate_State_PDU_Test, SetGetForceID) {
  EXPECT_EQ(0, pdu.GetForceID());  // default
  constexpr KDIS::DATA_TYPE::ENUMS::ForceID fid{
      KDIS::DATA_TYPE::ENUMS::Friendly4};
  EXPECT_NO_THROW(pdu.SetForceID(fid));
  EXPECT_EQ(fid, pdu.GetForceID());
}

TEST_F(Aggregate_State_PDU_Test, SetGetAggregateState) {
  EXPECT_EQ(0, pdu.GetAggregateState());  // default
  constexpr KDIS::DATA_TYPE::ENUMS::AggregateState as{
      KDIS::DATA_TYPE::ENUMS::Disaggregated};
  EXPECT_NO_THROW(pdu.SetAggregateState(as));
  EXPECT_EQ(as, pdu.GetAggregateState());
}

TEST_F(Aggregate_State_PDU_Test, SetGetFormation) {
  EXPECT_EQ(0, pdu.GetFormation());  // default
  constexpr KDIS::DATA_TYPE::ENUMS::Formation form{
      KDIS::DATA_TYPE::ENUMS::Wedge};
  EXPECT_NO_THROW(pdu.SetFormation(form));
  EXPECT_EQ(form, pdu.GetFormation());
}

TEST_F(Aggregate_State_PDU_Test, AddVariableDatum) {
  KDIS::DATA_TYPE::VarDtmPtr vdp = new KDIS::DATA_TYPE::VariableDatum;
  EXPECT_NO_THROW(pdu.AddVariableDatum(vdp));
}

TEST_F(Aggregate_State_PDU_Test, SetClearVariableDatumList) {
  KDIS::DATA_TYPE::VarDtmPtr vdp = new KDIS::DATA_TYPE::VariableDatum;
  std::vector<KDIS::DATA_TYPE::VarDtmPtr> vvdp = {vdp};
  EXPECT_NO_THROW(pdu.SetVariableDatumList(vvdp));
  EXPECT_NO_THROW(pdu.ClearVariableDatumList());
}

TEST_F(Aggregate_State_PDU_Test, ClearVariableDatumList) {
  // Clear should also work even if no datum list has been set
  EXPECT_NO_THROW(pdu.ClearVariableDatumList());
}

TEST_F(Aggregate_State_PDU_Test, GetAsString) {
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST(PDU_ProtocolFamily6, IsGroupOf_PDU) {
  KDIS::PDU::IsGroupOf_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::EntityManagement,
            pdu.GetProtocolFamily());
  EXPECT_EQ(0, pdu.GetGroupedEntityCategory());
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST(PDU_ProtocolFamily6, IsPartOf_PDU) {
  KDIS::PDU::IsPartOf_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::EntityManagement,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Transfer_Control_Request_PDU) {
  KDIS::PDU::Transfer_Control_Request_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::EntityManagement,
            pdu.GetProtocolFamily());
  EXPECT_EQ(0, pdu.GetRequiredReliabilityService());
  EXPECT_EQ(0, pdu.GetTransferType());
}

class Header6_Test : public ::testing::Test {
 protected:
  KDIS::PDU::Header6 hdr6;
  KDIS::KDataStream stream;
};

TEST_F(Header6_Test, AlternateConstructors) {
  constexpr KDIS::DATA_TYPE::ENUMS::ProtocolVersion pv{
      KDIS::DATA_TYPE::ENUMS::DIS_PDU_Version_1};
  constexpr KDIS::DATA_TYPE::ENUMS::PDUType pdut{
      KDIS::DATA_TYPE::ENUMS::Data_PDU_Type};
  constexpr KDIS::DATA_TYPE::ENUMS::ProtocolFamily pf{
      KDIS::DATA_TYPE::ENUMS::LiveEntity};
  const KDIS::DATA_TYPE::TimeStamp ts;
  EXPECT_NO_THROW(KDIS::PDU::Header6(pv, 7, pdut, pf, ts, 9));
}

TEST_F(Header6_Test, Decode) {
  EXPECT_THROW(hdr6.Decode(stream),
               KDIS::KException);  // stream not long enough
}

//
// Live Entity
//
TEST(PDU_ProtocolFamily6, Appearance_PDU) {
  KDIS::PDU::Appearance_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::LiveEntity,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.SetForceIDFlag(true));
  EXPECT_TRUE(pdu.GetForceIDFlag());
  EXPECT_NO_THROW(pdu.SetEntityTypeFlag(false));
  EXPECT_TRUE(!pdu.GetEntityTypeFlag());
  EXPECT_NO_THROW(pdu.SetAlternateEntityTypeFlag(true));
  EXPECT_TRUE(pdu.GetAlternateEntityTypeFlag());
  EXPECT_NO_THROW(pdu.SetEntityMarkingFlag(false));
  EXPECT_TRUE(!pdu.GetEntityMarkingFlag());
  EXPECT_NO_THROW(pdu.SetCapabilitiesFlag(true));
  EXPECT_TRUE(pdu.GetCapabilitiesFlag());
  EXPECT_NO_THROW(pdu.SetAppearanceVisualFlag(false));
  EXPECT_TRUE(!pdu.GetAppearanceVisualFlag());
  EXPECT_NO_THROW(pdu.SetAppearanceIRFlag(true));
  EXPECT_TRUE(pdu.GetAppearanceIRFlag());
  EXPECT_NO_THROW(pdu.SetFlag2Flag(false));
  EXPECT_TRUE(!pdu.GetFlag2Flag());
  EXPECT_NO_THROW(pdu.SetAppearanceEMFlag(true));
  EXPECT_TRUE(pdu.GetAppearanceEMFlag());
  EXPECT_NO_THROW(pdu.SetAppearanceAudioFlag(false));
  EXPECT_TRUE(!pdu.GetAppearanceAudioFlag());
  constexpr KDIS::DATA_TYPE::ENUMS::ForceID fid{
      KDIS::DATA_TYPE::ENUMS::OtherForceID};
  EXPECT_NO_THROW(pdu.SetForceID(fid));
  EXPECT_EQ(fid, pdu.GetForceID());
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST(PDU_ProtocolFamily6, Articulated_Parts_PDU) {
  KDIS::PDU::Articulated_Parts_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::LiveEntity,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST(PDU_ProtocolFamily6, LE_Detonation_PDU) {
  KDIS::PDU::LE_Detonation_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::LiveEntity,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.SetTargetEntityIDFlag(true));
  EXPECT_TRUE(pdu.GetTargetEntityIDFlag());
  EXPECT_NO_THROW(pdu.SetMunitionEntityIDFlag(false));
  EXPECT_TRUE(!pdu.GetMunitionEntityIDFlag());
  EXPECT_NO_THROW(pdu.SetMunitionEntityIDSiteAppIncludedFlag(true));
  EXPECT_TRUE(pdu.GetMunitionEntityIDSiteAppIncludedFlag());
  EXPECT_NO_THROW(pdu.SetEventIDSiteAppIncludedFlag(false));
  EXPECT_TRUE(!pdu.GetEventIDSiteAppIncludedFlag());
  EXPECT_NO_THROW(pdu.SetWarheadFuseFlag(true));
  EXPECT_TRUE(pdu.GetWarheadFuseFlag());
  KDIS::KDataStream stream;
  EXPECT_NO_THROW(pdu.Encode(stream));
  EXPECT_NO_THROW(pdu.Decode(stream));
  EXPECT_NO_THROW(pdu.SetQuantityRateFlag(false));
  EXPECT_TRUE(!pdu.GetQuantityRateFlag());
  EXPECT_NO_THROW(pdu.SetLocationInEntityCoordinatesFlag(true));
  EXPECT_TRUE(pdu.GetLocationInEntityCoordinatesFlag());
  EXPECT_NO_THROW(pdu.SetFlag2Flag(false));
  EXPECT_TRUE(!pdu.GetFlag2Flag());
  EXPECT_NO_THROW(pdu.SetMunitionOrientationFlag(true));
  EXPECT_TRUE(pdu.GetMunitionOrientationFlag());
  EXPECT_NO_THROW(pdu.SetEventNumberIncludedFlag(false));
  EXPECT_TRUE(!pdu.GetEventNumberIncludedFlag());
  EXPECT_EQ(0, pdu.GetDetonationResult());
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST(PDU_ProtocolFamily6, LE_Fire_PDU) {
  KDIS::PDU::LE_Fire_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::LiveEntity,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.SetTargetEntityIDFlag(true));
  EXPECT_TRUE(pdu.GetTargetEntityIDFlag());
  EXPECT_NO_THROW(pdu.SetMunitionEntityIDFlag(false));
  EXPECT_TRUE(!pdu.GetMunitionEntityIDFlag());
  EXPECT_NO_THROW(pdu.SetMunitionEntityIDSiteAppIncludedFlag(true));
  EXPECT_TRUE(pdu.GetMunitionEntityIDSiteAppIncludedFlag());
  EXPECT_NO_THROW(pdu.SetEventIDSiteAppIncludedFlag(false));
  EXPECT_TRUE(!pdu.GetEventIDSiteAppIncludedFlag());
  EXPECT_NO_THROW(pdu.SetWarheadFuseFlag(true));
  EXPECT_TRUE(pdu.GetWarheadFuseFlag());
  KDIS::KDataStream stream;
  EXPECT_NO_THROW(pdu.Encode(stream));
  EXPECT_NO_THROW(pdu.Decode(stream));
  EXPECT_NO_THROW(pdu.SetQuantityRateFlag(false));
  EXPECT_TRUE(!pdu.GetQuantityRateFlag());
  EXPECT_NO_THROW(pdu.SetLocationFlag(true));
  EXPECT_TRUE(pdu.GetLocationFlag());
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST(PDU_ProtocolFamily6, TSPI_PDU) {
  KDIS::PDU::TSPI_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::LiveEntity,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.SetEntityLinearVelocityFlag(true));
  EXPECT_TRUE(pdu.GetEntityLinearVelocityFlag());
  EXPECT_NO_THROW(pdu.SetEntityOrientationFlag(false));
  EXPECT_TRUE(!pdu.GetEntityOrientationFlag());
  EXPECT_NO_THROW(pdu.SetPositionErrorFlag(true));
  EXPECT_TRUE(pdu.GetPositionErrorFlag());
  EXPECT_NO_THROW(pdu.SetOrientationErrorFlag(false));
  EXPECT_TRUE(!pdu.GetOrientationErrorFlag());
  EXPECT_NO_THROW(pdu.SetDeadReckoningParameterFlag(true));
  EXPECT_TRUE(pdu.GetDeadReckoningParameterFlag());
  EXPECT_NO_THROW(pdu.SetMeasuredSpeedFlag(false));
  EXPECT_TRUE(!pdu.GetMeasuredSpeedFlag());
  EXPECT_NO_THROW(pdu.SetSystemSpecificDataFlag(true));
  EXPECT_TRUE(pdu.GetSystemSpecificDataFlag());
  EXPECT_NO_THROW(pdu.GetAsString());
}

class Minefield_Data_PDU_Test : public ::testing::Test {
 protected:
  KDIS::PDU::Minefield_Data_PDU pdu;
  KDIS::KDataStream stream;
  KDIS::DATA_TYPE::Mine mn;
  const KDIS::DATA_TYPE::MinefieldDataFilter mdf{
      false, false, false, false,
      false, false, false, true /*TripDetonationWire*/,
      false, false, false};
  const KDIS::DATA_TYPE::EntityIdentifier mfid{7, 4, 44};
  const KDIS::DATA_TYPE::SimulationIdentifier sid{53, 2};
  const KDIS::DATA_TYPE::EntityIdentifier rsid{sid, 18};
  const KDIS::DATA_TYPE::EntityType mineType{
      KDIS::DATA_TYPE::ENUMS::Munition,
      4,
      KDIS::DATA_TYPE::ENUMS::OtherCountry,
      4,
      4,
      4,
      4};
};

TEST_F(Minefield_Data_PDU_Test, AlternateConstructors) {
  EXPECT_NO_THROW(
      KDIS::PDU::Minefield_Data_PDU(mfid, rsid, 14, 2, 3, 8, mdf, mineType));
}

TEST_F(Minefield_Data_PDU_Test, SetGetRequestingSimulationID) {
  EXPECT_NO_THROW(pdu.SetRequestingSimulationID(rsid));
  EXPECT_EQ(rsid, pdu.GetRequestingSimulationID());
}

TEST_F(Minefield_Data_PDU_Test, GetProtocolFamily) {
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Minefield,
            pdu.GetProtocolFamily());
}

TEST_F(Minefield_Data_PDU_Test, GetAsString) {
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST_F(Minefield_Data_PDU_Test, SetDataFilter) {
  EXPECT_NO_THROW(pdu.SetDataFilter(mdf));
}

TEST_F(Minefield_Data_PDU_Test, AddMineWithTripDetonationWire) {
  EXPECT_NO_THROW(pdu.SetDataFilter(mdf));
  const std::vector<KDIS::DATA_TYPE::Vector> vtx = {
      KDIS::DATA_TYPE::Vector(1, 2, 3)};
  EXPECT_NO_THROW(mn.AddTripDetonationWire(vtx));
  EXPECT_NO_THROW(pdu.AddMine(mn));
}

TEST_F(Minefield_Data_PDU_Test, AddMineOptionalFieldsMismatch) {
  EXPECT_NO_THROW(pdu.SetDataFilter(mdf));
  // Don't add a trip detonation wire this time to mn, causing mismatch
  // between
  //    mn and pdu
  EXPECT_THROW(pdu.AddMine(mn), KDIS::KException);
}

TEST_F(Minefield_Data_PDU_Test, SetGetMines) {
  EXPECT_NO_THROW(pdu.SetDataFilter(mdf));
  std::vector<KDIS::DATA_TYPE::Mine> mines{mn};
  // exception on following call because pdu's data filter doesn't match mn's
  EXPECT_THROW(pdu.SetMines(mines), KDIS::KException);
  const std::vector<KDIS::DATA_TYPE::Vector> vtx = {
      KDIS::DATA_TYPE::Vector(1, 2, 3)};
  EXPECT_NO_THROW(mn.AddTripDetonationWire(vtx));
  std::vector<KDIS::DATA_TYPE::Mine> mines2{mn};
  // this time, it should work
  EXPECT_NO_THROW(pdu.SetMines(mines2));
  EXPECT_EQ(mines2, pdu.GetMines());
}

TEST_F(Minefield_Data_PDU_Test, Encode) { EXPECT_NO_THROW(pdu.Encode(stream)); }

TEST_F(Minefield_Data_PDU_Test, EncodeWithScalarDetectionException) {
  EXPECT_NO_THROW(pdu.SetDataFilter(mdf));
  // Make the following call to cause m_ui8NumSensTyp to change from default
  EXPECT_NO_THROW(pdu.AddSensorType(KDIS::DATA_TYPE::ENUMS::Laser_Generic));
  const std::vector<KDIS::DATA_TYPE::Vector> vtx = {
      KDIS::DATA_TYPE::Vector(1, 2, 3)};
  EXPECT_NO_THROW(mn.AddTripDetonationWire(vtx));
  EXPECT_NO_THROW(pdu.AddMine(mn));
  const KDIS::DATA_TYPE::MinefieldDataFilter mdf2{
      false, false, false, false, false,
      false, false, false, false, true /* ScalarDetectionCoefficient*/,
      false};
  // Change the PDU's MinefieldDataFilter to force the
  //    ScalarDetectionCoefficient check
  EXPECT_NO_THROW(pdu.SetDataFilter(mdf2));
  // Exception expected because the mine doesn't have the correct number of
  // SDC
  //    values
  EXPECT_THROW(pdu.Encode(stream), KDIS::KException);
}

TEST(PDU_ProtocolFamily6, Minefield_Query_PDU) {
  KDIS::PDU::Minefield_Query_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Minefield,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST(PDU_ProtocolFamily6, Minefield_Response_NACK_PDU) {
  KDIS::PDU::Minefield_Response_NACK_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Minefield,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.AddMissingPDUSequenceNumber(4));
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST(PDU_ProtocolFamily6, Minefield_State_PDU) {
  KDIS::PDU::Minefield_State_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Minefield,
            pdu.GetProtocolFamily());
  constexpr KDIS::DATA_TYPE::ENUMS::MinefieldProtocolMode mpm{
      KDIS::DATA_TYPE::ENUMS::Heartbeat};
  EXPECT_NO_THROW(pdu.SetMinefieldProtocolMode(mpm));
  EXPECT_EQ(mpm, pdu.GetMinefieldProtocolMode());
  EXPECT_NO_THROW(pdu.GetAsString());
  EXPECT_EQ(0, pdu.GetForceID());
}

TEST(PDU_ProtocolFamily6, Intercom_Control_PDU) {
  KDIS::PDU::Intercom_Control_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Radio_Communications,
            pdu.GetProtocolFamily());
  EXPECT_EQ(0, pdu.GetControlType());
  EXPECT_EQ(0, pdu.GetTransmitLineState());
  EXPECT_EQ(0, pdu.GetLineStateCommand());
  EXPECT_NO_THROW(pdu.GetAsString());
}

//
// Simulation Management With Reliability
//
TEST(PDU_ProtocolFamily6, Acknowledge_R_PDU) {
  KDIS::PDU::Acknowledge_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Action_Request_R_PDU) {
  KDIS::PDU::Action_Request_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Action_Response_R_PDU) {
  KDIS::PDU::Action_Response_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Comment_R_PDU) {
  KDIS::PDU::Comment_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Create_Entity_R_PDU) {
  KDIS::PDU::Create_Entity_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Data_Query_R_PDU) {
  KDIS::PDU::Data_Query_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Data_R_PDU) {
  KDIS::PDU::Data_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Event_Report_R_PDU) {
  KDIS::PDU::Event_Report_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Record_Query_R_PDU) {
  KDIS::PDU::Record_Query_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
  EXPECT_EQ(0, pdu.GetEventType());
}

TEST(PDU_ProtocolFamily6, Record_R_PDU) {
  KDIS::PDU::Record_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
  EXPECT_EQ(0, pdu.GetEventType());
}

TEST(PDU_ProtocolFamily6, Remove_Entity_R_PDU) {
  KDIS::PDU::Remove_Entity_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Set_Data_R_PDU) {
  KDIS::PDU::Set_Data_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Set_Record_R_PDU) {
  KDIS::PDU::Set_Record_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Start_Resume_R_PDU) {
  KDIS::PDU::Start_Resume_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Stop_Freeze_R_PDU) {
  KDIS::PDU::Stop_Freeze_R_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::
                SimulationManagementwithReliability,
            pdu.GetProtocolFamily());
  EXPECT_EQ(0, pdu.GetRequiredReliabilityService());
}

//
// Synthetic Environment
//
TEST(PDU_ProtocolFamily6, Areal_Object_State_PDU) {
  KDIS::PDU::Areal_Object_State_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::SyntheticEnvironment,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.GetAsString());
  EXPECT_EQ(0, pdu.GetForceID());
}

TEST(PDU_ProtocolFamily6, Environmental_Process_PDU) {
  KDIS::PDU::Environmental_Process_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::SyntheticEnvironment,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.GetAsString());
}

class Gridded_Data_PDU_Test : public ::testing::Test {
 protected:
  KDIS::PDU::Gridded_Data_PDU pdu;
  KDIS::KDataStream stream;
  const KDIS::DATA_TYPE::EntityIdentifier eid;
};

TEST_F(Gridded_Data_PDU_Test, AlternateConstructors) {
  EXPECT_NO_THROW(KDIS::PDU::Gridded_Data_PDU(
      eid, 1, 2, 3, KDIS::DATA_TYPE::ENUMS::LatLonDepth,
      KDIS::DATA_TYPE::ENUMS::Updated, KDIS::DATA_TYPE::EnvironmentType(),
      KDIS::DATA_TYPE::EulerAngles(), 54));
}

TEST_F(Gridded_Data_PDU_Test, GetProtocolFamily) {
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::SyntheticEnvironment,
            pdu.GetProtocolFamily());
}

TEST_F(Gridded_Data_PDU_Test, SetGetEnvironmentalProcessID) {
  EXPECT_NO_THROW(pdu.SetEnvironmentalProcessID(eid));
  EXPECT_EQ(eid, pdu.GetEnvironmentalProcessID());
}

TEST_F(Gridded_Data_PDU_Test, SetPDUNumberAndTotal) {
  EXPECT_THROW(pdu.SetPDUNumberAndTotal(5, 4), KDIS::KException);
  EXPECT_NO_THROW(pdu.SetPDUNumberAndTotal(4, 5));
}

TEST_F(Gridded_Data_PDU_Test, GetCoordinateSystem) {
  EXPECT_EQ(0, pdu.GetCoordinateSystem());
}

TEST_F(Gridded_Data_PDU_Test, GetConstantGrid) {
  EXPECT_EQ(0, pdu.GetConstantGrid());
}

TEST_F(Gridded_Data_PDU_Test, SetGetGridAxisDescriptors) {
  KDIS::DATA_TYPE::GridAxisDescriptor gad =
      new KDIS::DATA_TYPE::GridAxisRegular;
  const std::vector<KDIS::DATA_TYPE::GridAxisDescriptor> gads = {gad};
  EXPECT_NO_THROW(pdu.SetGridAxisDescriptors(gads));
  EXPECT_EQ(gads, pdu.GetGridAxisDescriptors());
  // exercise GetAsString with non-empty grid axis descriptors
  EXPECT_NO_THROW(pdu.GetAsString());
  // exercise Encode with non-empty grid axis descriptors
  EXPECT_NO_THROW(pdu.Encode(stream));
}

TEST_F(Gridded_Data_PDU_Test, SetGetGridData) {
  KDIS::DATA_TYPE::GridDataPtr gdt0 = new KDIS::DATA_TYPE::GridDataType0;
  const std::vector<KDIS::DATA_TYPE::GridDataPtr> gds = {gdt0};
  EXPECT_NO_THROW(pdu.SetGridData(gds));
  EXPECT_EQ(gds, pdu.GetGridData());
  // exercise GetAsString with non-empty grid data
  EXPECT_NO_THROW(pdu.GetAsString());
  // exercise Encode with non-empty grid data
  EXPECT_NO_THROW(pdu.Encode(stream));
}

TEST_F(Gridded_Data_PDU_Test, GetAsStringBasic) {
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST_F(Gridded_Data_PDU_Test, DecodeStreamTooSmall) {
  EXPECT_THROW(pdu.Decode(stream), KDIS::KException);
}

TEST_F(Gridded_Data_PDU_Test, EncodeDecodeRoundTrip) {
  EXPECT_NO_THROW(pdu.Encode(stream));
  EXPECT_NO_THROW(pdu.Decode(stream, false));
}

TEST_F(Gridded_Data_PDU_Test, EncodeDecodeBadGridData) {
  KDIS::KDataStream stream2;
  stream2 << 0x0000;
  // the second parameter in the GridDataType2 c'tor will be unacceptable at
  // the
  //    pdu.Decode step below
  KDIS::DATA_TYPE::GridDataPtr gdt2Bad =
      new KDIS::DATA_TYPE::GridDataType2(0, 3, stream2);
  // assign the malformed GridDataPtr to the PDU
  EXPECT_NO_THROW(pdu.AddGridData(gdt2Bad));
  EXPECT_NO_THROW(pdu.Encode(stream));
  EXPECT_THROW(pdu.Decode(stream, false), KDIS::KException);
}

TEST(PDU_ProtocolFamily6, Linear_Object_State_PDU) {
  KDIS::PDU::Linear_Object_State_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::SyntheticEnvironment,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Point_Object_State_PDU) {
  KDIS::PDU::Point_Object_State_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::SyntheticEnvironment,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.GetAsString());
}
