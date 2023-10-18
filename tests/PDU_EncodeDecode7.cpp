#if DIS_VERSION >= 7

  #include <gtest/gtest.h>

  #include <KDIS/KDefines.hpp>
  #include <KDIS/PDU/Entity_Info_Interaction/Attribute_PDU.hpp>
  #include <KDIS/PDU/Information_Operations/IO_Action_PDU.hpp>
  #include <KDIS/PDU/Information_Operations/IO_Report_PDU.hpp>
  #include <iostream>

template <typename T>
class EncodeDecodeTest7 : public ::testing::Test {
 public:
  void TestEncodeDecode() {
    T pduIn;
    KDIS::KDataStream stream = pduIn.Encode();
    T pduOut(stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
  }

  void TestEncodeDecodeIgnoreHeader() {
    T pduIn;
    KDIS::KDataStream stream = pduIn.Encode();

    KDIS::PDU::Header hdr(stream);
    T pduOut(hdr, stream);
    EXPECT_EQ(pduIn, pduOut);
    EXPECT_EQ(0, stream.GetBufferSize());
  }
};

typedef ::testing::Types<
    KDIS::PDU::Attribute_PDU, KDIS::PDU::IO_Action_PDU,
    KDIS::PDU::IO_Report_PDU>
    PduTestTypes7;

TYPED_TEST_SUITE(EncodeDecodeTest7, PduTestTypes7);

TYPED_TEST(EncodeDecodeTest7, PDU_PduTestTypes7) { this->TestEncodeDecode(); }

TYPED_TEST(EncodeDecodeTest7, PDU_PduTestTypes5_IgnoreHeader) {
  this->TestEncodeDecodeIgnoreHeader();
}

#endif
