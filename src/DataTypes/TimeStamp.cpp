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

#include <iomanip>

#include "KDIS/DataTypes/TimeStamp.hpp"
#include "KDIS/utils/NumberConversions.hpp"
#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#else
#include <time.h>
#endif

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

const KFLOAT64 TimeStamp::SEC_PER_UNIT_TIME = (3600.0) / 2147483648.0;
const KFLOAT64 TimeStamp::UNIT_TIME_PER_SEC = 1.0 / SEC_PER_UNIT_TIME;
const KFLOAT64 TimeStamp::NANOSEC_PER_UNIT_TIME = SEC_PER_UNIT_TIME * 1.0e9;
const KFLOAT64 TimeStamp::UNIT_TIME_PER_NANOSEC = 1.0 / NANOSEC_PER_UNIT_TIME;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

TimeStamp::TimeStamp() : m_bAutoCalcRel(false) {
  m_TimeStampUnion.m_ui32TimeStamp = 0;
}

//////////////////////////////////////////////////////////////////////////

TimeStamp::TimeStamp(KDataStream& stream) : m_bAutoCalcRel(false) {
  Decode(stream);
}

//////////////////////////////////////////////////////////////////////////

TimeStamp::TimeStamp(TimeStampType T, KUINT32 Time,
                     KBOOL AutoCalcRelative /*= false*/)
    : m_bAutoCalcRel(AutoCalcRelative) {
  m_TimeStampUnion.m_ui32TimeStampType = T;
  m_TimeStampUnion.m_ui32Time = Time;
}

//////////////////////////////////////////////////////////////////////////

TimeStamp::~TimeStamp() {}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::SetTimeStampType(TimeStampType T) {
  m_TimeStampUnion.m_ui32TimeStampType = T;
}

//////////////////////////////////////////////////////////////////////////

TimeStampType TimeStamp::GetTimeStampType() const {
  return (TimeStampType)m_TimeStampUnion.m_ui32TimeStampType;
}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::SetTime(KUINT32 T) { m_TimeStampUnion.m_ui32Time = T; }

//////////////////////////////////////////////////////////////////////////

KUINT32 TimeStamp::GetTime() const { return m_TimeStampUnion.m_ui32Time; }

//////////////////////////////////////////////////////////////////////////

void TimeStamp::SetTimeStampAutoCalculate(KBOOL A) { m_bAutoCalcRel = A; }

//////////////////////////////////////////////////////////////////////////

KBOOL TimeStamp::IsTimeStampAutoCalculated() const { return m_bAutoCalcRel; }

//////////////////////////////////////////////////////////////////////////

void TimeStamp::CalculateTimeStamp() {
  // Calculate the time by taking the minutes, seconds and milliseconds(if
  // supported by os) since the hour and dividing them by 0.000001676
  KINT32 iTs = 0;

#if defined(WIN32) | defined(WIN64)  // Microsoft Windows

  SYSTEMTIME now;
  GetSystemTime(&now);
  KFLOAT64 f = (now.wMinute * 60) + now.wSecond + (now.wMilliseconds / 1000.0);
  iTs = KDIS::UTILS::double_to_int32(f * UNIT_TIME_PER_SEC);

#else

  time_t aclock;
  time(&aclock);
  struct tm* newtime = localtime(&aclock);
  iTs = newtime->tm_sec + (newtime->tm_min * 60);
  iTs = iTs * UNIT_TIME_PER_SEC;

#endif

#if defined(linux)  // Linux -- Note: You need to include the rt library for
                    // clock_gettime.

  // Add nano seconds
  timespec ts;
  clock_gettime(0, &ts);
  iTs += ts.tv_nsec * UNIT_TIME_PER_NANOSEC;

#endif

  m_TimeStampUnion.m_ui32Time = iTs;
}

//////////////////////////////////////////////////////////////////////////

KString TimeStamp::GetAsString() const {
  // Each time unit is 3600/(2^31) seconds.
  KFLOAT64 totalsecs =
      static_cast<KFLOAT64>(m_TimeStampUnion.m_ui32TimeStamp >> 1) *
      SEC_PER_UNIT_TIME;
  KUINT16 minutes = static_cast<KINT16>(totalsecs) / 60;
  KFLOAT64 seconds = totalsecs - (60 * minutes);

  KStringStream ss;

  ss << "Timestamp:       ";
  ss << std::setfill('0') << std::setw(2) << minutes << ":" << std::setfill('0')
     << std::setw(2) << seconds << " ("
     << GetEnumAsStringTimeStampType(m_TimeStampUnion.m_ui32TimeStampType)
     << ") " << "\n";

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::Decode(KDataStream& stream) {
  if (stream.GetBufferSize() < TIME_STAMP_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  stream >> m_TimeStampUnion.m_ui32TimeStamp;
}

//////////////////////////////////////////////////////////////////////////

KDataStream TimeStamp::Encode() const {
  KDataStream stream;

  TimeStamp::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::Encode(KDataStream& stream) const {
  // Do we need to calculate the timestamp first?
  if (m_bAutoCalcRel) {
    // We need to cast away the const so we can make the change.
    TimeStamp* self = const_cast<TimeStamp*>(this);
    self->CalculateTimeStamp();
  }

  stream << m_TimeStampUnion.m_ui32TimeStamp;
}

//////////////////////////////////////////////////////////////////////////

KBOOL TimeStamp::operator==(const TimeStamp& Value) const {
  if (m_TimeStampUnion.m_ui32TimeStamp !=
      Value.m_TimeStampUnion.m_ui32TimeStamp)
    return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL TimeStamp::operator!=(const TimeStamp& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////

KBOOL TimeStamp::operator<(const TimeStamp& Value) const {
  // Note: We don't check if the time stamps are the same type.
  return m_TimeStampUnion.m_ui32Time < Value.m_TimeStampUnion.m_ui32Time;
}

//////////////////////////////////////////////////////////////////////////
