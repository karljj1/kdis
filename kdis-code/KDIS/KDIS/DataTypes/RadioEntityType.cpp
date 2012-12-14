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

#include "./RadioEntityType.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

RadioEntityType::RadioEntityType( void ) :
    m_ui8EntityKind( 0 ),
    m_ui8Domain( 0 ),
    m_ui16Country( 0 ),
    m_ui8Category( 0 ),
    m_ui8NomenclatureVersion( 0 ),
    m_ui16Nomenclature( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

RadioEntityType::RadioEntityType( EntityKind Kind, KUINT8 Domain, Country Country, KUINT8  Categoy,
                                  KUINT8  NomenclatureVersion, KUINT16 Nomenclature ) :
    m_ui8EntityKind( Kind ),
    m_ui8Domain( Domain ),
    m_ui16Country( Country ),
    m_ui8Category( Categoy ),
    m_ui8NomenclatureVersion( NomenclatureVersion ),
    m_ui16Nomenclature( Nomenclature )
{
}

//////////////////////////////////////////////////////////////////////////

RadioEntityType::RadioEntityType( KUINT8 Kind, KUINT8  Domain, KUINT8 Country, KUINT8  Categoy,
                                  KUINT8  NomenclatureVersion, KUINT16 Nomenclature ) :
    m_ui8EntityKind( Kind ),
    m_ui8Domain( Domain ),
    m_ui16Country( Country ),
    m_ui8Category( Categoy ),
    m_ui8NomenclatureVersion( NomenclatureVersion ),
    m_ui16Nomenclature( Nomenclature )
{
}

//////////////////////////////////////////////////////////////////////////

RadioEntityType::RadioEntityType( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

RadioEntityType::~RadioEntityType( void )
{
}

//////////////////////////////////////////////////////////////////////////

void RadioEntityType::SetEntityKind( EntityKind UI )
{
    m_ui8EntityKind = UI;
}

//////////////////////////////////////////////////////////////////////////

EntityKind RadioEntityType::GetEntityKind() const
{
    return ( EntityKind )m_ui8EntityKind;
}

//////////////////////////////////////////////////////////////////////////

void RadioEntityType::SetDomain( EntityDomain UI )
{
    m_ui8Domain = UI;
}

//////////////////////////////////////////////////////////////////////////

EntityDomain RadioEntityType::GetDomain() const
{
    return ( EntityDomain )m_ui8Domain;
}

//////////////////////////////////////////////////////////////////////////

void RadioEntityType::SetCountry( Country UI )
{
    m_ui16Country = UI;
}

//////////////////////////////////////////////////////////////////////////

Country RadioEntityType::GetCountry() const
{
    return ( Country )m_ui16Country;
}

//////////////////////////////////////////////////////////////////////////

void RadioEntityType::SetCategory( KUINT8 UI )
{
    m_ui8Category = UI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 RadioEntityType::GetCategory() const
{
    return m_ui8Category;
}

//////////////////////////////////////////////////////////////////////////

void RadioEntityType::SetNomenclatureVersion( KUINT8 NV )
{
    m_ui8NomenclatureVersion = NV;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 RadioEntityType::GetNomenclatureVersion() const
{
    return m_ui8NomenclatureVersion;
}

//////////////////////////////////////////////////////////////////////////

void RadioEntityType::SetNomenclature( KUINT16 N )
{
    m_ui16Nomenclature = N;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 RadioEntityType::GetNomenclature() const
{
    return m_ui16Nomenclature;
}

//////////////////////////////////////////////////////////////////////////

KString RadioEntityType::GetAsString() const
{
    KStringStream ss;

    ss << ( KUINT16 )m_ui8EntityKind          << " , "
       << ( KUINT16 )m_ui8Domain              << " , "
       << ( KUINT16 )m_ui16Country            << " , "
       << ( KUINT16 )m_ui8Category            << " , "
       << ( KUINT16 )m_ui8NomenclatureVersion << " , "
       << ( KUINT16 )m_ui16Nomenclature       << " , "
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void RadioEntityType::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RADIO_ENTITY_TYPE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8EntityKind
           >> m_ui8Domain
           >> m_ui16Country
           >> m_ui8Category
           >> m_ui8NomenclatureVersion
           >> m_ui16Nomenclature;
}

//////////////////////////////////////////////////////////////////////////

KDataStream RadioEntityType::Encode() const
{
    KDataStream stream;

    RadioEntityType::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void RadioEntityType::Encode( KDataStream & stream ) const
{
    stream << m_ui8EntityKind
           << m_ui8Domain
           << m_ui16Country
           << m_ui8Category
           << m_ui8NomenclatureVersion
           << m_ui16Nomenclature;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RadioEntityType::operator == ( const RadioEntityType & Value ) const
{
    if( m_ui8EntityKind           != Value.m_ui8EntityKind )          return false;
    if( m_ui8Domain               != Value.m_ui8Domain )              return false;
    if( m_ui16Country             != Value.m_ui16Country )            return false;
    if( m_ui8Category             != Value.m_ui8Category )            return false;
    if( m_ui8NomenclatureVersion  != Value.m_ui8NomenclatureVersion ) return false;
    if( m_ui16Nomenclature        != Value.m_ui16Nomenclature )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RadioEntityType::operator != ( const RadioEntityType & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////




