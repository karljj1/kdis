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

#include "./EmitterSystem.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EmitterSystem::EmitterSystem() :
    m_ui16EmitterName( 0 ),
    m_ui8Function( 0 ),
    m_ui8EmitterIDNumber( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

EmitterSystem::EmitterSystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EmitterSystem::EmitterSystem( EmitterName EN, EmitterFunction F, KUINT8 ID ) :
    m_ui16EmitterName( EN ),
    m_ui8Function( F ),
    m_ui8EmitterIDNumber( ID )
{
}

//////////////////////////////////////////////////////////////////////////

EmitterSystem::~EmitterSystem()
{
}

//////////////////////////////////////////////////////////////////////////

void EmitterSystem::SetEmitterName( EmitterName EN )
{
    m_ui16EmitterName = EN;
}

//////////////////////////////////////////////////////////////////////////

EmitterName EmitterSystem::GetEmitterName() const
{
    return ( EmitterName )m_ui16EmitterName;
}

//////////////////////////////////////////////////////////////////////////

void EmitterSystem::SetFunction( EmitterFunction F )
{
    m_ui8Function = F;
}

//////////////////////////////////////////////////////////////////////////

EmitterFunction EmitterSystem::GetFunction() const
{
    return ( EmitterFunction )m_ui8Function;
}

//////////////////////////////////////////////////////////////////////////

void EmitterSystem::SetEmitterID( KUINT8 ID )
{
    m_ui8EmitterIDNumber = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 EmitterSystem::GetEmitterID() const
{
    return m_ui8EmitterIDNumber;
}

//////////////////////////////////////////////////////////////////////////

KString EmitterSystem::GetAsString() const
{
    KStringStream ss;

    ss << "Emitter System:"
       << "\n\tName:     " << GetEnumAsStringEmitterName( m_ui16EmitterName )
       << "\n\tFunction: " << GetEnumAsStringEmitterFunction( m_ui8Function )
       << "\n\tID:       " << ( KUINT16 )m_ui8EmitterIDNumber
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EmitterSystem::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < EMITTER_SYSTEM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16EmitterName
           >> m_ui8Function
           >> m_ui8EmitterIDNumber;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EmitterSystem::Encode() const
{
    KDataStream stream;

    EmitterSystem::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EmitterSystem::Encode( KDataStream & stream ) const
{
    stream << m_ui16EmitterName
           << m_ui8Function
           << m_ui8EmitterIDNumber;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EmitterSystem::operator == ( const EmitterSystem & Value ) const
{
    if( m_ui16EmitterName    != Value.m_ui16EmitterName )    return false;
    if( m_ui8Function        != Value.m_ui8Function )        return false;
    if( m_ui8EmitterIDNumber != Value.m_ui8EmitterIDNumber ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EmitterSystem::operator != ( const EmitterSystem & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

