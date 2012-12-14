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
    class:      Simulation_Management_Header
    DIS:        (5) 1278.1 - 1995
    created:    17/09/2008
    author:     Karl Jones

    purpose:    Contains common fields found in Simulation management PDU.
    Size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Simulation_Management_Header : public Header
{
protected:

    EntityIdentifier m_OriginatingEntityID;

    EntityIdentifier m_ReceivingEntityID;

public:

    static const KUINT16 SIMULATION_MANAGEMENT_HEADER_SIZE = 24;

    Simulation_Management_Header( void );

    Simulation_Management_Header( KDataStream & stream ) throw( KException );

    Simulation_Management_Header( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID );

    virtual ~Simulation_Management_Header( void );

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::SetOriginatingEntityID
    //              KDIS::PDU::Simulation_Management_Header::GetOriginatingEntityID
    // Description: Originating Entity ID
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetOriginatingEntityID ( const EntityIdentifier & ID );
    const EntityIdentifier & GetOriginatingEntityID() const;
    EntityIdentifier & GetOriginatingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::SetReceivingEntityID
    //              KDIS::PDU::Simulation_Management_Header::GetReceivingEntityID
    // Description: Receiving Entity ID:
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetReceivingEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetReceivingEntityID() const;
    EntityIdentifier & GetReceivingEntityID();

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Simulation_Management_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Simulation_Management_Header & Value ) const;
    KBOOL operator != ( const Simulation_Management_Header & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
