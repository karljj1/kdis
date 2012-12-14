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

Electromagnetic_Emission_PDU::Electromagnetic_Emission_PDU( void ) :
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
    Decode( stream );
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

Electromagnetic_Emission_PDU::~Electromagnetic_Emission_PDU( void )
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

void Electromagnetic_Emission_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ELECTROMAGNETIC_EMISSION_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

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

    for( ; citr != m_vEmissionSystem.end(); ++citr )
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





