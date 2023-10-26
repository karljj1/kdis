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

//
// Inspired by
// https://github.com/CppCodeReviewers/Covariant-Return-Types-and-Smart-Pointers
//

#pragma once

#include <memory>
#include <type_traits>

namespace KDIS {
namespace PDU {

/**
 * @brief Clone PDU.
 *
 * Creates and returns an exact copy of the PDU.
 *
 * @tparam T Cloneable PDU type.
 * @param pdu Cloneable PDU.
 * @return std::unique_ptr<T> Cloned PDU.
 */
template <typename T>
std::unique_ptr<T> clone(const T& pdu) {
  using base_class = typename T::base_class;
  static_assert(std::is_base_of<base_class, T>::value,
                "T class must be derived from T::base_class");
  auto pdu_ptr = static_cast<const base_class&>(pdu).clone();
  return std::unique_ptr<T>(static_cast<T*>(pdu_ptr));
}

template <typename T>
class Cloneable {
 public:
  using base_class = T;

  virtual ~Cloneable() = default;

 protected:
  virtual T* clone() const = 0;

  template <typename TT>
  friend std::unique_ptr<TT> KDIS::PDU::clone(const TT& cls);
};

class CloneablePDU : public Cloneable<CloneablePDU> {};

}  // namespace PDU
}  // namespace KDIS
