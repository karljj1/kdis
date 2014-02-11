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

#include "./LE_EulerAngles.h"
#include "./../Extras/KUtils.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LE_EulerAngles::LE_EulerAngles()
{
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles::LE_EulerAngles( KFIXED8_3 Psi, KFIXED8_3 Theta, KFIXED8_3 Phi ) :
    m_Psi( Psi ),
    m_Theta( Theta ),
    m_Phi( Phi )
{
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles::LE_EulerAngles( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles::~LE_EulerAngles()
{
}

//////////////////////////////////////////////////////////////////////////

void LE_EulerAngles::SetPsiInRadians( KFIXED8_3 Psi )
{
    m_Psi = Psi;
}

//////////////////////////////////////////////////////////////////////////

KFIXED8_3 LE_EulerAngles::GetPsiInRadians() const
{
    return m_Psi;
}

//////////////////////////////////////////////////////////////////////////

void LE_EulerAngles::SetPsiInDegrees( KFIXED8_3 Psi )
{
    m_Psi = DegToRad( Psi );
}

//////////////////////////////////////////////////////////////////////////

KFIXED8_3 LE_EulerAngles::GetPsiInDegrees() const
{
    return RadToDeg( m_Psi );
}

//////////////////////////////////////////////////////////////////////////

void LE_EulerAngles::SetThetaInRadians( KFIXED8_3 Theta )
{
    m_Theta = Theta;
}

//////////////////////////////////////////////////////////////////////////

KFIXED8_3 LE_EulerAngles::GetThetaInRadians() const
{
    return m_Theta;
}

//////////////////////////////////////////////////////////////////////////

void LE_EulerAngles::SetThetaInDegrees( KFIXED8_3 Theta )
{
    m_Theta = DegToRad( Theta );
}

//////////////////////////////////////////////////////////////////////////

KFIXED8_3 LE_EulerAngles::GetThetaInDegrees() const
{
    return RadToDeg( m_Theta );
}

//////////////////////////////////////////////////////////////////////////

void LE_EulerAngles::SetPhiInRadians( KFIXED8_3 Phi )
{
    m_Phi = Phi;
}

//////////////////////////////////////////////////////////////////////////

KFIXED8_3 LE_EulerAngles::GetPhiInRadians() const
{
    return m_Phi;
}

//////////////////////////////////////////////////////////////////////////

void LE_EulerAngles::SetPhiInDegrees( KFIXED8_3 Phi )
{
    m_Phi = DegToRad( Phi );
}

//////////////////////////////////////////////////////////////////////////

KFIXED8_3 LE_EulerAngles::GetPhiInDegrees() const
{
    return RadToDeg( m_Phi );
}

//////////////////////////////////////////////////////////////////////////

KString LE_EulerAngles::GetAsString() const
{
    KStringStream ss;

    ss << "Psi: "       << m_Psi.GetAsFloat32()
       << ",  Theta: "  << m_Theta.GetAsFloat32()
       << ",  Phi: "    << m_Phi.GetAsFloat32() << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LE_EulerAngles::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LE_EULER_ANGLES_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> KDIS_STREAM m_Psi
           >> KDIS_STREAM m_Theta
           >> KDIS_STREAM m_Phi;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LE_EulerAngles::Encode() const
{
    KDataStream stream;

    LE_EulerAngles::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LE_EulerAngles::Encode( KDataStream & stream ) const
{
    stream << KDIS_STREAM m_Psi
           << KDIS_STREAM m_Theta
           << KDIS_STREAM m_Phi;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_EulerAngles::operator == ( const LE_EulerAngles & Value ) const
{
    if( m_Psi    != Value.m_Psi )     return false;
    if( m_Theta  != Value.m_Theta )   return false;
    if( m_Phi    != Value.m_Phi )     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_EulerAngles::operator != ( const LE_EulerAngles & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles LE_EulerAngles::operator * ( const LE_EulerAngles & Value ) const
{
    LE_EulerAngles tmp = *this;
    tmp.m_Psi   = tmp.m_Psi * Value.m_Psi;
    tmp.m_Theta = tmp.m_Theta * Value.m_Theta;
    tmp.m_Phi   = tmp.m_Phi * Value.m_Phi;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles KDIS::DATA_TYPE::LE_EulerAngles::operator * ( KFLOAT64 Value ) const
{
    LE_EulerAngles tmp = *this;
    tmp.m_Psi   = tmp.m_Psi * Value;
    tmp.m_Theta = tmp.m_Theta * Value;
    tmp.m_Phi   = tmp.m_Phi * Value;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles LE_EulerAngles::operator+( const LE_EulerAngles & Value ) const
{
    LE_EulerAngles tmp = *this;
    tmp.m_Psi   = tmp.m_Psi + Value.m_Psi;
    tmp.m_Theta = tmp.m_Theta + Value.m_Theta;
    tmp.m_Phi   = tmp.m_Phi + Value.m_Phi;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles & LE_EulerAngles::operator += ( const LE_EulerAngles & Value )
{
    m_Psi   = m_Psi + Value.m_Psi;
    m_Theta = m_Theta + Value.m_Theta;
    m_Phi   = m_Phi + Value.m_Phi;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles LE_EulerAngles::operator - ( const LE_EulerAngles & Value ) const
{
    LE_EulerAngles tmp = *this;
    tmp.m_Psi   = tmp.m_Psi - Value.m_Psi;
    tmp.m_Theta = tmp.m_Theta - Value.m_Theta;
    tmp.m_Phi   = tmp.m_Phi - Value.m_Phi;
    return tmp;
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles & LE_EulerAngles::operator -= ( const LE_EulerAngles & Value )
{
    m_Psi   = m_Psi - Value.m_Psi;
    m_Theta = m_Theta - Value.m_Theta;
    m_Phi   = m_Phi - Value.m_Phi;
    return *this;
}

//////////////////////////////////////////////////////////////////////////

KFIXED8_3 & LE_EulerAngles::operator [] ( KUINT16 i ) throw( KException )
{
    switch( i )
    {
    case 0:
        return m_Psi;
    case 1:
        return m_Theta;
    case 2:
        return m_Phi;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////

const KFIXED8_3 & LE_EulerAngles::operator [] ( KUINT16 i ) const throw( KException )
{
    switch( i )
    {
    case 0:
        return m_Psi;
    case 1:
        return m_Theta;
    case 2:
        return m_Phi;
    default:
        throw KException( __FUNCTION__, OUT_OF_BOUNDS );
    }
}

//////////////////////////////////////////////////////////////////////////
