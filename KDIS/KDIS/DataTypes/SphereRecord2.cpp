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

#include "./SphereRecord2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

SphereRecord2::SphereRecord2()
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

SphereRecord2::~SphereRecord2()
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

    SphereRecord2::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SphereRecord2::Encode( KDataStream & stream ) const
{
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
