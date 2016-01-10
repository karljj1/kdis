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

#include "./IsGroupOf_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IsGroupOf_PDU::IsGroupOf_PDU() :
    m_ui8GrpdEntCat( 0 ),
    m_ui8NumOfGroupedEnts( 0 ),
    m_ui32Padding1( 0 ),
    m_f64GrpLat( 0 ),
    m_f64GrpLon( 0 )
{
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = IsGroupOf_PDU_Type;
    m_ui16PDULength = IS_GROUP_OF_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IsGroupOf_PDU::IsGroupOf_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IsGroupOf_PDU::IsGroupOf_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
    Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

IsGroupOf_PDU::IsGroupOf_PDU( const EntityIdentifier & EI, GroupedEntityCategory GED, KFLOAT64 GrpLatitude, KFLOAT64 GrpLongitude ) :
    m_GroupedEntityID( EI ),
    m_ui8GrpdEntCat( GED ),
    m_ui8NumOfGroupedEnts( 0 ),
    m_ui32Padding1( 0 ),
    m_f64GrpLat( GrpLatitude ),
    m_f64GrpLon( GrpLongitude )
{
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = IsGroupOf_PDU_Type;
    m_ui16PDULength = IS_GROUP_OF_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IsGroupOf_PDU::IsGroupOf_PDU( const EntityIdentifier & EI, KFLOAT64 GrpLatitude, KFLOAT64 GrpLongitude, const GEDList & GED ) throw( KException ) :
    m_GroupedEntityID( EI ),
    m_ui32Padding1( 0 ),
    m_f64GrpLat( GrpLatitude ),
    m_f64GrpLon( GrpLongitude )
{
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = EntityManagement;
    m_ui8PDUType = IsGroupOf_PDU_Type;

    try
    {
        SetGED( GED );
    }
    catch( const std::exception & e )
    {
        m_ui8NumOfGroupedEnts = 0;
        throw;
    }
}

//////////////////////////////////////////////////////////////////////////

IsGroupOf_PDU::~IsGroupOf_PDU()
{
    m_vpGED.clear();
}

//////////////////////////////////////////////////////////////////////////

void IsGroupOf_PDU::SetGroupedEntityID( const EntityIdentifier & EI )
{
    m_GroupedEntityID = EI;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IsGroupOf_PDU::GetGroupedEntityID() const
{
    return m_GroupedEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IsGroupOf_PDU::GetGroupedEntityID()
{
    return m_GroupedEntityID;
}

//////////////////////////////////////////////////////////////////////////

void IsGroupOf_PDU::SetGroupedEntityCategory( GroupedEntityCategory GED )
{
    m_ui8GrpdEntCat = GED;
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory IsGroupOf_PDU::GetGroupedEntityCategory() const
{
    return ( GroupedEntityCategory )m_ui8GrpdEntCat;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 IsGroupOf_PDU::GetNumberOfGroupedEntities() const
{
    return m_ui8NumOfGroupedEnts;
}

//////////////////////////////////////////////////////////////////////////

void IsGroupOf_PDU::SetGroupReferencePoint( KFLOAT64 Latitude, KFLOAT64 Longitude )
{
    m_f64GrpLat = Latitude;
    m_f64GrpLon = Longitude;
}

//////////////////////////////////////////////////////////////////////////

void IsGroupOf_PDU::SetGroupReferencePointLatitude( KFLOAT64 L )
{
    m_f64GrpLat = L;
}

//////////////////////////////////////////////////////////////////////////

void IsGroupOf_PDU::SetGroupReferencePointLongitude( KFLOAT64 L )
{
    m_f64GrpLon = L;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 IsGroupOf_PDU::GetGroupReferencePointLatitude() const
{
    return m_f64GrpLat;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT64 IsGroupOf_PDU::GetGroupReferencePointLongitude() const
{
    return m_f64GrpLon;
}

//////////////////////////////////////////////////////////////////////////

void IsGroupOf_PDU::AddGED( const GEDItem & GED ) throw( KException )
{
    if( m_ui8GrpdEntCat != GED->GetGroupedEntityCategory() )throw KException( __FUNCTION__, INVALID_DATA );

    m_vpGED.push_back( GED );
    ++m_ui8NumOfGroupedEnts;
    m_ui16PDULength += GED->GetLength();
}

//////////////////////////////////////////////////////////////////////////

void IsGroupOf_PDU::SetGED( const GEDList & GED ) throw( KException )
{
    if( GED.size() == 0 )return;

    KUINT8 i = 0;

    GroupedEntityCategory gec = GED[i]->GetGroupedEntityCategory();
    ++i;

    while( i < GED.size() )
    {
        if( GED[i]->GetGroupedEntityCategory() != gec )throw KException( __FUNCTION__, INVALID_DATA );
        ++i;
    }

    m_ui8GrpdEntCat = gec;

    m_vpGED.clear();

    m_vpGED = GED;

    m_ui8NumOfGroupedEnts = m_vpGED.size();

    // Calc new PDU length.
    m_ui16PDULength = IS_GROUP_OF_PDU_SIZE;

    i = 0;

    while( i < GED.size() )
    {
        m_ui16PDULength += m_vpGED[i]->GetLength();
        ++i;
    }
}

//////////////////////////////////////////////////////////////////////////

const GEDList & IsGroupOf_PDU::GetGED() const
{
    return m_vpGED;
}

//////////////////////////////////////////////////////////////////////////

KString IsGroupOf_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Is Group Of PDU-\n"
       << m_GroupedEntityID.GetAsString()
       << "Grouped Entity Category:         " << GetEnumAsStringGroupedEntityCategory( m_ui8GrpdEntCat ) << "\n"
       << "Number Of Grouped Entity:        " << ( KUINT16 )m_ui8NumOfGroupedEnts                        << "\n"
       << "Group Reference Point(Lat,Lon) : " << m_f64GrpLat << " , " << m_f64GrpLon                     << "\n";

    KUINT8 i = 0;

    while( i < m_vpGED.size() )
    {
        ss << m_vpGED[i]->GetAsString();
        ++i;
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IsGroupOf_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < IS_GROUP_OF_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vpGED.clear();

    Header::Decode( stream, ignoreHeader );

    stream >> KDIS_STREAM m_GroupedEntityID
           >> m_ui8GrpdEntCat
           >> m_ui8NumOfGroupedEnts
           >> m_ui32Padding1
           >> m_f64GrpLat
           >> m_f64GrpLon;

    KUINT8 i = 0;

    while( i < m_ui8NumOfGroupedEnts )
    {
        switch( m_ui8GrpdEntCat )
        {
        case BasicGroundCombatVehicleGEC:
            m_vpGED.push_back( GEDItem( new GED_BasicGroundCombatVehicle( stream ) ) );
            break;
        case EnhancedGroundCombatVehicleGEC:
            m_vpGED.push_back( GEDItem( new GED_EnhancedGroundCombatVehicle( stream ) ) );
            break;
        case BasicGroundCombatSoldierGEC:
            m_vpGED.push_back( GEDItem( new GED_BasicGroundCombatSoldier( stream ) ) );
            break;
        case EnhancedGroundCombatSoldierGEC:
            m_vpGED.push_back( GEDItem( new GED_EnhancedGroundCombatSoldier( stream ) ) );
            break;
        case BasicRotorWingAircraftGEC:
            m_vpGED.push_back( GEDItem( new GED_BasicRotorWingAircraft( stream ) ) );
            break;
        case EnhancedRotorWingAircraftGEC:
            m_vpGED.push_back( GEDItem( new GED_EnhancedRotaryWingAircraft( stream ) ) );
            break;
        case BasicFixedWingAircraftGEC:
            m_vpGED.push_back( GEDItem( new GED_BasicFixedWingAircraft( stream ) ) );
            break;
        case EnhancedFixedWingAircraftGEC:
            m_vpGED.push_back( GEDItem( new GED_EnhancedFixedWingAircraft( stream ) ) );
            break;
        case GroundLogisticsVehicleGEC:
            m_vpGED.push_back( GEDItem( new GED_GroundLogisticsVehicle( stream ) ) );
            break;
        }
        ++i;
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IsGroupOf_PDU::Encode() const
{
    KDataStream stream;

    IsGroupOf_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IsGroupOf_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_GroupedEntityID
           << m_ui8GrpdEntCat
           << m_ui8NumOfGroupedEnts
           << m_ui32Padding1
           << m_f64GrpLat
           << m_f64GrpLon;

    KUINT8 i = 0;

    while( i < m_vpGED.size() )
    {
        m_vpGED[i]->Encode( stream );
        ++i;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL IsGroupOf_PDU::operator == ( const IsGroupOf_PDU & Value ) const
{
    if( Header::operator      !=( Value ) )                    return false;
    if( m_GroupedEntityID     != Value.m_GroupedEntityID )     return false;
    if( m_ui8GrpdEntCat       != Value.m_ui8GrpdEntCat )       return false;
    if( m_ui8NumOfGroupedEnts != Value.m_ui8NumOfGroupedEnts ) return false;
    if( m_f64GrpLat           != Value.m_f64GrpLat )           return false;
    if( m_f64GrpLon           != Value.m_f64GrpLon )           return false;
    if( m_vpGED               != Value.m_vpGED )               return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IsGroupOf_PDU::operator != ( const IsGroupOf_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////




