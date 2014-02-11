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

#include "./Supplies.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Supplies::Supplies() :
    m_f32Quantity( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Supplies::Supplies( EntityKind Kind, KUINT8 Domain, Country Country, KUINT8 Categoy,
                    KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra, KFLOAT32 Quantity ) :
    EntityType( Kind, Domain, Country, Categoy, SubCategory, Specific, Extra ),
    m_f32Quantity( Quantity )
{
}

//////////////////////////////////////////////////////////////////////////

Supplies::Supplies( EntityType Type, KFLOAT32 Quantity ) :
    EntityType( Type ),
    m_f32Quantity( Quantity )
{
}

//////////////////////////////////////////////////////////////////////////

Supplies::Supplies( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Supplies::~Supplies()
{
}

//////////////////////////////////////////////////////////////////////////

void Supplies::SetQuantity( KFLOAT32 F )
{
    m_f32Quantity = F;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Supplies::GetQuantity() const
{
    return m_f32Quantity;
}

//////////////////////////////////////////////////////////////////////////

KString Supplies::GetAsString() const
{
    KStringStream ss;

    ss << EntityType::GetAsString()
       << "Quantity:   " << m_f32Quantity
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Supplies::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SUPPLIES_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    EntityType::Decode( stream );
    stream >> m_f32Quantity;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Supplies::Encode() const
{
    KDataStream stream;

    Supplies::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Supplies::Encode( KDataStream & stream ) const
{
    EntityType::Encode( stream );
    stream << m_f32Quantity;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Supplies::operator == ( const Supplies & Value ) const
{
    if( EntityType::operator !=( Value ) )            return false;
    if( m_f32Quantity        != Value.m_f32Quantity ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Supplies::operator != ( const Supplies & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////




