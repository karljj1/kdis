/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

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

EntityCapabilities::EntityCapabilities( void ) :
    m_ui16Data( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

EntityCapabilities::EntityCapabilities( KDataStream & stream ) throw( KException )
{
    m_Unused = 0;
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
}

//////////////////////////////////////////////////////////////////////////

EntityCapabilities::EntityCapabilities( KBOOL AmunitionSupply, KBOOL FuelSupply, KBOOL RecoveryService, KBOOL RepairService )
{
    m_Unused = 0;
    m_AmmunitionSupply = AmunitionSupply;
    m_FuelSupply = FuelSupply;
    m_RecoveryService = RecoveryService;
    m_RepairService = RepairService;
}

//////////////////////////////////////////////////////////////////////////

EntityCapabilities::~EntityCapabilities( void )
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


