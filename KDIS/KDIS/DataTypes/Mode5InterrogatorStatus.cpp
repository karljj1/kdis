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

#include "./Mode5InterrogatorStatus.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Mode5InterrogatorStatus::Mode5InterrogatorStatus() 
{
	m_StatusUnion.m_ui8Status = 0;
}

//////////////////////////////////////////////////////////////////////////

Mode5InterrogatorStatus::Mode5InterrogatorStatus( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Mode5InterrogatorStatus::Mode5InterrogatorStatus( KUINT8 IFFMission, KDIS::DATA_TYPE::ENUMS::Mode5MessageFormat MF, 
                                                  KBOOL OnOffStatus, KBOOL Damaged, KBOOL Malfunction )
{
	m_StatusUnion.m_ui8Status = 0; // Set all fields to 0
	m_StatusUnion.m_ui8IffMis = IFFMission;
	m_StatusUnion.m_ui8MsgFrmt = MF;
	m_StatusUnion.m_ui8OnOff = OnOffStatus;
	m_StatusUnion.m_ui8Dmg = Damaged;
	m_StatusUnion.m_ui8MalFnc = Malfunction;
}

//////////////////////////////////////////////////////////////////////////

Mode5InterrogatorStatus::~Mode5InterrogatorStatus()
{
}

//////////////////////////////////////////////////////////////////////////

void Mode5InterrogatorStatus::SetIFFMission( KUINT8 IFFM ) throw( KException )
{
	if( IFFM > 7 )throw KException( __FUNCTION__, INVALID_DATA );
	m_StatusUnion.m_ui8IffMis = IFFM;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Mode5InterrogatorStatus::GetIFFMIssion() const
{
	return m_StatusUnion.m_ui8IffMis;
}

//////////////////////////////////////////////////////////////////////////

void Mode5InterrogatorStatus::SetMode5MessageFormat( Mode5MessageFormat MF )
{
	m_StatusUnion.m_ui8MsgFrmt = MF;
}

//////////////////////////////////////////////////////////////////////////

Mode5MessageFormat Mode5InterrogatorStatus::GetMode5MessageFormat() const
{
	return ( Mode5MessageFormat )m_StatusUnion.m_ui8MsgFrmt;
}

//////////////////////////////////////////////////////////////////////////

void Mode5InterrogatorStatus::SetOnOffStatus( KBOOL OOS )
{
	m_StatusUnion.m_ui8OnOff = OOS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5InterrogatorStatus::GetOnOffStatus() const
{
	return m_StatusUnion.m_ui8OnOff;
}

//////////////////////////////////////////////////////////////////////////

void Mode5InterrogatorStatus::SetDamaged( KBOOL D )
{
	m_StatusUnion.m_ui8Dmg = D;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5InterrogatorStatus::IsDamaged() const
{
	return m_StatusUnion.m_ui8Dmg;
}

//////////////////////////////////////////////////////////////////////////

void Mode5InterrogatorStatus::SetMalfunction( KBOOL M )
{
	m_StatusUnion.m_ui8MalFnc = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5InterrogatorStatus::HasMalfunction() const
{
	return m_StatusUnion.m_ui8MalFnc;
}

//////////////////////////////////////////////////////////////////////////

KString Mode5InterrogatorStatus::GetAsString() const
{
    KStringStream ss;	
	ss << "Mode 5 Interrogator Status:"
	   << "\n\tIFF Mission:    " << ( KUINT16 )m_StatusUnion.m_ui8IffMis
	   << "\n\tMessage Format: " << GetEnumAsStringMode5MessageFormat( m_StatusUnion.m_ui8MsgFrmt )
	   << "\n\tOn/Off Status:  " << ( KBOOL )m_StatusUnion.m_ui8OnOff
	   << "\n\tDamaged:        " << ( KBOOL )m_StatusUnion.m_ui8Dmg 
	   << "\n\tMalfunction:    " << ( KBOOL )m_StatusUnion.m_ui8MalFnc
	   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Mode5InterrogatorStatus::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_5_INTERROGATOR_STATUS_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	
	stream >> m_StatusUnion.m_ui8Status;	
}

//////////////////////////////////////////////////////////////////////////

KDataStream Mode5InterrogatorStatus::Encode() const
{
    KDataStream stream;

    Mode5InterrogatorStatus::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Mode5InterrogatorStatus::Encode( KDataStream & stream ) const
{
	stream << m_StatusUnion.m_ui8Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5InterrogatorStatus::operator == ( const Mode5InterrogatorStatus & Value ) const
{
	if( m_StatusUnion.m_ui8Status != Value.m_StatusUnion.m_ui8Status ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5InterrogatorStatus::operator != ( const Mode5InterrogatorStatus & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
