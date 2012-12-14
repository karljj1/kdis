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

#include "./RelationshipRecord.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

RelationshipRecord::RelationshipRecord( void ) :
    m_ui16Nature( 0 ),
    m_ui16Pos( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

RelationshipRecord::RelationshipRecord( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

RelationshipRecord::RelationshipRecord( RelationshipNature N, RelationshipPosition P ) :
    m_ui16Nature( N ),
    m_ui16Pos( P )
{
}

//////////////////////////////////////////////////////////////////////////

RelationshipRecord::~RelationshipRecord( void )
{
}

//////////////////////////////////////////////////////////////////////////

void RelationshipRecord::SetNature( RelationshipNature N )
{
    m_ui16Nature = N;
}

//////////////////////////////////////////////////////////////////////////

RelationshipNature RelationshipRecord::GetNature() const
{
    return ( RelationshipNature )m_ui16Nature;
}

//////////////////////////////////////////////////////////////////////////

void RelationshipRecord::SetPosition( RelationshipPosition P )
{
    m_ui16Pos = P;
}

//////////////////////////////////////////////////////////////////////////

RelationshipPosition RelationshipRecord::GetPosition() const
{
    return ( RelationshipPosition )m_ui16Pos;
}

//////////////////////////////////////////////////////////////////////////

KString RelationshipRecord::GetAsString() const
{
    KStringStream ss;

    ss << "Relationship Record:"
       << "\n\tNature:   " << GetEnumAsStringRelationshipNature( m_ui16Nature )
       << "\n\tPosition: " << GetEnumAsStringRelationshipPosition( m_ui16Pos )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void RelationshipRecord::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RELATIONSHIP_RECORD_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16Nature
           >> m_ui16Pos;
}

//////////////////////////////////////////////////////////////////////////

KDataStream RelationshipRecord::Encode() const
{
    KDataStream stream;

    RelationshipRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void RelationshipRecord::Encode( KDataStream & stream ) const
{
    stream << m_ui16Nature
           << m_ui16Pos;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RelationshipRecord::operator == ( const RelationshipRecord & Value ) const
{
    if( m_ui16Nature  != Value.m_ui16Nature ) return false;
    if( m_ui16Pos     != Value.m_ui16Pos )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RelationshipRecord::operator != ( const RelationshipRecord & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

