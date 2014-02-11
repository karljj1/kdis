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

#include "./LineRecord2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

LineRecord2::LineRecord2()
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

LineRecord2::~LineRecord2()
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
