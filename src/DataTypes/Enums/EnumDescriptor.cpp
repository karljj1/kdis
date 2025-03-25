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

#include <cstddef>

#include "KDIS/DataTypes/Enums/EnumDescriptor.hpp"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////

template <typename T>
static KString EnumAsStringWorker(const T* descrips, KUINT32 NumElements,
                                  KINT32 Value) {
  for (KUINT32 i = 0; i < NumElements; ++i) {
    if (Value == descrips[i].Value) {
      return descrips[i].Name;
    }
  }

  KStringStream ss;
  ss << "Unknown Enum: " << Value;
  return ss.str();
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsString(const EnumDescriptor* pArray,
                                                KUINT32 NumElements,
                                                KINT32 Value) {
  return EnumAsStringWorker(pArray, NumElements, Value);
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsString(
    const std::vector<EnumDescriptor>& descrips, KINT32 Value) {
  return EnumAsStringWorker(descrips.data(), descrips.size(), Value);
}

//////////////////////////////////////////////////////////////////////////

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromString(const EnumDescriptor* pArray,
                                                KUINT32 NumElements,
                                                const KString& Value,
                                                KINT32& ValueOut) {
  for (KUINT32 i = 0; i < NumElements; ++i) {
    if (Value == pArray[i].Name) {
      ValueOut = pArray[i].Value;
      return true;
    }
  }
  // No match found
  return false;
}

//////////////////////////////////////////////////////////////////////////

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromString(
    const std::vector<EnumDescriptor>& descrips, const KString& Value,
    KINT32& ValueOut) {
  for (const EnumDescriptor& elt : descrips) {
    if (Value == elt.Name) {
      ValueOut = elt.Value;
      return true;
    }
  }
  // No match found
  return false;
}