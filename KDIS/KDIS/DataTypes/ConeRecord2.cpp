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

#include "./ConeRecord2.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ConeRecord2::ConeRecord2( void ) :
    m_f32ddtHeight( 0 ),
    m_f32ddtPeak( 0 )
{
    m_ui32EnvRecTyp = ConeRecord2Type;
    m_ui16Length = CONE_RECORD_2_SIZE * 8;
}

//////////////////////////////////////////////////////////////////////////

ConeRecord2::ConeRecord2( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ConeRecord2::ConeRecord2( KUINT8 Index, const WorldCoordinates & VertexLocation, const EulerAngles & Orientation,
                          const Vector & Velocity, const Vector & AngularVelocity, KFLOAT32 Height,
                          KFLOAT32 PeakAngle, KFLOAT32 DHeightOverDt, KFLOAT32 DPeakAngleOverDt ) :
    ConeRecord1( Index, VertexLocation, Orientation, Height, PeakAngle ),
    m_Velocity( Velocity ),
    m_AngularVelocity( AngularVelocity ),
    m_f32ddtHeight( DHeightOverDt ),
    m_f32ddtPeak( DPeakAngleOverDt )
{
    m_ui32EnvRecTyp = ConeRecord2Type;
    m_ui16Length = CONE_RECORD_2_SIZE * 8;
}

//////////////////////////////////////////////////////////////////////////

ConeRecord2::~ConeRecord2( void )
{
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::SetVelocity( const Vector & V )
{
    m_Velocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & ConeRecord2::GetVelocity() const
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & ConeRecord2::GetVelocity()
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::SetAngularVelocity( const Vector & V )
{
    m_AngularVelocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & ConeRecord2::GetAngularVelocity() const
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & ConeRecord2::GetAngularVelocity()
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::SetDHeightOverDt( KFLOAT32 DDT )
{
    m_f32ddtHeight = DDT;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 ConeRecord2::GetDHeightOverDt() const
{
    return m_f32ddtHeight;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::SetDPeakAngleOverDt( KFLOAT32 DDT )
{
    m_f32ddtPeak = DDT;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 ConeRecord2::GetDPeakAngleOverDt() const
{
    return m_f32ddtPeak;
}

//////////////////////////////////////////////////////////////////////////

KString ConeRecord2::GetAsString() const
{
    KStringStream ss;

    ss << EnvironmentRecord::GetAsString()
       << "\tVertex Location: "  << m_Loc.GetAsString()
       << "\tOritantaion: "      << m_Ori.GetAsString()
       << "\tVelocity: "         << m_Velocity.GetAsString()
       << "\tAngular Velocity: " << m_AngularVelocity.GetAsString()
       << "\tHeight: "           << m_f32Height         << "\n"
       << "\td(Height)/dt: "     << m_f32ddtHeight      << "\n"
       << "\tPeak Angle: "       << m_f32PeakAngle      << "\n"
       << "\td(Peak Angle)/dt: " << m_f32ddtPeak        << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < CONE_RECORD_2_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32EnvRecTyp
           >> m_ui16Length
           >> m_ui8Index
           >> m_ui8Padding
           >> KDIS_STREAM m_Loc
           >> KDIS_STREAM m_Ori
           >> KDIS_STREAM m_Velocity
           >> KDIS_STREAM m_AngularVelocity
           >> m_f32Height
           >> m_f32ddtHeight
           >> m_f32PeakAngle
           >> m_f32ddtPeak
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ConeRecord2::Encode() const
{
    KDataStream stream;

    ConeRecord2::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ConeRecord2::Encode( KDataStream & stream ) const
{
    stream << m_ui32EnvRecTyp
           << m_ui16Length
           << m_ui8Index
           << m_ui8Padding
           << KDIS_STREAM m_Loc
           << KDIS_STREAM m_Ori
           << KDIS_STREAM m_Velocity
           << KDIS_STREAM m_AngularVelocity
           << m_f32Height
           << m_f32ddtHeight
           << m_f32PeakAngle
           << m_f32ddtPeak
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ConeRecord2::operator == ( const ConeRecord2 & Value )const
{
    if( EnvironmentRecord::operator !=( Value ) )         return false;
    if( m_Loc               != Value.m_Loc )              return false;
    if( m_Ori               != Value.m_Ori )              return false;
    if( m_Velocity          != Value.m_Velocity )         return false;
    if( m_AngularVelocity   != Value.m_AngularVelocity )  return false;
    if( m_f32Height         != Value.m_f32Height )        return false;
    if( m_f32ddtHeight      != Value.m_f32ddtHeight )     return false;
    if( m_f32PeakAngle      != Value.m_f32PeakAngle )     return false;
    if( m_f32ddtPeak        != Value.m_f32ddtPeak )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ConeRecord2::operator != ( const ConeRecord2 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
