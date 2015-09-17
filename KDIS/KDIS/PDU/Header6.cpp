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

#include "./Header6.h"
#include <iomanip>
#include <limits>

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Header6::Header6() :
    m_ui8ProtocolVersion( 0 ),
    m_ui8ExerciseID( 0 ),
    m_ui8PDUType( 0 ),
    m_ui8ProtocolFamily( 0 ),
    m_ui16PDULength( 0 ),
	m_ui8Padding1( 0 ),
    m_ui8Padding2( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Header6::Header6( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Header6::Header6( ProtocolVersion PV, KUINT8 ExerciseID, PDUType PT, ProtocolFamily PF, const TimeStamp & TS, KUINT16 PDULength ) :
    m_ui8ProtocolVersion( PV ),
    m_ui8ExerciseID( ExerciseID ),
    m_ui8PDUType( PT ),
    m_ui8ProtocolFamily( PF ),
    m_TimeStamp( TS ),
    m_ui16PDULength( PDULength ),
	m_ui8Padding1( 0 ),
    m_ui8Padding2( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Header6::~Header6()
{
}

//////////////////////////////////////////////////////////////////////////

void Header6::SetProtocolVersion( ProtocolVersion PV )
{
    m_ui8ProtocolVersion = PV;
}

//////////////////////////////////////////////////////////////////////////

ProtocolVersion Header6::GetProtocolVersion() const
{
    return ( ProtocolVersion )m_ui8ProtocolVersion;
}

//////////////////////////////////////////////////////////////////////////

void Header6::SetExerciseID( KUINT8 EID )
{
    m_ui8ExerciseID = EID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Header6::GetExerciseID() const
{
    return m_ui8ExerciseID;
}

//////////////////////////////////////////////////////////////////////////

void Header6::SetPDUType( PDUType Type )
{
    m_ui8PDUType = Type;
}

//////////////////////////////////////////////////////////////////////////

PDUType Header6::GetPDUType() const
{
    return ( PDUType )m_ui8PDUType;
}

//////////////////////////////////////////////////////////////////////////

void Header6::SetProtocolFamily( ProtocolFamily PF )
{
    m_ui8ProtocolFamily = PF;
}

//////////////////////////////////////////////////////////////////////////

ProtocolFamily Header6::GetProtocolFamily() const
{
    return ( ProtocolFamily )m_ui8ProtocolFamily;
}

//////////////////////////////////////////////////////////////////////////

void Header6::SetTimeStamp( const TimeStamp & TS )
{
    m_TimeStamp = TS;
}

//////////////////////////////////////////////////////////////////////////

const TimeStamp & Header6::GetTimeStamp() const
{
    return m_TimeStamp;
}

//////////////////////////////////////////////////////////////////////////

TimeStamp & Header6::GetTimeStamp()
{
    return m_TimeStamp;
}

//////////////////////////////////////////////////////////////////////////

void Header6::SetPDULength( KUINT16 PDUL )
{
    m_ui16PDULength = PDUL;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Header6::GetPDULength() const
{
    return m_ui16PDULength;
}

//////////////////////////////////////////////////////////////////////////

KString Header6::GetAsString() const
{
    KStringStream ss;

    ss << "-PDU Header-\n"
       << "Protocol Version: " << GetEnumAsStringProtocolVersion( m_ui8ProtocolVersion )    << "\n"
       << "Exercise ID:      " << ( KUINT16 )GetExerciseID()                                << "\n"
       << "PDU Type:         " << GetEnumAsStringPDUType( m_ui8PDUType )                    << "\n"
       << "Protocol Family:  " << GetEnumAsStringProtocolFamily( m_ui8ProtocolFamily )      << "\n"
       << m_TimeStamp.GetAsString()
       << "PDU Length:       " << m_ui16PDULength                                           << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Header6::Decode( KDataStream & stream, bool ignoreHeader /*= false*/  ) throw( KException )
{
	if( !ignoreHeader )
	{
		if( stream.GetBufferSize() < HEADER6_PDU_SIZE )
        {
            const KUINT16 bufferSize = stream.GetBufferSize();
            KStringStream ss;
            ss << "Received " << stream.GetBufferSize() << " bytes. Expected minimum " << HEADER6_PDU_SIZE << " bytes.\nData: ";
            for(KUINT16 i = 0; i < bufferSize; i++)
            {
                ss << std::setfill('0') << std::setw(std::numeric_limits<KUOCTET>::digits/4) << std::hex << static_cast<KUINT32>(stream.GetBuffer()[i]) << " ";
            }
            ss << "\n";
            throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER, ss.str() );
        }

		stream >> m_ui8ProtocolVersion
			   >> m_ui8ExerciseID
			   >> m_ui8PDUType
			   >> m_ui8ProtocolFamily
			   >> KDIS_STREAM m_TimeStamp
			   >> m_ui16PDULength
			   >> m_ui8Padding1
			   >> m_ui8Padding2;
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream Header6::Encode() const
{
    KDataStream stream;

    Header6::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Header6::Encode( KDataStream & stream ) const
{
    stream << m_ui8ProtocolVersion
           << m_ui8ExerciseID
           << m_ui8PDUType
           << m_ui8ProtocolFamily
           << KDIS_STREAM m_TimeStamp
           << m_ui16PDULength
           << m_ui8Padding1
           << m_ui8Padding2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header6::operator == ( const Header6 & Value ) const
{
    if( m_ui8ProtocolVersion    != Value.m_ui8ProtocolVersion )  return false;
    if( m_ui8ExerciseID         != Value.m_ui8ExerciseID )       return false;
    if( m_ui8PDUType            != Value.m_ui8PDUType )          return false;
    if( m_ui8ProtocolFamily     != Value.m_ui8ProtocolFamily )   return false;
    if( m_TimeStamp             != Value.m_TimeStamp )           return false;
    if( m_ui16PDULength         != Value.m_ui16PDULength )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Header6::operator != ( const Header6 & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////





