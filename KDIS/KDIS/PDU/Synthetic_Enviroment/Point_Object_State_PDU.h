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

using KDIS::DATA_TYPE::ObjectType;
using KDIS::DATA_TYPE::WorldCoordinates;
using KDIS::DATA_TYPE::EulerAngles;
using KDIS::DATA_TYPE::PointObjectAppearance;
using KDIS::DATA_TYPE::SimulationIdentifier;
using KDIS::DATA_TYPE::ENUMS::ForceID;

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

    ObjectType m_ObjTyp;

    WorldCoordinates m_Loc;

    EulerAngles m_Ori;

    PointObjectAppearance m_Apperance;

    KUINT16 m_ui16Padding;

    SimulationIdentifier m_ReqID;

    SimulationIdentifier m_RecvID;

    KUINT32 m_ui32Padding1;

public:

    static const KUINT16 POINT_OBJECT_STATE_PDU_SIZE = 88;

    Point_Object_State_PDU();

    Point_Object_State_PDU( KDataStream & stream ) throw( KException );

	Point_Object_State_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Point_Object_State_PDU( const EntityIdentifier & ObjID, const EntityIdentifier & RefObjID , KUINT16 UpdateNum,
                            ForceID FI, const ObjectType & O, const WorldCoordinates & Loc, const EulerAngles & Ori,
                            const PointObjectAppearance & P, const SimulationIdentifier & ReqID,
                            const SimulationIdentifier & RecvID );

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
    // Parameter:   const ObjectType & O, void
    //************************************
    void SetObjectType( const ObjectType & O );
    const ObjectType & GetObjectType() const;
    ObjectType & GetObjectType();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetLocation
    //              KDIS::PDU::Point_Object_State_PDU::GetLocation
    // Description: The physical location of the object.
    // Parameter:   const WorldCoordinates & L, void
    //************************************
    void SetLocation( const WorldCoordinates & L );
    const WorldCoordinates & GetLocation() const;
    WorldCoordinates & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetOrientation
    //              KDIS::PDU::Point_Object_State_PDU::GetOrientation
    // Description: The objects orientation.
    // Parameter:   const EulerAngles & O, void
    //************************************
    void SetOrientation( const EulerAngles & O );
    const EulerAngles & GetOrientation() const;
    EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetObjectAppearance
    //              KDIS::PDU::Point_Object_State_PDU::GetObjectAppearance
    // Description: Specifies the dynamic changes to an object’s appearance attributes.
    // Parameter:   const PointObjectAppearance & O, void
    //************************************
    void SetObjectAppearance( const PointObjectAppearance & A );
    const PointObjectAppearance & GetObjectAppearance() const;
    PointObjectAppearance & GetObjectAppearance();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetRequestorSimulationID
    //              KDIS::PDU::Point_Object_State_PDU::GetRequestorSimulationID
    // Description: The simulation application sending the PDU.
    // Parameter:   const SimulationIdentifier & ID, void
    //************************************
    void SetRequestorSimulationID( const SimulationIdentifier & ID );
    const SimulationIdentifier & GetRequestorSimulationID() const;
    SimulationIdentifier & GetRequestorSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Point_Object_State_PDU::SetReceivingSimulationID
    //              KDIS::PDU::Point_Object_State_PDU::GetReceivingSimulationID
    // Description: The simulation application that is to receive the PDU.
    // Parameter:   const SimulationIdentifier & ID, void
    //************************************
    void SetReceivingSimulationID( const SimulationIdentifier & ID );
    const SimulationIdentifier & GetReceivingSimulationID() const;
    SimulationIdentifier & GetReceivingSimulationID();

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
