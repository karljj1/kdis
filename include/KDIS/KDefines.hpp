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
    KDefines
    created:    17/09/2008
    author:     Karl Jones

    purpose:    Defines some of the core data types that KDIS uses.
*********************************************************************/

#ifndef KDIS_KDEFINES_HPP_
#define KDIS_KDEFINES_HPP_

#include <cstdint>
#include <cstring>  // TODO(carlocorradini) Remove
#include <exception>
#include <sstream>
#include <string>

#include "KDIS/KExport.hpp"
#include "KDIS/KSymbolicNames.hpp"
#include "KDIS/util/format.hpp"

// TODO(carlocorradini) Remove
#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  // Disable this warning, it simply warns us about any functions that have a
  // throw qualifier.
  #pragma warning(disable : 4290)

  // Warning about conversion from size_t
  #pragma warning(disable : 4267)

  // Safe to ignore this error as we are only exporting STL objects
  #pragma warning(disable : 4251)
#endif

//
// Checks
//

// DIS version
#ifndef DIS_VERSION
  #error DIS_VERSION must be defined. Possible values are 5 (IEEE 1278.1-1995), 6 (IEEE 1278.1A-1998), or 7 (IEEE 1278.1x-2012)
#endif
#if DIS_VERSION != 5 && DIS_VERSION != 6 && DIS_VERSION != 7
  #error Invalid DIS_VERSION. Possible values are 5 (IEEE 1278.1-1995), 6 (IEEE 1278.1A-1998), or 7 (IEEE 1278.1x-2012)
#endif

//
// Type definitions
//

/**
 * @brief Maximum PDU size in bytes.
 */
#define MAX_PDU_SIZE MAX_PDU_SIZE_OCTETS

namespace KDIS {

typedef bool KBOOL;

typedef std::int8_t KINT8;
typedef std::uint8_t KUINT8;

typedef std::int16_t KINT16;
typedef std::uint16_t KUINT16;

typedef std::int32_t KINT32;
typedef std::uint32_t KUINT32;

typedef std::int64_t KINT64;
typedef std::uint64_t KUINT64;

typedef char KOCTET;
typedef unsigned char KUOCTET;

typedef char KCHAR8;
typedef unsigned char KUCHAR8;

typedef float KFLOAT32;
typedef double KFLOAT64;

typedef std::string KString;
typedef std::stringstream KStringStream;

//
// Errors & Exceptions
//

/**
 * @brief Error code.
 * An enumeration of all error codes.
 */
enum class ErrorCode : std::uint8_t {
  /**
   * @brief No errors.
   */
  NO_ERRORS,
  /**
   * @brief Buffer is too small.
   */
  BUFFER_TOO_SMALL,
  /**
   * @brief Buffer does not contains enough information to decode.
   */
  NOT_ENOUGH_DATA_IN_BUFFER,
  /**
   * @brief String size too big.
   */
  STRING_PDU_SIZE_TOO_BIG,
  /**
   * @brief Data type is too large.
   */
  DATA_TYPE_TOO_LARGE,
  /**
   * @brief Incorrect PDU type specified in header.
   */
  WRONG_PDU_TYPE_IN_HEADER,
  /**
   * @brief Could not open file for reading/writing.
   */
  FILE_NOT_OPEN,
  /**
   * @brief Parameter is out of bounds/range of acceptable values.
   */
  OUT_OF_BOUNDS,
  /**
   * @brief Invalid data.
   */
  INVALID_DATA,
  /**
   * @brief Unsupported data type. Unable to decode.
   */
  UNSUPPORTED_DATATYPE,
  /**
   * @brief Invalid operation.
   */
  INVALID_OPERATION,
  /**
   * @brief PDU is too large. PDU must not exceeds 8192 bytes.
   */
  PDU_TOO_LARGE,
  /**
   * @brief Socket error.
   */
  CONNECTION_SOCKET_ERROR,
  /**
   * @brief Not found error.
   */
  NOT_FOUND,
  /**
   * @brief System error.
   */
  SYSTEM,
  /**
   * @brief Unknown error.
   */
  UNKOWN
};

/**
 * @brief Converts the error code to text.
 *
 * @param errorCode Error code.
 * @return Error code as text.
 */
static const char* errorCodeText(ErrorCode errorCode) {
  switch (errorCode) {
    case ErrorCode::NO_ERRORS:
      return "No errors";
    case ErrorCode::BUFFER_TOO_SMALL:
      return "Buffer is too small";
    case ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER:
      return "Buffer does not contains enough information to decode";
    case ErrorCode::STRING_PDU_SIZE_TOO_BIG:
      return "String size too big";
    case ErrorCode::DATA_TYPE_TOO_LARGE:
      return "Data type is too large";
    case ErrorCode::WRONG_PDU_TYPE_IN_HEADER:
      return "Incorrect PDU type specified in header";
    case ErrorCode::FILE_NOT_OPEN:
      return "Could not open file for reading/writing";
    case ErrorCode::OUT_OF_BOUNDS:
      return "Parameter is out of bounds/range of acceptable values";
    case ErrorCode::INVALID_DATA:
      return "Invalid data";
    case ErrorCode::UNSUPPORTED_DATATYPE:
      return "Unsupported data type. Unable to decode";
    case ErrorCode::INVALID_OPERATION:
      return "Invalid operation";
    case ErrorCode::PDU_TOO_LARGE:
      return "PDU is too large. PDU must not exceeds 8192 bytes";
    case ErrorCode::CONNECTION_SOCKET_ERROR:
      return "Socket error";
    case ErrorCode::NOT_FOUND:
      return "Not found error";
    case ErrorCode::SYSTEM:
      return "System error";
    case ErrorCode::UNKOWN:
    default:
      return "Unknown error";
  }
}

//
// Exception
//

/**
 * @brief KDIS exception.
 */
class KDIS_EXPORT KException : public std::runtime_error {
 public:
  /**
   * @brief Error code.
   */
  const ErrorCode errorCode;

  explicit KException(const ErrorCode errorCode)
      : std::runtime_error(errorCodeText(errorCode)), errorCode(errorCode) {}

  KException(const ErrorCode errorCode, const std::string& message)
      : std::runtime_error(KDIS::UTIL::format(
            "%s: %s", errorCodeText(errorCode), message.c_str())),
        errorCode(errorCode) {}

  virtual ~KException() = default;
};

}  // namespace KDIS

#endif  // KDIS_KDEFINES_HPP_
