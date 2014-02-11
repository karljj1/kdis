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
    class:      Repair_Complete_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Repair Complete PDU
    Size:       224 bits / 28 octets
*********************************************************************/

#pragma once

#include "./Logistics_Header.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Repair_Complete_PDU : public Logistics_Header
{
protected:

    KUINT16 m_ui16Repair;

    KUINT16 m_ui16Padding;

public:

    static const KUINT16 REPAIR_COMPLETE_PDU_SIZE = 28;

    Repair_Complete_PDU();

    Repair_Complete_PDU( KDataStream & stream ) throw( KException );

	Repair_Complete_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Repair_Complete_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & SupplyingEntityID,
		                 KDIS::DATA_TYPE::ENUMS::RepairTypePerformed RTP );

    virtual ~Repair_Complete_PDU();

    //************************************
    // FullName:    KDIS::PDU::Repair_Complete_PDU::SetRepairTypePerformed
    //              KDIS::PDU::Repair_Complete_PDU::GetRepairTypePerformed
    // Description: Enumeration to describe the type of repair provided
    // Parameter:   RepairTypePerformed RTP, void
    //************************************
    void SetRepairTypePerformed( KDIS::DATA_TYPE::ENUMS::RepairTypePerformed RTP );
    KDIS::DATA_TYPE::ENUMS::RepairTypePerformed GetRepairTypePerformed() const;

    //************************************
    // FullName:    KDIS::PDU::Repair_Complete_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Repair_Complete_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Repair_Complete_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Repair_Complete_PDU & Value ) const;
    KBOOL operator != ( const Repair_Complete_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
