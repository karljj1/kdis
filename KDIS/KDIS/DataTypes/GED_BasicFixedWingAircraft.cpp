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

#include "./GED_BasicFixedWingAircraft.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_BasicFixedWingAircraft::GED_BasicFixedWingAircraft() :
    m_ui16EntityID( 0 ),
    m_ui8FuelStatus( 0 ),
    m_i8HoriDevi( 0 ),
    m_i8VertDevi( 0 ),
    m_i16Spd( 0 )
{
    for( KINT8 i = 0; i < 3; ++i )
    {
        m_i16Offsets[i] = 0;
        m_i8Ori[i] = 0;
    }
}

//////////////////////////////////////////////////////////////////////////

GED_BasicFixedWingAircraft::GED_BasicFixedWingAircraft( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_BasicFixedWingAircraft::GED_BasicFixedWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi, KINT8 Theta,
        KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation, KINT16 Speed ) :
    m_ui16EntityID( ID ),
    m_EA( EA ),
    m_ui8FuelStatus( FuelStatus ),
    m_i8HoriDevi( HorizontalDeviation ),
    m_i8VertDevi( VerticalDeviation )
{
    m_i16Offsets[0] = XOffset;
    m_i16Offsets[1] = YOffset;
    m_i16Offsets[2] = ZOffset;
    m_i8Ori[0] = Psi;
    m_i8Ori[1] = Theta;
    m_i8Ori[2] = Phi;
}

//////////////////////////////////////////////////////////////////////////

GED_BasicFixedWingAircraft::~GED_BasicFixedWingAircraft()
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_BasicFixedWingAircraft::GetGroupedEntityCategory() const
{
    return BasicFixedWingAircraftGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_BasicFixedWingAircraft::GetLength() const
{
    return GED_BASIC_FIXED_WING_AIRCRAFT_SIZE;
}


//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityID(KUINT16 ID)
{
    m_ui16EntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GED_BasicFixedWingAircraft::GetEntityID() const
{
    return m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityLocation(KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset)
{
    m_i16Offsets[0] = XOffset;
    m_i16Offsets[1] = YOffset;
    m_i16Offsets[2] = ZOffset;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityLocation(KINT16 Offsets[3])
{
    for (KUINT8 i = 0; i < 3; ++i)
    {
        m_i16Offsets[i] = Offsets[i];
    }
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityLocationXOffset(KINT16 X)
{
    m_i16Offsets[0] = X;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityLocationYOffset(KINT16 Y)
{
    m_i16Offsets[1] = Y;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityLocationZOffset(KINT16 Z)
{
    m_i16Offsets[2] = Z;
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicFixedWingAircraft::GetEntityLocationXOffset() const
{
    return m_i16Offsets[0];
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicFixedWingAircraft::GetEntityLocationYOffset() const
{
    return m_i16Offsets[1];
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicFixedWingAircraft::GetEntityLocationZOffset() const
{
    return m_i16Offsets[2];
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityAppearance(const EntityAppearance & EA)
{
    m_EA = EA;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & GED_BasicFixedWingAircraft::GetEntityAppearance() const
{
    return m_EA;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & GED_BasicFixedWingAircraft::GetEntityAppearance()
{
    return m_EA;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityOrientation(KINT8 Psi, KINT8 Theta, KINT8 Phi)
{
    m_i8Ori[0] = Psi;
    m_i8Ori[0] = Theta;
    m_i8Ori[0] = Phi;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityOrientation(KINT8 Ori[3])
{
    for (KINT8 i = 0; i < 3; ++i)
    {
        m_i8Ori[i] = Ori[i];
    }
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityOrientationPsi(KINT8 P)
{
    m_i8Ori[0] = P;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityOrientationTheta(KINT8 T)
{
    m_i8Ori[1] = T;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetEntityOrientationPhi(KINT8 P)
{
    m_i8Ori[2] = P;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicFixedWingAircraft::GetEntityOrientationPsi() const
{
    return m_i8Ori[0];
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicFixedWingAircraft::GetEntityOrientationTheta() const
{
    return m_i8Ori[1];
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicFixedWingAircraft::GetEntityOrientationPhi() const
{
    return m_i8Ori[2];
}


//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetFuelStatus( KUINT8 F )
{
    m_ui8FuelStatus = F;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_BasicFixedWingAircraft::GetFuelStatus() const
{
    return m_ui8FuelStatus;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetMovementDirection( KINT8 Horizontal, KINT8 Vertical )
{
    m_i8HoriDevi = Horizontal;
    m_i8VertDevi = Vertical;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetMovementDirectionHorizontal( KINT8 H )
{
    m_i8HoriDevi = H;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetMovementDirectionVertical( KINT8 V )
{
    m_i8VertDevi = V;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicFixedWingAircraft::GetMovementDirectionHorizontal() const
{
    return m_i8HoriDevi;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicFixedWingAircraft::GetMovementDirectionVertical() const
{
    return m_i8VertDevi;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::SetSpeed(KINT16 S)
{
    m_i16Spd = S;
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicFixedWingAircraft::GetSpeed() const
{
    return m_i16Spd;
}

//////////////////////////////////////////////////////////////////////////

KString GED_BasicFixedWingAircraft::GetAsString() const
{
    KStringStream ss;

    ss << "GED Basic Fixed Wing Aircraft\n"
       << "\tEntity ID:                  " << m_ui16EntityID  << "\n"
       << "\tLocation Offsets(x,y,z):    " << m_i16Offsets[0] << " " << m_i16Offsets[1] << " " << m_i16Offsets[2] << "\n"
       << IndentString( m_EA.GetAsString( EntityType( Platform, Air, 0, 0, 0, 0, 0 ) ), 1 )
       << "\tOrientation(Psi,Theta,Phi): " << ( KINT16 )m_i8Ori[0]    << " " << ( KINT16 )m_i8Ori[1] << " " << ( KINT16 )m_i8Ori[2] << "\n"
       << "\tFuel Status:                " << ( KUINT16 )m_ui8FuelStatus << "\n"
       << "\tHorizontal Deviation:       " << ( KINT16 )m_i8HoriDevi  << "\n"
       << "\tVertical Deviation:         " << ( KINT16 )m_i8VertDevi  << "\n"
       << "\tSpeed:                      " << m_i16Spd << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GED_BASIC_FIXED_WING_AIRCRAFT_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16EntityID
           >> m_i16Offsets[0]
           >> m_i16Offsets[1]
           >> m_i16Offsets[2]
           >> KDIS_STREAM m_EA
           >> m_i8Ori[0]
           >> m_i8Ori[1]
           >> m_i8Ori[2]
           >> m_ui8FuelStatus
           >> m_i8HoriDevi
           >> m_i8VertDevi
           >> m_i16Spd;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_BasicFixedWingAircraft::Encode() const
{
    KDataStream stream;

    GED_BasicFixedWingAircraft::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicFixedWingAircraft::Encode( KDataStream & stream ) const
{
    stream << m_ui16EntityID
           << m_i16Offsets[0]
           << m_i16Offsets[1]
           << m_i16Offsets[2]
           << KDIS_STREAM m_EA
           << m_i8Ori[0]
           << m_i8Ori[1]
           << m_i8Ori[2]
           << m_ui8FuelStatus
           << m_i8HoriDevi
           << m_i8VertDevi
           << m_i16Spd;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicFixedWingAircraft::operator == ( const GED_BasicFixedWingAircraft & Value ) const
{
    if( m_ui16EntityID      != Value.m_ui16EntityID )   return false;
    if( m_i16Offsets[0]     != Value.m_i16Offsets[0] )  return false;
    if( m_i16Offsets[1]     != Value.m_i16Offsets[1] )  return false;
    if( m_i16Offsets[2]     != Value.m_i16Offsets[2] )  return false;
    if( m_EA                != Value.m_EA )             return false;
    if( m_i8Ori[0]          != Value.m_i8Ori[0] )       return false;
    if( m_i8Ori[1]          != Value.m_i8Ori[1] )       return false;
    if( m_i8Ori[2]          != Value.m_i8Ori[2] )       return false;
    if( m_ui8FuelStatus     != Value.m_ui8FuelStatus )  return false;
    if( m_i8HoriDevi        != Value.m_i8HoriDevi )     return false;
    if( m_i8VertDevi        != Value.m_i8VertDevi )     return false;
    if(m_i16Spd            != Value.m_i16Spd)         return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicFixedWingAircraft::operator != ( const GED_BasicFixedWingAircraft & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
