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
    class:      Mode5InterrogatorBasicData
    DIS:        (7) 1278.1 - 2012
    created:    30/09/2013
    author:     Karl Jones

    purpose:    Included in the Mode 5 Interrogator format for Layer 3 of the IFF PDU.

    Size:       128 bits / 16 octets 
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EntityIdentifier.h"
#include "./Mode5InterrogatorStatus.h"
#include <bitset>

namespace KDIS {
namespace DATA_TYPE {
	
class KDIS_EXPORT Mode5InterrogatorBasicData : public DataTypeBase
{
protected:
	
	Mode5InterrogatorStatus m_Status;

	KUINT8 m_ui8Padding;

	KUINT16 m_ui16Padding1;

	KUINT32 m_ui32MsgFormats;

	EntityIdentifier m_InterrogatedID;

	KUINT16 m_ui16Padding2;

public:

    static const KUINT16 MODE_5_INTERROGATOR_BASIC_DATA_SIZE = 16; 

    Mode5InterrogatorBasicData();

	Mode5InterrogatorBasicData( const Mode5InterrogatorStatus & Status, KUINT32 FormatsPresent, const EntityIdentifier & ID );

    Mode5InterrogatorBasicData( KDataStream & stream ) throw( KException );

    virtual ~Mode5InterrogatorBasicData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::SetStatus
    //              KDIS::DATA_TYPE::Mode5InterrogatorBasicData::GetStatus	
    // Description: The Mode 5 Message Formats supported by this Mode 5 interrogator.
    // Parameter:   const InterrogatorStatus & S
    //************************************
	void SetStatus( const Mode5InterrogatorStatus & S );
	const Mode5InterrogatorStatus & GetStatus() const;
	Mode5InterrogatorStatus & GetStatus();

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::SetMessageFormatsPresent
    //              KDIS::DATA_TYPE::Mode5InterrogatorBasicData::GetMessageFormatsPresentBitSet	
	//              KDIS::DATA_TYPE::Mode5InterrogatorBasicData::GetMessageFormatsPresent
    // Description: The Mode 5 Message Formats supported by this Mode 5 interrogator.
	//              When a Mode 5 interrogator is in the Regeneration Mode, the included message 
	//              formats shall be either:
	//              1) Those that this Mode 5 interrogator is capableof supporting and could be sent 
	//              in a Mode 5 interrogation as indicated by the Message Formats Status field being
	//              set to Capability (0).
	//              2) Only the specific message formats associated with this Mode 5 interrogator’s 
	//              current active interrogation as indicated by the Message Formats Status field 
	//              being set to Active Interrogation (1).
	//              When a Mode 5 interrogator is in the Interactive Mode, the requirements specified in
	//              Interactive Basic Mode 5 IFF Data record are applicable.
	//              Each bit represents a specific message format: Not Present (0) and Present (1).
    // Parameter:   KUINT32 MFP, const std::bitset<32> & MFP
    //************************************
	void SetMessageFormatsPresent( KUINT32 MFP );
	void SetMessageFormatsPresent( const std::bitset<32> & MFP );
	const std::bitset<32> GetMessageFormatsPresentBitSet() const;
	KUINT32 GetMessageFormatsPresent();
	
	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::SetInterrogatedEntityID
    //              KDIS::DATA_TYPE::Mode5InterrogatorBasicData::GetInterrogatedEntityID		
    // Description: The Entity ID of the entity to which an active interrogation is being
    //              directed. If there is no active interrogation, this field shall be set
	//              to NO_SPECIFIC_ENTITY. 
    // Parameter:   const EntityIdentifier & ID 
    //************************************
    void SetInterrogatedEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetInterrogatedEntityID() const;
    EntityIdentifier & GetInterrogatedEntityID();

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Mode5InterrogatorBasicData & Value ) const;
    KBOOL operator != ( const Mode5InterrogatorBasicData & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
