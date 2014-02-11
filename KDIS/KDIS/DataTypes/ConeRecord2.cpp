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

#include "./ConeRecord2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ConeRecord2::ConeRecord2() :
    m_f32ddtHeight( 0 ),
    m_f32ddtPeak( 0 )
{
    m_ui32EnvRecTyp = ConeRecord2Type;
    m_ui16Length = CONE_RECORD_2_SIZE * 8;
}

//////////////////////////////////////////////////////////////////////////

ConeRecord2::ConeRecord2( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ConeRecord2::ConeRecord2( KUINT8 Index, const WorldCoordinates & VertexLocation, const EulerAngles & Orientation,
                          const Vector & Velocity, const Vector & AngularVelocity, KFLOAT32 Height,
                          KFLOAT32 PeakAngle, KFLOAT32 DHeightOverDt, KFLOAT32 DPeakAngleOverDt ) :
    ConeRecord1( Index, VertexLocation, Orientation, Height, PeakAngle ),
    m_Velocity( Velocity ),
    m_AngularVelocity( AngularVelocity ),
    m_f32ddtHeight( DHeightOverDt ),
    m_f32ddtPeak( DPeakAngleOverDt )
{
    m_ui32EnvRecTyp = ConeRecord2Type;
    m_ui16Length = CONE_RECORD_2_SIZE * 8;
}

//////////////////////////////////////////////////////////////////////////

ConeRecord2::~ConeRecord2()
{
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::SetVelocity( const Vector & V )
{
    m_Velocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & ConeRecord2::GetVelocity() const
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & ConeRecord2::GetVelocity()
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::SetAngularVelocity( const Vector & V )
{
    m_AngularVelocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & ConeRecord2::GetAngularVelocity() const
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & ConeRecord2::GetAngularVelocity()
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::SetDHeightOverDt( KFLOAT32 DDT )
{
    m_f32ddtHeight = DDT;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 ConeRecord2::GetDHeightOverDt() const
{
    return m_f32ddtHeight;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::SetDPeakAngleOverDt( KFLOAT32 DDT )
{
    m_f32ddtPeak = DDT;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 ConeRecord2::GetDPeakAngleOverDt() const
{
    return m_f32ddtPeak;
}

//////////////////////////////////////////////////////////////////////////

KString ConeRecord2::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tVertex Location: "  << m_Loc.GetAsString()
       << "\tOritantaion: "      << m_Ori.GetAsString()
       << "\tVelocity: "         << m_Velocity.GetAsString()
       << "\tAngular Velocity: " << m_AngularVelocity.GetAsString()
       << "\tHeight: "           << m_f32Height         << "\n"
       << "\td(Height)/dt: "     << m_f32ddtHeight      << "\n"
       << "\tPeak Angle: "       << m_f32PeakAngle      << "\n"
       << "\td(Peak Angle)/dt: " << m_f32ddtPeak        << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < CONE_RECORD_2_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_Loc
           >> KDIS_STREAM m_Ori
           >> KDIS_STREAM m_Velocity
           >> KDIS_STREAM m_AngularVelocity
           >> m_f32Height
           >> m_f32ddtHeight
           >> m_f32PeakAngle
           >> m_f32ddtPeak
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ConeRecord2::Encode() const
{
    KDataStream stream;

    ConeRecord2::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_Loc
           << KDIS_STREAM m_Ori
           << KDIS_STREAM m_Velocity
           << KDIS_STREAM m_AngularVelocity
           << m_f32Height
           << m_f32ddtHeight
           << m_f32PeakAngle
           << m_f32ddtPeak
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ConeRecord2::operator == ( const ConeRecord2 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) )         return false;
    if( m_Loc               != Value.m_Loc )              return false;
    if( m_Ori               != Value.m_Ori )              return false;
    if( m_Velocity          != Value.m_Velocity )         return false;
    if( m_AngularVelocity   != Value.m_AngularVelocity )  return false;
    if( m_f32Height         != Value.m_f32Height )        return false;
    if( m_f32ddtHeight      != Value.m_f32ddtHeight )     return false;
    if( m_f32PeakAngle      != Value.m_f32PeakAngle )     return false;
    if( m_f32ddtPeak        != Value.m_f32ddtPeak )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ConeRecord2::operator != ( const ConeRecord2 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
