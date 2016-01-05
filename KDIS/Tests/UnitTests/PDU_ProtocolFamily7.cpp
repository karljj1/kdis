#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/KDefines.h"

#if DIS_VERSION > 6

#include "KDIS/PDU/Entity_Info_Interaction/Attribute_PDU.h"
#include "KDIS/PDU/Information_Operations/IO_Action_PDU.h"
#include "KDIS/PDU/Information_Operations/IO_Report_PDU.h"

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE::ENUMS;

//////////////////////////////////////////////////////////////////////////
// Entity Info Interaction
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily7, Attribute_PDU)
{
    Attribute_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Entity_Information_Interaction, pdu.GetProtocolFamily());
}

//////////////////////////////////////////////////////////////////////////
// Information Operations
//////////////////////////////////////////////////////////////////////////

TEST(PDU_ProtocolFamily7, IO_Action_PDU)
{
    IO_Report_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Information_Operations, pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily7, IO_Report_PDU)
{
    IO_Report_PDU pdu;
    EXPECT_EQ(ProtocolFamily::Information_Operations, pdu.GetProtocolFamily());
}

#endif