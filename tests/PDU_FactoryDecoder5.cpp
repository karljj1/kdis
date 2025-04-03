#include <gtest/gtest.h>

#include <KDIS/Extras/PDU_Factory.hpp>
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
TEST(PDU_FactoryDecoder5, Designator_PDU) {
  KDIS::PDU::Designator_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetDesignatorCodeName());
  EXPECT_EQ(0, pduIn.GetDesignatorCode());
  EXPECT_EQ(0, pduIn.GetDeadReckoningAlgorithm());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Designator_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Electromagnetic_Emission_PDU) {
  KDIS::PDU::Electromagnetic_Emission_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetStateUpdateIndicator());
  EXPECT_NO_THROW(pduIn.GetAsString());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Electromagnetic_Emission_PDU*>(
                       pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Entity Info Interaction
//
TEST(PDU_FactoryDecoder5, Collision_PDU) {
  KDIS::PDU::Collision_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetCollisionType());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Collision_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Entity_State_PDU) {
  KDIS::PDU::Entity_State_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetForceID());
  EXPECT_NO_THROW(pduIn.GetAsString());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Entity_State_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

class Entity_State_PDU_Test : public ::testing::Test {
 protected:
  const KDIS::DATA_TYPE::EntityIdentifier eid{};
  const KDIS::DATA_TYPE::ENUMS::ForceID fid{KDIS::DATA_TYPE::ENUMS::Friendly7};
  const KDIS::DATA_TYPE::EntityType ety{};
  const KDIS::DATA_TYPE::EntityType aty{};
  const KDIS::DATA_TYPE::Vector vec{};
  const KDIS::DATA_TYPE::WorldCoordinates wco{};
  const KDIS::DATA_TYPE::EulerAngles ean{};
  const KDIS::DATA_TYPE::EntityAppearance eap{};
  const KDIS::DATA_TYPE::DeadReckoningParameter drp{};
  const KDIS::DATA_TYPE::EntityMarking emk{};
  const KDIS::DATA_TYPE::EntityCapabilities ecp{};
};

TEST_F(Entity_State_PDU_Test, ApplyDeadReckoning) {
  KDIS::PDU::Entity_State_PDU pdu;
  EXPECT_THROW(pdu.ApplyDeadReckoning(37.2), KDIS::KException);
}

TEST_F(Entity_State_PDU_Test, AlternateConstructor) {
  EXPECT_NO_THROW(KDIS::PDU::Entity_State_PDU(eid, fid, ety, aty, vec, wco, ean,
                                              eap, drp, emk, ecp));
}

//
// Logistics
//
TEST(PDU_FactoryDecoder5, Repair_Complete_PDU) {
  KDIS::PDU::Repair_Complete_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetRepairTypePerformed());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn,
            *dynamic_cast<KDIS::PDU::Repair_Complete_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Repair_Response_PDU) {
  KDIS::PDU::Repair_Response_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetRepairResult());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn,
            *dynamic_cast<KDIS::PDU::Repair_Response_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Resupply_Cancel_PDU) {
  KDIS::PDU::Resupply_Cancel_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn,
            *dynamic_cast<KDIS::PDU::Resupply_Cancel_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Resupply_Offer_PDU) {
  KDIS::PDU::Resupply_Offer_PDU pduIn;
  EXPECT_NO_THROW(pduIn.GetAsString());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Resupply_Offer_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Resupply_Received_PDU) {
  KDIS::PDU::Resupply_Received_PDU pduIn;
  EXPECT_NO_THROW(pduIn.GetAsString());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn,
            *dynamic_cast<KDIS::PDU::Resupply_Received_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Service_Request_PDU) {
  KDIS::PDU::Service_Request_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetServiceTypeRequested());
  EXPECT_NO_THROW(pduIn.GetAsString());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn,
            *dynamic_cast<KDIS::PDU::Service_Request_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Radio Communications
//
TEST(PDU_FactoryDecoder5, Receiver_PDU) {
  KDIS::PDU::Receiver_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetReceiverState());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Receiver_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Signal_PDU) {
  KDIS::PDU::Signal_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Signal_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Transmitter_PDU) {
  KDIS::PDU::Transmitter_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetTransmitState());
  EXPECT_EQ(0, pduIn.GetInputSource());
  EXPECT_EQ(0, pduIn.GetAntennaPatternType());
  EXPECT_NO_THROW(pduIn.GetAsString());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Transmitter_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Simulation Management
//
TEST(PDU_FactoryDecoder5, Acknowledge_PDU) {
  KDIS::PDU::Acknowledge_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetAcknowledgeFlag());
  EXPECT_EQ(0, pduIn.GetAcknowledgeResponseFlag());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Acknowledge_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Action_Request_PDU) {
  KDIS::PDU::Action_Request_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetActionID());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Action_Request_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Action_Response_PDU) {
  KDIS::PDU::Action_Response_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetRequestStatus());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn,
            *dynamic_cast<KDIS::PDU::Action_Response_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Comment_PDU) {
  KDIS::PDU::Comment_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Comment_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Create_Entity_PDU) {
  KDIS::PDU::Create_Entity_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Create_Entity_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Data_PDU) {
  KDIS::PDU::Data_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Data_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Data_Query_PDU) {
  KDIS::PDU::Data_Query_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Data_Query_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Event_Report_PDU) {
  KDIS::PDU::Event_Report_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetEventType());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Event_Report_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Remove_Entity_PDU) {
  KDIS::PDU::Remove_Entity_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Remove_Entity_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Set_Data_PDU) {
  KDIS::PDU::Set_Data_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Set_Data_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Start_Resume_PDU) {
  KDIS::PDU::Start_Resume_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Start_Resume_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Stop_Freeze_PDU) {
  KDIS::PDU::Stop_Freeze_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetReason());
  EXPECT_EQ(0, pduIn.GetFrozenBehavior());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Stop_Freeze_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Warfare
//
TEST(PDU_FactoryDecoder5, Detonation_PDU) {
  KDIS::PDU::Detonation_PDU pduIn;
  EXPECT_EQ(0, pduIn.GetDetonationResult());
  EXPECT_NO_THROW(pduIn.GetAsString());
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Detonation_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Fire_PDU) {
  KDIS::PDU::Fire_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::UTILS::PDU_Factory factory;
  std::unique_ptr<KDIS::PDU::Header> pduOut = factory.Decode(stream);
  EXPECT_EQ(pduIn, *dynamic_cast<KDIS::PDU::Fire_PDU*>(pduOut.get()));
  EXPECT_EQ(0, stream.GetBufferSize());
}
