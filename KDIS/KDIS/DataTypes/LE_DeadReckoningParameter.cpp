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

#include "./LE_DeadReckoningParameter.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LE_DeadReckoningParameter::LE_DeadReckoningParameter() :
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

LE_DeadReckoningParameter::~LE_DeadReckoningParameter()
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
