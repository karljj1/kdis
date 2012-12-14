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
    class:      Underwater_Acoustic_PDU
    DIS:        (6) 1278.1A - 1998
    created:    2008/10/19
    author:     Karl Jones

    purpose:    Contains infomation about under water acoustic emissions
    Size:       272 bits / 34 octets - min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/EmissionSystem.h"
#include "./../../DataTypes/Shaft.h"
#include "./../../DataTypes/APA.h"
#include "./../../DataTypes/UnderwaterAcousticEmitterSystem.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::Shaft;
using KDIS::DATA_TYPE::APA;
using KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem;
using KDIS::DATA_TYPE::ENUMS::StateUpdateIndicator;
using KDIS::DATA_TYPE::ENUMS::PassiveParameterIndex;
using KDIS::DATA_TYPE::ENUMS::PropulsionPlantConfiguration;
using std::vector;

class KDIS_EXPORT Underwater_Acoustic_PDU : public Header
{
protected:

    EntityIdentifier m_EmittingEntityID;

    EntityIdentifier m_EventID;

    KUINT8 m_ui8StateUpdateIndicator;

    KUINT8 m_ui8Padding1;

    KUINT16 m_ui16PassiveParamIndex;

    KUINT8 m_ui8PropPlantConfig;

    KUINT8 m_ui8NumShafts;

    KUINT8 m_ui8NumAPA;

    KUINT8 m_ui8NumEmitterSys;

    vector<Shaft> m_vShafts;

    vector<APA> m_vAPA;

    vector<UnderwaterAcousticEmitterSystem> m_vUAES;

public:

    static const KUINT16 UNDERWATER_ACOUSTIC_PDU_SIZE = 34; // Min Size

    Underwater_Acoustic_PDU( void );

    Underwater_Acoustic_PDU( KDataStream & stream ) throw( KException );

    virtual ~Underwater_Acoustic_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::SetEmittingEntityID
    //              KDIS::PDU::Underwater_Acoustic_PDU::GetEmittingEntityID
    // Description: Emitting Entity ID
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEmittingEntityID ( const EntityIdentifier & ID );
    const EntityIdentifier & GetEmittingEntityID() const;
    EntityIdentifier & GetEmittingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::SetEventID
    //              KDIS::PDU::Underwater_Acoustic_PDU::GetEventID
    // Description: Event ID. For associated events.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEventID( const EntityIdentifier & ID );
    const EntityIdentifier & GetEventID() const;
    EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::SetStateUpdateIndicator
    //              KDIS::PDU::Underwater_Acoustic_PDU::GetStateUpdateIndicator
    // Description: Indicates if the data contained in the PDU represents a state update or
    //              just data that has changed since issuance of the last Electromagnetic Emission
    //              PDU.
    // Parameter:   StateUpdateIndicator SUI, void
    //************************************
    void SetStateUpdateIndicator( StateUpdateIndicator SUI );
    StateUpdateIndicator GetStateUpdateIndicator() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::SetPassiveParameterIndex
    //              KDIS::PDU::Underwater_Acoustic_PDU::GetPassiveParameterIndex
    // Description: Indicates which database record ( or file ) shall
    //              be used in the definition of passive signature (unintentional)
    //              emissions of the entity. The indicated record/file shall
    //              define all noise generated as a function of propulsion plant
    //              configuration and associated auxiliaries.
    //              E.G parameter indexex identifying a file in a common
    //              acoustic database (CADB) would be used here.
    // Parameter:   PassiveParameterIndex PPI, void
    //************************************
    void SetPassiveParameterIndex( PassiveParameterIndex PPI );
    PassiveParameterIndex GetPassiveParameterIndex() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::SetPropulsionPlantConfiguration
    //              KDIS::PDU::Underwater_Acoustic_PDU::GetPropulsionPlantConfiguration
    // Description: Used to determine the passive signature
    //              characteristics of an entity
    // Parameter:   PropulsionPlantConfiguration PPC, void
    //************************************
    void SetPropulsionPlantConfiguration( PropulsionPlantConfiguration PPC );
    PropulsionPlantConfiguration GetPropulsionPlantConfiguration() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::GetNumberOfShafts
    // Description: Returns number of shafts on platform
    //************************************
    KUINT8 GetNumberOfShafts() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::GetNumberOfAPA
    // Description: Returns number of APA.
    //************************************
    KUINT8 GetNumberOfAPA() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::GetNumberOfUAEmitterSystems
    // Description: Returns number of UA emitter systems.
    //************************************
    KUINT8 GetNumberOfUAEmitterSystems() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::AddShaft
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::SetShafts
    //              KDIS::PDU::Underwater_Acoustic_PDU::GetShafts
    // Description: Shafts belonging to the platform.
    // Parameter:   const vector<Shaft> & S, void
    //************************************
    void AddShaft( const Shaft & S );
    void SetShafts( const vector<Shaft> & S );
    const vector<Shaft> & GetShafts() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::AddAPA
    //              KDIS::PDU::Underwater_Acoustic_PDU::SetAPA
    //              KDIS::PDU::Underwater_Acoustic_PDU::GetAPA
    // Description: Additional Passive Activity ( APA )
    // Parameter:   const APA & A, const vector<APA> & A, void
    //************************************
    void AddAPA( const APA & A );
    void SetAPA( const vector<APA> & A );
    const vector<APA> & GetAPA() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::AddUnderwaterAcousticEmitterSystem
    //              KDIS::PDU::Underwater_Acoustic_PDU::SetUnderwaterAcousticEmitterSystem
    //              KDIS::PDU::Underwater_Acoustic_PDU::GetUnderwaterAcousticEmitterSystem
    // Description: Adds a system to the platform.
    // Parameter:   const UnderwaterAcousticEmitterSystem & UAES, const vector<UnderwaterAcousticEmitterSystem> & UAES, void
    //************************************
    void AddUnderwaterAcousticEmitterSystem( const UnderwaterAcousticEmitterSystem & UAES );
    void SetUnderwaterAcousticEmitterSystem( const vector<UnderwaterAcousticEmitterSystem> & UAES );
    const vector<UnderwaterAcousticEmitterSystem> & GetUnderwaterAcousticEmitterSystem() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Underwater_Acoustic_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Underwater_Acoustic_PDU & Value ) const;
    KBOOL operator != ( const Underwater_Acoustic_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
