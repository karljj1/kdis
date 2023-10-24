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

#include "KDIS/DataTypes/EllipsoidRecord2.hpp"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

EllipsoidRecord2::EllipsoidRecord2() : m_ui32Padding(0) {
  m_ui32EnvRecTyp = EllipsoidRecord2Type;
  m_ui16Length = (ELIPSOID_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE) * 8;
}

//////////////////////////////////////////////////////////////////////////

EllipsoidRecord2::EllipsoidRecord2(KDataStream& stream) { Decode(stream); }

//////////////////////////////////////////////////////////////////////////

EllipsoidRecord2::EllipsoidRecord2(KUINT8 Index,
                                   const WorldCoordinates& CentroidLocation,
                                   const Vector& Sigma,
                                   const EulerAngles& Orientation,
                                   const Vector& DDT, const Vector& Velocity,
                                   const Vector& AngularVelocity)
    : EllipsoidRecord1(Index, CentroidLocation, Sigma, Orientation),
      m_DDT(DDT),
      m_Velocity(Velocity),
      m_AngularVelocity(AngularVelocity),
      m_ui32Padding(0) {
  m_ui32EnvRecTyp = EllipsoidRecord2Type;
  m_ui16Length = (ELIPSOID_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE) * 8;
}

//////////////////////////////////////////////////////////////////////////

EllipsoidRecord2::~EllipsoidRecord2() {}

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord2::SetDOverDt(const Vector& S) { m_DDT = S; }

//////////////////////////////////////////////////////////////////////////

const Vector& EllipsoidRecord2::GetDOverDt() const { return m_DDT; }

//////////////////////////////////////////////////////////////////////////

Vector& EllipsoidRecord2::GetDOverDt() { return m_DDT; }

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord2::SetVelocity(const Vector& V) { m_Velocity = V; }

//////////////////////////////////////////////////////////////////////////

const Vector& EllipsoidRecord2::GetVelocity() const { return m_Velocity; }

//////////////////////////////////////////////////////////////////////////

Vector& EllipsoidRecord2::GetVelocity() { return m_Velocity; }

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord2::SetAngularVelocity(const Vector& V) {
  m_AngularVelocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector& EllipsoidRecord2::GetAngularVelocity() const {
  return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector& EllipsoidRecord2::GetAngularVelocity() { return m_AngularVelocity; }

//////////////////////////////////////////////////////////////////////////

KString EllipsoidRecord2::GetAsString() const {
  KStringStream ss;

  ss << EllipsoidRecord1::GetAsString()
     << "\td(Sigma)/dt:      " << m_DDT.GetAsString()
     << "\tVelocity:         " << m_Velocity.GetAsString()
     << "\tAngular Velocity: " << m_AngularVelocity.GetAsString();

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord2::Decode(KDataStream& stream) {
  if (stream.GetBufferSize() < ELIPSOID_RECORD_2_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  stream >> m_ui32EnvRecTyp >> m_ui16Length >> m_ui8Index >> m_ui8Padding >>
      KDIS_STREAM m_CentLocation >> KDIS_STREAM m_Sigma >> KDIS_STREAM m_DDT >>
      KDIS_STREAM m_Ori >> KDIS_STREAM m_Velocity >>
      KDIS_STREAM m_AngularVelocity >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EllipsoidRecord2::Encode() const {
  KDataStream stream;

  EllipsoidRecord2::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord2::Encode(KDataStream& stream) const {
  stream << m_ui32EnvRecTyp << m_ui16Length << m_ui8Index << m_ui8Padding
         << KDIS_STREAM m_CentLocation << KDIS_STREAM m_Sigma
         << KDIS_STREAM m_DDT << KDIS_STREAM m_Ori << KDIS_STREAM m_Velocity
         << KDIS_STREAM m_AngularVelocity
         << m_ui32Padding;  // padding to 64 bit boundary.
}

//////////////////////////////////////////////////////////////////////////

KBOOL EllipsoidRecord2::operator==(const EllipsoidRecord2& Value) const {
  if (EllipsoidRecord1::operator!=(Value)) return false;
  if (m_DDT != Value.m_DDT) return false;
  if (m_Velocity != Value.m_Velocity) return false;
  if (m_AngularVelocity != Value.m_AngularVelocity) return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EllipsoidRecord2::operator!=(const EllipsoidRecord2& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
