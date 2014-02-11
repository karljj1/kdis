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

class KDIS_EXPORT GridData : public DataTypeBase
{
protected:

    KUINT16 m_ui16SmpTyp;

    KUINT16 m_ui16DtRep;

public:

    static const KUINT16 GRID_DATA_SIZE = 4;

    GridData();

    GridData( KDataStream & stream ) throw( KException );

    virtual ~GridData();

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
    KDIS::DATA_TYPE::ENUMS::GridDataRepresentation GetDataRepresentation() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS

