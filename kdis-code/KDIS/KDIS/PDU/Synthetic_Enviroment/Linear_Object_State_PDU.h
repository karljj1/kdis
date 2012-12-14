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
    class:      Linear_Object_State_PDU
    DIS:        (6) 1278.1a - 1998
    created:    15/03/2010
    author:     Karl Jones

    purpose:    Contains detailed information about the addition/modification of a
                synthetic environment object that is geometrically anchored to the
                terrain with one point and has size and orientation.

    size:       320 bits / 40 octets - Min size.
*********************************************************************/

#pragma once

#include "./Object_State_Header.h"
#include "./../../DataTypes/SimulationIdentifier.h"
#include "./../../DataTypes/ObjectType.h"
#include "./../../DataTypes/LinearSegmentParameter.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::SimulationIdentifier;
using KDIS::DATA_TYPE::ObjectType;
using KDIS::DATA_TYPE::LinearSegmentParameter;
using KDIS::DATA_TYPE::ENUMS::ForceID;

class KDIS_EXPORT Linear_Object_State_PDU : public Object_State_Header
{
protected:

    KUINT8 m_ui8NumSegment;

    SimulationIdentifier m_ReqID;

    SimulationIdentifier m_RecvID;

    ObjectType m_ObjTyp;

    vector<LinearSegmentParameter> m_vSegments;

public:

    static const KUINT16 LINEAR_OBJECT_STATE_PDU_SIZE = 40;

    Linear_Object_State_PDU( void );

    Linear_Object_State_PDU( KDataStream & stream ) throw( KException );

    Linear_Object_State_PDU( const EntityIdentifier & ObjID, const EntityIdentifier & RefObjID , KUINT16 UpdateNum,
                             ForceID FI, const SimulationIdentifier & ReqID, const SimulationIdentifier & RecvID,
                             const ObjectType & O );

    Linear_Object_State_PDU( const EntityIdentifier & ObjID, const EntityIdentifier & RefObjID , KUINT16 UpdateNum,
                             ForceID FI, const SimulationIdentifier & ReqID, const SimulationIdentifier & RecvID,
                             const ObjectType & O, vector<LinearSegmentParameter> & Segments );

    virtual ~Linear_Object_State_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Linear_Object_State_PDU::GetNumberOfSegments
    // Description: The number of Linear Segment Parameter records contained within this PDU.
    //************************************
    KUINT8 GetNumberOfSegments() const;

    //************************************
    // FullName:    KDIS::PDU::Linear_Object_State_PDU::SetRequestorSimulationID
    //              KDIS::PDU::Linear_Object_State_PDU::GetRequestorSimulationID
    // Description: The simulation application sending the PDU.
    // Parameter:   const SimulationIdentifier & ID, void
    //************************************
    void SetRequestorSimulationID( const SimulationIdentifier & ID );
    const SimulationIdentifier & GetRequestorSimulationID() const;
    SimulationIdentifier & GetRequestorSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Linear_Object_State_PDU::SetReceivingSimulationID
    //              KDIS::PDU::Linear_Object_State_PDU::GetReceivingSimulationID
    // Description: The simulation application that is to receive the PDU.
    // Parameter:   const SimulationIdentifier & ID, void
    //************************************
    void SetReceivingSimulationID( const SimulationIdentifier & ID );
    const SimulationIdentifier & GetReceivingSimulationID() const;
    SimulationIdentifier & GetReceivingSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Linear_Object_State_PDU::SetObjectType
    //              KDIS::PDU::Linear_Object_State_PDU::GetObjectType
    // Description: The type of object. Represented as DIS enumeration(domain, kind, Category and sub category).
    // Parameter:   const ObjectType & O, void
    //************************************
    void SetObjectType( const ObjectType & O );
    const ObjectType & GetObjectType() const;
    ObjectType & GetObjectType();

    //************************************
    // FullName:    KDIS::PDU::Linear_Object_State_PDU::AddLinearSegmentParameter
    //              KDIS::PDU::Linear_Object_State_PDU::SetLinearSegmentParameters
    //              KDIS::PDU::Linear_Object_State_PDU::GetLinearSegmentParameters
    // Description: Specifies the parameter values for representing each linear segment.
    // Parameter:   const LinearSegmentParameter & L, const vector<LinearSegmentParameter> & L, void
    //************************************
    void AddLinearSegmentParameter( const LinearSegmentParameter & L );
    void SetLinearSegmentParameters( const vector<LinearSegmentParameter> & L );
    const vector<LinearSegmentParameter> & GetLinearSegmentParameters() const;

    //************************************
    // FullName:    KDIS::PDU::Linear_Object_State_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Linear_Object_State_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Linear_Object_State_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Linear_Object_State_PDU & Value ) const;
    KBOOL operator != ( const Linear_Object_State_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
