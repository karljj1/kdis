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
    class:      Acknowledge_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    23:03:2009
    author:     Karl Jones

    purpose:    Sent to acknowledges receipt of a Start/Resume-R PDU, Stop/Freeze-R PDU,
                Create Entity-R PDU or Remove Entity-R PDU.
    size:       256 bits / 32 octets
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Acknowledge_PDU.h"
#include "./Create_Entity_R_PDU.h"
#include "./Remove_Entity_R_PDU.h"
#include "./Start_Resume_R_PDU.h"
#include "./Stop_Freeze_R_PDU.h"
#include "./../Entity_Management/Transfer_Control_Request_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::ENUMS::AcknowledgeFlag;
using KDIS::DATA_TYPE::ENUMS::AcknowledgeResponseFlag;

class KDIS_EXPORT Acknowledge_R_PDU : public Acknowledge_PDU
{
public:

    static const KUINT16 ACKNOWLEDGE_R_PDU_SIZE = 32;

    Acknowledge_R_PDU( void );

    Acknowledge_R_PDU( KDataStream & stream ) throw( KException );

    Acknowledge_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                       AcknowledgeFlag AF, AcknowledgeResponseFlag ARF, KUINT32 RequestID );

    Acknowledge_R_PDU( const Simulation_Management_Header & SimMgrHeader, AcknowledgeFlag AF,
                       AcknowledgeResponseFlag ARF, KUINT32 RequestID );

    // Generate a response to a specific PDU
    Acknowledge_R_PDU( const Create_Entity_R_PDU & pdu, AcknowledgeResponseFlag ARF );
    Acknowledge_R_PDU( const Remove_Entity_R_PDU & pdu, AcknowledgeResponseFlag ARF );
    Acknowledge_R_PDU( const Start_Resume_R_PDU  & pdu, AcknowledgeResponseFlag ARF );
    Acknowledge_R_PDU( const Stop_Freeze_R_PDU   & pdu, AcknowledgeResponseFlag ARF );
    Acknowledge_R_PDU( const Transfer_Control_Request_PDU & pdu, AcknowledgeResponseFlag ARF );

    virtual ~Acknowledge_R_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Acknowledge_R_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    KBOOL operator == ( const Acknowledge_R_PDU & Value ) const;
    KBOOL operator != ( const Acknowledge_R_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
