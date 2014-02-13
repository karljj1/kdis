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
This example is the same as PDU Factory example 1 however it uses some of the new features provided by the Connection class.
https://sourceforge.net/apps/mediawiki/kdis/index.php?title=PDU_Factory2
*********************************************************************/

#include <iostream>
#include "KDIS/Extras/PDU_Factory.h"
#include "KDIS/Network/Connection.h" // A cross platform connection class.
#include "KDIS/Network/ConnectionSubscriber.h"

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace PDU;
using namespace ENUMS;
using namespace UTILS;
using namespace NETWORK;

//
// This is our example subscriber class. It simply prints out the senders IP address and the contents of the PDU.
//
class ExampleSubscriber : public ConnectionSubscriber
{
public:

    ExampleSubscriber()
    {
    };

    ~ExampleSubscriber()
    {
    };

    // Our overloaded Data Received function
    virtual KBOOL OnDataReceived( const KOCTET * Data, KUINT32 DataLength, const KString & SenderIp )
    {
        cout << "Received " << DataLength << " bytes from " << SenderIp << endl;

        // We return true here, if we return false then the data will be discarded by the connection class.
        // This means an IP address based filter could be implemented here.
        return true;
    };

    // Our overloaded PDU Received function
    virtual void OnPDUReceived( const Header * H )
    {
        // Print out the contents of the PDU.
        cout << H->GetAsString();
        cout << "*****************************************************************\n\n" << endl;
    };
};

int main()
{
    try
    {
        // Note this multi cast address will probably be different for your network however
        // port 3000 is the assigned number by IANA(Internet Assigned Numbers Authority) for DIS simulations.
        Connection conn( "192.168.86.255" );

        // Lets apply a filter to the factory so it only lets through PDU that have an exercise ID of 1.
        conn.GetPDU_Factory()->AddFilter( new FactoryFilterExerciseID( 1 ) );

        // Add our subscriber
        conn.AddSubscriber( new ExampleSubscriber );

        while( true )
        {
            try
            {
				// Note: GetNextPDU supports PDU Bundling, which Receive does not.
                conn.GetNextPDU();
            }
            catch( exception & e )
            {
                // KDIS error, should be safe to carry on.
                cout << e.what() << endl;
            }
        }
    }
    catch( exception & e )
    {
        // Socket/Connection error, better stop.
        cout << e.what() << endl;
    }

    return 0;
}

