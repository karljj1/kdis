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
    class:      IO_Action_PDU
    DIS:        (7) 1278.1-200x
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

using std::vector;
using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::StandardVariable;
using KDIS::DATA_TYPE::StdVarPtr;
using KDIS::DATA_TYPE::ENUMS::WarfareType;
using KDIS::DATA_TYPE::ENUMS::ActionType;
using KDIS::DATA_TYPE::ENUMS::ActionPhase;

class KDIS_EXPORT IO_Action_PDU : public IO_Header
{
protected:

    EntityIdentifier m_RecEntityID;

    KUINT32 m_ui32ReqId;

    KUINT16 m_ui16WrTyp;

    KUINT16 m_ui16SimSrc;

    KUINT16 m_ui16ActTyp;

    KUINT16 m_ui16ActPhs;

    KUINT32 m_ui32Padding;

    EntityIdentifier m_AtkEntityID;

    EntityIdentifier m_TgtEntityID;

    KUINT16 m_ui16Padding;

    KUINT16 m_ui16NumStdVarRec;

    vector<StdVarPtr> m_vStdVarRecs;

public:

    static const KUINT16 IO_ACTION_PDU_SIZE = 56;

    IO_Action_PDU( void );

    IO_Action_PDU( const EntityIdentifier & OrigID, const EntityIdentifier & RecvID, KUINT32 ReqID,
                   WarfareType WT, KUINT16 SimSrc, ActionType AT, ActionPhase AP,
                   const EntityIdentifier & AtkID, const EntityIdentifier & TgtID );

    IO_Action_PDU( KDataStream & stream ) throw( KException );

    virtual ~IO_Action_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetReceivingEntityID
    //              KDIS::PDU::IO_Action_PDU::GetReceivingEntityID
    // Description: Receiving Entity ID.
    //              The simulation to which this PDU is addressed,
    //              if applicable.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetReceivingEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetReceivingEntityID() const;
    EntityIdentifier & GetReceivingEntityID();

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
    void SetWarfareType( WarfareType WT );
    WarfareType GetWarfareType() const;

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
    void SetActionType( ActionType AT );
    ActionType GetActionType() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetActionPhase
    //              KDIS::PDU::IO_Action_PDU::GetActionPhase
    // Description: Identifies the Phase of IO action.
    // Parameter:   ActionPhase AP
    //************************************
    void SetActionPhase( ActionPhase AP );
    ActionPhase GetActionPhase() const;

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetAttackerEntityID
    //              KDIS::PDU::IO_Action_PDU::GetAttackerEntityID
    // Description: Identifies the IO Attacker Entity ID.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetAttackerEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetAttackerEntityID() const;
    EntityIdentifier & GetAttackerEntityID();

    //************************************
    // FullName:    KDIS::PDU::IO_Action_PDU::SetPrimaryTargetEntityID
    //              KDIS::PDU::IO_Action_PDU::GetPrimaryTargetEntityID
    // Description: Identifies the IO Primary Target Entity ID.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetPrimaryTargetEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetPrimaryTargetEntityID() const;
    EntityIdentifier & GetPrimaryTargetEntityID();

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
    void AddStandardVariableRecord( StdVarPtr SVR );
    void SetStandardVariableRecords( const vector<StdVarPtr> & SVR );
    const vector<StdVarPtr> & GetStandardVariableRecords() const;
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
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
