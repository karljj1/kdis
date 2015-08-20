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

This example shows how you can add your custom data types to KDIS.
In this example we create our own version of a VariableDatum.

WARNING: If you create a derived data type you will also need to ensure that it is correctly padded. See the DIS standard for specifics.

For the accompanying tutorial:
https://sourceforge.net/apps/mediawiki/kdis/index.php?title=How_to_extend_the_KDIS_Data_Types_using_the_FactoryDecoder
*********************************************************************/

#include <iostream>
#include "KDIS/Extras/PDU_Factory.h"
#include "KDIS/DataTypes/VariableDatum.h"
#include "KDIS/PDU/Simulation_Management/Comment_PDU.h"

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace PDU;
using namespace UTILS;

//
// This is our custom class, it will be used to decode any data that has the DatumID '500123'
//
class MyCustomClass : public VariableDatum
{
private:

	// Lets use a 64 bit value for testing so we dont have to add any padding.
	KUINT64 m_ui64OurTestValue;

public:

	MyCustomClass( KUINT64 Val ) 	  
	{
		m_ui32DatumID = 500123; // Our custom DatumID.
		m_ui32DatumLength = 64; // The Datum length is the size in bits of our custom data
		m_ui64OurTestValue = Val;
	};

	MyCustomClass( KDataStream & stream )
	{
		Decode( stream );
	}

	virtual ~MyCustomClass()
	{
	};

    virtual KString GetAsString() const
	{
		KStringStream ss;

		ss << "This is our custom VariableDatum!!!! Our value is " << m_ui64OurTestValue << "\n";
		
		return ss.str();
	}

	// Our custom decode function.
    virtual void Decode( KDataStream & stream ) throw( KException )
	{
		// Deocode the standard variable datum fields
		stream >> m_ui32DatumID
               >> m_ui32DatumLength;

		// Now decode our 'extra' field.
		stream >> m_ui64OurTestValue; 
	}

    virtual void Encode( KDataStream & stream ) const
	{
		// Encode the standard variable datum fields
		stream << m_ui32DatumID
               << m_ui32DatumLength;

		// Now encode our 'extra' field.
		stream << m_ui64OurTestValue;
	}
};

// 
// Our decoder class
//
class MyDecoderClass : public FactoryDecoder<VariableDatum>
{
public:

	MyDecoderClass(){};

	~MyDecoderClass(){};

	// This is our factory decode function, we do the decoding for KDIS in here.
	virtual VariableDatum * FactoryDecode( KINT32 EnumVal, KDataStream & stream )
	{
		// This should allways return a new data type, however you can return NULL. We could use a single decoder class to support multiple custom data types....
		if( EnumVal == 500123 )
		{
			return new MyCustomClass( stream );
		}
		else return 0;
	}
};


int main()
{
	try
	{
		// 1
		// Register our factory decode function. 			
		VariableDatum::FacDecPtr decoder( new MyDecoderClass() ); 
		VariableDatum::RegisterFactoryDecoder( 500123, decoder );

		// 2
		// Create an instance of our data type.		
		MyCustomClass * pMyCustomDataClass = new MyCustomClass( 123321 );
		
		// 3
		// Now create a PDU that uses this data type and add it like normal.
		Comment_PDU ourPDU;
		ourPDU.AddVariableDatum( pMyCustomDataClass );

		// 4 
		// Encode the PDU.		
		KDataStream stream = ourPDU.Encode();
		
		// 5
		// Lets skip actually sending this data over the network in order to keep things simple..
		//

		// 6
		// Now decode the PDU as if we have just received it from the network.		
		PDU_Factory pduFact;
		auto_ptr<Header> pdu = pduFact.Decode( stream );
		
		if( pdu.get() )
		{
			// Here we should see that our variable datum has been correctly decoded.
			cout << pdu->GetAsString() << endl;

			// Lets get the decoded class
			Comment_PDU * ourRecPDU = ( Comment_PDU * )pdu.get();
			
			// Get the first and only item.
			VarDtmPtr pVd = ourRecPDU->GetVariableDatum()[0];

			// Now upcast so we get our data type.
			MyCustomClass * pMyClass = dynamic_cast<MyCustomClass*>( ( VariableDatum * )pVd );
			
			if( pMyClass )
			{
				cout << "Ta da!, we got the custom data class back out!" << endl;				
			}
		}
		else
		{
			cout << "Something went horribly wrong!" << endl;
		}
	}
	catch( exception & e )
	{
		cout  << e.what() << endl;
	}

	// 7
	// Now we should clean up memory. Our decoder will not be deleted unless we call ClearFactoryDecoders.
	VariableDatum::ClearFactoryDecoders();

    return 0;
}

