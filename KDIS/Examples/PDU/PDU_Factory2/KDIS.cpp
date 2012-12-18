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

