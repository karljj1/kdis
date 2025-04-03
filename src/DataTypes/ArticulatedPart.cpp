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

#include "KDIS/DataTypes/ArticulatedPart.hpp"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ArticulatedPart::ArticulatedPart() { m_ui8VarParamType = ArticulatedPartType; }

//////////////////////////////////////////////////////////////////////////

ArticulatedPart::ArticulatedPart(KDataStream& stream) { Decode(stream); }

//////////////////////////////////////////////////////////////////////////

ArticulatedPart::ArticulatedPart(KUINT8 ParamChangeIndicator, KUINT16 AttachID,
                                 ArticulatedPartsClass C,
                                 ArticulatedPartsMetric M, KFLOAT32 Value)
    : m_ui8ParameterChange(ParamChangeIndicator),
      m_ui16AttachmentID(AttachID),
      m_f32ParamValue(Value) {
  m_ui8VarParamType = ArticulatedPartType;
  m_ui32ParamTypeVariant = C + M;
}
//////////////////////////////////////////////////////////////////////////

ArticulatedPart::ArticulatedPart(KUINT8 ParamChangeIndicator, KUINT16 AttachID,
                                 KUINT32 TypeVariant, KFLOAT32 Value)
    : m_ui8ParameterChange(ParamChangeIndicator),
      m_ui16AttachmentID(AttachID),
      m_ui32ParamTypeVariant(TypeVariant),
      m_f32ParamValue(Value) {
  m_ui8VarParamType = ArticulatedPartType;
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetParameterChangeIndicator(KUINT8 PCI) {
  m_ui8ParameterChange = PCI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 ArticulatedPart::GetParameterChangeIndicator() const {
  return m_ui8ParameterChange;
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetAttachmentID(KUINT16 ID) { m_ui16AttachmentID = ID; }

//////////////////////////////////////////////////////////////////////////

KUINT16 ArticulatedPart::GetAttachmentID() const { return m_ui16AttachmentID; }

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetTypeVariantClass(ArticulatedPartsClass C) {
  m_ui32ParamTypeVariant = C + (m_ui32ParamTypeVariant % 32);
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPartsClass ArticulatedPart::GetTypeVariantClass() const {
  return static_cast<ArticulatedPartsClass>(m_ui32ParamTypeVariant -
                                            (m_ui32ParamTypeVariant % 32));
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetTypeVariantMetric(ArticulatedPartsMetric M) {
  m_ui32ParamTypeVariant =
      m_ui32ParamTypeVariant - (m_ui32ParamTypeVariant % 32) + M;
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPartsMetric ArticulatedPart::GetTypeVariantMetric() const {
  return static_cast<ArticulatedPartsMetric>(m_ui32ParamTypeVariant % 32);
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetTypeVariant(KUINT32 TV) {
  m_ui32ParamTypeVariant = TV;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 ArticulatedPart::GetTypeVariant() const {
  return m_ui32ParamTypeVariant;
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetValue(KFLOAT32 val) { m_f32ParamValue = val; }

//////////////////////////////////////////////////////////////////////////

KFLOAT32 ArticulatedPart::GetValue() const { return m_f32ParamValue; }

//////////////////////////////////////////////////////////////////////////

KString ArticulatedPart::GetAsString() const {
  KStringStream ss;

  ss << "Articulation Parameters:" << "\n\tParameter Change:     "
     << m_ui8ParameterChange
     << "\n\tAttachment ID:       " << m_ui16AttachmentID
     << "\n\tType Metric:          "
     << GetEnumAsStringArticulatedPartsMetric(GetTypeVariantMetric())
     << "\n\tType High Bits:       "
     << GetEnumAsStringArticulatedPartsClass(GetTypeVariantClass())
     << "\n\tValue:                " << m_f32ParamValue << "\n";

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::Decode(KDataStream& stream) {
  if (stream.GetBufferSize() < VariableParameter::VARIABLE_PARAMETER_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  stream >> m_ui8VarParamType >> m_ui8ParameterChange >> m_ui16AttachmentID >>
      m_ui32ParamTypeVariant >> m_f32ParamValue >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ArticulatedPart::Encode() const {
  KDataStream stream;

  ArticulatedPart::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::Encode(KDataStream& stream) const {
  stream << m_ui8VarParamType << m_ui8ParameterChange << m_ui16AttachmentID
         << m_ui32ParamTypeVariant << m_f32ParamValue << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArticulatedPart::operator==(const ArticulatedPart& Value) const {
  if (m_ui8VarParamType != Value.m_ui8VarParamType) return false;
  if (m_ui8ParameterChange != Value.m_ui8ParameterChange) return false;
  if (m_ui16AttachmentID != Value.m_ui16AttachmentID) return false;
  if (m_ui32ParamTypeVariant != Value.m_ui32ParamTypeVariant) return false;
  if (m_f32ParamValue != Value.m_f32ParamValue) return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArticulatedPart::operator!=(const ArticulatedPart& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
