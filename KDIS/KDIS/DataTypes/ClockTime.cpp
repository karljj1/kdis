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

#include "./ClockTime.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ClockTime::ClockTime( void ) :
    m_i32Hour( 0 ),
    m_ui32TimePastHour( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

ClockTime::ClockTime( KINT32 Hour, KUINT32 TimePastHour ) :
    m_i32Hour( Hour ),
    m_ui32TimePastHour( TimePastHour )
{
}

//////////////////////////////////////////////////////////////////////////

ClockTime::ClockTime( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ClockTime::~ClockTime( void )
{
}

//////////////////////////////////////////////////////////////////////////

void ClockTime::SetHour( KINT32 H )
{
    m_i32Hour = H;
}

//////////////////////////////////////////////////////////////////////////

KINT32 ClockTime::GetHour() const
{
    return m_i32Hour;
}

//////////////////////////////////////////////////////////////////////////

void ClockTime::SetTimePastHour( KUINT32 TPH )
{
    m_ui32TimePastHour = TPH;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 ClockTime::GetTimePastHour() const
{
    return m_ui32TimePastHour;
}

//////////////////////////////////////////////////////////////////////////

KString ClockTime::GetAsString() const
{
    KStringStream ss;

    ss << "Hour:             " << m_i32Hour          << "\n"
       << "Time Past Hour:   " << m_ui32TimePastHour << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ClockTime::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < CLOCK_TIME_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_i32Hour
           >> m_ui32TimePastHour;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ClockTime::Encode() const
{
    KDataStream stream;

    ClockTime::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ClockTime::Encode( KDataStream & stream ) const
{
    stream << m_i32Hour
           << m_ui32TimePastHour;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ClockTime::operator == ( const ClockTime & Value ) const
{
    if( m_i32Hour          != Value.m_i32Hour )          return false;
    if( m_ui32TimePastHour != Value.m_ui32TimePastHour ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ClockTime::operator != ( const ClockTime & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KBOOL ClockTime::operator < ( const ClockTime & Value ) const
{
    if( m_i32Hour < Value.m_i32Hour )return true;
    if( m_i32Hour > Value.m_i32Hour )return false;

    return m_ui32TimePastHour < Value.m_ui32TimePastHour;
}

//////////////////////////////////////////////////////////////////////////
