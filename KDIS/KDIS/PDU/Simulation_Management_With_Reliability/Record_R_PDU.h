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

class KDIS_EXPORT Record_R_PDU : public Set_Record_R_PDU
{
protected:

    KUINT16 m_ui16EvntTyp;

    KUINT32 m_ui32SrlNm;

public:

    static const KUINT16 RECORD_R_PDU_SIZE = 40;

    Record_R_PDU();

    Record_R_PDU( KDataStream & stream ) throw( KException );

	Record_R_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Record_R_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID, KUINT32 RequestID,
                  KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS, KDIS::DATA_TYPE::ENUMS::EventType ET, KUINT32 ResponseSerialNumber );

    virtual ~Record_R_PDU();

    //************************************
    // FullName:    KDIS::PDU::Record_R_PDU::SetEventType
    //              KDIS::PDU::Record_R_PDU::GetEventType
    // Description: Event type
    // Parameter:   EventType ET
    //************************************
    void SetEventType( KDIS::DATA_TYPE::ENUMS::EventType ET );
    KDIS::DATA_TYPE::ENUMS::EventType GetEventType() const;

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
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Record_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
