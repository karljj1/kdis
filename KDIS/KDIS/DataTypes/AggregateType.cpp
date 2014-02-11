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

#include "./AggregateType.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

AggregateType::AggregateType() :
    m_ui8Kind( 0 ),
    m_ui8Domain( 0 ),
    m_ui16Country( 0 ),
    m_ui8Category( 0 ),
    m_ui8SubCategory( 0 ),
    m_ui8Specific( 0 ),
    m_ui8Extra( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

AggregateType::AggregateType( AggregateKind Kind, KUINT8 Domain, Country Country, KUINT8  Categoy,
                              KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra ) :
    m_ui8Kind( Kind ),
    m_ui8Domain( Domain ),
    m_ui16Country( Country ),
    m_ui8Category( Categoy ),
    m_ui8SubCategory( SubCategory ),
    m_ui8Specific( Specific ),
    m_ui8Extra( Extra )
{
}

//////////////////////////////////////////////////////////////////////////

AggregateType::AggregateType( KUINT8 Kind, KUINT8  Domain, KUINT8 Country, KUINT8  Categoy,
                              KUINT8  SubCategory, KUINT8  Specific, KUINT8  Extra ) :
    m_ui8Kind( Kind ),
    m_ui8Domain( Domain ),
    m_ui16Country( Country ),
    m_ui8Category( Categoy ),
    m_ui8SubCategory( SubCategory ),
    m_ui8Specific( Specific ),
    m_ui8Extra( Extra )
{
}

//////////////////////////////////////////////////////////////////////////

AggregateType::AggregateType( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

AggregateType::~AggregateType()
{
}

//////////////////////////////////////////////////////////////////////////

void AggregateType::SetEntityKind( AggregateKind AK )
{
    m_ui8Kind = AK;
}

//////////////////////////////////////////////////////////////////////////

AggregateKind AggregateType::GetEntityKind() const
{
    return ( AggregateKind )m_ui8Kind;
}

//////////////////////////////////////////////////////////////////////////

void AggregateType::SetDomain( EntityDomain UI )
{
    m_ui8Domain = UI;
}

//////////////////////////////////////////////////////////////////////////

EntityDomain AggregateType::GetDomain() const
{
    return ( EntityDomain )m_ui8Domain;
}

//////////////////////////////////////////////////////////////////////////

void AggregateType::SetCountry( Country UI )
{
    m_ui16Country = UI;
}

//////////////////////////////////////////////////////////////////////////

Country AggregateType::GetCountry() const
{
    return ( Country )m_ui16Country;
}

//////////////////////////////////////////////////////////////////////////

void AggregateType::SetCategory( KUINT8 UI )
{
    m_ui8Category = UI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 AggregateType::GetCategory() const
{
    return m_ui8Category;
}

//////////////////////////////////////////////////////////////////////////

void AggregateType::SetSubCategory( KUINT8 UI )
{
    m_ui8SubCategory = UI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 AggregateType::GetSubCategory() const
{
    return m_ui8SubCategory;
}

//////////////////////////////////////////////////////////////////////////

void AggregateType::SetSpecific( KUINT8 UI )
{
    m_ui8Specific = UI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 AggregateType::GetSpecific() const
{
    return m_ui8Specific;
}

//////////////////////////////////////////////////////////////////////////

void AggregateType::SetExtra( KUINT8 UI )
{
    m_ui8Extra = UI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 AggregateType::GetExtra() const
{
    return m_ui8Extra;
}

//////////////////////////////////////////////////////////////////////////

KString AggregateType::GetAsString() const
{
    KStringStream ss;

    ss << ( KUINT16 )m_ui8Kind        << " , "
       << ( KUINT16 )m_ui8Domain      << " , "
       << ( KUINT16 )m_ui16Country    << " , "
       << ( KUINT16 )m_ui8Category    << " , "
       << ( KUINT16 )m_ui8SubCategory << " , "
       << ( KUINT16 )m_ui8Specific    << " , "
       << ( KUINT16 )m_ui8Extra
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void AggregateType::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < AGGREGATE_TYPE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8Kind
           >> m_ui8Domain
           >> m_ui16Country
           >> m_ui8Category
           >> m_ui8SubCategory
           >> m_ui8Specific
           >> m_ui8Extra;
}

//////////////////////////////////////////////////////////////////////////

KDataStream AggregateType::Encode() const
{
    KDataStream stream;

    AggregateType::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void AggregateType::Encode( KDataStream & stream ) const
{
    stream << m_ui8Kind
           << m_ui8Domain
           << m_ui16Country
           << m_ui8Category
           << m_ui8SubCategory
           << m_ui8Specific
           << m_ui8Extra;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AggregateType::operator == ( const AggregateType & Value ) const
{
    if( m_ui8Kind           != Value.m_ui8Kind )        return false;
    if( m_ui8Domain         != Value.m_ui8Domain )      return false;
    if( m_ui16Country       != Value.m_ui16Country )    return false;
    if( m_ui8Category       != Value.m_ui8Category )    return false;
    if( m_ui8SubCategory    != Value.m_ui8SubCategory ) return false;
    if( m_ui8Specific       != Value.m_ui8Specific )    return false;
    if( m_ui8Extra          != Value.m_ui8Extra )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AggregateType::operator != ( const AggregateType & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KBOOL AggregateType::operator < ( const AggregateType & Value ) const
{
    // We will bit shift all 7 fields into a single KUINT64, this will generate a new unique value which we can then use for comparison.
    // bits 56-63 = Kind
    // bits 48-55 = Domain
    // bits 32-47 = Country
    // bits 24-31 = Category
    // bits 16-23 = SubCategory
    // bits 8-15  = Specific
    // bits 0-7   = Extra
    KUINT64 ui64ThisCmpVal = 0, ui64OtherCmpVal = 0;

    ui64ThisCmpVal = ( KUINT64 )m_ui8Kind << 56 | ( KUINT64 )m_ui8Domain << 48 | ( KUINT64 )m_ui16Country << 32 | ( KUINT64 )m_ui8Category << 24 | ( KUINT64 )m_ui8SubCategory << 16 | ( KUINT64 )m_ui8Specific << 8 | ( KUINT64 )m_ui8Extra;

    ui64OtherCmpVal = ( KUINT64 )Value.m_ui8Kind << 56 | ( KUINT64 )Value.m_ui8Domain << 48 | ( KUINT64 )Value.m_ui16Country << 32 | ( KUINT64 )Value.m_ui8Category << 24 | ( KUINT64 )Value.m_ui8SubCategory << 16 | ( KUINT64 )Value.m_ui8Specific << 8 | ( KUINT64 )Value.m_ui8Extra;

    return ui64ThisCmpVal < ui64OtherCmpVal;
}

//////////////////////////////////////////////////////////////////////////

