#if DIS_VERSION >= 7

#include <gtest/gtest.h>

#include <KDIS/KDefines.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Attribute_PDU.hpp>
#include <KDIS/PDU/Information_Operations/IO_Action_PDU.hpp>
#include <KDIS/PDU/Information_Operations/IO_Report_PDU.hpp>
#include <KDIS/PDU/Warfare/Directed_Energy_Fire_PDU.hpp>
#include <KDIS/PDU/Warfare/Entity_Damage_Status_PDU.hpp>
#include <iostream>

//
// Entity Info Interaction
//
TEST(PDU_ProtocolFamily7, Attribute_PDU) {
  KDIS::PDU::Attribute_PDU pdu;
  EXPECT_EQ(
      KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Entity_Information_Interaction,
      pdu.GetProtocolFamily());
}

//
// Information Operations
//
TEST(PDU_ProtocolFamily7, IO_Action_PDU) {
  KDIS::PDU::IO_Action_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Information_Operations,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily7, IO_Report_PDU) {
  KDIS::PDU::IO_Report_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Information_Operations,
            pdu.GetProtocolFamily());
}

//
// Warfare
//
TEST(PDU_ProtocolFamily5, Directed_Energy_Fire_PDU) {
  KDIS::PDU::Directed_Energy_Fire_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Warfare,
            pdu.GetProtocolFamily());
}

TEST(PDU_ProtocolFamily5, Entity_Damage_Status_PDU) {
  KDIS::PDU::Entity_Damage_Status_PDU pdu;
  EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::ProtocolFamily::Warfare,
            pdu.GetProtocolFamily());
}

#endif
