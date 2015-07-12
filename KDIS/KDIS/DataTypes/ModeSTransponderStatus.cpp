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
/*
ModeSTransponderStatus::ModeSTransponderStatus( KDIS::DATA_TYPE::ENUMS::Mode5Reply R, KBOOL LineTest, KDIS::DATA_TYPE::ENUMS::AntennaSelection AS, KBOOL Crypto,
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
*/
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

KString ModeSTransponderStatus::GetAsString() const
{
    KStringStream ss;	
/*
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
*/
    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ModeSTransponderStatus::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_5_TRANSPONDER_STATUS_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	
	//stream >> m_StatusUnion.m_ui16Status;
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
	//stream << m_StatusUnion.m_ui16Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::operator == ( const ModeSTransponderStatus & Value ) const
{
	//if( m_StatusUnion.m_ui16Status != Value.m_StatusUnion.m_ui16Status ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSTransponderStatus::operator != ( const ModeSTransponderStatus & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
