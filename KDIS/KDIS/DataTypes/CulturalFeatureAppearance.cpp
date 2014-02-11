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

#include "./CulturalFeatureAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void CulturalFeatureAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage CulturalFeatureAppearance::GetEntityDamage() const
{
    return ( EntityDamage )m_Damage;
}

//////////////////////////////////////////////////////////////////////////

void CulturalFeatureAppearance::SetEntitySmoke( EntitySmoke ES )
{
    m_Smoke = ES;
}

//////////////////////////////////////////////////////////////////////////

EntitySmoke CulturalFeatureAppearance::GetEntitySmoke() const
{
    return ( EntitySmoke )m_Smoke;
}

//////////////////////////////////////////////////////////////////////////

void CulturalFeatureAppearance::SetEntityFlamingEffect( KBOOL EFE )
{
    m_FlamingEffectField = EFE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CulturalFeatureAppearance::IsEntityFlaming() const
{
    return m_FlamingEffectField;
}

//////////////////////////////////////////////////////////////////////////

void CulturalFeatureAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CulturalFeatureAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void CulturalFeatureAppearance::SetInternalHeatStatusOn( KBOOL IHS )
{
	m_InternalHeatStatus = IHS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CulturalFeatureAppearance::IsInternalHeatOn() const
{
	return m_InternalHeatStatus;
}

//////////////////////////////////////////////////////////////////////////

void CulturalFeatureAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CulturalFeatureAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

void CulturalFeatureAppearance::SetEntityExteriorLights( KBOOL EL )
{
	m_ExteriorLights = EL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CulturalFeatureAppearance::IsEntityExteriorLightsOn() const
{
	return m_ExteriorLights;
}

//////////////////////////////////////////////////////////////////////////

void CulturalFeatureAppearance::SetEntityInteriorLights( KBOOL IL )
{
	m_InteriorLights = IL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CulturalFeatureAppearance::IsEntityInteriorLightsOn() const
{
	return m_InteriorLights;
}

//////////////////////////////////////////////////////////////////////////

void CulturalFeatureAppearance::SetEntityMaskedCloaked( KBOOL MC )
{
	m_MaskedCloaked = MC;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CulturalFeatureAppearance::IsEntityMaskedCloaked() const
{
	return m_MaskedCloaked;
}

//////////////////////////////////////////////////////////////////////////

KString CulturalFeatureAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Cultural Feature Appearance:"
       << "\n\tDamage:                 " << GetEnumAsStringEntityDamage( m_Damage )
       << "\n\tSmoke:                  " << GetEnumAsStringEntitySmoke( m_Smoke ) 
       << "\n\tFlaming Effect:         " << m_FlamingEffectField		
       << "\n\tFrozen Status:          " << m_FrozenStatus
	   << "\n\tInternal Heat:          " << m_InternalHeatStatus
       << "\n\tState:                  " << m_State
	   << "\n\tExterior Lights:        " << m_InteriorLights
	   << "\n\tInterior Lights:        " << m_InteriorLights
	   << "\n\tMasked/Cloaked:         " << m_MaskedCloaked
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL CulturalFeatureAppearance::operator == ( const CulturalFeatureAppearance & Value ) const
{
	// Lets do a single comparison instead of checking every field. 
	// This struct is basically a KUINT32 so lets cast it to one and compare.

	KUINT32 a = *( KUINT32 * )this;
	KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CulturalFeatureAppearance::operator != ( const CulturalFeatureAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



