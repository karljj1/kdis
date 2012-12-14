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

#include "./Bundle.h"

using namespace KDIS;
using namespace PDU;

//////////////////////////////////////////////////////////////////////////
// Protected:
//////////////////////////////////////////////////////////////////////////

void Bundle::calculateLength()
{
	m_ui16Length = 0;

	vector<Header>::const_iterator citrObj = m_vHeaders.begin();
	vector<Header>::const_iterator citrObjEnd = m_vHeaders.end();
	for( ; citrObj != citrObjEnd; ++citrObj )
	{
		m_ui16Length += citrObj->GetPDULength();
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

Bundle::Bundle( void ) : 
	m_ui16Length( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Bundle::~Bundle( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Bundle::AddPDU( const Header & H )
{
	m_vHeaders.push_back( H );
	m_ui16Length += H.GetPDULength();	
}

//////////////////////////////////////////////////////////////////////////

void Bundle::AddPDU( PduPtr H )
{
	m_vRefHeaders.push_back( H );
	m_ui16Length += H->GetPDULength();
}

//////////////////////////////////////////////////////////////////////////

void Bundle::SetPDUs( const vector<Header> & P )
{
	m_vHeaders = P;

	// Reset length
	m_ui16Length = 0;
}

//////////////////////////////////////////////////////////////////////////

void Bundle::SetPDUs( const vector<PduPtr> & P )
{
	m_vRefHeaders = P;

	// Reset length
	m_ui16Length = 0;
}

//////////////////////////////////////////////////////////////////////////

void Bundle::SetPDUs( const vector<Header> & Objects, const vector<PduPtr> & References )
{
	m_vHeaders = Objects;
	m_vRefHeaders = References;

	// Reset length
	m_ui16Length = 0;
}

//////////////////////////////////////////////////////////////////////////

const vector<Header> & Bundle::GetPDUs() const
{
	return m_vHeaders;
}

//////////////////////////////////////////////////////////////////////////

const vector<PduPtr> & Bundle::GetRefPDUs() const
{
	return m_vRefHeaders;
}

//////////////////////////////////////////////////////////////////////////

void Bundle::ClearPDUs()
{
	m_vHeaders.clear();
	m_vRefHeaders.clear();
	m_ui16Length = 0;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Bundle::GetLength() 
{
	// Check if the length has been calculated
	if( m_ui16Length == 0 )
	{
		calculateLength();
	}

	return m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

KString Bundle::GetAsString() 
{
    KStringStream ss;	
	
	ss << "***************************************************************";	
	ss << "PDU Bundle.\nTotal Length: " << GetLength();
	ss << "***************************************************************";	

	vector<Header>::const_iterator citrObj = m_vHeaders.begin();
	vector<Header>::const_iterator citrObjEnd = m_vHeaders.end();
	for( ; citrObj != citrObjEnd; ++citrObj )
	{
		ss << citrObj->GetAsString();
	}

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

	vector<Header>::const_iterator citrObj = m_vHeaders.begin();
	vector<Header>::const_iterator citrObjEnd = m_vHeaders.end();
	for( ; citrObj != citrObjEnd; ++citrObj )
	{
		citrObj->Encode( stream );
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
	if( m_vHeaders != Value.m_vHeaders )       return false;
	if( m_vRefHeaders != Value.m_vRefHeaders ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Bundle::operator != ( const Bundle & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


