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
    EnumDesignator
    created:    21/10/2008
    author:     Karl Jones

    purpose:    Enums used for Warfare/Designator.
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Designator Code Name                                                 */
/* As of "SISO-REF-010-2006" these values have yet to be determined     */
/* Used In:                                                             */
/*  Designator PDU                                                      */
/************************************************************************/

enum DesignatorCodeName
{
    OtherDesignatorCodeName                                           = 0
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeDesignatorCodeName();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorDesignatorCodeName( KUINT32 Index );

KString GetEnumAsStringDesignatorCodeName( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDesignatorCodeName( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Designator Code                                                      */
/* As of "SISO-REF-010-2006" these values have yet to be determined     */
/* Used In:                                                             */
/*  Designator PDU                                                      */
/************************************************************************/

enum DesignatorCode
{
    OtherDesignatorCode                                               = 0
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeDesignatorCode();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorDesignatorCode( KUINT32 Index );

KString GetEnumAsStringDesignatorCode( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDesignatorCode( const KString & Value, KINT32 & ValueOut ); 

// DIS 7
#if DIS_VERSION > 6

/************************************************************************/
/* BeamSpotShape                                                        */
/*  Identifies the pulse shape of a DE weapon.                          */
/* Used In:                                                             */
/*  Directed Energy Fire PDU                                            */
/************************************************************************/

enum BeamSpotShape
{
    OtherBeamSpotShape                                                = 0,
	Gaussian                                                          = 1,
	TopHat                                                            = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeBeamSpotShape();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorBeamSpotShape( KUINT32 Index );

KString GetEnumAsStringBeamSpotShape( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringBeamSpotShape( const KString & Value, KINT32 & ValueOut ); 

#endif

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
