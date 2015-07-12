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
	//m_StatusUnion.m_ui8Status = 0;
}

//////////////////////////////////////////////////////////////////////////

ModeSLevelsPresent::ModeSLevelsPresent( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////
/*
ModeSLevelsPresent::ModeSLevelsPresent( KUINT8 IFFMission, KDIS::DATA_TYPE::ENUMS::Mode5MessageFormat MF, 
                                                  KBOOL OnOffStatus, KBOOL Damaged, KBOOL Malfunction )
{
	m_StatusUnion.m_ui8Status = 0; // Set all fields to 0
	m_StatusUnion.m_ui8IffMis = IFFMission;
	m_StatusUnion.m_ui8MsgFrmt = MF;
	m_StatusUnion.m_ui8OnOff = OnOffStatus;
	m_StatusUnion.m_ui8Dmg = Damaged;
	m_StatusUnion.m_ui8MalFnc = Malfunction;
}
*/
//////////////////////////////////////////////////////////////////////////

ModeSLevelsPresent::~ModeSLevelsPresent()
{
}

//////////////////////////////////////////////////////////////////////////

KString ModeSLevelsPresent::GetAsString() const
{
    KStringStream ss;	/*
	ss << "Mode 5 Interrogator Status:"
	   << "\n\tIFF Mission:    " << ( KUINT16 )m_StatusUnion.m_ui8IffMis
	   << "\n\tMessage Format: " << GetEnumAsStringMode5MessageFormat( m_StatusUnion.m_ui8MsgFrmt )
	   << "\n\tOn/Off Status:  " << ( KBOOL )m_StatusUnion.m_ui8OnOff
	   << "\n\tDamaged:        " << ( KBOOL )m_StatusUnion.m_ui8Dmg 
	   << "\n\tMalfunction:    " << ( KBOOL )m_StatusUnion.m_ui8MalFnc
	   << "\n";
*/
    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ModeSLevelsPresent::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_S_LEVELS_PRESENT_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	
	stream >> m_StatusUnion.m_ui8Status;	
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
	stream << m_StatusUnion.m_ui8Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSLevelsPresent::operator == ( const ModeSLevelsPresent & Value ) const
{
	//if( m_StatusUnion.m_ui8Status != Value.m_StatusUnion.m_ui8Status ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSLevelsPresent::operator != ( const ModeSLevelsPresent & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
