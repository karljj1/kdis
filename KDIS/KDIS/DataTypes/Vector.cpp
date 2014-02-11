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

#include "./Vector.h"
#include <math.h>

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Vector::Vector() :
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

Vector::~Vector()
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

void Vector::Set( KFLOAT32 X, KFLOAT32 Y, KFLOAT32 Z )
{
	m_f32X = X;
	m_f32Y = Y;
	m_f32Z = Z;
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

Vector Vector::Lerp( const Vector & From, const Vector & To, KFLOAT32 T )
{
	return From + ( ( To - From ) * T );	
}

//////////////////////////////////////////////////////////////////////////

void Vector::Lerp( const Vector & To, KFLOAT32 T )
{
	*this = Lerp( *this, To, T );
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

Vector Vector::operator * ( KFLOAT32 Value ) const
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
		case 0: 	return m_f32X;
		case 1:		return m_f32Y;
		case 2:		return m_f32Z;
		default:	throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////

const KFLOAT32 & Vector::operator [] ( KUINT16 i ) const throw( KException )
{
    switch( i )
    {
		case 0:		return m_f32X;
		case 1:		return m_f32Y;
		case 2:		return m_f32Z;
		default:    throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////


