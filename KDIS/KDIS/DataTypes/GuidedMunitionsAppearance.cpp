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

#include "./GuidedMunitionsAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void GuidedMunitionsAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage GuidedMunitionsAppearance::GetEntityDamage() const
{
    return ( EntityDamage )m_Damage;
}

//////////////////////////////////////////////////////////////////////////

void GuidedMunitionsAppearance::SetEntitySmoke( EntitySmoke ES )
{
    m_Smoke = ES;
}

//////////////////////////////////////////////////////////////////////////

EntitySmoke GuidedMunitionsAppearance::GetEntitySmoke() const
{
    return ( EntitySmoke )m_Smoke;
}

//////////////////////////////////////////////////////////////////////////

void GuidedMunitionsAppearance::SetEntityTrailingEffect( EntityTrailingEffect ETE )
{
    m_TrailingEffect = ETE;
}

//////////////////////////////////////////////////////////////////////////

EntityTrailingEffect GuidedMunitionsAppearance::GetEntityTrailingEffect() const
{
    return ( EntityTrailingEffect )m_TrailingEffect;
}

//////////////////////////////////////////////////////////////////////////

void GuidedMunitionsAppearance::SetEntityFlamingEffect( KBOOL EFE )
{
    m_FlamingEffectField = EFE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GuidedMunitionsAppearance::IsEntityFlaming() const
{
    return m_FlamingEffectField;
}

//////////////////////////////////////////////////////////////////////////

void GuidedMunitionsAppearance::SetLaunchFlashPresent( KBOOL LF )
{
	m_LaunchFlash = LF;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GuidedMunitionsAppearance::IsLaunchFlashPresent() const
{
	return m_LaunchFlash;
}

//////////////////////////////////////////////////////////////////////////

void GuidedMunitionsAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GuidedMunitionsAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void GuidedMunitionsAppearance::SetEntityPowerPlantOn( KBOOL EPPS )
{
    m_PowerPlantStatus = EPPS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GuidedMunitionsAppearance::IsEntityPowerPlantOn() const
{
    return m_PowerPlantStatus;
}

//////////////////////////////////////////////////////////////////////////

void GuidedMunitionsAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GuidedMunitionsAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

void GuidedMunitionsAppearance::SetMaskedCloaked( KBOOL MC )
{
	m_MaskedCloaked = MC;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GuidedMunitionsAppearance::IsMaskedCloaked() const
{
	return m_MaskedCloaked;
}

//////////////////////////////////////////////////////////////////////////

KString GuidedMunitionsAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Guided Munitions Appearance:"       	   
       << "\n\tDamage:                 " << GetEnumAsStringEntityDamage( m_Damage )
       << "\n\tSmoke:                  " << GetEnumAsStringEntitySmoke( m_Smoke )
	   << "\n\tTrailing Effect:        " << GetEnumAsStringEntityTrailingEffect( m_TrailingEffect )
       << "\n\tFlaming Effect:         " << m_FlamingEffectField		
	   << "\n\tLaunch FLash:           " << m_LaunchFlash	
       << "\n\tFrozen Status:          " << m_FrozenStatus
       << "\n\tPower Plant:            " << m_PowerPlantStatus
       << "\n\tState:                  " << m_State
	   << "\n\tMasked/Cloaked:         " << m_MaskedCloaked
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL GuidedMunitionsAppearance::operator == ( const GuidedMunitionsAppearance & Value ) const
{
	// Lets do a single comparison instead of checking every field. 
	// This struct is basically a KUINT32 so lets cast it to one and compare.

	KUINT32 a = *( KUINT32 * )this;
	KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GuidedMunitionsAppearance::operator != ( const GuidedMunitionsAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
