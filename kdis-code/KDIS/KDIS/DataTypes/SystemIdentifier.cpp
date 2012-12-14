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

#include "./SystemIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SystemIdentifier::SystemIdentifier( void ) :
    m_ui16SystemType( 0 ),
    m_ui16SystemName( 0 ),
    m_ui8SystemMode( 0 ),
    m_ui8ChangeIndicator( 0 ),
    m_ui8AltMode4( 0 ),
    m_ui8AltModeC( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

SystemIdentifier::SystemIdentifier( SystemType T, SystemName N, SystemMode M, KBOOL ChangeIndicator,
                                    KBOOL AltMode4 /* = false */, KBOOL AltModeC /* = false */ ) :
    m_ui16SystemType( T ),
    m_ui16SystemName( N ),
    m_ui8SystemMode( M ),
    m_ui8ChangeIndicator( ChangeIndicator ),
    m_ui8AltMode4( AltMode4 ),
    m_ui8AltModeC( AltModeC )
{
}

//////////////////////////////////////////////////////////////////////////

SystemIdentifier::SystemIdentifier( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SystemIdentifier::~SystemIdentifier( void )
{
}

//////////////////////////////////////////////////////////////////////////

void SystemIdentifier::SetSystemType( SystemType T )
{
    m_ui16SystemType = T;
}

//////////////////////////////////////////////////////////////////////////

SystemType SystemIdentifier::GetSystemType() const
{
    return ( SystemType )m_ui16SystemType;
}

//////////////////////////////////////////////////////////////////////////

void SystemIdentifier::SetSystemName( SystemName N )
{
    m_ui16SystemName = N;
}

//////////////////////////////////////////////////////////////////////////

SystemName SystemIdentifier::GetSystemName() const
{
    return ( SystemName )m_ui16SystemName;
}

//////////////////////////////////////////////////////////////////////////

void SystemIdentifier::SetSystemMode( SystemMode M )
{
    m_ui8SystemMode = M;
}

//////////////////////////////////////////////////////////////////////////

SystemMode SystemIdentifier::GetSystemMode() const
{
    return ( SystemMode )m_ui8SystemMode;
}

//////////////////////////////////////////////////////////////////////////

void SystemIdentifier::SetChangeOptions( KBOOL ChangeIndicator, KBOOL AltMode4, KBOOL AltModeC )
{
    m_ui8ChangeIndicator = ChangeIndicator;
    m_ui8AltMode4 = AltMode4;
    m_ui8AltModeC = AltModeC;
}

//////////////////////////////////////////////////////////////////////////

void SystemIdentifier::SetChangeIndicator( KBOOL CI )
{
    m_ui8ChangeIndicator = CI;
}

//////////////////////////////////////////////////////////////////////////

void SystemIdentifier::SetAltMode4( KBOOL AM )
{
    m_ui8AltMode4 = AM;
}

//////////////////////////////////////////////////////////////////////////

void SystemIdentifier::SetAltModeC( KBOOL AM )
{
    m_ui8AltModeC = AM;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SystemIdentifier::GetChangeIndicator() const
{
    return m_ui8ChangeIndicator;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SystemIdentifier::GetAltMode4() const
{
    return m_ui8AltMode4;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SystemIdentifier::GetAltModeC() const
{
    return m_ui8AltModeC;
}

//////////////////////////////////////////////////////////////////////////

KString SystemIdentifier::GetAsString() const
{
    KStringStream ss;

    ss << "System Identifier:"
       << "\n\tType:           " << GetEnumAsStringSystemType( m_ui16SystemType )
       << "\n\tName:           " << GetEnumAsStringSystemName( m_ui16SystemName )
       << "\n\tMode:           " << GetEnumAsStringSystemMode( m_ui8SystemMode )
       << "\n\tChange/Options: " << ( KBOOL )m_ui8ChangeIndicator
       << "\n";

    if( m_ui16SystemType == Mark_X_XII_ATCRBS_ModeS_Interrogator ||
            m_ui16SystemType == Mark_X_XII_ATCRBS_ModeS_Transponder )
    {
        ss << "\tAlt Mode 4: " << ( KUINT16 )m_ui8AltMode4
           << "\n\tAlt Mode C:  " << ( KUINT16 )m_ui8AltModeC
           << "\n";
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SystemIdentifier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SYSTEM_IDENTIFER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16SystemType
           >> m_ui16SystemName
           >> m_ui8SystemMode
           >> m_ui8ChangeOptions;
}

//////////////////////////////////////////////////////////////////////////

KDataStream SystemIdentifier::Encode() const
{
    KDataStream stream;

    SystemIdentifier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SystemIdentifier::Encode( KDataStream & stream ) const
{
    stream << m_ui16SystemType
           << m_ui16SystemName
           << m_ui8SystemMode
           << m_ui8ChangeOptions;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SystemIdentifier::operator == ( const SystemIdentifier & Value ) const
{
    if( m_ui16SystemType   != Value.m_ui16SystemType )   return false;
    if( m_ui16SystemName   != Value.m_ui16SystemName )   return false;
    if( m_ui8SystemMode    != Value.m_ui8SystemMode )    return false;
    if( m_ui8ChangeOptions != Value.m_ui8ChangeOptions ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SystemIdentifier::operator != ( const SystemIdentifier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

