#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/Extras/PDU_Factory.h"

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
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Distributed Emission Regeneration
//////////////////////////////////////////////////////////////////////////

TEST(PDU_FactoryDecoder5, Designator_PDU)
{
    Designator_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    PDU_Factory factory;
    std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Designator_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Electromagnetic_Emission_PDU)
{
    Electromagnetic_Emission_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Electromagnetic_Emission_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Entity Info Interaction
//////////////////////////////////////////////////////////////////////////

TEST(PDU_FactoryDecoder5, Collision_PDU)
{
    Collision_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Collision_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Entity_State_PDU)
{
    Entity_State_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Entity_State_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Logistics
//////////////////////////////////////////////////////////////////////////

TEST(PDU_FactoryDecoder5, Repair_Complete_PDU)
{
    Repair_Complete_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Repair_Complete_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Repair_Response_PDU)
{
    Repair_Response_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Repair_Response_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Resupply_Cancel_PDU)
{
    Resupply_Cancel_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Resupply_Cancel_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Resupply_Offer_PDU)
{
    Resupply_Offer_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Resupply_Offer_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Resupply_Received_PDU)
{
    Resupply_Received_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Resupply_Received_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Service_Request_PDU)
{
    Service_Request_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Service_Request_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Radio Communications
//////////////////////////////////////////////////////////////////////////

TEST(PDU_FactoryDecoder5, Receiver_PDU)
{
    Receiver_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Receiver_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Signal_PDU)
{
    Signal_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Signal_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Transmitter_PDU)
{
    Transmitter_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Transmitter_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Simulation Management
//////////////////////////////////////////////////////////////////////////

TEST(PDU_FactoryDecoder5, Acknowledge_PDU)
{
    Acknowledge_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Acknowledge_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Action_Request_PDU)
{
    Action_Request_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Action_Request_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Action_Response_PDU)
{
    Action_Response_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Action_Response_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Comment_PDU)
{
    Comment_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Comment_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Create_Entity_PDU)
{
    Create_Entity_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Create_Entity_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Data_PDU)
{
    Data_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Data_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Data_Query_PDU)
{
    Data_Query_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Data_Query_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Event_Report_PDU)
{
    Event_Report_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Event_Report_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Remove_Entity_PDU)
{
    Remove_Entity_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Remove_Entity_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Set_Data_PDU)
{
    Set_Data_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Set_Data_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Start_Resume_PDU)
{
    Start_Resume_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Start_Resume_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Stop_Freeze_PDU)
{
    Stop_Freeze_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Stop_Freeze_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Warfare
//////////////////////////////////////////////////////////////////////////

TEST(PDU_FactoryDecoder5, Detonation_PDU)
{
    Detonation_PDU pduIn;
    KDataStream stream = pduIn.Encode();
	PDU_Factory factory;
	std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Detonation_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_FactoryDecoder5, Fire_PDU)
{
    Fire_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    PDU_Factory factory;
    std::unique_ptr<Header> pduOut = factory.Decode(stream);
    EXPECT_EQ(pduIn, *(Fire_PDU*)pduOut.get());
    EXPECT_EQ(0, stream.GetBufferSize());
}