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

class KDIS_EXPORT GED_BasicRotorWingAircraft : public GED_BasicFixedWingAircraft
{
protected:

    KINT8 m_i8TrrtAz;

    KINT8 m_i8GnElv;

    KINT8 m_i8TrrtSlwRt;

    KINT8 m_i8GnElvRt;

public:

    static const KUINT16 GED_BASIC_ROTOR_WING_AIRCRAFT_SIZE = 24;

    GED_BasicRotorWingAircraft();

    GED_BasicRotorWingAircraft( KDataStream & stream )throw( KException );

    GED_BasicRotorWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi,
                                KINT8 Theta, KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation,
                                KINT16 Speed, KINT8 TurretAzimuth, KINT8 GunElevation, KINT8 TurretSlewRate, KINT8 GunElevationRate );

    virtual ~GED_BasicRotorWingAircraft();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicRotorWingAircraft::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GetGroupedEntityCategory() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS

