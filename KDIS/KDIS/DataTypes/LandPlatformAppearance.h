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
    class:      LandPlatformAppearance
    created:    22/09/2008 - Updated Feb 2012
    author:     Karl Jones

    purpose:    Represents the appearance of a land platform.
                Implemented as struct so as to prevent the size from
                changing due to RTTI etc. This struct will be part of a
                union with all appearance values so it is implemented
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

struct KDIS_EXPORT LandPlatformAppearance
{
protected:	
	                                     // Bits 
    KUINT32 m_PaintScheme           : 1; // 0
    KUINT32 m_MobilityKill          : 1; // 1
    KUINT32 m_FirePower             : 1; // 2
    KUINT32 m_Damage                : 2; // 3-4
    KUINT32 m_Smoke                 : 2; // 5-6
    KUINT32 m_TrailingEffect        : 2; // 7-8
    KUINT32 m_HatchState            : 3; // 9-11
    KUINT32 m_HeadLights            : 1; // 12
	KUINT32 m_TailLights            : 1; // 13
	KUINT32 m_BrakeLights           : 1; // 14
    KUINT32 m_FlamingEffectField    : 1; // 15
    KUINT32 m_Launcher              : 1; // 16
    KUINT32 m_Camouflage            : 2; // 17-18
    KUINT32 m_Concealed             : 1; // 19
    KUINT32 m_Unused                : 1; // 20 Unused
    KUINT32 m_FrozenStatus          : 1; // 21
    KUINT32 m_PowerPlantStatus      : 1; // 22
    KUINT32 m_State                 : 1; // 23 
    KUINT32 m_Tent                  : 1; // 24
    KUINT32 m_Ramp                  : 1; // 25
	KUINT32 m_BlackoutLights        : 1; // 26
	KUINT32 m_BlackoutBrakeLights   : 1; // 27
	KUINT32 m_SpotLights            : 1; // 28
	KUINT32 m_InteriorLights        : 1; // 29
	KUINT32 m_SurrenderState        : 1; // 30
	KUINT32 m_MaskedCloaked         : 1; // 31

public:

	
    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityPaintScheme
    //              KDIS::DATA_TYPE::LandPlatformAppearance::GetEntityPaintScheme
    // Description: Describes the paint scheme of an entity.
    // Parameter:   EntityPaintScheme EPS
    //************************************
    void SetEntityPaintScheme( KDIS::DATA_TYPE::ENUMS::EntityPaintScheme EPS );
    KDIS::DATA_TYPE::ENUMS::EntityPaintScheme GetEntityPaintScheme() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityMobilityKill
    //              KDIS::DATA_TYPE::LandPlatformAppearance::DoesEntityMobilityKill
    // Description: Mobility Kill True/False?
    // Parameter:   KBOOL MK
    //************************************
    void SetEntityMobilityKill( KBOOL MK );
    KBOOL DoesEntityMobilityKill() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityFirePowerKill
    //              KDIS::DATA_TYPE::LandPlatformAppearance::DoesFirePowerKill
    // Description: Does Fire Power Kill?
    // Parameter:   KBOOL FP
    //************************************
    void SetEntityFirePower( KBOOL FP );
    KBOOL DoesFirePowerKill() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::LandPlatformAppearance::GetEntityDamage
    // Description: Entity Damage State
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED );
    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntitySmoke,
    //              KDIS::DATA_TYPE::LandPlatformAppearance::GetEntitySmoke
    // Description: Entity Smoke State
    // Parameter:   EntitySmoke ES
    //************************************
    void SetEntitySmoke( KDIS::DATA_TYPE::ENUMS::EntitySmoke ES );
    KDIS::DATA_TYPE::ENUMS::EntitySmoke GetEntitySmoke() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityTrailingEffect
    //              KDIS::DATA_TYPE::LandPlatformAppearance::GetEntityTrailingEffect
    // Description: Describes the size of the dust cloud/trailing effect.
    // Parameter:   EntityTrailingEffect ETE
    //************************************
    void SetEntityTrailingEffect( KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect ETE );
    KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect GetEntityTrailingEffect() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityHatchState
    //              KDIS::DATA_TYPE::LandPlatformAppearance::GetEntityHatchState
    // Description: Entity primary hatch state. Open, closed etc.
    // Parameter:   EntityHatchState EHS
    //************************************
    void SetEntityHatchState( KDIS::DATA_TYPE::ENUMS::EntityHatchState EHS );
    KDIS::DATA_TYPE::ENUMS::EntityHatchState GetEntityHatchState() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityHeadLights
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityHeadLightsOn
    // Description: Are the vehicles head lights turned on? True = On, False = Off.
    // Parameter:   KBOOL HL
    //************************************
    void SetEntityHeadLights( KBOOL HL );
    KBOOL IsEntityHeadLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityHeadLights
    //              KDIS::DATA_TYPE::LandPlatformAppearance::GetEntityLights
    // Description: Are the vehicles tail lights turned on? True = On, False = Off.
    // Parameter:   KBOOL TL
    //************************************
    void SetEntityTailLights( KBOOL TL );
    KBOOL IsEntityTailLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityBrakeLights
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityBrakeLightsOn
    // Description: Are the vehicles brake lights turned on? True = On, False = Off.
    // Parameter:   KBOOL BL
    //************************************
    void SetEntityBrakeLights( KBOOL BL );
    KBOOL IsEntityBrakeLightsOn() const;
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityFlamingEffect
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityFlaming
    // Description: Are flames rising from the entity?
    // Parameter:   KBOOL EFE
    //************************************
    void SetEntityFlamingEffect( KBOOL EFE );
    KBOOL IsEntityFlaming() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityLauncher
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityLauncherRaised
    // Description: Set launcher status. False = Not Raised, True = Raised.
    // Parameter:   KBOOL EL
    //************************************
    void SetEntityLauncher( KBOOL EL );
    KBOOL IsEntityLauncherRaised() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityCamouflage
    //              KDIS::DATA_TYPE::LandPlatformAppearance::GetEntityCamouflage
    // Description: Camouflage type worn.
    // Parameter:   EntityCamouflage EC
    //************************************
    void SetEntityCamouflage( KDIS::DATA_TYPE::ENUMS::EntityCamouflage EC );
    KDIS::DATA_TYPE::ENUMS::EntityCamouflage GetEntityCamouflage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityConcealed
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityConcealed
    // Description: Is the entity concealed? 
	//              False = Not concealed. True = Entity in a prepared concealed
	//              position (with netting, etc.)
    // Parameter:   KBOOL EC
    //************************************
    void SetEntityConcealed( KBOOL EC );
    KBOOL IsEntityConcealed() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned, they should remain 
	//              frozen in place. You would likely freeze entites when your application is
	//              in a paused state.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityPowerPlantOn
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityPowerPlantOn
    // Description: Power Plant On/Off. True = On, False = Off.
    // Parameter:   KBOOL EPPS
    //************************************
    void SetEntityPowerPlantOn( KBOOL EPPS );
    KBOOL IsEntityPowerPlantOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityStateActive
    // Description: True = Active, False = Deactivated.
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityTentExtended
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityTentExtended
    // Description: Tent status. True = Not extended, False = Extended.
    // Parameter:   KBOOL ET
    //************************************
    void SetEntityTentExtended( KBOOL ET );
    KBOOL IsEntityTentExtended() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityRampDown
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityRampDown
    // Description: Ramp Status. Up / Down. True = Down, False = Up.
    // Parameter:   KBOOL ER
    //************************************
    void SetEntityRampDown( KBOOL ER );
    KBOOL IsEntityRampDown() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityBlackoutLights
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityBlackoutLightsOn
    // Description: Are the vehicles blackout lights turned on? True = On, False = Off.
    // Parameter:   KBOOL BL
    //************************************
    void SetEntityBlackoutLights( KBOOL BL );
    KBOOL IsEntityBlackoutLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityBlackoutBrakeLights
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityBlackoutBrakeLightsOn
    // Description: Are the vehicles blackout brake lights turned on? True = On, False = Off.
    // Parameter:   KBOOL BBL
    //************************************
    void SetEntityBlackoutBrakeLights( KBOOL BBL );
    KBOOL IsEntityBlackoutBrakeLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityBlackoutBrakeLights
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityBlackoutBrakeLightsOn
    // Description: Are the vehicles spot lights turned on? True = On, False = Off.
    // Parameter:   KBOOL SL
    //************************************
    void SetEntitySpotLights( KBOOL SL );
    KBOOL IsEntitySpotLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntityInteriorLights
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityInteriorLightsOn
    // Description: Are the vehicles interior lights turned on? True = On, False = Off.
    // Parameter:   KBOOL IL
    //************************************
    void SetEntityInteriorLights( KBOOL IL );
    KBOOL IsEntityInteriorLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntitySurrdenderState
    //              KDIS::DATA_TYPE::LandPlatformAppearance::HasEntitySurrendered
    // Description: Has the vehicle occupant surrendered? 
	//              True = Surrendered, False = Not Surrendered.
    // Parameter:   KBOOL SS
    //************************************
    void SetEntitySurrdenderState( KBOOL SS );
    KBOOL HasEntitySurrendered() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::SetEntitySurrdenderState
    //              KDIS::DATA_TYPE::LandPlatformAppearance::IsEntityMaskedCloaked
    // Description: Is the entity masked/cloaked or not. 
	//              True = Masked/Cloaked, False = Not Masked/Cloaked.
    // Parameter:   KBOOL MC
    //************************************
    void SetEntityMaskedCloaked( KBOOL MC );
    KBOOL IsEntityMaskedCloaked() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LandPlatformAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const LandPlatformAppearance & Value ) const;
    KBOOL operator != ( const LandPlatformAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

