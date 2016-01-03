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
    class:      EnvironmentRecord
    created:    18/08/2009
    author:     Karl Jones

    purpose:    This is the base class for all state and geometry records
                used in the Environmental_Process_PDU.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./FactoryDecoder.h"
#include "./../Extras/KRef_Ptr.h"

namespace KDIS {
namespace DATA_TYPE {

/************************************************************************/
// Define the type of pointer we are using for VariableDatum Records,
// do we want a weak reference or a ref counter?
// By default we use a ref pointer, however if you want to use a standard
// pointer or one of your own then simply change it below.
/************************************************************************/
class EnvironmentRecord;
typedef KDIS::UTILS::KRef_Ptr<EnvironmentRecord> EnvironmentRecordPtr; // Ref counter
//typedef EnvironmentRecord* EnvironmentRecordPtr; // Weak ref

class KDIS_EXPORT EnvironmentRecord : public DataTypeBase, public FactoryDecoderUser<EnvironmentRecord>
{
protected:

    KUINT32 m_ui32EnvRecTyp;

    KUINT16 m_ui16Length;

    KUINT8 m_ui8Index;

    KUINT8 m_ui8Padding;

public:

    static const KUINT16 ENVIRONMENT_RECORD_SIZE = 8;

    EnvironmentRecord();

    virtual ~EnvironmentRecord();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentRecord::GetEnvironmentRecordType
    // Description: Specifies the record type.
    // Parameter:   EnvironmentRecordType RT, void
    //************************************
    KDIS::DATA_TYPE::ENUMS::EnvironmentRecordType GetEnvironmentRecordType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentRecord::GetLength
    // Description: Specifies the length in bits of the Environment record.
    //************************************
    virtual KUINT16 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentRecord::SetIndex
    //              KDIS::DATA_TYPE::EnvironmentRecord::GetIndex
    // Description: Identifies the sequentially numbered record index.
    // Parameter:   KUINT8 I, void
    //************************************
    void SetIndex( KUINT8 I );
    KUINT8 GetIndex() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentRecord::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentRecord::FactoryDecodeEnvironmentRecord
    // Description: Decode method for decoding any EnvironmentRecord child classes.
	//				First checks for a custom decode, if one can not be found then uses one of the KDIS EnvironmentRecord data types.
    //              Throws exception for unknown records(UNSUPPORTED_DATATYPE) or when stream is
    //              too small(NOT_ENOUGH_DATA_IN_BUFFER).
    // Parameter:   KDataStream & stream
    //************************************
    static EnvironmentRecordPtr FactoryDecodeEnvironmentRecord(  KDataStream & stream ) throw( KException );

    KBOOL operator == ( const EnvironmentRecord & Value )const;
    KBOOL operator != ( const EnvironmentRecord & Value )const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
