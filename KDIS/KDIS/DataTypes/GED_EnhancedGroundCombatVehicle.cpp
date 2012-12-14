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

#include "./GED_EnhancedGroundCombatVehicle.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatVehicle::GED_EnhancedGroundCombatVehicle( void ) :
    m_ui8FuelStatus( 0 ),
    m_ui8GrndMaintStatus( 0 ),
    m_ui8PriAmmun( 0 ),
    m_ui8SecAmmun( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatVehicle::GED_EnhancedGroundCombatVehicle( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatVehicle::GED_EnhancedGroundCombatVehicle( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi,
        KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 TurretAzimuth, KINT8 GunElevation, KINT8 TurretSlewRate,
        KINT8 GunElevationRate, KUINT8 FuelStatus, KUINT8 GroundMaintenanceStatus, KUINT8 PrimaryAmmunition,
        KUINT8 SecondaryAmmunition ) :
    GED_BasicGroundCombatVehicle( ID, XOffset, YOffset, ZOffset, EA, Psi, Theta, Phi, Speed,
                                  TurretAzimuth, GunElevation, TurretSlewRate, GunElevationRate ),
    m_ui8FuelStatus( FuelStatus ),
    m_ui8GrndMaintStatus( GroundMaintenanceStatus ),
    m_ui8PriAmmun( PrimaryAmmunition ),
    m_ui8SecAmmun( SecondaryAmmunition )
{
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatVehicle::GED_EnhancedGroundCombatVehicle( const GED_BasicGroundCombatVehicle & BGCV, KUINT8 FuelStatus, KUINT8 GroundMaintenanceStatus,
        KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition ) :
    GED_BasicGroundCombatVehicle( BGCV ),
    m_ui8FuelStatus( FuelStatus ),
    m_ui8GrndMaintStatus( GroundMaintenanceStatus ),
    m_ui8PriAmmun( PrimaryAmmunition ),
    m_ui8SecAmmun( SecondaryAmmunition )
{
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatVehicle::~GED_EnhancedGroundCombatVehicle( void )
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_EnhancedGroundCombatVehicle::GetGroupedEntityCategory() const
{
    return EnhancedGroundCombatVehicleGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedGroundCombatVehicle::GetLength() const
{
    return GED_ENHANCED_GROUND_COMBAT_VEHICLE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatVehicle::SetFuelStatus( KUINT8 F )
{
    m_ui8FuelStatus = F;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedGroundCombatVehicle::GetFuelStatus() const
{
    return m_ui8FuelStatus;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatVehicle::SetGroundMaintenanceStatus( KUINT8 G )
{
    m_ui8GrndMaintStatus = G;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedGroundCombatVehicle::GetGroundMaintenanceStatus() const
{
    return m_ui8GrndMaintStatus;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatVehicle::SetPrimaryAmmunition( KUINT8 P )
{
    m_ui8PriAmmun = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedGroundCombatVehicle::GetPrimaryAmmunition() const
{
    return m_ui8PriAmmun;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatVehicle::SetSecondaryAmmunition( KUINT8 S )
{
    m_ui8SecAmmun = S;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedGroundCombatVehicle::GetSecondaryAmmunition() const
{
    return m_ui8SecAmmun;
}

//////////////////////////////////////////////////////////////////////////

KString GED_EnhancedGroundCombatVehicle::GetAsString() const
{
    KStringStream ss;

    ss << GED_BasicGroundCombatVehicle::GetAsString();

    ss << "GED Enhanced Ground Combat Vehicle\n"
       << "\tFuel Status:               " << ( KUINT16 )m_ui8FuelStatus      << "0 Litres\n"
       << "\tGround Maintenance Status: " << ( KUINT16 )m_ui8GrndMaintStatus << "0 km\n"
       << "\tPrimary Ammunition:        " << ( KUINT16 )m_ui8PriAmmun        << "\n"
       << "\tSecondary Ammunition:      " << ( KUINT16 )m_ui8SecAmmun        << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatVehicle::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GED_ENHANCED_GROUND_COMBAT_VEHICLE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    GED_BasicGroundCombatVehicle::Decode( stream );

    stream >> m_ui8FuelStatus
           >> m_ui8GrndMaintStatus
           >> m_ui8PriAmmun
           >> m_ui8SecAmmun;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_EnhancedGroundCombatVehicle::Encode() const
{
    KDataStream stream;

    GED_EnhancedGroundCombatVehicle::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatVehicle::Encode( KDataStream & stream ) const
{
    GED_BasicGroundCombatVehicle::Encode( stream );

    stream << m_ui8FuelStatus
           << m_ui8GrndMaintStatus
           << m_ui8PriAmmun
           << m_ui8SecAmmun;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_EnhancedGroundCombatVehicle::operator == ( const GED_EnhancedGroundCombatVehicle & Value ) const
{
    if( GED_BasicGroundCombatVehicle::operator!=( Value ) )     return false;
    if( m_ui8FuelStatus         != Value.m_ui8FuelStatus )      return false;
    if( m_ui8GrndMaintStatus    != Value.m_ui8GrndMaintStatus ) return false;
    if( m_ui8PriAmmun           != Value.m_ui8PriAmmun )        return false;
    if( m_ui8SecAmmun           != Value.m_ui8SecAmmun )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_EnhancedGroundCombatVehicle::operator != ( const GED_EnhancedGroundCombatVehicle & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
