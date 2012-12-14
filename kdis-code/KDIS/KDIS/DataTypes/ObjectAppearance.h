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
    class:      ObjectAppearance
    created:    16/02/2010
    author:     Karl Jones

    purpose:    Represents the general object appearance.
    size:       16 Bits / 2 Octet
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::ObjectDamage;

class KDIS_EXPORT ObjectAppearance : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16PcComp         : 8;
            KUINT16 m_ui16Dmg            : 2;
            KUINT16 m_ui16Predistributed : 1;
            KUINT16 m_ui16State          : 1;
            KUINT16 m_ui16Smoking        : 1;
            KUINT16 m_ui16Flaming        : 1;
            KUINT16 m_ui16Unused         : 2;
        };

        KUINT16 m_ui16GeneralAppearance;
        KUINT8 m_ui8GeneralAppearance[2]; // Used for encode/decode
    } m_GeneralAppearanceUnion;

public:

    static const KUINT16 OBJECT_APPEARANCE_SIZE = 2;

    ObjectAppearance( void );

    ObjectAppearance( KDataStream & stream ) throw( KException );

    ObjectAppearance( KUINT8 PerCent, ObjectDamage OD, KBOOL Predist, KBOOL State,
                      KBOOL Smoking, KBOOL Flaming ) throw( KException );

    virtual ~ObjectAppearance( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::SetGeneralAppearance
    //              KDIS::DATA_TYPE::ObjectAppearance::GetGeneralAppearance
    // Description: General appearance bit field.
    // Parameter:   KUINT16 GA, void
    //************************************
    void SetGeneralAppearance( KUINT16 GA );
    KUINT16 GetGeneralAppearance() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::SetPercentageComplete
    //              KDIS::DATA_TYPE::ObjectAppearance::GetPercentageComplete
    // Description: Indicates the percent completion of the object.
    //              Acceptable values are 0 - 100 else throws INVALID_DATA exception.
    // Parameter:   KUINT8 P, void
    //************************************
    void SetPercentageComplete( KUINT8 P ) throw( KException );
    KUINT8 GetPercentageComplete() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::SetDamage
    //              KDIS::DATA_TYPE::ObjectAppearance::GetDamage
    // Description: Describes the damaged appearance of the object.
    // Parameter:   ObjectDamage OD, void
    //************************************
    void SetDamage( ObjectDamage OD );
    ObjectDamage GetDamage() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::SetPredistributed
    //              KDIS::DATA_TYPE::ObjectAppearance::IsPredistributed
    // Description: Describes whether the object was predistributed.
    //              false - Object created during the exercise
    //              true - Object predistributed prior to exercise start.
    // Parameter:   KBOOL P, void
    //************************************
    void SetPredistributed( KBOOL P );
    KBOOL IsPredistributed() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::SetState
    //              KDIS::DATA_TYPE::ObjectAppearance::GetState
    // Description: Describes the state of the object.
    //              false - Deactivated.
    //              true - Active.
    // Parameter:   KBOOL S, void
    //************************************
    void SetState( KBOOL S );
    KBOOL GetState() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::SetSmoking
    //              KDIS::DATA_TYPE::ObjectAppearance::IsSmoking
    // Description: Describes whether smoke is rising from an object.
    //              false - No smoke.
    //              true - Smoke present.
    // Parameter:   KBOOL S, void
    //************************************
    void SetSmoking( KBOOL S );
    KBOOL IsSmoking() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::SetFlaming
    //              KDIS::DATA_TYPE::ObjectAppearance::IsFlaming
    // Description: Describes whether Flames are rising from an object.
    //              false - No Flames.
    //              true - Flames present.
    // Parameter:   KBOOL F, void
    //************************************
    void SetFlaming( KBOOL F );
    KBOOL IsFlaming() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::GetAsString
    // Description: Returns a string representation of the appearance
    // Parameter:   const EntityType & EntType
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectAppearance::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ObjectAppearance & Value ) const;
    KBOOL operator != ( const ObjectAppearance & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
