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
    class:      IFF_PDU
    DIS:        (6) 1278.1A - 1998 & (7) 1278.1-2012
    updated:    20/09/2013
    author:     Karl Jones

    purpose:    Identification Friend or Foe (IFF) PDU Layer 1.
				Additional layers shall contain the following types of data:

						  // DIS 6 //

				Layer 1  - basic system data. Always included. 

                Layer 2 - This layer is used for basic emissions data when required to support
				          simulations that need detailed IFF electromagnetic characteristics.
						  The field formats of the two Operational Parameter fields and the 
						  System-Specific Data field may vary depending on the system type.

						  // DIS 7 //

				Layers 3 - Mode 5 formats. The military Mode 5 system is the only system that currently uses Layer 3.

				Layers 4 - Mode S formats. The civilian Mode S system is the only system that currently uses Layer 4.

				Layers 5 - data communications. Optional layer. This layer is used to extend a layer that does 
						   not have a standard variable record section (i.e., Layers1 and 2) and to support the
						   emulation of real-world transponder and interrogator data link messages.

                Layers 6 & 7 - Not defined. Reserved for future use.

    Size:       480 bits / 60 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/SystemIdentifier.h"
#include "./../../DataTypes/FundamentalOperationalData.h"

// Layers
#include <vector>
#include "./../../DataTypes/LayerHeader.h"
#include "./../../DataTypes/IFF_Layer2.h" 

#if DIS_VERSION > 6
#include "./../../DataTypes/IFF_Layer3Interrogator.h"
#include "./../../DataTypes/IFF_Layer3Transponder.h"
#endif

namespace KDIS {
namespace PDU {

class KDIS_EXPORT IFF_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_EmittingEntityID;

    KDIS::DATA_TYPE::EntityIdentifier m_EventID;

    KDIS::DATA_TYPE::Vector m_Location;

    KDIS::DATA_TYPE::SystemIdentifier m_SystemID;

	KUINT8 m_ui8SystemDesignator; // DIS 7

	KUINT8 m_ui8SystemSpecific; // DIS 7

    KDIS::DATA_TYPE::FundamentalOperationalData m_FOD;

	std::vector<KDIS::DATA_TYPE::LyrHdrPtr> m_vLayers;

public:

    static const KUINT16 IFF_PDU_SIZE = 60;

    IFF_PDU();

	IFF_PDU( const Header & H );

    IFF_PDU( KDataStream & stream ) throw( KException );

	IFF_PDU( const Header & H, KDataStream & stream ) throw( KException );

    IFF_PDU( const KDIS::DATA_TYPE::EntityIdentifier & EmittingID, const KDIS::DATA_TYPE::EntityIdentifier & EventID, const KDIS::DATA_TYPE::Vector & Location,
             const KDIS::DATA_TYPE::SystemIdentifier & ID, const KDIS::DATA_TYPE::FundamentalOperationalData & FOD );

    virtual ~IFF_PDU();

    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::SetEmittingEntityID
    //              KDIS::PDU::IFF_PDU::GetEmittingEntityID
    // Description: Emitting Entity ID.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetEmittingEntityID ( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetEmittingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetEmittingEntityID();

    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::SetEventID
    //              KDIS::PDU::IFF_PDU::GetEventID
    // Description: Event ID. For associated events.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetEventID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetEventID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::SetLocation
    //              KDIS::PDU::IFF_PDU::GetLocation
    // Description: Location of the emitting system relative to
    //              the emitting entity's coordinate system.
    //              Represented as a Entity Coordinate Vector
    // Parameter:   const Vector & L
    //************************************
    void SetLocation( const KDIS::DATA_TYPE::Vector & L );
    const KDIS::DATA_TYPE::Vector & GetLocation() const;
    KDIS::DATA_TYPE::Vector & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::SetSystemIdentifier
    //              KDIS::PDU::IFF_PDU::GetSystemIdentifier
    // Description: Identifies the emitting system.
    // Parameter:   const SystemIdentifier & ID
    //************************************
    void SetSystemIdentifier( const KDIS::DATA_TYPE::SystemIdentifier & ID );
    const KDIS::DATA_TYPE::SystemIdentifier & GetSystemIdentifier() const;
    KDIS::DATA_TYPE::SystemIdentifier & GetSystemIdentifier();

    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::SetFundamentalOperationalData
    //              KDIS::PDU::IFF_PDU::GetFundamentalOperationalData
    // Description: Identifies certain basic operational data for an emitting system.
    // Parameter:   const FundamentalOperationalData & FOD
    //************************************
    void SetFundamentalOperationalData( const KDIS::DATA_TYPE::FundamentalOperationalData & FOD );
    const KDIS::DATA_TYPE::FundamentalOperationalData & GetFundamentalOperationalData() const;
    KDIS::DATA_TYPE::FundamentalOperationalData & GetFundamentalOperationalData();

	#if DIS_VERSION > 6
	
    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::SetSystemDesignator
    //              KDIS::PDU::IFF_PDU::GetSystemDesignator
    // Description: A unique decimal number assigned to this interrogator or transponder
	//              to distinguish it from multiple interrogators or transponders that are
	//              associated with the same entity.
    // Parameter:   KUINT8 SD
    //************************************
    void SetSystemDesignator ( KUINT8 SD );
    KUINT8 GetSystemDesignator() const;  

    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::SetSystemSpecificData
    //              KDIS::PDU::IFF_PDU::GetSystemSpecificData
    // Description: This is a variable format field whose meaning is defined for each specific system.
    // Parameter:   KUINT8 SSD
    //************************************
    void SetSystemSpecificData ( KUINT8 SSD );
    KUINT8 GetSystemSpecificData() const;    

	#endif

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer2::AddLayer
    //              KDIS::DATA_TYPE::IFF_Layer2::SetLayers
    //              KDIS::DATA_TYPE::IFF_Layer2::GetLayers
	//              KDIS::DATA_TYPE::IFF_Layer2::ClearLayers
    // Description: Any additional layers attached to this IFF PDU.
    // Parameter:   const KDIS::DATA_TYPE::LyrHdrPtr L, const vector<KDIS::DATA_TYPE::LyrHdrPtr> & L
    //************************************
    void AddLayer( const KDIS::DATA_TYPE::LyrHdrPtr & L );
	void SetLayers( const std::vector<KDIS::DATA_TYPE::LyrHdrPtr> & L );
	const std::vector<KDIS::DATA_TYPE::LyrHdrPtr> & GetLayers() const;
	void ClearLayers();
	
    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::IFF_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IFF_PDU & Value ) const;
    KBOOL operator != ( const IFF_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
