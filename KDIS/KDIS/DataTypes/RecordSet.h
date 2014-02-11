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
    class:      RecordSet
    created:    2009/03/14
    author:     Karl Jones

    purpose:    Record set contained within Record Specification.
    size:       96 bits / 12 octets - Min size
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT RecordSet : public DataTypeBase
{
protected:

    KUINT32 m_ui32RecID;

    KUINT32 m_ui32RecSetSerialNum;

    KUINT16 m_ui16RecLen;

    KUINT16 m_ui16RecCnt;

	std::vector<KUINT8> m_vui8RecVals;

public:

    static const KUINT16 RECORD_SET_SIZE = 12; // Min size

    RecordSet();

    RecordSet( KDataStream & stream )throw( KException );

	RecordSet( KDIS::DATA_TYPE::ENUMS::RecordID ID, KUINT32 SerialNum, 
		       const std::vector<KUINT8> & RecordValue, KUINT16 RecordCount );

    virtual ~RecordSet();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::SetRecordID
    //              KDIS::DATA_TYPE::RecordSet::GetRecordID
    // Description: Specifies the data structure used to convey
    //              the parameters values of the record.
    // Parameter:   RecordID ID
    //************************************
    void SetRecordID( KDIS::DATA_TYPE::ENUMS::RecordID ID );
    KDIS::DATA_TYPE::ENUMS::RecordID GetRecordID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::SetSerialNumber
    //              KDIS::DATA_TYPE::RecordSet::GetSerialNumber
    // Description: Record serial number.
    // Parameter:   KUINT32 SN
    //************************************
    void SetSerialNumber( KUINT32 SN );
    KUINT32 GetSerialNumber() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::GetRecordLength
    // Description: Specifies the total length in bytes/octets of the record set.
    //************************************
    KUINT16 GetRecordLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::SetRecordCount
    //              KDIS::DATA_TYPE::RecordSet::GetRecordCount
    // Description: Specifies the number of bits used in the record.
    // Parameter:   KUINT16 RC, void
    //************************************
    void SetRecordCount( KUINT16 RC );
    KUINT16 GetRecordCount() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::SetRecordValues
    //              KDIS::DATA_TYPE::RecordSet::GetRecordValues
    //              KDIS::DATA_TYPE::RecordSet::ClearRecordValues
    // Description: Contains the concatenated records of the format specified by the Record ID.
    //              You will need to set the record count, this is the number of bits in the
    //              record values parameter(RV) that are used.
    // Parameter:   vector<KUINT8> & RC, void
    // Parameter:   KUINT16 RecNt - Number of bits used by the record.
    //************************************
	void SetRecordValues( const std::vector<KUINT8> & RV, KUINT16 RecCnt );
	const std::vector<KUINT8> & GetRecordValues() const;
    void ClearRecordValues();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const RecordSet & Value ) const;
    KBOOL operator != ( const RecordSet & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
