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

#include "./LineRecord1.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

LineRecord1::LineRecord1( void )
{
    m_ui32EnvRecTyp = LineRecord1Type;
    m_ui16Length = ( LINE_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

LineRecord1::LineRecord1( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LineRecord1::LineRecord1( KUINT8 Index, const WorldCoordinates & Start, const WorldCoordinates & End  ) :
    m_StartLocation( Start ),
    m_EndLocation( End )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = LineRecord1Type;
    m_ui16Length = ( LINE_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

LineRecord1::~LineRecord1( void )
{
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::SetLocation( const WorldCoordinates & Start, const WorldCoordinates & End )
{
    m_StartLocation = Start;
    m_EndLocation = End;
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::SetStartLocation( const WorldCoordinates & L )
{
    m_StartLocation = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & LineRecord1::GetStartLocation() const
{
    return m_StartLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & LineRecord1::GetStartLocation()
{
    return m_StartLocation;
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::SetEndLocation( const WorldCoordinates & L )
{
    m_EndLocation = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & LineRecord1::GetEndLocation() const
{
    return m_EndLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & LineRecord1::GetEndLocation()
{
    return m_EndLocation;
}

//////////////////////////////////////////////////////////////////////////

KString LineRecord1::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tStart Location: " <<  m_StartLocation.GetAsString()
       << "\tEnd Location:   " <<  m_EndLocation.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LINE_RECORD_1_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_StartLocation
           >> KDIS_STREAM m_EndLocation;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LineRecord1::Encode() const
{
    KDataStream stream;

    LineRecord1::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_StartLocation
           << KDIS_STREAM m_EndLocation;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LineRecord1::operator == ( const LineRecord1 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) ) return false;
    if( m_StartLocation != Value.m_StartLocation ) return false;
    if( m_EndLocation   != Value.m_EndLocation ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LineRecord1::operator != ( const LineRecord1 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
