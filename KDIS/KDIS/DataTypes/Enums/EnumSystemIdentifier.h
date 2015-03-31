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
    EnumSystemIdentifier
    created:    05/12/2008
    author:     Karl Jones

    purpose:    Enums for System Identifier.
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* System Type                                                          */
/* System Type field in the System Identifier record of the             */
/* IFF/ATC/NAVAIDS PDU. General type of emitting system                 */
/* Used In:                                                             */
/*  System Identifier                                                   */
/************************************************************************/

enum SystemType
{
    OtherSystemType                                                   = 0,
    Mark_X_XII_ATCRBS_ModeS_Transponder                               = 1,
    Mark_X_XII_ATCRBS_ModeS_Interrogator                              = 2,
    Soviet_Transponder                                                = 3,
    Soviet_Interrogator                                               = 4,
    RRB_Transponder                                                   = 5
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeSystemType();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorSystemType( KUINT32 Index );

KString GetEnumAsStringSystemType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringSystemType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* System Name                                                          */
/* System name field in the System Identifier record of the             */
/* IFF/ATC/NAVAIDS PDU. Pariticular named type system                   */
/* Used In:                                                             */
/*  System Identifier                                                   */
/************************************************************************/

enum SystemName
{
    OtherSystemName                                                   = 0,
    Mark_X                                                            = 1,
    Mark_XII                                                          = 2,
    ATCRBS                                                            = 3,
    Soviet                                                            = 4,
    Mode_S                                                            = 5,
    Mark_X_XII_ATCRBS                                                 = 6,
    Mark_X_XII_ATCRBS_Mode_S                                          = 7,
    ARI_5954                                                          = 8,
    ARI_5983                                                          = 9
    // 10+ Not used
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeSystemName();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorSystemName( KUINT32 Index );

KString GetEnumAsStringSystemName( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringSystemName( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* System Mode                                                          */
/* System mode field in the System Identifier record of the             */
/* IFF/ATC/NAVAIDS PDU. Mode of operation for the named system          */
/* Used In:                                                             */
/*  System Identifier                                                   */
/************************************************************************/

enum SystemMode
{
    OtherSystemMode                                                   = 0
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeSystemMode();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorSystemMode( KUINT32 Index );

KString GetEnumAsStringSystemMode( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringSystemMode( const KString & Value, KINT32 & ValueOut );

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
