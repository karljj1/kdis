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

#include "./RectangularVolumeRecord3.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

RectangularVolumeRecord3::RectangularVolumeRecord3( void )
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

RectangularVolumeRecord3::~RectangularVolumeRecord3( void )
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
