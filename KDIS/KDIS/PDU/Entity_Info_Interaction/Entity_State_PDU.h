/*********************************************************************
Copyright 2013 KDIS
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
    DIS:        (5) 1278.1 - 1995 & (7) 1278.1 - 200x draft 14
    created:    22/09/2008
    author:     Karl Jones

    purpose:    Contains information about a particular entity.
    size:       1152 bits / 144 octets + 128/16 * Num Art Params
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
#include "./../../DataTypes/ArticulationParameters.h"
#include "./../../Extras/DeadReckoningCalculator.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::EntityType;
using KDIS::DATA_TYPE::Vector;
using KDIS::DATA_TYPE::WorldCoordinates;
using KDIS::DATA_TYPE::EulerAngles;
using KDIS::DATA_TYPE::EntityAppearance;
using KDIS::DATA_TYPE::DeadReckoningParameter;
using KDIS::DATA_TYPE::EntityMarking;
using KDIS::DATA_TYPE::EntityCapabilities;
using KDIS::DATA_TYPE::ArticulationParameters;
using KDIS::DATA_TYPE::ENUMS::ForceID;
using KDIS::UTILS::DeadReckoningCalculator;
using std::vector;

class KDIS_EXPORT Entity_State_PDU : public Header
{
protected:

    EntityIdentifier m_EntityID;

    KUINT8 m_ui8ForceID;

    KUINT8 m_ui8NumOfArticulationParams;

    EntityType m_EntityType;

    EntityType m_AltEntityType;

    Vector m_EntityLinearVelocity;

    WorldCoordinates m_EntityLocation;

    EulerAngles m_EntityOrientation;

    EntityAppearance m_EntityAppearance;

    DeadReckoningParameter m_DeadReckoningParameter;

    EntityMarking m_EntityMarking;

    EntityCapabilities m_EntityCapabilities;

    vector<ArticulationParameters> m_vArticulationParameters;

    DeadReckoningCalculator * m_pDrCalc;

public:

    // Min Size not including variable articulation parameters field
    static const KUINT16 ENTITY_STATE_PDU_SIZE = 144;

    Entity_State_PDU();

    Entity_State_PDU( KDataStream & stream ) throw( KException );

    Entity_State_PDU( const EntityIdentifier & EI, ForceID ID, const EntityType & Type, const EntityType & AltType,
                      const Vector & EntityLinearVelocity, const WorldCoordinates & EntityLocation,
                      const EulerAngles & EntityOrientation, const EntityAppearance & EA,
                      const DeadReckoningParameter & DRP, const EntityMarking & EM,
                      const EntityCapabilities & EC );

    virtual ~Entity_State_PDU();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityIdentifier
    //              KDIS::PDU::Entity_State_PDU::GetEntityIdentifier
    // Description: ID of entity issuing the PDU. This is a unique identifier made up of 3 values. The first 2 represent
    //              the simulation address.(site, application) and the final is the entity. This ID should be unqiue to the simulation.
    // Parameter:   const EntityIdentifier & EI
    //************************************
    void SetEntityIdentifier( const EntityIdentifier & EI );
    const EntityIdentifier & GetEntityIdentifier() const;
    EntityIdentifier & GetEntityIdentifier();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetForceID
    //              KDIS::PDU::Entity_State_PDU::GetForceID
    // Description: Force ID. Enumerated value representing the force the entity belongs to,
    //              such as friendly, opposing or neutral.
    // Parameter:   ForceID ID
    //************************************
    void SetForceID( ForceID ID );
    ForceID GetForceID() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::GetNumberOfArticulationParams
    // Description: Number of articulation parameters.
    //************************************
    KUINT8 GetNumberOfArticulationParams() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityType
    //              KDIS::PDU::Entity_State_PDU::GetEntityType
    // Description: Entity Type. Consists of 7 values used to represent
    //              the type of entity. Please see DIS Enums document found on
    //              the SISO website for a full list of enumerations available.
    // Parameter:   const EntityType & Type
    //************************************
    void SetEntityType( const EntityType & Type );
    const EntityType & GetEntityType() const;
    EntityType & GetEntityType();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetAltEntityType
    //              KDIS::PDU::Entity_State_PDU::GetAltEntityType
    // Description: This identifies the entity type to be displayed by members of forces
    //              other than that of the issuing entity.
    //              I.E This could be used to represent an entity in disguise.
    // Parameter:   const EntityType & Type
    //************************************
    void SetAltEntityType( const EntityType & Type );
    const EntityType & GetAltEntityType() const;
    EntityType & GetAltEntityType();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityLinearVelocity
    //              KDIS::PDU::Entity_State_PDU::GetEntityLinearVelocity
    // Description: Represented as Linear Velocity Vector. m/s.
    // Parameter:   const Vector & ELV
    //************************************
    void SetEntityLinearVelocity( const Vector & ELV );
    const Vector & GetEntityLinearVelocity() const;
    Vector & GetEntityLinearVelocity();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityLocation
    //              KDIS::PDU::Entity_State_PDU::GetEntityLocation
    // Description: Entity Location in Geocentric world coordinates.
    //              Note: See KConversions.h for some useful coordinate conversions.
    // Parameter:   const WorldCoordinates & EL
    //************************************
    void SetEntityLocation( const WorldCoordinates & EL );
    const WorldCoordinates & GetEntityLocation() const;
    WorldCoordinates & GetEntityLocation();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityOrientation
    //              KDIS::PDU::Entity_State_PDU::GetEntityOrientation
    // Description: Orientation of entity. Geocentric Euler Angles.
    //              Note: See KConversions.h for some useful orientation conversions.
    // Parameter:   const EulerAngles & EO
    //************************************
    void SetEntityOrientation( const EulerAngles & EO );
    const EulerAngles & GetEntityOrientation() const;
    EulerAngles & GetEntityOrientation();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityAppearance
    //              KDIS::PDU::Entity_State_PDU::GetEntityAppearance
    // Description: Entity Appearance.
    //              Appearance is communicated via a series of bit flags/values. Such as damage states, smoking, on fire etc.
    //              Note The "Specific Entity Appearance" varies depending on entity type, E.G Air, Ground, Lifeform etc.
    // Parameter:   const EntityAppearance & EA
    //************************************
    void SetEntityAppearance( const EntityAppearance & EA );
    const EntityAppearance & GetEntityAppearance() const;
    EntityAppearance & GetEntityAppearance();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetDeadReckoningParameter
    //              KDIS::PDU::Entity_State_PDU::GetDeadReckoningParameter
    // Description: Dead Reckoning Parameter. Dead Reckoning is used to provide an estimate of an entities position between PDUs.
    //              Using dead reckoning an entity can be given the appearance that it is moving smoothly in an environment.
    //              The dead reckoning values are used to predict where the entity will be within the foreseeable future.
    //              When a new entity update is received the entities position is corrected via a process called "smoothing".
    // Parameter:   const DeadReckoningParameter & DRP
    //************************************
    void SetDeadReckoningParameter( const DeadReckoningParameter & DRP );
    const DeadReckoningParameter & GetDeadReckoningParameter() const;
    DeadReckoningParameter & GetDeadReckoningParameter();

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
    void SetDeadReckoningCalculator( DeadReckoningCalculator * DR );
    DeadReckoningCalculator * GetDeadReckoningCalculator();

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
    // Parameter:   KFLOAT64 DeltaTime the time since the DR has been reset. Not the simulation time step.
    //************************************
    void ApplyDeadReckoning( KFLOAT64 totalTimeSinceDrReset ) throw( KException );

    /************************************************************************/

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityMarking
    //              KDIS::PDU::Entity_State_PDU::GetEntityMarking
    // Description: Entity Marking. This can be the entities name,Army Markings or Chevrons.
    // Parameter:   const EntityMarking & EM, void
    //************************************
    void SetEntityMarking( const EntityMarking & EM );
    const EntityMarking & GetEntityMarking() const;
    EntityMarking & GetEntityMarking();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::SetEntityCapabilities
    //              KDIS::PDU::Entity_State_PDU::GetEntityCapabilities
    // Description: Entity Capabilities. Such as has fuel/ammo supply etc.
    // Parameter:   const EntityCapabilities & EC, void
    //************************************
    void SetEntityCapabilities( const EntityCapabilities & EC );
    const EntityCapabilities & GetEntityCapabilities() const;
    EntityCapabilities & GetEntityCapabilities();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::AddArticulationParameter
    //              KDIS::PDU::Entity_State_PDU::SetArticulationParameter
    //              KDIS::PDU::Entity_State_PDU::GetArticulationParameters
    //              KDIS::PDU::Entity_State_PDU::ClearArticulationParameters
    // Description: Add a articulation parameter / Get vector or params
    //              Adding will update the Number Of Articulation Params and the PDU length field.
    // Parameter:   const ArticulationParameters & AP, vector<ArticulationParameters> & AP, void
    //************************************
    void AddArticulationParameter( const ArticulationParameters & AP );
    void SetArticulationParameter( const vector<ArticulationParameters> & AP );
    const vector<ArticulationParameters> & GetArticulationParameters() const;
    void ClearArticulationParameters();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::GetAsString
    // Description: Returns a string representation of the PDU. Great for debugging!
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Entity_State_PDU & Value ) const;
    KBOOL operator != ( const Entity_State_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
