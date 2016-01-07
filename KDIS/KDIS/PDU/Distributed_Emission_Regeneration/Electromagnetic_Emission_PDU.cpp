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

#include "./Electromagnetic_Emission_PDU.h"

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

Electromagnetic_Emission_PDU::Electromagnetic_Emission_PDU() :
    m_ui8StateUpdateIndicator( 0 ),
    m_ui8NumberOfEmissionSystems( 0 ),
    m_ui16Padding( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = Electromagnetic_Emission_PDU_Type;
    m_ui16PDULength = ELECTROMAGNETIC_EMISSION_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Electromagnetic_Emission_PDU::Electromagnetic_Emission_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Electromagnetic_Emission_PDU::Electromagnetic_Emission_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Electromagnetic_Emission_PDU::Electromagnetic_Emission_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID,
        StateUpdateIndicator SUI ) :
    m_EmittingEntityID( EmittingID ),
    m_EventID( EventID ),
    m_ui8StateUpdateIndicator( SUI ),
    m_ui8NumberOfEmissionSystems( 0 ),
    m_ui16Padding( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = Electromagnetic_Emission_PDU_Type;
    m_ui16PDULength = ELECTROMAGNETIC_EMISSION_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Electromagnetic_Emission_PDU::Electromagnetic_Emission_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID,
        StateUpdateIndicator SUI, const vector<EmissionSystem> & EmissionSystems ) :
    m_EmittingEntityID( EmittingID ),
    m_EventID( EventID ),
    m_ui8StateUpdateIndicator( SUI ),
    m_ui8NumberOfEmissionSystems( EmissionSystems.size() ),
    m_ui16Padding( 0 ),
    m_vEmissionSystem( EmissionSystems )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = Electromagnetic_Emission_PDU_Type;
    m_ui16PDULength = ELECTROMAGNETIC_EMISSION_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Electromagnetic_Emission_PDU::~Electromagnetic_Emission_PDU()
{
    m_vEmissionSystem.clear();
}

//////////////////////////////////////////////////////////////////////////

void Electromagnetic_Emission_PDU::SetEmittingEntityID( const EntityIdentifier & ID )
{
    m_EmittingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Electromagnetic_Emission_PDU::GetEmittingEntityID() const
{
    return m_EmittingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Electromagnetic_Emission_PDU::GetEmittingEntityID()
{
    return m_EmittingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Electromagnetic_Emission_PDU::SetEventID( const EntityIdentifier & ID )
{
    m_EventID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Electromagnetic_Emission_PDU::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Electromagnetic_Emission_PDU::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

void Electromagnetic_Emission_PDU::SetStateUpdateIndicator( StateUpdateIndicator SUI )
{
    m_ui8StateUpdateIndicator = SUI;
}

//////////////////////////////////////////////////////////////////////////

StateUpdateIndicator Electromagnetic_Emission_PDU::GetStateUpdateIndicator() const
{
    return ( StateUpdateIndicator )m_ui8StateUpdateIndicator;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Electromagnetic_Emission_PDU::GetNumberOfEmissionSystems() const
{
    return m_ui8NumberOfEmissionSystems;
}

//////////////////////////////////////////////////////////////////////////

void Electromagnetic_Emission_PDU::AddEmissionSystem( const EmissionSystem & ES )
{
    m_vEmissionSystem.push_back( ES );
    m_ui8NumberOfEmissionSystems = m_vEmissionSystem.size();

    // Data length values are in 32 bits so multiply by 4 to get the PDU length
    // which is stored in octets.
    m_ui16PDULength += ES.GetSystemDataLength() * 4;
}

//////////////////////////////////////////////////////////////////////////

void Electromagnetic_Emission_PDU::SetEmissionSystem( const vector<EmissionSystem> & ES )
{
    m_vEmissionSystem = ES;
    m_ui8NumberOfEmissionSystems = m_vEmissionSystem.size();

    // Data length values are in 32 bits so multiply by 4 to get the PDU length
    // which is stored in octets.
    m_ui16PDULength = ELECTROMAGNETIC_EMISSION_PDU_SIZE;

    vector<EmissionSystem>::const_iterator citr = m_vEmissionSystem.begin();
    vector<EmissionSystem>::const_iterator citrEnd = m_vEmissionSystem.end();

    for( ; citr != citrEnd; ++citr )
    {
        m_ui16PDULength += citr->GetSystemDataLength() * 4;
    }
}

//////////////////////////////////////////////////////////////////////////

const vector<EmissionSystem> & Electromagnetic_Emission_PDU::GetEmissionSystems() const
{
    return m_vEmissionSystem;
}

//////////////////////////////////////////////////////////////////////////

void Electromagnetic_Emission_PDU::ClearEmissionSystem()
{
    m_vEmissionSystem.clear();
    m_ui8NumberOfEmissionSystems = 0;
    m_ui16PDULength = ELECTROMAGNETIC_EMISSION_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString Electromagnetic_Emission_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Electromagnetic Emission PDU-\n"
       << "Emitting Entity ID:\n"
       << IndentString( m_EmittingEntityID.GetAsString(), 1 )
       << "Event ID:\n"
       << IndentString( m_EventID.GetAsString(), 1 )
       << "State Update Indicator:     " << GetEnumAsStringStateUpdateIndicator( m_ui8StateUpdateIndicator ) << "\n"
       << "Number Of Emission Systems: " << ( KUINT16 )m_ui8NumberOfEmissionSystems  << "\n";

    vector<EmissionSystem>::const_iterator citr = m_vEmissionSystem.begin();
    vector<EmissionSystem>::const_iterator citrEnd = m_vEmissionSystem.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << citr->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Electromagnetic_Emission_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < ELECTROMAGNETIC_EMISSION_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_EmittingEntityID
           >> KDIS_STREAM m_EventID
           >> m_ui8StateUpdateIndicator
           >> m_ui8NumberOfEmissionSystems
           >> m_ui16Padding;

    for( KUINT8 i = 0; i < m_ui8NumberOfEmissionSystems; ++i )
    {
        m_vEmissionSystem.push_back( EmissionSystem( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Electromagnetic_Emission_PDU::Encode() const
{
    KDataStream stream;

    Electromagnetic_Emission_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Electromagnetic_Emission_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_EmittingEntityID
           << KDIS_STREAM m_EventID
           << m_ui8StateUpdateIndicator
           << m_ui8NumberOfEmissionSystems
           << m_ui16Padding;

    vector<EmissionSystem>::const_iterator citr = m_vEmissionSystem.begin();
    vector<EmissionSystem>::const_iterator citrEnd = m_vEmissionSystem.end();
    for( ; citr != citrEnd; ++citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Electromagnetic_Emission_PDU::operator == ( const Electromagnetic_Emission_PDU & Value ) const
{
    if( Header::operator                !=( Value ) )                           return false;
    if( m_EmittingEntityID              != Value.m_EmittingEntityID )           return false;
    if( m_EventID                       != Value.m_EventID )                    return false;
    if( m_ui8StateUpdateIndicator       != Value.m_ui8StateUpdateIndicator )    return false;
    if( m_ui8NumberOfEmissionSystems    != Value.m_ui8NumberOfEmissionSystems ) return false;
    if( m_vEmissionSystem               != Value.m_vEmissionSystem )            return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Electromagnetic_Emission_PDU::operator != ( const Electromagnetic_Emission_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////





