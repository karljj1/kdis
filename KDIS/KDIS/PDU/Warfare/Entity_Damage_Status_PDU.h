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
    class:      Entity_Damage_Status_PDU
    DIS:        (7) 1278.1-200x
    created:    27/07/2011
    author:     Karl Jones

    purpose:    Used to communicate detailed damage information sustained by an entity regardless
	            of the source of the damage.
                The cause of the damage may be a weapon fired at the entity, a collision with 
				another object, or some other reason. The Entity Damage Status PDU enables damage 
				to a specific location on an entity to be conveyed whether or not that location 
				is associated with an articulated or attached part.
				The information conveyed in this PDU augments damage information communicated in 
				the Entity State and other PDUs.

    Size:       192 bits / 24 octets - Min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/StandardVariable.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::StandardVariable;
using KDIS::DATA_TYPE::StdVarPtr;

class KDIS_EXPORT Entity_Damage_Status_PDU : public Header
{
protected:

	EntityIdentifier m_DmgEnt;

	KUINT32 m_ui32Padding;

	KUINT16 m_ui16NumDmgDescRecs;

	vector<StdVarPtr> m_vDdRec;

public:

    static const KUINT16 ENTITY_DAMAGE_STATE_PDU = 24; // Min size

    Entity_Damage_Status_PDU( void );

	Entity_Damage_Status_PDU( const EntityIdentifier & DamagedEntityID );

    Entity_Damage_Status_PDU( KDataStream & stream ) throw( KException );

    virtual ~Entity_Damage_Status_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Entity_Damage_Status_PDU::SetDamagedEntityID
    //              KDIS::PDU::Entity_Damage_Status_PDU::GetDamagedEntityID
    // Description: The damaged entity.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetDamagedEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetDamagedEntityID() const;
    EntityIdentifier & GetDamagedEntityID();

    //************************************
    // FullName:    KDIS::PDU::Entity_Damage_Status_PDU::GetNumberOfDamageDescriptionRecords    
    // Description: The Number of Damage Description records stored in this PDU.
    //************************************
	KUINT16 GetNumberOfDamageDescriptionRecords() const;

	//************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::AddDamageDescriptionRecord
    //              KDIS::PDU::Directed_Energy_Fire_PDU::SetDamageDescriptionRecords
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetDamageDescriptionRecords
    //              KDIS::PDU::Directed_Energy_Fire_PDU::ClearDamageDescriptionRecords
    // Description: This field can contain one or more DD records and may also contain 
	//				other Standard Variable records.
    // Parameter:   StdVarPtr DD, const vector<StdVarPtr> & DD
	//************************************    
    void AddDamageDescriptionRecord( StdVarPtr DD );
    void SetDamageDescriptionRecords( const vector<StdVarPtr> & DD );
    const vector<StdVarPtr> & GetDamageDescriptionRecords() const;
	void ClearDamageDescriptionRecords();
  
    //************************************
    // FullName:    KDIS::PDU::Entity_Damage_Status_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_Damage_Status_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Entity_Damage_Status_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Entity_Damage_Status_PDU & Value ) const;
    KBOOL operator != ( const Entity_Damage_Status_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
