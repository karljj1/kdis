
#include "./ConnectionAddressFilter.h"

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

ConnectionAddressFilter::~ConnectionAddressFilter( void )
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

