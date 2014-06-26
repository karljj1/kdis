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

Mode5TransponderStatus::Mode5TransponderStatus( KDIS::DATA_TYPE::ENUMS::Mode5Reply R, KBOOL LineTest, KDIS::DATA_TYPE::ENUMS::AntennaSelection AS, KBOOL Crypto,
	                                            KBOOL LocationIncluded, KBOOL LocationErrorIncluded, KDIS::DATA_TYPE::ENUMS::PlatformType PT, KBOOL Lvl2Included,
                                                KBOOL Status, KBOOL Dmg, KBOOL Malfnc )
{	
	m_StatusUnion.m_ui16Reply = R;
	m_StatusUnion.m_ui16LineTst = LineTest;      
	m_StatusUnion.m_ui16AntennaSel = AS;
	m_StatusUnion.m_ui16CryptoCtrl = Crypto; 
	m_StatusUnion.m_ui16LatLonAltSrc = LocationIncluded;
	m_StatusUnion.m_ui16LocErrs = LocationErrorIncluded;
	m_StatusUnion.m_ui16PlatfrmTyp = PT;
	m_StatusUnion.m_ui16LvlSel = Lvl2Included;
	m_StatusUnion.m_ui16Padding = 0;
	m_StatusUnion.m_ui16OnOff = Status;
	m_StatusUnion.m_ui16Dmg = Dmg;          
	m_StatusUnion.m_ui16MalFnc = Malfnc;   	
}

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
	return ( KBOOL )m_StatusUnion.m_ui16CryptoCtrl;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetLocationRecordPresent( KBOOL LRP )
{
	m_StatusUnion.m_ui16LatLonAltSrc = LRP;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::IsLocationRecordPresent() const
{
	return ( KBOOL )m_StatusUnion.m_ui16LatLonAltSrc;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetLocationErrorRecordPresent( KBOOL LERP )
{
	m_StatusUnion.m_ui16LocErrs = LERP;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::IsLocationErrorRecordPresent() const
{
	return ( KBOOL )m_StatusUnion.m_ui16LocErrs;
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

void Mode5TransponderStatus::SetMode5Level2Included( KBOOL M )
{
	m_StatusUnion.m_ui16LvlSel = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::IsMode5Level2Included() const
{
	return ( KBOOL )m_StatusUnion.m_ui16LvlSel;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetStatus( KBOOL S )
{
	m_StatusUnion.m_ui16OnOff = S;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::GetStatus() const
{
	return ( KBOOL )m_StatusUnion.m_ui16OnOff;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetDamaged( KBOOL D )
{
	m_StatusUnion.m_ui16Dmg = D;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::IsDamaged() const
{
	return ( KBOOL )m_StatusUnion.m_ui16Dmg;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::SetMalfunctioning( KBOOL M )
{
	m_StatusUnion.m_ui16MalFnc = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::IsMalfunctioning() const
{
	return ( KBOOL )m_StatusUnion.m_ui16MalFnc;
}

//////////////////////////////////////////////////////////////////////////

KString Mode5TransponderStatus::GetAsString() const
{
    KStringStream ss;	

	ss << "Mode 5 Transponder Status:"
	   << "\n\tReply:                   " << GetEnumAsStringMode5Reply( m_StatusUnion.m_ui16Reply )
	   << "\n\tLine Test:               " << ( KBOOL )m_StatusUnion.m_ui16LineTst
	   << "\n\tAntenna Selection:       " << GetEnumAsStringAntennaSelection( m_StatusUnion.m_ui16AntennaSel )
	   << "\n\tCrypto Control:          " << ( KBOOL )m_StatusUnion.m_ui16CryptoCtrl
	   << "\n\tLocation Included:       " << ( KBOOL )m_StatusUnion.m_ui16LatLonAltSrc
	   << "\n\tLocation Error Included: " << ( KBOOL )m_StatusUnion.m_ui16LocErrs
	   << "\n\tPlatform Type:           " << GetEnumAsStringPlatformType( m_StatusUnion.m_ui16PlatfrmTyp )
	   << "\n\tLevel 2 Included:        " << ( KBOOL )m_StatusUnion.m_ui16LvlSel
	   << "\n\tOn/Off Status:           " << ( KBOOL )m_StatusUnion.m_ui16OnOff
	   << "\n\tDamaged:                 " << ( KBOOL )m_StatusUnion.m_ui16Dmg
	   << "\n\tMalfunction:             " << ( KBOOL )m_StatusUnion.m_ui16MalFnc 
	   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderStatus::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_5_TRANSPONDER_STATUS_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	
	stream >> m_StatusUnion.m_ui16Status;
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
	stream << m_StatusUnion.m_ui16Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::operator == ( const Mode5TransponderStatus & Value ) const
{
	if( m_StatusUnion.m_ui16Status != Value.m_StatusUnion.m_ui16Status ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderStatus::operator != ( const Mode5TransponderStatus & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
