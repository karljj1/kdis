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

#include "./AttributeRecordSet.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

AttributeRecordSet::AttributeRecordSet( void ) :
    m_ui16NumAttrRecs( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

AttributeRecordSet::AttributeRecordSet( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

AttributeRecordSet::AttributeRecordSet( const EntityIdentifier & EI ) :
	m_EntityID( EI ),
    m_ui16NumAttrRecs( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

AttributeRecordSet::~AttributeRecordSet( void )
{
}

//////////////////////////////////////////////////////////////////////////

void AttributeRecordSet::SetEntityIdentifier( const EntityIdentifier & EI )
{
	m_EntityID = EI;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & AttributeRecordSet::GetEntityIdentifier() const
{
	return m_EntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & AttributeRecordSet::GetEntityIdentifier()
{
	return m_EntityID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 AttributeRecordSet::GetNumberOfAttributeRecords() const
{
	return m_ui16NumAttrRecs;
}

//////////////////////////////////////////////////////////////////////////

void AttributeRecordSet::AddAttributeRecord( StdVarPtr AR )
{
	m_vAttrRec.push_back( AR );
	++m_ui16NumAttrRecs;
}

//////////////////////////////////////////////////////////////////////////

void AttributeRecordSet::SetAttributeRecords( const vector<StdVarPtr> & AR )
{
	m_vAttrRec = AR;
	m_ui16NumAttrRecs = m_vAttrRec.size();
}

//////////////////////////////////////////////////////////////////////////

const vector<StdVarPtr> & AttributeRecordSet::GetAttributeRecords() const
{
	return m_vAttrRec;
}

//////////////////////////////////////////////////////////////////////////

void AttributeRecordSet::ClearAttributeRecords()
{
	m_vAttrRec.clear();
	m_ui16NumAttrRecs = 0;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 AttributeRecordSet::GetRecordLength() const
{
	// Calculate the length
	KUINT16 len = 0;

	// Itterate through all the records and sum up the total length.
	vector<StdVarPtr>::const_iterator citr = m_vAttrRec.begin();
	vector<StdVarPtr>::const_iterator citrEnd = m_vAttrRec.end();
	for( ; citr != citrEnd; ++citr )
	{
		len += ( *citr )->GetRecordLength();
	}

	return len;
}

//////////////////////////////////////////////////////////////////////////

KString AttributeRecordSet::GetAsString() const
{
    KStringStream ss;

    ss << "AttributeRecordSet:"
	   << "\n\tEntity ID:\n" << IndentString( m_EntityID.GetAsString(), 2 )
	   << "\n\tNumber Of Attribute Records: " << m_ui16NumAttrRecs 
	   << "\n\tRecords:\n";

	vector<StdVarPtr>::const_iterator citr = m_vAttrRec.begin();
	vector<StdVarPtr>::const_iterator citrEnd = m_vAttrRec.end();
	for( ; citr != citrEnd; ++citr )
	{
		ss << IndentString( ( *citr )->GetAsString(), 1 );
	}

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void AttributeRecordSet::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ATTRIBUTE_RECORD_SET_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	m_vAttrRec.clear();

	stream >> KDIS_STREAM m_EntityID
		   >> m_ui16NumAttrRecs;

	for( KUINT16 i = 0; i < m_ui16NumAttrRecs; ++i )
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
			m_vAttrRec.push_back( StdVarPtr( p ) );
		}
		else
		{
			// Default
			m_vAttrRec.push_back( StdVarPtr( new StandardVariable( stream ) ) );
		}
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream AttributeRecordSet::Encode() const
{
    KDataStream stream;

    AttributeRecordSet::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void AttributeRecordSet::Encode( KDataStream & stream ) const
{
	stream << KDIS_STREAM m_EntityID
		   << m_ui16NumAttrRecs;

	vector<StdVarPtr>::const_iterator citr = m_vAttrRec.begin();
	vector<StdVarPtr>::const_iterator citrEnd = m_vAttrRec.end();
	for( ; citr != citrEnd; ++citr )
	{
		( *citr )->Encode( stream );
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL AttributeRecordSet::operator == ( const AttributeRecordSet & Value ) const
{
    if( m_EntityID        != Value.m_EntityID )        return false;
    if( m_ui16NumAttrRecs != Value.m_ui16NumAttrRecs ) return false;
	if( m_vAttrRec        != Value.m_vAttrRec )		   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AttributeRecordSet::operator != ( const AttributeRecordSet & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

