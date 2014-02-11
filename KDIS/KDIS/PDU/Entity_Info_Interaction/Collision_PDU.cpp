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

#include "./Collision_PDU.h"

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

Collision_PDU::Collision_PDU() :
    m_ui8Padding( 0 )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = Collision_PDU_Type;
    m_ui16PDULength = COLLISION_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Collision_PDU::Collision_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Collision_PDU::Collision_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Collision_PDU::Collision_PDU( const EntityIdentifier & IssuingID, const EntityIdentifier & CollidingID,
                              const EntityIdentifier & EventID, CollisionType CT,const Vector & Velocity,
                              KFLOAT32 Mass, const Vector & Location ) :
    m_IssuingEntityID( IssuingID ),
    m_CollidingEntityID( CollidingID ),
    m_EventID( EventID ),
    m_ui8CollisionType( CT ),
    m_ui8Padding( 0 ),
    m_Velocity( Velocity ),
    m_f32Mass( Mass ),
    m_Location( Location )
{
    m_ui8ProtocolFamily = Entity_Information_Interaction;
    m_ui8PDUType = Collision_PDU_Type;
    m_ui16PDULength = COLLISION_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Collision_PDU::~Collision_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Collision_PDU::SetIssuingEntityID( const EntityIdentifier & ID )
{
    m_IssuingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Collision_PDU::GetIssuingEntityID() const
{
    return m_IssuingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Collision_PDU::GetIssuingEntityID()
{
    return m_IssuingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Collision_PDU::SetCollidingEntityID( const EntityIdentifier & ID )
{
    m_CollidingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Collision_PDU::GetCollidingEntityID() const
{
    return m_CollidingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Collision_PDU::GetCollidingEntityID()
{
    return m_CollidingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Collision_PDU::SetEventID( const EntityIdentifier & ID )
{
    m_EventID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Collision_PDU::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Collision_PDU::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

void Collision_PDU::SetCollisionType( CollisionType CT )
{
    m_ui8CollisionType = CT;
}

//////////////////////////////////////////////////////////////////////////

CollisionType Collision_PDU::GetCollisionType() const
{
    return ( CollisionType )m_ui8CollisionType;
}

//////////////////////////////////////////////////////////////////////////

void Collision_PDU::SetVelocity( const Vector & V )
{
    m_Velocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Collision_PDU::GetVelocity() const
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & Collision_PDU::GetVelocity()
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

void Collision_PDU::SetMass( KFLOAT32 M )
{
    m_f32Mass = M;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Collision_PDU::GetMass() const
{
    return m_f32Mass;
}

//////////////////////////////////////////////////////////////////////////

void Collision_PDU::SetLocation( const Vector & L )
{
    m_Location = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Collision_PDU::GetLocation() const
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

Vector & Collision_PDU::GetLocation()
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

KString Collision_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Collision PDU-\n"
       << "Issuing Entity ID:\n"
       << IndentString( m_IssuingEntityID.GetAsString(), 1 )
       << "Colliding Entity ID:\n"
       << IndentString( m_CollidingEntityID.GetAsString(), 1 )
       << "Event ID:\n"
       << IndentString( m_EventID.GetAsString(), 1 )
       << "Collision Type: "                      << GetEnumAsStringCollisionType( m_ui8CollisionType )
       << "\nVelocity:     "                      << m_Velocity.GetAsString()
       << "Mass (KG):      "                      << m_f32Mass
       << "\nLocation (With Respect To Entity): " << m_Location.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Collision_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < COLLISION_PDU_SIZE  )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_IssuingEntityID
           >> KDIS_STREAM m_CollidingEntityID
           >> KDIS_STREAM m_EventID
           >> m_ui8CollisionType
           >> m_ui8Padding
           >> KDIS_STREAM m_Velocity
		   >> m_f32Mass
           >> KDIS_STREAM m_Location;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Collision_PDU::Encode() const
{
    KDataStream stream;

    Collision_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Collision_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );
    stream << KDIS_STREAM m_IssuingEntityID
           << KDIS_STREAM m_CollidingEntityID
           << KDIS_STREAM m_EventID
           << m_ui8CollisionType
           << m_ui8Padding
           << KDIS_STREAM m_Velocity
		   << m_f32Mass
           << KDIS_STREAM m_Location;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Collision_PDU::operator == ( const Collision_PDU & Value ) const
{
    if( Header::operator     !=( Value ) )                   return false;
    if( m_IssuingEntityID    != Value.m_IssuingEntityID )    return false;
    if( m_CollidingEntityID  != Value.m_CollidingEntityID )  return false;
    if( m_EventID            != Value.m_EventID )            return false;
    if( m_ui8CollisionType   != Value.m_ui8CollisionType )   return false;
    if( m_Velocity           != Value.m_Velocity )           return false;
	if( m_f32Mass            != Value.m_f32Mass )            return false;	
    if( m_Location           != Value.m_Location )           return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Collision_PDU::operator != ( const Collision_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

