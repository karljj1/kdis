#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/KDefines.h"

#if DIS_VERSION > 6

#include "KDIS/PDU/Entity_Info_Interaction/Attribute_PDU.h"
#include "KDIS/PDU/Information_Operations/IO_Action_PDU.h"
#include "KDIS/PDU/Information_Operations/IO_Report_PDU.h"

using namespace KDIS;
using namespace PDU;

//////////////////////////////////////////////////////////////////////////
// Entity Info Interaction
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode7, Attribute_PDU)
{
    Attribute_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    Attribute_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//////////////////////////////////////////////////////////////////////////
// Information Operations
//////////////////////////////////////////////////////////////////////////

TEST(PDU_EncodeDecode7, IO_Action_PDU)
{
    IO_Action_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    IO_Action_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode7, IO_Report_PDU)
{
    IO_Report_PDU pduIn;
    KDataStream stream = pduIn.Encode();
    IO_Report_PDU pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

#endif