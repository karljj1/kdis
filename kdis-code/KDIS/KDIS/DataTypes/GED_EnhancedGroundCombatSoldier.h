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
    class:      GED_EnhancedGroundCombatSoldier
    created:    07:06:2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of enhanced ground combat soldiers.
    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./GED_BasicGroundCombatSoldier.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;
using KDIS::DATA_TYPE::ENUMS::RestStatus;

class KDIS_EXPORT GED_EnhancedGroundCombatSoldier : public GED_BasicGroundCombatSoldier
{
protected:

    KUINT8 m_ui8WaterStatus;

    KUINT8 m_ui8RestStatus;

    KUINT8 m_ui8PriAmmun;

    KUINT8 m_ui8SecAmmun;

public:

    static const KUINT16 GED_ENHANCED_GROUND_COMBAT_SOLDIER_SIZE = 24;

    GED_EnhancedGroundCombatSoldier( void );

    GED_EnhancedGroundCombatSoldier( KDataStream & stream )throw( KException );

    GED_EnhancedGroundCombatSoldier( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA,
                                     KINT8 Psi, KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 HeadAzimuth, KINT8 HeadElevation,
                                     KINT8 HeadScanRate, KINT8 HeadElevationRate, KUINT8 WaterStatus, RestStatus R,
                                     KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    GED_EnhancedGroundCombatSoldier( const GED_BasicGroundCombatSoldier & BGCS, KUINT8 WaterStatus, RestStatus R,
                                     KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    virtual ~GED_EnhancedGroundCombatSoldier( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::SetWaterStatus
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetWaterStatus
    // Description: Represents the amount of water on hand.
    //              Specified in one ounce increments.
    // Parameter:   KUINT8  W, void
    //************************************
    void SetWaterStatus( KUINT8 W );
    KUINT8 GetWaterStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::SetRestStatus
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetRestStatus
    // Description: How rested is the soldier. Number of hours slept on average.
    // Parameter:   RestStatus  R, void
    //************************************
    void SetRestStatus( RestStatus R );
    RestStatus GetRestStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::SetPrimaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetPrimaryAmmunition
    // Description: Amount of primary ammunition remaining.
    //              Specified in natural ammunition units for the primary weapon system.
    // Parameter:   KUINT8  P, void
    //************************************
    void SetPrimaryAmmunition( KUINT8 P );
    KUINT8 GetPrimaryAmmunition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::SetSecondaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetSecondaryAmmunition
    // Description: Amount of secondary ammunition remaining.
    //              Specified in natural ammunition units for the secondary weapon system.
    // Parameter:   KUINT8  S, void
    //************************************
    void SetSecondaryAmmunition( KUINT8 S );
    KUINT8 GetSecondaryAmmunition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GED_EnhancedGroundCombatSoldier & Value ) const;
    KBOOL operator != ( const GED_EnhancedGroundCombatSoldier & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

