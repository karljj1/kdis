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

#include "./IO_Header.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IO_Header::IO_Header( void )
{
    m_ui8ProtocolFamily = Information_Operations;
    m_ui8ProtocolVersion = IEEE_1278_1_200x;
}

//////////////////////////////////////////////////////////////////////////

IO_Header::IO_Header( const EntityIdentifier & OrigID ) :
    m_OriginatingEntityID( OrigID )
{
    m_ui8ProtocolFamily = Information_Operations;
    m_ui8ProtocolVersion = IEEE_1278_1_200x;
}

//////////////////////////////////////////////////////////////////////////

IO_Header::IO_Header( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

IO_Header::~IO_Header( void )
{
}

//////////////////////////////////////////////////////////////////////////

void IO_Header::SetOriginatingEntityID( const EntityIdentifier & ID )
{
    m_OriginatingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IO_Header::GetOriginatingEntityID() const
{
    return m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IO_Header::GetOriginatingEntityID()
{
    return m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KString IO_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Originating Entity ID:\n"
       << IndentString( m_OriginatingEntityID.GetAsString(), 1 );

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IO_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < IO_HEADER_SIZE  )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

    stream >> KDIS_STREAM m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream IO_Header::Encode() const
{
    KDataStream stream;

    IO_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IO_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IO_Header::operator == ( const IO_Header & Value ) const
{
    if( Header::operator        !=( Value ) )                    return false;
    if( m_OriginatingEntityID   != Value.m_OriginatingEntityID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IO_Header::operator != ( const IO_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

