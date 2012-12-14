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

#include "./Reliability_Header.h"

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

Reliability_Header::Reliability_Header( void ) :
    m_ui8ReqRelSrv( 0 ),
    m_ui16Padding1( 0 ),
    m_ui8Padding( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Reliability_Header::Reliability_Header( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Reliability_Header::Reliability_Header( RequiredReliabilityService RRS ) :
    m_ui8ReqRelSrv( RRS ),
    m_ui16Padding1( 0 ),
    m_ui8Padding( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Reliability_Header::~Reliability_Header( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Reliability_Header::SetRequiredReliabilityService( RequiredReliabilityService RRS )
{
    m_ui8ReqRelSrv = RRS;
}

//////////////////////////////////////////////////////////////////////////

RequiredReliabilityService Reliability_Header::GetRequiredReliabilityService() const
{
    return ( RequiredReliabilityService )m_ui8ReqRelSrv;
}

//////////////////////////////////////////////////////////////////////////

KString Reliability_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Required Reliability Service: " << GetEnumAsStringRequiredReliabilityService( m_ui8ReqRelSrv )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Reliability_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RELIABILITY_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8ReqRelSrv
           >> m_ui16Padding1
           >> m_ui8Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Reliability_Header::Encode() const
{
    KDataStream stream;

    Reliability_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Reliability_Header::Encode( KDataStream & stream ) const
{
    stream << m_ui8ReqRelSrv
           << m_ui16Padding1
           << m_ui8Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Reliability_Header::operator == ( const Reliability_Header & Value ) const
{
    if( m_ui8ReqRelSrv != Value.m_ui8ReqRelSrv ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Reliability_Header::operator != ( const Reliability_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
