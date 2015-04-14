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

For a tutorial on sending the Entity State PDU see:
http://sourceforge.net/apps/mediawiki/kdis/index.php?title=Sending_a_Entity_State_PDU_Tutorial

This example shows the older method for sending a PDU, to see how the connection class can further help see the Environmental_Process_PDU example.
*********************************************************************/

#include <iostream>
#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.h"
#include "KDIS/Network/Connection.h" // A cross platform connection class.

// Lets declare all namespaces to keep the code small.
using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace PDU;
using namespace ENUMS;
using namespace UTILS;
using namespace NETWORK;

int main()
{
    // First create the PDU we are going to send, for this example I will use a
    // Entity_State_PDU, When this PDU is sent most DIS applications should then show a new entity
    EntityIdentifier EntID( 1, 3001, 3 );
    ForceID EntForceID( Friendly );
    EntityType EntType( 3, 1, 225, 3, 0, 1, 0 ); // A Civilian male
    Vector EntityLinearVelocity( 0, 0, 0 );

    // Convert local coordinate systems to DIS
    KFLOAT64 Lat = 40.664, Lon = -122.63, Alt = 615; // West coast of USA
    KFLOAT64 GeoX = 0.0, GeoY = 0.0, GeoZ = 0.0;
    KFLOAT64 Heading = 0.0, Pitch = 0.0, Roll = 0.0;
    KFLOAT64 Psi = 0.0, Theta = 0.0, Phi = 0.0;
    KDIS::UTILS::GeodeticToGeocentric( Lat, Lon, Alt, GeoX, GeoY, GeoZ, WGS_1984 );
    KDIS::UTILS::HeadingPitchRollToEuler( DegToRad( Heading ), DegToRad( Pitch ), DegToRad( Roll ), DegToRad( Lat ), DegToRad( Lon ), Psi, Theta, Phi );

    WorldCoordinates EntityLocation( GeoX, GeoY, GeoZ );
    EulerAngles EntityOrientation( Psi, Theta , Phi );
    EntityAppearance EntEA; 
    DeadReckoningParameter DRP( Static, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
    EntityMarking EntMarking( ASCII, "KARL", 4 );
    EntityCapabilities EntEC( false, false, false, false );

    // Create the PDU
    Entity_State_PDU Entity( EntID, EntForceID, EntType, EntType, EntityLinearVelocity, EntityLocation,
                             EntityOrientation, EntEA, DRP, EntMarking, EntEC );

    // Set the PDU Header values
    Entity.SetExerciseID( 1 );

    // Set the time stamp to automatically calculate each time encode is called.
    Entity.SetTimeStamp( TimeStamp( RelativeTime, 0, true ) );
	
    try
    {
        // Note: This address will probably be different for your network.
        Connection myConnection( "192.168.0.255" );

        // Encode the PDU contents into network data
        KDataStream stream;
        Entity.Encode( stream );

        while( true )
        {
            // Send the data on the network.
            myConnection.Send( stream.GetBufferPtr(), stream.GetBufferSize() );
            cout << "Sent the PDU" << endl;
        }
    }
    catch( exception & e )
    {
        cout << e.what() << endl;
    }

    return 0;
}

