#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/PDU/Distributed_Emission_Regeneration/Designator_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/Electromagnetic_Emission_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/IFF_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/SEES_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/Underwater_Acoustic_PDU.h"

#include "KDIS/PDU/Entity_Info_Interaction/Attribute_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Collision_Elastic_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Collision_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_Update_PDU.h"

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

#include "KDIS/PDU/Minefield/Minefield_Data_PDU.h"
#include "KDIS/PDU/Minefield/Minefield_Query_PDU.h"
#include "KDIS/PDU/Minefield/Minefield_Response_NACK_PDU.h"
#include "KDIS/PDU/Minefield/Minefield_State_PDU.h"

#include "KDIS/PDU/Radio_Communications/Intercom_Control_PDU.h"
#include "KDIS/PDU/Radio_Communications/Intercom_Signal_PDU.h"
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

#include "KDIS/PDU/Simulation_Management_With_Reliability/Acknowledge_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Action_Request_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Action_Response_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Comment_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Create_Entity_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Data_Query_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Data_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Event_Report_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Record_Query_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Record_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Remove_Entity_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Set_Data_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Set_Record_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Start_Resume_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Stop_Freeze_R_PDU.h"

#include "KDIS/PDU/Synthetic_Environment/Areal_Object_State_PDU.h"
#include "KDIS/PDU/Synthetic_Environment/Environmental_Process_PDU.h"
#include "KDIS/PDU/Synthetic_Environment/Gridded_Data_PDU.h"
#include "KDIS/PDU/Synthetic_Environment/Linear_Object_State_PDU.h"
#include "KDIS/PDU/Synthetic_Environment/Point_Object_State_PDU.h"

#include "KDIS/PDU/Warfare/Detonation_PDU.h"
#include "KDIS/PDU/Warfare/Directed_Energy_Fire_PDU.h"
#include "KDIS/PDU/Warfare/Entity_Damage_Status_PDU.h"
#include "KDIS/PDU/Warfare/Fire_PDU.h"

using namespace KDIS;
using namespace PDU;

//////////////////////////////////////////////////////////////////////////
// Distributed Emission Regeneration
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Designator_PDU)
{
	Designator_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Designator_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Electromagnetic_Emission_PDU)
{
	Electromagnetic_Emission_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Electromagnetic_Emission_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, IFF_PDU)
{
	IFF_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	IFF_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}


TEST(PDU_EncodeDecode, SEES_PDU)
{
	SEES_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	SEES_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Underwater_Acoustic_PDU)
{
	Underwater_Acoustic_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Underwater_Acoustic_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Entity Info Interaction
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Attribute_PDU)
{
	Attribute_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Attribute_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Collision_Elastic_PDU)
{
	Collision_Elastic_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Collision_Elastic_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Collision_PDU)
{
	Collision_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Collision_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Entity_State_PDU)
{
	Entity_State_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Entity_State_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Entity_State_Update_PDU)
{
	Entity_State_Update_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Entity_State_Update_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Entity Management
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Aggregate_State_PDU)
{
	Aggregate_State_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Aggregate_State_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, IsGroupOf_PDU)
{
	IsGroupOf_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	IsGroupOf_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, IsPartOf_PDU)
{
	IsPartOf_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	IsPartOf_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Transfer_Control_Request_PDU)
{
	Transfer_Control_Request_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Transfer_Control_Request_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Information Operations
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, IO_Action_PDU)
{
	IO_Action_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	IO_Action_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, IO_Report_PDU)
{
	IO_Report_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	IO_Report_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Live Entity
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Appearance_PDU)
{
	Appearance_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Appearance_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Articulated_Parts_PDU)
{
	Articulated_Parts_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Articulated_Parts_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, LE_Detonation_PDU)
{
	LE_Detonation_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	LE_Detonation_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, LE_Fire_PDU)
{
	LE_Fire_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	LE_Fire_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, TSPI_PDU)
{
	TSPI_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	TSPI_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Logistics
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Repair_Complete_PDU)
{
	Repair_Complete_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Repair_Complete_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Repair_Response_PDU)
{
	Repair_Response_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Repair_Response_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Resupply_Cancel_PDU)
{
	Resupply_Cancel_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Resupply_Cancel_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Resupply_Offer_PDU)
{
	Resupply_Offer_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Resupply_Offer_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Resupply_Received_PDU)
{
	Resupply_Received_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Resupply_Received_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Service_Request_PDU)
{
	Service_Request_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Service_Request_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Minefield
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Minefield_Data_PDU)
{
	Minefield_Data_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Minefield_Data_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Minefield_Query_PDU)
{
	Minefield_Query_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Minefield_Query_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Minefield_Response_NACK_PDU)
{
	Minefield_Response_NACK_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Minefield_Response_NACK_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Minefield_State_PDU)
{
	Minefield_State_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Minefield_State_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Radio Communications
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Intercom_Control_PDU)
{
	Intercom_Control_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Intercom_Control_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Intercom_Signal_PDU)
{
	Intercom_Signal_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Intercom_Signal_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Receiver_PDU)
{
	Receiver_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Receiver_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Signal_PDU)
{
	Signal_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Signal_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Transmitter_PDU)
{
	Transmitter_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Transmitter_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Simulation Management
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Acknowledge_PDU)
{
	Acknowledge_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Acknowledge_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Action_Request_PDU)
{
	Action_Request_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Action_Request_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Action_Response_PDU)
{
	Action_Response_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Action_Response_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Comment_PDU)
{
	Comment_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Comment_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Create_Entity_PDU)
{
	Create_Entity_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Create_Entity_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Data_PDU)
{
	Data_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Data_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Data_Query_PDU)
{
	Data_Query_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Data_Query_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Event_Report_PDU)
{
	Event_Report_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Event_Report_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Remove_Entity_PDU)
{
	Remove_Entity_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Remove_Entity_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Set_Data_PDU)
{
	Set_Data_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Set_Data_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Start_Resume_PDU)
{
	Start_Resume_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Start_Resume_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(PDU_EncodeDecode, Stop_Freeze_PDU)
{
	Stop_Freeze_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Stop_Freeze_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Simulation Management With Reliability
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Acknowledge_R_PDU)
{
	Acknowledge_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Acknowledge_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Action_Request_R_PDU)
{
	Action_Request_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Action_Request_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Action_Response_R_PDU)
{
	Action_Response_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Action_Response_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Comment_R_PDU)
{
	Comment_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Comment_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Create_Entity_R_PDU)
{
	Create_Entity_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Create_Entity_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Data_Query_R_PDU)
{
	Data_Query_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Data_Query_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Data_R_PDU)
{
	Data_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Data_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Event_Report_R_PDU)
{
	Event_Report_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Event_Report_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Record_Query_R_PDU)
{
	Record_Query_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Record_Query_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Record_R_PDU)
{
	Record_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Record_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Remove_Entity_R_PDU)
{
	Remove_Entity_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Remove_Entity_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Set_Data_R_PDU)
{
	Set_Data_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Set_Data_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Set_Record_R_PDU)
{
	Set_Record_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Set_Record_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Start_Resume_R_PDU)
{
	Start_Resume_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Start_Resume_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Stop_Freeze_R_PDU)
{
	Stop_Freeze_R_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Stop_Freeze_R_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

//////////////////////////////////////////////////////////////////////////
// Synthetic Environment
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode, Areal_Object_State_PDU)
{
	Areal_Object_State_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Areal_Object_State_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Environmental_Process_PDU)
{
	Environmental_Process_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Environmental_Process_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Gridded_Data_PDU)
{
	Gridded_Data_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Gridded_Data_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Linear_Object_State_PDU)
{
	Linear_Object_State_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Linear_Object_State_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

TEST(R_PDU_EncodeDecode, Point_Object_State_PDU)
{
	Point_Object_State_PDU pduIn;
	KDataStream stream = pduIn.Encode();
	Point_Object_State_PDU pduOut(stream);
	EXPECT_EQ(pduIn, pduOut);
}

