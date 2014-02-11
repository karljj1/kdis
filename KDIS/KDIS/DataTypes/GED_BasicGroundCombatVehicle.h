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
    class:      GED_BasicGroundCombatVehicle
    created:    13:05:2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of basic ground combat vehicles.
    size:       160 bits / 20 octets
*********************************************************************/

#pragma once

#include "./GED.h"
#include "./EntityAppearance.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GED_BasicGroundCombatVehicle : public GED
{
protected:

    KUINT16 m_ui16EntityID;

    KINT16 m_i16Offsets[3];

    EntityAppearance m_EA;

    KINT8 m_i8Ori[3];

    KINT8 m_i8Spd;

    KINT8 m_i8TrrtAz;

    KINT8 m_i8GnElv;

    KINT8 m_i8TrrtSlwRt;

    KINT8 m_i8GnElvRt;

public:

    static const KUINT16 GED_BASIC_GROUND_COMBAT_VEHICLE_SIZE = 20;

    GED_BasicGroundCombatVehicle();

    GED_BasicGroundCombatVehicle( KDataStream & stream )throw( KException );

    GED_BasicGroundCombatVehicle( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA,
                                  KINT8 Psi, KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 TurretAzimuth, KINT8 GunElevation,
                                  KINT8 TurretSlewRate, KINT8 GunElevationRate );

    virtual ~GED_BasicGroundCombatVehicle();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityID
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetEntityID
    // Description: Entity identifier unique within the group.
    //              The Site Identifier and Application Identifiers shall be the same as
    //              those designated in the Group Entity ID field.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetEntityID( KUINT16 ID );
    KUINT16 GetEntityID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityLocation
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityLocationXOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityLocationYOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityLocationZOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetEntityLocationXOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetEntityLocationYOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetEntityLocationZOffset
    // Description: Location of the grouped entity specified by a set of three offsets.
    //              Determined by the difference, in meters, of the grouped entity from the Group Reference Point.
    // Parameter:   KINT16, void
    //************************************
    void SetEntityLocation( KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset );
    void SetEntityLocation( KINT16 Offsets[3] );
    void SetEntityLocationXOffset( KINT16 X );
    void SetEntityLocationYOffset( KINT16 Y );
    void SetEntityLocationZOffset( KINT16 Z );
    KINT16 GetEntityLocationXOffset() const;
    KINT16 GetEntityLocationYOffset() const;
    KINT16 GetEntityLocationZOffset() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityAppearance
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetEntityAppearance
    // Description: Entity appearance bit field accessors/mutator
    // Parameter:   const EntityAppearance & EA, void
    //************************************
    void SetEntityAppearance( const EntityAppearance & EA );
    const EntityAppearance & GetEntityAppearance() const;
    EntityAppearance & GetEntityAppearance();

    //************************************
    //              GetEntityOrientationPhi
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityOrientation
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityOrientationPsi
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityOrientationTheta
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetEntityOrientationPhi
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetEntityOrientationPsi
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetEntityOrientationTheta
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetEntityOrientationPhi
    // Description: Entity orientation in euler angles, psi, theta and phi, in 25 milliradian increments.
    // Parameter:   KINT8, void
    //************************************
    void SetEntityOrientation( KINT8 Psi, KINT8 Theta, KINT8 Phi );
    void SetEntityOrientation( KINT8 Ori[3] );
    void SetEntityOrientationPsi( KINT8 P );
    void SetEntityOrientationTheta( KINT8 T );
    void SetEntityOrientationPhi( KINT8 P );
    KINT8 GetEntityOrientationPsi() const;
    KINT8 GetEntityOrientationTheta() const;
    KINT8 GetEntityOrientationPhi() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetSpeed
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetSpeed
    // Description: Signed magnitude value of the entity’s absolute velocity vector.
    //              A negative value shall indicate that the entity is moving backwards.
    //              Measured in Meters Per Secound (m/s).
    // Parameter:   KINT8 S, void
    //************************************
    void SetSpeed( KINT8 S );
    KINT8 GetSpeed() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetTurretAzimuth
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetTurretAzimuth
    // Description: Turret azimuth specified in 25 milliradian increments.
    // Parameter:   KINT8 T, void
    //************************************
    void SetTurretAzimuth( KINT8 T );
    KINT8 GetTurretAzimuth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetGunElevation
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetGunElevation
    // Description: Gun elevation specified in 25 milliradian increments.
    // Parameter:   KINT8 G, void
    //************************************
    void SetGunElevation( KINT8 G );
    KINT8 GetGunElevation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetTurretSlewRate
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetTurretSlewRate
    // Description: Turret slew rate specified in 25 milliradian per secound increments.
    // Parameter:   KINT8 T, void
    //************************************
    void SetTurretSlewRate( KINT8 T );
    KINT8 GetTurretSlewRate() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::SetGunElevationRate
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetGunElevationRate
    // Description: Gun elevation rate specified in 25 milliradian per secound increments.
    // Parameter:   KINT8 G, void
    //************************************
    void SetGunElevationRate( KINT8 G );
    KINT8 GetGunElevationRate() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GED_BasicGroundCombatVehicle & Value ) const;
    KBOOL operator != ( const GED_BasicGroundCombatVehicle & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

