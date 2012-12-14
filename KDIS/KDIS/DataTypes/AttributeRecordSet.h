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

using std::vector;

class KDIS_EXPORT AttributeRecordSet : public DataTypeBase
{
protected:

	EntityIdentifier m_EntityID;

	KUINT16 m_ui16NumAttrRecs;

	vector<StdVarPtr> m_vAttrRec;	

public:

    static const KUINT16 ATTRIBUTE_RECORD_SET_SIZE = 8; // Min size

    AttributeRecordSet( void );

    AttributeRecordSet( KDataStream & stream ) throw( KException );

	AttributeRecordSet( const EntityIdentifier & EI );
	
    virtual ~AttributeRecordSet( void );

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
    void SetAttributeRecords( const vector<StdVarPtr> & AR );
    const vector<StdVarPtr> & GetAttributeRecords() const;
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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

