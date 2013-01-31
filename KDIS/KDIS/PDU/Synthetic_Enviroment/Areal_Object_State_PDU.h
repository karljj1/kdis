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

using KDIS::DATA_TYPE::ObjectType;
using KDIS::DATA_TYPE::ArealObjectAppearance;
using KDIS::DATA_TYPE::SimulationIdentifier;
using KDIS::DATA_TYPE::WorldCoordinates;
using std::vector;

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

    ObjectType m_ObjTyp;

    ArealObjectAppearance m_Apperance;

    KUINT16 m_ui16NumPoints;

    SimulationIdentifier m_ReqID;

    SimulationIdentifier m_RecvID;

    vector<WorldCoordinates> m_vPoints;

public:

    static const KUINT16 AREAL_OBJECT_STATE_PDU_SIZE = 48;

    Areal_Object_State_PDU( void );

    Areal_Object_State_PDU( KDataStream & stream ) throw( KException );

    Areal_Object_State_PDU( KUINT8 Modification, const ObjectType & T, const ArealObjectAppearance & A,
                            const SimulationIdentifier & RequestorID, const SimulationIdentifier & ReceivingID );

    Areal_Object_State_PDU( KUINT8 Modification, const ObjectType & T, const ArealObjectAppearance & A,
                            const SimulationIdentifier & RequestorID, const SimulationIdentifier & ReceivingID,
                            const vector<WorldCoordinates> & Points );

    virtual ~Areal_Object_State_PDU( void );

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
    // Parameter:   const ObjectType & O, void
    //************************************
    void SetObjectType( const ObjectType & O );
    const ObjectType & GetObjectType() const;
    ObjectType & GetObjectType();

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::SetObjectAppearance
    //              KDIS::PDU::Areal_Object_State_PDU::GetObjectAppearance
    // Description: Specifies the dynamic changes to an object’s appearance attributes.
    // Parameter:   const ArealObjectAppearance & A, void
    //************************************
    void SetObjectAppearance( const ArealObjectAppearance & A );
    const ArealObjectAppearance & GetObjectAppearance() const;
    ArealObjectAppearance & GetObjectAppearance();

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::GetNumberOfPoints
    // Description: The total number of points making up the areal object.
    //************************************
    KUINT16 GetNumberOfPoints() const;

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::SetRequestorSimulationID
    //              KDIS::PDU::Areal_Object_State_PDU::GetRequestorSimulationID
    // Description: The simulation application sending the PDU.
    // Parameter:   const SimulationIdentifier & ID, void
    //************************************
    void SetRequestorSimulationID( const SimulationIdentifier & ID );
    const SimulationIdentifier & GetRequestorSimulationID() const;
    SimulationIdentifier & GetRequestorSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::SetReceivingSimulationID
    //              KDIS::PDU::Areal_Object_State_PDU::GetReceivingSimulationID
    // Description: The simulation application that is to receive the PDU.
    // Parameter:   const SimulationIdentifier & ID, void
    //************************************
    void SetReceivingSimulationID( const SimulationIdentifier & ID );
    const SimulationIdentifier & GetReceivingSimulationID() const;
    SimulationIdentifier & GetReceivingSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::AddPoint
    //              KDIS::PDU::Areal_Object_State_PDU::SetPoints
    //              KDIS::PDU::Areal_Object_State_PDU::GetPoints
    // Description: Specifies the points that make up the object’s physical location.
    // Parameter:   const WorldCoordinates & P, const vector<WorldCoordinates> & P, void
    //************************************
    void AddPoint( const WorldCoordinates & P );
    void SetPoints( const vector<WorldCoordinates> & P );
    const vector<WorldCoordinates> & GetPoints() const;

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Areal_Object_State_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
