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
    class:      SubSurfacePlatformAppearance
    created:    22/09/2008 - Updated March 2012
    author:     Karl Jones

    purpose:    Represents the appearance of a sub surface platform.
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

struct KDIS_EXPORT SubSurfacePlatformAppearance
{
protected:

    KUINT32 m_PaintScheme           : 1; // 0
    KUINT32 m_MobilityKill          : 1; // 1
    KUINT32 m_Unused1               : 1; // 2
    KUINT32 m_Damage                : 2; // 3-4
    KUINT32 m_Smoke                 : 2; // 5-6
    KUINT32 m_Unused2               : 2; // 7-8
	KUINT32 m_HatchState            : 3; // 9-11
    KUINT32 m_RunningLights         : 1; // 12
	KUINT32 m_Unused3               : 2; // 13-14
    KUINT32 m_FlamingEffectField    : 1; // 15    
    KUINT32 m_Unused4               : 5; // 16-20        
    KUINT32 m_FrozenStatus          : 1; // 21
    KUINT32 m_PowerPlantStatus      : 1; // 22
    KUINT32 m_State                 : 1; // 23     
    KUINT32 m_Unused5               : 8; // 24-31			

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntityPaintScheme
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::GetEntityPaintScheme
    // Description: Describes the paint scheme of an entity.
    // Parameter:   EntityPaintScheme EPS
    //************************************
    void SetEntityPaintScheme( KDIS::DATA_TYPE::ENUMS::EntityPaintScheme EPS );
    KDIS::DATA_TYPE::ENUMS::EntityPaintScheme GetEntityPaintScheme() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntityMobilityKill
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::DoesEntityMobilityKill
    // Description: Mobility/Propulsion Kill True/False?
    // Parameter:   KBOOL MK
    //************************************
    void SetEntityMobilityKill( KBOOL MK );
    KBOOL DoesEntityMobilityKill() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::GetEntityDamage
    // Description: Entity Damage State
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED );
    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntitySmoke,
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::GetEntitySmoke
    // Description: Entity Smoke State
    // Parameter:   EntitySmoke ES
    //************************************
    void SetEntitySmoke( KDIS::DATA_TYPE::ENUMS::EntitySmoke ES );
    KDIS::DATA_TYPE::ENUMS::EntitySmoke GetEntitySmoke() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntityCanopyState
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::GetEntityCanopyState
    // Description: Is the hatch open or closed? Note: Only PrimaryHatchIsClosed
	//				or PrimaryHatchIsOpen are acceptable values when using aircraft.
    // Parameter:   EntityHatchState EHS
    //************************************
    void SetEntityHatchState( KDIS::DATA_TYPE::ENUMS::EntityHatchState EHS );
    KDIS::DATA_TYPE::ENUMS::EntityHatchState GetEntityHatchState() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntityRunningLights
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::IsEntityRunningLightsOn
    // Description: Are the vehicles running lights turned on? True = On, False = Off.
    // Parameter:   KBOOL RL
    //************************************
    void SetEntityRunningLights( KBOOL RL );
    KBOOL IsEntityRunningLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntityFlamingEffect
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::IsEntityFlaming
    // Description: Are flames rising from the entity?
    // Parameter:   KBOOL EFE
    //************************************
    void SetEntityFlamingEffect( KBOOL EFE );
    KBOOL IsEntityFlaming() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned, they should remain 
	//              frozen in place. You would likely freeze entites when your application is
	//              in a paused state.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntityPowerPlantOn
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::IsEntityPowerPlantOn
    // Description: Power Plant On/Off. True = On, False = Off.
    // Parameter:   KBOOL EPPS
    //************************************
    void SetEntityPowerPlantOn( KBOOL EPPS );
    KBOOL IsEntityPowerPlantOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::SubSurfacePlatformAppearance::IsEntityStateActive
    // Description: True = Active, False = Deactivated.
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SubSurfacePlatformAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const SubSurfacePlatformAppearance & Value ) const;
    KBOOL operator != ( const SubSurfacePlatformAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

