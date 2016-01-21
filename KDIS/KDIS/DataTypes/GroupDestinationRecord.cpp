/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include "./GroupDestinationRecord.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

GroupDestinationRecord::GroupDestinationRecord() :
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

GroupDestinationRecord::~GroupDestinationRecord()
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
       << "\nGroup Bit Field:       " << m_ui32GrpBtField
       << "\nPriority:              " << ( KUINT16 )m_ui8DstPriority
       << "\nLine State Command:    " << ( KUINT16 )m_ui8LnStCmd
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
