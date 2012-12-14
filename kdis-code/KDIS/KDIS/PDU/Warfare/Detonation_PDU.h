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
    class:      Detonation_PDU
    DIS:        (5) 1278.1 - 1995
    updated:    31/03/2010
    author:     Karl Jones

    purpose:    Communicates detonation or impact of munitions.
    Size:       832 bits / 104 octets + 128n / 16n
*********************************************************************/

#pragma once

#include "./Warfare_Header.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/BurstDescriptor.h"
#include "./../../DataTypes/ArticulationParameters.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::Vector;
using KDIS::DATA_TYPE::WorldCoordinates;
using KDIS::DATA_TYPE::BurstDescriptor;
using KDIS::DATA_TYPE::ArticulationParameters;
using KDIS::DATA_TYPE::ENUMS::DetonationResult;

#if DIS_VERSION > 6
using KDIS::DATA_TYPE::ENUMS::DetonationType;
#endif

using std::vector;

class KDIS_EXPORT Detonation_PDU : public Warfare_Header
{
protected:

    Vector m_Velocity;

    WorldCoordinates m_LocationWorldCoords;

    BurstDescriptor m_BurstDescriptor;

    Vector m_LocationEntityCoords;

    KUINT8 m_ui8DetonationResult;

    KUINT8 m_ui8NumOfArticulationParams;

    KUINT16 m_ui16Padding1;

    vector<ArticulationParameters> m_vArticulationParameters;

public:

    static const KUINT16 DETONATION_PDU_SIZE = 104;

    Detonation_PDU( void );

    Detonation_PDU( KDataStream & stream ) throw( KException );

    Detonation_PDU( const EntityIdentifier & FiringEntID, const EntityIdentifier & TargetEntID,
                    const EntityIdentifier & MunitionID, const EntityIdentifier & EventID,
                    const Vector & Velocity, const WorldCoordinates & LocationWorldCoords,
                    const BurstDescriptor & Burst, const Vector & LocationEntityCoords,
                    DetonationResult DetonationResult );

    Detonation_PDU( const Warfare_Header & WarfareHeader, const Vector & Velocity,
                    const WorldCoordinates & LocationWorldCoords, const BurstDescriptor & Burst ,
                    const Vector & LocationEntityCoords, DetonationResult DetonationResult );

    virtual ~Detonation_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetVelocity
    //              KDIS::PDU::Detonation_PDU::GetVelocity
    // Description: Velocity of fire munition.
    // Parameter:   const Vector & V, void
    //************************************
    void SetVelocity( const Vector & V );
    const Vector & GetVelocity() const;
    Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetLocationInWorldCoords
    //              KDIS::PDU::Detonation_PDU::GetLocationInWorldCoords
    // Description: Location of detonation event in world
    //              coordinates.
    // Parameter:   const WorldCoordinates & L, void
    //************************************
    void SetLocationInWorldCoords( const WorldCoordinates & L );
    const WorldCoordinates & GetLocationInWorldCoords() const;
    WorldCoordinates & GetLocationInWorldCoords();

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetBurstDescriptor
    //              KDIS::PDU::Detonation_PDU::GetBurstDescriptor
    // Description: Burst descriptor, describes type of munition.
    // Parameter:   const BurstDescriptor & BD, void
    //************************************
    void SetBurstDescriptor( const BurstDescriptor & BD );
    const BurstDescriptor & GetBurstDescriptor() const;
    BurstDescriptor & GetBurstDescriptor();

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetLocationInEntityCoords
    //              KDIS::PDU::Detonation_PDU::GetLocationInEntityCoords
    // Description: Location of detonation event in entity coordinates.
    //              Use for damage assessment to the entity.
    // Parameter:   const Vector & L
    //************************************
    void SetLocationInEntityCoords( const Vector & L );
    const Vector & GetLocationInEntityCoords() const;
    Vector & GetLocationInEntityCoords();

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetDetonationResult
    //              KDIS::PDU::Detonation_PDU::GetDetonationResult
    // Description: Represents the result of the detonation.
    // Parameter:   DetonationResult DR
    //************************************
    void SetDetonationResult( DetonationResult DR );
    DetonationResult GetDetonationResult() const;

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::GetNumberOfArticulationParams
    // Description: Number of articulation parameters
    //************************************
    KUINT8 GetNumberOfArticulationParams() const;

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::AddArticulationParameter
    //              KDIS::PDU::Detonation_PDU::GetArticulationParameters
    // Description: Add a articulation parameter / Get vector or params
    //              Adding will update the Number Of Articulation Params
    //              field.
    // Parameter:   const ArticulationParameters & AP, const vector<ArticulationParameters> & AP
    //************************************
    void AddArticulationParameter( const ArticulationParameters & AP );
    void SetArticulationParameter( const vector<ArticulationParameters> & AP );
    const vector<ArticulationParameters> & GetArticulationParameters() const;

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Detonation_PDU & Value ) const;
    KBOOL operator != ( const Detonation_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
