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

#include "./VectoringNozzleSystem.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

VectoringNozzleSystem::VectoringNozzleSystem() :
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

VectoringNozzleSystem::~VectoringNozzleSystem()
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
