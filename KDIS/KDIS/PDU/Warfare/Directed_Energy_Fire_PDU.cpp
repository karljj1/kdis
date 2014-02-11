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

#include "./Directed_Energy_Fire_PDU.h"

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

Directed_Energy_Fire_PDU::Directed_Energy_Fire_PDU() :
	m_f32CumulativeShotTime( 0 ),
	m_f32AperDiameter( 0 ),
	m_f32Wavelength( 0 ),
	m_f32PeakIrradiance( 0 ),
	m_f32PulseRepFreq( 0 ),
	m_f32PulseWidth( 0 ),
	m_ui8PulseShp( 0 ),
	m_ui8Padding1( 0 ),
	m_ui32Padding2( 0 ),
	m_ui16Padding3( 0 ),
	m_ui16NumDERecs( 0 )
{
	m_ui8PDUType = DirectedEnergyFire_PDU_Type;
    m_ui16PDULength = DIRECTED_ENERGY_PDU_SIZE;
	m_ui8ProtocolFamily = Warfare;
    m_ui8ProtocolVersion = IEEE_1278_1_2012;
	m_DeUnion.m_ui16Flags = 0;
}

//////////////////////////////////////////////////////////////////////////

Directed_Energy_Fire_PDU::Directed_Energy_Fire_PDU( const EntityIdentifier & FireID, const EntityIdentifier & EventID,
												    const EntityType & MunitionType, const ClockTime & ShotStartTime, 
												    KFLOAT32 CumulativeShotTime, const Vector & EmitterLocation, 
												    KFLOAT32 ApertureDiameter, KFLOAT32 Wavelength, KFLOAT32 PeakIrradiance, 
												    KFLOAT32 PulseRepetitionFrequency, KFLOAT32 PulseWidth, 
												    KBOOL WeaponState, KBOOL UpdateState, BeamSpotShape PS ) :
	m_FiringEntityID( FireID ),
	m_EventID( EventID ),
	m_MunTyp( MunitionType ),
	m_ShotStartTime( ShotStartTime ),
	m_f32CumulativeShotTime( CumulativeShotTime ),
	m_EmitterLoc( EmitterLocation ),
	m_f32AperDiameter( ApertureDiameter ),
	m_f32Wavelength( Wavelength ),
	m_f32PeakIrradiance( PeakIrradiance ),
	m_f32PulseRepFreq( PulseRepetitionFrequency ),
	m_f32PulseWidth( PulseWidth ),	
	m_ui8PulseShp( PS ),
	m_ui8Padding1( 0 ),
	m_ui32Padding2( 0 ),
	m_ui16Padding3( 0 ),
	m_ui16NumDERecs( 0 )
{
	m_ui8PDUType = DirectedEnergyFire_PDU_Type;
    m_ui16PDULength = DIRECTED_ENERGY_PDU_SIZE;
	m_ui8ProtocolFamily = Warfare;
    m_ui8ProtocolVersion = IEEE_1278_1_2012;
	m_DeUnion.m_ui16WeaponState = WeaponState;
	m_DeUnion.m_ui16StateUpdate = UpdateState;
}

//////////////////////////////////////////////////////////////////////////

Directed_Energy_Fire_PDU::Directed_Energy_Fire_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Directed_Energy_Fire_PDU::Directed_Energy_Fire_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Directed_Energy_Fire_PDU::~Directed_Energy_Fire_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetFiringEntityID( const EntityIdentifier & ID )
{
    m_FiringEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Directed_Energy_Fire_PDU::GetFiringEntityID() const
{
    return m_FiringEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Directed_Energy_Fire_PDU::GetFiringEntityID()
{
    return m_FiringEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetEventID( const EntityIdentifier & ID )
{
    m_EventID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Directed_Energy_Fire_PDU::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Directed_Energy_Fire_PDU::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetMunitionType( const EntityType & MT )
{
	m_MunTyp = MT;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & Directed_Energy_Fire_PDU::GetMunitionType() const
{
	return m_MunTyp;
}

//////////////////////////////////////////////////////////////////////////

EntityType & Directed_Energy_Fire_PDU::GetMunitionType()
{
	return m_MunTyp;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetShotStartTime( const ClockTime & SST )
{
	m_ShotStartTime = SST;
}

//////////////////////////////////////////////////////////////////////////

const ClockTime & Directed_Energy_Fire_PDU::GetShotStartTime() const
{
	return m_ShotStartTime;
}

//////////////////////////////////////////////////////////////////////////

ClockTime & Directed_Energy_Fire_PDU::GetShotStartTime()
{
	return m_ShotStartTime;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetCumulativeShotTime( KFLOAT32 CST )
{
	m_f32CumulativeShotTime = CST;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Directed_Energy_Fire_PDU::GetCumulativeShotTime() const
{
	return m_f32CumulativeShotTime;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetEmitterLocation( const Vector & EL )
{
	m_EmitterLoc = EL;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Directed_Energy_Fire_PDU::GetEmitterLocation() const
{
	return m_EmitterLoc;
}

//////////////////////////////////////////////////////////////////////////

Vector & Directed_Energy_Fire_PDU::GetEmitterLocation()
{
	return m_EmitterLoc;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetApertureDiameter( KFLOAT32 AD )
{
	m_f32AperDiameter = AD;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Directed_Energy_Fire_PDU::GetApertureDiameter() const
{
	return m_f32AperDiameter;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetWavelength( KFLOAT32 W )
{
	m_f32Wavelength = W;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Directed_Energy_Fire_PDU::GetWavelength() const
{
	return m_f32Wavelength;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetPeakIrradiance( KFLOAT32 PI )
{
	m_f32PeakIrradiance = PI;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Directed_Energy_Fire_PDU::GetPeakIrradiance() const
{
	return m_f32PeakIrradiance;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetPulseRepetitionFrequency( KFLOAT32 PRF )
{
	m_f32PulseRepFreq = PRF;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Directed_Energy_Fire_PDU::GetPulseRepetitionFrequency() const
{
	return m_f32PulseRepFreq;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetPulseWidth( KFLOAT32 PW )
{
	m_f32PulseWidth = PW;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Directed_Energy_Fire_PDU::GetPulseWidth() const
{
	return m_f32PulseWidth;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetFlagWeaponState( KBOOL WS )
{
	m_DeUnion.m_ui16WeaponState = WS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Directed_Energy_Fire_PDU::GetFlagWeaponState() const
{
	return m_DeUnion.m_ui16WeaponState;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetFlagStateUpdate( KBOOL SU )
{
	m_DeUnion.m_ui16StateUpdate = SU;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Directed_Energy_Fire_PDU::GetFlagStateUpdate() const
{
	return m_DeUnion.m_ui16StateUpdate;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetPulseShape( BeamSpotShape PS )
{
	m_ui8PulseShp = PS;
}

//////////////////////////////////////////////////////////////////////////

BeamSpotShape Directed_Energy_Fire_PDU::GetPulseShape() const
{
	return ( BeamSpotShape )m_ui8PulseShp;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Directed_Energy_Fire_PDU::GetNumberOfDirectedEnergyRecords() const
{
	return m_ui16NumDERecs;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::AddDirectedEnergyRecord( StdVarPtr DE )
{
	m_vDeRec.push_back( DE );
	++m_ui16NumDERecs;
	m_ui16PDULength += DE->GetRecordLength();
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::SetDirectedEnergyRecords( const vector<StdVarPtr> & DE )
{
	m_vDeRec = DE;
	m_ui16NumDERecs = DE.size();
	m_ui16PDULength = DIRECTED_ENERGY_PDU_SIZE;

	// Calculate new pdu length
	vector<StdVarPtr>::const_iterator citr = DE.begin();
	vector<StdVarPtr>::const_iterator citrEnd = DE.end();
	for( ; citr != citrEnd; ++citr )
	{
		m_ui16PDULength += ( *citr )->GetRecordLength();
	}
}

//////////////////////////////////////////////////////////////////////////

const vector<StdVarPtr> & Directed_Energy_Fire_PDU::GetDirectedEnergyRecords() const
{
	return m_vDeRec;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::ClearDirectedEnergyRecords()
{
	m_vDeRec.clear();
	m_ui16NumDERecs = 0;
	m_ui16PDULength = DIRECTED_ENERGY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString Directed_Energy_Fire_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Directed Energy Fire PDU-\n"
	   << "Firing Entity ID:\n"
       << IndentString( m_FiringEntityID.GetAsString(), 1 )
	   << "Event ID:\n"
       << IndentString( m_EventID.GetAsString(), 1 )
	   << "Munition Type:              " << m_MunTyp.GetAsString()
	   << "Shot Start Time:            " << m_ShotStartTime.GetAsString()
	   << "Cumulative Shot Time:       " << m_f32CumulativeShotTime                       << "\n"
	   << "Emitter Location:           " << m_EmitterLoc.GetAsString() 
	   << "Aperture Diameter:          " << m_f32AperDiameter                             << "\n"
	   << "Wavelength:                 " << m_f32Wavelength                               << "\n"
	   << "Peak Irradiance:            " << m_f32PeakIrradiance                           << "\n"
	   << "Pulse Repetition Frequency: " << m_f32PulseRepFreq                             << "\n"
	   << "Pulse Width:                " << m_f32PulseWidth                               << "\n"
	   << "Flags:\n"
	   << "\tWeapon State: "             << m_DeUnion.m_ui16WeaponState                   << "\n"
	   << "\tState Update: "             << m_DeUnion.m_ui16StateUpdate                   << "\n"
	   << "Pulse Shape:                " << GetEnumAsStringBeamSpotShape( m_ui8PulseShp ) << "\n"
	   << "Number Of DE Records:       " << m_ui16NumDERecs                               << "\n"
	   << "DE Records:\n";

	vector<StdVarPtr>::const_iterator citr = m_vDeRec.begin();
	vector<StdVarPtr>::const_iterator citrEnd = m_vDeRec.end();
	for( ; citr != citrEnd; ++citr )
	{
		ss << ( *citr )->GetAsString();
	}

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < DIRECTED_ENERGY_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	m_vDeRec.clear();

	Header::Decode( stream, ignoreHeader );	

	stream >> KDIS_STREAM m_FiringEntityID
		   >> KDIS_STREAM m_EventID
		   >> KDIS_STREAM m_MunTyp
		   >> KDIS_STREAM m_ShotStartTime
		   >> m_f32CumulativeShotTime
		   >> KDIS_STREAM m_EmitterLoc
		   >> m_f32AperDiameter
		   >> m_f32Wavelength
		   >> m_f32PeakIrradiance
		   >> m_f32PulseRepFreq
		   >> m_f32PulseWidth
		   >> m_DeUnion.m_ui16Flags
		   >> m_ui8PulseShp
		   >> m_ui8Padding1
		   >> m_ui32Padding2
		   >> m_ui16Padding3
		   >> m_ui16NumDERecs;

	for( KUINT16 i = 0; i < m_ui16NumDERecs; ++i )
	{
		// Save the current write position so we can peek.
		KUINT16 pos = stream.GetCurrentWritePosition();
		KUINT32 datumID;

		// Extract the datum id then reset the stream.
		stream >> datumID;
		stream.SetCurrentWritePosition( pos );

		// Use the factory decoder. 
		StandardVariable * p = StandardVariable::FactoryDecode( datumID, stream );

		// Did we find a custom decoder? if not then use the default.
		if( p )
		{
			m_vDeRec.push_back( StdVarPtr( p ) );
		}
		else
		{
			// Default
			m_vDeRec.push_back( StdVarPtr( new StandardVariable( stream ) ) );
		}
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream Directed_Energy_Fire_PDU::Encode() const
{
    KDataStream stream;

    Directed_Energy_Fire_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Directed_Energy_Fire_PDU::Encode( KDataStream & stream ) const
{
	Header::Encode( stream );

	stream << KDIS_STREAM m_FiringEntityID
		   << KDIS_STREAM m_EventID
		   << KDIS_STREAM m_MunTyp
		   << KDIS_STREAM m_ShotStartTime
		   << m_f32CumulativeShotTime
		   << KDIS_STREAM m_EmitterLoc
		   << m_f32AperDiameter
		   << m_f32Wavelength
		   << m_f32PeakIrradiance
		   << m_f32PulseRepFreq
		   << m_f32PulseWidth
		   << m_DeUnion.m_ui16Flags
		   << m_ui8PulseShp
		   << m_ui8Padding1
		   << m_ui32Padding2
		   << m_ui16Padding3
		   << m_ui16NumDERecs;

	vector<StdVarPtr>::const_iterator citr = m_vDeRec.begin();
	vector<StdVarPtr>::const_iterator citrEnd = m_vDeRec.end();
	for( ; citr != citrEnd; ++citr )
	{
		( *citr )->Encode( stream );
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL Directed_Energy_Fire_PDU::operator == ( const Directed_Energy_Fire_PDU & Value ) const
{
    if( Header::operator        !=( Value ) )                      return false;
    if( m_FiringEntityID        != Value.m_FiringEntityID )        return false;
    if( m_EventID               != Value.m_EventID )               return false;
    if( m_MunTyp                != Value.m_MunTyp )                return false;
    if( m_ShotStartTime         != Value.m_ShotStartTime )         return false;
    if( m_f32CumulativeShotTime != Value.m_f32CumulativeShotTime ) return false;
    if( m_EmitterLoc            != Value.m_EmitterLoc )            return false;
    if( m_f32AperDiameter       != Value.m_f32AperDiameter )       return false;
    if( m_f32Wavelength         != Value.m_f32Wavelength )         return false;
    if( m_f32PeakIrradiance     != Value.m_f32PeakIrradiance )     return false;
    if( m_f32PulseRepFreq       != Value.m_f32PulseRepFreq )       return false;
    if( m_f32PulseWidth         != Value.m_f32PulseWidth )         return false;
    if( m_DeUnion.m_ui16Flags   != Value.m_DeUnion.m_ui16Flags )   return false;
	if( m_ui8PulseShp           != Value.m_ui8PulseShp )           return false;
    if( m_ui16NumDERecs         != Value.m_ui16NumDERecs )         return false;
	if( m_vDeRec                != Value.m_vDeRec )                return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Directed_Energy_Fire_PDU::operator != ( const Directed_Energy_Fire_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////







