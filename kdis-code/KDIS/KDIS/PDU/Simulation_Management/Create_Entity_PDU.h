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
    class:      Create_Entity_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Sent when a new entity is created
    size:       224 bits / 28 octets
*********************************************************************/

#pragma once

#include "./Simulation_Management_Header.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Create_Entity_PDU : public Simulation_Management_Header
{
protected:

    KUINT32 m_ui32RequestID;

public:

    static const KUINT16 CREATE_ENTITY_PDU_SIZE = 28;

    Create_Entity_PDU( void );

    Create_Entity_PDU( KDataStream & stream ) throw( KException );

    Create_Entity_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity, KUINT32 RequestID );

    Create_Entity_PDU( const Simulation_Management_Header & SimMgrHeader, KUINT32 RequestID );

    virtual ~Create_Entity_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Create_Entity_PDU::SetRequestID
    //              KDIS::PDU::Create_Entity_PDU::GetRequestID
    // Description: Request ID
    // Parameter:   KUINT32 ID, void
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Create_Entity_PDU::GetString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Create_Entity_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Create_Entity_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Create_Entity_PDU & Value ) const;
    KBOOL operator != ( const Create_Entity_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
