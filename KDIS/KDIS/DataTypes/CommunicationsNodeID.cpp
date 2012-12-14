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

#include "./CommunicationsNodeID.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID( void ) :
    m_ui16ElementID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID( KUINT16 Site, KUINT16 App, KUINT16 Obj, KUINT16 Element ) :
    EntityIdentifier( Site, App, Obj ),
    m_ui16ElementID( Element )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID( const SimulationIdentifier & SimID, KUINT16 Obj, KUINT16 Element ) :
    EntityIdentifier( SimID, Obj ),
    m_ui16ElementID( Element )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID( const EntityIdentifier & EntID, KUINT16 Element ) :
    EntityIdentifier( EntID ),
    m_ui16ElementID( Element )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::~CommunicationsNodeID( void )
{
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsNodeID::SetElementID( KUINT16 ID )
{
    m_ui16ElementID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 CommunicationsNodeID::GetElementID() const
{
    return m_ui16ElementID;
}

//////////////////////////////////////////////////////////////////////////

KString CommunicationsNodeID::GetAsString() const
{
    KStringStream ss;

    ss << EntityIdentifier::GetAsString()
       << "Element:     " << m_ui16ElementID << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsNodeID::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < COMMUNICATIONS_NODE_ID_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    EntityIdentifier::Decode( stream );
    stream >> m_ui16ElementID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream CommunicationsNodeID::Encode() const
{
    KDataStream stream;

    CommunicationsNodeID::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsNodeID::Encode( KDataStream & stream ) const
{
    EntityIdentifier::Encode( stream );
    stream << m_ui16ElementID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CommunicationsNodeID::operator == ( const CommunicationsNodeID & Value ) const
{
    if( EntityIdentifier::operator !=( Value ) )   return false;
    if( m_ui16ElementID != Value.m_ui16ElementID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CommunicationsNodeID::operator != ( const CommunicationsNodeID & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
