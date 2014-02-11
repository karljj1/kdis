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
    class:      ConnectionSubscriber
    created:    19/10/2010
    author:     Karl Jones

    purpose:    This class allows you to handle PDU in an event based manner.
                It also allows for an IP address filter mechanisms to be created.
                Note: Any PDU filtering should be done in the PDU_Factory.

                An example of some of the uses of the ConnectionSubscriber could be:
                    Statistics
                    EntityManager
                    IpAddressFilter
                    Logging
*********************************************************************/

#pragma once

#include "./../PDU/Header.h"

namespace KDIS {
namespace NETWORK {

class KDIS_EXPORT ConnectionSubscriber
{
public:

    ConnectionSubscriber()
    {
    };

    virtual ~ConnectionSubscriber()
    {
    };

    //************************************
    // FullName:    KDIS::NETWORK::ConnectionSubscriber::OnDataReceived
    // Description: This function is first called when data is received on the connection,
    //              before any decoding has been performed.
    //              You should return true if you wish the connection to continue processing
    //              the data(i.e decode the PDU) or false if you want it to stop and discard the data.
    //              This means you can create a filter mechanism here for IP address.
    // Parameter:   const KOCTET * Data
    // Parameter:   KUINT32 DataLength
    // Parameter:   const KString & SenderIp
    //************************************
    virtual KBOOL OnDataReceived( const KOCTET * Data, KUINT32 DataLength, const KString & SenderIp )
    {
        return true;
    };

    //************************************
    // FullName:    KDIS::NETWORK::ConnectionSubscriber::OnPDUReceived
    // Description: Called after a PDU has been decoded (GetNextPDU). Use this function to handle various PDU,
    //              e.g a data logger or entity manager class.
    //              Note: This function is not for filtering, for PDU based filtering see the PDU_Factory.
    //              Note: By default this PDU will be deleted unless it is released(auto_ptr) by the function that calls GetNextPDU.
    // Parameter:   const KOCTET * Data
    //************************************
    virtual void OnPDUReceived( const KDIS::PDU::Header * H )
    {
    };

    //************************************
    // FullName:    KDIS::NETWORK::ConnectionSubscriber::OnPDUReceived
    // Description: Called before a PDU is transmitted over the network.
    //              Note: This function is not for filtering, for PDU based filtering see the PDU_Factory.
    // Parameter:   const KOCTET * Data
    //************************************
    virtual void OnPDUTransmit( KDIS::PDU::Header * H )
    {
    };
};

} // END namespace NETWORK
} // END namespace KDIS
