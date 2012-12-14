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

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::Vector;
using KDIS::DATA_TYPE::ENUMS::CollisionType;

class KDIS_EXPORT Collision_PDU : public Header
{
protected:

    EntityIdentifier m_IssuingEntityID;

    EntityIdentifier m_CollidingEntityID;

    EntityIdentifier m_EventID;

    KUINT8 m_ui8CollisionType;

    KUINT8 m_ui8Padding;

    Vector m_Velocity;

    KFLOAT32 m_f32Mass;

    Vector m_Location;

public:

    static const KUINT16 COLLISION_PDU_SIZE = 60;

    Collision_PDU( void );

    Collision_PDU( KDataStream & stream ) throw( KException );

    Collision_PDU( const EntityIdentifier & IssuingID, const EntityIdentifier & CollidingID,
                   const EntityIdentifier & EventID, CollisionType CT,const Vector & Velocity,
                   KFLOAT32 Mass, const Vector & Location );

    virtual ~Collision_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetIssuingEntityID
    //              KDIS::PDU::Collision_PDU::GetIssuingEntityID
    // Description: Entity Issuing the collision
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetIssuingEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetIssuingEntityID() const;
    EntityIdentifier & GetIssuingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetCollidingEntityID
    //              KDIS::PDU::Collision_PDU::GetCollidingEntityID
    // Description: Entity that has collided with the issuing entity
    //              If collision is with terrain or unknown entity
    //              the id will be ENTITY_ID_UNKNOWN
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetCollidingEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetCollidingEntityID() const;
    EntityIdentifier & GetCollidingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetEventID
    //              KDIS::PDU::Collision_PDU::GetEventID
    // Description: ID generated to associate related collision events
    //              to this one.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEventID( const EntityIdentifier & ID );
    const EntityIdentifier & GetEventID() const;
    EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetCollisionType
    //              KDIS::PDU::Collision_PDU::GetCollisionType
    // Description: Describes the type of collision that occurred
    // Parameter:   CollisionType CT, void
    //************************************
    void SetCollisionType( CollisionType CT );
    CollisionType GetCollisionType() const;

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetVelocity
    //              KDIS::PDU::Collision_PDU::GetVelocity
    // Description: Issuing Entity Velocity at time of collision
    //              detection. Represented as a Linear
    //              Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetVelocity( const Vector & V );
    const Vector & GetVelocity() const;
    Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetMass
    //              KDIS::PDU::Collision_PDU::GetMass
    // Description: Issuing entity mass in kilograms
    // Parameter:   KFLOAT32 M, void
    //************************************
    void SetMass( KFLOAT32 M );
    KFLOAT32 GetMass() const;

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::SetLocation
    //              KDIS::PDU::Collision_PDU::GetLocation
    // Description: Location of collision with respect to the
    //              issuing entity. Represented by an
    //              Entity Coordinate Vector.
    // Parameter:   const Vector & L, void
    //************************************
    void SetLocation( const Vector & L );
    const Vector & GetLocation() const;
    Vector & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Collision_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
