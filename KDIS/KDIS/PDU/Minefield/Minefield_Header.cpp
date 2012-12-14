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

#include "./Minefield_Header.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Minefield_Header::Minefield_Header( void )
{
    m_ui8ProtocolFamily = Minefield;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Minefield_Header::Minefield_Header( KDataStream & stream ) throw( KException )
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

Minefield_Header::~Minefield_Header( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Header::SetMinefieldID( const EntityIdentifier & ID )
{
    m_MinefieldID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Minefield_Header::GetMinefieldID() const
{
    return m_MinefieldID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Minefield_Header::GetMinefieldID()
{
    return m_MinefieldID;
}

//////////////////////////////////////////////////////////////////////////

KString Minefield_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Minefield ID:\n"
       << IndentString( m_MinefieldID.GetAsString(), 1 )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MINEFIELD_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

    stream >> KDIS_STREAM m_MinefieldID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Minefield_Header::Encode() const
{
    KDataStream stream;

    Minefield_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_MinefieldID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Minefield_Header::operator == ( const Minefield_Header & Value ) const
{
    if( Header::operator  != ( Value ) )           return false;
    if( m_MinefieldID     != Value.m_MinefieldID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Minefield_Header::operator != ( const Minefield_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


