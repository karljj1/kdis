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

#include "./UnderwaterAcousticEmitterSystem.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticEmitterSystem::UnderwaterAcousticEmitterSystem() :
    m_ui8EmitterSystemDataLength( UNDERWATER_ACOUSTIC_EMITTER_SYSTEM_SIZE / 4 ),
    m_ui8NumBeams( 0 ),
    m_ui16Padding1( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticEmitterSystem::UnderwaterAcousticEmitterSystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticEmitterSystem::~UnderwaterAcousticEmitterSystem()
{
    m_vUAEB.clear();
}

//////////////////////////////////////////////////////////////////////////

KUINT8 UnderwaterAcousticEmitterSystem::GetEmitterSystemDataLength() const
{
    return m_ui8EmitterSystemDataLength;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 UnderwaterAcousticEmitterSystem::GetNumberOfBeams() const
{
    return m_ui8NumBeams;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterSystem::SetAcousticEmitterSystem( const AcousticEmitterSystem & AES )
{
    m_AES = AES;
}

//////////////////////////////////////////////////////////////////////////

const AcousticEmitterSystem & UnderwaterAcousticEmitterSystem::GetAcousticEmitterSystem() const
{
    return m_AES;
}

//////////////////////////////////////////////////////////////////////////

AcousticEmitterSystem & UnderwaterAcousticEmitterSystem::GetAcousticEmitterSystem()
{
    return m_AES;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterSystem::SetLocation( const Vector & L )
{
    m_Location = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & UnderwaterAcousticEmitterSystem::GetLocation() const
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

Vector & UnderwaterAcousticEmitterSystem::GetLocation()
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterSystem::AddUnderwaterAcousticEmitterBeam( const UnderwaterAcousticEmitterBeam & UAEB )
{
    ++m_ui8NumBeams;
    m_vUAEB.push_back( UAEB );
    m_ui8EmitterSystemDataLength += UnderwaterAcousticEmitterBeam::UNDERWATER_ACOUSTIC_EMITTER_BEAM_SIZE / 4;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterSystem::SetUnderwaterAcousticEmitterBeams( const vector<UnderwaterAcousticEmitterBeam> & UAEB )
{
    m_ui8EmitterSystemDataLength = UNDERWATER_ACOUSTIC_EMITTER_SYSTEM_SIZE / 4;
    m_vUAEB = UAEB;
    m_ui8NumBeams = m_vUAEB.size();
    m_ui8EmitterSystemDataLength += ( m_vUAEB.size() * UnderwaterAcousticEmitterBeam::UNDERWATER_ACOUSTIC_EMITTER_BEAM_SIZE ) / 4;
}

//////////////////////////////////////////////////////////////////////////

const vector<UnderwaterAcousticEmitterBeam> & UnderwaterAcousticEmitterSystem::GetUnderwaterAcousticEmitterBeam() const
{
    return m_vUAEB;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterSystem::ClearUnderwaterAcousticEmitterBeams()
{
    m_ui8EmitterSystemDataLength = UNDERWATER_ACOUSTIC_EMITTER_SYSTEM_SIZE / 4;
    m_vUAEB.clear();
    m_ui8NumBeams = 0;
}

//////////////////////////////////////////////////////////////////////////

KString UnderwaterAcousticEmitterSystem::GetAsString() const
{
    KStringStream ss;

    ss << "Underwater Acoustic Emitter System:"
       << "\n\tData Length:       " << ( KUINT16 )m_ui8EmitterSystemDataLength
       << "\n\tNumber Of Beams:   " << ( KUINT16 )m_ui8NumBeams
       << m_AES.GetAsString()
       << "\n\tLocation:          " << m_Location.GetAsString();

    vector<UnderwaterAcousticEmitterBeam>::const_iterator citr = m_vUAEB.begin();
    vector<UnderwaterAcousticEmitterBeam>::const_iterator citrEnd = m_vUAEB.end();

    for( ; citr != citrEnd; ++citr )
    {
        ss << citr->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterSystem::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < UNDERWATER_ACOUSTIC_EMITTER_SYSTEM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8EmitterSystemDataLength
           >> m_ui8NumBeams
           >> m_ui16Padding1
           >> KDIS_STREAM m_AES
           >> KDIS_STREAM m_Location;

    m_vUAEB.clear();

    for( KUINT8 i = 0; i < m_ui8NumBeams; ++i )
    {
        UnderwaterAcousticEmitterBeam UAEB;
        stream >> KDIS_STREAM UAEB;
        m_vUAEB.push_back( UAEB );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream UnderwaterAcousticEmitterSystem::Encode() const
{
    KDataStream stream;

    UnderwaterAcousticEmitterSystem::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterSystem::Encode( KDataStream & stream ) const
{
    stream << m_ui8EmitterSystemDataLength
           << m_ui8NumBeams
           << m_ui16Padding1
           << KDIS_STREAM m_AES
           << KDIS_STREAM m_Location;

    vector<UnderwaterAcousticEmitterBeam>::const_iterator citr = m_vUAEB.begin();
    vector<UnderwaterAcousticEmitterBeam>::const_iterator citrEnd = m_vUAEB.end();
    for( ; citr != citrEnd; ++citr )
    {
        stream << KDIS_STREAM *citr;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL UnderwaterAcousticEmitterSystem::operator == ( const UnderwaterAcousticEmitterSystem & Value ) const
{
    if( m_ui8EmitterSystemDataLength  != Value.m_ui8EmitterSystemDataLength )  return false;
    if( m_ui8NumBeams                 != Value.m_ui8NumBeams )                 return false;
    if( m_AES                         != Value.m_AES )                         return false;
    if( m_Location                    != Value.m_Location )                    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL UnderwaterAcousticEmitterSystem::operator != ( const UnderwaterAcousticEmitterSystem & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
