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

/********************************************************************
    class:      ConnectionAddressFilter
    created:    04/02/2011
    author:     Karl Jones

    purpose:    A simple filter for allowing data through based on its IP address.
*********************************************************************/

#pragma once

#include "./ConnectionSubscriber.h"
#include <set>

namespace KDIS {
namespace NETWORK {

class KDIS_EXPORT ConnectionAddressFilter : public ConnectionSubscriber
{
public:

	enum FilterMode
	{
		AllowAddressesInFilterList,
		BlockAddressesInFilterList
	};

protected:

	FilterMode m_FM;

	std::set<KString> m_Filter;

public:

	ConnectionAddressFilter( FilterMode FM = AllowAddressesInFilterList );

	~ConnectionAddressFilter();

	//************************************
	// FullName:    KDIS::NETWORK::ConnectionAddressFilter::SetFilterMode
	//              KDIS::NETWORK::ConnectionAddressFilter::GetFilterMode
	// Description: How is the filter operating? Should it block all
	//              addresses in its list or only allow those?
	// Parameter:   const KString & A
	//************************************
	void SetFilterMode( FilterMode FM );
	FilterMode GetFilterMode() const;

	//************************************
	// FullName:    KDIS::NETWORK::ConnectionAddressFilter::AddAddress
	// Description: Add an address to the filter list, this address will either
	//              be blocked or allowed depending on the FilterMode.
	// Parameter:   const KString & A
	//************************************
	void AddAddress( const KString & A );

	//************************************
	// FullName:    KDIS::NETWORK::ConnectionAddressFilter::RemoveAddress
	// Description: Remove an address from the filter list.
	//				If the address is not in the list then nothing happens.
	// Parameter:   const KString & A
	//************************************
	void RemoveAddress( const KString & A );

	//************************************
	// FullName:    KDIS::NETWORK::ConnectionAddressFilter::TestAddress
	// Description: Test an address to see if it will be allowed through the filter.
	//				Returns true if address is allowed else false.
	// Parameter:   const KString & A
	//************************************
	KBOOL TestAddress( const KString & A );

	//************************************
	// FullName:    KDIS::NETWORK::ConnectionAddressFilter::OnDataReceived
	// Description: This is where the filtering is done, we check if the IP address is in 
	//              the block/allow list and return true/false to allow/stop the PDU.
	// Parameter:   const KOCTET * Data
	// Parameter:   KUINT32 DataLength
	// Parameter:   const KString & SenderIp
	//************************************
	virtual KBOOL OnDataReceived( const KOCTET * Data, KUINT32 DataLength, const KString & SenderIp );
};

} // END namespace NETWORK
} // END namespace KDIS
