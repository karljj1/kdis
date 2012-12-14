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

IsPartOf_PDU::IsPartOf_PDU( void )
{
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = IsPartOf_PDU_Type;
    m_ui16PDULength = IS_PART_OF_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IsPartOf_PDU::IsPartOf_PDU( KDataStream & stream ) throw( KException )
{
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
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

IsPartOf_PDU::~IsPartOf_PDU( void )
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

void IsPartOf_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < IS_PART_OF_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream );

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


