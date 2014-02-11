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

#include "./ConnectionAddressFilter.h"

using namespace std;
using namespace KDIS;
using namespace NETWORK;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ConnectionAddressFilter::ConnectionAddressFilter( FilterMode FM /* = AllowAddressesInFilterList */ ) :
	m_FM( FM )
{
}

//////////////////////////////////////////////////////////////////////////

ConnectionAddressFilter::~ConnectionAddressFilter()
{
}

//////////////////////////////////////////////////////////////////////////

void ConnectionAddressFilter::SetFilterMode( FilterMode FM )
{
	m_FM = FM;
}

//////////////////////////////////////////////////////////////////////////

ConnectionAddressFilter::FilterMode ConnectionAddressFilter::GetFilterMode() const
{
	return m_FM;
}

//////////////////////////////////////////////////////////////////////////

void ConnectionAddressFilter::AddAddress( const KString & A )
{
	m_Filter.insert( A );
}

//////////////////////////////////////////////////////////////////////////

void ConnectionAddressFilter::RemoveAddress( const KString & A )
{
	set<KString>::iterator itr = m_Filter.find( A );
	if( itr != m_Filter.end() )
	{
		// If we found the address then remove it.
		m_Filter.erase( itr );
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL ConnectionAddressFilter::TestAddress( const KString & A )
{
	// Check if the sender is in our filter.
	set<KString>::iterator itr = m_Filter.find( A );
	if( itr != m_Filter.end() )
	{
		return ( m_FM == AllowAddressesInFilterList ) ? true : false;
	}

	return ( m_FM == AllowAddressesInFilterList ) ? false : true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ConnectionAddressFilter::OnDataReceived( const KOCTET * Data, KUINT32 DataLength, const KString & SenderIp )
{
	return TestAddress( SenderIp );
}

//////////////////////////////////////////////////////////////////////////

