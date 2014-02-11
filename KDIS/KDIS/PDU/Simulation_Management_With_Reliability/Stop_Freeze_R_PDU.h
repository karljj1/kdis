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
    class:      Stop_Freeze_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    21:03:2009
    author:     Karl Jones

    purpose:    Indicates the stopping/freezing of an entity/exercise
    size:       352 bits / 44 octets
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Stop_Freeze_PDU.h"
#include "./Reliability_Header.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Stop_Freeze_R_PDU : public Stop_Freeze_PDU,
                                      public Reliability_Header
{
public:

    static const KUINT16 STOP_FREEZE_R_PDU_SIZE = 40;

    Stop_Freeze_R_PDU();

    Stop_Freeze_R_PDU( KDataStream & stream ) throw( KException );

	Stop_Freeze_R_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Stop_Freeze_R_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntity, const KDIS::DATA_TYPE::EntityIdentifier & SupplyingEntity, 
		               const KDIS::DATA_TYPE::ClockTime & RealWorldTime, KDIS::DATA_TYPE::ENUMS::StopFreezeReason SFR, 
					   KDIS::DATA_TYPE::ENUMS::FrozenBehavior FB, KUINT32 ReqID, KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS );

    Stop_Freeze_R_PDU( const Simulation_Management_Header & SimMgrHeader, const KDIS::DATA_TYPE::ClockTime & RealWorldTime,
		               KDIS::DATA_TYPE::ENUMS::StopFreezeReason SFR, KDIS::DATA_TYPE::ENUMS::FrozenBehavior FB, KUINT32 ReqID, 
					   KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS );

    virtual ~Stop_Freeze_R_PDU();

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_R_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_R_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Stop_Freeze_R_PDU & Value ) const;
    KBOOL operator != ( const Stop_Freeze_R_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
