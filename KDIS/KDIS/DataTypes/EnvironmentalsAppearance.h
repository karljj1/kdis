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
    class:      EnvironmentalsAppearance
    created:    22/09/2008 - Updated May 2012
    author:     Karl Jones

    purpose:    Represents the appearance of the Enviromentals.
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

using KDIS::DATA_TYPE::ENUMS::EntityDensity;

struct KDIS_EXPORT EnvironmentalsAppearance
{
protected:

    KUINT32 m_Unused1               : 16; // 0-15
    KUINT32 m_Density               : 4;  // 16-19  
	KUINT32 m_Unused2               : 1;  // 20 - This bit is assumed to be unused, in the standard it is unaccounted for. (SISO-EBV-REF-010-2006)
	KUINT32 m_FrozenStatus          : 1;  // 21
    KUINT32 m_Unused3               : 1;  // 22 
    KUINT32 m_State                 : 1;  // 23
	KUINT32 m_Unused4               : 7;  // 24-30
    KUINT32 m_MaskedCloaked         : 1;  // 31

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentalsAppearance::SetEntityDensity
    //              KDIS::DATA_TYPE::EnvironmentalsAppearance::GetEntityDensity
    // Description: Describes the density of the environmentals.
    // Parameter:   EntityDensity ED
    //************************************
    void SetEntityDensity( EntityDensity ED );
    EntityDensity GetEntityDensity() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentalsAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::EnvironmentalsAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned, they should remain 
	//              frozen in place. You would likely freeze entites when your application is
	//              in a paused state.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS );
    KBOOL IsEntityFrozen() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentalsAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::EnvironmentalsAppearance::IsEntityStateActive
    // Description: Active(true) / De active(false)
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES );
    KBOOL IsEntityStateActive() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentalsAppearance::SetEntitySurrdenderState
    //              KDIS::DATA_TYPE::EnvironmentalsAppearance::IsEntityMaskedCloaked
    // Description: Is the entity masked/cloaked or not. 
	//              True = Masked/Cloaked, False = Not Masked/Cloaked.
    // Parameter:   KBOOL MC
    //************************************
    void SetEntityMaskedCloaked( KBOOL MC );
    KBOOL IsEntityMaskedCloaked() const;
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentalsAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const EnvironmentalsAppearance & Value ) const;
    KBOOL operator != ( const EnvironmentalsAppearance & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

