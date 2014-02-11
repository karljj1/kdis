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

#include "./GridDataType0.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace std;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GridDataType0::GridDataType0() :
    m_ui16NumBytes( 0 ),
    m_ui8Padding( 0 )
{
    m_ui16DtRep = Type0;
}

//////////////////////////////////////////////////////////////////////////

GridDataType0::GridDataType0( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GridDataType0::GridDataType0( KUINT16 SampleType, KUINT16 DataRepresentation, KDataStream & stream )
{
    m_ui16SmpTyp = SampleType;
    m_ui16DtRep = DataRepresentation;

    stream >> m_ui16NumBytes;

    KUINT8 tmp = 0;
    for( KUINT16 i = 0; i < m_ui16NumBytes; ++i )
    {
        stream >> tmp;
        m_vui8DataVals.push_back( tmp );
    }

    // Do we need to extract any padding?
    if( m_ui16NumBytes % 2 == 1 )
    {
        stream >> m_ui8Padding;
    }
}

//////////////////////////////////////////////////////////////////////////

GridDataType0::GridDataType0( KUINT16 SampleType, KUINT8 * Data, KUINT16 NumBytes ) :
    m_ui16NumBytes( NumBytes ),
    m_ui8Padding( 0 )
{
    m_ui16SmpTyp = SampleType;
    m_ui16DtRep = Type0;

    for( KUINT16 i = 0; i < m_ui16NumBytes; ++i )
    {
        m_vui8DataVals.push_back( Data[i] );
    }
}

//////////////////////////////////////////////////////////////////////////

GridDataType0::~GridDataType0()
{
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridDataType0::GetNumberOfBytes() const
{
    return m_ui16NumBytes;
}

//////////////////////////////////////////////////////////////////////////

void GridDataType0::AddDataValue( KUINT8 D )
{
    ++m_ui16NumBytes;
    m_vui8DataVals.push_back( D );
}

//////////////////////////////////////////////////////////////////////////

void GridDataType0::SetDataValues( KUINT8 * Data, KUINT16 NumBytes )
{
    m_vui8DataVals.clear();
    m_ui16NumBytes = NumBytes;
    for( KUINT16 i = 0; i < m_ui16NumBytes; ++i )
    {
        m_vui8DataVals.push_back( Data[i] );
    }
}

//////////////////////////////////////////////////////////////////////////

void GridDataType0::SetDataValues( const std::vector<KUINT8> & DV )
{
    m_vui8DataVals = DV;
    m_ui16NumBytes = m_vui8DataVals.size();
}

//////////////////////////////////////////////////////////////////////////

const std::vector<KUINT8> & GridDataType0::GetDataValues() const
{
    return m_vui8DataVals;
}

//////////////////////////////////////////////////////////////////////////

void GridDataType0::ClearValues()
{
    m_vui8DataVals.clear();
    m_ui16NumBytes = 0;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridDataType0::GetSize() const
{
    if( m_ui16NumBytes % 2 == 1 )
    {
        // Padding is included.
        return m_ui16NumBytes + GRID_DATA_TYPE0_SIZE;
    }

    return m_ui16NumBytes + GRID_DATA_TYPE0_SIZE - 1; // No padding. GRID_DATA_TYPE0_SIZE has padding included in its size so we need to remove it.
}

//////////////////////////////////////////////////////////////////////////

KString GridDataType0::GetAsString() const
{
    KStringStream ss;

    ss << GridData::GetAsString()
       << "GridDataType0:"
       << "\n\tNumber Of Bytes: " << m_ui16NumBytes
       << "\n\tData: ";

    vector<KUINT8>::const_iterator citr = m_vui8DataVals.begin();
    vector<KUINT8>::const_iterator citrEnd = m_vui8DataVals.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << " " << ( KUINT16 )*citr;
    }
    ss << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GridDataType0::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GRID_DATA_TYPE0_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vui8DataVals.clear();

    GridData::Decode( stream );

    stream >> m_ui16NumBytes;

    KUINT8 tmp = 0;
    for( KUINT16 i = 0; i < m_ui16NumBytes; ++i )
    {
        stream >> tmp;
        m_vui8DataVals.push_back( tmp );
    }

    // Do we need to extract any padding?
    if( m_ui16NumBytes % 2 == 1 )
    {
        stream >> m_ui8Padding;
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream GridDataType0::Encode() const
{
    KDataStream stream;

    GridDataType0::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GridDataType0::Encode( KDataStream & stream ) const
{
    GridData::Encode( stream );

    stream << m_ui16NumBytes;

    vector<KUINT8>::const_iterator citr = m_vui8DataVals.begin();
    vector<KUINT8>::const_iterator citrEnd = m_vui8DataVals.end();
    for( ; citr != citrEnd; ++citr )
    {
        stream << *citr;
    }

    // Should we add some padding onto the end? We need to have a 16 bit alignment.
    if( m_ui16NumBytes % 2 == 1 )
    {
        stream << m_ui8Padding;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridDataType0::operator == ( const GridDataType0 & Value ) const
{
    if( GridData::operator != ( Value ) )         return false;
    if( m_ui16NumBytes != Value.m_ui16NumBytes )  return false;
    if( m_vui8DataVals  != Value.m_vui8DataVals ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridDataType0::operator != ( const GridDataType0 & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

