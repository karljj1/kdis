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
    class:      GroupAssignmentRecord
    created:    2009/02/06
    author:     Karl Jones

    purpose:    Used to assign a group bit field to a specific entity.
                A bit set to one shall indicate membership in the corresponding group.
                Multiple bits can be set to indicate membership in multiple groups.
    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EntityIdentifier.h"
#include <bitset>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GroupAssignmentRecord :   public DataTypeBase
{
protected:

    KUINT32 m_ui32GrpBtField;

    EntityIdentifier m_Entity;

    KUINT16 m_ui16DstCommsDvcID;

    KUINT8 m_ui8DstLineID;

    KUINT16 m_ui16Padding1; // 24 Bits - Reserved

    KUINT8 m_ui8Padding2;

public:

    static const KUINT16 GROUP_ASSIGNMENT_RECORD_SIZE = 16;

    GroupAssignmentRecord( void );

    GroupAssignmentRecord( KDataStream & stream )throw( KException );

    GroupAssignmentRecord( KUINT32 GroupBitField, const EntityIdentifier & ID,
                           KUINT8 DeviceID, KUINT8 LineID );

    virtual ~GroupAssignmentRecord( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupAssignmentRecord::SetGroupBitField
    //              KDIS::DATA_TYPE::GroupAssignmentRecord::GetGroupBitField
    // Description: Sets the group/s the Entity will belong to.
    //              Each group is represented by a single bit, 1 indicates membership of the group.
    //              Exception thrown if a bit greater than 31 is specified in Group.
    // Parameter:   KUINT32 AllGroups, void, KUINT8 Group
    // Parameter:   KBOOL InGroup = true
    //************************************
    void SetGroupBitField( KUINT32 AllGroups );
    KUINT32 GetGroupBitField() const;
    void SetGroupBitField( KUINT8 Group, KBOOL InGroup = true ) throw( KException );
    KBOOL IsGroupBitSet( KUINT8 Group ) const throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupAssignmentRecord::SetDestinationEntityID
    //              KDIS::DATA_TYPE::GroupAssignmentRecord::GetDestinationEntityID
    // Description: Entity that is the recipient of the PDU.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetDestinationEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetDestinationEntityID() const;
    EntityIdentifier & GetDestinationEntityID();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupAssignmentRecord::SetDestinationCommDeviceID
    //              KDIS::DATA_TYPE::GroupAssignmentRecord::GetDestinationCommDeviceID
    // Description: Identifies the specific intercom device being interfaced
    //              and/or simulated within an entity.
    //              All devices on an entity must have a unique ID.
    //              Set to 0 if the entity does not have a simulated device.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetDestinationCommDeviceID( KUINT16 ID );
    KUINT16 GetDestinationCommDeviceID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupAssignmentRecord::SetDestinationLineID
    //              KDIS::DATA_TYPE::GroupAssignmentRecord::GetDestinationLineID
    // Description: Identifies the line number to which this intercom control refers.
    //              E.G. For a intercom device with a single line the value would be 1.
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetDestinationLineID( KUINT8 ID );
    KUINT8 GetDestinationLineID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupAssignmentRecord::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupAssignmentRecord::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupAssignmentRecord::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GroupAssignmentRecord & Value ) const;
    KBOOL operator != ( const GroupAssignmentRecord & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
