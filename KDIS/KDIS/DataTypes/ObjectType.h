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
    class:      ObjectType
    created:    24/01/2010
    author:     Karl Jones

    purpose:    Represents the type of the synthetic environment
                object(point, linear and areal).
    size:       32 bits / 4 Octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::EntityDomain;

class KDIS_EXPORT ObjectType : public DataTypeBase
{
protected:

    KUINT8 m_ui8Domain;

    KUINT8 m_ui8EntityKind;

    KUINT8 m_ui8Category;

    KUINT8 m_ui8SubCategory;

public:

    static const KUINT16 OBJECT_TYPE_SIZE = 4;

    ObjectType( void );

    ObjectType( KUINT8 Domain, KUINT8 Kind, KUINT8  Categoy, KUINT8 SubCategory );

    ObjectType( KDataStream & stream ) throw( KException );

    virtual ~ObjectType( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::SetDomain
    //              KDIS::DATA_TYPE::ObjectType::GetDomain
    // Description: Objects domain.
    // Parameter:   EntityDomain  UI, void
    //************************************
    void SetDomain( EntityDomain UI );
    EntityDomain GetDomain() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::SetEntityKind
    //              KDIS::DATA_TYPE::ObjectType::GetEntityKind
    // Description: Object Kind.
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetEntityKind( KUINT8 UI );
    KUINT8 GetEntityKind() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::SetCategory
    //              KDIS::DATA_TYPE::ObjectType::GetCategory
    // Description: Category.
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetCategory( KUINT8 UI );
    KUINT8 GetCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::SetSubCategory
    //              KDIS::DATA_TYPE::ObjectType::GetSubCategory
    // Description: Sub Category.
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetSubCategory( KUINT8 UI );
    KUINT8 GetSubCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ObjectType & Value ) const;
    KBOOL operator != ( const ObjectType & Value ) const;
    KBOOL operator  < ( const ObjectType & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

