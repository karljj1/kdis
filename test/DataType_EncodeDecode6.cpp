#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/KDefines.h"

#if DIS_VERSION > 5

#include "KDIS/DataTypes/AcousticEmitterSystem.h"
#include "KDIS/DataTypes/AggregateIdentifier.h"
#include "KDIS/DataTypes/AggregateMarking.h"
#include "KDIS/DataTypes/AggregateType.h"
#include "KDIS/DataTypes/APA.h"
#include "KDIS/DataTypes/ArealObjectAppearance.h"
#include "KDIS/DataTypes/BeamData.h"
#include "KDIS/DataTypes/BoundingSphereRecord.h"
#include "KDIS/DataTypes/COMBICState.h"
#include "KDIS/DataTypes/CommunicationsChannelType.h"
#include "KDIS/DataTypes/ConeRecord1.h"
#include "KDIS/DataTypes/ConeRecord2.h"
#include "KDIS/DataTypes/EllipsoidRecord1.h"
#include "KDIS/DataTypes/EllipsoidRecord2.h"
#include "KDIS/DataTypes/EntityDestinationRecord.h"
#include "KDIS/DataTypes/EnvironmentType.h"
#include "KDIS/DataTypes/FlareState.h"
#include "KDIS/DataTypes/FundamentalOperationalData.h"
#include "KDIS/DataTypes/GaussianPlumeRecord.h"
#include "KDIS/DataTypes/GaussianPuffRecord.h"
#include "KDIS/DataTypes/GED_BasicFixedWingAircraft.h"
#include "KDIS/DataTypes/GED_BasicGroundCombatSoldier.h"
#include "KDIS/DataTypes/GED_BasicGroundCombatVehicle.h"
#include "KDIS/DataTypes/GED_BasicRotorWingAircraft.h"
#include "KDIS/DataTypes/GED_EnhancedFixedWingAircraft.h"
#include "KDIS/DataTypes/GED_EnhancedGroundCombatSoldier.h"
#include "KDIS/DataTypes/GED_EnhancedGroundCombatVehicle.h"
#include "KDIS/DataTypes/GED_EnhancedRotaryWingAircraft.h"
#include "KDIS/DataTypes/GED_GroundLogisticsVehicle.h"
#include "KDIS/DataTypes/GridAxisIrregular.h"
#include "KDIS/DataTypes/GridAxisRegular.h"
#include "KDIS/DataTypes/GridDataType0.h"
#include "KDIS/DataTypes/GridDataType1.h"
#include "KDIS/DataTypes/GridDataType2.h"
#include "KDIS/DataTypes/GroupAssignmentRecord.h"
#include "KDIS/DataTypes/GroupDestinationRecord.h"
#include "KDIS/DataTypes/IFF_ATC_NAVAIDS_FundamentalParameterData.h"
#include "KDIS/DataTypes/IFF_Layer2.h"
#include "KDIS/DataTypes/IntercomCommunicationParameters.h"
#include "KDIS/DataTypes/LayerHeader.h"
#include "KDIS/DataTypes/LE_DeadReckoningParameter.h"
#include "KDIS/DataTypes/LE_EntityIdentifier.h"
#include "KDIS/DataTypes/LE_EulerAngles.h"
#include "KDIS/DataTypes/LinearObjectAppearance.h"
#include "KDIS/DataTypes/LinearSegmentParameter.h"
#include "KDIS/DataTypes/LineRecord1.h"
#include "KDIS/DataTypes/LineRecord2.h"
#include "KDIS/DataTypes/MinefieldAppearance.h"
#include "KDIS/DataTypes/MinefieldDataFilter.h"
#include "KDIS/DataTypes/MineFusing.h"
#include "KDIS/DataTypes/MinePaintScheme.h"
#include "KDIS/DataTypes/NamedLocationIdentifier.h"
#include "KDIS/DataTypes/ObjectAppearance.h"
#include "KDIS/DataTypes/ObjectType.h"
#include "KDIS/DataTypes/OrientationError.h"
#include "KDIS/DataTypes/PerimeterPointCoordinate.h"
#include "KDIS/DataTypes/PointObjectAppearance.h"
#include "KDIS/DataTypes/PointRecord1.h"
#include "KDIS/DataTypes/PointRecord2.h"
#include "KDIS/DataTypes/PositionError.h"
#include "KDIS/DataTypes/PropulsionSystem.h"
#include "KDIS/DataTypes/RecordSet.h"
#include "KDIS/DataTypes/RectangularVolumeRecord1.h"
#include "KDIS/DataTypes/RectangularVolumeRecord2.h"
#include "KDIS/DataTypes/RectangularVolumeRecord3.h"
#include "KDIS/DataTypes/RelationshipRecord.h"
#include "KDIS/DataTypes/RelativeWorldCoordinates.h"
#include "KDIS/DataTypes/SecondaryOperationalData.h"
#include "KDIS/DataTypes/Shaft.h"
#include "KDIS/DataTypes/SilentAggregateSystem.h"
#include "KDIS/DataTypes/SilentEntitySystem.h"
#include "KDIS/DataTypes/SphereRecord1.h"
#include "KDIS/DataTypes/SphereRecord2.h"
#include "KDIS/DataTypes/SystemIdentifier.h"
#include "KDIS/DataTypes/UnderwaterAcousticEmitterBeam.h"
#include "KDIS/DataTypes/UnderwaterAcousticEmitterSystem.h"
#include "KDIS/DataTypes/UnderwaterAcousticFundamentalParameterData.h"
#include "KDIS/DataTypes/VectoringNozzleSystem.h"

using namespace KDIS;
using namespace DATA_TYPE;

TEST(DataType_EncodeDecode6, AcousticEmitterSystem)
{
    AcousticEmitterSystem dtIn;
    KDataStream stream = dtIn.Encode();
    AcousticEmitterSystem dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, AggregateIdentifier)
{
    AggregateIdentifier dtIn;
    KDataStream stream = dtIn.Encode();
    AggregateIdentifier dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, AggregateMarking)
{
    AggregateMarking dtIn;
    KDataStream stream = dtIn.Encode();
    AggregateMarking dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, AggregateType)
{
    AggregateType dtIn;
    KDataStream stream = dtIn.Encode();
    AggregateType dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, APA)
{
    APA dtIn;
    KDataStream stream = dtIn.Encode();
    APA dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ArealObjectAppearance)
{
    ArealObjectAppearance dtIn;
    KDataStream stream = dtIn.Encode();
    ArealObjectAppearance dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, BeamData)
{
    BeamData dtIn;
    KDataStream stream = dtIn.Encode();
    BeamData dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, BoundingSphereRecord)
{
    BoundingSphereRecord dtIn;
    KDataStream stream = dtIn.Encode();
    BoundingSphereRecord dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, COMBICState)
{
    COMBICState dtIn;
    KDataStream stream = dtIn.Encode();
    COMBICState dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, CommunicationsChannelType)
{
    CommunicationsChannelType dtIn;
    KDataStream stream = dtIn.Encode();
    CommunicationsChannelType dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ConeRecord1)
{
    ConeRecord1 dtIn;
    KDataStream stream = dtIn.Encode();
    ConeRecord1 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ConeRecord2)
{
    ConeRecord2 dtIn;
    KDataStream stream = dtIn.Encode();
    ConeRecord2 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, EllipsoidRecord1)
{
    EllipsoidRecord1 dtIn;
    KDataStream stream = dtIn.Encode();
    EllipsoidRecord1 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, EllipsoidRecord2)
{
    EllipsoidRecord2 dtIn;
    KDataStream stream = dtIn.Encode();
    EllipsoidRecord2 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, EntityDestinationRecord)
{
    EntityDestinationRecord dtIn;
    KDataStream stream = dtIn.Encode();
    EntityDestinationRecord dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, EnvironmentType)
{
    EnvironmentType dtIn;
    KDataStream stream = dtIn.Encode();
    EnvironmentType dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, FlareState)
{
    FlareState dtIn;
    KDataStream stream = dtIn.Encode();
    FlareState dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, FundamentalOperationalData)
{
    FundamentalOperationalData dtIn;
    KDataStream stream = dtIn.Encode();
    FundamentalOperationalData dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GaussianPlumeRecord)
{
    GaussianPlumeRecord dtIn;
    KDataStream stream = dtIn.Encode();
    GaussianPlumeRecord dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GaussianPuffRecord)
{
    GaussianPuffRecord dtIn;
    KDataStream stream = dtIn.Encode();
    GaussianPuffRecord dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicFixedWingAircraft)
{
    GED_BasicFixedWingAircraft dtIn;
    KDataStream stream = dtIn.Encode();
    GED_BasicFixedWingAircraft dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicGroundCombatSoldier)
{
    GED_BasicGroundCombatSoldier dtIn;
    KDataStream stream = dtIn.Encode();
    GED_BasicGroundCombatSoldier dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicGroundCombatVehicle)
{
    GED_BasicGroundCombatVehicle dtIn;
    KDataStream stream = dtIn.Encode();
    GED_BasicGroundCombatVehicle dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_BasicRotorWingAircraft)
{
    GED_BasicRotorWingAircraft dtIn;
    KDataStream stream = dtIn.Encode();
    GED_BasicRotorWingAircraft dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedFixedWingAircraft)
{
    GED_EnhancedFixedWingAircraft dtIn;
    KDataStream stream = dtIn.Encode();
    GED_EnhancedFixedWingAircraft dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedGroundCombatSoldier)
{
    GED_EnhancedGroundCombatSoldier dtIn;
    KDataStream stream = dtIn.Encode();
    GED_EnhancedGroundCombatSoldier dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedGroundCombatVehicle)
{
    GED_EnhancedGroundCombatVehicle dtIn;
    KDataStream stream = dtIn.Encode();
    GED_EnhancedGroundCombatVehicle dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_EnhancedRotaryWingAircraft)
{
    GED_EnhancedRotaryWingAircraft dtIn;
    KDataStream stream = dtIn.Encode();
    GED_EnhancedRotaryWingAircraft dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GED_GroundLogisticsVehicle)
{
    GED_GroundLogisticsVehicle dtIn;
    KDataStream stream = dtIn.Encode();
    GED_GroundLogisticsVehicle dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridAxisIrregular)
{
    GridAxisIrregular dtIn;
    KDataStream stream = dtIn.Encode();
    GridAxisIrregular dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridAxisRegular)
{
    GridAxisRegular dtIn;
    KDataStream stream = dtIn.Encode();
    GridAxisRegular dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridDataType0)
{
    GridDataType0 dtIn;
    KDataStream stream = dtIn.Encode();
    GridDataType0 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridDataType1)
{
    GridDataType1 dtIn;
    KDataStream stream = dtIn.Encode();
    GridDataType1 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GridDataType2)
{
    GridDataType2 dtIn;
    KDataStream stream = dtIn.Encode();
    GridDataType2 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GroupAssignmentRecord)
{
    GroupAssignmentRecord dtIn;
    KDataStream stream = dtIn.Encode();
    GroupAssignmentRecord dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, GroupDestinationRecord)
{
    GroupDestinationRecord dtIn;
    KDataStream stream = dtIn.Encode();
    GroupDestinationRecord dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, IFF_ATC_NAVAIDS_FundamentalParameterData)
{
    IFF_ATC_NAVAIDS_FundamentalParameterData dtIn;
    KDataStream stream = dtIn.Encode();
    IFF_ATC_NAVAIDS_FundamentalParameterData dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, IFF_Layer2)
{
    IFF_Layer2 dtIn;
    KDataStream stream = dtIn.Encode();
    IFF_Layer2 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, IntercomCommunicationParameters)
{
    IntercomCommunicationParameters dtIn;
    KDataStream stream = dtIn.Encode();
    IntercomCommunicationParameters dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LayerHeader)
{
    LayerHeader dtIn;
    KDataStream stream = dtIn.Encode();
    LayerHeader dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LE_DeadReckoningParameter)
{
    LE_DeadReckoningParameter dtIn;
    KDataStream stream = dtIn.Encode();
    LE_DeadReckoningParameter dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LE_EntityIdentifier)
{
    LE_EntityIdentifier dtIn;
    KDataStream stream = dtIn.Encode();
    LE_EntityIdentifier dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LE_EulerAngles)
{
    LE_EulerAngles dtIn;
    KDataStream stream = dtIn.Encode();
    LE_EulerAngles dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LinearObjectAppearance)
{
    LinearObjectAppearance dtIn;
    KDataStream stream = dtIn.Encode();
    LinearObjectAppearance dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LinearSegmentParameter)
{
    LinearSegmentParameter dtIn;
    KDataStream stream = dtIn.Encode();
    LinearSegmentParameter dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LineRecord1)
{
    LineRecord1 dtIn;
    KDataStream stream = dtIn.Encode();
    LineRecord1 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, LineRecord2)
{
    LineRecord2 dtIn;
    KDataStream stream = dtIn.Encode();
    LineRecord2 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, MinefieldAppearance)
{
    MinefieldAppearance dtIn;
    KDataStream stream = dtIn.Encode();
    MinefieldAppearance dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, MinefieldDataFilter)
{
    MinefieldDataFilter dtIn;
    KDataStream stream = dtIn.Encode();
    MinefieldDataFilter dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, MineFusing)
{
    MineFusing dtIn;
    KDataStream stream = dtIn.Encode();
    MineFusing dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, MinePaintScheme)
{
    MinePaintScheme dtIn;
    KDataStream stream = dtIn.Encode();
    MinePaintScheme dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, NamedLocationIdentifier)
{
    NamedLocationIdentifier dtIn;
    KDataStream stream = dtIn.Encode();
    NamedLocationIdentifier dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ObjectAppearance)
{
    ObjectAppearance dtIn;
    KDataStream stream = dtIn.Encode();
    ObjectAppearance dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, ObjectType)
{
    ObjectType dtIn;
    KDataStream stream = dtIn.Encode();
    ObjectType dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, OrientationError)
{
    OrientationError dtIn;
    KDataStream stream = dtIn.Encode();
    OrientationError dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PerimeterPointCoordinate)
{
    PerimeterPointCoordinate dtIn;
    KDataStream stream = dtIn.Encode();
    PerimeterPointCoordinate dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PointObjectAppearance)
{
    PointObjectAppearance dtIn;
    KDataStream stream = dtIn.Encode();
    PointObjectAppearance dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PointRecord1)
{
    PointRecord1 dtIn;
    KDataStream stream = dtIn.Encode();
    PointRecord1 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PointRecord2)
{
    PointRecord2 dtIn;
    KDataStream stream = dtIn.Encode();
    PointRecord2 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PositionError)
{
    PositionError dtIn;
    KDataStream stream = dtIn.Encode();
    PositionError dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, PropulsionSystem)
{
    PropulsionSystem dtIn;
    KDataStream stream = dtIn.Encode();
    PropulsionSystem dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RecordSet)
{
    RecordSet dtIn;
    KDataStream stream = dtIn.Encode();
    RecordSet dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RectangularVolumeRecord1)
{
    RectangularVolumeRecord1 dtIn;
    KDataStream stream = dtIn.Encode();
    RectangularVolumeRecord1 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RectangularVolumeRecord2)
{
    RectangularVolumeRecord2 dtIn;
    KDataStream stream = dtIn.Encode();
    RectangularVolumeRecord2 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RectangularVolumeRecord3)
{
    RectangularVolumeRecord3 dtIn;
    KDataStream stream = dtIn.Encode();
    RectangularVolumeRecord3 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RelationshipRecord)
{
    RelationshipRecord dtIn;
    KDataStream stream = dtIn.Encode();
    RelationshipRecord dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, RelativeWorldCoordinates)
{
    RelativeWorldCoordinates dtIn;
    KDataStream stream = dtIn.Encode();
    RelativeWorldCoordinates dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SecondaryOperationalData)
{
    SecondaryOperationalData dtIn;
    KDataStream stream = dtIn.Encode();
    SecondaryOperationalData dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, Shaft)
{
    Shaft dtIn;
    KDataStream stream = dtIn.Encode();
    Shaft dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SilentAggregateSystem)
{
    SilentAggregateSystem dtIn;
    KDataStream stream = dtIn.Encode();
    SilentAggregateSystem dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SilentEntitySystem)
{
    SilentEntitySystem dtIn;
    KDataStream stream = dtIn.Encode();
    SilentEntitySystem dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SphereRecord1)
{
    SphereRecord1 dtIn;
    KDataStream stream = dtIn.Encode();
    SphereRecord1 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SphereRecord2)
{
    SphereRecord2 dtIn;
    KDataStream stream = dtIn.Encode();
    SphereRecord2 dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, SystemIdentifier)
{
    SystemIdentifier dtIn;
    KDataStream stream = dtIn.Encode();
    SystemIdentifier dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, UnderwaterAcousticEmitterBeam)
{
    UnderwaterAcousticEmitterBeam dtIn;
    KDataStream stream = dtIn.Encode();
    UnderwaterAcousticEmitterBeam dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, UnderwaterAcousticEmitterSystem)
{
    UnderwaterAcousticEmitterSystem dtIn;
    KDataStream stream = dtIn.Encode();
    UnderwaterAcousticEmitterSystem dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, UnderwaterAcousticFundamentalParameterData)
{
    UnderwaterAcousticFundamentalParameterData dtIn;
    KDataStream stream = dtIn.Encode();
    UnderwaterAcousticFundamentalParameterData dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

TEST(DataType_EncodeDecode6, VectoringNozzleSystem)
{
    VectoringNozzleSystem dtIn;
    KDataStream stream = dtIn.Encode();
    VectoringNozzleSystem dtOut(stream);
    EXPECT_EQ(dtIn, dtOut);
    EXPECT_EQ(0, stream.GetBufferSize());
}

#endif
