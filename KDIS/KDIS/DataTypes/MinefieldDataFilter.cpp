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

#include "./MinefieldDataFilter.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

MinefieldDataFilter::MinefieldDataFilter( void )
{
    m_FilterUnion.m_ui32Filter = 0;
}

//////////////////////////////////////////////////////////////////////////

MinefieldDataFilter::MinefieldDataFilter( KBOOL GroundBurialDepthOffset, KBOOL WaterBurialDepthOffset, KBOOL SnowBurialDepthOffset,
        KBOOL MineOrientation, KBOOL ThermalContrast, KBOOL Reflectance, KBOOL MineEmplacementAge,
        KBOOL TripDetonationWire, KBOOL Fusing, KBOOL ScalarDetectionCoefficient, KBOOL PaintScheme )
{
    m_FilterUnion.m_ui32GroundOffset = GroundBurialDepthOffset;
    m_FilterUnion.m_ui32WaterOffset  = WaterBurialDepthOffset;
    m_FilterUnion.m_ui32SnowOffset   = SnowBurialDepthOffset;
    m_FilterUnion.m_ui32MineOri      = MineOrientation;
    m_FilterUnion.m_ui32ThermalCon   = ThermalContrast;
    m_FilterUnion.m_ui32Reflectance  = Reflectance;
    m_FilterUnion.m_ui32MineEmpAge   = MineEmplacementAge;
    m_FilterUnion.m_ui32TripDetWire  = TripDetonationWire;
    m_FilterUnion.m_ui32Fusing       = Fusing;
    m_FilterUnion.m_ui32ScalarDet    = ScalarDetectionCoefficient;
    m_FilterUnion.m_ui32PaintScm     = PaintScheme;
    m_FilterUnion.m_ui32Padding      = 0;
}

//////////////////////////////////////////////////////////////////////////

MinefieldDataFilter::MinefieldDataFilter( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

MinefieldDataFilter::~MinefieldDataFilter( void )
{
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetGroundBurialDepthOffset( KBOOL B )
{
    m_FilterUnion.m_ui32GroundOffset = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsGroundBurialDepthOffset() const
{
    return m_FilterUnion.m_ui32GroundOffset;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetWaterBurialDepthOffset( KBOOL B )
{
    m_FilterUnion.m_ui32WaterOffset = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsWaterBurialDepthOffset() const
{
    return m_FilterUnion.m_ui32WaterOffset;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetSnowBurialDepthOffset( KBOOL B )
{
    m_FilterUnion.m_ui32SnowOffset = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsSnowBurialDepthOffset() const
{
    return m_FilterUnion.m_ui32SnowOffset;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetMineOrientation( KBOOL B )
{
    m_FilterUnion.m_ui32MineOri = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsMineOrientation() const
{
    return m_FilterUnion.m_ui32MineOri;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetThermalContrast( KBOOL B )
{
    m_FilterUnion.m_ui32ThermalCon = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsThermalContrast() const
{
    return m_FilterUnion.m_ui32ThermalCon;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetReflectance( KBOOL B )
{
    m_FilterUnion.m_ui32Reflectance = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsReflectance() const
{
    return m_FilterUnion.m_ui32Reflectance;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetMineEmplacementAge( KBOOL B )
{
    m_FilterUnion.m_ui32MineEmpAge = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsMineEmplacementAge() const
{
    return m_FilterUnion.m_ui32MineEmpAge;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetTripDetonationWire( KBOOL B )
{
    m_FilterUnion.m_ui32TripDetWire = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsTripDetonationWire() const
{
    return m_FilterUnion.m_ui32TripDetWire;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetFusing( KBOOL B )
{
    m_FilterUnion.m_ui32Fusing = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsFusing() const
{
    return m_FilterUnion.m_ui32Fusing;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetScalarDetectionCoefficient( KBOOL B )
{
    m_FilterUnion.m_ui32ScalarDet = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsScalarDetectionCoefficient() const
{
    return m_FilterUnion.m_ui32ScalarDet;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::SetPaintScheme( KBOOL B )
{
    m_FilterUnion.m_ui32PaintScm = B;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::IsPaintScheme() const
{
    return m_FilterUnion.m_ui32PaintScm;
}

//////////////////////////////////////////////////////////////////////////

KString MinefieldDataFilter::GetAsString() const
{
    KStringStream ss;

    ss << "Minefield Data Filter:"
       << "\n\tGround Offset: "                 << m_FilterUnion.m_ui32GroundOffset
       << "\n\tWater Offset: "                  << m_FilterUnion.m_ui32WaterOffset
       << "\n\tSnow Offset: "                   << m_FilterUnion.m_ui32SnowOffset
       << "\n\tMine Orientation: "              << m_FilterUnion.m_ui32MineOri
       << "\n\tThermal Contrast: "              << m_FilterUnion.m_ui32ThermalCon
       << "\n\tReflectance: "                   << m_FilterUnion.m_ui32Reflectance
       << "\n\tMine Emplacement Age: "          << m_FilterUnion.m_ui32MineEmpAge
       << "\n\tTrip / Detonation Wire: "        << m_FilterUnion.m_ui32TripDetWire
       << "\n\tFusing: "                        << m_FilterUnion.m_ui32Fusing
       << "\n\tScalar Detection Coefficient: "  << m_FilterUnion.m_ui32ScalarDet
       << "\n\tPaint Scheme: "                  << m_FilterUnion.m_ui32PaintScm
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MINEFIELD_DATA_FILTER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_FilterUnion.m_ui32Filter;
}

//////////////////////////////////////////////////////////////////////////

KDataStream MinefieldDataFilter::Encode() const
{
    KDataStream stream;

    MinefieldDataFilter::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldDataFilter::Encode( KDataStream & stream ) const
{
    stream << m_FilterUnion.m_ui32Filter;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::operator == ( const MinefieldDataFilter & Value ) const
{
    if( m_FilterUnion.m_ui32Filter != Value.m_FilterUnion.m_ui32Filter )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldDataFilter::operator != ( const MinefieldDataFilter & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
