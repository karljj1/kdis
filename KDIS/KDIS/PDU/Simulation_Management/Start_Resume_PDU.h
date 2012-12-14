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
    class:      Start_Resume_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Indicates a start resume status to the entity/exercise
    size:       352 bits / 44 octets
*********************************************************************/

#pragma once

#include "./Simulation_Management_Header.h"
#include "./../../DataTypes/ClockTime.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::ClockTime;

class KDIS_EXPORT Start_Resume_PDU : public Simulation_Management_Header
{
protected:

    ClockTime m_RealWorldTime;

    ClockTime m_SimTime;

    KUINT32 m_ui32RequestID;

public:

    static const KUINT16 START_RESUME_PDU_SIZE = 44;

    Start_Resume_PDU( void );

    Start_Resume_PDU( KDataStream & stream ) throw( KException );

    Start_Resume_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity,
                      const ClockTime & RealWorldTime, const ClockTime & SimTime, KUINT32 ReqID );

    Start_Resume_PDU( const Simulation_Management_Header & SimMgrHeader, const ClockTime & RealWorldTime,
                      const ClockTime & SimTime, KUINT32 ReqID  );

    virtual ~Start_Resume_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Start_Resume_PDU::SetRealWorldTime
    //              KDIS::PDU::Start_Resume_PDU::GetRealWorldTime
    // Description: specify the real-world time at which the entity
    //              is to start/resume in the exercise.
    // Parameter:   const ClockTime & T, void
    //************************************
    void  SetRealWorldTime( const ClockTime & T );
    const ClockTime & GetRealWorldTime() const;
    ClockTime & GetRealWorldTime();

    //************************************
    // FullName:    KDIS::PDU::Start_Resume_PDU::SetSimulationTime
    //              KDIS::PDU::Start_Resume_PDU::GetSimulationTime
    // Description: specify the simulation time at which the entity
    //              is to start/resume in the exercies.
    // Parameter:   const ClockTime & T, void
    //************************************
    void SetSimulationTime( const ClockTime & T );
    const ClockTime & GetSimulationTime() const;
    ClockTime & GetSimulationTime();

    //************************************
    // FullName:    KDIS::PDU::Start_Resume_PDU::SetRequestID
    //              KDIS::PDU::Start_Resume_PDU::GetRequestID
    // Description: Request ID
    // Parameter:   KUINT32 ID, void
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Start_Resume_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Start_Resume_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Start_Resume_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Start_Resume_PDU & Value ) const;
    KBOOL operator != ( const Start_Resume_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
