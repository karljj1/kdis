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

KString GetEnumAsStringTCAS( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTCAS( const KString & Value, KINT32 & ValueOut ); 

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
