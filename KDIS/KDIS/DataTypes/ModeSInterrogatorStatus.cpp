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

#include "./ModeSInterrogatorStatus.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////


ModeSInterrogatorStatus::ModeSInterrogatorStatus()
{
	m_StatusUnion.m_ui8Status = 0;
}

//////////////////////////////////////////////////////////////////////////

ModeSInterrogatorStatus::ModeSInterrogatorStatus( KBOOL OnOffStatus, KDIS::DATA_TYPE::ENUMS::ModeSInterrogatorStatusTransmitState TS,
	                                              KBOOL Damaged, KBOOL Malfunction )
{
	m_StatusUnion.m_ui8Status = 0;
	m_StatusUnion.m_ui8OnOff = OnOffStatus;
	m_StatusUnion.m_ui8Transmit = TS;
	m_StatusUnion.m_ui8Dmg = Damaged;
	m_StatusUnion.m_ui8MalFnc = Malfunction;
}


//////////////////////////////////////////////////////////////////////////

ModeSInterrogatorStatus::ModeSInterrogatorStatus( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ModeSInterrogatorStatus::~ModeSInterrogatorStatus()
{
}

//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorStatus::SetOnOffStatus( KBOOL OOS )
{
	m_StatusUnion.m_ui8OnOff = OOS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSInterrogatorStatus::GetOnOffStatus() const
{
	return m_StatusUnion.m_ui8OnOff;
}

//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorStatus::SetTransmitState( ModeSInterrogatorStatusTransmitState TS )
{
	m_StatusUnion.m_ui8Transmit = TS;
}

//////////////////////////////////////////////////////////////////////////

ModeSInterrogatorStatusTransmitState ModeSInterrogatorStatus::GetTransmitState() const
{
	return ( ModeSInterrogatorStatusTransmitState )m_StatusUnion.m_ui8Transmit;
}

//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorStatus::SetDamaged( KBOOL D )
{
	m_StatusUnion.m_ui8Dmg = D;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSInterrogatorStatus::IsDamaged() const
{
	return m_StatusUnion.m_ui8Dmg;
}

//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorStatus::SetMalfunction( KBOOL M )
{
	m_StatusUnion.m_ui8MalFnc = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSInterrogatorStatus::HasMalfunction() const
{
	return m_StatusUnion.m_ui8MalFnc;
}

//////////////////////////////////////////////////////////////////////////

KString ModeSInterrogatorStatus::GetAsString() const
{
    KStringStream ss;	
	ss << "Mode S Interrogator Status:"
	   << "\n\tOn/Off Status:  " << ( KBOOL )m_StatusUnion.m_ui8OnOff
	   << "\nTransmit State:   " << GetEnumAsStringModeSInterrogatorStatusTransmitState( m_StatusUnion.m_ui8Transmit )
	   << "\n\tDamaged:        " << ( KBOOL )m_StatusUnion.m_ui8Dmg 
	   << "\n\tMalfunction:    " << ( KBOOL )m_StatusUnion.m_ui8MalFnc
	   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorStatus::Decode( KDataStream & stream ) throw( KException )
{
	if( stream.GetBufferSize() < MODE_S_INTERROGATOR_STATUS_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	stream >> m_StatusUnion.m_ui8Status;	
}

//////////////////////////////////////////////////////////////////////////

KDataStream ModeSInterrogatorStatus::Encode() const
{
    KDataStream stream;

    ModeSInterrogatorStatus::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorStatus::Encode( KDataStream & stream ) const
{
	stream << m_StatusUnion.m_ui8Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSInterrogatorStatus::operator == ( const ModeSInterrogatorStatus & Value ) const
{
	if( m_StatusUnion.m_ui8Status != Value.m_StatusUnion.m_ui8Status ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSInterrogatorStatus::operator != ( const ModeSInterrogatorStatus & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
