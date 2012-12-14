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

#include "./GridAxisIrregular.h"

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

void GridAxisIrregular::calculatePadding()
{
    // Calculate padding needed to be on a 64 bit boundary.
    m_vui16Padding.clear();
    KUINT8 NumPadding = m_ui16NumPoints % 4;

    // Add the padding
    KUINT16 Padding = 0;
    for( KUINT8 i = 0; i < NumPadding; ++i )
    {
        m_vui16Padding.push_back( Padding );
    }
}

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GridAxisIrregular::GridAxisIrregular( void ) :
    m_f64CoordScaleXi( 0 ),
    m_f64CoordOffsetXi( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GridAxisIrregular::GridAxisIrregular( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GridAxisIrregular::GridAxisIrregular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                                      KUINT8 AxisType, KDataStream & stream ) :
    GridAxisRegular( InitialXi, FinalXi, PointsXi, InterleafFactor, AxisType, stream )
{
    stream >> m_f64CoordScaleXi
           >> m_f64CoordOffsetXi;

    KUINT16 ui16TmpVal = 0;
    for( KUINT16 i = 0; i < m_ui16NumPoints; ++i )
    {
        stream >> ui16TmpVal;
        m_vXiValues.push_back( ui16TmpVal );
    }

    // Calculate the padding that needs to be extracted. 64 bit boundary
    KUINT8 NumPadding = m_ui16NumPoints % 4;
    for( KUINT8 i = 0; i < NumPadding; ++i )
    {
        stream >> ui16TmpVal;
        m_vui16Padding.push_back( ui16TmpVal );
    }
}

//////////////////////////////////////////////////////////////////////////

GridAxisIrregular::GridAxisIrregular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                                      KUINT8 AxisType, KUINT16 InitialIndexXi, KFLOAT64 CoordinateScaleXi,
                                      KFLOAT64 CoordinateOffsetXi, const vector<KUINT16> & XiValues ) :
    GridAxisRegular( InitialXi, FinalXi, PointsXi, InterleafFactor, AxisType, XiValues.size(), InitialIndexXi ),
    m_f64CoordScaleXi( CoordinateScaleXi ),
    m_f64CoordOffsetXi( CoordinateOffsetXi ),
    m_vXiValues( XiValues )
{
    calculatePadding();
}

//////////////////////////////////////////////////////////////////////////

GridAxisIrregular::~GridAxisIrregular( void )
{
}

//////////////////////////////////////////////////////////////////////////

void GridAxisIrregular::SetCoordinateScaleXi( KFLOAT64 Xi )
{
    m_f64CoordScaleXi = Xi;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 GridAxisIrregular::GetCoordinateScaleXi() const
{
    return m_f64CoordScaleXi;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisIrregular::SetCoordinateOffsetXi( KFLOAT64 Xi )
{
    m_f64CoordOffsetXi = Xi;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 GridAxisIrregular::GetCoordinateOffsetXi() const
{
    return m_f64CoordOffsetXi;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisIrregular::AddXiValue( KUINT16 Xi )
{
    m_vXiValues.push_back( Xi );
    m_ui16NumPoints = m_vXiValues.size();
    calculatePadding();
}

//////////////////////////////////////////////////////////////////////////

void GridAxisIrregular::SetXiValues( const std::vector<KUINT16> & Xi )
{
    m_vXiValues = Xi;
    m_ui16NumPoints = m_vXiValues.size();
    calculatePadding();
}

//////////////////////////////////////////////////////////////////////////

const std::vector<KUINT16> & GridAxisIrregular::GetXiValues() const
{
    return m_vXiValues;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisIrregular::ClearXiValues()
{
    m_vXiValues.clear();
    m_ui16NumPoints = 0;
    calculatePadding();
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridAxisIrregular::IsGridRegular() const
{
    return false;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridAxisIrregular::GetLength()
{
    KUINT16 ui16Length = GRID_AXIS_IRREGULAR;
    ui16Length += m_vXiValues.size() * 2;
    ui16Length += m_vui16Padding.size() * 2;
    return ui16Length;
}

//////////////////////////////////////////////////////////////////////////

KString GridAxisIrregular::GetAsString() const
{
    KStringStream ss;

    ss << "Grid Axis Irregular:"
       << "\n\tDomain Initial Xi:    " << m_f64DomainInitialXi
       << "\n\tDomain Final Xi:		 " << m_f64DomainFinalXi
       << "\n\tDomain Points Xi:	 " << m_ui16DomainPointsXi
       << "\n\tInterleaf Factor:	 " << m_ui8InterleafFactor
       << "\n\tAxis Type:			 " << ( KUINT16 )m_ui8AxisType
       << "\n\tNumber Of Points:	 " << m_ui16NumPoints
       << "\n\tInitial Index:		 " << m_ui16InitialIndex
       << "\n\tCoordinate Scale Xi:  " << m_f64CoordScaleXi
       << "\n\tCoordinate Offset Xi: " << m_f64CoordOffsetXi
       << "\n\tXi Values:";

    vector<KUINT16>::const_iterator citr = m_vXiValues.begin();
    vector<KUINT16>::const_iterator citrEnd = m_vXiValues.end();

    for( ; citr != citrEnd; ++citr )
    {
        ss << "\n\t" << *citr;
    }

    ss << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GridAxisIrregular::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GRID_AXIS_IRREGULAR )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vXiValues.clear();
    m_vui16Padding.clear();

    GridAxisRegular::Decode( stream );

    stream >> m_f64CoordScaleXi
           >> m_f64CoordOffsetXi;

    KUINT16 ui16TmpVal = 0;
    for( KUINT16 i = 0; i < m_ui16NumPoints; ++i )
    {
        stream >> ui16TmpVal;
        m_vXiValues.push_back( ui16TmpVal );
    }

    // Calculate the padding that needs to be extracted. 64 bit boundary
    KUINT8 NumPadding = m_ui16NumPoints % 4;
    for( KUINT8 i = 0; i < NumPadding; ++i )
    {
        stream >> ui16TmpVal;
        m_vui16Padding.push_back( ui16TmpVal );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream GridAxisIrregular::Encode() const
{
    KDataStream stream;

    GridAxisIrregular::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisIrregular::Encode( KDataStream & stream ) const
{
    GridAxisRegular::Encode( stream );

    stream << m_f64CoordScaleXi
           << m_f64CoordOffsetXi;

    vector<KUINT16>::const_iterator citr = m_vXiValues.begin();
    vector<KUINT16>::const_iterator citrEnd = m_vXiValues.end();

    for( ; citr != citrEnd; ++citr )
    {
        stream << *citr;
    }

    // Padding
    citr = m_vui16Padding.begin();
    citrEnd = m_vui16Padding.end();

    for( ; citr != citrEnd; ++citr )
    {
        stream << *citr;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridAxisIrregular::operator == ( const GridAxisIrregular & Value ) const
{
    if( GridAxisRegular::operator != ( Value ) )          return false;
    if( m_f64CoordScaleXi   != Value.m_f64CoordScaleXi )  return false;
    if( m_f64CoordOffsetXi  != Value.m_f64CoordOffsetXi ) return false;
    if( m_vXiValues         != Value.m_vXiValues )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridAxisIrregular::operator != ( const GridAxisIrregular & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

