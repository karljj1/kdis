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
    class:      Designator_PDU
    DIS:        (5) 1278.1 - 1995 & (7) 1278.1 - 200x draft 14
    created:    2008/10/21
    author:     Karl Jones

    purpose:    Communicates designating operations.
                E.G a laser designator for targeting.
    size:       704 bits / 88 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/WorldCoordinates.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::Vector;
using KDIS::DATA_TYPE::WorldCoordinates;
using KDIS::DATA_TYPE::ENUMS::DesignatorCode;
using KDIS::DATA_TYPE::ENUMS::DesignatorCodeName;
using KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm;

class KDIS_EXPORT Designator_PDU : public Header
{
protected:

    EntityIdentifier m_DesignatingEntityID;

    KUINT16 m_ui16CodeName;

    EntityIdentifier m_DesignatedEntityID;

    KUINT16 m_ui16Code;

    KFLOAT32 m_f32Power;

    KFLOAT32 m_f32WaveLength;

    Vector m_SpotRegardsToEntity;

    WorldCoordinates m_SpotLocation;

    KUINT8 m_ui8DeadReckoningAlgorithm;

    KUINT16 m_ui16Padding1;

    KUINT8 m_ui8Padding2;

    Vector m_EntityLinearAcceleration;

public:

    static const KUINT16 DESIGNATOR_PDU_SIZE = 88;

    Designator_PDU( void );

    Designator_PDU( KDataStream & stream ) throw( KException );

    Designator_PDU( const EntityIdentifier & DesignatingEntityID, DesignatorCodeName CodeName,
                    const EntityIdentifier & DesignatedEntityID, DesignatorCode Code, KFLOAT32 Power,
                    KFLOAT32 WaveLength, const Vector & SpotLocationRegardsToEntity,
                    const WorldCoordinates & SpotLocation, DeadReckoningAlgorithm DRA,
                    const Vector & EntityLinearAcceleration );

    virtual ~Designator_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetDesignatingEntityID
    //              KDIS::PDU::Designator_PDU::GetDesignatingEntityID
    // Description: Entity that is positioning the designator.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetDesignatingEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetDesignatingEntityID() const;
    EntityIdentifier & GetDesignatingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetDesignatorCodeName
    //              KDIS::PDU::Designator_PDU::GetDesignatorCodeName
    // Description: Code name for designator
    // Parameter:   DesignatorCodeName CN, void
    //************************************
    void SetDesignatorCodeName( DesignatorCodeName CN );
    DesignatorCodeName GetDesignatorCodeName() const;

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetDesignatedEntityID
    //              KDIS::PDU::Designator_PDU::GetDesignatedEntityID
    // Description: Object that is being designated, if not an entity
    //              the value shall be set to the symbolic name: D_SPOT_NO_ENTITY
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetDesignatedEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetDesignatedEntityID() const;
    EntityIdentifier & GetDesignatedEntityID();

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetDesignatorCode
    //              KDIS::PDU::Designator_PDU::GetDesignatorCode
    // Description: Code used by designator
    // Parameter:   DesignatorCode C, void
    //************************************
    void SetDesignatorCode( DesignatorCode C );
    DesignatorCode GetDesignatorCode() const;

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetDesignatingPower
    //              KDIS::PDU::Designator_PDU::GetDesignatingPower
    // Description: Output power in Watts
    // Parameter:   KFLOAT32 DP, void
    //************************************
    void SetDesignatingPower( KFLOAT32 DP );
    KFLOAT32 GetDesignatingPower() const;

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetDesignatingWaveLength
    //              KDIS::PDU::Designator_PDU::GetDesignatingWaveLength
    // Description: Wave Length in units of microns
    // Parameter:   KFLOAT32 WL, void
    //************************************
    void SetDesignatingWaveLength( KFLOAT32 WL );
    KFLOAT32 GetDesignatingWaveLength() const;

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetDesignatorSpotRespectToDesignatedEntity
    //              KDIS::PDU::Designator_PDU::GetDesignatorSpotRespectToDesignatedEntity
    // Description: Location of the designator spot with regards to the
    //              designated entity coordinate system. If the designated
    //              object is not an entity (I.E the Designated Entity ID contains
    //              the symbolic value D_SPOT_NO_ENTITY) then the field shall contain
    //              [0.0, 0.0, 0.0]. Represented as Entity Coordinate Vector
    // Parameter:   const Vector & DPL, void
    //************************************
    void SetDesignatorSpotRespectToDesignatedEntity( const Vector & DPL );
    const Vector & GetDesignatorSpotRespectToDesignatedEntity() const;
    Vector & GetDesignatorSpotRespectToDesignatedEntity();

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetSpotLocation
    //              KDIS::PDU::Designator_PDU::GetSpotLocation
    // Description: Location of designator spot in world coordinates
    // Parameter:   const WorldCoordinates & SL, void
    //************************************
    void SetSpotLocation( const WorldCoordinates & SL );
    const WorldCoordinates & GetSpotLocation() const;
    WorldCoordinates & GetSpotLocation();

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetDeadReckoningAlgorithm
    //              KDIS::PDU::Designator_PDU::GetDeadReckoningAlgorithm
    // Description: Used for dead reckoning the designator spot, also uses
    //              entity linear acceleration in order to perform the dead
    //              reckoning task.
    // Parameter:   const WorldCoordinates & SL, void
    //************************************
    void SetDeadReckoningAlgorithm( DeadReckoningAlgorithm DRA );
    DeadReckoningAlgorithm GetDeadReckoningAlgorithm() const;

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::SetEntityLinearAcceleration
    //              KDIS::PDU::Designator_PDU::GetEntityLinearAcceleration
    // Description: Entity Linear Acceleration. Represented as Linear Acceleration Vector.
    // Parameter:   const Vector & ELA, void
    //************************************
    void SetEntityLinearAcceleration( const Vector & ELA );
    const Vector & GetEntityLinearAcceleration() const;
    Vector & GetEntityLinearAcceleration();

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Designator_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Designator_PDU & Value ) const;
    KBOOL operator != ( const Designator_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
