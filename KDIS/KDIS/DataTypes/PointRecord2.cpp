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

#include "./PointRecord2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

PointRecord2::PointRecord2( void ) :
    m_ui32Padding( 0 )
{
    m_ui32EnvRecTyp = PointRecord2Type;
    m_ui16Length = ( POINT_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

PointRecord2::PointRecord2( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

PointRecord2::PointRecord2( KUINT8 Index, const WorldCoordinates & Location, const Vector & Velocity ) :
    PointRecord1( Index, Location ),
    m_Vel( Velocity ),
    m_ui32Padding( 0 )
{
    m_ui32EnvRecTyp = PointRecord2Type;
    m_ui16Length = ( POINT_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

PointRecord2::~PointRecord2( void )
{
}

//////////////////////////////////////////////////////////////////////////

void PointRecord2::SetVelocity( const Vector & V )
{
    m_Vel = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & PointRecord2::GetVelocity() const
{
    return m_Vel;
}

//////////////////////////////////////////////////////////////////////////

Vector & PointRecord2::GetVelocity()
{
    return m_Vel;
}

//////////////////////////////////////////////////////////////////////////

KString PointRecord2::GetAsString() const
{
    KStringStream ss;

    ss << PointRecord1::GetAsString()
       << "\tVelocity(m/s): " <<  m_Vel.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void PointRecord2::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < POINT_RECORD_2_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    PointRecord1::Decode( stream );
    stream >> KDIS_STREAM m_Vel
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream PointRecord2::Encode() const
{
    KDataStream stream;

    PointRecord2::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void PointRecord2::Encode( KDataStream & stream ) const
{
    PointRecord1::Encode( stream );
    stream << KDIS_STREAM m_Vel
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointRecord2::operator == ( const PointRecord2 & Value )const
{
    if( PointRecord1::operator !=( Value ) ) return false;
    if( m_Vel != Value.m_Vel ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointRecord2::operator != ( const PointRecord2 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
