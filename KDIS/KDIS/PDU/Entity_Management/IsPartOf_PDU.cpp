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

#include "./IsPartOf_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IsPartOf_PDU::IsPartOf_PDU()
{
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = IsPartOf_PDU_Type;
    m_ui16PDULength = IS_PART_OF_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IsPartOf_PDU::IsPartOf_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IsPartOf_PDU::IsPartOf_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Simulation_Management_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

IsPartOf_PDU::IsPartOf_PDU( const RelationshipRecord & RR, const Vector & LocationOfPart,
                            const NamedLocationIdentifier & NLI, const EntityType & PartType ) :
    m_RelRec( RR ),
    m_LocPrt( LocationOfPart ),
    m_NmLocID( NLI ),
    m_PrtTyp( PartType )
{
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = IsPartOf_PDU_Type;
    m_ui16PDULength = IS_PART_OF_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IsPartOf_PDU::~IsPartOf_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void IsPartOf_PDU::SetRelationshipRecord( const RelationshipRecord & RR )
{
    m_RelRec = RR;
}

//////////////////////////////////////////////////////////////////////////

const RelationshipRecord & IsPartOf_PDU::GetRelationshipRecord() const
{
    return m_RelRec;
}

//////////////////////////////////////////////////////////////////////////

RelationshipRecord & IsPartOf_PDU::GetRelationshipRecord()
{
    return m_RelRec;
}

//////////////////////////////////////////////////////////////////////////

void IsPartOf_PDU::SetLocationOfPart( const Vector & LP )
{
    m_LocPrt = LP;
}

//////////////////////////////////////////////////////////////////////////

const Vector & IsPartOf_PDU::GetLocationOfPart() const
{
    return m_LocPrt;
}

//////////////////////////////////////////////////////////////////////////

Vector & IsPartOf_PDU::GetLocationOfPart()
{
    return m_LocPrt;
}

//////////////////////////////////////////////////////////////////////////

void IsPartOf_PDU::SetNamedLocationIdentifier( const NamedLocationIdentifier & NLI )
{
    m_NmLocID = NLI;
}

//////////////////////////////////////////////////////////////////////////

const NamedLocationIdentifier & IsPartOf_PDU::GetNamedLocationIdentifier() const
{
    return m_NmLocID;
}

//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier & IsPartOf_PDU::GetNamedLocationIdentifier()
{
    return m_NmLocID;
}

//////////////////////////////////////////////////////////////////////////

void IsPartOf_PDU::SetPartType( const EntityType & PT )
{
    m_PrtTyp = PT;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & IsPartOf_PDU::GetPartType() const
{
    return m_PrtTyp;
}

//////////////////////////////////////////////////////////////////////////

EntityType & IsPartOf_PDU::GetPartType()
{
    return m_PrtTyp;
}

//////////////////////////////////////////////////////////////////////////

KString IsPartOf_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Transfer Control Request PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << m_RelRec.GetAsString()
       << "Location Of Part: " << m_LocPrt.GetAsString()
       << m_NmLocID.GetAsString()
       << "Part Type: " << m_PrtTyp.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IsPartOf_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < IS_PART_OF_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_RelRec
           >> KDIS_STREAM m_LocPrt
           >> KDIS_STREAM m_NmLocID
           >> KDIS_STREAM m_PrtTyp;
}

//////////////////////////////////////////////////////////////////////////

KDataStream IsPartOf_PDU::Encode() const
{
    KDataStream stream;

    IsPartOf_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IsPartOf_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );

    stream << KDIS_STREAM m_RelRec
           << KDIS_STREAM m_LocPrt
           << KDIS_STREAM m_NmLocID
           << KDIS_STREAM m_PrtTyp;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IsPartOf_PDU::operator == ( const IsPartOf_PDU & Value ) const
{
    if( Simulation_Management_Header::operator    !=( Value ) )        return false;
    if( m_RelRec                                  != Value.m_RelRec )  return false;
    if( m_LocPrt                                  != Value.m_LocPrt )  return false;
    if( m_NmLocID                                 != Value.m_NmLocID ) return false;
    if( m_PrtTyp                                  != Value.m_PrtTyp )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IsPartOf_PDU::operator != ( const IsPartOf_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


