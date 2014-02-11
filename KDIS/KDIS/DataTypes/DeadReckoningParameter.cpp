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

#include "./DeadReckoningParameter.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

DeadReckoningParameter::DeadReckoningParameter() :
    m_ui8DeadRecknoningAlgorithm( 0 )
{
    memset( m_OtherParams, 0, 15 );
}

//////////////////////////////////////////////////////////////////////////

DeadReckoningParameter::DeadReckoningParameter( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

DeadReckoningParameter::DeadReckoningParameter( DeadReckoningAlgorithm DRA, const Vector & LinearAcceleration,
        const Vector & AngularVelocity ) :
    m_ui8DeadRecknoningAlgorithm( DRA ),
    m_LinearAcceleration( LinearAcceleration ),
    m_AngularVelocity( AngularVelocity )
{
    memset( m_OtherParams, 0, 15 );
}

//////////////////////////////////////////////////////////////////////////

DeadReckoningParameter::~DeadReckoningParameter()
{
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningParameter::SetDeadReckoningAlgorithm( DeadReckoningAlgorithm DRA )
{
    m_ui8DeadRecknoningAlgorithm = DRA;
}

//////////////////////////////////////////////////////////////////////////

DeadReckoningAlgorithm DeadReckoningParameter::GetDeadReckoningAlgorithm() const
{
    return ( DeadReckoningAlgorithm )m_ui8DeadRecknoningAlgorithm;
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningParameter::SetLinearAcceleration( const Vector & LA )
{
    m_LinearAcceleration = LA;
}

//////////////////////////////////////////////////////////////////////////

const Vector & DeadReckoningParameter::GetLinearAcceleration() const
{
    return m_LinearAcceleration;
}

//////////////////////////////////////////////////////////////////////////

Vector & DeadReckoningParameter::GetLinearAcceleration()
{
    return m_LinearAcceleration;
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningParameter::SetAngularVelocity( const Vector & AV )
{
    m_AngularVelocity = AV;
}

//////////////////////////////////////////////////////////////////////////

const Vector & DeadReckoningParameter::GetAngularVelocity() const
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & DeadReckoningParameter::GetAngularVelocity()
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////


KString DeadReckoningParameter::GetAsString() const
{
    KStringStream ss;

    ss << "Dead Reckoning Parameters:\n"
       << "\tAlgorithm:            "   << GetEnumAsStringDeadReckoningAlgorithm( m_ui8DeadRecknoningAlgorithm )
       << "\n\tLinear Acceleration:  " << m_LinearAcceleration.GetAsString()
       << "\tAngular Velocity:     "   << m_AngularVelocity.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningParameter::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < DEAD_RECKONING_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8DeadRecknoningAlgorithm;

    for( KUINT16 i = 0; i < 15; ++i )
    {
        stream >> m_OtherParams[i];
    }

    stream >> KDIS_STREAM m_LinearAcceleration
           >> KDIS_STREAM m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

KDataStream DeadReckoningParameter::Encode() const
{
    KDataStream stream;

    DeadReckoningParameter::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void DeadReckoningParameter::Encode( KDataStream & stream ) const
{
    stream << m_ui8DeadRecknoningAlgorithm;

    for( KUINT16 i = 0; i < 15; ++i )
    {
        stream << m_OtherParams[i];
    }

    stream << KDIS_STREAM m_LinearAcceleration
           << KDIS_STREAM m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

KBOOL DeadReckoningParameter::operator == ( const DeadReckoningParameter & Value ) const
{
    if( m_ui8DeadRecknoningAlgorithm    != Value.m_ui8DeadRecknoningAlgorithm ) return false;
    if( m_LinearAcceleration            != Value.m_LinearAcceleration )         return false;
    if( m_AngularVelocity               != Value.m_AngularVelocity )            return false;
    if( memcmp( m_OtherParams, Value.m_OtherParams, 15 ) != 0 )                 return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL DeadReckoningParameter::operator != ( const DeadReckoningParameter & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

void KDIS::DATA_TYPE::DeadReckoningParameter::SetQuatAxis( const Vector & QA )
{
    KFLOAT32 &x = *reinterpret_cast<KFLOAT32*>(&m_OtherParams[0]);
    KFLOAT32 &y = *reinterpret_cast<KFLOAT32*>(&m_OtherParams[0+sizeof(KFLOAT32)]);
    KFLOAT32 &z = *reinterpret_cast<KFLOAT32*>(&m_OtherParams[0+sizeof(KFLOAT32)*2]);

    x = QA.GetX();
    y = QA.GetY();
    z = QA.GetZ();
}

const Vector KDIS::DATA_TYPE::DeadReckoningParameter::GetQuatAxis() const
{
    const KFLOAT32 &x = *reinterpret_cast<const KFLOAT32*>(&m_OtherParams[0]);
    const KFLOAT32 &y = *reinterpret_cast<const KFLOAT32*>(&m_OtherParams[0+sizeof(KFLOAT32)]);
    const KFLOAT32 &z = *reinterpret_cast<const KFLOAT32*>(&m_OtherParams[0+sizeof(KFLOAT32)*2]);

    return Vector(x,y,z);
}

Vector KDIS::DATA_TYPE::DeadReckoningParameter::GetQuatAxis()
{
    const KFLOAT32 &x = *reinterpret_cast<const KFLOAT32*>(&m_OtherParams[0]);
    const KFLOAT32 &y = *reinterpret_cast<const KFLOAT32*>(&m_OtherParams[0+sizeof(KFLOAT32)]);
    const KFLOAT32 &z = *reinterpret_cast<const KFLOAT32*>(&m_OtherParams[0+sizeof(KFLOAT32)*2]);

    return Vector(x,y,z);
}
