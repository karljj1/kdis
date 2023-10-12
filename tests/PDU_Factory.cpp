#include <gtest/gtest.h>

#include <KDIS/Extras/PDU_Factory.hpp>
#include <KDIS/KDefines.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.hpp>
#include <iostream>

class PDU_Factory_Filter_Test : public KDIS::UTILS::PDU_Factory_Filter {
 public:
  int m_ApplyFilterCalled;
  int m_AppplyFilterBeforeDecodingPDUBodyCalled;

  KDIS::KBOOL m_ApplyFilterReturnValue;
  KDIS::KBOOL m_ApplyFilterBeforeDecodingPDUBodyReturnValue;

  PDU_Factory_Filter_Test()
      : m_ApplyFilterCalled(0),
        m_AppplyFilterBeforeDecodingPDUBodyCalled(0),
        m_ApplyFilterReturnValue(true),
        m_ApplyFilterBeforeDecodingPDUBodyReturnValue(true) {}

  ~PDU_Factory_Filter_Test() {}

  virtual KDIS::KBOOL ApplyFilter(const KDIS::PDU::Header* H) {
    ++m_ApplyFilterCalled;
    return m_ApplyFilterReturnValue;
  }

  virtual KDIS::KBOOL ApplyFilterBeforeDecodingPDUBody(
      const KDIS::PDU::Header* H) {
    ++m_AppplyFilterBeforeDecodingPDUBodyCalled;
    return m_ApplyFilterBeforeDecodingPDUBodyReturnValue;
  }
};

TEST(PDU_Factory, PDU_Factory_Filter_FiltersAreUsed) {
  KDIS::UTILS::PDU_Factory factory;
  PDU_Factory_Filter_Test* filter = new PDU_Factory_Filter_Test();
  factory.AddFilter(filter);
  KDIS::PDU::Entity_State_PDU pdu;
  KDIS::KDataStream stream = pdu.Encode();

  ASSERT_EQ(0, filter->m_ApplyFilterCalled);
  ASSERT_EQ(0, filter->m_AppplyFilterBeforeDecodingPDUBodyCalled);

  std::unique_ptr<KDIS::PDU::Header> header = factory.Decode(stream);

  EXPECT_EQ(1, filter->m_ApplyFilterCalled);
  EXPECT_EQ(1, filter->m_AppplyFilterBeforeDecodingPDUBodyCalled);
}

TEST(PDU_Factory, PDU_Factory_Filter_ApplyFilterFalse_RejectsPDU) {
  KDIS::UTILS::PDU_Factory factory;
  PDU_Factory_Filter_Test* filter = new PDU_Factory_Filter_Test();
  filter->m_ApplyFilterReturnValue = false;
  factory.AddFilter(filter);
  KDIS::PDU::Entity_State_PDU pdu;
  KDIS::KDataStream stream = pdu.Encode();

  std::unique_ptr<KDIS::PDU::Header> header = factory.Decode(stream);
  EXPECT_FALSE(header.get());
}

TEST(PDU_Factory,
     PDU_Factory_Filter_ApplyFilterBeforeDecodingPDUBody_RejectsPDU) {
  KDIS::UTILS::PDU_Factory factory;
  PDU_Factory_Filter_Test* filter = new PDU_Factory_Filter_Test();
  filter->m_ApplyFilterBeforeDecodingPDUBodyReturnValue = false;
  factory.AddFilter(filter);
  KDIS::PDU::Entity_State_PDU pdu;
  KDIS::KDataStream stream = pdu.Encode();

  std::unique_ptr<KDIS::PDU::Header> header = factory.Decode(stream);
  EXPECT_FALSE(header.get());
}
