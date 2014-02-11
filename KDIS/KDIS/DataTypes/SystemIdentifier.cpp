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

#include "./SystemIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SystemIdentifier::SystemIdentifier() :
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

SystemIdentifier::~SystemIdentifier()
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

