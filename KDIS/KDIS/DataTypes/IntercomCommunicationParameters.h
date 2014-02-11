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

class KDIS_EXPORT IntercomCommunicationParameters : public DataTypeBase
{
protected:

    KUINT16 m_ui16Type;

    KUINT16 m_ui16Length;

    DataTypeBase * m_pRecord;

    KBOOL m_bMemoryManage; // If we create the pointer we should delete it

public:

    static const KUINT16 INTERCOM_COMMS_PARAM_SIZE = 4;

    IntercomCommunicationParameters();

    IntercomCommunicationParameters( KDataStream & stream )throw( KException );

    IntercomCommunicationParameters( EntityDestinationRecord * EDR );

    IntercomCommunicationParameters( GroupDestinationRecord * GDR );

    IntercomCommunicationParameters( GroupAssignmentRecord * GAR );

    virtual ~IntercomCommunicationParameters();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IntercomCommunicationParameters::GetRecordType
    // Description: Identifies the additional parameters type.
    //************************************
    KDIS::DATA_TYPE::ENUMS::AdditionalIntrCommParamType GetRecordType() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS
