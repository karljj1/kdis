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

#include "./Bundle.h"

using namespace std;
using namespace KDIS;
using namespace PDU;

//////////////////////////////////////////////////////////////////////////
// Protected:
//////////////////////////////////////////////////////////////////////////

void Bundle::calculateLength()
{
	m_ui16Length = 0;

	vector<KDataStream>::const_iterator citrObj = m_vStreams.begin();
	vector<KDataStream>::const_iterator citrObjEnd = m_vStreams.end();
	for( ; citrObj != citrObjEnd; ++citrObj )
	{
		m_ui16Length += citrObj->GetBufferSize();
	}

	vector<PduPtr>::const_iterator citrRef = m_vRefHeaders.begin();
	vector<PduPtr>::const_iterator citrRefEnd = m_vRefHeaders.end();
	for( ; citrRef != citrRefEnd; ++citrRef )
	{
		m_ui16Length += ( *citrRef )->GetPDULength();
	}
}

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Bundle::Bundle() : 
	m_ui16Length( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Bundle::~Bundle()
{
}

//////////////////////////////////////////////////////////////////////////

void Bundle::AddPDU( const KDataStream & K ) throw( KException )
{
	m_vStreams.push_back( K );
	m_ui16Length += K.GetBufferSize();	
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

void Bundle::AddPDU( PduPtr H ) throw( KException )
{
	m_vRefHeaders.push_back( H );
	m_ui16Length += H->GetPDULength();
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

void Bundle::SetPDUs( const vector<KDataStream> & P ) throw( KException )
{
	m_vStreams = P;
	calculateLength();
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

void Bundle::SetPDUs( const vector<PduPtr> & P ) throw( KException )
{
	m_vRefHeaders = P;
	calculateLength();
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

void Bundle::SetPDUs( const vector<KDataStream> & Streams, const vector<PduPtr> & References ) throw( KException )
{
	m_vStreams = Streams;
	m_vRefHeaders = References;
	calculateLength();
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

const vector<KDataStream> & Bundle::GetPDUStreams() const
{
	return m_vStreams;
}

//////////////////////////////////////////////////////////////////////////

const vector<PduPtr> & Bundle::GetRefPDUs() const
{
	return m_vRefHeaders;
}

//////////////////////////////////////////////////////////////////////////

void Bundle::ClearPDUs()
{
	m_vStreams.clear();
	m_vRefHeaders.clear();
	m_ui16Length = 0;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Bundle::GetLength() 
{
	return m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

KString Bundle::GetAsString() 
{
    KStringStream ss;	
	
	ss << "***************************************************************";	
	ss << "PDU Bundle.\nTotal Length: " << m_ui16Length;
	ss << "***************************************************************";	

	// We only print the PDU, no point in printing the streams.

	//vector<KDataStream>::const_iterator citrObj = m_vStreams.begin();
	//vector<KDataStream>::const_iterator citrObjEnd = m_vStreams.end();
	//for( ; citrObj != citrObjEnd; ++citrObj )
	//{
	//	ss << citrObj->GetAsString();
	//}

	vector<PduPtr>::const_iterator citrRef = m_vRefHeaders.begin();
	vector<PduPtr>::const_iterator citrRefEnd = m_vRefHeaders.end();
	for( ; citrRef != citrRefEnd; ++citrRef )
	{
		ss << ( *citrRef )->GetAsString();
	}

	ss << "***************************************************************";	

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KDataStream Bundle::Encode() const
{
    KDataStream stream;

	Bundle::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Bundle::Encode( KDataStream & stream ) const
{
	// TODO: Check for 64 bit alignment and pad

	vector<KDataStream>::const_iterator citrObj = m_vStreams.begin();
	vector<KDataStream>::const_iterator citrObjEnd = m_vStreams.end();
	for( ; citrObj != citrObjEnd; ++citrObj )
	{
		stream.CopyFromBuffer( citrObj->GetBufferPtr(), citrObj->GetBufferSize() );
	}

	vector<PduPtr>::const_iterator citrRef = m_vRefHeaders.begin();
	vector<PduPtr>::const_iterator citrRefEnd = m_vRefHeaders.end();
	for( ; citrRef != citrRefEnd; ++citrRef )
	{
		( *citrRef )->Encode( stream );
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL Bundle::operator == ( const Bundle & Value ) const
{    
	if( m_vStreams    != Value.m_vStreams )    return false;
	if( m_vRefHeaders != Value.m_vRefHeaders ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Bundle::operator != ( const Bundle & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


