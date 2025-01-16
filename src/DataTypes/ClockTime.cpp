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

#include "KDIS/DataTypes/ClockTime.hpp"

#include <iomanip>

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

const KFLOAT64 ClockTime::SEC_PER_UNIT_TIME = (3600.0) / 2147483648.0;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ClockTime::ClockTime() : m_i32Hour(0), m_ui32TimePastHour(0) {}

//////////////////////////////////////////////////////////////////////////

ClockTime::ClockTime(KINT32 Hour, KUINT32 TimePastHour)
    : m_i32Hour(Hour), m_ui32TimePastHour(TimePastHour) {}

//////////////////////////////////////////////////////////////////////////

ClockTime::ClockTime(KDataStream& stream) { Decode(stream); }

//////////////////////////////////////////////////////////////////////////

ClockTime::~ClockTime() {}

//////////////////////////////////////////////////////////////////////////

void ClockTime::SetHour(KINT32 H) { m_i32Hour = H; }

//////////////////////////////////////////////////////////////////////////

KINT32 ClockTime::GetHour() const { return m_i32Hour; }

//////////////////////////////////////////////////////////////////////////

void ClockTime::SetTimePastHour(KUINT32 TPH) { m_ui32TimePastHour = TPH; }

//////////////////////////////////////////////////////////////////////////

KUINT32 ClockTime::GetTimePastHour() const { return m_ui32TimePastHour; }

//////////////////////////////////////////////////////////////////////////

KString ClockTime::GetAsString() const {
  // Each time unit is 3600/(2^31) seconds.
  KFLOAT64 totalsecs =
      static_cast<KFLOAT64>(m_ui32TimePastHour >> 1) * SEC_PER_UNIT_TIME;
  KUINT16 minutes = static_cast<KINT16>(totalsecs) / 60;
  KFLOAT64 seconds = totalsecs - (60 * minutes);

  KStringStream ss;

  ss << "Hour:             " << std::setfill('0') << std::setw(2) << m_i32Hour
     << "\n"
     << "Time Past Hour:   " << std::setfill('0') << std::setw(2) << minutes
     << ":" << std::setfill('0') << std::setw(2) << seconds << " ("
     << GetEnumAsStringTimeStampType(m_ui32TimePastHour & 1) << ") " << "\n";

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ClockTime::Decode(KDataStream& stream) {
  if (stream.GetBufferSize() < CLOCK_TIME_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  stream >> m_i32Hour >> m_ui32TimePastHour;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ClockTime::Encode() const {
  KDataStream stream;

  ClockTime::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void ClockTime::Encode(KDataStream& stream) const {
  stream << m_i32Hour << m_ui32TimePastHour;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ClockTime::operator==(const ClockTime& Value) const {
  if (m_i32Hour != Value.m_i32Hour) return false;
  if (m_ui32TimePastHour != Value.m_ui32TimePastHour) return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ClockTime::operator!=(const ClockTime& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////

KBOOL ClockTime::operator<(const ClockTime& Value) const {
  if (m_i32Hour < Value.m_i32Hour) return true;
  if (m_i32Hour > Value.m_i32Hour) return false;

  return m_ui32TimePastHour < Value.m_ui32TimePastHour;
}

//////////////////////////////////////////////////////////////////////////
