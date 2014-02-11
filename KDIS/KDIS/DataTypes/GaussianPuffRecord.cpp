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

#include "./GaussianPuffRecord.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

GaussianPuffRecord::GaussianPuffRecord() :
    m_f32CentHeight( 0 )
{
    m_ui32EnvRecTyp = GaussianPuffRecordType;
    m_ui16Length = ( GAUSSIAN_PUFF_RECORD_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

GaussianPuffRecord::GaussianPuffRecord( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GaussianPuffRecord::GaussianPuffRecord( KUINT8 Index, const WorldCoordinates & PuffLocation, const WorldCoordinates & OriginationLocation,
                                        const Vector & Sigma, const Vector & DDT, const EulerAngles & Orientation, const Vector & Velocity,
                                        const Vector & AngularVelocity, KFLOAT32 CentroidHeight ) :
    m_PuffLocation( PuffLocation ),
    m_OrigLocation( OriginationLocation ),
    m_Sigma( Sigma ),
    m_DDTSigma( DDT ),
    m_Ori( Orientation ),
    m_Velocity( Velocity ),
    m_AngularVelocity( AngularVelocity ),
    m_f32CentHeight( CentroidHeight )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = GaussianPuffRecordType;
    m_ui16Length = ( GAUSSIAN_PUFF_RECORD_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

GaussianPuffRecord::~GaussianPuffRecord()
{
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::SetPuffLocation( const WorldCoordinates & L )
{
    m_PuffLocation = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & GaussianPuffRecord::GetPuffLocation() const
{
    return m_PuffLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & GaussianPuffRecord::GetPuffLocation()
{
    return m_PuffLocation;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::SetOriginationLocation( const WorldCoordinates & L )
{
    m_OrigLocation = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & GaussianPuffRecord::GetOriginationLocation() const
{
    return m_OrigLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & GaussianPuffRecord::GetOriginationLocation()
{
    return m_OrigLocation;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::SetSigma( const Vector & S )
{
    m_Sigma = S;
}

//////////////////////////////////////////////////////////////////////////

const Vector & GaussianPuffRecord::GetSigma() const
{
    return m_Sigma;
}

//////////////////////////////////////////////////////////////////////////

Vector & GaussianPuffRecord::GetSigma()
{
    return m_Sigma;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::SetDOverDtSigma( const Vector & S )
{
    m_DDTSigma = S;
}

//////////////////////////////////////////////////////////////////////////

const Vector & GaussianPuffRecord::GetDOverDtSigma() const
{
    return m_DDTSigma;
}

//////////////////////////////////////////////////////////////////////////

Vector & GaussianPuffRecord::GetDOverDtSigma()
{
    return m_DDTSigma;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::SetOrientation( const EulerAngles & O )
{
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & GaussianPuffRecord::GetOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & GaussianPuffRecord::GetOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::SetVelocity( const Vector & V )
{
    m_Velocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & GaussianPuffRecord::GetVelocity() const
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & GaussianPuffRecord::GetVelocity()
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::SetAngularVelocity( const Vector & V )
{
    m_AngularVelocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & GaussianPuffRecord::GetAngularVelocity() const
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & GaussianPuffRecord::GetAngularVelocity()
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::SetCentroidHeight( KFLOAT32 H )
{
    m_f32CentHeight = H;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 GaussianPuffRecord::GetCentroidHeight() const
{
    return m_f32CentHeight;
}

//////////////////////////////////////////////////////////////////////////

KString GaussianPuffRecord::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tPuff Location:        " << m_PuffLocation.GetAsString()
       << "\tOrigination Location: " << m_OrigLocation.GetAsString()
       << "\tSigma:                " << m_Sigma.GetAsString()
       << "\td(Sigma)/dt:          " << m_DDTSigma.GetAsString()
       << "\tOrientation:          " << m_Ori.GetAsString()
       << "\tVelocity:             " << m_Velocity.GetAsString()
       << "\tAngualr Velocity:     " << m_AngularVelocity.GetAsString()
       << "\tCentroid Height:      " << m_f32CentHeight << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GAUSSIAN_PUFF_RECORD_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_PuffLocation
           >> KDIS_STREAM m_OrigLocation
           >> KDIS_STREAM m_Sigma
           >> KDIS_STREAM m_DDTSigma
           >> KDIS_STREAM m_Ori
           >> KDIS_STREAM m_Velocity
           >> KDIS_STREAM m_AngularVelocity
           >> m_f32CentHeight;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GaussianPuffRecord::Encode() const
{
    KDataStream stream;

    GaussianPuffRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPuffRecord::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_PuffLocation
           << KDIS_STREAM m_OrigLocation
           << KDIS_STREAM m_Sigma
           << KDIS_STREAM m_DDTSigma
           << KDIS_STREAM m_Ori
           << KDIS_STREAM m_Velocity
           << KDIS_STREAM m_AngularVelocity
           << m_f32CentHeight;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GaussianPuffRecord::operator == ( const GaussianPuffRecord & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) )       return false;
    if( m_PuffLocation     != Value.m_PuffLocation )    return false;
    if( m_OrigLocation     != Value.m_OrigLocation )    return false;
    if( m_Sigma            != Value.m_Sigma )           return false;
    if( m_DDTSigma         != Value.m_DDTSigma )        return false;
    if( m_Ori              != Value.m_Ori )             return false;
    if( m_Velocity         != Value.m_Velocity )        return false;
    if( m_AngularVelocity  != Value.m_AngularVelocity ) return false;
    if( m_f32CentHeight    != Value.m_f32CentHeight )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GaussianPuffRecord::operator != ( const GaussianPuffRecord & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

