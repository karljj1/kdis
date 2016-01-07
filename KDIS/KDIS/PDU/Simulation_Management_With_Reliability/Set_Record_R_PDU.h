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

class KDIS_EXPORT Set_Record_R_PDU : public Simulation_Management_Header,
                                     public Reliability_Header
{
protected:

    KUINT32 m_ui32RqId;

    KUINT32 m_ui32NumRecSets;

    KUINT8 m_ui8Padding1;

    KUINT16 m_ui16Padding;

    KUINT32 m_ui32Padding;

	std::vector<KDIS::DATA_TYPE::RecordSet> m_vRecs;

public:

    static const KUINT16 SET_RECORD_R_PDU_SIZE = 40;

    Set_Record_R_PDU();

	Set_Record_R_PDU( const Header & H );

    Set_Record_R_PDU( KDataStream & stream ) throw( KException );

	Set_Record_R_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Set_Record_R_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID,
		KUINT32 RequestID, KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS );

    virtual ~Set_Record_R_PDU();

    //************************************
    // FullName:    KDIS::PDU::Set_Record_R_PDU::SetRequestID
    //              KDIS::PDU::Set_Record_R_PDU::GetRequestID
    // Description: Request ID
    // Parameter:   KUINT32 ID
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
    void AddRecordSet( const KDIS::DATA_TYPE::RecordSet & RS );
	void SetRecordSets( const std::vector<KDIS::DATA_TYPE::RecordSet> & RS );
	const std::vector<KDIS::DATA_TYPE::RecordSet> & GetRecordSets() const;

    //************************************
    // FullName:    KDIS::PDU::Set_Record_R_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Set_Record_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
