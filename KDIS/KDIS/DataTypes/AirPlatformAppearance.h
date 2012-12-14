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
    class:      AirPlatformAppearance
    created:    22/09/2008 - Updated March 2012    
    author:     Karl Jones

    purpose:    Represents the appearance of a air platform.
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

using KDIS::DATA_TYPE::ENUMS::EntityPaintScheme;
using KDIS::DATA_TYPE::ENUMS::EntityDamage;
using KDIS::DATA_TYPE::ENUMS::EntitySmoke;
using KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect;
using KDIS::DATA_TYPE::ENUMS::EntityHatchState;

struct KDIS_EXPORT AirPlatformAppearance
{
protected:
                                         // Bits 
    KUINT32 m_PaintScheme           : 1; // 0
    KUINT32 m_MobilityKill          : 1; // 1
    KUINT32 m_Unused1               : 1; // 2
    KUINT32 m_Damage                : 2; // 3-4
    KUINT32 m_Smoke                 : 2; // 5-6
    KUINT32 m_TrailingEffect        : 2; // 7-8
    KUINT32 m_CanopyState           : 3; // 9-11
    KUINT32 m_LandingLights         : 1; // 12
	KUINT32 m_NavLights             : 1; // 13
	KUINT32 m_AntiColLights         : 1; // 14
    KUINT32 m_FlamingEffectField    : 1; // 15
    KUINT32 m_Afterburner           : 1; // 16
    KUINT32 m_Unused2               : 4; // 17-20        
    KUINT32 m_FrozenStatus          : 1; // 21
    KUINT32 m_PowerPlantStatus      : 1; // 22
    KUINT32 m_State                 : 1; // 23 
    KUINT32 m_FormationLights       : 1; // 24
    KUINT32 m_Unused3               : 3; // 25-27	
	KUINT32 m_SpotLights            : 1; // 28
	KUINT32 m_InteriorLights        : 1; // 29
	KUINT32 m_Unused4               : 2; // 30 - 31

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityPaintScheme
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityPaintScheme
    // Description: Describes the paint scheme of an entity.
    // Parameter:   EntityPaintScheme EPS
    //************************************
    void SetEntityPaintScheme( EntityPaintScheme EPS );
    EntityPaintScheme GetEntityPaintScheme() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityMobilityKill
    //              KDIS::DATA_TYPE::AirPlatformAppearance::DoesEntityMobilityKill
    // Description: Mobility/Propulsion Kill True/False?
    // Parameter:   KBOOL MK
    //************************************
    void SetEntityMobilityKill( KBOOL MK );
    KBOOL DoesEntityMobilityKill() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityDamage
    // Description: Entity Damage State
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( EntityDamage ED );
    EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntitySmoke,
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntitySmoke
    // Description: Entity Smoke State
    // Parameter:   EntitySmoke ES
    //************************************
    void SetEntitySmoke( EntitySmoke ES );
    EntitySmoke GetEntitySmoke() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityTrailingEffect
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityTrailingEffect
    // Description: Describes the size of the dust cloud/trailing effect.
    // Parameter:   EntityTrailingEffect ETE
    //************************************
    void SetEntityTrailingEffect( EntityTrailingEffect ETE );
    EntityTrailingEffect GetEntityTrailingEffect() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityCanopyState
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityCanopyState
    // Description: Is the canopy open or closed? Note: Only PrimaryHatchIsClosed
	//				or PrimaryHatchIsOpen are acceptable values when using aircraft.
    // Parameter:   EntityHatchState ECS
    //************************************
    void SetEntityCanopyState( EntityHatchState ECS );
    EntityHatchState GetEntityCanopyState() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityLandingLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityLandingLightsOn
    // Description: Are the vehicles landing lights turned on? True = On, False = Off.
    // Parameter:   KBOOL LL
    //************************************
    void SetEntityLandingLights( KBOOL LL );
    KBOOL IsEntityLandingLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityNavigationLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityNavigationLightsOn
    // Description: Are the vehicles Navigation lights turned on? True = On, False = Off.
    // Parameter:   KBOOL NL
    //************************************
    void SetEntityNavigationLights( KBOOL NL );
    KBOOL IsEntityNavigationLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityAntiCollisionLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityAntiCollisionLightsOn
    // Description: Are the vehicles Anti-Collision lights turned on? True = On, False = Off.
    // Parameter:   KBOOL ACL
    //************************************
    void SetEntityAntiCollisionLights( KBOOL ACL );
    KBOOL IsEntityAntiCollisionLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFlamingEffect
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFlaming
    // Description: Are flames rising from the entity?
    // Parameter:   KBOOL EFE
    //************************************
    void SetEntityFlamingEffect( KBOOL EFE );
    KBOOL IsEntityFlaming() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityAfterburner
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsAfterburnerOn
    // Description: Is the entity afterburner on?
    // Parameter:   KBOOL AB, void
    //************************************
    void SetEntityAfterburner( KBOOL AB );
    KBOOL IsAfterburnerOn() const;
	
	//************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned, they should remain 
	//              frozen in place. You would likely freeze entites when your application is
	//              in a paused state.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityPowerPlantOn
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityPowerPlantOn
    // Description: Power Plant On/Off. True = On, False = Off.
    // Parameter:   KBOOL EPPS
    //************************************
    void SetEntityPowerPlantOn( KBOOL EPPS );
    KBOOL IsEntityPowerPlantOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityStateActive
    // Description: True = Active, False = Deactivated.
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFormationLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFormationLightsOn
    // Description: Are the vehicles Formation lights turned on? True = On, False = Off.
    // Parameter:   KBOOL FL
    //************************************
    void SetEntityFormationLights( KBOOL FL );
    KBOOL IsEntityFormationLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityBlackoutBrakeLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityBlackoutBrakeLightsOn
    // Description: Are the vehicles spot lights turned on? True = On, False = Off.
    // Parameter:   KBOOL SL
    //************************************
    void SetEntitySpotLights( KBOOL SL );
    KBOOL IsEntitySpotLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityInteriorLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityInteriorLightsOn
    // Description: Are the vehicles interior lights turned on? True = On, False = Off.
    // Parameter:   KBOOL IL
    //************************************
    void SetEntityInteriorLights( KBOOL IL );
    KBOOL IsEntityInteriorLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const AirPlatformAppearance & Value ) const;
    KBOOL operator != ( const AirPlatformAppearance & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

