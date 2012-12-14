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
    KDISEncodersDecoders
    created:    17/9/2008
    author:     Karl Jones

    purpose:    Implementation of Encoding and Decoding classes.
                Convert an array of KOCTETs/bytes/chars etc into a
                appropriate data type
*********************************************************************/

#pragma once

#include "./KDefines.h"

/************************************************************************/
/* Encode / Decode Network Data.                                        */
/************************************************************************/

namespace KDIS {

template<class DataType>
union NetToDataType
{
    struct
    {
        KOCTET m_Octs[sizeof( DataType )];
    };
    DataType m_Value;

    //////////////////////////////////////////////////////

    void SwapBytes()
    {
        KOCTET Temp[sizeof( DataType )];

        // Copy Data To temp;
        for( KUINT16 i = 0; i < sizeof( DataType ); ++i )
        {
            Temp[i] = m_Octs[i];
        }

        // Now swap bytes
        KUINT16 j = ( sizeof( DataType ) ) - 1 ;

        for( KUINT16 i = 0; i < sizeof( DataType ); ++i )
        {
            m_Octs[i] = Temp[j];
            --j;
        }
    };

    //////////////////////////////////////////////////////

    NetToDataType( void )
    {
    };

    //////////////////////////////////////////////////////

    NetToDataType( const KOCTET * O, KBOOL SwapByteOrder = true )
    {
        for( KUINT16 i = 0; i < sizeof( DataType ); ++i )
        {
            m_Octs[i] = O[i];
        }

        if( SwapByteOrder )SwapBytes();
    };

    //////////////////////////////////////////////////////

    NetToDataType( DataType DT, KBOOL SwapByteOrder = true )
    {
        m_Value = DT;

        if( SwapByteOrder )SwapBytes();
    };
};

/************************************************************************/
/* Typedefs for all conversions                                         */
/************************************************************************/

typedef NetToDataType<KUINT32> NetToKUINT32;
typedef NetToDataType<KUINT16> NetToKUINT16;
typedef NetToDataType<KINT32> NetToKINT32;
typedef NetToDataType<KINT16> NetToKINT16;
typedef NetToDataType<KUINT64> NetToKUINT64;
typedef NetToDataType<KFLOAT32> NetToKFLOAT32;
typedef NetToDataType<KFLOAT64> NetToKFLOAT64;

};
