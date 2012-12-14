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
    class:      GED_GroundLogisticsVehicle
    created:    24:06:2009
    author:     Karl Jones

    purpose:    Contains entity state information about an individual entity
                within a group of ground logistics vehicles.
    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./GED.h"
#include "./EntityAppearance.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;

class KDIS_EXPORT GED_GroundLogisticsVehicle : public GED
{
protected:

    KUINT16 m_ui16EntityID;

    KINT16 m_i16Offsets[3];

    EntityAppearance m_EA;

    KINT8 m_i8Ori[3];

    KINT8 m_i8Spd;

public:

    static const KUINT16 GED_GROUND_LOGISTICS_VEHICLE_SIZE = 16;

    GED_GroundLogisticsVehicle( void );

    GED_GroundLogisticsVehicle( KDataStream & stream )throw( KException );

    GED_GroundLogisticsVehicle( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA,
                                KINT8 Psi, KINT8 Theta, KINT8 Phi, KINT8 Speed );

    virtual ~GED_GroundLogisticsVehicle( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityID
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetEntityID
    // Description: Entity identifier unique within the group.
    //              The Site Identifier and Application Identifiers shall be the same as
    //              those designated in the Group Entity ID field.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetEntityID( KUINT16 ID );
    KUINT16 GetEntityID() const;

    //************************************
    //              GetEntityLocationZOffset
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityLocation
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityLocationXOffset
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityLocationYOffset
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityLocationZOffset
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetEntityLocationXOffset
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetEntityLocationYOffset
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetEntityLocationZOffset
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
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityAppearance
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetEntityAppearance
    // Description: Entity appearance bit field accessors/mutator
    // Parameter:   const EntityAppearance & EA, void
    //************************************
    void SetEntityAppearance( const EntityAppearance & EA );
    const EntityAppearance & GetEntityAppearance() const;
    EntityAppearance & GetEntityAppearance();

    //************************************
    //              GetEntityOrientationPhi
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityOrientation
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityOrientationPsi
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityOrientationTheta
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetEntityOrientationPhi
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetEntityOrientationPsi
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetEntityOrientationTheta
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetEntityOrientationPhi
    // Description: Entity orientation in Euler angles, psi, theta and phi, in 25 milli radian increments.
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
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::SetSpeed
    //              KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetSpeed
    // Description: Signed magnitude value of the entity’s absolute velocity vector.
    //              A negative value shall indicate that the entity is moving backwards.
    //              Specified in 0.1 meter per second increments for aircraft and meters
    //              per second for ground vehicles.
    // Parameter:   KINT8 S, void
    //************************************
    void SetSpeed( KINT8 S );
    KINT8 GetSpeed() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED_GroundLogisticsVehicle::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GED_GroundLogisticsVehicle & Value ) const;
    KBOOL operator != ( const GED_GroundLogisticsVehicle & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

