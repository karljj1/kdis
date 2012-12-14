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

#include "./LE_DeadReckoningParameter.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LE_DeadReckoningParameter::LE_DeadReckoningParameter( void ) :
    m_ui8DeadRecknoningAlgorithm( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

LE_DeadReckoningParameter::LE_DeadReckoningParameter( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LE_DeadReckoningParameter::LE_DeadReckoningParameter( DeadReckoningAlgorithm DRA, const LE_Vector8_3 & LinearAcceleration,
        const LE_Vector8_3 & AngularVelocity ) :
    m_ui8DeadRecknoningAlgorithm( DRA ),
    m_LinearAcceleration( LinearAcceleration ),
    m_AngularVelocity( AngularVelocity )
{
}

//////////////////////////////////////////////////////////////////////////

LE_DeadReckoningParameter::~LE_DeadReckoningParameter( void )
{
}

//////////////////////////////////////////////////////////////////////////

void LE_DeadReckoningParameter::SetDeadReckoningAlgorithm( DeadReckoningAlgorithm DRA )
{
    m_ui8DeadRecknoningAlgorithm = DRA;
}

//////////////////////////////////////////////////////////////////////////

DeadReckoningAlgorithm LE_DeadReckoningParameter::GetDeadReckoningAlgorithm() const
{
    return ( DeadReckoningAlgorithm )m_ui8DeadRecknoningAlgorithm;
}

//////////////////////////////////////////////////////////////////////////

void LE_DeadReckoningParameter::SetLinearAcceleration( const LE_Vector8_3 & LA )
{
    m_LinearAcceleration = LA;
}

//////////////////////////////////////////////////////////////////////////

const LE_Vector8_3 & LE_DeadReckoningParameter::GetLinearAcceleration() const
{
    return m_LinearAcceleration;
}

//////////////////////////////////////////////////////////////////////////

LE_Vector8_3 & LE_DeadReckoningParameter::GetLinearAcceleration()
{
    return m_LinearAcceleration;
}

//////////////////////////////////////////////////////////////////////////

void LE_DeadReckoningParameter::SetAngularVelocity( const LE_Vector8_3 & AV )
{
    m_AngularVelocity = AV;
}

//////////////////////////////////////////////////////////////////////////

const LE_Vector8_3 & LE_DeadReckoningParameter::GetAngularVelocity() const
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

LE_Vector8_3 & LE_DeadReckoningParameter::GetAngularVelocity()
{
    return m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

KString LE_DeadReckoningParameter::GetAsString() const
{
    KStringStream ss;

    ss << "LE Dead Reckoning Parameters:\n"
       << "\tAlgorithm:          "   << GetEnumAsStringDeadReckoningAlgorithm( m_ui8DeadRecknoningAlgorithm )
       << "\n\tLinear Acceleration: " << m_LinearAcceleration.GetAsString()
       << "\tAngular Velocity:    "   << m_AngularVelocity.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LE_DeadReckoningParameter::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LE_DEAD_RECKONING_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8DeadRecknoningAlgorithm
           >> KDIS_STREAM m_LinearAcceleration
           >> KDIS_STREAM m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LE_DeadReckoningParameter::Encode() const
{
    KDataStream stream;

    LE_DeadReckoningParameter::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LE_DeadReckoningParameter::Encode( KDataStream & stream ) const
{
    stream << m_ui8DeadRecknoningAlgorithm
           << KDIS_STREAM m_LinearAcceleration
           << KDIS_STREAM m_AngularVelocity;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_DeadReckoningParameter::operator == ( const LE_DeadReckoningParameter & Value ) const
{
    if( m_ui8DeadRecknoningAlgorithm    != Value.m_ui8DeadRecknoningAlgorithm ) return false;
    if( m_LinearAcceleration            != Value.m_LinearAcceleration )         return false;
    if( m_AngularVelocity               != Value.m_AngularVelocity )            return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_DeadReckoningParameter::operator != ( const LE_DeadReckoningParameter & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
