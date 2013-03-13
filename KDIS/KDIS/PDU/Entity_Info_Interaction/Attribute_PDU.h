/*********************************************************************

Copyright 2013 KDIS
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
    class:      Attribute_PDU
    DIS:        (7) 1278.1-2012
    created:    27/01/2011
    author:     Karl Jones

    purpose:    Information about individual attributes for a particular entity,
                other object, or event may be communicated using an Attribute PDU.
                The Attribute PDU shall not be used to exchange data available in
                any other PDU except where explicitly mentioned in the PDU issuance
                instructions within the standard.
    Size:       256 bits / 32 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/SimulationIdentifier.h"
#include "./../../DataTypes/AttributeRecordSet.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::SimulationIdentifier;
using KDIS::DATA_TYPE::AttributeRecordSet;
using KDIS::DATA_TYPE::ENUMS::AttributeID;
using KDIS::DATA_TYPE::ENUMS::ActionCode;
using std::vector;

class KDIS_EXPORT Attribute_PDU : public Header
{
protected:

    SimulationIdentifier m_OrigSimAddr;

    KUINT32 m_ui32Padding;

    KUINT16 m_ui16Padding;

    KUINT8 m_ui8ExtPDUType;

    KUINT8 m_ui8ExtProtocolVersion;

	KUINT32 m_ui32MasterRecType;

	KUINT8 m_ui8ActionCode;

	KUINT8 m_ui8Padding1;

	KUINT16 m_ui16NumAttrRecSets;

	vector<AttributeRecordSet> m_vAttributeRecordSets;

public:

    static const KUINT16 ATTRIBUTE_PDU_SIZE = 32; // Min size

    Attribute_PDU();

    Attribute_PDU( KDataStream & stream ) throw( KException );

	Attribute_PDU( const Header & H, KDataStream & stream ) throw( KException );

	Attribute_PDU( const SimulationIdentifier & OriginatingID, PDUType T, 
				   ProtocolVersion PV, AttributeID MART, ActionCode AC );

    virtual ~Attribute_PDU();

    //************************************
    // FullName:    KDIS::PDU::Attribute_PDU::SetOriginatingSimulationAddress
    //              KDIS::PDU::Attribute_PDU::GetOriginatingSimulationAddress
    // Description: Identifies the simulation issuing the PDU.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetOriginatingSimulationAddress( const SimulationIdentifier & ID );
    const SimulationIdentifier & GetOriginatingSimulationAddress() const;
    SimulationIdentifier & GetOriginatingSimulationAddress();

    //************************************
    // FullName:    KDIS::PDU::Attribute_PDU::SetExtendedPDUType
    //              KDIS::PDU::Attribute_PDU::GetExtendedPDUType
    // Description: The type of PDU that is being extended or updated, if applicable.
    // Parameter:   PDUType Type
    //************************************
    void SetExtendedPDUType( PDUType T );
    PDUType GetExtendedPDUType() const;

    //************************************
    // FullName:    KDIS::PDU::Attribute_PDU::SetExtendedProtocolVersion
    //              KDIS::PDU::Attribute_PDU::GetExtendedProtocolVersion
    // Description: The protocol version asociated with the extended/updated PDU.
    // Parameter:   ProtocolVersion PV
    //************************************
    void SetExtendedProtocolVersion( ProtocolVersion PV );
    ProtocolVersion GetExtendedProtocolVersion() const;

    //************************************
    // FullName:    KDIS::PDU::Attribute_PDU::SetMasterAttributeRecordType
    //              KDIS::PDU::Attribute_PDU::GetMasterAttributeRecordType
    // Description: Contains the Attribute record type of the Attribute records
	//              in the PDU if they all have the same Attribute record type.
    // Parameter:   AttributeID MART
    //************************************
	void SetMasterAttributeRecordType( AttributeID MART );
	AttributeID GetMasterAttributeRecordType() const;

    //************************************
    // FullName:    KDIS::PDU::Attribute_PDU::SetActionCode
    //              KDIS::PDU::Attribute_PDU::GetActionCode
    // Description: Action code applicable to all attribute records in this Attribute_PDU.
    // Parameter:   ActionCode AC
    //************************************
	void SetActionCode( ActionCode AC );
	ActionCode GetActionCode() const;

    //************************************
    // FullName:    KDIS::PDU::Attribute_PDU::GetNumberOfAttributeRecordSets    
    // Description: The number of Attribute Record Sets contained within this PDU.    
    //************************************
	KUINT16 GetNumberOfAttributeRecordSets() const;

    //************************************
    // FullName:    KDIS::PDU::Entity_State_PDU::AddAttributeRecordSet
    //              KDIS::PDU::Entity_State_PDU::SetAttributeRecordSets
    //              KDIS::PDU::Entity_State_PDU::GetAttributeRecordSets
    //              KDIS::PDU::Entity_State_PDU::ClearAttributeRecordSet
    // Description: Add/Set the record sets.
    //              Adding will update the Number of Attribute Record Sets Params and the PDU length field.
    // Parameter:   const AttributeRecordSet & AR, const vector<AttributeRecordSet> & AR
    //************************************
    void AddAttributeRecordSet( const AttributeRecordSet & AR );
    void SetAttributeRecordSets( const vector<AttributeRecordSet> & AR );
    const vector<AttributeRecordSet> & GetAttributeRecordSets() const;
    void ClearAttributeRecordSet();	

    //************************************
    // FullName:    KDIS::PDU::Attribute_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Attribute_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Attribute_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Attribute_PDU & Value ) const;
    KBOOL operator != ( const Attribute_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS

