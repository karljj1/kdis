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

#include "./EllipsoidRecord1.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

EllipsoidRecord1::EllipsoidRecord1()
{
    m_ui32EnvRecTyp = EllipsoidRecord1Type;
    m_ui16Length = ( ELIPSOID_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

EllipsoidRecord1::EllipsoidRecord1( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EllipsoidRecord1::EllipsoidRecord1( KUINT8 Index, const WorldCoordinates & CentroidLocation,
                                    const Vector & Sigma, const EulerAngles & Orientation ) :
    m_CentLocation( CentroidLocation ),
    m_Sigma( Sigma ),
    m_Ori( Orientation )
{
    m_ui32EnvRecTyp = EllipsoidRecord1Type;
    m_ui16Length = ( ELIPSOID_RECORD_1_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

EllipsoidRecord1::~EllipsoidRecord1()
{
}

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord1::SetCentroidLocation( const WorldCoordinates & CL )
{
    m_CentLocation = CL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & EllipsoidRecord1::GetCentroidLocation() const
{
    return m_CentLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & EllipsoidRecord1::GetCentroidLocation()
{
    return m_CentLocation;
}

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord1::SetSigma( const Vector & S )
{
    m_Sigma = S;
}

//////////////////////////////////////////////////////////////////////////

const Vector & EllipsoidRecord1::GetSigma() const
{
    return m_Sigma;
}

//////////////////////////////////////////////////////////////////////////

Vector & EllipsoidRecord1::GetSigma()
{
    return m_Sigma;
}

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord1::SetOrientation( const EulerAngles & O )
{
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & EllipsoidRecord1::GetOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & EllipsoidRecord1::GetOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

KString EllipsoidRecord1::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tCentroid Location: " << m_CentLocation.GetAsString()
       << "\tSigma:   " << m_Sigma.GetAsString()
       << "\tOritantaion: " << m_Ori.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord1::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ELIPSOID_RECORD_1_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_CentLocation
           >> KDIS_STREAM m_Sigma
           >> KDIS_STREAM m_Ori;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EllipsoidRecord1::Encode() const
{
    KDataStream stream;

    EllipsoidRecord1::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EllipsoidRecord1::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_CentLocation
           << KDIS_STREAM m_Sigma
           << KDIS_STREAM m_Ori;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EllipsoidRecord1::operator == ( const EllipsoidRecord1 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) ) return false;
    if( m_CentLocation != Value.m_CentLocation )  return false;
    if( m_Sigma        != Value.m_Sigma )         return false;
    if( m_Ori          != Value.m_Ori )           return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EllipsoidRecord1::operator != ( const EllipsoidRecord1 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
