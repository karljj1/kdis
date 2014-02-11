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
    class:      Transfer_Control_Request_PDU
    DIS:        (6) 1278.1A - 1998
    created:    2009/03/14
    author:     Karl Jones

    purpose:    Contains information initiating the dynamic allocation and
                control of simulation entities between two simulation applications.

                Note: Also known as Transfer Ownership PDU.

    size:       320 bits / 40 octets - min size
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Simulation_Management_Header.h"
#include "./../../DataTypes/RecordSet.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::RecordSet;
using KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService;
using KDIS::DATA_TYPE::ENUMS::TransferType;
using std::vector;

class KDIS_EXPORT Transfer_Control_Request_PDU : public Simulation_Management_Header
{
protected:

    KUINT32 m_ui32ReqID;

    KUINT8 m_ui8ReqRelSrv;

    KUINT8 m_ui8TrnTyp;

    KDIS::DATA_TYPE::EntityIdentifier m_TrnsEntID;

    KUINT32 m_ui32NumRecSets;

	std::vector<KDIS::DATA_TYPE::RecordSet> m_vRecs;

public:

    static const KUINT16 TRANSFER_CONTROL_REQUEST_PDU_SIZE = 40; // Min size

    Transfer_Control_Request_PDU();

    Transfer_Control_Request_PDU( KDataStream & stream ) throw( KException );

	Transfer_Control_Request_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Transfer_Control_Request_PDU( KUINT32 ReqID, KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS, KDIS::DATA_TYPE::ENUMS::TransferType TT,
                                  const KDIS::DATA_TYPE::EntityIdentifier & TrnsEntID );

    virtual ~Transfer_Control_Request_PDU();

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::SetRequestID
    //              KDIS::PDU::Transfer_Control_Request_PDU::GetRequestID
    // Description: Identifies the transfer of control request being requested.
    // Parameter:   KUINT32 ID
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::SetRequiredReliabilityService
    //              KDIS::PDU::Transfer_Control_Request_PDU::GetRequiredReliabilityService
    // Description: specifies the required level of reliability service to be
    //              used for this transaction/PDU.
    // Parameter:   RequiredReliabilityService RRS
    //************************************
    void SetRequiredReliabilityService( KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS );
    KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService GetRequiredReliabilityService() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::SetTransferType
    //              KDIS::PDU::Transfer_Control_Request_PDU::GetTransferType
    // Description: Type of transfer desired.
    // Parameter:   TransferType TT
    //************************************
    void SetTransferType( KDIS::DATA_TYPE::ENUMS::TransferType TT );
    KDIS::DATA_TYPE::ENUMS::TransferType GetTransferType() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::SetTransferEntityID
    //              KDIS::PDU::Transfer_Control_Request_PDU::GetTransferEntityID
    // Description: Identifies the entity for which control is being
    //              requested to transfer.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetTransferEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetTransferEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetTransferEntityID();

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::GetNumberOfRecords
    // Description: Returns number of records.
    //************************************
    KUINT32 GetNumberOfRecords() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::AddRecordSet
    //              KDIS::PDU::Transfer_Control_Request_PDU::SetRecordSets
    //              KDIS::PDU::Transfer_Control_Request_PDU::GetRecordSets
    // Description:
    // Parameter:   const RecordSet & RS, vector<RecordSet> & RC
    //************************************
    void AddRecordSet( const KDIS::DATA_TYPE::RecordSet & RS );
	void SetRecordSets( const std::vector<KDIS::DATA_TYPE::RecordSet> & RS );
	const std::vector<KDIS::DATA_TYPE::RecordSet> & GetRecordSets() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Transfer_Control_Request_PDU & Value ) const;
    KBOOL operator != ( const Transfer_Control_Request_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
