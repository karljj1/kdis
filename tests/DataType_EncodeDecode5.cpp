#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/DataTypes/AntennaLocation.h"
#include "KDIS/DataTypes/ArticulatedPart.h"
#include "KDIS/DataTypes/AttachedPart.h"
#include "KDIS/DataTypes/ClockTime.h"
#include "KDIS/DataTypes/CryptoSystem.h"
#include "KDIS/DataTypes/DeadReckoningParameter.h"
#include "KDIS/DataTypes/Descriptor.h"
#include "KDIS/DataTypes/EmissionSystem.h"
#include "KDIS/DataTypes/EmitterBeam.h"
#include "KDIS/DataTypes/EmitterSystem.h"
#include "KDIS/DataTypes/EncodingScheme.h"
#include "KDIS/DataTypes/EntityAppearance.h"
#include "KDIS/DataTypes/EntityCapabilities.h"
#include "KDIS/DataTypes/EntityIdentifier.h"
#include "KDIS/DataTypes/EntityMarking.h"
#include "KDIS/DataTypes/EntityType.h"
#include "KDIS/DataTypes/EulerAngles.h"
#include "KDIS/DataTypes/FixedDatum.h"
#include "KDIS/DataTypes/FundamentalParameterData.h"
#include "KDIS/DataTypes/ModulationType.h"
#include "KDIS/DataTypes/MunitionDescriptor.h"
#include "KDIS/DataTypes/RadioEntityType.h"
#include "KDIS/DataTypes/SimulationIdentifier.h"
#include "KDIS/DataTypes/Supplies.h"
#include "KDIS/DataTypes/TimeStamp.h"
#include "KDIS/DataTypes/TrackJamTargetIdentifier.h"
#include "KDIS/DataTypes/VariableDatum.h"
#include "KDIS/DataTypes/VariableParameter.h"
#include "KDIS/DataTypes/Vector.h"
#include "KDIS/DataTypes/WorldCoordinates.h"

using namespace KDIS;
using namespace DATA_TYPE;

TEST(DataType_EncodeDecode5, AntennaLocation)
{
    AntennaLocation dtIn;
    KDataStream stream = dtIn.Encode();
    AntennaLocation dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, ArticulatedPart)
{
    ArticulatedPart dtIn;
    KDataStream stream = dtIn.Encode();
    ArticulatedPart dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, AttachedPart)
{
    AttachedPart dtIn;
    KDataStream stream = dtIn.Encode();
    AttachedPart dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, ClockTime)
{
    ClockTime dtIn;
    KDataStream stream = dtIn.Encode();
    ClockTime dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, CryptoSystem)
{
    CryptoSystem dtIn;
    KDataStream stream = dtIn.Encode();
    CryptoSystem dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, DeadReckoningParameter)
{
    DeadReckoningParameter dtIn;
    KDataStream stream = dtIn.Encode();
    DeadReckoningParameter dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EmissionSystem)
{
    EmissionSystem dtIn;
    KDataStream stream = dtIn.Encode();
    EmissionSystem dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EmitterBeam)
{
    EmitterBeam dtIn;
    KDataStream stream = dtIn.Encode();
    EmitterBeam dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EmitterSystem)
{
    EmitterSystem dtIn;
    KDataStream stream = dtIn.Encode();
    EmitterSystem dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EncodingScheme)
{
    EncodingScheme dtIn;
    KDataStream stream = dtIn.Encode();
    EncodingScheme dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityAppearance)
{
    EntityAppearance dtIn;
    KDataStream stream = dtIn.Encode();
    EntityAppearance dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityCapabilities)
{
    EntityCapabilities dtIn;
    KDataStream stream = dtIn.Encode();
    EntityCapabilities dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityIdentifier)
{
    EntityIdentifier dtIn;
    KDataStream stream = dtIn.Encode();
    EntityIdentifier dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityMarking)
{
    EntityMarking dtIn;
    KDataStream stream = dtIn.Encode();
    EntityMarking dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EntityType)
{
    EntityType dtIn;
    KDataStream stream = dtIn.Encode();
    EntityType dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, EulerAngles)
{
    EulerAngles dtIn;
    KDataStream stream = dtIn.Encode();
    EulerAngles dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, FixedDatum)
{
    FixedDatum dtIn;
    KDataStream stream = dtIn.Encode();
    FixedDatum dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, FundamentalParameterData)
{
    FundamentalParameterData dtIn;
    KDataStream stream = dtIn.Encode();
    FundamentalParameterData dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, ModulationType)
{
    ModulationType dtIn;
    KDataStream stream = dtIn.Encode();
    ModulationType dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, MunitionDescriptor)
{
    MunitionDescriptor dtIn;
    KDataStream stream = dtIn.Encode();
    MunitionDescriptor dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, RadioEntityType)
{
    RadioEntityType dtIn;
    KDataStream stream = dtIn.Encode();
    RadioEntityType dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, SimulationIdentifier)
{
    SimulationIdentifier dtIn;
    KDataStream stream = dtIn.Encode();
    SimulationIdentifier dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, Supplies)
{
    Supplies dtIn;
    KDataStream stream = dtIn.Encode();
    Supplies dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, TimeStamp)
{
    TimeStamp dtIn;
    KDataStream stream = dtIn.Encode();
    TimeStamp dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, TrackJamTargetIdentifier)
{
    TrackJamTargetIdentifier dtIn;
    KDataStream stream = dtIn.Encode();
    TrackJamTargetIdentifier dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, VariableDatum)
{
    VariableDatum dtIn;
    KDataStream stream = dtIn.Encode();
    VariableDatum dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, VariableParameter)
{
    VariableParameter dtIn;
    KDataStream stream = dtIn.Encode();
    VariableParameter dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, Vector)
{
    Vector dtIn;
    KDataStream stream = dtIn.Encode();
    Vector dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode5, WorldCoordinates)
{
    WorldCoordinates dtIn;
    KDataStream stream = dtIn.Encode();
    WorldCoordinates dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}
