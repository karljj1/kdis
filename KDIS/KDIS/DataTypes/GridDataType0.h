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
    class:      GridDataType0
    created:    19/11/2009
    author:     Karl Jones

    purpose:    The Grid Data record contains the actual environmental state variable data for
                each grid location. This record specifes the data sample type, the format by
                which the data are represented and the actual data values in 8-bit.

                NOTE: Data Representation Type 0 is specifcally designed to be fexible to accommodate anything
                from character data to data expressed as foating point numbers.

    size:       64 bits / 8 octets - Min size
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

    vector<KUINT8> m_vui8DataVals;

    KUINT8 m_ui8Padding;

public:

    static const KUINT16 GRID_DATA_TYPE0_SIZE = 8; // Min size

    GridDataType0( void );

    GridDataType0( KDataStream & stream ) throw( KException );

    // This constructor is used by the Gridded_Data_PDU. In order to know what type of grid
    // data we have we must decode the first 2 values.So this constructor is here to aid in this process.
    GridDataType0( KUINT16 SampleType, KUINT16 DataRepresentation, KDataStream & stream );

    GridDataType0( KUINT16 SampleType, KUINT8 * Data, KUINT16 NumBytes );

    virtual ~GridDataType0( void );

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
    // Parameter:   KUINT8 D, KUINT8 * Data,, const vector<KUINT8> & DV, void
    // Parameter:   void, KUINT16 NumBytes, void, void
    //************************************
    void AddDataValue( KUINT8 D );
    void SetDataValues( KUINT8 * Data, KUINT16 NumBytes );
    void SetDataValues( const vector<KUINT8> & DV );
    const vector<KUINT8> & GetDataValues() const;
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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

