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

#include "./FlareState.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

FlareState::FlareState( void ) :
    m_ui32TSC( 0 ),
    m_ui32NumInt( 0 ),
    m_ui32NumSrcs( 0 ),
    m_ui16GeometryIndex( 0 ),
    m_ui16Padding( 0 )
{
    m_ui32EnvRecTyp = FlareStateType;
    m_ui16Length = FLARE_STATE_SIZE * 8;
}

//////////////////////////////////////////////////////////////////////////

FlareState::FlareState( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

FlareState::FlareState( KUINT8 Index, KUINT32 TimeSinceCreation, const EntityType & MunitionSource,
                        KUINT32 NumberIntensity, KUINT32 NumberOfSources, KUINT16 GeometryIndex ) :
    m_ui32TSC( TimeSinceCreation ),
    m_Src( MunitionSource ),
    m_ui32NumInt( NumberIntensity ),
    m_ui32NumSrcs( NumberOfSources ),
    m_ui16GeometryIndex( GeometryIndex ),
    m_ui16Padding( 0 )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = FlareStateType;
    m_ui16Length = FLARE_STATE_SIZE * 8;
}

//////////////////////////////////////////////////////////////////////////

FlareState::~FlareState( void )
{
}

//////////////////////////////////////////////////////////////////////////

void FlareState::SetTimeSinceCreation( KUINT32 TSC )
{
    m_ui32TSC = TSC;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 FlareState::GetTimeSinceCreation() const
{
    return m_ui32TSC;
}

//////////////////////////////////////////////////////////////////////////

void FlareState::SetSource( const EntityType & S )
{
    m_Src = S;
}

//////////////////////////////////////////////////////////////////////////

const EntityType FlareState::GetSource() const
{
    return m_Src;
}

//////////////////////////////////////////////////////////////////////////

EntityType FlareState::GetSource()
{
    return m_Src;
}

//////////////////////////////////////////////////////////////////////////

void FlareState::SetNumberIntensity( KUINT32 NI )
{
    m_ui32NumInt = NI;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 FlareState::GetNumberIntensity() const
{
    return m_ui32NumInt;
}

//////////////////////////////////////////////////////////////////////////

void FlareState::SetNumberOfSources( KUINT32 NOS )
{
    m_ui32NumSrcs = NOS;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 FlareState::GetNumberOfSources() const
{
    return m_ui32NumSrcs;
}

//////////////////////////////////////////////////////////////////////////

void FlareState::SetGeometryIndex( KUINT16 GI )
{
    m_ui16GeometryIndex = GI;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 FlareState::GetGeometryIndex() const
{
    return m_ui16GeometryIndex;
}

//////////////////////////////////////////////////////////////////////////

KString FlareState::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tTime Since Creation:	" << m_ui32TSC                 << "\n"
       << "\tSource:				" << m_Src.GetAsString()
       << "\tNumber Intensity:      " << m_ui32NumInt            << "\n"
       << "\tNumber Of Sources:		" << m_ui32NumSrcs          << "\n"
       << "\tGeometry Index:		" << m_ui16GeometryIndex   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void FlareState::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < FLARE_STATE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> m_ui32TSC
           >> KDIS_STREAM m_Src
           >> m_ui32NumInt
           >> m_ui32NumSrcs
           >> m_ui16GeometryIndex
           >> m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream FlareState::Encode() const
{
    KDataStream stream;

    FlareState::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void FlareState::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << m_ui32TSC
           << KDIS_STREAM m_Src
           << m_ui32NumInt
           << m_ui32NumSrcs
           << m_ui16GeometryIndex
           << m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FlareState::operator == ( const FlareState & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) )          return false;
    if( m_ui32TSC           != Value.m_ui32TSC )           return false;
    if( m_Src               != Value.m_Src )               return false;
    if( m_ui32NumInt        != Value.m_ui32NumInt )        return false;
    if( m_ui32NumSrcs       != Value.m_ui32NumSrcs )       return false;
    if( m_ui16GeometryIndex != Value.m_ui16GeometryIndex ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FlareState::operator != ( const FlareState & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
