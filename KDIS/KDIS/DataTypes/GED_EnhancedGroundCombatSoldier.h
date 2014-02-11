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

class KDIS_EXPORT GED_EnhancedGroundCombatSoldier : public GED_BasicGroundCombatSoldier
{
protected:

    KUINT8 m_ui8WaterStatus;

    KUINT8 m_ui8RestStatus;

    KUINT8 m_ui8PriAmmun;

    KUINT8 m_ui8SecAmmun;

public:

    static const KUINT16 GED_ENHANCED_GROUND_COMBAT_SOLDIER_SIZE = 24;

    GED_EnhancedGroundCombatSoldier();

    GED_EnhancedGroundCombatSoldier( KDataStream & stream )throw( KException );

    GED_EnhancedGroundCombatSoldier( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA,
                                     KINT8 Psi, KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 HeadAzimuth, KINT8 HeadElevation,
                                     KINT8 HeadScanRate, KINT8 HeadElevationRate, KUINT8 WaterStatus, KDIS::DATA_TYPE::ENUMS::RestStatus R,
                                     KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    GED_EnhancedGroundCombatSoldier( const GED_BasicGroundCombatSoldier & BGCS, KUINT8 WaterStatus, KDIS::DATA_TYPE::ENUMS::RestStatus R,
                                     KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition );

    virtual ~GED_EnhancedGroundCombatSoldier();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GetGroupedEntityCategory() const;

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
    // Parameter:   KUINT8  W
    //************************************
    void SetWaterStatus( KUINT8 W );
    KUINT8 GetWaterStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::SetRestStatus
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetRestStatus
    // Description: How rested is the soldier. Number of hours slept on average.
    // Parameter:   RestStatus  R
    //************************************
    void SetRestStatus( KDIS::DATA_TYPE::ENUMS::RestStatus R );
    KDIS::DATA_TYPE::ENUMS::RestStatus GetRestStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::SetPrimaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetPrimaryAmmunition
    // Description: Amount of primary ammunition remaining.
    //              Specified in natural ammunition units for the primary weapon system.
    // Parameter:   KUINT8  P
    //************************************
    void SetPrimaryAmmunition( KUINT8 P );
    KUINT8 GetPrimaryAmmunition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::SetSecondaryAmmunition
    //              KDIS::DATA_TYPE::GED_EnhancedGroundCombatSoldier::GetSecondaryAmmunition
    // Description: Amount of secondary ammunition remaining.
    //              Specified in natural ammunition units for the secondary weapon system.
    // Parameter:   KUINT8  S
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

} // END namespace DATA_TYPES
} // END namespace KDIS

