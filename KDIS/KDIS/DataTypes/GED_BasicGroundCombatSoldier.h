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
    class:      GED_BasicGroundCombatSoldier
    created:    07:06:2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of basic ground combat soldiers.
    size:       160 bits / 20 octets
*********************************************************************/

#pragma once

#include "./GED.h"
#include "./EntityAppearance.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;

class KDIS_EXPORT GED_BasicGroundCombatSoldier : public GED
{
protected:

    KUINT16 m_ui16EntityID;

    KINT16 m_i16Offsets[3];

    EntityAppearance m_EA;

    KINT8 m_i8Ori[3];

    KINT8 m_i8Spd;

    KINT8 m_i8HdAz;

    KINT8 m_i8HdElv;

    KINT8 m_i8HdScanRt;

    KINT8 m_i8HdElvRt;

public:

    static const KUINT16 GED_BASIC_GROUND_COMBAT_SOLDIER_SIZE = 20;

    GED_BasicGroundCombatSoldier( void );

    GED_BasicGroundCombatSoldier( KDataStream & stream )throw( KException );

    GED_BasicGroundCombatSoldier( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA,
                                  KINT8 Psi, KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 HeadAzimuth, KINT8 HeadElevation,
                                  KINT8 HeadScanRate, KINT8 HeadElevationRate );

    virtual ~GED_BasicGroundCombatSoldier( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetEntityID
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetEntityID
    // Description: Entity identifier unique within the group.
    //              The Site Identifier and Application Identifiers shall be the same as
    //              those designated in the Group Entity ID field.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetEntityID( KUINT16 ID );
    KUINT16 GetEntityID() const;

    //************************************
    //              GetEntityLocationZOffset
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetEntityLocation
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetEntityLocationXOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetEntityLocationYOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetEntityLocationZOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetEntityLocationXOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetEntityLocationYOffset
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetEntityLocationZOffset
    // Description: Location of the grouped entity specified by a set of three offsets.
    //              Determined by the difference, in meters, of the grouped entity from the Group Reference Point.
    // Parameter:   KINT16, void
    //************************************
    void SetEntityLocation( KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset );
    void SetEntityLocation( KINT16 Offsets[3] );
    void SetEntityLocationXOffset( KINT16 X );
    void SetEntityLocationYOffset( KINT16 Y );
    void SetEntityLocationZOffset( KINT16 Z );
    KINT16 GetEntityLocationXOffset() const;
    KINT16 GetEntityLocationYOffset() const;
    KINT16 GetEntityLocationZOffset() const;

    //************************************
    // FullName:    KDIS::PDU::GED_BasicGroundCombatSoldier::SetEntityAppearance
    //              KDIS::PDU::GED_BasicGroundCombatSoldier::GetEntityAppearance
    // Description: Entity Appearance bit field accessors/mutator
    // Parameter:   const EntityAppearance & EA, void
    //************************************
    void SetEntityAppearance( const EntityAppearance & EA );
    const EntityAppearance & GetEntityAppearance() const;
    EntityAppearance & GetEntityAppearance();

    //************************************
    //              GetEntityOrientationPhi
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetEntityOrientation
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetEntityOrientationPsi
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetEntityOrientationTheta
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetEntityOrientationPhi
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetEntityOrientationPsi
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetEntityOrientationTheta
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetEntityOrientationPhi
    // Description: Entity Orientation in euler angles, psi, theta and phi, in 25 milliradian increments.
    // Parameter:   KINT8, void
    //************************************
    void SetEntityOrientation( KINT8 Psi, KINT8 Theta, KINT8 Phi );
    void SetEntityOrientation( KINT8 Ori[3] );
    void SetEntityOrientationPsi( KINT8 P );
    void SetEntityOrientationTheta( KINT8 T );
    void SetEntityOrientationPhi( KINT8 P );
    KINT8 GetEntityOrientationPsi() const;
    KINT8 GetEntityOrientationTheta() const;
    KINT8 GetEntityOrientationPhi() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetSpeed
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetSpeed
    // Description: Signed magnitude value of the entity’s absolute velocity vector.
    //              A negative value shall indicate that the entity is moving backwards.
    //              Measured in Meters Per Secound (m/s).
    // Parameter:   KINT8 S, void
    //************************************
    void SetSpeed( KINT8 S );
    KINT8 GetSpeed() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetHeadAzimuth
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetHeadAzimuth
    // Description: Head azimuth specified in 25 milliradian increments.
    // Parameter:   KINT8 T, void
    //************************************
    void SetHeadAzimuth( KINT8 H );
    KINT8 GetHeadAzimuth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetHeadElevation
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetHeadElevation
    // Description: Head elevation specified in 25 milliradian increments.
    // Parameter:   KINT8 G, void
    //************************************
    void SetHeadElevation( KINT8 H );
    KINT8 GetHeadElevation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetHeadScanRate
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetHeadScanRate
    // Description: Head scan rate specified in 25 milliradian per secound increments.
    // Parameter:   KINT8 T, void
    //************************************
    void SetHeadScanRate( KINT8 T );
    KINT8 GetHeadScanRate() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::SetHeadElevationRate
    //              KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetHeadElevationRate
    // Description: Head Elevation Rate specified in 25 milliradian per secound increments.
    // Parameter:   KINT8 H, void
    //************************************
    void SetHeadElevationRate( KINT8 H );
    KINT8 GetHeadElevationRate() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_BasicGroundCombatSoldier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GED_BasicGroundCombatSoldier & Value ) const;
    KBOOL operator != ( const GED_BasicGroundCombatSoldier & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

