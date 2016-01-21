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
    class:      GED_BasicFixedWingAircraft
    updated:    21/012016
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of basic fixed wing aircraft.
    size:       160 bits / 20 octets
*********************************************************************/

#pragma once

#include "./GED.h"
#include "./EntityAppearance.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GED_BasicFixedWingAircraft : public GED
{
protected:

    KUINT16 m_ui16EntityID;

    KINT16 m_i16Offsets[3];

    EntityAppearance m_EA;

    KINT8 m_i8Ori[3];

    KUINT8 m_ui8FuelStatus;

    KINT8 m_i8HoriDevi;

    KINT8 m_i8VertDevi;

    KINT16 m_i16Spd;

public:

    static const KUINT16 GED_BASIC_FIXED_WING_AIRCRAFT_SIZE = 20;

    GED_BasicFixedWingAircraft();

    GED_BasicFixedWingAircraft( KDataStream & stream )throw( KException );

    GED_BasicFixedWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi, KINT8 Theta,
                                KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation, KINT16 Speed );

    virtual ~GED_BasicFixedWingAircraft();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;


    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityID
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetEntityID
    // Description: Entity identifier unique within the group.
    //              The Site Identifier and Application Identifiers shall be the same as
    //              those designated in the Group Entity ID field.
    // Parameter:   KUINT16 ID
    //************************************
    void SetEntityID(KUINT16 ID);
    KUINT16 GetEntityID() const;

    //************************************
    //              GetEntityLocationZOffset
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityLocation
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityLocationXOffset
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityLocationYOffset
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityLocationZOffset
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetEntityLocationXOffset
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetEntityLocationYOffset
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetEntityLocationZOffset
    // Description: Location of the grouped entity specified by a set of three offsets.
    //              Determined by the difference, in meters, of the grouped entity from the Group Reference Point.
    // Parameter:   KINT16
    //************************************
    void SetEntityLocation(KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset);
    void SetEntityLocation(KINT16 Offsets[3]);
    void SetEntityLocationXOffset(KINT16 X);
    void SetEntityLocationYOffset(KINT16 Y);
    void SetEntityLocationZOffset(KINT16 Z);
    KINT16 GetEntityLocationXOffset() const;
    KINT16 GetEntityLocationYOffset() const;
    KINT16 GetEntityLocationZOffset() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityAppearance
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetEntityAppearance
    // Description: Entity appearance bit field accessors/mutator
    // Parameter:   const EntityAppearance & EA
    //************************************
    void SetEntityAppearance(const EntityAppearance & EA);
    const EntityAppearance & GetEntityAppearance() const;
    EntityAppearance & GetEntityAppearance();

    //************************************
    //              GetEntityOrientationPhi
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityOrientation
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityOrientationPsi
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityOrientationTheta
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetEntityOrientationPhi
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetEntityOrientationPsi
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetEntityOrientationTheta
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetEntityOrientationPhi
    // Description: Entity orientation in Euler angles, psi, theta and phi, in 25 milli radian increments.
    // Parameter:   KINT8
    //************************************
    void SetEntityOrientation(KINT8 Psi, KINT8 Theta, KINT8 Phi);
    void SetEntityOrientation(KINT8 Ori[3]);
    void SetEntityOrientationPsi(KINT8 P);
    void SetEntityOrientationTheta(KINT8 T);
    void SetEntityOrientationPhi(KINT8 P);
    KINT8 GetEntityOrientationPsi() const;
    KINT8 GetEntityOrientationTheta() const;
    KINT8 GetEntityOrientationPhi() const;

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
    // FullName:    KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::SetSpeed
    //              KDIS::DATA_TYPE::GED_BasicFixedWingAircraft::GetSpeed
    // Description: Signed magnitude value of the entity’s absolute velocity vector.
    //              A negative value shall indicate that the entity is moving backwards.
    //              Specified in 0.1 meter per second increments for aircraft and meters
    //              per second for ground vehicles.
    // Parameter:   KINT16 S
    //************************************
    void SetSpeed(KINT16 S);
    KINT16 GetSpeed() const;

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

