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

#include "./PointRecord2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

PointRecord2::PointRecord2() :
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

PointRecord2::~PointRecord2()
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
