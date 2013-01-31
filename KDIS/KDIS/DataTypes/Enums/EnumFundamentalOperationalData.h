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
