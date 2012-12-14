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

using std::vector;

class KDIS_EXPORT GridDataType2 : public GridData
{
protected:

    KUINT16 m_ui16NumValues;

    vector<KFLOAT32> m_vf32Values;

    KUINT16 m_ui16Padding;

public:

    static const KUINT16 GRID_DATA_TYPE2_SIZE = 8; // Min size

    GridDataType2( void );

    GridDataType2( KDataStream & stream ) throw( KException );

    // This constructor is used by the Gridded_Data_PDU. In order to know what type of grid
    // data we have we must decode the first 2 values.So this constructor is here to aid in this process.
    GridDataType2( KUINT16 SampleType, KUINT16 DataRepresentation, KDataStream & stream );

    GridDataType2( KUINT16 SampleType, const vector<KFLOAT32> & Values );

    virtual ~GridDataType2( void );

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
    // Parameter:   KFLOAT32 V, const vector<KFLOAT32> & V, void
    //************************************
    void AddValue( KFLOAT32 V );
    void SetValues( const vector<KFLOAT32> & V );
    const vector<KFLOAT32> & GetValues() const;
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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

