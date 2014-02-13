/**********************************************************************
The following UNLICENSE statement applies to this example.

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
*********************************************************************/

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

