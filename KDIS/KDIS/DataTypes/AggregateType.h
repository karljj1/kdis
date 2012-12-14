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
    class:      AggregateType
    created:    2009/02/07
    author:     Karl Jones

    purpose:    Holds DIS enum for Aggregate Type
    size:       64 bits / 8 Octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::AggregateKind;
using KDIS::DATA_TYPE::ENUMS::EntityDomain;
using KDIS::DATA_TYPE::ENUMS::Country;

class KDIS_EXPORT AggregateType : public DataTypeBase
{
protected:

    KUINT8 m_ui8Kind;

    KUINT8 m_ui8Domain;

    KUINT16 m_ui16Country;

    KUINT8 m_ui8Category;

    KUINT8 m_ui8SubCategory;

    KUINT8 m_ui8Specific;

    KUINT8 m_ui8Extra;

public:

    static const KUINT16 AGGREGATE_TYPE_SIZE = 8;

    AggregateType( void );

    AggregateType( AggregateKind Kind, KUINT8  Domain, Country Country, KUINT8  Categoy,
                   KUINT8  SubCategory, KUINT8  Specific, KUINT8  Extra );

    AggregateType( KUINT8 Kind, KUINT8  Domain, KUINT8 Country, KUINT8  Categoy,
                   KUINT8  SubCategory, KUINT8  Specific, KUINT8  Extra );

    AggregateType( KDataStream & stream ) throw( KException );

    virtual ~AggregateType( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::SetEntityKind
    //              KDIS::DATA_TYPE::AggregateType::GetEntityKind
    // Description: Kind
    // Parameter:   AggregateKind UI, void
    //************************************
    void SetEntityKind( AggregateKind AK );
    AggregateKind GetEntityKind() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::SetDomain
    //              KDIS::DATA_TYPE::AggregateType::GetDomain
    // Description: Domain - Same as Entity Type record
    // Parameter:   EntityDomain  UI, void
    //************************************
    void SetDomain( EntityDomain UI );
    EntityDomain GetDomain() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::SetCountry
    //              KDIS::DATA_TYPE::AggregateType::GetCountry
    // Description: Country
    // Parameter:   Country UI, void
    //************************************
    void SetCountry( Country UI );
    Country GetCountry() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::SetCategory
    //              KDIS::DATA_TYPE::AggregateType::GetCategory
    // Description: Category
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetCategory( KUINT8 UI );
    KUINT8 GetCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::SetSubCategory
    //              KDIS::DATA_TYPE::AggregateType::GetSubCategory
    // Description: Sub Category
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetSubCategory( KUINT8 UI );
    KUINT8 GetSubCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::SetSpecific
    //              KDIS::DATA_TYPE::AggregateType::GetSpecific
    // Description: Specific
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetSpecific( KUINT8 UI );
    KUINT8 GetSpecific() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::SetExtra
    //              KDIS::DATA_TYPE::AggregateType::GetExtra
    // Description: Extra
    // Parameter:   KUINT8  UI, void
    //************************************
    void SetExtra( KUINT8 UI );
    KUINT8 GetExtra() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const AggregateType & Value ) const;
    KBOOL operator != ( const AggregateType & Value ) const;
    KBOOL operator  < ( const AggregateType & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

