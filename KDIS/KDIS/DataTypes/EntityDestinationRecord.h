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

    EntityDestinationRecord();

    EntityDestinationRecord( KDataStream & stream )throw( KException );

    EntityDestinationRecord( const EntityIdentifier & ID, KUINT16 CommDeviceID, KUINT8 LineID,
                             KUINT8 Priority, KDIS::DATA_TYPE::ENUMS::LineStateCommand LSC );

    virtual ~EntityDestinationRecord();

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
    void SetLineStateCommand( KDIS::DATA_TYPE::ENUMS::LineStateCommand LSC );
    KDIS::DATA_TYPE::ENUMS::LineStateCommand GetLineStateCommand() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS
