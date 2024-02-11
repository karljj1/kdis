#include <gtest/gtest.h>

#include <KDIS/PDU/Distributed_Emission_Regeneration/Designator_PDU.hpp>
#include <KDIS/PDU/Distributed_Emission_Regeneration/Electromagnetic_Emission_PDU.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Collision_PDU.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.hpp>
#include <KDIS/PDU/Header.hpp>
#include <KDIS/PDU/Logistics/Logistics_Header.hpp>
#include <KDIS/PDU/Logistics/Repair_Complete_PDU.hpp>
#include <KDIS/PDU/Logistics/Repair_Response_PDU.hpp>
#include <KDIS/PDU/Logistics/Resupply_Cancel_PDU.hpp>
#include <KDIS/PDU/Logistics/Resupply_Offer_PDU.hpp>
#include <KDIS/PDU/Logistics/Resupply_Received_PDU.hpp>
#include <KDIS/PDU/Logistics/Service_Request_PDU.hpp>
#include <KDIS/PDU/Radio_Communications/Radio_Communications_Header.hpp>
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
#include <KDIS/PDU/Simulation_Management/Simulation_Management_Header.hpp>
#include <KDIS/PDU/Simulation_Management/Start_Resume_PDU.hpp>
#include <KDIS/PDU/Simulation_Management/Stop_Freeze_PDU.hpp>
#include <KDIS/PDU/Warfare/Detonation_PDU.hpp>
#include <KDIS/PDU/Warfare/Fire_PDU.hpp>
#include <KDIS/PDU/Warfare/Warfare_Header.hpp>

#if DIS_VERSION >= 6
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
  #include <KDIS/PDU/Live_Entity/LE_Header.hpp>
  #include <KDIS/PDU/Live_Entity/TSPI_PDU.hpp>
  #include <KDIS/PDU/Minefield/Minefield_Data_PDU.hpp>
  #include <KDIS/PDU/Minefield/Minefield_Header.hpp>
  #include <KDIS/PDU/Minefield/Minefield_Query_PDU.hpp>
  #include <KDIS/PDU/Minefield/Minefield_Response_NACK_PDU.hpp>
  #include <KDIS/PDU/Minefield/Minefield_State_PDU.hpp>
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
  // #include
  // <KDIS/PDU/Simulation_Management_With_Reliability/Reliability_Header.hpp>
  #include <KDIS/PDU/Simulation_Management_With_Reliability/Remove_Entity_R_PDU.hpp>
  #include <KDIS/PDU/Simulation_Management_With_Reliability/Set_Data_R_PDU.hpp>
  #include <KDIS/PDU/Simulation_Management_With_Reliability/Set_Record_R_PDU.hpp>
  #include <KDIS/PDU/Simulation_Management_With_Reliability/Start_Resume_R_PDU.hpp>
  #include <KDIS/PDU/Simulation_Management_With_Reliability/Stop_Freeze_R_PDU.hpp>
  #include <KDIS/PDU/Synthetic_Environment/Areal_Object_State_PDU.hpp>
  #include <KDIS/PDU/Synthetic_Environment/Environmental_Process_PDU.hpp>
  #include <KDIS/PDU/Synthetic_Environment/Gridded_Data_PDU.hpp>
  #include <KDIS/PDU/Synthetic_Environment/Linear_Object_State_PDU.hpp>
  #include <KDIS/PDU/Synthetic_Environment/Object_State_Header.hpp>
  #include <KDIS/PDU/Synthetic_Environment/Point_Object_State_PDU.hpp>
#endif

#if DIS_VERSION >= 7
  #include <KDIS/PDU/Entity_Info_Interaction/Attribute_PDU.hpp>
  #include <KDIS/PDU/Header7.hpp>
  #include <KDIS/PDU/Information_Operations/IO_Action_PDU.hpp>
  #include <KDIS/PDU/Information_Operations/IO_Header.hpp>
  #include <KDIS/PDU/Information_Operations/IO_Report_PDU.hpp>
  #include <KDIS/PDU/Warfare/Directed_Energy_Fire_PDU.hpp>
  #include <KDIS/PDU/Warfare/Entity_Damage_Status_PDU.hpp>
#endif

#include <iostream>
#include <type_traits>

template <typename T>
class CloneTest : public ::testing::Test {
 public:
  void Test() {
    T pdu;
    pdu.SetExerciseID(123);
    auto clone = KDIS::PDU::clone(pdu);
    EXPECT_TRUE((std::is_same<std::unique_ptr<T>, decltype(clone)>::value));
    EXPECT_EQ(pdu.GetExerciseID(), clone->GetExerciseID());
    EXPECT_EQ(pdu, *clone);
    clone->SetExerciseID(246);
    EXPECT_NE(pdu.GetExerciseID(), clone->GetExerciseID());
    EXPECT_NE(pdu, *clone);
  }
};

typedef ::testing::Types<
#if DIS_VERSION >= 6
    KDIS::PDU::Header6, KDIS::PDU::IFF_PDU, KDIS::PDU::SEES_PDU,
    KDIS::PDU::Underwater_Acoustic_PDU, KDIS::PDU::Collision_Elastic_PDU,
    KDIS::PDU::Entity_State_Update_PDU, KDIS::PDU::Aggregate_State_PDU,
    KDIS::PDU::IsGroupOf_PDU, KDIS::PDU::IsPartOf_PDU,
    KDIS::PDU::Transfer_Control_Request_PDU, KDIS::PDU::Appearance_PDU,
    KDIS::PDU::Articulated_Parts_PDU, KDIS::PDU::LE_Detonation_PDU,
    KDIS::PDU::LE_Header, KDIS::PDU::LE_Fire_PDU, KDIS::PDU::TSPI_PDU,
    KDIS::PDU::Minefield_Data_PDU, KDIS::PDU::Minefield_Header,
    KDIS::PDU::Minefield_Query_PDU, KDIS::PDU::Minefield_Response_NACK_PDU,
    KDIS::PDU::Minefield_State_PDU, KDIS::PDU::Intercom_Control_PDU,
    KDIS::PDU::Intercom_Signal_PDU, KDIS::PDU::Acknowledge_R_PDU,
    KDIS::PDU::Action_Request_R_PDU, KDIS::PDU::Action_Response_R_PDU,
    KDIS::PDU::Comment_R_PDU, KDIS::PDU::Create_Entity_R_PDU,
    KDIS::PDU::Data_Query_R_PDU, KDIS::PDU::Data_R_PDU,
    KDIS::PDU::Event_Report_R_PDU, KDIS::PDU::Record_Query_R_PDU,
    KDIS::PDU::Record_R_PDU, /*KDIS::PDU::Reliability_Header,*/
    KDIS::PDU::Remove_Entity_R_PDU, KDIS::PDU::Set_Data_R_PDU,
    KDIS::PDU::Set_Record_R_PDU, KDIS::PDU::Start_Resume_R_PDU,
    KDIS::PDU::Stop_Freeze_R_PDU, KDIS::PDU::Areal_Object_State_PDU,
    KDIS::PDU::Environmental_Process_PDU, KDIS::PDU::Gridded_Data_PDU,
    KDIS::PDU::Linear_Object_State_PDU, KDIS::PDU::Object_State_Header,
    KDIS::PDU::Point_Object_State_PDU,
#endif
#if DIS_VERSION >= 7
    KDIS::PDU::Header7, KDIS::PDU::Attribute_PDU,
    KDIS::PDU::Directed_Energy_Fire_PDU, KDIS::PDU::Entity_Damage_Status_PDU,
    KDIS::PDU::IO_Header, KDIS::PDU::IO_Action_PDU, KDIS::PDU::IO_Report_PDU,
#endif
    KDIS::PDU::Header, KDIS::PDU::Designator_PDU,
    KDIS::PDU::Electromagnetic_Emission_PDU, KDIS::PDU::Collision_PDU,
    KDIS::PDU::Entity_State_PDU, KDIS::PDU::Logistics_Header,
    KDIS::PDU::Repair_Complete_PDU, KDIS::PDU::Repair_Response_PDU,
    KDIS::PDU::Resupply_Cancel_PDU, KDIS::PDU::Resupply_Offer_PDU,
    KDIS::PDU::Resupply_Received_PDU, KDIS::PDU::Service_Request_PDU,
    KDIS::PDU::Radio_Communications_Header, KDIS::PDU::Receiver_PDU,
    KDIS::PDU::Signal_PDU, KDIS::PDU::Transmitter_PDU,
    KDIS::PDU::Acknowledge_PDU, KDIS::PDU::Action_Request_PDU,
    KDIS::PDU::Action_Response_PDU, KDIS::PDU::Comment_PDU,
    KDIS::PDU::Create_Entity_PDU, KDIS::PDU::Data_PDU,
    KDIS::PDU::Data_Query_PDU, KDIS::PDU::Event_Report_PDU,
    KDIS::PDU::Remove_Entity_PDU, KDIS::PDU::Set_Data_PDU,
    KDIS::PDU::Simulation_Management_Header, KDIS::PDU::Start_Resume_PDU,
    KDIS::PDU::Stop_Freeze_PDU, KDIS::PDU::Detonation_PDU, KDIS::PDU::Fire_PDU,
    KDIS::PDU::Warfare_Header>
    PduTestTypes;

TYPED_TEST_SUITE(CloneTest, PduTestTypes);
TYPED_TEST(CloneTest, PDUClone) { this->Test(); }
