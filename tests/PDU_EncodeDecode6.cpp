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
#include <KDIS/PDU/Radio_Communications/Intercom_Control_PDU.hpp>
#include <KDIS/PDU/Radio_Communications/Intercom_Signal_PDU.hpp>
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

template <typename T>
class EncodeDecodeTest6 : public ::testing::Test {
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

typedef ::testing::Types<
    KDIS::PDU::SEES_PDU, KDIS::PDU::Underwater_Acoustic_PDU,
    KDIS::PDU::Collision_Elastic_PDU, KDIS::PDU::Entity_State_Update_PDU,
    KDIS::PDU::Aggregate_State_PDU, KDIS::PDU::IsGroupOf_PDU,
    KDIS::PDU::IsPartOf_PDU, KDIS::PDU::Transfer_Control_Request_PDU,
    KDIS::PDU::Appearance_PDU, KDIS::PDU::Articulated_Parts_PDU,
    KDIS::PDU::LE_Detonation_PDU, KDIS::PDU::LE_Fire_PDU, KDIS::PDU::TSPI_PDU,
    KDIS::PDU::Minefield_Data_PDU, KDIS::PDU::Intercom_Signal_PDU,
    KDIS::PDU::Intercom_Control_PDU, KDIS::PDU::Acknowledge_R_PDU,
    KDIS::PDU::Action_Request_R_PDU, KDIS::PDU::Action_Response_R_PDU,
    KDIS::PDU::Comment_R_PDU, KDIS::PDU::Create_Entity_R_PDU,
    KDIS::PDU::Data_Query_R_PDU, KDIS::PDU::Data_R_PDU,
    KDIS::PDU::Event_Report_R_PDU, KDIS::PDU::Record_Query_R_PDU,
    KDIS::PDU::Record_R_PDU, KDIS::PDU::Remove_Entity_R_PDU,
    KDIS::PDU::Set_Data_R_PDU, KDIS::PDU::Set_Record_R_PDU,
    KDIS::PDU::Start_Resume_R_PDU, KDIS::PDU::Stop_Freeze_R_PDU,
    KDIS::PDU::Areal_Object_State_PDU, KDIS::PDU::Environmental_Process_PDU,
    KDIS::PDU::Gridded_Data_PDU, KDIS::PDU::Linear_Object_State_PDU,
    KDIS::PDU::Point_Object_State_PDU>
    PduTestTypes6;

TYPED_TEST_SUITE(EncodeDecodeTest6, PduTestTypes6);

TYPED_TEST(EncodeDecodeTest6, PDU_EncodeDecode6) { this->TestEncodeDecode(); }

TYPED_TEST(EncodeDecodeTest6, PDU_EncodeDecode6_IgnoreHeader) {
  this->TestEncodeDecodeIgnoreHeader();
}
