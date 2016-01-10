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

/********************************************************************
    class:      Entity_State_PDU
    DIS:        (5) 1278.1 - 1995 & (7) 1278.1-2012
    updated:    08/03/2013
    author:     Karl Jones

    purpose:    Contains information about a particular entity.
    size:       1152 bits / 144 octets + 128/16 * Num var Params
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/EntityType.h"
#include "./../../DataTypes/EulerAngles.h"
#include "./../../DataTypes/EntityAppearance.h"
#include "./../../DataTypes/DeadReckoningParameter.h"
#include "./../../DataTypes/EntityMarking.h"
#include "./../../DataTypes/EntityCapabilities.h"
#include "./../../DataTypes/VariableParameter.h"
#include "./../../Extras/DeadReckoningCalculator.h"
#include <vector>

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Entity_State_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_EntityID;

    KUINT8 m_ui8ForceID;

    KUINT8 m_ui8NumOfVariableParams;

    KDIS::DATA_TYPE::EntityType m_EntityType;

    KDIS::DATA_TYPE::EntityType m_AltEntityType;

    KDIS::DATA_TYPE::Vector m_EntityLinearVelocity;

    KDIS::DATA_TYPE::WorldCoordinates m_EntityLocation;

    KDIS::DATA_TYPE::EulerAngles m_EntityOrientation;

    KDIS::DATA_TYPE::EntityAppearance m_EntityAppearance;

    KDIS::DATA_TYPE::DeadReckoningParameter m_DeadReckoningParameter;

    KDIS::DATA_TYPE::EntityMarking m_EntityMarking;

    KDIS::DATA_TYPE::EntityCapabilities m_EntityCapabilities;

    std::vector<KDIS::DATA_TYPE::VarPrmPtr> m_vVariableParameters;

    KDIS::UTILS::DeadReckoningCalculator * m_pDrCalc;

public:

    // Min Size not including variable parameters field
    static const KUINT16 ENTITY_STATE_PDU_SIZE = 144;

    Entity_State_PDU();

    Entity_State_PDU( KDataStream & stream ) throw( KException );

    Entity_State_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Entity_State_PDU( const Entity_State_PDU & ESPDU );

    Entity_State_PDU( const KDIS::DATA_TYPE::EntityIdentifier & EI, KDIS::DATA_TYPE::ENUMS::ForceID ID, const KDIS::DATA_TYPE::EntityType & Type,
                      const KDIS::DATA_TYPE::EntityType & AltType, const KDIS::DATA_TYPE::Vector & EntityLinearVelocity,
                      const KDIS::DATA_TYPE::WorldCoordinates & EntityLocation, const KDIS::DATA_TYPE::EulerAngles & EntityOrientation,
                      const KDIS::DATA_TYPE::EntityAppearance & EA, const KDIS::DATA_TYPE::DeadReckoningParameter & DRP,
                      const KDIS::DATA_TYPE::EntityMarking & EM, const KDIS::DATA_TYPE::EntityCapabilities & EC );

    virtual ~Entity_State_PDU();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityIdentifier
    //              KDIS::PDU::Entity_State_PDU::GetEntityIdentifier
    // Description: ID of entity issuing the PDU. This is a unique identifier made up of 3 values. The first 2 represent
    //              the simulation address.(site, application) and the final is the entity. This ID should be unqiue to the simulation.
    // Parameter:   const EntityIdentifier & EI
    //************************************
    void SetEntityIdentifier( const KDIS::DATA_TYPE::EntityIdentifier & EI );
    const KDIS::DATA_TYPE::EntityIdentifier & GetEntityIdentifier() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetEntityIdentifier();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetForceID
    //              KDIS::PDU::Entity_State_PDU::GetForceID
    // Description: Force ID. Enumerated value representing the force the entity belongs to,
    //              such as friendly, opposing or neutral.
    // Parameter:   ForceID ID
    //************************************
    void SetForceID( KDIS::DATA_TYPE::ENUMS::ForceID ID );
    KDIS::DATA_TYPE::ENUMS::ForceID GetForceID() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::GetNumberOfVariableParams
    // Description: Number of variable parameters.
    //************************************
    KUINT8 GetNumberOfVariableParams() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityType
    //              KDIS::PDU::Entity_State_PDU::GetEntityType
    // Description: Entity Type. Consists of 7 values used to represent
    //              the type of entity. Please see DIS Enums document found on
    //              the SISO website for a full list of enumerations available.
    // Parameter:   const EntityType & Type
    //************************************
    void SetEntityType( const KDIS::DATA_TYPE::EntityType & Type );
    const KDIS::DATA_TYPE::EntityType & GetEntityType() const;
    KDIS::DATA_TYPE::EntityType & GetEntityType();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetAltEntityType
    //              KDIS::PDU::Entity_State_PDU::GetAltEntityType
    // Description: This identifies the entity type to be displayed by members of forces
    //              other than that of the issuing entity.
    //              I.E This could be used to represent an entity in disguise.
    // Parameter:   const EntityType & Type
    //************************************
    void SetAltEntityType( const KDIS::DATA_TYPE::EntityType & Type );
    const KDIS::DATA_TYPE::EntityType & GetAltEntityType() const;
    KDIS::DATA_TYPE::EntityType & GetAltEntityType();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityLinearVelocity
    //              KDIS::PDU::Entity_State_PDU::GetEntityLinearVelocity
    // Description: Represented as Linear Velocity Vector. m/s.
    // Parameter:   const Vector & ELV
    //************************************
    void SetEntityLinearVelocity( const KDIS::DATA_TYPE::Vector & ELV );
    const KDIS::DATA_TYPE::Vector & GetEntityLinearVelocity() const;
    KDIS::DATA_TYPE::Vector & GetEntityLinearVelocity();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityLocation
    //              KDIS::PDU::Entity_State_PDU::GetEntityLocation
    // Description: Entity Location in Geocentric world coordinates.
    //              Note: See KConversions.h for some useful coordinate conversions.
    // Parameter:   const WorldCoordinates & EL
    //************************************
    void SetEntityLocation( const KDIS::DATA_TYPE::WorldCoordinates & EL );
    const KDIS::DATA_TYPE::WorldCoordinates & GetEntityLocation() const;
    KDIS::DATA_TYPE::WorldCoordinates & GetEntityLocation();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityOrientation
    //              KDIS::PDU::Entity_State_PDU::GetEntityOrientation
    // Description: Orientation of entity. Geocentric Euler Angles.
    //              Note: See KConversions.h for some useful orientation conversions.
    // Parameter:   const EulerAngles & EO
    //************************************
    void SetEntityOrientation( const KDIS::DATA_TYPE::EulerAngles & EO );
    const KDIS::DATA_TYPE::EulerAngles & GetEntityOrientation() const;
    KDIS::DATA_TYPE::EulerAngles & GetEntityOrientation();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityAppearance
    //              KDIS::PDU::Entity_State_PDU::GetEntityAppearance
    // Description: Entity Appearance.
    //              Appearance is communicated via a series of bit flags/values. Such as damage states, smoking, on fire etc.
    //              Note The "Specific Entity Appearance" varies depending on entity type, E.G Air, Ground, Lifeform etc.
    // Parameter:   const EntityAppearance & EA
    //************************************
    void SetEntityAppearance( const KDIS::DATA_TYPE::EntityAppearance & EA );
    const KDIS::DATA_TYPE::EntityAppearance & GetEntityAppearance() const;
    KDIS::DATA_TYPE::EntityAppearance & GetEntityAppearance();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetDeadReckoningParameter
    //              KDIS::PDU::Entity_State_PDU::GetDeadReckoningParameter
    // Description: Dead Reckoning Parameter. Dead Reckoning is used to provide an estimate of an entities position between PDUs.
    //              Using dead reckoning an entity can be given the appearance that it is moving smoothly in an environment.
    //              The dead reckoning values are used to predict where the entity will be within the foreseeable future.
    //              When a new entity update is received the entities position is corrected via a process called "smoothing".
    // Parameter:   const DeadReckoningParameter & DRP
    //************************************
    void SetDeadReckoningParameter( const KDIS::DATA_TYPE::DeadReckoningParameter & DRP );
    const KDIS::DATA_TYPE::DeadReckoningParameter & GetDeadReckoningParameter() const;
    KDIS::DATA_TYPE::DeadReckoningParameter & GetDeadReckoningParameter();

    /************************************************************************/
    /* Dead reckoning calculator                                            */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetDeadReckoningCalculator
    //              KDIS::PDU::Entity_State_PDU::GetDeadReckoningCalculator
    // Description: Set or return the DeadReckoningCalculator object.
    //              Returns null pointer if InitDeadReckoning has not been called first.
    // Parameter:   const DeadReckoningParameter & DRP
    //************************************
    void SetDeadReckoningCalculator( KDIS::UTILS::DeadReckoningCalculator * DR );
    KDIS::UTILS::DeadReckoningCalculator * GetDeadReckoningCalculator();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::InitDeadReckoning
    // Description: Initialise the dead reckoning object. Call this first.
    //************************************
    void InitDeadReckoning();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::ResetDeadReckoning
    // Description: Resets the dead reckoning object. For a local entity should be called before sending out
    //              an entity state PDU so the local entity can dead-reckon itself.
    //              For a remote entity should be called when an ES PDU is received.
    //              Note: Nothing will happen if you have not initialised the dead reckoning calculator first.
    //************************************
    void ResetDeadReckoning();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::ApplyDeadReckoning
    // Description: Applies a dead reckoning transformation to the entity for a time step.
    //              Throws INVALID_OPERATION exception if InitDeadReckoning has not been called first.
    // Parameter:   KFLOAT64 totalTimeSinceDrReset the time since the DR has been reset. Not the simulation time step.
    //************************************
    void ApplyDeadReckoning( KFLOAT64 totalTimeSinceDrReset ) throw( KException );

    /************************************************************************/

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityMarking
    //              KDIS::PDU::Entity_State_PDU::GetEntityMarking
    // Description: Entity Marking. This can be the entities name,Army Markings or Chevrons.
    // Parameter:   const EntityMarking & EM
    //************************************
    void SetEntityMarking( const KDIS::DATA_TYPE::EntityMarking & EM );
    const KDIS::DATA_TYPE::EntityMarking & GetEntityMarking() const;
    KDIS::DATA_TYPE::EntityMarking & GetEntityMarking();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityCapabilities
    //              KDIS::PDU::Entity_State_PDU::GetEntityCapabilities
    // Description: Entity Capabilities. Such as has fuel/ammo supply etc.
    // Parameter:   const EntityCapabilities & EC
    //************************************
    void SetEntityCapabilities( const KDIS::DATA_TYPE::EntityCapabilities & EC );
    const KDIS::DATA_TYPE::EntityCapabilities & GetEntityCapabilities() const;
    KDIS::DATA_TYPE::EntityCapabilities & GetEntityCapabilities();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::AddVariableParameter
    //              KDIS::PDU::Entity_State_PDU::SetVariableParameter
    //              KDIS::PDU::Entity_State_PDU::GetVariableParameters
    //              KDIS::PDU::Entity_State_PDU::ClearVariableParameters
    // Description: Information associated with an entity or detonation, not otherwise accounted
    //	            for in a PDU such as Articulated and Attached Parts.
    //              See VariableParameter for supported/implemented types.
    // Parameter:   VarPrmPtr VP, vector<VarPrmPtr> & VP
    //************************************
    void AddVariableParameter( KDIS::DATA_TYPE::VarPrmPtr VP );
    void SetVariableParameters( const std::vector<KDIS::DATA_TYPE::VarPrmPtr> & VP );
    const std::vector<KDIS::DATA_TYPE::VarPrmPtr> & GetVariableParameters() const;
    void ClearVariableParameters();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::GetAsString
    // Description: Returns a string representation of the PDU. Great for debugging!
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream?
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    Entity_State_PDU & operator=( const Entity_State_PDU & Other );

    KBOOL operator == ( const Entity_State_PDU & Value ) const;
    KBOOL operator != ( const Entity_State_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
