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

#include "./COMBICState.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

COMBICState::COMBICState() :
    m_ui32TSC( 0 ),
    m_ui32NumSrcs( 0 ),
    m_ui16GeometryIndex( 0 ),
    m_ui16Padding( 0 ),
    m_ui32SrcType( 0 ),
    m_f32BarrageRate( 0 ),
    m_f32BarrageDuration( 0 ),
    m_f32BarrageCrosswindLength( 0 ),
    m_f32BarrageDownwindLength( 0 ),
    m_ui32Padding( 0 )
{
    m_ui32EnvRecTyp = COMBICStateType;
    m_ui16Length = COMBIC_STATE_SIZE * 8;
}

//////////////////////////////////////////////////////////////////////////

COMBICState::COMBICState( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

COMBICState::COMBICState( KUINT8 Index, KUINT32 TimeSinceCreation, const EntityType & MunitionSource,
                          KUINT32 NumberOfSources, KUINT16 GeometryIndex, KUINT32 SourceType,
                          KFLOAT32 BarrageRate, KFLOAT32 BarrageDuration, KFLOAT32 BarrageCrosswindLength,
                          KFLOAT32 BarrageDownwindLength, const EulerAngles & DetonationVelocity ) :
    m_ui32TSC( TimeSinceCreation ),
    m_MunSrc( MunitionSource ),
    m_ui32NumSrcs( NumberOfSources ),
    m_ui16GeometryIndex( GeometryIndex ),
    m_ui16Padding( 0 ),
    m_ui32SrcType( SourceType ),
    m_f32BarrageRate( BarrageRate ),
    m_f32BarrageDuration( BarrageDuration ),
    m_f32BarrageCrosswindLength( BarrageCrosswindLength ),
    m_f32BarrageDownwindLength( BarrageDownwindLength ),
    m_DetVel( DetonationVelocity ),
    m_ui32Padding( 0 )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = COMBICStateType;
    m_ui16Length = COMBIC_STATE_SIZE * 8;
}

//////////////////////////////////////////////////////////////////////////

COMBICState::~COMBICState()
{
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetTimeSinceCreation( KUINT32 TSC )
{
    m_ui32TSC = TSC;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 COMBICState::GetTimeSinceCreation() const
{
    return m_ui32TSC;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetMunitionSource( const EntityType & MS )
{
    m_MunSrc = MS;
}

//////////////////////////////////////////////////////////////////////////

const EntityType COMBICState::GetMunitionSource() const
{
    return m_MunSrc;
}

//////////////////////////////////////////////////////////////////////////

EntityType COMBICState::GetMunitionSource()
{
    return m_MunSrc;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetNumberOfSources( KUINT32 NOS )
{
    m_ui32NumSrcs = NOS;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 COMBICState::GetNumberOfSources() const
{
    return m_ui32NumSrcs;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetGeometryIndex( KUINT16 GI )
{
    m_ui16GeometryIndex = GI;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 COMBICState::GetGeometryIndex() const
{
    return m_ui16GeometryIndex;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetSourceType( KUINT32 ST )
{
    m_ui32SrcType = ST;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 COMBICState::GetSourceType() const
{
    return m_ui32SrcType;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetBarrageRate( KFLOAT32 BR )
{
    m_f32BarrageRate = BR;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 COMBICState::GetBarrageRate() const
{
    return m_f32BarrageRate;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetBarrageDuration( KFLOAT32 BD )
{
    m_f32BarrageDuration = BD;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 COMBICState::GetBarrageDuration() const
{
    return m_f32BarrageDuration;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetBarrageCrosswindLength( KFLOAT32 BCL )
{
    m_f32BarrageCrosswindLength = BCL;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 COMBICState::GetBarrageCrosswindLength() const
{
    return m_f32BarrageCrosswindLength;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetBarrageDownwindLength( KFLOAT32 BDL )
{
    m_f32BarrageDownwindLength = BDL;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 COMBICState::GetBarrageDownwindLength() const
{
    return m_f32BarrageDownwindLength;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::SetDetonationVelocity( const EulerAngles & DV )
{
    m_DetVel = DV;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & COMBICState::GetDetonationVelocity() const
{
    return m_DetVel;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & COMBICState::GetDetonationVelocity()
{
    return m_DetVel;
}

//////////////////////////////////////////////////////////////////////////

KString COMBICState::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tTime Since Creation:       " << m_ui32TSC                   << "\n"
       << "\tMunition Source:           " << m_MunSrc.GetAsString()
       << "\tNumber Of Sources:         " << m_ui32NumSrcs               << "\n"
       << "\tGeometry Index:            " << m_ui16GeometryIndex         << "\n"
       << "\tSource Type:               " << m_ui32SrcType               << "\n"
       << "\tBarrage Rate:              " << m_f32BarrageRate            << "\n"
       << "\tBarrage Duration:          " << m_f32BarrageDuration        << "\n"
       << "\tBarrage Crosswind Length:  " << m_f32BarrageCrosswindLength << "\n"
       << "\tBarrage Downwind Length:   " << m_f32BarrageDownwindLength  << "\n"
       << "\tDetonation Velocity:       " << m_DetVel.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < COMBIC_STATE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> m_ui32TSC
           >> KDIS_STREAM m_MunSrc
           >> m_ui32NumSrcs
           >> m_ui16GeometryIndex
           >> m_ui16Padding
           >> m_ui32SrcType
           >> m_f32BarrageRate
           >> m_f32BarrageDuration
           >> m_f32BarrageCrosswindLength
           >> m_f32BarrageDownwindLength
           >> KDIS_STREAM m_DetVel
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream COMBICState::Encode() const
{
    KDataStream stream;

    COMBICState::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void COMBICState::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << m_ui32TSC
           << KDIS_STREAM m_MunSrc
           << m_ui32NumSrcs
           << m_ui16GeometryIndex
           << m_ui16Padding
           << m_ui32SrcType
           << m_f32BarrageRate
           << m_f32BarrageDuration
           << m_f32BarrageCrosswindLength
           << m_f32BarrageDownwindLength
           << KDIS_STREAM m_DetVel
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL COMBICState::operator == ( const COMBICState & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) )                          return false;
    if( m_ui32TSC                   != Value.m_ui32TSC )                   return false;
    if( m_MunSrc                    != Value.m_MunSrc )                    return false;
    if( m_ui32NumSrcs               != Value.m_ui32NumSrcs )               return false;
    if( m_ui16GeometryIndex         != Value.m_ui16GeometryIndex )         return false;
    if( m_ui32SrcType               != Value.m_ui32SrcType )               return false;
    if( m_f32BarrageRate            != Value.m_f32BarrageRate )            return false;
    if( m_f32BarrageDuration        != Value.m_f32BarrageDuration )        return false;
    if( m_f32BarrageCrosswindLength != Value.m_f32BarrageCrosswindLength ) return false;
    if( m_f32BarrageDownwindLength  != Value.m_f32BarrageDownwindLength )  return false;
    if( m_DetVel                    != Value.m_DetVel )                    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL COMBICState::operator != ( const COMBICState & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
