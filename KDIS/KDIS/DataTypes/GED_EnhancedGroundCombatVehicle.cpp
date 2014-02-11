/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

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

GED_EnhancedGroundCombatVehicle::GED_EnhancedGroundCombatVehicle() :
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

GED_EnhancedGroundCombatVehicle::~GED_EnhancedGroundCombatVehicle()
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
