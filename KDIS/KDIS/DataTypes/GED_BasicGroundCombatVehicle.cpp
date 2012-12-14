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

#include "./GED_BasicGroundCombatVehicle.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_BasicGroundCombatVehicle::GED_BasicGroundCombatVehicle( void ) :
    m_ui16EntityID( 0 ),
    m_i8Spd( 0 ),
    m_i8TrrtAz( 0 ),
    m_i8GnElv( 0 ),
    m_i8TrrtSlwRt( 0 ),
    m_i8GnElvRt( 0 )
{
    for( KINT8 i = 0; i < 3; ++i )
    {
        m_i16Offsets[i] = 0;
        m_i8Ori[i] = 0;
    }
}

//////////////////////////////////////////////////////////////////////////

GED_BasicGroundCombatVehicle::GED_BasicGroundCombatVehicle( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_BasicGroundCombatVehicle::GED_BasicGroundCombatVehicle( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA,
        KINT8 Psi, KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 TurretAzimuth, KINT8 GunElevation,
        KINT8 TurretSlewRate, KINT8 GunElevationRate ) :
    m_ui16EntityID( ID ),
    m_EA( EA ),
    m_i8Spd( Speed ),
    m_i8TrrtAz( TurretAzimuth ),
    m_i8GnElv( GunElevation ),
    m_i8TrrtSlwRt( TurretSlewRate ),
    m_i8GnElvRt( GunElevationRate )
{
    m_i16Offsets[0] = XOffset;
    m_i16Offsets[1] = YOffset;
    m_i16Offsets[2] = ZOffset;
    m_i8Ori[0] = Psi;
    m_i8Ori[1] = Theta;
    m_i8Ori[2] = Phi;
}

//////////////////////////////////////////////////////////////////////////

GED_BasicGroundCombatVehicle::~GED_BasicGroundCombatVehicle( void )
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_BasicGroundCombatVehicle::GetGroupedEntityCategory() const
{
    return BasicGroundCombatVehicleGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_BasicGroundCombatVehicle::GetLength() const
{
    return GED_BASIC_GROUND_COMBAT_VEHICLE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityID( KUINT16 ID )
{
    m_ui16EntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GED_BasicGroundCombatVehicle::GetEntityID() const
{
    return m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityLocation( KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset )
{
    m_i16Offsets[0] = XOffset;
    m_i16Offsets[1] = YOffset;
    m_i16Offsets[2] = ZOffset;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityLocation( KINT16 Offsets[3] )
{
    for( KUINT8 i = 0; i < 3; ++i )
    {
        m_i16Offsets[i] = Offsets[i];
    }
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityLocationXOffset( KINT16 X )
{
    m_i16Offsets[0] = X;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityLocationYOffset( KINT16 Y )
{
    m_i16Offsets[1] = Y;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityLocationZOffset( KINT16 Z )
{
    m_i16Offsets[2] = Z;
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicGroundCombatVehicle::GetEntityLocationXOffset() const
{
    return m_i16Offsets[0];
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicGroundCombatVehicle::GetEntityLocationYOffset() const
{
    return m_i16Offsets[1];
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicGroundCombatVehicle::GetEntityLocationZOffset() const
{
    return m_i16Offsets[2];
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityAppearance( const EntityAppearance & EA )
{
    m_EA = EA;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & GED_BasicGroundCombatVehicle::GetEntityAppearance() const
{
    return m_EA;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & GED_BasicGroundCombatVehicle::GetEntityAppearance()
{
    return m_EA;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityOrientation( KINT8 Psi, KINT8 Theta, KINT8 Phi )
{
    m_i8Ori[0] = Psi;
    m_i8Ori[1] = Theta;
    m_i8Ori[2] = Phi;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityOrientation( KINT8 Ori[3] )
{
    for( KINT8 i = 0; i < 3; ++i )
    {
        m_i8Ori[i] = Ori[i];
    }
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityOrientationPsi( KINT8 P )
{
    m_i8Ori[0] = P;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityOrientationTheta( KINT8 T )
{
    m_i8Ori[1] = T;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetEntityOrientationPhi( KINT8 P )
{
    m_i8Ori[2] = P;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatVehicle::GetEntityOrientationPsi() const
{
    return m_i8Ori[0];
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatVehicle::GetEntityOrientationTheta() const
{
    return m_i8Ori[1];
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatVehicle::GetEntityOrientationPhi() const
{
    return m_i8Ori[2];
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetSpeed( KINT8 S )
{
    m_i8Spd = S;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatVehicle::GetSpeed() const
{
    return m_i8Spd;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetTurretAzimuth( KINT8 T )
{
    m_i8TrrtAz = T;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatVehicle::GetTurretAzimuth() const
{
    return m_i8TrrtAz;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetGunElevation( KINT8 G )
{
    m_i8GnElv = G;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatVehicle::GetGunElevation() const
{
    return m_i8GnElv;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetTurretSlewRate( KINT8 T )
{
    m_i8TrrtSlwRt = T;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatVehicle::GetTurretSlewRate() const
{
    return m_i8TrrtSlwRt;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::SetGunElevationRate( KINT8 G )
{
    m_i8GnElvRt = G;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatVehicle::GetGunElevationRate() const
{
    return m_i8GnElvRt;
}

//////////////////////////////////////////////////////////////////////////

KString GED_BasicGroundCombatVehicle::GetAsString() const
{
    KStringStream ss;

    ss << "GED Basic Ground Combat Vehicle\n"
       << "\tEntity ID:                  " << m_ui16EntityID  << "\n"
       << "\tLocation Offsets(x,y,z):    " << m_i16Offsets[0] << " " << m_i16Offsets[1] << " " << m_i16Offsets[2] << "\n"
       << IndentString( m_EA.GetAsString( EntityType( Platform, Land, 0, 0, 0, 0, 0 ) ), 1 )
       << "\tOrientation(Psi,Theta,Phi): " << ( KINT16 )m_i8Ori[0]    << " " << ( KINT16 )m_i8Ori[1] << " " << ( KINT16 )m_i8Ori[2] << "\n"
       << "\tSpeed:                      " << ( KINT16 )m_i8Spd       << "m/s\n"
       << "\tTurret Azimuth:             " << ( KINT16 )m_i8TrrtAz    << "\n"
       << "\tGun Elevation:              " << ( KINT16 )m_i8GnElv     << "\n"
       << "\tTurret Slew Rate:           " << ( KINT16 )m_i8TrrtSlwRt << "\n"
       << "\tGun Elevation Rate:         " << ( KINT16 )m_i8GnElvRt   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GED_BASIC_GROUND_COMBAT_VEHICLE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16EntityID
           >> m_i16Offsets[0]
           >> m_i16Offsets[1]
           >> m_i16Offsets[2]
           >> KDIS_STREAM m_EA
           >> m_i8Ori[0]
           >> m_i8Ori[1]
           >> m_i8Ori[2]
           >> m_i8Spd
           >> m_i8TrrtAz
           >> m_i8GnElv
           >> m_i8TrrtSlwRt
           >> m_i8GnElvRt;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_BasicGroundCombatVehicle::Encode() const
{
    KDataStream stream;

    GED_BasicGroundCombatVehicle::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatVehicle::Encode( KDataStream & stream ) const
{
    stream << m_ui16EntityID
           << m_i16Offsets[0]
           << m_i16Offsets[1]
           << m_i16Offsets[2]
           << KDIS_STREAM m_EA
           << m_i8Ori[0]
           << m_i8Ori[1]
           << m_i8Ori[2]
           << m_i8Spd
           << m_i8TrrtAz
           << m_i8GnElv
           << m_i8TrrtSlwRt
           << m_i8GnElvRt;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicGroundCombatVehicle::operator == ( const GED_BasicGroundCombatVehicle & Value ) const
{
    if( m_ui16EntityID      != Value.m_ui16EntityID )   return false;
    if( m_i16Offsets[0]     != Value.m_i16Offsets[0] )  return false;
    if( m_i16Offsets[1]     != Value.m_i16Offsets[1] )  return false;
    if( m_i16Offsets[2]     != Value.m_i16Offsets[2] )  return false;
    if( m_EA                != Value.m_EA )             return false;
    if( m_i8Ori[0]          != Value.m_i8Ori[0] )       return false;
    if( m_i8Ori[1]          != Value.m_i8Ori[1] )       return false;
    if( m_i8Ori[2]          != Value.m_i8Ori[2] )       return false;
    if( m_i8Spd             != Value.m_i8Spd )          return false;
    if( m_i8TrrtAz          != Value.m_i8TrrtAz )       return false;
    if( m_i8GnElv           != Value.m_i8GnElv  )       return false;
    if( m_i8TrrtSlwRt       != Value.m_i8TrrtSlwRt )    return false;
    if( m_i8GnElvRt         != Value.m_i8GnElvRt )      return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicGroundCombatVehicle::operator != ( const GED_BasicGroundCombatVehicle & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
