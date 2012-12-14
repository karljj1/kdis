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

using KDIS::DATA_TYPE::ENUMS::EnvironmentRecordType;

/************************************************************************/
// Define the type of pointer we are using for VariableDatum Records,
// do we want a weak reference or a ref counter?
// By default we use a ref pointer, however if you want to use a standard
// pointer or one of your own then simply change it below.
/************************************************************************/
class EnvironmentRecord;
typedef KDIS::UTILS::KRef_Ptr<EnvironmentRecord> EnviromentRecordPtr; // Ref counter
//typedef EnvironmentRecord* EnviromentRecordPtr; // Weak ref

class KDIS_EXPORT EnvironmentRecord : public DataTypeBase, public FactoryDecoderUser<EnvironmentRecord>
{
protected:

    KUINT32 m_ui32EnvRecTyp;

    KUINT16 m_ui16Length;

    KUINT8 m_ui8Index;

    KUINT8 m_ui8Padding;

public:

    static const KUINT16 ENVIRONMENT_RECORD_SIZE = 8;

    EnvironmentRecord( void );

    virtual ~EnvironmentRecord( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentRecord::GetEnvironmentRecordType
    // Description: Specifies the record type.
    // Parameter:   EnvironmentRecordType RT, void
    //************************************
    EnvironmentRecordType GetEnvironmentRecordType() const;

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
    static EnviromentRecordPtr FactoryDecodeEnvironmentRecord(  KDataStream & stream ) throw( KException );

    KBOOL operator == ( const EnvironmentRecord & Value )const;
    KBOOL operator != ( const EnvironmentRecord & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
