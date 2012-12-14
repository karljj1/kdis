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

#include "./GroupAssignmentRecord.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

GroupAssignmentRecord::GroupAssignmentRecord( void ) :
    m_ui32GrpBtField( 0 ),
    m_ui16DstCommsDvcID( 0 ),
    m_ui8DstLineID( 0 ),
    m_ui16Padding1( 0 ),
    m_ui8Padding2( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GroupAssignmentRecord::GroupAssignmentRecord( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GroupAssignmentRecord::GroupAssignmentRecord( KUINT32 GroupBitField, const EntityIdentifier & ID,
        KUINT8 DeviceID, KUINT8 LineID ) :
    m_ui32GrpBtField( GroupBitField ),
    m_Entity( ID ),
    m_ui16DstCommsDvcID( DeviceID ),
    m_ui8DstLineID( LineID ),
    m_ui16Padding1( 0 ),
    m_ui8Padding2( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GroupAssignmentRecord::~GroupAssignmentRecord( void )
{
}

//////////////////////////////////////////////////////////////////////////

void GroupAssignmentRecord::SetDestinationEntityID( const EntityIdentifier & ID )
{
    m_Entity = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & GroupAssignmentRecord::GetDestinationEntityID() const
{
    return m_Entity;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & GroupAssignmentRecord::GetDestinationEntityID()
{
    return m_Entity;
}

//////////////////////////////////////////////////////////////////////////

void GroupAssignmentRecord::SetGroupBitField( KUINT32 AllGroups )
{
    m_ui32GrpBtField = AllGroups;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 GroupAssignmentRecord::GetGroupBitField() const
{
    return m_ui32GrpBtField;
}

//////////////////////////////////////////////////////////////////////////

void GroupAssignmentRecord::SetGroupBitField( KUINT8 Group, KBOOL InGroup /*= true*/ ) throw( KException )
{
    if( Group > 31 )throw KException( __FUNCTION__, OUT_OF_BOUNDS );

    bitset<32> bits( ( KINT32 )m_ui32GrpBtField ); // We need to cast to a signed int, this is a visual studio 2010 fix
    InGroup ? bits.set( Group ) : bits.reset( Group );
}

//////////////////////////////////////////////////////////////////////////

KBOOL GroupAssignmentRecord::IsGroupBitSet( KUINT8 Group ) const throw( KException )
{
    if( Group > 31 )throw KException( __FUNCTION__, OUT_OF_BOUNDS );

    const bitset<32> bits( ( KINT32 )m_ui32GrpBtField ); // We need to cast to a signed int, this is a visual studio 2010 fix
    return bits.test( Group );
}

//////////////////////////////////////////////////////////////////////////

void GroupAssignmentRecord::SetDestinationCommDeviceID( KUINT16 ID )
{
    m_ui16DstCommsDvcID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GroupAssignmentRecord::GetDestinationCommDeviceID() const
{
    return m_ui16DstCommsDvcID;
}

//////////////////////////////////////////////////////////////////////////

void GroupAssignmentRecord::SetDestinationLineID( KUINT8 ID )
{
    m_ui8DstLineID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GroupAssignmentRecord::GetDestinationLineID() const
{
    return m_ui8DstLineID;
}

//////////////////////////////////////////////////////////////////////////

KString GroupAssignmentRecord::GetAsString() const
{
    KStringStream ss;

    ss << "Group Assignment Record"
       << "\nGroup Bit Field:		  " << m_ui32GrpBtField
       << "Entity ID:\n"                << IndentString( m_Entity.GetAsString(), 1 )
       << "Communication Device ID:   " << m_ui16DstCommsDvcID
       << "\nLine ID:                 " << ( KUINT16 )m_ui8DstLineID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GroupAssignmentRecord::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GROUP_ASSIGNMENT_RECORD_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32GrpBtField
           >> KDIS_STREAM m_Entity
           >> m_ui16DstCommsDvcID
           >> m_ui8DstLineID
           >> m_ui16Padding1
           >> m_ui8Padding2;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GroupAssignmentRecord::Encode() const
{
    KDataStream stream;

    GroupAssignmentRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GroupAssignmentRecord::Encode( KDataStream & stream ) const
{
    stream << m_ui32GrpBtField
           << KDIS_STREAM m_Entity
           << m_ui16DstCommsDvcID
           << m_ui8DstLineID
           << m_ui16Padding1
           << m_ui8Padding2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GroupAssignmentRecord::operator == ( const GroupAssignmentRecord & Value ) const
{
    if( m_ui32GrpBtField    != Value.m_ui32GrpBtField )     return false;
    if( m_Entity            != Value.m_Entity )             return false;
    if( m_ui16DstCommsDvcID != Value.m_ui16DstCommsDvcID )  return false;
    if( m_ui8DstLineID      != Value.m_ui8DstLineID )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GroupAssignmentRecord::operator != ( const GroupAssignmentRecord & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
