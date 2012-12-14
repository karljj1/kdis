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

#include "./Entity_Damage_Status_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Entity_Damage_Status_PDU::Entity_Damage_Status_PDU( void ) : 
	m_ui32Padding( 0 ),
	m_ui16NumDmgDescRecs( 0 )
{
	m_ui8PDUType = Acknowledge_R_PDU_Type;
    m_ui16PDULength = ENTITY_DAMAGE_STATE_PDU;
	m_ui8ProtocolFamily = Warfare;
    m_ui8ProtocolVersion = IEEE_1278_1_200x;
}

//////////////////////////////////////////////////////////////////////////

Entity_Damage_Status_PDU::Entity_Damage_Status_PDU( const EntityIdentifier & DamagedEntityID ) :
	m_DmgEnt( DamagedEntityID ),
	m_ui16NumDmgDescRecs( 0 )
{
	m_ui8PDUType = Acknowledge_R_PDU_Type;
    m_ui16PDULength = ENTITY_DAMAGE_STATE_PDU;
	m_ui8ProtocolFamily = Warfare;
    m_ui8ProtocolVersion = IEEE_1278_1_200x;
}

//////////////////////////////////////////////////////////////////////////

Entity_Damage_Status_PDU::Entity_Damage_Status_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Entity_Damage_Status_PDU::~Entity_Damage_Status_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Entity_Damage_Status_PDU::SetDamagedEntityID( const EntityIdentifier & ID )
{
	m_DmgEnt = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Entity_Damage_Status_PDU::GetDamagedEntityID() const
{
	return m_DmgEnt;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Entity_Damage_Status_PDU::GetDamagedEntityID()
{
	return m_DmgEnt;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Entity_Damage_Status_PDU::GetNumberOfDamageDescriptionRecords() const
{
	return m_ui16NumDmgDescRecs;
}

//////////////////////////////////////////////////////////////////////////

void Entity_Damage_Status_PDU::AddDamageDescriptionRecord( StdVarPtr DD )
{
	m_vDdRec.push_back( DD );
	++m_ui16NumDmgDescRecs;
	m_ui16PDULength += DD->GetRecordLength();
}

//////////////////////////////////////////////////////////////////////////

void Entity_Damage_Status_PDU::SetDamageDescriptionRecords( const vector<StdVarPtr> & DD )
{
	m_vDdRec = DD;
	m_ui16NumDmgDescRecs = DD.size();
	m_ui16PDULength = ENTITY_DAMAGE_STATE_PDU;

	// Calculate new pdu length
	vector<StdVarPtr>::const_iterator citr = DD.begin();
	vector<StdVarPtr>::const_iterator citrEnd = DD.end();
	for( ; citr != citrEnd; ++citr )
	{
		m_ui16PDULength += ( *citr )->GetRecordLength();
	}
}

//////////////////////////////////////////////////////////////////////////

const vector<StdVarPtr> & Entity_Damage_Status_PDU::GetDamageDescriptionRecords() const
{
	return m_vDdRec;
}

//////////////////////////////////////////////////////////////////////////

void Entity_Damage_Status_PDU::ClearDamageDescriptionRecords()
{
	m_vDdRec.clear();
	m_ui16NumDmgDescRecs = 0;
	m_ui16PDULength = ENTITY_DAMAGE_STATE_PDU;
}

//////////////////////////////////////////////////////////////////////////

KString Entity_Damage_Status_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Entity Damage Status PDU-\n"
	   << "Damaged Entity ID:\n"
       << IndentString( m_DmgEnt.GetAsString(), 1 )
	   << "Number Of DD Records: " << m_ui16NumDmgDescRecs 
	   << "\nDE Records:\n";

	vector<StdVarPtr>::const_iterator citr = m_vDdRec.begin();
	vector<StdVarPtr>::const_iterator citrEnd = m_vDdRec.end();
	for( ; citr != citrEnd; ++citr )
	{
		ss << ( *citr )->GetAsString();
	}

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Entity_Damage_Status_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ENTITY_DAMAGE_STATE_PDU )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	m_vDdRec.clear();

	Header::Decode( stream );

	stream >> KDIS_STREAM m_DmgEnt
		   >> m_ui16NumDmgDescRecs;

	for( KUINT16 i = 0; i < m_ui16NumDmgDescRecs; ++i )
	{
		// Save the current write position so we can peek.
		KUINT16 pos = stream.GetCurrentWritePosition();
		KUINT32 datumID;

		// Extract the datum id then reset the stream.
		stream >> datumID;
		stream.SetCurrentWritePosition( pos );

		// Use the factory decoder. 
		StandardVariable * p = StandardVariable::FactoryDecode( datumID, stream );

		// Did we find a custom decoder? if not then use the default.
		if( p )
		{
			m_vDdRec.push_back( StdVarPtr( p ) );
		}
		else
		{
			// Default
			m_vDdRec.push_back( StdVarPtr( new StandardVariable( stream ) ) );
		}
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream Entity_Damage_Status_PDU::Encode() const
{
    KDataStream stream;

    Entity_Damage_Status_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Entity_Damage_Status_PDU::Encode( KDataStream & stream ) const
{
	Header::Encode( stream );

	stream << KDIS_STREAM m_DmgEnt
		   << m_ui16NumDmgDescRecs;

	vector<StdVarPtr>::const_iterator citr = m_vDdRec.begin();
	vector<StdVarPtr>::const_iterator citrEnd = m_vDdRec.end();
	for( ; citr != citrEnd; ++citr )
	{
		( *citr )->Encode( stream );
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL Entity_Damage_Status_PDU::operator == ( const Entity_Damage_Status_PDU & Value ) const
{
    if( Header::operator     !=( Value ) )                   return false;
    if( m_DmgEnt             != Value.m_DmgEnt )             return false;
	if( m_ui16NumDmgDescRecs != Value.m_ui16NumDmgDescRecs ) return false;
    if( m_vDdRec             != Value.m_vDdRec )             return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Entity_Damage_Status_PDU::operator != ( const Entity_Damage_Status_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////







