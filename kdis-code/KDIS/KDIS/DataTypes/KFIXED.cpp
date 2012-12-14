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
KFIXED<Type, BinaryPoint>::KFIXED( void ) :
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
KFIXED<Type, BinaryPoint>::~KFIXED( void )
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
    return m_Val == convert( Value );                                                                       \
}                                                                                                           \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KBOOL KFIXED<Type, BinaryPoint>::operator OPERATOR ( KFLOAT64 Value ) const                                 \
{                                                                                                           \
    return m_Val == convert( Value );                                                                       \
}                                                                                                           \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KBOOL KFIXED<Type, BinaryPoint>::operator OPERATOR ( Type Value ) const                                     \
{                                                                                                           \
    return m_Val == m_Val;                                                                                  \
}                                                                                                           \
                                                                                                            \
template<class Type, KUINT8 BinaryPoint>                                                                    \
KBOOL KFIXED<Type, BinaryPoint>::operator OPERATOR ( KFIXED<Type, BinaryPoint> Value ) const                \
{                                                                                                           \
    return m_Val == Value.m_Val;                                                                            \
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
