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

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::ClockTime;
using KDIS::DATA_TYPE::ENUMS::StopFreezeReason;
using KDIS::DATA_TYPE::ENUMS::FrozenBehavior;

class KDIS_EXPORT Stop_Freeze_PDU : public Simulation_Management_Header
{
protected:

    ClockTime m_RealWorldTime;

    KUINT8 m_ui8Reason;

    KUINT8 m_ui8FrozenBehaviour;

    KUINT16 m_ui16Padding;

    KUINT32 m_ui32RequestID;

public:

    static const KUINT16 STOP_FREEZE_PDU_SIZE = 40;

    Stop_Freeze_PDU( void );

    Stop_Freeze_PDU( KDataStream & stream ) throw( KException );

    Stop_Freeze_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity,
                     const ClockTime & RealWorldTime, StopFreezeReason SFR, FrozenBehavior FB, KUINT32 ReqID );

    Stop_Freeze_PDU( const Simulation_Management_Header & SimMgrHeader, const ClockTime & RealWorldTime,
                     StopFreezeReason SFR, FrozenBehavior FB, KUINT32 ReqID );

    virtual ~Stop_Freeze_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::SetRealWorldTime
    //              KDIS::PDU::Stop_Freeze_PDU::GetRealWorldTime
    // Description: specify the real-world time at which the entity
    //              is to start/resume in the exercise.
    // Parameter:   const ClockTime T, void
    //************************************
    void  SetRealWorldTime( const ClockTime & T );
    const ClockTime & GetRealWorldTime() const;
    ClockTime & GetRealWorldTime();

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::SetReason
    //              KDIS::PDU::Stop_Freeze_PDU::GetReason
    // Description: Reason the entity/exercise was frozen
    // Parameter:   StopFreezeReason SFR, void
    //************************************
    void SetReason( StopFreezeReason SFR );
    StopFreezeReason GetReason() const;

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::SetFrozenBehavior
    //              KDIS::PDU::Stop_Freeze_PDU::GetFrozenBehavior
    // Description: Specifies the internal behavior of the simulation and its
    //              appearance whilst the frozen to the other participants of the
    //              exercise
    // Parameter:   FrozenBehavior FB
    //************************************
    void SetFrozenBehavior( FrozenBehavior FB );
    FrozenBehavior GetFrozenBehavior() const;

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::SetRequestID
    //              KDIS::PDU::Stop_Freeze_PDU::GetRequestID
    // Description: Request ID
    // Parameter:   KUINT32 ID, void
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Stop_Freeze_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Stop_Freeze_PDU & Value ) const;
    KBOOL operator != ( const Stop_Freeze_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
