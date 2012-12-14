/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include "./Designator_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Designator_PDU::Designator_PDU( void ) :
    m_ui16Padding1( 0 ),
    m_ui8Padding2( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = Designator_PDU_Type;
    m_ui16PDULength = DESIGNATOR_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Designator_PDU::Designator_PDU( KDataStream & stream ) throw( KException )
{
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
}

//////////////////////////////////////////////////////////////////////////

Designator_PDU::Designator_PDU( const EntityIdentifier & DesignatingEntityID, DesignatorCodeName CodeName,
                                const EntityIdentifier & DesignatedEntityID, DesignatorCode Code, KFLOAT32 Power,
                                KFLOAT32 WaveLength, const Vector & SpotLocationRegardsToEntity,
                                const WorldCoordinates & SpotLocation, DeadReckoningAlgorithm DRA,
                                const Vector & EntityLinearAcceleration ) :
    m_DesignatingEntityID( DesignatingEntityID ),
    m_ui16CodeName( CodeName ),
    m_DesignatedEntityID( DesignatedEntityID ),
    m_ui16Code( Code ),
    m_f32Power( Power ),
    m_f32WaveLength( WaveLength ),
    m_SpotRegardsToEntity( SpotLocationRegardsToEntity ),
    m_SpotLocation( SpotLocation ),
    m_ui8DeadReckoningAlgorithm( DRA ),
    m_ui16Padding1( 0 ),
    m_ui8Padding2( 0 ),
    m_EntityLinearAcceleration( EntityLinearAcceleration )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = Designator_PDU_Type;
    m_ui16PDULength = DESIGNATOR_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Designator_PDU::~Designator_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetDesignatingEntityID( const EntityIdentifier & ID )
{
    m_DesignatingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Designator_PDU::GetDesignatingEntityID() const
{
    return m_DesignatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Designator_PDU::GetDesignatingEntityID()
{
    return m_DesignatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetDesignatorCodeName( DesignatorCodeName CN )
{
    m_ui16CodeName = CN;
}

//////////////////////////////////////////////////////////////////////////

DesignatorCodeName Designator_PDU::GetDesignatorCodeName() const
{
    return ( DesignatorCodeName )m_ui16CodeName;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetDesignatedEntityID( const EntityIdentifier & ID )
{
    m_DesignatedEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Designator_PDU::GetDesignatedEntityID() const
{
    return m_DesignatedEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Designator_PDU::GetDesignatedEntityID()
{
    return m_DesignatedEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetDesignatorCode( DesignatorCode C )
{
    m_ui16Code = C;
}

//////////////////////////////////////////////////////////////////////////

DesignatorCode Designator_PDU::GetDesignatorCode() const
{
    return ( DesignatorCode )m_ui16Code;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetDesignatingPower( KFLOAT32 DP )
{
    m_f32Power = DP;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Designator_PDU::GetDesignatingPower() const
{
    return m_f32Power;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetDesignatingWaveLength( KFLOAT32 WL )
{
    m_f32WaveLength = WL;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Designator_PDU::GetDesignatingWaveLength() const
{
    return m_f32WaveLength;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetDesignatorSpotRespectToDesignatedEntity( const Vector & DPL )
{
    m_SpotRegardsToEntity = DPL;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Designator_PDU::GetDesignatorSpotRespectToDesignatedEntity() const
{
    return m_SpotRegardsToEntity;
}

//////////////////////////////////////////////////////////////////////////

Vector & Designator_PDU::GetDesignatorSpotRespectToDesignatedEntity()
{
    return m_SpotRegardsToEntity;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetSpotLocation( const WorldCoordinates & SL )
{
    m_SpotLocation = SL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & Designator_PDU::GetSpotLocation() const
{
    return m_SpotLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & Designator_PDU::GetSpotLocation()
{
    return m_SpotLocation;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetDeadReckoningAlgorithm( DeadReckoningAlgorithm DRA )
{
    m_ui8DeadReckoningAlgorithm = DRA;
}

//////////////////////////////////////////////////////////////////////////

DeadReckoningAlgorithm Designator_PDU::GetDeadReckoningAlgorithm() const
{
    return ( DeadReckoningAlgorithm )m_ui8DeadReckoningAlgorithm;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::SetEntityLinearAcceleration( const Vector & ELA )
{
    m_EntityLinearAcceleration = ELA;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Designator_PDU::GetEntityLinearAcceleration() const
{
    return m_EntityLinearAcceleration;
}

//////////////////////////////////////////////////////////////////////////

Vector & Designator_PDU::GetEntityLinearAcceleration()
{
    return m_EntityLinearAcceleration;
}

//////////////////////////////////////////////////////////////////////////

KString Designator_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Designator PDU-\n"
       << "Designating Entity ID:\n"
       << IndentString( m_DesignatingEntityID.GetAsString(), 1 )
       << "Code Name:                   " << m_ui16CodeName                            << "\n"
       << "Designated Entity ID:\n"
       << IndentString( m_DesignatedEntityID.GetAsString(), 1 )
       << "Code:                        " << m_ui16Code                                << "\n"
       << "Power(watts):                " << m_f32Power                                << "\n"
       << "Wave Length(microns):        " << m_f32WaveLength                           << "\n"
       << "Spot Location(Entity):       " << m_SpotRegardsToEntity.GetAsString()
       << "Spot World Location:         " << m_SpotLocation.GetAsString()
       << "Dead Reckoning Algorithm:    " << ( KUINT16 )m_ui8DeadReckoningAlgorithm    << "\n"
       << "Entity Linear Acceleration:  " << m_EntityLinearAcceleration.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < DESIGNATOR_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

    stream >> KDIS_STREAM m_DesignatingEntityID
           >> m_ui16CodeName
           >> KDIS_STREAM m_DesignatedEntityID
           >> m_ui16Code
           >> m_f32Power
           >> m_f32WaveLength
           >> KDIS_STREAM m_SpotRegardsToEntity
           >> KDIS_STREAM m_SpotLocation
           >> m_ui8DeadReckoningAlgorithm
           >> m_ui16Padding1
           >> m_ui8Padding2
           >> KDIS_STREAM m_EntityLinearAcceleration;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Designator_PDU::Encode() const
{
    KDataStream stream;

    Designator_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Designator_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_DesignatingEntityID
           << m_ui16CodeName
           << KDIS_STREAM m_DesignatedEntityID
           << m_ui16Code
           << m_f32Power
           << m_f32WaveLength
           << KDIS_STREAM m_SpotRegardsToEntity
           << KDIS_STREAM m_SpotLocation
           << m_ui8DeadReckoningAlgorithm
           << m_ui16Padding1
           << m_ui8Padding2
           << KDIS_STREAM m_EntityLinearAcceleration;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Designator_PDU::operator == ( const Designator_PDU & Value ) const
{
    if( Header::operator             !=( Value ) )                          return false;
    if( m_DesignatingEntityID        != Value.m_DesignatingEntityID )       return false;
    if( m_ui16CodeName               != Value.m_ui16CodeName )              return false;
    if( m_DesignatedEntityID         != Value.m_DesignatedEntityID )        return false;
    if( m_ui16Code                   != Value.m_ui16Code )                  return false;
    if( m_f32Power                   != Value.m_f32Power )                  return false;
    if( m_f32WaveLength              != Value.m_f32WaveLength )             return false;
    if( m_SpotRegardsToEntity        != Value.m_SpotRegardsToEntity )       return false;
    if( m_SpotLocation               != Value.m_SpotLocation )              return false;
    if( m_ui8DeadReckoningAlgorithm  != Value.m_ui8DeadReckoningAlgorithm ) return false;
    if( m_EntityLinearAcceleration   != Value.m_EntityLinearAcceleration )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Designator_PDU::operator != ( const Designator_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



