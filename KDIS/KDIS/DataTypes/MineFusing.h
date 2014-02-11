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
    class:      MineFusing
    created:    11/06/2010
    author:     Karl Jones

    purpose:    Represent the primary, secondary fuse and anti-handling
                device for each mine.
    size:       16 bits / 2 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT MineFusing : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16Primary   : 7;
            KUINT16 m_ui16Secondary : 7;
            KUINT16 m_ui16AHD       : 1;
            KUINT16 m_ui16Unused    : 1;
        };

        KUINT16 m_ui16Fusing;
    } m_FuseUnion;

public:

    static const KUINT16 MINE_FUSING_SIZE = 2;

    MineFusing();

    MineFusing( KDIS::DATA_TYPE::ENUMS::MineFuse Primary, KDIS::DATA_TYPE::ENUMS::MineFuse Secondary, KBOOL AntiHandlingDevice );

    MineFusing( KDataStream & stream ) throw( KException );

    virtual ~MineFusing();

    //************************************
    // FullName:    KDIS::DATA_TYPE::MineFusing::SetPrimaryFuse
    //              KDIS::DATA_TYPE::MineFusing::GetPrimaryFuse
    // Description: Identifies the type of the primary fuse.
    // Parameter:   MineFuse F
    //************************************
    void SetPrimaryFuse( KDIS::DATA_TYPE::ENUMS::MineFuse F );
    KDIS::DATA_TYPE::ENUMS::MineFuse GetPrimaryFuse() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MineFusing::SetSecondaryFuse
    //              KDIS::DATA_TYPE::MineFusing::GetSecondaryFuse
    // Description: Identifies the type of the secondary fuse.
    // Parameter:   MineFuse F
    //************************************
    void SetSecondaryFuse( KDIS::DATA_TYPE::ENUMS::MineFuse F );
    KDIS::DATA_TYPE::ENUMS::MineFuse GetSecondaryFuse() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MineFusing::SetHasAntiHandlingDevice
    //              KDIS::DATA_TYPE::MineFusing::GetHasAntiHandlingDevice
    // Description: Describes the anti-handling device status of the mine
    //              true = anti-handling device.
    //              false = No anti-handling device.
    // Parameter:   KBOOL AHD
    //************************************
    void SetHasAntiHandlingDevice( KBOOL AHD );
    KBOOL GetHasAntiHandlingDevice() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MineFusing::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MineFusing::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MineFusing::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const MineFusing & Value ) const;
    KBOOL operator != ( const MineFusing & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

