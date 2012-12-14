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
                KUtils
    created:    23:9:2008
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

}; // END namespace UTILS
}; // END namespace KDIS
