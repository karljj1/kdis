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
    class:      Supplies
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Represents a supply and its quantity
    size:       96 Bits / 12 Octets
*********************************************************************/

#pragma once

#include "./EntityType.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Supplies : public EntityType
{
protected:

    KFLOAT32 m_f32Quantity;

public:

    static const KUINT16 SUPPLIES_SIZE = 12;

    Supplies( void );

    Supplies( EntityKind Kind, KUINT8 Domain, Country Country, KUINT8 Categoy,
              KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra,
              KFLOAT32 Quantity );

    Supplies( EntityType Type, KFLOAT32 Quantity );

    Supplies( KDataStream & stream ) throw( KException );

    virtual ~Supplies( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Supplies::SetQuantity
    //              KDIS::DATA_TYPE::Supplies::GetQuantity
    // Description: Quantity for selected supply.
    // Parameter:   KFLOAT32  F, void
    //************************************
    void SetQuantity( KFLOAT32 F );
    KFLOAT32 GetQuantity() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Supplies::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Supplies::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Supplies & Value ) const;
    KBOOL operator != ( const Supplies & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
