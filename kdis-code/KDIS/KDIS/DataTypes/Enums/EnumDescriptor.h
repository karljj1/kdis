/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

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
KString GetEnumAsString( const EnumDescriptor * pArray, KUINT32 NumElements, KINT32 Value );

//************************************
// FullName:    KDIS::DATA_TYPE::ENUMS::GetEnumFromString
// Description: Uses a linear search to find the enum value from a string. Search is case sensitive..
//				Returns true if a match was found else false.
// Parameter:   const EnumDescriptor * pArray
// Parameter:   KUINT32 NumElements
// Parameter:   const KString & Value
// Parameter:   KINT32 & ValueOut - The returned value if search found one.
//************************************
KBOOL GetEnumFromString( const EnumDescriptor * pArray, KUINT32 NumElements, const KString & Value, KINT32 & ValueOut );

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
