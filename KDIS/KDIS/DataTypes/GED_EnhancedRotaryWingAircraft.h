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
    class:      GED_EnhancedRotaryWingAircraft
    created:    07:06:2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of enhanced rotary wing aircraft.
    size:       224 bits / 28 octets
*********************************************************************/

#pragma once

#include "./GED_BasicRotorWingAircraft.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GED_EnhancedRotaryWingAircraft : public GED_BasicRotorWingAircraft
{
protected:

    KUINT8 m_ui8SupFuelStatus;

    KUINT8 m_ui8AirMaintStatus;

    KUINT8 m_ui8PriAmmun;

    KUINT8 m_ui8SecAmmun;

public:

    static const KUINT16 GED_ENHANCED_ROTARY_WING_AIRCRAFT_SIZE = 28;

    GED_EnhancedRotaryWingAircraft();

    GED_EnhancedRotaryWingAircraft( KDataStream & stream )throw( KException );

    GED_EnhancedRotaryWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi,
                                    KINT8 Theta, KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation,
                                    KINT8 Speed, KINT8 TurretAzimuth, KINT8 GunElevation, KINT8 TurretSlewRate, KINT8 GunElevationRate,
                                    KUINT8 SupFuelStatus, KUINT8 AirMaintenanceStatus, KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    GED_EnhancedRotaryWingAircraft( const GED_BasicRotorWingAircraft & BRWA, KUINT8 SupFuelStatus, KUINT8 AirMaintenanceStatus, KUINT8 PrimaryAmmunition,
                                    KUINT8 SecondaryAmmunition );

    virtual ~GED_EnhancedRotaryWingAircraft();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::SetSupplementalFuelStatus
    //              KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::GetSupplementalFuelStatus
    // Description: Represents the amount of supplemental fuel remaining.
    //              Specified in natural units.
    // Parameter:   KUINT8  F
    //************************************
    void SetSupplementalFuelStatus( KUINT8 F );
    KUINT8 GetSupplementalFuelStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::SetAirMaintenanceStatus
    //              KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::GetAirMaintenanceStatus
    // Description: Time spent since last maintenance in hours.
    // Parameter:   KUINT8  A
    //************************************
    void SetAirMaintenanceStatus( KUINT8 A );
    KUINT8 GetAirMaintenanceStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::SetPrimaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::GetPrimaryAmmunition
    // Description: Amount of primary ammunition remaining.
    //              Specified in natural ammunition units for the primary weapon system.
    // Parameter:   KUINT8  P
    //************************************
    void SetPrimaryAmmunition( KUINT8 P );
    KUINT8 GetPrimaryAmmunition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::SetSecondaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::GetSecondaryAmmunition
    // Description: Amount of secondary ammunition remaining.
    //              Specified in natural ammunition units for the secondary weapon system.
    // Parameter:   KUINT8  S
    //************************************
    void SetSecondaryAmmunition( KUINT8 S );
    KUINT8 GetSecondaryAmmunition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedRotaryWingAircraft::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GED_EnhancedRotaryWingAircraft & Value ) const;
    KBOOL operator != ( const GED_EnhancedRotaryWingAircraft & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

