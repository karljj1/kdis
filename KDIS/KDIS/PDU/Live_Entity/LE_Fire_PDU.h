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
    class:      LE_Fire_PDU
    DIS:        (6) 1278.1a - 1998
    created:    20/08/2010
    author:     Karl Jones

    purpose:
    size:       280 bits / 35 octets - Min size
*********************************************************************/

#pragma once

#include "./LE_Header.h"
#include "./../../DataTypes/RelativeWorldCoordinates.h"
#include "./../../DataTypes/BurstDescriptor.h"
#include "./../../DataTypes/RelativeWorldCoordinates.h"
#include "./../../DataTypes/LE_Vector.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::RelativeWorldCoordinates;
using KDIS::DATA_TYPE::BurstDescriptor;
using KDIS::DATA_TYPE::RelativeWorldCoordinates;
using KDIS::DATA_TYPE::LE_Vector16_3;

class KDIS_EXPORT LE_Fire_PDU : public LE_Header
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8TargetId        : 1;
            KUINT8 m_ui8MunitionSiteApp : 1;
            KUINT8 m_ui8MunitionId      : 1;
            KUINT8 m_ui8EventSiteAppId  : 1;
            KUINT8 m_ui8WarheadFuse     : 1;
            KUINT8 m_ui8QuantRate       : 1;
            KUINT8 m_ui8Location        : 1;
            KUINT8 m_ui8Reserved        : 1;
        };
        KUINT8 m_ui8Flag;
    } m_FireFlagUnion;

    LE_EntityIdentifier m_TargetID;

    LE_EntityIdentifier m_MunitionID;

    LE_EntityIdentifier m_EventID;

    BurstDescriptor m_MunitionDesc;

    RelativeWorldCoordinates m_Loc;

    LE_Vector16_3 m_Vel;

    KUINT16 m_ui16Range;

    //************************************
    // FullName:    KDIS::PDU::LE_Header::checkSiteApplicationFlags
    // Description: Checks the site and application values to see if we need to include them during
    //              encoding. The values are set when the set id functions are called however it is
    //              possible that a change may have occurred since, I.E by calling the GetID function
    //              and setting through it.
    //************************************
    void checkSiteApplicationFlags();

public:

    static const KUINT16 LE_FIRE_PDU_SIZE = 35; // Min size, not including optional fields

    LE_Fire_PDU( void );

    LE_Fire_PDU( const LE_EntityIdentifier & ID );

    LE_Fire_PDU( KDataStream & stream ) throw( KException );

    virtual ~LE_Fire_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::SetTargetEntityIDFlag
    //              KDIS::PDU::LE_Fire_PDU::GetTargetEntityIDFlag
    //              KDIS::PDU::LE_Fire_PDU::SetMunitionEntityIDFlag
    //              KDIS::PDU::LE_Fire_PDU::GetMunitionEntityIDFlag
    //              KDIS::PDU::LE_Fire_PDU::SetMunitionEntityIDSiteAppIncludedFlag
    //              KDIS::PDU::LE_Fire_PDU::GetMunitionEntityIDSiteAppIncludedFlag
    //              KDIS::PDU::LE_Fire_PDU::SetEventIDSiteAppIncludedFlag
    //              KDIS::PDU::LE_Fire_PDU::GetEventIDSiteAppIncludedFlag
    //              KDIS::PDU::LE_Fire_PDU::SetWarheadFuseFlag
    //              KDIS::PDU::LE_Fire_PDU::GetWarheadFuseFlag
    //              KDIS::PDU::LE_Fire_PDU::SetQuantityRateFlag
    //              KDIS::PDU::LE_Fire_PDU::GetQuantityRateFlag
    //              KDIS::PDU::LE_Fire_PDU::SetLocationFlag
    //              KDIS::PDU::LE_Fire_PDU::GetLocationFlag
    // Description: Identifies optional data fields that are being transmitted with
    //              this PDU.
    // Parameter:   KBOOL F
    //************************************
    void SetTargetEntityIDFlag( KBOOL F );
    KBOOL GetTargetEntityIDFlag() const;
    void SetMunitionEntityIDFlag( KBOOL F );
    KBOOL GetMunitionEntityIDFlag() const;
    void SetMunitionEntityIDSiteAppIncludedFlag( KBOOL F );
    KBOOL GetMunitionEntityIDSiteAppIncludedFlag() const;
    void SetEventIDSiteAppIncludedFlag( KBOOL F );
    KBOOL GetEventIDSiteAppIncludedFlag() const;
    void SetWarheadFuseFlag( KBOOL F );
    KBOOL GetWarheadFuseFlag() const;
    void SetQuantityRateFlag( KBOOL F );
    KBOOL GetQuantityRateFlag() const;
    void SetLocationFlag( KBOOL F );
    KBOOL GetLocationFlag() const;

    //************************************
    // FullName:    KDIS::PDU::LE_Header::SetTargetEntityID
    //              KDIS::PDU::LE_Header::GetTargetEntityID
    // Description: Optional field.The intended target. If the intended target is unknown, this field
    //              shall not be included in the PDU however, the Location field shall be present.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   const LE_EntityIdentifier & ID
    //************************************
    void SetTargetEntityID( const LE_EntityIdentifier & ID );
    const LE_EntityIdentifier & GetTargetEntityID() const;
    LE_EntityIdentifier & GetTargetEntityID();

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::SetMunitionEntityID
    //              KDIS::PDU::LE_Fire_PDU::GetMunitionEntityID
    // Description: Optional field. Identifies the fired munition if tracking data is required.
    //              If tracking data for the munition are not required, this field
    //              shall not be included in the PDU.
    //              If the Site Number and Application Number fields are the same as
    //              those in the Firing Entity ID, they shall not be included;
    //              and the associated Fire Flag field bit will be set to zero.
    //              Note: Setting this value will also cause the relevant flags to be set to true.
    //              A check is automatically made when encoding to see if the site/app fields match the
    //              firing entity and the relevant flags are set accordingly.
    // Parameter:   const LE_EntityIdentifier & ID
    //************************************
    void SetMunitionEntityID( const LE_EntityIdentifier & ID );
    const LE_EntityIdentifier & GetMunitionEntityID() const;
    LE_EntityIdentifier & GetMunitionEntityID();

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::SetEventID
    //              KDIS::PDU::LE_Fire_PDU::GetEventID
    // Description: Contains an identification generated by the firing entity to associate related
    //              firing and detonation events.
    //              If the Site Number and Application Number are the same as those in the
    //              Firing Entity ID, they will not be included.
    //              Note: Setting this value will also cause the relevant flags to be set to true.
    //              A check is automatically made when encoding to see if the site/app fields match the
    //              firing entity and the relevant flags are set accordingly.
    // Parameter:   const LE_EntityIdentifier & ID
    //************************************
    void SetEventID( const LE_EntityIdentifier & ID );
    const LE_EntityIdentifier & GetEventID() const;
    LE_EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::SetEntityLocation
    //              KDIS::PDU::LE_Fire_PDU::GetEntityLocation
    // Description: Optional field. Location from which the munition was launched.
    //              This field is optional if the Target Entity ID is provided and mandatory
    //              if the Target Entity ID field is not included in the PDU.
    //              If the Location field is not included in the PDU, the firing location
    //              shall be the current dead reckoned location of the firing entity.
    // Parameter:   const RelativeWorldCoordinates & L
    //************************************
    void SetLocation( const RelativeWorldCoordinates & L );
    const RelativeWorldCoordinates & GetLocation() const;
    RelativeWorldCoordinates & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::SetMunitionDescriptor
    //              KDIS::PDU::LE_Fire_PDU::GetMunitionDescriptor
    // Description: Describes the type of munition fired, warhead, fuse, quantity,
    //              and rate. The warhead, fuse, quantity, and rate fields of this record
    //              are optional. If you wish to have them included then the relevant flag field must be set:
    //              void SetWarheadFuseFlag( true ) - To include Warhead and fuse fields.
    //              void SetQuantityRateFlag( true ) - To include Quantity and Rate fields.
    //              This field is also known as the BurstDescriptor in older versions of the DIS standard.
    // Parameter:   const BurstDescriptor & BD
    //************************************
    void SetMunitionDescriptor( const BurstDescriptor & BD );
    const BurstDescriptor & GetMunitionDescriptor() const;
    BurstDescriptor & GetMunitionDescriptor();

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::SetVelocity
    //              KDIS::PDU::LE_Fire_PDU::GetVelocity
    // Description: Specifies the velocity of the fired munition at the point when the
    //              issuing simulation application intends the externally visible effects
    //              of the launch (e.g., exhaust plume or muzzle blast) to first become
    //              apparent. In decimeters per second.
    // Parameter:   const LE_Vector16_3 & V
    //************************************
    void SetVelocity( const LE_Vector16_3 & V );
    const LE_Vector16_3 & GetVelocity() const;
    LE_Vector16_3 & GetVelocity();

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::SetRange
    //              KDIS::PDU::LE_Fire_PDU::GetRange
    // Description: Range in meters that an entity’s fire control system has assumed in
    //              computing the fire control solution. For systems where range is
    //              unknown or unavailable, this field shall contain the value zero.
    // Parameter:   KUINT16 R
    //************************************
    void SetRange( KUINT16 R );
    KUINT16 GetRange() const;

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::GetAsString
    // Description: Returns a string representation of the PDU
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_Fire_PDU & Value ) const;
    KBOOL operator != ( const LE_Fire_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
