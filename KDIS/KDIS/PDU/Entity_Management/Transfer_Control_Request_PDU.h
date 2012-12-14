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

    EntityIdentifier m_TrnsEntID;

    KUINT32 m_ui32NumRecSets;

    vector<RecordSet> m_vRecs;

public:

    static const KUINT16 TRANSFER_CONTROL_REQUEST_PDU_SIZE = 40; // Min size

    Transfer_Control_Request_PDU( void );

    Transfer_Control_Request_PDU( KDataStream & stream ) throw( KException );

    Transfer_Control_Request_PDU( KUINT32 ReqID, RequiredReliabilityService RRS, TransferType TT,
                                  const EntityIdentifier & TrnsEntID );

    virtual ~Transfer_Control_Request_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::SetRequestID
    //              KDIS::PDU::Transfer_Control_Request_PDU::GetRequestID
    // Description: Identifies the transfer of control request being requested.
    // Parameter:   KUINT32 ID, void
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::SetRequiredReliabilityService
    //              KDIS::PDU::Transfer_Control_Request_PDU::GetRequiredReliabilityService
    // Description: specifies the required level of reliability service to be
    //              used for this transaction/PDU.
    // Parameter:   RequiredReliabilityService RRS, void
    //************************************
    void SetRequiredReliabilityService( RequiredReliabilityService RRS );
    RequiredReliabilityService GetRequiredReliabilityService() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::SetTransferType
    //              KDIS::PDU::Transfer_Control_Request_PDU::GetTransferType
    // Description: Type of transfer desired.
    // Parameter:   TransferType TT, void
    //************************************
    void SetTransferType( TransferType TT );
    TransferType GetTransferType() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::SetTransferEntityID
    //              KDIS::PDU::Transfer_Control_Request_PDU::GetTransferEntityID
    // Description: Identifies the entity for which control is being
    //              requested to transfer.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetTransferEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetTransferEntityID() const;
    EntityIdentifier & GetTransferEntityID();

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
    void AddRecordSet( const RecordSet & RS );
    void SetRecordSets( const vector<RecordSet> & RS );
    const vector<RecordSet> & GetRecordSets() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Transfer_Control_Request_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
