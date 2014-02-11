/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    class:      Bundle
	DIS:        1278.2 - draft
    created:    14/12/2012
    author:     Karl Jones

    purpose:    Bundling is defined as the process of concatenating two or more PDUs 
				into a single network datagram so that they can be transmitted and relayed 
				through the network in one operation. The increase in network efficiency by 
				the use of bundling works best when there are many PDUs ready to be transmitted 
				at the same time. Simulations may choose to delay transmission of a PDU for a
				short amount of time to allow more PDUs to become ready to add to the bundle. 
				However, this increases latency, which is undesirable. The latency increase should be
				weighed against network performance gains in determining the bundling delay.
				Bundling is also useful when two or more PDUs have to be delivered in order as a single
				coherent unit. Network layers do not split datagrams so bundled PDUs will arrive 
				at the receiver in their original concatenated format.

				This class allows you to package multiple PDU up for sending, it is not used for receiving data.				

*********************************************************************/

#pragma once

#include "./Header.h"
#include "./../Extras/KRef_Ptr.h"
#include <vector>

namespace KDIS {
namespace PDU {

/************************************************************************/
// Define the type of pointer we are using for PDU,
// do we want a weak reference or a ref counter?
// By default we use a ref counted pointer, however if you want to use a standard
// pointer or one of your own then simply change it below.
/************************************************************************/
typedef KDIS::UTILS::KRef_Ptr<Header> PduPtr; // Ref counter
//typedef Header * PduPtr; // Weak ref

class KDIS_EXPORT Bundle
{
protected:

	std::vector<KDataStream> m_vStreams;

	std::vector<PduPtr> m_vRefHeaders;

	KUINT16 m_ui16Length;

    //************************************
    // FullName:    KDIS::PDU::Bundle::AddPDU
    // Description: Calculate the total length of the Bundle.    
    //************************************
	void calculateLength();

public:

    Bundle();

    virtual ~Bundle();
	
    //************************************
    // FullName:    KDIS::PDU::Bundle::AddPDU
    // Description: Adds a PDU stream or referenced PDU to the bundle.	
	//              Throws exeption PDU_TOO_LARGE if the total bundles length is greater than MAX_PDU_SIZE
    // Parameter:   const Header & H, PduPtr H.
    //************************************
	void AddPDU( const KDataStream & K ) throw( KException );
	void AddPDU( PduPtr H ) throw( KException );

	//************************************
    // FullName:    KDIS::PDU::Bundle::SetPDUs
    // Description: Set multiple PDU. 
	//              Throws exeption PDU_TOO_LARGE if the total bundles length is greater than MAX_PDU_SIZE
    // Parameter:   const vector<KDataStream> & P, const vector<PduPtr> & P
    //************************************
    void SetPDUs( const std::vector<KDataStream> & P ) throw( KException );
	void SetPDUs( const std::vector<PduPtr> & P ) throw( KException );
	void SetPDUs( const std::vector<KDataStream> & Streams, const std::vector<PduPtr> & References ) throw( KException );

	//************************************
    // FullName:    KDIS::PDU::Bundle::GetPDUStreams
	//				KDIS::PDU::Bundle::GetRefPDUs
    // Description: Gets the stored PDU stremas or referenced PDUs.  
    //************************************
	const std::vector<KDataStream> & GetPDUStreams() const;
	const std::vector<PduPtr> & GetRefPDUs() const;

	//************************************
    // FullName:    KDIS::PDU::Bundle::ClearPDUs	
    // Description: Clears stored PDUs.  
    //************************************
    void ClearPDUs();

	//************************************
    // FullName:    KDIS::PDU::Bundle::ClearPDUs	
    // Description: Returns total length of all PDU in bytes.
    //************************************
	KUINT16 GetLength();

    //************************************
    // FullName:    KDIS::PDU::Bundle::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString();

    //************************************
    // FullName:    KDIS::PDU::Bundle::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Bundle & Value ) const;
    KBOOL operator != ( const Bundle & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS

