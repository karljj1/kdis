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

using KDIS::DATA_TYPE::ENUMS::EntityKind;
using KDIS::DATA_TYPE::ENUMS::EntityDomain;
using KDIS::DATA_TYPE::ENUMS::Country;

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

    RadioEntityType( void );

    RadioEntityType( EntityKind Kind, KUINT8  Domain, Country Country, KUINT8  Categoy,
                     KUINT8  NomenclatureVersion, KUINT16 Nomenclature );

    RadioEntityType( KUINT8 Kind, KUINT8  Domain, KUINT8 Country, KUINT8  Categoy,
                     KUINT8  NomenclatureVersion, KUINT16 Nomenclature );

    RadioEntityType( KDataStream & stream ) throw( KException );

    virtual ~RadioEntityType( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetEntityKind
    //              KDIS::DATA_TYPE::RadioEntityType::GetEntityKind
    // Description: Kind
    // Parameter:   EntityKind UI, void
    //************************************
    void SetEntityKind( EntityKind UI );
    EntityKind GetEntityKind() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetDomain
    //              KDIS::DATA_TYPE::RadioEntityType::GetDomain
    // Description: Domain
    // Parameter:   EntityDomain  UI, void
    //************************************
    void SetDomain( EntityDomain UI );
    EntityDomain GetDomain() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetCountry
    //              KDIS::DATA_TYPE::RadioEntityType::GetCountry
    // Description: Country
    // Parameter:   Country UI, void
    //************************************
    void SetCountry( Country UI );
    Country GetCountry() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetCategory
    //              KDIS::DATA_TYPE::RadioEntityType::GetCategory
    // Description: Category
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetCategory( KUINT8 UI );
    KUINT8 GetCategory() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetNomenclatureVersion
    //              KDIS::DATA_TYPE::RadioEntityType::GetNomenclatureVersion
    // Description: Nomenclature, Version
    // Parameter:   KUINT8 UI, void
    //************************************
    void SetNomenclatureVersion( KUINT8 NV );
    KUINT8 GetNomenclatureVersion() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RadioEntityType::SetNomenclature
    //              KDIS::DATA_TYPE::RadioEntityType::GetNomenclature
    // Description: Nomenclature,
    // Parameter:   KINT16 N, void
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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

