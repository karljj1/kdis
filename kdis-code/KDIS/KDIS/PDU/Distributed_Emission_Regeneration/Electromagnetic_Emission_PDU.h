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

    Electromagnetic_Emission_PDU( void );

    Electromagnetic_Emission_PDU( KDataStream & stream ) throw( KException );

    Electromagnetic_Emission_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID,
                                  StateUpdateIndicator SUI );

    Electromagnetic_Emission_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID,
                                  StateUpdateIndicator SUI, const vector<EmissionSystem> & EmissionSystems );

    virtual ~Electromagnetic_Emission_PDU( void );

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
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
