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

#include "./Aggregate_State_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::calcPadding()
{
    const KUINT16 ui16NumBytesToConsider = ( ( AggregateIdentifier::AGGREGATE_IDENTIFER_SIZE * m_ui16NumAggregates ) + ( EntityIdentifier::ENTITY_IDENTIFER_SIZE * m_ui16NumEntities ) ) % 4;
    m_ui16NumberOfPaddingOctets = ui16NumBytesToConsider == 0 ? 0 : 4 - ui16NumBytesToConsider;
}

void Aggregate_State_PDU::updatePadding()
{
    m_ui16PDULength -= m_ui16NumberOfPaddingOctets;
    calcPadding();
    m_ui16PDULength += m_ui16NumberOfPaddingOctets;
}

bool Aggregate_State_PDU::needsPadding() const
{
    return m_ui16NumberOfPaddingOctets > 0;
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Aggregate_State_PDU::Aggregate_State_PDU() :
    m_ui8ForceID( 0 ),
    m_ui8AggState( 0 ),
    m_ui32Formation( 0 ),
    m_ui16NumAggregates( 0 ),
    m_ui16NumEntities( 0 ),
    m_ui16NumSilentAggregateTypes( 0 ),
    m_ui16NumSilentEntityTypes( 0 ),
    m_bNeedsPadding( false ),
    m_ui16Padding1( 0 ),
    m_ui16NumberOfPaddingOctets( 0 ),
    m_ui32NumVariableDatum( 0 )
{
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = AggregateState_PDU_Type;
    m_ui16PDULength = AGGREGATE_STATE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Aggregate_State_PDU::Aggregate_State_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Aggregate_State_PDU::Aggregate_State_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
    Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Aggregate_State_PDU::Aggregate_State_PDU( const AggregateIdentifier & AI, ForceID FID, AggregateState AS,
        const AggregateType & AT, Formation F, const AggregateMarking & AM,
        const Vector & Dimensions, const EulerAngles & Orientation,
        const WorldCoordinates & CenterOfMass, const Vector & Velocity ) :
    m_AggregateID( AI ),
    m_ui8ForceID( FID ),
    m_ui8AggState( AS ),
    m_AggregateType( AT ),
    m_ui32Formation( F ),
    m_AggregateMarking( AM ),
    m_Dimensions( Dimensions ),
    m_Ori( Orientation ),
    m_CtrOfMassLoc( CenterOfMass ),
    m_Vel( Velocity ),
    m_ui16NumAggregates( 0 ),
    m_ui16NumEntities( 0 ),
    m_ui16NumSilentAggregateTypes( 0 ),
    m_ui16NumSilentEntityTypes( 0 ),
    m_bNeedsPadding( false ),
    m_ui16Padding1( 0 ),
    m_ui16NumberOfPaddingOctets( 0 ),
    m_ui32NumVariableDatum( 0 )
{
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = AggregateState_PDU_Type;
    m_ui16PDULength = AGGREGATE_STATE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}


//////////////////////////////////////////////////////////////////////////

Aggregate_State_PDU::~Aggregate_State_PDU()
{
    m_vAI.clear();
    m_vEI.clear();
    m_vSASL.clear();
    m_vSESL.clear();
    m_vVD.clear();
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetAggregateIdentifier( const AggregateIdentifier & AI )
{
    m_AggregateID = AI;
}

//////////////////////////////////////////////////////////////////////////

const AggregateIdentifier & Aggregate_State_PDU::GetAggregateIdentifier() const
{
    return m_AggregateID;
}

//////////////////////////////////////////////////////////////////////////

AggregateIdentifier & Aggregate_State_PDU::GetAggregateIdentifier()
{
    return m_AggregateID;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetForceID( ForceID ID )
{
    m_ui8ForceID = ID;
}

//////////////////////////////////////////////////////////////////////////

ForceID Aggregate_State_PDU::GetForceID() const
{
    return ( ForceID )m_ui8ForceID;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetAggregateState( AggregateState AS )
{
    m_ui8AggState = AS;
}

//////////////////////////////////////////////////////////////////////////

AggregateState Aggregate_State_PDU::GetAggregateState() const
{
    return ( AggregateState )m_ui8AggState;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetAggregateType( const AggregateType & Type )
{
    m_AggregateType = Type;
}

//////////////////////////////////////////////////////////////////////////

const AggregateType & Aggregate_State_PDU::GetAggregateType() const
{
    return m_AggregateType;
}

//////////////////////////////////////////////////////////////////////////

AggregateType & Aggregate_State_PDU::GetAggregateType()
{
    return m_AggregateType;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetFormation( Formation F )
{
    m_ui32Formation = F;
}

//////////////////////////////////////////////////////////////////////////

Formation Aggregate_State_PDU::GetFormation() const
{
    return ( Formation )m_ui32Formation;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetAggregateMarking( const AggregateMarking & AM )
{
    m_AggregateMarking = AM;
}

//////////////////////////////////////////////////////////////////////////

const AggregateMarking & Aggregate_State_PDU::GetAggregateMarking() const
{
    return m_AggregateMarking;
}

//////////////////////////////////////////////////////////////////////////

AggregateMarking & Aggregate_State_PDU::GetAggregateMarking()
{
    return m_AggregateMarking;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetAggregateDimensions( const Vector & AD )
{
    m_Dimensions = AD;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Aggregate_State_PDU::GetAggregateDimensions() const
{
    return m_Dimensions;
}

//////////////////////////////////////////////////////////////////////////

Vector & Aggregate_State_PDU::GetAggregateDimensions()
{
    return m_Dimensions;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetAggregateOrientation( const EulerAngles & AO )
{
    m_Ori = AO;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & Aggregate_State_PDU::GetAggregateOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & Aggregate_State_PDU::GetAggregateOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetCenterOfMassLocation( const WorldCoordinates & COML )
{
    m_CtrOfMassLoc = COML;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & Aggregate_State_PDU::GetCenterOfMassLocation() const
{
    return m_CtrOfMassLoc;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & Aggregate_State_PDU::GetCenterOfMassLocation()
{
    return m_CtrOfMassLoc;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetAggregateVelocity( const Vector & V )
{
    m_Vel = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Aggregate_State_PDU::GetAggregateVelocity() const
{
    return m_Vel;
}

//////////////////////////////////////////////////////////////////////////

Vector & Aggregate_State_PDU::GetAggregateVelocity()
{
    return m_Vel;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Aggregate_State_PDU::GetNumberOfDISAggregates() const
{
    return m_ui16NumAggregates;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Aggregate_State_PDU::GetNumberOfDISEntities() const
{
    return m_ui16NumEntities;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Aggregate_State_PDU::GetNumberOfSilentAggregateTypes() const
{
    return m_ui16NumSilentAggregateTypes;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Aggregate_State_PDU::GetNumberOfSilentEntityTypes() const
{
    return m_ui16NumSilentEntityTypes;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::AddAggregateID( const AggregateIdentifier & AI )
{
    m_vAI.push_back( AI );
    m_ui16NumAggregates = m_vAI.size();
    m_ui16PDULength += AggregateIdentifier::AGGREGATE_IDENTIFER_SIZE;
    updatePadding();
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetAggregateIDList( const vector<AggregateIdentifier> & AI )
{
    // Reset the PDU length field
    m_ui16PDULength -= m_ui16NumAggregates * AggregateIdentifier::AGGREGATE_IDENTIFER_SIZE;

    m_vAI = AI;
    m_ui16NumAggregates = m_vAI.size();
    m_ui16PDULength += m_ui16NumAggregates * AggregateIdentifier::AGGREGATE_IDENTIFER_SIZE;
    updatePadding();
}

//////////////////////////////////////////////////////////////////////////

const vector<AggregateIdentifier> & Aggregate_State_PDU::GetAggregateIDList() const
{
    return m_vAI;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::AddEntityID( const EntityIdentifier & EI )
{
    m_vEI.push_back( EI );
    m_ui16NumEntities = m_vEI.size();
    m_ui16PDULength += EntityIdentifier::ENTITY_IDENTIFER_SIZE;
    updatePadding();
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetEntityIDList( const vector<EntityIdentifier> & EI )
{
    // Reset the PDU length field
    m_ui16PDULength -= m_ui16NumEntities * EntityIdentifier::ENTITY_IDENTIFER_SIZE;

    m_vEI = EI;
    m_ui16NumEntities = m_vEI.size();
    m_ui16PDULength += m_ui16NumEntities * EntityIdentifier::ENTITY_IDENTIFER_SIZE;
    updatePadding();
}

//////////////////////////////////////////////////////////////////////////

const vector<EntityIdentifier> & Aggregate_State_PDU::GetEntityIDList() const
{
    return m_vEI;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::AddSilentAggregateSystem( const SilentAggregateSystem & SAS )
{
    m_ui16PDULength += SilentAggregateSystem::SILENT_AGGREGATE_SYSTEM_SIZE;

    m_vSASL.push_back( SAS );
    m_ui16NumSilentAggregateTypes = m_vSASL.size();
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetSilentAggregateSystemList( const vector<SilentAggregateSystem> & SAS )
{
    // Reset the PDU length
    m_ui16PDULength -= m_ui16NumSilentAggregateTypes * SilentAggregateSystem::SILENT_AGGREGATE_SYSTEM_SIZE;

    m_vSASL = SAS;
    m_ui16NumSilentAggregateTypes = m_vSASL.size();
    m_ui16PDULength += m_ui16NumSilentAggregateTypes * SilentAggregateSystem::SILENT_AGGREGATE_SYSTEM_SIZE;
}

//////////////////////////////////////////////////////////////////////////

const vector<SilentAggregateSystem> & Aggregate_State_PDU::GetSilentAggregateSystemList() const
{
    return m_vSASL;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::AddSilentEntitySystem( const SilentEntitySystem & SES )
{
    m_ui16PDULength += SilentEntitySystem::SILENT_ENTITY_SYSTEM_SIZE + ( SES.GetNumberOfAppearanceRecords() * EntityAppearance::ENTITY_APPEARANCE_SIZE );
    m_vSESL.push_back( SES );
    m_ui16NumSilentEntityTypes = m_vSESL.size();
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetSilentEntitySystemList( const vector<SilentEntitySystem> & SES )
{
    // Reset the PDU length
    vector<SilentEntitySystem>::const_iterator citr = m_vSESL.begin();
    vector<SilentEntitySystem>::const_iterator citrEnd = m_vSESL.end();

    for( ; citr != citrEnd; ++citr )
    {
        m_ui16PDULength -= SilentEntitySystem::SILENT_ENTITY_SYSTEM_SIZE + ( citr->GetNumberOfAppearanceRecords() * EntityAppearance::ENTITY_APPEARANCE_SIZE );
    }

    m_vSESL = SES;

    for( citr = m_vSESL.begin(); citr!= m_vSESL.end(); ++citr )
    {
        m_ui16PDULength += SilentEntitySystem::SILENT_ENTITY_SYSTEM_SIZE + ( citr->GetNumberOfAppearanceRecords() * EntityAppearance::ENTITY_APPEARANCE_SIZE );
    }

    m_ui16NumSilentEntityTypes = m_vSESL.size();
}

//////////////////////////////////////////////////////////////////////////

const vector<SilentEntitySystem> & Aggregate_State_PDU::GetSilentEntitySystemList() const
{
    return m_vSESL;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Aggregate_State_PDU::GetNumberOfVariableDatums() const
{
    return m_ui32NumVariableDatum;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::AddVariableDatum( VarDtmPtr VD )
{
    m_vVD.push_back( VD );

    // Calculate the size, note get datum length only returns length of the value and does not
    // include the datum id or length field so we use VARIABLE_DATUM_SIZE to get this.
    m_ui16PDULength += VariableDatum::VARIABLE_DATUM_SIZE + ( VD->GetDatumLength() / 8 );
    ++m_ui32NumVariableDatum;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::SetVariableDatumList( const vector<VarDtmPtr> & VD )
{
    ClearVariableDatumList();

    m_vVD = VD;

    vector<VarDtmPtr>::const_iterator citr = m_vVD.begin();
    vector<VarDtmPtr>::const_iterator citrEnd = m_vVD.end();
    for( citr = m_vVD.begin(); citr != m_vVD.end(); ++citr )
    {
        m_ui16PDULength += VariableDatum::VARIABLE_DATUM_SIZE + ( ( *citr )->GetDatumLength() / 8 );
    }

    m_ui32NumVariableDatum = m_vVD.size();
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::ClearVariableDatumList()
{
    // Reset the PDU length
    vector<VarDtmPtr>::const_iterator citr = m_vVD.begin();
    vector<VarDtmPtr>::const_iterator citrEnd = m_vVD.end();
    for( ; citr != citrEnd; ++citr )
    {
        m_ui16PDULength -= VariableDatum::VARIABLE_DATUM_SIZE + ( ( *citr )->GetDatumLength() / 8 );
    }

    m_vVD.clear();
    m_ui32NumVariableDatum = 0;
}

//////////////////////////////////////////////////////////////////////////

const vector<VarDtmPtr> & Aggregate_State_PDU::GetVariableDatumList() const
{
    return m_vVD;
}

//////////////////////////////////////////////////////////////////////////

KString Aggregate_State_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Aggregate State PDU-\n"
       << "Aggregate ID:\n"
       << IndentString( m_AggregateID.GetAsString(), 1 )
       << "Force ID:                    " << GetEnumAsStringForceID( m_ui8ForceID )         << "\n"
       << "Aggregate State:             " << GetEnumAsStringAggregateState( m_ui8AggState ) << "\n"
       << m_AggregateType.GetAsString()
       << "Formation:                   " << GetEnumAsStringFormation( m_ui32Formation )    << "\n"
       << m_AggregateMarking.GetAsString()
       << "Dimensions:                  " << m_Dimensions.GetAsString()
       << "Orientation:                 " << m_Ori.GetAsString()
       << "Center Of Mass:              " << m_CtrOfMassLoc.GetAsString()
       << "Velocity:                    " << m_Vel.GetAsString()
       << "Number Of Aggregates:        " << m_ui16NumAggregates                            << "\n"
       << "Number Of Entities:          " << m_ui16NumEntities                              << "\n"
       << "Number Of Silent Aggregates: " << m_ui16NumSilentAggregateTypes                  << "\n"
       << "Number Of Silent Entities    " << m_ui16NumSilentEntityTypes                     << "\n";

    vector<AggregateIdentifier>::const_iterator citrAI = m_vAI.begin();
    vector<AggregateIdentifier>::const_iterator citrAIEnd = m_vAI.end();
    for( ; citrAI != citrAIEnd; ++citrAI )
    {
        ss << citrAI->GetAsString();
    }

    vector<EntityIdentifier>::const_iterator citrEI = m_vEI.begin();
    vector<EntityIdentifier>::const_iterator citrEIEnd = m_vEI.end();
    for( ; citrEI != citrEIEnd; ++citrEI )
    {
        ss << citrEI->GetAsString();
    }

    if (needsPadding())
    {
        ss << "Padding:                 " << m_ui16NumberOfPaddingOctets << " octets\n";
    }

    vector<SilentAggregateSystem>::const_iterator citrSAS = m_vSASL.begin();
    vector<SilentAggregateSystem>::const_iterator citrSASEnd = m_vSASL.end();
    for( ; citrSAS != citrSASEnd; ++citrSAS )
    {
        ss << citrSAS->GetAsString();
    }

    vector<SilentEntitySystem>::const_iterator citrSES = m_vSESL.begin();
    vector<SilentEntitySystem>::const_iterator citrSESEnd = m_vSESL.end();
    for( ; citrSES != citrSESEnd; ++citrSES )
    {
        ss << citrSES->GetAsString();
    }

    ss << "Number Of Variable Datums:   " << m_ui32NumVariableDatum << "\n";

    vector<VarDtmPtr>::const_iterator citrVD = m_vVD.begin();
    vector<VarDtmPtr>::const_iterator citrVDEnd = m_vVD.end();
    for( ; citrVD != citrVDEnd; ++citrVD )
    {
        ss << ( *citrVD )->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    m_bNeedsPadding = false;
    m_ui16NumberOfPaddingOctets = 0;
    m_vAI.clear();
    m_vEI.clear();
    m_vSASL.clear();
    m_vSESL.clear();
    m_vVD.clear();
    m_ui16NumAggregates = 0;
    m_ui16NumEntities = 0;
    m_ui16NumSilentAggregateTypes = 0;
    m_ui16NumSilentEntityTypes = 0;
    m_ui32NumVariableDatum = 0;

    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < AGGREGATE_STATE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );

    stream >> KDIS_STREAM m_AggregateID
           >> m_ui8ForceID
           >> m_ui8AggState
           >> KDIS_STREAM m_AggregateType
           >> m_ui32Formation
           >> KDIS_STREAM m_AggregateMarking
           >> KDIS_STREAM m_Dimensions
           >> KDIS_STREAM m_Ori
           >> KDIS_STREAM m_CtrOfMassLoc
           >> KDIS_STREAM m_Vel
           >> m_ui16NumAggregates
           >> m_ui16NumEntities
           >> m_ui16NumSilentAggregateTypes
           >> m_ui16NumSilentEntityTypes;

    // Does the PDU contain padding?
    calcPadding();

    if( needsPadding() )
    {
        KUINT8 ui8Padding = 0;
        for( KUINT16 p = 0; p < m_ui16NumberOfPaddingOctets; ++p )
        {
            stream >> ui8Padding;
        }
    }

    for( KUINT16 i = 0; i < m_ui16NumAggregates; ++i )
    {
        m_vAI.push_back( AggregateIdentifier( stream ) );
    }

    for( KUINT16 j = 0; j < m_ui16NumEntities; ++j )
    {
        m_vEI.push_back( EntityIdentifier( stream ) );
    }

    // Does the PDU contain padding?
    calcPadding();

    if( m_bNeedsPadding )
    {
        stream >> m_ui16Padding1;
    }

    for( KUINT16 k = 0; k < m_ui16NumSilentAggregateTypes; ++k )
    {
        m_vSASL.push_back( SilentAggregateSystem( stream ) );
    }

    for( KUINT16 l = 0; l < m_ui16NumSilentEntityTypes; ++l )
    {
        m_vSESL.push_back( SilentEntitySystem( stream ) );
    }

    stream >> m_ui32NumVariableDatum;

    // VariableDatum
    for( KUINT16 n = 0; n < m_ui32NumVariableDatum; ++n )
    {
        // Save the current write position so we can peek.
        KUINT16 pos = stream.GetCurrentWritePosition();
        KUINT32 datumID;

        // Extract the datum id then reset the stream.
        stream >> datumID;
        stream.SetCurrentWritePosition( pos );

        // Use the factory decoder.
        VariableDatum * p = VariableDatum::FactoryDecode( datumID, stream );

        // Did we find a custom decoder? if not then use the default.
        if( p )
        {
            m_vVD.push_back( VarDtmPtr( p ) );
        }
        else
        {
            // Default
            m_vVD.push_back( VarDtmPtr( new VariableDatum( stream ) ) );
        }
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Aggregate_State_PDU::Encode() const
{
    KDataStream stream;

    Aggregate_State_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Aggregate_State_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_AggregateID
           << m_ui8ForceID
           << m_ui8AggState
           << KDIS_STREAM m_AggregateType
           << m_ui32Formation
           << KDIS_STREAM m_AggregateMarking
           << KDIS_STREAM m_Dimensions
           << KDIS_STREAM m_Ori
           << KDIS_STREAM m_CtrOfMassLoc
           << KDIS_STREAM m_Vel
           << m_ui16NumAggregates
           << m_ui16NumEntities
           << m_ui16NumSilentAggregateTypes
           << m_ui16NumSilentEntityTypes;

    vector<AggregateIdentifier>::const_iterator citrAI = m_vAI.begin();
    for( ; citrAI != m_vAI.end(); ++citrAI )
    {
        citrAI->Encode( stream );
    }

    vector<EntityIdentifier>::const_iterator citrEI = m_vEI.begin();
    for( ; citrEI != m_vEI.end(); ++citrEI )
    {
        citrEI->Encode( stream );
    }

    if( needsPadding() )
    {
        const KUINT8 ui8Padding = 0;
        for( KUINT16 p = 0; p < m_ui16NumberOfPaddingOctets; ++p )
        {
            stream << ui8Padding;
        }
    }

    vector<SilentAggregateSystem>::const_iterator citrSAS = m_vSASL.begin();
    for( ; citrSAS != m_vSASL.end(); ++citrSAS )
    {
        citrSAS->Encode( stream );
    }

    vector<SilentEntitySystem>::const_iterator citrSES = m_vSESL.begin();
    for( ; citrSES != m_vSESL.end(); ++citrSES )
    {
        citrSES->Encode( stream );
    }

    stream << m_ui32NumVariableDatum;

    vector<VarDtmPtr>::const_iterator citrVD = m_vVD.begin();
    for( ; citrVD != m_vVD.end(); ++citrVD )
    {
        ( *citrVD )->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Aggregate_State_PDU::operator == ( const Aggregate_State_PDU & Value ) const
{
    if( Header::operator                !=( Value ) )                            return false;
    if( m_AggregateID                   != Value.m_AggregateID )                 return false;
    if( m_ui8ForceID                    != Value.m_ui8ForceID )                  return false;
    if( m_ui8AggState                   != Value.m_ui8AggState )                 return false;
    if( m_AggregateType                 != Value.m_AggregateType )               return false;
    if( m_ui32Formation                 != Value.m_ui32Formation )               return false;
    if( m_AggregateMarking              != Value.m_AggregateMarking )            return false;
    if( m_Dimensions                    != Value.m_Dimensions )                  return false;
    if( m_Ori                           != Value.m_Ori )                         return false;
    if( m_CtrOfMassLoc                  != Value.m_CtrOfMassLoc )                return false;
    if( m_Vel                           != Value.m_Vel )                         return false;
    if( m_ui16NumAggregates             != Value.m_ui16NumAggregates )           return false;
    if( m_ui16NumEntities               != Value.m_ui16NumEntities )             return false;
    if( m_ui16NumSilentAggregateTypes   != Value.m_ui16NumSilentAggregateTypes ) return false;
    if( m_ui16NumSilentEntityTypes      != Value.m_ui16NumSilentEntityTypes )    return false;
    if( m_vAI                           != Value.m_vAI )                         return false;
    if( m_vEI                           != Value.m_vEI )                         return false;
    if( m_vSASL                         != Value.m_vSASL )                       return false;
    if( m_vSESL                         != Value.m_vSESL )                       return false;
    if( m_vVD                           != Value.m_vVD )                         return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Aggregate_State_PDU::operator != ( const Aggregate_State_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
