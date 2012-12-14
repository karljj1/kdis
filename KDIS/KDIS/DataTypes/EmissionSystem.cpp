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

EmissionSystem::EmissionSystem( void ) :
    m_ui8SystemDataLength( EMISSION_SYSTEM_SIZE ),
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
    m_ui8SystemDataLength( EMISSION_SYSTEM_SIZE ),
    m_ui16Padding( 0 ),
    m_ui8NumberOfBeams( 0 ),
    m_EmitterSystemRecord( ESR ),
    m_Location( Location )
{
}

//////////////////////////////////////////////////////////////////////////

EmissionSystem::~EmissionSystem( void )
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
    m_ui8SystemDataLength = EMISSION_SYSTEM_SIZE;

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
    m_ui8SystemDataLength = EMISSION_SYSTEM_SIZE;
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
