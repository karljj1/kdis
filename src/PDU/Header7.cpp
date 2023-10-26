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

#include "KDIS/PDU/Header7.hpp"

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

Header7* Header7::clone() const { return new Header7(*this); }

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Header7::Header7() {}

//////////////////////////////////////////////////////////////////////////

Header7::Header7(KDataStream& stream) { Decode(stream, false); }

//////////////////////////////////////////////////////////////////////////

Header7::Header7(ProtocolVersion PV, KUINT8 ExerciseID, PDUType PT,
                 ProtocolFamily PF, const TimeStamp& TS, KUINT16 PDULength)
    : Header6(PV, ExerciseID, PT, PF, TS, PDULength) {
  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

Header7::~Header7() {}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatus(KUINT8 S) {
  m_PDUStatus = std::bitset<8>(S);
  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Header7::GetPDUStatus() const {
  return static_cast<KUINT8>(m_PDUStatus.to_ulong());
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusCEI(KBOOL CEI) {
  // CEI - Coupled Extension Indicator
  // Bit #3 of the DIS 7 PDU Status field.
  m_PDUStatus.set(3, CEI);
  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::GetPDUStatusCEI() const {
  // CEI - Coupled Extension Indicator
  // Bit #3 of the DIS 7 PDU Status field.
  return m_PDUStatus.test(3);
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusTEI(KBOOL TEI) {
  // TEI - Transferred Entity Indicator
  // Bit #0 of the DIS 7 PDU Status field.
  m_PDUStatus.set(0, TEI);
  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::GetPDUStatusTEI() const {
  // TEI - Transferred Entity Indicator
  // Bit #0 of the DIS 7 PDU Status field.
  return m_PDUStatus.test(0);
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusLVC(LVCIndicator LVC) {
  // LVC - LVC Indicator
  // Bits #1 and #2 of the DIS 7 PDU Status field.
  if (LVC == LiveLVC) {
    m_PDUStatus.set(1);
    m_PDUStatus.reset(2);
  } else if (LVC == VirtualLVC) {
    m_PDUStatus.reset(1);
    m_PDUStatus.set(2);
  } else if (LVC == ConstructiveLVC) {
    m_PDUStatus.set(1);
    m_PDUStatus.set(2);
  } else {
    // NoStatementLVC
    m_PDUStatus.reset(1);
    m_PDUStatus.reset(2);
  }

  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

LVCIndicator Header7::GetPDUStatusLVC() const {
  // LVC - LVC Indicator
  // Bits #1 and #2 of the DIS 7 PDU Status field.
  std::bitset<8> mask(0b00000110);
  std::bitset<8> value = m_PDUStatus & mask;
  return static_cast<LVCIndicator>(value.to_ulong() >> 1);
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusFTI(KBOOL FTI) {
  // FTI - Fire Type Indicator
  // Bit #4 of the DIS 7 PDU Status field.
  m_PDUStatus.set(4, FTI);
  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::GetPDUStatusFTI() const {
  // FTI - Fire Type Indicator
  // Bit #4 of the DIS 7 PDU Status field.
  return m_PDUStatus.test(4);
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusDTI(DetonationType DTI) {
  // DTI - Detonation Type Indicator
  // Bits #4 and #5 of the DIS 7 PDU Status field.
  if (DTI == ExpendableDTI) {
    m_PDUStatus.set(4);
    m_PDUStatus.reset(5);
  } else if (DTI == NonMunitionExplosionDTI) {
    m_PDUStatus.reset(4);
    m_PDUStatus.set(5);
  } else {
    // MunitionDTI
    m_PDUStatus.reset(4);
    m_PDUStatus.reset(5);
  }

  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

DetonationType Header7::GetPDUStatusDTI() const {
  // DTI - Detonation Type Indicator
  // Bits #4 and #5 of the DIS 7 PDU Status field.
  std::bitset<8> mask(0b00110000);
  std::bitset<8> value = m_PDUStatus & mask;
  return static_cast<DetonationType>(value.to_ulong() >> 4);
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusRAI(AttachedIndicator RAI) {
  // RAI - Radio Attached Indicator
  // Bits #4 and #5 of the DIS 7 PDU Status field.
  if (RAI == UnattachedAttachedIndicator) {
    m_PDUStatus.set(4);
    m_PDUStatus.reset(5);
  } else if (RAI == AttachedAttachedIndicator) {
    m_PDUStatus.reset(4);
    m_PDUStatus.set(5);
  } else {
    // NoStatementAttachedIndicator
    m_PDUStatus.reset(4);
    m_PDUStatus.reset(5);
  }

  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

AttachedIndicator Header7::GetPDUStatusRAI() const {
  // RAI - Radio Attached Indicator
  // Bits #4 and #5 of the DIS 7 PDU Status field.
  std::bitset<8> mask(0b00110000);
  std::bitset<8> value = m_PDUStatus & mask;
  return static_cast<AttachedIndicator>(value.to_ulong() >> 4);
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusIAI(AttachedIndicator IAI) {
  // RAI - Intercom Attached Indicator
  // Bits #4 and #5 of the DIS 7 PDU Status field.
  if (IAI == UnattachedAttachedIndicator) {
    m_PDUStatus.set(4);
    m_PDUStatus.reset(5);
  } else if (IAI == AttachedAttachedIndicator) {
    m_PDUStatus.reset(4);
    m_PDUStatus.set(5);
  } else {
    // NoStatementAttachedIndicator
    m_PDUStatus.reset(4);
    m_PDUStatus.reset(5);
  }

  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

AttachedIndicator Header7::GetPDUStatusIAI() const {
  // RAI - Intercom Attached Indicator
  // Bits #4 and #5 of the DIS 7 PDU Status field.
  std::bitset<8> mask(0b00110000);
  std::bitset<8> value = m_PDUStatus & mask;
  return static_cast<AttachedIndicator>(value.to_ulong() >> 4);
}

//////////////////////////////////////////////////////////////////////////

void Header7::SetPDUStatusSM(KBOOL SM) {
  // ISM - IFF Simulation Mode
  // Bit #4 of the DIS 7 PDU Status field.
  m_PDUStatus.set(4, SM);
  m_ui8ProtocolVersion = IEEE_1278_1_2012;  // We are using a DIS 7 feature now.
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::GetPDUStatusSM() const {
  // ISM - IFF Simulation Mode
  // Bit #4 of the DIS 7 PDU Status field.
  return m_PDUStatus.test(4);
}

//////////////////////////////////////////////////////////////////////////

KString Header7::GetAsString() const {
  KStringStream ss;

  ss << Header6::GetAsString();

  // Append the status flags this PDU should have
  if (m_ui8PDUType < Attribute_PDU_Type) {
    //
    // CEI - Applies to every PDU except attribute
    //
    ss << "PDU Status:\n"
       << "\tCoupled Extension Indicator: "
       << static_cast<KUINT16>(GetPDUStatusCEI()) << "\n";

    //
    // TEI - Applies to various PDU
    //
    if (m_ui8PDUType == Entity_State_PDU_Type ||
        m_ui8PDUType == Electromagnetic_Emission_PDU_Type ||
        m_ui8PDUType == Designator_PDU_Type ||
        m_ui8PDUType == Transmitter_PDU_Type ||
        m_ui8PDUType == Signal_PDU_Type || m_ui8PDUType == Receiver_PDU_Type ||
        m_ui8PDUType == IFF_ATC_NAVAIDS_PDU_Type ||
        m_ui8PDUType == IntercomSignal_PDU_Type ||
        m_ui8PDUType == IntercomControl_PDU_Type ||
        m_ui8PDUType == EnvironmentalProcess_PDU_Type ||
        m_ui8PDUType == EntityStateUpdate_PDU_Type) {
      ss << "\tTransferred Entity Indicator: "
         << static_cast<KUINT16>(GetPDUStatusTEI()) << "\n";
    }

    //
    // LVC - Applies to various PDU
    //
    if (m_ui8PDUType == Entity_State_PDU_Type ||
        m_ui8PDUType == Fire_PDU_Type || m_ui8PDUType == Designator_PDU_Type ||
        m_ui8PDUType == Electromagnetic_Emission_PDU_Type ||
        m_ui8PDUType == Designator_PDU_Type ||
        m_ui8PDUType == Transmitter_PDU_Type ||
        m_ui8PDUType == Signal_PDU_Type || m_ui8PDUType == Receiver_PDU_Type ||
        m_ui8PDUType == IFF_ATC_NAVAIDS_PDU_Type ||
        m_ui8PDUType == IntercomSignal_PDU_Type ||
        m_ui8PDUType == IntercomControl_PDU_Type ||
        m_ui8PDUType == EnvironmentalProcess_PDU_Type ||
        m_ui8PDUType == EntityStateUpdate_PDU_Type ||
        m_ui8PDUType == DirectedEnergyFire_PDU_Type ||
        m_ui8PDUType == EntityDamageStatus_PDU_Type ||
        m_ui8PDUType == IO_Action_PDU_Type ||
        m_ui8PDUType == IO_Report_PDU_Type) {
      ss << "\tLVC Indicator: "
         << GetEnumAsStringLVCIndicator(static_cast<KUINT16>(GetPDUStatusLVC()))
         << "\n";
    }

    //
    // FTI - Fire PDU only or DTI - Detonation PDU only
    //
    if (m_ui8PDUType == Fire_PDU_Type) {
      ss << "\tFire Type Indicator: " << static_cast<KUINT16>(GetPDUStatusFTI())
         << "\n";
    } else if (m_ui8PDUType == Detonation_PDU_Type) {
      ss << "\tDetonation Type Indicator: "
         << static_cast<KUINT16>(GetPDUStatusDTI()) << "\n";
    }

    //
    // RAI - Transmitter(25), Signal(26), Receiver(27) or IAI  -
    // IntercomSignal(31), IntercomControl(32)
    //
    if (m_ui8PDUType == Transmitter_PDU_Type ||
        m_ui8PDUType == Signal_PDU_Type || m_ui8PDUType == Receiver_PDU_Type) {
      ss << "\tRadio Attached Indicator: "
         << GetEnumAsStringAttachedIndicator(
                static_cast<KUINT16>(GetPDUStatusRAI()))
         << "\n";
    } else if (m_ui8PDUType == IntercomSignal_PDU_Type ||
               m_ui8PDUType == IntercomControl_PDU_Type) {
      ss << "\tIntercom Attached Indicator: "
         << GetEnumAsStringAttachedIndicator(
                static_cast<KUINT16>(GetPDUStatusIAI()))
         << "\n";
    }

    //
    // SM - IFF ATC NAVAIDS(28) only
    //
    if (m_ui8PDUType == IFF_ATC_NAVAIDS_PDU_Type) {
      ss << "\tSimulation Mode: " << static_cast<KUINT16>(GetPDUStatusSM())
         << "\n";
    }
  }

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Header7::Decode(KDataStream& stream, bool ignoreHeader /*= false*/) {
  if (!ignoreHeader) {
    if (stream.GetBufferSize() < HEADER6_PDU_SIZE)
      throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

    KUINT8 pduStatus = 0;

    stream >> m_ui8ProtocolVersion >> m_ui8ExerciseID >> m_ui8PDUType >>
        m_ui8ProtocolFamily >> KDIS_STREAM m_TimeStamp >> m_ui16PDULength >>
        ((m_ui8ProtocolFamily == LiveEntity)
             ? m_ui8Padding1
             : pduStatus)  // LE family use the padding for the sub protocol
                           // field.
        >> m_ui8Padding2;

    m_PDUStatus = std::bitset<8>(pduStatus);
  }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Header7::Encode() const {
  KDataStream stream;

  Header6::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void Header7::Encode(KDataStream& stream) const {
  stream << m_ui8ProtocolVersion << m_ui8ExerciseID << m_ui8PDUType
         << m_ui8ProtocolFamily << KDIS_STREAM m_TimeStamp << m_ui16PDULength
         << ((m_ui8ProtocolFamily == LiveEntity)
                 ? m_ui8Padding1
                 : static_cast<KUINT8>(
                       m_PDUStatus.to_ulong()))  // LE family use the padding
                                                 // for the sub protocol field.
         << m_ui8Padding2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::operator==(const Header7& Value) const {
  if (Header6::operator!=(Value)) return false;
  if (static_cast<KUINT8>(m_PDUStatus.to_ulong()) !=
      static_cast<KUINT8>(Value.m_PDUStatus.to_ulong()))
    return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header7::operator!=(const Header7& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
