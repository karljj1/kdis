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

#include "KDIS/DataTypes/EnvironmentRecord.hpp"

#include "KDIS/DataTypes/BoundingSphereRecord.hpp"
#include "KDIS/DataTypes/COMBICState.hpp"
#include "KDIS/DataTypes/ConeRecord1.hpp"
#include "KDIS/DataTypes/ConeRecord2.hpp"
#include "KDIS/DataTypes/EllipsoidRecord1.hpp"
#include "KDIS/DataTypes/EllipsoidRecord2.hpp"
#include "KDIS/DataTypes/FlareState.hpp"
#include "KDIS/DataTypes/GaussianPlumeRecord.hpp"
#include "KDIS/DataTypes/GaussianPuffRecord.hpp"
#include "KDIS/DataTypes/LineRecord1.hpp"
#include "KDIS/DataTypes/LineRecord2.hpp"
#include "KDIS/DataTypes/PointRecord1.hpp"
#include "KDIS/DataTypes/PointRecord2.hpp"
#include "KDIS/DataTypes/RectangularVolumeRecord1.hpp"
#include "KDIS/DataTypes/RectangularVolumeRecord2.hpp"
#include "KDIS/DataTypes/RectangularVolumeRecord3.hpp"
#include "KDIS/DataTypes/SphereRecord1.hpp"
#include "KDIS/DataTypes/SphereRecord2.hpp"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

EnvironmentRecord::EnvironmentRecord()
    : m_ui32EnvRecTyp(0), m_ui16Length(0), m_ui8Index(0), m_ui8Padding(0) {}

//////////////////////////////////////////////////////////////////////////

EnvironmentRecord::~EnvironmentRecord() {}

//////////////////////////////////////////////////////////////////////////

KUINT16 EnvironmentRecord::GetLength() const { return m_ui16Length; }

//////////////////////////////////////////////////////////////////////////

EnvironmentRecordType EnvironmentRecord::GetEnvironmentRecordType() const {
  return (EnvironmentRecordType)m_ui32EnvRecTyp;
}

//////////////////////////////////////////////////////////////////////////

void EnvironmentRecord::SetIndex(KUINT8 I) { m_ui8Index = I; }

//////////////////////////////////////////////////////////////////////////

KUINT8 EnvironmentRecord::GetIndex() const { return m_ui8Index; }

//////////////////////////////////////////////////////////////////////////

KString EnvironmentRecord::GetAsString() const {
  KStringStream ss;

  ss << "Environment Record\n"
     << "\tRecord Type: "
     << GetEnumAsStringEnvironmentRecordType(m_ui32EnvRecTyp) << "\n"
     << "\tLength:      " << m_ui16Length << "\n"
     << "\tIndex:       " << (KUINT16)m_ui8Index << "\n";

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

EnvironmentRecordPtr EnvironmentRecord::FactoryDecodeEnvironmentRecord(
    KDataStream& stream) {
  // We now need to "peak" at the next 4 bytes to determine the Environment
  // Record type, once we have determined the type we need to return the buffers
  // write positon as this field needs to be re-read by the decode function of
  // the derived Environment Record.
  KUINT16 ui16CurrentWritePos = stream.GetCurrentWritePosition();

  KUINT32 ui32RecType;
  stream >> ui32RecType;

  // We now know what type of record we should create, we need to reset the
  // buffer so this value can be re-read.
  stream.SetCurrentWritePosition(ui16CurrentWritePos);

  // Check for a custom decoder, if none if found then use one of our standard
  // data types.
  EnvironmentRecord* pRec = FactoryDecode(ui32RecType, stream);
  if (pRec) {
    return EnvironmentRecordPtr(pRec);
  }

  switch (ui32RecType) {
    //
    // Geometry Records
    //
    case PointRecord1Type:
      return new PointRecord1(stream);
    case PointRecord2Type:
      return new PointRecord2(stream);
    case LineRecord1Type:
      return new LineRecord1(stream);
    case LineRecord2Type:
      return new LineRecord2(stream);
    case BoundingSphereRecordType:
      return new BoundingSphereRecord(stream);
    case SphereRecord1Type:
      return new SphereRecord1(stream);
    case SphereRecord2Type:
      return new SphereRecord2(stream);
    case EllipsoidRecord1Type:
      return new EllipsoidRecord1(stream);
    case EllipsoidRecord2Type:
      return new EllipsoidRecord2(stream);
    case ConeRecord1Type:
      return new ConeRecord1(stream);
    case ConeRecord2Type:
      return new ConeRecord2(stream);
    case UniformGeometryRecordType:
      throw KException(__FUNCTION__, UNSUPPORTED_DATATYPE,
                       "UniformGeometryRecordType");  // We don't know how to
                                                      // decode this type.
    case RectangularVolumeRecord1Type:
      return new RectangularVolumeRecord1(stream);
    case RectangularVolumeRecord2Type:
      return new RectangularVolumeRecord2(stream);
    case GaussianPlumeRecordType:
      return new GaussianPlumeRecord(stream);
    case GaussianPuffRecordType:
      return new GaussianPuffRecord(stream);
    case RectangularVolumeRecord3Type:
      return new RectangularVolumeRecord3(stream);

    //
    // State Records
    //
    case COMBICStateType:
      return new COMBICState(stream);
    case FlareStateType:
      return new FlareState(stream);
    default:
      throw KException(__FUNCTION__, UNSUPPORTED_DATATYPE,
                       ui32RecType);  // We don't know how to decode this type.
  }
}

//////////////////////////////////////////////////////////////////////////

KBOOL EnvironmentRecord::operator==(const EnvironmentRecord& Value) const {
  if (m_ui32EnvRecTyp != Value.m_ui32EnvRecTyp) return false;
  if (m_ui16Length != Value.m_ui16Length) return false;
  if (m_ui8Index != Value.m_ui8Index) return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EnvironmentRecord::operator!=(const EnvironmentRecord& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
