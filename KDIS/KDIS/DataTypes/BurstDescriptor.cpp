/*********************************************************************
Copyright 2013 KDIS
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

#include "./BurstDescriptor.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

BurstDescriptor::BurstDescriptor() :
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

BurstDescriptor::~BurstDescriptor()
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


