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

#include "./AcousticEmitterSystem.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

AcousticEmitterSystem::AcousticEmitterSystem( void ) :
    m_ui16EmitterName( 0 ),
    m_ui8Function( 0 ),
    m_ui8EmitterIDNumber( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

AcousticEmitterSystem::AcousticEmitterSystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

AcousticEmitterSystem::AcousticEmitterSystem( AcousticSystemName ASN, AcousticSystemFunction ASF, KUINT8 ID ) :
    m_ui16EmitterName( ASN ),
    m_ui8Function( ASF ),
    m_ui8EmitterIDNumber( ID )
{
}

//////////////////////////////////////////////////////////////////////////

AcousticEmitterSystem::~AcousticEmitterSystem( void )
{
}

//////////////////////////////////////////////////////////////////////////

void AcousticEmitterSystem::SetName( AcousticSystemName ASN )
{
    m_ui16EmitterName = ASN;
}

//////////////////////////////////////////////////////////////////////////

AcousticSystemName AcousticEmitterSystem::GetName() const
{
    return ( AcousticSystemName )m_ui16EmitterName;
}

//////////////////////////////////////////////////////////////////////////

void AcousticEmitterSystem::SetFunction( AcousticSystemFunction ASF )
{
    m_ui8Function = ASF;
}

//////////////////////////////////////////////////////////////////////////

AcousticSystemFunction AcousticEmitterSystem::GetFunction() const
{
    return ( AcousticSystemFunction )m_ui8Function;
}

//////////////////////////////////////////////////////////////////////////

void AcousticEmitterSystem::SetEmitterID( KUINT8 ID )
{
    m_ui8EmitterIDNumber = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 AcousticEmitterSystem::GetEmitterID() const
{
    return m_ui8EmitterIDNumber;
}

//////////////////////////////////////////////////////////////////////////

KString AcousticEmitterSystem::GetAsString() const
{
    KStringStream ss;

    ss << "Acoustic Emitter System:"
       << "\n\tName:     " << GetEnumAsStringAcousticSystemName( m_ui16EmitterName )
       << "\n\tFunction: " << GetEnumAsStringAcousticSystemFunction( m_ui8Function )
       << "\n\tID:       " << ( KUINT16 )m_ui8EmitterIDNumber
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void AcousticEmitterSystem::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ACOUSTIC_EMITTER_SYSTEM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16EmitterName
           >> m_ui8Function
           >> m_ui8EmitterIDNumber;
}

//////////////////////////////////////////////////////////////////////////

KDataStream AcousticEmitterSystem::Encode() const
{
    KDataStream stream;

    AcousticEmitterSystem::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void AcousticEmitterSystem::Encode( KDataStream & stream ) const
{
    stream << m_ui16EmitterName
           << m_ui8Function
           << m_ui8EmitterIDNumber;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AcousticEmitterSystem::operator == ( const AcousticEmitterSystem & Value ) const
{
    if( m_ui16EmitterName       != Value.m_ui16EmitterName )    return false;
    if( m_ui8Function           != Value.m_ui8Function )        return false;
    if( m_ui8EmitterIDNumber    != Value.m_ui8EmitterIDNumber ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AcousticEmitterSystem::operator != ( const AcousticEmitterSystem & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////
