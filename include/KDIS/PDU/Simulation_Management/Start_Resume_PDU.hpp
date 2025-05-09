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
    class:      Start_Resume_PDU
    DIS:        (5) 1278.1 - 1995
    created:    22/09/2008
    author:     Karl Jones

    purpose:    Indicates a start resume status to the entity/exercise
    size:       352 bits / 44 octets
*********************************************************************/

#pragma once

#include "KDIS/DataTypes/ClockTime.hpp"
#include "KDIS/PDU/Simulation_Management/Simulation_Management_Header.hpp"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Start_Resume_PDU : public Simulation_Management_Header {
 protected:
  KDIS::DATA_TYPE::ClockTime m_RealWorldTime;

  KDIS::DATA_TYPE::ClockTime m_SimTime;

  KUINT32 m_ui32RequestID;

  Start_Resume_PDU* clone() const override;

 public:
  static const KUINT16 START_RESUME_PDU_SIZE = 44;

  Start_Resume_PDU();

  explicit Start_Resume_PDU(const Header& H);

  explicit Start_Resume_PDU(KDataStream& stream);

  Start_Resume_PDU(const Header& H, KDataStream& stream);

  Start_Resume_PDU(const KDIS::DATA_TYPE::EntityIdentifier& ReceivingEntity,
                   const KDIS::DATA_TYPE::EntityIdentifier& SupplyingEntity,
                   const KDIS::DATA_TYPE::ClockTime& RealWorldTime,
                   const KDIS::DATA_TYPE::ClockTime& SimTime, KUINT32 ReqID);

  Start_Resume_PDU(const Simulation_Management_Header& SimMgrHeader,
                   const KDIS::DATA_TYPE::ClockTime& RealWorldTime,
                   const KDIS::DATA_TYPE::ClockTime& SimTime, KUINT32 ReqID);

  virtual ~Start_Resume_PDU();

  //************************************
  // FullName:    KDIS::PDU::Start_Resume_PDU::SetRealWorldTime
  //              KDIS::PDU::Start_Resume_PDU::GetRealWorldTime
  // Description: specify the real-world time at which the entity
  //              is to start/resume in the exercise.
  // Parameter:   const ClockTime & T
  //************************************
  void SetRealWorldTime(const KDIS::DATA_TYPE::ClockTime& T);
  const KDIS::DATA_TYPE::ClockTime& GetRealWorldTime() const;
  KDIS::DATA_TYPE::ClockTime& GetRealWorldTime();

  //************************************
  // FullName:    KDIS::PDU::Start_Resume_PDU::SetSimulationTime
  //              KDIS::PDU::Start_Resume_PDU::GetSimulationTime
  // Description: specify the simulation time at which the entity
  //              is to start/resume in the exercises.
  // Parameter:   const ClockTime & T
  //************************************
  void SetSimulationTime(const KDIS::DATA_TYPE::ClockTime& T);
  const KDIS::DATA_TYPE::ClockTime& GetSimulationTime() const;
  KDIS::DATA_TYPE::ClockTime& GetSimulationTime();

  //************************************
  // FullName:    KDIS::PDU::Start_Resume_PDU::SetRequestID
  //              KDIS::PDU::Start_Resume_PDU::GetRequestID
  // Description: Request ID
  // Parameter:   KUINT32 ID
  //************************************
  void SetRequestID(KUINT32 ID);
  KUINT32 GetRequestID() const;

  //************************************
  // FullName:    KDIS::PDU::Start_Resume_PDU::GetAsString
  // Description: Returns a string representation of the PDU.
  //************************************
  KString GetAsString() const override;

  //************************************
  // FullName:    KDIS::PDU::Start_Resume_PDU::Decode
  // Description: Convert From Network Data.
  // Parameter:   KDataStream & stream
  // Parameter:   bool ignoreHeader = false - Decode the header from the stream?
  //************************************
  void Decode(KDataStream& stream, bool ignoreHeader = false) override;

  //************************************
  // FullName:    KDIS::PDU::Start_Resume_PDU::Encode
  // Description: Convert To Network Data.
  //************************************
  KDataStream Encode() const override;
  void Encode(KDataStream& stream) const override;

  KBOOL operator==(const Start_Resume_PDU& Value) const;
  KBOOL operator!=(const Start_Resume_PDU& Value) const;
};

}  // END namespace PDU
}  // END namespace KDIS
