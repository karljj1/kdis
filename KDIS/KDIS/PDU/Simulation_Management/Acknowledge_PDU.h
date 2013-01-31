/*********************************************************************
Copyright 2013 KDIS
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
    class:      Acknowledge_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/10/19
    author:     Karl Jones

    purpose:    Sent to acknowledges receipt of a Start/Resume PDU, Stop/Freeze PDU,
                Create Entity PDU or Remove Entity PDU.
    size:       256 bits / 32 octets
*********************************************************************/

#pragma once

#include "./Simulation_Management_Header.h"
#include "./Create_Entity_PDU.h"
#include "./Remove_Entity_PDU.h"
#include "./Start_Resume_PDU.h"
#include "./Stop_Freeze_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::ENUMS::AcknowledgeFlag;
using KDIS::DATA_TYPE::ENUMS::AcknowledgeResponseFlag;

class KDIS_EXPORT Acknowledge_PDU : public Simulation_Management_Header
{
protected:

    KUINT16 m_ui16AcknowledgeFlag;

    KUINT16 m_ui16ResponseFlag;

    KUINT32 m_ui32RequestID;

public:

    static const KUINT16 ACKNOWLEDGE_PDU_SIZE = 32;

    Acknowledge_PDU( void );

    Acknowledge_PDU( KDataStream & stream ) throw( KException );

    Acknowledge_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                     AcknowledgeFlag AF, AcknowledgeResponseFlag ARF, KUINT32 RequestID );

    Acknowledge_PDU( const Simulation_Management_Header & SimMgrHeader, AcknowledgeFlag AF,
                     AcknowledgeResponseFlag ARF, KUINT32 RequestID );

    // Generate a response to a specific PDU
    Acknowledge_PDU( const Create_Entity_PDU & pdu, AcknowledgeResponseFlag ARF );
    Acknowledge_PDU( const Remove_Entity_PDU & pdu, AcknowledgeResponseFlag ARF );
    Acknowledge_PDU( const Start_Resume_PDU  & pdu, AcknowledgeResponseFlag ARF );
    Acknowledge_PDU( const Stop_Freeze_PDU   & pdu, AcknowledgeResponseFlag ARF );

    virtual ~Acknowledge_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Acknowledge_PDU::SetAcknowledgeFlag
    //              KDIS::PDU::Acknowledge_PDU::GetAcknowledgeFlag
    // Description: Indicates the type of message being acknowledged
    // Parameter:   AcknowledgeFlag AF, void
    //************************************
    void SetAcknowledgeFlag( AcknowledgeFlag AF );
    AcknowledgeFlag GetAcknowledgeFlag() const;

    //************************************
    // FullName:    KDIS::PDU::Acknowledge_PDU::SetAcknowledgeResponseFlag
    //              KDIS::PDU::Acknowledge_PDU::GetAcknowledgeResponseFlag
    // Description: Indicates if the receiving entity is able to comply with the request
    // Parameter:   AcknowledgeResponseFlag ARF
    //************************************
    void SetAcknowledgeResponseFlag( AcknowledgeResponseFlag ARF );
    AcknowledgeResponseFlag GetAcknowledgeResponseFlag() const;

    //************************************
    // FullName:    KDIS::PDU::Acknowledge_PDU::SetRequestID
    //              KDIS::PDU::Acknowledge_PDU::GetRequestID
    // Description: Request ID
    // Parameter:   KUINT32 ID, void
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Acknowledge_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Acknowledge_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Acknowledge_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Acknowledge_PDU & Value ) const;
    KBOOL operator != ( const Acknowledge_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
