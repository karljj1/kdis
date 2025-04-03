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

#include <cstdint>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

#include "KDIS/DataTypes/EntityType.hpp"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityType::EntityType(EntityKind Kind, KUINT8 Domain, Country Country,
                       KUINT8 Categoy, KUINT8 SubCategory, KUINT8 Specific,
                       KUINT8 Extra)
    : m_ui8EntityKind(Kind),
      m_ui8Domain(Domain),
      m_ui16Country(Country),
      m_ui8Category(Categoy),
      m_ui8SubCategory(SubCategory),
      m_ui8Specific(Specific),
      m_ui8Extra(Extra) {}

//////////////////////////////////////////////////////////////////////////

EntityType::EntityType(KUINT8 Kind, KUINT8 Domain, KUINT16 Country,
                       KUINT8 Categoy, KUINT8 SubCategory, KUINT8 Specific,
                       KUINT8 Extra)
    : m_ui8EntityKind(Kind),
      m_ui8Domain(Domain),
      m_ui16Country(Country),
      m_ui8Category(Categoy),
      m_ui8SubCategory(SubCategory),
      m_ui8Specific(Specific),
      m_ui8Extra(Extra) {}

//////////////////////////////////////////////////////////////////////////

EntityType::EntityType(KDataStream& stream) { Decode(stream); }

//////////////////////////////////////////////////////////////////////////

void EntityType::SetEntityKind(EntityKind UI) { m_ui8EntityKind = UI; }

//////////////////////////////////////////////////////////////////////////

EntityKind EntityType::GetEntityKind() const {
  return static_cast<EntityKind>(m_ui8EntityKind);
}

//////////////////////////////////////////////////////////////////////////

void EntityType::SetDomain(EntityDomain UI) { m_ui8Domain = UI; }

//////////////////////////////////////////////////////////////////////////

EntityDomain EntityType::GetDomain() const {
  return static_cast<EntityDomain>(m_ui8Domain);
}

//////////////////////////////////////////////////////////////////////////

void EntityType::SetCountry(Country UI) { m_ui16Country = UI; }

//////////////////////////////////////////////////////////////////////////

Country EntityType::GetCountry() const {
  return static_cast<Country>(m_ui16Country);
}

//////////////////////////////////////////////////////////////////////////

void EntityType::SetCategory(KUINT8 UI) { m_ui8Category = UI; }

//////////////////////////////////////////////////////////////////////////

KUINT8 EntityType::GetCategory() const { return m_ui8Category; }

//////////////////////////////////////////////////////////////////////////

void EntityType::SetSubCategory(KUINT8 UI) { m_ui8SubCategory = UI; }

//////////////////////////////////////////////////////////////////////////

KUINT8 EntityType::GetSubCategory() const { return m_ui8SubCategory; }

//////////////////////////////////////////////////////////////////////////

void EntityType::SetSpecific(KUINT8 UI) { m_ui8Specific = UI; }

//////////////////////////////////////////////////////////////////////////

KUINT8 EntityType::GetSpecific() const { return m_ui8Specific; }

//////////////////////////////////////////////////////////////////////////

void EntityType::SetExtra(KUINT8 UI) { m_ui8Extra = UI; }

//////////////////////////////////////////////////////////////////////////

KUINT8 EntityType::GetExtra() const { return m_ui8Extra; }

//////////////////////////////////////////////////////////////////////////

void EntityType::ReadFromTokenisedString(const KString& String,
                                         KCHAR8 Separator /*= ','*/) {
  KStringStream ss(String);
  KString token;
  int nn{0};

  // This logic can be simplified with auto lambda params once we move to C++14
  for (; nn < 8 && std::getline(ss, token, Separator); nn++) {
    if (2 == nn) {  // 3rd iteration contains a 16 bit value
      std::int16_t tk = std::stoi(token);
      if (tk < 0) tk = 0;  // make negative values 0
      m_ui16Country = tk;
    } else {  // all other iterations contain an 8 bit value
      std::int8_t tk = std::stoi(token);
      if (tk < 0) tk = 0;  // make negative values 0
      switch (nn) {
        case 0:
          m_ui8EntityKind = tk;
          break;
        case 1:
          m_ui8Domain = tk;
          break;
        case 3:
          m_ui8Category = tk;
          break;
        case 4:
          m_ui8SubCategory = tk;
          break;
        case 5:
          m_ui8Specific = tk;
          break;
        case 6:
          m_ui8Extra = tk;
          break;
        default:
          break;
      }
    }
  }

  if (7 != nn) {
    std::stringstream ss;
    ss << __FUNCTION__ << " | Token string [" << String
       << "] must contain 7 integer values only";
    throw KException(ErrorCode::INVALID_DATA, ss.str());
  }
}

//////////////////////////////////////////////////////////////////////////

KString EntityType::CreateTokenisedString(KCHAR8 Separator /*= ','*/) const {
  KStringStream ss;

  ss << static_cast<KUINT16>(m_ui8EntityKind) << Separator
     << static_cast<KUINT16>(m_ui8Domain) << Separator << m_ui16Country
     << Separator << static_cast<KUINT16>(m_ui8Category) << Separator
     << static_cast<KUINT16>(m_ui8SubCategory) << Separator
     << static_cast<KUINT16>(m_ui8Specific) << Separator
     << static_cast<KUINT16>(m_ui8Extra);

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KString EntityType::GetAsString() const {
  KStringStream ss;

  ss << CreateTokenisedString() << "\n";

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EntityType::Decode(KDataStream& stream) {
  if (stream.GetBufferSize() < ENTITY_TYPE_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  stream >> m_ui8EntityKind >> m_ui8Domain >> m_ui16Country >> m_ui8Category >>
      m_ui8SubCategory >> m_ui8Specific >> m_ui8Extra;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EntityType::Encode() const {
  KDataStream stream;

  EntityType::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void EntityType::Encode(KDataStream& stream) const {
  stream << m_ui8EntityKind << m_ui8Domain << m_ui16Country << m_ui8Category
         << m_ui8SubCategory << m_ui8Specific << m_ui8Extra;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityType::operator==(const EntityType& Value) const {
  if (m_ui8EntityKind != Value.m_ui8EntityKind) return false;
  if (m_ui8Domain != Value.m_ui8Domain) return false;
  if (m_ui16Country != Value.m_ui16Country) return false;
  if (m_ui8Category != Value.m_ui8Category) return false;
  if (m_ui8SubCategory != Value.m_ui8SubCategory) return false;
  if (m_ui8Specific != Value.m_ui8Specific) return false;
  if (m_ui8Extra != Value.m_ui8Extra) return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityType::operator!=(const EntityType& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityType::operator<(const EntityType& Value) const {
  // We will bit shift all 7 fields into a single KUINT64, this will generate
  // a new unique value which we can then use for comparisons. bits 56-63 =
  // EntityKind bits 48-55 = Domain bits 32-47 = Country bits 24-31 = Category
  // bits 16-23 = SubCategory
  // bits 8-15  = Specific
  // bits 0-7   = Extra
  KUINT64 ui64ThisCmpVal = 0, ui64OtherCmpVal = 0;

  ui64ThisCmpVal = static_cast<KUINT64>(m_ui8EntityKind) << 56 |
                   static_cast<KUINT64>(m_ui8Domain) << 48 |
                   static_cast<KUINT64>(m_ui16Country) << 32 |
                   static_cast<KUINT64>(m_ui8Category) << 24 |
                   static_cast<KUINT64>(m_ui8SubCategory) << 16 |
                   static_cast<KUINT64>(m_ui8Specific) << 8 |
                   static_cast<KUINT64>(m_ui8Extra);

  ui64OtherCmpVal = static_cast<KUINT64>(Value.m_ui8EntityKind) << 56 |
                    static_cast<KUINT64>(Value.m_ui8Domain) << 48 |
                    static_cast<KUINT64>(Value.m_ui16Country) << 32 |
                    static_cast<KUINT64>(Value.m_ui8Category) << 24 |
                    static_cast<KUINT64>(Value.m_ui8SubCategory) << 16 |
                    static_cast<KUINT64>(Value.m_ui8Specific) << 8 |
                    static_cast<KUINT64>(Value.m_ui8Extra);

  return ui64ThisCmpVal < ui64OtherCmpVal;
}

//////////////////////////////////////////////////////////////////////////
