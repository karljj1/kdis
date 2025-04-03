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

#include "KDIS/DataTypes/LinearObjectAppearance.hpp"
#include "KDIS/utils/format.hpp"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance::LinearObjectAppearance() {
  m_SpecificAppearanceUnion.m_ui32SpecificAppearance = 0;
}

//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance::LinearObjectAppearance(KDataStream& stream) {
  Decode(stream);
}

//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance::~LinearObjectAppearance() {}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreach(Breach2bit B) {
  m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32Breach = B;
}

//////////////////////////////////////////////////////////////////////////

Breach2bit LinearObjectAppearance::GetBreach() const {
  return static_cast<Breach2bit>(
      m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32Breach);
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreachLength(KUINT8 L) {
  m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLength = L;
}

////////////////////////////////////////////////////////////////////////////

KUINT8 LinearObjectAppearance::GetBreachLength() const {
  return m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLength;
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreachLocation(const bitset<8>& L) {
  KUINT32 i = L.to_ulong();
  m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLoc =
      static_cast<KUINT8>(i);
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreachLocation(KUINT8 L) {
  m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLoc = L;
}

////////////////////////////////////////////////////////////////////////////

KUINT8 LinearObjectAppearance::GetBreachLocation() const {
  return m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLoc;
}

////////////////////////////////////////////////////////////////////////////

bitset<8> LinearObjectAppearance::GetBreachLocationAsBitset() {
  return bitset<8>(
      m_SpecificAppearanceUnion.m_TankDitchConcertinaWire.m_ui32BreachLoc);
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetOpacity(KUINT8 O) {
  if (O > 100)
    throw KException(
        ErrorCode::INVALID_DATA,
        KDIS::UTILS::format("%s | %u is not a valid opacity value. "
                            "Valid values are from 0 to 100",
                            __FUNCTION__, O));

  m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Opacity = O;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LinearObjectAppearance::GetOpacity() const {
  return m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Opacity;
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetAttached(KBOOL A) {
  m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Attached = A;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearObjectAppearance::IsAttached() const {
  return static_cast<KBOOL>(
      m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Attached);
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetChemical(Chemical C) {
  m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Chemical = C;
}

//////////////////////////////////////////////////////////////////////////

Chemical LinearObjectAppearance::GetChemical() const {
  return static_cast<Chemical>(
      m_SpecificAppearanceUnion.m_ExhaustSmoke.m_ui32Chemical);
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetVisibleSide(VisibleSide V) {
  m_SpecificAppearanceUnion.m_MinefieldLaneMarker.m_ui32VisibleSide = V;
}

//////////////////////////////////////////////////////////////////////////

VisibleSide LinearObjectAppearance::GetVisibleSide() const {
  return static_cast<VisibleSide>(
      m_SpecificAppearanceUnion.m_MinefieldLaneMarker.m_ui32VisibleSide);
}

//////////////////////////////////////////////////////////////////////////

KString LinearObjectAppearance::GetAsString() const {
  KStringStream ss;

  ss << ObjectAppearance::GetAsString() << "\tSpecific Appearance: "
     << m_SpecificAppearanceUnion.m_ui32SpecificAppearance << "\n";

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::Decode(KDataStream& stream) {
  if (stream.GetBufferSize() < LINEAR_OBJECT_APPEARANCE_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  // Note: The order of the bytes is switched in the linear appearance to fix an
  // alignment issue in the 1998 standard.
  stream >> m_GeneralAppearanceUnion.m_ui16GeneralAppearance >>
      m_SpecificAppearanceUnion.m_ui32SpecificAppearance;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LinearObjectAppearance::Encode() const {
  KDataStream stream;

  LinearObjectAppearance::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::Encode(KDataStream& stream) const {
  // First add the specific bytes and then the general.
  stream << m_GeneralAppearanceUnion.m_ui16GeneralAppearance
         << m_SpecificAppearanceUnion.m_ui32SpecificAppearance;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearObjectAppearance::operator==(
    const LinearObjectAppearance& Value) const {
  if (ObjectAppearance::operator!=(Value)) return false;
  if (m_SpecificAppearanceUnion.m_ui32SpecificAppearance !=
      Value.m_SpecificAppearanceUnion.m_ui32SpecificAppearance)
    return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearObjectAppearance::operator!=(
    const LinearObjectAppearance& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
