/*********************************************************************
Copyright 2018 Karl Jones
               Todd Klasik
               GBL Systems Corporation
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
    class:      ExpendableDescriptor
    created:    03/05/2018
    author:     Todd Klasik

    purpose:    Represents the burst of a chaff expendable or ignition of a
flare This descriptor is applicable to the Fire PDU and Detonation PDU. size:
128 bits / 16 octets
*********************************************************************/

#pragma once

#include "KDIS/DataTypes/Descriptor.hpp"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ExpendableDescriptor : public Descriptor {
 protected:
  KUINT64 m_ui64Padding;

 public:
  ExpendableDescriptor();

  ExpendableDescriptor(KDataStream& stream);

  ExpendableDescriptor(const EntityType& T);

  virtual ~ExpendableDescriptor();

  //************************************
  // FullName:    KDIS::DATA_TYPE::MunitionDescriptor::Decode
  // Description: Convert From Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  void Decode(KDataStream& stream) override;

  //************************************
  // FullName:    KDIS::DATA_TYPE::MunitionDescriptor::Encode
  // Description: Convert To Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  KDataStream Encode() const override;
  void Encode(KDataStream& stream) const override;

  KBOOL operator==(const ExpendableDescriptor& Value) const;
  KBOOL operator!=(const ExpendableDescriptor& Value) const;
};

}  // namespace DATA_TYPE
}  // END namespace KDIS
