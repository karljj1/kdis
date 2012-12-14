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

#include "./Entity_State_Update_PDU.h"

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

Entity_State_Update_PDU::Entity_State_Update_PDU( void ) :
    m_ui8Padding1( 0 ),
    m_ui8NumOfArticulationParams( 0 )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = EntityStateUpdate_PDU_Type;
    m_ui16PDULength = ENTITY_STATE_UPDATE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Entity_State_Update_PDU::Entity_State_Update_PDU( KDataStream & stream ) throw( KException )
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

Entity_State_Update_PDU::Entity_State_Update_PDU( const EntityIdentifier & EI, const Vector & EntityLinearVelocity,
        const WorldCoordinates & EntityLocation, const EulerAngles & EntityOrientation,
        const EntityAppearance & EA ) :
    m_ui8Padding1( 0 ),
    m_EntityID( EI ),
    m_ui8NumOfArticulationParams( 0 ),
    m_EntityLinearVelocity( EntityLinearVelocity ),
    m_EntityLocation( EntityLocation ),
    m_EntityOrientation( EntityOrientation ),
    m_EntityAppearance( EA )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = EntityStateUpdate_PDU_Type;
    m_ui16PDULength = ENTITY_STATE_UPDATE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Entity_State_Update_PDU::~Entity_State_Update_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::SetEntityIdentifier( const EntityIdentifier & EI )
{
    m_EntityID = EI;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Entity_State_Update_PDU::GetEntityIdentifier() const
{
    return m_EntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Entity_State_Update_PDU::GetEntityIdentifier()
{
    return m_EntityID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Entity_State_Update_PDU::GetNumberOfArticulationParams() const
{
    return m_vArticulationParameters.size();
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::AddArticulationParameter( const ArticulationParameters & AP )
{
    m_vArticulationParameters.push_back( AP );
    ++m_ui8NumOfArticulationParams;
    m_ui16PDULength += ArticulationParameters::ARTICULATION_PARAMETERS_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::SetArticulationParameters( const vector<ArticulationParameters> & AP )
{
    m_vArticulationParameters = AP;
    m_ui8NumOfArticulationParams = m_vArticulationParameters.size();
    m_ui16PDULength = ENTITY_STATE_UPDATE_PDU_SIZE + ( m_ui8NumOfArticulationParams * ArticulationParameters::ARTICULATION_PARAMETERS_SIZE );
}

//////////////////////////////////////////////////////////////////////////

const vector<ArticulationParameters> & Entity_State_Update_PDU::GetArticulationParameters() const
{
    return m_vArticulationParameters;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::ClearArticulationParameters()
{
    m_vArticulationParameters.clear();
    m_ui8NumOfArticulationParams = 0;
    m_ui16PDULength = ENTITY_STATE_UPDATE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString Entity_State_Update_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Entity State Update PDU-\n"
       << "Entity ID:\n"
       << IndentString( m_EntityID.GetAsString(), 1 )
       << "Number Of Articulation Params:  " << ( KUINT16 )m_ui8NumOfArticulationParams << "\n"
       << "Linear Velocity:                " << m_EntityLinearVelocity.GetAsString()
       << "Entity Location:                " << m_EntityLocation.GetAsString()
       << "Entity Orientation:             " << m_EntityOrientation.GetAsString();
    // We can not print the entity appearance as we do not have the entity type.

    // Articulated parts
    vector<ArticulationParameters>::const_iterator citr = m_vArticulationParameters.begin();
    vector<ArticulationParameters>::const_iterator citrEnd = m_vArticulationParameters.end();

    for( ; citr != citrEnd; ++ citr )
    {
        ss << IndentString( citr->GetAsString(), 1 );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ENTITY_STATE_UPDATE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vArticulationParameters.clear();

    Header::Decode( stream );

    stream >> KDIS_STREAM m_EntityID
           >> m_ui8NumOfArticulationParams
           >> KDIS_STREAM m_EntityLinearVelocity
           >> KDIS_STREAM m_EntityLocation
           >> KDIS_STREAM m_EntityOrientation
           >> KDIS_STREAM m_EntityAppearance;

    for( KUINT8 i = 0; i < m_ui8NumOfArticulationParams; ++i )
    {
        m_vArticulationParameters.push_back( ArticulationParameters( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Entity_State_Update_PDU::Encode() const
{
    KDataStream stream;

    Entity_State_Update_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );
    stream << KDIS_STREAM m_EntityID
           << m_ui8NumOfArticulationParams
           << KDIS_STREAM m_EntityLinearVelocity
           << KDIS_STREAM m_EntityLocation
           << KDIS_STREAM m_EntityOrientation
           << KDIS_STREAM m_EntityAppearance;

    // Add the articulated parts
    vector<ArticulationParameters>::const_iterator citr = m_vArticulationParameters.begin();
    vector<ArticulationParameters>::const_iterator citrEnd = m_vArticulationParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Entity_State_Update_PDU::operator == ( const Entity_State_Update_PDU & Value ) const
{
    if( Header::operator                !=( Value ) )                           return false;
    if( m_EntityID                      != Value.m_EntityID )                   return false;
    if( m_ui8NumOfArticulationParams    != Value.m_ui8NumOfArticulationParams ) return false;
    if( m_EntityLinearVelocity          != Value.m_EntityLinearVelocity )       return false;
    if( m_EntityLocation                != Value.m_EntityLocation )             return false;
    if( m_EntityOrientation             != Value.m_EntityOrientation )          return false;
    if( m_EntityAppearance              != Value.m_EntityAppearance )           return false;
    if( m_vArticulationParameters       != Value.m_vArticulationParameters )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Entity_State_Update_PDU::operator != ( const Entity_State_Update_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



