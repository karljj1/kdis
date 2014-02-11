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

    EnvironmentType();

    EnvironmentType( KUINT8 Kind, KDIS::DATA_TYPE::ENUMS::EntityDomain Domain, KUINT16 Class, KUINT8 Categoy,
                     KDIS::DATA_TYPE::ENUMS::EnvironmentSubcategory SubCategory, KUINT8 Specific, KUINT8 Extra );

    EnvironmentType( KDIS::DATA_TYPE::ENUMS::EntityDomain Domain, KUINT16 Class, KUINT8 Categoy,
                     KDIS::DATA_TYPE::ENUMS::EnvironmentSubcategory SubCategory, KUINT8 Specific, KUINT8 Extra );

    EnvironmentType( KDataStream & stream ) throw( KException );

    virtual ~EnvironmentType();

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
    void SetDomain( KDIS::DATA_TYPE::ENUMS::EntityDomain UI );
    KDIS::DATA_TYPE::ENUMS::EntityDomain GetDomain() const;

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
    void SetSubCategory( KDIS::DATA_TYPE::ENUMS::EnvironmentSubcategory UI );
    KDIS::DATA_TYPE::ENUMS::EnvironmentSubcategory GetSubCategory() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS

