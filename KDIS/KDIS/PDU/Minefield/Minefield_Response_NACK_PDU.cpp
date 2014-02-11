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

#include "./Minefield_Response_NACK_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace std;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Minefield_Response_NACK_PDU::Minefield_Response_NACK_PDU() :
    m_ui8ReqID( 0 ),
    m_ui8NumMisPdus( 0 )
{
    m_ui8PDUType = MinefieldResponseNAK_PDU_Type;
    m_ui16PDULength = MINEFIELD_RESPONSE_NACK_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Minefield_Response_NACK_PDU::Minefield_Response_NACK_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Minefield_Response_NACK_PDU::Minefield_Response_NACK_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Minefield_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Minefield_Response_NACK_PDU::Minefield_Response_NACK_PDU( const EntityIdentifier & MinefieldID, const EntityIdentifier & RequestingSimulationID,
        KUINT8 ReqID ) :
    m_ReqID( RequestingSimulationID ),
    m_ui8ReqID( ReqID ),
    m_ui8NumMisPdus( 0 )
{
    m_MinefieldID = MinefieldID;
    m_ui8PDUType = MinefieldResponseNAK_PDU_Type;
    m_ui16PDULength = MINEFIELD_RESPONSE_NACK_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Minefield_Response_NACK_PDU::Minefield_Response_NACK_PDU( const EntityIdentifier & MinefieldID, const EntityIdentifier & RequestingSimulationID,
        KUINT8 ReqID, const vector<KUINT8> & MissingSeqNums ) :
    m_ReqID( RequestingSimulationID ),
    m_ui8ReqID( ReqID )
{
    m_MinefieldID = MinefieldID;
    m_ui8PDUType = MinefieldResponseNAK_PDU_Type;
    m_ui16PDULength = MINEFIELD_RESPONSE_NACK_SIZE;
    SetMissingPDUSequenceNumbers( MissingSeqNums );
}

//////////////////////////////////////////////////////////////////////////

Minefield_Response_NACK_PDU::~Minefield_Response_NACK_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Response_NACK_PDU::SetRequestingSimulationID( const EntityIdentifier & ID )
{
    m_ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Minefield_Response_NACK_PDU::GetRequestingSimulationID() const
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Minefield_Response_NACK_PDU::GetRequestingSimulationID()
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Response_NACK_PDU::SetRequestID( KUINT8 ID )
{
    m_ui8ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Response_NACK_PDU::GetRequestID() const
{
    return m_ui8ReqID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Response_NACK_PDU::GetNumberMissingPDUs() const
{
    return m_ui8NumMisPdus;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Response_NACK_PDU::AddMissingPDUSequenceNumber( KUINT8 N )
{
    m_vSeqNums.push_back( N );
    ++m_ui8NumMisPdus;
    ++m_ui16PDULength;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Response_NACK_PDU::SetMissingPDUSequenceNumbers( const std::vector<KUINT8> & N )
{
    m_vSeqNums = N;
    m_ui8NumMisPdus = N.size();
    m_ui16PDULength = MINEFIELD_RESPONSE_NACK_SIZE + m_ui8NumMisPdus;
}

//////////////////////////////////////////////////////////////////////////

const std::vector<KUINT8> & Minefield_Response_NACK_PDU::GetMissingPDUSequenceNumbers() const
{
    return m_vSeqNums;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Response_NACK_PDU::ClearMissingPDUSequenceNumbers()
{
    m_vSeqNums.clear();
    m_ui8NumMisPdus = 0;

    // Reset PDU length.
    m_ui16PDULength = MINEFIELD_RESPONSE_NACK_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString Minefield_Response_NACK_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Minefield Response NACK PDU-\n"
       << Minefield_Header::GetAsString()
       << "Requesting Entity ID.: " << m_ReqID.GetAsString()
       << "Request ID: "            << ( KUINT16 )m_ui8ReqID        << "\n"
       << "Number Missing PDU's: "  << ( KUINT16 )m_ui8NumMisPdus   << "\n"
       << "Missing PDU Sequence Numbers:\n";

    vector<KUINT8>::const_iterator citr = m_vSeqNums.begin();
    vector<KUINT8>::const_iterator citrEnd = m_vSeqNums.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << "\t" << ( KUINT16 )*citr << "\n";
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Response_NACK_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < MINEFIELD_RESPONSE_NACK_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vSeqNums.clear();

    Minefield_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_ReqID
           >> m_ui8ReqID
           >> m_ui8NumMisPdus;

    KUINT8 ui8Tmp = 0;
    for( KUINT8 i = 0; i < m_ui8NumMisPdus; ++i )
    {
        stream >> ui8Tmp;
        m_vSeqNums.push_back( ui8Tmp );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Minefield_Response_NACK_PDU::Encode() const
{
    KDataStream stream;

    Minefield_Response_NACK_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Response_NACK_PDU::Encode( KDataStream & stream ) const
{
    Minefield_Header::Encode( stream );

    stream << KDIS_STREAM m_ReqID
           << m_ui8ReqID
           << m_ui8NumMisPdus;

    vector<KUINT8>::const_iterator citr = m_vSeqNums.begin();
    vector<KUINT8>::const_iterator citrEnd = m_vSeqNums.end();
    for( ; citr != citrEnd; ++citr )
    {
        stream << *citr;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Minefield_Response_NACK_PDU::operator == ( const Minefield_Response_NACK_PDU & Value ) const
{
    if( Minefield_Header::operator  != ( Value ) )              return false;
    if( m_ReqID                     != Value.m_ReqID )          return false;
    if( m_ui8ReqID                  != Value.m_ui8ReqID )       return false;
    if( m_ui8NumMisPdus             != Value.m_ui8NumMisPdus )  return false;
    if( m_vSeqNums                  != Value.m_vSeqNums )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Minefield_Response_NACK_PDU::operator != ( const Minefield_Response_NACK_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
