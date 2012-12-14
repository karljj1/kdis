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

#include "./GED_EnhancedFixedWingAircraft.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_EnhancedFixedWingAircraft::GED_EnhancedFixedWingAircraft( void ) :
    m_ui8SupFuelStatus( 0 ),
    m_ui8AirMaintStatus( 0 ),
    m_ui8PriAmmun( 0 ),
    m_ui8SecAmmun( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedFixedWingAircraft::GED_EnhancedFixedWingAircraft( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedFixedWingAircraft::GED_EnhancedFixedWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi,
        KINT8 Theta, KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation,
        KINT8 Speed, KUINT8 SupFuelStatus, KUINT8 AirMaintenanceStatus, KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition ) :
    GED_BasicFixedWingAircraft( ID, XOffset, YOffset, ZOffset, EA, Psi, Theta, Phi, FuelStatus, HorizontalDeviation, VerticalDeviation, Speed ),
    m_ui8SupFuelStatus( SupFuelStatus ),
    m_ui8AirMaintStatus( AirMaintenanceStatus ),
    m_ui8PriAmmun( PrimaryAmmunition ),
    m_ui8SecAmmun( SecondaryAmmunition )
{
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedFixedWingAircraft::GED_EnhancedFixedWingAircraft( const GED_BasicFixedWingAircraft & BFWA, KUINT8 SupFuelStatus, KUINT8 AirMaintenanceStatus, KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition ) :
    GED_BasicFixedWingAircraft( BFWA ),
    m_ui8SupFuelStatus( SupFuelStatus ),
    m_ui8AirMaintStatus( AirMaintenanceStatus ),
    m_ui8PriAmmun( PrimaryAmmunition ),
    m_ui8SecAmmun( SecondaryAmmunition )
{
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedFixedWingAircraft::~GED_EnhancedFixedWingAircraft( void )
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_EnhancedFixedWingAircraft::GetGroupedEntityCategory() const
{
    return EnhancedFixedWingAircraftGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedFixedWingAircraft::GetLength() const
{
    return GED_ENHANCED_FIXED_WING_AIRCRAFT_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedFixedWingAircraft::SetSupplementalFuelStatus( KUINT8 F )
{
    m_ui8SupFuelStatus = F;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedFixedWingAircraft::GetSupplementalFuelStatus() const
{
    return m_ui8SupFuelStatus;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedFixedWingAircraft::SetAirMaintenanceStatus( KUINT8 A )
{
    m_ui8AirMaintStatus = A;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedFixedWingAircraft::GetAirMaintenanceStatus() const
{
    return m_ui8AirMaintStatus;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedFixedWingAircraft::SetPrimaryAmmunition( KUINT8 P )
{
    m_ui8PriAmmun = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedFixedWingAircraft::GetPrimaryAmmunition() const
{
    return m_ui8PriAmmun;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedFixedWingAircraft::SetSecondaryAmmunition( KUINT8 S )
{
    m_ui8SecAmmun = S;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedFixedWingAircraft::GetSecondaryAmmunition() const
{
    return m_ui8SecAmmun;
}

//////////////////////////////////////////////////////////////////////////

KString GED_EnhancedFixedWingAircraft::GetAsString() const
{
    KStringStream ss;

    ss << GED_BasicFixedWingAircraft::GetAsString();

    ss << "GED Enhanced Fixed Wing Aircraft\n"
       << "\tFuel Status:               " << ( KUINT16 )m_ui8SupFuelStatus   << "0 Liters\n"
       << "\tAir Maintenance Status:    " << ( KUINT16 )m_ui8AirMaintStatus  << "0 km\n"
       << "\tPrimary Ammunition:        " << ( KUINT16 )m_ui8PriAmmun        << "\n"
       << "\tSecondary Ammunition:      " << ( KUINT16 )m_ui8SecAmmun        << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedFixedWingAircraft::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GED_ENHANCED_FIXED_WING_AIRCRAFT_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    GED_BasicFixedWingAircraft::Decode( stream );

    stream >> m_ui8SupFuelStatus
           >> m_ui8AirMaintStatus
           >> m_ui8PriAmmun
           >> m_ui8SecAmmun;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_EnhancedFixedWingAircraft::Encode() const
{
    KDataStream stream;

    GED_EnhancedFixedWingAircraft::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedFixedWingAircraft::Encode( KDataStream & stream ) const
{
    GED_BasicFixedWingAircraft::Encode( stream );

    stream << m_ui8SupFuelStatus
           << m_ui8AirMaintStatus
           << m_ui8PriAmmun
           << m_ui8SecAmmun;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_EnhancedFixedWingAircraft::operator == ( const GED_EnhancedFixedWingAircraft & Value ) const
{
    if( GED_BasicFixedWingAircraft::operator!=( Value ) )   return false;
    if( m_ui8SupFuelStatus  != Value.m_ui8SupFuelStatus )   return false;
    if( m_ui8AirMaintStatus != Value.m_ui8AirMaintStatus )  return false;
    if( m_ui8PriAmmun       != Value.m_ui8PriAmmun )        return false;
    if( m_ui8SecAmmun       != Value.m_ui8SecAmmun )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_EnhancedFixedWingAircraft::operator != ( const GED_EnhancedFixedWingAircraft & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

