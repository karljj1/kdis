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

#include "./LifeFormAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetEntityPaintScheme( EntityPaintScheme EPS )
{
    m_PaintScheme = EPS;
}

//////////////////////////////////////////////////////////////////////////

EntityPaintScheme LifeFormAppearance::GetEntityPaintScheme() const
{
    return ( EntityPaintScheme )m_PaintScheme;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage LifeFormAppearance::GetEntityDamage() const
{
    return ( EntityDamage )m_Damage;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetEntityEntityCompliance( EntityCompliance EC )
{
	m_Compliance = EC;
}

//////////////////////////////////////////////////////////////////////////

EntityCompliance LifeFormAppearance::GetEntityEntityCompliance() const
{
	return ( EntityCompliance ) m_Compliance;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetEntityFlashLights( KBOOL FL )
{
	m_Flashlight = FL;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LifeFormAppearance::IsEntityFlashLightsOn() const
{
	return m_Flashlight;
}

//////////////////////////////////////////////////////////////////////////

EntityLifeformAppearance LifeFormAppearance::GetEntityLifeformState() const
{
    return ( EntityLifeformAppearance )m_LifeformState;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LifeFormAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LifeFormAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetEntityLifeformWeapon1( EntityLifeformWeapon ELW )
{
    m_Weapon1 = ELW;
}

//////////////////////////////////////////////////////////////////////////

EntityLifeformWeapon LifeFormAppearance::GetEntityLifeformWeapon1() const
{
    return ( EntityLifeformWeapon )m_Weapon1;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetEntityLifeformWeapon2( EntityLifeformWeapon ELW )
{
    m_Weapon2 = ELW;
}

//////////////////////////////////////////////////////////////////////////

EntityLifeformWeapon LifeFormAppearance::GetEntityLifeformWeapon2() const
{
    return ( EntityLifeformWeapon )m_Weapon2;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetEntityCamouflage( EntityCamouflage EC )
{
    m_Camouflage = EC;
}

//////////////////////////////////////////////////////////////////////////

EntityCamouflage LifeFormAppearance::GetEntityCamouflage() const
{
    return ( EntityCamouflage )m_Camouflage;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetConcealedStationary( KBOOL CS )
{
	m_ConcealedStationary = CS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LifeFormAppearance::IsConcealedStationary() const
{
	return m_ConcealedStationary;
}

//////////////////////////////////////////////////////////////////////////

void LifeFormAppearance::SetConcealedMovement( KBOOL CM )
{
	m_ConcealedMovement = CM;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LifeFormAppearance::IsConcealedMovement() const
{
	return m_ConcealedMovement;
}

//////////////////////////////////////////////////////////////////////////

KString LifeFormAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Lifeform Appearance:"
       << "\n\tPaint Scheme:        " << GetEnumAsStringPaintScheme( m_PaintScheme )
	   << "\n\tDamage:              " << GetEnumAsStringEntityDamage( m_Damage )
	   << "\nCompliance:           " << GetEnumAsStringEntityCompliance( m_Compliance )
	   << "\nFlash Lights:          " << m_Flashlight
       << "\n\tLifeform State:      " << GetEnumAsStringEntityLifeformAppearance( m_LifeformState )
       << "\n\tFrozen Status:       " << m_FrozenStatus
       << "\n\tState:               " << m_State
       << "\n\tWeapon 1:            " << GetEnumAsStringEntityLifeformWeapon( m_Weapon1 )
       << "\n\tWeapon 2:            " << GetEnumAsStringEntityLifeformWeapon( m_Weapon2 )
	   << "\n\tCamouflage:          " << GetEnumAsStringEntityCamouflage( m_Camouflage )
	   << "\nConcealed Stationary:  " << m_ConcealedStationary
	   << "\nConcealed Movement:    " << m_ConcealedMovement
	   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL LifeFormAppearance::operator == ( const LifeFormAppearance & Value ) const
{
	// Lets do a single comparison instead of checking every field. 
	// This struct is basically a KUINT32 so lets cast it to one and compare.

	KUINT32 a = *( KUINT32 * )this;
	KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LifeFormAppearance::operator != ( const LifeFormAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
