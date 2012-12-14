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

#include "./EnumFundamentalOperationalData.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for AlternateParameter4

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AlternateParameter4Descriptor[] =
{
    { 0 , "OtherAlternateParameter4" },
    { 1 , "Valid" },
    { 2 , "Invalid" },
    { 3 , "NoResponse" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAlternateParameter4( KINT32 Value )
{
    return GetEnumAsString( AlternateParameter4Descriptor, sizeof( AlternateParameter4Descriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAlternateParameter4( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AlternateParameter4Descriptor, sizeof( AlternateParameter4Descriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAlternateParameter4( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAlternateParameter4( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for TCAS

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TCASDescriptor[] =
{
    { 0 , "TCAS_I" },
    { 1 , "TCAS_II" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTCAS( KINT32 Value )
{
    return GetEnumAsString( TCASDescriptor, sizeof( TCASDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTCAS( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TCASDescriptor, sizeof( TCASDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTCAS( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTCAS( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
