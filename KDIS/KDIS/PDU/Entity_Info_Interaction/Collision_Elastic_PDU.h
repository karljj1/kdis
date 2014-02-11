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
    class:      Collision_Elastic_PDU
    DIS:        (6) 1278.1A - 1998
    created:    08/11/2008
    author:     Karl Jones

    purpose:    The Collision-Elastic PDU is a member of a commercially 
				available set of Newtonian Protocols and in that protocol
				set is named the Newtonian Collision PDU. 
				The Newtonian Protocol provides a mechanism for introducing
				high fidelity interactions in DIS exercises.

    Size:       800 bits / 100 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/Vector.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::Vector;

class KDIS_EXPORT Collision_Elastic_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_IssuingEntityID;

    KDIS::DATA_TYPE::EntityIdentifier m_CollidingEntityID;

    KDIS::DATA_TYPE::EntityIdentifier m_EventID;

    KUINT16 m_ui16Padding1;

    KDIS::DATA_TYPE::Vector m_ContactVelocity;

    KFLOAT32 m_f32Mass;

    KDIS::DATA_TYPE::Vector m_Location;

    KFLOAT32 m_f32CIRXX;

    KFLOAT32 m_f32CIRXY;

    KFLOAT32 m_f32CIRXZ;

    KFLOAT32 m_f32CIRYY;

    KFLOAT32 m_f32CIRYZ;

    KFLOAT32 m_f32CIRZZ;

    KDIS::DATA_TYPE::Vector m_UnitSurfaceNormal;

    KFLOAT32 m_f32COR;

public:

    static const KUINT16 COLLISION_ELASTIC_PDU_SIZE = 100;

    Collision_Elastic_PDU();

    Collision_Elastic_PDU( KDataStream & stream ) throw( KException );

	Collision_Elastic_PDU( const Header & H, KDataStream & stream ) throw( KException );

    virtual ~Collision_Elastic_PDU();

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::SetIssuingEntityID
    //              KDIS::PDU::Collision_Elastic_PDU::GetIssuingEntityID
    // Description: Entity Issuing the collision
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetIssuingEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetIssuingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetIssuingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::SetCollidingEntityID
    //              KDIS::PDU::Collision_Elastic_PDU::GetCollidingEntityID
    // Description: Entity that has collided with the issuing entity
    //              If collision is with terrain or unknown entity
    //              the id will be ENTITY_ID_UNKNOWN
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetCollidingEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetCollidingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetCollidingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::SetEventID
    //              KDIS::PDU::Collision_Elastic_PDU::GetEventID
    // Description: ID generated to associate related collision events
    //              to this one.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetEventID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetEventID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::SetContactVelocity
    //              KDIS::PDU::Collision_Elastic_PDU::GetContactVelocity
    // Description: Velocity at the time collision is detected at the point the
    //              collision is detected.
    //              Linear Velocity Vector.
    // Parameter:   const Vector & V
    //************************************
    void SetContactVelocity( const KDIS::DATA_TYPE::Vector & V );
    const KDIS::DATA_TYPE::Vector & GetContactVelocity() const;
    KDIS::DATA_TYPE::Vector & GetContactVelocity();

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::SetMass
    //              KDIS::PDU::Collision_Elastic_PDU::GetMass
    // Description: Issuing entity mass in kilograms
    // Parameter:   KFLOAT32 M
    //************************************
    void SetMass( KFLOAT32 M );
    KFLOAT32 GetMass() const;

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::SetLocation
    //              KDIS::PDU::Collision_Elastic_PDU::GetLocation
    // Description: Location of collision with respect to the
    //              issuing entity. Represented by an
    //              Entity Coordinate Vector.
    // Parameter:   const Vector & L
    //************************************
    void SetLocation( const KDIS::DATA_TYPE::Vector & L );
    const KDIS::DATA_TYPE::Vector & GetLocation() const;
    KDIS::DATA_TYPE::Vector & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::SetCollisionIntermediateResult
    //              KDIS::PDU::Collision_Elastic_PDU::GetCollisionIntermediateResult
    // Description: Collision intermediate result. Theese six records represent
    //              the six independent components of a positive semi-definite matrix
    //              formed by pre-multiplying and post-multiplying the tensor inertia, by
    //              the antisymmetric matrix generated by the moment arm.
    // Parameter:   KFLOAT32 CIR, void
    //************************************
    void SetCollisionIntermediateResultXX( KFLOAT32 CIR );
    void SetCollisionIntermediateResultXY( KFLOAT32 CIR );
    void SetCollisionIntermediateResultXZ( KFLOAT32 CIR );
    void SetCollisionIntermediateResultYY( KFLOAT32 CIR );
    void SetCollisionIntermediateResultYZ( KFLOAT32 CIR );
    void SetCollisionIntermediateResultZZ( KFLOAT32 CIR );
    KFLOAT32 GetCollisionIntermediateResultXX() const;
    KFLOAT32 GetCollisionIntermediateResultXY() const;
    KFLOAT32 GetCollisionIntermediateResultXZ() const;
    KFLOAT32 GetCollisionIntermediateResultYY() const;
    KFLOAT32 GetCollisionIntermediateResultYZ() const;
    KFLOAT32 GetCollisionIntermediateResultZZ() const;
    void SetCollisionIntermediateResult( KFLOAT32 XX, KFLOAT32 XY, KFLOAT32 XZ,
                                         KFLOAT32 YY, KFLOAT32 YZ, KFLOAT32 ZZ );

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::SetUnitSurfaceNormal
    //              KDIS::PDU::Collision_Elastic_PDU::GetUnitSurfaceNormal
    // Description: Normal vector to the surface at the point
    //              of collision detection. Represented in world coordinates.
    //              Vector type = Entity Coordinate Vector.
    // Parameter:   const Vector & USN
    //************************************
    void SetUnitSurfaceNormal( const KDIS::DATA_TYPE::Vector & USN );
    const KDIS::DATA_TYPE::Vector & GetUnitSurfaceNormal() const;
    KDIS::DATA_TYPE::Vector & GetUnitSurfaceNormal();

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::SetCoefficientOfRestitution
    //              KDIS::PDU::Collision_Elastic_PDU::GetCoefficientOfRestitution
    // Description: Represents the degree to which energy is conserved
    //              in addition represents a free parameter which developers
    //              may tune their collision interactions.
    // Parameter:   KFLOAT32 COR
    //************************************
    void SetCoefficientOfRestitution( KFLOAT32 COR );
    KFLOAT32 GetCoefficientOfRestitution() const;

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Collision_Elastic_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Collision_Elastic_PDU & Value ) const;
    KBOOL operator != ( const Collision_Elastic_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
