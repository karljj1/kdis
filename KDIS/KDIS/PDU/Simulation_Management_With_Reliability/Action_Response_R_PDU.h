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
    class:      Action_Response_R_PDU
    DIS:        (5) 1278.1 - 1995
    created:    28:03:2009
    author:     Karl Jones

    purpose:    Communicates a response to a Action Request PDU
    size:       320 bits/ 40 octets - not including variable param sizes
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Action_Response_PDU.h"
#include "./Action_Request_R_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::ENUMS::RequestStatus;

class KDIS_EXPORT Action_Response_R_PDU : public Action_Response_PDU
{
public:

    static const KUINT16 ACTION_RESPONSE_R_PDU_SIZE = 40;

    Action_Response_R_PDU( void );

    Action_Response_R_PDU( KDataStream & stream ) throw( KException );

    // Generate a response from a PDU.
    Action_Response_R_PDU( const Action_Request_R_PDU & pdu, RequestStatus RS );

    virtual ~Action_Response_R_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Action_Response_R_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    KBOOL operator == ( const Action_Response_R_PDU & Value ) const;
    KBOOL operator != ( const Action_Response_R_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS

