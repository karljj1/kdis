/*********************************************************************
Copyright 2013 KDIS
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
