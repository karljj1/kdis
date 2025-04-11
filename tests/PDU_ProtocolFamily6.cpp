#include <gtest/gtest.h>

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
TEST(PDU_ProtocolFamily6, IFF_PDU) {
  KDIS::PDU::IFF_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Distributed_Emission_Regeneration,
      pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.GetAsString());
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
TEST(PDU_ProtocolFamily6, Aggregate_State_PDU) {
  KDIS::PDU::Aggregate_State_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::EntityManagement,
            pdu.GetProtocolFamily());
  EXPECT_EQ(0, pdu.GetForceID());
  EXPECT_EQ(0, pdu.GetAggregateState());
  EXPECT_EQ(0, pdu.GetFormation());
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::IEEE_1278_1A_1998,
            pdu.GetProtocolVersion());
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::AggregateState_PDU_Type, pdu.GetPDUType());
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

TEST(PDU_ProtocolFamily6, Minefield_Data_PDU) {
  KDIS::PDU::Minefield_Data_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Minefield,
            pdu.GetProtocolFamily());
  EXPECT_NO_THROW(pdu.GetAsString());
  const KDIS::DATA_TYPE::MinefieldDataFilter mdf{
      false, false, false, false,
      false, false, false, true /*TripDetonationWire*/,
      false, false, false};
  EXPECT_NO_THROW(pdu.SetDataFilter(mdf));
  KDIS::DATA_TYPE::Mine mn;
  const std::vector<KDIS::DATA_TYPE::Vector> vtx = {
      KDIS::DATA_TYPE::Vector(1, 2, 3)};
  EXPECT_NO_THROW(mn.AddTripDetonationWire(vtx));
  EXPECT_NO_THROW(pdu.AddMine(mn));
  KDIS::KDataStream stream;
  EXPECT_NO_THROW(pdu.Encode(stream));
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
};

TEST_F(Gridded_Data_PDU_Test, GetProtocolFamily) {
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::SyntheticEnvironment,
            pdu.GetProtocolFamily());
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

TEST_F(Gridded_Data_PDU_Test, GetAsString) {
  EXPECT_NO_THROW(pdu.GetAsString());
}

TEST_F(Gridded_Data_PDU_Test, DecodeStreamTooSmall) {
  EXPECT_THROW(pdu.Decode(stream), KDIS::KException);
}

TEST_F(Gridded_Data_PDU_Test, EncodeDecodeRoundTrip) {
  EXPECT_NO_THROW(pdu.Encode(stream));
  EXPECT_NO_THROW(pdu.Decode(stream, false));
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
