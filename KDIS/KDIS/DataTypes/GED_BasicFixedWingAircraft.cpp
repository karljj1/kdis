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

#include "./GED_BasicFixedWingAircraft.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_BasicFixedWingAircraft::GED_BasicFixedWingAircraft( void ) :
    m_i8HoriDevi( 0 ),
    m_i8VertDevi( 0 )
{
    for( KINT8 i = 0; i < 3; ++i )
    {
        m_i16Offsets[i] = 0;
        m_i8Ori[i] = 0;
    }
}

//////////////////////////////////////////////////////////////////////////

GED_BasicFixedWingAircraft::GED_BasicFixedWingAircraft( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_BasicFixedWingAircraft::GED_BasicFixedWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi, KINT8 Theta,
        KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation, KINT8 Speed ) :
    GED_GroundLogisticsVehicle( ID, XOffset, YOffset, ZOffset, EA, Psi, Theta, Phi, Speed ),
    m_ui8FuelStatus( FuelStatus ),
    m_i8HoriDevi( HorizontalDeviation ),
    m_i8VertDevi( VerticalDeviation )
{
}

//////////////////////////////////////////////////////////////////////////

GED_BasicFixedWingAircraft::~GED_BasicFixedWingAircraft( void )
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_BasicFixedWingAircraft::GetGroupedEntityCategory() const
{
    return BasicFixedWingAircraftGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_BasicFixedWingAircraft::GetLength() const
{
    return GED_BASIC_FIXED_WING_AIRCRAFT_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetFuelStatus( KUINT8 F )
{
    m_ui8FuelStatus = F;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_BasicFixedWingAircraft::GetFuelStatus() const
{
    return m_ui8FuelStatus;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetMovementDirection( KINT8 Horizontal, KINT8 Vertical )
{
    m_i8HoriDevi = Horizontal;
    m_i8VertDevi = Vertical;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetMovementDirectionHorizontal( KINT8 H )
{
    m_i8HoriDevi = H;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetMovementDirectionVertical( KINT8 V )
{
    m_i8VertDevi = V;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicFixedWingAircraft::GetMovementDirectionHorizontal() const
{
    return m_i8HoriDevi;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicFixedWingAircraft::GetMovementDirectionVertical() const
{
    return m_i8VertDevi;
}

//////////////////////////////////////////////////////////////////////////

KString GED_BasicFixedWingAircraft::GetAsString() const
{
    KStringStream ss;

    ss << "GED Basic Fixed Wing Aircraft\n"
       << "\tEntity ID:                  " << m_ui16EntityID  << "\n"
       << "\tLocation Offsets(x,y,z):    " << m_i16Offsets[0] << " " << m_i16Offsets[1] << " " << m_i16Offsets[2] << "\n"
       << IndentString( m_EA.GetAsString( EntityType( Platform, Air, 0, 0, 0, 0, 0 ) ), 1 )
       << "\tOrientation(Psi,Theta,Phi): " << ( KINT16 )m_i8Ori[0]    << " " << ( KINT16 )m_i8Ori[1] << " " << ( KINT16 )m_i8Ori[2] << "\n"
       << "\tFuel Status:                " << ( KUINT16 )m_ui8FuelStatus << "\n"
       << "\tHorizontal Deviation:       " << ( KINT16 )m_i8HoriDevi  << "\n"
       << "\tVertical Deviation:         " << ( KINT16 )m_i8VertDevi  << "\n"
       << "\tSpeed:                      " << ( KINT16 )m_i8Spd       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GED_BASIC_FIXED_WING_AIRCRAFT_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16EntityID
           >> m_i16Offsets[0]
           >> m_i16Offsets[1]
           >> m_i16Offsets[2]
           >> KDIS_STREAM m_EA
           >> m_i8Ori[0]
           >> m_i8Ori[1]
           >> m_i8Ori[2]
           >> m_ui8FuelStatus
           >> m_i8HoriDevi
           >> m_i8VertDevi
           >> m_i8Spd;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_BasicFixedWingAircraft::Encode() const
{
    KDataStream stream;

    GED_BasicFixedWingAircraft::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::Encode( KDataStream & stream ) const
{
    stream << m_ui16EntityID
           << m_i16Offsets[0]
           << m_i16Offsets[1]
           << m_i16Offsets[2]
           << KDIS_STREAM m_EA
           << m_i8Ori[0]
           << m_i8Ori[1]
           << m_i8Ori[2]
           << m_ui8FuelStatus
           << m_i8HoriDevi
           << m_i8VertDevi
           << m_i8Spd;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicFixedWingAircraft::operator == ( const GED_BasicFixedWingAircraft & Value ) const
{
    if( m_ui16EntityID      != Value.m_ui16EntityID )   return false;
    if( m_i16Offsets[0]     != Value.m_i16Offsets[0] )  return false;
    if( m_i16Offsets[1]     != Value.m_i16Offsets[1] )  return false;
    if( m_i16Offsets[2]     != Value.m_i16Offsets[2] )  return false;
    if( m_EA                != Value.m_EA )             return false;
    if( m_i8Ori[0]          != Value.m_i8Ori[0] )       return false;
    if( m_i8Ori[1]          != Value.m_i8Ori[1] )       return false;
    if( m_i8Ori[2]          != Value.m_i8Ori[2] )       return false;
    if( m_ui8FuelStatus     != Value.m_ui8FuelStatus )  return false;
    if( m_i8HoriDevi        != Value.m_i8HoriDevi )     return false;
    if( m_i8VertDevi        != Value.m_i8VertDevi )     return false;
    if( m_i8Spd             != Value.m_i8Spd )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicFixedWingAircraft::operator != ( const GED_BasicFixedWingAircraft & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
