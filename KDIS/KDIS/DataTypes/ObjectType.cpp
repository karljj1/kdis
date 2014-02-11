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

#include "./ObjectType.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ObjectType::ObjectType() :
    m_ui8Domain( 0 ),
    m_ui8EntityKind( 0 ),
    m_ui8Category( 0 ),
    m_ui8SubCategory( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

ObjectType::ObjectType( KUINT8 Domain, KUINT8 Kind, KUINT8 Categoy, KUINT8 SubCategory ) :
    m_ui8EntityKind( Kind ),
    m_ui8Domain( Domain ),
    m_ui8Category( Categoy ),
    m_ui8SubCategory( SubCategory )
{
}

//////////////////////////////////////////////////////////////////////////

ObjectType::ObjectType( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ObjectType::~ObjectType()
{
}

//////////////////////////////////////////////////////////////////////////

void ObjectType::SetDomain( EntityDomain UI )
{
    m_ui8Domain = UI;
}

//////////////////////////////////////////////////////////////////////////

EntityDomain ObjectType::GetDomain() const
{
    return ( EntityDomain )m_ui8Domain;
}

//////////////////////////////////////////////////////////////////////////

void ObjectType::SetEntityKind( KUINT8 UI )
{
    m_ui8EntityKind = UI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 ObjectType::GetEntityKind() const
{
    return m_ui8EntityKind;
}

//////////////////////////////////////////////////////////////////////////

void ObjectType::SetCategory( KUINT8 UI )
{
    m_ui8Category = UI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 ObjectType::GetCategory() const
{
    return m_ui8Category;
}

//////////////////////////////////////////////////////////////////////////

void ObjectType::SetSubCategory( KUINT8 UI )
{
    m_ui8SubCategory = UI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 ObjectType::GetSubCategory() const
{
    return m_ui8SubCategory;
}

//////////////////////////////////////////////////////////////////////////

KString ObjectType::GetAsString() const
{
    KStringStream ss;

    ss << ( KUINT16 )m_ui8Domain      << " , "
       << ( KUINT16 )m_ui8EntityKind  << " , "
       << ( KUINT16 )m_ui8Category    << " , "
       << ( KUINT16 )m_ui8SubCategory
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ObjectType::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < OBJECT_TYPE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8Domain
           >> m_ui8EntityKind
           >> m_ui8Category
           >> m_ui8SubCategory;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ObjectType::Encode() const
{
    KDataStream stream;

    ObjectType::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ObjectType::Encode( KDataStream & stream ) const
{
    stream << m_ui8Domain
           << m_ui8EntityKind
           << m_ui8Category
           << m_ui8SubCategory;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectType::operator == ( const ObjectType & Value ) const
{
    if( m_ui8Domain      != Value.m_ui8Domain )      return false;
    if( m_ui8EntityKind  != Value.m_ui8EntityKind )  return false;
    if( m_ui8Category    != Value.m_ui8Category )    return false;
    if( m_ui8SubCategory != Value.m_ui8SubCategory ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectType::operator != ( const ObjectType & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectType::operator < ( const ObjectType & Value ) const
{
    // We will bit shift all 4 fields into a single KUINT32, this will generate a new unique value which we can then use for comparisons.
    // bits 24-31 = SubCategory
    // bits 16-23 = Category
    // bits 8-15  = Kind
    // bits 0-7   = Domain

    KUINT32 ui32ThisCmpVal = 0, ui32OtherCmpVal = 0;

    ui32ThisCmpVal = ( KUINT32 )m_ui8SubCategory << 24 | ( KUINT32 )m_ui8EntityKind << 16 | ( KUINT32 )m_ui8Category << 8 | ( KUINT32 )m_ui8SubCategory;
    ui32OtherCmpVal = ( KUINT32 )Value.m_ui8SubCategory << 24 | ( KUINT32 )Value.m_ui8EntityKind << 16 | ( KUINT32 )Value.m_ui8Category << 8 | ( KUINT32 )Value.m_ui8SubCategory;

    return ui32ThisCmpVal < ui32OtherCmpVal;
}

//////////////////////////////////////////////////////////////////////////
