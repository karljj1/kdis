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
    class:      SEES_PDU
    DIS:        (6) 1278.1A - 1998
    created:    2009/01/15
    author:     Karl Jones

    purpose:    Supplemental Emission / Entity State (SEES)
                Contains infomation on an entitys physical state that
                is not contained within the Entity_State_PDU.
    size:       224 bits / 28 octets - Min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include <vector>
#include "./../../DataTypes/PropulsionSystem.h"
#include "./../../DataTypes/VectoringNozzleSystem.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::PropulsionSystem;
using KDIS::DATA_TYPE::VectoringNozzleSystem;
using std::vector;

class KDIS_EXPORT SEES_PDU : public Header
{
protected:

    EntityIdentifier m_OriginatingEntity;

    KUINT16 m_ui16IrSigRepIndex;

    KUINT16 m_ui16AcousticSigRepIndex;

    KUINT16 m_ui16CrossSection;

    KUINT16 m_ui16NumPropulsionSys;

    KUINT16 m_ui16NumVectoringNozzleSys;

    vector<PropulsionSystem> m_vPropSys;

    vector<VectoringNozzleSystem> m_vVecNozzleSys;

public:

    static const KUINT16 SEES_PDU_SIZE = 28; // Min size

    SEES_PDU( void );

    SEES_PDU( KDataStream & stream ) throw( KException );

    SEES_PDU( const EntityIdentifier & OriginatingEnt, KUINT16 IrSigIndex, KUINT16 AcousticSigIndex,
              KUINT16 RadarCrossSectionSigIndex );

    virtual ~SEES_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::SetOriginatingEntityID
    //              KDIS::PDU::SEES_PDU::GetOriginatingEntityID
    // Description: Entity that is the source of the information
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetOriginatingEntityID ( const EntityIdentifier & ID );
    const EntityIdentifier & GetOriginatingEntityID() const;
    EntityIdentifier & GetOriginatingEntityID();

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::SetInfraredSignatureRepresentationIndex
    //              KDIS::PDU::SEES_PDU::GetInfraredSignatureRepresentationIndex
    // Description: Represents an index to a specific value or an index pointer
    //              to a data table accessed with other information to obtain a specific value
    //              for the system state in which the entity is currently.
    // Parameter:   KUINT16 ISRI, void
    //************************************
    void SetInfraredSignatureRepresentationIndex( KUINT16 ISRI );
    KUINT16 GetInfraredSignatureRepresentationIndex() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::SetAcousticSignatureRepresentationIndex
    //              KDIS::PDU::SEES_PDU::GetAcousticSignatureRepresentationIndex
    // Description: Represents an index to a specific value or an index pointer
    //              to a data table accessed with other information to obtain a specific value
    //              for the system state in which the entity is currently.
    // Parameter:   KUINT16 ASRI, void
    //************************************
    void SetAcousticSignatureRepresentationIndex( KUINT16 ASRI );
    KUINT16 GetAcousticSignatureRepresentationIndex() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::SetRadarCrossSectionSignatureRepresentationIndex
    //              KDIS::PDU::SEES_PDU::GetRadarCrossSectionSignatureRepresentationIndex
    // Description: Represents an index to a specific value or an index pointer
    //              to a data table accessed with other information to obtain a specific value
    //              for the system state in which the entity is currently.
    // Parameter:   KUINT16 RCSSRI, void
    //************************************
    void SetRadarCrossSectionSignatureRepresentationIndex( KUINT16 RCSSRI );
    KUINT16 GetRadarCrossSectionSignatureRepresentationIndex() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::GetNumberOfPropulsionSystems
    // Description: Specifies the number of operational propulsion systems aboard the entity. one, several
    //              or all may be specified in a single SEES PDU.
    //************************************
    KUINT16 GetNumberOfPropulsionSystems() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::GetNumberOfVectoringNozzleSystems
    // Description: Specifies the number of operational vector nozzle systems aboard the entity. one, several
    //              or all may be specified in a single SEES PDU.
    //************************************
    KUINT16 GetNumberOfVectoringNozzleSystems() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::AddPropulsionSystem
    //              KDIS::PDU::SEES_PDU::SetPropulsionSystem
    //              KDIS::PDU::SEES_PDU::GetPropulsionSystem
    // Description: Entity propulsion system
    // Parameter:   const PropulsionSystem & PS, const vector<PropulsionSystem> & PS, void
    //************************************
    void AddPropulsionSystem( const PropulsionSystem & PS );
    void SetPropulsionSystem( const vector<PropulsionSystem> & PS );
    const vector<PropulsionSystem> GetPropulsionSystem() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::AddVectoringNozzleSystem
    //              KDIS::PDU::SEES_PDU::SetVectoringNozzleSystem
    //              KDIS::PDU::SEES_PDU::GetVectoringNozzleSystem
    // Description:
    // Parameter:   const VectoringNozzleSystem & VNS, const vector<VectoringNozzleSystem> & VNS, void
    //************************************
    void AddVectoringNozzleSystem( const VectoringNozzleSystem & VNS );
    void SetVectoringNozzleSystem( const vector<VectoringNozzleSystem> & VNS );
    const vector<VectoringNozzleSystem> GetVectoringNozzleSystem() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const SEES_PDU & Value ) const;
    KBOOL operator != ( const SEES_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
