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
    class:      GridDataType0
    updated:    21/01/2016
    author:     Karl Jones

    purpose:    The Grid Data record contains the actual environmental state variable data for
                each grid location. This record specifes the data sample type, the format by
                which the data are represented and the actual data values in 8-bit.

                NOTE: Data Representation Type 0 is specifcally designed to be fexible to accommodate anything
                from character data to data expressed as foating point numbers.

    size:       48 bits / 6 octets - Min size
*********************************************************************/

#pragma once

#include "./GridData.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

using std::vector;

class KDIS_EXPORT GridDataType0 : public GridData
{
protected:

    KUINT16 m_ui16NumBytes;

    std::vector<KUINT8> m_vui8DataVals;

    KUINT8 m_ui8Padding;

public:

    static const KUINT16 GRID_DATA_TYPE0_SIZE = 6; // Min size

    GridDataType0();

    GridDataType0( KDataStream & stream ) throw( KException );

    // This constructor is used by the Gridded_Data_PDU. In order to know what type of grid
    // data we have we must decode the first 2 values.So this constructor is here to aid in this process.
    GridDataType0( KUINT16 SampleType, KUINT16 DataRepresentation, KDataStream & stream );

    GridDataType0( KUINT16 SampleType, KUINT8 * Data, KUINT16 NumBytes );

    virtual ~GridDataType0();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType0::Encode
    // Description: The number of bytes of environmental state variable data
    //              values contained in this record.
    // Parameter:   KDataStream & stream
    //************************************
    KUINT16 GetNumberOfBytes() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType0::AddGridAxisDescriptor
    //              KDIS::DATA_TYPE::GridDataType0::SetGridAxisDescriptors
    //              KDIS::DATA_TYPE::GridDataType0::GetSetGridAxisDescriptors
    //              KDIS::DATA_TYPE::GridDataType0::ClearValues
    // Description: Specifies the environmental state variable data values. The data shall
    //              be represented as a stream of bytes, the interpretation of which shall be
    //              agreed to prior to the start of the exercise.
    // Parameter:   KUINT8 D, KUINT8 * Data,, const vector<KUINT8> & DV
    // Parameter:   KUINT16 NumBytes
    //************************************
    void AddDataValue( KUINT8 D );
    void SetDataValues( KUINT8 * Data, KUINT16 NumBytes );
    void SetDataValues( const std::vector<KUINT8> & DV );
    const std::vector<KUINT8> & GetDataValues() const;
    void ClearValues();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType0::GetDataRepresentation
    // Description: Returns the size of the whole Grid Data type object in octets.
    //              Note: This information is not encoded into the PDU, it is here for the
    //              internal calculation of the PDU length value.
    //************************************
    virtual KUINT16 GetSize() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType0::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType0::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType0::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GridDataType0 & Value ) const;
    KBOOL operator != ( const GridDataType0 & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

