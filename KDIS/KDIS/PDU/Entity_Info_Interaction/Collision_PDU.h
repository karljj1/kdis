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
    class:      Collision_PDU
    DIS:        (5) 1278.1 - 1995
    created:    08/10/2008
    author:     Karl Jones

    purpose:    PDU Sent upon a collision event. This could be between a simulated
				entity or another object in the simulated world (e.g., a cultural
				feature such as a bridge or building).

    Size:       480 bits / 60 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/Vector.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Collision_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_IssuingEntityID;

    KDIS::DATA_TYPE::EntityIdentifier m_CollidingEntityID;

    KDIS::DATA_TYPE::EntityIdentifier m_EventID;

    KUINT8 m_ui8CollisionType;

    KUINT8 m_ui8Padding;

    KDIS::DATA_TYPE::Vector m_Velocity;

    KFLOAT32 m_f32Mass;

    KDIS::DATA_TYPE::Vector m_Location;

public:

    static const KUINT16 COLLISION_PDU_SIZE = 60;

    Collision_PDU();

    Collision_PDU( KDataStream & stream ) throw( KException );

	Collision_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Collision_PDU( const KDIS::DATA_TYPE::EntityIdentifier & IssuingID, const KDIS::DATA_TYPE::EntityIdentifier & CollidingID,
				   const KDIS::DATA_TYPE::EntityIdentifier & EventID, KDIS::DATA_TYPE::ENUMS::CollisionType CT,const KDIS::DATA_TYPE::Vector & Velocity,
                   KFLOAT32 Mass, const KDIS::DATA_TYPE::Vector & Location );

    virtual ~Collision_PDU();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetIssuingEntityID
    //              KDIS::PDU::Collision_PDU::GetIssuingEntityID
    // Description: Entity Issuing the collision
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetIssuingEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetIssuingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetIssuingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetCollidingEntityID
    //              KDIS::PDU::Collision_PDU::GetCollidingEntityID
    // Description: Entity that has collided with the issuing entity
    //              If collision is with terrain or unknown entity
    //              the id will be ENTITY_ID_UNKNOWN
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetCollidingEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetCollidingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetCollidingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetEventID
    //              KDIS::PDU::Collision_PDU::GetEventID
    // Description: ID generated to associate related collision events
    //              to this one.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetEventID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetEventID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetCollisionType
    //              KDIS::PDU::Collision_PDU::GetCollisionType
    // Description: Describes the type of collision that occurred
    // Parameter:   CollisionType CT
    //************************************
	void SetCollisionType( KDIS::DATA_TYPE::ENUMS::CollisionType CT );
	KDIS::DATA_TYPE::ENUMS::CollisionType GetCollisionType() const;

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetVelocity
    //              KDIS::PDU::Collision_PDU::GetVelocity
    // Description: Issuing Entity Velocity at time of collision
    //              detection. Represented as a Linear
    //              Velocity Vector.
    // Parameter:   const Vector & V
    //************************************
    void SetVelocity( const KDIS::DATA_TYPE::Vector & V );
    const KDIS::DATA_TYPE::Vector & GetVelocity() const;
    KDIS::DATA_TYPE::Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetMass
    //              KDIS::PDU::Collision_PDU::GetMass
    // Description: Issuing entity mass in kilograms
    // Parameter:   KFLOAT32 M
    //************************************
    void SetMass( KFLOAT32 M );
    KFLOAT32 GetMass() const;

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetLocation
    //              KDIS::PDU::Collision_PDU::GetLocation
    // Description: Location of collision with respect to the
    //              issuing entity. Represented by an
    //              Entity Coordinate Vector.
    // Parameter:   const Vector & L
    //************************************
    void SetLocation( const KDIS::DATA_TYPE::Vector & L );
    const KDIS::DATA_TYPE::Vector & GetLocation() const;
    KDIS::DATA_TYPE::Vector & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Collision_PDU & Value ) const;
    KBOOL operator != ( const Collision_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
