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

#include "./ExpendableAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage ExpendableAppearance::GetEntityDamage() const
{
    return static_cast<EntityDamage>( m_Damage );
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntitySmokeEmanating( KBOOL ESE )
{
    m_Smoke = ESE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableAppearance::IsEntitySmokeEmanating() const
{
    return m_Smoke;
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityParachuteStatus( Parachute EPS )
{
    m_ParachuteStatus = EPS;
}

//////////////////////////////////////////////////////////////////////////

Parachute ExpendableAppearance::GetEntityParachuteStatus() const
{
    return static_cast<Parachute>( m_ParachuteStatus );
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityFlareSmokeColor( FlareSmokeColor EFSC )
{
    m_FlareSmokeColor = EFSC;
}

//////////////////////////////////////////////////////////////////////////

FlareSmokeColor ExpendableAppearance::GetEntityFlareSmokeColor() const
{
    return static_cast<FlareSmokeColor>( m_FlareSmokeColor );
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityFlamingEffect( KBOOL EFE )
{
    m_FlamingEffectField = EFE;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableAppearance::IsEntityFlaming() const
{
    return m_FlamingEffectField;
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityLaunchFlashPresent( KBOOL ELFP )
{
    m_LaunchFlash = ELFP;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableAppearance::IsEntityLaunchFlashPresent() const
{
    return m_LaunchFlash;
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityFlareSmokeStatus( FlareSmokeStatus EFSS )
{
    m_FlareSmokeStatus = EFSS;
}

//////////////////////////////////////////////////////////////////////////

FlareSmokeStatus ExpendableAppearance::GetEntityFlareSmokeStatus() const
{
    return static_cast<FlareSmokeStatus>( m_FlareSmokeStatus );
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityPowerPlantOn( KBOOL EPPS )
{
    m_PowerPlantStatus = EPPS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableAppearance::IsEntityPowerPlantOn() const
{
    return m_PowerPlantStatus;
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntitySpotChaffStatus( SpotChaff ESCS )
{
    m_SpotChaffStatus = ESCS;
}

//////////////////////////////////////////////////////////////////////////

SpotChaff ExpendableAppearance::GetEntitySpotChaffStatus() const
{
    return static_cast<SpotChaff>( m_SpotChaffStatus );
}

//////////////////////////////////////////////////////////////////////////

void ExpendableAppearance::SetEntityMaskedCloaked( KBOOL MC )
{
  m_MaskedCloaked = MC;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableAppearance::IsEntityMaskedCloaked() const
{
  return m_MaskedCloaked;
}

//////////////////////////////////////////////////////////////////////////

namespace
{
const char *sRetTab = "\n\t";
}

KString ExpendableAppearance::GetAsString() const
{
    KStringStream ss;

    ss <<            "Expendable Appearance:"
       << sRetTab << "Damage:               " << GetEnumAsStringEntityDamage( m_Damage )
       << sRetTab << "Is Smoke Emanating:   " << m_Smoke
       << sRetTab << "Parachute Status:     " << GetEnumAsStringParachute( m_ParachuteStatus )
       << sRetTab << "Flare/Smoke Color:    " << GetEnumAsStringFlareSmokeColor( m_FlareSmokeColor )
       << sRetTab << "Flaming Effect:       " << m_FlamingEffectField
       << sRetTab << "Launch Flash:         " << m_LaunchFlash
       << sRetTab << "Flare/Smoke Status:   " << GetEnumAsStringFlareSmokeStatus( m_FlareSmokeStatus )
       << sRetTab << "Frozen Status:        " << m_FrozenStatus
       << sRetTab << "Power Plant Status:   " << m_PowerPlantStatus
       << sRetTab << "State:                " << m_State
       << sRetTab << "Spot Chaff Status:    " << GetEnumAsStringSpotChaff( m_SpotChaffStatus )
       << sRetTab << "Masked/Cloaked:       " << m_MaskedCloaked
       << sRetTab;

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableAppearance::operator == ( const ExpendableAppearance & Value ) const
{
    // Lets do a single comparison instead of checking every field.
    // This struct is basically a KUINT32 so lets cast it to one and compare.

    KUINT32 a = *( KUINT32 * )this;
    KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableAppearance::operator != ( const ExpendableAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
