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

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAlternateParameter4()
{
	return sizeof( AlternateParameter4Descriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAlternateParameter4( KUINT32 Index )
{
	return &AlternateParameter4Descriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAlternateParameter4( KINT32 Value )
{
    return GetEnumAsString( AlternateParameter4Descriptor, sizeof( AlternateParameter4Descriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAlternateParameter4( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AlternateParameter4Descriptor, sizeof( AlternateParameter4Descriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAlternateParameter4()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAlternateParameter4( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAlternateParameter4( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

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

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTCAS()
{
	return sizeof( TCASDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTCAS( KUINT32 Index )
{
	return &TCASDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTCAS( KINT32 Value )
{
    return GetEnumAsString( TCASDescriptor, sizeof( TCASDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTCAS( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TCASDescriptor, sizeof( TCASDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeTCAS()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorTCAS( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTCAS( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

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

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMode5MessageFormat()
{
	return sizeof( Mode5MessageFormatDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMode5MessageFormat( KUINT32 Index )
{
	return &Mode5MessageFormatDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMode5MessageFormat( KINT32 Value )
{
    return GetEnumAsString( Mode5MessageFormatDescriptor, sizeof( Mode5MessageFormatDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMode5MessageFormat( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( Mode5MessageFormatDescriptor, sizeof( Mode5MessageFormatDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMode5MessageFormat()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMode5MessageFormat( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMode5MessageFormat( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMode5MessageFormat( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for Mode5Reply

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor Mode5ReplyDescriptor[] =
{
    { 0 , "No Response" },
    { 1 , "Valid Reply" },
	{ 2 , "Invalid Reply" },
	{ 3 , "Unable To Verify" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMode5Reply()
{
	return sizeof( Mode5ReplyDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMode5Reply( KUINT32 Index )
{
	return &Mode5ReplyDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMode5Reply( KINT32 Value )
{
    return GetEnumAsString( Mode5MessageFormatDescriptor, sizeof( Mode5ReplyDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMode5Reply( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( Mode5MessageFormatDescriptor, sizeof( Mode5ReplyDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeMode5Reply()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorMode5Reply( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringMode5Reply( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringMode5Reply( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for AntennaSelection

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor AntennaSelectionDescriptor[] =
{
    { 0 , "No Statement" },
	{ 1 , "Top" },
	{ 2 , "Bottom" },
	{ 3 , "Diversity" }
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAntennaSelection()
{
	return sizeof( AntennaSelectionDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAntennaSelection( KUINT32 Index )
{
	return &AntennaSelectionDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAntennaSelection( KINT32 Value )
{
    return GetEnumAsString( AntennaSelectionDescriptor, sizeof( Mode5ReplyDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAntennaSelection( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( AntennaSelectionDescriptor, sizeof( Mode5ReplyDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeAntennaSelection()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorAntennaSelection( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringAntennaSelection( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringAntennaSelection( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for PlatformType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor PlatformTypeDescriptor[] =
{
    { 0 , "Ground" },
	{ 1 , "Air" },	
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePlatformType()
{
	return sizeof( PlatformTypeDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPlatformType( KUINT32 Index )
{
	return &PlatformTypeDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPlatformType( KINT32 Value )
{
    return GetEnumAsString( PlatformTypeDescriptor, sizeof( Mode5ReplyDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPlatformType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( PlatformTypeDescriptor, sizeof( Mode5ReplyDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizePlatformType()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorPlatformType( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPlatformType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPlatformType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for NavigationSource

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor NavigationSourceDescriptor[] =
{
    { 0 , "No Statement" },
	{ 1 , "GPS" },
	{ 2 , "INS" },
	{ 3 , "INS/GPS" },	
};

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeNavigationSource()
{
	return sizeof( NavigationSourceDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorNavigationSource( KUINT32 Index )
{
	return &NavigationSourceDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringNavigationSource( KINT32 Value )
{
    return GetEnumAsString( NavigationSourceDescriptor, sizeof( NavigationSourceDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringNavigationSource( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( NavigationSourceDescriptor, sizeof( NavigationSourceDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeNavigationSource()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorNavigationSource( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringNavigationSource( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringNavigationSource( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

#endif // Endif DIS Version > 6
