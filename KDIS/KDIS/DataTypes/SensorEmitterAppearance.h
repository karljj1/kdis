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
    class:      SensorEmitterAppearance
    created:    08/08/2012
    author:     Karl Jones

    purpose:    Represents the appearance of a sensor/emitter.
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

struct KDIS_EXPORT SensorEmitterAppearance
{
protected:	
	                                     // Bits 
    KUINT32 m_PaintScheme           : 1; // 0
    KUINT32 m_MobilityKill          : 1; // 1
    KUINT32 m_Mission               : 1; // 2
    KUINT32 m_Damage                : 2; // 3-4
    KUINT32 m_Smoke                 : 2; // 5-6
    KUINT32 m_TrailingEffect        : 2; // 7-8
    KUINT32 m_Unused1               : 3; // 9-11
    KUINT32 m_Lights                : 1; // 12
	KUINT32 m_Unused2               : 2; // 13-14	
    KUINT32 m_FlamingEffectField    : 1; // 15
    KUINT32 m_Antenna               : 1; // 16
    KUINT32 m_Camouflage            : 2; // 17-18
    KUINT32 m_Concealed             : 1; // 19
    KUINT32 m_Unused                : 1; // 20 Unused
    KUINT32 m_FrozenStatus          : 1; // 21
    KUINT32 m_PowerPlantStatus      : 1; // 22
    KUINT32 m_State                 : 1; // 23 
    KUINT32 m_Tent                  : 1; // 24
    KUINT32 m_Unused3               : 1; // 25
	KUINT32 m_BlackoutLights        : 1; // 26
	KUINT32 m_Unused4               : 2; // 27-28	
	KUINT32 m_InteriorLights        : 1; // 29
	KUINT32 m_Unused5               : 2; // 30-31	

public:

	//************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityPaintScheme
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::GetEntityPaintScheme
    // Description: Describes the paint scheme of an entity.
    // Parameter:   EntityPaintScheme EPS
    //************************************
    void SetEntityPaintScheme( KDIS::DATA_TYPE::ENUMS::EntityPaintScheme EPS );
    KDIS::DATA_TYPE::ENUMS::EntityPaintScheme GetEntityPaintScheme() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityMobilityKill
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::DoesEntityMobilityKill
    // Description: Mobility Kill True/False?
    // Parameter:   KBOOL MK
    //************************************
    void SetEntityMobilityKill( KBOOL MK );
    KBOOL DoesEntityMobilityKill() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetMissionKill
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::HasMissionKill
    // Description: Describes characteristics of mission kill (e.g. damaged antenna).
	//	            False - No mission kill  
	//              True -  Mission kill
    // Parameter:   KBOOL MK
    //************************************
    void SetMissionKill( KBOOL MK );
    KBOOL HasMissionKill() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::GetEntityDamage
    // Description: Entity Damage State
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED );
    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntitySmoke,
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::GetEntitySmoke
    // Description: Entity Smoke State
    // Parameter:   EntitySmoke ES
    //************************************
    void SetEntitySmoke( KDIS::DATA_TYPE::ENUMS::EntitySmoke ES );
    KDIS::DATA_TYPE::ENUMS::EntitySmoke GetEntitySmoke() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityTrailingEffect
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::GetEntityTrailingEffect
    // Description: Describes the size of the dust cloud/trailing effect.
    // Parameter:   EntityTrailingEffect ETE
    //************************************
    void SetEntityTrailingEffect( KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect ETE );
    KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect GetEntityTrailingEffect() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityHeadLights
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityHeadLightsOn
    // Description: Are the vehicles head lights turned on? True = On, False = Off.
    // Parameter:   KBOOL HL
    //************************************
    void SetEntityHeadLights( KBOOL HL );
    KBOOL IsEntityHeadLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SeLights
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsLightsOn
    // Description: Are the sensors lights turned on? True = On, False = Off.
    // Parameter:   KBOOL L
    //************************************
    void SeLights( KBOOL L );
    KBOOL IsLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityFlamingEffect
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityFlaming
    // Description: Are flames rising from the entity?
    // Parameter:   KBOOL EFE
    //************************************
    void SetEntityFlamingEffect( KBOOL EFE );
    KBOOL IsEntityFlaming() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetAntennaRaised
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsAntennaRaised
    // Description: Sensor antenna raised status. False = Not Raised, True = Raised.
    // Parameter:   KBOOL EL
    //************************************
    void SetAntennaRaised( KBOOL AR );
    KBOOL IsAntennaRaised() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityCamouflage
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::GetEntityCamouflage
    // Description: Camouflage type worn.
    // Parameter:   EntityCamouflage EC
    //************************************
    void SetEntityCamouflage( KDIS::DATA_TYPE::ENUMS::EntityCamouflage EC );
    KDIS::DATA_TYPE::ENUMS::EntityCamouflage GetEntityCamouflage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityConcealed
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityConcealed
    // Description: Is the entity concealed? 
	//              False = Not concealed. True = Entity in a prepared concealed
	//              position (with netting, etc.)
    // Parameter:   KBOOL EC
    //************************************
    void SetEntityConcealed( KBOOL EC );
    KBOOL IsEntityConcealed() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned, they should remain 
	//              frozen in place. You would likely freeze entites when your application is
	//              in a paused state.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityPowerPlantOn
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityPowerPlantOn
    // Description: Power Plant On/Off. True = On, False = Off.
    // Parameter:   KBOOL EPPS
    //************************************
    void SetEntityPowerPlantOn( KBOOL EPPS );
    KBOOL IsEntityPowerPlantOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityStateActive
    // Description: True = Active, False = Deactivated.
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityTentExtended
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityTentExtended
    // Description: Tent status. True = Not extended, False = Extended.
    // Parameter:   KBOOL ET
    //************************************
    void SetEntityTentExtended( KBOOL ET );
    KBOOL IsEntityTentExtended() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityBlackoutLights
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityBlackoutLightsOn
    // Description: Are the vehicles blackout lights turned on? True = On, False = Off.
    // Parameter:   KBOOL BL
    //************************************
    void SetEntityBlackoutLights( KBOOL BL );
    KBOOL IsEntityBlackoutLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityBlackoutBrakeLights
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityBlackoutBrakeLightsOn
    // Description: Are the vehicles blackout brake lights turned on? True = On, False = Off.
    // Parameter:   KBOOL BBL
    //************************************
    void SetEntityBlackoutBrakeLights( KBOOL BBL );
    KBOOL IsEntityBlackoutBrakeLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::SetEntityInteriorLights
    //              KDIS::DATA_TYPE::SensorEmitterAppearance::IsEntityInteriorLightsOn
    // Description: Are the vehicles interior lights turned on? True = On, False = Off.
    // Parameter:   KBOOL IL
    //************************************
    void SetEntityInteriorLights( KBOOL IL );
    KBOOL IsEntityInteriorLightsOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SensorEmitterAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const SensorEmitterAppearance & Value ) const;
    KBOOL operator != ( const SensorEmitterAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

