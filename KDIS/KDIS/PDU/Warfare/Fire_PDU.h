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
    class:      Fire_PDU
    DIS:        (5) 1278.1 - 1995 & (7) 1278.1-2012(when using descriptors that are not MunitionDescriptors)    
	updated:    22/04/2013
    author:     Karl Jones

    purpose:    Communicates firing of munitions. 
    Size:       768 bits / 96 octets
*********************************************************************/

#pragma once

#include "./Warfare_Header.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/MunitionDescriptor.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Fire_PDU : public Warfare_Header
{
protected:

    KUINT32 m_ui32FireMissionIndex;

    KDIS::DATA_TYPE::WorldCoordinates m_Location;

	KDIS::DATA_TYPE::DescPtr m_pDescriptor;

    KDIS::DATA_TYPE::Vector m_Velocity;

    KFLOAT32 m_f32Range;

public:

    static const KUINT16 FIRE_PDU_SIZE = 96;

    Fire_PDU();

    Fire_PDU( KDataStream & stream ) throw( KException );

	Fire_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Fire_PDU( const Warfare_Header & WarfareHeader, KUINT32 FireMissionIndex, const KDIS::DATA_TYPE::WorldCoordinates & Location,
              KDIS::DATA_TYPE::DescPtr Desc, const KDIS::DATA_TYPE::Vector & Velocity, KFLOAT32 Range );

    Fire_PDU( const KDIS::DATA_TYPE::EntityIdentifier & FiringEntID, const KDIS::DATA_TYPE::EntityIdentifier & TargetEntID,
              const KDIS::DATA_TYPE::EntityIdentifier & MunitionID, const KDIS::DATA_TYPE::EntityIdentifier & EventID,
              KUINT32 FireMissionIndex, const KDIS::DATA_TYPE::WorldCoordinates & Location,
              KDIS::DATA_TYPE::DescPtr Desc, const KDIS::DATA_TYPE::Vector & Velocity, KFLOAT32 Range );

    virtual ~Fire_PDU();

	#if DIS_VERSION > 6
    //************************************
    // FullName:    KDIS::PDU::Fire_PDU::SetPDUStatusFireType
    //              KDIS::PDU::Fire_PDU::GetPDUStatusFireType
    // Description: Indicates the descriptor type used. FTI.
    // Parameter:   FireType FT
    //************************************
	void SetPDUStatusFireType( KDIS::DATA_TYPE::ENUMS::FireType FT );
	KDIS::DATA_TYPE::ENUMS::FireType GetPDUStatusFireType() const;
	#endif

    //************************************
    // FullName:    KDIS::PDU::Fire_PDU::SetFireMissionIndex
    //              KDIS::PDU::Fire_PDU::GetFireMissionIndex
    // Description: Identifies the fire mission. If unknown value will
    //              be symbolic value: NO_FIRE_MISSION
    // Parameter:   KUINT32 FMI
    //************************************
    void SetFireMissionIndex( KUINT32 FMI );
    KUINT32 GetFireMissionIndex() const;

    //************************************
    // FullName:    KDIS::PDU::Fire_PDU::SetLocation
    //              KDIS::PDU::Fire_PDU::GetLocation
    // Description: Location of fire event in world
    //              coordinates.
    // Parameter:   const WorldCoordinates & L
    //************************************
    void SetLocation( const KDIS::DATA_TYPE::WorldCoordinates & L );
    const KDIS::DATA_TYPE::WorldCoordinates & GetLocation() const;
    KDIS::DATA_TYPE::WorldCoordinates & GetLocation();

    //************************************
    // FullName:    KDIS::PDU::Fire_PDU::SetDescriptor
    //              KDIS::PDU::Fire_PDU::GetDescriptor
    // Description: Descriptor, describes type of munition. 
	//              Pre DIS 7 this will always be a MunitionDescriptor. 
	//              In DIS 7 a Fire PDU can send a Munition Descriptor or an Expendable
	//              Descriptor. Setting this in DIS 7 will automatically set the 
	//              FTI (PDUStatusFireType) field and will cause the protocol version to change to
	//              7 if the type is Expendable. I leave it as default if the type is Munition.
	//              Note: By default this value will be a MunitionDescriptor, it is not null by default.
	//              Example usage in DIS 7: SetDescriptor( DescPtr( new ExplosionDescriptor() ) );
    // Parameter:   DescPtr D
    //************************************
    void SetDescriptor( KDIS::DATA_TYPE::DescPtr D );
    const KDIS::DATA_TYPE::DescPtr GetDescriptor() const;
    KDIS::DATA_TYPE::DescPtr GetDescriptor();

    //************************************
    // FullName:    KDIS::PDU::Fire_PDU::SetVelocity
    //              KDIS::PDU::Fire_PDU::GetVelocity
    // Description: Velocity of fire munition.
    // Parameter:   const Vector & V
    //************************************
    void SetVelocity( const KDIS::DATA_TYPE::Vector & V );
    const KDIS::DATA_TYPE::Vector & GetVelocity() const;
    KDIS::DATA_TYPE::Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::PDU::Fire_PDU::SetRange
    //              KDIS::PDU::Fire_PDU::GetRange
    // Description: Range. Range that firing entity has
    //              calculated target to be.
    // Parameter:   KFLOAT32 R
    //************************************
    void SetRange( KFLOAT32 R );
    KFLOAT32 GetRange() const;

    //************************************
    // FullName:    KDIS::PDU::Fire_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Fire_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Fire_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Fire_PDU & Value ) const;
    KBOOL operator != ( const Fire_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
