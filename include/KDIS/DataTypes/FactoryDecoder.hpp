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
    class:      FactoryDecoder
    created:    15/03/2011
    author:     Karl Jones

    purpose:    This is an Abstract class that can be used to create your own
custom decoders for some of the more extendable data types. For example the
VariableDatum can support many different variations including your own custom
ones, using a FactoryDecoder you can add your custom classes into KDIS.

                                If you want KDIS to decode your custom classes
simply call the RegisterFactoryDecoder function of the relevant class.

                                Example:

                                // You could create a seperate decoder class
just for the decoding task, here I use multiple inheritance... class
MyCustomVariableDatumClass : public variableDatum, public
FactoryDecoder<VariableDatum,
                                {
                                        ...
                                        variableDatum * FactoryDecode( int
TypeEnum, KDataStream & stream )
                                        {
                                                // Do you custom decoding in
here.
                                        }
                                        ...
                                }


                                // Now when your application starts up register
you new FactoryDecoderClass like so:

                                // 123 could be your type enum value.
                                VariableDatum::RegisterFactoryDecoder( 123, new
MyCustomVariableDatumClass );

                                // Now when ever a VariableDatum with type 123
is received it will be decoded with your custom class.

                                // When you no longer need the custom decoders
you should call 'ClearFactoryDecoders', which can also free up the memory for
you.

*********************************************************************/

#pragma once

#include <map>

#include "KDIS/Extras/KRef_Ptr.hpp"
#include "KDIS/KDataStream.hpp"
#include "KDIS/util/format.hpp"

namespace KDIS {
namespace DATA_TYPE {

template <class DecoderBaseTyp,
          typename EnumValTyp = KINT32>
class FactoryDecoder {
 public:
  FactoryDecoder() {}

  virtual ~FactoryDecoder() {}

  //************************************
  // FullName:    KDIS::DATA_TYPE::FactoryDecoder::FactoryDecode
  // Description: This is where you decode the stream into your custom class,
  //              the enum value is also passed back so you can perform decoding
  //              of multiple types within a single FactoryDecoder.
  // Parameter:   EnumValTyp EnumVal
  // Parameter:   KDataStream & stream
  //************************************
  virtual DecoderBaseTyp* FactoryDecode(EnumValTyp EnumVal,
                                        KDataStream& stream) = 0;
};

/********************************************************************
    class:      FactoryDecoderUser
    created:    17/03/2011
    author:     Karl Jones

    purpose:    This class adds support for custom decoding.
*********************************************************************/

template <class DecoderBaseTyp,
          typename EnumValTyp = KINT32>
class FactoryDecoderUser {
 public:
  typedef KDIS::UTILS::KRef_Ptr<FactoryDecoder<DecoderBaseTyp,
                                               EnumValTyp>> FacDecPtr;

 protected:
  static std::map<EnumValTyp, FacDecPtr> m_mDecoders;

 public:
  //************************************
  // FullName:    KDIS::DATA_TYPE::FactoryDecoderUser::RegisterFactoryDecoder
  // Description: Registers a decoder for a custom class.
  //              EnumVal is the relevant enum value representing the new class.
  //              E.G DatumID enum for VariableDatum.
  //              Exception thrown if a decoder already exists for this enum.
  // Parameter:   EnumValTyp EnumVal
  // Parameter:   FacDecPtr Decoder
  //************************************
  static void RegisterFactoryDecoder(EnumValTyp EnumVal, FacDecPtr Decoder) {
    if (m_mDecoders.find(EnumVal) != m_mDecoders.end()) {
      throw KException(
          ErrorCode::INVALID_OPERATION,
          KDIS::UTIL::format("%s | A decoder for enum %d already exists",
                             __FUNCTION__, EnumVal));
    }

    // Register the new decoder.
    m_mDecoders[EnumVal] = Decoder;
  }

  //************************************
  // FullName:    KDIS::DATA_TYPE::FactoryDecoderUser::FactoryDecode
  // Description: Attempts to find a decoder for the enum, returns NULL if none
  // are found.
  //              Note: An exception may be thrown by a decoder.
  // Parameter:   EnumValTyp EnumVal
  // Parameter:   KDataStream & stream
  //************************************
  static DecoderBaseTyp* FactoryDecode(EnumValTyp EnumVal, KDataStream& stream) {
    // Try to find a decoder
    typename std::map<EnumValTyp, FacDecPtr>::iterator itr =
        m_mDecoders.find(EnumVal);
    if (itr != m_mDecoders.end()) {
      return itr->second->FactoryDecode(EnumVal, stream);
    }

    // No decoders found so return NULL.
    return 0;
  }

  //************************************
  // FullName:    KDIS::DATA_TYPE::FactoryDecoderUser::FactoryDecode
  // Description: Removes all factory decoders.
  //************************************
  static void ClearFactoryDecoders() { m_mDecoders.clear(); }
};

// Init static map variable.
template <class DecoderBaseTyp,
          typename EnumValTyp>
std::map<EnumValTyp, KDIS::UTILS::KRef_Ptr<FactoryDecoder<DecoderBaseTyp,
                                                          EnumValTyp>>>
    FactoryDecoderUser<DecoderBaseTyp, EnumValTyp>::m_mDecoders;

}  // namespace DATA_TYPE
}  // END namespace KDIS
