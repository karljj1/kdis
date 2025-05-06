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
    class:      AggregateType
    created:    2009/02/07
    author:     Karl Jones

    purpose:    Holds DIS enum for Aggregate Type
    size:       64 bits / 8 Octets
*********************************************************************/

#pragma once

#include "KDIS/DataTypes/DataTypeBase.hpp"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT AggregateType : public DataTypeBase {
 protected:
  KUINT8 m_ui8Kind{0};

  KUINT8 m_ui8Domain{0};

  KUINT16 m_ui16Country{0};

  KUINT8 m_ui8Category{0};

  KUINT8 m_ui8SubCategory{0};

  KUINT8 m_ui8Specific{0};

  KUINT8 m_ui8Extra{0};

 public:
  static constexpr KUINT16 AGGREGATE_TYPE_SIZE{8};

  AggregateType() = default;

  AggregateType(KDIS::DATA_TYPE::ENUMS::AggregateKind Kind, KUINT8 Domain,
                KDIS::DATA_TYPE::ENUMS::Country Country, KUINT8 Categoy,
                KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra);

  AggregateType(KUINT8 Kind, KUINT8 Domain, KUINT8 Country, KUINT8 Categoy,
                KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra);

  AggregateType(KDataStream& stream);

  virtual ~AggregateType() = default;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::SetEntityKind
  //              KDIS::DATA_TYPE::AggregateType::GetEntityKind
  // Description: Kind
  // Parameter:   AggregateKind UI, void
  //************************************
  void SetEntityKind(KDIS::DATA_TYPE::ENUMS::AggregateKind AK);
  KDIS::DATA_TYPE::ENUMS::AggregateKind GetEntityKind() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::SetDomain
  //              KDIS::DATA_TYPE::AggregateType::GetDomain
  // Description: Domain - Same as Entity Type record
  // Parameter:   EntityDomain  UI, void
  //************************************
  void SetDomain(KDIS::DATA_TYPE::ENUMS::EntityDomain UI);
  KDIS::DATA_TYPE::ENUMS::EntityDomain GetDomain() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::SetCountry
  //              KDIS::DATA_TYPE::AggregateType::GetCountry
  // Description: Country
  // Parameter:   Country UI, void
  //************************************
  void SetCountry(KDIS::DATA_TYPE::ENUMS::Country UI);
  KDIS::DATA_TYPE::ENUMS::Country GetCountry() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::SetCategory
  //              KDIS::DATA_TYPE::AggregateType::GetCategory
  // Description: Category
  // Parameter:   KUINT8 UI, void
  //************************************
  void SetCategory(KUINT8 UI);
  KUINT8 GetCategory() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::SetSubCategory
  //              KDIS::DATA_TYPE::AggregateType::GetSubCategory
  // Description: Sub Category
  // Parameter:   KUINT8 UI, void
  //************************************
  void SetSubCategory(KUINT8 UI);
  KUINT8 GetSubCategory() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::SetSpecific
  //              KDIS::DATA_TYPE::AggregateType::GetSpecific
  // Description: Specific
  // Parameter:   KUINT8 UI, void
  //************************************
  void SetSpecific(KUINT8 UI);
  KUINT8 GetSpecific() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::SetExtra
  //              KDIS::DATA_TYPE::AggregateType::GetExtra
  // Description: Extra
  // Parameter:   KUINT8  UI, void
  //************************************
  void SetExtra(KUINT8 UI);
  KUINT8 GetExtra() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::GetAsString
  // Description: Returns a string representation
  //************************************
  KString GetAsString() const override;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::Decode
  // Description: Convert From Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  void Decode(KDataStream& stream) override;

  //************************************
  // FullName:    KDIS::DATA_TYPE::AggregateType::Encode
  // Description: Convert To Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  KDataStream Encode() const override;
  void Encode(KDataStream& stream) const override;

  KBOOL operator==(const AggregateType& Value) const;
  KBOOL operator!=(const AggregateType& Value) const;
  KBOOL operator<(const AggregateType& Value) const;
};

}  // namespace DATA_TYPE
}  // END namespace KDIS
