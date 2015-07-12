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

#include "./ModeSTransponderStatus.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ModeSTransponderStatus::ModeSTransponderStatus() 
{
	m_StatusUnion.m_ui16Status = 0;	
}

//////////////////////////////////////////////////////////////////////////

ModeSTransponderStatus::ModeSTransponderStatus( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ModeSTransponderStatus::ModeSTransponderStatus( KBOOL SquitterOn, ModeSSquitterType ST, KBOOL RecSrc, KBOOL AirPos, KBOOL AirVel,
		                                        KBOOL SurfPos, KBOOL Id, KBOOL EvntDrv, KBOOL Status, KBOOL Dmg, KBOOL Malfnc )
{	
	m_StatusUnion.m_ui16Status = 0;
	m_StatusUnion.m_ui161SquitterStatus = SquitterOn;
	m_StatusUnion.m_ui16SquitterType = ST;
	m_StatusUnion.m_ui16SquitterRecSrc = RecSrc;
	m_StatusUnion.m_ui16AirPosRptInd = AirPos;
	m_StatusUnion.m_ui16AirVelRptInd = AirVel;
	m_StatusUnion.m_ui16SurfPosRptInd = SurfPos;
	m_StatusUnion.m_ui16IdRptInd = Id;
	m_StatusUnion.m_ui16EvtDrvRptInd = EvntDrv;
	m_StatusUnion.m_ui16Padding = 0;
	m_StatusUnion.m_ui16OnOff = Status;
	m_StatusUnion.m_ui16Dmg = Dmg;          
	m_StatusUnion.m_ui16MalFnc = Malfnc;   	
}

//////////////////////////////////////////////////////////////////////////

ModeSTransponderStatus::~ModeSTransponderStatus()
{
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetSquitterOn( KBOOL S )
{
	m_StatusUnion.m_ui161SquitterStatus = S;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::IsSquitterOn() const
{
	return m_StatusUnion.m_ui161SquitterStatus;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetSquitterType( ModeSSquitterType ST )
{
	m_StatusUnion.m_ui16SquitterType = ST;
}

//////////////////////////////////////////////////////////////////////////

ModeSSquitterType ModeSTransponderStatus::GetSquitterType() const
{
	return ( ModeSSquitterType )m_StatusUnion.m_ui16SquitterType;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetSquitterRecordSource( KBOOL RS )
{
	m_StatusUnion.m_ui16SquitterRecSrc = RS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::GetSquitterRecordSource() const
{
	return m_StatusUnion.m_ui16SquitterRecSrc;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetAirbornePositionReportIndicator( KBOOL RI )
{
	m_StatusUnion.m_ui16AirPosRptInd = RI;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::GetAirbornePositionReportIndicator() const
{
	return m_StatusUnion.m_ui16AirPosRptInd;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetAirborneVelocityReportIndicator( KBOOL RI )
{
	m_StatusUnion.m_ui16AirVelRptInd = RI;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::GetAirborneVelocityReportIndicator() const
{
	return m_StatusUnion.m_ui16AirVelRptInd;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetSurfacePositionReportIndicator( KBOOL RI )
{
	m_StatusUnion.m_ui16SurfPosRptInd = RI;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::GetSurfacePositionReportIndicator() const
{
	return m_StatusUnion.m_ui16SurfPosRptInd;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetIdentificationReportIndicator( KBOOL RI )
{
	m_StatusUnion.m_ui16IdRptInd = RI;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::GetIdentificationReportIndicator() const
{
	return m_StatusUnion.m_ui16IdRptInd;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetEventDrivenReportIndicator( KBOOL RI )
{
	m_StatusUnion.m_ui16EvtDrvRptInd = RI;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::GetEventDrivenReportIndicator() const
{
	return m_StatusUnion.m_ui16EvtDrvRptInd;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetStatus( KBOOL S )
{
	m_StatusUnion.m_ui16OnOff = S;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::GetStatus() const
{
	return ( KBOOL )m_StatusUnion.m_ui16OnOff;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetDamaged( KBOOL D )
{
	m_StatusUnion.m_ui16Dmg = D;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::IsDamaged() const
{
	return ( KBOOL )m_StatusUnion.m_ui16Dmg;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::SetMalfunctioning( KBOOL M )
{
	m_StatusUnion.m_ui16MalFnc = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::IsMalfunctioning() const
{
	return ( KBOOL )m_StatusUnion.m_ui16MalFnc;
}

//////////////////////////////////////////////////////////////////////////

KString ModeSTransponderStatus::GetAsString() const
{
    KStringStream ss;	

	ss << "Mode S Transponder Status:"
	   << "\n\tStatus:                  " << ( KBOOL )m_StatusUnion.m_ui161SquitterStatus
	   << "\n\tSquitter Type:           " << GetEnumAsStringModeSSquitterType( m_StatusUnion.m_ui16SquitterType )
	   << "\n\Squitter Record Source:   " << ( KBOOL )m_StatusUnion.m_ui16SquitterRecSrc 
	   << "\n\tAirborne Position:       " << ( KBOOL )m_StatusUnion.m_ui16AirPosRptInd 
	   << "\n\tAirborne Velcoity:       " << ( KBOOL )m_StatusUnion.m_ui16AirVelRptInd 
	   << "\n\Surface Position:         " << ( KBOOL )m_StatusUnion.m_ui16SurfPosRptInd
	   << "\n\Identification:           " << ( KBOOL )m_StatusUnion.m_ui16IdRptInd
	   << "\n\Event-Driven:             " << ( KBOOL )m_StatusUnion.m_ui16EvtDrvRptInd
	   << "\n\tOn/Off Status:           " << ( KBOOL )m_StatusUnion.m_ui16OnOff
	   << "\n\tDamaged:                 " << ( KBOOL )m_StatusUnion.m_ui16Dmg
	   << "\n\tMalfunction:             " << ( KBOOL )m_StatusUnion.m_ui16MalFnc 
	   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_S_TRANSPONDER_STATUS_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	
	stream >> m_StatusUnion.m_ui16Status;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ModeSTransponderStatus::Encode() const
{
    KDataStream stream;

    ModeSTransponderStatus::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::Encode( KDataStream & stream ) const
{
	stream << m_StatusUnion.m_ui16Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::operator == ( const ModeSTransponderStatus & Value ) const
{
	if( m_StatusUnion.m_ui16Status != Value.m_StatusUnion.m_ui16Status ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::operator != ( const ModeSTransponderStatus & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
