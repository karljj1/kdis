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

#include "./SubSurfacePlatformAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void SubSurfacePlatformAppearance::SetEntityPaintScheme( EntityPaintScheme EPS )
{
    m_PaintScheme = EPS;
}

//////////////////////////////////////////////////////////////////////////

EntityPaintScheme SubSurfacePlatformAppearance::GetEntityPaintScheme() const
{
    return (EntityPaintScheme)m_PaintScheme;
}

//////////////////////////////////////////////////////////////////////////

void SubSurfacePlatformAppearance::SetEntityMobilityKill( KBOOL MK )
{
    m_MobilityKill = MK;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SubSurfacePlatformAppearance::DoesEntityMobilityKill() const
{
    return m_MobilityKill;
}

//////////////////////////////////////////////////////////////////////////

void SubSurfacePlatformAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage SubSurfacePlatformAppearance::GetEntityDamage() const
{
    return ( EntityDamage )m_Damage;
}

//////////////////////////////////////////////////////////////////////////

void SubSurfacePlatformAppearance::SetEntitySmoke( EntitySmoke ES )
{
    m_Smoke = ES;
}

//////////////////////////////////////////////////////////////////////////

EntitySmoke SubSurfacePlatformAppearance::GetEntitySmoke() const
{
    return ( EntitySmoke )m_Smoke;
}

//////////////////////////////////////////////////////////////////////////

void SubSurfacePlatformAppearance::SetEntityHatchState( EntityHatchState ECS )
{
	m_HatchState = ECS;
}

//////////////////////////////////////////////////////////////////////////

EntityHatchState SubSurfacePlatformAppearance::GetEntityHatchState() const
{
	return ( EntityHatchState )m_HatchState;
}

//////////////////////////////////////////////////////////////////////////

void SubSurfacePlatformAppearance::SetEntityFlamingEffect( KBOOL EFE )
{
    m_FlamingEffectField = EFE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SubSurfacePlatformAppearance::IsEntityFlaming() const
{
    return m_FlamingEffectField;
}

//////////////////////////////////////////////////////////////////////////

void SubSurfacePlatformAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SubSurfacePlatformAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void SubSurfacePlatformAppearance::SetEntityPowerPlantOn( KBOOL EPPS )
{
    m_PowerPlantStatus = EPPS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SubSurfacePlatformAppearance::IsEntityPowerPlantOn() const
{
    return m_PowerPlantStatus;
}

//////////////////////////////////////////////////////////////////////////

void SubSurfacePlatformAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SubSurfacePlatformAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

KString SubSurfacePlatformAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Sub Surface Platform Appearance:"
       << "\n\tPaint Scheme:           " << GetEnumAsStringPaintScheme( m_PaintScheme )
	   << "\n\tMobility Kill:          " << m_MobilityKill       
       << "\n\tDamage:                 " << GetEnumAsStringEntityDamage( m_Damage )
       << "\n\tSmoke:                  " << GetEnumAsStringEntitySmoke( m_Smoke )
	   << "\n\tHatch State:            " << GetEnumAsStringEntityHatchState( m_HatchState )
	   << "\n\tRunning Lights:         " << m_RunningLights
       << "\n\tFlaming Effect:         " << m_FlamingEffectField		
       << "\n\tFrozen Status:          " << m_FrozenStatus
       << "\n\tPower Plant:            " << m_PowerPlantStatus
       << "\n\tState:                  " << m_State
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL SubSurfacePlatformAppearance::operator == ( const SubSurfacePlatformAppearance & Value ) const
{
	// Lets do a single comparison instead of checking every field. 
	// This struct is basically a KUINT32 so lets cast it to one and compare.

	KUINT32 a = *( KUINT32 * )this;
	KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SubSurfacePlatformAppearance::operator != ( const SubSurfacePlatformAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
