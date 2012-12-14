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
    class:      Fire_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/10/13
    author:     Karl Jones

    purpose:    Warfare PDU family header
    Size:       288 bits / 36 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Warfare_Header : public Header
{
protected:

    EntityIdentifier m_FiringEntityID;

    EntityIdentifier m_TargetEntityID;

    EntityIdentifier m_MunitionID;

    EntityIdentifier m_EventID;

public:

    static const KUINT16 WARFARE_HEADER_SIZE = 36;

    Warfare_Header( void );

    Warfare_Header( const EntityIdentifier & FiringEntID, const EntityIdentifier & TargetEntID,
                    const EntityIdentifier & MunitionID, const EntityIdentifier & EventID );

    virtual ~Warfare_Header( void );

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::SetFiringEntityID
    //              KDIS::PDU::Warfare_Header::GetFiringEntityID
    // Description: Firing Entity.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetFiringEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetFiringEntityID() const;
    EntityIdentifier & GetFiringEntityID();

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::SetTargetEntityID
    //              KDIS::PDU::Warfare_Header::GetTargetEntityID
    // Description: Target Entity. If target is unknown the ID
    //              shall contain the symbolic value: TARGET_ID_UNKNOWN.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetTargetEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetTargetEntityID() const;
    EntityIdentifier & GetTargetEntityID();

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::SetMunitionID
    //              KDIS::PDU::Warfare_Header::GetMunitionID
    // Description: Munition ID. If the munition is not tracked
    //              the ID shall contain the symbolic value: MUNITION_NOT_TRACKED.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetMunitionID( const EntityIdentifier & ID );
    const EntityIdentifier & GetMunitionID() const;
    EntityIdentifier & GetMunitionID();

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::SetEventID
    //              KDIS::PDU::Warfare_Header::GetEventID
    // Description: Event ID. Used to associate related firing/detonation
    //              events. If a detonation event if not proceeded
    //              by a firing event then the value shall be 0 (e.g land mines)
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEventID( const EntityIdentifier & ID );
    const EntityIdentifier & GetEventID() const;
    EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Warfare_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Warfare_Header & Value ) const;
    KBOOL operator != ( const Warfare_Header & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
