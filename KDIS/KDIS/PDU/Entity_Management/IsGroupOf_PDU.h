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
    class:      IsGroupOf_PDU
    DIS:        (6) 1278.1A - 1998
    created:    13:05:2009
    author:     Karl Jones

    purpose:    Contains information about a particular group of
                entities (grouped together for the purposes of
                network bandwidth reduction or aggregation).
    size:       320 bits / 40 octets - min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/GED.h"
#include "./../../Extras/KRef_Ptr.h"
#include "./../../DataTypes/GED_BasicGroundCombatVehicle.h"
#include "./../../DataTypes/GED_EnhancedGroundCombatVehicle.h"
#include "./../../DataTypes/GED_BasicGroundCombatSoldier.h"
#include "./../../DataTypes/GED_EnhancedGroundCombatSoldier.h"
#include "./../../DataTypes/GED_BasicRotorWingAircraft.h"
#include "./../../DataTypes/GED_EnhancedRotaryWingAircraft.h"
#include "./../../DataTypes/GED_BasicFixedWingAircraft.h"
#include "./../../DataTypes/GED_EnhancedFixedWingAircraft.h"
#include "./../../DataTypes/GED_GroundLogisticsVehicle.h"

namespace KDIS {

namespace DATA_TYPE {

// Some PDU specific data types.
typedef KDIS::UTILS::KRef_Ptr<GED> GEDItem;
typedef std::vector<GEDItem> GEDList;

} // END namespace DATA_TYPE

namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::GED;
using KDIS::DATA_TYPE::GEDItem;
using KDIS::DATA_TYPE::GEDList;
using KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory;

class KDIS_EXPORT IsGroupOf_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_GroupedEntityID;

    KUINT8 m_ui8GrpdEntCat;

    KUINT8 m_ui8NumOfGroupedEnts;

    KUINT32 m_ui32Padding1;

    KFLOAT64 m_f64GrpLat;

    KFLOAT64 m_f64GrpLon;

    KDIS::DATA_TYPE::GEDList m_vpGED;

public:

    static const KUINT16 IS_GROUP_OF_PDU_SIZE = 40; // Min size

    IsGroupOf_PDU();

    IsGroupOf_PDU( KDataStream & stream ) throw( KException );

    IsGroupOf_PDU( const Header & H, KDataStream & stream ) throw( KException );

    IsGroupOf_PDU( const KDIS::DATA_TYPE::EntityIdentifier & EI, KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GED, KFLOAT64 GrpLatitude, KFLOAT64 GrpLongitude );

    IsGroupOf_PDU( const KDIS::DATA_TYPE::EntityIdentifier & EI, KFLOAT64 GrpLatitude, KFLOAT64 GrpLongitude, const KDIS::DATA_TYPE::GEDList & GED ) throw( KException );

    virtual ~IsGroupOf_PDU();

    //************************************
    // FullName:    KDIS::PDU::IsGroupOf_PDU::SetGroupedEntityID
    //              KDIS::PDU::IsGroupOf_PDU::GetGroupedEntityID
    // Description: The entity that represents the group of entities.
    // Parameter:   const EntityIdentifier & EI
    //************************************
    void SetGroupedEntityID( const KDIS::DATA_TYPE::EntityIdentifier & EI );
    const KDIS::DATA_TYPE::EntityIdentifier & GetGroupedEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetGroupedEntityID();

    //************************************
    // FullName:    KDIS::PDU::IsGroupOf_PDU::SetGroupedEntityCategory
    //              KDIS::PDU::IsGroupOf_PDU::GetGroupedEntityCategory
    // Description: Describes the type of entities constituting a group.
    // Parameter:   const GroupedEntityCategor GED
    //************************************
    void SetGroupedEntityCategory( KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GED );
    KDIS::DATA_TYPE::ENUMS::GroupedEntityCategory GetGroupedEntityCategory() const;

    //************************************
    // FullName:    KDIS::PDU::IsGroupOf_PDU::GetNumberOfGroupedEntities
    // Description: Specifies the number of individual entities
    //              constituting the group.
    //************************************
    KUINT8 GetNumberOfGroupedEntities() const;

    //************************************
    // FullName:    KDIS::PDU::IsGroupOf_PDU::SetGroupReferencePoint
    //              KDIS::PDU::IsGroupOf_PDU::SetGroupReferencePointLatitude
    //              KDIS::PDU::IsGroupOf_PDU::SetGroupReferencePointLongitude
    //              KDIS::PDU::IsGroupOf_PDU::GetGroupReferencePointLatitude
    //              KDIS::PDU::IsGroupOf_PDU::GetGroupReferencePointLongitude
    // Description: Specifies the location of the group that will be used as
    //              the reference point from which the locations of all other grouped
    //              entities are based.
    //              Note: The third coordinate of the Reference Point, which will not be transmitted in the IsGroupOf
    //              PDU, is defined to be 100 m below Adjusted Mean Sea Level to compensate for the lowest surface
    //              point on the earth.
    // Parameter:   KFLOAT64 Latitude, void
    // Parameter:   KFLOAT64 Longitude, void
    //************************************
    void SetGroupReferencePoint( KFLOAT64 Latitude, KFLOAT64 Longitude );
    void SetGroupReferencePointLatitude( KFLOAT64 L );
    void SetGroupReferencePointLongitude( KFLOAT64 L );
    KFLOAT64 GetGroupReferencePointLatitude() const;
    KFLOAT64 GetGroupReferencePointLongitude() const;

    //************************************
    // FullName:    KDIS::PDU::IsGroupOf_PDU::AddGED
    //              KDIS::PDU::IsGroupOf_PDU::SetGED
    //              KDIS::PDU::IsGroupOf_PDU::GetGED
    // Description: Grouped Entity Descriptions (GEDs). This field consists of GED records
    //              that specify information about each individual entity's within
    //              the group. A GED record must be of the type specified by GroupedEntityCategory, if not an
    //              INVALID_DATA exception is thrown.
    //              Calling SetGED will change the GroupedEntityCategory to the new GED type, if the GED vector
    //              contains multiple types an INVALID_DATA exception will be thrown.
    //              Available GED are:
    //                  GED_BasicGroundCombatVehicle
    //                  GED_EnhancedGroundCombatVehicle
    //                  GED_BasicGroundCombatSoldier
    //                  GED_EnhancedGroundCombatSoldier
    //                  GED_BasicRotorWingAircraft
    //                  GED_EnhancedRotaryWingAircraft
    //                  GED_BasicFixedWingAircraft
    //                  GED_EnhancedFixedWingAircraft
    //                  GED_GroundLogisticsVehicle
    // Parameter:   const GEDItem & GED, const GEDList & GED, void
    //************************************
    void AddGED( const KDIS::DATA_TYPE::GEDItem & GED ) throw( KException );
    void SetGED( const KDIS::DATA_TYPE::GEDList & GED ) throw( KException );
    const KDIS::DATA_TYPE::GEDList & GetGED() const;

    //************************************
    // FullName:    KDIS::PDU::IsGroupOf_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::IsGroupOf_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream?
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::IsGroupOf_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IsGroupOf_PDU & Value ) const;
    KBOOL operator != ( const IsGroupOf_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
