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

/********************************************************************
    class:      Minefield_Query_PDU
    DIS:        (6) 1278.1a - 1998
    created:    17/05/2010
    author:     Karl Jones

    purpose:    Provides the means to query a minefield simulation for information on individual
                mines contained within a minefield when operating in QRP mode (MinefieldProtocolMode = 1).

    size:       320 bits / 40 octets  - Min size
*********************************************************************/

#pragma once

#include "./Minefield_Header.h"
#include "./../../DataTypes/MinefieldDataFilter.h"
#include "./../../DataTypes/EntityType.h"
#include "./../../DataTypes/PerimeterPointCoordinate.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::MinefieldDataFilter;
using KDIS::DATA_TYPE::EntityType;
using KDIS::DATA_TYPE::PerimeterPointCoordinate;
using KDIS::DATA_TYPE::ENUMS::SensorType;
using std::vector;

class KDIS_EXPORT Minefield_Query_PDU : public Minefield_Header
{
protected:

    EntityIdentifier m_ReqID;

    KUINT8 m_ui8ReqID;

    KUINT8 m_ui8NumPerimPoints;

    KUINT8 m_ui8Padding1;

    KUINT8 m_ui8NumSensTyp;

    MinefieldDataFilter m_DataFilter;

    EntityType m_MineTypFilter;

    vector<PerimeterPointCoordinate> m_vPoints;

    vector<KUINT16> m_vui16SensorTypes;
    KBOOL m_bNeedsPadding;
    KUINT16 m_ui16Padding1;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::calcPadding
    // Description: Calculates the padding so the PDU lies on a 32 bit boundary.
    //************************************
    void calcPadding();

public:

    static const KUINT16 MINEFIELD_QUERY_PDU_SIZE = 40; // Min size

    Minefield_Query_PDU( void );

    Minefield_Query_PDU( const EntityIdentifier & MinefieldID, const EntityIdentifier & RequestingSimulationID,
                         KUINT8 RequestID, const MinefieldDataFilter & DF, const EntityType & MineTypeFilter );

    Minefield_Query_PDU( KDataStream & stream ) throw( KException );

    virtual ~Minefield_Query_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::SetRequestingSimulationID
    //              KDIS::PDU::Minefield_Query_PDU::GetRequestingSimulationID
    // Description: The simulation that is requesting the information.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetRequestingSimulationID( const EntityIdentifier & ID );
    const EntityIdentifier & GetRequestingSimulationID() const;
    EntityIdentifier & GetRequestingSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::SetRequestID
    //              KDIS::PDU::Minefield_Query_PDU::GetRequestID
    // Description: Identifies the minefield query request.
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetRequestID( KUINT8 ID );
    KUINT8 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::GetNumberOfPerimeterPoints
    // Description: Number of points in the perimeter of the minefield.
    //************************************
    KUINT8 GetNumberOfPerimeterPoints() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::GetNumberOfSensorsTypes
    // Description: The number of sensor types employed by the requesting simulation.
    //              A zero in this field shall indicate that the requesting simulation
    //              is not a detection system.
    //************************************
    KUINT8 GetNumberOfSensorsTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::SetDataFilter
    //              KDIS::PDU::Minefield_Query_PDU::GetDataFilter
    // Description: The data filter is used to identify which of the optional
    //              fields are being requested.
    // Parameter:   const MinefieldDataFilter & DF, void
    //************************************
    void SetDataFilter( const MinefieldDataFilter & DF );
    const MinefieldDataFilter & GetDataFilter() const;
    MinefieldDataFilter & GetDataFilter();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::SetMineTypeFilter
    //              KDIS::PDU::Minefield_Query_PDU::GetMineTypeFilter
    // Description: Requested Mine Type Filter. Specifies the type of mine being queried by the requesting
    //              simulation.
    //              If a subfield within the Requested Minefield Type filter record (e.g., the country
    //              field) contains the value –1 (all bits set), then all subfield values shall match the filter
    //              (e.g., all countries are allowed).
    // Parameter:   const EntityType & MT, void
    //************************************
    void SetMineTypeFilter( const EntityType & MT );
    const EntityType & GetMineTypeFilter() const;
    EntityType & GetMineTypeFilter();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::AddRequestedPerimeterPointCoordinate
    //              KDIS::PDU::Minefield_Query_PDU::SetRequestedPerimeterPointCoordinates
    //              KDIS::PDU::Minefield_Query_PDU::GetRequestedPerimeterPointCoordinates
    // Description: Specifies the location of each perimeter point in the requested area,
    //              relative to the Minefield Location field from the Minefield State PDU.
    //              Only the x and y coordinates shall be specified.
    // Parameter:   const PerimeterPointCoordinate & PPC, vector<PerimeterPointCoordinate> & PPC, void
    //************************************
    void AddRequestedPerimeterPointCoordinate( const PerimeterPointCoordinate & PPC );
    void SetRequestedPerimeterPointCoordinates( const vector<PerimeterPointCoordinate> & PPC );
    const vector<PerimeterPointCoordinate> & GetRequestedPerimeterPointCoordinates() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::AddSensorType
    //              KDIS::PDU::Minefield_Query_PDU::SetSensorTypes
    //              KDIS::PDU::Minefield_Query_PDU::GetSensorTypes
    // Description: Specifies which types of sensors are requesting the data. The type of
    //              sensor determines which scalar detection coefficients shall be included
    //              in the Minefield Data PDU.
    //              The sensor type is represented as a 16 bit enumeration where bits 0-3
    //              identify the category of the sensor type and bits 4-15 identify the
    //              subcategory within the specified category.
    //              The enum SensorType(EnumMinefield.h) provides all sensor types from SISO-REF-10-2006 which have all the bits set
    //              correctly for each sensor type.
    // Parameter:   SensorType ST, vector<KUINT16> & ST, void
    //************************************
    void AddSensorType( SensorType ST );
    void SetSensorTypes( const vector<KUINT16> & ST );
    const vector<KUINT16> & GetSensorTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Minefield_Query_PDU & Value ) const;
    KBOOL operator != ( const Minefield_Query_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
