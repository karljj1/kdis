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

#include "./NonHumanLifeFormAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

void NonHumanLifeFormAppearance::SetEntityDamage( EntityDamage ED )
{
    m_Damage = ED;
}

//////////////////////////////////////////////////////////////////////////

EntityDamage NonHumanLifeFormAppearance::GetEntityDamage() const
{
    return static_cast<EntityDamage>( m_Damage );
}

//////////////////////////////////////////////////////////////////////////

void NonHumanLifeFormAppearance::SetEntityFrozenStatus( KBOOL EFS )
{
    m_FrozenStatus = EFS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL NonHumanLifeFormAppearance::IsEntityFrozen() const
{
    return m_FrozenStatus;
}

//////////////////////////////////////////////////////////////////////////

void NonHumanLifeFormAppearance::SetEntityMountedHoisted( KBOOL MH )
{
    m_MountedHoisted = MH;
}

//////////////////////////////////////////////////////////////////////////

KBOOL NonHumanLifeFormAppearance::IsEntityMountedHoisted() const
{
    return m_MountedHoisted;
}

//////////////////////////////////////////////////////////////////////////

void NonHumanLifeFormAppearance::SetEntityStateActive( KBOOL ES )
{
    m_State = !ES;
}

//////////////////////////////////////////////////////////////////////////

KBOOL NonHumanLifeFormAppearance::IsEntityStateActive() const
{
    return !m_State;
}

//////////////////////////////////////////////////////////////////////////

KString NonHumanLifeFormAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Non-Human Lifeform Appearance:"
       << "\n\tDamage:               " << GetEnumAsStringEntityDamage( m_Damage )
       << "\n\tFrozen Status:        " << m_FrozenStatus
       << "\n\tMounted/Hoisted:      " << m_MountedHoisted
       << "\n\tState:                " << m_State
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL NonHumanLifeFormAppearance::operator == ( const NonHumanLifeFormAppearance & Value ) const
{
    // Lets do a single comparison instead of checking every field.
    // This struct is basically a KUINT32 so lets cast it to one and compare.

    KUINT32 a = *( KUINT32 * )this;
    KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL NonHumanLifeFormAppearance::operator != ( const NonHumanLifeFormAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
