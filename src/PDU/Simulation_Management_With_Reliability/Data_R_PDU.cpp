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

#include "KDIS/PDU/Simulation_Management_With_Reliability/Data_R_PDU.hpp"

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

Data_R_PDU* Data_R_PDU::clone() const { return new Data_R_PDU(*this); }

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Data_R_PDU::Data_R_PDU() {
  m_ui8PDUType = Data_R_PDU_Type;
  m_ui16PDULength = DATA_R_PDU_SIZE;
  m_ui8ProtocolVersion = IEEE_1278_1A_1998;
  m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Data_R_PDU::Data_R_PDU(const Header& H) : Data_PDU(H) {}

//////////////////////////////////////////////////////////////////////////

Data_R_PDU::Data_R_PDU(KDataStream& stream) { Decode(stream, false); }

//////////////////////////////////////////////////////////////////////////

Data_R_PDU::Data_R_PDU(const Header& H, KDataStream& stream) : Data_PDU(H) {
  Decode(stream, true);
}

//////////////////////////////////////////////////////////////////////////

Data_R_PDU::Data_R_PDU(const EntityIdentifier& OriginatingEntityID,
                       const EntityIdentifier& ReceivingEntityID,
                       KUINT32 RequestID, RequiredReliabilityService RRS)
    : Data_PDU(OriginatingEntityID, ReceivingEntityID, RequestID),
      Reliability_Header(RRS) {
  m_ui8PDUType = Data_R_PDU_Type;
  m_ui16PDULength = DATA_R_PDU_SIZE;
  m_ui8ProtocolVersion = IEEE_1278_1A_1998;
  m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Data_R_PDU::~Data_R_PDU() {}

//////////////////////////////////////////////////////////////////////////

KString Data_R_PDU::GetAsString() const {
  KStringStream ss;

  ss << Header::GetAsString() << "-Data PDU-\n"
     << Simulation_Management_Header::GetAsString()
     << "\tRequest ID:                " << m_ui32RequestID
     << Reliability_Header::GetAsString()
     << "\n\tNumber Fixed Datum:        " << m_ui32NumFixedDatum
     << "\n\tNumber Variable Datum:     " << m_ui32NumVariableDatum << "\n";

  ss << "Fixed Datumn";
  vector<FixDtmPtr>::const_iterator citrFixed = m_vFixedDatum.begin();
  vector<FixDtmPtr>::const_iterator citrFixedEnd = m_vFixedDatum.end();
  for (; citrFixed != citrFixedEnd; ++citrFixed) {
    ss << IndentString((*citrFixed)->GetAsString());
  }

  ss << "Variable Datumn";
  vector<VarDtmPtr>::const_iterator citrVar = m_vVariableDatum.begin();
  vector<VarDtmPtr>::const_iterator citrVarEnd = m_vVariableDatum.end();
  for (; citrVar != citrVarEnd; ++citrVar) {
    ss << IndentString((*citrVar)->GetAsString());
  }

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Data_R_PDU::Decode(KDataStream& stream, bool ignoreHeader /*= true*/) {
  if ((stream.GetBufferSize() + (ignoreHeader ? Header::HEADER6_PDU_SIZE : 0)) <
      DATA_R_PDU_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  Simulation_Management_Header::Decode(stream, ignoreHeader);

  stream >> m_ui32RequestID;

  Reliability_Header::Decode(stream);

  stream >> m_ui32NumFixedDatum >> m_ui32NumVariableDatum;

  // FixedDatum
  for (KUINT16 i = 0; i < m_ui32NumFixedDatum; ++i) {
    // Save the current write position so we can peek.
    KUINT16 pos = stream.GetCurrentWritePosition();
    KUINT32 datumID;

    // Extract the datum id then reset the stream.
    stream >> datumID;
    stream.SetCurrentWritePosition(pos);

    // Use the factory decoder.
    FixedDatum* p = FixedDatum::FactoryDecode(datumID, stream);

    // Did we find a custom decoder? if not then use the default.
    if (p) {
      m_vFixedDatum.push_back(FixDtmPtr(p));
    } else {
      // Default
      m_vFixedDatum.push_back(FixDtmPtr(new FixedDatum(stream)));
    }
  }

  // VariableDatum
  for (KUINT16 i = 0; i < m_ui32NumVariableDatum; ++i) {
    // Save the current write position so we can peek.
    KUINT16 pos = stream.GetCurrentWritePosition();
    KUINT32 datumID;

    // Extract the datum id then reset the stream.
    stream >> datumID;
    stream.SetCurrentWritePosition(pos);

    // Use the factory decoder.
    VariableDatum* p = VariableDatum::FactoryDecode(datumID, stream);

    // Did we find a custom decoder? if not then use the default.
    if (p) {
      m_vVariableDatum.push_back(VarDtmPtr(p));
    } else {
      // Default
      m_vVariableDatum.push_back(VarDtmPtr(new VariableDatum(stream)));
    }
  }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Data_R_PDU::Encode() const {
  KDataStream stream;

  Data_R_PDU::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void Data_R_PDU::Encode(KDataStream& stream) const {
  Simulation_Management_Header::Encode(stream);

  stream << m_ui32RequestID;

  Reliability_Header::Encode(stream);

  stream << m_ui32NumFixedDatum << m_ui32NumVariableDatum;

  vector<FixDtmPtr>::const_iterator citrFixed = m_vFixedDatum.begin();
  vector<FixDtmPtr>::const_iterator citrFixedEnd = m_vFixedDatum.end();
  for (; citrFixed != citrFixedEnd; ++citrFixed) {
    (*citrFixed)->Encode(stream);
  }

  vector<VarDtmPtr>::const_iterator citrVar = m_vVariableDatum.begin();
  vector<VarDtmPtr>::const_iterator citrVarEnd = m_vVariableDatum.end();
  for (; citrVar != citrVarEnd; ++citrVar) {
    (*citrVar)->Encode(stream);
  }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Data_R_PDU::operator==(const Data_R_PDU& Value) const {
  if (Data_PDU::operator!=(Value)) return false;
  if (Reliability_Header::operator!=(Value)) return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Data_R_PDU::operator!=(const Data_R_PDU& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
