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

using KDIS::DATA_TYPE::AggregateIdentifier;
using KDIS::DATA_TYPE::AggregateType;
using KDIS::DATA_TYPE::AggregateMarking;
using KDIS::DATA_TYPE::EulerAngles;
using KDIS::DATA_TYPE::WorldCoordinates;
using KDIS::DATA_TYPE::Vector;
using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::SilentAggregateSystem;
using KDIS::DATA_TYPE::SilentEntitySystem;
using KDIS::DATA_TYPE::VariableDatum;
using KDIS::DATA_TYPE::VarDtmPtr;
using KDIS::DATA_TYPE::ENUMS::ForceID;
using KDIS::DATA_TYPE::ENUMS::AggregateState;
using KDIS::DATA_TYPE::ENUMS::Formation;
using std::vector;

class KDIS_EXPORT Aggregate_State_PDU : public Header
{
protected:

    AggregateIdentifier m_AggregateID;

    KUINT8 m_ui8ForceID;

    KUINT8 m_ui8AggState;

    AggregateType m_AggregateType;

    KUINT32 m_ui32Formation;

    AggregateMarking m_AggregateMarking;

    Vector m_Dimensions;

    EulerAngles m_Ori;

    WorldCoordinates m_CtrOfMassLoc;

    Vector m_Vel;

    KUINT16 m_ui16NumAggregates;

    KUINT16 m_ui16NumEntities;

    KUINT16 m_ui16NumSilentAggregateTypes;

    KUINT16 m_ui16NumSilentEntityTypes;

    vector<AggregateIdentifier> m_vAI;

    vector<EntityIdentifier> m_vEI;

    KBOOL m_bNeedsPadding;
    KUINT16 m_ui16Padding1;

    vector<SilentAggregateSystem> m_vSASL;

    vector<SilentEntitySystem> m_vSESL;

    KUINT32 m_ui32NumVariableDatum;

    vector<VarDtmPtr> m_vVD;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::calcPadding
    // Description: Calculates the padding so the PDU lies on a 32 bit boundary.
    //************************************
    void calcPadding();

public:

    static const KUINT16 AGGREGATE_STATE_PDU_SIZE = 136; // Min size

    Aggregate_State_PDU();

    Aggregate_State_PDU( KDataStream & stream ) throw( KException );

    Aggregate_State_PDU( const AggregateIdentifier & AI, ForceID FID, AggregateState AS,
                         const AggregateType & AT, Formation F, const AggregateMarking & AM,
                         const Vector & Dimensions, const EulerAngles & Orientation,
                         const WorldCoordinates & CenterOfMass, const Vector & Velocity );

    virtual ~Aggregate_State_PDU();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateIdentifier
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateIdentifier
    // Description: ID of the aggregate issuing the PDU.
    // Parameter:   const AggregateIdentifier & AI, void
    //************************************
    void SetAggregateIdentifier( const AggregateIdentifier & AI );
    const AggregateIdentifier & GetAggregateIdentifier() const;
    AggregateIdentifier & GetAggregateIdentifier();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetForceID
    //              KDIS::PDU::Aggregate_State_PDU::GetForceID
    // Description: Force ID of the aggregate, aggregates of opposing forces
    //              may not group together.
    // Parameter:   ForceID ID, void
    //************************************
    void SetForceID( ForceID ID );
    ForceID GetForceID() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateState
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateState
    // Description: Aggregate state enumeration.
    // Parameter:   AggregateState AS, void
    //************************************
    void SetAggregateState( AggregateState AS );
    AggregateState GetAggregateState() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateType
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateType
    // Description: Aggregate type enumerations.
    // Parameter:   const AggregateType & Type, void
    //************************************
    void SetAggregateType( const AggregateType & Type );
    const AggregateType & GetAggregateType() const;
    AggregateType & GetAggregateType();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetFormation
    //              KDIS::PDU::Aggregate_State_PDU::GetFormation
    // Description: Aggregate formation.
    // Parameter:   Formation F, void
    //************************************
    void SetFormation( Formation F );
    Formation GetFormation() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateMarking
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateMarking
    // Description: Aggregate marking.
    // Parameter:   const AggregateMarking & AM, void
    //************************************
    void SetAggregateMarking( const AggregateMarking & AM );
    const AggregateMarking & GetAggregateMarking() const;
    AggregateMarking & GetAggregateMarking();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateDimensions
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateDimensions
    // Description: Identifies the bounding space, in meters, that the aggregate
    //              occupies. These measurements are taken along the orientation
    //              axes of the aggregate. Measurements X, Y, and Z are taken from
    //              the center of mass of the aggregate to the shortest distance
    //              along an axis in the positive or negative direction that includes
    //              all of the constituent entities. See fig 38 from IEEE 1278.1A-1998.
    // Parameter:   const Vector & AD, void
    //************************************
    void SetAggregateDimensions( const Vector & AD );
    const Vector & GetAggregateDimensions() const;
    Vector & GetAggregateDimensions();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetAggregateOrientation
    //              KDIS::PDU::Aggregate_State_PDU::GetAggregateOrientation
    // Description: Orientation of the aggregate.
    //              Calculated by taking the average orientation of its
    //              constituent entities.
    // Parameter:   const EulerAngles & AO, void
    //************************************
    void SetAggregateOrientation( const EulerAngles & AO );
    const EulerAngles & GetAggregateOrientation() const;
    EulerAngles & GetAggregateOrientation();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::SetCenterOfMassLocation
    //              KDIS::PDU::Aggregate_State_PDU::GetCenterOfMassLocation
    // Description: Location of the aggregate’s center of mass in the simulated world.
    // Parameter:   const WorldCoordinates & COML, void
    //************************************
    void SetCenterOfMassLocation( const WorldCoordinates & COML );
    const WorldCoordinates & GetCenterOfMassLocation() const;
    WorldCoordinates & GetCenterOfMassLocation();

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
    // Parameter:   const Vector & V, void
    //************************************
    void SetAggregateVelocity( const Vector & V );
    const Vector & GetAggregateVelocity() const;
    Vector & GetAggregateVelocity();

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
    void AddAggregateID( const AggregateIdentifier & AI );
    void SetAggregateIDList( const vector<AggregateIdentifier> & AI );
    const vector<AggregateIdentifier> & GetAggregateIDList() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::AddEntityID
    //              KDIS::PDU::Aggregate_State_PDU::SetEntityIDList
    //              KDIS::PDU::Aggregate_State_PDU::GetEntityIDList
    // Description: Identifies the constituent entities that are
    //              transmitting Entity State PDUs.
    // Parameter:   const EntityIdentifier & EI, const vector<EntityIdentifier> & EI
    //************************************
    void AddEntityID( const EntityIdentifier & EI );
    void SetEntityIDList( const vector<EntityIdentifier> & EI );
    const vector<EntityIdentifier> & GetEntityIDList() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::AddSilentAggregateSystem
    //              KDIS::PDU::Aggregate_State_PDU::GetSilentAggregateSystemList
    //              KDIS::PDU::Aggregate_State_PDU::GetSilentAggregateSystemList
    // Description: Contains information about sub aggregates not producing
    //              Aggregate State PDUs.
    // Parameter:   const SilentAggregateSystem & SAS, const vector<SilentAggregateSystem> & SAS
    //************************************
    void AddSilentAggregateSystem( const SilentAggregateSystem & SAS );
    void SetSilentAggregateSystemList( const vector<SilentAggregateSystem> & SAS );
    const vector<SilentAggregateSystem> & GetSilentAggregateSystemList() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::AddSilentEntitySystem
    //              KDIS::PDU::Aggregate_State_PDU::GetSilentEntitySystemList
    //              KDIS::PDU::Aggregate_State_PDU::GetSilentEntitySystemList
    // Description: Contains information about entities not producing
    //              Entity State PDUs.
    // Parameter:   const SilentEntitySystem & SES, const vector<SilentEntitySystem> & SES
    //************************************
    void AddSilentEntitySystem( const SilentEntitySystem & SES );
    void SetSilentEntitySystemList( const vector<SilentEntitySystem> & SES );
    const vector<SilentEntitySystem> & GetSilentEntitySystemList() const;

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
    void AddVariableDatum( VarDtmPtr VD );
    void SetVariableDatumList( const vector<VarDtmPtr> & VD );
    const vector<VarDtmPtr> & GetVariableDatumList() const;
	void ClearVariableDatumList();

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Aggregate_State_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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
