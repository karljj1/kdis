/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    class:      FactoryDecoder
    created:    15/03/2011
    author:     Karl Jones

    purpose:    This is an Abstract class that can be used to create your own custom decoders for some of the more extendable data types.
	            For example the VariableDatum can support many different variations including your own custom ones, using a FactoryDecoder 
				you can add your custom classes into KDIS.				
				
				If you want KDIS to decode your custom classes simply call the RegisterFactoryDecoder function of the relevant class.
	
				Example:				
				
				// You could create a seperate decoder class just for the decoding task, here I use multiple inheritance...
                class MyCustomVariableDatumClass : public variableDatum, public FactoryDecoder<VariableDatum, 
				{
					...
					variableDatum * FactoryDecode( int TypeEnum, KDataStream & stream )
					{
						// Do you custom decoding in here.
					}
					...
				}


				// Now when your application starts up register you new FactoryDecoderClass like so:

				// 123 could be your type enum value.
				VariableDatum::RegisterFactoryDecoder( 123, new MyCustomVariableDatumClass );

				// Now when ever a VariableDatum with type 123 is received it will be decoded with your custom class.	

				// When you no longer need the custom decoders you should call 'ClearFactoryDecoders', which can also free up the memory for you.
	
*********************************************************************/

#pragma once

#include "./../KDataStream.h"
#include <map>

namespace KDIS {
namespace DATA_TYPE {

using std::map;

template<class DecoderBaseTyp>
class FactoryDecoder 
{
public:
	
	FactoryDecoder( void ){};

	virtual ~FactoryDecoder( void ){};

    //************************************
    // FullName:    KDIS::DATA_TYPE::FactoryDecoder::FactoryDecode
    // Description: This is where you decode the stream into your custom class, 
	//              the enum value is also passed back so you can perform decoding 
	//              of multiple types within a single FactoryDecoder.
    // Parameter:   KINT32 EnumVal
	// Parameter:   KDataStream & stream
    //************************************
	virtual DecoderBaseTyp * FactoryDecode( KINT32 EnumVal, KDataStream & stream ) = 0;
};

/********************************************************************
    class:      FactoryDecoderUser
    created:    17/03/2011
    author:     Karl Jones

    purpose:    This class adds support for custom decoding.        				
*********************************************************************/

template<class DecoderBaseTyp>
class FactoryDecoderUser
{
protected:

	static map<KINT32, FactoryDecoder<DecoderBaseTyp>* > m_mDecoders;

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::FactoryDecoderUser::RegisterFactoryDecoder    
    // Description: Registers a decoder for a custom class.
	//              EnumVal is the relevant enum value representing the new class.
	//              E.G DatumID enum for VariableDatum.
	//              Exception thrown if a decoder already exists for this enum.
    // Parameter:   KINT32 EnumVal
	// Parameter:   FactoryDecoder<DecoderBaseTyp> * Decoder
    //************************************
	static void RegisterFactoryDecoder( KINT32 EnumVal, FactoryDecoder<DecoderBaseTyp> * Decoder ) throw( KException )
	{
		if( m_mDecoders.find( EnumVal ) != m_mDecoders.end() )
		{
			KStringStream ss;
			ss << "A decoder already exists for this enum: " << EnumVal;
			throw KException( __FUNCTION__, INVALID_OPERATION, ss.str() );
		}

		// Register the new decoder.
		m_mDecoders[EnumVal] = Decoder;
	}

    //************************************
    // FullName:    KDIS::DATA_TYPE::FactoryDecoderUser::FactoryDecode
    // Description: Attempts to find a decoder for the enum, returns NULL if none are found. 
	//              Note: An exception may be thrown by a decoder.
    // Parameter:   KINT32 EnumVal
	// Parameter:   KDataStream & stream
    //************************************
	static DecoderBaseTyp * FactoryDecode( KINT32 EnumVal, KDataStream & stream ) throw( KException )
	{
		// Try to find a decoder
		typename map<KINT32, FactoryDecoder<DecoderBaseTyp>* >::iterator itr = m_mDecoders.find( EnumVal );
		if( itr != m_mDecoders.end() )
		{
			return itr->second->FactoryDecode( EnumVal, stream );
		}
		
		// No decoders found so return NULL.
		return 0;
	}

    //************************************
    // FullName:    KDIS::DATA_TYPE::FactoryDecoderUser::FactoryDecode
    // Description: Removes all factory decoders. If AutoDelete is set they 
	//              will be deleted in the process.
    // Parameter:   bool AutoDelete = true 
    //************************************
	static void ClearFactoryDecoders( bool AutoDelete = true )
	{
		if( AutoDelete )
		{
			typename map<KINT32, FactoryDecoder<DecoderBaseTyp>* >::iterator itr = m_mDecoders.begin();
			typename map<KINT32, FactoryDecoder<DecoderBaseTyp>* >::iterator itrEnd = m_mDecoders.end();
			for( ; itr != itrEnd; ++itr )
			{
				delete itr->second;
			}
		}

		m_mDecoders.clear();
	}
};

// Init static map variable.
template<class DecoderBaseTyp>
map<KINT32, FactoryDecoder<DecoderBaseTyp>* > FactoryDecoderUser<DecoderBaseTyp>::m_mDecoders = map<KINT32, FactoryDecoder<DecoderBaseTyp>* >();

}; // END namespace DATA_TYPES
}; // END namespace KDIS

