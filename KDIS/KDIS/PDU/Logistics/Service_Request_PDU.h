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
    class:      Service_Request_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Service Request PDU
    Size:       224 bits / 28 octets + ( 96 bits / 12 octets * ( number of supplies ) )
*********************************************************************/

#pragma once

#include "./Resupply_Received_PDU.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Service_Request_PDU : public Resupply_Received_PDU
{
protected:

    KUINT8 m_ui8ServiceTypeRequested;

public:

    // Min Size the PDU can be, size can be more depending on NumSupplyTypes field
    static const KUINT16 SERVICE_REQUEST_PDU_SIZE = 28; // Does not include supply size

    Service_Request_PDU();

    Service_Request_PDU( KDataStream & stream ) throw( KException );

	Service_Request_PDU( const Header & H, KDataStream & stream ) throw( KException );

	Service_Request_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntity, const KDIS::DATA_TYPE::EntityIdentifier & SupplyingEntity, 
		                 KDIS::DATA_TYPE::ENUMS::ServiceTypeRequested STR );

    virtual ~Service_Request_PDU();

    //************************************
    // FullName:    KDIS::PDU::Service_Request_PDU::SetServiceTypeRequested
    //              KDIS::PDU::Service_Request_PDU::GetServiceTypeRequested
    // Description: Describes type of service being requested
    // Parameter:   ServiceTypeRequested  STR, void
    //************************************
	void SetServiceTypeRequested( KDIS::DATA_TYPE::ENUMS::ServiceTypeRequested STR );
	KDIS::DATA_TYPE::ENUMS::ServiceTypeRequested GetServiceTypeRequested() const;

    //************************************
    // FullName:    KDIS::PDU::Service_Request_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Service_Request_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Service_Request_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Service_Request_PDU & Value ) const;
    KBOOL operator != ( const Service_Request_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
