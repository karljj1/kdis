/*********************************************************************
For Further Information on KDIS:
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include <iostream>
#include <time.h>
#include "KDIS/Extras/DIS_Logger_Playback.h"
#include "KDIS/Network/Connection.h" // A cross platform connection class.

#define LOG_FILE "Log.txt"

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace PDU;
using namespace ENUMS;
using namespace UTILS;
using namespace NETWORK;

int main()
{
    // Note this address will probably be different for your network.
    Connection conn( "192.168.3.255" );

    KOCTET cBuffer[MAX_PDU_SIZE]; // Somewhere to store the data we receive.

    // Load all data into memory from the log.
    DIS_Logger_Playback Log( LOG_FILE, 0 );

    KUINT32 uiStartTime = time( NULL );
    KUINT32 ui32Timepassed;
    KBOOL bWaiting;

    try
    {
        while( Log.EndOfLogReached() == false )
        {
            ui32Timepassed = time( NULL ) - uiStartTime;

            // Get the next entry in the log
            KUINT32 ui32Stamp;
            KDataStream stream;
            Log.GetNext( ui32Stamp, stream );

            bWaiting = true;

            // Wait untill it is time to send the PDU
            while( bWaiting )
            {
                if( ui32Stamp <= ui32Timepassed )
                {
                    bWaiting = false;
                    stream.CopyIntoBuffer( cBuffer, MAX_PDU_SIZE );

                    conn.Send( cBuffer, stream.GetBufferSize() );

                    stream.Clear();
                }
                else
                {
                    ui32Timepassed = time( NULL ) - uiStartTime;
                }
            }
        }
    }
    catch( exception & e )
    {
        cout << e.what() << endl;
    }

    return 0;
}

