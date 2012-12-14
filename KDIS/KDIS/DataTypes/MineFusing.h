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

using KDIS::DATA_TYPE::ENUMS::MineFuse;

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

    MineFusing( void );

    MineFusing( MineFuse Primary, MineFuse Secondary, KBOOL AntiHandlingDevice );

    MineFusing( KDataStream & stream ) throw( KException );

    virtual ~MineFusing( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MineFusing::SetPrimaryFuse
    //              KDIS::DATA_TYPE::MineFusing::GetPrimaryFuse
    // Description: Identifies the type of the primary fuse.
    // Parameter:   MineFuse F
    //************************************
    void SetPrimaryFuse( MineFuse F );
    MineFuse GetPrimaryFuse() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MineFusing::SetSecondaryFuse
    //              KDIS::DATA_TYPE::MineFusing::GetSecondaryFuse
    // Description: Identifies the type of the secondary fuse.
    // Parameter:   MineFuse F
    //************************************
    void SetSecondaryFuse( MineFuse F );
    MineFuse GetSecondaryFuse() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

