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
    class:      LE_Detonation_PDU
    DIS:        (6) 1278.1a - 1998
    created:    23/08/2010
    author:     Karl Jones

    purpose:    Communicates the detonation or impact of munitions.
    size:       320 bits / 40 octets - Min size
*********************************************************************/

#pragma once

#include "./LE_Header.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/RelativeWorldCoordinates.h"
#include "./../../DataTypes/LE_Vector.h"
#include "./../../DataTypes/LE_EulerAngles.h"
#include "./../../DataTypes/MunitionDescriptor.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT LE_Detonation_PDU : public LE_Header
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
            KUINT8 m_ui8LocationTyp     : 1; // F6 : 0 = Location in Entity Coordinates field is not included; Location in
                                             //          Relative World Coordinates field is included
                                             //      1 = Location in Entity Coordinates field is included; Location in Relative
                                             //          World Coordinates field is not included
            KUINT8 m_ui8Flag2           : 1; // F7 : 0 = Flag Octet 2 is not included
                                             //      1 = Flag Octet 2 is included
        };
        KUINT8 m_ui8Flag;
    } m_DetonationFlag1Union;

    union
    {
        struct
        {
            KUINT8 m_ui8MunitionOri     : 1; // G0 : 0 = Munition Orientation field is not included
                                             //      1 = Munition Orientation field is included
            KUINT8 m_ui8EventNum        : 1; // G1 : 0 = Event Number field is not included in Event ID
                                             //      1 = Event Number field is included in Event ID
            KUINT8 m_ui8Unused          : 5;
            KUINT8 m_ui8Reserved        : 1;
        };
        KUINT8 m_ui8Flag;
    } m_DetonationFlag2Union;

    KDIS::DATA_TYPE::LE_EntityIdentifier m_TargetID;

    KDIS::DATA_TYPE::LE_EntityIdentifier m_MunitionID;

    KDIS::DATA_TYPE::LE_EntityIdentifier m_EventID;

    KDIS::DATA_TYPE::LE_Vector16_3 m_LocEntCoord;
    KDIS::DATA_TYPE::RelativeWorldCoordinates m_LocWrldCoord;

    KDIS::DATA_TYPE::LE_Vector16_3 m_Vel;

    KDIS::DATA_TYPE::LE_EulerAngles m_Ori;

    KDIS::DATA_TYPE::MunitionDescriptor m_MunitionDesc;

    KUINT8 m_ui8DetonationResult;

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::checkFlagsAndPDULength
    // Description: Checks the site and application values to see if we need to include them during
    //              encoding. The values are set when the set id functions are called however it is
    //              possible that a change may have occurred since, I.E by calling the GetID function
    //              and setting through it.
    //************************************
    void checkFlagsAndPDULength();

public:

    static const KUINT16 LE_DETONATION_PDU_SIZE = 40; // Min size, not including optional fields

    LE_Detonation_PDU();

    LE_Detonation_PDU( KDataStream & stream ) throw( KException );

    LE_Detonation_PDU( const Header & H, KDataStream & stream ) throw( KException );

    LE_Detonation_PDU( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );

    virtual ~LE_Detonation_PDU();

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::SetTargetEntityIDFlag
    //              KDIS::PDU::LE_Detonation_PDU::GetTargetEntityIDFlag
    //              KDIS::PDU::LE_Detonation_PDU::SetMunitionEntityIDFlag
    //              KDIS::PDU::LE_Detonation_PDU::GetMunitionEntityIDFlag
    //              KDIS::PDU::LE_Detonation_PDU::SetMunitionEntityIDSiteAppIncludedFlag
    //              KDIS::PDU::LE_Detonation_PDU::GetMunitionEntityIDSiteAppIncludedFlag
    //              KDIS::PDU::LE_Detonation_PDU::SetEventIDSiteAppIncludedFlag
    //              KDIS::PDU::LE_Detonation_PDU::GetEventIDSiteAppIncludedFlag
    //              KDIS::PDU::LE_Detonation_PDU::SetWarheadFuseFlag
    //              KDIS::PDU::LE_Detonation_PDU::GetWarheadFuseFlag
    //              KDIS::PDU::LE_Detonation_PDU::SetQuantityRateFlag
    //              KDIS::PDU::LE_Detonation_PDU::GetQuantityRateFlag
    //              KDIS::PDU::LE_Detonation_PDU::SetLocationInEntityCoordinatesFlag
    //              KDIS::PDU::LE_Detonation_PDU::GetLocationInEntityCoordinatesFlag
    // Description: Identifies optional data fields that are being transmitted with
    //              this PDU.
    //              Notes:
    //              TargetEntityIDFlag - If the value is true then the location must be
    //              specified using WorldCoordinates otherwise use RelativeWorldCoordinates.
    //              LocationInEntityCoordinatesFlag - If the value is true the location class is
    //              in WorldCoordinates otherwise the location is in RelativeWorldCoordinates.
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
    void SetLocationInEntityCoordinatesFlag( KBOOL F );
    KBOOL GetLocationInEntityCoordinatesFlag() const;
    void SetFlag2Flag( KBOOL F );
    KBOOL GetFlag2Flag() const;
    void SetMunitionOrientationFlag( KBOOL F );
    KBOOL GetMunitionOrientationFlag() const;
    void SetEventNumberIncludedFlag( KBOOL F );
    KBOOL GetEventNumberIncludedFlag() const;

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::SetTargetEntityID
    //              KDIS::PDU::LE_Detonation_PDU::GetTargetEntityID
    // Description: Optional field.The intended target. If the intended target is unknown, this field
    //              shall not be included in the PDU.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   const LE_EntityIdentifier & ID
    //************************************
    void SetTargetEntityID( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );
    const KDIS::DATA_TYPE::LE_EntityIdentifier & GetTargetEntityID() const;
    KDIS::DATA_TYPE::LE_EntityIdentifier & GetTargetEntityID();

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::SetMunitionEntityID
    //              KDIS::PDU::LE_Detonation_PDU::GetMunitionEntityID
    // Description: Optional field. Identifies the fired munition if tracking data is required.
    //              If tracking data for the munition are not required, this field
    //              shall not be included in the PDU.
    //              If the Site Number and Application Number fields are the same as
    //              those in the Firing Entity ID, they shall not be included;
    //              and the associated Flag field bit will be set to zero.
    //              Note: Setting this value will also cause the relevant flags to be set to true.
    // Parameter:   const LE_EntityIdentifier & ID
    //************************************
    void SetMunitionEntityID( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );
    const KDIS::DATA_TYPE::LE_EntityIdentifier & GetMunitionEntityID() const;
    KDIS::DATA_TYPE::LE_EntityIdentifier & GetMunitionEntityID();

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::SetEventID
    //              KDIS::PDU::LE_Detonation_PDU::GetEventID
    // Description: Optional field. Should contain the same data as in the Event ID field of the
    //              LE Fire PDU that communicated the launch of the munition.
    //              If the detonation is not preceded by a corresponding fire event, then the
    //              Event ID field shall not be included in the current PDU.
    //              If the Site Number and Application Number fields are the same as those in the
    //              Firing Entity ID, they shall not be included.
    //              Note: Setting this value will also cause the relevant flags to be set to true.
    //              A check is automatically made when encoding to see if the site/app fields match the
    //              firing entity and the relevant flags are set accordingly.
    // Parameter:   const LE_EntityIdentifier & ID
    //************************************
    void SetEventID( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );
    const KDIS::DATA_TYPE::LE_EntityIdentifier & GetEventID() const;
    KDIS::DATA_TYPE::LE_EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::SetLocation
    //              KDIS::PDU::LE_Detonation_PDU::SetLocationEntityCoordinates
    //              KDIS::PDU::LE_Detonation_PDU::GetLocationEntityCoordinates
    //              KDIS::PDU::LE_Detonation_PDU::SetLocationWorldCoordinates
    //              KDIS::PDU::LE_Detonation_PDU::GetLocationWorldCoordinates
    // Description: The location of the detonation.
    //              If the Target ID field is included the location will be in EntityCoordinates(LE_Vector16_3),
    //              This information should be used for damage assessment.
    //              If the Target ID field is not included then this field will be in WorldCoordinates.
    //              Note: Setting this value will also cause the relevant flag to be set correctly.
    // Parameter:   const LE_Vector16_3 & L, const RelativeWorldCoordinates & L
    //************************************
    void SetLocation( const KDIS::DATA_TYPE::LE_Vector16_3 & L  );
    void SetLocation( const KDIS::DATA_TYPE::RelativeWorldCoordinates & L  );
    void SetLocationEntityCoordinates( const KDIS::DATA_TYPE::LE_Vector16_3 & L );
    const KDIS::DATA_TYPE::LE_Vector16_3 & GetLocationEntityCoordinates() const;
    KDIS::DATA_TYPE::LE_Vector16_3 & GetLocationEntityCoordinates();
    void SetLocationWorldCoordinates( const KDIS::DATA_TYPE::RelativeWorldCoordinates & L );
    const KDIS::DATA_TYPE::RelativeWorldCoordinates & GetLocationWorldCoordinates() const;
    KDIS::DATA_TYPE::RelativeWorldCoordinates & GetLocationWorldCoordinates();

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::SetVelocity
    //              KDIS::PDU::LE_Detonation_PDU::GetVelocity
    // Description: The velocity of the munition immediately before
    //              detonation/impact in decimeters per second.
    // Parameter:   const LE_Vector16_3 & V
    //************************************
    void SetVelocity( const KDIS::DATA_TYPE::LE_Vector16_3 & V );
    const KDIS::DATA_TYPE::LE_Vector16_3 & GetVelocity() const;
    KDIS::DATA_TYPE::LE_Vector16_3 & GetVelocity();

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::SetMunitionOrientation
    //              KDIS::PDU::LE_Detonation_PDU::GetMunitionOrientation
    // Description: Optional field. Orientation of the munition in entity based
    //              coordinates at the time of detonation.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   const LE_EulerAngles & O
    //************************************
    void SetMunitionOrientation( const KDIS::DATA_TYPE::LE_EulerAngles & O );
    const KDIS::DATA_TYPE::LE_EulerAngles & GetMunitionOrientation() const;
    KDIS::DATA_TYPE::LE_EulerAngles & GetMunitionOrientation();

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::SetMunitionDescriptor
    //              KDIS::PDU::LE_Detonation_PDU::GetMunitionDescriptor
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
    // FullName:    KDIS::PDU::LE_Detonation_PDU::SetDetonationResult
    //              KDIS::PDU::LE_Detonation_PDU::GetDetonationResult
    // Description: Represents the result of the detonation.
    // Parameter:   DetonationResult DR
    //************************************
    void SetDetonationResult( KDIS::DATA_TYPE::ENUMS::DetonationResult DR );
    KDIS::DATA_TYPE::ENUMS::DetonationResult GetDetonationResult() const;

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::GetAsString
    // Description: Returns a string representation of the PDU
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream?
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::LE_Detonation_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_Detonation_PDU & Value ) const;
    KBOOL operator != ( const LE_Detonation_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
