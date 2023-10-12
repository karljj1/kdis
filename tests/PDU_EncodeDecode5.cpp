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
TEST(PDU_EncodeDecode5, Designator_PDU) {
  KDIS::PDU::Designator_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Designator_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Electromagnetic_Emission_PDU) {
  KDIS::PDU::Electromagnetic_Emission_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Electromagnetic_Emission_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Entity Info Interaction
//
TEST(PDU_EncodeDecode5, Collision_PDU) {
  KDIS::PDU::Collision_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Collision_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Entity_State_PDU) {
  KDIS::PDU::Entity_State_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Entity_State_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Logistics
//
TEST(PDU_EncodeDecode5, Repair_Complete_PDU) {
  KDIS::PDU::Repair_Complete_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Repair_Complete_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Repair_Response_PDU) {
  KDIS::PDU::Repair_Response_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Repair_Response_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Resupply_Cancel_PDU) {
  KDIS::PDU::Resupply_Cancel_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Resupply_Cancel_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Resupply_Offer_PDU) {
  KDIS::PDU::Resupply_Offer_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Resupply_Offer_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Resupply_Received_PDU) {
  KDIS::PDU::Resupply_Received_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Resupply_Received_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Service_Request_PDU) {
  KDIS::PDU::Service_Request_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Service_Request_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Radio Communications
//
TEST(PDU_EncodeDecode5, Receiver_PDU) {
  KDIS::PDU::Receiver_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Receiver_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Signal_PDU) {
  KDIS::PDU::Signal_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Signal_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Transmitter_PDU) {
  KDIS::PDU::Transmitter_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Transmitter_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Simulation Management
//
TEST(PDU_EncodeDecode5, Acknowledge_PDU) {
  KDIS::PDU::Acknowledge_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Acknowledge_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Action_Request_PDU) {
  KDIS::PDU::Action_Request_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Action_Request_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Action_Response_PDU) {
  KDIS::PDU::Action_Response_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Action_Response_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Comment_PDU) {
  KDIS::PDU::Comment_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Comment_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Create_Entity_PDU) {
  KDIS::PDU::Create_Entity_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Create_Entity_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Data_PDU) {
  KDIS::PDU::Data_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Data_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Data_Query_PDU) {
  KDIS::PDU::Data_Query_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Data_Query_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Event_Report_PDU) {
  KDIS::PDU::Event_Report_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Event_Report_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Remove_Entity_PDU) {
  KDIS::PDU::Remove_Entity_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Remove_Entity_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Set_Data_PDU) {
  KDIS::PDU::Set_Data_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Set_Data_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Start_Resume_PDU) {
  KDIS::PDU::Start_Resume_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Start_Resume_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Stop_Freeze_PDU) {
  KDIS::PDU::Stop_Freeze_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Stop_Freeze_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Warfare
//
TEST(PDU_EncodeDecode5, Detonation_PDU) {
  KDIS::PDU::Detonation_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Detonation_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Fire_PDU) {
  KDIS::PDU::Fire_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Fire_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}
