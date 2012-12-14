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

#include "./BurstDescriptor.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

BurstDescriptor::BurstDescriptor( void ) :
    m_ui16Warhead( 0 ),
    m_ui16Fuse( 0 ),
    m_ui16Quantity( 0 ),
    m_ui16Rate( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

BurstDescriptor::BurstDescriptor( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

BurstDescriptor::BurstDescriptor( const EntityType & M, WarheadType WT, FuseType FT,
                                  KUINT16 Quantity, KUINT16 Rate ) :
    m_Munition( M ),
    m_ui16Warhead( WT ),
    m_ui16Fuse( FT ),
    m_ui16Quantity( Quantity ),
    m_ui16Rate( Rate )
{
}

//////////////////////////////////////////////////////////////////////////

BurstDescriptor::~BurstDescriptor( void )
{
}

//////////////////////////////////////////////////////////////////////////

void BurstDescriptor::SetMunition( const EntityType & M )
{
    m_Munition = M;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & BurstDescriptor::GetMunition() const
{
    return m_Munition;
}

//////////////////////////////////////////////////////////////////////////

EntityType & BurstDescriptor::GetMunition()
{
    return m_Munition;
}

//////////////////////////////////////////////////////////////////////////

void BurstDescriptor::SetWarhead( WarheadType WT )
{
    m_ui16Warhead = WT;
}

//////////////////////////////////////////////////////////////////////////

WarheadType BurstDescriptor::GetWarhead() const
{
    return ( WarheadType )m_ui16Warhead;
}

//////////////////////////////////////////////////////////////////////////

void BurstDescriptor::SetFuse( FuseType FT )
{
    m_ui16Fuse = FT;
}

//////////////////////////////////////////////////////////////////////////

FuseType BurstDescriptor::GetFuse() const
{
    return ( FuseType )m_ui16Fuse;
}

//////////////////////////////////////////////////////////////////////////

void BurstDescriptor::SetQuantity( KUINT16 Q )
{
    m_ui16Quantity = Q;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 BurstDescriptor::GetQuantity() const
{
    return m_ui16Quantity;
}

//////////////////////////////////////////////////////////////////////////

void BurstDescriptor::SetRate( KUINT16 R )
{
    m_ui16Rate = R;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 BurstDescriptor::GetRate() const
{
    return m_ui16Rate;
}

//////////////////////////////////////////////////////////////////////////

KString BurstDescriptor::GetAsString() const
{
    KStringStream ss;

    ss << "Burst Descriptor:"
       << "\n\tMunition: " << m_Munition.GetAsString()
       << "\tWarhead:  "   << GetEnumAsStringWarheadType( m_ui16Warhead )
       << "\n\tFuse:     " << GetEnumAsStringFuseType( m_ui16Fuse )
       << "\n\tQuantity: " << m_ui16Quantity
       << "\n\tRate:     " << m_ui16Rate
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void BurstDescriptor::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < BURST_DESCRIPTOR_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> KDIS_STREAM m_Munition
           >> m_ui16Warhead
           >> m_ui16Fuse
           >> m_ui16Quantity
           >> m_ui16Rate;
}

//////////////////////////////////////////////////////////////////////////

KDataStream BurstDescriptor::Encode() const
{
    KDataStream stream;

    BurstDescriptor::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void BurstDescriptor::Encode( KDataStream & stream ) const
{
    stream << KDIS_STREAM m_Munition
           << m_ui16Warhead
           << m_ui16Fuse
           << m_ui16Quantity
           << m_ui16Rate;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BurstDescriptor::operator == ( const BurstDescriptor & Value ) const
{
    if( m_Munition      != Value.m_Munition )     return false;
    if( m_ui16Warhead   != Value.m_ui16Warhead )  return false;
    if( m_ui16Fuse      != Value.m_ui16Fuse )     return false;
    if( m_ui16Quantity  != Value.m_ui16Quantity ) return false;
    if( m_ui16Rate      != Value.m_ui16Rate )     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BurstDescriptor::operator != ( const BurstDescriptor & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


