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
    class:      Repair_Response_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    When a receiving entity receives a repair complete PDU
                from its repairing entity, the receiving entity shall acknowledge
                the reapir by issuing a repair response PDU.
    Size:       224 bits / 28 octets
*********************************************************************/

#pragma once

#include "./Logistics_Header.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Repair_Response_PDU : public Logistics_Header
{
protected:

    KUINT8 m_ui8RepairResult;

    KUINT8 m_ui8Padding;

    KUINT16 m_ui16Padding;

public:

    static const KUINT16 REPAIR_RESPONSE_PDU_SIZE = 28;

    Repair_Response_PDU();

    Repair_Response_PDU( KDataStream & stream ) throw( KException );

	Repair_Response_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Repair_Response_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & SupplyingEntityID,
		                 KDIS::DATA_TYPE::ENUMS::RepairResult RR );

    virtual ~Repair_Response_PDU();

    //************************************
    // FullName:    KDIS::PDU::Repair_Response_PDU::SetRepairResult
    //              KDIS::PDU::Repair_Response_PDU::GetRepairResult
    // Description: Specifies the result of a previous repair completed PDU
    // Parameter:   RepairResult RR
    //************************************
	void SetRepairResult( KDIS::DATA_TYPE::ENUMS::RepairResult RR );
    KDIS::DATA_TYPE::ENUMS::RepairResult GetRepairResult() const;

    //************************************
    // FullName:    KDIS::PDU::Repair_Response_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Repair_Response_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Repair_Response_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Repair_Response_PDU & Value ) const;
    KBOOL operator != ( const Repair_Response_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
