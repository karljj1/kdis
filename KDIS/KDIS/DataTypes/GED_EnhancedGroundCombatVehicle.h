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
    class:      GED_EnhancedGroundCombatVehicle
    created:    07/06/2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of enhanced ground combat vehicles.
    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./GED_BasicGroundCombatVehicle.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GED_EnhancedGroundCombatVehicle : public GED_BasicGroundCombatVehicle
{
protected:

    KUINT8 m_ui8FuelStatus;

    KUINT8 m_ui8GrndMaintStatus;

    KUINT8 m_ui8PriAmmun;

    KUINT8 m_ui8SecAmmun;

public:

    static const KUINT16 GED_ENHANCED_GROUND_COMBAT_VEHICLE_SIZE = 24;

    GED_EnhancedGroundCombatVehicle();

    GED_EnhancedGroundCombatVehicle( KDataStream & stream )throw( KException );

    GED_EnhancedGroundCombatVehicle( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi,
                                     KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 TurretAzimuth, KINT8 GunElevation, KINT8 TurretSlewRate,
                                     KINT8 GunElevationRate, KUINT8 FuelStatus, KUINT8 GroundMaintenanceStatus, KUINT8 PrimaryAmmunition,
                                     KUINT8 SecondaryAmmunition );

    GED_EnhancedGroundCombatVehicle( const GED_BasicGroundCombatVehicle & BGCV, KUINT8 FuelStatus, KUINT8 GroundMaintenanceStatus,
                                     KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    virtual ~GED_EnhancedGroundCombatVehicle();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatVehicle::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GetGroupedEntityCategory() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS

