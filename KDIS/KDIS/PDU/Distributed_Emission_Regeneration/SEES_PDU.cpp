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

#include "./SEES_PDU.h"

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

SEES_PDU::SEES_PDU() :
    m_ui16NumPropulsionSys( 0 ),
    m_ui16NumVectoringNozzleSys( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = SupplementalEmission_EntityState_PDU_Type;
    m_ui16PDULength = SEES_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

SEES_PDU::SEES_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

SEES_PDU::SEES_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

SEES_PDU::SEES_PDU( const EntityIdentifier & OriginatingEnt, KUINT16 IrSigIndex, KUINT16 AcousticSigIndex,
                    KUINT16 RadarCrossSectionSigIndex ) :
    m_OriginatingEntity( OriginatingEnt ),
    m_ui16IrSigRepIndex( IrSigIndex ),
    m_ui16AcousticSigRepIndex( AcousticSigIndex ),
    m_ui16CrossSection( RadarCrossSectionSigIndex ),
    m_ui16NumPropulsionSys( 0 ),
    m_ui16NumVectoringNozzleSys( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = SupplementalEmission_EntityState_PDU_Type;
    m_ui16PDULength = SEES_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

SEES_PDU::~SEES_PDU()
{
    m_vPropSys.clear();
    m_vVecNozzleSys.clear();
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::SetOriginatingEntityID ( const EntityIdentifier & ID )
{
    m_OriginatingEntity = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & SEES_PDU::GetOriginatingEntityID() const
{
    return m_OriginatingEntity;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & SEES_PDU::GetOriginatingEntityID()
{
    return m_OriginatingEntity;
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::SetInfraredSignatureRepresentationIndex( KUINT16 ISRI )
{
    m_ui16IrSigRepIndex = ISRI;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SEES_PDU::GetInfraredSignatureRepresentationIndex() const
{
    return m_ui16IrSigRepIndex;
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::SetAcousticSignatureRepresentationIndex( KUINT16 ASRI )
{
    m_ui16AcousticSigRepIndex = ASRI;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SEES_PDU::GetAcousticSignatureRepresentationIndex() const
{
    return m_ui16AcousticSigRepIndex;
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::SetRadarCrossSectionSignatureRepresentationIndex( KUINT16 RCSSRI )
{
    m_ui16CrossSection = RCSSRI;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SEES_PDU::GetRadarCrossSectionSignatureRepresentationIndex() const
{
    return m_ui16CrossSection;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SEES_PDU::GetNumberOfPropulsionSystems() const
{
    return m_ui16NumPropulsionSys;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SEES_PDU::GetNumberOfVectoringNozzleSystems() const
{
    return m_ui16NumVectoringNozzleSys;
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::AddPropulsionSystem( const PropulsionSystem & PS )
{
    m_ui16PDULength += PropulsionSystem::PROPULSION_SYSTEM_SIZE;
    m_vPropSys.push_back( PS );
    ++m_ui16NumPropulsionSys;
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::SetPropulsionSystem( const vector<PropulsionSystem> & PS )
{
    m_ui16PDULength -= PropulsionSystem::PROPULSION_SYSTEM_SIZE * m_vPropSys.size();
    m_vPropSys = PS;
    m_ui16NumPropulsionSys = m_vPropSys.size();
    m_ui16PDULength += m_vPropSys.size() * PropulsionSystem::PROPULSION_SYSTEM_SIZE;
}

//////////////////////////////////////////////////////////////////////////

const vector<PropulsionSystem> SEES_PDU::GetPropulsionSystem() const
{
    return m_vPropSys;
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::AddVectoringNozzleSystem( const VectoringNozzleSystem & VNS )
{
    ++m_ui16NumVectoringNozzleSys;
    m_ui16PDULength += VectoringNozzleSystem::VECTORING_NOZZLE_SYSTEM_SIZE;
    m_vVecNozzleSys.push_back( VNS );
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::SetVectoringNozzleSystem( const vector<VectoringNozzleSystem> & VNS )
{
    m_ui16PDULength -= VectoringNozzleSystem::VECTORING_NOZZLE_SYSTEM_SIZE * m_vVecNozzleSys.size();
    m_vVecNozzleSys = VNS;
    m_ui16NumVectoringNozzleSys = m_vVecNozzleSys.size();
    m_ui16PDULength += VectoringNozzleSystem::VECTORING_NOZZLE_SYSTEM_SIZE * m_vVecNozzleSys.size();
}

//////////////////////////////////////////////////////////////////////////

const vector<VectoringNozzleSystem> SEES_PDU::GetVectoringNozzleSystem() const
{
    return m_vVecNozzleSys;
}

//////////////////////////////////////////////////////////////////////////

KString SEES_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-SEES PDU-\n"
       << "Originating Entity ID:\n"
       << IndentString( m_OriginatingEntity.GetAsString(), 1 )
       << "IR Signature Representation Index:                  " << m_ui16IrSigRepIndex         << "\n"
       << "Acosutic Signature Representation Index:            " << m_ui16AcousticSigRepIndex   << "\n"
       << "Radar Cross Section Signature Representation Index: " << m_ui16CrossSection          << "\n"
       << "Number Of Propulsion Systems:                       " << m_ui16NumPropulsionSys      << "\n"
       << "Number Of Vectoring Nozzle Systems:                 " << m_ui16NumVectoringNozzleSys << "\n";

    vector<PropulsionSystem>::const_iterator citrPS = m_vPropSys.begin();

    for( ; citrPS != m_vPropSys.end(); ++citrPS )
    {
        ss << citrPS->GetAsString();
    }

    vector<VectoringNozzleSystem>::const_iterator citrVNS = m_vVecNozzleSys.begin();

    for( ; citrVNS != m_vVecNozzleSys.end(); ++citrVNS )
    {
        ss << citrVNS->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < SEES_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_OriginatingEntity
           >> m_ui16IrSigRepIndex
           >> m_ui16AcousticSigRepIndex
           >> m_ui16CrossSection
           >> m_ui16NumPropulsionSys
           >> m_ui16NumVectoringNozzleSys;

    m_vPropSys.clear();
    m_vVecNozzleSys.clear();

    for( KUINT16 i = 0; i < m_ui16NumPropulsionSys; ++i )
    {
        PropulsionSystem ps;
        stream >> KDIS_STREAM ps;
        m_vPropSys.push_back( ps );
    }

    for( KUINT16 i = 0; i < m_ui16NumVectoringNozzleSys; ++i )
    {
        VectoringNozzleSystem vns;
        stream >> KDIS_STREAM vns;
        m_vVecNozzleSys.push_back( vns );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream SEES_PDU::Encode() const
{
    KDataStream stream;

    SEES_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SEES_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_OriginatingEntity
           << m_ui16IrSigRepIndex
           << m_ui16AcousticSigRepIndex
           << m_ui16CrossSection
           << m_ui16NumPropulsionSys
           << m_ui16NumVectoringNozzleSys;

    vector<PropulsionSystem>::const_iterator citrPS = m_vPropSys.begin();

    for( ; citrPS != m_vPropSys.end(); ++citrPS )
    {
        stream << KDIS_STREAM *citrPS;
    }

    vector<VectoringNozzleSystem>::const_iterator citrVNS = m_vVecNozzleSys.begin();

    for( ; citrVNS != m_vVecNozzleSys.end(); ++citrVNS )
    {
        stream << KDIS_STREAM *citrVNS;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL SEES_PDU::operator == ( const SEES_PDU & Value ) const
{
    if( Header::operator            !=( Value ) )                          return false;
    if( m_OriginatingEntity         != Value.m_OriginatingEntity )         return false;
    if( m_ui16IrSigRepIndex         != Value.m_ui16IrSigRepIndex )         return false;
    if( m_ui16CrossSection          != Value.m_ui16CrossSection )          return false;
    if( m_ui16NumPropulsionSys      != Value.m_ui16NumPropulsionSys )      return false;
    if( m_ui16NumVectoringNozzleSys != Value.m_ui16NumVectoringNozzleSys ) return false;
    if( m_vPropSys                  != Value.m_vPropSys )                  return false;
    if( m_vVecNozzleSys             != Value.m_vVecNozzleSys )             return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SEES_PDU::operator != ( const SEES_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



