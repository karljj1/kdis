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

template <typename T>
class EncodeDecodeTest5 : public ::testing::Test {
 public:
  void TestEncodeDecode() {
    T pduIn;
    KDIS::KDataStream stream = pduIn.Encode();
    T pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
  }

  void TestEncodeDecodeIgnoreHeader() {
    T pduIn;
    KDIS::KDataStream stream = pduIn.Encode();

    KDIS::PDU::Header hdr(stream);
    T pduOut(hdr, stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
  }
};

typedef ::testing::Types < KDIS::PDU::Designator_PDU,
    KDIS::PDU::Electromagnetic_Emission_PDU, KDIS::PDU::Collision_PDU,
    KDIS::PDU::Entity_State_PDU, KDIS::PDU::Repair_Complete_PDU,
    KDIS::PDU::Repair_Response_PDU, KDIS::PDU::Resupply_Cancel_PDU,
    KDIS::PDU::Resupply_Offer_PDU, KDIS::PDU::Resupply_Received_PDU,
    KDIS::PDU::Service_Request_PDU, KDIS::PDU::Receiver_PDU,
    KDIS::PDU::Signal_PDU, KDIS::PDU::Transmitter_PDU,
    KDIS::PDU::Acknowledge_PDU, KDIS::PDU::Action_Request_PDU,
    KDIS::PDU::Action_Response_PDU, KDIS::PDU::Comment_PDU,
    KDIS::PDU::Create_Entity_PDU, KDIS::PDU::Data_PDU,
    KDIS::PDU::Data_Query_PDU, KDIS::PDU::Event_Report_PDU,
    KDIS::PDU::Remove_Entity_PDU, KDIS::PDU::Set_Data_PDU,
    KDIS::PDU::Start_Resume_PDU, KDIS::PDU::Stop_Freeze_PDU,
    KDIS::PDU::Detonation_PDU, KDIS::PDU::Fire_PDU>
    PduTestTypes5;

TYPED_TEST_SUITE(EncodeDecodeTest5, PduTestTypes5);

TYPED_TEST(EncodeDecodeTest5, PDU_PduTestTypes5) { this->TestEncodeDecode(); }

TYPED_TEST(EncodeDecodeTest5, PDU_PduTestTypes5_IgnoreHeader) {
  this->TestEncodeDecodeIgnoreHeader();
}
