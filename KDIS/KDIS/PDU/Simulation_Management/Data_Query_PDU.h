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

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Data_Query_PDU : public Simulation_Management_Header
{
protected:
	
    KUINT32 m_ui32RequestID;

	TimeStamp m_TimeInterval;	
	
	KUINT32 m_ui32NumFixedDatum;

    KUINT32 m_ui32NumVariableDatum;

    vector<KUINT32> m_vFixedDatum;

    vector<KUINT32> m_vVariableDatum;    

public:

    static const KUINT16 DATA_QUERY_PDU_SIZE = 40;

    Data_Query_PDU( void );

    Data_Query_PDU( KDataStream & stream ) throw( KException );

    Data_Query_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                    KUINT32 RequestID );

    virtual ~Data_Query_PDU( void );
	
    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::SetRequestID
    //              KDIS::PDU::Data_Query_PDU::GetRequestID
    // Description: Request ID, identifies the matching response
    //              to a Data Query PDU or Set Data PDU.
    // Parameter:   KUINT32 ID, void
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
    void SetTimeInterval( const TimeStamp & TI );
    const TimeStamp & GetTimeInterval() const;
	TimeStamp & GetTimeInterval();

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
    void SetFixedDatum( const vector<KUINT32> & FD );
    const vector<KUINT32> & GetFixedDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::AddVariableDatum
    //              KDIS::PDU::Data_Query_PDU::SetVariableDatum
    //              KDIS::PDU::Data_Query_PDU::GetVariableDatum
    // Description: Datum ID's for which information is required.
    // Parameter:   VarDtmPtr VD, const vector<VarDtmPtr> & VD
    //************************************
    void AddVariableDatum( KUINT32 VD );
    void SetVariableDatum( const vector<KUINT32> & VD );
    const vector<KUINT32> & GetVariableDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Data_Query_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS

