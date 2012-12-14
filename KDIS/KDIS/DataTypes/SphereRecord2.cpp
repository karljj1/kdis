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

#include "./SphereRecord2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

SphereRecord2::SphereRecord2( void )
{
    m_ui32EnvRecTyp = SphereRecord2Type;
    m_ui16Length = ( SPHERE_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

SphereRecord2::SphereRecord2( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SphereRecord2::SphereRecord2( KUINT8 Index, const WorldCoordinates & CentroidLocation, KFLOAT32 Radius,
                              KFLOAT32 DDT, const Vector & Velocity, const Vector & AngularVelocity ) :
    SphereRecord1( Index, CentroidLocation, Radius ),
    m_f32ddt( DDT ),
    m_Velocity( Velocity ),
    m_AngularVelocity( AngularVelocity )
{
    m_ui32EnvRecTyp = SphereRecord2Type;
    m_ui16Length = ( SPHERE_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

SphereRecord2::~SphereRecord2( void )
{
}

//////////////////////////////////////////////////////////////////////////

void SphereRecord2::SetDOverDt( KFLOAT32 DDT )
{
    m_f32ddt = DDT;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 SphereRecord2::GetDOverDt() const
{
    return m_f32ddt;
}

//////////////////////////////////////////////////////////////////////////

void SphereRecord2::SetVelocity( const Vector & V )
{
    m_Velocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & SphereRecord2::GetVelocity() const
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & SphereRecord2::GetVelocity()
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

void SphereRecord2::SetAngularVelocity( const Vector & V )
{
    m_AngularVelocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & SphereRecord2::GetAngularVelocity() const
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & SphereRecord2::GetAngularVelocity()
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////


KString SphereRecord2::GetAsString() const
{
    KStringStream ss;

    ss << BoundingSphereRecord::GetAsString()
       << "\td(Radius)/dt: "    << m_f32ddt   << "\n"
       << "\tVelocity: "        << m_Velocity.GetAsString()
       << "\tAngularVelocity: " << m_AngularVelocity.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SphereRecord2::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SPHERE_RECORD_2_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_CentLocation
           >> m_f32Rad
           >> m_f32ddt
           >> KDIS_STREAM m_Velocity
           >> KDIS_STREAM m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

KDataStream SphereRecord2::Encode() const
{
    KDataStream stream;

    BoundingSphereRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SphereRecord2::Encode( KDataStream & stream ) const
{
    BoundingSphereRecord::Encode( stream );

    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_CentLocation
           << m_f32Rad
           << m_f32ddt
           << KDIS_STREAM m_Velocity
           << KDIS_STREAM m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SphereRecord2::operator == ( const SphereRecord2 & Value )const
{
    if( BoundingSphereRecord::operator !=( Value ) )  return false;
    if( m_f32ddt          != Value.m_f32ddt )         return false;
    if( m_Velocity        != Value.m_Velocity )       return false;
    if( m_AngularVelocity != Value.m_AngularVelocity )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SphereRecord2::operator != ( const SphereRecord2 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
