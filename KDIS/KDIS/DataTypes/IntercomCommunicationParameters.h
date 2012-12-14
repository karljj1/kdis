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
    class:      IntercomCommunicationParameters
    created:    2009/02/01
    author:     Karl Jones

    purpose:    Additional parameters for the Intercom Control PDU.
    size:       4 bits / 4 octets - header only
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EntityDestinationRecord.h"
#include "./GroupDestinationRecord.h"
#include "./GroupAssignmentRecord.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::AdditionalIntrCommParamType;

class KDIS_EXPORT IntercomCommunicationParameters : public DataTypeBase
{
protected:

    KUINT16 m_ui16Type;

    KUINT16 m_ui16Length;

    DataTypeBase * m_pRecord;

    KBOOL m_bMemoryManage; // If we create the pointer we should delete it

public:

    static const KUINT16 INTERCOM_COMMS_PARAM_SIZE = 4;

    IntercomCommunicationParameters( void );

    IntercomCommunicationParameters( KDataStream & stream )throw( KException );

    IntercomCommunicationParameters( EntityDestinationRecord * EDR );

    IntercomCommunicationParameters( GroupDestinationRecord * GDR );

    IntercomCommunicationParameters( GroupAssignmentRecord * GAR );

    virtual ~IntercomCommunicationParameters( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IntercomCommunicationParameters::GetRecordType
    // Description: Identifies the additional parameters type.
    //************************************
    AdditionalIntrCommParamType GetRecordType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IntercomCommunicationParameters::GetLength
    // Description: Length of the RECORD parameters, does not include size of type and
    //              length field.
    //************************************
    KUINT16 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IntercomCommunicationParameters::SetRecord
    //              KDIS::DATA_TYPE::IntercomCommunicationParameters::GetRecord
    // Description: Set the record. GetRecord will return NULL if no record is stored.
    //              Use GetType to know what record type to cast the returned pointer to.
    // Parameter:   ...Record *
    //************************************
    void SetRecord( EntityDestinationRecord * EDR );
    void SetRecord( GroupDestinationRecord * GDR );
    void SetRecord( GroupAssignmentRecord * GAR );
    const DataTypeBase * GetRecord() const;
    DataTypeBase * GetRecord();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IntercomCommunicationParameters::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IntercomCommunicationParameters::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IntercomCommunicationParameters::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IntercomCommunicationParameters & Value ) const;
    KBOOL operator != ( const IntercomCommunicationParameters & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
