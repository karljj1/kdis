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

#include "./Supplies.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Supplies::Supplies( void ) :
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

Supplies::~Supplies( void )
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




