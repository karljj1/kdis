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

#include "./Underwater_Acoustic_PDU.h"

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

Underwater_Acoustic_PDU::Underwater_Acoustic_PDU() :
    m_ui8Padding1( 0 ),
    m_ui8NumAPA( 0 ),
    m_ui8NumEmitterSys( 0 ),
    m_ui8NumShafts( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = UnderwaterAcoustic_PDU_Type;
    m_ui16PDULength = UNDERWATER_ACOUSTIC_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Underwater_Acoustic_PDU::Underwater_Acoustic_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Underwater_Acoustic_PDU::Underwater_Acoustic_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Underwater_Acoustic_PDU::~Underwater_Acoustic_PDU()
{
    m_vShafts.clear();
    m_vAPA.clear();
    m_vUAES.clear();
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::SetEmittingEntityID( const EntityIdentifier & ID )
{
    m_EmittingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Underwater_Acoustic_PDU::GetEmittingEntityID() const
{
    return m_EmittingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Underwater_Acoustic_PDU::GetEmittingEntityID()
{
    return m_EmittingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::SetEventID( const EntityIdentifier & ID )
{
    m_EventID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Underwater_Acoustic_PDU::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Underwater_Acoustic_PDU::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::SetStateUpdateIndicator( StateUpdateIndicator SUI )
{
    m_ui8StateUpdateIndicator = SUI;
}

//////////////////////////////////////////////////////////////////////////

StateUpdateIndicator Underwater_Acoustic_PDU::GetStateUpdateIndicator() const
{
    return ( StateUpdateIndicator )m_ui8StateUpdateIndicator;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::SetPassiveParameterIndex( PassiveParameterIndex PPI )
{
    m_ui16PassiveParamIndex = PPI;
}

//////////////////////////////////////////////////////////////////////////

PassiveParameterIndex Underwater_Acoustic_PDU::GetPassiveParameterIndex() const
{
    return ( PassiveParameterIndex )m_ui16PassiveParamIndex;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::SetPropulsionPlantConfiguration( PropulsionPlantConfiguration PPC )
{
    m_ui8PropPlantConfig = PPC;
}

//////////////////////////////////////////////////////////////////////////

PropulsionPlantConfiguration Underwater_Acoustic_PDU::GetPropulsionPlantConfiguration() const
{
    return ( PropulsionPlantConfiguration )m_ui8PropPlantConfig;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Underwater_Acoustic_PDU::GetNumberOfShafts() const
{
    return m_ui8NumShafts;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Underwater_Acoustic_PDU::GetNumberOfAPA() const
{
    return m_ui8NumAPA;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Underwater_Acoustic_PDU::GetNumberOfUAEmitterSystems() const
{
    return m_ui8NumEmitterSys;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::AddShaft( const Shaft & S )
{
    ++m_ui8NumShafts;
    m_vShafts.push_back( S );
    m_ui16PDULength += Shaft::SHAFT_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::SetShafts( const vector<Shaft> & S )
{
    // Reset PDU length
    m_ui16PDULength -= m_vShafts.size() * Shaft::SHAFT_SIZE;

    m_vShafts = S;

    // Calculate the new PDU length
    m_ui16PDULength += m_vShafts.size() * Shaft::SHAFT_SIZE;

    m_ui8NumShafts = m_vShafts.size();
}

//////////////////////////////////////////////////////////////////////////

const vector<Shaft> & Underwater_Acoustic_PDU::GetShafts() const
{
    return m_vShafts;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::AddAPA( const APA & A )
{
    ++m_ui8NumAPA;
    m_vAPA.push_back( A );
    m_ui16PDULength += APA::APA_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::SetAPA( const vector<APA> & A )
{
    // Reset PDU length
    m_ui16PDULength -= m_vAPA.size() * APA::APA_SIZE;

    m_vAPA= A;

    // Calculate the new PDU length
    m_ui16PDULength += m_vAPA.size() * APA::APA_SIZE;

    m_ui8NumAPA = m_vAPA.size();
}

//////////////////////////////////////////////////////////////////////////

const vector<APA> & Underwater_Acoustic_PDU::GetAPA() const
{
    return m_vAPA;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::AddUnderwaterAcousticEmitterSystem( const UnderwaterAcousticEmitterSystem & UAES )
{
    ++m_ui8NumEmitterSys;
    m_vUAES.push_back( UAES );
    m_ui16PDULength += UAES.GetEmitterSystemDataLength() * 4;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::SetUnderwaterAcousticEmitterSystem( const vector<UnderwaterAcousticEmitterSystem> & UAES )
{
    // Reset PDU length
    vector<UnderwaterAcousticEmitterSystem>::const_iterator citr = m_vUAES.begin();
    vector<UnderwaterAcousticEmitterSystem>::const_iterator citrEnd = m_vUAES.end();

    for( ; citr != citrEnd; ++citr )
    {
        m_ui16PDULength -= citr->GetEmitterSystemDataLength() * 4;
    }

    m_vUAES = UAES;

    citr = m_vUAES.begin();

    for( ; citr != m_vUAES.end(); ++citr )
    {
        m_ui16PDULength += citr->GetEmitterSystemDataLength() * 4;
    }

    m_ui8NumEmitterSys = m_vUAES.size();
}

//////////////////////////////////////////////////////////////////////////

const vector<UnderwaterAcousticEmitterSystem> & Underwater_Acoustic_PDU::GetUnderwaterAcousticEmitterSystem() const
{
    return m_vUAES;
}

//////////////////////////////////////////////////////////////////////////

KString Underwater_Acoustic_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Underwater Acoustic PDU-\n"
       << "Emitting Entity ID:\n"
       << IndentString( m_EmittingEntityID.GetAsString(), 1 )
       << "Event ID:\n"
       << IndentString( m_EventID.GetAsString(), 1 )
       << "State Update Indicator:  " << GetEnumAsStringStateUpdateIndicator( m_ui8StateUpdateIndicator )    << "\n"
       << "Passive Parameter Index: " << GetEnumAsStringPassiveParameterIndex( m_ui16PassiveParamIndex )     << "\n"
       << "Prop Plant Config:       " << GetEnumAsStringPropulsionPlantConfiguration( m_ui8PropPlantConfig ) << "\n"
       << "Number Of Shafts:        " << ( KUINT16 )m_ui8NumShafts               << "\n"
       << "Number Of APA:           " << ( KUINT16 )m_ui8NumAPA                  << "\n"
       << "Number Of UAES:          " << ( KUINT16 )m_ui8NumEmitterSys           << "\n";

    vector<Shaft>::const_iterator citrShafts = m_vShafts.begin();
    vector<Shaft>::const_iterator citrShaftsEnd = m_vShafts.end();
    for( ; citrShafts != citrShaftsEnd; ++citrShafts )
    {
        ss << citrShafts->GetAsString();
    }

    vector<APA>::const_iterator citrAPA =  m_vAPA.begin();
    vector<APA>::const_iterator citrAPAEnd =  m_vAPA.end();
    for( ; citrAPA != citrAPAEnd; ++citrAPA )
    {
        ss << citrAPA->GetAsString();
    }

    vector<UnderwaterAcousticEmitterSystem>::const_iterator citrUAES = m_vUAES.begin();
    vector<UnderwaterAcousticEmitterSystem>::const_iterator citrUAESEnd = m_vUAES.end();
    for( ; citrUAES != citrUAESEnd; ++citrUAES )
    {
        ss << citrUAES->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < UNDERWATER_ACOUSTIC_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_EmittingEntityID
           >> KDIS_STREAM m_EventID
           >> m_ui8StateUpdateIndicator
           >> m_ui8Padding1
           >> m_ui16PassiveParamIndex
           >> m_ui8PropPlantConfig
           >> m_ui8NumShafts
           >> m_ui8NumAPA
           >> m_ui8NumEmitterSys;

    m_vShafts.clear();
    m_vAPA.clear();
    m_vUAES.clear();

    for( KUINT8 i = 0; i < m_ui8NumShafts; ++i )
    {
        Shaft sft;
        stream >> KDIS_STREAM sft;
        m_vShafts.push_back( sft );
    }

    for( KUINT8 i = 0; i < m_ui8NumAPA; ++i )
    {
        APA apa;
        stream >> KDIS_STREAM apa;
        m_vAPA.push_back( apa );
    }

    for( KUINT8 i = 0; i < m_ui8NumEmitterSys; ++i )
    {
        UnderwaterAcousticEmitterSystem uaes;
        stream >> KDIS_STREAM uaes;
        m_vUAES.push_back( uaes );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Underwater_Acoustic_PDU::Encode() const
{
    KDataStream stream;

    Underwater_Acoustic_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Underwater_Acoustic_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_EmittingEntityID
           << KDIS_STREAM m_EventID
           << m_ui8StateUpdateIndicator
           << m_ui8Padding1
           << m_ui16PassiveParamIndex
           << m_ui8PropPlantConfig
           << m_ui8NumShafts
           << m_ui8NumAPA
           << m_ui8NumEmitterSys;

    vector<Shaft>::const_iterator citrShafts = m_vShafts.begin();

    for( ; citrShafts != m_vShafts.end(); ++citrShafts )
    {
        stream << KDIS_STREAM *citrShafts;
    }

    vector<APA>::const_iterator citrAPA =  m_vAPA.begin();

    for( ; citrAPA != m_vAPA.end(); ++citrAPA )
    {
        stream << KDIS_STREAM *citrAPA;
    }

    vector<UnderwaterAcousticEmitterSystem>::const_iterator citrUAES = m_vUAES.begin();

    for( ; citrUAES != m_vUAES.end(); ++citrUAES )
    {
        stream << KDIS_STREAM *citrUAES;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Underwater_Acoustic_PDU::operator == ( const Underwater_Acoustic_PDU & Value ) const
{
    if( Header::operator          !=( Value ) )                         return false;
    if( m_EmittingEntityID        != Value.m_EmittingEntityID )         return false;
    if( m_EventID                 != Value.m_EventID )                  return false;
    if( m_ui8StateUpdateIndicator != Value.m_ui8StateUpdateIndicator )  return false;
    if( m_ui16PassiveParamIndex   != Value.m_ui16PassiveParamIndex )    return false;
    if( m_ui8PropPlantConfig      != Value.m_ui8PropPlantConfig )       return false;
    if( m_ui8NumShafts            != Value.m_ui8NumShafts )             return false;
    if( m_ui8NumAPA               != Value.m_ui8NumAPA )                return false;
    if( m_ui8NumEmitterSys        != Value.m_ui8NumEmitterSys )         return false;
    if( m_vShafts                 != Value.m_vShafts )                  return false;
    if( m_vAPA                    != Value.m_vAPA )                     return false;
    if( m_vUAES                   != Value.m_vUAES )                   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Underwater_Acoustic_PDU::operator != ( const Underwater_Acoustic_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////





