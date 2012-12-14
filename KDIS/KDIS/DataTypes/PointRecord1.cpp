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

#include "./PointRecord1.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

PointRecord1::PointRecord1( void )
{
    m_ui32EnvRecTyp = PointRecord1Type;
    m_ui16Length = ( POINT_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

PointRecord1::PointRecord1( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

PointRecord1::PointRecord1( KUINT8 Index, const WorldCoordinates & Location ) :
    m_Location( Location )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = PointRecord1Type;
    m_ui16Length = ( POINT_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

PointRecord1::~PointRecord1( void )
{
}

//////////////////////////////////////////////////////////////////////////

void PointRecord1::SetLocation( const WorldCoordinates & L )
{
    m_Location = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & PointRecord1::GetLocation() const
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & PointRecord1::GetLocation()
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

KString PointRecord1::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tLocation: " <<  m_Location.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void PointRecord1::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < POINT_RECORD_1_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_Location;
}

//////////////////////////////////////////////////////////////////////////

KDataStream PointRecord1::Encode() const
{
    KDataStream stream;

    PointRecord1::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void PointRecord1::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_Location;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointRecord1::operator == ( const PointRecord1 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) ) return false;
    if( m_Location != Value.m_Location ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointRecord1::operator != ( const PointRecord1 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
