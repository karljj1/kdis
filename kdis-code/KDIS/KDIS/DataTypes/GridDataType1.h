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
    class:      GridDataType1
    created:    20/11/2009
    author:     Karl Jones

    purpose:    The Grid Data record contains the actual environmental state variable data for
                each grid location. This record specifes the data sample type, the format by
                which the data are represented, feld scale factor and offset values,
                and the actual data values in 16-bit.

    size:       128 bits / 16 octets - Min size
*********************************************************************/

#pragma once

#include "./GridData.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

using std::vector;

class KDIS_EXPORT GridDataType1 : public GridData
{
protected:

    KFLOAT32 m_f32FieldScale;

    KFLOAT32 m_f32FieldOffset;

    KUINT16 m_ui16NumValues;

    vector<KUINT16> m_vui16Values;

    KUINT16 m_ui16Padding;

public:

    static const KUINT16 GRID_DATA_TYPE1_SIZE = 16; // Min size

    GridDataType1( void );

    GridDataType1( KDataStream & stream ) throw( KException );

    // This constructor is used by the Gridded_Data_PDU. In order to know what type of grid
    // data we have we must decode the first 2 values.So this constructor is here to aid in this process.
    GridDataType1( KUINT16 SampleType, KUINT16 DataRepresentation, KDataStream & stream );

    GridDataType1( KUINT16 SampleType, KFLOAT32 FieldScale, KFLOAT32 FieldOffset,
                   const vector<KUINT16> & Values );

    virtual ~GridDataType1( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType1::SetFieldScale
    //              KDIS::DATA_TYPE::GridDataType1::GetFieldScale
    // Description: Specifies the constant scale factor used to scale the environmental
    //              state variable data values contained in this record.
    // Parameter:   KFLOAT32 FS, void
    //************************************
    void SetFieldScale( KFLOAT32 FS );
    KFLOAT32 GetFieldScale() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType1::SetFieldOffset
    //              KDIS::DATA_TYPE::GridDataType1::GetFieldOffset
    // Description: Specifies the constant offset used to scale the environmental state
    //              variable data values contained in this record.
    // Parameter:   KFLOAT32 FO, void
    //************************************
    void SetFieldOffset( KFLOAT32 FO );
    KFLOAT32 GetFieldOffset() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType1::SetFieldOffset
    //              KDIS::DATA_TYPE::GridDataType1::GetFieldOffset
    // Description: The Number of environmental state variable data values contained in this record.
    //************************************
    KUINT16 GetNumberOfValues() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType1::AddValue
    //              KDIS::DATA_TYPE::GridDataType1::SetValues
    //              KDIS::DATA_TYPE::GridDataType1::GetValues
    //              KDIS::DATA_TYPE::GridDataType1::ClearValues
    // Description: The environmental state variable data values.
    // Parameter:   KUINT16 V, const vector<KUINT16> & V, void
    //************************************
    void AddValue( KUINT16 V );
    void SetValues( const vector<KUINT16> & V );
    const vector<KUINT16> & GetValues() const;
    void ClearValues();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType1::GetDataRepresentation
    // Description: Returns the size of the whole Grid Data type object in octets.
    //              Note: This information is not encoded into the PDU, it is here for the
    //              internal calculation of the PDU length value.
    //************************************
    virtual KUINT16 GetSize() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType1::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType1::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridDataType1::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GridDataType1 & Value ) const;
    KBOOL operator != ( const GridDataType1 & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

