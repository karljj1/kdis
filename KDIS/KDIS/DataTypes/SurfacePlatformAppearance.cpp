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

#include "./SurfacePlatformAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityPaintScheme( EntityPaintScheme EPS )
{
    m_PaintScheme = EPS;
}

//////////////////////////////////////////////////////////////////////////

EntityPaintScheme SurfacePlatformAppearance::GetEntityPaintScheme() const
{
    return (EntityPaintScheme)m_PaintScheme;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityMobilityKill( KBOOL MK )
{
    m_MobilityKill = MK;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::DoesEntityMobilityKill() const
{
    return m_MobilityKill;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage SurfacePlatformAppearance::GetEntityDamage() const
{
    return ( EntityDamage )m_Damage;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntitySmoke( EntitySmoke ES )
{
    m_Smoke = ES;
}

//////////////////////////////////////////////////////////////////////////

EntitySmoke SurfacePlatformAppearance::GetEntitySmoke() const
{
    return ( EntitySmoke )m_Smoke;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityTrailingEffect( EntityTrailingEffect ETE )
{
    m_TrailingEffect = ETE;
}

//////////////////////////////////////////////////////////////////////////

EntityTrailingEffect SurfacePlatformAppearance::GetEntityTrailingEffect() const
{
    return ( EntityTrailingEffect )m_TrailingEffect;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityRunningLights( KBOOL RL )
{
	m_RunningLights = RL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::IsEntityRunningLightsOn() const
{
	return m_RunningLights;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityFlamingEffect( KBOOL EFE )
{
    m_FlamingEffectField = EFE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::IsEntityFlaming() const
{
    return m_FlamingEffectField;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityPowerPlantOn( KBOOL EPPS )
{
    m_PowerPlantStatus = EPPS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::IsEntityPowerPlantOn() const
{
    return m_PowerPlantStatus;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntitySpotLights( KBOOL SL )
{
	m_SpotLights = SL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::IsEntitySpotLightsOn() const
{
	return m_SpotLights;
}

//////////////////////////////////////////////////////////////////////////

void SurfacePlatformAppearance::SetEntityInteriorLights( KBOOL IL )
{
	m_InteriorLights = IL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::IsEntityInteriorLightsOn() const
{
	return m_InteriorLights;
}

//////////////////////////////////////////////////////////////////////////

KString SurfacePlatformAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Surface Platform Appearance:"
       << "\n\tPaint Scheme:           " << GetEnumAsStringPaintScheme( m_PaintScheme )
	   << "\n\tMobility Kill:          " << m_MobilityKill       
       << "\n\tDamage:                 " << GetEnumAsStringEntityDamage( m_Damage )
       << "\n\tSmoke:                  " << GetEnumAsStringEntitySmoke( m_Smoke )
       << "\n\tTrailing Effect:        " << GetEnumAsStringEntityTrailingEffect( m_TrailingEffect )  
	   << "\n\tRunning Lights:         " << m_RunningLights
       << "\n\tFlaming Effect:         " << m_FlamingEffectField		
       << "\n\tFrozen Status:          " << m_FrozenStatus
       << "\n\tPower Plant:            " << m_PowerPlantStatus
       << "\n\tState:                  " << m_State
	   << "\n\tSpot Lights:            " << m_SpotLights
	   << "\n\tInterior Lights:        " << m_InteriorLights
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::operator == ( const SurfacePlatformAppearance & Value ) const
{
	// Lets do a single comparison instead of checking every field. 
	// This struct is basically a KUINT32 so lets cast it to one and compare.

	KUINT32 a = *( KUINT32 * )this;
	KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SurfacePlatformAppearance::operator != ( const SurfacePlatformAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

