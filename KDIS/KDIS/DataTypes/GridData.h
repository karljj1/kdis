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
    class:      GridData
    created:    18/11/2009
    author:     Karl Jones

    purpose:    This is the base class for all grid daya types 0, 1 and 2.
                The data representation type value can be used to determine
                the correct grid data type.
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::GridDataRepresentation;

class KDIS_EXPORT GridData : public DataTypeBase
{
protected:

    KUINT16 m_ui16SmpTyp;

    KUINT16 m_ui16DtRep;

public:

    static const KUINT16 GRID_DATA_SIZE = 4;

    GridData( void );

    GridData( KDataStream & stream ) throw( KException );

    virtual ~GridData( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridData::SetSampleType
    //              KDIS::DATA_TYPE::GridData::GetSampleType
    // Description: Specifies the environmental data sample contained in
    //              the PDU (e.g. u-comconent of wind).
    // Parameter:   KUINT16 ST, void
    //************************************
    void SetSampleType( KUINT16 ST );
    KUINT16 GetSampleType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridData::GetDataRepresentation
    // Description: Specifies the value that describes the data representation method
    //              for the environmental state variable data contained within the Data
    //              Values fields of this record. Use this value to know what type you should up cast to.
    //              E.G if the value was 1 then you would upcast to a "GridDataType1" to get access to the data.
    //************************************
    GridDataRepresentation GetDataRepresentation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridData::GetDataRepresentation
    // Description: Returns size of Grid Data in octets.
    //              Note this information is not encoded into the PDU.
    //************************************
    virtual KUINT16 GetSize() const = 0;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GridData & Value ) const;
    KBOOL operator != ( const GridData & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

