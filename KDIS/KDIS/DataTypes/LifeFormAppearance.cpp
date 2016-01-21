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

void LifeFormAppearance::SetEntityLifeformState( KDIS::DATA_TYPE::ENUMS::EntityLifeformAppearance EA )
{
    m_LifeformState = EA;
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
       << "\n\tPaint Scheme:         " << GetEnumAsStringPaintScheme( m_PaintScheme )
	   << "\n\tDamage:               " << GetEnumAsStringEntityDamage( m_Damage )
	   << "\n\tCompliance:           " << GetEnumAsStringEntityCompliance( m_Compliance )
	   << "\n\tFlash Lights:         " << m_Flashlight
       << "\n\tLifeform State:       " << GetEnumAsStringEntityLifeformAppearance( m_LifeformState )
       << "\n\tFrozen Status:        " << m_FrozenStatus
       << "\n\tState:                " << m_State
       << "\n\tWeapon 1:             " << GetEnumAsStringEntityLifeformWeapon( m_Weapon1 )
       << "\n\tWeapon 2:             " << GetEnumAsStringEntityLifeformWeapon( m_Weapon2 )
	   << "\n\tCamouflage:           " << GetEnumAsStringEntityCamouflage( m_Camouflage )
	   << "\n\tConcealed Stationary: " << m_ConcealedStationary
	   << "\n\tConcealed Movement:   " << m_ConcealedMovement
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
