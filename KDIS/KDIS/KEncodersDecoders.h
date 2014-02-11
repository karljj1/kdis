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

    NetToDataType()
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
