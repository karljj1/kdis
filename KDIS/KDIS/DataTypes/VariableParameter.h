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
    class:      VariableParameter
    created:    08/03/2013
    author:     Karl Jones

    purpose:    Information associated with an entity or detonation, not otherwise accounted
                for in a PDU.
                Currently implemented types:
					ArticulatedParts
					AttachedPart

				Note: See FactoryDecoder for a guide to adding support for using your own VariableParameters. 

    size:       128 bits / 16 octets 
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./FactoryDecoder.h"
#include "./../Extras/KRef_Ptr.h"

namespace KDIS {
namespace DATA_TYPE {

/************************************************************************/
// Define the type of pointer we are using for VariableParameter Records,
// do we want a weak reference or a ref counter?
// By default we use a ref pointer, however if you want to use a standard
// pointer or one of your own then simply change it below.
/************************************************************************/
class VariableParameter;
typedef KDIS::UTILS::KRef_Ptr<VariableParameter> VarPrmPtr; // Ref counter
//typedef VariableParameter* VarPrmPtr; // Weak ref

using KDIS::DATA_TYPE::ENUMS::VariableParameterType;

class KDIS_EXPORT VariableParameter : public DataTypeBase, public FactoryDecoderUser<VariableParameter>
{
protected:		

	KUINT8 m_ui8VarParamType;
   
	KUINT8 m_Data[15];

public:

    static const KUINT16 VARIABLE_PARAMETER_SIZE = 16;    

	VariableParameter();

	VariableParameter( VariableParameterType VPT, KUINT8 * Data, KUINT8 DataSize ) throw( KException );

    VariableParameter( KDataStream & stream ) throw( KException );

	virtual ~VariableParameter();

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableParameter::SetVariableParameterType
    //              KDIS::DATA_TYPE::VariableParameter::GetVariableParameterType
    // Description: VP record type.
    // Parameter:   VariableParameterType VPT
    //************************************
    void SetVariableParameterType( VariableParameterType VPT );
    VariableParameterType GetVariableParameterType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableParameter::SetVariableParameterType
    //              KDIS::DATA_TYPE::VariableParameter::GetVariableParameterType
    // Description: Raw VP data. 15 byte array. 
    // Parameter:   const KUINT8 * D
	// Parameter:   KUINT8 DataSize - Exception thrown if data size is greater than 15.
    //************************************
	void SetData( const KUINT8 * D, KUINT8 DataSize ) throw( KException );
	const KUINT8 * GetData() const;
	KUINT8 * GetData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableParameter::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableParameter::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableParameter::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const VariableParameter & Value ) const;
    KBOOL operator != ( const VariableParameter & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
