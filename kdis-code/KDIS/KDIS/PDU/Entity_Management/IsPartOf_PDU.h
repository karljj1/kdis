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
    class:      IsPartOf_PDU
    DIS:        (6) 1278.1A - 1998
    created:    26:06:2009
    author:     Karl Jones

    purpose:    Communicates the joining of two or more simulation entities to form a
                single entity with constituent parts.
    size:       416 bits / 52 octets
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Simulation_Management_Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/RelationshipRecord.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/NamedLocationIdentifier.h"
#include "./../../DataTypes/EntityType.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::RelationshipRecord;
using KDIS::DATA_TYPE::Vector;
using KDIS::DATA_TYPE::NamedLocationIdentifier;
using KDIS::DATA_TYPE::EntityType;

class KDIS_EXPORT IsPartOf_PDU : public Simulation_Management_Header
{
protected:

    RelationshipRecord m_RelRec;

    Vector  m_LocPrt;

    NamedLocationIdentifier m_NmLocID;

    EntityType m_PrtTyp;

public:

    static const KUINT16 IS_PART_OF_PDU_SIZE = 52;

    IsPartOf_PDU( void );

    IsPartOf_PDU( KDataStream & stream ) throw( KException );

    IsPartOf_PDU( const RelationshipRecord & RR, const Vector & LocationOfPart,
                  const NamedLocationIdentifier & NLI, const EntityType & PartType );

    virtual ~IsPartOf_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::SetRelationshipRecord
    //              KDIS::PDU::IsPartOf_PDU::GetRelationshipRecord
    // Description: Specifies the relationship of the part entity to its host entity.
    // Parameter:   const RelationshipRecord & RR, void
    //************************************
    void SetRelationshipRecord( const RelationshipRecord & RR );
    const RelationshipRecord & GetRelationshipRecord() const;
    RelationshipRecord & GetRelationshipRecord();

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::SetLocationOfPart
    //              KDIS::PDU::IsPartOf_PDU::GetLocationOfPart
    // Description: Specifies the location of the part’s centroid in the host entity’s coordinate system.
    //              Represented by an Entity Coordinate Vector record.
    //              The syntax of the part’s location data shall be specified by the Station Name enumeration. When the
    //              Station Name enumeration indicates On station (Range/Bearing or RNG/BRG), the three location data fields shall represent the Range (in meters),
    //              the Bearing (in radians), and the third field (the value zero). When the Station Name enumeration indicates On station
    //              (x, y, z), the three location data fields shall represent the x, y, and z coordinates of the part. When the
    //              Station Name enumeration is other than On station (RNG/BRG) or On station (x, y, z), the three
    //              fields of the Part Location record shall contain the value zero.
    // Parameter:   const Vector & LP, void
    //************************************
    void SetLocationOfPart( const Vector & LP );
    const Vector & GetLocationOfPart() const;
    Vector & GetLocationOfPart();

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::SetNamedLocationIdentifier
    //              KDIS::PDU::IsPartOf_PDU::GetNamedLocationIdentifier
    // Description: Contaiins information about the discrete positional relationship of the part
    //              entity with respect to the its host entity.
    // Parameter:   const NamedLocationIdentifier & NLI, void
    //************************************
    void SetNamedLocationIdentifier( const NamedLocationIdentifier & NLI );
    const NamedLocationIdentifier & GetNamedLocationIdentifier() const;
    NamedLocationIdentifier & GetNamedLocationIdentifier();

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::SetPartType
    //              KDIS::PDU::IsPartOf_PDU::GetPartType
    // Description: Identifies the part type.
    // Parameter:   const EntityType & PT, void
    //************************************
    void SetPartType( const EntityType & PT );
    const EntityType & GetPartType() const;
    EntityType & GetPartType();

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IsPartOf_PDU & Value ) const;
    KBOOL operator != ( const IsPartOf_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
