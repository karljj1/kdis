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

#include "KDIS/PDU/Simulation_Management_With_Reliability/Create_Entity_R_PDU.hpp"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU* Create_Entity_R_PDU::clone() const {
  return new Create_Entity_R_PDU(*this);
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::Create_Entity_R_PDU() {
  m_ui8PDUType = CreateEntity_R_PDU_Type;
  m_ui16PDULength = CREATE_ENTITY_R_PDU_SIZE;
  m_ui8ProtocolVersion = IEEE_1278_1A_1998;
  m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::Create_Entity_R_PDU(const Header& H)
    : Create_Entity_PDU(H) {}

//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::Create_Entity_R_PDU(KDataStream& stream) {
  Decode(stream, false);
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::Create_Entity_R_PDU(const Header& H, KDataStream& stream)
    : Create_Entity_PDU(H) {
  Decode(stream, true);
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::Create_Entity_R_PDU(const EntityIdentifier& OrigintatingID,
                                         const EntityIdentifier& ReceivingID,
                                         KUINT32 RequestID,
                                         RequiredReliabilityService RRS)
    : Create_Entity_PDU(OrigintatingID, ReceivingID, RequestID),
      Reliability_Header(RRS) {
  m_ui8PDUType = CreateEntity_R_PDU_Type;
  m_ui16PDULength = CREATE_ENTITY_R_PDU_SIZE;
  m_ui8ProtocolVersion = IEEE_1278_1A_1998;
  m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::Create_Entity_R_PDU(
    const Simulation_Management_Header& SimMgrHeader, KUINT32 RequestID,
    RequiredReliabilityService RRS)
    : Create_Entity_PDU(SimMgrHeader, RequestID), Reliability_Header(RRS) {
  m_ui8PDUType = CreateEntity_R_PDU_Type;
  m_ui16PDULength = CREATE_ENTITY_R_PDU_SIZE;
  m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_R_PDU::~Create_Entity_R_PDU() {}

//////////////////////////////////////////////////////////////////////////

KString Create_Entity_R_PDU::GetAsString() const {
  KStringStream ss;

  ss << Header::GetAsString() << "-Create Entity-R PDU-\n"
     << Simulation_Management_Header::GetAsString()
     << Reliability_Header::GetAsString() << "Request ID: " << m_ui32RequestID
     << "\n";

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Create_Entity_R_PDU::Decode(KDataStream& stream,
                                 bool ignoreHeader /*= true*/) {
  if ((stream.GetBufferSize() + (ignoreHeader ? Header::HEADER6_PDU_SIZE : 0)) <
      CREATE_ENTITY_R_PDU_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  Simulation_Management_Header::Decode(stream, ignoreHeader);

  Reliability_Header::Decode(stream);

  stream >> m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Create_Entity_R_PDU::Encode() const {
  KDataStream stream;

  Create_Entity_R_PDU::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void Create_Entity_R_PDU::Encode(KDataStream& stream) const {
  Simulation_Management_Header::Encode(stream);

  Reliability_Header::Encode(stream);

  stream << m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Create_Entity_R_PDU::operator==(const Create_Entity_R_PDU& Value) const {
  if (Create_Entity_PDU::operator!=(Value)) return false;
  if (Reliability_Header::operator!=(Value)) return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Create_Entity_R_PDU::operator!=(const Create_Entity_R_PDU& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
