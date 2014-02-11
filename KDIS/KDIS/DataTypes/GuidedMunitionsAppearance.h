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

/********************************************************************
    class:      GuidedMunitionsAppearance
    created:    22/09/2008 - Updated April 2012
    author:     Karl Jones

    purpose:    Represents the appearance of a Guided Munitions.
                Implemented as struct so as to prevent the size from
                changing due to RTTI etc. This struct will be part of a
                union with all specific appearance values so it is implemented
                slightly different.
                No constructors to prevent C2620 error caused by union of
                classes/structs.
    size:       32 Bits / 4 Octet
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./Enums/KDISEnums.h"

namespace KDIS {
namespace DATA_TYPE {

struct KDIS_EXPORT GuidedMunitionsAppearance
{
protected:

    KUINT32 m_Unused1               : 3; // 0-2    
    KUINT32 m_Damage                : 2; // 3-4
    KUINT32 m_Smoke                 : 2; // 5-6
    KUINT32 m_TrailingEffect        : 2; // 7-8
	KUINT32 m_Unused2               : 6; // 9-14	
    KUINT32 m_FlamingEffectField    : 1; // 15   
	KUINT32 m_LaunchFlash           : 1; // 16
	KUINT32 m_Unused3               : 4; // 17-20    
    KUINT32 m_FrozenStatus          : 1; // 21
    KUINT32 m_PowerPlantStatus      : 1; // 22
    KUINT32 m_State                 : 1; // 23     
    KUINT32 m_Unused4               : 7; // 24-30
	KUINT32 m_MaskedCloaked         : 1; // 31

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::GetEntityDamage
    // Description: Entity Damage State
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED );
    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntitySmoke,
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::GetEntitySmoke
    // Description: Entity Smoke State
    // Parameter:   EntitySmoke ES
    //************************************
    void SetEntitySmoke( KDIS::DATA_TYPE::ENUMS::EntitySmoke ES );
    KDIS::DATA_TYPE::ENUMS::EntitySmoke GetEntitySmoke() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntityTrailingEffect
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::GetEntityTrailingEffect
    // Description: Describes the size of the dust cloud/trailing effect.
    // Parameter:   EntityTrailingEffect ETE
    //************************************
    void SetEntityTrailingEffect( KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect ETE );
    KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect GetEntityTrailingEffect() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntityFlamingEffect
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::IsEntityFlaming
    // Description: Are flames rising from the entity?
    // Parameter:   KBOOL EFE
    //************************************
    void SetEntityFlamingEffect( KBOOL EFE );
    KBOOL IsEntityFlaming() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetLaunchFlashPresent
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::IsLaunchFlashPresent
    // Description: Presence of a launch flash? True - Flash Present, False - No Flash.
    // Parameter:   KBOOL LF
    //************************************
    void SetLaunchFlashPresent( KBOOL LF );
    KBOOL IsLaunchFlashPresent() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned, they should remain 
	//              frozen in place. You would likely freeze entites when your application is
	//              in a paused state.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntityPowerPlantOn
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::IsEntityPowerPlantOn
    // Description: Power Plant On/Off. True = On, False = Off.
    // Parameter:   KBOOL EPPS
    //************************************
    void SetEntityPowerPlantOn( KBOOL EPPS );
    KBOOL IsEntityPowerPlantOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::IsEntityStateActive
    // Description: True = Active, False = Deactivated.
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::IsEntityStateActive
    // Description: Is the entity masked or cloaked? True - Masked/Cloaked, False - No Masked/Cloaked
    // Parameter:   KBOOL MC
    //************************************
    void SetMaskedCloaked( KBOOL MC );
    KBOOL IsMaskedCloaked() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const GuidedMunitionsAppearance & Value ) const;
    KBOOL operator != ( const GuidedMunitionsAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

