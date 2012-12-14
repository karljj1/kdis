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

#include "./LineRecord2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

LineRecord2::LineRecord2( void )
{
    m_ui32EnvRecTyp = LineRecord2Type;
    m_ui16Length = ( LINE_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

LineRecord2::LineRecord2( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LineRecord2::LineRecord2( KUINT8 Index, const WorldCoordinates & StartLoc, const WorldCoordinates & EndLoc,
                          const Vector & StartVel, const Vector & EndVel ) :
    LineRecord1( Index, StartLoc, EndLoc ),
    m_StartVel( StartVel ),
    m_EndVel( EndVel )
{
    m_ui32EnvRecTyp = LineRecord2Type;
    m_ui16Length = ( LINE_RECORD_2_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

LineRecord2::~LineRecord2( void )
{
}

//////////////////////////////////////////////////////////////////////////

void LineRecord2::SetVelocity( const Vector & Start, const Vector & End )
{
    m_StartVel = Start;
    m_EndVel = End;
}

//////////////////////////////////////////////////////////////////////////

void LineRecord2::SetStartVelocity( const Vector & V)
{
    m_StartVel = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & LineRecord2::GetStartVelocity() const
{
    return m_StartVel;
}

//////////////////////////////////////////////////////////////////////////

Vector & LineRecord2::GetStartVelocity()
{
    return m_StartVel;
}

//////////////////////////////////////////////////////////////////////////

void LineRecord2::SetEndVelocity( const Vector & V )
{
    m_EndVel = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & LineRecord2::GetEndVelocity() const
{
    return m_EndVel;
}

//////////////////////////////////////////////////////////////////////////

Vector & LineRecord2::GetEndVelocity()
{
    return m_EndVel;
}

//////////////////////////////////////////////////////////////////////////

KString LineRecord2::GetAsString() const
{
    KStringStream ss;

    ss << LineRecord1::GetAsString()
       << "\tStart Velocity(m/s): " <<  m_StartVel.GetAsString()
       << "\tEnd Velocity(m/s):   " <<  m_EndVel.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LineRecord2::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LINE_RECORD_2_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    LineRecord1::Decode( stream );

    stream >> KDIS_STREAM m_StartVel
           >> KDIS_STREAM m_EndVel;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LineRecord2::Encode() const
{
    KDataStream stream;

    LineRecord2::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LineRecord2::Encode( KDataStream & stream ) const
{
    LineRecord1::Encode( stream );

    stream << KDIS_STREAM m_StartVel
           << KDIS_STREAM m_EndVel;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LineRecord2::operator == ( const LineRecord2 & Value )const
{
    if( LineRecord1::operator !=( Value ) ) return false;
    if( m_StartVel != Value.m_StartVel ) return false;
    if( m_EndVel   != Value.m_EndVel ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LineRecord2::operator != ( const LineRecord2 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
