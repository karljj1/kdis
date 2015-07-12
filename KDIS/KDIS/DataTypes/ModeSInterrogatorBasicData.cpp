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

#include "./ModeSInterrogatorBasicData.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace UTILS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ModeSInterrogatorBasicData::ModeSInterrogatorBasicData() :
	m_ui8Padding( 0 )
	//m_ui16Padding1( 0 ),
	//m_ui32MsgFormats( 0 ),
	//m_ui16Padding2( 0 )
{	
}

//////////////////////////////////////////////////////////////////////////

//ModeSInterrogatorBasicData::ModeSInterrogatorBasicData( const Mode5InterrogatorStatus & Status, KUINT32 FormatsPresent, const EntityIdentifier & ID ) :
//	m_Status( Status ),
//	m_ui8Padding( 0 ),
//	m_ui16Padding1( 0 ),
//	m_ui32MsgFormats( FormatsPresent ),
//	m_InterrogatedID( ID ),
//	m_ui16Padding2( 0 )
//{
//}


//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorBasicData::SetStatus(const ModeSInterrogatorStatus & S)
{
	m_Status = S;
}

//////////////////////////////////////////////////////////////////////////

const ModeSInterrogatorStatus & ModeSInterrogatorBasicData::GetStatus() const
{
	return m_Status;
}

//////////////////////////////////////////////////////////////////////////

ModeSInterrogatorStatus & ModeSInterrogatorBasicData::GetStatus()
{
	return m_Status;
}

//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorBasicData::SetLevelsPresent( const ModeSLevelsPresent & LP )
{
	m_LvlsPresent = LP;
}

//////////////////////////////////////////////////////////////////////////

const ModeSLevelsPresent & ModeSInterrogatorBasicData::GetLevelsPresent() const
{
	return m_LvlsPresent;
}

//////////////////////////////////////////////////////////////////////////

ModeSLevelsPresent & ModeSInterrogatorBasicData::GetLevelsPresent()
{
	return m_LvlsPresent;
}

//////////////////////////////////////////////////////////////////////////

ModeSInterrogatorBasicData::ModeSInterrogatorBasicData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ModeSInterrogatorBasicData::~ModeSInterrogatorBasicData()
{
}


//////////////////////////////////////////////////////////////////////////

KString ModeSInterrogatorBasicData::GetAsString() const
{
    KStringStream ss;	
	//ss << "Mode 5 Interrogator Basic Data:"
 //      << IndentString( m_Status.GetAsString() )
	//   << GetMessageFormatsPresentBitSet().to_string()
	//   << IndentString( m_InterrogatedID.GetAsString() );	   
	//   
    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorBasicData::Decode( KDataStream & stream ) throw( KException )
{
	if( stream.GetBufferSize() < MODE_S_INTERROGATOR_BASIC_DATA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	
/*    stream >> KDIS_STREAM m_Status
		   >> m_ui8Padding
		   >> m_ui16Padding1
		   >> m_ui32MsgFormats
		   >> KDIS_STREAM m_InterrogatedID
		   >> m_ui16Padding2;*/	
}

//////////////////////////////////////////////////////////////////////////

KDataStream ModeSInterrogatorBasicData::Encode() const
{
    KDataStream stream;

    ModeSInterrogatorBasicData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ModeSInterrogatorBasicData::Encode( KDataStream & stream ) const
{
	//stream << KDIS_STREAM m_Status
	//	   << m_ui8Padding
	//	   << m_ui16Padding1
	//	   << m_ui32MsgFormats
	//	   << KDIS_STREAM m_InterrogatedID
	//	   << m_ui16Padding2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSInterrogatorBasicData::operator == ( const ModeSInterrogatorBasicData & Value ) const
{
	//if( m_Status         != Value.m_Status )         return false;
	//if( m_ui32MsgFormats != Value.m_ui32MsgFormats ) return false;
	//if( m_InterrogatedID != Value.m_InterrogatedID ) return false;	
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeSInterrogatorBasicData::operator != ( const ModeSInterrogatorBasicData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
