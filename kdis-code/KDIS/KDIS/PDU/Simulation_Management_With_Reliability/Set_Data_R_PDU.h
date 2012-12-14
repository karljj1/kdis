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
    class:      Set_Data_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    29:04:2009
    author:     Karl Jones

    purpose:    Sent when initializing or changing internal state information
    size:       356 bits/ 44 octets - not including variable param sizes
*********************************************************************/

#pragma once

#include "./Data_R_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService;

class KDIS_EXPORT Set_Data_R_PDU : public Data_R_PDU
{
public:

    static const KUINT16 SET_DATA_R_PDU_SIZE = 44;

    Set_Data_R_PDU( void );

    Set_Data_R_PDU( KDataStream & stream ) throw( KException );

    Set_Data_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                    KUINT32 RequestID, RequiredReliabilityService RRS );

    virtual ~Set_Data_R_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Set_Data_R_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Set_Data_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Set_Data_R_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Set_Data_R_PDU & Value ) const;
    KBOOL operator != ( const Set_Data_R_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS

