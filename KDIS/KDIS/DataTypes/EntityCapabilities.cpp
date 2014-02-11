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

#include "./EntityCapabilities.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityCapabilities::EntityCapabilities() :
    m_ui16Data( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

EntityCapabilities::EntityCapabilities( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EntityCapabilities::EntityCapabilities( KBOOL AmunitionSupply, KBOOL FuelSupply, KBOOL RecoveryService, KBOOL RepairService )
{
    m_Unused = 0;
    m_AmmunitionSupply = AmunitionSupply;
    m_FuelSupply = FuelSupply;
    m_RecoveryService = RecoveryService;
    m_RepairService = RepairService;
	m_ADSB = 0;
}

//////////////////////////////////////////////////////////////////////////

EntityCapabilities::EntityCapabilities( KBOOL AmunitionSupply, KBOOL FuelSupply, KBOOL RecoveryService, KBOOL RepairService, KBOOL ADSB )
{
    m_Unused = 0;
    m_AmmunitionSupply = AmunitionSupply;
    m_FuelSupply = FuelSupply;
    m_RecoveryService = RecoveryService;
    m_RepairService = RepairService;
	m_ADSB = ADSB;
}

//////////////////////////////////////////////////////////////////////////

EntityCapabilities::~EntityCapabilities()
{
}

//////////////////////////////////////////////////////////////////////////

void EntityCapabilities::SetHasAmmunitionSupply( KBOOL HAS )
{
    m_AmmunitionSupply = HAS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityCapabilities::HasAmmunitionSupply() const
{
    return m_AmmunitionSupply;
}

//////////////////////////////////////////////////////////////////////////

void EntityCapabilities::SetHasFuelSupply( KBOOL HAS )
{
    m_FuelSupply = HAS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityCapabilities::HasFuelSupply() const
{
    return m_FuelSupply;
}

//////////////////////////////////////////////////////////////////////////

void EntityCapabilities::SetHasRecoveryService( KBOOL HAS )
{
    m_RecoveryService = HAS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityCapabilities::HasRecoveryService() const
{
    return m_RecoveryService;
}

//////////////////////////////////////////////////////////////////////////

void EntityCapabilities::SetHasRepairService( KBOOL HAS )
{
    m_RepairService = HAS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityCapabilities::HasRepairService() const
{
    return m_RepairService;
}

//////////////////////////////////////////////////////////////////////////

void EntityCapabilities::SetHasAutomaticDependentSurveillanceBroadcast( KBOOL ADSB )
{
	m_ADSB = ADSB;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityCapabilities::HasAutomaticDependentSurveillanceBroadcast() const
{
	return m_ADSB;
}

//////////////////////////////////////////////////////////////////////////

void EntityCapabilities::SetAllFields( KUINT32 All )
{
    m_ui16Data = All;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 EntityCapabilities::GetAllFields() const
{
    return m_ui16Data;
}

//////////////////////////////////////////////////////////////////////////

KString EntityCapabilities::GetAsString() const
{
    KStringStream ss;

    ss << "Entity Capabilities"
       << "\n\tAmmunition Supply:    " << m_AmmunitionSupply
       << "\n\tFuel Supply:          " << m_FuelSupply
       << "\n\tRecovery Service:     " << m_RecoveryService
       << "\n\tRepair Service:       " << m_RepairService
	   << "\n\tADS-B Service:        " << m_ADSB
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EntityCapabilities::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ENTITY_CAPABILITIES_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16Data;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EntityCapabilities::Encode() const
{
    KDataStream stream;

    EntityCapabilities::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EntityCapabilities::Encode( KDataStream & stream ) const
{
    stream << m_ui16Data;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityCapabilities::operator == ( const EntityCapabilities & Value ) const
{
    if( m_ui16Data != Value.m_ui16Data ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityCapabilities::operator != ( const EntityCapabilities & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


