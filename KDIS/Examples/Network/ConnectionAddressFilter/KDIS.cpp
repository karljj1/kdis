/*********************************************************************
For Further Information on KDIS:
http://p.sf.net/kdis/UserGuide

This example is based on PDU_Factory2 example however it shows how the 
ConnectionAddressFilter can be used to block/allow particular IP addresses.
If you want to test this you will need an other machine generating DIS to see the filter in action.
*********************************************************************/

#include <iostream>
#include "KDIS/Extras/PDU_Factory.h"
#include "KDIS/Network/Connection.h" 
#include "KDIS/Network/ConnectionAddressFilter.h"

using namespace std;
using namespace KDIS;
using namespace NETWORK;

int main()
{
    try
    {
        // Note this multi cast address will probably be different for your network however
        // port 3000 is the assigned number by IANA(Internet Assigned Numbers Authority) for DIS simulations.
        Connection conn( "192.168.3.255" );
		
		// Create the filter and set it up so it only allows our test machine through.
		ConnectionAddressFilter filter( ConnectionAddressFilter::AllowAddressesInFilterList ); // Only allow address we add through.
		//ConnectionAddressFilter filter( ConnectionAddressFilter::BlockAddressesInFilterList ); // Block the address we add and allow all others through.

		filter.AddAddress( "192.168.3.241" ); // This should be the address of your other DIS machine
		//filter.AddAddress( "192.168.3.124" ); // Add an other machine?

        // Add our filter
        conn.AddSubscriber( &filter );

        while( true )
        {
            try
            {
				auto_ptr<Header> pHeader = conn.GetNextPDU();
                if( pHeader.get() )
				{
					cout << pHeader->GetAsString() << endl;	
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
        // Socket/Connection error, better stop.
        cout << e.what() << endl;
    }

    return 0;
}

