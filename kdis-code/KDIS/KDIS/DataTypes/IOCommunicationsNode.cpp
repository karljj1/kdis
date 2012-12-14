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

#include "./IOCommunicationsNode.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

IOCommunicationsNode::IOCommunicationsNode( void ) :
    m_ui8CommNodeTyp( 0 ),
    m_ui8Padding( 0 )
{
    m_ui32Type = IOCommunicationsNodeRecord;
    m_ui16Length = IO_COMMUNICATIONS_NODE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IOCommunicationsNode::IOCommunicationsNode( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

IOCommunicationsNode::IOCommunicationsNode( IOCommunicationsNodeType T, const CommunicationsNodeID & ID ) :
    m_ui8CommNodeTyp( T ),
    m_ui8Padding( 0 ),
    m_CommID( ID )
{
    m_ui32Type = IOCommunicationsNodeRecord;
    m_ui16Length = IO_COMMUNICATIONS_NODE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IOCommunicationsNode::~IOCommunicationsNode( void )
{
}

//////////////////////////////////////////////////////////////////////////

void IOCommunicationsNode::SetIOCommunicationsNodeType( IOCommunicationsNodeType T )
{
    m_ui8CommNodeTyp = T;
}

//////////////////////////////////////////////////////////////////////////

IOCommunicationsNodeType IOCommunicationsNode::GetIOCommunicationsNodeType() const
{
    return ( IOCommunicationsNodeType )m_ui8CommNodeTyp;
}

//////////////////////////////////////////////////////////////////////////

void IOCommunicationsNode::SetCommunicationsNodeID( const CommunicationsNodeID & ID )
{
    m_CommID = ID;
}

//////////////////////////////////////////////////////////////////////////

const CommunicationsNodeID & IOCommunicationsNode::GetCommunicationsNodeID() const
{
    return m_CommID;
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID & IOCommunicationsNode::GetCommunicationsNodeID()
{
    return m_CommID;
}

//////////////////////////////////////////////////////////////////////////

KString IOCommunicationsNode::GetAsString() const
{
    KStringStream ss;

    ss << StandardVariable::GetAsString()
       << "Node Type: " << GetEnumAsStringIOCommunicationsNodeType( m_ui8CommNodeTyp ) << "\n"
       << m_CommID.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IOCommunicationsNode::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < STANDARD_VARIABLE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    StandardVariable::Decode( stream );

    stream >> m_ui8CommNodeTyp
           >> m_ui8Padding
           >> KDIS_STREAM m_CommID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream IOCommunicationsNode::Encode() const
{
    KDataStream stream;

    IOCommunicationsNode::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IOCommunicationsNode::Encode( KDataStream & stream ) const
{
    StandardVariable::Encode( stream );

    stream << m_ui8CommNodeTyp
           << m_ui8Padding
           << KDIS_STREAM m_CommID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IOCommunicationsNode::operator == ( const IOCommunicationsNode & Value ) const
{
    if( StandardVariable::operator  !=( Value ) )               return false;
    if( m_ui8CommNodeTyp            != Value.m_ui8CommNodeTyp ) return false;
    if( m_CommID                    != Value.m_CommID )         return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IOCommunicationsNode::operator != ( const IOCommunicationsNode & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
