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

class KDIS_EXPORT Acknowledge_R_PDU : public Acknowledge_PDU
{
public:

    static const KUINT16 ACKNOWLEDGE_R_PDU_SIZE = 32;

    Acknowledge_R_PDU();

    Acknowledge_R_PDU( KDataStream & stream ) throw( KException );

	Acknowledge_R_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Acknowledge_R_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID,
                       KDIS::DATA_TYPE::ENUMS::AcknowledgeFlag AF, KDIS::DATA_TYPE::ENUMS::AcknowledgeResponseFlag ARF, KUINT32 RequestID );

    Acknowledge_R_PDU( const Simulation_Management_Header & SimMgrHeader, KDIS::DATA_TYPE::ENUMS::AcknowledgeFlag AF,
                       KDIS::DATA_TYPE::ENUMS::AcknowledgeResponseFlag ARF, KUINT32 RequestID );

    // Generate a response to a specific PDU
    Acknowledge_R_PDU( const Create_Entity_R_PDU & pdu, KDIS::DATA_TYPE::ENUMS::AcknowledgeResponseFlag ARF );
    Acknowledge_R_PDU( const Remove_Entity_R_PDU & pdu, KDIS::DATA_TYPE::ENUMS::AcknowledgeResponseFlag ARF );
    Acknowledge_R_PDU( const Start_Resume_R_PDU  & pdu, KDIS::DATA_TYPE::ENUMS::AcknowledgeResponseFlag ARF );
    Acknowledge_R_PDU( const Stop_Freeze_R_PDU   & pdu, KDIS::DATA_TYPE::ENUMS::AcknowledgeResponseFlag ARF );
    Acknowledge_R_PDU( const Transfer_Control_Request_PDU & pdu, KDIS::DATA_TYPE::ENUMS::AcknowledgeResponseFlag ARF );

    virtual ~Acknowledge_R_PDU();

    //************************************
    // FullName:    KDIS::PDU::Acknowledge_R_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    KBOOL operator == ( const Acknowledge_R_PDU & Value ) const;
    KBOOL operator != ( const Acknowledge_R_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
