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
    class:      EntityIdentifier
    created:    18/09/2008
    author:     Karl Jones

    purpose:    Entity Identifier Field found in PDU's. 
				Also known as:
					Object Identifier. - where entity id is object id.
					Event Identifier. - where entity id is event id.
    size:       48 bits / 6 octets
*********************************************************************/

#pragma once

#include "./SimulationIdentifier.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EntityIdentifier : public SimulationIdentifier
{
protected:

    KUINT16 m_ui16EntityID;

public:

    static const KUINT16 ENTITY_IDENTIFER_SIZE = 6;

    EntityIdentifier( void );

    EntityIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID, KUINT16 EntityID );

    EntityIdentifier( const SimulationIdentifier & SimID, KUINT16 EntityID );

    EntityIdentifier( KDataStream & stream ) throw( KException );

    virtual ~EntityIdentifier( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityIdentifier::SetEntityID
    //              KDIS::DATA_TYPE::EntityIdentifier::GetEntityID
    // Description: Entity ID, also known as 'Object ID', 'Process Numbers', 'Event ID' or 'Reference Number'.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetEntityID( KUINT16 ID );
    KUINT16 GetEntityID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EntityIdentifier & Value ) const;
    KBOOL operator != ( const EntityIdentifier & Value ) const;
    KBOOL operator <  ( const EntityIdentifier & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

