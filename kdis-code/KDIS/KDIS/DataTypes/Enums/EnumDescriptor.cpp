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

#include "./EnumDescriptor.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsString( const EnumDescriptor * pArray, KUINT32 NumElements, KINT32 Value )
{
    KStringStream ss;
    KINT32 i32Lower = 0, i32Upper = NumElements - 1, i32Middle = ( i32Lower + i32Upper ) / 2;

    while( pArray[i32Middle].Value != Value && i32Lower <= i32Upper )
    {
        if( pArray[i32Middle].Value > Value )
        {
            // Search the left side.
            i32Upper = i32Middle - 1;
        }
        else
        {
            // Search the right side.
            i32Lower = i32Middle + 1;
        }

        i32Middle = ( i32Lower + i32Upper ) / 2;
    }

    if( i32Lower <= i32Upper )
    {
        ss << pArray[i32Middle].Name << "(" << Value << ")";
        return ss.str();
    }

    ss << "Unknown Enum: " << Value;
    return ss.str();
};

//////////////////////////////////////////////////////////////////////////

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromString( const EnumDescriptor * pArray, KUINT32 NumElements, const KString & Value, KINT32 & ValueOut )
{
	for( KINT32 i = 0; i < NumElements; ++i )
	{
		if( Value == pArray[i].Name )
		{
			ValueOut = pArray[i].Value;
			return true;
		}	
	}

	// No match found
	return false;
};

//////////////////////////////////////////////////////////////////////////
