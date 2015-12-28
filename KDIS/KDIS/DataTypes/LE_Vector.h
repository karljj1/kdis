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
    class:      LE_Vector
    created:    29/07/2010
    author:     Karl Jones

    purpose:    Template Vector class used for Live Entity PDU's.
                Supports KFIXED16_3 and KFIXED8_3 data types.
                To add support for other's see the bottom of the cpp file.
*********************************************************************/

#pragma once

#include "./KFIXED.h"

namespace KDIS {
namespace DATA_TYPE {

template<class Type>
class KDIS_EXPORT LE_Vector : public DataTypeBase
{
protected:

    Type m_X;

    Type m_Y;

    Type m_Z;

public:

    static const KUINT16 LE_VECTOR_SIZE = sizeof( typename Type::ValueType ) * 3;

    LE_Vector();

    LE_Vector( Type X, Type Y, Type Z );

    LE_Vector( KDataStream & stream ) throw( KException );

    virtual ~LE_Vector();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::SetX
    //              KDIS::DATA_TYPE::LE_Vector::GetX
    // Description: First Value / X
    // Parameter:   Type  X
    //************************************
    void SetX( Type X );
    Type GetX() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::SetY
    //              KDIS::DATA_TYPE::LE_Vector::GetY
    // Description: Second Value / Y
    // Parameter:   Type Y
    //************************************
    void SetY( Type Y );
    Type GetY() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::SetZ
    //              KDIS::DATA_TYPE::LE_Vector::GetZ
    // Description: Third Value / Z
    // Parameter:   Type Z
    //************************************
    void SetZ( Type Z );
    Type GetZ() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_Vector & Value ) const;
    KBOOL operator != ( const LE_Vector & Value ) const;
    LE_Vector operator * ( const LE_Vector & Value ) const;
    LE_Vector operator * ( KFLOAT64 Value ) const;
    LE_Vector operator + ( const LE_Vector & Value ) const;
    LE_Vector & operator += ( const LE_Vector & Value );
    LE_Vector operator - ( const LE_Vector & Value ) const;
    LE_Vector & operator -= ( const LE_Vector & Value );

    // Valid values 0 - X, 1 - Y, 2 - Z. throws OUT_OF_BOUNDS exception for any other value.
    Type & operator[] ( KUINT16 i ) throw( KException );
    const Type & operator[]  ( KUINT16 i ) const throw( KException );
};

// Predefined LE_Vector types.
// LE_Vectorx_y
// x = Size of data type in bits
// y = The position of the binary point.
typedef LE_Vector<KFIXED8_3> LE_Vector8_3;
typedef LE_Vector<KFIXED16_3> LE_Vector16_3;

} // END namespace DATA_TYPES
} // END namespace KDIS
