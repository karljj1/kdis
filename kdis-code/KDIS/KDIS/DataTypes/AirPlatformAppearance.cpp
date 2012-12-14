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

#include "./AirPlatformAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityPaintScheme( EntityPaintScheme EPS )
{
    m_PaintScheme = EPS;
}

//////////////////////////////////////////////////////////////////////////

EntityPaintScheme AirPlatformAppearance::GetEntityPaintScheme() const
{
    return (EntityPaintScheme)m_PaintScheme;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityMobilityKill( KBOOL MK )
{
    m_MobilityKill = MK;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::DoesEntityMobilityKill() const
{
    return m_MobilityKill;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage AirPlatformAppearance::GetEntityDamage() const
{
    return ( EntityDamage )m_Damage;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntitySmoke( EntitySmoke ES )
{
    m_Smoke = ES;
}

//////////////////////////////////////////////////////////////////////////

EntitySmoke AirPlatformAppearance::GetEntitySmoke() const
{
    return ( EntitySmoke )m_Smoke;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityTrailingEffect( EntityTrailingEffect ETE )
{
    m_TrailingEffect = ETE;
}

//////////////////////////////////////////////////////////////////////////

EntityTrailingEffect AirPlatformAppearance::GetEntityTrailingEffect() const
{
    return ( EntityTrailingEffect )m_TrailingEffect;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityCanopyState( EntityHatchState ECS )
{
	m_CanopyState = ECS;
}

//////////////////////////////////////////////////////////////////////////

EntityHatchState AirPlatformAppearance::GetEntityCanopyState() const
{
	return ( EntityHatchState )m_CanopyState;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityLandingLights( KBOOL LL )
{
	m_LandingLights = LL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntityLandingLightsOn() const
{
	return m_LandingLights;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityNavigationLights( KBOOL NL )
{
	m_NavLights = NL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntityNavigationLightsOn() const
{
	return m_NavLights;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityAntiCollisionLights( KBOOL ACL )
{
	m_AntiColLights = ACL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntityAntiCollisionLightsOn() const
{
	return m_AntiColLights;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityFlamingEffect( KBOOL EFE )
{
    m_FlamingEffectField = EFE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntityFlaming() const
{
    return m_FlamingEffectField;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityAfterburner( KBOOL AB )
{
    m_Afterburner = AB;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsAfterburnerOn() const
{
    return m_Afterburner;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityPowerPlantOn( KBOOL EPPS )
{
    m_PowerPlantStatus = EPPS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntityPowerPlantOn() const
{
    return m_PowerPlantStatus;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityFormationLights( KBOOL FL )
{
	m_FormationLights = FL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntityFormationLightsOn() const
{
	return m_FormationLights;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntitySpotLights( KBOOL SL )
{
	m_SpotLights = SL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntitySpotLightsOn() const
{
	return m_SpotLights;
}

//////////////////////////////////////////////////////////////////////////

void AirPlatformAppearance::SetEntityInteriorLights( KBOOL IL )
{
	m_InteriorLights = IL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::IsEntityInteriorLightsOn() const
{
	return m_InteriorLights;
}

//////////////////////////////////////////////////////////////////////////

KString AirPlatformAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Air Platform Appearance:"
       << "\n\tPaint Scheme:           " << GetEnumAsStringPaintScheme( m_PaintScheme )
	   << "\n\tMobility Kill:          " << m_MobilityKill       
       << "\n\tDamage:                 " << GetEnumAsStringEntityDamage( m_Damage )
       << "\n\tSmoke:                  " << GetEnumAsStringEntitySmoke( m_Smoke )
       << "\n\tTrailing Effect:        " << GetEnumAsStringEntityTrailingEffect( m_TrailingEffect )
       << "\n\tCanopy State:           " << GetEnumAsStringEntityHatchState( m_CanopyState )
	   << "\n\tLanding Lights:         " << m_LandingLights
	   << "\n\tNavigation Lights:      " << m_NavLights
	   << "\n\tAnti-Collision Lights:  " << m_AntiColLights	   
       << "\n\tFlaming Effect:         " << m_FlamingEffectField		
	   << "\n\tAfterburner:            " << m_Afterburner
       << "\n\tFrozen Status:          " << m_FrozenStatus
       << "\n\tPower Plant:            " << m_PowerPlantStatus
       << "\n\tState:                  " << m_State
	   << "\n\tFormation Lights:       " << m_FormationLights
	   << "\n\tSpot Lights:            " << m_SpotLights
	   << "\n\tInterior Lights:        " << m_InteriorLights
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::operator == ( const AirPlatformAppearance & Value ) const
{
	// Lets do a single comparison instead of checking every field. 
	// This struct is basically a KUINT32 so lets cast it to one and compare.

	KUINT32 a = *( KUINT32 * )this;
	KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::operator != ( const AirPlatformAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

