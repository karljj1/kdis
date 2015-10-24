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

#include "./Data_Query_PDU.h"

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

Data_Query_PDU::Data_Query_PDU() :
	m_ui32RequestID( 0 ),
	m_ui32NumFixedDatum( 0 ),
	m_ui32NumVariableDatum( 0 )
{
    m_ui8PDUType = Data_Query_PDU_Type;
    m_ui16PDULength = DATA_QUERY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Data_Query_PDU::Data_Query_PDU( const Header & H ) :
	Simulation_Management_Header( H ),
	m_ui32RequestID( 0 ),
	m_ui32NumFixedDatum( 0 ),
	m_ui32NumVariableDatum( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Data_Query_PDU::Data_Query_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                                KUINT32 RequestID ):
	Simulation_Management_Header( OriginatingEntityID, ReceivingEntityID ),
	m_ui32RequestID( RequestID ),
	m_ui32NumFixedDatum( 0 ),
	m_ui32NumVariableDatum( 0 )
{
    m_ui8PDUType = Data_Query_PDU_Type;
    m_ui16PDULength = DATA_QUERY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Data_Query_PDU::Data_Query_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Data_Query_PDU::Data_Query_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Simulation_Management_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Data_Query_PDU::~Data_Query_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Data_Query_PDU::SetRequestID( KUINT32 ID )
{
    m_ui32RequestID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Data_Query_PDU::GetRequestID() const
{
    return m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

void Data_Query_PDU::SetTimeInterval( const TimeStamp & TI )
{
	m_TimeInterval = TI;
}

//////////////////////////////////////////////////////////////////////////

const TimeStamp & Data_Query_PDU::GetTimeInterval() const
{
    return m_TimeInterval;
}

//////////////////////////////////////////////////////////////////////////

TimeStamp & Data_Query_PDU::GetTimeInterval() 
{
    return m_TimeInterval;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Data_Query_PDU::GetNumberFIxedDatum() const
{
	return m_ui32NumFixedDatum;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Data_Query_PDU::GetNumberVariableDatum() const
{
	return m_ui32NumVariableDatum;
}

//////////////////////////////////////////////////////////////////////////

void Data_Query_PDU::AddFixedDatum( KUINT32 FD )
{
	m_vFixedDatum.push_back( FD );
	m_ui16PDULength += 4; // Size of KUINT32
	++m_ui32NumFixedDatum;
}

//////////////////////////////////////////////////////////////////////////

void Data_Query_PDU::SetFixedDatum( const vector<KUINT32> & FD )
{
	m_vFixedDatum = FD;
	m_ui32NumFixedDatum = FD.size();
	m_ui16PDULength = DATA_QUERY_PDU_SIZE + ( m_ui32NumFixedDatum + m_ui32NumVariableDatum ) * 4; // Size of KUINT32
}

//////////////////////////////////////////////////////////////////////////

const vector<KUINT32> & Data_Query_PDU::GetFixedDatum() const
{
	return m_vFixedDatum;
}

//////////////////////////////////////////////////////////////////////////

void Data_Query_PDU::AddVariableDatum( KUINT32 VD )
{
	m_vVariableDatum.push_back( VD );
	m_ui16PDULength += 4; // Size of KUINT32
	++m_ui32NumVariableDatum;
}

//////////////////////////////////////////////////////////////////////////

void Data_Query_PDU::SetVariableDatum( const vector<KUINT32> & VD )
{
	m_vVariableDatum = VD;
	m_ui32NumVariableDatum = VD.size();
	m_ui16PDULength = DATA_QUERY_PDU_SIZE + ( m_ui32NumFixedDatum + m_ui32NumVariableDatum ) * 4; // Size of KUINT32
}

//////////////////////////////////////////////////////////////////////////

const vector<KUINT32> & Data_Query_PDU::GetVariableDatum() const
{
	return m_vVariableDatum;
}

//////////////////////////////////////////////////////////////////////////

KString Data_Query_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Data Query PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "Request ID:       "             << m_ui32RequestID
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

void Data_Query_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < DATA_QUERY_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	m_vFixedDatum.clear();
	m_vVariableDatum.clear();
	
    Simulation_Management_Header::Decode( stream, ignoreHeader );	

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

KDataStream Data_Query_PDU::Encode() const
{
    KDataStream stream;

    Data_Query_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Data_Query_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );
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

KBOOL Data_Query_PDU::operator == ( const Data_Query_PDU & Value ) const
{
    if( Simulation_Management_Header::operator !=( Value ) )     return false;
    if( m_TimeInterval         != Value.m_TimeInterval )         return false;
	if( m_ui32NumFixedDatum    != Value.m_ui32NumFixedDatum )    return false;
	if( m_ui32NumVariableDatum != Value.m_ui32NumVariableDatum ) return false;
	if( m_vFixedDatum          != Value.m_vFixedDatum )          return false;
	if( m_vVariableDatum       != Value.m_vVariableDatum )       return false;	
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Data_Query_PDU::operator != ( const Data_Query_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
