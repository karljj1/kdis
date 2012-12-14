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

#include "./RelativeWorldCoordinates.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

RelativeWorldCoordinates::RelativeWorldCoordinates ( void ) :
    m_ui16RefPnt( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

RelativeWorldCoordinates::RelativeWorldCoordinates( KUINT16 RefPnt, KFIXED16_3 DelX, KFIXED16_3 DelY, KFIXED16_3 DelZ ) :
    m_ui16RefPnt( RefPnt ),
    m_DelX( DelX ),
    m_DelY( DelY ),
    m_DelZ( DelZ )
{
}

//////////////////////////////////////////////////////////////////////////

RelativeWorldCoordinates::RelativeWorldCoordinates ( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

RelativeWorldCoordinates::~RelativeWorldCoordinates ( void )
{
}

//////////////////////////////////////////////////////////////////////////

void RelativeWorldCoordinates::SetReferencePoint( KUINT16 RP )
{
    m_ui16RefPnt = RP;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 RelativeWorldCoordinates::GetReferencePoint() const
{
    return m_ui16RefPnt;
}

//////////////////////////////////////////////////////////////////////////

void RelativeWorldCoordinates::SetDeltaX( KFIXED16_3 X )
{
    m_DelX = X;
}

//////////////////////////////////////////////////////////////////////////

KFIXED16_3 RelativeWorldCoordinates::GetDeltaX() const
{
    return m_DelX;
}

//////////////////////////////////////////////////////////////////////////

void RelativeWorldCoordinates::SetDeltaY( KFIXED16_3 Y )
{
    m_DelY = Y;
}

//////////////////////////////////////////////////////////////////////////

KFIXED16_3 RelativeWorldCoordinates::GetDeltaY() const
{
    return m_DelY;
}

//////////////////////////////////////////////////////////////////////////

void RelativeWorldCoordinates::SetDeltaZ( KFIXED16_3 Z )
{
    m_DelZ = Z;
}

//////////////////////////////////////////////////////////////////////////

KFIXED16_3 RelativeWorldCoordinates::GetDeltaZ() const
{
    return m_DelZ;
}

//////////////////////////////////////////////////////////////////////////

KString RelativeWorldCoordinates::GetAsString() const
{
    KStringStream ss;

    ss << "Relative World Coordinates\n"
       << "\n\tReference Point: " << m_ui16RefPnt
       << "X: " << m_DelX.GetAsFloat32()
       << "Y: " << m_DelY.GetAsFloat32()
       << "Z: " << m_DelZ.GetAsFloat32()
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void RelativeWorldCoordinates::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RELATVE_WORLD_COORDINATES_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16RefPnt
           >> KDIS_STREAM m_DelX
           >> KDIS_STREAM m_DelY
           >> KDIS_STREAM m_DelZ;
}

//////////////////////////////////////////////////////////////////////////

KDataStream RelativeWorldCoordinates::Encode() const
{
    KDataStream stream;

    RelativeWorldCoordinates::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void RelativeWorldCoordinates::Encode( KDataStream & stream ) const
{
    stream << m_ui16RefPnt
           << KDIS_STREAM m_DelX
           << KDIS_STREAM m_DelY
           << KDIS_STREAM m_DelZ;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RelativeWorldCoordinates::operator == ( const RelativeWorldCoordinates  & Value ) const
{
    if( m_ui16RefPnt != Value.m_ui16RefPnt ) return false;
    if( m_DelX       != Value.m_DelX )       return false;
    if( m_DelY       != Value.m_DelY )       return false;
    if( m_DelZ       != Value.m_DelZ )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RelativeWorldCoordinates::operator != ( const RelativeWorldCoordinates  & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

