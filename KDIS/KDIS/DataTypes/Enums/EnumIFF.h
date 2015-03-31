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
    EnumFundamentalOperationalData
    created:    5/12/2008
    author:     Karl Jones

    purpose:    Enums for Fundamental Operational Data
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Alternate Parameter 4                                                */
/* Used for an alternative representation of parameter 4                */
/* Used In:                                                             */
/*  Fundamental Operational Data                                        */
/************************************************************************/

enum AlternateParameter4
{
    OtherAlternateParameter4                                          = 0,
    Valid                                                             = 1,
    Invalid                                                           = 2,
    NoResponse                                                        = 3,
    // 4+ Not used
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeAlternateParameter4();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorAlternateParameter4( KUINT32 Index );

KString GetEnumAsStringAlternateParameter4( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAlternateParameter4( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* TCAS                                                                 */
/* TCAS Version                                                         */
/* Used In:                                                             */
/*  Fundamental Operational Data System 1                               */
/************************************************************************/

enum TCAS
{
    TCAS_I                                                            = 0,
    TCAS_II                                                           = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeTCAS();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorTCAS( KUINT32 Index );

KString GetEnumAsStringTCAS( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTCAS( const KString & Value, KINT32 & ValueOut ); 

#if DIS_VERSION > 6

/************************************************************************/
/* Mode 5 Message Format                                                */
/* Indicate the Mode 5 Message Format.                                  */
/* Used In:                                                             */
/*  Mode 5 Interrogator Status                                          */
/************************************************************************/

enum Mode5MessageFormat
{
    Capability                                                        = 0,
    ActiveInterrogation                                               = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeMode5MessageFormat();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorMode5MessageFormat( KUINT32 Index );

KString GetEnumAsStringMode5MessageFormat( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringMode5MessageFormat( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Mode 5 Reply                                                         */
/* Specifies the validity of a reply that would be transmitted          */
/* by a Mode 5 transponder if interrogated.                             */
/* Used In:                                                             */
/*  Mode 5 Transponder Status                                           */
/************************************************************************/

enum Mode5Reply
{
    NoResponseReply                                                   = 0,
    ValidReply                                                        = 1,
	InvalidReply                                                      = 2,
	UnableToVerify                                                    = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeMode5Reply();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorMode5Reply( KUINT32 Index );

KString GetEnumAsStringMode5Reply( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringMode5Reply( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Antenna Selection                                                    */
/* The present Mode 5 transponder antenna selection                     */
/* Used In:                                                             */
/*  Mode 5 Transponder Status                                           */
/************************************************************************/

enum AntennaSelection
{
    AntennaSelectionNoStatement                                       = 0,
	Top                                                               = 1,
	Bottom                                                            = 2,
	Diversity                                                         = 3	
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeAntennaSelection();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorAntennaSelection( KUINT32 Index );

KString GetEnumAsStringAntennaSelection( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAntennaSelection( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Platform Type	                                                    */
/* The type of platform (air or ground) that is associated with a Mode  */
/* 5 transponder.                                                       */
/* Used In:                                                             */
/*  Mode 5 Transponder Status                                           */
/************************************************************************/

enum PlatformType
{
    GroundPlatformType                                                = 0,
	AirPlatformType                                                   = 1
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizePlatformType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorPlatformType( KUINT32 Index );

KString GetEnumAsStringPlatformType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringPlatformType( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Navigation Source                                                    */
/* The navigation source.                                               */
/* Used In:                                                             */
/*  Mode 5 Transponder Basic Data                                       */
/************************************************************************/

enum NavigationSource
{
    NoStatementNavigationSource                                       = 0,
	GPS                                                               = 1,
	INS                                                               = 2,
	INS_GPS                                                           = 3	
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeNavigationSource();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorNavigationSource( KUINT32 Index );

KString GetEnumAsStringNavigationSource( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringNavigationSource( const KString & Value, KINT32 & ValueOut ); 

#endif // DIS 6

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
