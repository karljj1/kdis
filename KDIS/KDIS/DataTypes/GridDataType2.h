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
    class:      GridDataType2
    created:    20/11/2009
    author:     Karl Jones

    purpose:    The Grid Data record contains the actual environmental state variable data for
                each grid location. This record specifes the data sample type, the format by
                which the data are represented and the actual data values in 32-bit.

    size:       64 bits / 8 octets - Min size
*********************************************************************/

#pragma once

#include "./GridData.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GridDataType2 : public GridData
{
protected:

    KUINT16 m_ui16NumValues;

    std::vector<KFLOAT32> m_vf32Values;

    KUINT16 m_ui16Padding;

public:

    static const KUINT16 GRID_DATA_TYPE2_SIZE = 8; // Min size

    GridDataType2();

    GridDataType2( KDataStream & stream ) throw( KException );

    // This constructor is used by the Gridded_Data_PDU. In order to know what type of grid
    // data we have we must decode the first 2 values.So this constructor is here to aid in this process.
    GridDataType2( KUINT16 SampleType, KUINT16 DataRepresentation, KDataStream & stream );

    GridDataType2( KUINT16 SampleType, const std::vector<KFLOAT32> & Values );

    virtual ~GridDataType2();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType2::SetFieldOffset
    //              KDIS::DATA_TYPE::GridDataType2::GetFieldOffset
    // Description: The Number of environmental state variable data values contained in this record.
    //************************************
    KUINT16 GetNumberOfValues() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType2::AddValue
    //              KDIS::DATA_TYPE::GridDataType2::SetValues
    //              KDIS::DATA_TYPE::GridDataType2::GetValues
    //              KDIS::DATA_TYPE::GridDataType2::ClearValues
    // Description: The environmental state variable data values.
    // Parameter:   KFLOAT32 V, const vector<KFLOAT32> & V
    //************************************
    void AddValue( KFLOAT32 V );
    void SetValues( const std::vector<KFLOAT32> & V );
    const std::vector<KFLOAT32> & GetValues() const;
    void ClearValues();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType2::GetDataRepresentation
    // Description: Returns the size of the whole Grid Data type object in octets.
    //              Note: This information is not encoded into the PDU, it is here for the
    //              internal calculation of the PDU length value.
    //************************************
    virtual KUINT16 GetSize() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType2::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType2::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType2::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GridDataType2 & Value ) const;
    KBOOL operator != ( const GridDataType2 & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

