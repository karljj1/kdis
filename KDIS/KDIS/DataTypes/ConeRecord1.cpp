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

#include "./ConeRecord1.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ConeRecord1::ConeRecord1() :
    m_ui32Padding( 0 )
{
    m_ui32EnvRecTyp = ConeRecord1Type;
    m_ui16Length = ( CONE_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

ConeRecord1::ConeRecord1( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ConeRecord1::ConeRecord1( KUINT8 Index, const WorldCoordinates & VertexLocation, const EulerAngles & Orientation,
                          KFLOAT32 Height, KFLOAT32 PeakAngle ) :
    m_Loc( VertexLocation ),
    m_Ori( Orientation ),
    m_f32Height( Height ),
    m_f32PeakAngle( PeakAngle ),
    m_ui32Padding( 0 )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = ConeRecord1Type;
    m_ui16Length = ( CONE_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

ConeRecord1::~ConeRecord1()
{
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord1::SetVertexLocation( const WorldCoordinates & VL )
{
    m_Loc = VL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & ConeRecord1::GetVertexLocation() const
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & ConeRecord1::GetVertexLocation()
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord1::SetOrientation( const EulerAngles & O )
{
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & ConeRecord1::GetOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & ConeRecord1::GetOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord1::SetHeight( KFLOAT32 H )
{
    m_f32Height = H;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 ConeRecord1::GetHeight() const
{
    return m_f32Height;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord1::SetPeakAngle( KFLOAT32 PA )
{
    m_f32PeakAngle = PA;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 ConeRecord1::GetPeakAngle() const
{
    return m_f32PeakAngle;
}

//////////////////////////////////////////////////////////////////////////

KString ConeRecord1::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tVertex Location: " << m_Loc.GetAsString()
       << "\tOritantaion: "     << m_Ori.GetAsString()
       << "\tHeight: "          << m_f32Height          << "\n"
       << "\tPeak Angle: "      << m_f32PeakAngle       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord1::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < CONE_RECORD_1_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_Loc
           >> KDIS_STREAM m_Ori
           >> m_f32Height
           >> m_f32PeakAngle
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ConeRecord1::Encode() const
{
    KDataStream stream;

    ConeRecord1::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord1::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_Loc
           << KDIS_STREAM m_Ori
           << m_f32Height
           << m_f32PeakAngle
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ConeRecord1::operator == ( const ConeRecord1 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) ) return false;
    if( m_Loc          != Value.m_Loc )           return false;
    if( m_Ori          != Value.m_Ori )           return false;
    if( m_f32Height    != Value.m_f32Height )     return false;
    if( m_f32PeakAngle != Value.m_f32PeakAngle )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ConeRecord1::operator != ( const ConeRecord1 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
