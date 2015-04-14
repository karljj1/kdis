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
#include "KDIS\PDU\Radio_Communications\Intercom_Control_PDU.h"
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
   
	
    try
    {
		Intercom_Control_PDU pduOut;

		cout << "Encode" << endl;
		KDataStream stream = pduOut.Encode();

		cout << "Decode" << endl;
		Intercom_Control_PDU pduIn( stream );

		cout << pduIn.GetAsString() << endl;
    }
    catch( exception & e )
    {
        cout << e.what() << endl;
    }

    return 0;
}

