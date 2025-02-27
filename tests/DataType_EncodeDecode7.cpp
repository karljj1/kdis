#include <gtest/gtest.h>

#include <KDIS/DataTypes/AttributeRecordSet.hpp>
#include <KDIS/DataTypes/CommunicationsNodeID.hpp>
#include <KDIS/DataTypes/DEAreaAimpoint.hpp>
#include <KDIS/DataTypes/EnhancedMode1Code.hpp>
#include <KDIS/DataTypes/ExplosionDescriptor.hpp>
#include <KDIS/DataTypes/IFF_Layer3.hpp>
#include <KDIS/DataTypes/IFF_Layer3Interrogator.hpp>
#include <KDIS/DataTypes/IFF_Layer3Transponder.hpp>
#include <KDIS/DataTypes/IOCommunicationsNode.hpp>
#include <KDIS/DataTypes/IOEffect.hpp>
#include <KDIS/DataTypes/Mode5InterrogatorBasicData.hpp>
#include <KDIS/DataTypes/Mode5InterrogatorStatus.hpp>
#include <KDIS/DataTypes/Mode5TransponderBasicData.hpp>
#include <KDIS/DataTypes/Mode5TransponderStatus.hpp>
#include <KDIS/DataTypes/Mode5TransponderSupplementalData.hpp>
#include <KDIS/DataTypes/ModeXCodeRecord.hpp>
#include <KDIS/DataTypes/StandardVariable.hpp>
#include <KDIS/KDefines.hpp>
#include <bitset>
#include <iostream>

TEST(DataType_EncodeDecode7, AttributeRecordSet) {
  KDIS::DATA_TYPE::AttributeRecordSet dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::AttributeRecordSet dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, CommunicationsNodeID) {
  KDIS::DATA_TYPE::CommunicationsNodeID dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::CommunicationsNodeID dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, DEAreaAimpoint) {
  GTEST_SKIP();  // FIXME
  KDIS::DATA_TYPE::DEAreaAimpoint dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::DEAreaAimpoint dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, EnhancedMode1Code) {
  KDIS::DATA_TYPE::EnhancedMode1Code dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::EnhancedMode1Code dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, ExplosionDescriptor) {
  KDIS::DATA_TYPE::ExplosionDescriptor dtIn;
  EXPECT_EQ(0, dtIn.GetExplosiveMaterial());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ExplosionDescriptor dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IFF_Layer3) {
  KDIS::DATA_TYPE::IFF_Layer3 dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IFF_Layer3 dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IFF_Layer3Interrogator) {
  KDIS::DATA_TYPE::IFF_Layer3Interrogator dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IFF_Layer3Interrogator dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IFF_Layer3Transponder) {
  KDIS::DATA_TYPE::IFF_Layer3Transponder dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IFF_Layer3Transponder dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IOCommunicationsNode) {
  KDIS::DATA_TYPE::IOCommunicationsNode dtIn;
  EXPECT_EQ(0, dtIn.GetIOCommunicationsNodeType());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IOCommunicationsNode dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IOEffect) {
  KDIS::DATA_TYPE::IOEffect dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::IOStatus ios{
      KDIS::DATA_TYPE::ENUMS::NoStatementIOStatus};
  EXPECT_NO_THROW(dtIn.SetStatus(ios));
  EXPECT_EQ(ios, dtIn.GetStatus());
  constexpr KDIS::DATA_TYPE::ENUMS::IOLinkType iolt{
      KDIS::DATA_TYPE::ENUMS::NoStatementIOLinkType};
  EXPECT_NO_THROW(dtIn.SetLinkType(iolt));
  EXPECT_EQ(iolt, dtIn.GetLinkType());
  constexpr KDIS::DATA_TYPE::ENUMS::IOEffectType ioet{
      KDIS::DATA_TYPE::ENUMS::NoStatementIOEffectType};
  EXPECT_NO_THROW(dtIn.SetEffectType(ioet));
  EXPECT_EQ(ioet, dtIn.GetEffectType());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IOEffect dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5InterrogatorBasicData) {
  KDIS::DATA_TYPE::Mode5InterrogatorBasicData dtIn;
  constexpr std::bitset<32> bs32{0x34343434};
  EXPECT_NO_THROW(dtIn.SetMessageFormatsPresent(bs32));
  EXPECT_EQ(bs32, dtIn.GetMessageFormatsPresentBitSet());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5InterrogatorBasicData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5InterrogatorStatus) {
  KDIS::DATA_TYPE::Mode5InterrogatorStatus dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::Mode5MessageFormat m5mf{
      KDIS::DATA_TYPE::ENUMS::Capability};
  EXPECT_NO_THROW(dtIn.SetMode5MessageFormat(m5mf));
  EXPECT_EQ(m5mf, dtIn.GetMode5MessageFormat());
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5InterrogatorStatus dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5TransponderBasicData) {
  KDIS::DATA_TYPE::Mode5TransponderBasicData dtIn;
  constexpr std::bitset<32> bs32{0xABCDDCBA};
  EXPECT_NO_THROW(dtIn.SetMessageFormatsPresent(bs32));
  EXPECT_EQ(bs32, dtIn.GetMessageFormatsPresentBitSet());
  constexpr KDIS::DATA_TYPE::ENUMS::NavigationSource ns{
      KDIS::DATA_TYPE::ENUMS::NoStatementNavigationSource};
  EXPECT_NO_THROW(dtIn.SetNavigationSource(ns));
  EXPECT_EQ(ns, dtIn.GetNavigationSource());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5TransponderBasicData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5TransponderStatus) {
  KDIS::DATA_TYPE::Mode5TransponderStatus dtIn;
  constexpr KDIS::DATA_TYPE::ENUMS::Mode5Reply m5r{
      KDIS::DATA_TYPE::ENUMS::NoResponseReply};
  EXPECT_NO_THROW(dtIn.SetReply(m5r));
  EXPECT_EQ(m5r, dtIn.GetReply());
  EXPECT_NO_THROW(dtIn.SetLineTestInProgress(false));
  EXPECT_EQ(false, dtIn.IsLineTestInProgress());
  constexpr KDIS::DATA_TYPE::ENUMS::AntennaSelection as{
      KDIS::DATA_TYPE::ENUMS::AntennaSelectionNoStatement};
  EXPECT_NO_THROW(dtIn.SetAntennaSelection(as));
  EXPECT_EQ(as, dtIn.GetAntennaSelection());
  EXPECT_NO_THROW(dtIn.SetCryptoControlPresent(true));
  EXPECT_EQ(true, dtIn.IsCryptoControlPresent());
  EXPECT_NO_THROW(dtIn.SetLocationRecordPresent(false));
  EXPECT_EQ(false, dtIn.IsLocationRecordPresent());
  EXPECT_NO_THROW(dtIn.SetLocationErrorRecordPresent(true));
  EXPECT_EQ(true, dtIn.IsLocationErrorRecordPresent());
  constexpr KDIS::DATA_TYPE::ENUMS::PlatformType pt{
      KDIS::DATA_TYPE::ENUMS::GroundPlatformType};
  EXPECT_NO_THROW(dtIn.SetPlatformType(pt));
  EXPECT_EQ(pt, dtIn.GetPlatformType());
  EXPECT_NO_THROW(dtIn.SetMode5Level2Included(false));
  EXPECT_EQ(false, dtIn.IsMode5Level2Included());
  EXPECT_NO_THROW(dtIn.SetStatus(true));
  EXPECT_EQ(true, dtIn.GetStatus());
  EXPECT_NO_THROW(dtIn.SetDamaged(false));
  EXPECT_EQ(false, dtIn.IsDamaged());
  EXPECT_NO_THROW(dtIn.SetMalfunctioning(true));
  EXPECT_EQ(true, dtIn.IsMalfunctioning());
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5TransponderStatus dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5TransponderSupplementalData) {
  KDIS::DATA_TYPE::Mode5TransponderSupplementalData dtIn;
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5TransponderSupplementalData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, ModeXCodeRecord) {
  KDIS::DATA_TYPE::ModeXCodeRecord dtIn;
  EXPECT_NO_THROW(dtIn.SetStatus(true));
  EXPECT_EQ(true, dtIn.GetStatus());
  EXPECT_NO_THROW(dtIn.SetDamaged(false));
  EXPECT_EQ(false, dtIn.IsDamaged());
  EXPECT_NO_THROW(dtIn.SetMalfunctioning(true));
  EXPECT_EQ(true, dtIn.IsMalfunctioning());
  EXPECT_NO_THROW(dtIn.GetAsString());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ModeXCodeRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, StandardVariable) {
  KDIS::DATA_TYPE::StandardVariable dtIn;
  EXPECT_EQ(0, dtIn.GetStandardVariableType());
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::StandardVariable dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}
