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

#include "./RectangularVolumeRecord1.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord1::RectangularVolumeRecord1( void )
{
    m_ui32EnvRecTyp = RectangularVolumeRecord1Type;
    m_ui16Length = ( RECTANGLE_VOLUME_RECORD_1_SIZE - EnvironmentRecord::ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord1::RectangularVolumeRecord1( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord1::RectangularVolumeRecord1( KUINT8 Index, const WorldCoordinates & CornerLocation, const Vector & RectangleLength,
        const EulerAngles & Orientation ) :
    m_CornerLocation( CornerLocation ),
    m_RecLength( RectangleLength ),
    m_Ori( Orientation )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = RectangularVolumeRecord1Type;
    m_ui16Length = ( RECTANGLE_VOLUME_RECORD_1_SIZE - EnvironmentRecord::ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord1::~RectangularVolumeRecord1( void )
{
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord1::SetCornerLocation( const WorldCoordinates & RL )
{
    m_CornerLocation = RL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & RectangularVolumeRecord1::GetCornerLocation() const
{
    return m_CornerLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & RectangularVolumeRecord1::GetCornerLocation()
{
    return m_CornerLocation;
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord1::SetRectangleLength( const Vector & L )
{
    m_RecLength = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & RectangularVolumeRecord1::GetRectangleLength() const
{
    return m_RecLength;
}

//////////////////////////////////////////////////////////////////////////

Vector & RectangularVolumeRecord1::GetRectangleLength()
{
    return m_RecLength;
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord1::SetOrientation( const EulerAngles & O )
{
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & RectangularVolumeRecord1::GetOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & RectangularVolumeRecord1::GetOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

KString RectangularVolumeRecord1::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tCorner Location: "  << m_CornerLocation.GetAsString()
       << "\tRectangle Length: " << m_RecLength.GetAsString()
       << "\tOritantaion: "      << m_Ori.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord1::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RECTANGLE_VOLUME_RECORD_1_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_CornerLocation
           >> KDIS_STREAM m_RecLength
           >> KDIS_STREAM m_Ori;
}

//////////////////////////////////////////////////////////////////////////

KDataStream RectangularVolumeRecord1::Encode() const
{
    KDataStream stream;

    RectangularVolumeRecord1::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void RectangularVolumeRecord1::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_CornerLocation
           << KDIS_STREAM m_RecLength
           << KDIS_STREAM m_Ori;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RectangularVolumeRecord1::operator == ( const RectangularVolumeRecord1 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) )     return false;
    if( m_CornerLocation != Value.m_CornerLocation )  return false;
    if( m_RecLength      != Value.m_RecLength )       return false;
    if( m_Ori            != Value.m_Ori )             return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RectangularVolumeRecord1::operator != ( const RectangularVolumeRecord1 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
