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
    class:      KFIXED
    created:    01/07/2010
    author:     Karl Jones

    purpose:    A fixed point number used in Live Entity family.
                The binary point is defined by the sub protocol, but for the purposes
                of this standard the binary point has also been defined when a fixed point number is used,
                the point varies depending on the data type.

                This template class only supports certain fixed point numbers by default.
                They are:
                16 bit fixed with point at bit 3
                16 bit fixed with point at bit 8
                8 bit fixed with point at bit 3 - The DIS standard does not state where the bit goes so 3 is an educated guess..

                If you wish to add support for other binary point value then edit the end of the KFIXED.cpp file.
                See http://en.wikipedia.org/wiki/Fixed-point_arithmetic for more infomation on fixed-point numbers.

*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

template<class Type, KUINT8 BinaryPoint>
class KDIS_EXPORT KFIXED : public DataTypeBase
{
public:

    typedef Type ValueType;

protected:

    Type m_Val;

    //************************************
    // FullName:    KDIS::DATA_TYPE::KFIXED<Type, BinaryPoint>::convert
    // Description: convert from a float to a fixed value.
    // Parameter:   KFLOAT32 V
    //************************************
    Type convert( KFLOAT32 V ) const;
    Type convert( KFLOAT64 V ) const;

public:

    KFIXED();

    KFIXED( KFLOAT32 V );

    KFIXED( KFLOAT64 V );

    KFIXED( Type V );

    KFIXED( KDataStream & stream )throw( KException );

    virtual ~KFIXED();

    //************************************
    // FullName:    KDIS::DATA_TYPE::KFIXED::Set
    // Description: Sets the internal value.
    // Parameter:   KFLOAT32 V
    //************************************
    void Set( KFLOAT32 V );

    //************************************
    // FullName:    KDIS::DATA_TYPE::KFIXED::Set
    // Description: Sets the internal value.
    // Parameter:   KFLOAT64 V
    //************************************
    void Set( KFLOAT64 V );

    //************************************
    // FullName:    KDIS::DATA_TYPE::KFIXED::Set
    // Description: Set the internal value.
    // Parameter:   Type V
    //************************************
    void Set( Type V );

    //************************************
    // FullName:    KDIS::DATA_TYPE::KFIXED::Get
    // Description: Returns internal value.
    //************************************
    Type Get() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::KFIXED::GetAsFloat32
    // Description: Convert value to a float 32 bit.
    //************************************
    KFLOAT32 GetAsFloat32() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::KFIXED::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::KFIXED::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::KFIXED::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    // operators

    // Helper macros:
#define DECLARE_OPERATOR( OPERATOR )                                \
                                                                     \
 KFIXED operator OPERATOR ( KFLOAT32 Value );                        \
 KFIXED operator OPERATOR ( KFLOAT64 Value );                        \
 KFIXED operator OPERATOR ( Type Value );                            \
 KFIXED operator OPERATOR ( KFIXED<Type, BinaryPoint> Value );       \
 
#define DECLARE_COMPARISON_OPERATOR( OPERATOR )                     \
                                                                     \
 KBOOL operator OPERATOR ( KFLOAT32 Value ) const;                   \
 KBOOL operator OPERATOR ( KFLOAT64 Value ) const;                   \
 KBOOL operator OPERATOR ( Type Value ) const;                       \
 KBOOL operator OPERATOR ( KFIXED<Type, BinaryPoint> Value ) const;  \
 // End of macros

    // Supported operators
    DECLARE_OPERATOR( = )
    DECLARE_OPERATOR( + )
    DECLARE_OPERATOR( - )
    DECLARE_OPERATOR( * )
    DECLARE_OPERATOR( / )

    // Comparison operators:
    DECLARE_COMPARISON_OPERATOR( == )
    DECLARE_COMPARISON_OPERATOR( != )
    DECLARE_COMPARISON_OPERATOR( < )
    DECLARE_COMPARISON_OPERATOR( <= )
    DECLARE_COMPARISON_OPERATOR( > )
    DECLARE_COMPARISON_OPERATOR( >= )

    // We are finished with the macros now so lets remove them.
#undef DECLARE_OPERATOR
#undef DECLARE_COMPARISON_OPERATOR

    // Casting
    operator KFLOAT32 () const;
    operator Type () const;
};

// Predefined KFIXED types.
// KFIXEDx_y
// x = Size of data type in bits
// y = The position of the binary point.
typedef KFIXED<KINT8, 3> KFIXED8_3;
typedef KFIXED<KINT16, 3> KFIXED16_3;
typedef KFIXED<KINT16, 8> KFIXED16_8;

} // END namespace DATA_TYPES
} // END namespace KDIS
