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

#include "./BoundingSphereRecord.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

BoundingSphereRecord::BoundingSphereRecord( void ) :
    m_f32Rad( 0 ),
    m_ui32Padding( 0 )
{
    m_ui32EnvRecTyp = BoundingSphereRecordType;
    m_ui16Length = ( BOUNDING_SPHERE_RECORD_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

BoundingSphereRecord::BoundingSphereRecord( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

BoundingSphereRecord::BoundingSphereRecord( KUINT8 Index, const WorldCoordinates & CentroidLocation, KFLOAT32 Radius ) :
    m_CentLocation( CentroidLocation ),
    m_f32Rad( Radius ),
    m_ui32Padding( 0 )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = BoundingSphereRecordType;
    m_ui16Length = ( BOUNDING_SPHERE_RECORD_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

BoundingSphereRecord::~BoundingSphereRecord( void )
{
}

//////////////////////////////////////////////////////////////////////////

void BoundingSphereRecord::SetCentroidLocation( const WorldCoordinates & CL )
{
    m_CentLocation = CL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & BoundingSphereRecord::GetCentroidLocation() const
{
    return m_CentLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & BoundingSphereRecord::GetCentroidLocation()
{
    return m_CentLocation;
}

//////////////////////////////////////////////////////////////////////////

void BoundingSphereRecord::SetRadius( KFLOAT32 R )
{
    m_f32Rad = R;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 BoundingSphereRecord::GetRadius() const
{
    return m_f32Rad;
}

//////////////////////////////////////////////////////////////////////////

KString BoundingSphereRecord::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tCentroid Location: " <<  m_CentLocation.GetAsString()
       << "\tRadius:   "          <<  m_f32Rad << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void BoundingSphereRecord::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < BOUNDING_SPHERE_RECORD_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_CentLocation
           >> m_f32Rad
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream BoundingSphereRecord::Encode() const
{
    KDataStream stream;

    BoundingSphereRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void BoundingSphereRecord::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_CentLocation
           << m_f32Rad
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BoundingSphereRecord::operator == ( const BoundingSphereRecord & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) ) return false;
    if( m_CentLocation != Value.m_CentLocation )  return false;
    if( m_f32Rad       != Value.m_f32Rad )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BoundingSphereRecord::operator != ( const BoundingSphereRecord & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
