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

KString GetEnumAsStringBeamSpotShape( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringBeamSpotShape( const KString & Value, KINT32 & ValueOut ); 

#endif

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
