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

#include "./GridDataType2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace std;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GridDataType2::GridDataType2( void ) :
    m_ui16NumValues( 0 ),
    m_ui16Padding( 0 )
{
    m_ui16DtRep = Type2;
}

//////////////////////////////////////////////////////////////////////////

GridDataType2::GridDataType2( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GridDataType2::GridDataType2( KUINT16 SampleType, KUINT16 DataRepresentation, KDataStream & stream )
{
    m_ui16SmpTyp = SampleType;
    m_ui16DtRep = DataRepresentation;

    stream >> m_ui16NumValues;

    KFLOAT32 tmp = 0;
    for( KUINT16 i = 0; i < m_ui16NumValues; ++i )
    {
        stream >> tmp;
        m_vf32Values.push_back( tmp );
    }

    stream >> m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

GridDataType2::GridDataType2( KUINT16 SampleType, const std::vector<KFLOAT32> & Values ) :
    m_ui16NumValues( Values.size() ),
    m_vf32Values( Values ),
    m_ui16Padding( 0 )
{
    m_ui16SmpTyp = SampleType;
    m_ui16DtRep = Type2;
}

//////////////////////////////////////////////////////////////////////////

GridDataType2::~GridDataType2( void )
{
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridDataType2::GetNumberOfValues() const
{
    return m_ui16NumValues;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridDataType2::GetSize() const
{
    return GRID_DATA_TYPE2_SIZE + ( m_ui16NumValues * 4 );
}

//////////////////////////////////////////////////////////////////////////

void GridDataType2:: AddValue( KFLOAT32 V )
{
    ++m_ui16NumValues;
    m_vf32Values.push_back( V );
}

//////////////////////////////////////////////////////////////////////////

void GridDataType2::SetValues( const std::vector<KFLOAT32> & V )
{
    m_vf32Values = V;
    m_ui16NumValues = m_vf32Values.size();
}

////////////////////////////////////////////////////////////////////////

const std::vector<KFLOAT32> & GridDataType2::GetValues() const
{
    return m_vf32Values;
}

//////////////////////////////////////////////////////////////////////////

void GridDataType2::ClearValues()
{
    m_vf32Values.clear();
    m_ui16NumValues = 0;
}

//////////////////////////////////////////////////////////////////////////

KString GridDataType2::GetAsString() const
{
    KStringStream ss;

    ss << GridData::GetAsString()
       << "GridDataType2:"
       << "\n\tNumber Of Values: " << m_ui16NumValues
       << "\n\tValues: ";

    vector<KFLOAT32>::const_iterator citr = m_vf32Values.begin();
    vector<KFLOAT32>::const_iterator citrEnd = m_vf32Values.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << " " << *citr;
    }
    ss << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GridDataType2::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GRID_DATA_TYPE2_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vf32Values.clear();

    GridData::Decode( stream );

    stream >> m_ui16NumValues;

    KFLOAT32 tmp = 0;
    for( KUINT16 i = 0; i < m_ui16NumValues; ++i )
    {
        stream >> tmp;
        m_vf32Values.push_back( tmp );
    }

    stream >> m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GridDataType2::Encode() const
{
    KDataStream stream;

    GridDataType2::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GridDataType2::Encode( KDataStream & stream ) const
{
    GridData::Encode( stream );

    stream << m_ui16NumValues;

    vector<KFLOAT32>::const_iterator citr = m_vf32Values.begin();
    vector<KFLOAT32>::const_iterator citrEnd = m_vf32Values.end();
    for( ; citr != citrEnd; ++citr )
    {
        stream << *citr;
    }

    stream << m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridDataType2::operator == ( const GridDataType2 & Value ) const
{
    if( GridData::operator != ( Value ) )           return false;
    if( m_ui16NumValues  != Value.m_ui16NumValues ) return false;
    if( m_vf32Values     != Value.m_vf32Values )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridDataType2::operator != ( const GridDataType2 & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

