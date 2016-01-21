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

#include "./RelativeWorldCoordinates.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

RelativeWorldCoordinates::RelativeWorldCoordinates () :
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

RelativeWorldCoordinates::~RelativeWorldCoordinates ()
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

    ss << "Relative World Coordinates"
       << "\n\tReference Point: " << m_ui16RefPnt
       << ", Delta-X: " << m_DelX.GetAsFloat32()
       << ", Delta-Y: " << m_DelY.GetAsFloat32()
       << ", Delta-Z: " << m_DelZ.GetAsFloat32()
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

