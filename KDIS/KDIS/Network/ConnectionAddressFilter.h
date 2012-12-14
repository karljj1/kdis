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

using std::set;

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

	set<KString> m_Filter;

public:

	ConnectionAddressFilter( FilterMode FM = AllowAddressesInFilterList );

	~ConnectionAddressFilter( void );

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

}; // End namespace NETWORK
}; // End namespace KDIS
