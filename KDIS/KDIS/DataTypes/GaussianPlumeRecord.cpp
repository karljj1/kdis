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

#include "./GaussianPlumeRecord.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

GaussianPlumeRecord::GaussianPlumeRecord() :
    m_ui32Padding( 0 )
{
    m_ui32EnvRecTyp = GaussianPlumeRecordType;
    m_ui16Length = ( GAUSSIAN_PLUME_RECORD_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

GaussianPlumeRecord::GaussianPlumeRecord( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GaussianPlumeRecord::~GaussianPlumeRecord()
{
}

//////////////////////////////////////////////////////////////////////////

GaussianPlumeRecord::GaussianPlumeRecord( KUINT8 Index, const WorldCoordinates & Location, const EulerAngles & Orientation,
        const Vector & LWH, const Vector & DDT, KFLOAT32 LECH, const Vector & LEV ) :
    m_SrcLocation( Location ),
    m_Ori( Orientation ),
    m_PlumeLWH( LWH ),
    m_DDTLEH( DDT ),
    m_f32LdEdgeCenHght( LECH ),
    m_LdEdgeVel( LEV ),
    m_ui32Padding( 0 )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = GaussianPlumeRecordType;
    m_ui16Length = ( GAUSSIAN_PLUME_RECORD_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPlumeRecord::SetSourceLocation( const WorldCoordinates & L )
{
    m_SrcLocation = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & GaussianPlumeRecord::GetSourceLocation() const
{
    return m_SrcLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & GaussianPlumeRecord::GetSourceLocation()
{
    return m_SrcLocation;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPlumeRecord::SetOrientation( const EulerAngles & O )
{
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & GaussianPlumeRecord::GetOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & GaussianPlumeRecord::GetOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPlumeRecord::SetPlumeLengthWidthHeight( const Vector & LWH )
{
    m_PlumeLWH = LWH;
}

//////////////////////////////////////////////////////////////////////////

const Vector & GaussianPlumeRecord::GetPlumeLengthWidthHeight() const
{
    return m_PlumeLWH;
}

//////////////////////////////////////////////////////////////////////////

Vector & GaussianPlumeRecord::GetPlumeLengthWidthHeight()
{
    return m_PlumeLWH;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPlumeRecord::SetDOverDtLengthWidthHeight( const Vector & DDT )
{
    m_DDTLEH = DDT;
}

//////////////////////////////////////////////////////////////////////////

const Vector & GaussianPlumeRecord::GetDOverDtLengthWidthHeight() const
{
    return m_DDTLEH;
}

//////////////////////////////////////////////////////////////////////////

Vector & GaussianPlumeRecord::GetDOverDtLengthWidthHeight()
{
    return m_DDTLEH;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPlumeRecord::SetLeadingEdgeCentroidHeight( KFLOAT32 LECH )
{
    m_f32LdEdgeCenHght = LECH;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 GaussianPlumeRecord::GetLeadingEdgeCentroidHeight() const
{
    return m_f32LdEdgeCenHght;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPlumeRecord::SetLeadingEdgeVelocity( const Vector & LEV )
{
    m_LdEdgeVel = LEV;
}

//////////////////////////////////////////////////////////////////////////

const Vector & GaussianPlumeRecord::GetLeadingEdgeVelocity() const
{
    return m_LdEdgeVel;
}

//////////////////////////////////////////////////////////////////////////

Vector & GaussianPlumeRecord::GetLeadingEdgeVelocity()
{
    return m_LdEdgeVel;
}

//////////////////////////////////////////////////////////////////////////

KString GaussianPlumeRecord::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tLocation:                     " << m_SrcLocation.GetAsString()
       << "\tOrientation:                  " << m_Ori.GetAsString()
       << "\tPlume Length, Width, Height:  " << m_PlumeLWH.GetAsString()
       << "\td/dt:                         " << m_DDTLEH.GetAsString()
       << "\tLeading Edge Centroid Height: " << m_f32LdEdgeCenHght << "\n"
       << "\tLeading Edge Velocity:        " << m_LdEdgeVel.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GaussianPlumeRecord::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GAUSSIAN_PLUME_RECORD_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_SrcLocation
           >> KDIS_STREAM m_Ori
           >> KDIS_STREAM m_PlumeLWH
           >> KDIS_STREAM m_DDTLEH
           >> m_f32LdEdgeCenHght
           >> KDIS_STREAM m_LdEdgeVel
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GaussianPlumeRecord::Encode() const
{
    KDataStream stream;

    GaussianPlumeRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GaussianPlumeRecord::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_SrcLocation
           << KDIS_STREAM m_Ori
           << KDIS_STREAM m_PlumeLWH
           << KDIS_STREAM m_DDTLEH
           << m_f32LdEdgeCenHght
           << KDIS_STREAM m_LdEdgeVel
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GaussianPlumeRecord::operator == ( const GaussianPlumeRecord & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) )           return false;
    if( m_SrcLocation       != Value.m_SrcLocation )        return false;
    if( m_Ori               != Value.m_Ori )                return false;
    if( m_PlumeLWH          != Value.m_PlumeLWH )           return false;
    if( m_DDTLEH            != Value.m_DDTLEH )             return false;
    if( m_SrcLocation       != Value.m_SrcLocation )        return false;
    if( m_f32LdEdgeCenHght  != Value.m_f32LdEdgeCenHght )   return false;
    if( m_LdEdgeVel         != Value.m_LdEdgeVel )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GaussianPlumeRecord::operator != ( const GaussianPlumeRecord & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

