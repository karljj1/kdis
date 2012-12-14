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

#include "./DeadReckoningParameter.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

DeadReckoningParameter::DeadReckoningParameter( void ) :
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

DeadReckoningParameter::~DeadReckoningParameter( void )
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
