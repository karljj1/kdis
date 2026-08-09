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

#include "KDIS/PDU/Distributed_Emission_Regeneration/IFF_PDU.hpp"

#include <memory>

#include "KDIS/DataTypes/Enums/EnumSystemIdentifier.hpp"
#include "KDIS/utils/format.hpp"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////

namespace {
bool IsTransponder(const KDIS::DATA_TYPE::SystemIdentifier& SI) {
  switch (SI.GetSystemType()) {
    case KDIS::DATA_TYPE::ENUMS::Mark_X_XII_ATCRBS_ModeS_Transponder:
    case KDIS::DATA_TYPE::ENUMS::Soviet_Transponder:
    case KDIS::DATA_TYPE::ENUMS::RRB_Transponder:
#if DIS_VERSION > 6
    case KDIS::DATA_TYPE::ENUMS::Mark_XIIA_Transponder:
    case KDIS::DATA_TYPE::ENUMS::Mode_5_Transponder:
    case KDIS::DATA_TYPE::ENUMS::Mode_S_Transponder:
#endif
      return true;
    case KDIS::DATA_TYPE::ENUMS::Mark_X_XII_ATCRBS_ModeS_Interrogator:
    case KDIS::DATA_TYPE::ENUMS::Soviet_Interrogator:
#if DIS_VERSION > 6
    case KDIS::DATA_TYPE::ENUMS::Mark_XIIA_Interrogator:
    case KDIS::DATA_TYPE::ENUMS::Mode_5_Interrogator:
    case KDIS::DATA_TYPE::ENUMS::Mode_S_Interrogator:
#endif
      return false;
#if DIS_VERSION > 6
    case KDIS::DATA_TYPE::ENUMS::
        Mark_XIIA_Combined_Interrogator_Transponder_CIT:
    case KDIS::DATA_TYPE::ENUMS::Mark_XII_Combined_Interrogator_Transponder_CIT:
    case KDIS::DATA_TYPE::ENUMS::TCAS_ACAS_Transceiver:
      // B.2.4 Change/Options record, section e
      return SI.GetTransponderInterrogatorIndicator() == false;
#endif
    default:
      throw KException(ErrorCode::UNSUPPORTED_DATATYPE,
                       KDIS::UTILS::format("Unknown System %s | %u",
                                           __FUNCTION__, SI.GetSystemType()));
  }
}

template <typename T>
bool CompareSharedPtrNE(const T& lhs, const T& rhs) {
  if (lhs == nullptr && rhs == nullptr) return false;
  if (lhs == rhs) return false;
  if ((lhs == nullptr) != (rhs == nullptr)) return true;
  return *lhs != *rhs;
}

}  // namespace

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

IFF_PDU* IFF_PDU::clone() const { return new IFF_PDU(*this); }

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IFF_PDU::IFF_PDU() {
  m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
  m_ui8PDUType = IFF_ATC_NAVAIDS_PDU_Type;
  m_ui16PDULength = IFF_PDU_SIZE;

#if DIS_VERSION > 6
  m_ui8ProtocolVersion = IEEE_1278_1_2012;
#else
  m_ui8ProtocolVersion = IEEE_1278_1A_1998;
#endif
}

//////////////////////////////////////////////////////////////////////////

IFF_PDU::IFF_PDU(const Header& H) : Header(H) {}

//////////////////////////////////////////////////////////////////////////

IFF_PDU::IFF_PDU(KDataStream& stream) { Decode(stream, false); }

//////////////////////////////////////////////////////////////////////////

IFF_PDU::IFF_PDU(const Header& H, KDataStream& stream) : Header(H) {
  Decode(stream, true);
}

//////////////////////////////////////////////////////////////////////////

IFF_PDU::IFF_PDU(const EntityIdentifier& EmittingID,
                 const EntityIdentifier& EventID, const Vector& Location,
                 const SystemIdentifier& ID,
                 const FundamentalOperationalData& FOD)
    : m_EmittingEntityID(EmittingID),
      m_EventID(EventID),
      m_Location(Location),
      m_SystemID(ID),
      m_FOD(FOD),
      m_ui8SystemDesignator(0),
      m_ui8SystemSpecific(0) {
  m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
  m_ui8PDUType = IFF_ATC_NAVAIDS_PDU_Type;
  m_ui16PDULength = IFF_PDU_SIZE;

#if DIS_VERSION > 6
  m_ui8ProtocolVersion = IEEE_1278_1_2012;
#else
  m_ui8ProtocolVersion = IEEE_1278_1A_1998;
#endif
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetEmittingEntityID(const EntityIdentifier& ID) {
  m_EmittingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier& IFF_PDU::GetEmittingEntityID() const {
  return m_EmittingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier& IFF_PDU::GetEmittingEntityID() { return m_EmittingEntityID; }

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetEventID(const EntityIdentifier& ID) { m_EventID = ID; }

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier& IFF_PDU::GetEventID() const { return m_EventID; }

//////////////////////////////////////////////////////////////////////////

EntityIdentifier& IFF_PDU::GetEventID() { return m_EventID; }

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetLocation(const Vector& L) { m_Location = L; }

//////////////////////////////////////////////////////////////////////////

const Vector& IFF_PDU::GetLocation() const { return m_Location; }

//////////////////////////////////////////////////////////////////////////

Vector& IFF_PDU::GetLocation() { return m_Location; }

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetSystemIdentifier(const SystemIdentifier& ID) {
  m_SystemID = ID;
}

//////////////////////////////////////////////////////////////////////////

const SystemIdentifier& IFF_PDU::GetSystemIdentifier() const {
  return m_SystemID;
}

//////////////////////////////////////////////////////////////////////////

SystemIdentifier& IFF_PDU::GetSystemIdentifier() { return m_SystemID; }

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetFundamentalOperationalData(
    const FundamentalOperationalData& FOD) {
  m_FOD = FOD;
}

//////////////////////////////////////////////////////////////////////////

const FundamentalOperationalData& IFF_PDU::GetFundamentalOperationalData()
    const {
  return m_FOD;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData& IFF_PDU::GetFundamentalOperationalData() {
  return m_FOD;
}

//////////////////////////////////////////////////////////////////////////

#if DIS_VERSION > 6

void IFF_PDU::SetSystemDesignator(KUINT8 SD) { m_ui8SystemDesignator = SD; }

//////////////////////////////////////////////////////////////////////////

KUINT8 IFF_PDU::GetSystemDesignator() const { return m_ui8SystemDesignator; }

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetSystemSpecificData(KUINT8 SSD) { m_ui8SystemSpecific = SSD; }

//////////////////////////////////////////////////////////////////////////

KUINT8 IFF_PDU::GetSystemSpecificData() const { return m_ui8SystemSpecific; }

#endif

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetLayer(const std::shared_ptr<KDIS::DATA_TYPE::LayerHeader>& L) {
  switch (L->GetLayerNumber()) {
    case 2:
      m_pLayer2 = std::dynamic_pointer_cast<KDIS::DATA_TYPE::IFF_Layer2>(L);
      break;
#if DIS_VERSION > 6
    case 3:
      if (IsTransponder(m_SystemID)) {
        m_pLayer3Transponder =
            std::dynamic_pointer_cast<KDIS::DATA_TYPE::IFF_Layer3Transponder>(
                L);
      } else {
        m_pLayer3Interrogator =
            std::dynamic_pointer_cast<KDIS::DATA_TYPE::IFF_Layer3Interrogator>(
                L);
      }
      break;
    case 4:
    case 5:
      throw KException(ErrorCode::UNSUPPORTED_DATATYPE,
                       KDIS::UTILS::format("Not implemented: %s | %u",
                                           __FUNCTION__, L->GetLayerNumber()));
#endif
    default:
      throw KException(ErrorCode::UNSUPPORTED_DATATYPE,
                       KDIS::UTILS::format("Invalid layer number: %s | %u",
                                           __FUNCTION__, L->GetLayerNumber()));
  }
  m_ui16PDULength += L->GetLayerLength();
}

//////////////////////////////////////////////////////////////////////////

std::shared_ptr<LayerHeader> IFF_PDU::GetLayer(KUINT8 LayerNumber) {
  switch (LayerNumber) {
    case 2:
      return m_pLayer2;
#if DIS_VERSION > 6
    case 3:
      return IsTransponder(m_SystemID)
                 ? std::dynamic_pointer_cast<LayerHeader>(m_pLayer3Transponder)
                 : std::dynamic_pointer_cast<LayerHeader>(
                       m_pLayer3Interrogator);
    case 4:
    case 5:
      throw KException(ErrorCode::UNSUPPORTED_DATATYPE,
                       KDIS::UTILS::format("Not implemented: %s | %u",
                                           __FUNCTION__, LayerNumber));
#endif
    default:
      throw KException(ErrorCode::UNSUPPORTED_DATATYPE,
                       KDIS::UTILS::format("Invalid layer number: %s | %u",
                                           __FUNCTION__, LayerNumber));
  }
}

std::shared_ptr<KDIS::DATA_TYPE::IFF_Layer2> IFF_PDU::GetLayer2() {
  return m_pLayer2;
}

//////////////////////////////////////////////////////////////////////////

#if DIS_VERSION > 6

std::shared_ptr<KDIS::DATA_TYPE::IFF_Layer3> IFF_PDU::GetLayer3() {
  if (IsTransponder(m_SystemID)) {
    return m_pLayer3Transponder;
  } else {
    return m_pLayer3Interrogator;
  }
}

//////////////////////////////////////////////////////////////////////////

std::shared_ptr<KDIS::DATA_TYPE::IFF_Layer3Transponder>
IFF_PDU::GetLayer3Transponder() {
  return m_pLayer3Transponder;
}

//////////////////////////////////////////////////////////////////////////

std::shared_ptr<KDIS::DATA_TYPE::IFF_Layer3Interrogator>
IFF_PDU::GetLayer3Interrogator() {
  return m_pLayer3Interrogator;
}

#endif

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::ClearLayer(KUINT8 LayerNumber) {
  switch (LayerNumber) {
    case 2:
      if (m_pLayer2) {
        m_ui16PDULength -= m_pLayer2->GetLayerLength();
      }
      m_pLayer2.reset();
      break;
#if DIS_VERSION > 6
    case 3:
      if (m_pLayer3Transponder) {
        m_ui16PDULength -= m_pLayer3Transponder->GetLayerLength();
        m_pLayer3Transponder.reset();
      }
      if (m_pLayer3Interrogator) {
        m_ui16PDULength -= m_pLayer3Interrogator->GetLayerLength();
        m_pLayer3Interrogator.reset();
      }
      break;
    case 4:
    case 5:
      throw KException(ErrorCode::UNSUPPORTED_DATATYPE,
                       KDIS::UTILS::format("Not implemented: %s | %u",
                                           __FUNCTION__, LayerNumber));
#endif
    default:
      throw KException(ErrorCode::UNSUPPORTED_DATATYPE,
                       KDIS::UTILS::format("Invalid layer number: %s | %u",
                                           __FUNCTION__, LayerNumber));
  }
}

//////////////////////////////////////////////////////////////////////////

KString IFF_PDU::GetAsString() const {
  KStringStream ss;

  ss << Header::GetAsString() << "-IFF/ATC/NAVAIDS Layer 1 PDU-\n"
     << "Emitting Entity ID:\n"
     << IndentString(m_EmittingEntityID.GetAsString(), 1) << "Event ID:\n"
     << IndentString(m_EventID.GetAsString(), 1)
     << "Location:    " << m_Location.GetAsString() << m_SystemID.GetAsString()
     << m_FOD.GetAsString();

#if DIS_VERSION > 6

  ss << "System Designator:    " << m_ui8SystemDesignator << "\n"
     << "System Specific Data: " << m_ui8SystemSpecific << "\n";

#endif

  if (m_pLayer2) {
    ss << m_pLayer2->GetAsString();
  }
#if DIS_VERSION > 6
  if (m_pLayer3Transponder) {
    ss << m_pLayer3Transponder->GetAsString();
  }

  if (m_pLayer3Interrogator) {
    ss << m_pLayer3Interrogator->GetAsString();
  }
#endif
  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::Decode(KDataStream& stream, bool ignoreHeader /*= true*/) {
  if ((stream.GetBufferSize() + (ignoreHeader ? Header::HEADER6_PDU_SIZE : 0)) <
      IFF_PDU_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  Header::Decode(stream, ignoreHeader);

  // Record the size of the stream so we can calculate how much data is left. We
  // could just use stream.GetBufferSize() but what if this PDU was part of a
  // PDU bundle...
  KUINT32 streamSizeSnapshot = stream.GetBufferSize();

  stream >> KDIS_STREAM m_EmittingEntityID >> KDIS_STREAM m_EventID >>
      KDIS_STREAM m_Location >> KDIS_STREAM m_SystemID >>
      m_ui8SystemDesignator >> m_ui8SystemSpecific >> KDIS_STREAM m_FOD;

  KUINT16 remainingData = m_ui16PDULength - HEADER6_PDU_SIZE -
                          (streamSizeSnapshot - stream.GetBufferSize());

  // Decode each layer
  while (remainingData) {
    LayerHeader hdr(stream);

    switch (hdr.GetLayerNumber()) {
      case 2:
        m_pLayer2 = std::make_shared<IFF_Layer2>(hdr, stream);
        remainingData -= m_pLayer2->GetLayerLength();
        break;

#if DIS_VERSION > 6
      case 3:
        if (IsTransponder(m_SystemID)) {
          m_pLayer3Transponder =
              std::make_shared<IFF_Layer3Transponder>(hdr, stream);
          remainingData -= m_pLayer3Transponder->GetLayerLength();
        } else {
          m_pLayer3Interrogator =
              std::make_shared<IFF_Layer3Interrogator>(hdr, stream);
          remainingData -= m_pLayer3Interrogator->GetLayerLength();
        }

        break;
#endif

        // case 4: layer = new IFF_Layer4( hdr, stream ); break;
        // case 5: layer = new IFF_Layer5( hdr, stream ); break;

      default:
        throw KException(
            ErrorCode::UNSUPPORTED_DATATYPE,
            KDIS::UTILS::format("%s | %u", __FUNCTION__, hdr.GetLayerNumber()));
    }
  }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IFF_PDU::Encode() const {
  KDataStream stream;

  IFF_PDU::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::Encode(KDataStream& stream) const {
  Header::Encode(stream);

  stream << KDIS_STREAM m_EmittingEntityID << KDIS_STREAM m_EventID
         << KDIS_STREAM m_Location << KDIS_STREAM m_SystemID
         << m_ui8SystemDesignator << m_ui8SystemSpecific << KDIS_STREAM m_FOD;

  if (m_pLayer2) {
    m_pLayer2->Encode(stream);
  }
#if DIS_VERSION > 6
  if (m_pLayer3Transponder) {
    m_pLayer3Transponder->Encode(stream);
  }
  if (m_pLayer3Interrogator) {
    m_pLayer3Interrogator->Encode(stream);
  }
#endif
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_PDU::operator==(const IFF_PDU& Value) const {
  if (Header::operator!=(Value)) return false;
  if (m_EmittingEntityID != Value.m_EmittingEntityID) return false;
  if (m_EventID != Value.m_EventID) return false;
  if (m_Location != Value.m_Location) return false;
  if (m_SystemID != Value.m_SystemID) return false;
  if (m_FOD != Value.m_FOD) return false;
  if (CompareSharedPtrNE(m_pLayer2, Value.m_pLayer2)) return false;
#if DIS_VERSION > 6
  if (CompareSharedPtrNE(m_pLayer3Transponder, Value.m_pLayer3Transponder))
    return false;
  if (CompareSharedPtrNE(m_pLayer3Interrogator, Value.m_pLayer3Interrogator))
    return false;
#endif
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_PDU::operator!=(const IFF_PDU& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
