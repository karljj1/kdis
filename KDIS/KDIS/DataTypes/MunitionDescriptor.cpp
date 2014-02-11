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

#include "./MunitionDescriptor.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

MunitionDescriptor::MunitionDescriptor() :
    m_ui16Warhead( 0 ),
    m_ui16Fuse( 0 ),
    m_ui16Quantity( 0 ),
    m_ui16Rate( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

MunitionDescriptor::MunitionDescriptor( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

MunitionDescriptor::MunitionDescriptor( const EntityType & T, WarheadType WT, FuseType FT,
                                        KUINT16 Quantity, KUINT16 Rate ) :
    Descriptor( T ),
    m_ui16Warhead( WT ),
    m_ui16Fuse( FT ),
    m_ui16Quantity( Quantity ),
    m_ui16Rate( Rate )
{
}

//////////////////////////////////////////////////////////////////////////

MunitionDescriptor::~MunitionDescriptor()
{
}

//////////////////////////////////////////////////////////////////////////

void MunitionDescriptor::SetWarhead( WarheadType WT )
{
    m_ui16Warhead = WT;
}

//////////////////////////////////////////////////////////////////////////

WarheadType MunitionDescriptor::GetWarhead() const
{
    return ( WarheadType )m_ui16Warhead;
}

//////////////////////////////////////////////////////////////////////////

void MunitionDescriptor::SetFuse( FuseType FT )
{
    m_ui16Fuse = FT;
}

//////////////////////////////////////////////////////////////////////////

FuseType MunitionDescriptor::GetFuse() const
{
    return ( FuseType )m_ui16Fuse;
}

//////////////////////////////////////////////////////////////////////////

void MunitionDescriptor::SetQuantity( KUINT16 Q )
{
    m_ui16Quantity = Q;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 MunitionDescriptor::GetQuantity() const
{
    return m_ui16Quantity;
}

//////////////////////////////////////////////////////////////////////////

void MunitionDescriptor::SetRate( KUINT16 R )
{
    m_ui16Rate = R;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 MunitionDescriptor::GetRate() const
{
    return m_ui16Rate;
}

//////////////////////////////////////////////////////////////////////////

KString MunitionDescriptor::GetAsString() const
{
    KStringStream ss;

    ss << "Descriptor:"
       << "\n\tType:     " << m_Type.GetAsString()
       << "\tWarhead:  "   << GetEnumAsStringWarheadType( m_ui16Warhead )
       << "\n\tFuse:     " << GetEnumAsStringFuseType( m_ui16Fuse )
       << "\n\tQuantity: " << m_ui16Quantity
       << "\n\tRate:     " << m_ui16Rate
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void MunitionDescriptor::Decode( KDataStream & stream ) throw( KException )
{
	Descriptor::Decode( stream );

    stream >> m_ui16Warhead
           >> m_ui16Fuse
           >> m_ui16Quantity
           >> m_ui16Rate;
}

//////////////////////////////////////////////////////////////////////////

KDataStream MunitionDescriptor::Encode() const
{
    KDataStream stream;

    MunitionDescriptor::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void MunitionDescriptor::Encode( KDataStream & stream ) const
{
	Descriptor::Encode( stream );

    stream << m_ui16Warhead
           << m_ui16Fuse
           << m_ui16Quantity
           << m_ui16Rate;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MunitionDescriptor::operator == ( const MunitionDescriptor & Value ) const
{
	if( Descriptor::operator != ( Value ) )            return false;
    if( m_ui16Warhead        != Value.m_ui16Warhead )  return false;
    if( m_ui16Fuse           != Value.m_ui16Fuse )     return false;
    if( m_ui16Quantity       != Value.m_ui16Quantity ) return false;
    if( m_ui16Rate           != Value.m_ui16Rate )     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MunitionDescriptor::operator != ( const MunitionDescriptor & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


