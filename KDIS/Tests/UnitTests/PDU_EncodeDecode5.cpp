#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/PDU/Distributed_Emission_Regeneration/Designator_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/Electromagnetic_Emission_PDU.h"

#include "KDIS/PDU/Entity_Info_Interaction/Collision_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.h"

#include "KDIS/PDU/Entity_Management/Aggregate_State_PDU.h"
#include "KDIS/PDU/Entity_Management/IsGroupOf_PDU.h"
#include "KDIS/PDU/Entity_Management/IsPartOf_PDU.h"
#include "KDIS/PDU/Entity_Management/Transfer_Control_Request_PDU.h"

#include "KDIS/PDU/Information_Operations/IO_Action_PDU.h"
#include "KDIS/PDU/Information_Operations/IO_Report_PDU.h"

#include "KDIS/PDU/Live_Entity/Appearance_PDU.h"
#include "KDIS/PDU/Live_Entity/Articulated_Parts_PDU.h"
#include "KDIS/PDU/Live_Entity/LE_Detonation_PDU.h"
#include "KDIS/PDU/Live_Entity/LE_Fire_PDU.h"
#include "KDIS/PDU/Live_Entity/TSPI_PDU.h"

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
#include "KDIS/PDU/Warfare/Directed_Energy_Fire_PDU.h"
#include "KDIS/PDU/Warfare/Entity_Damage_Status_PDU.h"
#include "KDIS/PDU/Warfare/Fire_PDU.h"

using namespace KDIS;
using namespace PDU;

//////////////////////////////////////////////////////////////////////////
// Distributed Emission Regeneration
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode5, Designator_PDU)
{
    Designator_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Designator_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Electromagnetic_Emission_PDU)
{
    Electromagnetic_Emission_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Electromagnetic_Emission_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Entity Info Interaction
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode5, Collision_PDU)
{
    Collision_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Collision_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Entity_State_PDU)
{
    Entity_State_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Entity_State_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Entity Management
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode5, Aggregate_State_PDU)
{
    Aggregate_State_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Aggregate_State_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, IsGroupOf_PDU)
{
    IsGroupOf_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    IsGroupOf_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, IsPartOf_PDU)
{
    IsPartOf_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    IsPartOf_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Transfer_Control_Request_PDU)
{
    Transfer_Control_Request_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Transfer_Control_Request_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Information Operations
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode5, IO_Action_PDU)
{
    IO_Action_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    IO_Action_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, IO_Report_PDU)
{
    IO_Report_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    IO_Report_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Live Entity
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode5, Appearance_PDU)
{
    Appearance_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Appearance_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Articulated_Parts_PDU)
{
    Articulated_Parts_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Articulated_Parts_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, LE_Detonation_PDU)
{
    LE_Detonation_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    LE_Detonation_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, LE_Fire_PDU)
{
    LE_Fire_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    LE_Fire_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, TSPI_PDU)
{
    TSPI_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    TSPI_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Logistics
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode5, Repair_Complete_PDU)
{
    Repair_Complete_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Repair_Complete_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Repair_Response_PDU)
{
    Repair_Response_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Repair_Response_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Resupply_Cancel_PDU)
{
    Resupply_Cancel_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Resupply_Cancel_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Resupply_Offer_PDU)
{
    Resupply_Offer_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Resupply_Offer_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Resupply_Received_PDU)
{
    Resupply_Received_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Resupply_Received_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Service_Request_PDU)
{
    Service_Request_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Service_Request_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Radio Communications
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode5, Receiver_PDU)
{
    Receiver_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Receiver_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Signal_PDU)
{
    Signal_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Signal_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Transmitter_PDU)
{
    Transmitter_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Transmitter_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Simulation Management
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode5, Acknowledge_PDU)
{
    Acknowledge_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Acknowledge_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Action_Request_PDU)
{
    Action_Request_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Action_Request_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Action_Response_PDU)
{
    Action_Response_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Action_Response_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Comment_PDU)
{
    Comment_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Comment_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Create_Entity_PDU)
{
    Create_Entity_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Create_Entity_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Data_PDU)
{
    Data_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Data_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Data_Query_PDU)
{
    Data_Query_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Data_Query_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Event_Report_PDU)
{
    Event_Report_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Event_Report_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Remove_Entity_PDU)
{
    Remove_Entity_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Remove_Entity_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Set_Data_PDU)
{
    Set_Data_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Set_Data_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Start_Resume_PDU)
{
    Start_Resume_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Start_Resume_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Stop_Freeze_PDU)
{
    Stop_Freeze_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Stop_Freeze_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Warfare
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode5, Detonation_PDU)
{
    Detonation_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Detonation_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Directed_Energy_Fire_PDU)
{
    Directed_Energy_Fire_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Directed_Energy_Fire_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Entity_Damage_Status_PDU)
{
    Entity_Damage_Status_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Entity_Damage_Status_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode5, Fire_PDU)
{
    Fire_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Fire_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}