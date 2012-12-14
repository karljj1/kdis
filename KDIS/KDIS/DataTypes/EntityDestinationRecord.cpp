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

#include "./EntityDestinationRecord.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

EntityDestinationRecord::EntityDestinationRecord( void ) :
    m_ui16DstCommsDvcID( 0 ),
    m_ui8DstLineID( 0 ),
    m_ui8DstPriority( 0 ),
    m_ui8LnStCmd( 0 ),
    m_uiPadding1( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

EntityDestinationRecord::EntityDestinationRecord( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EntityDestinationRecord::EntityDestinationRecord( const EntityIdentifier & ID, KUINT16 CommDeviceID, KUINT8 LineID,
        KUINT8 Priority, LineStateCommand LSC ) :
    m_Entity( ID ),
    m_ui16DstCommsDvcID( CommDeviceID ),
    m_ui8DstLineID( LineID ),
    m_ui8DstPriority( Priority ),
    m_ui8LnStCmd( LSC ),
    m_uiPadding1( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

EntityDestinationRecord::~EntityDestinationRecord( void )
{
}

//////////////////////////////////////////////////////////////////////////

void EntityDestinationRecord::SetDestinationEntityID( const EntityIdentifier & ID )
{
    m_Entity = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & EntityDestinationRecord::GetDestinationEntityID() const
{
    return m_Entity;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & EntityDestinationRecord::GetDestinationEntityID()
{
    return m_Entity;
}

//////////////////////////////////////////////////////////////////////////

void EntityDestinationRecord::SetDestinationCommDeviceID( KUINT16 ID )
{
    m_ui16DstCommsDvcID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 EntityDestinationRecord::GetDestinationCommDeviceID() const
{
    return m_ui16DstCommsDvcID;
}

//////////////////////////////////////////////////////////////////////////

void EntityDestinationRecord::SetDestinationLineID( KUINT8 ID )
{
    m_ui8DstLineID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 EntityDestinationRecord::GetDestinationLineID() const
{
    return m_ui8DstLineID;
}

//////////////////////////////////////////////////////////////////////////

void EntityDestinationRecord::SetDestinationPriority( KUINT8 TP )
{
    m_ui8DstPriority = TP;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 EntityDestinationRecord::GetDestinationPriority() const
{
    return m_ui8DstPriority;
}

//////////////////////////////////////////////////////////////////////////

void EntityDestinationRecord::SetLineStateCommand( LineStateCommand LSC )
{
    m_ui8LnStCmd = LSC;
}

//////////////////////////////////////////////////////////////////////////

LineStateCommand EntityDestinationRecord::GetLineStateCommand() const
{
    return ( LineStateCommand )m_ui8LnStCmd;
}

//////////////////////////////////////////////////////////////////////////

KString EntityDestinationRecord::GetAsString() const
{
    KStringStream ss;

    ss << "Entity Destination Record\n"
       << "Entity ID:\n"          << IndentString( m_Entity.GetAsString(), 1 )
       << "Device ID:			" << m_ui16DstCommsDvcID
       << "\nLine ID:		  	  " << ( KUINT16 )m_ui8DstLineID
       << "\nPriority:			  " << ( KUINT16 )m_ui8DstPriority
       << "\nLine State Command:  " << ( KUINT16 )m_ui8LnStCmd
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EntityDestinationRecord::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ENTITY_DESTINATION_RECORD_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> KDIS_STREAM m_Entity
           >> m_ui16DstCommsDvcID
           >> m_ui8DstLineID
           >> m_ui8DstPriority
           >> m_ui8LnStCmd
           >> m_uiPadding1;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EntityDestinationRecord::Encode() const
{
    KDataStream stream;

    EntityDestinationRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EntityDestinationRecord::Encode( KDataStream & stream ) const
{
    stream << KDIS_STREAM m_Entity
           << m_ui16DstCommsDvcID
           << m_ui8DstLineID
           << m_ui8DstPriority
           << m_ui8LnStCmd
           << m_uiPadding1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityDestinationRecord::operator == ( const EntityDestinationRecord & Value ) const
{
    if( m_Entity            != Value.m_Entity )             return false;
    if( m_ui16DstCommsDvcID != Value.m_ui16DstCommsDvcID )  return false;
    if( m_ui8DstLineID      != Value.m_ui8DstLineID )       return false;
    if( m_ui8DstPriority    != Value.m_ui8DstPriority )     return false;
    if( m_ui8LnStCmd        != Value.m_ui8LnStCmd )         return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityDestinationRecord::operator != ( const EntityDestinationRecord & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


