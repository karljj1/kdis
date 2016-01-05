#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/KDefines.h"
#if DIS_VERSION > 5
#include "KDIS/PDU/Distributed_Emission_Regeneration/IFF_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/SEES_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/Underwater_Acoustic_PDU.h"

#include "KDIS/PDU/Entity_Info_Interaction/Collision_Elastic_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_Update_PDU.h"

#include "KDIS/PDU/Information_Operations/IO_Action_PDU.h"
#include "KDIS/PDU/Information_Operations/IO_Report_PDU.h"

#include "KDIS/PDU/Radio_Communications/Intercom_Control_PDU.h"
#include "KDIS/PDU/Radio_Communications/Intercom_Signal_PDU.h"

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

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE::ENUMS;

//////////////////////////////////////////////////////////////////////////
// Distributed Emission Regeneration
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily6, IFF_PDU)
{
    IFF_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Distributed_Emission_Regeneration, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, SEES_PDU)
{
    SEES_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Distributed_Emission_Regeneration, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Underwater_Acoustic_PDU)
{
    Underwater_Acoustic_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Distributed_Emission_Regeneration, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Entity Info Interaction
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily6, Collision_Elastic_PDU)
{
    Collision_Elastic_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Entity_Information_Interaction, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Entity_State_Update_PDU)
{
    Entity_State_Update_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Entity_Information_Interaction, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Information Operations
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily6, IO_Action_PDU)
{
    IO_Action_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Information_Operations, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, IO_Report_PDU)
{
    IO_Report_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Information_Operations, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Radio Communications
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily6, Intercom_Control_PDU)
{
    Intercom_Control_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Radio_Communications, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Intercom_Signal_PDU)
{
    Intercom_Signal_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Radio_Communications, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Simulation Management With Reliability
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily6, Acknowledge_R_PDU)
{
    Acknowledge_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Action_Request_R_PDU)
{
    Action_Request_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Action_Response_R_PDU)
{
    Action_Response_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Comment_R_PDU)
{
    Comment_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Create_Entity_R_PDU)
{
    Create_Entity_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Data_Query_R_PDU)
{
    Data_Query_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Data_R_PDU)
{
    Data_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Event_Report_R_PDU)
{
    Event_Report_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Record_Query_R_PDU)
{
    Record_Query_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Record_R_PDU)
{
    Record_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Remove_Entity_R_PDU)
{
    Remove_Entity_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Set_Data_R_PDU)
{
    Set_Data_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Set_Record_R_PDU)
{
    Set_Record_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Start_Resume_R_PDU)
{
    Start_Resume_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Stop_Freeze_R_PDU)
{
    Stop_Freeze_R_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SimulationManagementwithReliability, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Synthetic Environment
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily6, Areal_Object_State_PDU)
{
    Areal_Object_State_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SyntheticEnvironment, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Environmental_Process_PDU)
{
    Environmental_Process_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SyntheticEnvironment, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Gridded_Data_PDU)
{
    Gridded_Data_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SyntheticEnvironment, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Linear_Object_State_PDU)
{
    Linear_Object_State_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SyntheticEnvironment, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily6, Point_Object_State_PDU)
{
    Point_Object_State_PDU pdu;
    EXPECT_EQ(ProtocolFamily::SyntheticEnvironment, pdu.GetProtocolFamily());
}

#endif
