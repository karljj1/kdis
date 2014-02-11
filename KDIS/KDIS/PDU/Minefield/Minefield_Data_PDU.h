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
    class:      Minefield_Data_PDU
    DIS:        (6) 1278.1a - 1998
    created:    25/05/2010
    author:     Karl Jones

    purpose:    Provides information on individual mines contained within a minefield.

                Note: This is a very complex PDU(The hardest one in the standard!), I do not have access to any software to test Minefield
                PDU's so it may contain traces of nuts(bugs). Please let me know if you have any problems. Karl.

    size:       352 bits / 44 octets  - Min size
*********************************************************************/

#pragma once

#include "./Minefield_Header.h"
#include "./../../DataTypes/MinefieldDataFilter.h"
#include "./../../DataTypes/EntityType.h"
#include "./../../DataTypes/Vector.h"
#include "./../../DataTypes/EulerAngles.h"
#include "./../../DataTypes/Mine.h"
#include <vector>

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Minefield_Data_PDU : public Minefield_Header
{
protected:

	KDIS::DATA_TYPE::EntityIdentifier m_ReqID;

    union
    {
        struct
        {
            KUINT16 m_ui16Reserved : 1;
            KUINT16 m_ui16SeqNum15 : 15;
        };
        KUINT16 m_ui16SeqNum;
    } m_SeqNumUnion;

    KUINT8 m_ui8ReqID;

    KUINT8 m_ui8PduSeqNum;

    KUINT8 m_ui8NumPdus;

    KUINT8 m_ui8NumMines;

    KUINT8 m_ui8NumSensTyp;

    KUINT8 m_ui8Padding1;

    KDIS::DATA_TYPE::MinefieldDataFilter m_DataFilter;

    KDIS::DATA_TYPE::EntityType m_MineTyp;

	std::vector<KUINT16> m_vui16SensorTypes;

	std::vector<KDIS::DATA_TYPE::Mine> m_vMines;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::calcPaddingPaintScheme
    // Description: Calculates the padding after the paint scheme.
    //              Padding — 8{[4 – N(2 F(8) + M F(9) + F(10) + 2)]    mod4} bits unused
    //              PDU lies on a 32 bit boundary.
    //************************************
    KUINT8 calcPaddingPaintScheme() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::calcPaddingPaintScheme
    // Description: Calculates the padding after the Number of Vertices's field.
    //************************************
    KUINT8 calcPaddingVertices() const;

public:

    static const KUINT16 MINEFIELD_DATA_PDU_SIZE = 44; // Min size

    Minefield_Data_PDU();

	Minefield_Data_PDU( KDataStream & stream ) throw( KException );

	Minefield_Data_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Minefield_Data_PDU( const KDIS::DATA_TYPE::EntityIdentifier & MinefieldID, const KDIS::DATA_TYPE::EntityIdentifier & RequestingSimulationID,
                        KUINT16 SeqNum, KUINT8 RequestID, KUINT8 PduSeqNum, KUINT8 NumPdus,
                        const KDIS::DATA_TYPE::MinefieldDataFilter & DF, const KDIS::DATA_TYPE::EntityType & MineType );

    virtual ~Minefield_Data_PDU();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::SetRequestingSimulationID
    //              KDIS::PDU::Minefield_Data_PDU::GetRequestingSimulationID
    // Description: The simulation that is requesting the information.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetRequestingSimulationID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetRequestingSimulationID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetRequestingSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::SetSequenceNumber
    //              KDIS::PDU::Minefield_Data_PDU::GetSequenceNumber
    // Description: Identifies the matching minefield sequence number
    //              from the associated Minefield State PDU.
    // Parameter:   KUINT16 S
    //************************************
    void SetSequenceNumber( KUINT16 S );
    KUINT16 GetSequenceNumber() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::SetRequestID
    //              KDIS::PDU::Minefield_Data_PDU::GetRequestID
    // Description: The matching response to a request for mine information from the
    //              minefield simulation made by means of a Minefield Query PDU
    //              in QRP mode. In heartbeat mode, this field shall contain the value zero.
    // Parameter:   KUINT8 ID
    //************************************
    void SetRequestID( KUINT8 ID );
    KUINT8 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::SetPDUSequenceNumber
    //              KDIS::PDU::Minefield_Data_PDU::GetPDUSequenceNumber
    // Description: Specifies the number of the current Minefield Data PDU in a
    //              sequence of Minefield Data PDUs sent in response to a Minefield
    //              Query PDU when operating in QRP mode.
    //              When operating in heartbeat mode, this field is unused and shall contain the value zero.
    // Parameter:   KUINT8 SN
    //************************************
    void SetPDUSequenceNumber( KUINT8 SN );
    KUINT8 GetPDUSequenceNumber() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::GetNumberOfPDUs
    //              KDIS::PDU::Minefield_Data_PDU::SetNumberOfPDUs
    // Description: The total number of Minefield Data PDUs being sent in
    //              response to a Minefield Query PDU when operating in QRP mode.
    //              When operating in heartbeat mode, this field is unused and shall contain the value zero.
    // Parameter:   KUINT8 N
    //************************************
    void SetNumberOfPDUs( KUINT8 N );
    KUINT8 GetNumberOfPDUs() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::GetNumberOfMines
    // Description: The number of mines of the same type contained in this PDU.
    //************************************
    KUINT8 GetNumberOfMines() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::GetNumberOfSensorsTypes
    // Description: In QRP mode, this field shall specify the number of sensor types employed
    //              by the requesting simulation as specified in the Minefield Query PDU.
    //              In heartbeat mode, this field shall specify the number of sensor types
    //              employed in the exercise.
    //************************************
    KUINT8 GetNumberOfSensorsTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::SetDataFilter
    //              KDIS::PDU::Minefield_Data_PDU::GetDataFilter
    // Description: Identifies which of the optional data fields are set in
    //              the mines contained in this Minefield Data PDU.
    // Parameter:   const MinefieldDataFilter & DF
    //************************************
    void SetDataFilter( const KDIS::DATA_TYPE::MinefieldDataFilter & DF );
    const KDIS::DATA_TYPE::MinefieldDataFilter & GetDataFilter() const;
    KDIS::DATA_TYPE::MinefieldDataFilter & GetDataFilter();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::SetMineType
    //              KDIS::PDU::Minefield_Data_PDU::GetMineType
    // Description: The type of mine contained in this PDU.
    // Parameter:   const MinefieldDataFilter & DF
    //************************************
    void SetMineType( const KDIS::DATA_TYPE::EntityType & MT );
    const KDIS::DATA_TYPE::EntityType & GetMineType() const;
    KDIS::DATA_TYPE::EntityType & GetMineType();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::AddSensorType
    //              KDIS::PDU::Minefield_Data_PDU::SetSensorTypes
    //              KDIS::PDU::Minefield_Data_PDU::GetSensorTypes
    // Description: In QRP mode, this field shall specify the requesting sensor types
    //              which were specified in the Minefield Query PDU. In heartbeat mode,
    //              this field shall specify the sensor types that are being served by the minefield
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
    // FullName:    KDIS::PDU::Minefield_Data_PDU::AddMine
    //              KDIS::PDU::Minefield_Data_PDU::SetMines
    //              KDIS::PDU::Minefield_Data_PDU::GetMines
    // Description: The Mine class encapsulates the common attributes for a mine.
    //              Note: All the mines must have the same optional values set as stated by the
    //              MinefieldDataFilter, if they are not then an INVALID_OPERATION exception is thrown.
    // Parameter:   const Mine & M, const vector<Mine> & M
    //************************************
    void AddMine( const KDIS::DATA_TYPE::Mine & M ) throw( KException );
	void SetMines( const std::vector<KDIS::DATA_TYPE::Mine> & M ) throw( KException );
	const std::vector<KDIS::DATA_TYPE::Mine> & GetMines() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Minefield_Data_PDU::Encode
    // Description: Convert To Network Data. Exception is thrown if each mine does not
    //              have a ScalarDetectionCoefficient value for each sensor type.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const throw( KException );
    virtual void Encode( KDataStream & stream ) const throw( KException );

    KBOOL operator == ( const Minefield_Data_PDU & Value ) const;
    KBOOL operator != ( const Minefield_Data_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
