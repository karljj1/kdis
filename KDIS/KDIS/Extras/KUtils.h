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
                KUtils
    created:    23/9/2008
    author:     Karl Jones

    purpose:    Utility Features
*********************************************************************/

#include "./../KDefines.h"
#include "./KConversions.h"
#include "./../KEncodersDecoders.h"

#define _USE_MATH_DEFINES
#include <math.h>

#pragma once

namespace KDIS {
namespace UTILS {

/************************************************************************/
/* Add a tab to all new lines in a string, used for formatting PDU data */
/************************************************************************/

static inline void AddTabsToStringStream( KStringStream & Stream, KUINT16 Tabs, KCHAR8 Tab )
{
    for( KUINT16 i = 0; i < Tabs; ++i )
    {
        Stream << Tab;
    }
}

//////////////////////////////////////////////////////////////////////////

static inline KString IndentString( const KString & S, KUINT16 Tabs = 1, KCHAR8 Tab = '\t' )
{
    KStringStream NewS;

    // Add tab to first item and then check all new lines
    AddTabsToStringStream( NewS, Tabs, Tab );

    for( KUINT16 i = 0; i < S.size(); ++i )
    {
        if( S.c_str()[i] == '\n' && i != ( S.size() - 1 ) )
        {
            NewS << S.c_str()[i];
            AddTabsToStringStream( NewS, Tabs, Tab );
        }
        else
        {
            NewS << S.c_str()[i];
        }
    }

    return NewS.str();
}

/************************************************************************/
/* Determine the endian of the machine at run time                      */
/************************************************************************/

static inline KBOOL IsMachineBigEndian()
{
    static KUINT16 ui = 0x01;

    static NetToKUINT16 conv( ui, false );

    if( conv.m_Octs[0] == 0x01 )
    {
        return false;
    }
    else
    {
        return true;
    }
};

} // END namespace UTILS
} // END namespace KDIS
