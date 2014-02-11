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
    class:      Record_Query_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    12/05/2009
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

class KDIS_EXPORT Record_Query_R_PDU : public Simulation_Management_Header,
									   public Reliability_Header
{
protected:

    KUINT32 m_ui32RqId;

    KUINT16 m_ui16EvntTyp;

    KUINT32 m_ui32Time;

    KUINT32 m_ui32NumRecs;

	std::vector<KUINT32> m_vui32RecID;

public:

    static const KUINT16 RECORD_QUERY_R_PDU_SIZE = 40;

    Record_Query_R_PDU();

    Record_Query_R_PDU( KDataStream & stream ) throw( KException );

	Record_Query_R_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Record_Query_R_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID, KUINT32 RequestID,
                        KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS, KDIS::DATA_TYPE::ENUMS::EventType ET, KUINT32 Time );

    virtual ~Record_Query_R_PDU();

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::SetRequestID
    //              KDIS::PDU::Record_Query_R_PDU::GetRequestID
    // Description: Request ID
    // Parameter:   KUINT32 ID
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::SetEventType
    //              KDIS::PDU::Record_Query_R_PDU::GetEventType
    // Description: Event type
    // Parameter:   EventType ET
    //************************************
    void SetEventType( KDIS::DATA_TYPE::ENUMS::EventType ET );
    KDIS::DATA_TYPE::ENUMS::EventType GetEventType() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::SetTime
    //              KDIS::PDU::Record_Query_R_PDU::GetTime
    // Description: Specifies the time interval between issues of Record-R PDUs for periodic reporting.
    //              This value may also represent a specific time for time-based reporting.
    //              A value of zero in this field shall mean that the requested data should be sent
    //              once and not at any previously specified time interval.
    // Parameter:   KUINT32 T
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
    // Parameter:   vector<KUINT32> & ID
    //************************************
    void AddRecordID( const KUINT32 ID );
	void SetRecordIDs( const std::vector<KUINT32> & ID );
	const std::vector<KUINT32> & GetRecordIDs() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Record_Query_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
