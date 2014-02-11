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
    class:      DataTypeBase
    created:    18/09/2008
    author:     Karl Jones

    purpose:    Base class for all data types, all data types must
                provide a Decode/Encode functionality.
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./Enums/KDISEnums.h"
#include "./../KDataStream.h"
#include "./../Extras/KUtils.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT DataTypeBase
{
public:

    DataTypeBase();

    virtual ~DataTypeBase();

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const = 0;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException ) = 0;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const = 0;
    virtual void Encode( KDataStream & stream ) const = 0;

    friend KDataStream & operator >> ( KDataStream & stream, DataTypeBase * DTB )
    {
        DTB->Decode( stream );
        return stream;
    };

    friend KDataStream & operator << ( KDataStream & stream, DataTypeBase * DTB )
    {
        DTB->Encode( stream );
        return stream;
    };

    // For streaming a data type into a KDataStream,
#define KDIS_STREAM ( DataTypeBase * ) &
};

} // END namespace DATA_TYPES
} // END namespace KDIS
