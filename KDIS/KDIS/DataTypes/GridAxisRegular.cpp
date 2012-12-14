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

#include "./GridAxisRegular.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GridAxisRegular::GridAxisRegular( void ) :
    m_f64DomainInitialXi( 0 ),
    m_f64DomainFinalXi( 0 ),
    m_ui16DomainPointsXi( 0 ),
    m_ui8InterleafFactor( 0 ),
    m_ui8AxisType( 0 ),
    m_ui16NumPoints( 0 ),
    m_ui16InitialIndex( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GridAxisRegular::GridAxisRegular( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GridAxisRegular::GridAxisRegular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                                  KUINT8 AxisType, KDataStream & stream ) :
    m_f64DomainInitialXi( InitialXi ),
    m_f64DomainFinalXi( FinalXi ),
    m_ui16DomainPointsXi( PointsXi ),
    m_ui8InterleafFactor( InterleafFactor ),
    m_ui8AxisType( AxisType )
{
    // Decode the last 2 values.
    stream >> m_ui16NumPoints;
    stream >> m_ui16InitialIndex;
}

//////////////////////////////////////////////////////////////////////////

GridAxisRegular::GridAxisRegular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                                  KUINT8 AxisType, KUINT16 NumPoints, KUINT16 InitialIndexXi ) :
    m_f64DomainInitialXi( InitialXi ),
    m_f64DomainFinalXi( FinalXi ),
    m_ui16DomainPointsXi( PointsXi ),
    m_ui8InterleafFactor( InterleafFactor ),
    m_ui8AxisType( AxisType ),
    m_ui16NumPoints( NumPoints ),
    m_ui16InitialIndex( InitialIndexXi )
{
}

//////////////////////////////////////////////////////////////////////////

GridAxisRegular::~GridAxisRegular( void )
{
}

//////////////////////////////////////////////////////////////////////////

void GridAxisRegular::SetDomainInitialXi( KFLOAT64 Xi )
{
    m_f64DomainInitialXi = Xi;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 GridAxisRegular::GetDomainInitialXi() const
{
    return m_f64DomainInitialXi;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisRegular::SetDomainFinalXi( KFLOAT64 Xi )
{
    m_f64DomainFinalXi = Xi;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 GridAxisRegular::GetDomainFinalXi() const
{
    return m_f64DomainFinalXi;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisRegular::SetDomainPointsXi( KUINT16 Xi )
{
    m_ui16DomainPointsXi = Xi;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridAxisRegular::GetDomainPoints() const
{
    return m_ui16DomainPointsXi;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisRegular::SetInterleafFactor( KUINT8 IF )
{
    m_ui8InterleafFactor = IF;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GridAxisRegular::GetInterleafFactor() const
{
    return m_ui8InterleafFactor;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisRegular::SetAxisType( KUINT8 AT )
{
    m_ui8AxisType = AT;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GridAxisRegular::GetAxisType() const
{
    return m_ui8AxisType;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisRegular::SetNumberOfPointsOnXiAxis( KUINT16 NP )
{
    m_ui16NumPoints = NP;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridAxisRegular::GetNumberOfPointsOnXiAxis() const
{
    return m_ui16NumPoints;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisRegular::SetInitialIndexXi( KUINT16 I )
{
    m_ui16InitialIndex = I;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridAxisRegular::GetInitialIndexXi() const
{
    return m_ui16InitialIndex;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridAxisRegular::IsGridRegular() const
{
    return true;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridAxisRegular::GetLength()
{
    return GRID_AXIS_REGULAR;
}

//////////////////////////////////////////////////////////////////////////

KString GridAxisRegular::GetAsString() const
{
    KStringStream ss;

    ss << "Grid Axis Regular:"
       << "\n\tDomain Initial Xi:   " << m_f64DomainInitialXi
       << "\n\tDomain Final Xi:		" << m_f64DomainFinalXi
       << "\n\tDomain Points Xi:	" << m_ui16DomainPointsXi
       << "\n\tInterleaf Factor:	" << ( KUINT16 )m_ui8InterleafFactor
       << "\n\tAxis Type:			" << m_ui8AxisType
       << "\n\tNumber Of Points:	" << m_ui16NumPoints
       << "\n\tInitial Index:		" << m_ui16InitialIndex
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GridAxisRegular::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GRID_AXIS_REGULAR )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f64DomainInitialXi
           >> m_f64DomainFinalXi
           >> m_ui16DomainPointsXi
           >> m_ui8InterleafFactor
           >> m_ui8AxisType
           >> m_ui16NumPoints
           >> m_ui16InitialIndex;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GridAxisRegular::Encode() const
{
    KDataStream stream;

    GridAxisRegular::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GridAxisRegular::Encode( KDataStream & stream ) const
{
    stream << m_f64DomainInitialXi
           << m_f64DomainFinalXi
           << m_ui16DomainPointsXi
           << m_ui8InterleafFactor
           << m_ui8AxisType
           << m_ui16NumPoints
           << m_ui16InitialIndex;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridAxisRegular::operator == ( const GridAxisRegular & Value ) const
{
    if( m_f64DomainInitialXi != Value.m_f64DomainInitialXi ) return false;
    if( m_f64DomainFinalXi   != Value.m_f64DomainFinalXi )   return false;
    if( m_ui16DomainPointsXi != Value.m_ui16DomainPointsXi ) return false;
    if( m_ui8InterleafFactor != Value.m_ui8InterleafFactor ) return false;
    if( m_ui8AxisType        != Value.m_ui8AxisType )        return false;
    if( m_ui16NumPoints      != Value.m_ui16NumPoints )      return false;
    if( m_ui16InitialIndex   != Value.m_ui16InitialIndex )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridAxisRegular::operator != ( const GridAxisRegular & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

