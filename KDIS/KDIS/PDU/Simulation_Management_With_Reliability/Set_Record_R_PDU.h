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
    class:      Set_Record_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    12:05:2009
    author:     Karl Jones

    purpose:    Used when initializing or changing internal parameter.
    size:       288 bits/ 36 octets - not including record set sizes
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Simulation_Management_Header.h"
#include "./Reliability_Header.h"
#include "./../../DataTypes/RecordSet.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::RecordSet;
using KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService;
using std::vector;

class KDIS_EXPORT Set_Record_R_PDU : public Simulation_Management_Header,
    public Reliability_Header
{
protected:

    KUINT32 m_ui32RqId;

    KUINT32 m_ui32NumRecSets;

    vector<RecordSet> m_vRecs;

public:

    static const KUINT16 SET_RECORD_R_PDU_SIZE = 36;

    Set_Record_R_PDU( void );

    Set_Record_R_PDU( KDataStream & stream ) throw( KException );

    Set_Record_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                      KUINT32 RequestID, RequiredReliabilityService RRS );

    virtual ~Set_Record_R_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Set_Record_R_PDU::SetRequestID
    //              KDIS::PDU::Set_Record_R_PDU::GetRequestID
    // Description: Request ID
    // Parameter:   KUINT32 ID, void
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Set_Record_R_PDU::GetNumberOfRecords
    // Description: Returns number of records.
    //************************************
    KUINT32 GetNumberOfRecords() const;

    //************************************
    // FullName:    KDIS::PDU::Set_Record_R_PDU::AddRecordSet
    //              KDIS::PDU::Set_Record_R_PDU::SetRecordSets
    //              KDIS::PDU::Set_Record_R_PDU::GetRecordSets
    // Description:
    // Parameter:   const RecordSet & RS, vector<RecordSet> & RC
    //************************************
    void AddRecordSet( const RecordSet & RS );
    void SetRecordSets( const vector<RecordSet> & RS );
    const vector<RecordSet> & GetRecordSets() const;

    //************************************
    // FullName:    KDIS::PDU::Set_Record_R_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Set_Record_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Set_Record_R_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Set_Record_R_PDU & Value ) const;
    KBOOL operator != ( const Set_Record_R_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
