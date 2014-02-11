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

#include "./Minefield_Query_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace std;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::calcPadding()
{
    // Do we need to pad the PDU?
    // The PDU should be aligned to a 32 bit / 4 octet boundary.
    // We will either need 2 octet pad or 0 depending on how many perimeter points are included.
    if( m_bNeedsPadding )
    {
        m_ui16PDULength -= 2;
    }

    KUINT8 ui8PaddingNeeded = m_ui8NumSensTyp % 2;

    if( ui8PaddingNeeded )
    {
        m_bNeedsPadding = true;
        m_ui16PDULength += 2;
    }
    else
    {
        m_bNeedsPadding = false;
    }
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Minefield_Query_PDU::Minefield_Query_PDU() :
    m_ui8ReqID( 0 ),
    m_ui8NumPerimPoints( 0 ),
    m_ui8Padding1( 0 ),
    m_ui8NumSensTyp( 0 ),
    m_bNeedsPadding( 0 ),
    m_ui16Padding1( 0 )
{
    m_ui8PDUType = MinefieldQuery_PDU_Type;
    m_ui16PDULength = MINEFIELD_QUERY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Minefield_Query_PDU::Minefield_Query_PDU( const EntityIdentifier & MinefieldID, const EntityIdentifier & RequestingSimulationID,
        KUINT8 RequestID, const MinefieldDataFilter & DF, const EntityType & MineTypeFilter ) :
    m_ReqID( RequestingSimulationID ),
    m_ui8ReqID( RequestID ),
    m_DataFilter( DF ),
    m_MineTypFilter( MineTypeFilter ),
    m_ui8NumPerimPoints( 0 ),
    m_ui8Padding1( 0 ),
    m_ui8NumSensTyp( 0 ),
    m_bNeedsPadding( 0 ),
    m_ui16Padding1( 0 )
{
    m_ui8PDUType = MinefieldQuery_PDU_Type;
    m_ui16PDULength = MINEFIELD_QUERY_PDU_SIZE;
    m_MinefieldID = MinefieldID;
}

//////////////////////////////////////////////////////////////////////////

Minefield_Query_PDU::Minefield_Query_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Minefield_Query_PDU::Minefield_Query_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Minefield_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Minefield_Query_PDU::~Minefield_Query_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::SetRequestingSimulationID( const EntityIdentifier & ID )
{
    m_ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Minefield_Query_PDU::GetRequestingSimulationID() const
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Minefield_Query_PDU::GetRequestingSimulationID()
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::SetRequestID( KUINT8 ID )
{
    m_ui8ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Query_PDU::GetRequestID() const
{
    return m_ui8ReqID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Query_PDU::GetNumberOfPerimeterPoints() const
{
    return m_ui8NumPerimPoints;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Query_PDU::GetNumberOfSensorsTypes() const
{
    return m_ui8NumSensTyp;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::SetDataFilter( const MinefieldDataFilter & DF )
{
    m_DataFilter = DF;
}

//////////////////////////////////////////////////////////////////////////

const MinefieldDataFilter & Minefield_Query_PDU::GetDataFilter() const
{
    return m_DataFilter;
}

//////////////////////////////////////////////////////////////////////////

MinefieldDataFilter & Minefield_Query_PDU::GetDataFilter()
{
    return m_DataFilter;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::SetMineTypeFilter( const EntityType & MT )
{
    m_MineTypFilter = MT;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & Minefield_Query_PDU::GetMineTypeFilter() const
{
    return m_MineTypFilter;
}

//////////////////////////////////////////////////////////////////////////

EntityType & Minefield_Query_PDU::GetMineTypeFilter()
{
    return m_MineTypFilter;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::AddRequestedPerimeterPointCoordinate( const PerimeterPointCoordinate & PPC )
{
    m_vPoints.push_back( PPC );
    m_ui16PDULength += PerimeterPointCoordinate::PERIMETER_POINT_COORDINATE_SIZE;
    ++m_ui8NumPerimPoints;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::SetRequestedPerimeterPointCoordinates( const std::vector<PerimeterPointCoordinate> & PPC )
{
    // Subtract old values from pdu length.
    m_ui16PDULength -= m_ui8NumPerimPoints * PerimeterPointCoordinate::PERIMETER_POINT_COORDINATE_SIZE;

    m_vPoints = PPC;
    m_ui8NumPerimPoints = m_vPoints.size();

    // Calculate the new size
    m_ui16PDULength += m_ui8NumPerimPoints * PerimeterPointCoordinate::PERIMETER_POINT_COORDINATE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

const std::vector<PerimeterPointCoordinate> & Minefield_Query_PDU::GetRequestedPerimeterPointCoordinates() const
{
    return m_vPoints;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::AddSensorType( SensorType ST )
{
    m_vui16SensorTypes.push_back( ST );
    m_ui16PDULength += 2; // 16 bit enum. = 2 octets
    ++m_ui8NumSensTyp;
    calcPadding();
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::SetSensorTypes( const vector<KUINT16> & ST )
{
    // Subtract old values from pdu length.
    m_ui16PDULength -= m_ui8NumSensTyp * 2; // 2 = size of sensor type.

    m_vui16SensorTypes = ST;
    m_ui8NumSensTyp = m_vui16SensorTypes.size();

    // Calculate the new size
    m_ui16PDULength += m_ui8NumSensTyp * 2;
    calcPadding();
}

//////////////////////////////////////////////////////////////////////////

const vector<KUINT16> & Minefield_Query_PDU::GetSensorTypes() const
{
    return m_vui16SensorTypes;
}

//////////////////////////////////////////////////////////////////////////

KString Minefield_Query_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Minefield Query PDU-\n"
       << Minefield_Header::GetAsString()
       << "Requesting ID:			" << IndentString( m_ReqID.GetAsString(), 1 )
       << "Request ID:				" << ( KUINT16 )m_ui8ReqID                     << "\n"
       << "Number Of Permim Points: " << ( KUINT16 )m_ui8NumPerimPoints          << "\n"
       << "Number Of Sensor Types:  " << ( KUINT16 )m_ui8NumSensTyp              << "\n"
       << m_DataFilter.GetAsString()
       << "Mine Type Filter:		" << m_MineTypFilter.GetAsString()
       << "Perimeter Points:\n";

    std::vector<PerimeterPointCoordinate>::const_iterator citrPnt = m_vPoints.begin();
    std::vector<PerimeterPointCoordinate>::const_iterator citrEndPnt = m_vPoints.end();
    for( ; citrPnt != citrEndPnt; ++citrPnt )
    {
        ss << IndentString( citrPnt->GetAsString(), 1 );
    }

    ss << "Sensor Types:\n";

    std::vector<KUINT16>::const_iterator citrSt = m_vui16SensorTypes.begin();
    std::vector<KUINT16>::const_iterator citrEndSt = m_vui16SensorTypes.end();
    for( ; citrSt != citrEndSt; ++citrSt )
    {
        ss << "\t" << *citrSt << "\n";
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < MINEFIELD_QUERY_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vPoints.clear();
    m_vui16SensorTypes.clear();

    Minefield_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_ReqID
           >> m_ui8ReqID
           >> m_ui8NumPerimPoints
           >> m_ui8Padding1
           >> m_ui8NumSensTyp
           >> KDIS_STREAM m_DataFilter
           >> KDIS_STREAM m_MineTypFilter;

    for( KUINT8 i = 0; i < m_ui8NumPerimPoints; ++i )
    {
        m_vPoints.push_back( PerimeterPointCoordinate( stream ) );
    }

    KUINT16 ui16Tmp = 0;
    for( KUINT16 j = 0; j < m_ui8NumSensTyp; ++j )
    {
        stream >> ui16Tmp;
        m_vui16SensorTypes.push_back( ui16Tmp );
    }

    // Does the PDU contain padding?
    calcPadding();
    if( m_bNeedsPadding )
    {
        stream >> m_ui16Padding1;
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Minefield_Query_PDU::Encode() const
{
    KDataStream stream;

    Minefield_Query_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Query_PDU::Encode( KDataStream & stream ) const
{
    Minefield_Header::Encode( stream );

    stream << KDIS_STREAM m_ReqID
           << m_ui8ReqID
           << m_ui8NumPerimPoints
           << m_ui8Padding1
           << m_ui8NumSensTyp
           << KDIS_STREAM m_DataFilter
           << KDIS_STREAM m_MineTypFilter;

    std::vector<PerimeterPointCoordinate>::const_iterator citrPnt = m_vPoints.begin();
    std::vector<PerimeterPointCoordinate>::const_iterator citrEndPnt = m_vPoints.end();
    for( ; citrPnt != citrEndPnt; ++citrPnt )
    {
        citrPnt->Encode( stream );
    }

    std::vector<KUINT16>::const_iterator citrSt = m_vui16SensorTypes.begin();
    std::vector<KUINT16>::const_iterator citrEndSt = m_vui16SensorTypes.end();
    for( ; citrSt != citrEndSt; ++citrSt )
    {
        stream << *citrSt;
    }

    if( m_bNeedsPadding )
    {
        stream << m_ui16Padding1;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Minefield_Query_PDU::operator == ( const Minefield_Query_PDU & Value ) const
{
    if( Minefield_Header::operator  != ( Value ) )                  return false;
    if( m_ReqID                     != Value.m_ReqID )              return false;
    if( m_ui8ReqID                  != Value.m_ui8ReqID )           return false;
    if( m_ui8NumPerimPoints         != Value.m_ui8NumPerimPoints )  return false;
    if( m_ui8NumSensTyp             != Value.m_ui8NumSensTyp )      return false;
    if( m_MineTypFilter             != Value.m_MineTypFilter )      return false;
    if( m_vPoints                   != Value.m_vPoints )            return false;
    if( m_vui16SensorTypes          != Value.m_vui16SensorTypes )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Minefield_Query_PDU::operator != ( const Minefield_Query_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
