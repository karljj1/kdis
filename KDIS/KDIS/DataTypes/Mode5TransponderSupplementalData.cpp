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

#include "./Mode5TransponderSupplementalData.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace UTILS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Mode5TransponderSupplementalData::Mode5TransponderSupplementalData() 
{	
	m_SupplementalDataUnion.m_ui8SupplementalData = 0;
}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderSupplementalData::Mode5TransponderSupplementalData( KBOOL Squitter, KBOOL Lvl2Squitter, KUINT8 IFFMission ) throw( KException )
{
	if( IFFMission > 7 )throw KException( __FUNCTION__, DATA_TYPE_TOO_LARGE );
	m_SupplementalDataUnion.m_ui8SupplementalData = 0;
	m_SupplementalDataUnion.m_ui8SquitterStatus = Squitter;
	m_SupplementalDataUnion.m_ui8Lvl2SquitterStatus = Lvl2Squitter;
	m_SupplementalDataUnion.m_ui8IFFMission = IFFMission;
}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderSupplementalData::Mode5TransponderSupplementalData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderSupplementalData::~Mode5TransponderSupplementalData()
{
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderSupplementalData::SetSquitter( KBOOL S )
{
	m_SupplementalDataUnion.m_ui8SquitterStatus = S;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderSupplementalData::GetSquitter() const
{
	return m_SupplementalDataUnion.m_ui8SquitterStatus;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderSupplementalData::SetLevel2Squitter( KBOOL L2S )
{
	m_SupplementalDataUnion.m_ui8Lvl2SquitterStatus = L2S;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderSupplementalData::GetLevel2Squitter() const
{
	return m_SupplementalDataUnion.m_ui8Lvl2SquitterStatus;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderSupplementalData::SetIFFMission( KUINT8 IFFM ) throw( KException )
{
	if( IFFM > 7 )throw KException( __FUNCTION__, DATA_TYPE_TOO_LARGE );
	m_SupplementalDataUnion.m_ui8IFFMission = IFFM;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Mode5TransponderSupplementalData::GetIFFMission() const
{
	return m_SupplementalDataUnion.m_ui8IFFMission;
}

//////////////////////////////////////////////////////////////////////////

KString Mode5TransponderSupplementalData::GetAsString() const
{
    KStringStream ss;	
	ss << "Mode 5 Transponder Supplemental Data:"
	   << "\n\tSquitter: "        << ( KBOOL )m_SupplementalDataUnion.m_ui8SquitterStatus 
	   << "\n\tLevel 2 Squiter: " << ( KBOOL )m_SupplementalDataUnion.m_ui8Lvl2SquitterStatus
	   << "\n\tIFF Mission: "     << m_SupplementalDataUnion.m_ui8IFFMission
	   << "\n";
    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderSupplementalData::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_5_TRANSPONDER_SUPPLEMENTAL_DATA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	
	stream >> m_SupplementalDataUnion.m_ui8SupplementalData;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Mode5TransponderSupplementalData::Encode() const
{
    KDataStream stream;

    Mode5TransponderSupplementalData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderSupplementalData::Encode( KDataStream & stream ) const
{
	stream << m_SupplementalDataUnion.m_ui8SupplementalData;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderSupplementalData::operator == ( const Mode5TransponderSupplementalData & Value ) const
{
	if( m_SupplementalDataUnion.m_ui8SupplementalData != Value.m_SupplementalDataUnion.m_ui8SupplementalData ) return false;	
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderSupplementalData::operator != ( const Mode5TransponderSupplementalData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
