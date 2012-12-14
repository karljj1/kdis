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

#include "./LE_Header.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

LE_Header::LE_Header( void )
{
    m_ui8ProtocolFamily = LiveEntity;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

LE_Header::LE_Header( KDataStream & stream ) throw( KException )
{
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
}

//////////////////////////////////////////////////////////////////////////

LE_Header::~LE_Header( void )
{
}

//////////////////////////////////////////////////////////////////////////

void LE_Header::SetSubprotocol( KUINT8 S )
{
    m_ui8Padding1 = S; // Using the first pading octet from the header.
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LE_Header::GetSubprotocol() const
{
    return m_ui8Padding1; // Using the first pading octet from the header.
}

//////////////////////////////////////////////////////////////////////////

void LE_Header::SetLiveEntityID( const LE_EntityIdentifier & ID )
{
    m_EntID = ID;
}

//////////////////////////////////////////////////////////////////////////

const LE_EntityIdentifier & LE_Header::GetLiveEntityID() const
{
    return m_EntID;
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier & LE_Header::GetLiveEntityID()
{
    return m_EntID;
}

//////////////////////////////////////////////////////////////////////////

KString LE_Header::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "Subprotocol:		   " << m_ui8Padding1
       << "Live Entity ID:     " << m_EntID.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LE_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LE_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

    stream >> KDIS_STREAM m_EntID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LE_Header::Encode() const
{
    KDataStream stream;

    LE_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LE_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_EntID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Header::operator == ( const LE_Header & Value ) const
{
    if( Header::operator != ( Value ) )     return false;
    if( m_EntID          != Value.m_EntID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Header::operator != ( const LE_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


