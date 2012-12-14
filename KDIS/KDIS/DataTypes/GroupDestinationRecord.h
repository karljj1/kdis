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
    class:      GroupDestinationRecord
    created:    2009/02/05
    author:     Karl Jones

    purpose:    Used to send an Intercom Control PDU to an arbitrary group.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include <bitset>

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::LineStateCommand;

class KDIS_EXPORT GroupDestinationRecord :  public DataTypeBase
{
protected:

    KUINT32 m_ui32GrpBtField;

    KUINT8 m_ui8DstPriority;

    KUINT8 m_ui8LnStCmd;

    KUINT16 m_ui16Padding1;

public:

    static const KUINT16 GROUP_DESTINATION_RECORD_SIZE = 8;

    GroupDestinationRecord( void );

    GroupDestinationRecord( KDataStream & stream )throw( KException );

    GroupDestinationRecord( KUINT32 GroupBitField, KUINT8 Priority, LineStateCommand LSC );

    virtual ~GroupDestinationRecord( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupDestinationRecord::SetGroupBitField
    //              KDIS::DATA_TYPE::GroupDestinationRecord::GetGroupBitField
    // Description: Sets the group/s the Intercom PDU applies to.
    //              Each group is represented by a single bit, 1 indicates the PDU applies to this group.
    //              Exception thrown if a bit greater than 31 is specified in Group.
    // Parameter:   KUINT32 AllGroups, void, KUINT8 Group
    // Parameter:   KBOOL InGroup = true
    //************************************
    void SetGroupBitField( KUINT32 AllGroups );
    KUINT32 GetGroupBitField() const;
    void SetGroupBitField( KUINT8 Group, KBOOL InGroup = true ) throw( KException );
    KBOOL IsGroupBitSet( KUINT8 Group ) const throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupDestinationRecord::SetDestinationPriority
    //              KDIS::DATA_TYPE::GroupDestinationRecord::GetDestinationPriority
    // Description: Identifies the priority of this message relative to transmissions
    //              from other intercom devices on the same channel.
    //              The value 0 is reserved.
    //              1 = highest priority, 255 = lowest priority.
    // Parameter:   KUINT8 TP, void
    //************************************
    void SetDestinationPriority( KUINT8 TP );
    KUINT8 GetDestinationPriority() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupDestinationRecord::SetLineStateCommand
    //              KDIS::DATA_TYPE::GroupDestinationRecord::GetLineStateCommand
    // Description: When the Control Type of the Intercom Control PDU is
    //              request or acknowledge, this field shall specify the
    //              detailed type requested. Otherwise set to 0.
    // Parameter:   LineStateCommand LSC, void
    //************************************
    void SetLineStateCommand( LineStateCommand LSC );
    LineStateCommand GetLineStateCommand() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupDestinationRecord::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupDestinationRecord::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupDestinationRecord::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GroupDestinationRecord & Value ) const;
    KBOOL operator != ( const GroupDestinationRecord & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
