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

class KDIS_EXPORT Event_Report_PDU : public Comment_PDU
{
protected:

    KUINT32 m_ui32EventType;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 EVENT_REPORT_PDU_SIZE = 40;

    Event_Report_PDU();

	Event_Report_PDU( const Header & H );

    Event_Report_PDU( KDataStream & stream ) throw( KException );

	Event_Report_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Event_Report_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID,
		              KDIS::DATA_TYPE::ENUMS::EventType ET );

    virtual ~Event_Report_PDU();

    //************************************
    // FullName:    KDIS::PDU::Event_Report_PDU::SetEventType
    //              KDIS::PDU::Event_Report_PDU::GetEventType
    // Description: Event type
    // Parameter:   EventType ET
    //************************************
	void SetEventType( KDIS::DATA_TYPE::ENUMS::EventType ET );
	KDIS::DATA_TYPE::ENUMS::EventType GetEventType() const;

    //************************************
    // FullName:    KDIS::PDU::Event_Report_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Event_Report_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
