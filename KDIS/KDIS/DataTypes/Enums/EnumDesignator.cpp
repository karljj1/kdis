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

#include "./EnumDesignator.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for DesignatorCodeName

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DesignatorCodeNameDescriptor[] =
{
    { 0 , "OtherDesignatorCodeName" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDesignatorCodeName( KINT32 Value )
{
    return GetEnumAsString( DesignatorCodeNameDescriptor, sizeof( DesignatorCodeNameDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDesignatorCodeName( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DesignatorCodeNameDescriptor, sizeof( DesignatorCodeNameDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDesignatorCodeName( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDesignatorCodeName( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DesignatorCode

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DesignatorCodeDescriptor[] =
{
    { 0 , "OtherDesignatorCode" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDesignatorCode( KINT32 Value )
{
    return GetEnumAsString( DesignatorCodeDescriptor, sizeof( DesignatorCodeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDesignatorCode( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DesignatorCodeDescriptor, sizeof( DesignatorCodeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDesignatorCode( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDesignatorCode( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif



//////////////////////////////////////////////////////////////////////////
// DIS 7

#if DIS_VERSION > 6

// Implementation of string values for BeamSpotShape

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor BeamSpotShapeDescriptor[] =
{
    { 0 , "OtherBeamSpotShape" },
	{ 1 , "Gaussian" },
	{ 2 , "TopHat" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringBeamSpotShape( KINT32 Value )
{
    return GetEnumAsString( BeamSpotShapeDescriptor, sizeof( BeamSpotShapeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringBeamSpotShape( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( BeamSpotShapeDescriptor, sizeof( BeamSpotShapeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringBeamSpotShape( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringBeamSpotShape( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

#endif

