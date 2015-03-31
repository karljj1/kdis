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
    Detonation
    created:    17/09/2008    
    author:     Karl Jones

    purpose:    Enums used for Detonations
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Detonation Result                                                    */
/* Detonation Result Enums                                              */
/* Used In:                                                             */
/*  Detonation PDU                                                      */
/*  LE Detonation PDU                                                   */
/************************************************************************/

enum DetonationResult
{
    OtherDetonationResult                                             = 0,
    EntityImpact                                                      = 1,
    EntityProximateDetonation                                         = 2,
    GroundImpact                                                      = 3,
    GroundProximateDetonation                                         = 4,
    Detonation                                                        = 5,
    NoneOrNoDetonation_Dud                                            = 6,
    HEhit_Small                                                       = 7,
    HEhit_Medium                                                      = 8,
    HEhit_Large                                                       = 9,
    Armor_PiercingHit                                                 = 10,
    Dirtblast_Small                                                   = 11,
    Dirtblast_Medium                                                  = 12,
    Dirtblast_Large                                                   = 13,
    Waterblast_Small                                                  = 14,
    Waterblast_Medium                                                 = 15,
    Waterblast_Large                                                  = 16,
    AirHit                                                            = 17,
    BuildingHit_Small                                                 = 18,
    BuildingHit_Medium                                                = 19,
    BuildingHit_Large                                                 = 20,
    MineClearingLineCharge                                            = 21,
    EnvironmentObjectImpact                                           = 22,
    EnvironmentObjectProximateDetonation                              = 23,
    WaterImpact                                                       = 24,
    AirBurst                                                          = 25,
    KillWithFragmentType1                                             = 26,
    KillWithFragmentType2                                             = 27,
    KillWithFragmentType3                                             = 28,
    KillWithFragmentType1AfterflyOutFailure                           = 29,
    KillWithFragmentType2AfterflyOutFailure                           = 30,
    MissDueToflyOutFailure                                            = 31,
    MissDueToEndGameFailure                                           = 32,
    MissDueToflyOutAndEndGameFailure                                  = 33
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using GetEnumDescriptor<enum>.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will be returned.
KUINT32 GetEnumSizeDetonationResult();

// Returns the EnumDescriptor value for the specified index. 
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
const EnumDescriptor * GetEnumDescriptorDetonationResult( KUINT32 Index );

KString GetEnumAsStringDetonationResult( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetonationResult( const KString & Value, KINT32 & ValueOut ); 

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
