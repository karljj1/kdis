#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/PDU/Distributed_Emission_Regeneration/Designator_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/Electromagnetic_Emission_PDU.h"

#include "KDIS/PDU/Entity_Info_Interaction/Collision_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.h"

#include "KDIS/PDU/Logistics/Repair_Complete_PDU.h"
#include "KDIS/PDU/Logistics/Repair_Response_PDU.h"
#include "KDIS/PDU/Logistics/Resupply_Cancel_PDU.h"
#include "KDIS/PDU/Logistics/Resupply_Offer_PDU.h"
#include "KDIS/PDU/Logistics/Resupply_Received_PDU.h"
#include "KDIS/PDU/Logistics/Service_Request_PDU.h"

#include "KDIS/PDU/Radio_Communications/Receiver_PDU.h"
#include "KDIS/PDU/Radio_Communications/Signal_PDU.h"
#include "KDIS/PDU/Radio_Communications/Transmitter_PDU.h"

#include "KDIS/PDU/Simulation_Management/Acknowledge_PDU.h"
#include "KDIS/PDU/Simulation_Management/Action_Request_PDU.h"
#include "KDIS/PDU/Simulation_Management/Action_Response_PDU.h"
#include "KDIS/PDU/Simulation_Management/Comment_PDU.h"
#include "KDIS/PDU/Simulation_Management/Create_Entity_PDU.h"
#include "KDIS/PDU/Simulation_Management/Data_PDU.h"
#include "KDIS/PDU/Simulation_Management/Data_Query_PDU.h"
#include "KDIS/PDU/Simulation_Management/Event_Report_PDU.h"
#include "KDIS/PDU/Simulation_Management/Remove_Entity_PDU.h"
#include "KDIS/PDU/Simulation_Management/Set_Data_PDU.h"
#include "KDIS/PDU/Simulation_Management/Start_Resume_PDU.h"
#include "KDIS/PDU/Simulation_Management/Stop_Freeze_PDU.h"

#include "KDIS/PDU/Warfare/Detonation_PDU.h"
#include "KDIS/PDU/Warfare/Fire_PDU.h"

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE::ENUMS;

//////////////////////////////////////////////////////////////////////////
// Distributed Emission Regeneration
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily5, Designator_PDU)
{
    Designator_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Distributed_Emission_Regeneration, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Electromagnetic_Emission_PDU)
{
    Electromagnetic_Emission_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Distributed_Emission_Regeneration, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Entity Info Interaction
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily5, Collision_PDU)
{
    Collision_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Entity_Information_Interaction, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Entity_State_PDU)
{
    Entity_State_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Entity_Information_Interaction, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Logistics
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily5, Repair_Complete_PDU)
{
    Repair_Complete_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Logistics, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Repair_Response_PDU)
{
    Repair_Response_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Logistics, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Resupply_Cancel_PDU)
{
    Resupply_Cancel_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Logistics, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Resupply_Offer_PDU)
{
    Resupply_Offer_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Logistics, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Resupply_Received_PDU)
{
    Resupply_Received_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Logistics, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Service_Request_PDU)
{
    Service_Request_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Logistics, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Radio Communications
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily5, Receiver_PDU)
{
    Receiver_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Radio_Communications, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Signal_PDU)
{
    Signal_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Radio_Communications, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Transmitter_PDU)
{
    Transmitter_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Radio_Communications, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Simulation Management
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily5, Acknowledge_PDU)
{
    Acknowledge_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Action_Request_PDU)
{
    Action_Request_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Action_Response_PDU)
{
    Action_Response_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Comment_PDU)
{
    Comment_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Create_Entity_PDU)
{
    Create_Entity_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Data_PDU)
{
    Data_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Data_Query_PDU)
{
    Data_Query_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Event_Report_PDU)
{
    Event_Report_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Remove_Entity_PDU)
{
    Remove_Entity_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Set_Data_PDU)
{
    Set_Data_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Start_Resume_PDU)
{
    Start_Resume_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Stop_Freeze_PDU)
{
    Stop_Freeze_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Simulation_Management, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Warfare
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily5, Detonation_PDU)
{
    Detonation_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Warfare, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Fire_PDU)
{
    Fire_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Warfare, pdu.GetProtocolFamily());
}