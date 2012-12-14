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

#include "./VectoringNozzleSystem.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

VectoringNozzleSystem::VectoringNozzleSystem( void ) :
    m_f32HDeflAngle( 0 ),
    m_f32VDeflAngle( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

VectoringNozzleSystem::VectoringNozzleSystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

VectoringNozzleSystem::VectoringNozzleSystem( KFLOAT32 HorizontalDeflectionAngle, KFLOAT32 VerticalDeflectionAngle ) :
    m_f32HDeflAngle( HorizontalDeflectionAngle ),
    m_f32VDeflAngle( VerticalDeflectionAngle )
{
}

//////////////////////////////////////////////////////////////////////////

VectoringNozzleSystem::~VectoringNozzleSystem( void )
{
}

//////////////////////////////////////////////////////////////////////////

void VectoringNozzleSystem::SetHorizontalDeflectionAngle( KFLOAT32 HDA )
{
    m_f32HDeflAngle = HDA;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 VectoringNozzleSystem::GetHorizontalDeflectionAngle() const
{
    return m_f32HDeflAngle;
}

//////////////////////////////////////////////////////////////////////////

void VectoringNozzleSystem::SetVerticalDeflectionAngle( KFLOAT32 VDA )
{
    m_f32VDeflAngle = VDA;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 VectoringNozzleSystem::GetVerticalDeflectionAngle() const
{
    return m_f32VDeflAngle;
}

//////////////////////////////////////////////////////////////////////////

KString VectoringNozzleSystem::GetAsString() const
{
    KStringStream ss;

    ss << "Vectoring Nozzle System:"
       << "\n\tHorizontal Deflection Angle: " << m_f32HDeflAngle
       << "\n\tVertical Deflection Angle:   " << m_f32VDeflAngle
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void VectoringNozzleSystem::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < VECTORING_NOZZLE_SYSTEM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f32HDeflAngle
           >> m_f32VDeflAngle;
}

//////////////////////////////////////////////////////////////////////////

KDataStream VectoringNozzleSystem::Encode() const
{
    KDataStream stream;

    VectoringNozzleSystem::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void VectoringNozzleSystem::Encode( KDataStream & stream ) const
{
    stream << m_f32HDeflAngle
           << m_f32VDeflAngle;
}

//////////////////////////////////////////////////////////////////////////

KBOOL VectoringNozzleSystem::operator == ( const VectoringNozzleSystem & Value ) const
{
    if( m_f32HDeflAngle != Value.m_f32HDeflAngle ) return false;
    if( m_f32VDeflAngle != Value.m_f32VDeflAngle ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL VectoringNozzleSystem::operator != ( const VectoringNozzleSystem & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
