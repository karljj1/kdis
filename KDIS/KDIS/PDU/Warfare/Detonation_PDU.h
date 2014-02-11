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
    class:      Detonation_PDU
    DIS:        (5) 1278.1 - 1995 & (7) 1278.1-2012(when using descriptors that are not MunitionDescriptors)    
	updated:    22/04/2013
    author:     Karl Jones

    purpose:    Communicates detonation or impact of munitions.
    Size:       832 bits / 104 octets + 128n / 16n
*********************************************************************/

#pragma once

#include "./Warfare_Header.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/MunitionDescriptor.h"
#include "./../../DataTypes/VariableParameter.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Detonation_PDU : public Warfare_Header
{
protected:

    KDIS::DATA_TYPE::Vector m_Velocity;

    KDIS::DATA_TYPE::WorldCoordinates m_LocationWorldCoords;

    KDIS::DATA_TYPE::DescPtr m_pDescriptor;

    KDIS::DATA_TYPE::Vector m_LocationEntityCoords;

    KUINT8 m_ui8DetonationResult;

    KUINT8 m_ui8NumOfVariableParams;

    KUINT16 m_ui16Padding1;

	std::vector<KDIS::DATA_TYPE::VarPrmPtr> m_vVariableParameters;

public:

    static const KUINT16 DETONATION_PDU_SIZE = 104;

    Detonation_PDU();

    Detonation_PDU( KDataStream & stream ) throw( KException );

	Detonation_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Detonation_PDU( const KDIS::DATA_TYPE::EntityIdentifier & FiringEntID, const KDIS::DATA_TYPE::EntityIdentifier & TargetEntID,
                    const KDIS::DATA_TYPE::EntityIdentifier & MunitionID, const KDIS::DATA_TYPE::EntityIdentifier & EventID,
                    const KDIS::DATA_TYPE::Vector & Velocity, const KDIS::DATA_TYPE::WorldCoordinates & LocationWorldCoords,
                    KDIS::DATA_TYPE::DescPtr Desc, const KDIS::DATA_TYPE::Vector & LocationEntityCoords,
					KDIS::DATA_TYPE::ENUMS::DetonationResult DetonationResult );

    Detonation_PDU( const Warfare_Header & WarfareHeader, const KDIS::DATA_TYPE::Vector & Velocity,
                    const KDIS::DATA_TYPE::WorldCoordinates & LocationWorldCoords, KDIS::DATA_TYPE::DescPtr Desc,
					const KDIS::DATA_TYPE::Vector & LocationEntityCoords, KDIS::DATA_TYPE::ENUMS::DetonationResult DetonationResult );

    virtual ~Detonation_PDU();

	#if DIS_VERSION > 6
    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetPDUStatusDetonationType
    //              KDIS::PDU::Detonation_PDU::GetPDUStatusDetonationType
    // Description: Indicates the descriptor type used. DTI.
    // Parameter:   DetonationType FT
    //************************************
    void SetPDUStatusDetonationType( KDIS::DATA_TYPE::ENUMS::DetonationType DT );
    KDIS::DATA_TYPE::ENUMS::DetonationType GetPDUStatusDetonationType() const;
	#endif

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetVelocity
    //              KDIS::PDU::Detonation_PDU::GetVelocity
    // Description: Velocity of fire munition.
    // Parameter:   const Vector & V
    //************************************
    void SetVelocity( const KDIS::DATA_TYPE::Vector & V );
    const KDIS::DATA_TYPE::Vector & GetVelocity() const;
    KDIS::DATA_TYPE::Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetLocationInWorldCoords
    //              KDIS::PDU::Detonation_PDU::GetLocationInWorldCoords
    // Description: Location of detonation event in world
    //              coordinates.
    // Parameter:   const WorldCoordinates & L
    //************************************
    void SetLocationInWorldCoords( const KDIS::DATA_TYPE::WorldCoordinates & L );
    const KDIS::DATA_TYPE::WorldCoordinates & GetLocationInWorldCoords() const;
    KDIS::DATA_TYPE::WorldCoordinates & GetLocationInWorldCoords();

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetDescriptor
    //              KDIS::PDU::Detonation_PDU::GetDescriptor
    // Description: Descriptor, describes type of detonation. 
	//              Pre DIS 7 this will always be a MunitionDescriptor. 
	//              In DIS 7 a Detonation PDU can send a Munition, Expendable or an Explosion descriptor.
	//              Setting this in DIS 7 will automatically set the DTI (PDUStatusDetonationType) field and will 
	//              cause the protocol version to change to 7 if the type is Expendable or Explosion.
	//              I leave it as default if the type is Munition.
	//              Note: By default this value will be a MunitionDescriptor, it is not null by default.
	//              Example usage in DIS 7: SetDescriptor( DescPtr( new MunitionDescriptor() ) );
    // Parameter:   DescPtr D
    //************************************
    void SetDescriptor( KDIS::DATA_TYPE::DescPtr D );
    const KDIS::DATA_TYPE::DescPtr GetDescriptor() const;
    KDIS::DATA_TYPE::DescPtr GetDescriptor();

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetLocationInEntityCoords
    //              KDIS::PDU::Detonation_PDU::GetLocationInEntityCoords
    // Description: Location of detonation event in entity coordinates.
    //              Use for damage assessment to the entity.
    // Parameter:   const Vector & L
    //************************************
    void SetLocationInEntityCoords( const KDIS::DATA_TYPE::Vector & L );
    const KDIS::DATA_TYPE::Vector & GetLocationInEntityCoords() const;
    KDIS::DATA_TYPE::Vector & GetLocationInEntityCoords();

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::SetDetonationResult
    //              KDIS::PDU::Detonation_PDU::GetDetonationResult
    // Description: Represents the result of the detonation.
    // Parameter:   DetonationResult DR
    //************************************
    void SetDetonationResult( KDIS::DATA_TYPE::ENUMS::DetonationResult DR );
    KDIS::DATA_TYPE::ENUMS::DetonationResult GetDetonationResult() const;

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::GetNumberOfVariableParams
    // Description: Number of variable parameters.
    //************************************
    KUINT8 GetNumberOfVariableParams() const;

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::AddVariableParameter
    //              KDIS::PDU::Detonation_PDU::SetVariableParameter
    //              KDIS::PDU::Detonation_PDU::GetVariableParameters
    //              KDIS::PDU::Detonation_PDU::ClearVariableParameters
    // Description: Information associated with an entity or detonation, not otherwise accounted
    //	            for in a PDU such as Articulated and Attached Parts.
    //              See VariableParameter for supported/implemented types.
    // Parameter:   VarPrmPtr VP, vector<VarPrmPtr> & VP
    //************************************
    void AddVariableParameter( KDIS::DATA_TYPE::VarPrmPtr VP );
	void SetVariableParameters( const std::vector<KDIS::DATA_TYPE::VarPrmPtr> & VP );
	const std::vector<KDIS::DATA_TYPE::VarPrmPtr> & GetVariableParameters() const;
    void ClearVariableParameters();

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Detonation_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Detonation_PDU & Value ) const;
    KBOOL operator != ( const Detonation_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
