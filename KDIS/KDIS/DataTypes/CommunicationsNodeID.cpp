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

#include "./CommunicationsNodeID.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID() :
    m_ui16ElementID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID( KUINT16 Site, KUINT16 App, KUINT16 Obj, KUINT16 Element ) :
    EntityIdentifier( Site, App, Obj ),
    m_ui16ElementID( Element )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID( const SimulationIdentifier & SimID, KUINT16 Obj, KUINT16 Element ) :
    EntityIdentifier( SimID, Obj ),
    m_ui16ElementID( Element )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::CommunicationsNodeID( const EntityIdentifier & EntID, KUINT16 Element ) :
    EntityIdentifier( EntID ),
    m_ui16ElementID( Element )
{
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID::~CommunicationsNodeID()
{
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsNodeID::SetElementID( KUINT16 ID )
{
    m_ui16ElementID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 CommunicationsNodeID::GetElementID() const
{
    return m_ui16ElementID;
}

//////////////////////////////////////////////////////////////////////////

KString CommunicationsNodeID::GetAsString() const
{
    KStringStream ss;

    ss << EntityIdentifier::GetAsString()
       << "Element:     " << m_ui16ElementID << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsNodeID::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < COMMUNICATIONS_NODE_ID_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    EntityIdentifier::Decode( stream );
    stream >> m_ui16ElementID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream CommunicationsNodeID::Encode() const
{
    KDataStream stream;

    CommunicationsNodeID::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void CommunicationsNodeID::Encode( KDataStream & stream ) const
{
    EntityIdentifier::Encode( stream );
    stream << m_ui16ElementID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CommunicationsNodeID::operator == ( const CommunicationsNodeID & Value ) const
{
    if( EntityIdentifier::operator !=( Value ) )   return false;
    if( m_ui16ElementID != Value.m_ui16ElementID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CommunicationsNodeID::operator != ( const CommunicationsNodeID & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
