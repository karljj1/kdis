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
    class:      LE_EntityIdentifier
    created:    30/06/2010
    author:     Karl Jones

    purpose:    Entity Identifier Field found in Live Entity (LE) PDU's.
                The site and application id's have been reduced to 8 bits from 16.

    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT LE_EntityIdentifier : public DataTypeBase
{
protected:

    KUINT8 m_ui8SiteID;

    KUINT8 m_ui8ApplicationID;

    KUINT16 m_ui16EntityID;

public:

    static const KUINT16 LE_ENTITY_IDENTIFER_SIZE = 4;

    LE_EntityIdentifier( void );

    LE_EntityIdentifier( KUINT8 SiteID, KUINT8 ApplicatonID, KUINT16 EntityID );

    LE_EntityIdentifier( KDataStream & stream ) throw( KException );

    virtual ~LE_EntityIdentifier( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::SetSiteID
    //              KDIS::DATA_TYPE::LE_EntityIdentifier::GetSiteID
    // Description: Site ID for Live Entity EntityIdentifier's.
    // Parameter:   KUINT8 ID
    //************************************
    void SetSiteID( KUINT8 ID );
    KUINT8 GetSiteID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::SetApplicationID
    //              KDIS::DATA_TYPE::LE_EntityIdentifier::GetApplicationID
    // Description: Application ID for Live Entity EntityIdentifier's.
    // Parameter:   KUINT8 ID
    //************************************
    void SetApplicationID( KUINT8 ID );
    KUINT8 GetApplicationID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::SetEntityID
    //              KDIS::DATA_TYPE::LE_EntityIdentifier::GetEntityID
    // Description: Entity ID, also known as Object ID, Process Numbers and
    //              Reference Number in DIS version 7.
    // Parameter:   KUINT16 ID
    //************************************
    void SetEntityID( KUINT16 ID );
    KUINT16 GetEntityID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_EntityIdentifier & Value ) const;
    KBOOL operator != ( const LE_EntityIdentifier & Value ) const;
    KBOOL operator <  ( const LE_EntityIdentifier & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

