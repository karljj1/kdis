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

#include <ostream>
#include <iostream>
#include "./Connection.h"

#if defined( WIN32 ) | defined( _WIN32 ) | defined( WIN64 ) | defined( _WIN64 ) // Windows Headers //

#include <ws2tcpip.h>

#define ERROR_CODE WSAGetLastError()

#else   // Linux Headers //

#include <sys/time.h>
#include <unistd.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define ERROR_CODE errno

#endif

#define THROW_ERROR throw KException( getErrorText( ERROR_CODE ), CONNECTION_SOCKET_ERROR )
#define SEND_SOCK 0
#define RECEIVE_SOCK 1

using namespace KDIS;
using namespace PDU;
using namespace UTILS;
using namespace NETWORK;
using namespace std;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

void Connection::startup() throw( KException )
{
    // Create the sockets if they do not already exist.
    if( !m_iSocket[SEND_SOCK] && !m_iSocket[RECEIVE_SOCK] )
    {
        // Windows only //
#if defined( WIN32 ) | defined( _WIN32 ) | defined( WIN64 ) | defined( _WIN64 )
        WSADATA w;
        static KINT32 iWinSockInit = WSAStartup( 0x0202, &w ); // Init with winsock version 2.2
        if( iWinSockInit != NO_ERROR )
        {
            THROW_ERROR;
        }
#endif

        // Create both sockets
        for( KINT8 i = 0; i < 2; ++i )
        {
            m_iSocket[i] = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP ); // Create a IPv4 UDP socket.

            if( m_iSocket[i] == INVALID_SOCKET )
            {
                THROW_ERROR;
            }
        }

        // Bind socket for incoming data.
        bindSocket();
    }
}

//////////////////////////////////////////////////////////////////////////

void Connection::bindSocket()
{
    // Set the receive socket to be reusable. Useful if your server has
    // been shut down, and then restarted right away.
    KINT32 yes = 1;
    KINT32 iRet = setsockopt( m_iSocket[RECEIVE_SOCK], SOL_SOCKET, SO_REUSEADDR, ( const char * )&yes, sizeof( yes ) );
    if( iRet == SOCKET_ERROR )
    {
        THROW_ERROR;
    }

    // Construct bind structure
    sockaddr_in Address;
    memset( &Address, 0, sizeof( Address ) );
    Address.sin_family = AF_INET;                   // Internet address family
    Address.sin_addr.s_addr = htonl( INADDR_ANY );  // Any incoming interface
    Address.sin_port = htons( m_uiPort );           // Listen Port

    // Now bind
    iRet = bind( m_iSocket[RECEIVE_SOCK], ( sockaddr* )&Address, sizeof( Address ) );
    if( iRet == SOCKET_ERROR )
    {
        THROW_ERROR;
    }
}

//////////////////////////////////////////////////////////////////////////

void Connection::shutdown() throw( KException )
{
    for( KINT8 i = 0; i < 2; ++i )
    {
        if( m_iSocket[i] )
        {
			#if defined( WIN32 ) | defined( _WIN32 ) | defined( WIN64 ) | defined( _WIN64 )
				KINT32 iError = closesocket( m_iSocket[i] );
			#else
				KINT32 iError = close( m_iSocket[i] );
			#endif

            if( iError == SOCKET_ERROR )
            {
                THROW_ERROR;
            }

            m_iSocket[i] = 0;
        }
    }
}

//////////////////////////////////////////////////////////////////////////

const KCHAR8 * Connection::getErrorText( KINT32 ErrorCode ) const
{
    switch ( ErrorCode )
    {
#if defined( WIN32 ) | defined( _WIN32 ) | defined( WIN64 ) | defined( _WIN64 )
        case /* 10004 */ WSAEINTR:
            return "WSAEINTR: Invalid interrupt number";
        case /* 10009 */ WSAEBADF:
            return "WSAEBADF: Invalid file number";
        case /* 10013 */ WSAEACCES:
            return "WSAEACCES";
        case /* 10014 */ WSAEFAULT:
            return "WSAEFAULT - The buf parameter is not completely contained in a valid part of the user address space.";
        case /* 10022 */ WSAEINVAL:
            return "WSAEINVAL, Invalid argument";
        case /* 10024 */ WSAEMFILE:
            return "WSAEMFILE, Is a File";
        case /* 10035 */ WSAEWOULDBLOCK:
            return "WSAEWOULDBLOCK: Function would block";
        case /* 10036 */ WSAEINPROGRESS:
            return "WSAEINPROGRESS: Winsock blocking function in progress";
        case /* 10037 */ WSAEALREADY:
            return "WSAEALREADY";
        case /* 10038 */ WSAENOTSOCK:
            return "WSAENOTSOCK";
        case /* 10039 */ WSAEDESTADDRREQ:
            return "WSAEDESTADDRREQ";
        case /* 10040 */ WSAEMSGSIZE:
            return "WSAEMSGSIZE";
        case /* 10041 */ WSAEPROTOTYPE:
            return "WSAEPROTOTYPE";
        case /* 10042 */ WSAENOPROTOOPT:
            return "WSAENOPROTOOPT";
        case /* 10043 */ WSAEPROTONOSUPPORT:
            return "WSAEPROTONOSUPPORT: Protocol not supported.";
        case /* 10044 */ WSAESOCKTNOSUPPORT:
            return "WSAESOCKTNOSUPPORT: Socket type not supported.";
        case /* 10045 */ WSAEOPNOTSUPP:
            return "Operation not supported.";
        case /* 10046 */ WSAEPFNOSUPPORT:
            return "WSAEPFNOSUPPORT: Protocol family not supported.";
        case /* 10047 */ WSAEAFNOSUPPORT:
            return "WSAEAFNOSUPPORT: Address family not supported by protocol family.";
        case /* 10048 */ WSAEADDRINUSE:
            return "WSAEADDRINUSE: Address is already in use";
        case /* 10049 */ WSAEADDRNOTAVAIL:
            return "WSAEADDRNOTAVAIL: Address is not available";
        case /* 10050 */ WSAENETDOWN:
            return "WSAENETDOWN: Network is down";
        case /* 10051 */ WSAENETUNREACH:
            return "WSAENETUNREACH: Network is unreachable";
        case /* 10052 */ WSAENETRESET:
            return "WSAENETRESET: Network has been reset";
        case /* 10053 */ WSAECONNABORTED:
            return "WSAECONNABORTED: Connection aborted";
        case /* 10054 */ WSAECONNRESET:
            return "WSAECONNRESET: Connection has been reset";
        case /* 10056 */ WSAEISCONN:
            return "WSAEISCONN: Socket Is Already Connected. ";
        case /* 10057 */ WSAENOTCONN:
            return "WSAENOTCONN: Socket not connected";
        case /* 10058 */ WSAESHUTDOWN:
            return "WSAESHUTDOWN: Socket has been shutdown";
        case /* 10059 */ WSAETOOMANYREFS:
            return "WSAETOOMANYREFS: Too many references";
        case /* 10060 */ WSAETIMEDOUT:
            return "WSAETIMEDOUT: Operation timed out";
        case /* 10061 */ WSAECONNREFUSED:
            return "WSAECONNREFUSED: Connection refused";
        case /* 10062 */ WSAELOOP:
            return "WSAELOOP";
        case /* 10063 */ WSAENAMETOOLONG:
            return "WSAENAMETOOLONG: Name too long";
        case /* 10064 */ WSAEHOSTDOWN:
            return "WSAEHOSTDOWN: Host is down";
        case /* 10065 */ WSAEHOSTUNREACH:
            return "WSAEHOSTUNREACH: Host is unreachable";
        case /* 10066 */ WSAENOTEMPTY:
            return "WSAENOTEMPTY";
        case /* 10067 */ WSAEPROCLIM:
            return "WSAEPROCLIM";
        case /* 10068 */ WSAEUSERS:
            return "WSAEUSERS";
        case /* 10069 */ WSAEDQUOT:
            return "WSAEUSERS";
        case /* 10070 */ WSAESTALE:
            return "WSAESTALE";
        case /* 10071 */ WSAEREMOTE:
            return "WSAEREMOTE";
        case /* 10091 */ WSASYSNOTREADY:
            return "WSASYSNOTREADY: System not ready"; // WSAStartup
        case /* 10092 */ WSAVERNOTSUPPORTED:
            return "WSAVERNOTSUPPORTED: Version not supported"; // WSAStartup
        case /* 10093 */ WSANOTINITIALISED:
            return "WSANOTINITIALISED: Winsock not initialised"; // WSAStartup not called
        case /* 10101 */ WSAEDISCON:
            return "WSAEDISCON: Remote party has disconnected";
        case /* 11001 */ WSAHOST_NOT_FOUND:
            return "Host not found";
        case /* 11002 */ WSATRY_AGAIN:
            return "WSATRY_AGAIN: Try again";
        case /* 11003 */ WSANO_RECOVERY:
            return "WSANO_RECOVERY: No recovery";
        case /* 11004 */ WSANO_DATA:
            return "WSANO_DATA: No data";
#else
        case /* 00001 */ EPERM:
            return "EPERM: Operation not permitted";
        case /* 00002 */ ENOENT:
            return "ENOENT: No such file or directory";
        case /* 00003 */ ESRCH:
            return "ESRCH: No such process";
        case /* 00004 */ EINTR:
            return "EINTR: Interrupted system call";
        case /* 00005 */ EIO:
            return "EIO: I/O error";
        case /* 00006 */ ENXIO:
            return "ENXIO: No such device or address";
        case /* 00007 */ E2BIG:
            return "E2BIG: Argument list too long";
        case /* 00008 */ ENOEXEC:
            return "ENOEXEC: Exec format error";
        case /* 00009 */ EBADF:
            return "EBADF: Bad file number";
        case /* 00010 */ ECHILD:
            return "ECHILD: No child processes";
        case /* 00011 */ EAGAIN:
            return "EAGAIN: Try again";
        case /* 00012 */ ENOMEM:
            return "ENOMEM: Out of memory";
        case /* 00013 */ EACCES:
            return "EACCES: Permission denied";
        case /* 00014 */ EFAULT:
            return "EFAULT: Bad address";
        case /* 00015 */ ENOTBLK:
            return "ENOTBLK: Block device required";
        case /* 00016 */ EBUSY:
            return "EBUSY: Device or resource busy";
        case /* 00017 */ EEXIST:
            return "EEXIST: File exists";
        case /* 00018 */ EXDEV:
            return "EXDEV: Cross-device link";
        case /* 00019 */ ENODEV:
            return "ENODEV: No such device";
        case /* 00020 */ ENOTDIR:
            return "ENOTDIR: Not a directory";
        case /* 00021 */ EISDIR:
            return "EISDIR: Is a directory";
        case /* 00022 */ EINVAL:
            return "Invalid argument";
        case /* 00023 */ ENFILE:
            return "ENFILE: File table overflow";
        case /* 00024 */ EMFILE:
            return "EMFILE: Too many open files";
        case /* 00025 */ ENOTTY:
            return "ENOTTY: Not a typewriter";
        case /* 00026 */ ETXTBSY:
            return "ETXTBSY: Text file busy";
        case /* 00027 */ EFBIG:
            return "EFBIG: File too large";
        case /* 00028 */ ENOSPC:
            return "ENOSPC: No space left on device";
        case /* 00029 */ ESPIPE:
            return "ESPIPE: Illegal seek";
        case /* 00030 */ EROFS:
            return "EROFS: Read-only file system";
        case /* 00031 */ EMLINK:
            return "EMLINK: Too many links";
        case /* 00032 */ EPIPE:
            return "EPIPE: Broken pipe";
        case /* 00033 */ EDOM:
            return "EDOM: Math argument out of domain of func";
        case /* 00034 */ ERANGE:
            return "ERANGE: Math result not representable";
#endif

        default:
            return "Unknown Socket Error";
    }
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Connection::Connection( const KString & SendAddress, KUINT32 Port /* = 3000 */, KBOOL SendAddressIsMulticast /* = false */,
                        KBOOL Blocking /* = true */, PDU_Factory * Custom /* = 0 */ ) :
    m_uiPort( Port ),
    m_bBlockingSocket( Blocking )
{
    m_iSocket[SEND_SOCK] = 0;
    m_iSocket[RECEIVE_SOCK] = 0;
	
	m_blockingTimeout.tv_sec = 0;
	m_blockingTimeout.tv_usec = 0;

    startup();

    SetSendAddress( SendAddress, SendAddressIsMulticast );

    SetBlockingModeEnabled( Blocking );

    // Should we use the standard PDU_Factory or have we been supplied we a customised one?
    if( Custom )
    {
        m_pPduFact = Custom;
    }
    else
    {
        m_pPduFact = new PDU_Factory;
    }
}

//////////////////////////////////////////////////////////////////////////

Connection::~Connection()
{
    shutdown();
	delete m_pPduFact;	
}

//////////////////////////////////////////////////////////////////////////

void Connection::SetSendAddress( const KString & A, KBOOL Multicast /*= false */ ) throw( KException )
{
    m_sSendAddress = A;

    // Create the send to address structure
    memset( &m_SendToAddr, 0, sizeof( m_SendToAddr ) );
    m_SendToAddr.sin_family = AF_INET;
    m_SendToAddr.sin_addr.s_addr = inet_addr( m_sSendAddress.c_str() );
    m_SendToAddr.sin_port = htons( m_uiPort );

    if( Multicast )
    {
        AddMulticastAddress( A );

        // TODO: Do we need to disable broadcasting on the socket if we switch to multicast?
    }
    else
    {
        // Enable broadcasting on the send socket
        KINT32 yes = 1;
        KINT32 iRet = setsockopt( m_iSocket[SEND_SOCK], SOL_SOCKET, SO_BROADCAST, ( const char * )&yes, sizeof( yes ) );
        if( iRet == SOCKET_ERROR )
        {
            THROW_ERROR;
        }
    }
}

//////////////////////////////////////////////////////////////////////////

const KString & Connection::GetSendAddress() const
{
    return m_sSendAddress;
}

//////////////////////////////////////////////////////////////////////////

void Connection::AddMulticastAddress( const KString & A ) throw( KException )
{
    // Attempt to join the group
    ip_mreq mc;
    mc.imr_multiaddr.s_addr = inet_addr( m_sSendAddress.c_str() );
    mc.imr_interface.s_addr = htonl( INADDR_ANY );
    KINT32 iRet = setsockopt( m_iSocket[RECEIVE_SOCK], IPPROTO_IP, IP_ADD_MEMBERSHIP, ( KOCTET* )&mc, sizeof( mc ) );
    if( iRet == SOCKET_ERROR )
    {
        THROW_ERROR;
    }
}

//////////////////////////////////////////////////////////////////////////

void Connection::RemoveMulticastAddress( const KString & A ) throw( KException )
{
    // Attempt to drop the address.
    ip_mreq mc;
    mc.imr_multiaddr.s_addr = inet_addr( m_sSendAddress.c_str() );
    mc.imr_interface.s_addr = htonl( INADDR_ANY );
    KINT32 iRet = setsockopt( m_iSocket[RECEIVE_SOCK], IPPROTO_IP, IP_DROP_MEMBERSHIP, ( KOCTET* )&mc, sizeof( mc ) );
    if( iRet == SOCKET_ERROR )
    {
        THROW_ERROR;
    }
}

//////////////////////////////////////////////////////////////////////////

void Connection::SetBlockingModeEnabled( KBOOL E )
{
    m_bBlockingSocket = E;

    for( KINT8 i = 0; i < 2; ++i )
    {
        KINT32 iResult;

#if defined( WIN32 ) | defined( _WIN32 ) | defined( WIN64 ) | defined( _WIN64 )

        // Windows non blocking //
        unsigned long int uliIoctBlock = !m_bBlockingSocket;           // 1 enable, 0 disable.
        iResult = ioctlsocket( m_iSocket[i], FIONBIO, &uliIoctBlock ); // FIONBIO =  blocking mode

#else

        // Linux non blocking //
        KINT32 uliIoctBlock = !m_bBlockingSocket; // 1 enable, 0 disable.
        iResult = fcntl( m_iSocket[i], F_SETFL, O_NONBLOCK | FASYNC, &uliIoctBlock );

#endif

        if( iResult == SOCKET_ERROR )
        {
            THROW_ERROR;
        }
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Connection::IsBlockingModeEnabled() const
{
    return m_bBlockingSocket;
}

//////////////////////////////////////////////////////////////////////////
 
void Connection::SetBlockingTimeOut( KINT32 sec, KINT32 usec )
{
    m_blockingTimeout.tv_sec = sec;
    m_blockingTimeout.tv_usec = usec;
}

//////////////////////////////////////////////////////////////////////////

void Connection::AddSubscriber( ConnectionSubscriber * S )
{
    if( S )
    {
        m_vpSubscribers.push_back( S );
    }
}

//////////////////////////////////////////////////////////////////////////

void Connection::RemoveSubscriber( ConnectionSubscriber * S )
{
    if( S )
    {
        // Perform a linear search for the subscriber.
        vector<ConnectionSubscriber*>::iterator itr = m_vpSubscribers.begin();
        vector<ConnectionSubscriber*>::iterator itrEnd = m_vpSubscribers.end();
        for( ; itr != itrEnd; ++itr )
        {
            if( *itr == S )
            {
                // Remove the subsriber
                itr = m_vpSubscribers.erase( itr );
                itrEnd = m_vpSubscribers.end();

                // Now continue searching, the subscriber may have been added twice...
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////

void Connection::SetPDU_Factory( PDU_Factory * P )
{
    if( P )
    {
        if( m_pPduFact )delete m_pPduFact;
        m_pPduFact = P;
    }
}

//////////////////////////////////////////////////////////////////////////

PDU_Factory * Connection::GetPDU_Factory()
{
    return m_pPduFact;
}

//////////////////////////////////////////////////////////////////////////

KINT32 Connection::Send( const KOCTET * Data, KUINT32 DataSz ) throw ( KException )
{
    KINT32 iBytesSent =  sendto( m_iSocket[SEND_SOCK], Data, DataSz, 0, ( sockaddr * )&m_SendToAddr, sizeof( m_SendToAddr ) );

    if( iBytesSent == SOCKET_ERROR )
    {
        THROW_ERROR;
    }
	
	return iBytesSent;
}

//////////////////////////////////////////////////////////////////////////

KINT32 Connection::Send( const KDataStream & stream ) throw ( KException )
{
	return Send( stream.GetBufferPtr(), stream.GetBufferSize() );
}

//////////////////////////////////////////////////////////////////////////

KINT32 Connection::SendPDU( Header * H ) throw ( KException )
{
    // First lets fire the events, then send the PDU.
    vector<ConnectionSubscriber*>::iterator itr = m_vpSubscribers.begin();
    vector<ConnectionSubscriber*>::iterator itrEnd = m_vpSubscribers.end();
    for( ; itr != itrEnd; ++itr )
    {
        ( *itr )->OnPDUTransmit( H );
    }

    // Now send the PDU
    KDataStream stream;
    H->Encode( stream );
    return Send( stream.GetBufferPtr(), stream.GetBufferSize() );
}

//////////////////////////////////////////////////////////////////////////

KINT32 Connection::Receive( KOCTET * Buffer, KUINT32 BufferSz, KString * SenderIp /*= NULL*/ ) throw ( KException )
{
    // We use fd_set to test the receive socket for readability. This is used in both blocking
    // and none blocking mode however it is primarily here for none blocking mode as it is more
    // efficient to use this method than to continuously poll the socket.
    fd_set fd;
    FD_ZERO( &fd );
    FD_SET( m_iSocket[RECEIVE_SOCK], &fd );
    timeval pTimeout;

    if( !m_bBlockingSocket )
    {
        // If we are using none blocking mode we need to set
        // a time limit to wait for the select function.
        timeval tval;
        tval.tv_sec  = 0;
        tval.tv_usec = 1;
        pTimeout = tval;
    }
    else
    {
        // Even in blocking mode, it can be useful to return
        // occasionally after a long period without data.
        // where (long period == a second or so).
        // This can make clean exits a joy and allow status messages
        // from the same thread
        pTimeout = m_blockingTimeout;
	}
	
    // Check the socket, do we have data waiting?
    KINT32 uiErr = select( m_iSocket[RECEIVE_SOCK] + 1, &fd, 0, 0, &pTimeout );

    if( uiErr == SOCKET_ERROR )
    {
        THROW_ERROR;
    }

    if( uiErr ) // If none zero we have data waiting
    {
        // Get data from socket
        sockaddr_in ClientAddr;
        socklen_t iSz = sizeof( ClientAddr );
        uiErr = recvfrom( m_iSocket[RECEIVE_SOCK], Buffer, BufferSz, 0, ( sockaddr * )&ClientAddr, &iSz );

        if( uiErr == SOCKET_ERROR )
        {
            THROW_ERROR;
        }

        // Do we need the sending IP address?
        if( SenderIp )
        {
            *SenderIp = inet_ntoa( ClientAddr.sin_addr );
        }
    }

    return uiErr;
}

//////////////////////////////////////////////////////////////////////////

auto_ptr<Header> Connection::GetNextPDU( KString * SenderIp /* = 0 */ ) throw ( KException )
{  
	// Are we currently dealing with a PDU Bundle, if so then dont read any new data.
	if( m_stream.GetBufferSize() == 0 )
	{	
		// Get some new data from the network
		// Create a buffer to store network data
		KOCTET Buffer[MAX_PDU_SIZE];
		KINT32 iSz = Receive( Buffer, MAX_PDU_SIZE, &m_sLastIP );

		if( iSz )
		{
			// Fire the first event, this event can also be used to inform us if we should stop
			vector<ConnectionSubscriber*>::iterator itr = m_vpSubscribers.begin();
			vector<ConnectionSubscriber*>::iterator itrEnd = m_vpSubscribers.end();
			for( ; itr != itrEnd; ++itr )
			{
				if( !( *itr )->OnDataReceived( Buffer, iSz, m_sLastIP ) )
				{
					// We should quit
					return auto_ptr<Header>( 0 );
				}
			}
		
			// Create a new data stream
			m_stream.Clear();
			m_stream.CopyFromBuffer( Buffer, iSz );
		}
	}
	
	// Now process the stream
	if( m_stream.GetBufferSize() > 0 )
	{
		// Do they want the IP address returned?
		if( SenderIp )
		{
			*SenderIp = m_sLastIP;
	    }

		// Get the current write position
		KUINT16 currentPos = m_stream.GetCurrentWritePosition();

		try
		{
			// Get the next/only PDU from the stream
			auto_ptr<Header> pdu = m_pPduFact->Decode( m_stream );

			// If the PDU was decoded successfully then fire the next event
			if( pdu.get() )
			{ 
				vector<ConnectionSubscriber*>::iterator itr = m_vpSubscribers.begin();
				vector<ConnectionSubscriber*>::iterator itrEnd = m_vpSubscribers.end();
				for( ; itr != itrEnd; ++itr )
				{
					( *itr )->OnPDUReceived( pdu.get() );
				}

				// Set the write pos for the next pdu.
				m_stream.SetCurrentWritePosition( currentPos + pdu->GetPDULength() );

				// Now return the decoded pdu
				return pdu;
			}
		}
		catch( const exception & e )
		{
			// Something went wrong, the stream is likely corrupted now so wipe it or we will have issues in the next GetNextPDU call.
			m_stream.Clear();
			throw;
		}
	}
	
	return auto_ptr<Header>( 0 ); // No data so Null ptr     
}

//////////////////////////////////////////////////////////////////////////

