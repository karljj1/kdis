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
    class:      Record_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    11/05/2009
    author:     Karl Jones

    purpose:    Contains information issued in response to a Record Query-R PDU
                or Set Record-R PDU.
    size:       320 bits/ 40 octets - not including record set sizes
*********************************************************************/

#pragma once

#include "./Set_Record_R_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::ENUMS::EventType;

class KDIS_EXPORT Record_R_PDU : public Set_Record_R_PDU
{
protected:

    KUINT16 m_ui16EvntTyp;

    KUINT32 m_ui32SrlNm;

public:

    static const KUINT16 RECORD_R_PDU_SIZE = 40;

    Record_R_PDU( void );

    Record_R_PDU( KDataStream & stream ) throw( KException );

    Record_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID, KUINT32 RequestID,
                  RequiredReliabilityService RRS, EventType ET, KUINT32 ResponseSerialNumber );

    virtual ~Record_R_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Record_R_PDU::SetEventType
    //              KDIS::PDU::Record_R_PDU::GetEventType
    // Description: Event type
    // Parameter:   EventType ET, void
    //************************************
    void SetEventType( EventType ET );
    EventType GetEventType() const;

    //************************************
    // FullName:    KDIS::PDU::Record_R_PDU::SetResponseSerialNumber
    //              KDIS::PDU::Record_R_PDU::GetResponseSerialNumber
    // Description: Used to indicate the serial number of the
    //              Record-R PDU when more than one PDU is used
    //              to report record values.
    // Parameter:   KUINT32 RSN, void
    //************************************
    void SetResponseSerialNumber( KUINT32 RSN );
    KUINT32 GetResponseSerialNumber() const;

    //************************************
    // FullName:    KDIS::PDU::Record_R_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Record_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Record_R_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Record_R_PDU & Value ) const;
    KBOOL operator != ( const Record_R_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
