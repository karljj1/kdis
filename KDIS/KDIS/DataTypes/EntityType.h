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
    class:      EntityType
    created:    22/09/2008
    author:     Karl Jones

    purpose:    Holds DIS enum for Entity Type.
    size:       64 bits / 8 Octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::EntityKind;
using KDIS::DATA_TYPE::ENUMS::EntityDomain;
using KDIS::DATA_TYPE::ENUMS::Country;

class KDIS_EXPORT EntityType :  public DataTypeBase
{
protected:

    KUINT8 m_ui8EntityKind;

    KUINT8 m_ui8Domain;

    KUINT16 m_ui16Country;

    KUINT8 m_ui8Category;

    KUINT8 m_ui8SubCategory;

    KUINT8 m_ui8Specific;

    KUINT8 m_ui8Extra;

public:

    static const KUINT16 ENTITY_TYPE_SIZE = 8;

    EntityType( void );

    EntityType( EntityKind Kind, KUINT8 Domain, Country Country, KUINT8 Categoy,
                KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra );

    EntityType( KUINT8 Kind, KUINT8 Domain, KUINT16 Country, KUINT8  Categoy,
                KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra );

    EntityType( KDataStream & stream ) throw( KException );

    virtual ~EntityType( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetEntityKind
    //              KDIS::DATA_TYPE::EntityType::GetEntityKind
    // Description: Kind.
    // Parameter:   EntityKind UI
    //************************************
    void SetEntityKind( EntityKind UI );
    EntityKind GetEntityKind() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetDomain
    //              KDIS::DATA_TYPE::EntityType::GetDomain
    // Description: Domain.
    // Parameter:   EntityDomain  UI
    //************************************
    void SetDomain( EntityDomain UI );
    EntityDomain GetDomain() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetCountry
    //              KDIS::DATA_TYPE::EntityType::GetCountry
    // Description: Country.
    // Parameter:   Country UI
    //************************************
    void SetCountry( Country UI );
    Country GetCountry() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetCategory
    //              KDIS::DATA_TYPE::EntityType::GetCategory
    // Description: Category.
    // Parameter:   KUINT8 UI
    //************************************
    void SetCategory( KUINT8 UI );
    KUINT8 GetCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetSubCategory
    //              KDIS::DATA_TYPE::EntityType::GetSubCategory
    // Description: Sub Category.
    // Parameter:   KUINT8 UI
    //************************************
    void SetSubCategory( KUINT8 UI );
    KUINT8 GetSubCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetSpecific
    //              KDIS::DATA_TYPE::EntityType::GetSpecific
    // Description: Specific.
    // Parameter:   KUINT8 UI
    //************************************
    void SetSpecific( KUINT8 UI );
    KUINT8 GetSpecific() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetExtra
    //              KDIS::DATA_TYPE::EntityType::GetExtra
    // Description: Extra.
    // Parameter:   KUINT8  UI
    //************************************
    void SetExtra( KUINT8 UI );
    KUINT8 GetExtra() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::ReadFromTokenisedString
    // Description: Create a tokenised string to represent the type, such as csv.
    //              E.G a csv string such as "1, 1, 224, 0, 0, 0, 0"
    //              ReadFromTokenisedString Throws INVALID_DATA if 7 integer values are not found.
    //              Note: Any values less than 0 will be changed to 0.
    // Parameter:   const KString & String
    // Parameter:   KString & Seperator = ","
    //************************************
    void ReadFromTokenisedString( const KString & String, const KString & Seperator = "," ) throw( KException );
    KString CreateTokenisedString( const KString & Seperator = "," ) const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EntityType & Value ) const;
    KBOOL operator != ( const EntityType & Value ) const;
    KBOOL operator  < ( const EntityType & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

