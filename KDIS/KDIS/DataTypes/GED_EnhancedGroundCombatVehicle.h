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
    class:      GED_EnhancedGroundCombatVehicle
    created:    07:06:2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of enhanced ground combat vehicles.
    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./GED_BasicGroundCombatVehicle.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;

class KDIS_EXPORT GED_EnhancedGroundCombatVehicle : public GED_BasicGroundCombatVehicle
{
protected:

    KUINT8 m_ui8FuelStatus;

    KUINT8 m_ui8GrndMaintStatus;

    KUINT8 m_ui8PriAmmun;

    KUINT8 m_ui8SecAmmun;

public:

    static const KUINT16 GED_ENHANCED_GROUND_COMBAT_VEHICLE_SIZE = 24;

    GED_EnhancedGroundCombatVehicle( void );

    GED_EnhancedGroundCombatVehicle( KDataStream & stream )throw( KException );

    GED_EnhancedGroundCombatVehicle( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi,
                                     KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 TurretAzimuth, KINT8 GunElevation, KINT8 TurretSlewRate,
                                     KINT8 GunElevationRate, KUINT8 FuelStatus, KUINT8 GroundMaintenanceStatus, KUINT8 PrimaryAmmunition,
                                     KUINT8 SecondaryAmmunition );

    GED_EnhancedGroundCombatVehicle( const GED_BasicGroundCombatVehicle & BGCV, KUINT8 FuelStatus, KUINT8 GroundMaintenanceStatus,
                                     KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    virtual ~GED_EnhancedGroundCombatVehicle( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::SetFuelStatus
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::GetFuelStatus
    // Description: Represents the amount of fuel remaining.
    //              Specified in 10 liter increments.
    // Parameter:   KUINT8  F, void
    //************************************
    void SetFuelStatus( KUINT8 F );
    KUINT8 GetFuelStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::SetGroundMaintenanceStatus
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::GetGroundMaintenanceStatus
    // Description: Distance traveled since the last failure.
    //              Specified in tens of kilometers.
    // Parameter:   KUINT8  G, void
    //************************************
    void SetGroundMaintenanceStatus( KUINT8 G );
    KUINT8 GetGroundMaintenanceStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::SetPrimaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::GetPrimaryAmmunition
    // Description: Amount of primary ammunition remaining.
    //              Specified in natural ammunition units for the primary weapon system.
    // Parameter:   KUINT8  P, void
    //************************************
    void SetPrimaryAmmunition( KUINT8 P );
    KUINT8 GetPrimaryAmmunition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::SetSecondaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::GetSecondaryAmmunition
    // Description: Amount of secondary ammunition remaining.
    //              Specified in natural ammunition units for the secondary weapon system.
    // Parameter:   KUINT8  S, void
    //************************************
    void SetSecondaryAmmunition( KUINT8 S );
    KUINT8 GetSecondaryAmmunition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GED_EnhancedGroundCombatVehicle & Value ) const;
    KBOOL operator != ( const GED_EnhancedGroundCombatVehicle & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

