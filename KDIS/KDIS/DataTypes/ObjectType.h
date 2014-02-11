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

class KDIS_EXPORT ObjectType : public DataTypeBase
{
protected:

    KUINT8 m_ui8Domain;

    KUINT8 m_ui8EntityKind;

    KUINT8 m_ui8Category;

    KUINT8 m_ui8SubCategory;

public:

    static const KUINT16 OBJECT_TYPE_SIZE = 4;

    ObjectType();

    ObjectType( KUINT8 Domain, KUINT8 Kind, KUINT8  Categoy, KUINT8 SubCategory );

    ObjectType( KDataStream & stream ) throw( KException );

    virtual ~ObjectType();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::SetDomain
    //              KDIS::DATA_TYPE::ObjectType::GetDomain
    // Description: Objects domain.
    // Parameter:   EntityDomain  UI
    //************************************
    void SetDomain( KDIS::DATA_TYPE::ENUMS::EntityDomain UI );
    KDIS::DATA_TYPE::ENUMS::EntityDomain GetDomain() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::SetEntityKind
    //              KDIS::DATA_TYPE::ObjectType::GetEntityKind
    // Description: Object Kind.
    // Parameter:   KUINT8 UI
    //************************************
    void SetEntityKind( KUINT8 UI );
    KUINT8 GetEntityKind() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::SetCategory
    //              KDIS::DATA_TYPE::ObjectType::GetCategory
    // Description: Category.
    // Parameter:   KUINT8 UI
    //************************************
    void SetCategory( KUINT8 UI );
    KUINT8 GetCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ObjectType::SetSubCategory
    //              KDIS::DATA_TYPE::ObjectType::GetSubCategory
    // Description: Sub Category.
    // Parameter:   KUINT8 UI
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

} // END namespace DATA_TYPES
} // END namespace KDIS

