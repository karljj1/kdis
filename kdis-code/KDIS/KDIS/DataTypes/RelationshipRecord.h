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
    class:      RelationshipRecord
    created:    26:06:2008
    author:     Karl Jones

    purpose:    Specifies the relationship of the part entity to its host entity.
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::RelationshipNature;
using KDIS::DATA_TYPE::ENUMS::RelationshipPosition;

class KDIS_EXPORT RelationshipRecord : public DataTypeBase
{
protected:

    KUINT16 m_ui16Nature;

    KUINT16 m_ui16Pos;

public:

    static const KUINT16 RELATIONSHIP_RECORD_SIZE = 4;

    RelationshipRecord( void );

    RelationshipRecord( KDataStream & stream )throw( KException );

    RelationshipRecord( RelationshipNature N, RelationshipPosition P );

    virtual ~RelationshipRecord( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelationshipRecord::SetNature
    //              KDIS::DATA_TYPE::RelationshipRecord::GetNature
    // Description: Nature or purpose for joining of the part entity to the host
    //              entity within a IsPartOf PDU.
    // Parameter:   RelationshipNature N, void
    //************************************
    void SetNature( RelationshipNature N );
    RelationshipNature GetNature() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelationshipRecord::SetPosition
    //              KDIS::DATA_TYPE::RelationshipRecord::GetPosition
    // Description: Specifies the position of the part entity with respect to the host
    //              entity within a IsPartOf PDU.
    // Parameter:   RelationshipPosition P, void
    //************************************
    void SetPosition( RelationshipPosition P );
    RelationshipPosition GetPosition() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelationshipRecord::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelationshipRecord::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelationshipRecord::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const RelationshipRecord & Value ) const;
    KBOOL operator != ( const RelationshipRecord & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
