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
    class:      MinefieldAppearance
    created:    04/05/2010
    author:     Karl Jones

    purpose:    Represents the appearance bits of the Minefield State PDU.
    size:       16 bits / 2 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::MinefieldType;

class KDIS_EXPORT MinefieldAppearance : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16Type          : 2;

            KUINT16 m_ui16ActiveStatus  : 1;

            KUINT16 m_ui16Lane          : 1;

            KUINT16 m_ui16Unused1       : 9;

            KUINT16 m_ui16State         : 1;

            KUINT16 m_ui16Unused        : 2;
        };
        KUINT16 m_ui16App;
    } m_ui16BitUnion;

public:

    static const KUINT16 MINEFIELD_APPEARANCE_SIZE = 2;

    MinefieldAppearance( void );

    MinefieldAppearance( MinefieldType T, KBOOL IsStatusActive, KBOOL IsLaneActive, KBOOL IsStateActive );

    MinefieldAppearance( KDataStream & stream ) throw( KException );

    virtual ~MinefieldAppearance( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::SetMinefieldType
    //              KDIS::DATA_TYPE::MinefieldAppearance::GetMinefieldType
    // Description: The type of mines in the minefield. Anti personnel, anti tank or mixed.
    // Parameter:   MinefieldType T, void
    //************************************
    void SetMinefieldType( MinefieldType T );
    MinefieldType GetMinefieldType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::SetStatusActive
    //              KDIS::DATA_TYPE::MinefieldAppearance::IsStatusActive
    // Description: Identifies the active status of the minefield.
    //              Note: The DIS standard(SISO-REF-010-2006) specifies 0 for true and 1 for false however they are
    //              flipped internally by KDIS so you can use true and false as you would expect to.
    // Parameter:   KBOOL A, void
    //************************************
    void SetStatusActive( KBOOL A );
    KBOOL IsStatusActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::SetLaneActive
    //              KDIS::DATA_TYPE::MinefieldAppearance::IsLaneActive
    // Description: Identifies whether the minefield has an active lane.
    //              Note: The DIS standard(SISO-REF-010-2006) specifies 0 for true and 1 for false however they are
    //              flipped internally by KDIS so you can use true and false as you would expect to.
    // Parameter:   KBOOL A, void
    //************************************
    void SetLaneActive( KBOOL A );
    KBOOL IsLaneActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::SetStateActive
    //              KDIS::DATA_TYPE::MinefieldAppearance::IsStateActive
    // Description: Describes the state of the minefield.
    //              Note: The DIS standard(SISO-REF-010-2006) specifies 0 for true and 1 for false however they are
    //              flipped internally by KDIS so you can use true and false as you would expect to.
    // Parameter:   KBOOL A, void
    //************************************
    void SetStateActive( KBOOL A );
    KBOOL IsStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const MinefieldAppearance & Value ) const;
    KBOOL operator != ( const MinefieldAppearance & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

