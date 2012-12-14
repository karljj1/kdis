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

#include "./PerimeterPointCoordinate.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

PerimeterPointCoordinate::PerimeterPointCoordinate( void ) :
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

PerimeterPointCoordinate::~PerimeterPointCoordinate( void )
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


