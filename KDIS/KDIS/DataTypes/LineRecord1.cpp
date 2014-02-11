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

#include "./LineRecord1.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

LineRecord1::LineRecord1()
{
    m_ui32EnvRecTyp = LineRecord1Type;
    m_ui16Length = ( LINE_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

LineRecord1::LineRecord1( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LineRecord1::LineRecord1( KUINT8 Index, const WorldCoordinates & Start, const WorldCoordinates & End  ) :
    m_StartLocation( Start ),
    m_EndLocation( End )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = LineRecord1Type;
    m_ui16Length = ( LINE_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

LineRecord1::~LineRecord1()
{
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::SetLocation( const WorldCoordinates & Start, const WorldCoordinates & End )
{
    m_StartLocation = Start;
    m_EndLocation = End;
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::SetStartLocation( const WorldCoordinates & L )
{
    m_StartLocation = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & LineRecord1::GetStartLocation() const
{
    return m_StartLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & LineRecord1::GetStartLocation()
{
    return m_StartLocation;
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::SetEndLocation( const WorldCoordinates & L )
{
    m_EndLocation = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & LineRecord1::GetEndLocation() const
{
    return m_EndLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & LineRecord1::GetEndLocation()
{
    return m_EndLocation;
}

//////////////////////////////////////////////////////////////////////////

KString LineRecord1::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tStart Location: " <<  m_StartLocation.GetAsString()
       << "\tEnd Location:   " <<  m_EndLocation.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LINE_RECORD_1_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_StartLocation
           >> KDIS_STREAM m_EndLocation;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LineRecord1::Encode() const
{
    KDataStream stream;

    LineRecord1::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LineRecord1::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_StartLocation
           << KDIS_STREAM m_EndLocation;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LineRecord1::operator == ( const LineRecord1 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) ) return false;
    if( m_StartLocation != Value.m_StartLocation ) return false;
    if( m_EndLocation   != Value.m_EndLocation ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LineRecord1::operator != ( const LineRecord1 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
