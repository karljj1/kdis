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
    class:      CommunicationsNodeID
    created:    04/12/2010
    author:     Karl Jones

    purpose:    The identification of a communications node is conveyed using
                the Communications Node ID record.
                The combination of Entity ID and Element ID uniquely identify
                an IO communications node within a simulation exercise.

    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./EntityIdentifier.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT CommunicationsNodeID : public EntityIdentifier
{
protected:

    KUINT16 m_ui16ElementID;

public:

    static const KUINT16 COMMUNICATIONS_NODE_ID_SIZE = 8;

    CommunicationsNodeID( void );

    CommunicationsNodeID( KDataStream & stream ) throw( KException );

    CommunicationsNodeID( KUINT16 Site, KUINT16 App, KUINT16 Obj, KUINT16 Element );

    CommunicationsNodeID( const SimulationIdentifier & SimID, KUINT16 Obj, KUINT16 Element );

    CommunicationsNodeID( const EntityIdentifier & EntID, KUINT16 Element );

    virtual ~CommunicationsNodeID( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsNodeID::SetElementID
    //              KDIS::DATA_TYPE::CommunicationsNodeID::GetElementID
    // Description: Identifies a particular communications element (e.g. radio,
    //              network component, or modem) within a given entity.
    //              If this element is a radio for which a Transmitter PDU
    //              is being issued, this value shall correspond to the Radio
    //              ID in that PDU.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetElementID( KUINT16 ID );
    KUINT16 GetElementID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsNodeID::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsNodeID::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsNodeID::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const CommunicationsNodeID & Value ) const;
    KBOOL operator != ( const CommunicationsNodeID & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
