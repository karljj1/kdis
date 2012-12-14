/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include "./Header6.h"

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Header6::Header6( void ) :
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
    Decode( stream );
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

Header6::~Header6( void )
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

void Header6::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < HEADER6_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8ProtocolVersion
           >> m_ui8ExerciseID
           >> m_ui8PDUType
           >> m_ui8ProtocolFamily
           >> KDIS_STREAM m_TimeStamp
           >> m_ui16PDULength
           >> m_ui8Padding1
           >> m_ui8Padding2;
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





