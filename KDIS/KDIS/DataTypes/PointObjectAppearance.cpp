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

#include "./PointObjectAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

PointObjectAppearance::PointObjectAppearance( void )
{
    m_SpecificAppearanceUnion.m_ui32SpecificAppearance = 0;
}

//////////////////////////////////////////////////////////////////////////

PointObjectAppearance::PointObjectAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

PointObjectAppearance::~PointObjectAppearance( void )
{
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetBreach( Breach2bit B )
{
    m_SpecificAppearanceUnion.m_LogCribAbatisVehicleDefiladeInf.m_ui32Breach = B;
}

//////////////////////////////////////////////////////////////////////////

Breach2bit PointObjectAppearance::GetBreach() const
{
    return ( Breach2bit )m_SpecificAppearanceUnion.m_LogCribAbatisVehicleDefiladeInf.m_ui32Breach;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetOpacity( KUINT8 O ) throw( KException )
{
    if( O > 100 ) throw KException( __FUNCTION__, INVALID_DATA, "Acceptable values are 0-100." );

    m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Opacity = O;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetOpacity() const
{
    return m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Opacity;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetBurstSize( KUINT8 S )
{
    m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Size = S;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetBurstSize() const
{
    return m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Size;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetHeight( KUINT8 H )
{
    m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Height = H;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetHeight() const
{
    return m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Height;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetChemical( Chemical C )
{
    m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Chemical = C;
}

//////////////////////////////////////////////////////////////////////////

Chemical PointObjectAppearance::GetChemical() const
{
    return ( Chemical )m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Chemical;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetCraterSize( KUINT8 S )
{
    m_SpecificAppearanceUnion.m_Crater.m_ui32Size = S;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetCraterSize() const
{
    return m_SpecificAppearanceUnion.m_Crater.m_ui32Size;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetNumSegments( KUINT8 N )
{
    m_SpecificAppearanceUnion.m_RibbonBridge.m_ui32NumSeg = N;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetNumSegments() const
{
    return m_SpecificAppearanceUnion.m_RibbonBridge.m_ui32NumSeg;
}

//////////////////////////////////////////////////////////////////////////

KString PointObjectAppearance::GetAsString() const
{
    KStringStream ss;

    ss << ObjectAppearance::GetAsString()
       << "\tSpecific Appearance: " << m_SpecificAppearanceUnion.m_ui32SpecificAppearance << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < POINT_OBJECT_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_SpecificAppearanceUnion.m_ui32SpecificAppearance
           >> m_GeneralAppearanceUnion.m_ui16GeneralAppearance;
}

//////////////////////////////////////////////////////////////////////////

KDataStream PointObjectAppearance::Encode() const
{
    KDataStream stream;

    PointObjectAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::Encode( KDataStream & stream ) const
{
    // First add the specific bytes and then the general.
    stream << m_SpecificAppearanceUnion.m_ui32SpecificAppearance
           << m_GeneralAppearanceUnion.m_ui16GeneralAppearance;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointObjectAppearance::operator == ( const PointObjectAppearance & Value ) const
{
    if( ObjectAppearance::operator  != ( Value ) ) return false;
    if( m_SpecificAppearanceUnion.m_ui32SpecificAppearance != Value.m_SpecificAppearanceUnion.m_ui32SpecificAppearance ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointObjectAppearance::operator != ( const PointObjectAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
