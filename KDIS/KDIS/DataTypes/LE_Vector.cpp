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

#include "./LE_Vector.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type>::LE_Vector()
{
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type>::LE_Vector( Type X, Type Y, Type Z ) :
    m_X( X ),
    m_Y( Y ),
    m_Z( Z )
{
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type>::LE_Vector( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type>::~LE_Vector()
{
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
void LE_Vector<Type>::SetX( Type X )
{
    m_X = X;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
Type LE_Vector<Type>::GetX() const
{
    return m_X;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
void LE_Vector<Type>::SetY( Type Y )
{
    m_Y = Y;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
Type LE_Vector<Type>::GetY() const
{
    return m_Y;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
void LE_Vector<Type>::SetZ( Type Z )
{
    m_Z = Z;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
Type LE_Vector<Type>::GetZ() const
{
    return m_Z;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
KString LE_Vector<Type>::GetAsString() const
{
    KStringStream ss;

    ss << "X: "    << m_X.GetAsFloat32()
       << ",  Y: " << m_Y.GetAsFloat32()
       << ",  Z: " << m_Z.GetAsFloat32()
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
void LE_Vector<Type>::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LE_VECTOR_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> KDIS_STREAM m_X
           >> KDIS_STREAM m_Y
           >> KDIS_STREAM m_Z;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
KDataStream LE_Vector<Type>::Encode() const
{
    KDataStream stream;

    LE_Vector<Type>::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
void LE_Vector<Type>::Encode( KDataStream & stream ) const
{
    stream << KDIS_STREAM m_X
           << KDIS_STREAM m_Y
           << KDIS_STREAM m_Z;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
KBOOL LE_Vector<Type>::operator == ( const LE_Vector & Value ) const
{
    if( m_X != Value.m_X ) return false;
    if( m_Y != Value.m_Y ) return false;
    if( m_Z != Value.m_Z ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
KBOOL LE_Vector<Type>::operator != ( const LE_Vector & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type> LE_Vector<Type>::operator * ( const LE_Vector & Value ) const
{
    LE_Vector tmp = *this;
    tmp.m_X = tmp.m_X * Value.m_X;
    tmp.m_Y = tmp.m_Y * Value.m_Y;
    tmp.m_Z = tmp.m_Z * Value.m_Z;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type> LE_Vector<Type>::operator * ( KFLOAT64 Value ) const
{
    LE_Vector tmp = *this;
    tmp.m_X = tmp.m_X * Value;
    tmp.m_Y = tmp.m_Y * Value;
    tmp.m_Z = tmp.m_Z * Value;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type> LE_Vector<Type>::operator + ( const LE_Vector & Value ) const
{
    LE_Vector tmp = *this;
    tmp.m_X = tmp.m_X + Value.m_X;
    tmp.m_Y = tmp.m_Y + Value.m_Y;
    tmp.m_Z = tmp.m_Z + Value.m_Z;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type> & LE_Vector<Type>::operator += ( const LE_Vector & Value )
{
    m_X = m_X + Value.m_X;
    m_Y = m_Y + Value.m_Y;
    m_Z = m_Z + Value.m_Z;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type> LE_Vector<Type>::operator - ( const LE_Vector & Value ) const
{
    LE_Vector tmp = *this;
    tmp.m_X = tmp.m_X - Value.m_X;
    tmp.m_Y = tmp.m_Y - Value.m_Y;
    tmp.m_Z = tmp.m_Z - Value.m_Z;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
LE_Vector<Type> & LE_Vector<Type>::operator -= ( const LE_Vector & Value )
{
    m_X = m_X - Value.m_X;
    m_Y = m_Y - Value.m_Y;
    m_Z = m_Z - Value.m_Z;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
Type & LE_Vector<Type>::operator [] ( KUINT16 i ) throw( KException )
{
    switch( i )
    {
    case 0:
        return m_X;
    case 1:
        return m_Y;
    case 2:
        return m_Z;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
const Type & LE_Vector<Type>::operator [] ( KUINT16 i ) const throw( KException )
{
    switch( i )
    {
    case 0:
        return m_X;
    case 1:
        return m_Y;
    case 2:
        return m_Z;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////

// When using a template class with implementation in a cpp file, linker
// errors will occur if you do not pre-declare the template types in that same file.
// If you do wish to add support for other binary point positions then simply add them
// below and re-compile.

template class LE_Vector<KFIXED16_3>;
template class LE_Vector<KFIXED8_3>;

