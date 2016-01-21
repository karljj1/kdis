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

#include "./FlareState.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

FlareState::FlareState() :
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

FlareState::~FlareState()
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
       << "\tTime Since Creation:   " << m_ui32TSC                 << "\n"
       << "\tSource:                " << m_Src.GetAsString()
       << "\tNumber Intensity:      " << m_ui32NumInt            << "\n"
       << "\tNumber Of Sources:     " << m_ui32NumSrcs          << "\n"
       << "\tGeometry Index:        " << m_ui16GeometryIndex   << "\n";

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
