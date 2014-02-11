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

#include "./LandPlatformAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityPaintScheme( EntityPaintScheme EPS )
{
    m_PaintScheme = EPS;
}

//////////////////////////////////////////////////////////////////////////

EntityPaintScheme LandPlatformAppearance::GetEntityPaintScheme() const
{
    return (EntityPaintScheme)m_PaintScheme;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityMobilityKill( KBOOL MK )
{
    m_MobilityKill = MK;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::DoesEntityMobilityKill() const
{
    return m_MobilityKill;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityFirePower( KBOOL FP )
{
    m_FirePower = FP;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::DoesFirePowerKill() const
{
    return m_FirePower;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage LandPlatformAppearance::GetEntityDamage() const
{
    return ( EntityDamage )m_Damage;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntitySmoke( EntitySmoke ES )
{
    m_Smoke = ES;
}

//////////////////////////////////////////////////////////////////////////

EntitySmoke LandPlatformAppearance::GetEntitySmoke() const
{
    return ( EntitySmoke )m_Smoke;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityTrailingEffect( EntityTrailingEffect ETE )
{
    m_TrailingEffect = ETE;
}

//////////////////////////////////////////////////////////////////////////

EntityTrailingEffect LandPlatformAppearance::GetEntityTrailingEffect() const
{
    return ( EntityTrailingEffect )m_TrailingEffect;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityHatchState( EntityHatchState EHS )
{
    m_HatchState = EHS;
}

//////////////////////////////////////////////////////////////////////////

EntityHatchState LandPlatformAppearance::GetEntityHatchState() const
{
    return ( EntityHatchState )m_HatchState;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityHeadLights( KBOOL HL )
{
	m_HeadLights = HL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityHeadLightsOn() const
{
	return m_HeadLights;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityTailLights( KBOOL TL )
{
	m_TailLights = TL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityTailLightsOn() const
{
	return m_TailLights;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityBrakeLights( KBOOL BL )
{
	m_BrakeLights = BL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityBrakeLightsOn() const	
{
	return m_BrakeLights;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityFlamingEffect( KBOOL EFE )
{
    m_FlamingEffectField = EFE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityFlaming() const
{
    return m_FlamingEffectField;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityLauncher( KBOOL EL )
{
    m_Launcher = EL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityLauncherRaised() const
{
    return m_Launcher;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityCamouflage( EntityCamouflage EC )
{
    m_Camouflage = EC;
}

//////////////////////////////////////////////////////////////////////////

EntityCamouflage LandPlatformAppearance::GetEntityCamouflage() const
{
    return ( EntityCamouflage )m_Camouflage;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityConcealed( KBOOL EC )
{
    m_Concealed = EC;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityConcealed() const
{
    return m_Concealed;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityPowerPlantOn( KBOOL EPPS )
{
    m_PowerPlantStatus = EPPS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityPowerPlantOn() const
{
    return m_PowerPlantStatus;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityTentExtended( KBOOL ET )
{
    m_Tent = ET;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityTentExtended() const
{
    return m_Tent;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityRampDown( KBOOL ER )
{
    m_Ramp = ER;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityRampDown() const
{
    return m_Ramp;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityBlackoutLights( KBOOL BL )
{
	m_BlackoutLights = BL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityBlackoutLightsOn() const
{
	return m_BlackoutLights;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityBlackoutBrakeLights( KBOOL BBL )
{
	m_BlackoutBrakeLights = BBL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityBlackoutBrakeLightsOn() const
{
	return m_BlackoutBrakeLights;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntitySpotLights( KBOOL SL )
{
	m_SpotLights = SL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntitySpotLightsOn() const
{
	return m_SpotLights;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityInteriorLights( KBOOL IL )
{
	m_InteriorLights = IL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityInteriorLightsOn() const
{
	return m_InteriorLights;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntitySurrdenderState( KBOOL SS )
{
	m_SurrenderState = SS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::HasEntitySurrendered() const
{
	return m_SurrenderState;
}

//////////////////////////////////////////////////////////////////////////

void LandPlatformAppearance::SetEntityMaskedCloaked( KBOOL MC )
{
	m_MaskedCloaked = MC;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::IsEntityMaskedCloaked() const
{
	return m_MaskedCloaked;
}

//////////////////////////////////////////////////////////////////////////

KString LandPlatformAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Land Platform Appearance:"
       << "\n\tPaint Scheme:           " << GetEnumAsStringPaintScheme( m_PaintScheme )
	   << "\n\tMobility Kill:          " << m_MobilityKill
       << "\n\tFire Power Kill:        " << m_FirePower
       << "\n\tDamage:                 " << GetEnumAsStringEntityDamage( m_Damage )
       << "\n\tSmoke:                  " << GetEnumAsStringEntitySmoke( m_Smoke )
       << "\n\tTrailing Effect:        " << GetEnumAsStringEntityTrailingEffect( m_TrailingEffect )
       << "\n\tHatch State:            " << GetEnumAsStringEntityHatchState( m_HatchState )
	   << "\n\tHead Lights:            " << m_HeadLights
	   << "\n\tTail Lights:            " << m_TailLights 
	   << "\n\tBrake Lights:           " << m_BrakeLights	   
       << "\n\tFlaming Effect:         " << m_FlamingEffectField		
	   << "\n\tLauncher:               " << m_Launcher
       << "\n\tCamouflage:             " << GetEnumAsStringEntityCamouflage( m_Camouflage )
       << "\n\tConcealed:              " << m_Concealed
       << "\n\tFrozen Status:          " << m_FrozenStatus
       << "\n\tPower Plant:            " << m_PowerPlantStatus
       << "\n\tState:                  " << m_State
       << "\n\tTent:                   " << m_Tent
       << "\n\tRamp:                   " << m_Ramp
	   << "\n\tBlackout Lights:        " << m_BlackoutLights
	   << "\n\tBlackout Brake Lights:  " << m_BlackoutBrakeLights
	   << "\n\tSpot Lights:            " << m_SpotLights
	   << "\n\tInterior Lights:        " << m_InteriorLights
	   << "\n\tSurrender State:        " << m_SurrenderState 
	   << "\n\tMasked/Cloaked:         " << m_MaskedCloaked
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::operator == ( const LandPlatformAppearance & Value ) const
{
	// Lets do a single comparison instead of checking every field. 
	// This struct is basically a KUINT32 so lets cast it to one and compare.

	KUINT32 a = *( KUINT32 * )this;
	KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LandPlatformAppearance::operator != ( const LandPlatformAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



