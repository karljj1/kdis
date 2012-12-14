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

#include "./Warfare_Header.h"

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

Warfare_Header::Warfare_Header( void )
{
    m_ui8ProtocolFamily = Warfare;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Warfare_Header::Warfare_Header( const EntityIdentifier & FiringEntID, const EntityIdentifier & TargetEntID, const EntityIdentifier & MunitionID, const EntityIdentifier & EventID ) :
    m_FiringEntityID( FiringEntID ),
    m_TargetEntityID( TargetEntID ),
    m_MunitionID( MunitionID ),
    m_EventID( EventID )
{
    m_ui8ProtocolFamily = Warfare;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Warfare_Header::~Warfare_Header( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Warfare_Header::SetFiringEntityID( const EntityIdentifier & ID )
{
    m_FiringEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Warfare_Header::GetFiringEntityID() const
{
    return m_FiringEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Warfare_Header::GetFiringEntityID()
{
    return m_FiringEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Warfare_Header::SetTargetEntityID( const EntityIdentifier & ID )
{
    m_TargetEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Warfare_Header::GetTargetEntityID() const
{
    return m_TargetEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Warfare_Header::GetTargetEntityID()
{
    return m_TargetEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Warfare_Header::SetMunitionID( const EntityIdentifier & ID )
{
    m_MunitionID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Warfare_Header::GetMunitionID() const
{
    return m_MunitionID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Warfare_Header::GetMunitionID()
{
    return m_MunitionID;
}

//////////////////////////////////////////////////////////////////////////

void Warfare_Header::SetEventID( const EntityIdentifier & ID )
{
    m_EventID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Warfare_Header::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Warfare_Header::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

KString Warfare_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Firing Entity ID:\n"
       << IndentString( m_FiringEntityID.GetAsString(), 1 )
       << "Target Entity ID:\n"
       << IndentString( m_TargetEntityID.GetAsString(), 1 )
       << "Munition ID:\n"
       << IndentString( m_MunitionID.GetAsString(), 1 )
       << "Event ID:\n"
       << IndentString( m_EventID.GetAsString(), 1 );

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Warfare_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < WARFARE_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );
    stream >> KDIS_STREAM m_FiringEntityID
           >> KDIS_STREAM m_TargetEntityID
           >> KDIS_STREAM m_MunitionID
           >> KDIS_STREAM m_EventID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Warfare_Header::Encode() const
{
    KDataStream stream;

    Warfare_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Warfare_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );
    stream << KDIS_STREAM m_FiringEntityID
           << KDIS_STREAM m_TargetEntityID
           << KDIS_STREAM m_MunitionID
           << KDIS_STREAM m_EventID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Warfare_Header::operator == ( const Warfare_Header & Value ) const
{
    if( Header::operator !=( Value ) )               return false;
    if( m_FiringEntityID != Value.m_FiringEntityID ) return false;
    if( m_TargetEntityID != Value.m_TargetEntityID ) return false;
    if( m_MunitionID     != Value.m_MunitionID )     return false;
    if( m_EventID        != Value.m_EventID )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Warfare_Header::operator != ( const Warfare_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

