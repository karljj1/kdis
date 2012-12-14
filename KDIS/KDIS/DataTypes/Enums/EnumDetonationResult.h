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

KString GetEnumAsStringDetonationResult( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetonationResult( const KString & Value, KINT32 & ValueOut ); 

#if DIS_VERSION > 6

/************************************************************************/
/* Detonation Type                                                      */
/* Indicates whether the type of object that detonated, exploded or     */
/* burst was a munition, expendable, or non-munition explosion.         */
/* Used In:                                                             */
/*  PDU Header 7                                                        */
/************************************************************************/

enum DetonationType
{
    MunitionDetonationType                                            = 0,
    ExpendableDetonationType                                          = 1,
	NonMunitionExplosionDetonationType                                = 2
};

KString GetEnumAsStringDetonationType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetonationType( const KString & Value, KINT32 & ValueOut ); 

#endif // DIS 7

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
