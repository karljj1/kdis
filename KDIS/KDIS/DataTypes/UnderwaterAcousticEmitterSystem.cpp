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

#include "./UnderwaterAcousticEmitterSystem.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticEmitterSystem::UnderwaterAcousticEmitterSystem( void ) :
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

UnderwaterAcousticEmitterSystem::~UnderwaterAcousticEmitterSystem( void )
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

    for( ; citr != m_vUAEB.end(); ++citr )
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
