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

#include "./WorldCoordinates.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

WorldCoordinates::WorldCoordinates( void ) :
    m_f64X( 0 ),
    m_f64Y( 0 ),
    m_f64Z( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates::WorldCoordinates( KFLOAT64  X, KFLOAT64  Y, KFLOAT64  Z ) :
    m_f64X( X ),
    m_f64Y( Y ),
    m_f64Z( Z )
{
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates::WorldCoordinates( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates::~WorldCoordinates( void )
{
}

//////////////////////////////////////////////////////////////////////////

void WorldCoordinates::SetX( KFLOAT64  X )
{
    m_f64X = X;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 WorldCoordinates::GetX() const
{
    return m_f64X;
}

//////////////////////////////////////////////////////////////////////////

void WorldCoordinates::SetY( KFLOAT64  Y )
{
    m_f64Y = Y;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 WorldCoordinates::GetY() const
{
    return m_f64Y;
}

//////////////////////////////////////////////////////////////////////////

void WorldCoordinates::SetZ( KFLOAT64  Z )
{
    m_f64Z = Z;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 WorldCoordinates::GetZ() const
{
    return m_f64Z;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 WorldCoordinates::GetDistance( const WorldCoordinates & Other )
{
	WorldCoordinates w = *this - Other;
	KFLOAT64 f = ( w.m_f64X * w.m_f64X ) + ( w.m_f64Y * w.m_f64Y ) + ( w.m_f64Z * w.m_f64Z );
	return sqrt( f );
}

//////////////////////////////////////////////////////////////////////////

KString WorldCoordinates::GetAsString() const
{
    KStringStream ss;

    ss << "X: "    << m_f64X
       << ",  Y: " << m_f64Y
       << ",  Z: " << m_f64Z << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void WorldCoordinates::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < WORLD_COORDINATES_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f64X
           >> m_f64Y
           >> m_f64Z;
}

//////////////////////////////////////////////////////////////////////////

KDataStream WorldCoordinates::Encode() const
{
    KDataStream stream;

    WorldCoordinates::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void WorldCoordinates::Encode( KDataStream & stream ) const
{
    stream << m_f64X
           << m_f64Y
           << m_f64Z;
}

//////////////////////////////////////////////////////////////////////////

KBOOL WorldCoordinates::operator == ( const WorldCoordinates & Value ) const
{
    if( m_f64X != Value.m_f64X ) return false;
    if( m_f64Y != Value.m_f64Y ) return false;
    if( m_f64Z != Value.m_f64Z ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL WorldCoordinates::operator != ( const WorldCoordinates & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates WorldCoordinates::operator * ( const WorldCoordinates & Value ) const
{
    WorldCoordinates tmp = *this;
    tmp.m_f64X *= Value.m_f64X;
    tmp.m_f64Y *= Value.m_f64Y;
    tmp.m_f64Z *= Value.m_f64Z;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates WorldCoordinates::operator * ( KFLOAT64 Value ) const
{
    WorldCoordinates tmp = *this;
    tmp.m_f64X *= Value;
    tmp.m_f64Y *= Value;
    tmp.m_f64Z *= Value;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates WorldCoordinates::operator + ( const WorldCoordinates & Value ) const
{
    WorldCoordinates tmp = *this;
    tmp.m_f64X += Value.m_f64X;
    tmp.m_f64Y += Value.m_f64Y;
    tmp.m_f64Z += Value.m_f64Z;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates WorldCoordinates::operator + ( const Vector & Value ) const
{
    WorldCoordinates tmp = *this;
    tmp.m_f64X += Value.GetX();
    tmp.m_f64Y += Value.GetY();
    tmp.m_f64Z += Value.GetZ();
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & WorldCoordinates::operator += ( const Vector & Value )
{
    m_f64X += Value.GetX();
    m_f64Y += Value.GetY();
    m_f64Z += Value.GetZ();
    return *this;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & WorldCoordinates::operator = ( const Vector & Value )
{
    m_f64X = Value.GetX();
    m_f64Y = Value.GetY();
    m_f64Z = Value.GetZ();
    return *this;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates WorldCoordinates::operator - ( const WorldCoordinates & Value ) const
{
    WorldCoordinates tmp = *this;
    tmp.m_f64X -= Value.m_f64X;
    tmp.m_f64Y -= Value.m_f64Y;
    tmp.m_f64Z -= Value.m_f64Z;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & WorldCoordinates::operator -= ( const WorldCoordinates & Value )
{
    m_f64X -= Value.m_f64X;
    m_f64Y -= Value.m_f64Y;
    m_f64Z -= Value.m_f64Z;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 & WorldCoordinates::operator[]( KUINT16 i ) throw( KException )
{
    switch( i )
    {
    case 0:
        return m_f64X;
    case 1:
        return m_f64Y;
    case 2:
        return m_f64Z;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////

const KFLOAT64 & WorldCoordinates::operator[]( KUINT16 i ) const throw( KException )
{
    switch( i )
    {
    case 0:
        return m_f64X;
    case 1:
        return m_f64Y;
    case 2:
        return m_f64Z;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////
