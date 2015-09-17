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
#include "./../../DataTypes/MunitionDescriptor.h"
#include "./../../DataTypes/RelativeWorldCoordinates.h"
#include "./../../DataTypes/LE_Vector.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT LE_Fire_PDU : public LE_Header
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8TargetId        : 1; // F0 : 0 = Target Entity ID field is not included
                                             //      1 = Target Entity ID field is included
            KUINT8 m_ui8MunitionSiteApp : 1; // F1 : 0 = Site Number and Application Number data are the same as the firing
                                             //          entity’s and are not included in the Munition ID
                                             //      1 = Site Number and Application Number fields are included in the Munition ID
            KUINT8 m_ui8MunitionId      : 1; // F2 : 0 = Munition ID field is not included
                                             //      1 = Munition ID field is included
            KUINT8 m_ui8EventSiteAppId  : 1; // F3 : 0 = Site Number and Application Number data are the same as the firing
                                             //          entity’s and are not included in the Event ID
                                             //      1 = Site Number and Application Number fields are included in the Event ID
            KUINT8 m_ui8WarheadFuse     : 1; // F4 : 0 = Warhead and Fuse fields of the Munition Descriptor record are not
                                             //          included (use munition default)
                                             //      1 = Warhead and Fuse fields of the Munition Descriptor record are present
            KUINT8 m_ui8QuantRate       : 1; // F5 : 0 = Quantity and Rate fields of the Munition Descriptor record are not
                                             //          included
                                             //      1 = Quantity and Rate fields of the Munition Descriptor record are included
            KUINT8 m_ui8Location        : 1; // F6 : 0 = Location field from which fire event occurs is not included
                                             //      1 = Location field from which fire event occurs is included
            KUINT8 m_ui8Reserved        : 1;
        };
        KUINT8 m_ui8Flag;
    } m_FireFlagUnion;

    KDIS::DATA_TYPE::LE_EntityIdentifier m_TargetID;

    KDIS::DATA_TYPE::LE_EntityIdentifier m_MunitionID;

    KDIS::DATA_TYPE::LE_EntityIdentifier m_EventID;

    KDIS::DATA_TYPE::MunitionDescriptor m_MunitionDesc;

    KDIS::DATA_TYPE::RelativeWorldCoordinates m_Loc;

    KDIS::DATA_TYPE::LE_Vector16_3 m_Vel;

    KUINT16 m_ui16Range;

    //************************************
    // FullName:    KDIS::PDU::LE_Header::checkFlagsAndPDULength
    // Description: Checks the site and application values to see if we need to include them during
    //              encoding. The values are set when the set id functions are called however it is
    //              possible that a change may have occurred since, I.E by calling the GetID function
    //              and setting through it.
    //************************************
    void checkFlagsAndPDULength();

public:

    static const KUINT16 LE_FIRE_PDU_SIZE = 35; // Min size, not including optional fields

    LE_Fire_PDU();
	
    LE_Fire_PDU( KDataStream & stream ) throw( KException );

	LE_Fire_PDU( const Header & H, KDataStream & stream ) throw( KException );

    LE_Fire_PDU( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );

    virtual ~LE_Fire_PDU();

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
    void SetTargetEntityID( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );
    const KDIS::DATA_TYPE::LE_EntityIdentifier & GetTargetEntityID() const;
    KDIS::DATA_TYPE::LE_EntityIdentifier & GetTargetEntityID();

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
    void SetMunitionEntityID( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );
    const KDIS::DATA_TYPE::LE_EntityIdentifier & GetMunitionEntityID() const;
    KDIS::DATA_TYPE::LE_EntityIdentifier & GetMunitionEntityID();

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
    void SetEventID( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );
    const KDIS::DATA_TYPE::LE_EntityIdentifier & GetEventID() const;
    KDIS::DATA_TYPE::LE_EntityIdentifier & GetEventID();

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
    void SetLocation( const KDIS::DATA_TYPE::RelativeWorldCoordinates & L );
    const KDIS::DATA_TYPE::RelativeWorldCoordinates & GetLocation() const;
    KDIS::DATA_TYPE::RelativeWorldCoordinates & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::SetMunitionDescriptor
    //              KDIS::PDU::LE_Fire_PDU::GetMunitionDescriptor
    // Description: Describes the type of munition fired, warhead, fuse, quantity,
    //              and rate. The warhead, fuse, quantity, and rate fields of this record
    //              are optional. If you wish to have them included then the relevant flag field must be set:
    //              void SetWarheadFuseFlag( true ) - To include Warhead and fuse fields.
    //              void SetQuantityRateFlag( true ) - To include Quantity and Rate fields.
    //              This field is also known as the BurstDescriptor in older versions of the DIS standard.
    // Parameter:   const MunitionDescriptor & MD
    //************************************
    void SetMunitionDescriptor( const KDIS::DATA_TYPE::MunitionDescriptor & MD );
    const KDIS::DATA_TYPE::MunitionDescriptor & GetMunitionDescriptor() const;
    KDIS::DATA_TYPE::MunitionDescriptor & GetMunitionDescriptor();

    //************************************
    // FullName:    KDIS::PDU::LE_Fire_PDU::SetVelocity
    //              KDIS::PDU::LE_Fire_PDU::GetVelocity
    // Description: Specifies the velocity of the fired munition at the point when the
    //              issuing simulation application intends the externally visible effects
    //              of the launch (e.g., exhaust plume or muzzle blast) to first become
    //              apparent. In decimeters per second.
    // Parameter:   const LE_Vector16_3 & V
    //************************************
    void SetVelocity( const KDIS::DATA_TYPE::LE_Vector16_3 & V );
    const KDIS::DATA_TYPE::LE_Vector16_3 & GetVelocity() const;
    KDIS::DATA_TYPE::LE_Vector16_3 & GetVelocity();

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
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
