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

using std::vector;

class KDIS_EXPORT SilentEntitySystem : public DataTypeBase
{
protected:

    KUINT16 m_ui16NumEnts;

    KUINT16 m_ui16NumOfAppearanceRecords;

    EntityType m_EntTyp;

    vector<EntityAppearance> m_vEA;

public:

    static const KUINT16 SILENT_ENTITY_SYSTEM_SIZE = 12; // Min Size

    SilentEntitySystem( void );

    SilentEntitySystem( KDataStream & stream ) throw( KException );

    virtual ~SilentEntitySystem( void );

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
    void SetEntityAppearanceList( const vector<EntityAppearance> & EA ) throw( KException );
    const vector<EntityAppearance> & GetEntityAppearanceList() const;
    void ClearEntityAppearanceList();

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentEntitySystem::SetEntityType
    //              KDIS::DATA_TYPE::SilentEntitySystem::GetEntityType
    // Description: Aggregate type for this record.
    // Parameter:   const EntityType & E, void
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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

