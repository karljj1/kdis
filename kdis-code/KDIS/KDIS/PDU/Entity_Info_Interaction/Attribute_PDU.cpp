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

#include "./Attribute_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace UTILS;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Attribute_PDU::Attribute_PDU( void ) :
    m_ui32Padding( 0 ),
    m_ui16Padding( 0 ),
    m_ui8ExtPDUType( 0 ),
    m_ui8ExtProtocolVersion( 0 ),
	m_ui32MasterRecType( 0 ),
	m_ui8Padding1( 0 ),
	m_ui8ActionCode( 0 ),
	m_ui16NumAttrRecSets( 0 )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = Attribute_PDU_Type;
    m_ui16PDULength = ATTRIBUTE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_200x;
}

//////////////////////////////////////////////////////////////////////////

Attribute_PDU::Attribute_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Attribute_PDU::Attribute_PDU( const SimulationIdentifier & OriginatingID, PDUType T, 
							  ProtocolVersion PV, AttributeID MART, ActionCode AC ) :
	m_OrigSimAddr( OriginatingID ),
    m_ui32Padding( 0 ),
    m_ui16Padding( 0 ),
    m_ui8ExtPDUType( T ),
    m_ui8ExtProtocolVersion( PV ),
	m_ui32MasterRecType( MART ),
	m_ui8Padding1( 0 ),
	m_ui8ActionCode( AC ),
	m_ui16NumAttrRecSets( 0 )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = Attribute_PDU_Type;
    m_ui16PDULength = ATTRIBUTE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_200x;
}

//////////////////////////////////////////////////////////////////////////

Attribute_PDU::~Attribute_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::SetOriginatingSimulationAddress( const SimulationIdentifier & ID )
{
    m_OrigSimAddr = ID;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & Attribute_PDU::GetOriginatingSimulationAddress() const
{
    return m_OrigSimAddr;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & Attribute_PDU::GetOriginatingSimulationAddress()
{
    return m_OrigSimAddr;
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::SetExtendedPDUType( PDUType T )
{
    m_ui8ExtPDUType = T;
}

//////////////////////////////////////////////////////////////////////////

PDUType Attribute_PDU::GetExtendedPDUType() const
{
    return ( PDUType )m_ui8ExtPDUType;
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::SetExtendedProtocolVersion( ProtocolVersion PV )
{
    m_ui8ExtProtocolVersion = PV;
}

//////////////////////////////////////////////////////////////////////////

ProtocolVersion Attribute_PDU::GetExtendedProtocolVersion() const
{
    return ( ProtocolVersion )m_ui8ExtProtocolVersion;
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::SetMasterAttributeRecordType( AttributeID MART )
{
	m_ui32MasterRecType = MART;
}

//////////////////////////////////////////////////////////////////////////

AttributeID Attribute_PDU::GetMasterAttributeRecordType() const
{
	return ( AttributeID )m_ui32MasterRecType;
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::SetActionCode( ActionCode AC )
{
	m_ui8ActionCode = AC;
}

//////////////////////////////////////////////////////////////////////////

ActionCode Attribute_PDU::GetActionCode() const
{
	return ( ActionCode )m_ui8ActionCode;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Attribute_PDU::GetNumberOfAttributeRecordSets() const
{
	return m_ui16NumAttrRecSets;
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::AddAttributeRecordSet( const AttributeRecordSet & AR )
{
	m_vAttributeRecordSets.push_back( AR );
	++m_ui16NumAttrRecSets;
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::SetAttributeRecordSets( const vector<AttributeRecordSet> & AR )
{
	ClearAttributeRecordSet();

	m_vAttributeRecordSets = AR;
	m_ui16NumAttrRecSets = m_vAttributeRecordSets.size();

	// Calculate the new pdu length
	vector<AttributeRecordSet>::const_iterator citr = m_vAttributeRecordSets.begin();
	vector<AttributeRecordSet>::const_iterator citrEnd = m_vAttributeRecordSets.end();
	for( ; citr != citrEnd; ++citr )
	{
		m_ui16PDULength += citr->GetRecordLength();	
	}
}

//////////////////////////////////////////////////////////////////////////

const vector<AttributeRecordSet> & Attribute_PDU::GetAttributeRecordSets() const
{
	return m_vAttributeRecordSets;
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::ClearAttributeRecordSet()
{
	// Reset the pdu length
	m_ui16PDULength = ATTRIBUTE_PDU_SIZE;
	m_vAttributeRecordSets.clear();
}
	
//////////////////////////////////////////////////////////////////////////

KString Attribute_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Attribute PDU-\n"
	   << "Originating Simulation Address:\n"
       << IndentString( m_OrigSimAddr.GetAsString(), 1 )
	   << "Extended PDU Type:  " << GetEnumAsStringPDUType( m_ui8ExtPDUType )                 << "\n"
	   << "Protocol Version:   " << GetEnumAsStringProtocolVersion( m_ui8ExtProtocolVersion ) << "\n"
	   << "Master Record Type: " << GetEnumAsStringAttributeID( m_ui32MasterRecType )         << "\n"
	   << "Action Code:        " << GetEnumAsStringActionCode( m_ui8ActionCode )              << "\n"
	   << "Number Of Records:  " << m_ui16NumAttrRecSets									  << "\n"
	   << "Record Sets:\n";

	vector<AttributeRecordSet>::const_iterator citr = m_vAttributeRecordSets.begin();
	vector<AttributeRecordSet>::const_iterator citrEnd = m_vAttributeRecordSets.end();
	for( ; citr != citrEnd; ++citr )
	{
		ss << IndentString( citr->GetAsString(), 1 );
	}		

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ATTRIBUTE_PDU_SIZE  )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	m_vAttributeRecordSets.clear();

    Header::Decode( stream );

	stream >> KDIS_STREAM m_OrigSimAddr
		   >> m_ui32Padding
		   >> m_ui16Padding
		   >> m_ui8ExtPDUType
		   >> m_ui8ExtProtocolVersion
		   >> m_ui32MasterRecType
		   >> m_ui8ActionCode
		   >> m_ui8Padding1
		   >> m_ui16NumAttrRecSets;

	for( KUINT16 i = 0; i < m_ui16NumAttrRecSets; ++i )
	{
		m_vAttributeRecordSets.push_back( AttributeRecordSet( stream ) );
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream Attribute_PDU::Encode() const
{
    KDataStream stream;

    Attribute_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Attribute_PDU::Encode( KDataStream & stream ) const
{
	Header::Encode( stream );

	stream << KDIS_STREAM m_OrigSimAddr
		   << m_ui32Padding
		   << m_ui16Padding
		   << m_ui8ExtPDUType
		   << m_ui8ExtProtocolVersion
		   << m_ui32MasterRecType
		   << m_ui8ActionCode
		   << m_ui8Padding1
		   << m_ui16NumAttrRecSets;

	vector<AttributeRecordSet>::const_iterator citr = m_vAttributeRecordSets.begin();
	vector<AttributeRecordSet>::const_iterator citrEnd = m_vAttributeRecordSets.end();
	for( ; citr != citrEnd; ++citr )
	{
		citr->Encode( stream );
	}		
}

//////////////////////////////////////////////////////////////////////////

KBOOL Attribute_PDU::operator == ( const Attribute_PDU & Value ) const
{
    if( Header::operator        !=( Value ) )                      return false;
    if( m_OrigSimAddr           != Value.m_OrigSimAddr )           return false;
    if( m_ui8ExtPDUType         != Value.m_ui8ExtPDUType )         return false;
    if( m_ui8ExtProtocolVersion != Value.m_ui8ExtProtocolVersion ) return false;
    if( m_ui32MasterRecType     != Value.m_ui32MasterRecType )     return false;
    if( m_ui8ActionCode         != Value.m_ui8ActionCode )         return false;
    if( m_ui16NumAttrRecSets    != Value.m_ui16NumAttrRecSets )    return false;
	if( m_vAttributeRecordSets  != Value.m_vAttributeRecordSets )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Attribute_PDU::operator != ( const Attribute_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

