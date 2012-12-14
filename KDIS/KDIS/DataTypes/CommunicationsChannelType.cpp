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

#include "./CommunicationsChannelType.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

CommunicationsChannelType::CommunicationsChannelType( void ) :
    m_ui8Type( 0 ),
    m_ui8Class( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsChannelType::CommunicationsChannelType( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

CommunicationsChannelType::CommunicationsChannelType( ChannelType CT, ChannelClass CC ) :
    m_ui8Type( CT ),
    m_ui8Class( CC )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsChannelType::~CommunicationsChannelType( void )
{
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsChannelType::SetType( ChannelType CT )
{
    m_ui8Type = CT;
}

//////////////////////////////////////////////////////////////////////////

ChannelType CommunicationsChannelType::GetType() const
{
    return ( ChannelType )m_ui8Type;
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsChannelType::SetClass( ChannelClass CC )
{
    m_ui8Class = CC;
}

//////////////////////////////////////////////////////////////////////////

ChannelClass CommunicationsChannelType::GetClass() const
{
    return ( ChannelClass )m_ui8Class;
}

//////////////////////////////////////////////////////////////////////////

KString CommunicationsChannelType::GetAsString() const
{
    KStringStream ss;

    ss << "Communications Channel Type:"
       << "\n\tType	 : " << ( KUINT16 )m_ui8Type
       << "\n\tClass : " << ( KUINT16 )m_ui8Class
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsChannelType::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < COMM_CHANNEL_TYPE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8CommChannelType;
}

//////////////////////////////////////////////////////////////////////////

KDataStream CommunicationsChannelType::Encode() const
{
    KDataStream stream;

    CommunicationsChannelType::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsChannelType::Encode( KDataStream & stream ) const
{
    stream << m_ui8CommChannelType;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CommunicationsChannelType::operator == ( const CommunicationsChannelType & Value ) const
{
    if( m_ui8CommChannelType != Value.m_ui8CommChannelType ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CommunicationsChannelType::operator != ( const CommunicationsChannelType & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


