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

#include "./GED_BasicRotorWingAircraft.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_BasicRotorWingAircraft::GED_BasicRotorWingAircraft( void ) :
    m_i8TrrtAz( 0 ),
    m_i8GnElv( 0 ),
    m_i8TrrtSlwRt( 0 ),
    m_i8GnElvRt( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GED_BasicRotorWingAircraft::GED_BasicRotorWingAircraft( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_BasicRotorWingAircraft::GED_BasicRotorWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi,
        KINT8 Theta, KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation,
        KINT8 Speed, KINT8 TurretAzimuth, KINT8 GunElevation, KINT8 TurretSlewRate, KINT8 GunElevationRate ) :
    GED_BasicFixedWingAircraft( ID, XOffset, YOffset, ZOffset, EA, Psi, Theta, Phi, FuelStatus, HorizontalDeviation, VerticalDeviation, Speed ),
    m_i8TrrtAz( TurretAzimuth ),
    m_i8GnElv( GunElevation ),
    m_i8TrrtSlwRt( TurretSlewRate ),
    m_i8GnElvRt( GunElevationRate )
{
}

//////////////////////////////////////////////////////////////////////////

GED_BasicRotorWingAircraft::~GED_BasicRotorWingAircraft( void )
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_BasicRotorWingAircraft::GetGroupedEntityCategory() const
{
    return BasicRotorWingAircraftGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_BasicRotorWingAircraft::GetLength() const
{
    return GED_BASIC_ROTOR_WING_AIRCRAFT_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::SetTurretAzimuth( KINT8 T )
{
    m_i8TrrtAz = T;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicRotorWingAircraft::GetTurretAzimuth() const
{
    return m_i8TrrtAz;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::SetGunElevation( KINT8 G )
{
    m_i8GnElv = G;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicRotorWingAircraft::GetGunElevation() const
{
    return m_i8GnElv;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::SetTurretSlewRate( KINT8 T )
{
    m_i8TrrtSlwRt = T;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicRotorWingAircraft::GetTurretSlewRate() const
{
    return m_i8TrrtSlwRt;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::SetGunElevationRate( KINT8 G )
{
    m_i8GnElvRt = G;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicRotorWingAircraft::GetGunElevationRate() const
{
    return m_i8GnElvRt;
}

//////////////////////////////////////////////////////////////////////////

KString GED_BasicRotorWingAircraft::GetAsString() const
{
    KStringStream ss;

    ss << "GED Basic Rotor Wing Aircraft\n"
       << "\tEntity ID:                  " << m_ui16EntityID  << "\n"
       << "\tLocation Offsets(x,y,z):    " << m_i16Offsets[0] << " " << m_i16Offsets[1] << " " << m_i16Offsets[2] << "\n"
       << IndentString( m_EA.GetAsString( EntityType( Platform, Air, 0, 0, 0, 0, 0 ) ), 1 )
       << "\tOrientation(Psi,Theta,Phi): " << ( KINT16 )m_i8Ori[0]    << " " << ( KINT16 )m_i8Ori[1] << " " << ( KINT16 )m_i8Ori[2] << "\n"
       << "\tFuel Status:                " << ( KUINT16 )m_ui8FuelStatus << "\n"
       << "\tHorizontal Deviation:       " << ( KINT16 )m_i8HoriDevi  << "\n"
       << "\tVertical Deviation:         " << ( KINT16 )m_i8VertDevi  << "\n"
       << "\tSpeed:                      " << ( KINT16 )m_i8Spd       << "\n"
       << "\tTurret Azimuth:             " << ( KINT16 )m_i8TrrtAz    << "\n"
       << "\tGun Elevation:              " << ( KINT16 )m_i8GnElv     << "\n"
       << "\tTurret Slew Rate:           " << ( KINT16 )m_i8TrrtSlwRt << "\n"
       << "\tGun Elevation Rate:         " << ( KINT16 )m_i8GnElvRt   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GED_BASIC_ROTOR_WING_AIRCRAFT_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    GED_BasicFixedWingAircraft::Decode( stream );

    stream >> m_i8TrrtAz
           >> m_i8GnElv
           >> m_i8TrrtSlwRt
           >> m_i8GnElvRt;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_BasicRotorWingAircraft::Encode() const
{
    KDataStream stream;

    GED_BasicRotorWingAircraft::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::Encode( KDataStream & stream ) const
{
    GED_BasicFixedWingAircraft::Encode( stream );

    stream << m_i8TrrtAz
           << m_i8GnElv
           << m_i8TrrtSlwRt
           << m_i8GnElvRt;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicRotorWingAircraft::operator == ( const GED_BasicRotorWingAircraft & Value ) const
{
    if( GED_BasicFixedWingAircraft::operator!=( Value ) )return false;
    if( m_i8TrrtAz    != Value.m_i8TrrtAz )    return false;
    if( m_i8GnElv     != Value.m_i8GnElv )     return false;
    if( m_i8TrrtSlwRt != Value.m_i8TrrtSlwRt ) return false;
    if( m_i8GnElvRt   != Value.m_i8GnElvRt )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicRotorWingAircraft::operator != ( const GED_BasicRotorWingAircraft & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
