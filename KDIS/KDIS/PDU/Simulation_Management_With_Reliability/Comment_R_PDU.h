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

/*********************************************************************
    class:      Comment_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    28:03:2009
    author:     Karl Jones

    purpose:    Arbitrary message (E.G char strings) shall be entered into the data
                stream by using a comment PDU. For use as comment, test message, error etc.
    size:       256 bits/ 32 octets - not including variable param sizes
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Comment_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Comment_R_PDU : public Comment_PDU
{
public:

    static const KUINT16 COMMENT_R_PDU_SIZE = 32; // Min size

    Comment_R_PDU( void );

    Comment_R_PDU( KDataStream & stream ) throw( KException );

    Comment_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID );

    virtual ~Comment_R_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Comment_R_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    KBOOL operator == ( const Comment_R_PDU & Value ) const;
    KBOOL operator != ( const Comment_R_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
