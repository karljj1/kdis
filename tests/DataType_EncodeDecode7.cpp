#if DIS_VERSION >= 7

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
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IOCommunicationsNode dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IOEffect) {
  KDIS::DATA_TYPE::IOEffect dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::IOEffect dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5InterrogatorBasicData) {
  KDIS::DATA_TYPE::Mode5InterrogatorBasicData dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5InterrogatorBasicData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5InterrogatorStatus) {
  KDIS::DATA_TYPE::Mode5InterrogatorStatus dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5InterrogatorStatus dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5TransponderBasicData) {
  KDIS::DATA_TYPE::Mode5TransponderBasicData dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5TransponderBasicData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5TransponderStatus) {
  KDIS::DATA_TYPE::Mode5TransponderStatus dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5TransponderStatus dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5TransponderSupplementalData) {
  KDIS::DATA_TYPE::Mode5TransponderSupplementalData dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::Mode5TransponderSupplementalData dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, ModeXCodeRecord) {
  KDIS::DATA_TYPE::ModeXCodeRecord dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::ModeXCodeRecord dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, StandardVariable) {
  KDIS::DATA_TYPE::StandardVariable dtIn;
  KDIS::KDataStream stream = dtIn.Encode();
  KDIS::DATA_TYPE::StandardVariable dtOut(stream);
  EXPECT_EQ(dtIn, dtOut);
  EXPECT_EQ(0, stream.GetBufferSize());
}

#endif
