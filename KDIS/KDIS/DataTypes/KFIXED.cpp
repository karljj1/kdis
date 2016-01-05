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

#include "./KFIXED.h"

using namespace KDIS;
using namespace DATA_TYPE;

/**
 *  [n].[m] digit fixed point binary number:
 *
 *      records fractions of integer values to precision [m] binary places
 *
 *  stored value (using integer container) = (int or float rhs) * 2^m
 *
 *  "2^m" is equivalent to "1 << m" which is can be literal constant.
 *
 *  Such code is used at many points in this file.
 */

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
Type KFIXED<Type, BinaryPoint>::convert( KFLOAT32 V ) const
{
    return V * ( 1 << BinaryPoint );
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
Type KFIXED<Type, BinaryPoint>::convert( KFLOAT64 V ) const
{
    return V * ( 1 << BinaryPoint );
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint>::KFIXED() :
    m_Val( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint>::KFIXED( KFLOAT32 V ) :
    m_Val( convert( V ) )
{
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint>::KFIXED( KFLOAT64 V ) :
    m_Val( convert( V ) )
{
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint>::KFIXED( Type V ) :
    m_Val( V )
{
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint>::KFIXED( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint>::~KFIXED()
{
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
void KFIXED<Type, BinaryPoint>::Set( KFLOAT32 V )
{
    m_Val = convert( V );
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
void KFIXED<Type, BinaryPoint>::Set( KFLOAT64 V )
{
    m_Val = convert( V );
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
void KFIXED<Type, BinaryPoint>::Set( Type V )
{
    m_Val = V ;
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
Type KFIXED<Type, BinaryPoint>::Get() const
{
    return m_Val;
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFLOAT32 KFIXED<Type, BinaryPoint>::GetAsFloat32() const
{
    return  m_Val * ( 1.0 / ( 1 << BinaryPoint ) );
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KString KFIXED<Type, BinaryPoint>::GetAsString() const
{
    KStringStream ss;

    ss << GetAsFloat32() << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
void KFIXED<Type, BinaryPoint>::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < sizeof( Type ) )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_Val;
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KDataStream KFIXED<Type, BinaryPoint>::Encode() const
{
    KDataStream stream;

    KFIXED<Type, BinaryPoint>::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
void KFIXED<Type, BinaryPoint>::Encode( KDataStream & stream ) const
{
    stream << m_Val;
}

//////////////////////////////////////////////////////////////////////////
// operators:
//////////////////////////////////////////////////////////////////////////

// Some macros to reduce the code a little

// DEFINE_OPERATOR ******************************************************************************************
#define DEFINE_OPERATOR( OPERATOR )                                                                         \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KFIXED<Type, BinaryPoint> KFIXED<Type, BinaryPoint>::operator OPERATOR ( KFLOAT32 Value )                   \
{                                                                                                           \
    return GetAsFloat32() OPERATOR Value;                                                                   \
}                                                                                                           \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KFIXED<Type, BinaryPoint> KFIXED<Type, BinaryPoint>::operator OPERATOR ( KFLOAT64 Value )                   \
{                                                                                                           \
    return GetAsFloat32() OPERATOR Value;                                                                   \
}                                                                                                           \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KFIXED<Type, BinaryPoint> KFIXED<Type, BinaryPoint>::operator OPERATOR ( Type Value )                       \
{                                                                                                           \
    return *this OPERATOR KFIXED( Value ).GetAsFloat32();                                                   \
}                                                                                                           \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KFIXED<Type, BinaryPoint> KFIXED<Type, BinaryPoint>::operator OPERATOR ( KFIXED<Type, BinaryPoint> Value )  \
{                                                                                                           \
    return GetAsFloat32() OPERATOR Value.GetAsFloat32();                                                    \
}

// DEFINE_COMPARISION_OPERATOR ******************************************************************************
#define DEFINE_COMPARISION_OPERATOR( OPERATOR )                                                             \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KBOOL KFIXED<Type, BinaryPoint>::operator OPERATOR ( KFLOAT32 Value ) const                                 \
{                                                                                                           \
    return m_Val OPERATOR convert( Value );                                                                 \
}                                                                                                           \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KBOOL KFIXED<Type, BinaryPoint>::operator OPERATOR ( KFLOAT64 Value ) const                                 \
{                                                                                                           \
    return m_Val OPERATOR convert( Value );                                                                 \
}                                                                                                           \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KBOOL KFIXED<Type, BinaryPoint>::operator OPERATOR ( Type Value ) const                                     \
{                                                                                                           \
    return m_Val OPERATOR m_Val;                                                                            \
}                                                                                                           \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KBOOL KFIXED<Type, BinaryPoint>::operator OPERATOR ( KFIXED<Type, BinaryPoint> Value ) const                \
{                                                                                                           \
    return m_Val OPERATOR Value.m_Val;                                                                      \
}

//***************************** End Macros ******************************************************************

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint> KFIXED<Type, BinaryPoint>::operator = ( KFLOAT32 Value )
{
    m_Val = convert( Value );
    return *this;
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint> KFIXED<Type, BinaryPoint>::operator = ( KFLOAT64 Value )
{
    m_Val = convert( Value );
    return *this;
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint> KFIXED<Type, BinaryPoint>::operator = ( Type Value )
{
    m_Val = Value;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint> KFIXED<Type, BinaryPoint>::operator = ( KFIXED<Type, BinaryPoint> Value )
{
    m_Val = Value.m_Val;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

DEFINE_OPERATOR( + )
DEFINE_OPERATOR( - )
DEFINE_OPERATOR( * )
DEFINE_OPERATOR( / )

//////////////////////////////////////////////////////////////////////////

DEFINE_COMPARISION_OPERATOR( == )
DEFINE_COMPARISION_OPERATOR( != )
DEFINE_COMPARISION_OPERATOR( < )
DEFINE_COMPARISION_OPERATOR( <= )
DEFINE_COMPARISION_OPERATOR( > )
DEFINE_COMPARISION_OPERATOR( >= )

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint>::operator KFLOAT32 () const
{
    return GetAsFloat32();
}

//////////////////////////////////////////////////////////////////////////

template<class Type, KUINT8 BinaryPoint>
KFIXED<Type, BinaryPoint>::operator Type () const
{
    return m_Val;
}

//////////////////////////////////////////////////////////////////////////

// When using a template class with implementation in a cpp file, linker
// errors will occur if you do not pre-declare the template types in that same file.
// This is good for us in this case as we only need to support a binary point of 3 and 8.
// If you do wish to add support for other binary point positions then simply add them
// below and re-compile.

template class KFIXED<KINT16, 3>;
template class KFIXED<KINT16, 8>;
template class KFIXED<KINT8, 3>;
