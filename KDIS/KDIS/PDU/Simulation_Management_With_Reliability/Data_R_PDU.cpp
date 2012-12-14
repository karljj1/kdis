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

#include "./Data_R_PDU.h"

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

Data_R_PDU::Data_R_PDU( void )
{
    m_ui8PDUType = Data_R_PDU_Type;
    m_ui16PDULength = DATA_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Data_R_PDU::Data_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Data_R_PDU::Data_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                        KUINT32 RequestID, RequiredReliabilityService RRS ) :
    Data_PDU( OriginatingEntityID, ReceivingEntityID, RequestID ),
    Reliability_Header( RRS )
{
    m_ui8PDUType = Data_R_PDU_Type;
    m_ui16PDULength = DATA_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Data_R_PDU::~Data_R_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KString Data_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Data PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "\tRequest ID:                "   << m_ui32RequestID
       << Reliability_Header::GetAsString()
       << "\n\tNumber Fixed Datum:        " << m_ui32NumFixedDatum
       << "\n\tNumber Variable Datum:     " << m_ui32NumVariableDatum
       << "\n";

    ss << "Fixed Datumn";
    vector<FixDtmPtr>::const_iterator citrFixed = m_vFixedDatum.begin();
	vector<FixDtmPtr>::const_iterator citrFixedEnd = m_vFixedDatum.end();
    for( ; citrFixed != citrFixedEnd; ++citrFixed )
    {
        ss << IndentString( ( *citrFixed )->GetAsString() );
    }

	ss << "Variable Datumn";
    vector<VarDtmPtr>::const_iterator citrVar = m_vVariableDatum.begin();
	vector<VarDtmPtr>::const_iterator citrVarEnd = m_vVariableDatum.end();
    for( ; citrVar != citrVarEnd; ++citrVar )
    {
        ss << IndentString( ( *citrVar )->GetAsString() );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Data_R_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < DATA_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream );

    stream >> m_ui32RequestID;

    Reliability_Header::Decode( stream );

    stream >> m_ui32NumFixedDatum
           >> m_ui32NumVariableDatum;

    // FixedDatum
    for( KUINT16 i = 0; i < m_ui32NumFixedDatum; ++i )
    {
		// Save the current write position so we can peek.
		KUINT16 pos = stream.GetCurrentWritePosition();
		KUINT32 datumID;

		// Extract the datum id then reset the stream.
		stream >> datumID;
		stream.SetCurrentWritePosition( pos );

		// Use the factory decoder. 
		FixedDatum * p = FixedDatum::FactoryDecode( datumID, stream );

		// Did we find a custom decoder? if not then use the default.
		if( p )
		{
			m_vFixedDatum.push_back( FixDtmPtr( p ) );
		}
		else
		{
			// Default
			m_vFixedDatum.push_back( FixDtmPtr( new FixedDatum( stream ) ) );
		}
    }

	// VariableDatum
    for( KUINT16 i = 0; i < m_ui32NumVariableDatum; ++i )
    {
		// Save the current write position so we can peek.
		KUINT16 pos = stream.GetCurrentWritePosition();
		KUINT32 datumID;

		// Extract the datum id then reset the stream.
		stream >> datumID;
		stream.SetCurrentWritePosition( pos );

		// Use the factory decoder. 
		VariableDatum * p = VariableDatum::FactoryDecode( datumID, stream );

		// Did we find a custom decoder? if not then use the default.
		if( p )
		{
			m_vVariableDatum.push_back( VarDtmPtr( p ) );
		}
		else
		{
			// Default
			m_vVariableDatum.push_back( VarDtmPtr( new VariableDatum( stream ) ) );
		}
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Data_R_PDU::Encode() const
{
    KDataStream stream;

    Data_R_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Data_R_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );

    stream << m_ui32RequestID;

    Reliability_Header::Encode( stream );

    stream << m_ui32NumFixedDatum
           << m_ui32NumVariableDatum;

    vector<FixDtmPtr>::const_iterator citrFixed = m_vFixedDatum.begin();
	vector<FixDtmPtr>::const_iterator citrFixedEnd = m_vFixedDatum.end();
    for( ; citrFixed != citrFixedEnd; ++citrFixed )
    {
        ( *citrFixed )->Encode( stream );
    }

    vector<VarDtmPtr>::const_iterator citrVar = m_vVariableDatum.begin();
	vector<VarDtmPtr>::const_iterator citrVarEnd = m_vVariableDatum.end();
    for( ; citrVar != citrVarEnd; ++citrVar )
    {
        ( *citrVar )->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Data_R_PDU::operator == ( const Data_R_PDU & Value ) const
{
    if( Data_PDU::operator           !=( Value ) ) return false;
    if( Reliability_Header::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Data_R_PDU::operator != ( const Data_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



