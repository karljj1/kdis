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
    class:      Connection
    created:    27/09/2010
    author:     Karl Jones

    purpose:    This class provides an interface to a DIS socket connection.
                All sending and receiving of DIS PDU should be sent through this
                class unless you wish to use your own socket implementation.
*********************************************************************/

#pragma once

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  #pragma comment(lib, "WS2_32")
  #include <WinSock2.h>
#else
  #include <arpa/inet.h>
  #include <errno.h>
  #include <fcntl.h>
  #include <netdb.h>
  #include <netinet/in.h>
  #include <sys/socket.h>
  #include <sys/types.h>
#endif

#include <vector>

#include "KDIS/Extras/PDU_Factory.hpp"
#include "KDIS/Network/ConnectionSubscriber.hpp"

namespace KDIS {
namespace NETWORK {

class KDIS_EXPORT Connection {
 protected:
  KINT32 m_iSocket[2];  // 1 for sending & 1 for receiving.

  KUINT32 m_uiPort;

  timeval m_blockingTimeout;

  sockaddr_in m_SendToAddr;
  KString m_sSendAddress;

  sockaddr_in m_InterfaceAddr;  // struct for IPv4 address of NIC to be used for
                                // outbound DIS
  KString m_sInterfaceAddress;  // e.g. "192.168.1.124"

  KBOOL m_bBlockingSocket;

  KBOOL m_bSendOnly;
  KBOOL m_bReceiveOnly;

  std::vector<ConnectionSubscriber*> m_vpSubscribers;

  KDIS::UTILS::PDU_Factory* m_pPduFact;

  // Allows us to handle pdu bundles
  KDataStream m_stream;
  KString m_sLastIP;

  //************************************
  // FullName:    KDIS::NETWORK::Connection::startup
  // Description: Setup the socket.
  //************************************
  void startup();

  //************************************
  // FullName:    KDIS::NETWORK::Connection::bindSocket
  // Description: Bind the socket to receive data from all.
  //************************************
  void bindSocket();

  //************************************
  // FullName:    KDIS::NETWORK::Connection::shutdown
  // Description: Shutdown all socket features.
  //************************************
  void shutdown();

  //************************************
  // FullName:    KDIS::NETWORK::Connection::getErrorText
  // Description: Convert an internal socket error code into a text description.
  // Parameter:   KINT32 ErrorCode
  //************************************
  const char* getErrorText(KINT32 ErrorCode) const;

 public:
  // Note: If using multicast you should ensure you use a correct multicast
  // address or an exception will occur.
  Connection(const KString& SendAddress, KUINT32 Port = 3000,
             KBOOL SendAddressIsMulticast = false, KBOOL Blocking = true,
             KDIS::UTILS::PDU_Factory* Custom = 0, KBOOL SendOnly = false,
             KBOOL ReceiveOnly = false, const KString& InterfaceAddress = "");

  virtual ~Connection();

 private:
  //************************************
  // FullName:    KDIS::NETWORK::Connection::Connection copy constructor
  // Description: Copy constructor for the Connection class.
  // Parameter:   const Connection& other
  //************************************
  Connection(const Connection& other) = delete;

  //************************************
  // FullName:    KDIS::NETWORK::Connection::Connection copy assignment operator
  // Description: Copy assignment operator for the Connection class.
  // Parameter:   const Connection& other
  //************************************
  Connection& operator=(const Connection& other) = delete;

 public:
  //************************************
  // FullName:    KDIS::NETWORK::Connection::SetInterfaceAddress
  //              KDIS::NETWORK::Connection::GetInterfaceAddress
  // Description: The IPv4 address of the specific NIC to be used for DIS.
  //				Optional.  For multi-NIC systems.
  // Parameter:   const KString & A
  //************************************
  virtual void SetInterfaceAddress(const KString& A);
  virtual const KString& GetInterfaceAddress() const;

  //************************************
  // FullName:    KDIS::NETWORK::Connection::SetSendAddress
  //              KDIS::NETWORK::Connection::GetSendAddress
  // Description: The address data is being sent to, if multicast then
  //              AddMulticastAddress will also be called.
  // Parameter:   const KString & A
  // Parameter:   KBOOL Multicast = false
  //************************************
  virtual void SetSendAddress(const KString& A, KBOOL Multicast = false);
  virtual const KString& GetSendAddress() const;

  //************************************
  // FullName:    KDIS::NETWORK::Connection::AddMulticastAddress
  //              KDIS::NETWORK::Connection::RemoveMulticastAddress
  // Description: Allows you to receive data from a multicast group.
  //              Note: If you want to also send data to this address you should
  //              call SetSendAddress with the same multicast address.
  //              Note: You can add multiple groups.
  // Parameter:   const KString & A
  //************************************
  virtual void AddMulticastAddress(const KString& A);
  virtual void RemoveMulticastAddress(const KString& A);

  //************************************
  // FullName:    KDIS::NETWORK::Connection::SetBlockingModeEnabled
  // Description: Enabled/Disable blocking mode.
  //              If running in blocking mode calling Receive will not
  //              return until data has been received on the network.
  // Parameter:   KBOOL E
  //************************************
  virtual void SetBlockingModeEnabled(KBOOL E);
  virtual KBOOL IsBlockingModeEnabled() const;

  //************************************
  // FullName:    KDIS::NETWORK::Connection::SetBlockingTimeout
  // Description: Sets the timeout for blocking I/O.
  //              Note: This is useful for reporting when there has been no
  //              socket I/O for a long time. Where long time == 1 second or so.
  //              Make it short enough, and you make it non-blocking I/O.
  // Parameter:   KINT32 sec
  // Parameter:   KINT32 usec
  //************************************
  virtual void SetBlockingTimeOut(KINT32 sec, KINT32 usec);

  //************************************
  // FullName:    KDIS::NETWORK::Connection::AddSubscriber
  //              KDIS::NETWORK::Connection::RemoveSubscriber
  // Description: Add/Remove a connection subscriber.
  //              Connection subscribers are notified when data is received/sent
  //              on the connection. The subscribers can also be used to add a
  //              Ip address filter thus allowing certain IP addresses to be
  //              "blocked". Note: The subscriber's will not be deleted by this
  //              class so if you are using dynamic Subscriber's you will also
  //              need to delete them when necessary.
  // Parameter:   const ConnectionSubscriber * S
  //************************************
  virtual void AddSubscriber(ConnectionSubscriber* S);
  virtual void RemoveSubscriber(ConnectionSubscriber* S);

  //************************************
  // FullName:    KDIS::NETWORK::Connection::SetPDU_Factory
  //              KDIS::NETWORK::Connection::GetPDU_Factory
  // Description: Set/Get the PDU_Factory, by default the standard pdu factory
  // is used however you
  //              can create a customised version and assign it using the set
  //              function. Note: Calling set will automatically delete the old
  //              PDU_Fatcory.
  // Parameter:   PDU_Factory * P
  //************************************
  virtual void SetPDU_Factory(KDIS::UTILS::PDU_Factory* P);
  virtual KDIS::UTILS::PDU_Factory* GetPDU_Factory();

  //************************************
  // FullName:    KDIS::NETWORK::Connection::Send
  // Description: Send data over the network. Returns number of bytes sent.
  //              Note: This function does NOT fire subscriber events.
  // Parameter:   const KOCTET * Data, KDataStream & stream
  // Parameter:   KUINT32 DataSz
  //************************************
  virtual KINT32 Send(const KOCTET* Data, KUINT32 DataSz);
  virtual KINT32 Send(const KDataStream& stream);

  //************************************
  // FullName:    KDIS::NETWORK::Connection::SendPDU
  // Description: Sends a PDU over the network, fires the OnPDUTransmit event.
  //              Returns number of bytes sent.
  // Parameter:   Header * H
  //************************************
  virtual KINT32 SendPDU(KDIS::PDU::Header* H);

  //************************************
  // FullName:    KDIS::NETWORK::Connection::Receive
  // Description: Check for new data being sent to us. Returns size of data
  // received in octets/bytes.
  //              This function will block in blocking mode.
  //              If using non blocking 0 be returned if no data is available.
  //              Note: This function does NOT fire subscriber events.
  // Parameter:   KOCTET * Buffer
  // Parameter:   KUINT32 BufferSz
  // Parameter:   KString * SenderIp - Optional field. Pass a none null pointer
  // to get the senders IP address.
  //************************************
  virtual KINT32 Receive(KOCTET* Buffer, KUINT32 BufferSz,
                         KString* SenderIp = 0);

  //************************************
  // FullName:    KDIS::NETWORK::Connection::GetNextPDU
  // Description: Checks the network for new data using Receive if not curently
  // handling a pdu bundle,
  //              then decodes the data using the PDU factory and finally
  //              returns the decoded PDU. If the connection is none blocking
  //              then a NULL ptr will be returned if no data is available.
  //              Note: This function DOES fire subscriber events.
  //              Note: This function supports PDU Bundles.
  // Parameter:   KString * SenderIp - Optional field. Pass a none null pointer
  // to get the senders IP address.
  //************************************
  virtual std::unique_ptr<KDIS::PDU::Header> GetNextPDU(KString* SenderIp = 0);
};

}  // END namespace NETWORK
}  // END namespace KDIS
