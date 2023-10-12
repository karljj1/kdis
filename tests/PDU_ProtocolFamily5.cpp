#include <gtest/gtest.h>

#include <KDIS/PDU/Distributed_Emission_Regeneration/Designator_PDU.hpp>
#include <KDIS/PDU/Distributed_Emission_Regeneration/Electromagnetic_Emission_PDU.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Collision_PDU.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.hpp>
#include <KDIS/PDU/Logistics/Repair_Complete_PDU.hpp>
#include <KDIS/PDU/Logistics/Repair_Response_PDU.hpp>
#include <KDIS/PDU/Logistics/Resupply_Cancel_PDU.hpp>
#include <KDIS/PDU/Logistics/Resupply_Offer_PDU.hpp>
#include <KDIS/PDU/Logistics/Resupply_Received_PDU.hpp>
#include <KDIS/PDU/Logistics/Service_Request_PDU.hpp>
#include <KDIS/PDU/Radio_Communications/Receiver_PDU.hpp>
#include <KDIS/PDU/Radio_Communications/Signal_PDU.hpp>
#include <KDIS/PDU/Radio_Communications/Transmitter_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Acknowledge_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Action_Request_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Action_Response_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Comment_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Create_Entity_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Data_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Data_Query_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Event_Report_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Remove_Entity_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Set_Data_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Start_Resume_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Stop_Freeze_PDU.hpp>
#include <KDIS/PDU/Warfare/Detonation_PDU.hpp>
#include <KDIS/PDU/Warfare/Fire_PDU.hpp>
#include <iostream>

//
// Distributed Emission Regeneration
//
TEST(PDU_ProtocolFamily5, Designator_PDU) {
  KDIS::PDU::Designator_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Distributed_Emission_Regeneration,
      pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Electromagnetic_Emission_PDU) {
  KDIS::PDU::Electromagnetic_Emission_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Distributed_Emission_Regeneration,
      pdu.GetProtocolFamily());
}

//
// Entity Info Interaction
//
TEST(PDU_ProtocolFamily5, Collision_PDU) {
  KDIS::PDU::Collision_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Entity_Information_Interaction,
      pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Entity_State_PDU) {
  KDIS::PDU::Entity_State_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Entity_Information_Interaction,
      pdu.GetProtocolFamily());
}

//
// Logistics
//
TEST(PDU_ProtocolFamily5, Repair_Complete_PDU) {
  KDIS::PDU::Repair_Complete_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Logistics,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Repair_Response_PDU) {
  KDIS::PDU::Repair_Response_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Logistics,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Resupply_Cancel_PDU) {
  KDIS::PDU::Resupply_Cancel_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Logistics,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Resupply_Offer_PDU) {
  KDIS::PDU::Resupply_Offer_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Logistics,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Resupply_Received_PDU) {
  KDIS::PDU::Resupply_Received_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Logistics,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Service_Request_PDU) {
  KDIS::PDU::Service_Request_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Logistics,
            pdu.GetProtocolFamily());
}

//
// Radio Communications
//
TEST(PDU_ProtocolFamily5, Receiver_PDU) {
  KDIS::PDU::Receiver_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Radio_Communications,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Signal_PDU) {
  KDIS::PDU::Signal_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Radio_Communications,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Transmitter_PDU) {
  KDIS::PDU::Transmitter_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Radio_Communications,
            pdu.GetProtocolFamily());
}

//
// Simulation Management
//
TEST(PDU_ProtocolFamily5, Acknowledge_PDU) {
  KDIS::PDU::Acknowledge_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Action_Request_PDU) {
  KDIS::PDU::Action_Request_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Action_Response_PDU) {
  KDIS::PDU::Action_Response_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Comment_PDU) {
  KDIS::PDU::Comment_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Create_Entity_PDU) {
  KDIS::PDU::Create_Entity_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Data_PDU) {
  KDIS::PDU::Data_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Data_Query_PDU) {
  KDIS::PDU::Data_Query_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Event_Report_PDU) {
  KDIS::PDU::Event_Report_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Remove_Entity_PDU) {
  KDIS::PDU::Remove_Entity_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Set_Data_PDU) {
  KDIS::PDU::Set_Data_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Start_Resume_PDU) {
  KDIS::PDU::Start_Resume_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Stop_Freeze_PDU) {
  KDIS::PDU::Stop_Freeze_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Simulation_Management,
            pdu.GetProtocolFamily());
}

//
// Warfare
//
TEST(PDU_ProtocolFamily5, Detonation_PDU) {
  KDIS::PDU::Detonation_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Warfare,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Fire_PDU) {
  KDIS::PDU::Fire_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Warfare,
            pdu.GetProtocolFamily());
}
