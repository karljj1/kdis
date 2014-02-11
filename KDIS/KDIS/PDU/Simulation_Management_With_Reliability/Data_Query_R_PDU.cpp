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

Data_Query_R_PDU::Data_Query_R_PDU()
{
    m_ui8PDUType = DataQuery_R_PDU_Type;
    m_ui16PDULength = DATA_QUERY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Data_Query_R_PDU::Data_Query_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Data_Query_R_PDU::Data_Query_R_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Data_Query_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Data_Query_R_PDU::~Data_Query_R_PDU()
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

void Data_Query_R_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < DATA_QUERY_R_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	
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

