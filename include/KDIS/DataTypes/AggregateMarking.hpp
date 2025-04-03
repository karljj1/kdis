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
    class:      AggregateMarking
    created:    07/02/2009
    author:     Karl Jones

    purpose:    Holds aggregate marking
                Note - Currently on supports ASCII marking text, changes will
need to be made to support the other sets. size:       256 bits / 32 Octets
*********************************************************************/

#pragma once

#include "KDIS/DataTypes/DataTypeBase.hpp"
#include "KDIS/utils/BoundedLengthString.hpp"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT AggregateMarking : public DataTypeBase {
 protected:
  KUINT8 m_ui8AggregateMarkingCharacterSet{KDIS::DATA_TYPE::ENUMS::ASCII};

  KDIS::UTILS::BoundedLengthString<32> m_sAggregateMarkingString;

 public:
  AggregateMarking() = default;

  AggregateMarking(KDataStream& stream);

  AggregateMarking(
      const KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet MarkingCharSet,
      const KString& MarkingText);

  virtual ~AggregateMarking() = default;

  //************************************
  // FullName:
  // KDIS::DATA_TYPE::AggregateMarking::SetAggregateMarkingCharacterSet
  //              KDIS::DATA_TYPE::AggregateMarking::GetAggregateMarkingCharacterSet
  // Description: Marking Char set
  // Parameter:   AggregateMarkingCharacterSet EMCS, void
  //************************************
  void SetAggregateMarkingCharacterSet(
      KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet EMCS);
  KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet
  GetAggregateMarkingCharacterSet() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateMarking::SetAggregateMarkingString
  //              KDIS::DATA_TYPE::AggregateMarking::GetAggregateMarkingString
  // Description: Marking string. entity name etc. max 31 octets/chars. Any
  //              length beyond max will be discarded.
  // Parameter:   const KString&, void
  //************************************
  void SetAggregateMarkingString(const KString& str);
  KString GetAggregateMarkingString() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateMarking::GetAsString
  // Description: Returns a string representation
  //************************************
  KString GetAsString() const override;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateMarking::Decode
  // Description: Convert From Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  void Decode(KDataStream& stream) override;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateMarking::Encode
  // Description: Convert To Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  KDataStream Encode() const override;
  void Encode(KDataStream& stream) const override;

  KBOOL operator==(const AggregateMarking& Value) const;
  KBOOL operator!=(const AggregateMarking& Value) const;
};

}  // namespace DATA_TYPE
}  // END namespace KDIS
