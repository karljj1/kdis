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

#include "./NamedLocationIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier::NamedLocationIdentifier( void ) :
    m_ui16StnName( 0 ),
    m_ui16StnNum( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier::NamedLocationIdentifier( StationName SN,  KUINT16 StationNumber ) :
    m_ui16StnName( SN ),
    m_ui16StnNum( StationNumber )
{
}

//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier::NamedLocationIdentifier( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier::~NamedLocationIdentifier( void )
{
}

//////////////////////////////////////////////////////////////////////////

void NamedLocationIdentifier::SetStationName( StationName SN )
{
    m_ui16StnName = SN;
}

//////////////////////////////////////////////////////////////////////////

StationName NamedLocationIdentifier::GetStationName() const
{
    return ( StationName )m_ui16StnName;
}

//////////////////////////////////////////////////////////////////////////

void NamedLocationIdentifier::SetStationNumber( KUINT16 SN )
{
    m_ui16StnNum = SN;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 NamedLocationIdentifier::GetStationNumber() const
{
    return m_ui16StnNum;
}

//////////////////////////////////////////////////////////////////////////

KString NamedLocationIdentifier::GetAsString() const
{
    KStringStream ss;

    ss << "Named Location Identifier:"
       << "\n\tName:   " << GetEnumAsStringStationName( m_ui16StnName )
       << "\n\tNumber: " << m_ui16StnNum
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void NamedLocationIdentifier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < NAMED_LOCATION_ID_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16StnName
           >> m_ui16StnNum;
}

//////////////////////////////////////////////////////////////////////////

KDataStream NamedLocationIdentifier::Encode() const
{
    KDataStream stream;

    NamedLocationIdentifier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void NamedLocationIdentifier::Encode( KDataStream & stream ) const
{
    stream << m_ui16StnName
           << m_ui16StnNum;
}

//////////////////////////////////////////////////////////////////////////

KBOOL NamedLocationIdentifier::operator == ( const NamedLocationIdentifier & Value ) const
{
    if( m_ui16StnName != Value.m_ui16StnName ) return false;
    if( m_ui16StnNum  != Value.m_ui16StnNum )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL NamedLocationIdentifier::operator != ( const NamedLocationIdentifier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


