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

#include "./GaussianPuffRecord.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

GaussianPuffRecord::GaussianPuffRecord( void ) :
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

GaussianPuffRecord::~GaussianPuffRecord( void )
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

