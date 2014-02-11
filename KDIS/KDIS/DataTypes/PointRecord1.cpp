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

#include "./PointRecord1.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

PointRecord1::PointRecord1()
{
    m_ui32EnvRecTyp = PointRecord1Type;
    m_ui16Length = ( POINT_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

PointRecord1::PointRecord1( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

PointRecord1::PointRecord1( KUINT8 Index, const WorldCoordinates & Location ) :
    m_Location( Location )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = PointRecord1Type;
    m_ui16Length = ( POINT_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

PointRecord1::~PointRecord1()
{
}

//////////////////////////////////////////////////////////////////////////

void PointRecord1::SetLocation( const WorldCoordinates & L )
{
    m_Location = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & PointRecord1::GetLocation() const
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & PointRecord1::GetLocation()
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

KString PointRecord1::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tLocation: " <<  m_Location.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void PointRecord1::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < POINT_RECORD_1_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_Location;
}

//////////////////////////////////////////////////////////////////////////

KDataStream PointRecord1::Encode() const
{
    KDataStream stream;

    PointRecord1::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void PointRecord1::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_Location;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointRecord1::operator == ( const PointRecord1 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) ) return false;
    if( m_Location != Value.m_Location ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointRecord1::operator != ( const PointRecord1 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
