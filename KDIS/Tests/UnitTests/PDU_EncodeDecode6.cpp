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

template<typename T>
class EncodeDecodeTest : public ::testing::Test
{
public:

    void TestEncodeDecode()
    {
        T pduIn;
        KDataStream stream = pduIn.Encode();
        T pduOut(stream);
        EXPECT_EQ(pduIn, pduOut);
        EXPECT_EQ(0, stream.GetBufferSize());
    }

    void TestEncodeDecodeIgnoreHeader()
    {
        T pduIn;
        KDataStream stream = pduIn.Encode();

        Header hdr(stream);
        T pduOut(hdr, stream);
        EXPECT_EQ(pduIn, pduOut);
        EXPECT_EQ(0, stream.GetBufferSize());
    }
};

typedef ::testing::Types
<
    IFF_PDU, 
    SEES_PDU,
    Underwater_Acoustic_PDU,
    Collision_Elastic_PDU,
    Entity_State_Update_PDU,
    Aggregate_State_PDU,
    IsGroupOf_PDU,
    IsPartOf_PDU,
    Transfer_Control_Request_PDU,
    Appearance_PDU,
    Articulated_Parts_PDU,
    LE_Detonation_PDU,
    LE_Fire_PDU,
    TSPI_PDU,
    Intercom_Signal_PDU,
    Intercom_Control_PDU,
    Acknowledge_R_PDU,
    Action_Request_R_PDU,
    Action_Response_R_PDU,
    Comment_R_PDU,
    Create_Entity_R_PDU,
    Data_Query_R_PDU,
    Data_R_PDU,
    Event_Report_R_PDU,
    Record_Query_R_PDU,
    Record_R_PDU,
    Remove_Entity_R_PDU,
    Set_Data_R_PDU,
    Set_Record_R_PDU,
    Start_Resume_R_PDU,
    Stop_Freeze_R_PDU,
    Areal_Object_State_PDU,
    Environmental_Process_PDU,
    Gridded_Data_PDU,
    Linear_Object_State_PDU,
    Point_Object_State_PDU
> PduTestTypes6;

TYPED_TEST_CASE(EncodeDecodeTest, PduTestTypes6);

TYPED_TEST(EncodeDecodeTest, PDU_EncodeDecode6)
{
    this->TestEncodeDecode();
}

TYPED_TEST(EncodeDecodeTest, PDU_EncodeDecode6_IgnoreHeader)
{
    this->TestEncodeDecodeIgnoreHeader();
}

#endif
