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

#include "./LinearObjectAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance::LinearObjectAppearance( void )
{
    m_SpecificAppearanceUnion.m_ui32SpecificAppearance = 0;
}

//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance::LinearObjectAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance::~LinearObjectAppearance( void )
{
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreach( Breach2bit B )
{
    m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32Breach = B;
}

//////////////////////////////////////////////////////////////////////////

Breach2bit LinearObjectAppearance::GetBreach() const
{
    return ( Breach2bit )m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32Breach;
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreachLength( KUINT8 L )
{
    m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLength = L;
}

////////////////////////////////////////////////////////////////////////////

KUINT8 LinearObjectAppearance::GetBreachLength() const
{
    return m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLength;
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreachLocation( const bitset<8> & L )
{
    KUINT32 i = L.to_ulong();
    m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLength = ( KUINT8 )i;
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreachLocation( KUINT8 L )
{
    m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLoc = L;
}

////////////////////////////////////////////////////////////////////////////

KUINT8 LinearObjectAppearance::GetBreachLocation() const
{
    return m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLoc;
}

////////////////////////////////////////////////////////////////////////////

bitset<8> LinearObjectAppearance::GetBreachLocationAsBitset()
{
    return bitset<8>( ( KINT32 )m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLoc ); // We need to cast to a signed int, this is a visual studio 2010 fix
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetOpacity( KUINT8 O ) throw( KException )
{
    if( O > 100 ) throw KException( __FUNCTION__, INVALID_DATA, "Acceptable values are 0-100." );

    m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Opacity = O;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LinearObjectAppearance::GetOpacity() const
{
    return m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Opacity;
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetAttached( KBOOL A )
{
    m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Attached = A;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearObjectAppearance::IsAttached() const
{
    return ( KBOOL )m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Attached;
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetChemical( Chemical C )
{
    m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Chemical = C;
}

//////////////////////////////////////////////////////////////////////////

Chemical LinearObjectAppearance::GetChemical() const
{
    return ( Chemical )m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Chemical;
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetVisibleSide( VisibleSide V )
{
    m_SpecificAppearanceUnion.m_MinefieldLaneMarker.m_ui32VisibleSide = V;
}

//////////////////////////////////////////////////////////////////////////

VisibleSide LinearObjectAppearance::GetVisibleSide() const
{
    return  ( VisibleSide )m_SpecificAppearanceUnion.m_MinefieldLaneMarker.m_ui32VisibleSide;
}

//////////////////////////////////////////////////////////////////////////

KString LinearObjectAppearance::GetAsString() const
{
    KStringStream ss;

    ss << ObjectAppearance::GetAsString()
       << "\tSpecific Appearance: " << m_SpecificAppearanceUnion.m_ui32SpecificAppearance << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LINEAR_OBJECT_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    // Note: The order of the bytes is switched in the linear appearance to fix an alignment issue in the 1998 standard.
    stream >> m_GeneralAppearanceUnion.m_ui16GeneralAppearance
           >> m_SpecificAppearanceUnion.m_ui32SpecificAppearance;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LinearObjectAppearance::Encode() const
{
    KDataStream stream;

    LinearObjectAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::Encode( KDataStream & stream ) const
{
    // First add the specific bytes and then the general.
    stream << m_GeneralAppearanceUnion.m_ui16GeneralAppearance
           << m_SpecificAppearanceUnion.m_ui32SpecificAppearance;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearObjectAppearance::operator == ( const LinearObjectAppearance & Value ) const
{
    if( ObjectAppearance::operator  != ( Value ) ) return false;
    if( m_SpecificAppearanceUnion.m_ui32SpecificAppearance != Value.m_SpecificAppearanceUnion.m_ui32SpecificAppearance ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearObjectAppearance::operator != ( const LinearObjectAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
