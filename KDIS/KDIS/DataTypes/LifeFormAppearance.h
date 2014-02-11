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
    class:      LifeFormAppearance
    created:    22/09/2008 - Updated May 2012   
    author:     Karl Jones

    purpose:    Represents the appearance of a life form.
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

struct KDIS_EXPORT LifeFormAppearance
{
protected:
                                         // Bits 
    KUINT32 m_PaintScheme           : 1; // 0
    KUINT32 m_Unused1               : 2; // 1-2
    KUINT32 m_Damage                : 2; // 3-4
	KUINT32 m_Compliance            : 4; // 5-8
	KUINT32 m_Unused2               : 3; // 9-11
	KUINT32 m_Flashlight            : 1; // 12
	KUINT32 m_Unused3               : 3; // 13-15
    KUINT32 m_LifeformState         : 4; // 16-19
    KUINT32 m_Unused4               : 1; // 20
	KUINT32 m_FrozenStatus          : 1; // 21
    KUINT32 m_Unused5               : 1; // 22 
    KUINT32 m_State                 : 1; // 23
    KUINT32 m_Weapon1               : 2; // 24-25
    KUINT32 m_Weapon2               : 2; // 26-27
	KUINT32 m_Camouflage            : 2; // 28-29
	KUINT32 m_ConcealedStationary   : 1; // 30
	KUINT32 m_ConcealedMovement     : 1; // 31
	
public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityPaintScheme
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityPaintScheme
    // Description: Describes the paint scheme of an entity.
    // Parameter:   EntityPaintScheme EPS
    //************************************
    void SetEntityPaintScheme( KDIS::DATA_TYPE::ENUMS::EntityPaintScheme EPS );
    KDIS::DATA_TYPE::ENUMS::EntityPaintScheme GetEntityPaintScheme() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityDamage
    // Description: Entity Damage/Health State.
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED );
    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityEntityCompliance
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityEntityCompliance
    // Description: Describes compliance of life form.
    // Parameter:   EntityCompliance EC
    //************************************
    void SetEntityEntityCompliance( KDIS::DATA_TYPE::ENUMS::EntityCompliance EC );
    KDIS::DATA_TYPE::ENUMS::EntityCompliance GetEntityEntityCompliance() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFlashLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFlashLightsOn
    // Description: Describes whether Flash Lights are on or off. True - On. False - Off.
    // Parameter:   KBOOL FL
    //************************************
    void SetEntityFlashLights( KBOOL FL );
    KBOOL IsEntityFlashLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityLifeformState
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityLifeformState
    // Description: Entities state/appearance. I.E Posture.
    // Parameter:   EntityLifeformAppearance EA
    //************************************
    void SetEntityLifeformState( KDIS::DATA_TYPE::ENUMS::EntityLifeformAppearance EA );
    KDIS::DATA_TYPE::ENUMS::EntityLifeformAppearance GetEntityLifeformState() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntityStateActive
    // Description: Active(true) / De active(false)
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityLifeformWeapon
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityLifeformWeapon
    // Description: Weapon Status. E.G Stowed.
    // Parameter:   EntityLifeformWeapon ELW
    //************************************
    void SetEntityLifeformWeapon1( KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon ELW );
    KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon GetEntityLifeformWeapon1() const;
    void SetEntityLifeformWeapon2( KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon ELW );
    KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon GetEntityLifeformWeapon2() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityCamouflage
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityCamouflage
    // Description: camouflage type worn.
    // Parameter:   EntityCamouflage EC
    //************************************
    void SetEntityCamouflage( KDIS::DATA_TYPE::ENUMS::EntityCamouflage EC );
    KDIS::DATA_TYPE::ENUMS::EntityCamouflage GetEntityCamouflage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetConcealedStationary
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsConcealedStationary
    // Description: Describes the type of stationary concealment. 
	//              False - Not concealed. True - Entity in a prepared concealed position.
    // Parameter:   KBOOL CS
    //************************************
    void SetConcealedStationary( KBOOL CS );
    KBOOL IsConcealedStationary() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetConcealedStationary
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsConcealedStationary
    // Description: Describes the type of movement concealment. 
	//              False - Open movement. True - Rushes between covered positions.
    // Parameter:   KBOOL CM
    //************************************
    void SetConcealedMovement( KBOOL CM );
    KBOOL IsConcealedMovement() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const LifeFormAppearance & Value ) const;
    KBOOL operator != ( const LifeFormAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

