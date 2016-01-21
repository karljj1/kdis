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

EntityDestinationRecord::EntityDestinationRecord() :
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

EntityDestinationRecord::~EntityDestinationRecord()
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
       << "Device ID:           " << m_ui16DstCommsDvcID
       << "\nLine ID:             " << ( KUINT16 )m_ui8DstLineID
       << "\nPriority:            " << ( KUINT16 )m_ui8DstPriority
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


