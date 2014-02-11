/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

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

class KDIS_EXPORT GroupDestinationRecord :  public DataTypeBase
{
protected:

    KUINT32 m_ui32GrpBtField;

    KUINT8 m_ui8DstPriority;

    KUINT8 m_ui8LnStCmd;

    KUINT16 m_ui16Padding1;

public:

    static const KUINT16 GROUP_DESTINATION_RECORD_SIZE = 8;

    GroupDestinationRecord();

    GroupDestinationRecord( KDataStream & stream )throw( KException );

    GroupDestinationRecord( KUINT32 GroupBitField, KUINT8 Priority, KDIS::DATA_TYPE::ENUMS::LineStateCommand LSC );

    virtual ~GroupDestinationRecord();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupDestinationRecord::SetGroupBitField
    //              KDIS::DATA_TYPE::GroupDestinationRecord::GetGroupBitField
    // Description: Sets the group/s the Intercom PDU applies to.
    //              Each group is represented by a single bit, 1 indicates the PDU applies to this group.
    //              Exception thrown if a bit greater than 31 is specified in Group.
    // Parameter:   KUINT32 AllGroups, KUINT8 Group
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
    // Parameter:   KUINT8 TP
    //************************************
    void SetDestinationPriority( KUINT8 TP );
    KUINT8 GetDestinationPriority() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GroupDestinationRecord::SetLineStateCommand
    //              KDIS::DATA_TYPE::GroupDestinationRecord::GetLineStateCommand
    // Description: When the Control Type of the Intercom Control PDU is
    //              request or acknowledge, this field shall specify the
    //              detailed type requested. Otherwise set to 0.
    // Parameter:   LineStateCommand LSC
    //************************************
    void SetLineStateCommand( KDIS::DATA_TYPE::ENUMS::LineStateCommand LSC );
    KDIS::DATA_TYPE::ENUMS::LineStateCommand GetLineStateCommand() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS
