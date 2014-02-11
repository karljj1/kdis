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

/********************************************************************
    class:      Directed_Energy_Fire_PDU
    DIS:        (7) 1278.1-2012
    created:    04/07/2011
    author:     Karl Jones

    purpose:    The Directed Energy Fire PDU shall be used to communicate information associated 
				with the firing of a directed energy (DE) weapon. A DE weapon may be directed at 
				a specific target or at an area possibly containing several targets. Distinct 
				aimpoint record types are defined to describe these two general cases.
				When firing at a specific target a Precision Aimpoint is employed. The DE Precision
				Aimpoint record is most commonly used to represent the firing of a High Energy Laser.
				Other types of directed energy weapons propagate effects over a wide region.
				Representation of these weapons uses the Area Aimpoint record to describe characteristics and effects.

    Size:       704 bits / 88 octets - Min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/EntityType.h"
#include "./../../DataTypes/ClockTime.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/StandardVariable.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Directed_Energy_Fire_PDU : public Header
{
protected:

	KDIS::DATA_TYPE::EntityIdentifier m_FiringEntityID;

	KDIS::DATA_TYPE::EntityIdentifier m_EventID;

	KDIS::DATA_TYPE::EntityType m_MunTyp;

	KDIS::DATA_TYPE::ClockTime m_ShotStartTime;

	KFLOAT32 m_f32CumulativeShotTime;

	KDIS::DATA_TYPE::Vector m_EmitterLoc;

	KFLOAT32 m_f32AperDiameter;

	KFLOAT32 m_f32Wavelength;

	KFLOAT32 m_f32PeakIrradiance;

	KFLOAT32 m_f32PulseRepFreq;

	KFLOAT32 m_f32PulseWidth;

    union
    {
        struct
        {
			KUINT16 m_ui16WeaponState : 1;
			KUINT16 m_ui16StateUpdate : 1;
			KUINT16 m_ui16Reserved    : 14;
        };
        KUINT16 m_ui16Flags;
    } m_DeUnion;

	KUINT8 m_ui8PulseShp;

	KUINT8 m_ui8Padding1;
	KUINT32 m_ui32Padding2;
	KUINT16 m_ui16Padding3;

	KUINT16 m_ui16NumDERecs;

	std::vector<KDIS::DATA_TYPE::StdVarPtr> m_vDeRec;

public:

    static const KUINT16 DIRECTED_ENERGY_PDU_SIZE = 88; // Min size

    Directed_Energy_Fire_PDU();

	Directed_Energy_Fire_PDU( KDataStream & stream ) throw( KException );

	Directed_Energy_Fire_PDU( const Header & H, KDataStream & stream ) throw( KException );

	Directed_Energy_Fire_PDU( const KDIS::DATA_TYPE::EntityIdentifier & FireID, const KDIS::DATA_TYPE::EntityIdentifier & EventID,
                              const KDIS::DATA_TYPE::EntityType & MunitionType, const KDIS::DATA_TYPE::ClockTime & ShotStartTime, 
	                          KFLOAT32 CumulativeShotTime, const KDIS::DATA_TYPE::Vector & EmitterLocation, 
                              KFLOAT32 ApertureDiameter, KFLOAT32 Wavelength, KFLOAT32 PeakIrradiance, 
	                          KFLOAT32 PulseRepetitionFrequency, KFLOAT32 PulseWidth, 
							  KBOOL WeaponState, KBOOL UpdateState, KDIS::DATA_TYPE::ENUMS::BeamSpotShape PS );

    virtual ~Directed_Energy_Fire_PDU();

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetFiringEntityID
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetFiringEntityID
    // Description: The Firing Entity.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetFiringEntityID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetFiringEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetFiringEntityID();

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetEventID
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetEventID
    // Description: Event ID. Used to associate related firing/detonation
    //              events. If a detonation event if not proceeded
    //              by a firing event then the value shall be 0 (e.g land mines)
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetEventID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetEventID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetEventID();

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetMunitionType
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetMunitionType
    // Description: Identifies the munition type enumeration for the DE weapon beam.
    // Parameter:   const EntityType & MT
    //************************************
    void SetMunitionType( const KDIS::DATA_TYPE::EntityType & MT );
    const KDIS::DATA_TYPE::EntityType & GetMunitionType() const;
    KDIS::DATA_TYPE::EntityType & GetMunitionType();

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetShotStartTime
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetShotStartTime
    // Description: The simulation time at start of the shot.
    // Parameter:   const ClockTime & SST
    //************************************
    void SetShotStartTime( const KDIS::DATA_TYPE::ClockTime & SST );
    const KDIS::DATA_TYPE::ClockTime & GetShotStartTime() const;
    KDIS::DATA_TYPE::ClockTime & GetShotStartTime();

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetCumulativeShotTime
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetCumulativeShotTime
    // Description: The current cumulative duration of the shot in units of seconds.
    // Parameter:   KFLOAT32 CST
    //************************************
	void SetCumulativeShotTime( KFLOAT32 CST );
	KFLOAT32 GetCumulativeShotTime() const;

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetEmitterLocation
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetEmitterLocation
    // Description: Location of the DE weapon aperture/emitter.
	//				Represented by an Entity Coordinate Vector.
    // Parameter:   const Vector & EL
    //************************************
    void SetEmitterLocation( const KDIS::DATA_TYPE::Vector & EL );
    const KDIS::DATA_TYPE::Vector & GetEmitterLocation() const;
    KDIS::DATA_TYPE::Vector & GetEmitterLocation();

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetApertureDiameter
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetApertureDiameter
    // Description: The beam diameter at the aperture/emitter. In meters.
    // Parameter:   KFLOAT32 AD
    //************************************
	void SetApertureDiameter( KFLOAT32 AD );
	KFLOAT32 GetApertureDiameter() const;

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetWavelength
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetWavelength
    // Description: Emissions wavelength in units of meters.
    // Parameter:   KFLOAT32 AD
    //************************************
	void SetWavelength( KFLOAT32 W );
	KFLOAT32 GetWavelength() const;
	
    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetPeakIrradiance
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetPeakIrradiance
    // Description: Current peak irradiance of emissions in units of Watts per square meter. 
    // Parameter:   KFLOAT32 PI
    //************************************
	void SetPeakIrradiance( KFLOAT32 PI );
	KFLOAT32 GetPeakIrradiance() const;
	
    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetPulseRepetitionFrequency
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetPulseRepetitionFrequency
    // Description: Current pulse repetition frequency in units of cycles per second (Hertz).
    // Parameter:   KFLOAT32 PRF
    //************************************
	void SetPulseRepetitionFrequency( KFLOAT32 PRF );
	KFLOAT32 GetPulseRepetitionFrequency() const;

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetPulseWidth
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetPulseWidth
    // Description: Pulse width emissions in units of seconds.
    // Parameter:   KFLOAT32 PW
    //************************************
	void SetPulseWidth( KFLOAT32 PW );
	KFLOAT32 GetPulseWidth() const;

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetFlagWeaponState
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetFlagWeaponState
    // Description: true = weapon on, false = weapon off
    // Parameter:   KBOOL WS
    //************************************
	void SetFlagWeaponState( KBOOL WS );
	KBOOL GetFlagWeaponState() const;

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetFlagStateUpdate
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetFlagStateUpdate
    // Description: true = state changed, false = update due to heartbeat timer
    // Parameter:   KFLOAT32 SU
    //************************************
	void SetFlagStateUpdate( KBOOL SU );
	KBOOL GetFlagStateUpdate() const;

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::SetPulseShape
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetPulseShape
    // Description: Identifies the pulse shape .
    // Parameter:   BeamSpotShape PS
    //************************************
	void SetPulseShape( KDIS::DATA_TYPE::ENUMS::BeamSpotShape PS );
	KDIS::DATA_TYPE::ENUMS::BeamSpotShape GetPulseShape() const;

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::GetNumberOfDirectedEnergyRecords    
    // Description: Number of Directed Energy records stored in this PDU.
    //************************************
	KUINT16 GetNumberOfDirectedEnergyRecords() const;

	//************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::AddDirectedEnergyRecord
    //              KDIS::PDU::Directed_Energy_Fire_PDU::SetDirectedEnergyRecords
    //              KDIS::PDU::Directed_Energy_Fire_PDU::GetDirectedEnergyRecords
    //              KDIS::PDU::Directed_Energy_Fire_PDU::ClearDirectedEnergyRecords
    // Description: This field can contain one or more DE records and may also contain 
	//				other Standard Variable records.
    // Parameter:   StdVarPtr DE, const vector<StdVarPtr> & DE
	//************************************    
    void AddDirectedEnergyRecord( KDIS::DATA_TYPE::StdVarPtr DE );
    void SetDirectedEnergyRecords( const std::vector<KDIS::DATA_TYPE::StdVarPtr> & DE );
    const std::vector<KDIS::DATA_TYPE::StdVarPtr> & GetDirectedEnergyRecords() const;
	void ClearDirectedEnergyRecords();

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Directed_Energy_Fire_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Directed_Energy_Fire_PDU & Value ) const;
    KBOOL operator != ( const Directed_Energy_Fire_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
