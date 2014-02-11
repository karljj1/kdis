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

#include "./EnumIFF.h"

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

//////////////////////////////////////////////////////////////////////////
#if DIS_VERSION > 6

// Implementation of string values for Mode5MessageFormat

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor Mode5MessageFormatDescriptor[] =
{
    { 0 , "Capability" },
    { 1 , "ActiveInterrogation" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMode5MessageFormat( KINT32 Value )
{
    return GetEnumAsString( Mode5MessageFormatDescriptor, sizeof( TCASDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMode5MessageFormat( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( Mode5MessageFormatDescriptor, sizeof( Mode5MessageFormatDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMode5MessageFormat( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMode5MessageFormat( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

#endif // Endif DIS Version > 6