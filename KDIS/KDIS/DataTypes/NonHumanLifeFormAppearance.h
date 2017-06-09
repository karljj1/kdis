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

For Further Information Please Contact Karl Jones at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    class:      NonHumanLifeFormAppearance
    created:    09/06/2017
    author:     Dale Marchand

    purpose:    Represents the appearance of a non-human life form.
                Implemented as struct so as to prevent the size from
                changing due to RTTI etc. This struct will be part of a
                union with all specific appearance values so it is implemented
                slightly different.
                No constructors to prevent C2620 error caused by union of
                classes/structs
    size:       32 Bits / 4 Octet
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./Enums/KDISEnums.h"

namespace KDIS {
namespace DATA_TYPE {

struct KDIS_EXPORT NonHumanLifeFormAppearance
{
protected:
                                         // Bits
    KUINT32 m_Unused1               : 3; // 0-2
    KUINT32 m_Damage                : 2; // 3-4
    KUINT32 m_Unused2               : 16; // 5-20
    KUINT32 m_FrozenStatus          : 1; // 21
    KUINT32 m_MountedHoisted        : 1; // 22
    KUINT32 m_State                 : 1; // 23
    KUINT32 m_Unused3               : 8; // 24-31

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::NonHumanLifeFormAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::NonHumanLifeFormAppearance::GetEntityDamage
    // Description: Entity Damage/Health State.
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED );
    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NonHumanLifeFormAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::NonHumanLifeFormAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NonHumanLifeFormAppearance::SetEntityMountedHoisted
    //              KDIS::DATA_TYPE::NonHumanLifeFormAppearance::IsEntityMountedHoisted
    // Description: Is the lifeform mounted/hoisted on another platform
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityMountedHoisted(KBOOL MH );
    KBOOL IsEntityMountedHoisted() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NonHumanLifeFormAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::NonHumanLifeFormAppearance::IsEntityStateActive
    // Description: Active(true) / De active(false)
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NonHumanLifeFormAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const NonHumanLifeFormAppearance & Value ) const;
    KBOOL operator != ( const NonHumanLifeFormAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
