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

#include "./GridDataType1.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace std;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GridDataType1::GridDataType1() :
    m_f32FieldScale( 0 ),
    m_f32FieldOffset( 0 ),
    m_ui16NumValues( 0 ),
    m_ui16Padding( 0 )
{
    m_ui16DtRep = Type1;
}

//////////////////////////////////////////////////////////////////////////

GridDataType1::GridDataType1( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GridDataType1::GridDataType1( KUINT16 SampleType, KUINT16 DataRepresentation, KDataStream & stream )
{
    m_ui16SmpTyp = SampleType;
    m_ui16DtRep = DataRepresentation;
    stream >> m_f32FieldScale
           >> m_f32FieldOffset
           >> m_ui16NumValues;

    KUINT16 tmp = 0;
    for( KUINT16 i = 0; i < m_ui16NumValues; ++i )
    {
        stream >> tmp;
        m_vui16Values.push_back( tmp );
    }

    // Do we need to extract any padding?
    if( m_ui16NumValues % 2 == 1 )
    {
        stream >> m_ui16Padding;
    }
}

//////////////////////////////////////////////////////////////////////////

GridDataType1::GridDataType1( KUINT16 SampleType, KFLOAT32 FieldScale, KFLOAT32 FieldOffset,
                              const std::vector<KUINT16> & Values ) :
    m_f32FieldScale( FieldScale ),
    m_f32FieldOffset( FieldOffset ),
    m_ui16NumValues( Values.size() ),
    m_vui16Values( Values ),
    m_ui16Padding( 0 )
{
    m_ui16SmpTyp = SampleType;
    m_ui16DtRep = Type1;
}

//////////////////////////////////////////////////////////////////////////

GridDataType1::~GridDataType1()
{
}

//////////////////////////////////////////////////////////////////////////

void GridDataType1::SetFieldScale( KFLOAT32 FS )
{
    m_f32FieldScale = FS;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 GridDataType1::GetFieldScale() const
{
    return m_f32FieldScale;
}

//////////////////////////////////////////////////////////////////////////

void GridDataType1::SetFieldOffset( KFLOAT32 FO )
{
    m_f32FieldOffset = FO;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 GridDataType1::GetFieldOffset() const
{
    return m_f32FieldOffset;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridDataType1::GetNumberOfValues() const
{
    return m_ui16NumValues;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridDataType1::GetSize() const
{
    if( m_ui16NumValues % 2 == 1 )
    {
        // Padding is included.
        return ( m_ui16NumValues * 2 ) + GRID_DATA_TYPE1_SIZE;
    }

    return ( m_ui16NumValues * 2 ) + GRID_DATA_TYPE1_SIZE - 2; // No padding. GRID_DATA_TYPE1_SIZE has padding included in its size so we need to remove it.
}

//////////////////////////////////////////////////////////////////////////

void GridDataType1:: AddValue( KUINT16 V )
{
    ++m_ui16NumValues;
    m_vui16Values.push_back( V );
}

//////////////////////////////////////////////////////////////////////////

void GridDataType1::SetValues( const std::vector<KUINT16> & V )
{
    m_vui16Values = V;
    m_ui16NumValues = m_vui16Values.size();
}

//////////////////////////////////////////////////////////////////////////

const std::vector<KUINT16> & GridDataType1::GetValues() const
{
    return m_vui16Values;
}

//////////////////////////////////////////////////////////////////////////

void GridDataType1::ClearValues()
{
    m_vui16Values.clear();
    m_ui16NumValues = 0;
}

//////////////////////////////////////////////////////////////////////////

KString GridDataType1::GetAsString() const
{
    KStringStream ss;

    ss << GridData::GetAsString()
       << "GridDataType1:"
       << "\n\tField Scale:      " << m_f32FieldScale
       << "\n\tField Offset:     " << m_f32FieldOffset
       << "\n\tNumber Of Values: " << m_ui16NumValues
       << "\n\tValues: ";

    vector<KUINT16>::const_iterator citr = m_vui16Values.begin();
    vector<KUINT16>::const_iterator citrEnd = m_vui16Values.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << " " << *citr;
    }
    ss << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GridDataType1::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GRID_DATA_TYPE1_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vui16Values.clear();

    GridData::Decode( stream );

    stream >> m_f32FieldScale
           >> m_f32FieldOffset
           >> m_ui16NumValues;

    KUINT16 tmp = 0;
    for( KUINT16 i = 0; i < m_ui16NumValues; ++i )
    {
        stream >> tmp;
        m_vui16Values.push_back( tmp );
    }

    // Do we need to extract any padding?
    if( m_ui16NumValues % 2 == 1 )
    {
        stream >> m_ui16Padding;
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream GridDataType1::Encode() const
{
    KDataStream stream;

    GridDataType1::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GridDataType1::Encode( KDataStream & stream ) const
{
    GridData::Encode( stream );

    stream << m_f32FieldScale
           << m_f32FieldOffset
           << m_ui16NumValues;

    vector<KUINT16>::const_iterator citr = m_vui16Values.begin();
    vector<KUINT16>::const_iterator citrEnd = m_vui16Values.end();
    for( ; citr != citrEnd; ++citr )
    {
        stream << *citr;
    }

    // Should we add some padding onto the end? We need to have a 32 bit alignment.
    if( m_ui16NumValues % 2 == 1 )
    {
        stream << m_ui16Padding;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridDataType1::operator == ( const GridDataType1 & Value ) const
{
    if( GridData::operator != ( Value ) )            return false;
    if( m_f32FieldScale  != Value.m_f32FieldScale )  return false;
    if( m_f32FieldOffset != Value.m_f32FieldOffset ) return false;
    if( m_ui16NumValues  != Value.m_ui16NumValues )  return false;
    if( m_vui16Values    != Value.m_vui16Values )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridDataType1::operator != ( const GridDataType1 & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

