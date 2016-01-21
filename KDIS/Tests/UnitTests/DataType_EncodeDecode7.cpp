#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/KDefines.h"

#if DIS_VERSION > 6

#include "KDIS/DataTypes/AttributeRecordSet.h"
#include "KDIS/DataTypes/CommunicationsNodeID.h"
#include "KDIS/DataTypes/DEAreaAimpoint.h"
#include "KDIS/DataTypes/EnhancedMode1Code.h"
#include "KDIS/DataTypes/ExplosionDescriptor.h"
#include "KDIS/DataTypes/IFF_Layer3.h"
#include "KDIS/DataTypes/IFF_Layer3Interrogator.h"
#include "KDIS/DataTypes/IFF_Layer3Transponder.h"
#include "KDIS/DataTypes/IOCommunicationsNode.h"
#include "KDIS/DataTypes/IOEffect.h"
#include "KDIS/DataTypes/Mode5InterrogatorBasicData.h"
#include "KDIS/DataTypes/Mode5InterrogatorStatus.h"
#include "KDIS/DataTypes/Mode5TransponderBasicData.h"
#include "KDIS/DataTypes/Mode5TransponderStatus.h"
#include "KDIS/DataTypes/Mode5TransponderSupplementalData.h"
#include "KDIS/DataTypes/ModeXCodeRecord.h"
#include "KDIS/DataTypes/StandardVariable.h"

using namespace KDIS;
using namespace DATA_TYPE;

TEST(DataType_EncodeDecode7, AttributeRecordSet)
{
    AttributeRecordSet dtIn;
    KDataStream stream = dtIn.Encode();
    AttributeRecordSet dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, CommunicationsNodeID)
{
    CommunicationsNodeID dtIn;
    KDataStream stream = dtIn.Encode();
    CommunicationsNodeID dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

//TEST(DataType_EncodeDecode7, DEAreaAimpoint)
//{
//	DEAreaAimpoint dtIn;
//	KDataStream stream = dtIn.Encode();
//	DEAreaAimpoint dtOut(stream);
//	EXPECT_EQ(dtIn, dtOut);
//	EXPECT_EQ(0, stream.GetBufferSize());
//}

TEST(DataType_EncodeDecode7, EnhancedMode1Code)
{
    EnhancedMode1Code dtIn;
    KDataStream stream = dtIn.Encode();
    EnhancedMode1Code dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, ExplosionDescriptor)
{
    ExplosionDescriptor dtIn;
    KDataStream stream = dtIn.Encode();
    ExplosionDescriptor dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IFF_Layer3)
{
    IFF_Layer3 dtIn;
    KDataStream stream = dtIn.Encode();
    IFF_Layer3 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IFF_Layer3Interrogator)
{
    IFF_Layer3Interrogator dtIn;
    KDataStream stream = dtIn.Encode();
    IFF_Layer3Interrogator dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IFF_Layer3Transponder)
{
    IFF_Layer3Transponder dtIn;
    KDataStream stream = dtIn.Encode();
    IFF_Layer3Transponder dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IOCommunicationsNode)
{
    IOCommunicationsNode dtIn;
    KDataStream stream = dtIn.Encode();
    IOCommunicationsNode dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, IOEffect)
{
    IOEffect dtIn;
    KDataStream stream = dtIn.Encode();
    IOEffect dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5InterrogatorBasicData)
{
    Mode5InterrogatorBasicData dtIn;
    KDataStream stream = dtIn.Encode();
    Mode5InterrogatorBasicData dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5InterrogatorStatus)
{
    Mode5InterrogatorStatus dtIn;
    KDataStream stream = dtIn.Encode();
    Mode5InterrogatorStatus dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5TransponderBasicData)
{
    Mode5TransponderBasicData dtIn;
    KDataStream stream = dtIn.Encode();
    Mode5TransponderBasicData dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5TransponderStatus)
{
    Mode5TransponderStatus dtIn;
    KDataStream stream = dtIn.Encode();
    Mode5TransponderStatus dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, Mode5TransponderSupplementalData)
{
    Mode5TransponderSupplementalData dtIn;
    KDataStream stream = dtIn.Encode();
    Mode5TransponderSupplementalData dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, ModeXCodeRecord)
{
    ModeXCodeRecord dtIn;
    KDataStream stream = dtIn.Encode();
    ModeXCodeRecord dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode7, StandardVariable)
{
    StandardVariable dtIn;
    KDataStream stream = dtIn.Encode();
    StandardVariable dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

#endif
