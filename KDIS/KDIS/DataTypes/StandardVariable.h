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
    class:      StandardVariable
    created:    17/11/2010
    author:     Karl Jones

    purpose:    Used by the Standard Variable Specification record.
                Provides base class for all standard variable records.

				Note: See FactoryDecoder for a guide to adding support for using your own VariableDatums. 

    size:       48 bits / 6 octets - not including record-specific fields or padding.
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./FactoryDecoder.h"
#include "./../Extras/KRef_Ptr.h"

namespace KDIS {
namespace DATA_TYPE {

/************************************************************************/
// Define the type of pointer we are using for StandardVariable Records,
// do we want a weak reference or a ref counter?
// By default we use a ref pointer, however if you want to use a standard
// pointer or one of your own then simply change it below.
/************************************************************************/
class StandardVariable;
typedef KDIS::UTILS::KRef_Ptr<StandardVariable> StdVarPtr; // Ref counter
//typedef StandardVariable* StdVarPtr; // Weak ref

class KDIS_EXPORT StandardVariable : public DataTypeBase, public FactoryDecoderUser<StandardVariable>
{
protected:

    KUINT32 m_ui32Type;

    KUINT16 m_ui16Length;

public:

    static const KUINT16 STANDARD_VARIABLE_SIZE = 6;

    StandardVariable();

    StandardVariable( KDataStream & stream ) throw( KException );

    virtual ~StandardVariable();

    //************************************
    // FullName:    KDIS::DATA_TYPE::StandardVariable::GetStandardVariableType
    // Description: The record type for this StandardVariable.
    //************************************
    KDIS::DATA_TYPE::ENUMS::StandardVariableType GetStandardVariableType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::StandardVariable::GetAsString
    // Description: The total record length in octets.
    //              The value of the Record Length shall be the sum of
    //              the sizes of the Record Type field, the Record Length field,
    //              all Record-Specific fields, and any padding required to end
    //              the record on a 64-bit boundary.
    //************************************
    KUINT16 GetRecordLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::StandardVariable::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::StandardVariable::FactoryDecodeStandardVariable
    // Description: Decode method for decoding any StandardVariable child classes that are part of KDIS.
    //              If you want to create a new StandardVariable child class then see the FactoryDecoder
	//				class for further info.
    //              Throws exception for unknown records(UNSUPPORTED_DATATYPE) or when stream is
    //              too small(NOT_ENOUGH_DATA_IN_BUFFER).
    // Parameter:   KDataStream & stream
    //************************************
    static StdVarPtr FactoryDecodeStandardVariable(  KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::StandardVariable::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::StandardVariable::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const StandardVariable & Value ) const;
    KBOOL operator != ( const StandardVariable & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
