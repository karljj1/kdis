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
    class:      FixedDatum
    created:    18/09/2008
    author:     Karl Jones

    purpose:    Stores fixed datum values.

				Note: See FactoryDecoder for a guide to adding support 
				for using your own FixedDatum. 

    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./FactoryDecoder.h"
#include "./../Extras/KRef_Ptr.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::DatumID;
using KDIS::UTILS::IsMachineBigEndian;

/************************************************************************/
// Define the type of pointer we are using for FixedDatum Records,
// do we want a weak reference or a ref counter?
// By default we use a ref pointer, however if you want to use a standard
// pointer or one of your own then simply change it below.
/************************************************************************/
class FixedDatum;
typedef KDIS::UTILS::KRef_Ptr<FixedDatum> FixDtmPtr; // Ref counter
//typedef FixedDatum* FixDtmPtr; // Weak ref

class KDIS_EXPORT FixedDatum : public DataTypeBase, public FactoryDecoderUser<FixedDatum>
{
protected:

    KUINT32 m_ui32DatumID;

    KOCTET m_cDatumValue[4];

public:

    static const KUINT16 FIXED_DATUM_SIZE = 8;

    FixedDatum();

    template<class Type>
    FixedDatum( DatumID ID, Type Value ) throw( KException );

    FixedDatum( KDataStream & stream ) throw( KException );

    virtual ~FixedDatum();

    //************************************
    // FullName:    KDIS::DATA_TYPE::FixedDatum::SetDatumID
    //              KDIS::DATA_TYPE::FixedDatum::GetDatumID
    // Description: Set the datum id, indicates what the datum value
    //              is for and what format it should be in.
    // Parameter:   DatumID ID
    //************************************
    virtual void SetDatumID( DatumID ID );
    virtual DatumID GetDatumID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FixedDatum<Type>::SetDatumValue
    //              KDIS::DATA_TYPE::FixedDatum<Type>::GetDatumValue
    // Description: Returns datum value in required format, format
    //              must be 32 bits or less.
    // Parameter:   Type val
    //************************************
    template<class Type>
    void SetDatumValue( Type val ) throw( KException );
    template<class Type>
    Type GetDatumValue() const throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::FixedDatum::GetDatumValue
    // Description: Copies octets into a buffer.
    //              Buffer must be 4 octets in size.
    //              All data types are stored in Big Endian
    //              in the buffer.
    // Parameter:   KOCTET * Buffer
    //************************************
    virtual void GetDatumValue( KOCTET * Buffer, KUINT16 BufferSize ) const throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::FixedDatum::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FixedDatum::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::FixedDatum::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const FixedDatum & Value ) const;
    KBOOL operator != ( const FixedDatum & Value ) const;
};

/////////////////////////////////////////////////////////////////////////
// templates
//////////////////////////////////////////////////////////////////////////

template<class Type>
FixedDatum::FixedDatum( DatumID ID, Type Value ) throw( KException )
{
    m_ui32DatumID = ID;
    SetDatumValue( Value );
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
Type FixedDatum::GetDatumValue() const throw( KException )
{
    if( sizeof( Type ) > 4 )throw KException( __FUNCTION__, DATA_TYPE_TOO_LARGE );

    NetToDataType<Type> NetValue( m_cDatumValue, false );

    // Do we need to convert the data back to machine endian?
    if( IsMachineBigEndian() == false )
    {
        // Need to convert
        NetValue.SwapBytes();
    }

    return NetValue.m_Value;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
void FixedDatum::SetDatumValue( Type val ) throw( KException )
{
    if( sizeof( Type ) > 4 )throw KException( __FUNCTION__, DATA_TYPE_TOO_LARGE );

    // Reset datum value.
    memset( m_cDatumValue, 0x00, 4 );

    NetToDataType<Type> NetValue( val, false );

    // Now convert the data into big endian, we want to store the value like this
    // as when we encode/decode we have no way to know what the data type is or how many
    // octets long it is. We only convert to machine endian when the data is requested.
    if( IsMachineBigEndian() == false )
    {
        // Need to convert
        NetValue.SwapBytes();
    }

    // Copy into datum value.
    for( KUINT16 i = 0; i < sizeof( Type ); ++i )
    {
        m_cDatumValue[i] = NetValue.m_Octs[i];
    }
}

//////////////////////////////////////////////////////////////////////////

} // END namespace DATA_TYPES
} // END namespace KDIS
