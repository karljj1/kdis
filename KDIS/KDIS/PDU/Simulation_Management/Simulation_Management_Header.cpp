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

#include "./Simulation_Management_Header.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::Simulation_Management_Header()
{
    m_ui8ProtocolFamily = Simulation_Management;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::Simulation_Management_Header( const Header & H ) :
	Header( H )
{
}

//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::Simulation_Management_Header( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::Simulation_Management_Header( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::Simulation_Management_Header( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID ) :
    m_OriginatingEntityID( OriginatingEntityID ),
    m_ReceivingEntityID( ReceivingEntityID )
{
    m_ui8ProtocolFamily = Simulation_Management;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::~Simulation_Management_Header()
{
}

//////////////////////////////////////////////////////////////////////////

void Simulation_Management_Header::SetOriginatingEntityID( const EntityIdentifier & ID )
{
    m_OriginatingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Simulation_Management_Header::GetOriginatingEntityID() const
{
    return m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Simulation_Management_Header::GetOriginatingEntityID()
{
    return m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Simulation_Management_Header::SetReceivingEntityID( const EntityIdentifier & ID )
{
    m_ReceivingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Simulation_Management_Header::GetReceivingEntityID() const
{
    return m_ReceivingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Simulation_Management_Header::GetReceivingEntityID()
{
    return m_ReceivingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KString Simulation_Management_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Originating Entity ID:\n"
       << IndentString( m_OriginatingEntityID.GetAsString(), 1 )
       << "Receiving Entity ID:\n"
       << IndentString( m_ReceivingEntityID.GetAsString(), 1 );

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Simulation_Management_Header::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < SIMULATION_MANAGEMENT_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_OriginatingEntityID
           >> KDIS_STREAM m_ReceivingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Simulation_Management_Header::Encode() const
{
    KDataStream stream;

    Simulation_Management_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Simulation_Management_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );
    stream << KDIS_STREAM m_OriginatingEntityID
           << KDIS_STREAM m_ReceivingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Simulation_Management_Header::operator == ( const Simulation_Management_Header & Value ) const
{
    if( Header::operator        !=( Value ) )                    return false;
    if( m_OriginatingEntityID   != Value.m_OriginatingEntityID ) return false;
    if( m_ReceivingEntityID     != Value.m_ReceivingEntityID )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Simulation_Management_Header::operator != ( const Simulation_Management_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
