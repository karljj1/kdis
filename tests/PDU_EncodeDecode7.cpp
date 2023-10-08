#if DIS_VERSION >= 7

#include <gtest/gtest.h>

#include <KDIS/KDefines.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Attribute_PDU.hpp>
#include <KDIS/PDU/Information_Operations/IO_Action_PDU.hpp>
#include <KDIS/PDU/Information_Operations/IO_Report_PDU.hpp>
#include <iostream>

//
// Entity Info Interaction
//
TEST(PDU_EncodeDecode7, Attribute_PDU) {
  KDIS::PDU::Attribute_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::Attribute_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

//
// Information Operations
//
TEST(PDU_EncodeDecode7, IO_Action_PDU) {
  KDIS::PDU::IO_Action_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::IO_Action_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(PDU_EncodeDecode7, IO_Report_PDU) {
  KDIS::PDU::IO_Report_PDU pduIn;
  KDIS::KDataStream stream = pduIn.Encode();
  KDIS::PDU::IO_Report_PDU pduOut(stream);
  EXPECT_EQ(pduIn, pduOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

#endif
