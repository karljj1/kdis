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
    class:      CulturalFeatureAppearance
    created:    08/08/2012
    author:     Karl Jones

    purpose:    Represents the appearance of a cultural feature.
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

struct KDIS_EXPORT CulturalFeatureAppearance
{
protected:	
	                                     // Bits 
    KUINT32 m_Unused1               : 3; // 0-2   
    KUINT32 m_Damage                : 2; // 3-4
    KUINT32 m_Smoke                 : 2; // 5-6
    KUINT32 m_Unused2               : 8; // 7-14    
    KUINT32 m_FlamingEffectField    : 1; // 15
    KUINT32 m_Unused3               : 5; // 16-20    
    KUINT32 m_FrozenStatus          : 1; // 21
    KUINT32 m_InternalHeatStatus    : 1; // 22
    KUINT32 m_State                 : 1; // 23 
    KUINT32 m_Unused4               : 4; // 24-27    
	KUINT32 m_ExteriorLights        : 1; // 28
	KUINT32 m_InteriorLights        : 1; // 29
	KUINT32 m_Unused5               : 1; // 30
	KUINT32 m_MaskedCloaked         : 1; // 31

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::CulturalFeatureAppearance::GetEntityDamage
    // Description: Entity Damage State
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED );
    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::SetEntitySmoke,
    //              KDIS::DATA_TYPE::CulturalFeatureAppearance::GetEntitySmoke
    // Description: Entity Smoke State
    // Parameter:   EntitySmoke ES
    //************************************
    void SetEntitySmoke( KDIS::DATA_TYPE::ENUMS::EntitySmoke ES );
    KDIS::DATA_TYPE::ENUMS::EntitySmoke GetEntitySmoke() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::SetEntityFlamingEffect
    //              KDIS::DATA_TYPE::CulturalFeatureAppearance::IsEntityFlaming
    // Description: Are flames rising from the entity?
    // Parameter:   KBOOL EFE
    //************************************
    void SetEntityFlamingEffect( KBOOL EFE );
    KBOOL IsEntityFlaming() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::CulturalFeatureAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned, they should remain 
	//              frozen in place. You would likely freeze entites when your application is
	//              in a paused state.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::SetInternalHeatStatusOn
    //              KDIS::DATA_TYPE::CulturalFeatureAppearance::IsInternalHeatOn
    // Description: Is the feature emitting internal heat?
    // Parameter:   KBOOL IHS
    //************************************
    void SetInternalHeatStatusOn( KBOOL IHS );
    KBOOL IsInternalHeatOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::CulturalFeatureAppearance::IsEntityStateActive
    // Description: True = Active, False = Deactivated.
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::SetEntityExteriorLights
    //              KDIS::DATA_TYPE::CulturalFeatureAppearance::IsEntityExteriorLightsOn
    // Description: Are the exterior lights turned on? True = On, False = Off.
    // Parameter:   KBOOL EL
    //************************************
    void SetEntityExteriorLights( KBOOL EL );
    KBOOL IsEntityExteriorLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::SetEntityInteriorLights
    //              KDIS::DATA_TYPE::CulturalFeatureAppearance::IsEntityInteriorLightsOn
    // Description: Are the vehicles interior lights turned on? True = On, False = Off.
    // Parameter:   KBOOL IL
    //************************************
    void SetEntityInteriorLights( KBOOL IL );
    KBOOL IsEntityInteriorLightsOn() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::SetEntitySurrdenderState
    //              KDIS::DATA_TYPE::CulturalFeatureAppearance::IsEntityMaskedCloaked
    // Description: Is the entity masked/cloaked or not. 
	//              True = Masked/Cloaked, False = Not Masked/Cloaked.
    // Parameter:   KBOOL MC
    //************************************
    void SetEntityMaskedCloaked( KBOOL MC );
    KBOOL IsEntityMaskedCloaked() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CulturalFeatureAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const CulturalFeatureAppearance & Value ) const;
    KBOOL operator != ( const CulturalFeatureAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

