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

#include "./GED_GroundLogisticsVehicle.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_GroundLogisticsVehicle::GED_GroundLogisticsVehicle() :
    m_ui16EntityID( 0 ),
    m_i8Spd( 0 )
{
    for( KINT8 i = 0; i < 3; ++i )
    {
        m_i16Offsets[i] = 0;
        m_i8Ori[i] = 0;
    }
}

//////////////////////////////////////////////////////////////////////////

GED_GroundLogisticsVehicle::GED_GroundLogisticsVehicle( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_GroundLogisticsVehicle::GED_GroundLogisticsVehicle( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA, KINT8 Psi, KINT8 Theta,
        KINT8 Phi, KINT8 Speed ) :
    m_ui16EntityID( ID ),
    m_EA( EA ),
    m_i8Spd( Speed )
{
    m_i16Offsets[0] = XOffset;
    m_i16Offsets[1] = YOffset;
    m_i16Offsets[2] = ZOffset;
    m_i8Ori[0] = Psi;
    m_i8Ori[1] = Theta;
    m_i8Ori[2] = Phi;
}

//////////////////////////////////////////////////////////////////////////

GED_GroundLogisticsVehicle::~GED_GroundLogisticsVehicle()
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_GroundLogisticsVehicle::GetGroupedEntityCategory() const
{
    return BasicFixedWingAircraftGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_GroundLogisticsVehicle::GetLength() const
{
    return GED_GROUND_LOGISTICS_VEHICLE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityID( KUINT16 ID )
{
    m_ui16EntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GED_GroundLogisticsVehicle::GetEntityID() const
{
    return m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityLocation( KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset )
{
    m_i16Offsets[0] = XOffset;
    m_i16Offsets[1] = YOffset;
    m_i16Offsets[2] = ZOffset;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityLocation( KINT16 Offsets[3] )
{
    for( KUINT8 i = 0; i < 3; ++i )
    {
        m_i16Offsets[i] = Offsets[i];
    }
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityLocationXOffset( KINT16 X )
{
    m_i16Offsets[0] = X;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityLocationYOffset( KINT16 Y )
{
    m_i16Offsets[1] = Y;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityLocationZOffset( KINT16 Z )
{
    m_i16Offsets[2] = Z;
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_GroundLogisticsVehicle::GetEntityLocationXOffset() const
{
    return m_i16Offsets[0];
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_GroundLogisticsVehicle::GetEntityLocationYOffset() const
{
    return m_i16Offsets[1];
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_GroundLogisticsVehicle::GetEntityLocationZOffset() const
{
    return m_i16Offsets[2];
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityAppearance( const EntityAppearance & EA )
{
    m_EA = EA;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & GED_GroundLogisticsVehicle::GetEntityAppearance() const
{
    return m_EA;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & GED_GroundLogisticsVehicle::GetEntityAppearance()
{
    return m_EA;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityOrientation( KINT8 Psi, KINT8 Theta, KINT8 Phi )
{
    m_i8Ori[0] = Psi;
    m_i8Ori[0] = Theta;
    m_i8Ori[0] = Phi;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityOrientation( KINT8 Ori[3] )
{
    for( KINT8 i = 0; i < 3; ++i )
    {
        m_i8Ori[i] = Ori[i];
    }
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityOrientationPsi( KINT8 P )
{
    m_i8Ori[0] = P;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityOrientationTheta( KINT8 T )
{
    m_i8Ori[1] = T;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetEntityOrientationPhi( KINT8 P )
{
    m_i8Ori[2] = P;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_GroundLogisticsVehicle::GetEntityOrientationPsi() const
{
    return m_i8Ori[0];
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_GroundLogisticsVehicle::GetEntityOrientationTheta() const
{
    return m_i8Ori[1];
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_GroundLogisticsVehicle::GetEntityOrientationPhi() const
{
    return m_i8Ori[2];
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::SetSpeed( KINT8 S )
{
    m_i8Spd = S;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_GroundLogisticsVehicle::GetSpeed() const
{
    return m_i8Spd;
}

//////////////////////////////////////////////////////////////////////////

KString GED_GroundLogisticsVehicle::GetAsString() const
{
    KStringStream ss;

    ss << "GED Basic Fixed Wing Aircraft\n"
       << "\tEntity ID:                  " << m_ui16EntityID  << "\n"
       << "\tLocation Offsets(x,y,z):    " << m_i16Offsets[0] << " " << m_i16Offsets[1] << " " << m_i16Offsets[2] << "\n"
       << IndentString( m_EA.GetAsString( EntityType( Platform, Air, 0, 0, 0, 0, 0 ) ), 1 )
       << "\tOrientation(Psi,Theta,Phi): " << ( KINT16 )m_i8Ori[0]    << " " << ( KINT16 )m_i8Ori[1] << " " << ( KINT16 )m_i8Ori[2] << "\n"
       << "\tSpeed:                      " << ( KINT16 )m_i8Spd       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GED_GROUND_LOGISTICS_VEHICLE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16EntityID
           >> m_i16Offsets[0]
           >> m_i16Offsets[1]
           >> m_i16Offsets[2]
           >> KDIS_STREAM m_EA
           >> m_i8Ori[0]
           >> m_i8Ori[1]
           >> m_i8Ori[2]
           >> m_i8Spd;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_GroundLogisticsVehicle::Encode() const
{
    KDataStream stream;

    GED_GroundLogisticsVehicle::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_GroundLogisticsVehicle::Encode( KDataStream & stream ) const
{
    stream << m_ui16EntityID
           << m_i16Offsets[0]
           << m_i16Offsets[1]
           << m_i16Offsets[2]
           << KDIS_STREAM m_EA
           << m_i8Ori[0]
           << m_i8Ori[1]
           << m_i8Ori[2]
           << m_i8Spd;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_GroundLogisticsVehicle::operator == ( const GED_GroundLogisticsVehicle & Value ) const
{
    if( m_ui16EntityID      != Value.m_ui16EntityID )   return false;
    if( m_i16Offsets[0]     != Value.m_i16Offsets[0] )  return false;
    if( m_i16Offsets[1]     != Value.m_i16Offsets[1] )  return false;
    if( m_i16Offsets[2]     != Value.m_i16Offsets[2] )  return false;
    if( m_EA                != Value.m_EA )             return false;
    if( m_i8Ori[0]          != Value.m_i8Ori[0] )       return false;
    if( m_i8Ori[1]          != Value.m_i8Ori[1] )       return false;
    if( m_i8Ori[2]          != Value.m_i8Ori[2] )       return false;
    if( m_i8Spd             != Value.m_i8Spd )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_GroundLogisticsVehicle::operator != ( const GED_GroundLogisticsVehicle & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
