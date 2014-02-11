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
    class:      Entity_State_Update_PDU
    DIS:        (6) 1278.1a - 1998 & (7) 1278.1-2012
    created:    09/11/2008
    author:     Karl Jones

    purpose:    Communicates nonstatic infomation about a particular
                entity. Only used when a simulation application is using
                first order dead reckoning.
    size:       576 bits / 72 octets + ( 128/16 * Num var Params )
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/EntityType.h"
#include "./../../DataTypes/EulerAngles.h"
#include "./../../DataTypes/EntityAppearance.h"
#include "./../../DataTypes/VariableParameter.h"
#include <vector>

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Entity_State_Update_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_EntityID;

    KUINT8 m_ui8Padding1;

    KUINT8 m_ui8NumOfVariableParams;

    KDIS::DATA_TYPE::Vector m_EntityLinearVelocity;

    KDIS::DATA_TYPE::WorldCoordinates m_EntityLocation;

    KDIS::DATA_TYPE::EulerAngles m_EntityOrientation;

    KDIS::DATA_TYPE::EntityAppearance m_EntityAppearance;
				      
	std::vector<KDIS::DATA_TYPE::VarPrmPtr> m_vVariableParameters;

public:

    // Min Size not including variable variable parameters field
    static const KUINT16 ENTITY_STATE_UPDATE_PDU_SIZE = 72;

    Entity_State_Update_PDU();

    Entity_State_Update_PDU( KDataStream & stream ) throw( KException );

	Entity_State_Update_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Entity_State_Update_PDU( const KDIS::DATA_TYPE::EntityIdentifier & EI, const KDIS::DATA_TYPE::Vector & EntityLinearVelocity,
                             const KDIS::DATA_TYPE::WorldCoordinates & EntityLocation, const KDIS::DATA_TYPE::EulerAngles & EntityOrientation,
                             const KDIS::DATA_TYPE::EntityAppearance & EA );

    virtual ~Entity_State_Update_PDU();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityIdentifier
    //              KDIS::PDU::Entity_State_Update_PDU::GetEntityIdentifier
    // Description: Entity ID
    // Parameter:   const EntityIdentifier & EI
    //************************************
    void SetEntityIdentifier( const KDIS::DATA_TYPE::EntityIdentifier & EI );
    const KDIS::DATA_TYPE::EntityIdentifier & GetEntityIdentifier() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetEntityIdentifier();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::GetNumberOfVariableParams
    // Description: Number of variable parameters.
    //************************************
    KUINT8 GetNumberOfVariableParams() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityLinearVelocity
    //              KDIS::PDU::Entity_State_Update_PDU::GetEntityLinearVelocity
    // Description: Linear Velocity
    // Parameter:   const Vector & ELV
    //************************************
    void SetEntityLinearVelocity( const KDIS::DATA_TYPE::Vector & ELV );
    const KDIS::DATA_TYPE::Vector & GetEntityLinearVelocity() const;
    KDIS::DATA_TYPE::Vector & GetEntityLinearVelocity();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityLocation
    // Description: Entity Location
    // Parameter:   const WorldCoordinates & EL
    //************************************
    void SetEntityLocation( const KDIS::DATA_TYPE::WorldCoordinates & EL );
    const KDIS::DATA_TYPE::WorldCoordinates & GetEntityLocation() const;
    KDIS::DATA_TYPE::WorldCoordinates & GetEntityLocation();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityOrientation
    //              KDIS::PDU::Entity_State_Update_PDU::GetEntityOrientation
    // Description: Orientation of entity. Euler Angles
    // Parameter:   const EulerAngles & EO
    //************************************
    void SetEntityOrientation( const KDIS::DATA_TYPE::EulerAngles & EO );
    const KDIS::DATA_TYPE::EulerAngles & GetEntityOrientation() const;
    KDIS::DATA_TYPE::EulerAngles & GetEntityOrientation();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityAppearance
    //              KDIS::PDU::Entity_State_Update_PDU::GetEntityAppearance
    // Description: Entity Appearance bit field accessors/mutator
    // Parameter:   const EntityAppearance & EA
    //************************************
    void SetEntityAppearance( const KDIS::DATA_TYPE::EntityAppearance & EA );
    const KDIS::DATA_TYPE::EntityAppearance & GetEntityAppearance() const;
    KDIS::DATA_TYPE::EntityAppearance & GetEntityAppearance();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::AddVariableParameter
    //              KDIS::PDU::Entity_State_Update_PDU::SetVariableParameter
    //              KDIS::PDU::Entity_State_Update_PDU::GetVariableParameters
    //              KDIS::PDU::Entity_State_Update_PDU::ClearVariableParameters
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
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Entity_State_Update_PDU & Value ) const;
    KBOOL operator != ( const Entity_State_Update_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
