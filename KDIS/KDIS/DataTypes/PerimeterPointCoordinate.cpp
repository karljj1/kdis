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

#include "./PerimeterPointCoordinate.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

PerimeterPointCoordinate::PerimeterPointCoordinate() :
    m_f32X( 0 ),
    m_f32Y( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

PerimeterPointCoordinate::PerimeterPointCoordinate( KFLOAT32 X, KFLOAT32 Y ) :
    m_f32X( X ),
    m_f32Y( Y )
{
}

//////////////////////////////////////////////////////////////////////////

PerimeterPointCoordinate::PerimeterPointCoordinate( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

PerimeterPointCoordinate::~PerimeterPointCoordinate()
{
}

//////////////////////////////////////////////////////////////////////////

void PerimeterPointCoordinate::SetX( KFLOAT32 X )
{
    m_f32X = X;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 PerimeterPointCoordinate::GetX() const
{
    return m_f32X;
}

//////////////////////////////////////////////////////////////////////////

void PerimeterPointCoordinate::SetY( KFLOAT32 Y )
{
    m_f32Y = Y;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 PerimeterPointCoordinate::GetY() const
{
    return m_f32Y;
}

//////////////////////////////////////////////////////////////////////////

KString PerimeterPointCoordinate::GetAsString() const
{
    KStringStream ss;

    ss << "X: "    << m_f32X
       << ",  Y: " << m_f32Y
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void PerimeterPointCoordinate::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < PERIMETER_POINT_COORDINATE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f32X
           >> m_f32Y;
}

//////////////////////////////////////////////////////////////////////////

KDataStream PerimeterPointCoordinate::Encode() const
{
    KDataStream stream;

    PerimeterPointCoordinate::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void PerimeterPointCoordinate::Encode( KDataStream & stream ) const
{
    stream << m_f32X
           << m_f32Y;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PerimeterPointCoordinate::operator == ( const PerimeterPointCoordinate & Value ) const
{
    if( m_f32X != Value.m_f32X ) return false;
    if( m_f32Y != Value.m_f32Y ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PerimeterPointCoordinate::operator != ( const PerimeterPointCoordinate & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 & PerimeterPointCoordinate::operator [] ( KUINT16 i ) throw( KException )
{
    switch( i )
    {
    case 0:
        return m_f32X;
    case 1:
        return m_f32Y;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////

const KFLOAT32 & PerimeterPointCoordinate::operator [] ( KUINT16 i ) const throw( KException )
{
    switch( i )
    {
    case 0:
        return m_f32X;
    case 1:
        return m_f32Y;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////


