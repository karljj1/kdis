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
    EnumDescriptor
    created:    20/07/2010
    author:     Karl Jones

    purpose:    Structure for holding a string to associate with an enum value.
                This allows for converting enumerations into their string representations.
*********************************************************************/

#pragma once

#include "./../../KDefines.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {	

struct EnumDescriptor
{
public:
    const KINT32 Value;
    const KCHAR8 * Name;
};

//************************************
// FullName:    KDIS::DATA_TYPE::ENUMS::GetEnumAsString
// Description: Uses a binary search to find the enum element.
// Parameter:   const EnumDescriptor * pArray
// Parameter:   KUINT32 NumElements
// Parameter:   KINT32 Value
//************************************
KDIS_EXPORT KString GetEnumAsString( const EnumDescriptor * pArray, KUINT32 NumElements, KINT32 Value );

//************************************
// FullName:    KDIS::DATA_TYPE::ENUMS::GetEnumFromString
// Description: Uses a linear search to find the enum value from a string. Search is case sensitive..
//				Returns true if a match was found else false.
// Parameter:   const EnumDescriptor * pArray
// Parameter:   KUINT32 NumElements
// Parameter:   const KString & Value
// Parameter:   KINT32 & ValueOut - The returned value if search found one.
//************************************
KDIS_EXPORT KBOOL GetEnumFromString( const EnumDescriptor * pArray, KUINT32 NumElements, const KString & Value, KINT32 & ValueOut );

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
