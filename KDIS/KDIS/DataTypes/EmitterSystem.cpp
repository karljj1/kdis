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

#include "./EmitterSystem.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EmitterSystem::EmitterSystem( void ) :
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

EmitterSystem::~EmitterSystem( void )
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

