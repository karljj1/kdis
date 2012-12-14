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

#include "./TimeStamp.h"

#if defined( WIN32 ) | defined( WIN64 )
#include <windows.h>
#else
#include <time.h>
#endif

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

TimeStamp::TimeStamp( void ) :
    m_bAutoCalcRel( false )
{
    m_TimeStampUnion.m_ui32TimeStamp = 0;
}

//////////////////////////////////////////////////////////////////////////

TimeStamp::TimeStamp( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

TimeStamp::TimeStamp( TimeStampType T, KUINT32 Time, KBOOL AutoCalcRelative /*= false*/ ) :
    m_bAutoCalcRel( AutoCalcRelative )
{
    m_TimeStampUnion.m_ui32TimeStampType = T;
    m_TimeStampUnion.m_ui32Time = Time;
}

//////////////////////////////////////////////////////////////////////////

TimeStamp::~TimeStamp( void )
{
}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::SetTimeStampType( TimeStampType T )
{
    m_TimeStampUnion.m_ui32TimeStampType;
}

//////////////////////////////////////////////////////////////////////////

TimeStampType TimeStamp::GetTimeStampType() const
{
    return ( TimeStampType )m_TimeStampUnion.m_ui32TimeStampType;
}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::SetTime( KUINT32 T )
{
    m_TimeStampUnion.m_ui32Time = T;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 TimeStamp::GetTime() const
{
    return m_TimeStampUnion.m_ui32Time;
}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::SetTimeStampAutoCalculate( KBOOL A )
{
    m_bAutoCalcRel = A;
}

//////////////////////////////////////////////////////////////////////////

KBOOL TimeStamp::IsTimeStampAutoCalculated() const
{
    return m_bAutoCalcRel;
}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::CalculateTimeStamp()
{
    // Calculate the time by taking the minutes, seconds and milliseconds(if supported by os) since the hour and dividing them by 0.000001676
    KINT32 iTs = 0;

#if defined( WIN32 ) | defined( WIN64 ) // Microsoft Windows

    SYSTEMTIME now;
    GetSystemTime( &now );
    KFLOAT64 f = ( now.wMinute * 60 ) + now.wSecond + ( now.wMilliseconds / 1000.0 );
    iTs = f / 0.00000167638;

#else

    time_t aclock;
    time( &aclock );
    struct tm * newtime = localtime( &aclock );
    iTs = newtime->tm_sec + ( newtime->tm_min * 60 );
    iTs = iTs / 0.00000167638;

#endif

#if defined( linux ) // Linux -- Note: You need to include the rt library for clock_gettime.

    // Add nano seconds
    timespec ts;
    clock_gettime( 0, &ts );
    iTs += ts.tv_nsec / 1676.38;

#endif

    m_TimeStampUnion.m_ui32Time = iTs;
}

//////////////////////////////////////////////////////////////////////////

KString TimeStamp::GetAsString() const
{
    KStringStream ss;

    ss << "Time Stamp:       ";
    ss << GetEnumAsStringTimeStampType( m_TimeStampUnion.m_ui32TimeStampType ) << ": "
       << m_TimeStampUnion.m_ui32Time
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < TIME_STAMP_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_TimeStampUnion.m_ui32TimeStamp;
}

//////////////////////////////////////////////////////////////////////////

KDataStream TimeStamp::Encode() const
{
    KDataStream stream;

    TimeStamp::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void TimeStamp::Encode( KDataStream & stream ) const
{
    // Do we need to calculate the timestamp first?
    if( m_bAutoCalcRel )
    {
        // We need to cast away the const so we can make the change.
        TimeStamp * self = const_cast<TimeStamp*>( this );
        self->CalculateTimeStamp();
    }

    stream << m_TimeStampUnion.m_ui32TimeStamp;
}

//////////////////////////////////////////////////////////////////////////

KBOOL TimeStamp::operator == ( const TimeStamp & Value ) const
{
    if( m_TimeStampUnion.m_ui32TimeStamp != Value.m_TimeStampUnion.m_ui32TimeStamp ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL TimeStamp::operator != ( const TimeStamp & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KBOOL TimeStamp::operator < ( const TimeStamp & Value ) const
{
    // Note: We don't check if the time stamps are the same type.
    return m_TimeStampUnion.m_ui32Time < Value.m_TimeStampUnion.m_ui32Time;
}

//////////////////////////////////////////////////////////////////////////

