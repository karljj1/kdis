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

    EntityType();

    EntityType( KDIS::DATA_TYPE::ENUMS::EntityKind Kind, KUINT8 Domain, KDIS::DATA_TYPE::ENUMS::Country Country, KUINT8 Categoy,
                KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra );

    EntityType( KUINT8 Kind, KUINT8 Domain, KUINT16 Country, KUINT8  Categoy,
                KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra );

    EntityType( KDataStream & stream ) throw( KException );

    virtual ~EntityType();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetEntityKind
    //              KDIS::DATA_TYPE::EntityType::GetEntityKind
    // Description: Kind.
    // Parameter:   EntityKind UI
    //************************************
    void SetEntityKind( KDIS::DATA_TYPE::ENUMS::EntityKind UI );
    KDIS::DATA_TYPE::ENUMS::EntityKind GetEntityKind() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetDomain
    //              KDIS::DATA_TYPE::EntityType::GetDomain
    // Description: Domain.
    // Parameter:   EntityDomain  UI
    //************************************
    void SetDomain( KDIS::DATA_TYPE::ENUMS::EntityDomain UI );
    KDIS::DATA_TYPE::ENUMS::EntityDomain GetDomain() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityType::SetCountry
    //              KDIS::DATA_TYPE::EntityType::GetCountry
    // Description: Country.
    // Parameter:   Country UI
    //************************************
    void SetCountry( KDIS::DATA_TYPE::ENUMS::Country UI );
    KDIS::DATA_TYPE::ENUMS::Country GetCountry() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS

