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

#include "./OrientationError.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

OrientationError::OrientationError( void )
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

OrientationError::~OrientationError( void )
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

