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

#include "./OrientationError.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

OrientationError::OrientationError()
{
}

//////////////////////////////////////////////////////////////////////////

OrientationError::OrientationError( KFIXED16_8 Azimuth, KFIXED16_8 Elevation, KFIXED16_8 Rotation ) :
    m_AziErr( Azimuth ),
    m_ElvErr( Elevation ),
    m_RotErr( Rotation )
{
}

//////////////////////////////////////////////////////////////////////////

OrientationError::OrientationError( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

OrientationError::~OrientationError()
{
}

//////////////////////////////////////////////////////////////////////////

void OrientationError::SetAzimuthError( KFIXED16_8 AE )
{
    m_AziErr = AE;
}

//////////////////////////////////////////////////////////////////////////

KFIXED16_8 OrientationError::GetAzimuthError() const
{
    return m_AziErr;
}

//////////////////////////////////////////////////////////////////////////

void OrientationError::SetElevationError( KFIXED16_8 EE )
{
    m_ElvErr;
}

//////////////////////////////////////////////////////////////////////////

KFIXED16_8 OrientationError::GetElevationError() const
{
    return m_ElvErr;
}

//////////////////////////////////////////////////////////////////////////

void OrientationError::SetRotationError( KFIXED16_8 RE )
{
    m_RotErr = RE;
}

//////////////////////////////////////////////////////////////////////////

KFIXED16_8 OrientationError::GetRotationError() const
{
    return m_RotErr;
}

//////////////////////////////////////////////////////////////////////////

KString OrientationError::GetAsString() const
{
    KStringStream ss;

    ss << "OrientationError:\n"
       << "\tAzimuth Error:   " << m_AziErr.GetAsString()
       << "\tElevation Error: " << m_ElvErr.GetAsString()
       << "\tRotation Error : " << m_RotErr.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void OrientationError::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ORIENTATION_ERROR_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> KDIS_STREAM m_AziErr
           >> KDIS_STREAM m_ElvErr
           >> KDIS_STREAM m_RotErr;
}

//////////////////////////////////////////////////////////////////////////

KDataStream OrientationError::Encode() const
{
    KDataStream stream;

    OrientationError::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void OrientationError::Encode( KDataStream & stream ) const
{
    stream << KDIS_STREAM m_AziErr
           << KDIS_STREAM m_ElvErr
           << KDIS_STREAM m_RotErr;
}

//////////////////////////////////////////////////////////////////////////

KBOOL OrientationError::operator == ( const OrientationError & Value ) const
{
    if( m_AziErr != Value.m_AziErr )return false;
    if( m_ElvErr != Value.m_ElvErr )return false;
    if( m_RotErr != Value.m_RotErr )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL OrientationError::operator != ( const OrientationError & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

