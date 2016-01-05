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
    class:      SilentEntitySystem
    created:    2009/02/08
    author:     Karl Jones

    purpose:    Contains information about entities not producing
                Entity State PDUs.
    size:       96 bits / 12 octets - Min size
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EntityType.h"
#include "./EntityAppearance.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT SilentEntitySystem : public DataTypeBase
{
protected:

    KUINT16 m_ui16NumEnts;

    KUINT16 m_ui16NumOfAppearanceRecords;

    EntityType m_EntTyp;

    std::vector<EntityAppearance> m_vEA;

public:

    static const KUINT16 SILENT_ENTITY_SYSTEM_SIZE = 12; // Min Size

    SilentEntitySystem();

    SilentEntitySystem( KDataStream & stream ) throw( KException );

    virtual ~SilentEntitySystem();

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentEntitySystem::SetNumberOfEntities
    //              KDIS::DATA_TYPE::SilentEntitySystem::GetNumberOfEntities
    // Description: Number of entities of this type.
    // Parameter:   KUINT16 NOE
    //************************************
    void SetNumberOfEntities( KUINT16 NOE );
    KUINT16 GetNumberOfEntities() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentEntitySystem::GetNumberOfAppearanceRecords
    // Description: Number of appearance records.
    //************************************
    KUINT16 GetNumberOfAppearanceRecords() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentEntitySystem::AddEntityAppearance
    //              KDIS::DATA_TYPE::SilentEntitySystem::SetEntityAppearanceList
    //              KDIS::DATA_TYPE::SilentEntitySystem::GetEntityAppearanceList
    //              KDIS::DATA_TYPE::SilentEntitySystem::ClearEntityAppearanceList
    // Description: The number of Entity Appearance records should be between zero and the number of
    //              entities of this type.
    //              Simulation applications representing the aggregate that do not model
    //              entity appearances shall set this field to zero.
    //              Simulation applications representing the aggregate that model entity
    //              appearances shall set this field to the number of entity appearances
    //              that deviate from the default appearance.
    //              Other simulations can safely assume that any entity appearances not specified are
    //              default appearances.
    //              Exception thrown if the size of the list is greater than the number of entities.
    // Parameter:   const EntityAppearance & EA, const vector<EntityAppearance> & EA
    //************************************
    void AddEntityAppearance( const EntityAppearance & EA ) throw( KException );
    void SetEntityAppearanceList( const std::vector<EntityAppearance> & EA ) throw( KException );
    const std::vector<EntityAppearance> & GetEntityAppearanceList() const;
    void ClearEntityAppearanceList();

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentEntitySystem::SetEntityType
    //              KDIS::DATA_TYPE::SilentEntitySystem::GetEntityType
    // Description: Aggregate type for this record.
    // Parameter:   const EntityType & E
    //************************************
    void SetEntityType( const EntityType & A );
    const EntityType & GetEntityType() const;
    EntityType & GetEntityType();

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentEntitySystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentEntitySystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentEntitySystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const SilentEntitySystem & Value ) const;
    KBOOL operator != ( const SilentEntitySystem & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

