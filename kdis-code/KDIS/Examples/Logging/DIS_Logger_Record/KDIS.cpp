/*********************************************************************
For Further Information on KDIS:
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include <iostream>
#include <time.h>
#include "KDIS/Extras/DIS_Logger_Record.h"
#include "KDIS/Network/Connection.h" // A cross platform connection class.

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;
using namespace NETWORK;

#define LOG_FILE "Log.txt"

int main()
{
    // Note this address will probably be different for your network.
    Connection conn( "192.168.3.255" );

    KOCTET cBuffer[MAX_PDU_SIZE]; // Somewhere to store the data we receive.

    // Create the DIS logger, we want to buffer the data so we are not constantly
    // performing I/O.
    DIS_Logger_Record DisLogger( LOG_FILE, false );
    KUINT32 ui32StartTime = time( NULL );

    try
    {
        while( true )
        {
            KINT32 i32Recv = 0;

            i32Recv = conn.Receive( cBuffer, MAX_PDU_SIZE );

            KDataStream s( cBuffer, i32Recv );

            // Record the PDU.
            KUINT32 ui32TimeStamp = time( NULL ) - ui32StartTime;
            DisLogger.Record( ui32TimeStamp, s );

            if( DisLogger.GetBufferSize() > MAX_PDU_SIZE )DisLogger.Save();
        }
    }
    catch( exception & e )
    {
        cout << e.what() << endl;
    }

    return 0;

}

