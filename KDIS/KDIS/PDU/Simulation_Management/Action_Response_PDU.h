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
    class:      Action_Response_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/10/19
    author:     Karl Jones

    purpose:    Communicates a response to a Action Request PDU
    size:       320 bits/ 40 octets - not including variable param sizes
*********************************************************************/

#pragma once

#include "./Data_PDU.h"
#include "./Action_Request_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::ENUMS::RequestStatus;

class KDIS_EXPORT Action_Response_PDU : public Data_PDU
{
protected:

    KUINT32 m_ui32RequestStatus;

public:

    static const KUINT16 ACTION_RESPONSE_PDU_SIZE = 40;

    Action_Response_PDU( void );

    Action_Response_PDU( KDataStream & stream ) throw( KException );

    // Generate a response from a PDU.
    Action_Response_PDU( const Action_Request_PDU & pdu, RequestStatus RS );

    virtual ~Action_Response_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Action_Response_PDU::SetRequestStatus
    //              KDIS::PDU::Action_Response_PDU::GetRequestStatus
    // Description: Identifies the status of the request action
    // Parameter:   RequestStatus RS, void
    //************************************
    void SetRequestStatus( RequestStatus RS );
    RequestStatus GetRequestStatus() const;

    //************************************
    // FullName:    KDIS::PDU::Action_Response_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Action_Response_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Action_Response_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Action_Response_PDU & Value ) const;
    KBOOL operator != ( const Action_Response_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS

