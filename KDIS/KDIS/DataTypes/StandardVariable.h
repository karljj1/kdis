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

using KDIS::DATA_TYPE::ENUMS::StandardVariableType;

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

    StandardVariable( void );

    StandardVariable( KDataStream & stream ) throw( KException );

    virtual ~StandardVariable( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::StandardVariable::GetStandardVariableType
    // Description: TODO: The record type for this StandardVariable.
    //************************************
    StandardVariableType GetStandardVariableType() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
