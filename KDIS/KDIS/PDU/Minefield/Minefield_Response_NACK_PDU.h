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
    class:      Minefield_Response_NACK_PDU
    DIS:        (6) 1278.1a - 1998
    created:    25/06/2010
    author:     Karl Jones

    purpose:    Provides the means by which a simulation shall request a minefield
                simulation to retransmit Minefield Data PDUs not received in response
                to a query when operating in QRP mode.
    size:       208 bits / 26 octets  - Min size
*********************************************************************/

#pragma once

#include "./Minefield_Header.h"
#include "./../../DataTypes/EntityType.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::EntityType;
using std::vector;

class KDIS_EXPORT Minefield_Response_NACK_PDU : public Minefield_Header
{
protected:

    EntityIdentifier m_ReqID;

    KUINT8 m_ui8ReqID;

    KUINT8 m_ui8NumMisPdus;

    vector<KUINT8> m_vSeqNums;

public:

    static const KUINT16 MINEFIELD_RESPONSE_NACK_SIZE = 26; // Min size

    Minefield_Response_NACK_PDU( void );

    Minefield_Response_NACK_PDU( const EntityIdentifier & MinefieldID, const EntityIdentifier & RequestingSimulationID,
                                 KUINT8 ReqID );

    Minefield_Response_NACK_PDU( const EntityIdentifier & MinefieldID, const EntityIdentifier & RequestingSimulationID,
                                 KUINT8 ReqID, const vector<KUINT8> & MissingSeqNums );

    Minefield_Response_NACK_PDU( KDataStream & stream ) throw( KException );

    virtual ~Minefield_Response_NACK_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Minefield_Response_NACK_PDU::SetRequestingSimulationID
    //              KDIS::PDU::Minefield_Response_NACK_PDU::GetRequestingSimulationID
    // Description: Identifies the simulation that generated the query and is requesting
    //              retransmission of information from the minefield simulation.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetRequestingSimulationID( const EntityIdentifier & ID );
    const EntityIdentifier & GetRequestingSimulationID() const;
    EntityIdentifier & GetRequestingSimulationID();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Response_NACK_PDU::SetRequestID
    //              KDIS::PDU::Minefield_Response_NACK_PDU::GetRequestID
    // Description: Identifies the minefield query request.
    // Parameter:   KUINT8 ID
    //************************************
    void SetRequestID( KUINT8 ID );
    KUINT8 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Response_NACK_PDU::GetNumberMissingPDUs
    // Description: Identifies the number of PDUs that were not received by
    //              the requesting simulation in response to a minefield query request.
    //              This value is derived from the Minefield Data PDUs that were
    //              received in response to the minefield query request.
    //************************************
    KUINT8 GetNumberMissingPDUs() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Response_NACK_PDU::GetNumberMissingPDUs
    //              KDIS::PDU::Minefield_Response_NACK_PDU::SetMissingPDUSequenceNumbers
    //              KDIS::PDU::Minefield_Response_NACK_PDU::GetMissingPDUSequenceNumbers
    //              KDIS::PDU::Minefield_Response_NACK_PDU::ClearMissingPDUSequenceNumbers
    // Description: The sequence number(s) of the missing PDU(s).
    //              These values are derived from the Minefield Data PDUs that were
    //              received in response to the minefield query request.
    // Parameter:   KUINT8 N, const vector<KUINT8> & N
    //************************************
    void AddMissingPDUSequenceNumber( KUINT8 N );
    void SetMissingPDUSequenceNumbers( const vector<KUINT8> & N );
    const vector<KUINT8> & GetMissingPDUSequenceNumbers() const;
    void ClearMissingPDUSequenceNumbers();

    //************************************
    // FullName:    KDIS::PDU::Minefield_Response_NACK_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Minefield_Response_NACK_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Minefield_Response_NACK_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Minefield_Response_NACK_PDU & Value ) const;
    KBOOL operator != ( const Minefield_Response_NACK_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
