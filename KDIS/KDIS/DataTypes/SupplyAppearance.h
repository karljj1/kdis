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
    class:      SupplyAppearance
    created:    09/16/2017
    author:     Dale Marchand

    purpose:    Represents the appearance of a supply entity.
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

struct KDIS_EXPORT SupplyAppearance
{
protected:
                                       // Bits
  KUINT32 m_PaintScheme           : 1; // 0
  KUINT32 m_Unused1               : 2; // 1-2
  KUINT32 m_Damage                : 2; // 3-4
  KUINT32 m_Unused2               : 2; // 5-6
  KUINT32 m_ParachuteStatus       : 2; // 7-8
  KUINT32 m_Unused3               : 6; // 9-14
  KUINT32 m_FlamingEffectField    : 1; // 15
  KUINT32 m_Unused4               : 5; // 16-20
  KUINT32 m_FrozenStatus          : 1; // 21
  KUINT32 m_Unused5               : 1; // 22
  KUINT32 m_State                 : 1; // 23
  KUINT32 m_DeployedStatus        : 2; // 24-25
  KUINT32 m_Unused6               : 5; // 26-30
  KUINT32 m_MaskedCloaked         : 1; // 31

public:

  //************************************
  // FullName:    KDIS::DATA_TYPE::SupplyAppearance::SetEntityPaintScheme
  //              KDIS::DATA_TYPE::SupplyAppearance::GetEntityPaintScheme
  // Description: Describes the paint scheme of an entity.
  // Parameter:   EntityPaintScheme EPS
  //************************************
  void SetEntityPaintScheme( KDIS::DATA_TYPE::ENUMS::EntityPaintScheme EPS );
  KDIS::DATA_TYPE::ENUMS::EntityPaintScheme GetEntityPaintScheme() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SupplyAppearance::SetEntityDamage
  //              KDIS::DATA_TYPE::SupplyAppearance::GetEntityDamage
  // Description: Entity Damage/Health State.
  // Parameter:   EntityDamage ED
  //************************************
  void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED );
  KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SupplyAppearance::SetEntityParachuteStatus
  //              KDIS::DATA_TYPE::SupplyAppearance::GetEntityParachuteStatus
  // Description: Entity Parachute Status.
  // Parameter:   EntityParachuteStatus EPS
  //************************************
  void SetEntityParachuteStatus( KDIS::DATA_TYPE::ENUMS::Parachute EPS );
  KDIS::DATA_TYPE::ENUMS::Parachute GetEntityParachuteStatus() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SupplyAppearance::SetEntityFlamingEffect
  //              KDIS::DATA_TYPE::SupplyAppearance::IsEntityFlaming
  // Description: Are flames rising from the entity?
  // Parameter:   KBOOL EFE
  //************************************
  void SetEntityFlamingEffect( KBOOL EFE );
  KBOOL IsEntityFlaming() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SupplyAppearance::SetEntityFrozenStatus
  //              KDIS::DATA_TYPE::SupplyAppearance::IsEntityFrozen
  // Description: Is the entity frozen?
  //              Note: Frozen entities should not be dead-reckoned.
  // Parameter:   KBOOL EFS
  //************************************
  void SetEntityFrozenStatus( KBOOL EFS );
  KBOOL IsEntityFrozen() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SupplyAppearance::SetEntityStateActive
  //              KDIS::DATA_TYPE::SupplyAppearance::IsEntityStateActive
  // Description: Active(true) / De active(false)
  // Parameter:   KBOOL ES
  //************************************
  void SetEntityStateActive( KBOOL ES );
  KBOOL IsEntityStateActive() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SupplyAppearance::SetEntityDeployedStatus
  //              KDIS::DATA_TYPE::SupplyAppearance::GetEntityDeployedStatus
  // Description: Entity Parachute Status.
  // Parameter:   EntityDeployedStatus EDS
  //************************************
  void SetEntityDeployedStatus( KDIS::DATA_TYPE::ENUMS::SupplyDeployed EDS );
  KDIS::DATA_TYPE::ENUMS::SupplyDeployed GetEntityDeployedStatus() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SupplyAppearance::SetEntityMaskedCloaked
  //              KDIS::DATA_TYPE::SupplyAppearance::IsEntityMaskedCloaked
  // Description: Is the entity masked/cloaked or not.
  //              True = Masked/Cloaked, False = Not Masked/Cloaked.
  // Parameter:   KBOOL MC
  //************************************
  void SetEntityMaskedCloaked( KBOOL MC );
  KBOOL IsEntityMaskedCloaked() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SupplyAppearance::GetAsString
  // Description: Returns a string representation
  //************************************
  KString GetAsString() const;

  KBOOL operator == ( const SupplyAppearance & Value ) const;
  KBOOL operator != ( const SupplyAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
