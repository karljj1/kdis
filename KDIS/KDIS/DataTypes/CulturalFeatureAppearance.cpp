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
	m_ExteriorLights = SL;
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



