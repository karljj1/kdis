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
    class:      ExpendableAppearance
    created:    09/16/2017
    author:     Dale Marchand

    purpose:    Represents the appearance of a expendable entity..
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

struct KDIS_EXPORT ExpendableAppearance
{
protected:
                                         // Bits
    KUINT32 m_Unused1               : 3; // 0-2
    KUINT32 m_Damage                : 2; // 3-4
    KUINT32 m_Smoke                 : 1; // 5
    KUINT32 m_Unused2               : 1; // 6
    KUINT32 m_ParachuteStatus       : 2; // 7-8
    KUINT32 m_FlareSmokeColor       : 3; // 9-11
    KUINT32 m_Unused3               : 3; // 12-14
    KUINT32 m_FlamingEffectField    : 1; // 15
    KUINT32 m_LaunchFlash           : 1; // 16
    KUINT32 m_FlareSmokeStatus      : 2; // 17-18
    KUINT32 m_Unused4               : 2; // 19-20
    KUINT32 m_FrozenStatus          : 1; // 21
    KUINT32 m_PowerPlantStatus      : 1; // 22
    KUINT32 m_State                 : 1; // 23
    KUINT32 m_SpotChaffStatus       : 2; // 24-25
    KUINT32 m_Unused5               : 5; // 26-30
    KUINT32 m_MaskedCloaked         : 1; // 31

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::ExpendableAppearance::GetEntityDamage
    // Description: Entity Damage/Health State.
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED );
    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntitySmokeEmanating
    //              KDIS::DATA_TYPE::ExpendableAppearance::IsEntitySmokeEmanating
    // Description: Is the entity emanating smoke?
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntitySmokeEmanating( KBOOL ESE );
    KBOOL IsEntitySmokeEmanating() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityParachuteStatus
    //              KDIS::DATA_TYPE::ExpendableAppearance::GetEntityParachuteStatus
    // Description: Entity Parachute Status.
    // Parameter:   EntityParachuteStatus EPS
    //************************************
    void SetEntityParachuteStatus( KDIS::DATA_TYPE::ENUMS::Parachute EPS );
    KDIS::DATA_TYPE::ENUMS::Parachute GetEntityParachuteStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityFlareSmokeColor
    //              KDIS::DATA_TYPE::ExpendableAppearance::GetEntityFlareSmokeColor
    // Description: Entity Parachute Status.
    // Parameter:   EntityFlareSmokeColor EFSC
    //************************************
    void SetEntityFlareSmokeColor( KDIS::DATA_TYPE::ENUMS::FlareSmokeColor EFSC );
    KDIS::DATA_TYPE::ENUMS::FlareSmokeColor GetEntityFlareSmokeColor() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityFlamingEffect
    //              KDIS::DATA_TYPE::ExpendableAppearance::IsEntityFlaming
    // Description: Are flames rising from the entity?
    // Parameter:   KBOOL EFE
    //************************************
    void SetEntityFlamingEffect( KBOOL EFE );
    KBOOL IsEntityFlaming() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityLaunchFlashPresent
    //              KDIS::DATA_TYPE::ExpendableAppearance::IsEntityLaunchFlashPresent
    // Description: Is a launch flash present?
    // Parameter:   KBOOL ELFP
    //************************************
    void SetEntityLaunchFlashPresent( KBOOL ELFP );
    KBOOL IsEntityLaunchFlashPresent() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityFlareSmokeStatus
    //              KDIS::DATA_TYPE::ExpendableAppearance::GetEntityFlareSmokeStatus
    // Description: Entity Parachute Status.
    // Parameter:   EntityFlareSmokeStatus EFSS
    //************************************
    void SetEntityFlareSmokeStatus( KDIS::DATA_TYPE::ENUMS::FlareSmokeStatus EFSS );
    KDIS::DATA_TYPE::ENUMS::FlareSmokeStatus GetEntityFlareSmokeStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::ExpendableAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityPowerPlantOn
    //              KDIS::DATA_TYPE::ExpendableAppearance::IsEntityPowerPlantOn
    // Description: Power Plant On/Off. True = On, False = Off.
    // Parameter:   KBOOL EPPS
    //************************************
    void SetEntityPowerPlantOn( KBOOL EPPS );
    KBOOL IsEntityPowerPlantOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::ExpendableAppearance::IsEntityStateActive
    // Description: Active(true) / De active(false)
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntitySpotChaffStatus
    //              KDIS::DATA_TYPE::ExpendableAppearance::GetEntitySpotChaffStatus
    // Description: Entity Parachute Status.
    // Parameter:   EntitySpotChaffStatus ESCS
    //************************************
    void SetEntitySpotChaffStatus( KDIS::DATA_TYPE::ENUMS::SpotChaff ESCS );
    KDIS::DATA_TYPE::ENUMS::SpotChaff GetEntitySpotChaffStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::SetEntityMaskedCloaked
    //              KDIS::DATA_TYPE::ExpendableAppearance::IsEntityMaskedCloaked
    // Description: Is the entity masked/cloaked or not.
    //              True = Masked/Cloaked, False = Not Masked/Cloaked.
    // Parameter:   KBOOL MC
    //************************************
    void SetEntityMaskedCloaked( KBOOL MC );
    KBOOL IsEntityMaskedCloaked() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExpendableAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const ExpendableAppearance & Value ) const;
    KBOOL operator != ( const ExpendableAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
