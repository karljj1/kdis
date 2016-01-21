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
    class:      IsPartOf_PDU
    DIS:        (6) 1278.1A - 1998
    created:    26/06/2009
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

class KDIS_EXPORT IsPartOf_PDU : public Simulation_Management_Header
{
protected:

    KDIS::DATA_TYPE::RelationshipRecord m_RelRec;

    KDIS::DATA_TYPE::Vector m_LocPrt;

    KDIS::DATA_TYPE::NamedLocationIdentifier m_NmLocID;

    KDIS::DATA_TYPE::EntityType m_PrtTyp;

public:

    static const KUINT16 IS_PART_OF_PDU_SIZE = 52;

    IsPartOf_PDU();

    IsPartOf_PDU( KDataStream & stream ) throw( KException );

    IsPartOf_PDU( const Header & H, KDataStream & stream ) throw( KException );

    IsPartOf_PDU( const KDIS::DATA_TYPE::RelationshipRecord & RR, const KDIS::DATA_TYPE::Vector & LocationOfPart,
                  const KDIS::DATA_TYPE::NamedLocationIdentifier & NLI, const KDIS::DATA_TYPE::EntityType & PartType );

    virtual ~IsPartOf_PDU();

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::SetRelationshipRecord
    //              KDIS::PDU::IsPartOf_PDU::GetRelationshipRecord
    // Description: Specifies the relationship of the part entity to its host entity.
    // Parameter:   const RelationshipRecord & RR
    //************************************
    void SetRelationshipRecord( const KDIS::DATA_TYPE::RelationshipRecord & RR );
    const KDIS::DATA_TYPE::RelationshipRecord & GetRelationshipRecord() const;
    KDIS::DATA_TYPE::RelationshipRecord & GetRelationshipRecord();

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
    // Parameter:   const Vector & LP
    //************************************
    void SetLocationOfPart( const KDIS::DATA_TYPE::Vector & LP );
    const KDIS::DATA_TYPE::Vector & GetLocationOfPart() const;
    KDIS::DATA_TYPE::Vector & GetLocationOfPart();

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::SetNamedLocationIdentifier
    //              KDIS::PDU::IsPartOf_PDU::GetNamedLocationIdentifier
    // Description: Contaiins information about the discrete positional relationship of the part
    //              entity with respect to the its host entity.
    // Parameter:   const NamedLocationIdentifier & NLI
    //************************************
    void SetNamedLocationIdentifier( const KDIS::DATA_TYPE::NamedLocationIdentifier & NLI );
    const KDIS::DATA_TYPE::NamedLocationIdentifier & GetNamedLocationIdentifier() const;
    KDIS::DATA_TYPE::NamedLocationIdentifier & GetNamedLocationIdentifier();

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::SetPartType
    //              KDIS::PDU::IsPartOf_PDU::GetPartType
    // Description: Identifies the part type.
    // Parameter:   const EntityType & PT
    //************************************
    void SetPartType( const KDIS::DATA_TYPE::EntityType & PT );
    const KDIS::DATA_TYPE::EntityType & GetPartType() const;
    KDIS::DATA_TYPE::EntityType & GetPartType();

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::IsPartOf_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
