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

#include "./AttributeRecordSet.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

AttributeRecordSet::AttributeRecordSet() :
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

AttributeRecordSet::~AttributeRecordSet()
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

