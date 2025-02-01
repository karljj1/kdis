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

/********************************************************************
    class:      AcousticEmitterSystem
    created:    06/01/2009
    author:     Karl Jones

    purpose:    Contains information about a particular Underwater Acoustic
emitter. size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "KDIS/DataTypes/DataTypeBase.hpp"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT AcousticEmitterSystem : public DataTypeBase {
 protected:
  KUINT16 m_ui16EmitterName {0};

  KUINT8 m_ui8Function {0};

  KUINT8 m_ui8EmitterIDNumber {0};

 public:
  static const KUINT16 ACOUSTIC_EMITTER_SYSTEM_SIZE = 4;

  AcousticEmitterSystem() = default;

  explicit AcousticEmitterSystem(KDataStream& stream);

  AcousticEmitterSystem(KDIS::DATA_TYPE::ENUMS::AcousticSystemName ASN,
                        KDIS::DATA_TYPE::ENUMS::AcousticSystemFunction ASF,
                        KUINT8 ID);

  virtual ~AcousticEmitterSystem() = default;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::SetName
  //              KDIS::DATA_TYPE::AcousticEmitterSystem::GetName
  // Description: Specifies the system for the particular emitter
  // Parameter:   AcousticSystemName ASN, void
  //************************************
  void SetName(KDIS::DATA_TYPE::ENUMS::AcousticSystemName ASN);
  KDIS::DATA_TYPE::ENUMS::AcousticSystemName GetName() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::SetFunction
  //              KDIS::DATA_TYPE::AcousticEmitterSystem::GetFunction
  // Description: Specifies the function of the emitter system
  // Parameter:   AcousticSystemFunction ASF, void
  //************************************
  void SetFunction(KDIS::DATA_TYPE::ENUMS::AcousticSystemFunction ASF);
  KDIS::DATA_TYPE::ENUMS::AcousticSystemFunction GetFunction() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::SetEmitterID
  //              KDIS::DATA_TYPE::AcousticEmitterSystem::GetEmitterID
  // Description: ID of the emitter. Used for identifying multiple emitters on a
  //              single entity. Numbering of systems shall begin with 1.
  // Parameter:   KUINT8 ID, void
  //************************************
  void SetEmitterID(KUINT8 ID);
  KUINT8 GetEmitterID() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::GetAsString
  // Description: Returns a string representation
  //************************************
  virtual KString GetAsString() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::Decode
  // Description: Convert From Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  virtual void Decode(KDataStream& stream);

  //************************************
  // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::Encode
  // Description: Convert To Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  virtual KDataStream Encode() const;
  virtual void Encode(KDataStream& stream) const;

  KBOOL operator==(const AcousticEmitterSystem& Value) const;
  KBOOL operator!=(const AcousticEmitterSystem& Value) const;
};

}  // namespace DATA_TYPE
}  // END namespace KDIS
