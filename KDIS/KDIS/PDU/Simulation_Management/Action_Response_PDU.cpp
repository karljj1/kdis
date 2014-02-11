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

#include "./Action_Response_PDU.h"

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

Action_Response_PDU::Action_Response_PDU()
{
    m_ui8PDUType = Action_Response_PDU_Type;
    m_ui16PDULength = ACTION_RESPONSE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Action_Response_PDU::Action_Response_PDU( const Header & H ) :
	Data_PDU( H )
{
}

//////////////////////////////////////////////////////////////////////////

Action_Response_PDU::Action_Response_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Action_Response_PDU::Action_Response_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Data_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Action_Response_PDU::Action_Response_PDU( const Action_Request_PDU & pdu, RequestStatus RS ) :
    m_ui32RequestStatus( RS )
{
    m_ui8PDUType = Action_Response_PDU_Type;
    m_ui32RequestID = pdu.GetRequestID();
    m_OriginatingEntityID = pdu.GetOriginatingEntityID();
    m_OriginatingEntityID = pdu.GetReceivingEntityID();
    m_vVariableDatum = pdu.GetVariableDatum();
    m_vFixedDatum = pdu.GetFixedDatum();
    m_ui32NumFixedDatum = m_vFixedDatum.size();
    m_ui32NumVariableDatum = m_vVariableDatum.size();

    // Calculate the size
    m_ui16PDULength = ACTION_RESPONSE_PDU_SIZE + ( Action_Request_PDU::ACTION_REQUEST_PDU_SIZE - pdu.GetPDULength() );
}

//////////////////////////////////////////////////////////////////////////

Action_Response_PDU::~Action_Response_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Action_Response_PDU::SetRequestStatus( RequestStatus ID )
{
    m_ui32RequestStatus = ID;
}

//////////////////////////////////////////////////////////////////////////

RequestStatus Action_Response_PDU::GetRequestStatus() const
{
    return ( RequestStatus )m_ui32RequestStatus;
}

//////////////////////////////////////////////////////////////////////////

KString Action_Response_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Action Request PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "\tRequest ID:               "   << m_ui32RequestID
       << "\n\tRequest Status:           " << GetEnumAsStringRequestStatus( m_ui32RequestStatus )
       << "\n\tNumber Fixed Datum:       " << m_ui32NumFixedDatum
       << "\n\tNumber Variable Datum:    " << m_ui32NumVariableDatum
       << "\n";

	ss << "Fixed Datum:\n";
    vector<FixDtmPtr>::const_iterator citrFixed = m_vFixedDatum.begin();
	vector<FixDtmPtr>::const_iterator citrFixedEnd = m_vFixedDatum.end();
    for( ; citrFixed != citrFixedEnd; ++citrFixed )
    {
        ss << IndentString( ( *citrFixed )->GetAsString() );
    }

	ss << "Variable Datum:\n";
    vector<VarDtmPtr>::const_iterator citrVar = m_vVariableDatum.begin();
	vector<VarDtmPtr>::const_iterator citrVarEnd = m_vVariableDatum.end();
    for( ; citrVar != citrVarEnd; ++citrVar )
    {
        ss << IndentString( ( *citrVar )->GetAsString() );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Action_Response_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < ACTION_RESPONSE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> m_ui32RequestID
           >> m_ui32RequestStatus
           >> m_ui32NumFixedDatum
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

KDataStream Action_Response_PDU::Encode() const
{
    KDataStream stream;

    Action_Response_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Action_Response_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );
    stream << m_ui32RequestID
           << m_ui32RequestStatus
           << m_ui32NumFixedDatum
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

KBOOL Action_Response_PDU::operator == ( const Action_Response_PDU & Value ) const
{
    if( Data_PDU::operator   !=( Value ) )                  return false;
    if( m_ui32RequestStatus  != Value.m_ui32RequestStatus ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Action_Response_PDU::operator != ( const Action_Response_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


