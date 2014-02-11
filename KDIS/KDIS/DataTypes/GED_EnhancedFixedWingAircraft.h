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
    class:      GED_EnhancedFixedWingAircraft
    created:    24:06:2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of enhanced fixed wing aircraft.
    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./GED_BasicFixedWingAircraft.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GED_EnhancedFixedWingAircraft : public GED_BasicFixedWingAircraft
{
protected:

    KUINT8 m_ui8SupFuelStatus;

    KUINT8 m_ui8AirMaintStatus;

    KUINT8 m_ui8PriAmmun;

    KUINT8 m_ui8SecAmmun;

public:

    static const KUINT16 GED_ENHANCED_FIXED_WING_AIRCRAFT_SIZE = 24;

    GED_EnhancedFixedWingAircraft();

    GED_EnhancedFixedWingAircraft( KDataStream & stream )throw( KException );

    GED_EnhancedFixedWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi, KINT8 Theta, KINT8 Phi,
                                   KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation, KINT8 Speed, KUINT8 SupFuelStatus,
                                   KUINT8 AirMaintenanceStatus, KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    GED_EnhancedFixedWingAircraft( const GED_BasicFixedWingAircraft & BFWA,  KUINT8 SupFuelStatus, KUINT8 AirMaintenanceStatus, KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    virtual ~GED_EnhancedFixedWingAircraft();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::SetSupplementalFuelStatus
    //              KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::GetSupplementalFuelStatus
    // Description: Represents the amount of supplemental fuel remaining.
    //              Specified in natural units.
    // Parameter:   KUINT8  F, void
    //************************************
    void SetSupplementalFuelStatus( KUINT8 F );
    KUINT8 GetSupplementalFuelStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::SetAirMaintenanceStatus
    //              KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::GetAirMaintenanceStatus
    // Description: Time spent since last maintenance in hours.
    // Parameter:   KUINT8  A, void
    //************************************
    void SetAirMaintenanceStatus( KUINT8 A );
    KUINT8 GetAirMaintenanceStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::SetPrimaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::GetPrimaryAmmunition
    // Description: Amount of primary ammunition remaining.
    //              Specified in natural ammunition units for the primary weapon system.
    // Parameter:   KUINT8  P, void
    //************************************
    void SetPrimaryAmmunition( KUINT8 P );
    KUINT8 GetPrimaryAmmunition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::SetSecondaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::GetSecondaryAmmunition
    // Description: Amount of secondary ammunition remaining.
    //              Specified in natural ammunition units for the secondary weapon system.
    // Parameter:   KUINT8  S, void
    //************************************
    void SetSecondaryAmmunition( KUINT8 S );
    KUINT8 GetSecondaryAmmunition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GED_EnhancedFixedWingAircraft & Value ) const;
    KBOOL operator != ( const GED_EnhancedFixedWingAircraft & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

