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

#include "./SilentAggregateSystem.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SilentAggregateSystem::SilentAggregateSystem( void ) :
    m_ui16NumAggregates( 0 )
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
    m_AggTyp( T )
{
}

//////////////////////////////////////////////////////////////////////////

SilentAggregateSystem::~SilentAggregateSystem( void )
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
           >> KDIS_STREAM m_AggTyp;
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
           << KDIS_STREAM m_AggTyp;
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
