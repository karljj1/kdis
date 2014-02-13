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

