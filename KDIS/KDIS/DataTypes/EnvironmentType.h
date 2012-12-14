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
    class:      EnvironmentType
    created:    27/06/2009
    author:     Karl Jones

    purpose:    Holds DIS enum for Environment Type.
    size:       64 bits / 8 Octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::EntityDomain;
using KDIS::DATA_TYPE::ENUMS::EnvironmentSubcategory;

class KDIS_EXPORT EnvironmentType : public DataTypeBase
{
protected:

    KUINT8 m_ui8EntityKind; // This value should allways be Environmental(4)

    KUINT8 m_ui8Domain;

    KUINT16 m_ui16Class;

    KUINT8 m_ui8Category;

    KUINT8 m_ui8SubCategory;

    KUINT8 m_ui8Specific;

    KUINT8 m_ui8Extra;

public:

    static const KUINT16 ENVIROMENT_TYPE_SIZE = 8;

    EnvironmentType( void );

    EnvironmentType( KUINT8 Kind, EntityDomain Domain, KUINT16 Class, KUINT8 Categoy,
                     EnvironmentSubcategory SubCategory, KUINT8 Specific, KUINT8 Extra );

    EnvironmentType( EntityDomain Domain, KUINT16 Class, KUINT8 Categoy,
                     EnvironmentSubcategory SubCategory, KUINT8 Specific, KUINT8 Extra );

    EnvironmentType( KDataStream & stream ) throw( KException );

    virtual ~EnvironmentType( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateType::SetKind
    //              KDIS::DATA_TYPE::AggregateType::GetKind
    // Description: Kind. This values should be 4 according to the EBV document however
    //              some DIS application do use other values for custom types.
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetKind( KUINT8 K );
    KUINT8 GetKind() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentType::SetDomain
    //              KDIS::DATA_TYPE::EnvironmentType::GetDomain
    // Description: Domain
    // Parameter:   EntityDomain  UI, void
    //************************************
    void SetDomain( EntityDomain UI );
    EntityDomain GetDomain() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentType::SetClass
    //              KDIS::DATA_TYPE::EnvironmentType::GetClass
    // Description: Class
    // Parameter:   KUINT16 CL, void
    //************************************
    void SetClass( KUINT16 UI );
    KUINT16 GetClass() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentType::SetCategory
    //              KDIS::DATA_TYPE::EnvironmentType::GetCategory
    // Description: Category
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetCategory( KUINT8 UI );
    KUINT8 GetCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentType::SetSubCategory
    //              KDIS::DATA_TYPE::EnvironmentType::GetSubCategory
    // Description: Sub Category
    // Parameter:   EnvironmentSubcategory UI, void
    //************************************
    void SetSubCategory( EnvironmentSubcategory UI );
    EnvironmentSubcategory GetSubCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentType::SetSpecific
    //              KDIS::DATA_TYPE::EnvironmentType::GetSpecific
    // Description: Specific
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetSpecific( KUINT8 UI );
    KUINT8 GetSpecific() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentType::SetExtra
    //              KDIS::DATA_TYPE::EnvironmentType::GetExtra
    // Description: Extra
    // Parameter:   KUINT8  UI, void
    //************************************
    void SetExtra( KUINT8 UI );
    KUINT8 GetExtra() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentType::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentType::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnvironmentType::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EnvironmentType & Value ) const;
    KBOOL operator != ( const EnvironmentType & Value ) const;
    KBOOL operator  < ( const EnvironmentType & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

