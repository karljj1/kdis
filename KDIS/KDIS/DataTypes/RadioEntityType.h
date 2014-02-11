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
    class:      RadioEntityType
    created:    2008/10/22
    author:     Karl Jones

    purpose:    Holds DIS enum for Radio Entity Type
    size:       64 bits / 8 Octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT RadioEntityType : public DataTypeBase
{
protected:

    KUINT8 m_ui8EntityKind;

    KUINT8 m_ui8Domain;

    KUINT16 m_ui16Country;

    KUINT8 m_ui8Category;

    KUINT8 m_ui8NomenclatureVersion;

    KUINT16 m_ui16Nomenclature;

public:

    static const KUINT16 RADIO_ENTITY_TYPE_SIZE = 8;

    RadioEntityType();

    RadioEntityType( KDIS::DATA_TYPE::ENUMS::EntityKind Kind, KUINT8 Domain, 
		             KDIS::DATA_TYPE::ENUMS::Country Country, KUINT8 Categoy, KUINT8 NomenclatureVersion,
					 KUINT16 Nomenclature );

    RadioEntityType( KUINT8 Kind, KUINT8 Domain, KUINT8 Country, KUINT8 Categoy,
                     KUINT8 NomenclatureVersion, KUINT16 Nomenclature );

    RadioEntityType( KDataStream & stream ) throw( KException );

    virtual ~RadioEntityType();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetEntityKind
    //              KDIS::DATA_TYPE::RadioEntityType::GetEntityKind
    // Description: Kind
    // Parameter:   EntityKind UI
    //************************************
    void SetEntityKind( KDIS::DATA_TYPE::ENUMS::EntityKind UI );
    KDIS::DATA_TYPE::ENUMS::EntityKind GetEntityKind() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetDomain
    //              KDIS::DATA_TYPE::RadioEntityType::GetDomain
    // Description: Domain
    // Parameter:   EntityDomain UI
    //************************************
    void SetDomain( KDIS::DATA_TYPE::ENUMS::EntityDomain UI );
    KDIS::DATA_TYPE::ENUMS::EntityDomain GetDomain() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetCountry
    //              KDIS::DATA_TYPE::RadioEntityType::GetCountry
    // Description: Country
    // Parameter:   Country UI
    //************************************
    void SetCountry( KDIS::DATA_TYPE::ENUMS::Country UI );
    KDIS::DATA_TYPE::ENUMS::Country GetCountry() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetCategory
    //              KDIS::DATA_TYPE::RadioEntityType::GetCategory
    // Description: Category
    // Parameter:   KUINT8 UI
    //************************************
    void SetCategory( KUINT8 UI );
    KUINT8 GetCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetNomenclatureVersion
    //              KDIS::DATA_TYPE::RadioEntityType::GetNomenclatureVersion
    // Description: Nomenclature Version
    // Parameter:   KUINT8 UI
    //************************************
    void SetNomenclatureVersion( KUINT8 NV );
    KUINT8 GetNomenclatureVersion() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetNomenclature
    //              KDIS::DATA_TYPE::RadioEntityType::GetNomenclature
    // Description: Nomenclature
    // Parameter:   KINT16 N
    //************************************
    void SetNomenclature( KUINT16 N );
    KUINT16 GetNomenclature() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const RadioEntityType & Value ) const;
    KBOOL operator != ( const RadioEntityType & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

