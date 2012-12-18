/*********************************************************************
For Further Information on KDIS:
http://p.sf.net/kdis/UserGuide

This example shows how to use the PDU bundling features in KDIS. 
If you are sending multiple PDU in a short time then bundling 
them into a single datagram can help reduce bandwidth and increase performance. 
Note: Not all systems support bundling.

Run the PDU_Factory2 example to see the output of this example, PDU_Factory1 does not support bundling.
*********************************************************************/

#include <iostream>
#include "KDIS/PDU/Bundle.h" // Our bundle class
#include "KDIS/Network/Connection.h"
#include "./EntityGenerator.h" // Generates random Entity State PDU's

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace PDU;
using namespace ENUMS;
using namespace UTILS;
using namespace NETWORK;

#define PDU_COUNT 10

int main()
{
	try
	{		
		// Note: This address will probably be different for your network.
        Connection myConnection( "192.168.3.255" );

		// We have 2 ways we can use the Bundle. 

		//
		// 1
		// We can give it PDU datastreams and it will concatenate them for us into a single packet.

		// Create the bundle. Just a collection of random ESPDUs.
		Bundle pduBundle;	
		for( int i = 0; i < PDU_COUNT; ++i )
		{
			pduBundle.AddPDU( EntityGenerator::GenerateEntity().Encode() );
		}

		// Now send the bundle
		myConnection.Send( pduBundle.Encode() );	
		cout << "1: Sent Bundle, Size: " << pduBundle.GetLength() << endl;

		//
		// 2
		// We can give it PDU pointers/references which will be encoded each time. 
		// We can then use this over time if we want to keep sending the PDU together.
		pduBundle.ClearPDUs();

	    for( int i = 0; i < PDU_COUNT; ++i )
		{
			pduBundle.AddPDU( EntityGenerator::GenerateEntityRef() );
		}

		// Now send the bundle
		myConnection.Send( pduBundle.Encode() );	

		cout << "2: Sent Bundle, Size: " << pduBundle.GetLength() << endl;
	}
	catch( exception & e )
	{
		cout << e.what() << endl;
	}

    return 0;
}

