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

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::ENUMS::RepairResult;

class KDIS_EXPORT Repair_Response_PDU : public Logistics_Header
{
protected:

    KUINT8 m_ui8RepairResult;

    KUINT8 m_ui8Padding;

    KUINT16 m_ui16Padding;

public:

    static const KUINT16 REPAIR_RESPONSE_PDU_SIZE = 28;

    Repair_Response_PDU( void );

    Repair_Response_PDU( KDataStream & stream ) throw( KException );

    Repair_Response_PDU( const EntityIdentifier & ReceivingEntityID, const EntityIdentifier & SupplyingEntityID,
                         RepairResult RR );

    virtual ~Repair_Response_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Repair_Response_PDU::SetRepairResult
    //              KDIS::PDU::Repair_Response_PDU::GetRepairResult
    // Description: Specifies the result of a previous repair completed PDU
    // Parameter:   RepairResult RR
    //************************************
    void SetRepairResult( RepairResult RR );
    RepairResult GetRepairResult() const;

    //************************************
    // FullName:    KDIS::PDU::Repair_Response_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Repair_Response_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
