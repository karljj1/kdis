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

using KDIS::DATA_TYPE::ENUMS::EntityDamage;
using KDIS::DATA_TYPE::ENUMS::EntitySmoke;
using KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect;

struct GuidedMunitionsAppearance
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
    void SetEntityDamage( EntityDamage ED );
    EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntitySmoke,
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::GetEntitySmoke
    // Description: Entity Smoke State
    // Parameter:   EntitySmoke ES
    //************************************
    void SetEntitySmoke( EntitySmoke ES );
    EntitySmoke GetEntitySmoke() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GuidedMunitionsAppearance::SetEntityTrailingEffect
    //              KDIS::DATA_TYPE::GuidedMunitionsAppearance::GetEntityTrailingEffect
    // Description: Describes the size of the dust cloud/trailing effect.
    // Parameter:   EntityTrailingEffect ETE
    //************************************
    void SetEntityTrailingEffect( EntityTrailingEffect ETE );
    EntityTrailingEffect GetEntityTrailingEffect() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

