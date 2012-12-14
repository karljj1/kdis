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

#include "./SensorEmitterAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityPaintScheme( EntityPaintScheme EPS )
{
    m_PaintScheme = EPS;
}

//////////////////////////////////////////////////////////////////////////

EntityPaintScheme SensorEmitterAppearance::GetEntityPaintScheme() const
{
    return (EntityPaintScheme)m_PaintScheme;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityMobilityKill( KBOOL MK )
{
    m_MobilityKill = MK;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::DoesEntityMobilityKill() const
{
    return m_MobilityKill;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetMissionKill( KBOOL MK )
{
    m_Mission = MK;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::HasMissionKill() const
{
    return m_Mission;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage SensorEmitterAppearance::GetEntityDamage() const
{
    return ( EntityDamage )m_Damage;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntitySmoke( EntitySmoke ES )
{
    m_Smoke = ES;
}

//////////////////////////////////////////////////////////////////////////

EntitySmoke SensorEmitterAppearance::GetEntitySmoke() const
{
    return ( EntitySmoke )m_Smoke;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityTrailingEffect( EntityTrailingEffect ETE )
{
    m_TrailingEffect = ETE;
}

//////////////////////////////////////////////////////////////////////////

EntityTrailingEffect SensorEmitterAppearance::GetEntityTrailingEffect() const
{
    return ( EntityTrailingEffect )m_TrailingEffect;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SeLights( KBOOL L )
{
	m_Lights = L;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsLightsOn() const
{
	return m_Lights;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityFlamingEffect( KBOOL EFE )
{
    m_FlamingEffectField = EFE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsEntityFlaming() const
{
    return m_FlamingEffectField;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetAntennaRaised( KBOOL AR )
{
    m_Antenna = AR;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsAntennaRaised() const
{
    return m_Antenna;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityCamouflage( EntityCamouflage EC )
{
    m_Camouflage = EC;
}

//////////////////////////////////////////////////////////////////////////

EntityCamouflage SensorEmitterAppearance::GetEntityCamouflage() const
{
    return ( EntityCamouflage )m_Camouflage;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityConcealed( KBOOL EC )
{
    m_Concealed = EC;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsEntityConcealed() const
{
    return m_Concealed;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityPowerPlantOn( KBOOL EPPS )
{
    m_PowerPlantStatus = EPPS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsEntityPowerPlantOn() const
{
    return m_PowerPlantStatus;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityTentExtended( KBOOL ET )
{
    m_Tent = ET;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsEntityTentExtended() const
{
    return m_Tent;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityBlackoutLights( KBOOL BL )
{
	m_BlackoutLights = BL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsEntityBlackoutLightsOn() const
{
	return m_BlackoutLights;
}

//////////////////////////////////////////////////////////////////////////

void SensorEmitterAppearance::SetEntityInteriorLights( KBOOL IL )
{
	m_InteriorLights = IL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::IsEntityInteriorLightsOn() const
{
	return m_InteriorLights;
}

//////////////////////////////////////////////////////////////////////////

KString SensorEmitterAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Land Platform Appearance:"
       << "\n\tPaint Scheme:           " << GetEnumAsStringPaintScheme( m_PaintScheme )
	   << "\n\tMobility Kill:          " << m_MobilityKill
	   << "\n\tMission Kill:           " << m_Mission
       << "\n\tDamage:                 " << GetEnumAsStringEntityDamage( m_Damage )
       << "\n\tSmoke:                  " << GetEnumAsStringEntitySmoke( m_Smoke )
       << "\n\tTrailing Effect:        " << GetEnumAsStringEntityTrailingEffect( m_TrailingEffect )	   
	   << "\n\tLights:                 " << m_Lights		
       << "\n\tFlaming Effect:         " << m_FlamingEffectField		
	   << "\n\tAntenna Raised:         " << m_Antenna		
       << "\n\tCamouflage:             " << GetEnumAsStringEntityCamouflage( m_Camouflage )
       << "\n\tConcealed:              " << m_Concealed
       << "\n\tFrozen Status:          " << m_FrozenStatus
       << "\n\tPower Plant:            " << m_PowerPlantStatus
       << "\n\tState:                  " << m_State
       << "\n\tTent:                   " << m_Tent
	   << "\n\tBlackout Lights:        " << m_BlackoutLights
	   << "\n\tInterior Lights:        " << m_InteriorLights
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::operator == ( const SensorEmitterAppearance & Value ) const
{
	// Lets do a single comparison instead of checking every field. 
	// This struct is basically a KUINT32 so lets cast it to one and compare.

	KUINT32 a = *( KUINT32 * )this;
	KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SensorEmitterAppearance::operator != ( const SensorEmitterAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



