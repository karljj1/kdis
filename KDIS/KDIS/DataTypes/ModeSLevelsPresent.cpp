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

#include "./ModeSLevelsPresent.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ModeSLevelsPresent::ModeSLevelsPresent() 
{
	m_LevelsUnion.m_ui8LevelsPresent = 0;
}

//////////////////////////////////////////////////////////////////////////

ModeSLevelsPresent::ModeSLevelsPresent( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ModeSLevelsPresent::ModeSLevelsPresent( KBOOL Lvl1, KBOOL Lvl2Elementary, KBOOL Lvl2Enhanced, KBOOL Lvl3, KBOOL Lvl4 )
{
	m_LevelsUnion.m_ui8LevelsPresent = 0;
	m_LevelsUnion.m_ui8Lvl1 = Lvl1;
	m_LevelsUnion.m_ui8Lvl2Elementary = Lvl2Elementary;
	m_LevelsUnion.m_ui8Lvl2Enhanced = Lvl2Enhanced;
	m_LevelsUnion.m_ui8Lvl3 = Lvl3;
	m_LevelsUnion.m_ui8Lvl4 = Lvl4;
}

//////////////////////////////////////////////////////////////////////////

ModeSLevelsPresent::~ModeSLevelsPresent()
{
}

//////////////////////////////////////////////////////////////////////////

void ModeSLevelsPresent::SetLevel1Present( KBOOL LP )
{
	m_LevelsUnion.m_ui8Lvl1 = LP;
}

//////////////////////////////////////////////////////////////////////////

void ModeSLevelsPresent::SetLevel2ElementarySublevelPresent( KBOOL LP )
{
	m_LevelsUnion.m_ui8Lvl2Elementary = LP;
}

//////////////////////////////////////////////////////////////////////////

void ModeSLevelsPresent::SetLevel2EnhancedSublevelPresent( KBOOL LP )
{
	m_LevelsUnion.m_ui8Lvl2Enhanced = LP;
}

//////////////////////////////////////////////////////////////////////////

void ModeSLevelsPresent::SetLevel3Present( KBOOL LP )
{
	m_LevelsUnion.m_ui8Lvl3 = LP;
}

//////////////////////////////////////////////////////////////////////////

void ModeSLevelsPresent::SetLevel4Present( KBOOL LP )
{
	m_LevelsUnion.m_ui8Lvl4 = LP;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSLevelsPresent::IsLevel1Present() const
{
	return m_LevelsUnion.m_ui8Lvl1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSLevelsPresent::IsLevel2ElementarySublevelPresent() const
{
	return m_LevelsUnion.m_ui8Lvl2Elementary;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSLevelsPresent::IsLevel2EnhancedSublevelPresent() const
{
	return m_LevelsUnion.m_ui8Lvl2Enhanced;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSLevelsPresent::IsLevel3Present() const
{
	return m_LevelsUnion.m_ui8Lvl3;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSLevelsPresent::IsLevel4Present() const
{
	return m_LevelsUnion.m_ui8Lvl4;
}

//////////////////////////////////////////////////////////////////////////

KString ModeSLevelsPresent::GetAsString() const
{
    KStringStream ss;	
	ss << "Mode S Levels Present:"
	   << "\n\tLevel 1: " << ( KBOOL )m_LevelsUnion.m_ui8Lvl1
	   << "\n\tLevel 2(Elementary Surveillance sublevel): " << ( KBOOL )m_LevelsUnion.m_ui8Lvl2Elementary
	   << "\n\tLevel 2(Enhanced Surveillance sublevel): " << ( KBOOL )m_LevelsUnion.m_ui8Lvl2Enhanced
	   << "\n\tLevel 3: " << ( KBOOL )m_LevelsUnion.m_ui8Lvl3
	   << "\n\tLevel 4: " << ( KBOOL )m_LevelsUnion.m_ui8Lvl4
	   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ModeSLevelsPresent::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_S_LEVELS_PRESENT_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	
	stream >> m_LevelsUnion.m_ui8LevelsPresent;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ModeSLevelsPresent::Encode() const
{
    KDataStream stream;

    ModeSLevelsPresent::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ModeSLevelsPresent::Encode( KDataStream & stream ) const
{
	stream << m_LevelsUnion.m_ui8LevelsPresent;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSLevelsPresent::operator == ( const ModeSLevelsPresent & Value ) const
{
	if( m_LevelsUnion.m_ui8LevelsPresent != Value.m_LevelsUnion.m_ui8LevelsPresent ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSLevelsPresent::operator != ( const ModeSLevelsPresent & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
