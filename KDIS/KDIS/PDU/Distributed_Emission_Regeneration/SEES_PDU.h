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

class KDIS_EXPORT SEES_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_OriginatingEntity;

    KUINT16 m_ui16IrSigRepIndex;

    KUINT16 m_ui16AcousticSigRepIndex;

    KUINT16 m_ui16CrossSection;

    KUINT16 m_ui16NumPropulsionSys;

    KUINT16 m_ui16NumVectoringNozzleSys;

	std::vector<KDIS::DATA_TYPE::PropulsionSystem> m_vPropSys;

	std::vector<KDIS::DATA_TYPE::VectoringNozzleSystem> m_vVecNozzleSys;

public:

    static const KUINT16 SEES_PDU_SIZE = 28; // Min size

    SEES_PDU();

    SEES_PDU( KDataStream & stream ) throw( KException );

	SEES_PDU( const Header & H, KDataStream & stream ) throw( KException );

    SEES_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEnt, KUINT16 IrSigIndex, 
		      KUINT16 AcousticSigIndex, KUINT16 RadarCrossSectionSigIndex );

    virtual ~SEES_PDU();

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::SetOriginatingEntityID
    //              KDIS::PDU::SEES_PDU::GetOriginatingEntityID
    // Description: Entity that is the source of the information
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetOriginatingEntityID ( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetOriginatingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetOriginatingEntityID();

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::SetInfraredSignatureRepresentationIndex
    //              KDIS::PDU::SEES_PDU::GetInfraredSignatureRepresentationIndex
    // Description: Represents an index to a specific value or an index pointer
    //              to a data table accessed with other information to obtain a specific value
    //              for the system state in which the entity is currently.
    // Parameter:   KUINT16 ISRI
    //************************************
    void SetInfraredSignatureRepresentationIndex( KUINT16 ISRI );
    KUINT16 GetInfraredSignatureRepresentationIndex() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::SetAcousticSignatureRepresentationIndex
    //              KDIS::PDU::SEES_PDU::GetAcousticSignatureRepresentationIndex
    // Description: Represents an index to a specific value or an index pointer
    //              to a data table accessed with other information to obtain a specific value
    //              for the system state in which the entity is currently.
    // Parameter:   KUINT16 ASRI
    //************************************
    void SetAcousticSignatureRepresentationIndex( KUINT16 ASRI );
    KUINT16 GetAcousticSignatureRepresentationIndex() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::SetRadarCrossSectionSignatureRepresentationIndex
    //              KDIS::PDU::SEES_PDU::GetRadarCrossSectionSignatureRepresentationIndex
    // Description: Represents an index to a specific value or an index pointer
    //              to a data table accessed with other information to obtain a specific value
    //              for the system state in which the entity is currently.
    // Parameter:   KUINT16 RCSSRI
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
    // Parameter:   const PropulsionSystem & PS, const vector<PropulsionSystem> & PS
    //************************************
    void AddPropulsionSystem( const KDIS::DATA_TYPE::PropulsionSystem & PS );
	void SetPropulsionSystem( const std::vector<KDIS::DATA_TYPE::PropulsionSystem> & PS );
	const std::vector<KDIS::DATA_TYPE::PropulsionSystem> GetPropulsionSystem() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::AddVectoringNozzleSystem
    //              KDIS::PDU::SEES_PDU::SetVectoringNozzleSystem
    //              KDIS::PDU::SEES_PDU::GetVectoringNozzleSystem
    // Description:
    // Parameter:   const VectoringNozzleSystem & VNS, const vector<VectoringNozzleSystem> & VNS
    //************************************
    void AddVectoringNozzleSystem( const KDIS::DATA_TYPE::VectoringNozzleSystem & VNS );
	void SetVectoringNozzleSystem( const std::vector<KDIS::DATA_TYPE::VectoringNozzleSystem> & VNS );
	const std::vector<KDIS::DATA_TYPE::VectoringNozzleSystem> GetVectoringNozzleSystem() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::SEES_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const SEES_PDU & Value ) const;
    KBOOL operator != ( const SEES_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
