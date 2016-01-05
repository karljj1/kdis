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
    class:      Entity_Damage_Status_PDU
    DIS:        (7) 1278.1-2012
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

class KDIS_EXPORT Entity_Damage_Status_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_DmgEnt;

    KUINT32 m_ui32Padding;

    KUINT16 m_ui16NumDmgDescRecs;

    std::vector<KDIS::DATA_TYPE::StdVarPtr> m_vDdRec;

public:

    static const KUINT16 ENTITY_DAMAGE_STATE_PDU = 24; // Min size

    Entity_Damage_Status_PDU();

    Entity_Damage_Status_PDU( KDataStream & stream ) throw( KException );

    Entity_Damage_Status_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Entity_Damage_Status_PDU( const KDIS::DATA_TYPE::EntityIdentifier & DamagedEntityID );

    virtual ~Entity_Damage_Status_PDU();

    //************************************
    // FullName:    KDIS::PDU::Entity_Damage_Status_PDU::SetDamagedEntityID
    //              KDIS::PDU::Entity_Damage_Status_PDU::GetDamagedEntityID
    // Description: The damaged entity.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetDamagedEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetDamagedEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetDamagedEntityID();

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
    //              other Standard Variable records.
    // Parameter:   StdVarPtr DD, const vector<StdVarPtr> & DD
    //************************************    
    void AddDamageDescriptionRecord( KDIS::DATA_TYPE::StdVarPtr DD );
    void SetDamageDescriptionRecords( const std::vector<KDIS::DATA_TYPE::StdVarPtr> & DD );
    const std::vector<KDIS::DATA_TYPE::StdVarPtr> & GetDamageDescriptionRecords() const;
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
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
