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

using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;

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

    GED_BasicGroundCombatVehicle( void );

    GED_BasicGroundCombatVehicle( KDataStream & stream )throw( KException );

    GED_BasicGroundCombatVehicle( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA,
                                  KINT8 Psi, KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 TurretAzimuth, KINT8 GunElevation,
                                  KINT8 TurretSlewRate, KINT8 GunElevationRate );

    virtual ~GED_BasicGroundCombatVehicle( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatVehicle::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual GroupedEntityCategory GetGroupedEntityCategory() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

