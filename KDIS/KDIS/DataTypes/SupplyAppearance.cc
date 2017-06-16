/*********************************************************************
Copyright 2017 Karl Jones
               Dale Marchand
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

#include "./SupplyAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void SupplyAppearance::SetEntityPaintScheme( EntityPaintScheme EPS )
{
    m_PaintScheme = EPS;
}

//////////////////////////////////////////////////////////////////////////

EntityPaintScheme SupplyAppearance::GetEntityPaintScheme() const
{
    return static_cast<EntityPaintScheme>( m_PaintScheme );
}

//////////////////////////////////////////////////////////////////////////

void SupplyAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage SupplyAppearance::GetEntityDamage() const
{
    return static_cast<EntityDamage>( m_Damage );
}

//////////////////////////////////////////////////////////////////////////

void SupplyAppearance::SetEntityParachuteStatus( Parachute EPS )
{
    m_ParachuteStatus = EPS;
}

//////////////////////////////////////////////////////////////////////////

Parachute SupplyAppearance::GetEntityParachuteStatus() const
{
    return static_cast<Parachute>( m_ParachuteStatus );
}

//////////////////////////////////////////////////////////////////////////

void SupplyAppearance::SetEntityFlamingEffect( KBOOL EFE )
{
    m_FlamingEffectField = EFE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SupplyAppearance::IsEntityFlaming() const
{
    return m_FlamingEffectField;
}

//////////////////////////////////////////////////////////////////////////

void SupplyAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SupplyAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void SupplyAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SupplyAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

void SupplyAppearance::SetEntityDeployedStatus( SupplyDeployed EDS )
{
    m_DeployedStatus = EDS;
}

//////////////////////////////////////////////////////////////////////////

SupplyDeployed SupplyAppearance::GetEntityDeployedStatus() const
{
    return static_cast<SupplyDeployed>( m_DeployedStatus );
}

//////////////////////////////////////////////////////////////////////////

void SupplyAppearance::SetEntityMaskedCloaked( KBOOL MC )
{
  m_MaskedCloaked = MC;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SupplyAppearance::IsEntityMaskedCloaked() const
{
  return m_MaskedCloaked;
}

//////////////////////////////////////////////////////////////////////////

namespace
{
const char *sRetTab = "\n\t";
}

KString SupplyAppearance::GetAsString() const
{
    KStringStream ss;

    ss <<            "Supply Appearance:"
       << sRetTab << "Paint Scheme:         " << GetEnumAsStringEntityPaintScheme( m_PaintScheme )
       << sRetTab << "Damage:               " << GetEnumAsStringEntityDamage( m_Damage )
       << sRetTab << "Parachute Status:     " << GetEnumAsStringParachute( m_ParachuteStatus )
       << sRetTab << "Flaming Effect:       " << m_FlamingEffectField
       << sRetTab << "Frozen Status:        " << m_FrozenStatus
       << sRetTab << "State:                " << m_State
       << sRetTab << "Deployed Status:      " << GetEnumAsStringSupplyDeployed( m_DeployedStatus )
       << sRetTab << "Masked/Cloaked:       " << m_MaskedCloaked
       << sRetTab;

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL SupplyAppearance::operator == ( const SupplyAppearance & Value ) const
{
    // Lets do a single comparison instead of checking every field.
    // This struct is basically a KUINT32 so lets cast it to one and compare.

    KUINT32 a = *( KUINT32 * )this;
    KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SupplyAppearance::operator != ( const SupplyAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
