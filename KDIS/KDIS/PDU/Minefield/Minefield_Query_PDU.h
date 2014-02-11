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

class KDIS_EXPORT Minefield_Query_PDU : public Minefield_Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_ReqID;

    KUINT8 m_ui8ReqID;

    KUINT8 m_ui8NumPerimPoints;

    KUINT8 m_ui8Padding1;

    KUINT8 m_ui8NumSensTyp;

    KDIS::DATA_TYPE::MinefieldDataFilter m_DataFilter;

    KDIS::DATA_TYPE::EntityType m_MineTypFilter;

	std::vector<KDIS::DATA_TYPE::PerimeterPointCoordinate> m_vPoints;

	std::vector<KUINT16> m_vui16SensorTypes;
    KBOOL m_bNeedsPadding;
    KUINT16 m_ui16Padding1;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::calcPadding
    // Description: Calculates the padding so the PDU lies on a 32 bit boundary.
    //************************************
    void calcPadding();

public:

    static const KUINT16 MINEFIELD_QUERY_PDU_SIZE = 40; // Min size

    Minefield_Query_PDU();

	Minefield_Query_PDU( KDataStream & stream ) throw( KException );

	Minefield_Query_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Minefield_Query_PDU( const KDIS::DATA_TYPE::EntityIdentifier & MinefieldID, const KDIS::DATA_TYPE::EntityIdentifier & RequestingSimulationID,
                         KUINT8 RequestID, const KDIS::DATA_TYPE::MinefieldDataFilter & DF, const KDIS::DATA_TYPE::EntityType & MineTypeFilter );

    virtual ~Minefield_Query_PDU();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::SetRequestingSimulationID
    //              KDIS::PDU::Minefield_Query_PDU::GetRequestingSimulationID
    // Description: The simulation that is requesting the information.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetRequestingSimulationID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetRequestingSimulationID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetRequestingSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::SetRequestID
    //              KDIS::PDU::Minefield_Query_PDU::GetRequestID
    // Description: Identifies the minefield query request.
    // Parameter:   KUINT8 ID
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
    // Parameter:   const MinefieldDataFilter & DF
    //************************************
    void SetDataFilter( const KDIS::DATA_TYPE::MinefieldDataFilter & DF );
    const KDIS::DATA_TYPE::MinefieldDataFilter & GetDataFilter() const;
    KDIS::DATA_TYPE::MinefieldDataFilter & GetDataFilter();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::SetMineTypeFilter
    //              KDIS::PDU::Minefield_Query_PDU::GetMineTypeFilter
    // Description: Requested Mine Type Filter. Specifies the type of mine being queried by the requesting
    //              simulation.
    //              If a subfield within the Requested Minefield Type filter record (e.g., the country
    //              field) contains the value –1 (all bits set), then all subfield values shall match the filter
    //              (e.g., all countries are allowed).
    // Parameter:   const EntityType & MT
    //************************************
    void SetMineTypeFilter( const KDIS::DATA_TYPE::EntityType & MT );
    const KDIS::DATA_TYPE::EntityType & GetMineTypeFilter() const;
    KDIS::DATA_TYPE::EntityType & GetMineTypeFilter();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::AddRequestedPerimeterPointCoordinate
    //              KDIS::PDU::Minefield_Query_PDU::SetRequestedPerimeterPointCoordinates
    //              KDIS::PDU::Minefield_Query_PDU::GetRequestedPerimeterPointCoordinates
    // Description: Specifies the location of each perimeter point in the requested area,
    //              relative to the Minefield Location field from the Minefield State PDU.
    //              Only the x and y coordinates shall be specified.
    // Parameter:   const PerimeterPointCoordinate & PPC, vector<PerimeterPointCoordinate> & PPC
    //************************************
    void AddRequestedPerimeterPointCoordinate( const KDIS::DATA_TYPE::PerimeterPointCoordinate & PPC );
	void SetRequestedPerimeterPointCoordinates( const std::vector<KDIS::DATA_TYPE::PerimeterPointCoordinate> & PPC );
	const std::vector<KDIS::DATA_TYPE::PerimeterPointCoordinate> & GetRequestedPerimeterPointCoordinates() const;

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
    // Parameter:   SensorType ST, vector<KUINT16> & ST
    //************************************
	void AddSensorType( KDIS::DATA_TYPE::ENUMS::SensorType ST );
	void SetSensorTypes( const std::vector<KUINT16> & ST );
	const std::vector<KUINT16> & GetSensorTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Query_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS
