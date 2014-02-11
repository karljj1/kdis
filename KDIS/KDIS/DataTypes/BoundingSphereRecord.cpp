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

#include "./BoundingSphereRecord.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

BoundingSphereRecord::BoundingSphereRecord() :
    m_f32Rad( 0 ),
    m_ui32Padding( 0 )
{
    m_ui32EnvRecTyp = BoundingSphereRecordType;
    m_ui16Length = ( BOUNDING_SPHERE_RECORD_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

BoundingSphereRecord::BoundingSphereRecord( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

BoundingSphereRecord::BoundingSphereRecord( KUINT8 Index, const WorldCoordinates & CentroidLocation, KFLOAT32 Radius ) :
    m_CentLocation( CentroidLocation ),
    m_f32Rad( Radius ),
    m_ui32Padding( 0 )
{
    m_ui8Index = Index;
    m_ui32EnvRecTyp = BoundingSphereRecordType;
    m_ui16Length = ( BOUNDING_SPHERE_RECORD_SIZE - ENVIRONMENT_RECORD_SIZE ) * 8;
}

//////////////////////////////////////////////////////////////////////////

BoundingSphereRecord::~BoundingSphereRecord()
{
}

//////////////////////////////////////////////////////////////////////////

void BoundingSphereRecord::SetCentroidLocation( const WorldCoordinates & CL )
{
    m_CentLocation = CL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & BoundingSphereRecord::GetCentroidLocation() const
{
    return m_CentLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & BoundingSphereRecord::GetCentroidLocation()
{
    return m_CentLocation;
}

//////////////////////////////////////////////////////////////////////////

void BoundingSphereRecord::SetRadius( KFLOAT32 R )
{
    m_f32Rad = R;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 BoundingSphereRecord::GetRadius() const
{
    return m_f32Rad;
}

//////////////////////////////////////////////////////////////////////////

KString BoundingSphereRecord::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tCentroid Location: " <<  m_CentLocation.GetAsString()
       << "\tRadius:   "          <<  m_f32Rad << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void BoundingSphereRecord::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < BOUNDING_SPHERE_RECORD_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_CentLocation
           >> m_f32Rad
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream BoundingSphereRecord::Encode() const
{
    KDataStream stream;

    BoundingSphereRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void BoundingSphereRecord::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_CentLocation
           << m_f32Rad
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BoundingSphereRecord::operator == ( const BoundingSphereRecord & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) ) return false;
    if( m_CentLocation != Value.m_CentLocation )  return false;
    if( m_f32Rad       != Value.m_f32Rad )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BoundingSphereRecord::operator != ( const BoundingSphereRecord & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
