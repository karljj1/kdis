/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include "./Entity_State_Update_PDU.h"
#include "./../../DataTypes/ArticulatedPart.h"
#include "./../../DataTypes/AttachedPart.h"

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

Entity_State_Update_PDU::Entity_State_Update_PDU() :
    m_ui8Padding1( 0 ),
    m_ui8NumOfVariableParams( 0 )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = EntityStateUpdate_PDU_Type;
    m_ui16PDULength = ENTITY_STATE_UPDATE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Entity_State_Update_PDU::Entity_State_Update_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Entity_State_Update_PDU::Entity_State_Update_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Entity_State_Update_PDU::Entity_State_Update_PDU( const EntityIdentifier & EI, const Vector & EntityLinearVelocity,
        const WorldCoordinates & EntityLocation, const EulerAngles & EntityOrientation,
        const EntityAppearance & EA ) :
    m_ui8Padding1( 0 ),
    m_EntityID( EI ),
    m_ui8NumOfVariableParams( 0 ),
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

Entity_State_Update_PDU::~Entity_State_Update_PDU()
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

KUINT8 Entity_State_Update_PDU::GetNumberOfVariableParams() const
{
    return m_vVariableParameters.size();
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::SetEntityLinearVelocity( const Vector & ELV )
{
    m_EntityLinearVelocity = ELV;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Entity_State_Update_PDU::GetEntityLinearVelocity() const
{
    return m_EntityLinearVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & Entity_State_Update_PDU::GetEntityLinearVelocity()
{
    return m_EntityLinearVelocity;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::SetEntityLocation( const WorldCoordinates & EL )
{
    m_EntityLocation = EL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & Entity_State_Update_PDU::GetEntityLocation() const
{
    return m_EntityLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & Entity_State_Update_PDU::GetEntityLocation()
{
    return m_EntityLocation;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::SetEntityOrientation( const EulerAngles & EO )
{
    m_EntityOrientation = EO;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & Entity_State_Update_PDU::GetEntityOrientation() const
{
    return m_EntityOrientation;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & Entity_State_Update_PDU::GetEntityOrientation()
{
    return m_EntityOrientation;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::SetEntityAppearance( const EntityAppearance & EA )
{
    m_EntityAppearance = EA;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & Entity_State_Update_PDU::GetEntityAppearance() const
{
    return m_EntityAppearance;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & Entity_State_Update_PDU::GetEntityAppearance()
{
    return m_EntityAppearance;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::AddVariableParameter( VarPrmPtr VP )
{
    m_vVariableParameters.push_back( VP );
    ++m_ui8NumOfVariableParams;
	m_ui16PDULength += VariableParameter::VARIABLE_PARAMETER_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::SetVariableParameters( const vector<VarPrmPtr> & VP )
{
    m_vVariableParameters = VP;
    m_ui8NumOfVariableParams = m_vVariableParameters.size();
    m_ui16PDULength = ENTITY_STATE_UPDATE_PDU_SIZE + ( m_ui8NumOfVariableParams * VariableParameter::VARIABLE_PARAMETER_SIZE );
}

//////////////////////////////////////////////////////////////////////////

const vector<VarPrmPtr> & Entity_State_Update_PDU::GetVariableParameters() const
{
    return m_vVariableParameters;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::ClearVariableParameters()
{
    m_vVariableParameters.clear();
    m_ui8NumOfVariableParams = 0;
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
       << "Number Of Variable Params:      " << ( KUINT16 )m_ui8NumOfVariableParams << "\n"
       << "Linear Velocity:                " << m_EntityLinearVelocity.GetAsString()
       << "Entity Location:                " << m_EntityLocation.GetAsString()
       << "Entity Orientation:             " << m_EntityOrientation.GetAsString();
    // We can not print the entity appearance as we do not have the entity type.

    // Variable params
    vector<VarPrmPtr>::const_iterator citr = m_vVariableParameters.begin();
    vector<VarPrmPtr>::const_iterator citrEnd = m_vVariableParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ss << IndentString( ( *citr )->GetAsString(), 1 );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_Update_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < ENTITY_STATE_UPDATE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vVariableParameters.clear();

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_EntityID
		   >> m_ui8Padding1
           >> m_ui8NumOfVariableParams
           >> KDIS_STREAM m_EntityLinearVelocity
           >> KDIS_STREAM m_EntityLocation
           >> KDIS_STREAM m_EntityOrientation
           >> KDIS_STREAM m_EntityAppearance;

	for( KUINT8 i = 0; i < m_ui8NumOfVariableParams; ++i )
	{
		// Save the current write position so we can peek.
		KUINT16 pos = stream.GetCurrentWritePosition();
		KUINT8 paramTyp;

		// Extract the  type then reset the stream.
		stream >> paramTyp;
		stream.SetCurrentWritePosition( pos );

		// Use the factory decoder. 
		VariableParameter * p = VariableParameter::FactoryDecode( paramTyp, stream );

		// Did we find a custom decoder? if not then use the default.
		if( p )
		{
			m_vVariableParameters.push_back( VarPrmPtr( p ) );
		}
		else
		{
			// Default internals
			switch( paramTyp )
			{
				case ArticulatedPartType:				
					m_vVariableParameters.push_back( VarPrmPtr( new ArticulatedPart( stream ) ) );
					break;

				case AttachedPartType:
					m_vVariableParameters.push_back( VarPrmPtr( new AttachedPart( stream ) ) );
					break;

				default:
					m_vVariableParameters.push_back( VarPrmPtr( new VariableParameter( stream ) ) );
					break;
			}
		}
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
		   << m_ui8Padding1
           << m_ui8NumOfVariableParams
           << KDIS_STREAM m_EntityLinearVelocity
           << KDIS_STREAM m_EntityLocation
           << KDIS_STREAM m_EntityOrientation
           << KDIS_STREAM m_EntityAppearance;

    // Add the articulated parts
    vector<VarPrmPtr>::const_iterator citr = m_vVariableParameters.begin();
    vector<VarPrmPtr>::const_iterator citrEnd = m_vVariableParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ( *citr )->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Entity_State_Update_PDU::operator == ( const Entity_State_Update_PDU & Value ) const
{
    if( Header::operator                !=( Value ) )                           return false;
    if( m_EntityID                      != Value.m_EntityID )                   return false;
    if( m_ui8NumOfVariableParams    != Value.m_ui8NumOfVariableParams ) return false;
    if( m_EntityLinearVelocity          != Value.m_EntityLinearVelocity )       return false;
    if( m_EntityLocation                != Value.m_EntityLocation )             return false;
    if( m_EntityOrientation             != Value.m_EntityOrientation )          return false;
    if( m_EntityAppearance              != Value.m_EntityAppearance )           return false;
    if( m_vVariableParameters       != Value.m_vVariableParameters )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Entity_State_Update_PDU::operator != ( const Entity_State_Update_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



