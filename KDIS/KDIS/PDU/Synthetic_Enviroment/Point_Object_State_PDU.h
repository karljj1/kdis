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
    class:      Point_Object_State_PDU
    DIS:        (6) 1278.1a - 1998
    created:    04/12/2009
    author:     Karl Jones

    purpose:    Details the addition/modification of an object in the
                synthetic environment geometrically anchored to the terrain
                with a single point.

    size:       704 bits / 88 octets
*********************************************************************/

#pragma once

#include "./Object_State_Header.h"
#include "./../../DataTypes/ObjectType.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/EulerAngles.h"
#include "./../../DataTypes/PointObjectAppearance.h"
#include "./../../DataTypes/SimulationIdentifier.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Point_Object_State_PDU : public Object_State_Header
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8LocBit : 1;
            KUINT8 m_ui8OriBit : 1;
            KUINT8 m_ui8Unused : 6;
        };

        KUINT8 m_ui8Modifications;
    } m_ModificationUnion;

    KDIS::DATA_TYPE::ObjectType m_ObjTyp;

    KDIS::DATA_TYPE::WorldCoordinates m_Loc;

    KDIS::DATA_TYPE::EulerAngles m_Ori;

    KDIS::DATA_TYPE::PointObjectAppearance m_Apperance;

    KUINT16 m_ui16Padding;

    KDIS::DATA_TYPE::SimulationIdentifier m_ReqID;

    KDIS::DATA_TYPE::SimulationIdentifier m_RecvID;

    KUINT32 m_ui32Padding1;

public:

    static const KUINT16 POINT_OBJECT_STATE_PDU_SIZE = 88;

    Point_Object_State_PDU();

    Point_Object_State_PDU( KDataStream & stream ) throw( KException );

	Point_Object_State_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Point_Object_State_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ObjID, const KDIS::DATA_TYPE::EntityIdentifier & RefObjID , KUINT16 UpdateNum,
		                    KDIS::DATA_TYPE::ENUMS::ForceID FI, const KDIS::DATA_TYPE::ObjectType & O, const KDIS::DATA_TYPE::WorldCoordinates & Loc, const KDIS::DATA_TYPE::EulerAngles & Ori,
                            const KDIS::DATA_TYPE::PointObjectAppearance & P, const KDIS::DATA_TYPE::SimulationIdentifier & ReqID,
                            const KDIS::DATA_TYPE::SimulationIdentifier & RecvID );

    virtual ~Point_Object_State_PDU();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetModification
    //              KDIS::PDU::Point_Object_State_PDU::GetModification
    //              KDIS::PDU::Point_Object_State_PDU::SetModificationLocation
    //              KDIS::PDU::Point_Object_State_PDU::IsModificationLocation
    //              KDIS::PDU::Point_Object_State_PDU::SetModificationOrientation
    //              KDIS::PDU::Point_Object_State_PDU::IsModificationOrientation
    // Description: Identifies whether a modification has been made to the point object’s
    //              location or orientation. Modification is represented by a single 8 bit unsigned int, where
    //              bit 0 is the location modified flag and bit 1 is the orientation flag. A value of 1(true)
    //              indicates the field has been changed.
    //              You can also set these values using SetModificationLocation and SetModificationOrientation.
    //              All values are set to false(0) by default.
    // Parameter:   KUINT8 M, KBOOL M = true
    //************************************
    void SetModification( KUINT8 M );
    KUINT8 GetModification() const;
    void SetModificationLocation( KBOOL M = true );
    KBOOL IsModificationLocation() const;
    void SetModificationOrientation( KBOOL M = true );
    KBOOL IsModificationOrientation() const;

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetObjectType
    //              KDIS::PDU::Point_Object_State_PDU::GetObjectType
    // Description: The type of object. Represented as DIS enumeration(domain, kind, Category and sub category).
    // Parameter:   const ObjectType & O
    //************************************
    void SetObjectType( const KDIS::DATA_TYPE::ObjectType & O );
    const KDIS::DATA_TYPE::ObjectType & GetObjectType() const;
    KDIS::DATA_TYPE::ObjectType & GetObjectType();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetLocation
    //              KDIS::PDU::Point_Object_State_PDU::GetLocation
    // Description: The physical location of the object.
    // Parameter:   const WorldCoordinates & L
    //************************************
    void SetLocation( const KDIS::DATA_TYPE::WorldCoordinates & L );
    const KDIS::DATA_TYPE::WorldCoordinates & GetLocation() const;
    KDIS::DATA_TYPE::WorldCoordinates & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetOrientation
    //              KDIS::PDU::Point_Object_State_PDU::GetOrientation
    // Description: The objects orientation.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetOrientation( const KDIS::DATA_TYPE::EulerAngles & O );
    const KDIS::DATA_TYPE::EulerAngles & GetOrientation() const;
    KDIS::DATA_TYPE::EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetObjectAppearance
    //              KDIS::PDU::Point_Object_State_PDU::GetObjectAppearance
    // Description: Specifies the dynamic changes to an object’s appearance attributes.
    // Parameter:   const PointObjectAppearance & O
    //************************************
    void SetObjectAppearance( const KDIS::DATA_TYPE::PointObjectAppearance & A );
    const KDIS::DATA_TYPE::PointObjectAppearance & GetObjectAppearance() const;
    KDIS::DATA_TYPE::PointObjectAppearance & GetObjectAppearance();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetRequestorSimulationID
    //              KDIS::PDU::Point_Object_State_PDU::GetRequestorSimulationID
    // Description: The simulation application sending the PDU.
    // Parameter:   const SimulationIdentifier & ID
    //************************************
    void SetRequestorSimulationID( const KDIS::DATA_TYPE::SimulationIdentifier & ID );
    const KDIS::DATA_TYPE::SimulationIdentifier & GetRequestorSimulationID() const;
    KDIS::DATA_TYPE::SimulationIdentifier & GetRequestorSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetReceivingSimulationID
    //              KDIS::PDU::Point_Object_State_PDU::GetReceivingSimulationID
    // Description: The simulation application that is to receive the PDU.
    // Parameter:   const SimulationIdentifier & ID
    //************************************
    void SetReceivingSimulationID( const KDIS::DATA_TYPE::SimulationIdentifier & ID );
    const KDIS::DATA_TYPE::SimulationIdentifier & GetReceivingSimulationID() const;
    KDIS::DATA_TYPE::SimulationIdentifier & GetReceivingSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Point_Object_State_PDU & Value ) const;
    KBOOL operator != ( const Point_Object_State_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
