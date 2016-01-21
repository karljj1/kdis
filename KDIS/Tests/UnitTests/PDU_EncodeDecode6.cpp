#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/KDefines.h"
#if DIS_VERSION > 5
#include "KDIS/PDU/Distributed_Emission_Regeneration/IFF_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/SEES_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/Underwater_Acoustic_PDU.h"

#include "KDIS/PDU/Entity_Info_Interaction/Collision_Elastic_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_Update_PDU.h"

#include "KDIS/PDU/Entity_Management/Aggregate_State_PDU.h"
#include "KDIS/PDU/Entity_Management/IsGroupOf_PDU.h"
#include "KDIS/PDU/Entity_Management/IsPartOf_PDU.h"
#include "KDIS/PDU/Entity_Management/Transfer_Control_Request_PDU.h"

#include "KDIS/PDU/Live_Entity/Appearance_PDU.h"
#include "KDIS/PDU/Live_Entity/Articulated_Parts_PDU.h"
#include "KDIS/PDU/Live_Entity/LE_Detonation_PDU.h"
#include "KDIS/PDU/Live_Entity/LE_Fire_PDU.h"
#include "KDIS/PDU/Live_Entity/TSPI_PDU.h"

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

//////////////////////////////////////////////////////////////////////////
// Distributed Emission Regeneration
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode6, IFF_PDU)
{
    IFF_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    IFF_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode6, SEES_PDU)
{
    SEES_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    SEES_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode6, Underwater_Acoustic_PDU)
{
    Underwater_Acoustic_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Underwater_Acoustic_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Entity Info Interaction
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode6, Collision_Elastic_PDU)
{
    Collision_Elastic_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Collision_Elastic_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode6, Entity_State_Update_PDU)
{
    Entity_State_Update_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Entity_State_Update_PDU pduOut(stream);
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
// Radio Communications
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode6, Intercom_Control_PDU)
{
    Intercom_Control_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Intercom_Control_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode6, Intercom_Signal_PDU)
{
    Intercom_Signal_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Intercom_Signal_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Simulation Management With Reliability
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode6, Acknowledge_R_PDU)
{
    Acknowledge_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Acknowledge_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Action_Request_R_PDU)
{
    Action_Request_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Action_Request_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Action_Response_R_PDU)
{
    Action_Response_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Action_Response_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Comment_R_PDU)
{
    Comment_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Comment_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Create_Entity_R_PDU)
{
    Create_Entity_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Create_Entity_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Data_Query_R_PDU)
{
    Data_Query_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Data_Query_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Data_R_PDU)
{
    Data_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Data_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Event_Report_R_PDU)
{
    Event_Report_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Event_Report_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Record_Query_R_PDU)
{
    Record_Query_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Record_Query_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Record_R_PDU)
{
    Record_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Record_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Remove_Entity_R_PDU)
{
    Remove_Entity_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Remove_Entity_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Set_Data_R_PDU)
{
    Set_Data_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Set_Data_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Set_Record_R_PDU)
{
    Set_Record_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Set_Record_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Start_Resume_R_PDU)
{
    Start_Resume_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Start_Resume_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Stop_Freeze_R_PDU)
{
    Stop_Freeze_R_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Stop_Freeze_R_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Synthetic Environment
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode6, Areal_Object_State_PDU)
{
    Areal_Object_State_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Areal_Object_State_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Environmental_Process_PDU)
{
    Environmental_Process_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Environmental_Process_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Gridded_Data_PDU)
{
    Gridded_Data_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Gridded_Data_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Linear_Object_State_PDU)
{
    Linear_Object_State_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Linear_Object_State_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(R_PDU_EncodeDecode6, Point_Object_State_PDU)
{
    Point_Object_State_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Point_Object_State_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

#endif
