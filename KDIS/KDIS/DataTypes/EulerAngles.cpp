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

#include "./EulerAngles.h"
#include "./../Extras/KUtils.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EulerAngles::EulerAngles() :
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

EulerAngles::~EulerAngles()
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
