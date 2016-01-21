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

#include "./GED_BasicRotorWingAircraft.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_BasicRotorWingAircraft::GED_BasicRotorWingAircraft() :
    m_i8TrrtAz( 0 ),
    m_i8GnElv( 0 ),
    m_i8TrrtSlwRt( 0 ),
    m_i8GnElvRt( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GED_BasicRotorWingAircraft::GED_BasicRotorWingAircraft( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_BasicRotorWingAircraft::GED_BasicRotorWingAircraft( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi,
        KINT8 Theta, KINT8 Phi, KUINT8 FuelStatus, KINT8 HorizontalDeviation, KINT8 VerticalDeviation,
        KINT16 Speed, KINT8 TurretAzimuth, KINT8 GunElevation, KINT8 TurretSlewRate, KINT8 GunElevationRate ) :
    GED_BasicFixedWingAircraft( ID, XOffset, YOffset, ZOffset, EA, Psi, Theta, Phi, FuelStatus, HorizontalDeviation, VerticalDeviation, Speed ),
    m_i8TrrtAz( TurretAzimuth ),
    m_i8GnElv( GunElevation ),
    m_i8TrrtSlwRt( TurretSlewRate ),
    m_i8GnElvRt( GunElevationRate )
{
}

//////////////////////////////////////////////////////////////////////////

GED_BasicRotorWingAircraft::~GED_BasicRotorWingAircraft()
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_BasicRotorWingAircraft::GetGroupedEntityCategory() const
{
    return BasicRotorWingAircraftGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_BasicRotorWingAircraft::GetLength() const
{
    return GED_BASIC_ROTOR_WING_AIRCRAFT_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::SetTurretAzimuth( KINT8 T )
{
    m_i8TrrtAz = T;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicRotorWingAircraft::GetTurretAzimuth() const
{
    return m_i8TrrtAz;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::SetGunElevation( KINT8 G )
{
    m_i8GnElv = G;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicRotorWingAircraft::GetGunElevation() const
{
    return m_i8GnElv;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::SetTurretSlewRate( KINT8 T )
{
    m_i8TrrtSlwRt = T;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicRotorWingAircraft::GetTurretSlewRate() const
{
    return m_i8TrrtSlwRt;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::SetGunElevationRate( KINT8 G )
{
    m_i8GnElvRt = G;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicRotorWingAircraft::GetGunElevationRate() const
{
    return m_i8GnElvRt;
}

//////////////////////////////////////////////////////////////////////////

KString GED_BasicRotorWingAircraft::GetAsString() const
{
    KStringStream ss;

    ss << "GED Basic Rotor Wing Aircraft\n"
       << "\tEntity ID:                  " << m_ui16EntityID  << "\n"
       << "\tLocation Offsets(x,y,z):    " << m_i16Offsets[0] << " " << m_i16Offsets[1] << " " << m_i16Offsets[2] << "\n"
       << IndentString( m_EA.GetAsString( EntityType( Platform, Air, 0, 0, 0, 0, 0 ) ), 1 )
       << "\tOrientation(Psi,Theta,Phi): " << ( KINT16 )m_i8Ori[0]    << " " << ( KINT16 )m_i8Ori[1] << " " << ( KINT16 )m_i8Ori[2] << "\n"
       << "\tFuel Status:                " << ( KUINT16 )m_ui8FuelStatus << "\n"
       << "\tHorizontal Deviation:       " << ( KINT16 )m_i8HoriDevi  << "\n"
       << "\tVertical Deviation:         " << ( KINT16 )m_i8VertDevi  << "\n"
       << "\tSpeed:                      " << ( KINT16 )m_i16Spd      << "\n"
       << "\tTurret Azimuth:             " << ( KINT16 )m_i8TrrtAz    << "\n"
       << "\tGun Elevation:              " << ( KINT16 )m_i8GnElv     << "\n"
       << "\tTurret Slew Rate:           " << ( KINT16 )m_i8TrrtSlwRt << "\n"
       << "\tGun Elevation Rate:         " << ( KINT16 )m_i8GnElvRt   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GED_BASIC_ROTOR_WING_AIRCRAFT_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    GED_BasicFixedWingAircraft::Decode( stream );

    stream >> m_i8TrrtAz
           >> m_i8GnElv
           >> m_i8TrrtSlwRt
           >> m_i8GnElvRt;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_BasicRotorWingAircraft::Encode() const
{
    KDataStream stream;

    GED_BasicRotorWingAircraft::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicRotorWingAircraft::Encode( KDataStream & stream ) const
{
    GED_BasicFixedWingAircraft::Encode( stream );

    stream << m_i8TrrtAz
           << m_i8GnElv
           << m_i8TrrtSlwRt
           << m_i8GnElvRt;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicRotorWingAircraft::operator == ( const GED_BasicRotorWingAircraft & Value ) const
{
    if( GED_BasicFixedWingAircraft::operator!=( Value ) )return false;
    if( m_i8TrrtAz    != Value.m_i8TrrtAz )    return false;
    if( m_i8GnElv     != Value.m_i8GnElv )     return false;
    if( m_i8TrrtSlwRt != Value.m_i8TrrtSlwRt ) return false;
    if( m_i8GnElvRt   != Value.m_i8GnElvRt )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicRotorWingAircraft::operator != ( const GED_BasicRotorWingAircraft & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
