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

using KDIS::PDU::Header;

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
    virtual void OnPDUReceived( const Header * H )
    {
    };

    //************************************
    // FullName:    KDIS::NETWORK::ConnectionSubscriber::OnPDUReceived
    // Description: Called before a PDU is transmitted over the network.
    //              Note: This function is not for filtering, for PDU based filtering see the PDU_Factory.
    // Parameter:   const KOCTET * Data
    //************************************
    virtual void OnPDUTransmit( Header * H )
    {
    };
};

}; // End namespace NETWORK
}; // End namespace KDIS
