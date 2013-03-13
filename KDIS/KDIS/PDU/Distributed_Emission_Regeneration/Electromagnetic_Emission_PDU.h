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
    class:      Electromagnetic_Emission_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/10/19
    author:     Karl Jones

    purpose:    Contains infomation about electronic warfare (EW) emissions and
                active EW countermeasure.

    Size:       224 bits / 28 octets - min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/EmissionSystem.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::EmissionSystem;
using KDIS::DATA_TYPE::ENUMS::StateUpdateIndicator;
using std::vector;

class KDIS_EXPORT Electromagnetic_Emission_PDU : public Header
{
protected:

    EntityIdentifier m_EmittingEntityID;

    EntityIdentifier m_EventID;

    KUINT8 m_ui8StateUpdateIndicator;

    KUINT8 m_ui8NumberOfEmissionSystems;

    KUINT16 m_ui16Padding;

    vector<EmissionSystem> m_vEmissionSystem;

public:

    static const KUINT16 ELECTROMAGNETIC_EMISSION_PDU_SIZE = 28; // Min Size

    Electromagnetic_Emission_PDU();

    Electromagnetic_Emission_PDU( KDataStream & stream ) throw( KException );

	Electromagnetic_Emission_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Electromagnetic_Emission_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID,
                                  StateUpdateIndicator SUI );

    Electromagnetic_Emission_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID,
                                  StateUpdateIndicator SUI, const vector<EmissionSystem> & EmissionSystems );

    virtual ~Electromagnetic_Emission_PDU();

    //************************************
    // FullName:    KDIS::PDU::Electromagnetic_Emission_PDU::SetEmittingEntityID
    //              KDIS::PDU::Electromagnetic_Emission_PDU::GetEmittingEntityID
    // Description: Emitting Entity ID
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEmittingEntityID ( const EntityIdentifier & ID );
    const EntityIdentifier & GetEmittingEntityID() const;
    EntityIdentifier & GetEmittingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Electromagnetic_Emission_PDU::SetEventID
    //              KDIS::PDU::Electromagnetic_Emission_PDU::GetEventID
    // Description: Event ID. For associated events.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEventID( const EntityIdentifier & ID );
    const EntityIdentifier & GetEventID() const;
    EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::Electromagnetic_Emission_PDU::SetStateUpdateIndicator
    //              KDIS::PDU::Electromagnetic_Emission_PDU::GetStateUpdateIndicator
    // Description: Indicates if the data contained in the PDU represents a state update or
    //              just data that has changed since issuance of the last Electromagnetic Emission
    //              PDU.
    // Parameter:   StateUpdateIndicator SUI, void
    //************************************
    void SetStateUpdateIndicator( StateUpdateIndicator SUI );
    StateUpdateIndicator GetStateUpdateIndicator() const;

    //************************************
    // FullName:    KDIS::PDU::Electromagnetic_Emission_PDU::GetNumberOfEmissionSystems
    // Description: Returns number of emission system records
    //************************************
    KUINT8 GetNumberOfEmissionSystems() const;

    //************************************
    // FullName:    KDIS::PDU::Electromagnetic_Emission_PDU::AddEmissionSystem
    //              KDIS::PDU::Electromagnetic_Emission_PDU::SetEmissionSystem
    //              KDIS::PDU::Electromagnetic_Emission_PDU::GetEmissionSystems
    //              KDIS::PDU::Electromagnetic_Emission_PDU::ClearEmissionSystem
    // Description: Emissions systems belonging to the electromagnetic emission PDU.
    // Parameter:   const EmissionSystem & ES, const vector<EmissionSystem> & ES
    //************************************
    void AddEmissionSystem( const EmissionSystem & ES );
    void SetEmissionSystem( const vector<EmissionSystem> & ES );
    const vector<EmissionSystem> & GetEmissionSystems() const;
    void ClearEmissionSystem();

    //************************************
    // FullName:    KDIS::PDU::Electromagnetic_Emission_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Electromagnetic_Emission_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Electromagnetic_Emission_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Electromagnetic_Emission_PDU & Value ) const;
    KBOOL operator != ( const Electromagnetic_Emission_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
