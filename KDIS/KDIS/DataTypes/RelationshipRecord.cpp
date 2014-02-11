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

#include "./RelationshipRecord.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

RelationshipRecord::RelationshipRecord() :
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

RelationshipRecord::~RelationshipRecord()
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

