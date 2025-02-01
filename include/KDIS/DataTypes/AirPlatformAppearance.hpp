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

#include "KDIS/DataTypes/Enums/KDISEnums.hpp"
#include "KDIS/KDefines.hpp"

namespace KDIS {
namespace DATA_TYPE {

struct KDIS_EXPORT AirPlatformAppearance {
 protected:
  // Bits
  KUINT32 m_PaintScheme : 1;                   // 0
  KUINT32 m_MobilityKill : 1;                  // 1
  KUINT32 m_NVGMode : 1;                       // 2
  KUINT32 m_Damage : 2;                        // 3-4
  KUINT32 m_Smoke : 2;                         // 5-6
  KUINT32 m_TrailingEffect : 2;                // 7-8
  KUINT32 m_CanopyState : 3;                   // 9-11
  KUINT32 m_LandingLights : 1;                 // 12
  KUINT32 m_NavLights : 1;                     // 13
  KUINT32 m_AntiColLights : 1;                 // 14
  KUINT32 m_FlamingEffectField : 1;            // 15
  KUINT32 m_Afterburner : 1;                   // 16
  KUINT32 m_LowerAntiCollisionLight : 1;       // 17
  KUINT32 m_UpperAntiCollisionLight : 1;       // 18
  KUINT32 m_AntiCollisionLightDayNight : 1;    // 19
  KUINT32 m_IsBlinking : 1;                    // 20
  KUINT32 m_FrozenStatus : 1;                  // 21
  KUINT32 m_PowerPlantStatus : 1;              // 22
  KUINT32 m_State : 1;                         // 23
  KUINT32 m_FormationLights : 1;               // 24
  KUINT32 m_LandingGearExtended : 1;           // 25
  KUINT32 m_CargoDoorsOpened : 1;              // 26
  KUINT32 m_NavigationPositionBrightness : 1;  // 27
  KUINT32 m_SpotLights : 1;                    // 28
  KUINT32 m_InteriorLights : 1;                // 29
  KUINT32 m_ReverseThrustEngaged : 1;          // 30
  KUINT32 m_WeightOnWheels : 1;                // 31

 public:
  AirPlatformAppearance();

  ~AirPlatformAppearance() = default;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityPaintScheme
  //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityPaintScheme
  // Description: Describes the paint scheme of an entity.
  // Parameter:   EntityPaintScheme EPS
  //************************************
  void SetEntityPaintScheme(KDIS::DATA_TYPE::ENUMS::EntityPaintScheme EPS);
  KDIS::DATA_TYPE::ENUMS::EntityPaintScheme GetEntityPaintScheme() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityMobilityKill
  //              KDIS::DATA_TYPE::AirPlatformAppearance::DoesEntityMobilityKill
  // Description: Mobility/Propulsion Kill True/False?
  // Parameter:   KBOOL MK
  //************************************
  void SetEntityMobilityKill(KBOOL MK);
  KBOOL DoesEntityMobilityKill() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetNVGMode
  //              KDIS::DATA_TYPE::AirPlatformAppearance::GetNVGMode
  // Description: NVG Lighting Mode.
  // Parameter:   NVGMode NM
  //************************************
  void SetNVGMode(KDIS::DATA_TYPE::ENUMS::NVGMode NM);
  KDIS::DATA_TYPE::ENUMS::NVGMode GetNVGMode() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityDamage
  //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityDamage
  // Description: Entity Damage State
  // Parameter:   EntityDamage ED
  //************************************
  void SetEntityDamage(KDIS::DATA_TYPE::ENUMS::EntityDamage ED);
  KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntitySmoke,
  //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntitySmoke
  // Description: Entity Smoke State
  // Parameter:   EntitySmoke ES
  //************************************
  void SetEntitySmoke(KDIS::DATA_TYPE::ENUMS::EntitySmoke ES);
  KDIS::DATA_TYPE::ENUMS::EntitySmoke GetEntitySmoke() const;

  //************************************
  // FullName: KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityTrailingEffect
  //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityTrailingEffect
  // Description: Describes the size of the dust cloud/trailing effect.
  // Parameter:   EntityTrailingEffect ETE
  //************************************
  void SetEntityTrailingEffect(
      KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect ETE);
  KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect GetEntityTrailingEffect() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityCanopyState
  //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityCanopyState
  // Description: Is the canopy open or closed? Note: Only PrimaryHatchIsClosed
  //              or PrimaryHatchIsOpen are acceptable values when using
  //              aircraft.
  // Parameter:   EntityHatchState ECS
  //************************************
  void SetEntityCanopyState(KDIS::DATA_TYPE::ENUMS::EntityHatchState ECS);
  KDIS::DATA_TYPE::ENUMS::EntityHatchState GetEntityCanopyState() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityLandingLights
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityLandingLightsOn
  // Description: Are the vehicles landing lights turned on? True = On, False =
  // Off. Parameter:   KBOOL LL
  //************************************
  void SetEntityLandingLights(KBOOL LL);
  KBOOL IsEntityLandingLightsOn() const;

  //************************************
  // FullName: KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityNavigationLights
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityNavigationLightsOn
  // Description: Are the vehicles Navigation lights turned on? True = On, False
  // = Off. Parameter:   KBOOL NL
  //************************************
  void SetEntityNavigationLights(KBOOL NL);
  KBOOL IsEntityNavigationLightsOn() const;

  //************************************
  // FullName:
  // KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityAntiCollisionLights
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityAntiCollisionLightsOn
  // Description: Are the vehicles Anti-Collision lights turned on? True = On,
  // False = Off. Parameter:   KBOOL ACL
  //************************************
  void SetEntityAntiCollisionLights(KBOOL ACL);
  KBOOL IsEntityAntiCollisionLightsOn() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFlamingEffect
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFlaming
  // Description: Are flames rising from the entity?
  // Parameter:   KBOOL EFE
  //************************************
  void SetEntityFlamingEffect(KBOOL EFE);
  KBOOL IsEntityFlaming() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityAfterburner
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsAfterburnerOn
  // Description: Is the entity afterburner on?
  // Parameter:   KBOOL AB, void
  //************************************
  void SetEntityAfterburner(KBOOL AB);
  KBOOL IsAfterburnerOn() const;

  //************************************
  // FullName:
  // KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityLowerAntiCollisionLight
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityLowerAntiCollisionLightOn
  // Description: Is the vehicles lower anti-collision light turned on? True =
  // On, False = Off. Parameter:   KBOOL LACL
  //************************************
  void SetEntityLowerAntiCollisionLight(KBOOL LACL);
  KBOOL IsEntityLowerAntiCollisionLightOn() const;

  //************************************
  // FullName:
  // KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityUpperAntiCollisionLight
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityUpperAntiCollisionLightOn
  // Description: Is the vehicles lower anti-collision light turned on? True =
  // On, False = Off. Parameter:   KBOOL UACL
  //************************************
  void SetEntityUpperAntiCollisionLight(KBOOL UACL);
  KBOOL IsEntityUpperAntiCollisionLightOn() const;

  //************************************
  // FullName:
  // KDIS::DATA_TYPE::AirPlatformAppearance::SetAntiCollisionLightDayNight
  //              KDIS::DATA_TYPE::AirPlatformAppearance::GetAntiCollisionLightDayNight
  // Description: Anti-Collision Light Day/Night.
  // Parameter:   AntiCollisionDayNight ACDN
  //************************************
  void SetAntiCollisionLightDayNight(
      KDIS::DATA_TYPE::ENUMS::AntiCollisionDayNight ACDN);
  KDIS::DATA_TYPE::ENUMS::AntiCollisionDayNight GetAntiCollisionLightDayNight()
      const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetBlinking
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsBlinking
  // Description: Are any lights blinking?
  // Parameter:   KBOOL EFS
  //***********************************?
  void SetBlinking(KBOOL B);
  KBOOL IsBlinking() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFrozenStatus
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFrozen
  // Description: Is the entity frozen?
  //              Note: Frozen entities should not be dead-reckoned, they should
  //              remain frozen in place. You would likely freeze entites when
  //              your application is in a paused state.
  // Parameter:   KBOOL EFS
  //************************************
  void SetEntityFrozenStatus(KBOOL EFS);
  KBOOL IsEntityFrozen() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityPowerPlantOn
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityPowerPlantOn
  // Description: Power Plant On/Off. True = On, False = Off.
  // Parameter:   KBOOL EPPS
  //************************************
  void SetEntityPowerPlantOn(KBOOL EPPS);
  KBOOL IsEntityPowerPlantOn() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityStateActive
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityStateActive
  // Description: True = Active, False = Deactivated.
  // Parameter:   KBOOL ES
  //************************************
  void SetEntityStateActive(KBOOL ES);
  KBOOL IsEntityStateActive() const;

  //************************************
  // FullName: KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFormationLights
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFormationLightsOn
  // Description: Are the vehicles Formation lights turned on? True = On, False
  // = Off. Parameter:   KBOOL FL
  //************************************
  void SetEntityFormationLights(KBOOL FL);
  KBOOL IsEntityFormationLightsOn() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetLandingGearExtended
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsLandingGearExtended
  // Description: Is the landing gear extended or wholly retracted?
  // Parameter:   KBOOL LGE
  //***********************************?
  void SetLandingGearExtended(KBOOL LGE);
  KBOOL IsLandingGearExtended() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetCargoDoorsOpened
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsCargoDoorsOpened
  // Description: Is the cargo door (main door) open?
  // Parameter:   KBOOL LGE
  //***********************************?
  void SetCargoDoorsOpened(KBOOL CDO);
  KBOOL IsCargoDoorsOpened() const;

  //************************************
  // FullName:
  // KDIS::DATA_TYPE::AirPlatformAppearance::SetNavigationPositionBrightness
  //              KDIS::DATA_TYPE::AirPlatformAppearance::GetNavigationPositionBrightness
  // Description: Brightness of the navigation/position lights
  // Parameter:   KDIS::DATA_TYPE::ENUMS::NavigationnPositionBrightness NPB
  //***********************************?
  void SetNavigationPositionBrightness(
      KDIS::DATA_TYPE::ENUMS::NavigationPositionBrightness NPB);
  KDIS::DATA_TYPE::ENUMS::NavigationPositionBrightness
  GetNavigationPositionBrightness() const;

  //************************************
  // FullName:
  // KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityBlackoutBrakeLights
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityBlackoutBrakeLightsOn
  // Description: Are the vehicles spot lights turned on? True = On, False =
  // Off. Parameter:   KBOOL SL
  //************************************
  void SetEntitySpotLights(KBOOL SL);
  KBOOL IsEntitySpotLightsOn() const;

  //************************************
  // FullName: KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityInteriorLights
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityInteriorLightsOn
  // Description: Are the vehicles interior lights turned on? True = On, False =
  // Off. Parameter:   KBOOL IL
  //************************************
  void SetEntityInteriorLights(KBOOL IL);
  KBOOL IsEntityInteriorLightsOn() const;

  //************************************
  // FullName: KDIS::DATA_TYPE::AirPlatformAppearance::SetReverseThrustEngaged
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsReverseThrustEngaged
  // Description: Is reverse thrust engaged?
  // Parameter:   KBOOL RTE
  //************************************
  void SetReverseThrustEngaged(KBOOL RTE);
  KBOOL IsReverseThrustEngaged() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetWeightOnWheels
  //              KDIS::DATA_TYPE::AirPlatformAppearance::IsWeightOnWheels
  // Description: Is weight on the main landing gear?
  // Parameter:   KBOOL RTE
  //************************************
  void SetWeightOnWheels(KBOOL WOW);
  KBOOL IsWeightOnWheels() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::GetAsString
  // Description: Returns a string representation
  //************************************
  KString GetAsString() const;

  KBOOL operator==(const AirPlatformAppearance& Value) const;
  KBOOL operator!=(const AirPlatformAppearance& Value) const;
};

}  // namespace DATA_TYPE
}  // END namespace KDIS
