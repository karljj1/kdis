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

#include "./Vector.h"
#include <math.h>

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Vector::Vector( void ) :
    m_f32X( 0 ),
    m_f32Y( 0 ),
    m_f32Z( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Vector::Vector( KFLOAT32 X, KFLOAT32 Y, KFLOAT32 Z ) :
    m_f32X( X ),
    m_f32Y( Y ),
    m_f32Z( Z )
{
}

//////////////////////////////////////////////////////////////////////////

Vector::Vector( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Vector::~Vector( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Vector::SetX( KFLOAT32 X )
{
    m_f32X = X;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Vector::GetX() const
{
    return m_f32X;
}

//////////////////////////////////////////////////////////////////////////

void Vector::SetY( KFLOAT32 Y )
{
    m_f32Y = Y;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Vector::GetY() const
{
    return m_f32Y;
}

//////////////////////////////////////////////////////////////////////////

void Vector::SetZ( KFLOAT32 Z )
{
    m_f32Z = Z;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Vector::GetZ() const
{
    return m_f32Z;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Vector::GetMagnitude() const
{
	return sqrt( ( m_f32X * m_f32X ) + ( m_f32Y * m_f32Y ) + ( m_f32Z * m_f32Z ) );
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Vector::GetDistance( const Vector & Other )
{
	Vector v = *this - Other;
	return v.GetMagnitude();
}

//////////////////////////////////////////////////////////////////////////

KString Vector::GetAsString() const
{
    KStringStream ss;

    ss << "X: "    << m_f32X
       << ",  Y: " << m_f32Y
       << ",  Z: " << m_f32Z << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Vector::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < VECTOR_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f32X
           >> m_f32Y
           >> m_f32Z;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Vector::Encode() const
{
    KDataStream stream;

    Vector::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Vector::Encode( KDataStream & stream ) const
{
    stream << m_f32X
           << m_f32Y
           << m_f32Z;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Vector::operator == ( const Vector & Value ) const
{
    if( m_f32X != Value.m_f32X ) return false;
    if( m_f32Y != Value.m_f32Y ) return false;
    if( m_f32Z != Value.m_f32Z ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Vector::operator != ( const Vector & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

Vector Vector::operator * ( const Vector & Value ) const
{
    Vector tmp = *this;
    tmp.m_f32X *= Value.m_f32X;
    tmp.m_f32Y *= Value.m_f32Y;
    tmp.m_f32Z *= Value.m_f32Z;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

Vector Vector::operator * ( KFLOAT64 Value ) const
{
    Vector tmp = *this;
    tmp.m_f32X *= Value;
    tmp.m_f32Y *= Value;
    tmp.m_f32Z *= Value;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

Vector Vector::operator + ( const Vector & Value ) const
{
    Vector tmp = *this;
    tmp.m_f32X += Value.m_f32X;
    tmp.m_f32Y += Value.m_f32Y;
    tmp.m_f32Z += Value.m_f32Z;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

Vector & Vector::operator += ( const Vector & Value )
{
    m_f32X += Value.m_f32X;
    m_f32Y += Value.m_f32Y;
    m_f32Z += Value.m_f32Z;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

Vector Vector::operator - ( const Vector & Value ) const
{
    Vector tmp = *this;
    tmp.m_f32X -= Value.m_f32X;
    tmp.m_f32Y -= Value.m_f32Y;
    tmp.m_f32Z -= Value.m_f32Z;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

Vector & Vector::operator -= ( const Vector & Value )
{
    m_f32X -= Value.m_f32X;
    m_f32Y -= Value.m_f32Y;
    m_f32Z -= Value.m_f32Z;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 & Vector::operator [] ( KUINT16 i ) throw( KException )
{
    switch( i )
    {
    case 0:
        return m_f32X;
    case 1:
        return m_f32Y;
    case 2:
        return m_f32Z;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////

const KFLOAT32 & Vector::operator [] ( KUINT16 i ) const throw( KException )
{
    switch( i )
    {
    case 0:
        return m_f32X;
    case 1:
        return m_f32Y;
    case 2:
        return m_f32Z;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////


