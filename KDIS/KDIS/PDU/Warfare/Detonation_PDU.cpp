/*********************************************************************
Copyright 2013 KDIS
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

#include "./Detonation_PDU.h"

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

Detonation_PDU::Detonation_PDU( void ) :
    m_ui8NumOfArticulationParams( 0 )
{
    m_ui8PDUType = Detonation_PDU_Type;
    m_ui16PDULength = DETONATION_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Detonation_PDU::Detonation_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Detonation_PDU::Detonation_PDU( const EntityIdentifier & FiringEntID, const EntityIdentifier & TargetEntID,
                                const EntityIdentifier & MunitionID, const EntityIdentifier & EventID ,
                                const Vector & Velocity, const WorldCoordinates & LocationWorldCoords,
                                const BurstDescriptor & Burst, const Vector & LocationEntityCoords,
                                DetonationResult DetonationResult ) :
    Warfare_Header( FiringEntID, TargetEntID, MunitionID, EventID ),
    m_Velocity( Velocity ),
    m_LocationWorldCoords( LocationWorldCoords ),
    m_BurstDescriptor( Burst ),
    m_LocationEntityCoords( LocationEntityCoords ),
    m_ui8DetonationResult( DetonationResult ),
    m_ui8NumOfArticulationParams( 0 ),
    m_ui16Padding1( 0 )
{
    m_ui8PDUType = Detonation_PDU_Type;
    m_ui16PDULength = DETONATION_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Detonation_PDU::Detonation_PDU( const Warfare_Header & WarfareHeader, const Vector & Velocity,
                                const WorldCoordinates & LocationWorldCoords, const BurstDescriptor & Burst,
                                const Vector & LocationEntityCoords, DetonationResult DetonationResult ) :
    Warfare_Header( WarfareHeader ),
    m_Velocity( Velocity ),
    m_LocationWorldCoords( LocationWorldCoords ),
    m_BurstDescriptor( Burst ),
    m_LocationEntityCoords( LocationEntityCoords ),
    m_ui8DetonationResult( DetonationResult ),
    m_ui8NumOfArticulationParams( 0 ),
    m_ui16Padding1( 0 )
{
    m_ui8PDUType = Detonation_PDU_Type;
    m_ui16PDULength = DETONATION_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Detonation_PDU::~Detonation_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetVelocity( const Vector & V )
{
    m_Velocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Detonation_PDU::GetVelocity() const
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & Detonation_PDU::GetVelocity()
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetLocationInWorldCoords( const WorldCoordinates & L )
{
    m_LocationWorldCoords = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & Detonation_PDU::GetLocationInWorldCoords() const
{
    return m_LocationWorldCoords;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & Detonation_PDU::GetLocationInWorldCoords()
{
    return m_LocationWorldCoords;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetBurstDescriptor( const BurstDescriptor & BD )
{
    m_BurstDescriptor = BD;
}

//////////////////////////////////////////////////////////////////////////

const BurstDescriptor & Detonation_PDU::GetBurstDescriptor() const
{
    return m_BurstDescriptor;
}

//////////////////////////////////////////////////////////////////////////

BurstDescriptor & Detonation_PDU::GetBurstDescriptor()
{
    return m_BurstDescriptor;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetLocationInEntityCoords( const Vector & L )
{
    m_LocationEntityCoords = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Detonation_PDU::GetLocationInEntityCoords() const
{
    return m_LocationEntityCoords;
}

//////////////////////////////////////////////////////////////////////////

Vector & Detonation_PDU::GetLocationInEntityCoords()
{
    return m_LocationEntityCoords;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetDetonationResult( DetonationResult DR )
{
    m_ui8DetonationResult = DR;
}

//////////////////////////////////////////////////////////////////////////

DetonationResult Detonation_PDU::GetDetonationResult() const
{
    return ( DetonationResult )m_ui8DetonationResult;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Detonation_PDU::GetNumberOfArticulationParams() const
{
    return m_ui8NumOfArticulationParams;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::AddArticulationParameter( const ArticulationParameters & AP )
{
    m_vArticulationParameters.push_back( AP );
    ++m_ui8NumOfArticulationParams;
    m_ui16PDULength += ArticulationParameters::ARTICULATION_PARAMETERS_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetArticulationParameter( const vector<ArticulationParameters> & AP )
{
    m_vArticulationParameters = AP;
    m_ui8NumOfArticulationParams = m_vArticulationParameters.size();
    m_ui16PDULength = DETONATION_PDU_SIZE + ( m_ui8NumOfArticulationParams * ArticulationParameters::ARTICULATION_PARAMETERS_SIZE );
}

//////////////////////////////////////////////////////////////////////////

const vector<ArticulationParameters> & Detonation_PDU::GetArticulationParameters() const
{
    return m_vArticulationParameters;
}

//////////////////////////////////////////////////////////////////////////

KString Detonation_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Detonation PDU-\n"
       << Warfare_Header::GetAsString()
       << "Velocity:                 " << m_Velocity.GetAsString()
       << "World Location:           " << m_LocationWorldCoords.GetAsString()
       << m_BurstDescriptor.GetAsString()
       << "Entity Location:          " << m_LocationEntityCoords.GetAsString()
       << "Detonation Result:        " << GetEnumAsStringDetonationResult( m_ui8DetonationResult ) << "\n"
       << "Num Articulation Params:  " << ( KUINT16 )m_ui8NumOfArticulationParams
       << "\n";

    // Add the articulated parts
    vector<ArticulationParameters>::const_iterator citr = m_vArticulationParameters.begin();
    vector<ArticulationParameters>::const_iterator citrEnd = m_vArticulationParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ss << IndentString( citr->GetAsString(), 1 );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < DETONATION_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Warfare_Header::Decode( stream );

    stream >> KDIS_STREAM m_Velocity
           >> KDIS_STREAM m_LocationWorldCoords
           >> KDIS_STREAM m_BurstDescriptor
           >> KDIS_STREAM m_LocationEntityCoords
           >> m_ui8DetonationResult
           >> m_ui8NumOfArticulationParams
           >> m_ui16Padding1;

    for( KUINT16 i = 0; i < m_ui8NumOfArticulationParams; ++i )
    {
        ArticulationParameters ap;
        stream >> KDIS_STREAM ap;
        m_vArticulationParameters.push_back( ap );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Detonation_PDU::Encode() const
{
    KDataStream stream;

    Detonation_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::Encode( KDataStream & stream ) const
{
    Warfare_Header::Encode( stream );

    stream << KDIS_STREAM m_Velocity
           << KDIS_STREAM m_LocationWorldCoords
           << KDIS_STREAM m_BurstDescriptor
           << KDIS_STREAM m_LocationEntityCoords
           << m_ui8DetonationResult
           << m_ui8NumOfArticulationParams
           << m_ui16Padding1;

    // Add the articulated parts
    vector<ArticulationParameters>::const_iterator citr = m_vArticulationParameters.begin();
    vector<ArticulationParameters>::const_iterator citrEnd = m_vArticulationParameters.end();

    for( ; citr != citrEnd; ++ citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Detonation_PDU::operator == ( const Detonation_PDU & Value ) const
{
    if( Warfare_Header::operator     !=( Value ) )                           return false;
    if( m_Velocity                   != Value.m_Velocity )                   return false;
    if( m_LocationWorldCoords        != Value.m_LocationWorldCoords )        return false;
    if( m_BurstDescriptor            != Value.m_BurstDescriptor )            return false;
    if( m_LocationEntityCoords       != Value.m_LocationEntityCoords )       return false;
    if( m_ui8DetonationResult        != Value.m_ui8DetonationResult )        return false;
    if( m_ui8NumOfArticulationParams != Value.m_ui8NumOfArticulationParams ) return false;
    if( m_vArticulationParameters    != Value.m_vArticulationParameters )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Detonation_PDU::operator != ( const Detonation_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


