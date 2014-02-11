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

Warfare_Header::Warfare_Header()
{
    m_ui8ProtocolFamily = Warfare;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Warfare_Header::Warfare_Header( const Header & H ) :
	Header( H )
{
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

Warfare_Header::~Warfare_Header()
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

void Warfare_Header::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < WARFARE_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	
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

