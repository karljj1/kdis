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
    class:      IO_Action_PDU
    DIS:        (7) 1278.1-2012
    created:    12/11/2010
    author:     Karl Jones

    purpose:    The information operations effects on a communications network
                shall be conveyed using the Information Operations Action PDU.
                This PDU may either be an order that affected IO simulations
                are required to accept and process regarding the IO affect on
                their system and communications network or may be a report of
                an IO effect initiated or terminated, or may provide the sender's
                perception of the effect of an IO attack.
                An IO simulation modeling a system or communications network uses
                the data in the IO Action PDU to affect the model's behavior.
    Size:       448 bits / 56 octets - min size not including standard variables
*********************************************************************/

#pragma once

#include "./IO_Header.h"

// Standard Variable Records
#include "./../../DataTypes/IOCommunicationsNode.h"
#include "./../../DataTypes/IOEffect.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT IO_Action_PDU : public IO_Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_RecEntityID;

    KUINT32 m_ui32ReqId;

    KUINT16 m_ui16WrTyp;

    KUINT16 m_ui16SimSrc;

    KUINT16 m_ui16ActTyp;

    KUINT16 m_ui16ActPhs;

    KUINT32 m_ui32Padding;

    KDIS::DATA_TYPE::EntityIdentifier m_AtkEntityID;

    KDIS::DATA_TYPE::EntityIdentifier m_TgtEntityID;

    KUINT16 m_ui16Padding;

    KUINT16 m_ui16NumStdVarRec;

	std::vector<KDIS::DATA_TYPE::StdVarPtr> m_vStdVarRecs;

public:

    static const KUINT16 IO_ACTION_PDU_SIZE = 56;

    IO_Action_PDU();

	IO_Action_PDU( KDataStream & stream ) throw( KException );

	IO_Action_PDU( const Header & H, KDataStream & stream ) throw( KException );

    IO_Action_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OrigID, const KDIS::DATA_TYPE::EntityIdentifier & RecvID, KUINT32 ReqID,
                   KDIS::DATA_TYPE::ENUMS::WarfareType WT, KUINT16 SimSrc, KDIS::DATA_TYPE::ENUMS::ActionType AT, KDIS::DATA_TYPE::ENUMS::ActionPhase AP,
                   const KDIS::DATA_TYPE::EntityIdentifier & AtkID, const KDIS::DATA_TYPE::EntityIdentifier & TgtID );

    virtual ~IO_Action_PDU();

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetReceivingEntityID
    //              KDIS::PDU::IO_Action_PDU::GetReceivingEntityID
    // Description: Receiving Entity ID.
    //              The simulation to which this PDU is addressed,
    //              if applicable.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetReceivingEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetReceivingEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetReceivingEntityID();

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetRequestID
    //              KDIS::PDU::IO_Action_PDU::GetRequestID
    // Description: Request ID. The request number for this IO Action PDU.
    // Parameter:   KUINT32 ID
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetWarfareType
    //              KDIS::PDU::IO_Action_PDU::GetWarfareType
    // Description: Identifies the type of IO warfare.
    // Parameter:   WarfareType WT
    //************************************
    void SetWarfareType( KDIS::DATA_TYPE::ENUMS::WarfareType WT );
    KDIS::DATA_TYPE::ENUMS::WarfareType GetWarfareType() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetSimulationSource
    //              KDIS::PDU::IO_Action_PDU::GetSimulationSource
    // Description: Identifies the name of the simulation model issuing this PDU.
    //              0       No statement.
    //              1-200   Reserved for future Io simulation sources.
    //              201-255 Reserved for United States IO Simulation Sources –
    //                      See applicable agreement or the organizers of the event
    //                      (training, exercise, etc) in which information operations
    //                      is included.
    // Parameter:   KUINT16 SS
    //************************************
    void SetSimulationSource( KUINT16 SS );
    KUINT16 GetSimulationSource() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetActionType
    //              KDIS::PDU::IO_Action_PDU::GetActionType
    // Description: Identifies the type of IO action.
    // Parameter:   ActionType AT
    //************************************
    void SetActionType( KDIS::DATA_TYPE::ENUMS::ActionType AT );
    KDIS::DATA_TYPE::ENUMS::ActionType GetActionType() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetActionPhase
    //              KDIS::PDU::IO_Action_PDU::GetActionPhase
    // Description: Identifies the Phase of IO action.
    // Parameter:   ActionPhase AP
    //************************************
    void SetActionPhase( KDIS::DATA_TYPE::ENUMS::ActionPhase AP );
    KDIS::DATA_TYPE::ENUMS::ActionPhase GetActionPhase() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetAttackerEntityID
    //              KDIS::PDU::IO_Action_PDU::GetAttackerEntityID
    // Description: Identifies the IO Attacker Entity ID.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetAttackerEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetAttackerEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetAttackerEntityID();

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetPrimaryTargetEntityID
    //              KDIS::PDU::IO_Action_PDU::GetPrimaryTargetEntityID
    // Description: Identifies the IO Primary Target Entity ID.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetPrimaryTargetEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetPrimaryTargetEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetPrimaryTargetEntityID();

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::GetNumberOfIORecords
    // Description: Indicates the number of IO standard variable records included.
    //************************************
    KUINT16 GetNumberOfIORecords() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::AddStandardVariableRecord
    //              KDIS::PDU::IO_Action_PDU::SetStandardVariableRecords
    //              KDIS::PDU::IO_Action_PDU::GetStandardVariableRecords
    //              KDIS::PDU::IO_Action_PDU::ClearStandardVariableRecords
    // Description: The following Standard Records currently exist:
    //              -   IOCommunicationsNode
    //              -   IOEffect
    // Parameter:   StdVarPtr SVR, const vector<StdVarPtr> & SVR
    //************************************
    void AddStandardVariableRecord( KDIS::DATA_TYPE::StdVarPtr SVR );
	void SetStandardVariableRecords( const std::vector<KDIS::DATA_TYPE::StdVarPtr> & SVR );
	const std::vector<KDIS::DATA_TYPE::StdVarPtr> & GetStandardVariableRecords() const;
    void ClearStandardVariableRecords();

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IO_Action_PDU & Value ) const;
    KBOOL operator != ( const IO_Action_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
