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

#include "./RectangularVolumeRecord3.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord3::RectangularVolumeRecord3()
{
    m_ui32EnvRecTyp = RectangularVolumeRecord3Type;
    m_ui16Length = ( RECTANGLE_VOLUME_RECORD_3_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord3::RectangularVolumeRecord3( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord3::RectangularVolumeRecord3( KUINT8 Index, const WorldCoordinates & CenterLocation, const Vector & RectangleLength,
        const EulerAngles & Orientation ) :
    m_CentLocation( CenterLocation ),
    m_RecLength( RectangleLength ),
    m_Ori( Orientation )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = RectangularVolumeRecord3Type;
    m_ui16Length = ( RECTANGLE_VOLUME_RECORD_3_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord3::~RectangularVolumeRecord3()
{
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord3::SetCenterLocation( const WorldCoordinates & RL )
{
    m_CentLocation = RL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & RectangularVolumeRecord3::GetCenterLocation() const
{
    return m_CentLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & RectangularVolumeRecord3::GetCenterLocation()
{
    return m_CentLocation;
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord3::SetRectangleLength( const Vector & L )
{
    m_RecLength = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & RectangularVolumeRecord3::GetRectangleLength() const
{
    return m_RecLength;
}

//////////////////////////////////////////////////////////////////////////

Vector & RectangularVolumeRecord3::GetRectangleLength()
{
    return m_RecLength;
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord3::SetOrientation( const EulerAngles & O )
{
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & RectangularVolumeRecord3::GetOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & RectangularVolumeRecord3::GetOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

KString RectangularVolumeRecord3::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tCenter Location:  " << m_CentLocation.GetAsString()
       << "\tRectangle Length: " << m_RecLength.GetAsString()
       << "\tOritantaion:      " << m_Ori.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord3::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RECTANGLE_VOLUME_RECORD_3_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_CentLocation
           >> KDIS_STREAM m_RecLength
           >> KDIS_STREAM m_Ori;
}

//////////////////////////////////////////////////////////////////////////

KDataStream RectangularVolumeRecord3::Encode() const
{
    KDataStream stream;

    RectangularVolumeRecord3::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord3::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_CentLocation
           << KDIS_STREAM m_RecLength
           << KDIS_STREAM m_Ori;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RectangularVolumeRecord3::operator == ( const RectangularVolumeRecord3 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) )     return false;
    if( m_CentLocation   != Value.m_CentLocation )  return false;
    if( m_RecLength      != Value.m_RecLength )       return false;
    if( m_Ori            != Value.m_Ori )             return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RectangularVolumeRecord3::operator != ( const RectangularVolumeRecord3 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
