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

using KDIS::DATA_TYPE::ENUMS::RecordID;
using std::vector;

class KDIS_EXPORT RecordSet : public DataTypeBase
{
protected:

    KUINT32 m_ui32RecID;

    KUINT32 m_ui32RecSetSerialNum;

    KUINT16 m_ui16RecLen;

    KUINT16 m_ui16RecCnt;

    vector<KUINT8> m_vui8RecVals;

public:

    static const KUINT16 RECORD_SET_SIZE = 12; // Min size

    RecordSet( void );

    RecordSet( KDataStream & stream )throw( KException );

    RecordSet( RecordID ID, KUINT32 SerialNum, const vector<KUINT8> & RecordValue,
               KUINT16 RecordCount );

    virtual ~RecordSet( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::SetRecordID
    //              KDIS::DATA_TYPE::RecordSet::GetRecordID
    // Description: Specifies the data structure used to convey
    //              the parameters values of the record.
    // Parameter:   RecordID ID, void
    //************************************
    void SetRecordID( RecordID ID );
    RecordID GetRecordID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RecordSet::SetSerialNumber
    //              KDIS::DATA_TYPE::RecordSet::GetSerialNumber
    // Description: Record serial number.
    // Parameter:   KUINT32 SN, void
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
    void SetRecordValues( const vector<KUINT8> & RV, KUINT16 RecCnt );
    const vector<KUINT8> & GetRecordValues() const;
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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
