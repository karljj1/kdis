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
    class:      Aggregate_State_PDU
    DIS:        (6) 1278.1A - 1998
    created:    07/02/2009
    author:     Karl Jones

    purpose:    Contains detailed information about aggregating entities.
    size:       1088 bits / 136 octets - min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/AggregateIdentifier.h"
#include "./../../DataTypes/AggregateType.h"
#include "./../../DataTypes/AggregateMarking.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/EulerAngles.h"
#include "./../../DataTypes/WorldCoordinates.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/SilentAggregateSystem.h"
#include "./../../DataTypes/SilentEntitySystem.h"
#include "./../../DataTypes/VariableDatum.h"
#include <vector>

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Aggregate_State_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::AggregateIdentifier m_AggregateID;

    KUINT8 m_ui8ForceID;

    KUINT8 m_ui8AggState;

    KDIS::DATA_TYPE::AggregateType m_AggregateType;

    KUINT32 m_ui32Formation;

    KDIS::DATA_TYPE::AggregateMarking m_AggregateMarking;

    KDIS::DATA_TYPE::Vector m_Dimensions;

    KDIS::DATA_TYPE::EulerAngles m_Ori;

    KDIS::DATA_TYPE::WorldCoordinates m_CtrOfMassLoc;

    KDIS::DATA_TYPE::Vector m_Vel;

    KUINT16 m_ui16NumAggregates;

    KUINT16 m_ui16NumEntities;

    KUINT16 m_ui16NumSilentAggregateTypes;

    KUINT16 m_ui16NumSilentEntityTypes;

    std::vector<KDIS::DATA_TYPE::AggregateIdentifier> m_vAI;

    std::vector<KDIS::DATA_TYPE::EntityIdentifier> m_vEI;

    KBOOL m_bNeedsPadding;
    KUINT16 m_ui16Padding1;
    KUINT16 m_ui16NumberOfPaddingOctets;

    std::vector<KDIS::DATA_TYPE::SilentAggregateSystem> m_vSASL;

    std::vector<KDIS::DATA_TYPE::SilentEntitySystem> m_vSESL;

    KUINT32 m_ui32NumVariableDatum;

    std::vector<KDIS::DATA_TYPE::VarDtmPtr> m_vVD;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::calcPadding
    // Description: Calculates the padding so the PDU lies on a 32 bit boundary.
    //************************************
    void calcPadding();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::updatePadding
    // Description: Calculates the padding so the PDU lies on a 32 bit boundary.
    //              Updates local member m_ui16NumberOfPaddingOctets and also
    //              inherited Header6::m_ui16PDULength.
    //************************************
    void updatePadding();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::needsPadding
    // Description: Returns true if padding is needed.
    //************************************
    bool needsPadding() const;

public:

    static const KUINT16 AGGREGATE_STATE_PDU_SIZE = 136; // Min size

    Aggregate_State_PDU();

    Aggregate_State_PDU( KDataStream & stream ) throw( KException );

    Aggregate_State_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Aggregate_State_PDU( const KDIS::DATA_TYPE::AggregateIdentifier & AI, KDIS::DATA_TYPE::ENUMS::ForceID FID, KDIS::DATA_TYPE::ENUMS::AggregateState AS,
                         const KDIS::DATA_TYPE::AggregateType & AT, KDIS::DATA_TYPE::ENUMS::Formation F, const KDIS::DATA_TYPE::AggregateMarking & AM,
                         const KDIS::DATA_TYPE::Vector & Dimensions, const KDIS::DATA_TYPE::EulerAngles & Orientation,
                         const KDIS::DATA_TYPE::WorldCoordinates & CenterOfMass, const KDIS::DATA_TYPE::Vector & Velocity );

    virtual ~Aggregate_State_PDU();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateIdentifier
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateIdentifier
    // Description: ID of the aggregate issuing the PDU.
    // Parameter:   const AggregateIdentifier & AI
    //************************************
    void SetAggregateIdentifier( const KDIS::DATA_TYPE::AggregateIdentifier & AI );
    const KDIS::DATA_TYPE::AggregateIdentifier & GetAggregateIdentifier() const;
    KDIS::DATA_TYPE::AggregateIdentifier & GetAggregateIdentifier();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetForceID
    //              KDIS::PDU::Aggregate_State_PDU::GetForceID
    // Description: Force ID of the aggregate, aggregates of opposing forces
    //              may not group together.
    // Parameter:   ForceID ID
    //************************************
    void SetForceID( KDIS::DATA_TYPE::ENUMS::ForceID ID );
    KDIS::DATA_TYPE::ENUMS::ForceID GetForceID() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateState
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateState
    // Description: Aggregate state enumeration.
    // Parameter:   AggregateState AS
    //************************************
    void SetAggregateState( KDIS::DATA_TYPE::ENUMS::AggregateState AS );
    KDIS::DATA_TYPE::ENUMS::AggregateState GetAggregateState() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateType
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateType
    // Description: Aggregate type enumerations.
    // Parameter:   const AggregateType & Type
    //************************************
    void SetAggregateType( const KDIS::DATA_TYPE::AggregateType & Type );
    const KDIS::DATA_TYPE::AggregateType & GetAggregateType() const;
    KDIS::DATA_TYPE::AggregateType & GetAggregateType();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetFormation
    //              KDIS::PDU::Aggregate_State_PDU::GetFormation
    // Description: Aggregate formation.
    // Parameter:   Formation F
    //************************************
    void SetFormation( KDIS::DATA_TYPE::ENUMS::Formation F );
    KDIS::DATA_TYPE::ENUMS::Formation GetFormation() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateMarking
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateMarking
    // Description: Aggregate marking.
    // Parameter:   const AggregateMarking & AM
    //************************************
    void SetAggregateMarking( const KDIS::DATA_TYPE::AggregateMarking & AM );
    const KDIS::DATA_TYPE::AggregateMarking & GetAggregateMarking() const;
    KDIS::DATA_TYPE::AggregateMarking & GetAggregateMarking();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateDimensions
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateDimensions
    // Description: Identifies the bounding space, in meters, that the aggregate
    //              occupies. These measurements are taken along the orientation
    //              axes of the aggregate. Measurements X, Y, and Z are taken from
    //              the center of mass of the aggregate to the shortest distance
    //              along an axis in the positive or negative direction that includes
    //              all of the constituent entities. See fig 38 from IEEE 1278.1A-1998.
    // Parameter:   const Vector & AD
    //************************************
    void SetAggregateDimensions( const KDIS::DATA_TYPE::Vector & AD );
    const KDIS::DATA_TYPE::Vector & GetAggregateDimensions() const;
    KDIS::DATA_TYPE::Vector & GetAggregateDimensions();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateOrientation
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateOrientation
    // Description: Orientation of the aggregate.
    //              Calculated by taking the average orientation of its
    //              constituent entities.
    // Parameter:   const EulerAngles & AO
    //************************************
    void SetAggregateOrientation( const KDIS::DATA_TYPE::EulerAngles & AO );
    const KDIS::DATA_TYPE::EulerAngles & GetAggregateOrientation() const;
    KDIS::DATA_TYPE::EulerAngles & GetAggregateOrientation();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetCenterOfMassLocation
    //              KDIS::PDU::Aggregate_State_PDU::GetCenterOfMassLocation
    // Description: Location of the aggregate’s center of mass in the simulated world.
    // Parameter:   const WorldCoordinates & COML
    //************************************
    void SetCenterOfMassLocation( const KDIS::DATA_TYPE::WorldCoordinates & COML );
    const KDIS::DATA_TYPE::WorldCoordinates & GetCenterOfMassLocation() const;
    KDIS::DATA_TYPE::WorldCoordinates & GetCenterOfMassLocation();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateVelocity
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateVelocity
    // Description: Specifies an aggregate’s linear velocity.
    //              The coordinate system for an aggregate’s linear velocity depends
    //              on the dead reckoning algorithm used.
    //              Represented by a Linear Velocity Vector.
    //              An aggreagte’s velocity is calculated by taking the average velocity
    //              of its constituent entities. The velocity of the aggregate is
    //              directed from the center of mass. See fig 39 from IEEE 1278.1A-1998.
    // Parameter:   const Vector & V
    //************************************
    void SetAggregateVelocity( const KDIS::DATA_TYPE::Vector & V );
    const KDIS::DATA_TYPE::Vector & GetAggregateVelocity() const;
    KDIS::DATA_TYPE::Vector & GetAggregateVelocity();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::GetNumberOfDISAggregates
    // Description: Number of sub-aggregates that are transmitting Aggregate State PDUs.
    //************************************
    KUINT16 GetNumberOfDISAggregates() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::GetNumberOfDISEntities
    // Description: Number of constituent entities that are transmitting Entity State PDUs.
    //************************************
    KUINT16 GetNumberOfDISEntities() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::GetNumberOfSilentAggregateTypes
    // Description: Number of sub aggregates that are not transmitting Aggregate State PDUs.
    //************************************
    KUINT16 GetNumberOfSilentAggregateTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::GetNumberOfSilentEntityTypes
    // Description: Number of constituent entity systems that are not transmitting Entity State PDUs.
    //************************************
    KUINT16 GetNumberOfSilentEntityTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::AddAggregateID
    //              KDIS::PDU::Aggregate_State_PDU::SetAggregateID
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateIDs
    // Description: Identify sub aggregates that are transmitting Aggregate State PDUs.
    // Parameter:   const AggregateIdentifier & AI, const vector<AggregateIdentifier> & AI
    //************************************
    void AddAggregateID( const KDIS::DATA_TYPE::AggregateIdentifier & AI );
    void SetAggregateIDList( const std::vector<KDIS::DATA_TYPE::AggregateIdentifier> & AI );
    const std::vector<KDIS::DATA_TYPE::AggregateIdentifier> & GetAggregateIDList() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::AddEntityID
    //              KDIS::PDU::Aggregate_State_PDU::SetEntityIDList
    //              KDIS::PDU::Aggregate_State_PDU::GetEntityIDList
    // Description: Identifies the constituent entities that are
    //              transmitting Entity State PDUs.
    // Parameter:   const EntityIdentifier & EI, const vector<EntityIdentifier> & EI
    //************************************
    void AddEntityID( const KDIS::DATA_TYPE::EntityIdentifier & EI );
    void SetEntityIDList( const std::vector<KDIS::DATA_TYPE::EntityIdentifier> & EI );
    const std::vector<KDIS::DATA_TYPE::EntityIdentifier> & GetEntityIDList() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::AddSilentAggregateSystem
    //              KDIS::PDU::Aggregate_State_PDU::GetSilentAggregateSystemList
    //              KDIS::PDU::Aggregate_State_PDU::GetSilentAggregateSystemList
    // Description: Contains information about sub aggregates not producing
    //              Aggregate State PDUs.
    // Parameter:   const SilentAggregateSystem & SAS, const vector<SilentAggregateSystem> & SAS
    //************************************
    void AddSilentAggregateSystem( const KDIS::DATA_TYPE::SilentAggregateSystem & SAS );
    void SetSilentAggregateSystemList( const std::vector<KDIS::DATA_TYPE::SilentAggregateSystem> & SAS );
    const std::vector<KDIS::DATA_TYPE::SilentAggregateSystem> & GetSilentAggregateSystemList() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::AddSilentEntitySystem
    //              KDIS::PDU::Aggregate_State_PDU::GetSilentEntitySystemList
    //              KDIS::PDU::Aggregate_State_PDU::GetSilentEntitySystemList
    // Description: Contains information about entities not producing
    //              Entity State PDUs.
    // Parameter:   const SilentEntitySystem & SES, const vector<SilentEntitySystem> & SES
    //************************************
    void AddSilentEntitySystem( const KDIS::DATA_TYPE::SilentEntitySystem & SES );
    void SetSilentEntitySystemList( const std::vector<KDIS::DATA_TYPE::SilentEntitySystem> & SES );
    const std::vector<KDIS::DATA_TYPE::SilentEntitySystem> & GetSilentEntitySystemList() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::GetNumberOfVariableDatums
    // Description: Number of variable datum records.
    //************************************
    KUINT32 GetNumberOfVariableDatums() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::AddVariableDatum
    //              KDIS::PDU::Aggregate_State_PDU::GetVariableDatumList
    //              KDIS::PDU::Aggregate_State_PDU::GetVariableDatumList
    //              KDIS::PDU::Aggregate_State_PDU::ClearVariableDatumList
    // Description: Specifies extra data that is used by the entity-level and
    //              aggregate-level simulations to transfer control and correlate the
    //              simulation of entities in an aggregate.
    //              The contents of these records shall be determined before
    //              each exercise.
    //              The first Variable Datum record may be used to indicate a flag that
    //              tells that the composition or formation of the unit has changed.
    // Parameter:   VarDtmPtr VD, const vector<VarDtmPtr> & VD
    //************************************
    void AddVariableDatum( KDIS::DATA_TYPE::VarDtmPtr VD );
    void SetVariableDatumList( const std::vector<KDIS::DATA_TYPE::VarDtmPtr> & VD );
    const std::vector<KDIS::DATA_TYPE::VarDtmPtr> & GetVariableDatumList() const;
    void ClearVariableDatumList();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream?
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Aggregate_State_PDU & Value ) const;
    KBOOL operator != ( const Aggregate_State_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
