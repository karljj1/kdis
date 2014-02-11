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
    class:      Data_Query_PDU
    DIS:        (5) 1278.1 - 1995
    created:    08/10/2008
    author:     Karl Jones

    purpose:    Requests for data from an entity are communicated by a Data Query PDU
	size:       320 bits/ 40 octets - not including variable param sizes
*********************************************************************/

#pragma once

#include "./Data_PDU.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Data_Query_PDU : public Simulation_Management_Header
{
protected:
	
    KUINT32 m_ui32RequestID;

	KDIS::DATA_TYPE::TimeStamp m_TimeInterval;	
	
	KUINT32 m_ui32NumFixedDatum;

    KUINT32 m_ui32NumVariableDatum;

	std::vector<KUINT32> m_vFixedDatum;

	std::vector<KUINT32> m_vVariableDatum;    

public:

    static const KUINT16 DATA_QUERY_PDU_SIZE = 40;

    Data_Query_PDU();

	Data_Query_PDU( const Header & H );

    Data_Query_PDU( KDataStream & stream ) throw( KException );

	Data_Query_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Data_Query_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID,
                    KUINT32 RequestID );

    virtual ~Data_Query_PDU();
	
    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::SetRequestID
    //              KDIS::PDU::Data_Query_PDU::GetRequestID
    // Description: Request ID, identifies the matching response
    //              to a Data Query PDU or Set Data PDU.
    // Parameter:   KUINT32 ID
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;	

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::SetTimeInterval
    //              KDIS::PDU::Data_Query_PDU::GetTimeInterval
    // Description: Specifies the time interval between issues of
    //              Data PDUs, a value of 0(default) indicates the data should
    //              be sent once and not at any other time intervals.
    // Parameter:   TimeStamp TI
    //************************************
    void SetTimeInterval( const KDIS::DATA_TYPE::TimeStamp & TI );
    const KDIS::DATA_TYPE::TimeStamp & GetTimeInterval() const;
	KDIS::DATA_TYPE::TimeStamp & GetTimeInterval();

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::GetNumberFIxedDatum
    // Description: Returns number of fixed datum records
    //************************************
    KUINT32 GetNumberFIxedDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::GetNumberVariableDatum
    // Description: Returns number of variable datum records
    //************************************
    KUINT32 GetNumberVariableDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::AddFixedDatum
    //              KDIS::PDU::Data_Query_PDU::SetFixedDatum
    //              KDIS::PDU::Data_Query_PDU::GetFixedDatum
    // Description: Datum ID's for which information is required.
    // Parameter:   KUINT32 FD, const vector<KUINT32> & FD
    //************************************
    void AddFixedDatum( KUINT32 FD );
	void SetFixedDatum( const std::vector<KUINT32> & FD );
	const std::vector<KUINT32> & GetFixedDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::AddVariableDatum
    //              KDIS::PDU::Data_Query_PDU::SetVariableDatum
    //              KDIS::PDU::Data_Query_PDU::GetVariableDatum
    // Description: Datum ID's for which information is required.
    // Parameter:   VarDtmPtr VD, const vector<VarDtmPtr> & VD
    //************************************
    void AddVariableDatum( KUINT32 VD );
	void SetVariableDatum( const std::vector<KUINT32> & VD );
	const std::vector<KUINT32> & GetVariableDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Data_Query_PDU & Value ) const;
    KBOOL operator != ( const Data_Query_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS

