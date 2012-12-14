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

using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;

class KDIS_EXPORT GED_EnhancedFixedWingAircraft : public GED_BasicFixedWingAircraft
{
protected:

    KUINT8 m_ui8SupFuelStatus;

    KUINT8 m_ui8AirMaintStatus;

    KUINT8 m_ui8PriAmmun;

    KUINT8 m_ui8SecAmmun;

public:

    static const KUINT16 GED_ENHANCED_FIXED_WING_AIRCRAFT_SIZE = 24;

    GED_EnhancedFixedWingAircraft( void );

    GED_EnhancedFixedWingAircraft( KDataStream & stream )throw( KException );

    GED_EnhancedFixedWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi, KINT8 Theta, KINT8 Phi,
                                   KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation, KINT8 Speed, KUINT8 SupFuelStatus,
                                   KUINT8 AirMaintenanceStatus, KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    GED_EnhancedFixedWingAircraft( const GED_BasicFixedWingAircraft & BFWA,  KUINT8 SupFuelStatus, KUINT8 AirMaintenanceStatus, KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    virtual ~GED_EnhancedFixedWingAircraft( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedFixedWingAircraft::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual GroupedEntityCategory GetGroupedEntityCategory() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

