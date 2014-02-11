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
    class:      Minefield_State_PDU
    DIS:        (6) 1278.1a - 1998
    created:    13/04/2010
    author:     Karl Jones

    purpose:    Provides information about the complete minefield. The minefield presence,
                perimeter, protocol mode, and the types of mines contained within the minefield.

    size:       576 bits / 72 octets  - Min size
*********************************************************************/

#pragma once

#include "./Minefield_Header.h"
#include "./../../DataTypes/EntityType.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/EulerAngles.h"
#include "./../../DataTypes/MinefieldAppearance.h"
#include "./../../DataTypes/PerimeterPointCoordinate.h"
#include <vector>

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Minefield_State_PDU : public Minefield_Header
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16Reserved : 1;
            KUINT16 m_ui16SeqNum15 : 15;
        };
        KUINT16 m_ui16SeqNum;
    } m_SeqNumUnion;

    KUINT8 m_ui8ForceID;

    KUINT8 m_ui8NumPerimPoints;

    KDIS::DATA_TYPE::EntityType m_MinefieldType;

    KUINT16 m_ui16NumMineTypes;

    KDIS::DATA_TYPE::WorldCoordinates m_Loc;

    KDIS::DATA_TYPE::EulerAngles m_Ori;

    KDIS::DATA_TYPE::MinefieldAppearance m_App;

    union
    {
        struct
        {
            KUINT16 m_ui16ProtocolMode2 : 2;
            KUINT16 m_ui16Reserved      : 14;
        };
        KUINT16 m_ui16ProtocolMode16;
    } m_ui16ProtocolModeUnion;

	std::vector<KDIS::DATA_TYPE::PerimeterPointCoordinate> m_vPoints;

	std::vector<KDIS::DATA_TYPE::EntityType> m_vMineTypes;

public:

    static const KUINT16 MINEFIELD_STATE_PDU_SIZE = 72; // Min size

    Minefield_State_PDU();

	Minefield_State_PDU( KDataStream & stream ) throw( KException );

	Minefield_State_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Minefield_State_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ID, KUINT16 SequenceNumber, KDIS::DATA_TYPE::ENUMS::ForceID FID, const KDIS::DATA_TYPE::EntityType & Type,
                         const KDIS::DATA_TYPE::WorldCoordinates & Loc, const KDIS::DATA_TYPE::EulerAngles & Ori, const KDIS::DATA_TYPE::MinefieldAppearance & MA,
                         KDIS::DATA_TYPE::ENUMS::MinefieldProtocolMode MPM );

    virtual ~Minefield_State_PDU();

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::SetSequenceNumber
    //              KDIS::PDU::Minefield_State_PDU::GetSequenceNumber
    // Description: Specifies a change in state of a minefield as a result of a
    //              change in minefield information or a change in the state,
    //              in accordance with the rules specified in 5.9.2.3(IEEE 1278.1a).
    // Parameter:   KUINT16 S
    //************************************
    void SetSequenceNumber( KUINT16 S );
    KUINT16 GetSequenceNumber() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::SetForceID
    //              KDIS::PDU::Minefield_State_PDU::GetForceID
    // Description: Force ID. Enumerated value representing the force the minefield belongs to,
    //              such as friendly, opposing or neutral.
    // Parameter:   ForceID ID
    //************************************
    void SetForceID( KDIS::DATA_TYPE::ENUMS::ForceID ID );
    KDIS::DATA_TYPE::ENUMS::ForceID GetForceID() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::GetNumberOfPerimeterPoints
    // Description: Number of points in the perimeter of the minefield.
    //************************************
    KUINT8 GetNumberOfPerimeterPoints() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::SetMinefieldType
    //              KDIS::PDU::Minefield_State_PDU::GetMinefieldType
    // Description: Identifies the minefield type of the issuing minefield.
    //              Consists of 7 values used to represent the type of minefield.
    //              Please see DIS Enums document found on the SISO website for a full list of enumerations available.
    //              See 6.2.30(IEEE 1278.1) and Section 4 of SISO-REF-010.
    // Parameter:   const EntityType & Type
    //************************************
    void SetMinefieldType( const KDIS::DATA_TYPE::EntityType & Type );
    const KDIS::DATA_TYPE::EntityType & GetMinefieldType() const;
    KDIS::DATA_TYPE::EntityType & GetMinefieldType();

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::GetNumberOfMineTypes
    // Description: The number of different mine types employed in the minefield.
    //************************************
    KUINT8 GetNumberOfMineTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::SetMinefieldLocation
    //              KDIS::PDU::Minefield_State_PDU::GetMinefieldLocation
    // Description: Location of the center of the minefield in Geocentric world coordinates.
    //              Note: See KConversions.h for some useful coordinate conversions.
    // Parameter:   const WorldCoordinates & L
    //************************************
    void SetMinefieldLocation( const KDIS::DATA_TYPE::WorldCoordinates & L );
    const KDIS::DATA_TYPE::WorldCoordinates & GetMinefieldLocation() const;
    KDIS::DATA_TYPE::WorldCoordinates & GetMinefieldLocation();

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::SetMinefieldOrientation
    //              KDIS::PDU::Minefield_State_PDU::GetMinefieldOrientation
    // Description: Orientation of minefield. Geocentric Euler Angles.
    //              Note: See KConversions.h for some useful orientation conversions.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetMinefieldOrientation( const KDIS::DATA_TYPE::EulerAngles & O );
    const KDIS::DATA_TYPE::EulerAngles & GetMinefieldOrientation() const;
    KDIS::DATA_TYPE::EulerAngles & GetMinefieldOrientation();

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::SetMinefieldAppearance
    //              KDIS::PDU::Minefield_State_PDU::GetMinefieldAppearance
    // Description: The appearance of the minefield.
    // Parameter:   const MinefieldAppearance & MA
    //************************************
    void SetMinefieldAppearance( const KDIS::DATA_TYPE::MinefieldAppearance & MA );
    const KDIS::DATA_TYPE::MinefieldAppearance & GetMinefieldAppearance() const;
    KDIS::DATA_TYPE::MinefieldAppearance & GetMinefieldAppearance();

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::SetMinefieldProtocolMode
    //              KDIS::PDU::Minefield_State_PDU::GetMinefieldProtocolMode
    // Description: Specifies which protocol mode is being used to communicate the minefield data.
    // Parameter:   MinefieldProtocolMode MPM
    //************************************
    void SetMinefieldProtocolMode( KDIS::DATA_TYPE::ENUMS::MinefieldProtocolMode MPM );
    KDIS::DATA_TYPE::ENUMS::MinefieldProtocolMode GetMinefieldProtocolMode() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::AddPerimeterPointCoordinate
    //              KDIS::PDU::Minefield_State_PDU::SetPerimeterPointCoordinates
    //              KDIS::PDU::Minefield_State_PDU::GetPerimeterPointCoordinates
    // Description: Specifies the location of each perimeter point, relative to
    //              the Minefield Location field.
    //              Only the x and y coordinates of each perimeter point shall be specified.
    // Parameter:   const PerimeterPointCoordinate & PPC, vector<PerimeterPointCoordinate> & PPC
    //************************************
    void AddPerimeterPointCoordinate( const KDIS::DATA_TYPE::PerimeterPointCoordinate & PPC );
	void SetPerimeterPointCoordinates( const std::vector<KDIS::DATA_TYPE::PerimeterPointCoordinate> & PPC );
	const std::vector<KDIS::DATA_TYPE::PerimeterPointCoordinate> & GetPerimeterPointCoordinates() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::AddMineType
    //              KDIS::PDU::Minefield_State_PDU::SetMineTypes
    //              KDIS::PDU::Minefield_State_PDU::GetMineTypes
    // Description: Specifies the type of each mine contained within the minefield.
    // Parameter:   const EntityType & MT, vector<EntityType> & MT
    //************************************
    void AddMineType( const KDIS::DATA_TYPE::EntityType & MT );
	void SetMineTypes( const std::vector<KDIS::DATA_TYPE::EntityType> & MT );
	const std::vector<KDIS::DATA_TYPE::EntityType> & GetMineTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Minefield_State_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Minefield_State_PDU & Value ) const;
    KBOOL operator != ( const Minefield_State_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
