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
    class:      Data_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Sent in response to a data query or set data request.
    size:       320 bits/ 40 octets - not including variable param sizes
*********************************************************************/

#pragma once

#include "./Comment_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;

class KDIS_EXPORT Data_PDU : public Comment_PDU
{
protected:

    KUINT32 m_ui32RequestID;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 DATA_PDU_SIZE = 40;

    Data_PDU( void );

    Data_PDU( KDataStream & stream ) throw( KException );

    Data_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
              KUINT32 RequestID );

    virtual ~Data_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Data_PDU::SetRequestID
    //              KDIS::PDU::Data_PDU::GetRequestID
    // Description: Request ID, identifies the matching response
    //              to a Data Query PDU or Set Data PDU.
    // Parameter:   KUINT32 ID, void
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Data_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Data_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Data_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Data_PDU & Value ) const;
    KBOOL operator != ( const Data_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
