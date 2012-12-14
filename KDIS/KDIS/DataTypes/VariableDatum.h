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
    class:      VariableDatum
    created:    2008/09/18
    author:     Karl Jones

    purpose:    Stores variable data types and their values. Such as strings.
                Get as string does not know what the data type is so for now assumes
                each byte is a ASCII char.
				
				Note: See FactoryDecoder for a guide to adding support for using your own VariableDatums. 

    size:       64 bits / 8 octets - Min size
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./FactoryDecoder.h"
#include "./../Extras/KRef_Ptr.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::DatumID;
using std::vector;

/************************************************************************/
// Define the type of pointer we are using for VariableDatum Records,
// do we want a weak reference or a ref counter?
// By default we use a ref pointer, however if you want to use a standard
// pointer or one of your own then simply change it below.
/************************************************************************/
class VariableDatum;
typedef KDIS::UTILS::KRef_Ptr<VariableDatum> VarDtmPtr; // Ref counter
//typedef VariableDatum* VarDtmPtr; // Weak ref

class KDIS_EXPORT VariableDatum : public DataTypeBase, public FactoryDecoderUser<VariableDatum>
{
protected:		

    KUINT32 m_ui32DatumID;

    KUINT32 m_ui32DatumLength;

    struct DatumEntry
    {
        KOCTET Buffer[8];

        DatumEntry( void )
        {
            memset( Buffer, 0x00, 8 );
        };
    };

    // Holds 64 bits, not all bits may belong to the value as padding is also added.
    vector<DatumEntry> m_v8DatumValue;

public:

    static const KUINT16 VARIABLE_DATUM_SIZE = 8; // Min Size

    VariableDatum( void );

    VariableDatum( DatumID ID, const KString & Value );

    VariableDatum( DatumID ID, const KOCTET * data, KUINT32 sizeInBits );

    VariableDatum( KDataStream & stream ) throw( KException );

	virtual ~VariableDatum( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableDatum::SetDatumID
    //              KDIS::DATA_TYPE::VariableDatum::GetDatumID
    // Description: Set the datum id, indicates what the datum value
    //              is for and what format it should be in.
    // Parameter:   DatumID ID
    //************************************
    virtual void SetDatumID( DatumID ID );
    virtual DatumID GetDatumID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableDatum::GetDatumLength
    // Description: Returns length of datum VALUE in bits.
	//				Note: Does not include the datum id or length field.
    //************************************
    virtual KUINT32 GetDatumLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableDatum::GetDatumLength
    // Description: Returns length of Datum in octets that it will
    //              occupy when put into a PDU.
    //************************************
    virtual KUINT32 GetPDULength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableDatum::GetDatumValueCopyIntoBuffer
    //              KDIS::DATA_TYPE::VariableDatum::GetDatumValueAsKString
    //              KDIS::DATA_TYPE::VariableDatum::GetDatumValueAsKUINT64
    //              KDIS::DATA_TYPE::VariableDatum::GetDatumValueAsKFLOAT64
    //              KDIS::DATA_TYPE::VariableDatum::ClearDatumValue
    // Description: Copy datum value into a buffer or
    //              return as a privative data type.
    //              primitives are returned as vectors,
    //              If the datum length is not a multiple of
    //              8 then the last octets are ignored.
    // Parameter:   KOCTET * Buffer
    // Parameter:   KUINT16 BufferSize
    //************************************
    virtual void GetDatumValueCopyIntoBuffer( KOCTET * Buffer, KUINT16 BufferSize ) const throw( KException );
    virtual KString GetDatumValueAsKString() const;
    virtual vector<KUINT64> GetDatumValueAsKUINT64() const;
    virtual vector<KFLOAT64> GetDatumValueAsKFLOAT64() const;
    virtual void SetDatumValue( const KString & s );
    virtual void ClearDatumValue();

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableDatum::SetDatumValue
    // Description: Set value from a byte array ... note that length is in bits.
    //************************************
    virtual void SetDatumValue( const KOCTET * data, KUINT32 sizeInBits );

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableDatum::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableDatum::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::VariableDatum::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const VariableDatum & Value ) const;
    KBOOL operator != ( const VariableDatum & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
