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
    class:      Event_Report_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2009/05/11
    author:     Karl Jones

    purpose:    Reports the occurrence of a significant event
                to the simulation manager.
    size:       320 bits/ 40 octets - not including variable param sizes
*********************************************************************/

#pragma once

#include "./Comment_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::ENUMS::EventType;

class KDIS_EXPORT Event_Report_PDU : public Comment_PDU
{
protected:

    KUINT32 m_ui32EventType;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 EVENT_REPORT_PDU_SIZE = 40;

    Event_Report_PDU( void );

    Event_Report_PDU( KDataStream & stream ) throw( KException );

    Event_Report_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                      EventType ET );

    virtual ~Event_Report_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Event_Report_PDU::SetEventType
    //              KDIS::PDU::Event_Report_PDU::GetEventType
    // Description: Event type
    // Parameter:   EventType ET, void
    //************************************
    void SetEventType( EventType ET );
    EventType GetEventType() const;

    //************************************
    // FullName:    KDIS::PDU::Event_Report_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Event_Report_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Event_Report_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Event_Report_PDU & Value ) const;
    KBOOL operator != ( const Event_Report_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
