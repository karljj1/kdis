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
    class:      EntityDestinationRecord
    created:    2009/02/05
    author:     Karl Jones

    purpose:    Used to send an Intercom Control PDU directly to a specific entity.
    size:       96 bits / 12 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EntityIdentifier.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::LineStateCommand;

class KDIS_EXPORT EntityDestinationRecord : public DataTypeBase
{
protected:

    EntityIdentifier m_Entity;

    KUINT16 m_ui16DstCommsDvcID;

    KUINT8 m_ui8DstLineID;

    KUINT8 m_ui8DstPriority;

    KUINT8 m_ui8LnStCmd;

    KUINT8 m_uiPadding1;

public:

    static const KUINT16 ENTITY_DESTINATION_RECORD_SIZE = 12;

    EntityDestinationRecord( void );

    EntityDestinationRecord( KDataStream & stream )throw( KException );

    EntityDestinationRecord( const EntityIdentifier & ID, KUINT16 CommDeviceID, KUINT8 LineID,
                             KUINT8 Priority, LineStateCommand LSC );

    virtual ~EntityDestinationRecord( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityDestinationRecord::SetDestinationEntityID
    //              KDIS::DATA_TYPE::EntityDestinationRecord::GetDestinationEntityID
    // Description: Entity that is the recipient of the PDU.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetDestinationEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetDestinationEntityID() const;
    EntityIdentifier & GetDestinationEntityID();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityDestinationRecord::SetDestinationCommDeviceID
    //              KDIS::DATA_TYPE::EntityDestinationRecord::GetDestinationCommDeviceID
    // Description: Identifies the specific intercom device being interfaced
    //              and/or simulated within an entity.
    //              All devices on an entity must have a unique ID.
    //              Set to 0 if the entity does not have a simulated device.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetDestinationCommDeviceID( KUINT16 ID );
    KUINT16 GetDestinationCommDeviceID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityDestinationRecord::SetDestinationLineID
    //              KDIS::DATA_TYPE::EntityDestinationRecord::GetDestinationLineID
    // Description: Identifies the line number to which this intercom control refers.
    //              E.G. For a intercom device with a single line the value would be 1.
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetDestinationLineID( KUINT8 ID );
    KUINT8 GetDestinationLineID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityDestinationRecord::SetDestinationPriority
    //              KDIS::DATA_TYPE::EntityDestinationRecord::GetDestinationPriority
    // Description: Identifies the priority of this message relative to transmissions
    //              from other intercom devices on the same channel.
    //              The value 0 is reserved.
    //              1 = highest priority, 255 = lowest priority.
    // Parameter:   KUINT8 TP, void
    //************************************
    void SetDestinationPriority( KUINT8 TP );
    KUINT8 GetDestinationPriority() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityDestinationRecord::SetLineStateCommand
    //              KDIS::DATA_TYPE::EntityDestinationRecord::GetLineStateCommand
    // Description: When the Control Type of the Intercom Control PDU is
    //              request or acknowledge, this field shall specify the
    //              detailed type requested. Otherwise set to 0.
    // Parameter:   LineStateCommand LSC, void
    //************************************
    void SetLineStateCommand( LineStateCommand LSC );
    LineStateCommand GetLineStateCommand() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityDestinationRecord::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityDestinationRecord::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityDestinationRecord::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EntityDestinationRecord & Value ) const;
    KBOOL operator != ( const EntityDestinationRecord & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
