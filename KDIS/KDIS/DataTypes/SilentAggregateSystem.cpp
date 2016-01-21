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

#include "./SilentAggregateSystem.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SilentAggregateSystem::SilentAggregateSystem() :
    m_ui16NumAggregates( 0 ),
    m_ui16Padding( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

SilentAggregateSystem::SilentAggregateSystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SilentAggregateSystem::SilentAggregateSystem( KUINT16 NumAggregates, const AggregateType & T ) :
    m_ui16NumAggregates( NumAggregates ),
    m_ui16Padding( 0 ),
    m_AggTyp( T )
{
}

//////////////////////////////////////////////////////////////////////////

SilentAggregateSystem::~SilentAggregateSystem()
{
}

//////////////////////////////////////////////////////////////////////////

void SilentAggregateSystem::SetNumberOfAggregates( KUINT16 NOA )
{
    m_ui16NumAggregates = NOA;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SilentAggregateSystem::GetNumberOfAggregates() const
{
    return m_ui16NumAggregates;
}

//////////////////////////////////////////////////////////////////////////

void SilentAggregateSystem::SetAggregateType( const AggregateType & A )
{
    m_AggTyp = A;
}

//////////////////////////////////////////////////////////////////////////

const AggregateType & SilentAggregateSystem::GetAggregateType() const
{
    return m_AggTyp;
}

//////////////////////////////////////////////////////////////////////////

AggregateType & SilentAggregateSystem::GetAggregateType()
{
    return m_AggTyp;
}

//////////////////////////////////////////////////////////////////////////

KString SilentAggregateSystem::GetAsString() const
{
    KStringStream ss;

    ss << "Silent Aggregate System:\n"
       << "Number Of Aggregates:  " << m_ui16NumAggregates << "\n"
       << m_AggTyp.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SilentAggregateSystem::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SilentAggregateSystem::SILENT_AGGREGATE_SYSTEM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16NumAggregates
           >> KDIS_STREAM m_AggTyp
           >> m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream SilentAggregateSystem::Encode() const
{
    KDataStream stream;

    SilentAggregateSystem::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SilentAggregateSystem::Encode( KDataStream & stream ) const
{
    stream << m_ui16NumAggregates
           << KDIS_STREAM m_AggTyp
           << m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SilentAggregateSystem::operator == ( const SilentAggregateSystem & Value ) const
{
    if( m_ui16NumAggregates != Value.m_ui16NumAggregates ) return false;
    if( m_AggTyp            != Value.m_AggTyp )            return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SilentAggregateSystem::operator != ( const SilentAggregateSystem & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
