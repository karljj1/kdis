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

#include "./GroupDestinationRecord.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

GroupDestinationRecord::GroupDestinationRecord( void ) :
    m_ui32GrpBtField( 0 ),
    m_ui8DstPriority( 0 ),
    m_ui8LnStCmd( 0 ),
    m_ui16Padding1( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GroupDestinationRecord::GroupDestinationRecord( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GroupDestinationRecord::GroupDestinationRecord( KUINT32 GroupBitField, KUINT8 Priority, LineStateCommand LSC ) :
    m_ui32GrpBtField( GroupBitField ),
    m_ui8DstPriority( Priority ),
    m_ui8LnStCmd( LSC ),
    m_ui16Padding1( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

void GroupDestinationRecord::SetGroupBitField( KUINT32 AllGroups )
{
    m_ui32GrpBtField = AllGroups;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 GroupDestinationRecord::GetGroupBitField() const
{
    return m_ui32GrpBtField;
}

//////////////////////////////////////////////////////////////////////////

void GroupDestinationRecord::SetGroupBitField( KUINT8 Group, KBOOL InGroup /*= true*/ ) throw( KException )
{
    if( Group > 31 )throw KException( __FUNCTION__, OUT_OF_BOUNDS );

    bitset<32> bits( ( KINT32 )m_ui32GrpBtField ); // We need to cast to a signed int, this is a visual studio 2010 fix
    InGroup ? bits.set( Group ) : bits.reset( Group );
}

//////////////////////////////////////////////////////////////////////////

KBOOL GroupDestinationRecord::IsGroupBitSet( KUINT8 Group ) const throw( KException )
{
    if( Group > 31 )throw KException( __FUNCTION__, OUT_OF_BOUNDS );

    const bitset<32> bits( ( KINT32 )m_ui32GrpBtField ); // We need to cast to a signed int, this is a visual studio 2010 fix
    return bits.test( Group );
}

//////////////////////////////////////////////////////////////////////////

GroupDestinationRecord::~GroupDestinationRecord( void )
{
}

//////////////////////////////////////////////////////////////////////////

void GroupDestinationRecord::SetDestinationPriority( KUINT8 TP )
{
    m_ui8DstPriority = TP;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GroupDestinationRecord::GetDestinationPriority() const
{
    return m_ui8DstPriority;
}

//////////////////////////////////////////////////////////////////////////

void GroupDestinationRecord::SetLineStateCommand( LineStateCommand LSC )
{
    m_ui8LnStCmd = LSC;
}

//////////////////////////////////////////////////////////////////////////

LineStateCommand GroupDestinationRecord::GetLineStateCommand() const
{
    return ( LineStateCommand )m_ui8LnStCmd;
}

//////////////////////////////////////////////////////////////////////////

KString GroupDestinationRecord::GetAsString() const
{
    KStringStream ss;

    ss << "Group Destination Record"
       << "\nGroup Bit Field:		" << m_ui32GrpBtField
       << "\nPriority:				" << ( KUINT16 )m_ui8DstPriority
       << "\nLine State Command:	" << ( KUINT16 )m_ui8LnStCmd
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GroupDestinationRecord::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GROUP_DESTINATION_RECORD_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32GrpBtField
           >> m_ui8DstPriority
           >> m_ui8LnStCmd
           >> m_ui16Padding1;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GroupDestinationRecord::Encode() const
{
    KDataStream stream;

    GroupDestinationRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GroupDestinationRecord::Encode( KDataStream & stream ) const
{
    stream << m_ui32GrpBtField
           << m_ui8DstPriority
           << m_ui8LnStCmd
           << m_ui16Padding1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GroupDestinationRecord::operator == ( const GroupDestinationRecord & Value ) const
{
    if( m_ui32GrpBtField != Value.m_ui32GrpBtField ) return false;
    if( m_ui8DstPriority != Value.m_ui8DstPriority ) return false;
    if( m_ui8LnStCmd     != Value.m_ui8LnStCmd )     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GroupDestinationRecord::operator != ( const GroupDestinationRecord & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
