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
