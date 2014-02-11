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
    class:      Areal_Object_State_PDU
    DIS:        (6) 1278.1a - 1998
    created:    17/03/2010
    author:     Karl Jones

    purpose:    An object that is geometrically anchored to the terrain
                with a set of three or more points that come to a closure.

    size:       384 bits / 48 octets - Min size.
*********************************************************************/

#pragma once

#include "./Object_State_Header.h"
#include "./../../DataTypes/ObjectType.h"
#include "./../../DataTypes/SimulationIdentifier.h"
#include "./../../DataTypes/ArealObjectAppearance.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include <vector>

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Areal_Object_State_PDU : public Object_State_Header
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8LocBit : 1;
            KUINT8 m_ui8Unused : 7;
        };

        KUINT8 m_ui8Modifications;
    } m_ModificationUnion;

    KDIS::DATA_TYPE::ObjectType m_ObjTyp;

    KDIS::DATA_TYPE::ArealObjectAppearance m_Apperance;

    KUINT16 m_ui16NumPoints;

    KDIS::DATA_TYPE::SimulationIdentifier m_ReqID;

    KDIS::DATA_TYPE::SimulationIdentifier m_RecvID;

	std::vector<KDIS::DATA_TYPE::WorldCoordinates> m_vPoints;

public:

    static const KUINT16 AREAL_OBJECT_STATE_PDU_SIZE = 48;

    Areal_Object_State_PDU();

    Areal_Object_State_PDU( KDataStream & stream ) throw( KException );

	Areal_Object_State_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Areal_Object_State_PDU( KUINT8 Modification, const KDIS::DATA_TYPE::ObjectType & T, const KDIS::DATA_TYPE::ArealObjectAppearance & A,
                            const KDIS::DATA_TYPE::SimulationIdentifier & RequestorID, const KDIS::DATA_TYPE::SimulationIdentifier & ReceivingID );

    Areal_Object_State_PDU( KUINT8 Modification, const KDIS::DATA_TYPE::ObjectType & T, const KDIS::DATA_TYPE::ArealObjectAppearance & A,
                            const KDIS::DATA_TYPE::SimulationIdentifier & RequestorID, const KDIS::DATA_TYPE::SimulationIdentifier & ReceivingID,
							const std::vector<KDIS::DATA_TYPE::WorldCoordinates> & Points );

    virtual ~Areal_Object_State_PDU();

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::SetModification
    //              KDIS::PDU::Areal_Object_State_PDU::GetModification
    //              KDIS::PDU::Areal_Object_State_PDU::SetModificationLocation
    //              KDIS::PDU::Areal_Object_State_PDU::IsModificationLocation
    // Description: Identifies whether a modification has been made to the point object’s location .
    //              Modification is represented by a single 8 bit unsigned int, where
    //              bit 0 is the location modified flag.
    //              A value of 1(true) indicates the field has been changed.
    //              All values are set to false(0) by default.
    // Parameter:   KUINT8 M, KBOOL M = true
    //************************************
    void SetModification( KUINT8 M );
    KUINT8 GetModification() const;
    void SetModificationLocation( KBOOL M = true );
    KBOOL IsModificationLocation() const;

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::SetObjectType
    //              KDIS::PDU::Areal_Object_State_PDU::GetObjectType
    // Description: The type of object. Represented as DIS enumeration(domain, kind, Category and sub category).
    // Parameter:   const ObjectType & O
    //************************************
    void SetObjectType( const KDIS::DATA_TYPE::ObjectType & O );
    const KDIS::DATA_TYPE::ObjectType & GetObjectType() const;
    KDIS::DATA_TYPE::ObjectType & GetObjectType();

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::SetObjectAppearance
    //              KDIS::PDU::Areal_Object_State_PDU::GetObjectAppearance
    // Description: Specifies the dynamic changes to an object’s appearance attributes.
    // Parameter:   const ArealObjectAppearance & A
    //************************************
    void SetObjectAppearance( const KDIS::DATA_TYPE::ArealObjectAppearance & A );
    const KDIS::DATA_TYPE::ArealObjectAppearance & GetObjectAppearance() const;
    KDIS::DATA_TYPE::ArealObjectAppearance & GetObjectAppearance();

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::GetNumberOfPoints
    // Description: The total number of points making up the areal object.
    //************************************
    KUINT16 GetNumberOfPoints() const;

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::SetRequestorSimulationID
    //              KDIS::PDU::Areal_Object_State_PDU::GetRequestorSimulationID
    // Description: The simulation application sending the PDU.
    // Parameter:   const SimulationIdentifier & ID
    //************************************
    void SetRequestorSimulationID( const KDIS::DATA_TYPE::SimulationIdentifier & ID );
    const KDIS::DATA_TYPE::SimulationIdentifier & GetRequestorSimulationID() const;
    KDIS::DATA_TYPE::SimulationIdentifier & GetRequestorSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::SetReceivingSimulationID
    //              KDIS::PDU::Areal_Object_State_PDU::GetReceivingSimulationID
    // Description: The simulation application that is to receive the PDU.
    // Parameter:   const SimulationIdentifier & ID
    //************************************
    void SetReceivingSimulationID( const KDIS::DATA_TYPE::SimulationIdentifier & ID );
    const KDIS::DATA_TYPE::SimulationIdentifier & GetReceivingSimulationID() const;
    KDIS::DATA_TYPE::SimulationIdentifier & GetReceivingSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::AddPoint
    //              KDIS::PDU::Areal_Object_State_PDU::SetPoints
    //              KDIS::PDU::Areal_Object_State_PDU::GetPoints
    // Description: Specifies the points that make up the object’s physical location.
    // Parameter:   const WorldCoordinates & P, const vector<WorldCoordinates> & P, void
    //************************************
    void AddPoint( const KDIS::DATA_TYPE::WorldCoordinates & P );
	void SetPoints( const std::vector<KDIS::DATA_TYPE::WorldCoordinates> & P );
	const std::vector<KDIS::DATA_TYPE::WorldCoordinates> & GetPoints() const;

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Areal_Object_State_PDU & Value ) const;
    KBOOL operator != ( const Areal_Object_State_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
