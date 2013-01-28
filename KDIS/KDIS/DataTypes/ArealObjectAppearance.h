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
    class:      ArealObjectAppearance
    created:    17/03/2010
    author:     Karl Jones

    purpose:    Represents a areal objects appearance.
    size:       48 Bits / 6 Octet
*********************************************************************/

#pragma once

#include "./ObjectAppearance.h"
#include <bitset>

namespace KDIS {
namespace DATA_TYPE {

using std::bitset;
using KDIS::DATA_TYPE::ENUMS::Breach2bit;

class KDIS_EXPORT ArealObjectAppearance : public ObjectAppearance
{
protected:

    union
    {
        struct
        {
            KUINT32 m_ui32Breach : 2;
			KUINT32 m_ui32Unused : 14;
            KUINT32 m_ui32Mines  : 16;
        } m_Minefield;

        KUINT32 m_ui32SpecificAppearance;
    } m_SpecificAppearanceUnion;

public:

    static const KUINT16 AREAL_OBJECT_APPEARANCE_SIZE = 6;

    ArealObjectAppearance( void );

    ArealObjectAppearance( KDataStream & stream ) throw( KException );

    virtual ~ArealObjectAppearance( void );

    /************************************************************************/
    /* The following appearance values are only for areal's of the type:    */
    /*  Minefield                                                           */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::SetBreach
    //              KDIS::DATA_TYPE::ArealObjectAppearance::GetBreach
    // Description: Describes the breached appearance of the object.
    // Parameter:   Breach2bit B, void
    ////************************************
    void SetBreach( Breach2bit B );
    Breach2bit GetBreach() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::SetMineCount
    //              KDIS::DATA_TYPE::ArealObjectAppearance::GetMineCount
    // Description: The number of mines in the minefield.
    // Parameter:   KUINT16 M, void
    //************************************
    void SetMineCount( KUINT16 M );
    KUINT16 GetMineCount() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::GetAsString
    // Description: Returns a string representation of the appearance
    // Parameter:   const EntityType & EntType
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ArealObjectAppearance & Value ) const;
    KBOOL operator != ( const ArealObjectAppearance & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
