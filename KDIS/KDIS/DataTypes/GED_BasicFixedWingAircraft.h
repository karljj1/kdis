/*********************************************************************
Copyright 2013 KDIS
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
    class:      GED_BasicFixedWingAircraft
    created:    21:06:2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of basic fixed wing aircraft.
    size:       160 bits / 20 octets
*********************************************************************/

#pragma once

#include "./GED_GroundLogisticsVehicle.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;

class KDIS_EXPORT GED_BasicFixedWingAircraft : public GED_GroundLogisticsVehicle
{
protected:

    KUINT8 m_ui8FuelStatus;

    KINT8 m_i8HoriDevi;

    KINT8 m_i8VertDevi;

public:

    static const KUINT16 GED_BASIC_FIXED_WING_AIRCRAFT_SIZE = 20;

    GED_BasicFixedWingAircraft();

    GED_BasicFixedWingAircraft( KDataStream & stream )throw( KException );

    GED_BasicFixedWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi, KINT8 Theta,
                                KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation, KINT8 Speed );

    virtual ~GED_BasicFixedWingAircraft();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetFuelStatus
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetFuelStatus
    // Description: Represents the amount of primary fuel remaining.
    //              Specified in natural units of the specified system.
    // Parameter:   KUINT8  F, void
    //************************************
    void SetFuelStatus( KUINT8 F );
    KUINT8 GetFuelStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetMovementDirection
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetMovementDirectionHorizontal
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetMovementDirectionVertical
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetMovementDirectionHorizontal
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetMovementDirectionVertical
    // Description: Movement Direction is specified as a horizontal and a vertical deviation from
    //              the Entity Orientation.
    //              Each deviation is specified in 25 milliradian increments.
    // Parameter:   KINT8 Horizontal, KINT8 H, KINT8 V, void
    // Parameter:   KINT8 Vertical, void
    //************************************
    void SetMovementDirection( KINT8 Horizontal, KINT8 Vertical );
    void SetMovementDirectionHorizontal( KINT8 H );
    void SetMovementDirectionVertical( KINT8 V );
    KINT8 GetMovementDirectionHorizontal() const;
    KINT8 GetMovementDirectionVertical() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GED_BasicFixedWingAircraft & Value ) const;
    KBOOL operator != ( const GED_BasicFixedWingAircraft & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

