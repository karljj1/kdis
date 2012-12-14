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

#include "./Data_Query_R_PDU.h"

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

Data_Query_R_PDU::Data_Query_R_PDU( void )
{
    m_ui8PDUType = DataQuery_R_PDU_Type;
    m_ui16PDULength = DATA_QUERY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Data_Query_R_PDU::Data_Query_R_PDU( KDataStream & stream ) throw( KException )
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

Data_Query_R_PDU::~Data_Query_R_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KString Data_Query_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Data Query PDU-R-\n"
       << Simulation_Management_Header::GetAsString()
	   << Reliability_Header::GetAsString()
       << "Request ID:                   " << m_ui32RequestID
       << "\nTime Interval:            \n" << IndentString( m_TimeInterval.GetAsString() )
       << "\nNumber Fixed Datum:         " << m_ui32NumFixedDatum
       << "\nNumber Variable Datum:      " << m_ui32NumVariableDatum
       << "\n";

	ss << "Fixed Datum ID's\n";
    vector<KUINT32>::const_iterator citrFixed = m_vFixedDatum.begin();
	vector<KUINT32>::const_iterator citrFixedEnd = m_vFixedDatum.end();
    for( ; citrFixed != citrFixedEnd; ++citrFixed )
    {
        ss << "\t" << *citrFixed << "\n";
    }

	ss << "Variable Datum ID's\n";
    vector<KUINT32>::const_iterator citrVar = m_vVariableDatum.begin();
	vector<KUINT32>::const_iterator citrVarEnd = m_vVariableDatum.end();
    for( ; citrVar != citrVarEnd; ++citrVar )
    {
        ss << "\t" << *citrVar << "\n";
    }


    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Data_Query_R_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < DATA_QUERY_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream );
    Reliability_Header::Decode( stream );

	stream >> m_ui32RequestID
           >> KDIS_STREAM m_TimeInterval
           >> m_ui32NumFixedDatum
           >> m_ui32NumVariableDatum;

	KUINT32 tmp = 0;

	// FixedDatum
    for( KUINT16 i = 0; i < m_ui32NumFixedDatum; ++i )
    {
		stream >> tmp;
		m_vFixedDatum.push_back( tmp );
    }

	// VariableDatum
    for( KUINT16 i = 0; i < m_ui32NumVariableDatum; ++i )
    {
		stream >> tmp;
		m_vVariableDatum.push_back( tmp );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Data_Query_R_PDU::Encode() const
{
    KDataStream stream;

    Data_Query_R_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Data_Query_R_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );
    Reliability_Header::Encode( stream );

    stream << m_ui32RequestID
           << KDIS_STREAM m_TimeInterval
           << m_ui32NumFixedDatum
           << m_ui32NumVariableDatum;

    vector<KUINT32>::const_iterator citrFixed = m_vFixedDatum.begin();
	vector<KUINT32>::const_iterator citrFixedEnd = m_vFixedDatum.end();
    for( ; citrFixed != citrFixedEnd; ++citrFixed )
    {
        stream << *citrFixed;
    }

    vector<KUINT32>::const_iterator citrVar = m_vVariableDatum.begin();
	vector<KUINT32>::const_iterator citrVarEnd = m_vVariableDatum.end();
    for( ; citrVar != citrVarEnd; ++citrVar )
    {
        stream << *citrVar;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Data_Query_R_PDU::operator == ( const Data_Query_R_PDU & Value ) const
{
    if( Data_Query_PDU::operator     !=( Value ) ) return false;
    if( Reliability_Header::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Data_Query_R_PDU::operator != ( const Data_Query_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

