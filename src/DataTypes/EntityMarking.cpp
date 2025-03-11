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

#include "KDIS/DataTypes/EntityMarking.hpp"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityMarking::EntityMarking(KDataStream& stream) { Decode(stream); }

//////////////////////////////////////////////////////////////////////////

EntityMarking::EntityMarking(const EntityMarkingCharacterSet MarkingCharSet,
                             const KString& MarkingText) {
  SetEntityMarkingCharacterSet(MarkingCharSet);
  SetEntityMarkingString(MarkingText);
}

//////////////////////////////////////////////////////////////////////////

void EntityMarking::SetEntityMarkingCharacterSet(
    const EntityMarkingCharacterSet EMCS) {
  m_ui8EntityMarkingCharacterSet = EMCS;
}

//////////////////////////////////////////////////////////////////////////

EntityMarkingCharacterSet EntityMarking::GetEntityMarkingCharacterSet() const {
  return static_cast<EntityMarkingCharacterSet>(m_ui8EntityMarkingCharacterSet);
}

//////////////////////////////////////////////////////////////////////////

void EntityMarking::SetEntityMarkingString(const KString& EMS) {
  m_sEntityMarkingString.assign(EMS);
}

//////////////////////////////////////////////////////////////////////////

KString EntityMarking::GetEntityMarkingString() const {
  return m_sEntityMarkingString.str();
}

//////////////////////////////////////////////////////////////////////////

KString EntityMarking::GetAsString() const {
  KStringStream ss;

  ss << "Entity Marking:" << "\n\tMarking Char Set:      "
     << GetEnumAsStringEntityMarkingCharacterSet(m_ui8EntityMarkingCharacterSet)
     << "\n\tMarking String:       " << GetEntityMarkingString() << "\n";

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EntityMarking::Decode(KDataStream& stream) {
  const std::size_t bounded_len{m_sEntityMarkingString.max_size()};
  if (stream.GetBufferSize() < bounded_len)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  stream >> m_ui8EntityMarkingCharacterSet;

  for (KUINT16 i = 0; i < bounded_len - 1; ++i) {
    stream >> m_sEntityMarkingString[i];
  }
  m_sEntityMarkingString[bounded_len - 1] = '\0';
}

//////////////////////////////////////////////////////////////////////////

KDataStream EntityMarking::Encode() const {
  KDataStream stream;

  EntityMarking::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void EntityMarking::Encode(KDataStream& stream) const {
  stream << m_ui8EntityMarkingCharacterSet;

  for (KUINT16 i = 0; i < m_sEntityMarkingString.max_size() - 1; ++i) {
    stream << m_sEntityMarkingString[i];
  }
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityMarking::operator==(const EntityMarking& Value) const {
  if (m_ui8EntityMarkingCharacterSet != Value.m_ui8EntityMarkingCharacterSet)
    return false;
  return (m_sEntityMarkingString == Value.m_sEntityMarkingString);
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityMarking::operator!=(const EntityMarking& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
