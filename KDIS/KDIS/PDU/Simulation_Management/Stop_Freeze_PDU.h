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
    class:      Stop_Freeze_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Indicates the stopping/freezing of an entity/exercise.
    size:       320 bits / 40 octets
*********************************************************************/

#pragma once

#include "./Simulation_Management_Header.h"
#include "./../../DataTypes/ClockTime.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Stop_Freeze_PDU : public Simulation_Management_Header
{
protected:

    KDIS::DATA_TYPE::ClockTime m_RealWorldTime;

    KUINT8 m_ui8Reason;

    KUINT8 m_ui8FrozenBehaviour;

    KUINT16 m_ui16Padding;

    KUINT32 m_ui32RequestID;

public:

    static const KUINT16 STOP_FREEZE_PDU_SIZE = 40;

    Stop_Freeze_PDU();

	Stop_Freeze_PDU( const Header & H );

    Stop_Freeze_PDU( KDataStream & stream ) throw( KException );

	Stop_Freeze_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Stop_Freeze_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntity, const KDIS::DATA_TYPE::EntityIdentifier & SupplyingEntity,
		const KDIS::DATA_TYPE::ClockTime & RealWorldTime, KDIS::DATA_TYPE::ENUMS::StopFreezeReason SFR, KDIS::DATA_TYPE::ENUMS::FrozenBehavior FB, KUINT32 ReqID );

    Stop_Freeze_PDU( const Simulation_Management_Header & SimMgrHeader, const KDIS::DATA_TYPE::ClockTime & RealWorldTime,
                     KDIS::DATA_TYPE::ENUMS::StopFreezeReason SFR, KDIS::DATA_TYPE::ENUMS::FrozenBehavior FB, KUINT32 ReqID );

    virtual ~Stop_Freeze_PDU();

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::SetRealWorldTime
    //              KDIS::PDU::Stop_Freeze_PDU::GetRealWorldTime
    // Description: specify the real-world time at which the entity
    //              is to start/resume in the exercise.
    // Parameter:   const ClockTime T
    //************************************
    void  SetRealWorldTime( const KDIS::DATA_TYPE::ClockTime & T );
    const KDIS::DATA_TYPE::ClockTime & GetRealWorldTime() const;
    KDIS::DATA_TYPE::ClockTime & GetRealWorldTime();

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::SetReason
    //              KDIS::PDU::Stop_Freeze_PDU::GetReason
    // Description: Reason the entity/exercise was frozen
    // Parameter:   StopFreezeReason SFR
    //************************************
    void SetReason( KDIS::DATA_TYPE::ENUMS::StopFreezeReason SFR );
    KDIS::DATA_TYPE::ENUMS::StopFreezeReason GetReason() const;

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::SetFrozenBehavior
    //              KDIS::PDU::Stop_Freeze_PDU::GetFrozenBehavior
    // Description: Specifies the internal behavior of the simulation and its
    //              appearance whilst the frozen to the other participants of the
    //              exercise
    // Parameter:   FrozenBehavior FB
    //************************************
    void SetFrozenBehavior( KDIS::DATA_TYPE::ENUMS::FrozenBehavior FB );
    KDIS::DATA_TYPE::ENUMS::FrozenBehavior GetFrozenBehavior() const;

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::SetRequestID
    //              KDIS::PDU::Stop_Freeze_PDU::GetRequestID
    // Description: Request ID
    // Parameter:   KUINT32 ID
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Stop_Freeze_PDU & Value ) const;
    KBOOL operator != ( const Stop_Freeze_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
