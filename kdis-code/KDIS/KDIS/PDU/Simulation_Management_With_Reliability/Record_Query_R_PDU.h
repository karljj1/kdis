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
    class:      Record_Query_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    12:05:2009
    author:     Karl Jones

    purpose:    A request for one or more records of data from an entity.
    size:       320 bits/ 40 octets - not including record set sizes
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Simulation_Management_Header.h"
#include "./Reliability_Header.h"
#include "./../../DataTypes/RecordSet.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::ENUMS::EventType;
using std::vector;

class KDIS_EXPORT Record_Query_R_PDU : public Simulation_Management_Header,
									   public Reliability_Header
{
protected:

    KUINT32 m_ui32RqId;

    KUINT16 m_ui16EvntTyp;

    KUINT32 m_ui32Time;

    KUINT32 m_ui32NumRecs;

    vector<KUINT32> m_vui32RecID;

public:

    static const KUINT16 RECORD_QUERY_R_PDU_SIZE = 40;

    Record_Query_R_PDU( void );

    Record_Query_R_PDU( KDataStream & stream ) throw( KException );

    Record_Query_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID, KUINT32 RequestID,
                        RequiredReliabilityService RRS, EventType ET, KUINT32 Time );

    virtual ~Record_Query_R_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::SetRequestID
    //              KDIS::PDU::Record_Query_R_PDU::GetRequestID
    // Description: Request ID
    // Parameter:   KUINT32 ID, void
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::SetEventType
    //              KDIS::PDU::Record_Query_R_PDU::GetEventType
    // Description: Event type
    // Parameter:   EventType ET, void
    //************************************
    void SetEventType( EventType ET );
    EventType GetEventType() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::SetTime
    //              KDIS::PDU::Record_Query_R_PDU::GetTime
    // Description: Specifies the time interval between issues of Record-R PDUs for periodic reporting.
    //              This value may also represent a specific time for time-based reporting.
    //              A value of zero in this field shall mean that the requested data should be sent
    //              once and not at any previously specified time interval.
    // Parameter:   KUINT32 T, void
    //************************************
    void SetTime( KUINT32 T );
    KUINT32 GetTime() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::GetNumberRecords
    // Description: Number of Record IDs.
    //************************************
    KUINT32 GetNumberRecords() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::AddRecordID
    //              KDIS::PDU::Record_Query_R_PDU::SetRecordIDs
    //              KDIS::PDU::Record_Query_R_PDU::GetRecordIDs
    // Description: Specifies the identification of the records for which information
    //              is requested.
    // Parameter:   vector<KUINT32> & ID, void
    //************************************
    void AddRecordID( const KUINT32 ID );
    void SetRecordIDs( const vector<KUINT32> & ID );
    const vector<KUINT32> & GetRecordIDs() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Record_Query_R_PDU & Value ) const;
    KBOOL operator != ( const Record_Query_R_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
