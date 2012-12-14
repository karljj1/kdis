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
    class:      GED_BasicRotorWingAircraft
    created:    07:06:2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of basic rotor wing aircrafts.
    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./GED_BasicFixedWingAircraft.h"
#include "./EntityAppearance.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;

class KDIS_EXPORT GED_BasicRotorWingAircraft : public GED_BasicFixedWingAircraft
{
protected:

    KINT8 m_i8TrrtAz;

    KINT8 m_i8GnElv;

    KINT8 m_i8TrrtSlwRt;

    KINT8 m_i8GnElvRt;

public:

    static const KUINT16 GED_BASIC_ROTOR_WING_AIRCRAFT_SIZE = 24;

    GED_BasicRotorWingAircraft( void );

    GED_BasicRotorWingAircraft( KDataStream & stream )throw( KException );

    GED_BasicRotorWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi,
                                KINT8 Theta, KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation,
                                KINT8 Speed, KINT8 TurretAzimuth, KINT8 GunElevation, KINT8 TurretSlewRate, KINT8 GunElevationRate );

    virtual ~GED_BasicRotorWingAircraft( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::SetTurretAzimuth
    //              KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::GetTurretAzimuth
    // Description: Turret azimuth specified in 25 milliradian increments.
    // Parameter:   KINT8 T, void
    //************************************
    void SetTurretAzimuth( KINT8 T );
    KINT8 GetTurretAzimuth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::SetGunElevation
    //              KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::GetGunElevation
    // Description: Gun elevation specified in 25 milliradian increments.
    // Parameter:   KINT8 G, void
    //************************************
    void SetGunElevation( KINT8 G );
    KINT8 GetGunElevation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::SetTurretSlewRate
    //              KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::GetTurretSlewRate
    // Description: Turret slew rate specified in 25 milliradian per secound increments.
    // Parameter:   KINT8 T, void
    //************************************
    void SetTurretSlewRate( KINT8 T );
    KINT8 GetTurretSlewRate() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::SetGunElevationRate
    //              KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::GetGunElevationRate
    // Description: Gun elevation rate specified in 25 milliradian per secound increments.
    // Parameter:   KINT8 G, void
    //************************************
    void SetGunElevationRate( KINT8 G );
    KINT8 GetGunElevationRate() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GED_BasicRotorWingAircraft & Value ) const;
    KBOOL operator != ( const GED_BasicRotorWingAircraft & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

