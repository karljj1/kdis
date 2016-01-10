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

#include "./Entity_State_PDU.h"
#include "./../../Extras/DeadReckoningCalculator.h"
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

Entity_State_PDU::Entity_State_PDU() :
    m_ui8NumOfVariableParams( 0 ),
    m_ui8ForceID( 0 ),
    m_pDrCalc( 0 )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = Entity_State_PDU_Type;
    m_ui16PDULength = ENTITY_STATE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Entity_State_PDU::Entity_State_PDU( KDataStream & stream ) throw( KException ) :
    m_pDrCalc( 0 )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Entity_State_PDU::Entity_State_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
    Header( H ),
    m_pDrCalc( 0 )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Entity_State_PDU::Entity_State_PDU( const Entity_State_PDU & ESPDU ) :
    Header( ESPDU ),
    m_EntityID( ESPDU.m_EntityID ),
    m_ui8ForceID( ESPDU.m_ui8ForceID ),
    m_ui8NumOfVariableParams( ESPDU.m_ui8NumOfVariableParams ),
    m_EntityType( ESPDU.m_EntityType ),
    m_AltEntityType( ESPDU.m_AltEntityType ),
    m_EntityLinearVelocity( ESPDU.m_EntityLinearVelocity ),
    m_EntityLocation( ESPDU.m_EntityLocation ),
    m_EntityOrientation( ESPDU.m_EntityOrientation ),
    m_EntityAppearance( ESPDU.m_EntityAppearance ),
    m_DeadReckoningParameter( ESPDU.m_DeadReckoningParameter ),
    m_EntityMarking( ESPDU.m_EntityMarking ),
    m_EntityCapabilities( ESPDU.m_EntityCapabilities ),
    m_vVariableParameters( ESPDU.m_vVariableParameters ),
    m_pDrCalc( ESPDU.m_pDrCalc ? new DeadReckoningCalculator( *ESPDU.m_pDrCalc ) : NULL )
{
}

//////////////////////////////////////////////////////////////////////////

Entity_State_PDU::Entity_State_PDU( const EntityIdentifier & EI, ForceID ID, const EntityType & Type, const EntityType & AltType,
                                    const Vector & EntityLinearVelocity, const WorldCoordinates & EntityLocation,
                                    const EulerAngles & EntityOrientation, const EntityAppearance & EA,
                                    const DeadReckoningParameter & DRP, const EntityMarking & EM,
                                    const EntityCapabilities & EC ) :
    m_EntityID( EI ),
    m_ui8ForceID( ID ),
    m_ui8NumOfVariableParams( 0 ),
    m_EntityType( Type ),
    m_AltEntityType( AltType ),
    m_EntityLinearVelocity( EntityLinearVelocity ),
    m_EntityLocation( EntityLocation ),
    m_EntityOrientation( EntityOrientation ),
    m_EntityAppearance( EA ),
    m_DeadReckoningParameter( DRP ),
    m_EntityMarking( EM ),
    m_EntityCapabilities( EC ),
    m_pDrCalc( 0 )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = Entity_State_PDU_Type;
    m_ui16PDULength = ENTITY_STATE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Entity_State_PDU::~Entity_State_PDU()
{
    if( m_pDrCalc )
    {
        delete m_pDrCalc;
    }
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetEntityIdentifier( const EntityIdentifier & EI )
{
    m_EntityID = EI;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Entity_State_PDU::GetEntityIdentifier() const
{
    return m_EntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Entity_State_PDU::GetEntityIdentifier()
{
    return m_EntityID;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetForceID( ForceID ID )
{
    m_ui8ForceID = ID;
}

//////////////////////////////////////////////////////////////////////////

ForceID Entity_State_PDU::GetForceID() const
{
    return ( ForceID )m_ui8ForceID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Entity_State_PDU::GetNumberOfVariableParams() const
{
    return m_ui8NumOfVariableParams;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetEntityType( const EntityType & Type )
{
    m_EntityType = Type;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & Entity_State_PDU::GetEntityType() const
{
    return m_EntityType;
}

//////////////////////////////////////////////////////////////////////////

EntityType & Entity_State_PDU::GetEntityType()
{
    return m_EntityType;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetAltEntityType( const EntityType & Type )
{
    m_AltEntityType = Type;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & Entity_State_PDU::GetAltEntityType() const
{
    return m_AltEntityType;
}

//////////////////////////////////////////////////////////////////////////

EntityType & Entity_State_PDU::GetAltEntityType()
{
    return m_AltEntityType;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetEntityLinearVelocity( const Vector & ELV )
{
    m_EntityLinearVelocity = ELV;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Entity_State_PDU::GetEntityLinearVelocity() const
{
    return m_EntityLinearVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & Entity_State_PDU::GetEntityLinearVelocity()
{
    return m_EntityLinearVelocity;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetEntityLocation( const WorldCoordinates & EL )
{
    m_EntityLocation = EL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & Entity_State_PDU::GetEntityLocation() const
{
    return m_EntityLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & Entity_State_PDU::GetEntityLocation()
{
    return m_EntityLocation;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetEntityOrientation( const EulerAngles & EO )
{
    m_EntityOrientation = EO;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & Entity_State_PDU::GetEntityOrientation() const
{
    return m_EntityOrientation;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & Entity_State_PDU::GetEntityOrientation()
{
    return m_EntityOrientation;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetEntityAppearance( const EntityAppearance & EA )
{
    m_EntityAppearance = EA;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & Entity_State_PDU::GetEntityAppearance() const
{
    return m_EntityAppearance;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & Entity_State_PDU::GetEntityAppearance()
{
    return m_EntityAppearance;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetDeadReckoningParameter( const DeadReckoningParameter & DRP )
{
    m_DeadReckoningParameter = DRP;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetDeadReckoningCalculator( DeadReckoningCalculator * DR )
{
    m_pDrCalc = DR;
}

//////////////////////////////////////////////////////////////////////////

DeadReckoningCalculator * Entity_State_PDU::GetDeadReckoningCalculator()
{
    return m_pDrCalc;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::InitDeadReckoning()
{
    if( !m_pDrCalc )
    {
        m_pDrCalc = new DeadReckoningCalculator;
    }

    ResetDeadReckoning();
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::ApplyDeadReckoning( KFLOAT64 totalTimeSinceDrReset ) throw( KException )
{
    if( !m_pDrCalc )throw KException( __FUNCTION__, INVALID_OPERATION, "You must call InitDeadReckoning() first." );
    m_pDrCalc->RunAlgorithm( totalTimeSinceDrReset, m_EntityLocation, m_EntityOrientation );
}

//////////////////////////////////////////////////////////////////////////

const DeadReckoningParameter & Entity_State_PDU::GetDeadReckoningParameter() const
{
    return m_DeadReckoningParameter;
}

//////////////////////////////////////////////////////////////////////////

DeadReckoningParameter & Entity_State_PDU::GetDeadReckoningParameter()
{
    return m_DeadReckoningParameter;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::ResetDeadReckoning()
{
    if( m_pDrCalc )
    {
        m_pDrCalc->Reset( m_EntityLinearVelocity, m_DeadReckoningParameter.GetLinearAcceleration(), m_DeadReckoningParameter.GetAngularVelocity(),
                          m_EntityLocation, m_EntityOrientation, m_DeadReckoningParameter.GetQuatAxis(), m_DeadReckoningParameter.GetDeadReckoningAlgorithm() );
    }
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetEntityMarking( const EntityMarking & EM )
{
    m_EntityMarking = EM;
}

//////////////////////////////////////////////////////////////////////////

const EntityMarking & Entity_State_PDU::GetEntityMarking() const
{
    return m_EntityMarking;
}

//////////////////////////////////////////////////////////////////////////

EntityMarking & Entity_State_PDU::GetEntityMarking()
{
    return m_EntityMarking;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetEntityCapabilities( const EntityCapabilities & EC )
{
    m_EntityCapabilities = EC;
}

//////////////////////////////////////////////////////////////////////////

const EntityCapabilities & Entity_State_PDU::GetEntityCapabilities() const
{
    return m_EntityCapabilities;
}

//////////////////////////////////////////////////////////////////////////

EntityCapabilities & Entity_State_PDU::GetEntityCapabilities()
{
    return m_EntityCapabilities;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::AddVariableParameter( VarPrmPtr VP )
{
    m_vVariableParameters.push_back( VP );
    ++m_ui8NumOfVariableParams;
    m_ui16PDULength += VariableParameter::VARIABLE_PARAMETER_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::SetVariableParameters( const vector<VarPrmPtr> & VP )
{
    m_vVariableParameters = VP;
    m_ui8NumOfVariableParams = m_vVariableParameters.size();
    m_ui16PDULength = ENTITY_STATE_PDU_SIZE + ( m_ui8NumOfVariableParams * VariableParameter::VARIABLE_PARAMETER_SIZE );
}

//////////////////////////////////////////////////////////////////////////

const vector<VarPrmPtr> & Entity_State_PDU::GetVariableParameters() const
{
    return m_vVariableParameters;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::ClearVariableParameters()
{
    m_vVariableParameters.clear();
    m_ui8NumOfVariableParams = 0;
    m_ui16PDULength = ENTITY_STATE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString Entity_State_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Entity State PDU-\n"
       << "Entity ID:\n"
       << IndentString( m_EntityID.GetAsString(), 1 )
       << "Force ID:                       " << GetEnumAsStringForceID( m_ui8ForceID )  << "\n"
       << "Number Of Variable Params:  " << ( KUINT16 )m_ui8NumOfVariableParams << "\n"
       << "Entity Type:                    " << m_EntityType.GetAsString()
       << "Alternative Entity Type:        " << m_AltEntityType.GetAsString()
       << "Linear Velocity:                " << m_EntityLinearVelocity.GetAsString()
       << "Entity Location:                " << m_EntityLocation.GetAsString()
       << "Entity Orientation:             " << m_EntityOrientation.GetAsString()
       << m_EntityAppearance.GetAsString( m_EntityType )
       << m_DeadReckoningParameter.GetAsString()
       << m_EntityMarking.GetAsString()
       << m_EntityCapabilities.GetAsString();

    // Add the articulated parts
    vector<VarPrmPtr>::const_iterator citr = m_vVariableParameters.begin();
    vector<VarPrmPtr>::const_iterator citrEnd = m_vVariableParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ss << ( *citr )->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < ENTITY_STATE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vVariableParameters.clear();

    Header::Decode( stream, ignoreHeader );

    stream >> KDIS_STREAM m_EntityID
           >> m_ui8ForceID
           >> m_ui8NumOfVariableParams
           >> KDIS_STREAM m_EntityType
           >> KDIS_STREAM m_AltEntityType
           >> KDIS_STREAM m_EntityLinearVelocity
           >> KDIS_STREAM m_EntityLocation
           >> KDIS_STREAM m_EntityOrientation
           >> KDIS_STREAM m_EntityAppearance
           >> KDIS_STREAM m_DeadReckoningParameter
           >> KDIS_STREAM m_EntityMarking
           >> KDIS_STREAM m_EntityCapabilities;

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

KDataStream Entity_State_PDU::Encode() const
{
    KDataStream stream;

    Entity_State_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Entity_State_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );
    stream << KDIS_STREAM m_EntityID
           << m_ui8ForceID
           << m_ui8NumOfVariableParams
           << KDIS_STREAM m_EntityType
           << KDIS_STREAM m_AltEntityType
           << KDIS_STREAM m_EntityLinearVelocity
           << KDIS_STREAM m_EntityLocation
           << KDIS_STREAM m_EntityOrientation
           << KDIS_STREAM m_EntityAppearance
           << KDIS_STREAM m_DeadReckoningParameter
           << KDIS_STREAM m_EntityMarking
           << KDIS_STREAM m_EntityCapabilities;

    // Add the articulated parts
    vector<VarPrmPtr>::const_iterator citr = m_vVariableParameters.begin();
    vector<VarPrmPtr>::const_iterator citrEnd = m_vVariableParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ( *citr )->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

Entity_State_PDU & Entity_State_PDU::operator=( const Entity_State_PDU & Other )
{
    Header::operator=( Other );
    m_EntityID = Other.m_EntityID;
    m_ui8ForceID = Other.m_ui8ForceID;
    m_ui8NumOfVariableParams = Other.m_ui8NumOfVariableParams;
    m_EntityType = Other.m_EntityType;
    m_AltEntityType = Other.m_AltEntityType;
    m_EntityLinearVelocity = Other.m_EntityLinearVelocity;
    m_EntityLocation = Other.m_EntityLocation;
    m_EntityOrientation = Other.m_EntityOrientation;
    m_EntityAppearance = Other.m_EntityAppearance;
    m_DeadReckoningParameter = Other.m_DeadReckoningParameter;
    m_EntityMarking = Other.m_EntityMarking;
    m_EntityCapabilities = Other.m_EntityCapabilities;
    m_vVariableParameters = Other.m_vVariableParameters;
    m_pDrCalc = ( Other.m_pDrCalc ? new DeadReckoningCalculator( *Other.m_pDrCalc ) : NULL );
    return *this;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Entity_State_PDU::operator == ( const Entity_State_PDU & Value ) const
{
    if( Header::operator              !=( Value ) )                              return false;
    if( m_EntityID                    != Value.m_EntityID )                      return false;
    if( m_ui8ForceID                  != Value.m_ui8ForceID )                    return false;
    if( m_ui8NumOfVariableParams  != Value.m_ui8NumOfVariableParams )            return false;
    if( m_EntityType                  != Value.m_EntityType )                    return false;
    if( m_AltEntityType               != Value.m_AltEntityType )                 return false;
    if( m_EntityLinearVelocity        != Value.m_EntityLinearVelocity )          return false;
    if( m_EntityLocation              != Value.m_EntityLocation )                return false;
    if( m_EntityOrientation           != Value.m_EntityOrientation )             return false;
    if( m_EntityAppearance            != Value.m_EntityAppearance )              return false;
    if( m_DeadReckoningParameter      != Value.m_DeadReckoningParameter )        return false;
    if( m_EntityMarking               != Value.m_EntityMarking )                 return false;
    if( m_EntityCapabilities          != Value.m_EntityCapabilities )            return false;
    if( m_vVariableParameters         != Value.m_vVariableParameters )           return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Entity_State_PDU::operator != ( const Entity_State_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
