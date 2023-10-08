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
    class:      JammingTechnique
    created:    2017/06/30
    author:     Dale Marchand

    purpose:    Contains information about a emitter beam
    size:       32 bits / 4 octets size
*********************************************************************/

#pragma once

#include <vector>

#include "KDIS/DataTypes/DataTypeBase.hpp"

namespace KDIS {
namespace DATA_TYPE {

#if DIS_VERSION > 6

class KDIS_EXPORT JammingTechnique : public DataTypeBase {
 protected:
  KUINT8 m_ui8Kind;

  KUINT8 m_ui8Category;

  KUINT8 m_ui8Subcategory;

  KUINT8 m_ui8Specific;

 public:
  static const KUINT16 JAMMING_TECHNIQUE_SIZE = 4;

  JammingTechnique();

  JammingTechnique(KDataStream& stream);

  JammingTechnique(KUINT8 KIND, KUINT8 CATEGORY, KUINT8 SUBCATEGORY,
                   KUINT8 SPECIFIC);

  virtual ~JammingTechnique();

  //************************************
  // FullName:    KDIS::DATA_TYPE::JammingTechnique::SetKind
  //              KDIS::DATA_TYPE::JammingTechnique::GetKind
  // Description: Kind.
  // Parameter:   KUINT8 KIND, void
  //************************************
  void SetKind(KUINT8 KIND);
  KUINT8 GetKind() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::JammingTechnique::SetCategory
  //              KDIS::DATA_TYPE::JammingTechnique::GetCategory
  // Description: Category.
  // Parameter:   KUINT8 CATEGORY, void
  //************************************
  void SetCategory(KUINT8 CATEGORY);
  KUINT8 GetCategory() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::JammingTechnique::SetSubcategory
  //              KDIS::DATA_TYPE::JammingTechnique::GetSubcategory
  // Description: Kind.
  // Parameter:   KUINT8 SUBCATEGORY, void
  //************************************
  void SetSubcategory(KUINT8 SUBCATEGORY);
  KUINT8 GetSubcategory() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::JammingTechnique::SetSpecific
  //              KDIS::DATA_TYPE::JammingTechnique::GetSpecific
  // Description: Kind.
  // Parameter:   KUINT8 SPECIFIC, void
  //************************************
  void SetSpecific(KUINT8 SPECIFIC);
  KUINT8 GetSpecific() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::JammingTechnique::GetAsString
  // Description: Returns a string representation
  //************************************
  virtual KString GetAsString() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::JammingTechnique::Decode
  // Description: Convert From Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  virtual void Decode(KDataStream& stream);

  //************************************
  // FullName:    KDIS::DATA_TYPE::JammingTechnique::Encode
  // Description: Convert To Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  virtual KDataStream Encode() const;
  virtual void Encode(KDataStream& stream) const;

  KBOOL operator==(const JammingTechnique& Value) const;
  KBOOL operator!=(const JammingTechnique& Value) const;
};

#endif

}  // namespace DATA_TYPE
}  // END namespace KDIS
