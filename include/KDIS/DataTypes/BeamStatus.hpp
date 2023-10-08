/*********************************************************************
Copyright 2017 Karl Jones
               Dale Marchand
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
    class:      BeamStatus
    created:    2017/06/30
    author:     Dale Marchand

    purpose:    Contains information about a beam status
    size:       8 bits / 1 octets size
*********************************************************************/

#pragma once

#include <vector>

#include "KDIS/DataTypes/DataTypeBase.hpp"

namespace KDIS {
namespace DATA_TYPE {

#if DIS_VERSION > 6

using KDIS::DATA_TYPE::ENUMS::BeamState;

class KDIS_EXPORT BeamStatus : public DataTypeBase {
 protected:
  KUINT8 m_ui8BeamStatus;  // bit 0 - BeamState, bits 1-7 - padding

 public:
  static const KUINT16 BEAM_STATUS_SIZE = 1;

  BeamStatus();

  BeamStatus(KDataStream& stream);

  BeamStatus(BeamState BS);

  virtual ~BeamStatus();

  //************************************
  // FullName:    KDIS::DATA_TYPE::BeamStatus::SetBeamState
  //              KDIS::DATA_TYPE::BeamStatus::GetBeamState
  // Description: Beam State.
  // Parameter:   BeamState BS, void
  //************************************
  void SetBeamState(BeamState BS);
  BeamState GetBeamState() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::BeamStatus::GetAsString
  // Description: Returns a string representation
  //************************************
  virtual KString GetAsString() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::BeamStatus::Decode
  // Description: Convert From Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  virtual void Decode(KDataStream& stream);

  //************************************
  // FullName:    KDIS::DATA_TYPE::BeamStatus::Encode
  // Description: Convert To Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  virtual KDataStream Encode() const;
  virtual void Encode(KDataStream& stream) const;

  KBOOL operator==(const BeamStatus& Value) const;
  KBOOL operator!=(const BeamStatus& Value) const;
};

#endif

}  // namespace DATA_TYPE
}  // END namespace KDIS
