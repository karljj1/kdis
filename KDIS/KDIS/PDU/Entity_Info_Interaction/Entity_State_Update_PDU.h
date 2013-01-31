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
    class:      Entity_State_Update_PDU
    DIS:        (6) 1278.1a - 1998 & (7) 1278.1 - 200x draft 14
    created:    09/11/2008
    author:     Karl Jones

    purpose:    Communicates nonstatic infomation about a particular
                entity. Only used when a simulation application is using
                first order dead reckoning.
    size:       576 bits / 72 octets + ( 128/16 * Num Art Params )
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/EntityType.h"
#include "./../../DataTypes/EulerAngles.h"
#include "./../../DataTypes/EntityAppearance.h"
#include "./../../DataTypes/ArticulationParameters.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::Vector;
using KDIS::DATA_TYPE::WorldCoordinates;
using KDIS::DATA_TYPE::EulerAngles;
using KDIS::DATA_TYPE::EntityAppearance;
using KDIS::DATA_TYPE::ArticulationParameters;
using std::vector;

class KDIS_EXPORT Entity_State_Update_PDU : public Header
{
protected:

    EntityIdentifier m_EntityID;

    KUINT8 m_ui8Padding1;

    KUINT8 m_ui8NumOfArticulationParams;

    Vector m_EntityLinearVelocity;

    WorldCoordinates m_EntityLocation;

    EulerAngles m_EntityOrientation;

    EntityAppearance m_EntityAppearance;

    vector<ArticulationParameters> m_vArticulationParameters;

public:

    // Min Size not including variable articulation parameters field
    static const KUINT16 ENTITY_STATE_UPDATE_PDU_SIZE = 72;

    Entity_State_Update_PDU( void );

    Entity_State_Update_PDU( KDataStream & stream ) throw( KException );

    Entity_State_Update_PDU( const EntityIdentifier & EI, const Vector & EntityLinearVelocity,
                             const WorldCoordinates & EntityLocation, const EulerAngles & EntityOrientation,
                             const EntityAppearance & EA );

    virtual ~Entity_State_Update_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityIdentifier
    //              KDIS::PDU::Entity_State_Update_PDU::GetEntityIdentifier
    // Description: Entity ID
    // Parameter:   const EntityIdentifier & EI, void
    //************************************
    void SetEntityIdentifier( const EntityIdentifier & EI );
    const EntityIdentifier & GetEntityIdentifier() const;
    EntityIdentifier & GetEntityIdentifier();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::GetNumberOfArticulationParams
    // Description: Number of articulation parameters
    //************************************
    KUINT8 GetNumberOfArticulationParams() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityLinearVelocity
    //              KDIS::PDU::Entity_State_Update_PDU::GetEntityLinearVelocity
    // Description: Linear Velocity
    // Parameter:   const Vector & ELV, void
    //************************************
    void SetEntityLinearVelocity( const Vector & ELV );
    const Vector & GetEntityLinearVelocity() const;
    Vector & GetEntityLinearVelocity();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityLocation
    // Description: Entity Location
    // Parameter:   const WorldCoordinates & EL, void
    //************************************
    void SetEntityLocation( const WorldCoordinates & EL );
    const WorldCoordinates & GetEntityLocation() const;
    WorldCoordinates & GetEntityLocation();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityOrientation
    //              KDIS::PDU::Entity_State_Update_PDU::GetEntityOrientation
    // Description: Orientation of entity. Euler Angles
    // Parameter:   const EulerAngles & EO, void
    //************************************
    void SetEntityOrientation( const EulerAngles & EO );
    const EulerAngles & GetEntityOrientation() const;
    EulerAngles & GetEntityOrientation();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::SetEntityAppearance
    //              KDIS::PDU::Entity_State_Update_PDU::GetEntityAppearance
    // Description: Entity Appearance bit field accessors/mutator
    // Parameter:   const EntityAppearance & EA, void
    //************************************
    void SetEntityAppearance( const EntityAppearance & EA );
    const EntityAppearance & GetEntityAppearance() const;
    EntityAppearance & GetEntityAppearance();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::AddArticulationParameter
    //              KDIS::PDU::Entity_State_Update_PDU::SetArticulationParameter
    //              KDIS::PDU::Entity_State_Update_PDU::GetArticulationParameters
    //              KDIS::PDU::Entity_State_Update_PDU::ClearArticulationParameters
    // Description: Add a articulation parameter / Get vector or params
    //              Adding will update the Number Of Articulation Params
    //              field.
    // Parameter:   const ArticulationParameters & AP, const vector<ArticulationParameters> & AP
    //************************************
    void AddArticulationParameter( const ArticulationParameters & AP );
    void SetArticulationParameters( const vector<ArticulationParameters> & AP );
    const vector<ArticulationParameters> & GetArticulationParameters() const;
    void ClearArticulationParameters();

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_Update_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
