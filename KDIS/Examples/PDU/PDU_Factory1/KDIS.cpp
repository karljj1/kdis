/*********************************************************************
For Further Information on KDIS:
http://p.sf.net/kdis/UserGuide
A guide to this example can be found at:
http://sourceforge.net/apps/mediawiki/kdis/index.php?title=PDU_Factory_Tutorial

NOTE: This method does not support PDU bundling, please see PDU_Factory2 
to see how to use GetNextPDU which does support bundling. 
*********************************************************************/

#include <iostream>
#include "KDIS/Extras/PDU_Factory.h"
#include "KDIS/Network/Connection.h" // A cross platform connection class.

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace PDU;
using namespace ENUMS;
using namespace UTILS;
using namespace NETWORK;

int main()
{
    PDU_Factory Factory;

    // Lets apply a filter to the factory so it only lets through PDU that have an exercise ID of 1.
    //Factory.AddFilter( new FactoryFilterExerciseID( 1 ) );

    // Note this multi cast address will probably be different for your network however
    // port 3000 is the assigned number by IANA(Internet Assigned Numbers Authority) for DIS simulations.
    Connection conn( "192.168.3.255" );

    KOCTET cBuffer[MAX_PDU_SIZE]; // Somewhere to store the data we receive.

    try
    {
        while( true )
        {
            KUINT32 ui32Recv = conn.Receive( cBuffer, MAX_PDU_SIZE );

            try
            {
                // Did we receive any data?
                // Note: A none blocking socket will return 0 if no data is waiting.
                if( ui32Recv )
                {
                    auto_ptr<Header> pHeader = Factory.Decode( cBuffer, ui32Recv );

                    // Print out the contents of the PDU.
                    if( pHeader.get() )
                    {
                        cout << "\n" << pHeader->GetAsString();
                        cout << "*****************************************************************\n\n" << endl;
                    }
                    else cout << "PDU Ignored/Unsupported." << endl;
                }
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
        // Socket error, better stop.
        cout << e.what() << endl;
    }

    return 0;
}

