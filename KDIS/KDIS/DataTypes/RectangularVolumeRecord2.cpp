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

#include "./RectangularVolumeRecord2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord2::RectangularVolumeRecord2() :
    m_f32Padding( 0 )
{
    m_ui32EnvRecTyp = RectangularVolumeRecord2Type;
    m_ui16Length = ( RECTANGLE_VOLUME_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord2::RectangularVolumeRecord2( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord2::RectangularVolumeRecord2( KUINT8 Index, const WorldCoordinates & CornerLocation, const Vector & RectangleLength,
        const Vector & DDT, const EulerAngles & Orientation, const Vector & Velocity,
        const Vector & AngularVelocity ) :
    RectangularVolumeRecord1( Index, CornerLocation, RectangleLength, Orientation ),
    m_DDT( DDT ),
    m_Velocity( Velocity ),
    m_AngularVelocity( AngularVelocity ),
    m_f32Padding( 0 )
{
    m_ui32EnvRecTyp = RectangularVolumeRecord2Type;
    m_ui16Length = ( RECTANGLE_VOLUME_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord2::~RectangularVolumeRecord2()
{
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord2::SetDOverDt( const Vector & DDT )
{
    m_DDT = DDT;
}

//////////////////////////////////////////////////////////////////////////

const Vector & RectangularVolumeRecord2::GetDOverDt() const
{
    return m_DDT;
}

//////////////////////////////////////////////////////////////////////////

Vector & RectangularVolumeRecord2::GetDOverDt()
{
    return m_DDT;
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord2::SetVelocity( const Vector & V )
{
    m_Velocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & RectangularVolumeRecord2::GetVelocity() const
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & RectangularVolumeRecord2::GetVelocity()
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord2::SetAngularVelocity( const Vector & V )
{
    m_AngularVelocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & RectangularVolumeRecord2::GetAngularVelocity() const
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & RectangularVolumeRecord2::GetAngularVelocity()
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

KString RectangularVolumeRecord2::GetAsString() const
{
    KStringStream ss;

    ss << RectangularVolumeRecord1::GetAsString()
       << "\td(Length)/dt: "      << m_DDT.GetAsString()
       << "\tVelocity: "          << m_Velocity.GetAsString()
       << "\tAngular Velocity: "  << m_AngularVelocity.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord2::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RECTANGLE_VOLUME_RECORD_2_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_CornerLocation
           >> KDIS_STREAM m_RecLength
           >> KDIS_STREAM m_DDT
           >> KDIS_STREAM m_Ori
           >> KDIS_STREAM m_Velocity
           >> KDIS_STREAM m_AngularVelocity
           >> m_f32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream RectangularVolumeRecord2::Encode() const
{
    KDataStream stream;

    RectangularVolumeRecord2::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord2::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_CornerLocation
           << KDIS_STREAM m_RecLength
           << KDIS_STREAM m_DDT
           << KDIS_STREAM m_Ori
           << KDIS_STREAM m_Velocity
           << KDIS_STREAM m_AngularVelocity
           << m_f32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RectangularVolumeRecord2::operator == ( const RectangularVolumeRecord2 & Value )const
{
    if( RectangularVolumeRecord1::operator !=( Value ) )  return false;
    if( m_DDT               != Value.m_DDT )              return false;
    if( m_Velocity          != Value.m_Velocity )         return false;
    if( m_AngularVelocity   != Value.m_AngularVelocity )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RectangularVolumeRecord2::operator != ( const RectangularVolumeRecord2 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
