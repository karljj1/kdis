/*********************************************************************
Copyright 2017 Karl Jones
               Dale Marchand
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

#include "./JammingTechnique.h"

using namespace KDIS;
using namespace DATA_TYPE;
using std::endl;

#if DIS_VERSION > 6

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

JammingTechnique::JammingTechnique() :
  DataTypeBase(),
  m_ui8Kind( 0u ),
  m_ui8Category( 0u ),
  m_ui8Subcategory( 0u ),
  m_ui8Specific( 0u )
{
}

//////////////////////////////////////////////////////////////////////////

JammingTechnique::JammingTechnique( KDataStream & stream ) throw( KException ) :
  DataTypeBase(),
  m_ui8Kind( 0u ),
  m_ui8Category( 0u ),
  m_ui8Subcategory( 0u ),
  m_ui8Specific( 0u )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

JammingTechnique::JammingTechnique( KUINT8 KIND, KUINT8 CATEGORY,
                                    KUINT8 SUBCATEGORY, KUINT8 SPECIFIC ) :
  DataTypeBase(),
  m_ui8Kind( KIND ),
  m_ui8Category( CATEGORY ),
  m_ui8Subcategory( SUBCATEGORY ),
  m_ui8Specific( SPECIFIC )
{
}

//////////////////////////////////////////////////////////////////////////

JammingTechnique::~JammingTechnique()
{
}

//////////////////////////////////////////////////////////////////////////

void JammingTechnique::SetKind( KUINT8 KIND )
{
    m_ui8Kind = KIND;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 JammingTechnique::GetKind() const
{
    return m_ui8Kind;
}

//////////////////////////////////////////////////////////////////////////

void JammingTechnique::SetCategory( KUINT8 CATEGORY )
{
    m_ui8Category = CATEGORY;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 JammingTechnique::GetCategory() const
{
    return m_ui8Category;
}

//////////////////////////////////////////////////////////////////////////

void JammingTechnique::SetSubcategory( KUINT8 SUBCATEGORY )
{
    m_ui8Subcategory = SUBCATEGORY;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 JammingTechnique::GetSubcategory() const
{
    return m_ui8Subcategory;
}

//////////////////////////////////////////////////////////////////////////

void JammingTechnique::SetSpecific( KUINT8 SPECIFIC )
{
    m_ui8Specific = SPECIFIC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 JammingTechnique::GetSpecific() const
{
    return m_ui8Specific;
}

//////////////////////////////////////////////////////////////////////////

KString JammingTechnique::GetAsString() const
{
    KStringStream ss;

    ss << "Kind:        " << static_cast<KUINT16>(m_ui8Kind)        << endl
       << "Category:    " << static_cast<KUINT16>(m_ui8Category)    << endl
       << "Subcategory: " << static_cast<KUINT16>(m_ui8Subcategory) << endl
       << "Specific:    " << static_cast<KUINT16>(m_ui8Specific)    << endl;

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void JammingTechnique::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < JAMMING_TECHNIQUE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8Kind
           >> m_ui8Category
           >> m_ui8Subcategory
           >> m_ui8Specific;
}

//////////////////////////////////////////////////////////////////////////

KDataStream JammingTechnique::Encode() const
{
    KDataStream stream;

    JammingTechnique::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void JammingTechnique::Encode( KDataStream & stream ) const
{
    stream << m_ui8Kind
           << m_ui8Category
           << m_ui8Subcategory
           << m_ui8Specific;
}

//////////////////////////////////////////////////////////////////////////

KBOOL JammingTechnique::operator == ( const JammingTechnique & Value ) const
{
    if( m_ui8Kind           != Value.m_ui8Kind )            return false;
    if( m_ui8Category       != Value.m_ui8Category )        return false;
    if( m_ui8Subcategory    != Value.m_ui8Subcategory )     return false;
    if( m_ui8Specific       != Value.m_ui8Specific )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL JammingTechnique::operator != ( const JammingTechnique & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

#endif
