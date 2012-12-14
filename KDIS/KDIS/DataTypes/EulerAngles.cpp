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

#include "./EulerAngles.h"
#include "./../Extras/KUtils.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EulerAngles::EulerAngles( void ) :
    m_f32Psi( 0 ),
    m_f32Theta( 0 ),
    m_f32Phi( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

EulerAngles::EulerAngles( KFLOAT32 Psi, KFLOAT32 Theta, KFLOAT32 Phi ) :
    m_f32Psi( Psi ),
    m_f32Theta( Theta ),
    m_f32Phi( Phi )
{
}

//////////////////////////////////////////////////////////////////////////

EulerAngles::EulerAngles( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EulerAngles::~EulerAngles( void )
{
}

//////////////////////////////////////////////////////////////////////////

void EulerAngles::SetPsiInRadians( KFLOAT32 Psi )
{
    m_f32Psi = Psi;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 EulerAngles::GetPsiInRadians() const
{
    return m_f32Psi;
}

//////////////////////////////////////////////////////////////////////////

void EulerAngles::SetPsiInDegrees( KFLOAT32 Psi )
{
    m_f32Psi = DegToRad( Psi );
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 EulerAngles::GetPsiInDegrees() const
{
    return RadToDeg( m_f32Psi );
}

//////////////////////////////////////////////////////////////////////////

void EulerAngles::SetThetaInRadians( KFLOAT32 Theta )
{
    m_f32Theta = Theta;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 EulerAngles::GetThetaInRadians() const
{
    return m_f32Theta;
}

//////////////////////////////////////////////////////////////////////////

void EulerAngles::SetThetaInDegrees( KFLOAT32 Theta )
{
    m_f32Theta = DegToRad( Theta );
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 EulerAngles::GetThetaInDegrees() const
{
    return RadToDeg( m_f32Theta );
}

//////////////////////////////////////////////////////////////////////////

void EulerAngles::SetPhiInRadians( KFLOAT32 Phi )
{
    m_f32Phi = Phi;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 EulerAngles::GetPhiInRadians() const
{
    return m_f32Phi;
}

//////////////////////////////////////////////////////////////////////////

void EulerAngles::SetPhiInDegrees( KFLOAT32 Phi )
{
    m_f32Phi = DegToRad( Phi );
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 EulerAngles::GetPhiInDegrees() const
{
    return RadToDeg( m_f32Phi );
}

//////////////////////////////////////////////////////////////////////////

KString EulerAngles::GetAsString() const
{
    KStringStream ss;

    ss << "Psi: "       << m_f32Psi
       << ",  Theta: "  << m_f32Theta
       << ",  Phi: "    << m_f32Phi << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EulerAngles::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < EULER_ANGLES_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f32Psi
           >> m_f32Theta
           >> m_f32Phi;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EulerAngles::Encode() const
{
    KDataStream stream;

    EulerAngles::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EulerAngles::Encode( KDataStream & stream ) const
{
    stream << m_f32Psi
           << m_f32Theta
           << m_f32Phi;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EulerAngles::operator == ( const EulerAngles & Value ) const
{
    if( m_f32Psi    != Value.m_f32Psi )     return false;
    if( m_f32Theta  != Value.m_f32Theta )   return false;
    if( m_f32Phi    != Value.m_f32Phi )     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EulerAngles::operator != ( const EulerAngles & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

EulerAngles EulerAngles::operator * ( const EulerAngles & Value ) const
{
    EulerAngles tmp = *this;
    tmp.m_f32Psi   *= Value.m_f32Psi;
    tmp.m_f32Theta *= Value.m_f32Theta;
    tmp.m_f32Phi   *= Value.m_f32Phi;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles KDIS::DATA_TYPE::EulerAngles::operator * ( KFLOAT64 Value ) const
{
    EulerAngles tmp = *this;
    tmp.m_f32Psi   *= Value;
    tmp.m_f32Theta *= Value;
    tmp.m_f32Phi   *= Value;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles EulerAngles::operator+( const EulerAngles & Value ) const
{
    EulerAngles tmp = *this;
    tmp.m_f32Psi   += Value.m_f32Psi;
    tmp.m_f32Theta += Value.m_f32Theta;
    tmp.m_f32Phi   += Value.m_f32Phi;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & EulerAngles::operator += ( const EulerAngles & Value )
{
    m_f32Psi   += Value.m_f32Psi;
    m_f32Theta += Value.m_f32Theta;
    m_f32Phi   += Value.m_f32Phi;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles EulerAngles::operator - ( const EulerAngles & Value ) const
{
    EulerAngles tmp = *this;
    tmp.m_f32Psi   -= Value.m_f32Psi;
    tmp.m_f32Theta -= Value.m_f32Theta;
    tmp.m_f32Phi   -= Value.m_f32Phi;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & EulerAngles::operator -= ( const EulerAngles & Value )
{
    m_f32Psi   -= Value.m_f32Psi;
    m_f32Theta -= Value.m_f32Theta;
    m_f32Phi   -= Value.m_f32Phi;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 & EulerAngles::operator [] ( KUINT16 i ) throw( KException )
{
    switch( i )
    {
    case 0:
        return m_f32Psi;
    case 1:
        return m_f32Theta;
    case 2:
        return m_f32Phi;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////

const KFLOAT32 & EulerAngles::operator [] ( KUINT16 i ) const throw( KException )
{
    switch( i )
    {
    case 0:
        return m_f32Psi;
    case 1:
        return m_f32Theta;
    case 2:
        return m_f32Phi;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////
