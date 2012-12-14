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
    class:      GED
    created:    07:06:2009
    author:     Karl Jones

    purpose:    Abstract class for all Grouped Entity Descriptors.

    The following derived classes exist:

                GED_BasicGroundCombatVehicle
                    GED_EnhancedGroundCombatVehicle
                GED_BasicGroundCombatSoldier
                    GED_EnhancedGroundCombatSoldier
                GED_BasicRotorWingAircraft
                    GED_EnhancedRotaryWingAircraft
                GED_BasicFixedWingAircraft
                    GED_EnhancedFixedWingAircraft
                GED_GroundLogisticsVehicle

    size:       N/A
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;

class KDIS_EXPORT GED : public DataTypeBase
{
public:

    GED( void ) {};

    virtual ~GED( void ) {};

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED::GetGroupedEntityCategory
    // Description: Identifies the derived GED class.
    //              Not part of the DIS PDU.
    //************************************
    virtual GroupedEntityCategory GetGroupedEntityCategory() const = 0;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GED::GetLength
    // Description: Returns size of the GED in octets.
    //              Not part of the DIS PDU.
    //************************************
    virtual KUINT8 GetLength() const = 0;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

