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
    class:      AttributeRecordSet
    created:    15/03/2011
    author:     Karl Jones

    purpose:    Attribute record set for Attribute_PDU. 
                Defines a entity/object and its attributes.
    size:       64 bits / 8 octets - Min size
*********************************************************************/

#pragma once

#include "./EntityIdentifier.h"
#include "./StandardVariable.h"

namespace KDIS {
namespace DATA_TYPE {	

class KDIS_EXPORT AttributeRecordSet : public DataTypeBase
{
protected:

	EntityIdentifier m_EntityID;

	KUINT16 m_ui16NumAttrRecs;

	std::vector<StdVarPtr> m_vAttrRec;	

public:

    static const KUINT16 ATTRIBUTE_RECORD_SET_SIZE = 8; // Min size

    AttributeRecordSet();

    AttributeRecordSet( KDataStream & stream ) throw( KException );

	AttributeRecordSet( const EntityIdentifier & EI );
	
    virtual ~AttributeRecordSet();

	//************************************
    // FullName:    KDIS::DATA_TYPE::AttributeRecordSet::SetEntityIdentifier
    //              KDIS::DATA_TYPE::AttributeRecordSet::GetEntityIdentifier
    // Description: The entity or object to which all Attribute records in this set apply.	              
    // Parameter:   const EntityIdentifier & EI
    //************************************
    void SetEntityIdentifier( const EntityIdentifier & EI );
    const EntityIdentifier & GetEntityIdentifier() const;
    EntityIdentifier & GetEntityIdentifier();

	//************************************
    // FullName:    KDIS::DATA_TYPE::AttributeRecordSet::GetNumberOfAttributeRecords
    // Description: The number of Attribute Records contained within this set.
    //************************************
	KUINT16 GetNumberOfAttributeRecords() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AttributeRecordSet::AddAttributeRecord
    //              KDIS::DATA_TYPE::AttributeRecordSet::SetAttributeRecords
    //              KDIS::DATA_TYPE::AttributeRecordSet::GetAttributeRecords
    //              KDIS::DATA_TYPE::AttributeRecordSet::ClearAttributeRecords
    // Description: Add/Set the Attribute Record/s.
    //              Adding will update the Number of Attribute Records Params field.
    // Parameter:   StdVarPtr AR, const vector<StdVarPtr> & AR
	//************************************    
    void AddAttributeRecord( StdVarPtr AR );
    void SetAttributeRecords( const std::vector<StdVarPtr> & AR );
    const std::vector<StdVarPtr> & GetAttributeRecords() const;
	void ClearAttributeRecords();

    //************************************
    // FullName:    KDIS::DATA_TYPE::AttributeRecordSet::GetRecordLength
    // Description: Returns the length of the set in octets.
	//				Note: This field is not part of the data type, this is just a helper function.
    //************************************
	KUINT16 GetRecordLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AttributeRecordSet::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AttributeRecordSet::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AttributeRecordSet::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const AttributeRecordSet & Value ) const;
    KBOOL operator != ( const AttributeRecordSet & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

