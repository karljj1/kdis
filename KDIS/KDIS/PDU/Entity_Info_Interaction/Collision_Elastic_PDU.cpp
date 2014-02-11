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

#include "./Collision_Elastic_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Collision_Elastic_PDU::Collision_Elastic_PDU() :
    m_ui16Padding1( 0 )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = Collision_Elastic_PDU_Type;
    m_ui16PDULength = COLLISION_ELASTIC_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Collision_Elastic_PDU::Collision_Elastic_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Collision_Elastic_PDU::Collision_Elastic_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Collision_Elastic_PDU::~Collision_Elastic_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetIssuingEntityID( const EntityIdentifier & ID )
{
    m_IssuingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Collision_Elastic_PDU::GetIssuingEntityID() const
{
    return m_IssuingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Collision_Elastic_PDU::GetIssuingEntityID()
{
    return m_IssuingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetCollidingEntityID( const EntityIdentifier & ID )
{
    m_CollidingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Collision_Elastic_PDU::GetCollidingEntityID() const
{
    return m_CollidingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Collision_Elastic_PDU::GetCollidingEntityID()
{
    return m_CollidingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetEventID( const EntityIdentifier & ID )
{
    m_EventID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Collision_Elastic_PDU::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Collision_Elastic_PDU::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetContactVelocity( const Vector & V )
{
    m_ContactVelocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Collision_Elastic_PDU::GetContactVelocity() const
{
    return m_ContactVelocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & Collision_Elastic_PDU::GetContactVelocity()
{
    return m_ContactVelocity;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetMass( KFLOAT32 M )
{
    m_f32Mass = M;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Collision_Elastic_PDU::GetMass() const
{
    return m_f32Mass;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetLocation( const Vector & L )
{
    m_Location = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Collision_Elastic_PDU::GetLocation() const
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

Vector & Collision_Elastic_PDU::GetLocation()
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetCollisionIntermediateResultXX( KFLOAT32 CIR )
{
    m_f32CIRXX = CIR;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetCollisionIntermediateResultXY( KFLOAT32 CIR )
{
    m_f32CIRXY = CIR;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetCollisionIntermediateResultXZ( KFLOAT32 CIR )
{
    m_f32CIRXZ = CIR;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetCollisionIntermediateResultYY( KFLOAT32 CIR )
{
    m_f32CIRYY = CIR;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetCollisionIntermediateResultYZ( KFLOAT32 CIR )
{
    m_f32CIRYZ = CIR;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetCollisionIntermediateResultZZ( KFLOAT32 CIR )
{
    m_f32CIRZZ = CIR;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Collision_Elastic_PDU::GetCollisionIntermediateResultXX() const
{
    return m_f32CIRXX;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Collision_Elastic_PDU::GetCollisionIntermediateResultXY() const
{
    return m_f32CIRXY;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Collision_Elastic_PDU::GetCollisionIntermediateResultXZ() const
{
    return m_f32CIRXZ;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Collision_Elastic_PDU::GetCollisionIntermediateResultYY() const
{
    return m_f32CIRYY;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Collision_Elastic_PDU::GetCollisionIntermediateResultYZ() const
{
    return m_f32CIRYZ;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Collision_Elastic_PDU::GetCollisionIntermediateResultZZ() const
{
    return m_f32CIRZZ;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetCollisionIntermediateResult( KFLOAT32 XX, KFLOAT32 XY, KFLOAT32 XZ,
        KFLOAT32 YY, KFLOAT32 YZ, KFLOAT32 ZZ )
{
    m_f32CIRXX = XX;
    m_f32CIRXY = XY;
    m_f32CIRXZ = XZ;
    m_f32CIRYY = YY;
    m_f32CIRYZ = YZ;
    m_f32CIRZZ = ZZ;
}

/////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetUnitSurfaceNormal( const Vector & USN )
{
    m_UnitSurfaceNormal = USN;
}

/////////////////////////////////////////////////////////////////////////

const Vector & Collision_Elastic_PDU::GetUnitSurfaceNormal() const
{
    return m_UnitSurfaceNormal;
}

/////////////////////////////////////////////////////////////////////////

Vector & Collision_Elastic_PDU::GetUnitSurfaceNormal()
{
    return m_UnitSurfaceNormal;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::SetCoefficientOfRestitution( KFLOAT32 COR )
{
    m_f32COR = COR;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Collision_Elastic_PDU::GetCoefficientOfRestitution() const
{
    return m_f32COR;
}

//////////////////////////////////////////////////////////////////////////

KString Collision_Elastic_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Collision Elastic PDU-\n"
       << "Issuing Entity ID:\n"
       << IndentString( m_IssuingEntityID.GetAsString(), 1 )
       << "Colliding Entity ID:\n"
       << IndentString( m_CollidingEntityID.GetAsString(), 1 )
       << "Event ID:\n"
       << IndentString( m_EventID.GetAsString(), 1 )
       << "ContactVelocity:       " << m_ContactVelocity.GetAsString()
       << "Mass (KG):             " << m_f32Mass
       << "\nLocation (With Respect To Entity): " << m_Location.GetAsString()
       << "Collision Intermediate Result:\n"
       << "XX : " << m_f32CIRXX << "\n"
       << "XY : " << m_f32CIRXY << "\n"
       << "XZ : " << m_f32CIRXZ << "\n"
       << "YY : " << m_f32CIRYY << "\n"
       << "YZ : " << m_f32CIRYZ << "\n"
       << "ZZ : " << m_f32CIRZZ << "\n"
       << "Unit Surface Normal:  " << m_UnitSurfaceNormal.GetAsString()
       << "Coeffcient Of Resititution:   " << m_f32COR
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < COLLISION_ELASTIC_PDU_SIZE  )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	
    stream >> KDIS_STREAM m_IssuingEntityID
           >> KDIS_STREAM m_CollidingEntityID
           >> KDIS_STREAM m_EventID
           >> m_ui16Padding1
           >> KDIS_STREAM m_ContactVelocity
           >> m_f32Mass
           >> KDIS_STREAM m_Location
           >> m_f32CIRXX
           >> m_f32CIRXY
           >> m_f32CIRXZ
           >> m_f32CIRYY
           >> m_f32CIRYZ
           >> m_f32CIRZZ
           >> KDIS_STREAM m_UnitSurfaceNormal
           >> m_f32COR;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Collision_Elastic_PDU::Encode() const
{
    KDataStream stream;

    Collision_Elastic_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Collision_Elastic_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );
    stream << KDIS_STREAM m_IssuingEntityID
           << KDIS_STREAM m_CollidingEntityID
           << KDIS_STREAM m_EventID
           << m_ui16Padding1
           << KDIS_STREAM m_ContactVelocity
           << m_f32Mass
           << KDIS_STREAM m_Location
           << m_f32CIRXX
           << m_f32CIRXY
           << m_f32CIRXZ
           << m_f32CIRYY
           << m_f32CIRYZ
           << m_f32CIRZZ
           << KDIS_STREAM m_UnitSurfaceNormal
           << m_f32COR;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Collision_Elastic_PDU::operator == ( const Collision_Elastic_PDU & Value ) const
{
    if( Header::operator     !=( Value ) )                   return false;
    if( m_IssuingEntityID    != Value.m_IssuingEntityID )    return false;
    if( m_CollidingEntityID  != Value.m_CollidingEntityID )  return false;
    if( m_EventID            != Value.m_EventID )            return false;
    if( m_ContactVelocity    != Value.m_ContactVelocity )    return false;
    if( m_f32Mass            != Value.m_f32Mass )            return false;
    if( m_Location           != Value.m_Location )           return false;
    if( m_f32CIRXX           != Value.m_f32CIRXX )           return false;
    if( m_f32CIRXY           != Value.m_f32CIRXY )           return false;
    if( m_f32CIRXZ           != Value.m_f32CIRXZ )           return false;
    if( m_f32CIRYY           != Value.m_f32CIRYY )           return false;
    if( m_f32CIRYZ           != Value.m_f32CIRYZ )           return false;
    if( m_f32CIRZZ           != Value.m_f32CIRZZ )           return false;
    if( m_UnitSurfaceNormal  != Value.m_UnitSurfaceNormal )  return false;
    if( m_f32COR             != Value.m_f32COR )             return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Collision_Elastic_PDU::operator != ( const Collision_Elastic_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


