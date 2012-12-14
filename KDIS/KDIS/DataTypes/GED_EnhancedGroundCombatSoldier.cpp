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

#include "./GED_EnhancedGroundCombatSoldier.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatSoldier::GED_EnhancedGroundCombatSoldier( void ) :
    m_ui8WaterStatus( 0 ),
    m_ui8RestStatus( 0 ),
    m_ui8PriAmmun( 0 ),
    m_ui8SecAmmun( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatSoldier::GED_EnhancedGroundCombatSoldier( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatSoldier::GED_EnhancedGroundCombatSoldier( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA,
        KINT8 Psi, KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 HeadAzimuth, KINT8 HeadElevation,
        KINT8 HeadScanRate, KINT8 HeadElevationRate, KUINT8 WaterStatus, RestStatus R,
        KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition ) :
    GED_BasicGroundCombatSoldier( ID, XOffset, YOffset, ZOffset, EA, Psi, Theta, Phi, Speed,
                                  HeadAzimuth, HeadElevation, HeadScanRate, HeadElevationRate ),
    m_ui8WaterStatus( WaterStatus ),
    m_ui8RestStatus( R ),
    m_ui8PriAmmun( PrimaryAmmunition ),
    m_ui8SecAmmun( SecondaryAmmunition )
{
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatSoldier::GED_EnhancedGroundCombatSoldier( const GED_BasicGroundCombatSoldier & BGCS, KUINT8 WaterStatus, RestStatus R,
        KUINT8 PrimaryAmmunition, KUINT8 SecondaryAmmunition ) :
    GED_BasicGroundCombatSoldier( BGCS ),
    m_ui8WaterStatus( WaterStatus ),
    m_ui8RestStatus( R ),
    m_ui8PriAmmun( PrimaryAmmunition ),
    m_ui8SecAmmun( SecondaryAmmunition )
{
}

//////////////////////////////////////////////////////////////////////////

GED_EnhancedGroundCombatSoldier::~GED_EnhancedGroundCombatSoldier( void )
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_EnhancedGroundCombatSoldier::GetGroupedEntityCategory() const
{
    return EnhancedGroundCombatSoldierGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedGroundCombatSoldier::GetLength() const
{
    return GED_ENHANCED_GROUND_COMBAT_SOLDIER_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatSoldier::SetWaterStatus( KUINT8 W )
{
    m_ui8WaterStatus = W;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedGroundCombatSoldier::GetWaterStatus() const
{
    return m_ui8WaterStatus;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatSoldier::SetRestStatus( RestStatus R )
{
    m_ui8RestStatus = R;
}

//////////////////////////////////////////////////////////////////////////

RestStatus GED_EnhancedGroundCombatSoldier::GetRestStatus() const
{
    return ( RestStatus )m_ui8RestStatus;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatSoldier::SetPrimaryAmmunition( KUINT8 P )
{
    m_ui8PriAmmun = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedGroundCombatSoldier::GetPrimaryAmmunition() const
{
    return m_ui8PriAmmun;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatSoldier::SetSecondaryAmmunition( KUINT8 S )
{
    m_ui8SecAmmun = S;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_EnhancedGroundCombatSoldier::GetSecondaryAmmunition() const
{
    return m_ui8SecAmmun;
}

//////////////////////////////////////////////////////////////////////////

KString GED_EnhancedGroundCombatSoldier::GetAsString() const
{
    KStringStream ss;

    ss << GED_BasicGroundCombatSoldier::GetAsString();

    ss << "GED Enhanced Ground Combat Vehicle\n"
       << "\tWater Status:         " << ( KUINT16 )m_ui8WaterStatus                  << " ounce/s\n"
       << "\tRest Status:          " << GetEnumAsStringRestStatus( m_ui8RestStatus ) << "\n"
       << "\tPrimary Ammunition:   " << ( KUINT16 )m_ui8PriAmmun                     << "\n"
       << "\tSecondary Ammunition: " << ( KUINT16 )m_ui8SecAmmun                     << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatSoldier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GED_ENHANCED_GROUND_COMBAT_SOLDIER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    GED_BasicGroundCombatSoldier::Decode( stream );

    stream >> m_ui8WaterStatus
           >> m_ui8RestStatus
           >> m_ui8PriAmmun
           >> m_ui8SecAmmun;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_EnhancedGroundCombatSoldier::Encode() const
{
    KDataStream stream;

    GED_EnhancedGroundCombatSoldier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_EnhancedGroundCombatSoldier::Encode( KDataStream & stream ) const
{
    GED_BasicGroundCombatSoldier::Encode( stream );

    stream << m_ui8WaterStatus
           << m_ui8RestStatus
           << m_ui8PriAmmun
           << m_ui8SecAmmun;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_EnhancedGroundCombatSoldier::operator == ( const GED_EnhancedGroundCombatSoldier & Value ) const
{
    if( GED_BasicGroundCombatSoldier::operator!=( Value ) ) return false;
    if( m_ui8WaterStatus  != Value.m_ui8WaterStatus )       return false;
    if( m_ui8RestStatus   != Value.m_ui8RestStatus )        return false;
    if( m_ui8PriAmmun     != Value.m_ui8PriAmmun )          return false;
    if( m_ui8SecAmmun     != Value.m_ui8SecAmmun )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_EnhancedGroundCombatSoldier::operator != ( const GED_EnhancedGroundCombatSoldier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


