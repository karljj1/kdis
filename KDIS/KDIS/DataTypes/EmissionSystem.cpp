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

#include "./EmissionSystem.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EmissionSystem::EmissionSystem() :
    m_ui8SystemDataLength( EMISSION_SYSTEM_SIZE / 4 ),
    m_ui16Padding( 0 ),
    m_ui8NumberOfBeams( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

EmissionSystem::EmissionSystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EmissionSystem::EmissionSystem( const EmitterSystem & ESR, const Vector & Location ) :
    m_ui8SystemDataLength( EMISSION_SYSTEM_SIZE / 4 ),
    m_ui16Padding( 0 ),
    m_ui8NumberOfBeams( 0 ),
    m_EmitterSystemRecord( ESR ),
    m_Location( Location )
{
}

//////////////////////////////////////////////////////////////////////////

EmissionSystem::~EmissionSystem()
{
    m_vEmitterBeams.clear();
}

//////////////////////////////////////////////////////////////////////////

KUINT8 EmissionSystem::GetSystemDataLength() const
{
    return m_ui8SystemDataLength;
}

//////////////////////////////////////////////////////////////////////////

void EmissionSystem::SetEmitterSystemRecord( const EmitterSystem & ESR )
{
    m_EmitterSystemRecord = ESR;
}

//////////////////////////////////////////////////////////////////////////

EmitterSystem EmissionSystem::GetEmitterSystemRecord() const
{
    return m_EmitterSystemRecord;
}

//////////////////////////////////////////////////////////////////////////

void EmissionSystem::SetLocation( const Vector & L )
{
    m_Location = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & EmissionSystem::GetLocation() const
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

Vector & EmissionSystem::GetLocation()
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

void EmissionSystem::AddEmitterBeam( const EmitterBeam & EB )
{
    m_vEmitterBeams.push_back( EB );
    m_ui8NumberOfBeams = m_vEmitterBeams.size();
    m_ui8SystemDataLength += EB.GetBeamDataLength();
}

//////////////////////////////////////////////////////////////////////////

void EmissionSystem::SetEmitterBeams( const vector<EmitterBeam> & Beams )
{
    m_vEmitterBeams = Beams;
    m_ui8NumberOfBeams = m_vEmitterBeams.size();

    // Re-Calculate the System Data Length
    m_ui8SystemDataLength = EMISSION_SYSTEM_SIZE / 4;

    vector<EmitterBeam>::const_iterator citr = m_vEmitterBeams.begin();
    vector<EmitterBeam>::const_iterator citrEnd = m_vEmitterBeams.end();

    for( ; citr != citrEnd; ++citr )
    {
        m_ui8SystemDataLength += citr->GetBeamDataLength();
    }
}

//////////////////////////////////////////////////////////////////////////

const vector<EmitterBeam> & EmissionSystem::GetEmitterBeams() const
{
    return m_vEmitterBeams;
}

//////////////////////////////////////////////////////////////////////////

void EmissionSystem::ClearEmitterBeams()
{
    m_vEmitterBeams.clear();
    m_ui8NumberOfBeams = 0;
    m_ui8SystemDataLength = EMISSION_SYSTEM_SIZE / 4;
}

//////////////////////////////////////////////////////////////////////////

KString EmissionSystem::GetAsString() const
{
    KStringStream ss;

    ss << "Emission System:\n\t"
       << "System Data Length (32 bits):    " << ( KUINT16 )m_ui8SystemDataLength            << "\n\t"
       << "Number Of Emitter Beams:         " << ( KUINT16 )m_ui8NumberOfBeams               << "\n"
       << IndentString( m_EmitterSystemRecord.GetAsString(), 1 )                             << "\t"
       << "Location:   " << m_Location.GetAsString();

    vector<EmitterBeam>::const_iterator citr = m_vEmitterBeams.begin();
    vector<EmitterBeam>::const_iterator citrEnd = m_vEmitterBeams.end();

    for( ; citr != citrEnd; ++citr )
    {
        ss << IndentString( citr->GetAsString(), 1 );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EmissionSystem::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < EMISSION_SYSTEM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8SystemDataLength
           >> m_ui8NumberOfBeams
           >> m_ui16Padding
           >> KDIS_STREAM m_EmitterSystemRecord
           >> KDIS_STREAM m_Location;

    for( KUINT8 i = 0; i < m_ui8NumberOfBeams; ++i )
    {
        m_vEmitterBeams.push_back( EmitterBeam( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream EmissionSystem::Encode() const
{
    KDataStream stream;

    EmissionSystem::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EmissionSystem::Encode( KDataStream & stream ) const
{
    stream << m_ui8SystemDataLength
           << m_ui8NumberOfBeams
           << m_ui16Padding
           << KDIS_STREAM m_EmitterSystemRecord
           << KDIS_STREAM m_Location;

    vector<EmitterBeam>::const_iterator citr = m_vEmitterBeams.begin();
    vector<EmitterBeam>::const_iterator citrEnd = m_vEmitterBeams.end();

    for( ; citr != citrEnd; ++citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL EmissionSystem::operator == ( const EmissionSystem & Value ) const
{
    if( m_ui8SystemDataLength   != Value.m_ui8SystemDataLength )    return false;
    if( m_ui8NumberOfBeams      != Value.m_ui8NumberOfBeams )       return false;
    if( m_EmitterSystemRecord   != Value.m_EmitterSystemRecord )    return false;
    if( m_Location              != Value.m_Location )               return false;
    if( m_vEmitterBeams         != Value.m_vEmitterBeams )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EmissionSystem::operator != ( const EmissionSystem & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
