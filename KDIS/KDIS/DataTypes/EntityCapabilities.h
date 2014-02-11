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
    class:      EntityCapabilities
    created:    2008/09/24
    author:     Karl Jones

    purpose:    Collection of bits to describe the capabilities of the entity
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EntityCapabilities :  public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT32 m_AmmunitionSupply : 1;
            KUINT32 m_FuelSupply       : 1;
            KUINT32 m_RecoveryService  : 1;
            KUINT32 m_RepairService    : 1;
			KUINT32 m_ADSB             : 1;
            KUINT32 m_Unused           : 27;
        };
        KUINT32 m_ui16Data;
    };

public:

    static const KUINT16 ENTITY_CAPABILITIES_SIZE = 4;

    EntityCapabilities();

    EntityCapabilities( KDataStream & stream ) throw( KException );

    EntityCapabilities( KBOOL AmunitionSupply, KBOOL FuelSupply, KBOOL RecoveryService, KBOOL RepairService );

	EntityCapabilities( KBOOL AmunitionSupply, KBOOL FuelSupply, KBOOL RecoveryService, KBOOL RepairService, KBOOL ADSB );

    virtual ~EntityCapabilities();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetHasAmmunitionSupply
    //              KDIS::DATA_TYPE::EntityCapabilities::HasAmmunitionSupply
    // Description: Does the entity have an ammunition supply
    // Parameter:   KBOOL HAS
    //************************************
    void SetHasAmmunitionSupply( KBOOL HAS );
    KBOOL HasAmmunitionSupply() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetHasFuelSupply
    //              KDIS::DATA_TYPE::EntityCapabilities::HasFuelSupply
    // Description: Does the entity have a fuel supply
    // Parameter:   KBOOL HAS
    //************************************
    void SetHasFuelSupply( KBOOL HAS );
    KBOOL HasFuelSupply() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetHasRecoveryService
    //              KDIS::DATA_TYPE::EntityCapabilities::HasRecoveryService
    // Description: Does the entity have a recovery service, such as towing
    // Parameter:   KBOOL HAS
    //************************************
    void SetHasRecoveryService( KBOOL HAS );
    KBOOL HasRecoveryService() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetHasRepairService
    //              KDIS::DATA_TYPE::EntityCapabilities::HasRepairService
    // Description: Does the entity have a repair service
    // Parameter:   KBOOL HAS
    //************************************
    void SetHasRepairService( KBOOL HAS );
    KBOOL HasRepairService() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetHasAutomaticDependentSurveillanceBroadcast
    //              KDIS::DATA_TYPE::EntityCapabilities::HasAutomaticDependentSurveillanceBroadcast
    // Description: Is the entity capable of Automatic Dependent Surveillance - Broadcast (ADS-B)?
    // Parameter:   KBOOL ADSB
    //************************************
	void SetHasAutomaticDependentSurveillanceBroadcast( KBOOL ADSB );
	KBOOL HasAutomaticDependentSurveillanceBroadcast() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::SetAllFields
    //              KDIS::DATA_TYPE::EntityCapabilities::GetAllFields
    // Description: 4 octet length field with all the bits set.
    // Parameter:   KUINT32 All
    //************************************
    void SetAllFields( KUINT32 All );
    KUINT32 GetAllFields() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityCapabilities::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EntityCapabilities & Value ) const;
    KBOOL operator != ( const EntityCapabilities & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

