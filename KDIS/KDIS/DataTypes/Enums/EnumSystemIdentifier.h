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

KString GetEnumAsStringSystemMode( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringSystemMode( const KString & Value, KINT32 & ValueOut );

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
