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

#include "./Mode5TransponderStatus.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Mode5TransponderStatus::Mode5TransponderStatus() 
{
	m_StatusUnion.m_ui16Status = 0;	
}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderStatus::Mode5TransponderStatus( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////
//
//Mode5TransponderStatus::Mode5TransponderStatus( KUINT8 IFFMission, KDIS::DATA_TYPE::ENUMS::Mode5MessageFormat MF, 
//                                                  KBOOL OnOffStatus, KBOOL Damaged, KBOOL Malfunction )
//{
//	m_StatusUnion.m_ui8Status = 0; // Set all fields to 0
//	m_StatusUnion.m_ui8IffMis = IFFMission;
//	m_StatusUnion.m_ui8MsgFrmt = MF;
//	m_StatusUnion.m_ui8OnOff = OnOffStatus;
//	m_StatusUnion.m_ui8Dmg = Damaged;
//	m_StatusUnion.m_ui8MalFnc = Malfunction;
//}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderStatus::~Mode5TransponderStatus()
{
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetReply( Mode5Reply R ) 
{	
	m_StatusUnion.m_ui16Reply = R;
}

//////////////////////////////////////////////////////////////////////////

Mode5Reply Mode5TransponderStatus::GetReply() const
{
	return ( Mode5Reply )m_StatusUnion.m_ui16Reply;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetLineTestInProgress( KBOOL LT ) 
{
	m_StatusUnion.m_ui16LineTst = LT;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::IsLineTestInProgress() const
{
	return ( KBOOL )m_StatusUnion.m_ui16LineTst;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetAntennaSelection( AntennaSelection AS )
{
	m_StatusUnion.m_ui16AntennaSel = AS;
}

//////////////////////////////////////////////////////////////////////////

AntennaSelection Mode5TransponderStatus::GetAntennaSelection() const
{
	return ( AntennaSelection )m_StatusUnion.m_ui16AntennaSel;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetCryptoControlPresent( KBOOL CC )
{
	m_StatusUnion.m_ui16CryptoCtrl = CC;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::IsCryptoControlPresent() const
{
	return m_StatusUnion.m_ui16CryptoCtrl;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetLocationRecordPresent( KBOOL LRP )
{
	m_StatusUnion.m_ui16LatLonAltSrc = LRP;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::IsLocationRecordPresent() const
{
	return m_StatusUnion.m_ui16LatLonAltSrc;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetLocationErrorRecordPresent( KBOOL LERP )
{
	m_StatusUnion.m_ui16LocErrs = LERP;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::IsLocationErrorRecordPresent() const
{
	return m_StatusUnion.m_ui16LocErrs;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetPlatformType( PlatformType PT )
{
	m_StatusUnion.m_ui16PlatfrmTyp = PT;
}

//////////////////////////////////////////////////////////////////////////

PlatformType Mode5TransponderStatus::GetPlatformType() const
{
	return ( PlatformType )m_StatusUnion.m_ui16PlatfrmTyp;
}

//////////////////////////////////////////////////////////////////////////

KString Mode5TransponderStatus::GetAsString() const
{
    KStringStream ss;	
	//ss << "Mode 5 Interrogator Status:"
	//   << "\n\tIFF Mission:    " << ( KUINT16 )m_StatusUnion.m_ui8IffMis
	//   << "\n\tMessage Format: " << GetEnumAsStringMode5MessageFormat( m_StatusUnion.m_ui8MsgFrmt )
	//   << "\n\tOn/Off Status:  " << ( KBOOL )m_StatusUnion.m_ui8OnOff
	//   << "\n\tDamaged:        " << ( KBOOL )m_StatusUnion.m_ui8Dmg 
	//   << "\n\tMalfunction:    " << ( KBOOL )m_StatusUnion.m_ui8MalFnc
	//   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_5_TRANSPONDER_STATUS_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	
	//stream >> m_StatusUnion.m_ui8Status;	
}

//////////////////////////////////////////////////////////////////////////

KDataStream Mode5TransponderStatus::Encode() const
{
    KDataStream stream;

    Mode5TransponderStatus::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::Encode( KDataStream & stream ) const
{
	//stream << m_StatusUnion.m_ui8Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::operator == ( const Mode5TransponderStatus & Value ) const
{
	//if( m_StatusUnion.m_ui8Status != Value.m_StatusUnion.m_ui8Status ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::operator != ( const Mode5TransponderStatus & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
